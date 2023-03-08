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

#include "Decl.h"

namespace mx {
class Decl;
class OMPAllocateDecl;
class OMPDeclarativeDirectiveDecl;
class OMPRequiresDecl;
class OMPThreadPrivateDecl;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDeclarativeDirectiveDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<OMPDeclarativeDirectiveDecl> in(const Fragment &frag);
  static gap::generator<OMPDeclarativeDirectiveDecl> in(const File &file);
  static gap::generator<OMPDeclarativeDirectiveDecl> in(const Index &index);
  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDeclarativeDirectiveDecl> by_id(const Index &, EntityId);

  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const Decl &decl);
  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const Stmt &stmt);
  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<OMPDeclarativeDirectiveDecl> redeclarations(void) const &;
  static std::optional<OMPDeclarativeDirectiveDecl> from(const Decl &parent);

  inline static std::optional<OMPDeclarativeDirectiveDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPDeclarativeDirectiveDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPDeclarativeDirectiveDecl> from(const Reference &r) {
    return OMPDeclarativeDirectiveDecl::from(r.as_declaration());
  }

  inline static std::optional<OMPDeclarativeDirectiveDecl> from(const TokenContext &t) {
    return OMPDeclarativeDirectiveDecl::from(t.as_declaration());
  }

};

static_assert(sizeof(OMPDeclarativeDirectiveDecl) == sizeof(Decl));

#endif
} // namespace mx
