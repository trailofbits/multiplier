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
class Expr;
class OMPExecutableDirective;
class OMPTaskgroupDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTaskgroupDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTaskgroupDirective> in(const Fragment &frag);
  static gap::generator<OMPTaskgroupDirective> in(const File &file);
  static gap::generator<OMPTaskgroupDirective> in(const Index &index);
  static gap::generator<OMPTaskgroupDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTaskgroupDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TASKGROUP_DIRECTIVE;
  }

  static gap::generator<OMPTaskgroupDirective> containing(const Decl &decl);
  static gap::generator<OMPTaskgroupDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTaskgroupDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTaskgroupDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTaskgroupDirective> from(const Stmt &parent);

  inline static std::optional<OMPTaskgroupDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTaskgroupDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPTaskgroupDirective> from(const Reference &r) {
    return OMPTaskgroupDirective::from(r.as_statement());
  }

  inline static std::optional<OMPTaskgroupDirective> from(const TokenContext &t) {
    return OMPTaskgroupDirective::from(t.as_statement());
  }

  Expr reduction_reference(void) const;
};

static_assert(sizeof(OMPTaskgroupDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
