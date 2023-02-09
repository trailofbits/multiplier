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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "OMPExecutableDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPCancellationPointDirective;
class OMPExecutableDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPCancellationPointDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPCancellationPointDirective> in(const Fragment &frag);
  static gap::generator<OMPCancellationPointDirective> in(const Index &index);
  static gap::generator<OMPCancellationPointDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPCancellationPointDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_CANCELLATION_POINT_DIRECTIVE;
  }

  static gap::generator<OMPCancellationPointDirective> containing(const Decl &decl);
  static gap::generator<OMPCancellationPointDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPCancellationPointDirective> containing(const Stmt &stmt);
  static gap::generator<OMPCancellationPointDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPCancellationPointDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPCancellationPointDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<OMPCancellationPointDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPCancellationPointDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPCancellationPointDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPCancellationPointDirective> from(const Stmt &parent);

  inline static std::optional<OMPCancellationPointDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPCancellationPointDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPCancellationPointDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
