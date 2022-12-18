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
#include "ObjCImplDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCImplementationDeclRange = DerivedEntityRange<DeclIterator, ObjCImplementationDecl>;
using ObjCImplementationDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCImplementationDecl>;
using ObjCImplementationDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCImplementationDecl>;

class ObjCImplementationDecl : public ObjCImplDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCImplDecl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCImplementationDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCImplementationDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCImplementationDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_IMPLEMENTATION;
  }

  static ObjCImplementationDeclContainingDeclRange containing(const Decl &decl);
  static ObjCImplementationDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCImplementationDecl> from(const TokenContext &c);
  static std::optional<ObjCImplementationDecl> from(const ObjCImplDecl &parent);

  inline static std::optional<ObjCImplementationDecl> from(const std::optional<ObjCImplDecl> &parent) {
    if (parent) {
      return ObjCImplementationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCImplementationDecl> from(const ObjCContainerDecl &parent);

  inline static std::optional<ObjCImplementationDecl> from(const std::optional<ObjCContainerDecl> &parent) {
    if (parent) {
      return ObjCImplementationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCImplementationDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCImplementationDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCImplementationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCImplementationDecl> from(const Decl &parent);

  inline static std::optional<ObjCImplementationDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCImplementationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token instance_variable_l_brace_token(void) const;
  Token instance_variable_r_brace_token(void) const;
  std::string_view obj_c_runtime_name_as_string(void) const;
  ObjCInterfaceDecl super_class(void) const;
  Token super_class_token(void) const;
  bool has_destructors(void) const;
  bool has_non_zero_constructors(void) const;
  std::vector<ObjCIvarDecl> instance_variables(void) const;
};

static_assert(sizeof(ObjCImplementationDecl) == sizeof(ObjCImplDecl));

#endif
} // namespace mx
