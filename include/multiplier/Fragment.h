// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "File.h"

namespace mx {

class Attr;
class Decl;
class EntityProvider;
class File;
class Fragment;
class FragmentImpl;
class Index;
class InvalidEntityProvider;
class ReferenceIterator;
class ReferenceIteratorImpl;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryMatch;
class RegexQueryResult;
class RegexQueryResultImpl;
class RegexQueryResultIterator;
class Stmt;
class Token;
class Type;
class WeggliQuery;
class WeggliQueryMatch;
class WeggliQueryResult;
class WeggliQueryResultImpl;
class WeggliQueryResultIterator;
class WeggliQueryResultIterator;

// A fragment of code containing one or more top-level declarations, the
// associated declaration and statement entities, macro expansion/substitution
// trees, and tokens.
class Fragment {
 private:
  friend class Attr;
  friend class Decl;
  friend class EntityProvider;
  friend class File;
  friend class FragmentImpl;
  friend class Index;
  friend class ReferenceIterator;
  friend class ReferenceIteratorImpl;
  friend class RemoteEntityProvider;
  friend class RegexQueryResultImpl;
  friend class RegexQueryResultIterator;
  friend class Stmt;
  friend class Token;
  friend class MacroSubstitution;
  friend class Type;
  friend class WeggliQueryResultImpl;
  friend class WeggliQueryResultIterator;

  std::shared_ptr<const FragmentImpl> impl;

  inline Fragment(std::shared_ptr<const FragmentImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  // Return the list of fragments in a file.
  static gap::generator<Fragment> in(const File &);

  // Return the fragment containing a query match.
  static Fragment containing(const WeggliQueryMatch &);

  static Fragment containing(const RegexQueryMatch &);

  static Fragment containing(const Decl &);
  static Fragment containing(const Stmt &);
  static Fragment containing(const Type &);
  static Fragment containing(const Attr &);
  static Fragment containing(const Designator &);
  static std::optional<Fragment> containing(const Token &);
  static Fragment containing(const MacroSubstitution &);
  static Fragment containing(const UseBase &);
  static Fragment containing(const Reference &);

  // Return the entity ID of this fragment.
  EntityId id(void) const noexcept;

  // The range of file tokens in this fragment.
  TokenRange file_tokens(void) const;

  // The range of parsed tokens in this fragment.
  TokenList parsed_tokens(void) const;

  // Return the pre-processed code from this fragment.
  std::optional<MacroSubstitution> preprocessed_code(void) const &;
  std::optional<MacroSubstitution> preprocessed_code(void) const &&;

  // Return the list of top-level declarations in this fragment.
  std::vector<Decl> top_level_declarations(void) const;

  // Returns source IR for the fragment.
  std::optional<std::string_view> source_ir(void) const noexcept;

  inline bool operator==(const Fragment &that) const noexcept {
    return id() == that.id();
  }

  inline bool operator!=(const Fragment &that) const noexcept {
    return id() != that.id();
  }

  // Run a Weggli search over this fragment.
  WeggliQueryResult query(const WeggliQuery &query) const;

  // Run a regular expression search over this fragment.
  RegexQueryResult query(const RegexQuery &query) const;
};

}  // namespace mx
