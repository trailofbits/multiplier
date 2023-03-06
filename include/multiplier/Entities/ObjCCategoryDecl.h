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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

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
class Stmt;
class Token;
class TokenRange;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCCategoryDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCCategoryDecl> in(const Fragment &frag);
  static gap::generator<ObjCCategoryDecl> in(const File &file);
  static gap::generator<ObjCCategoryDecl> in(const Index &index);
  static gap::generator<ObjCCategoryDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCCategoryDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_CATEGORY;
  }

  static gap::generator<ObjCCategoryDecl> containing(const Decl &decl);
  static gap::generator<ObjCCategoryDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCCategoryDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCCategoryDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCCategoryDecl> redeclarations(void) const &;
  static std::optional<ObjCCategoryDecl> from(const Decl &parent);

  inline static std::optional<ObjCCategoryDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCCategoryDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCCategoryDecl> from(const Reference &r) {
    return ObjCCategoryDecl::from(r.as_declaration());
  }

  inline static std::optional<ObjCCategoryDecl> from(const TokenContext &t) {
    return ObjCCategoryDecl::from(t.as_declaration());
  }

  bool is_class_extension(void) const;
  Token category_name_token(void) const;
  ObjCInterfaceDecl class_interface(void) const;
  ObjCCategoryImplDecl implementation(void) const;
  Token instance_variable_l_brace_token(void) const;
  Token instance_variable_r_brace_token(void) const;
  ObjCCategoryDecl next_class_category(void) const;
  std::optional<ObjCIvarDecl> nth_instance_variable(unsigned n) const;
  gap::generator<ObjCIvarDecl> instance_variables(void) const &;
  std::optional<Token> nth_protocol_token(unsigned n) const;
  gap::generator<Token> protocol_tokens(void) const &;
  std::optional<ObjCProtocolDecl> nth_protocol(unsigned n) const;
  gap::generator<ObjCProtocolDecl> protocols(void) const &;
};

static_assert(sizeof(ObjCCategoryDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
