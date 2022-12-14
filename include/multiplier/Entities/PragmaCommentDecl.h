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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Decl.h"
#include "DeclKind.h"
#include "PragmaMSCommentKind.h"

namespace mx {
class Decl;
class PragmaCommentDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using PragmaCommentDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, PragmaCommentDecl>;

class PragmaCommentDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static gap::generator<PragmaCommentDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<PragmaCommentDecl> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : PragmaCommentDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::PRAGMA_COMMENT;
  }

  static PragmaCommentDeclContainingDeclRange containing(const Decl &decl);
  static PragmaCommentDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<PragmaCommentDecl> from(const TokenContext &c);
  static std::optional<PragmaCommentDecl> from(const Decl &parent);

  inline static std::optional<PragmaCommentDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return PragmaCommentDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view argument(void) const;
  PragmaMSCommentKind comment_kind(void) const;
};

static_assert(sizeof(PragmaCommentDecl) == sizeof(Decl));

#endif
} // namespace mx
