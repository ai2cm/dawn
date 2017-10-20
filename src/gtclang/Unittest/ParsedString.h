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

#ifndef GTCLANG_UNITTEST_PARSEDSTRING_H
#define GTCLANG_UNITTEST_PARSEDSTRING_H
#include "dawn/SIR/ASTExpr.h"
#include "dawn/SIR/ASTStmt.h"
#include "dawn/SIR/ASTVisitor.h"
#include "dawn/SIR/SIR.h"
#include "dawn/Support/Array.h"
#include "dawn/Support/Casting.h"
#include "dawn/Support/Unreachable.h"
#include <string>
#include <vector>

namespace gtclang {

/// @brief parsing unittest-strings to automatically write simple stencils
/// @ingroup unittest
/// The class is filled with parse
/// To generate the stencil, we call FileWriter with this class as an argument
class ParsedString {
public:
  ParsedString() = default;
  ParsedString(ParsedString&&) = default;
  ParsedString(const ParsedString&) = default;
  ParsedString(const std::string& functionCall) : functionCall_(functionCall) {
    if(functionCall_.back() == ';') {
      functionCall_.pop_back();
    }
  }

  const std::vector<std::string>& getFields() const { return fields_; }
  const std::vector<std::string>& getVariables() const { return variables_; }
  const std::string& getCall() const { return functionCall_; }

  template <typename... Args>
  void argumentParsing(const std::shared_ptr<dawn::Expr>& argument, Args&&... args){
      argumentParsingImpl(argument);
      argumentParsing(std::forward<Args>(args)...);
    }
  void argumentParsing() {}

  void argumentParsingImpl(const std::shared_ptr<dawn::Expr>& argument){
      if(dawn::VarAccessExpr* expr = dawn::dyn_cast<dawn::VarAccessExpr>(argument.get())) {
        addVariable(expr->getName());
      } else if(dawn::FieldAccessExpr* expr = dawn::dyn_cast<dawn::FieldAccessExpr>(argument.get())) {
        addField(expr->getName());
      } else {
        dawn_unreachable("invalid expression");
      }
    }

  void dump();

private:
  void addField(std::string& field) { fields_.push_back(field); }
  void addVariable(std::string& variable) { variables_.push_back(variable); }

  std::vector<std::string> fields_;
  std::vector<std::string> variables_;
  std::string functionCall_;
};

/// @brief parses a string describing an operation with its respective variables
/// @ingroup unittest
/// @param[in] Function call as a string (e.g "a = b + c")
/// @param[in] Declaration of Variables as Fields or variable accesses [dawn::field("a"),
/// dawn::var("b")]
/// @param[out] An object containing all the information to autogenerate the corresponding stencil
/// to a File
template <typename... Args>
ParsedString parse(const std::string& functionCall, Args&&... args) {
  ParsedString parsed(functionCall);
  parsed.argumentParsing(std::forward<Args>(args)...);
  return parsed;
}
} // namespace gtclang

#endif
