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
#include <gap/core/generator.hpp>

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

using MacroSubstitutionEntry = std::variant<Token, MacroSubstitution>;

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

  gap::generator<MacroSubstitutionEntry> before(void) const;
  bool has_after(void) const;
  gap::generator<MacroSubstitutionEntry> after(void) const;
};

}  // namespace mx
