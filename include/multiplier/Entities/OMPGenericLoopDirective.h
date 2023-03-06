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

#include "OMPLoopDirective.h"

namespace mx {
class Decl;
class OMPExecutableDirective;
class OMPGenericLoopDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPGenericLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPGenericLoopDirective> in(const Fragment &frag);
  static gap::generator<OMPGenericLoopDirective> in(const File &file);
  static gap::generator<OMPGenericLoopDirective> in(const Index &index);
  static gap::generator<OMPGenericLoopDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPGenericLoopDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_GENERIC_LOOP_DIRECTIVE;
  }

  static gap::generator<OMPGenericLoopDirective> containing(const Decl &decl);
  static gap::generator<OMPGenericLoopDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPGenericLoopDirective> containing(const Stmt &stmt);
  static gap::generator<OMPGenericLoopDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPGenericLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPGenericLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPGenericLoopDirective> from(const Reference &r) {
    return OMPGenericLoopDirective::from(r.as_statement());
  }

  inline static std::optional<OMPGenericLoopDirective> from(const TokenContext &t) {
    return OMPGenericLoopDirective::from(t.as_statement());
  }

};

static_assert(sizeof(OMPGenericLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
