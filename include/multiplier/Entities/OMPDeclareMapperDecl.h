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
#include "OMPDeclarativeDirectiveValueDecl.h"

namespace mx {
class Decl;
class Expr;
class NamedDecl;
class OMPDeclarativeDirectiveValueDecl;
class OMPDeclareMapperDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDeclareMapperDecl : public OMPDeclarativeDirectiveValueDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveValueDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<OMPDeclareMapperDecl> in(const Fragment &frag);
  static gap::generator<OMPDeclareMapperDecl> in(const Index &index);
  static gap::generator<OMPDeclareMapperDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDeclareMapperDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_DECLARE_MAPPER;
  }

  static gap::generator<OMPDeclareMapperDecl> containing(const Decl &decl);
  static gap::generator<OMPDeclareMapperDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDeclareMapperDecl> containing(const Stmt &stmt);
  static gap::generator<OMPDeclareMapperDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<OMPDeclareMapperDecl> redeclarations(void) const;
  inline static std::optional<OMPDeclareMapperDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<OMPDeclareMapperDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<OMPDeclareMapperDecl> from(const OMPDeclarativeDirectiveValueDecl &parent);

  inline static std::optional<OMPDeclareMapperDecl> from(const std::optional<OMPDeclarativeDirectiveValueDecl> &parent) {
    if (parent) {
      return OMPDeclareMapperDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclareMapperDecl> from(const ValueDecl &parent);

  inline static std::optional<OMPDeclareMapperDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return OMPDeclareMapperDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclareMapperDecl> from(const NamedDecl &parent);

  inline static std::optional<OMPDeclareMapperDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return OMPDeclareMapperDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclareMapperDecl> from(const Decl &parent);

  inline static std::optional<OMPDeclareMapperDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPDeclareMapperDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr mapper_variable_reference(void) const;
  gap::generator<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(OMPDeclareMapperDecl) == sizeof(OMPDeclarativeDirectiveValueDecl));

#endif
} // namespace mx
