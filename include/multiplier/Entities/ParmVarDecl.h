// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "DeclKind.h"
#include "DeclObjCDeclQualifier.h"
#include "VarDecl.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class Expr;
class NamedDecl;
class ParmVarDecl;
class Type;
class ValueDecl;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ParmVarDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ParmVarDecl> in(const Fragment &frag);
  static gap::generator<ParmVarDecl> in(const File &file);
  static gap::generator<ParmVarDecl> in(const Index &index);
  static gap::generator<ParmVarDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ParmVarDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::PARM_VAR;
  }

  static gap::generator<ParmVarDecl> containing(const Decl &decl);
  static gap::generator<ParmVarDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ParmVarDecl> containing(const Stmt &stmt);
  static gap::generator<ParmVarDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ParmVarDecl> redeclarations(void) const;
  static std::optional<ParmVarDecl> from(const Decl &parent);

  inline static std::optional<ParmVarDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ParmVarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ParmVarDecl> from(const Reference &r) {
    return ParmVarDecl::from(r.as_declaration());
  }

  inline static std::optional<ParmVarDecl> from(const TokenContext &t) {
    return ParmVarDecl::from(t.as_declaration());
  }

  std::optional<Expr> default_argument(void) const;
  TokenRange default_argument_range(void) const;
  DeclObjCDeclQualifier obj_c_decl_qualifier(void) const;
  Type original_type(void) const;
  std::optional<Expr> uninstantiated_default_argument(void) const;
  bool has_default_argument(void) const;
  bool has_inherited_default_argument(void) const;
  bool has_uninstantiated_default_argument(void) const;
  bool has_unparsed_default_argument(void) const;
  bool is_destroyed_in_callee(void) const;
  bool is_knr_promoted(void) const;
  bool is_obj_c_method_parameter(void) const;
};

static_assert(sizeof(ParmVarDecl) == sizeof(VarDecl));

#endif
} // namespace mx
