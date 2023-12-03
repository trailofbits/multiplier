// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Stmt.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Stmt;
class SwitchCase;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT SwitchCase : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<SwitchCase> in(const Index &index);
  static gap::generator<SwitchCase> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwitchCase> by_id(const Index &, EntityId);
  static gap::generator<SwitchCase> in(const Fragment &frag);
  static gap::generator<SwitchCase> in(const File &file);

  static gap::generator<SwitchCase> containing(const Decl &decl);
  static gap::generator<SwitchCase> containing(const std::optional<Decl> &decl);

  static gap::generator<SwitchCase> containing(const Stmt &stmt);
  static gap::generator<SwitchCase> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SwitchCase> from_base(const Stmt &parent);
  inline static std::optional<SwitchCase> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<SwitchCase> from(const std::optional<Stmt> &parent);
  static std::optional<SwitchCase> from(const Reference &r);
  static std::optional<SwitchCase> from(const VariantEntity &e);
  static std::optional<SwitchCase> from(const TokenContext &t);

  Token colon_token(void) const;
  Token keyword_token(void) const;
  std::optional<SwitchCase> next_switch_case(void) const;
  Stmt sub_statement(void) const;
};

static_assert(sizeof(SwitchCase) == sizeof(Stmt));

#endif
} // namespace mx
