// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "NamedDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class HLSLBufferDecl;
class NamedDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class HLSLBufferDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<HLSLBufferDecl> in(const Index &index);
  static gap::generator<HLSLBufferDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<HLSLBufferDecl> by_id(const Index &, EntityId);
  static gap::generator<HLSLBufferDecl> in(const Fragment &frag);
  static gap::generator<HLSLBufferDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::HLSL_BUFFER;
  }

  static gap::generator<HLSLBufferDecl> containing(const Decl &decl);
  static gap::generator<HLSLBufferDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<HLSLBufferDecl> containing(const Stmt &stmt);
  static gap::generator<HLSLBufferDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  HLSLBufferDecl canonical_declaration(void) const;
  std::optional<HLSLBufferDecl> definition(void) const;
  gap::generator<HLSLBufferDecl> redeclarations(void) const &;
  static std::optional<HLSLBufferDecl> from_base(const Decl &parent);
  inline static std::optional<HLSLBufferDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<HLSLBufferDecl> from(const std::optional<Decl> &parent);
  static std::optional<HLSLBufferDecl> from(const Reference &r);
  static std::optional<HLSLBufferDecl> from(const VariantEntity &e);
  static std::optional<HLSLBufferDecl> from(const TokenContext &t);

  Token l_brace_token(void) const;
  Token token_start(void) const;
  Token r_brace_token(void) const;
  bool is_c_buffer(void) const;
};

static_assert(sizeof(HLSLBufferDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
