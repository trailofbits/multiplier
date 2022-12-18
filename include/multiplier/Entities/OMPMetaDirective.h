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

#include "OMPExecutableDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPMetaDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPMetaDirectiveRange = DerivedEntityRange<StmtIterator, OMPMetaDirective>;
using OMPMetaDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPMetaDirective>;
using OMPMetaDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPMetaDirective>;

class OMPMetaDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPMetaDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPMetaDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPMetaDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_META_DIRECTIVE;
  }

  static OMPMetaDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPMetaDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMetaDirective> from(const TokenContext &c);
  static std::optional<OMPMetaDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPMetaDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPMetaDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMetaDirective> from(const Stmt &parent);

  inline static std::optional<OMPMetaDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPMetaDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt if_statement(void) const;
};

static_assert(sizeof(OMPMetaDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
