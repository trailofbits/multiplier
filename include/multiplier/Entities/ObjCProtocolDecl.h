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

#include "DeclKind.h"
#include "ObjCContainerDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCContainerDecl;
class ObjCProtocolDecl;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCProtocolDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCProtocolDecl> in(const Fragment &frag);
  static gap::generator<ObjCProtocolDecl> in(const File &file);
  static gap::generator<ObjCProtocolDecl> in(const Index &index);
  static gap::generator<ObjCProtocolDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCProtocolDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_PROTOCOL;
  }

  static gap::generator<ObjCProtocolDecl> containing(const Decl &decl);
  static gap::generator<ObjCProtocolDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCProtocolDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCProtocolDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCProtocolDecl> redeclarations(void) const &;
  static std::optional<ObjCProtocolDecl> from(const Decl &parent);

  inline static std::optional<ObjCProtocolDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCProtocolDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCProtocolDecl> from(const Reference &r) {
    return ObjCProtocolDecl::from(r.as_declaration());
  }

  inline static std::optional<ObjCProtocolDecl> from(const TokenContext &t) {
    return ObjCProtocolDecl::from(t.as_declaration());
  }

  std::string_view obj_c_runtime_name_as_string(void) const;
  bool has_definition(void) const;
  bool is_non_runtime_protocol(void) const;
  bool is_this_declaration_a_definition(void) const;
  std::optional<Token> nth_protocol_token(unsigned n) const;
  gap::generator<Token> protocol_tokens(void) const &;
  std::optional<ObjCProtocolDecl> nth_protocol(unsigned n) const;
  gap::generator<ObjCProtocolDecl> protocols(void) const &;
};

static_assert(sizeof(ObjCProtocolDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
