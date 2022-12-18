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
class OMPDepobjDirective;
class OMPExecutableDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPDepobjDirectiveRange = DerivedEntityRange<StmtIterator, OMPDepobjDirective>;
using OMPDepobjDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDepobjDirective>;
using OMPDepobjDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPDepobjDirective>;

class OMPDepobjDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPDepobjDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDepobjDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPDepobjDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_DEPOBJ_DIRECTIVE;
  }

  static OMPDepobjDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPDepobjDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPDepobjDirective> from(const TokenContext &c);
  static std::optional<OMPDepobjDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPDepobjDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPDepobjDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDepobjDirective> from(const Stmt &parent);

  inline static std::optional<OMPDepobjDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPDepobjDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPDepobjDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
