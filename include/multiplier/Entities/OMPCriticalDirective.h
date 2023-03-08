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

namespace mx {
class Decl;
class OMPCriticalDirective;
class OMPExecutableDirective;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPCriticalDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPCriticalDirective> in(const Fragment &frag);
  static gap::generator<OMPCriticalDirective> in(const File &file);
  static gap::generator<OMPCriticalDirective> in(const Index &index);
  static gap::generator<OMPCriticalDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPCriticalDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_CRITICAL_DIRECTIVE;
  }

  static gap::generator<OMPCriticalDirective> containing(const Decl &decl);
  static gap::generator<OMPCriticalDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPCriticalDirective> containing(const Stmt &stmt);
  static gap::generator<OMPCriticalDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPCriticalDirective> from(const Stmt &parent);

  inline static std::optional<OMPCriticalDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPCriticalDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPCriticalDirective> from(const Reference &r) {
    return OMPCriticalDirective::from(r.as_statement());
  }

  inline static std::optional<OMPCriticalDirective> from(const TokenContext &t) {
    return OMPCriticalDirective::from(t.as_statement());
  }

};

static_assert(sizeof(OMPCriticalDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
