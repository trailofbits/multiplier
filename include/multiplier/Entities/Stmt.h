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

#include "DeclUseSelector.h"
#include "StmtKind.h"

namespace mx {
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using StmtRange = DerivedEntityRange<StmtIterator, Stmt>;
using StmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, Stmt>;
using StmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, Stmt>;

class Stmt {
 protected:
  friend class Attr;
  friend class AttrIterator;
  friend class Decl;
  friend class DeclIterator;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class ReferenceIterator;
  friend class ReferenceIteratorImpl;
  friend class StmtIterator;
  friend class TokenContext;
  friend class Type;
  friend class TypeIterator;
  friend class UseBase;
  friend class UseIteratorImpl;
  template <typename> friend class UseIterator;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset_;

 public:
  Stmt(Stmt &&) noexcept = default;
  Stmt(const Stmt &) = default;
  Stmt &operator=(Stmt &&) noexcept = default;
  Stmt &operator=(const Stmt &) = default;

  inline Stmt(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset__)
      : fragment(std::move(fragment_)),
        offset_(offset__) {}

  inline static std::optional<Stmt> from(const Stmt &self) {
    return self;
  }

  inline static std::optional<Stmt> from(const std::optional<Stmt> &self) {
    return self;
  }

  inline static std::optional<Stmt> from(const TokenContext &c) {
    return c.as_statement();
  }

  std::optional<Decl> parent_declaration(void) const;
  std::optional<Stmt> parent_statement(void) const;
  std::optional<Decl> referenced_declaration(void) const;
  EntityId id(void) const;
  UseRange<StmtUseSelector> uses(void) const;

 protected:
  static StmtIterator in_internal(const Fragment &fragment);

 public:
  inline static StmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static StmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : Stmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static StmtContainingStmtRange containing(const Decl &decl);
  static StmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  Stmt ignore_containers(void) const;
  std::vector<Stmt> children(void) const;
  TokenRange tokens(void) const;
  StmtKind kind(void) const;
  Stmt strip_label_like_statements(void) const;
};

#endif
} // namespace mx
