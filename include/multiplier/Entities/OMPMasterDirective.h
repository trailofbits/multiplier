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
class OMPMasterDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPMasterDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPMasterDirective> in(const Fragment &frag);
  static gap::generator<OMPMasterDirective> in(const File &file);
  static gap::generator<OMPMasterDirective> in(const Index &index);
  static gap::generator<OMPMasterDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPMasterDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_MASTER_DIRECTIVE;
  }

  static gap::generator<OMPMasterDirective> containing(const Decl &decl);
  static gap::generator<OMPMasterDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPMasterDirective> containing(const Stmt &stmt);
  static gap::generator<OMPMasterDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMasterDirective> from(const Stmt &parent);

  inline static std::optional<OMPMasterDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPMasterDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPMasterDirective> from(const Reference &r) {
    return OMPMasterDirective::from(r.as_statement());
  }

  inline static std::optional<OMPMasterDirective> from(const TokenContext &t) {
    return OMPMasterDirective::from(t.as_statement());
  }

};

static_assert(sizeof(OMPMasterDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
