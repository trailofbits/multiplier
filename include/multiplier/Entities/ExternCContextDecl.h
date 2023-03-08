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
class ExternCContextDecl;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExternCContextDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<ExternCContextDecl> in(const Fragment &frag);
  static gap::generator<ExternCContextDecl> in(const File &file);
  static gap::generator<ExternCContextDecl> in(const Index &index);
  static gap::generator<ExternCContextDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ExternCContextDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::EXTERN_C_CONTEXT;
  }

  static gap::generator<ExternCContextDecl> containing(const Decl &decl);
  static gap::generator<ExternCContextDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ExternCContextDecl> containing(const Stmt &stmt);
  static gap::generator<ExternCContextDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ExternCContextDecl> redeclarations(void) const &;
  static std::optional<ExternCContextDecl> from(const Decl &parent);

  inline static std::optional<ExternCContextDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ExternCContextDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ExternCContextDecl> from(const Reference &r) {
    return ExternCContextDecl::from(r.as_declaration());
  }

  inline static std::optional<ExternCContextDecl> from(const TokenContext &t) {
    return ExternCContextDecl::from(t.as_declaration());
  }

  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(ExternCContextDecl) == sizeof(Decl));

#endif
} // namespace mx
