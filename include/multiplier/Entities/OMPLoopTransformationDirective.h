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

#include "OMPLoopBasedDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopTransformationDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPLoopTransformationDirective : public OMPLoopBasedDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPLoopTransformationDirective> in(const Fragment &frag);
  static gap::generator<OMPLoopTransformationDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static gap::generator<StmtKind> derived_kinds(void);
  static gap::generator<OMPLoopTransformationDirective> containing(const Decl &decl);
  static gap::generator<OMPLoopTransformationDirective> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPLoopTransformationDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPLoopTransformationDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<OMPLoopTransformationDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPLoopTransformationDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPLoopTransformationDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPLoopTransformationDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPLoopTransformationDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPLoopTransformationDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPLoopTransformationDirective> from(const Stmt &parent);

  inline static std::optional<OMPLoopTransformationDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPLoopTransformationDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt pre_initializers(void) const;
  Stmt transformed_statement(void) const;
};

static_assert(sizeof(OMPLoopTransformationDirective) == sizeof(OMPLoopBasedDirective));

#endif
} // namespace mx
