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
class BuiltinTemplateDecl;
class Decl;
class NamedDecl;
class TemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BuiltinTemplateDeclRange = DerivedEntityRange<DeclIterator, BuiltinTemplateDecl>;
using BuiltinTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, BuiltinTemplateDecl>;
using BuiltinTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, BuiltinTemplateDecl>;

class BuiltinTemplateDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static BuiltinTemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BuiltinTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : BuiltinTemplateDecl::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::BUILTIN_TEMPLATE;
  }

  static BuiltinTemplateDeclContainingDeclRange containing(const Decl &decl);
  static BuiltinTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BuiltinTemplateDecl> from(const TokenContext &c);
  static std::optional<BuiltinTemplateDecl> from(const TemplateDecl &parent);

  inline static std::optional<BuiltinTemplateDecl> from(const std::optional<TemplateDecl> &parent) {
    if (parent) {
      return BuiltinTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BuiltinTemplateDecl> from(const NamedDecl &parent);

  inline static std::optional<BuiltinTemplateDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return BuiltinTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BuiltinTemplateDecl> from(const Decl &parent);

  inline static std::optional<BuiltinTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return BuiltinTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(BuiltinTemplateDecl) == sizeof(TemplateDecl));

#endif
} // namespace mx
