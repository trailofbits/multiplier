// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <optional>
#include <string_view>
#include <utility>
#include <variant>

#include "Types.h"
#include "Use.h"

namespace mx {

class EntityProvider;
class File;
class FileLocationCache;
class Fragment;
class FragmentImpl;
class Index;
class TokenContext;
class TokenList;
class TokenListIterator;
class TokenRange;
class TokenReader;
class MacroSubstitutionList;
class MacroSubstitutionListImpl;
class MacroSubstitutionListIterator;

// A token substitution gives access to the before and after tokens of a
// substitution. There can be one-or-more `before` tokens (e.g. function-like
// macro expansions, file inclusions) and zero-or-more `after` tokens.
class MacroSubstitution {
 protected:
  std::shared_ptr<const FragmentImpl> impl;

 private:
  friend class Fragment;
  friend class File;
  friend class Index;
  friend class MacroSubstitutionListIterator;

  unsigned offset;
  MacroSubstitutionKind kind_;

  inline MacroSubstitution(
      std::shared_ptr<const FragmentImpl> impl_,
      unsigned offset_, MacroSubstitutionKind kind__)
      : impl(std::move(impl_)),
        offset(offset_),
        kind_(kind__) {}

 public:
  inline MacroSubstitutionKind kind(void) const noexcept {
    return kind_;
  }

  MacroSubstitutionList before(void) const;
  std::optional<MacroSubstitutionList> after(void) const;
};

class MacroSubstitutionListIterator;

using MacroSubstitutionEnty = std::variant<Token, MacroSubstitution>;

// Iterate over a list of token or token substitution nodes.
class MacroSubstitutionListIterator {
 private:
  friend class MacroSubstitutionList;

  std::shared_ptr<const MacroSubstitutionListImpl> impl;
  unsigned index;
  unsigned num_nodes;

  bool operator==(const MacroSubstitutionListIterator &) = delete;
  bool operator!=(const MacroSubstitutionListIterator &) = delete;

  inline MacroSubstitutionListIterator(
      std::shared_ptr<const MacroSubstitutionListImpl> impl_,
      unsigned index_, unsigned num_nodes_)
      : impl(std::move(impl_)),
        index(index_),
        num_nodes(num_nodes_) {}

 public:
  using EndIteratorType = IteratorEnd;

  std::variant<Token, MacroSubstitution> operator*(void) const;

  // Pre-increment.
  inline MacroSubstitutionListIterator &operator++(void) noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline MacroSubstitutionListIterator operator++(int) noexcept {
    return MacroSubstitutionListIterator(impl, index++, num_nodes);
  }

  inline bool operator==(EndIteratorType) const noexcept {
    return index >= num_nodes;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return index < num_nodes;
  }
};

// List of token or substitution nodes.
class MacroSubstitutionList {
 private:
  friend class Fragment;
  friend class MacroSubstitution;

  std::shared_ptr<const MacroSubstitutionListImpl> impl;
  unsigned num_nodes{0u};

  inline MacroSubstitutionList(
      std::shared_ptr<const MacroSubstitutionListImpl> impl_,
      unsigned num_nodes_)
      : impl(std::move(impl_)),
        num_nodes(num_nodes_) {}

 public:
  MacroSubstitutionList(void) = default;

  inline MacroSubstitutionListIterator begin(void) && noexcept {
    return MacroSubstitutionListIterator(std::move(impl), 0, num_nodes);
  }

  inline MacroSubstitutionListIterator begin(void) const & noexcept {
    return MacroSubstitutionListIterator(impl, 0, num_nodes);
  }

  inline MacroSubstitutionListIterator::EndIteratorType
  end(void) const noexcept {
    return {};
  }
};

}  // namespace mx
