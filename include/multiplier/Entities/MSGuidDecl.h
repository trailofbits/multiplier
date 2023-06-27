// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ValueDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class MSGuidDecl;
class NamedDecl;
class Stmt;
class Token;
class ValueDecl;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSGuidDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<MSGuidDecl> in(const Fragment &frag);
  static gap::generator<MSGuidDecl> in(const File &file);
  static gap::generator<MSGuidDecl> in(const Index &index);
  static gap::generator<MSGuidDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MSGuidDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::MS_GUID;
  }

  static gap::generator<MSGuidDecl> containing(const Decl &decl);
  static gap::generator<MSGuidDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<MSGuidDecl> containing(const Stmt &stmt);
  static gap::generator<MSGuidDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  MSGuidDecl canonical_declaration(void) const;
  std::optional<MSGuidDecl> definition(void) const;
  gap::generator<MSGuidDecl> redeclarations(void) const &;
  static std::optional<MSGuidDecl> from(const Decl &parent);

  inline static std::optional<MSGuidDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return MSGuidDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSGuidDecl> from(const Reference &r);
  static std::optional<MSGuidDecl> from(const TokenContext &t);

};

static_assert(sizeof(MSGuidDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
