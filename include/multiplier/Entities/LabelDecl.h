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

#include "DeclKind.h"
#include "NamedDecl.h"

namespace mx {
class Decl;
class LabelDecl;
class LabelStmt;
class NamedDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LabelDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<LabelDecl> in(const Fragment &frag);
  static gap::generator<LabelDecl> in(const Index &index);
  static gap::generator<LabelDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<LabelDecl> by(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::LABEL;
  }

  static gap::generator<LabelDecl> containing(const Decl &decl);
  static gap::generator<LabelDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<LabelDecl> containing(const Stmt &stmt);
  static gap::generator<LabelDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<LabelDecl> redeclarations(void) const;
  inline static std::optional<LabelDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<LabelDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<LabelDecl> from(const NamedDecl &parent);

  inline static std::optional<LabelDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return LabelDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LabelDecl> from(const Decl &parent);

  inline static std::optional<LabelDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return LabelDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view ms_assembly_label(void) const;
  LabelStmt statement(void) const;
  bool is_gnu_local(void) const;
  bool is_ms_assembly_label(void) const;
  bool is_resolved_ms_assembly_label(void) const;
};

static_assert(sizeof(LabelDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
