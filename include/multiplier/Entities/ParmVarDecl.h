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
  static gap::generator<ParmVarDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::PARM_VAR;
  }

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<ParmVarDecl> containing(const Decl &decl);
  static gap::generator<ParmVarDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ParmVarDecl> redeclarations(void) const;
  inline static std::optional<ParmVarDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ParmVarDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ParmVarDecl> from(const VarDecl &parent);

  inline static std::optional<ParmVarDecl> from(const std::optional<VarDecl> &parent) {
    if (parent) {
      return ParmVarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ParmVarDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<ParmVarDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return ParmVarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ParmVarDecl> from(const ValueDecl &parent);

  inline static std::optional<ParmVarDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return ParmVarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ParmVarDecl> from(const NamedDecl &parent);

  inline static std::optional<ParmVarDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ParmVarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ParmVarDecl> from(const Decl &parent);

  inline static std::optional<ParmVarDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ParmVarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
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
