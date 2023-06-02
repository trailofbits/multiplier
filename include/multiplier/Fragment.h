// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/core/generator.hpp>
#include <memory>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

#include "File.h"

namespace mx {

class EntityProvider;
class FragmentImpl;
class Index;
class InvalidEntityProvider;
class ReferenceIteratorImpl;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryMatch;
class SourceIR;
class WeggliQuery;
class WeggliQueryMatch;
class WeggliQueryResult;
class WeggliQueryResultImpl;
class WeggliQueryResultIterator;
class WeggliQueryResultIterator;

#define MX_FORWARD_DECLARE(type_name, ln, e, c) \
    class type_name;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE)
#undef MX_FORWARD_DECLARE

using MacroOrToken = std::variant<Macro, Token>;

// A fragment of code containing one or more top-level declarations, the
// associated declaration and statement entities, macro expansion/substitution
// trees, and tokens.
class Fragment {
 private:
  friend class EntityProvider;
  friend class FragmentImpl;
  friend class Index;
  friend class Reference;
  friend class RemoteEntityProvider;
  friend class RegexQuery;
  friend class RegexQueryResultImpl;
  friend class SourceIRImpl;
  friend class TokenTree;
  friend class TokenTreeImpl;
  friend class WeggliQuery;
  friend class WeggliQueryResultImpl;

#define MX_FRIEND(type_name, ln, e, c) \
    friend class type_name;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND)
#undef MX_FRIEND

  std::shared_ptr<const FragmentImpl> impl;

 public:

  /* implicit */ inline Fragment(std::shared_ptr<const FragmentImpl> impl_)
      : impl(std::move(impl_)) {}

  // Return the fragment containing a query match.
  static Fragment containing(const WeggliQueryMatch &);
  static Fragment containing(const RegexQueryMatch &);

  // Return the fragment containing a token tree.
  static std::optional<Fragment> containing(const TokenTree &);

  inline static Fragment containing(const Fragment &fragment) {
    return fragment;
  }

  static Fragment containing(const Decl &);
  static Fragment containing(const Stmt &);
  static Fragment containing(const Attr &);
  static Fragment containing(const TemplateArgument &);
  static Fragment containing(const TemplateParameterList &);
  static Fragment containing(const CXXBaseSpecifier &);
  static Fragment containing(const Designator &);
  static std::optional<Fragment> containing(const Token &);
  static Fragment containing(const Macro &);
  static std::optional<Fragment> containing(const VariantEntity &);

  inline static constexpr EntityCategory entity_category(void) {
    return EntityCategory::FRAGMENT;
  }

  // Return the entity ID of this fragment.
  SpecificEntityId<FragmentId> id(void) const noexcept;

  // The range of file tokens in this fragment.
  TokenRange file_tokens(void) const;

  // The range of parsed tokens in this fragment.
  TokenRange parsed_tokens(void) const;

  // Return references to this fragment.
  gap::generator<Reference> references(void) const &;

  // Return the list of top-level declarations in this fragment.
  gap::generator<Decl> top_level_declarations(void) const &;

  // Return the list of top-level macros or macro tokens in this code.
  gap::generator<MacroOrToken> preprocessed_code(void) const &;

  // Returns source IR for the fragment.
  std::optional<SourceIR> ir(void) const noexcept;

  inline bool operator==(const Fragment &that) const noexcept {
    return id() == that.id();
  }

  inline bool operator!=(const Fragment &that) const noexcept {
    return id() != that.id();
  }

  // Run a Weggli search over this fragment.
  gap::generator<WeggliQueryMatch> query(const WeggliQuery &query) const &;

  // Run a regular expression search over this fragment.
  gap::generator<RegexQueryMatch> query(const RegexQuery &query) const &;
};

}  // namespace mx
