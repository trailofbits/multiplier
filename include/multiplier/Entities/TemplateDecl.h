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
#include "NamedDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TemplateDeclRange = DerivedEntityRange<DeclIterator, TemplateDecl>;
using TemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TemplateDecl>;
using TemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TemplateDecl>;

class TemplateDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : TemplateDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TEMPLATE;
  }

  static TemplateDeclContainingDeclRange containing(const Decl &decl);
  static TemplateDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TemplateDecl> from(const TokenContext &c);
  static std::optional<TemplateDecl> from(const NamedDecl &parent);

  inline static std::optional<TemplateDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateDecl> from(const Decl &parent);

  inline static std::optional<TemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(TemplateDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
