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
class OMPExecutableDirective;
class OMPTargetDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTargetDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetDirective> in(const Index &index);
  static gap::generator<OMPTargetDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_DIRECTIVE;
  }

  static gap::generator<OMPTargetDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPTargetDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPTargetDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<OMPTargetDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTargetDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTargetDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTargetDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
