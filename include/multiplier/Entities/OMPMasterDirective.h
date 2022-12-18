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
class OMPMasterDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPMasterDirectiveRange = DerivedEntityRange<StmtIterator, OMPMasterDirective>;
using OMPMasterDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPMasterDirective>;
using OMPMasterDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPMasterDirective>;

class OMPMasterDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPMasterDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPMasterDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPMasterDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_MASTER_DIRECTIVE;
  }

  static OMPMasterDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPMasterDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMasterDirective> from(const TokenContext &c);
  static std::optional<OMPMasterDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPMasterDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPMasterDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMasterDirective> from(const Stmt &parent);

  inline static std::optional<OMPMasterDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPMasterDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPMasterDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
