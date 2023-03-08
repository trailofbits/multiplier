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

#include "Decl.h"

namespace mx {
class Decl;
class PragmaDetectMismatchDecl;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PragmaDetectMismatchDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<PragmaDetectMismatchDecl> in(const Fragment &frag);
  static gap::generator<PragmaDetectMismatchDecl> in(const File &file);
  static gap::generator<PragmaDetectMismatchDecl> in(const Index &index);
  static gap::generator<PragmaDetectMismatchDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PragmaDetectMismatchDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::PRAGMA_DETECT_MISMATCH;
  }

  static gap::generator<PragmaDetectMismatchDecl> containing(const Decl &decl);
  static gap::generator<PragmaDetectMismatchDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<PragmaDetectMismatchDecl> containing(const Stmt &stmt);
  static gap::generator<PragmaDetectMismatchDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<PragmaDetectMismatchDecl> redeclarations(void) const &;
  static std::optional<PragmaDetectMismatchDecl> from(const Decl &parent);

  inline static std::optional<PragmaDetectMismatchDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return PragmaDetectMismatchDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<PragmaDetectMismatchDecl> from(const Reference &r) {
    return PragmaDetectMismatchDecl::from(r.as_declaration());
  }

  inline static std::optional<PragmaDetectMismatchDecl> from(const TokenContext &t) {
    return PragmaDetectMismatchDecl::from(t.as_declaration());
  }

  std::string_view name(void) const;
  std::string_view value(void) const;
};

static_assert(sizeof(PragmaDetectMismatchDecl) == sizeof(Decl));

#endif
} // namespace mx
