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
#include "VarTemplateSpecializationDecl.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class NamedDecl;
class ValueDecl;
class VarDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using VarTemplatePartialSpecializationDeclRange = DerivedEntityRange<DeclIterator, VarTemplatePartialSpecializationDecl>;
using VarTemplatePartialSpecializationDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, VarTemplatePartialSpecializationDecl>;
using VarTemplatePartialSpecializationDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, VarTemplatePartialSpecializationDecl>;

class VarTemplatePartialSpecializationDecl : public VarTemplateSpecializationDecl {
 private:
  friend class FragmentImpl;
  friend class VarTemplateSpecializationDecl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static VarTemplatePartialSpecializationDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VarTemplatePartialSpecializationDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : VarTemplatePartialSpecializationDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION;
  }

  static VarTemplatePartialSpecializationDeclContainingDeclRange containing(const Decl &decl);
  static VarTemplatePartialSpecializationDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<VarTemplatePartialSpecializationDecl> from(const TokenContext &c);
  static std::optional<VarTemplatePartialSpecializationDecl> from(const VarTemplateSpecializationDecl &parent);

  inline static std::optional<VarTemplatePartialSpecializationDecl> from(const std::optional<VarTemplateSpecializationDecl> &parent) {
    if (parent) {
      return VarTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplatePartialSpecializationDecl> from(const VarDecl &parent);

  inline static std::optional<VarTemplatePartialSpecializationDecl> from(const std::optional<VarDecl> &parent) {
    if (parent) {
      return VarTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplatePartialSpecializationDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<VarTemplatePartialSpecializationDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return VarTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplatePartialSpecializationDecl> from(const ValueDecl &parent);

  inline static std::optional<VarTemplatePartialSpecializationDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return VarTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplatePartialSpecializationDecl> from(const NamedDecl &parent);

  inline static std::optional<VarTemplatePartialSpecializationDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return VarTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplatePartialSpecializationDecl> from(const Decl &parent);

  inline static std::optional<VarTemplatePartialSpecializationDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return VarTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(VarTemplatePartialSpecializationDecl) == sizeof(VarTemplateSpecializationDecl));

#endif
} // namespace mx
