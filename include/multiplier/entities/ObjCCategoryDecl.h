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
#include "ObjCContainerDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCContainerDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class ObjCProtocolDecl;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCCategoryDeclRange = DerivedEntityRange<DeclIterator, ObjCCategoryDecl>;
using ObjCCategoryDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCCategoryDecl>;
using ObjCCategoryDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCCategoryDecl>;

class ObjCCategoryDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCCategoryDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCCategoryDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCCategoryDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_CATEGORY;
  }

  static ObjCCategoryDeclContainingDeclRange containing(const Decl &decl);
  static ObjCCategoryDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCCategoryDecl> from(const TokenContext &c);
  static std::optional<ObjCCategoryDecl> from(const ObjCContainerDecl &parent);

  inline static std::optional<ObjCCategoryDecl> from(const std::optional<ObjCContainerDecl> &parent) {
    if (parent) {
      return ObjCCategoryDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCCategoryDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCCategoryDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCCategoryDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCCategoryDecl> from(const Decl &parent);

  inline static std::optional<ObjCCategoryDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCCategoryDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_class_extension(void) const;
  Token category_name_token(void) const;
  ObjCInterfaceDecl class_interface(void) const;
  ObjCCategoryImplDecl implementation(void) const;
  Token instance_variable_l_brace_token(void) const;
  Token instance_variable_r_brace_token(void) const;
  ObjCCategoryDecl next_class_category(void) const;
  std::vector<ObjCIvarDecl> instance_variables(void) const;
  std::vector<Token> protocol_tokens(void) const;
  std::vector<ObjCProtocolDecl> protocols(void) const;
};

static_assert(sizeof(ObjCCategoryDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
