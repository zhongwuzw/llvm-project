//#include "ClangSACheckers.h"
#include "clang/StaticAnalyzer/Checkers/BuiltinCheckerRegistration.h"
#include "clang/StaticAnalyzer/Frontend/CheckerRegistry.h"
#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/Checker.h"
#include "clang/StaticAnalyzer/Core/CheckerManager.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CallEvent.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
using namespace clang;
using namespace clang::ento;
namespace {
class CustomMainCallChecker : public Checker<check::PreCall> {
  mutable std::unique_ptr<BugType> BT;

public:
  void checkPreCall(const CallEvent &Call, CheckerContext &C) const;
};
} // namespace
void CustomMainCallChecker::checkPreCall(const CallEvent &Call,
                                   CheckerContext &C) const {
  if (const IdentifierInfo *II = Call.getCalleeIdentifier())
    if (II->isStr("main")) {
      if (!BT)
        BT.reset(new BugType(this, "Call to main", "Example checker"));
      ExplodedNode *N = C.generateErrorNode();
      auto Report =
          std::make_unique<PathSensitiveBugReport>(*BT, "call failed", N);
      C.emitReport(std::move(Report));
    }
}

extern "C" const char clang_analyzerAPIVersionString[] =
CLANG_ANALYZER_API_VERSION_STRING;

extern "C" void clang_registerCheckers(CheckerRegistry &registry) {
    registry.addChecker<CustomMainCallChecker>("alpha.core.MainCallChecker", "Checks for calls to main","for test");
}

//void ento::registerCustomMainCallChecker(CheckerManager &Mgr) {
//  Mgr.registerChecker<CustomMainCallChecker>();
//}
//
//bool ento::shouldRegisterCustomMainCallChecker(const CheckerManager &mgr) {
//  return true;
//}
