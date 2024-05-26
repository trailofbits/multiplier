// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ObjCTypeParamVariance.h>
#include <multiplier/AST/TypedefNameDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class File;
class NamedDecl;
class ObjCTypeParamDecl;
class Stmt;
class Token;
class TypeDecl;
class TypedefNameDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCTypeParamDecl : public TypedefNameDecl {
 private:
  friend class FragmentImpl;
  friend class TypedefNameDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCTypeParamDecl> in(const Index &index);
  static gap::generator<ObjCTypeParamDecl> in(const Fragment &frag);
  static gap::generator<ObjCTypeParamDecl> in(const File &file);
  static gap::generator<ObjCTypeParamDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ObjCTypeParamDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCTypeParamDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_TYPE_PARAM;
  }

  static gap::generator<ObjCTypeParamDecl> containing(const Decl &decl);
  static gap::generator<ObjCTypeParamDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCTypeParamDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCTypeParamDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ObjCTypeParamDecl canonical_declaration(void) const;
  std::optional<ObjCTypeParamDecl> definition(void) const;
  gap::generator<ObjCTypeParamDecl> redeclarations(void) const &;
  static std::optional<ObjCTypeParamDecl> by_id(const Index &, EntityId);

  static std::optional<ObjCTypeParamDecl> from_base(const Decl &parent);
  inline static std::optional<ObjCTypeParamDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCTypeParamDecl> from(const std::optional<Decl> &parent);
  static std::optional<ObjCTypeParamDecl> from(const Reference &r);
  static std::optional<ObjCTypeParamDecl> from(const VariantEntity &e);
  static std::optional<ObjCTypeParamDecl> from(const TokenContext &t);

  Token colon_token(void) const;
  ObjCTypeParamVariance variance(void) const;
  Token variance_token(void) const;
  bool has_explicit_bound(void) const;
};

static_assert(sizeof(ObjCTypeParamDecl) == sizeof(TypedefNameDecl));

#endif
} // namespace mx
