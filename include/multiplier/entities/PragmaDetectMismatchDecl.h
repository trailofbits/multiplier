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

#include "Decl.h"
#include "DeclKind.h"

namespace mx {
class Decl;
class PragmaDetectMismatchDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using PragmaDetectMismatchDeclRange = DerivedEntityRange<DeclIterator, PragmaDetectMismatchDecl>;
using PragmaDetectMismatchDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, PragmaDetectMismatchDecl>;
using PragmaDetectMismatchDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, PragmaDetectMismatchDecl>;

class PragmaDetectMismatchDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static PragmaDetectMismatchDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static PragmaDetectMismatchDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : PragmaDetectMismatchDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::PRAGMA_DETECT_MISMATCH;
  }

  static PragmaDetectMismatchDeclContainingDeclRange containing(const Decl &decl);
  static PragmaDetectMismatchDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<PragmaDetectMismatchDecl> from(const TokenContext &c);
  static std::optional<PragmaDetectMismatchDecl> from(const Decl &parent);

  inline static std::optional<PragmaDetectMismatchDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return PragmaDetectMismatchDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view name(void) const;
  std::string_view value(void) const;
};

static_assert(sizeof(PragmaDetectMismatchDecl) == sizeof(Decl));

#endif
} // namespace mx
