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
class Expr;
class OMPExecutableDirective;
class OMPParallelSectionsDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPParallelSectionsDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelSectionsDirective>;
using OMPParallelSectionsDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelSectionsDirective>;
using OMPParallelSectionsDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelSectionsDirective>;

class OMPParallelSectionsDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelSectionsDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelSectionsDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPParallelSectionsDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_SECTIONS_DIRECTIVE;
  }

  static OMPParallelSectionsDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelSectionsDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelSectionsDirective> from(const TokenContext &c);
  static std::optional<OMPParallelSectionsDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPParallelSectionsDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPParallelSectionsDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelSectionsDirective> from(const Stmt &parent);

  inline static std::optional<OMPParallelSectionsDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPParallelSectionsDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPParallelSectionsDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
