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

#include "StmtKind.h"

namespace mx {
class Reference;
class Stmt;
class StmtImpl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Stmt {
 protected:
  friend class Attr;
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class Reference;
  friend class TokenContext;
  friend class Type;
  friend class StmtImpl;
  std::shared_ptr<const StmtImpl> impl;
 public:
  Stmt(Stmt &&) noexcept = default;
  Stmt(const Stmt &) = default;
  Stmt &operator=(Stmt &&) noexcept = default;
  Stmt &operator=(const Stmt &) = default;

  /* implicit */ inline Stmt(std::shared_ptr<const StmtImpl> impl_)
      : impl(std::move(impl_)) {}

  PackedStmtId id(void) const;
  gap::generator<Reference> references(void) const;

  std::optional<Decl> parent_declaration(void) const;
  std::optional<Stmt> parent_statement(void) const;
  std::optional<PackedDeclId> referenced_declaration_id(void) const;
  std::optional<Decl> referenced_declaration(void) const;
 protected:
  static gap::generator<Stmt> in_internal(const Fragment &fragment);

 public:
  static gap::generator<Stmt> in(const Fragment &frag);
  static gap::generator<Stmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static gap::generator<Stmt> containing(const Decl &decl);
  static gap::generator<Stmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<Stmt> from(const Stmt &self) {
    return self;
  }

  inline static std::optional<Stmt> from(const std::optional<Stmt> &self) {
    return self;
  }

  inline static std::optional<Stmt> from(const Reference &r) {
    return r.as_statement();
  }

  inline static std::optional<Stmt> from(const TokenContext &t) {
    return t.as_statement();
  }

  Stmt ignore_containers(void) const;
  gap::generator<Stmt> children(void) const;
  TokenRange tokens(void) const;
  StmtKind kind(void) const;
  Stmt strip_label_like_statements(void) const;
};

#endif
} // namespace mx
