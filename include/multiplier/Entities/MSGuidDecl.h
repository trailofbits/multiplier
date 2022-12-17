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
#include "ValueDecl.h"

namespace mx {
class Decl;
class MSGuidDecl;
class NamedDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MSGuidDeclRange = DerivedEntityRange<DeclIterator, MSGuidDecl>;
using MSGuidDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, MSGuidDecl>;
using MSGuidDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, MSGuidDecl>;

class MSGuidDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static MSGuidDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MSGuidDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : MSGuidDecl::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::MS_GUID;
  }

  static MSGuidDeclContainingDeclRange containing(const Decl &decl);
  static MSGuidDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MSGuidDecl> from(const TokenContext &c);
  static std::optional<MSGuidDecl> from(const ValueDecl &parent);

  inline static std::optional<MSGuidDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return MSGuidDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSGuidDecl> from(const NamedDecl &parent);

  inline static std::optional<MSGuidDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return MSGuidDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSGuidDecl> from(const Decl &parent);

  inline static std::optional<MSGuidDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return MSGuidDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(MSGuidDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
