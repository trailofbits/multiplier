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
#include "DeclUseSelector.h"
#include "ObjCContainerDecl.h"
#include "TypeUseSelector.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCCategoryDecl;
class ObjCContainerDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class ObjCProtocolDecl;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCInterfaceDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<ObjCInterfaceDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ObjCInterfaceDecl> containing(const Token &tok) {
    for(auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCInterfaceDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_INTERFACE;
  }

  static gap::generator<ObjCInterfaceDecl> containing(const Decl &decl);
  static gap::generator<ObjCInterfaceDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCInterfaceDecl> from(const TokenContext &c);
  static std::optional<ObjCInterfaceDecl> from(const ObjCContainerDecl &parent);

  inline static std::optional<ObjCInterfaceDecl> from(const std::optional<ObjCContainerDecl> &parent) {
    if (parent) {
      return ObjCInterfaceDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCInterfaceDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCInterfaceDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCInterfaceDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCInterfaceDecl> from(const Decl &parent);

  inline static std::optional<ObjCInterfaceDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCInterfaceDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<ObjCProtocolDecl> all_referenced_protocols(void) const;
  bool declares_or_inherits_designated_initializers(void) const;
  Token end_of_definition_token(void) const;
  ObjCImplementationDecl implementation(void) const;
  std::string_view obj_c_runtime_name_as_string(void) const;
  std::optional<ObjCInterfaceDecl> super_class(void) const;
  Token super_class_token(void) const;
  std::optional<Type> super_class_type(void) const;
  Type type_for_declaration(void) const;
  bool has_definition(void) const;
  bool has_designated_initializers(void) const;
  bool is_arc_weakref_unavailable(void) const;
  bool is_implicit_interface_declaration(void) const;
  ObjCInterfaceDecl is_obj_c_requires_property_definitions(void) const;
  std::vector<ObjCIvarDecl> instance_variables(void) const;
  std::vector<ObjCCategoryDecl> known_categories(void) const;
  std::vector<ObjCCategoryDecl> known_extensions(void) const;
  std::vector<Token> protocol_tokens(void) const;
  std::vector<ObjCProtocolDecl> protocols(void) const;
  std::vector<ObjCCategoryDecl> visible_categories(void) const;
  std::vector<ObjCCategoryDecl> visible_extensions(void) const;
};

static_assert(sizeof(ObjCInterfaceDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
