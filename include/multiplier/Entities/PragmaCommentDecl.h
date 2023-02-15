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
#include "DeclKind.h"
#include "PragmaMSCommentKind.h"

namespace mx {
class Decl;
class PragmaCommentDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PragmaCommentDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<PragmaCommentDecl> in(const Fragment &frag);
  static gap::generator<PragmaCommentDecl> in(const File &file);
  static gap::generator<PragmaCommentDecl> in(const Index &index);
  static gap::generator<PragmaCommentDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PragmaCommentDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::PRAGMA_COMMENT;
  }

  static gap::generator<PragmaCommentDecl> containing(const Decl &decl);
  static gap::generator<PragmaCommentDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<PragmaCommentDecl> containing(const Stmt &stmt);
  static gap::generator<PragmaCommentDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<PragmaCommentDecl> redeclarations(void) const &;
  static std::optional<PragmaCommentDecl> from(const Decl &parent);

  inline static std::optional<PragmaCommentDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return PragmaCommentDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<PragmaCommentDecl> from(const Reference &r) {
    return PragmaCommentDecl::from(r.as_declaration());
  }

  inline static std::optional<PragmaCommentDecl> from(const TokenContext &t) {
    return PragmaCommentDecl::from(t.as_declaration());
  }

  std::string_view argument(void) const;
  PragmaMSCommentKind comment_kind(void) const;
};

static_assert(sizeof(PragmaCommentDecl) == sizeof(Decl));

#endif
} // namespace mx
