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
#include "TemplateDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class RedeclarableTemplateDecl;
class TemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using RedeclarableTemplateDeclRange = DerivedEntityRange<DeclIterator, RedeclarableTemplateDecl>;
using RedeclarableTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, RedeclarableTemplateDecl>;
using RedeclarableTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, RedeclarableTemplateDecl>;

class RedeclarableTemplateDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static RedeclarableTemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RedeclarableTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : RedeclarableTemplateDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::REDECLARABLE_TEMPLATE;
  }

  static RedeclarableTemplateDeclContainingDeclRange containing(const Decl &decl);
  static RedeclarableTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<RedeclarableTemplateDecl> from(const TokenContext &c);
  static std::optional<RedeclarableTemplateDecl> from(const TemplateDecl &parent);

  inline static std::optional<RedeclarableTemplateDecl> from(const std::optional<TemplateDecl> &parent) {
    if (parent) {
      return RedeclarableTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RedeclarableTemplateDecl> from(const NamedDecl &parent);

  inline static std::optional<RedeclarableTemplateDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return RedeclarableTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RedeclarableTemplateDecl> from(const Decl &parent);

  inline static std::optional<RedeclarableTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return RedeclarableTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(RedeclarableTemplateDecl) == sizeof(TemplateDecl));

#endif
} // namespace mx
