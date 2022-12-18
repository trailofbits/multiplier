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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Decl.h"
#include "DeclKind.h"

namespace mx {
class Decl;
class ExternCContextDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ExternCContextDeclRange = DerivedEntityRange<DeclIterator, ExternCContextDecl>;
using ExternCContextDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExternCContextDecl>;
using ExternCContextDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ExternCContextDecl>;

class ExternCContextDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static ExternCContextDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExternCContextDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ExternCContextDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::EXTERN_C_CONTEXT;
  }

  static ExternCContextDeclContainingDeclRange containing(const Decl &decl);
  static ExternCContextDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ExternCContextDecl> from(const TokenContext &c);
  static std::optional<ExternCContextDecl> from(const Decl &parent);

  inline static std::optional<ExternCContextDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ExternCContextDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(ExternCContextDecl) == sizeof(Decl));

#endif
} // namespace mx
