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
class Decl;
class FileScopeAsmDecl;
class StringLiteral;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FileScopeAsmDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static gap::generator<FileScopeAsmDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<FileScopeAsmDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : FileScopeAsmDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FILE_SCOPE_ASM;
  }

  static gap::generator<FileScopeAsmDecl> containing(const Decl &decl);
  static gap::generator<FileScopeAsmDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FileScopeAsmDecl> from(const TokenContext &c);
  static std::optional<FileScopeAsmDecl> from(const Decl &parent);

  inline static std::optional<FileScopeAsmDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FileScopeAsmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token assembly_token(void) const;
  StringLiteral assembly_string(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(FileScopeAsmDecl) == sizeof(Decl));

#endif
} // namespace mx
