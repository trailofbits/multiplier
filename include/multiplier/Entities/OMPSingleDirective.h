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
class OMPSingleDirective;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPSingleDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPSingleDirective> in(const Fragment &frag);
  static gap::generator<OMPSingleDirective> in(const File &file);
  static gap::generator<OMPSingleDirective> in(const Index &index);
  static gap::generator<OMPSingleDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPSingleDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_SINGLE_DIRECTIVE;
  }

  static gap::generator<OMPSingleDirective> containing(const Decl &decl);
  static gap::generator<OMPSingleDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPSingleDirective> containing(const Stmt &stmt);
  static gap::generator<OMPSingleDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPSingleDirective> from(const Stmt &parent);

  inline static std::optional<OMPSingleDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPSingleDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPSingleDirective> from(const Reference &r) {
    return OMPSingleDirective::from(r.as_statement());
  }

  inline static std::optional<OMPSingleDirective> from(const TokenContext &t) {
    return OMPSingleDirective::from(t.as_statement());
  }

};

static_assert(sizeof(OMPSingleDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
