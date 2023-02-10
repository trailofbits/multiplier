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
class OMPMetaDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPMetaDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPMetaDirective> in(const Fragment &frag);
  static gap::generator<OMPMetaDirective> in(const File &file);
  static gap::generator<OMPMetaDirective> in(const Index &index);
  static gap::generator<OMPMetaDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPMetaDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_META_DIRECTIVE;
  }

  static gap::generator<OMPMetaDirective> containing(const Decl &decl);
  static gap::generator<OMPMetaDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPMetaDirective> containing(const Stmt &stmt);
  static gap::generator<OMPMetaDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMetaDirective> from(const Stmt &parent);

  inline static std::optional<OMPMetaDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPMetaDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPMetaDirective> from(const Reference &r) {
    return OMPMetaDirective::from(r.as_statement());
  }

  inline static std::optional<OMPMetaDirective> from(const TokenContext &t) {
    return OMPMetaDirective::from(t.as_statement());
  }

  Stmt if_statement(void) const;
};

static_assert(sizeof(OMPMetaDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
