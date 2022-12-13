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
#include "NamedDecl.h"

namespace mx {
class Decl;
class LabelDecl;
class LabelStmt;
class NamedDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using LabelDeclRange = DerivedEntityRange<DeclIterator, LabelDecl>;
using LabelDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, LabelDecl>;
using LabelDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, LabelDecl>;

class LabelDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static LabelDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LabelDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : LabelDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::LABEL;
  }

  static LabelDeclContainingDeclRange containing(const Decl &decl);
  static LabelDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<LabelDecl> from(const TokenContext &c);
  static std::optional<LabelDecl> from(const NamedDecl &parent);

  inline static std::optional<LabelDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return LabelDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LabelDecl> from(const Decl &parent);

  inline static std::optional<LabelDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return LabelDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view ms_assembly_label(void) const;
  LabelStmt statement(void) const;
  bool is_gnu_local(void) const;
  bool is_ms_assembly_label(void) const;
  bool is_resolved_ms_assembly_label(void) const;
};

static_assert(sizeof(LabelDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
