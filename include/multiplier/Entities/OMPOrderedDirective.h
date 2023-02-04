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
class OMPExecutableDirective;
class OMPOrderedDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPOrderedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPOrderedDirective> in(const Fragment &frag);
  static gap::generator<OMPOrderedDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_ORDERED_DIRECTIVE;
  }

  static gap::generator<OMPOrderedDirective> containing(const Decl &decl);
  static gap::generator<OMPOrderedDirective> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPOrderedDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPOrderedDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<OMPOrderedDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPOrderedDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPOrderedDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPOrderedDirective> from(const Stmt &parent);

  inline static std::optional<OMPOrderedDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPOrderedDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPOrderedDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
