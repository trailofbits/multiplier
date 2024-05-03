// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/coro/generator.hpp>
#include <memory>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

#include "Frontend/File.h"

namespace mx {
namespace ir {
class Operation;
}  // namespace ir

class EntityProvider;
class Index;
class InvalidEntityProvider;
class ReferenceIteratorImpl;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryMatch;

#define MX_FORWARD_DECLARE(ns_path, type_name, ln, e, c) \
    class type_name; \
    class type_name ## Impl;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_IGNORE_ENTITY_CATEGORY)
#undef MX_FORWARD_DECLARE

using MacroOrToken = std::variant<Macro, Token>;

// A fragment of code containing one or more top-level declarations, the
// associated declaration and statement entities, macro expansion/substitution
// trees, and tokens.
class MX_EXPORT Fragment {
 private:
  friend class Compilation;
  friend class CompilationImpl;
  friend class EntityProvider;
  friend class FragmentImpl;
  friend class Index;
  friend class Reference;
  friend class RemoteEntityProvider;
  friend class RegexQuery;
  friend class RegexQueryResultImpl;
  friend class TokenTree;
  friend class TokenTreeImpl;

#define MX_FRIEND(ns_path, type_name, ln, e, c) \
    friend class ns_path type_name;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND)
#undef MX_FRIEND

  std::shared_ptr<const FragmentImpl> impl;

 public:

  /* implicit */ inline Fragment(FragmentImplPtr impl_)
      : impl(std::move(impl_)) {}

  // A fragment can be nested inside of another fragment. This is very common
  // with C++ templates, but can also happen in C due to elaborated type uses,
  // such as `struct foo`, acting as forward declarations upon their first use.
  std::optional<Fragment> parent(void) const noexcept;
  std::optional<PackedFragmentId> parent_id(void) const noexcept;

  // Return a fragment's parent fragment. If this is a top-level fragment, then
  // this returns the argument.
  static Fragment containing(const Fragment &) noexcept;

  // Return the fragment containing a query match.
  static Fragment containing(const RegexQueryMatch &) noexcept;

  // Return the fragment containing a token tree.
  static std::optional<Fragment> containing(const TokenTree &) noexcept;

  static Fragment containing(const Decl &) noexcept;
  static Fragment containing(const Stmt &) noexcept;
  static Fragment containing(const Attr &) noexcept;
  static Fragment containing(const TemplateArgument &) noexcept;
  static Fragment containing(const TemplateParameterList &) noexcept;
  static Fragment containing(const CXXBaseSpecifier &) noexcept;
  static Fragment containing(const CXXCtorInitializer &) noexcept;
  static Fragment containing(const Designator &) noexcept;
  static std::optional<Fragment> containing(const Token &) noexcept;
  static Fragment containing(const Macro &) noexcept;
  static std::optional<Fragment> containing(const ir::Operation &) noexcept;
  static std::optional<Fragment> containing(const VariantEntity &) noexcept;

  // Try to convert a variant entity into a fragment.
  static std::optional<Fragment> from(const VariantEntity &) noexcept;

  // Generate all fragments in the index.
  static gap::generator<Fragment> in(const Index &index);

  inline static constexpr EntityCategory entity_category(void) noexcept {
    return EntityCategory::FRAGMENT;
  }

  // Return the entity ID of this fragment.
  PackedFragmentId id(void) const noexcept;

  // Returns the unique owning compilation that produced this fragment. There
  // may be many compilations which produced equivalent/redundant fragments, but
  // those redundancies are eliminated by the indexer.
  Compilation compilation(void) const noexcept;

  // The range of file tokens in this fragment.
  TokenRange file_tokens(void) const;

  // The range of parsed tokens in this fragment.
  TokenRange parsed_tokens(void) const;

  // Return child fragments.
  gap::generator<Fragment> nested_fragments(void) const &;

  // Return the list of top-level declarations in this fragment.
  gap::generator<Decl> top_level_declarations(void) const &;

  // Return the list of top-level macros or macro tokens in this code.
  gap::generator<MacroOrToken> preprocessed_code(void) const &;

  inline bool operator==(const Fragment &that) const noexcept {
    return id() == that.id();
  }

  inline bool operator!=(const Fragment &that) const noexcept {
    return id() != that.id();
  }

  // Run a regular expression search over this fragment.
  gap::generator<RegexQueryMatch> query(const RegexQuery &query) const &;
};

}  // namespace mx
