// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <optional>

#include "../Entity.h"
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
class MX_EXPORT TokenContext {
 private:
  friend class Token;

  std::shared_ptr<const TokenContextReader> reader;

  // Offset of this token context inside of the fragment.
  unsigned offset{0u};

  // Offset of this token context's parent within the fragment.
  std::optional<unsigned> parent_offset;

  // Entity to which this token context refers. In general, this belongs to
  // the current fragment, but in rare instances it may not.
  RawEntityId referenced_entity_id{kInvalidEntityId};

  TokenContext(void) = delete;

  inline TokenContext(std::shared_ptr<const TokenContextReader> reader_)
      : reader(std::move(reader_)) {}

  inline TokenContext(std::shared_ptr<const TokenContextReader> reader_,
                      RawEntityId referenced_entity_id_, unsigned offset_)
      : reader(std::move(reader_)),
        offset(offset_),
        referenced_entity_id(referenced_entity_id_) {}

 public:

  TokenContext(TokenContext &&) noexcept = default;
  TokenContext(const TokenContext &) noexcept = default;

  TokenContext &operator=(TokenContext &&) noexcept = default;
  TokenContext &operator=(const TokenContext &) noexcept = default;

  inline RawEntityId entity_id(void) const noexcept {
    return referenced_entity_id;
  }

  inline bool has_parent(void) const noexcept {
    return parent_offset.has_value();
  }

  // NOTE(pag): This is sort of an internal API, though it makes it convenient
  //            to identify token contexts.
  inline unsigned index_in_fragment(void) const noexcept {
    return offset;
  }

  // Return this TokenContext as a `VariantEntity`.
  VariantEntity as_variant(void) const noexcept;

#define MX_FORWARD_DECLARE_GETTER(ns_path, type_name, lower_name, enum_name, category) \
    std::optional<ns_path type_name> as_ ## lower_name(void) const;

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_FORWARD_DECLARE_GETTER

  // Return the parent context, if any.
  std::optional<TokenContext> parent(void) const;
};

}  // namespace mx
