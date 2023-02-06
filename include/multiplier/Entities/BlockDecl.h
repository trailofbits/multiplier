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

#include "Decl.h"
#include "DeclKind.h"

namespace mx {
class BlockDecl;
class CompoundStmt;
class Decl;
class ParmVarDecl;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BlockDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<BlockDecl> in(const Fragment &frag);
  static gap::generator<BlockDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::BLOCK;
  }

  static gap::generator<BlockDecl> containing(const Decl &decl);
  static gap::generator<BlockDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<BlockDecl> redeclarations(void) const;
  inline static std::optional<BlockDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<BlockDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<BlockDecl> from(const Decl &parent);

  inline static std::optional<BlockDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return BlockDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool block_missing_return_type(void) const;
  bool can_avoid_copy_to_heap(void) const;
  bool captures_cxx_this(void) const;
  bool does_not_escape(void) const;
  std::optional<Decl> block_mangling_context_declaration(void) const;
  Token caret_token(void) const;
  CompoundStmt compound_body(void) const;
  Type signature_as_written(void) const;
  bool has_captures(void) const;
  bool is_conversion_from_lambda(void) const;
  bool is_variadic(void) const;
  std::optional<ParmVarDecl> nth_parameter(unsigned n) const;
  gap::generator<ParmVarDecl> parameters(void) const;
  std::optional<ParmVarDecl> nth_parameter_declaration(unsigned n) const;
  gap::generator<ParmVarDecl> parameter_declarations(void) const;
  gap::generator<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(BlockDecl) == sizeof(Decl));

#endif
} // namespace mx
