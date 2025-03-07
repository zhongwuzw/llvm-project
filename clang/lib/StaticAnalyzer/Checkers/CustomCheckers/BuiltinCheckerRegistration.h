//===--- ClangSACheckers.h - Registration functions for Checkers *- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Declares the registation functions for the checkers defined in
// libclangStaticAnalyzerCheckers.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_CLANGSA_CUSTOM_CHECKERS_H
#define LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_CLANGSA_CUSTOM_CHECKERS_H

#include "clang/StaticAnalyzer/Core/BugReporter/CommonBugCategories.h"

namespace clang {

class LangOptions;

namespace ento {

class CheckerManager;
class CheckerRegistry;

#define GET_CHECKERS
#define CHECKER(FULLNAME, CLASS, HELPTEXT, DOC_URI, IS_HIDDEN)                 \
  void register##CLASS(CheckerManager &mgr);                                   \
  bool shouldRegister##CLASS(const CheckerManager &mgr);
#include "Checkers.inc"
#undef CHECKER
#undef GET_CHECKERS

} // end ento namespace

} // end clang namespace

#endif
