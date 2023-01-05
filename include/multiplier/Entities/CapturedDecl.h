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

namespace mx {
class CapturedDecl;
class Decl;
class ImplicitParamDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CapturedDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static gap::generator<CapturedDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CapturedDecl> containing(const Token &tok) {
    for(auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CapturedDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CAPTURED;
  }

  static gap::generator<CapturedDecl> containing(const Decl &decl);
  static gap::generator<CapturedDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CapturedDecl> from(const TokenContext &c);
  static std::optional<CapturedDecl> from(const Decl &parent);

  inline static std::optional<CapturedDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return CapturedDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ImplicitParamDecl context_parameter(void) const;
  bool is_nothrow(void) const;
  std::vector<ImplicitParamDecl> parameters(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(CapturedDecl) == sizeof(Decl));

#endif
} // namespace mx
