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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclKind.h"
#include "VarDecl.h"

namespace mx {
class BindingDecl;
class Decl;
class DeclaratorDecl;
class DecompositionDecl;
class NamedDecl;
class ValueDecl;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DecompositionDeclRange = DerivedEntityRange<DeclIterator, DecompositionDecl>;
using DecompositionDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, DecompositionDecl>;
using DecompositionDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, DecompositionDecl>;

class DecompositionDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static DecompositionDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DecompositionDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DecompositionDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::DECOMPOSITION;
  }

  static DecompositionDeclContainingDeclRange containing(const Decl &decl);
  static DecompositionDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DecompositionDecl> from(const TokenContext &c);
  static std::optional<DecompositionDecl> from(const VarDecl &parent);

  inline static std::optional<DecompositionDecl> from(const std::optional<VarDecl> &parent) {
    if (parent) {
      return DecompositionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DecompositionDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<DecompositionDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return DecompositionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DecompositionDecl> from(const ValueDecl &parent);

  inline static std::optional<DecompositionDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return DecompositionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DecompositionDecl> from(const NamedDecl &parent);

  inline static std::optional<DecompositionDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return DecompositionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DecompositionDecl> from(const Decl &parent);

  inline static std::optional<DecompositionDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return DecompositionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<BindingDecl> bindings(void) const;
};

static_assert(sizeof(DecompositionDecl) == sizeof(VarDecl));

#endif
} // namespace mx
