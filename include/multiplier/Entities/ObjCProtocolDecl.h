// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ObjCContainerDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class NamedDecl;
class ObjCContainerDecl;
class ObjCProtocolDecl;
class Stmt;
class Token;
class TokenRange;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

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

  ObjCProtocolDecl canonical_declaration(void) const;
  std::optional<ObjCProtocolDecl> definition(void) const;
  gap::generator<ObjCProtocolDecl> redeclarations(void) const &;
  static std::optional<ObjCProtocolDecl> from(const Decl &parent);

  inline static std::optional<ObjCProtocolDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCProtocolDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCProtocolDecl> from(const Reference &r);
  static std::optional<ObjCProtocolDecl> from(const TokenContext &t);

  std::string_view obj_c_runtime_name_as_string(void) const;
  bool has_definition(void) const;
  bool is_non_runtime_protocol(void) const;
  bool is_this_declaration_a_definition(void) const;
  std::optional<Token> nth_protocol_token(unsigned n) const;
  unsigned num_protocol_tokens(void) const;
  gap::generator<Token> protocol_tokens(void) const &;
  std::optional<ObjCProtocolDecl> nth_protocol(unsigned n) const;
  unsigned num_protocols(void) const;
  gap::generator<ObjCProtocolDecl> protocols(void) const &;
};

static_assert(sizeof(ObjCProtocolDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
