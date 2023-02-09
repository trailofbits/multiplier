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
class OMPTeamsDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTeamsDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTeamsDirective> in(const Fragment &frag);
  static gap::generator<OMPTeamsDirective> in(const Index &index);
  static gap::generator<OMPTeamsDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTeamsDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TEAMS_DIRECTIVE;
  }

  static gap::generator<OMPTeamsDirective> containing(const Decl &decl);
  static gap::generator<OMPTeamsDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTeamsDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTeamsDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPTeamsDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPTeamsDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<OMPTeamsDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTeamsDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTeamsDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTeamsDirective> from(const Stmt &parent);

  inline static std::optional<OMPTeamsDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTeamsDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTeamsDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
