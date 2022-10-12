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
class ObjCContainerDecl;
class ObjCProtocolDecl;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCProtocolDeclRange = DerivedEntityRange<DeclIterator, ObjCProtocolDecl>;
using ObjCProtocolDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCProtocolDecl>;
using ObjCProtocolDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCProtocolDecl>;

class ObjCProtocolDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCProtocolDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCProtocolDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCProtocolDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_PROTOCOL;
  }

  static ObjCProtocolDeclContainingDeclRange containing(const Decl &decl);
  static ObjCProtocolDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCProtocolDecl> from(const TokenContext &c);
  static std::optional<ObjCProtocolDecl> from(const ObjCContainerDecl &parent);

  inline static std::optional<ObjCProtocolDecl> from(const std::optional<ObjCContainerDecl> &parent) {
    if (parent) {
      return ObjCProtocolDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCProtocolDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCProtocolDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCProtocolDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCProtocolDecl> from(const Decl &parent);

  inline static std::optional<ObjCProtocolDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCProtocolDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view obj_c_runtime_name_as_string(void) const;
  bool has_definition(void) const;
  bool is_non_runtime_protocol(void) const;
  std::vector<Token> protocol_tokens(void) const;
  std::vector<ObjCProtocolDecl> protocols(void) const;
};

static_assert(sizeof(ObjCProtocolDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
