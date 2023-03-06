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

#include "VarDecl.h"

namespace mx {
class BindingDecl;
class Decl;
class DeclaratorDecl;
class DecompositionDecl;
class NamedDecl;
class Stmt;
class Token;
class ValueDecl;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DecompositionDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<DecompositionDecl> in(const Fragment &frag);
  static gap::generator<DecompositionDecl> in(const File &file);
  static gap::generator<DecompositionDecl> in(const Index &index);
  static gap::generator<DecompositionDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DecompositionDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::DECOMPOSITION;
  }

  static gap::generator<DecompositionDecl> containing(const Decl &decl);
  static gap::generator<DecompositionDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<DecompositionDecl> containing(const Stmt &stmt);
  static gap::generator<DecompositionDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<DecompositionDecl> redeclarations(void) const &;
  static std::optional<DecompositionDecl> from(const Decl &parent);

  inline static std::optional<DecompositionDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return DecompositionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<DecompositionDecl> from(const Reference &r) {
    return DecompositionDecl::from(r.as_declaration());
  }

  inline static std::optional<DecompositionDecl> from(const TokenContext &t) {
    return DecompositionDecl::from(t.as_declaration());
  }

  std::optional<BindingDecl> nth_binding(unsigned n) const;
  gap::generator<BindingDecl> bindings(void) const &;
};

static_assert(sizeof(DecompositionDecl) == sizeof(VarDecl));

#endif
} // namespace mx
