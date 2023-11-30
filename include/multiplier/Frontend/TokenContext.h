// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>

#include "../Types.h"

namespace mx {

class Token;
class TokenContextReader;

// An edge from tokens to AST nodes containing those tokens. Only parsed tokens
// have token contexts. Multiple contexts may share the same parents. The token
// context tree is a sort of DAG, via mechanism called "aliases." This is to
// handle the challenges of C's bizarre declaration syntax. For example:
//
//   int foo(void (*func_ptr)(...));
//
// This declares `func_ptr` as a function pointer-typed parameter of `foo`. The
// token contexts for this would have `func_ptr` link to something like:
//
//   foo ----------------------------------------------------.
//   ...                                                     |
//   func_ptr -> ParmVarDecl -> FunctionType -> ParmVarDecl -+-> FunctionDecl
//                    |                              ^
//                    '----------- alias ------------'
class TokenContext {
 private:
  friend class Token;

  std::shared_ptr<const TokenContextReader> reader;

  // Offset of this token context inside of the fragment.
  unsigned offset{0};

  // Offset of this token context's parent within the fragment.
  std::optional<unsigned> parent_offset;

  // Offset of this context's alias within the fragment.
  std::optional<unsigned> alias_offset;

  // Entity to which this token context refers. In general, this belongs to
  // the current fragment, but in rare instances it may not.
  RawEntityId entity_id{kInvalidEntityId};

  inline TokenContext(std::shared_ptr<const TokenContextReader> reader_)
      : reader(std::move(reader_)) {}

 public:
  inline bool has_parent(void) const noexcept {
    return parent_offset.has_value();
  }

  inline bool is_alias(void) const noexcept {
    return alias_offset.has_value();
  }

  // NOTE(pag): This is sort of an internal API, though it makes it convenient
  //            to identify token contexts.
  inline unsigned index_in_fragment(void) const noexcept {
    return offset;
  }

#define MX_FORWARD_DECLARE_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> as_ ## lower_name(void) const;

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_FORWARD_DECLARE_GETTER

  // Return the aliased context, if any.
  std::optional<TokenContext> aliasee(void) const;

  // Return the parent context, if any.
  std::optional<TokenContext> parent(void) const;
};

}  // namespace mx