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

#include "Decl.h"
#include "DeclKind.h"
#include "Linkage.h"
#include "ObjCStringFormatFamily.h"
#include "Visibility.h"

namespace mx {
class Decl;
class NamedDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NamedDeclRange = DerivedEntityRange<DeclIterator, NamedDecl>;
using NamedDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, NamedDecl>;
using NamedDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, NamedDecl>;

class NamedDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static NamedDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NamedDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NamedDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::NAMED;
  }

  static NamedDeclContainingDeclRange containing(const Decl &decl);
  static NamedDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<NamedDecl> from(const TokenContext &c);
  static std::optional<NamedDecl> from(const Decl &parent);

  inline static std::optional<NamedDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return NamedDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Linkage formal_linkage(void) const;
  std::string_view name(void) const;
  std::optional<ObjCStringFormatFamily> obj_cf_string_formatting_family(void) const;
  std::string_view qualified_name_as_string(void) const;
  NamedDecl underlying_declaration(void) const;
  Visibility visibility(void) const;
  bool has_external_formal_linkage(void) const;
  bool has_linkage(void) const;
  bool has_linkage_been_computed(void) const;
  bool is_cxx_class_member(void) const;
  bool is_cxx_instance_member(void) const;
  bool is_externally_declarable(void) const;
  bool is_externally_visible(void) const;
  bool is_linkage_valid(void) const;
};

static_assert(sizeof(NamedDecl) == sizeof(Decl));

#endif
} // namespace mx
