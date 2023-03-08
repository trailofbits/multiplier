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
class OMPExecutableDirective;
class OMPFlushDirective;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPFlushDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPFlushDirective> in(const Fragment &frag);
  static gap::generator<OMPFlushDirective> in(const File &file);
  static gap::generator<OMPFlushDirective> in(const Index &index);
  static gap::generator<OMPFlushDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPFlushDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_FLUSH_DIRECTIVE;
  }

  static gap::generator<OMPFlushDirective> containing(const Decl &decl);
  static gap::generator<OMPFlushDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPFlushDirective> containing(const Stmt &stmt);
  static gap::generator<OMPFlushDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPFlushDirective> from(const Stmt &parent);

  inline static std::optional<OMPFlushDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPFlushDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPFlushDirective> from(const Reference &r) {
    return OMPFlushDirective::from(r.as_statement());
  }

  inline static std::optional<OMPFlushDirective> from(const TokenContext &t) {
    return OMPFlushDirective::from(t.as_statement());
  }

};

static_assert(sizeof(OMPFlushDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
