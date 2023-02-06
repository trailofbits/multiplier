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

#include "OMPExecutableDirective.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class OMPExecutableDirective;
class OMPParallelSectionsDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPParallelSectionsDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPParallelSectionsDirective> in(const Fragment &frag);
  static gap::generator<OMPParallelSectionsDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_SECTIONS_DIRECTIVE;
  }

  static gap::generator<OMPParallelSectionsDirective> containing(const Decl &decl);
  static gap::generator<OMPParallelSectionsDirective> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPParallelSectionsDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPParallelSectionsDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

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
