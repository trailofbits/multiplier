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
class LinkageSpecDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using LinkageSpecDeclRange = DerivedEntityRange<DeclIterator, LinkageSpecDecl>;
using LinkageSpecDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, LinkageSpecDecl>;
using LinkageSpecDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, LinkageSpecDecl>;

class LinkageSpecDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static LinkageSpecDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LinkageSpecDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : LinkageSpecDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::LINKAGE_SPEC;
  }

  static LinkageSpecDeclContainingDeclRange containing(const Decl &decl);
  static LinkageSpecDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<LinkageSpecDecl> from(const TokenContext &c);
  static std::optional<LinkageSpecDecl> from(const Decl &parent);

  inline static std::optional<LinkageSpecDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return LinkageSpecDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(LinkageSpecDecl) == sizeof(Decl));

#endif
} // namespace mx
