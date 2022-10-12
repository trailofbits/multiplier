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
#include "RedeclarableTemplateDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class RedeclarableTemplateDecl;
class TemplateDecl;
class VarTemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using VarTemplateDeclRange = DerivedEntityRange<DeclIterator, VarTemplateDecl>;
using VarTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, VarTemplateDecl>;
using VarTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, VarTemplateDecl>;

class VarTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static VarTemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VarTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : VarTemplateDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::VAR_TEMPLATE;
  }

  static VarTemplateDeclContainingDeclRange containing(const Decl &decl);
  static VarTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<VarTemplateDecl> from(const TokenContext &c);
  static std::optional<VarTemplateDecl> from(const RedeclarableTemplateDecl &parent);

  inline static std::optional<VarTemplateDecl> from(const std::optional<RedeclarableTemplateDecl> &parent) {
    if (parent) {
      return VarTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplateDecl> from(const TemplateDecl &parent);

  inline static std::optional<VarTemplateDecl> from(const std::optional<TemplateDecl> &parent) {
    if (parent) {
      return VarTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplateDecl> from(const NamedDecl &parent);

  inline static std::optional<VarTemplateDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return VarTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplateDecl> from(const Decl &parent);

  inline static std::optional<VarTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return VarTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(VarTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
