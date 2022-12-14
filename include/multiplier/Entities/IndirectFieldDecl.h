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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclKind.h"
#include "DeclUseSelector.h"
#include "ValueDecl.h"

namespace mx {
class Decl;
class FieldDecl;
class IndirectFieldDecl;
class NamedDecl;
class ValueDecl;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using IndirectFieldDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, IndirectFieldDecl>;
using IndirectFieldDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, IndirectFieldDecl>;

class IndirectFieldDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<IndirectFieldDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static IndirectFieldDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : IndirectFieldDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::INDIRECT_FIELD;
  }

  static IndirectFieldDeclContainingDeclRange containing(const Decl &decl);
  static IndirectFieldDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<IndirectFieldDecl> from(const TokenContext &c);
  static std::optional<IndirectFieldDecl> from(const ValueDecl &parent);

  inline static std::optional<IndirectFieldDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return IndirectFieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IndirectFieldDecl> from(const NamedDecl &parent);

  inline static std::optional<IndirectFieldDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return IndirectFieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IndirectFieldDecl> from(const Decl &parent);

  inline static std::optional<IndirectFieldDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return IndirectFieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<NamedDecl> chain(void) const;
  std::optional<FieldDecl> anonymous_field(void) const;
  std::optional<VarDecl> variable_declaration(void) const;
};

static_assert(sizeof(IndirectFieldDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
