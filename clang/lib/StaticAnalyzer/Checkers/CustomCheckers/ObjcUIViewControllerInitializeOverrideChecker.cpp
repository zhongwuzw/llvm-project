#include "BuiltinCheckerRegistration.h"
#include "clang/StaticAnalyzer/Frontend/CheckerRegistry.h"
#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/Checker.h"
#include "clang/StaticAnalyzer/Core/CheckerManager.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CallEvent.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"

using namespace clang;
using namespace clang::ento;

namespace {
class ObjcUIViewControllerInitializeOverrideChecker : public Checker<check::ASTDecl<ObjCCategoryImplDecl>> {
    mutable std::unique_ptr<BugType> BT;
    mutable IdentifierInfo *IUIViewController;
    
public:
    void checkASTDecl(const ObjCCategoryImplDecl *D,
                      AnalysisManager &mgr, BugReporter &BR) const;
};
} // namespace

void ObjcUIViewControllerInitializeOverrideChecker::checkASTDecl(const ObjCCategoryImplDecl *OCD,
                                                                 AnalysisManager &Mgr, BugReporter &BR) const {
    ASTContext &Ctx = Mgr.getASTContext();
    if (!IUIViewController) {
        IUIViewController = &Ctx.Idents.get("UIViewController");
    }
    
    if (OCD->getClassInterface()->getIdentifier() != IUIViewController) {
        return;
    }
    
    for (const auto *MD : OCD->methods()) {
        if (MD->isClassMethod() && MD->getSelector().getMethodFamily() == OMF_initialize) {
            Selector S = MD->getSelector();
            PathDiagnosticLocation DLoc =
            PathDiagnosticLocation::createEnd(MD->getBody(),
                                              BR.getSourceManager(),
                                              Mgr.getAnalysisDeclContext(OCD));
            
            const char *Name = "Missing call to superclass";
            SmallString<320> Buf;
            llvm::raw_svector_ostream os(Buf);
            
            os << "The '" << S.getAsString()
            << "' cannot override in UIViewController ";
            
            BR.EmitBasicReport(MD, this, Name, categories::CoreFoundationObjectiveC,
                               os.str(), DLoc);
        }
    }
}

void ento::registerObjcUIViewControllerInitializeOverrideChecker(CheckerManager &Mgr) {
  Mgr.registerChecker<ObjcUIViewControllerInitializeOverrideChecker>();
}

bool ento::shouldRegisterObjcUIViewControllerInitializeOverrideChecker(const CheckerManager &mgr) {
  return true;
}
