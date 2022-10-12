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
#include "OMPDeclarativeDirectiveValueDecl.h"

namespace mx {
class Decl;
class Expr;
class NamedDecl;
class OMPDeclarativeDirectiveValueDecl;
class OMPDeclareMapperDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPDeclareMapperDeclRange = DerivedEntityRange<DeclIterator, OMPDeclareMapperDecl>;
using OMPDeclareMapperDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDeclareMapperDecl>;
using OMPDeclareMapperDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPDeclareMapperDecl>;

class OMPDeclareMapperDecl : public OMPDeclarativeDirectiveValueDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveValueDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static OMPDeclareMapperDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDeclareMapperDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPDeclareMapperDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_DECLARE_MAPPER;
  }

  static OMPDeclareMapperDeclContainingDeclRange containing(const Decl &decl);
  static OMPDeclareMapperDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPDeclareMapperDecl> from(const TokenContext &c);
  static std::optional<OMPDeclareMapperDecl> from(const OMPDeclarativeDirectiveValueDecl &parent);

  inline static std::optional<OMPDeclareMapperDecl> from(const std::optional<OMPDeclarativeDirectiveValueDecl> &parent) {
    if (parent) {
      return OMPDeclareMapperDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclareMapperDecl> from(const ValueDecl &parent);

  inline static std::optional<OMPDeclareMapperDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return OMPDeclareMapperDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclareMapperDecl> from(const NamedDecl &parent);

  inline static std::optional<OMPDeclareMapperDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return OMPDeclareMapperDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclareMapperDecl> from(const Decl &parent);

  inline static std::optional<OMPDeclareMapperDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPDeclareMapperDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr mapper_variable_reference(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(OMPDeclareMapperDecl) == sizeof(OMPDeclarativeDirectiveValueDecl));

#endif
} // namespace mx
