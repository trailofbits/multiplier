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

#include "MacroKind.h"
#include "MacroUseSelector.h"

namespace mx {
class Macro;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MacroOrToken = std::variant<Macro, Token>;
using MacroRange = DerivedEntityRange<MacroIterator, Macro>;
using MacroContainingMacroRange = DerivedEntityRange<ParentMacroIteratorImpl<Macro>, Macro>;

class Macro {
 protected:
  friend class Attr;
  friend class AttrIterator;
  friend class Decl;
  friend class DeclIterator;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class MacroReferenceIterator;
  friend class ReferenceIteratorImpl;
  friend class Stmt;
  friend class StmtReferenceIterator;
  friend class StmtIterator;
  friend class TokenContext;
  friend class Type;
  friend class TypeIterator;
  friend class UseBase;
  friend class UseIteratorImpl;
  template <typename> friend class UseIterator;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset_;

 public:
  Macro(Macro &&) noexcept = default;
  Macro(const Macro &) = default;
  Macro &operator=(Macro &&) noexcept = default;
  Macro &operator=(const Macro &) = default;

  inline Macro(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset__)
      : fragment(std::move(fragment_)),
        offset_(offset__) {}

  inline static std::optional<Macro> from(const Macro &self) {
    return self;
  }

  inline static std::optional<Macro> from(const std::optional<Macro> &self) {
    return self;
  }

  SpecificEntityId<MacroId> id(void) const;
  UseRange<MacroUseSelector> uses(void) const;

 protected:
  static MacroIterator in_internal(const Fragment &fragment);
  static ParentMacroIteratorImpl<Macro> containing_internal(const Token &token);

 public:
  static MacroContainingMacroRange containing(const Macro &macro);
  bool contains(const Macro &macro);

  static MacroContainingMacroRange containing(const Token &token);
  bool contains(const Token &token);

  MacroKind kind(void) const;
  std::optional<Macro> parent(void) const;
  std::vector<MacroOrToken> children(void) const;
};

#endif
} // namespace mx
