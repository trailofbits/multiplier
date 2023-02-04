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
class CapturedDecl;
class Decl;
class ImplicitParamDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CapturedDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<CapturedDecl> in(const Fragment &frag);
  static gap::generator<CapturedDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CAPTURED;
  }

  static gap::generator<CapturedDecl> containing(const Decl &decl);
  static gap::generator<CapturedDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<CapturedDecl> redeclarations(void) const;
  inline static std::optional<CapturedDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<CapturedDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

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
  std::optional<ImplicitParamDecl> nth_parameter(unsigned n) const;
  gap::generator<ImplicitParamDecl> parameters(void) const;
  gap::generator<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(CapturedDecl) == sizeof(Decl));

#endif
} // namespace mx
