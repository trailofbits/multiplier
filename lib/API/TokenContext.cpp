// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

namespace mx {

// Return the token context associated with a token.
//
// NOTE(pag): This only works with parsed tokens, and not all parsed tokens
//            are guaranteed to have a context.
std::optional<TokenContext> TokenContext::of(const Token &tok) {
  if (!tok.impl) {
    return std::nullopt;
  }

  auto frag = dynamic_cast<const PackedFragmentImpl *>(tok.impl.get());
  if (!frag) {
    return std::nullopt;
  }

  auto tc = frag->Fragment().getTokenContexts()[tok.index];
  auto index_kind = tc.getParentIndexAndKind();
  if (!index_kind) {
    return std::nullopt;
  }

  index_kind >>= 1u;

  std::shared_ptr<const FragmentImpl> frag_ptr(tok.impl, frag);

  // NOTE(pag): +1 to skip `kInvalid`.
  TokenContext ret(std::move(frag_ptr));
  ret.kind = static_cast<Kind>((index_kind & 0x3) + 1);
  ret.index = index_kind >> 2u;
  ret.offset = tc.getParentOffset();
  return ret;
}

std::optional<Decl> TokenContext::as_decl(void) const {
  if (kind != kDecl && kind != kDeclAlias) {
    return std::nullopt;
  } else if (!impl) {
    return std::nullopt;
  } else {
    return Decl(impl, index);
  }
}

std::optional<Stmt> TokenContext::as_stmt(void) const {
  if (kind != kStmt && kind != kStmtAlias) {
    return std::nullopt;
  } else if (!impl) {
    return std::nullopt;
  } else {
    return Stmt(impl, index);
  }
}

// Return the aliased context.
std::optional<TokenContext> TokenContext::aliasee(void) const {
  if (!impl) {
    return std::nullopt;

  } else if (kind == kDeclAlias) {
    auto tc = impl->Fragment().getTokenContexts()[offset];
    TokenContext ret(impl);
    ret.kind = kDecl;
    ret.index = index;
    ret.offset = tc.getAliasOffset();
    return ret;

  } else if (kind == kStmtAlias) {
    auto tc = impl->Fragment().getTokenContexts()[offset];
    TokenContext ret(impl);
    ret.kind = kStmt;
    ret.index = index;
    ret.offset = tc.getAliasOffset();
    return ret;

  } else {
    return std::nullopt;
  }
}

// Return the parent context.
std::optional<TokenContext> TokenContext::parent(void) const {
  if (!impl) {
    return std::nullopt;

  } else if (kind == kDecl || kind == kDeclAlias ||
             kind == kStmt || kind == kStmtAlias) {
    auto tc = impl->Fragment().getTokenContexts()[offset];
    auto index_kind = tc.getParentIndexAndKind();
    if (!index_kind) {
      return std::nullopt;
    }

    index_kind >>= 1u;

    // NOTE(pag): `+1` to skip `kInvalid`.
    TokenContext ret(impl);
    ret.kind = static_cast<Kind>((index_kind & 0x3) + 1);
    ret.index = index_kind >> 2u;
    ret.offset = tc.getParentOffset();
    return ret;
  } else {
    return std::nullopt;
  }
}

}  // namespace mx
