#include "clang/StaticAnalyzer/Checkers/BuiltinCheckerRegistration.h"
#include "clang/StaticAnalyzer/Frontend/CheckerRegistry.h"
#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/Checker.h"
#include "clang/StaticAnalyzer/Core/CheckerManager.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CallEvent.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
#include "BuiltinCheckerRegistration.h"

using namespace clang;
using namespace clang::ento;

extern "C" const char clang_analyzerAPIVersionString[] =
CLANG_ANALYZER_API_VERSION_STRING;

extern "C" void clang_registerCheckers(CheckerRegistry &registry) {
#define GET_CHECKERS
#define CHECKER(FULLNAME, CLASS, HELPTEXT, DOC_URI, IS_HIDDEN)                 \
    registry.addChecker(register##CLASS, shouldRegister##CLASS, FULLNAME, HELPTEXT,       \
    DOC_URI, IS_HIDDEN);
    
#include "Checkers.inc"
#undef CHECKER
#undef GET_CHECKERS
}
