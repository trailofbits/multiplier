// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CXXMethodDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXConversionDecl;
class CXXMethodDecl;
class Decl;
class DeclaratorDecl;
class FunctionDecl;
class NamedDecl;
class Stmt;
class Token;
class Type;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXConversionDecl : public CXXMethodDecl {
 private:
  friend class FragmentImpl;
  friend class CXXMethodDecl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<CXXConversionDecl> in(const Index &index);
  static gap::generator<CXXConversionDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXConversionDecl> by_id(const Index &, EntityId);
  static gap::generator<CXXConversionDecl> in(const Fragment &frag);
  static gap::generator<CXXConversionDecl> in(const File &file);

  static std::optional<CXXConversionDecl> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<CXXConversionDecl, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_CONVERSION;
  }

  static gap::generator<CXXConversionDecl> containing(const Decl &decl);
  static gap::generator<CXXConversionDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXConversionDecl> containing(const Stmt &stmt);
  static gap::generator<CXXConversionDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  CXXConversionDecl canonical_declaration(void) const;
  std::optional<CXXConversionDecl> definition(void) const;
  gap::generator<CXXConversionDecl> redeclarations(void) const &;
  static std::optional<CXXConversionDecl> from_base(const Decl &parent);
  inline static std::optional<CXXConversionDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<CXXConversionDecl> from(const std::optional<Decl> &parent);
  static std::optional<CXXConversionDecl> from(const Reference &r);
  static std::optional<CXXConversionDecl> from(const VariantEntity &e);
  static std::optional<CXXConversionDecl> from(const TokenContext &t);

  Type conversion_type(void) const;
  bool is_explicit(void) const;
  bool is_lambda_to_block_pointer_conversion(void) const;
};

static_assert(sizeof(CXXConversionDecl) == sizeof(CXXMethodDecl));

#endif
} // namespace mx
