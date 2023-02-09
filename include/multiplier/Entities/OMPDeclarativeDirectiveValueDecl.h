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
#include "ValueDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class OMPDeclarativeDirectiveValueDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDeclarativeDirectiveValueDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<OMPDeclarativeDirectiveValueDecl> in(const Fragment &frag);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> in(const Index &index);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<OMPDeclarativeDirectiveValueDecl> by(const Index &, EntityId);

  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const Decl &decl);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const Stmt &stmt);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<OMPDeclarativeDirectiveValueDecl> redeclarations(void) const;
  inline static std::optional<OMPDeclarativeDirectiveValueDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<OMPDeclarativeDirectiveValueDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const ValueDecl &parent);

  inline static std::optional<OMPDeclarativeDirectiveValueDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return OMPDeclarativeDirectiveValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const NamedDecl &parent);

  inline static std::optional<OMPDeclarativeDirectiveValueDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return OMPDeclarativeDirectiveValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const Decl &parent);

  inline static std::optional<OMPDeclarativeDirectiveValueDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPDeclarativeDirectiveValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPDeclarativeDirectiveValueDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
