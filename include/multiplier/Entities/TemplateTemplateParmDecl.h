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
class TemplateDecl;
class TemplateTemplateParmDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TemplateTemplateParmDeclRange = DerivedEntityRange<DeclIterator, TemplateTemplateParmDecl>;
using TemplateTemplateParmDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TemplateTemplateParmDecl>;
using TemplateTemplateParmDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TemplateTemplateParmDecl>;

class TemplateTemplateParmDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TemplateTemplateParmDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TemplateTemplateParmDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : TemplateTemplateParmDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TEMPLATE_TEMPLATE_PARM;
  }

  static TemplateTemplateParmDeclContainingDeclRange containing(const Decl &decl);
  static TemplateTemplateParmDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TemplateTemplateParmDecl> from(const TokenContext &c);
  static std::optional<TemplateTemplateParmDecl> from(const TemplateDecl &parent);

  inline static std::optional<TemplateTemplateParmDecl> from(const std::optional<TemplateDecl> &parent) {
    if (parent) {
      return TemplateTemplateParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateTemplateParmDecl> from(const NamedDecl &parent);

  inline static std::optional<TemplateTemplateParmDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TemplateTemplateParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateTemplateParmDecl> from(const Decl &parent);

  inline static std::optional<TemplateTemplateParmDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TemplateTemplateParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool default_argument_was_inherited(void) const;
  Token default_argument_token(void) const;
  bool has_default_argument(void) const;
  bool is_expanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
};

static_assert(sizeof(TemplateTemplateParmDecl) == sizeof(TemplateDecl));

#endif
} // namespace mx
