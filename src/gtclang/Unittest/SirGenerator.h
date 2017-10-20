//===--------------------------------------------------------------------------------*- C++ -*-===//
//                         _       _
//                        | |     | |
//                    __ _| |_ ___| | __ _ _ __   __ _
//                   / _` | __/ __| |/ _` | '_ \ / _` |
//                  | (_| | || (__| | (_| | | | | (_| |
//                   \__, |\__\___|_|\__,_|_| |_|\__, | - GridTools Clang DSL
//                    __/ |                       __/ |
//                   |___/                       |___/
//
//
//  This file is distributed under the MIT License (MIT).
//  See LICENSE.txt for details.
//
//===------------------------------------------------------------------------------------------===//

#ifndef GTCLANG_UNITTEST_SIRGENERATOR_H
#define GTCLANG_UNITTEST_SIRGENERATOR_H
#include "dawn/SIR/ASTExpr.h"
#include "dawn/SIR/ASTStmt.h"
#include "gtclang/Unittest/ParsedString.h"
#include <string>
#include <vector>

namespace gtclang {
struct CompareResult {
  std::string message;
  bool match;

  operator bool() { return match; }
  std::string why() {return message;}
};

///
/// \brief compares a string of an input operation with a statement wrapped into an ast
/// \param ps a parsed string with all its variables. Can be created i.e with
/// \code{.cpp}
/// parse("a=b", field("a"), field("b"))
/// \endcode
/// \param stmt a dawn statement. Will be inserted into a stencil with a vertical region going form
/// k_start to k_end and will add all the required fields
/// \return a Struct of string and boolean. If the parsed AST and the Wrapped AST match, we get true
/// and and empty string if we have a mismatch, we get a human-readable message of what failed and
/// false
///
CompareResult compare(const ParsedString& ps,
                                     const std::shared_ptr<dawn::Stmt>& stmt);

CompareResult compare(const ParsedString& ps,
                                     const std::shared_ptr<dawn::Expr>& expr);

} // namespace gtclang

#endif
