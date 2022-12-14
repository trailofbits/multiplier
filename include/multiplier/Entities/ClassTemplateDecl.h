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
#include "RedeclarableTemplateDecl.h"

namespace mx {
class ClassTemplateDecl;
class Decl;
class NamedDecl;
class RedeclarableTemplateDecl;
class TemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ClassTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ClassTemplateDecl>;
using ClassTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ClassTemplateDecl>;

class ClassTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<ClassTemplateDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ClassTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ClassTemplateDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CLASS_TEMPLATE;
  }

  static ClassTemplateDeclContainingDeclRange containing(const Decl &decl);
  static ClassTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ClassTemplateDecl> from(const TokenContext &c);
  static std::optional<ClassTemplateDecl> from(const RedeclarableTemplateDecl &parent);

  inline static std::optional<ClassTemplateDecl> from(const std::optional<RedeclarableTemplateDecl> &parent) {
    if (parent) {
      return ClassTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateDecl> from(const TemplateDecl &parent);

  inline static std::optional<ClassTemplateDecl> from(const std::optional<TemplateDecl> &parent) {
    if (parent) {
      return ClassTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateDecl> from(const NamedDecl &parent);

  inline static std::optional<ClassTemplateDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ClassTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateDecl> from(const Decl &parent);

  inline static std::optional<ClassTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ClassTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ClassTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
