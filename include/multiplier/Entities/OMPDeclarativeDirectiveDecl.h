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

#include "Decl.h"
#include "DeclKind.h"

namespace mx {
class Decl;
class OMPDeclarativeDirectiveDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDeclarativeDirectiveDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<OMPDeclarativeDirectiveDecl> in(const Fragment &frag);
  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const Decl &decl);
  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<OMPDeclarativeDirectiveDecl> redeclarations(void) const;
  inline static std::optional<OMPDeclarativeDirectiveDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<OMPDeclarativeDirectiveDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<OMPDeclarativeDirectiveDecl> from(const Decl &parent);

  inline static std::optional<OMPDeclarativeDirectiveDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPDeclarativeDirectiveDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPDeclarativeDirectiveDecl) == sizeof(Decl));

#endif
} // namespace mx
