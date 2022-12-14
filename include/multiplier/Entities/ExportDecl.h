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
class ExportDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ExportDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExportDecl>;
using ExportDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ExportDecl>;

class ExportDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static gap::generator<ExportDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ExportDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ExportDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::EXPORT;
  }

  static ExportDeclContainingDeclRange containing(const Decl &decl);
  static ExportDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ExportDecl> from(const TokenContext &c);
  static std::optional<ExportDecl> from(const Decl &parent);

  inline static std::optional<ExportDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ExportDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token export_token(void) const;
  Token r_brace_token(void) const;
  bool has_braces(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(ExportDecl) == sizeof(Decl));

#endif
} // namespace mx
