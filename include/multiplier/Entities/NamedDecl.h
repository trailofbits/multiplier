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

#include "Decl.h"
#include "DeclKind.h"
#include "Linkage.h"
#include "ObjCStringFormatFamily.h"
#include "Visibility.h"

namespace mx {
class Decl;
class NamedDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NamedDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static gap::generator<NamedDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<NamedDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : NamedDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static gap::generator<NamedDecl> containing(const Decl &decl);
  static gap::generator<NamedDecl> containing(const Stmt &stmt);

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
