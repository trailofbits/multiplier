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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "DeclOrStmtAttr.h"

namespace mx {
class Attr;
class DeclOrStmtAttr;
class InheritableAttr;
class NoMergeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NoMergeAttrRange = DerivedEntityRange<AttrIterator, NoMergeAttr>;
using NoMergeAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NoMergeAttr>;
class NoMergeAttr : public DeclOrStmtAttr {
 private:
  friend class FragmentImpl;
  friend class DeclOrStmtAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static NoMergeAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NoMergeAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NoMergeAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_MERGE;
  }

  static std::optional<NoMergeAttr> from(const TokenContext &c);
  static std::optional<NoMergeAttr> from(const DeclOrStmtAttr &parent);

  inline static std::optional<NoMergeAttr> from(const std::optional<DeclOrStmtAttr> &parent) {
    if (parent) {
      return NoMergeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoMergeAttr> from(const InheritableAttr &parent);

  inline static std::optional<NoMergeAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NoMergeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoMergeAttr> from(const Attr &parent);

  inline static std::optional<NoMergeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoMergeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(NoMergeAttr) == sizeof(DeclOrStmtAttr));

#endif
} // namespace mx
