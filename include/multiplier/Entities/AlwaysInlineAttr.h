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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AlwaysInlineAttrSpelling.h"
#include "AttrKind.h"
#include "DeclOrStmtAttr.h"

namespace mx {
class AlwaysInlineAttr;
class Attr;
class DeclOrStmtAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AlwaysInlineAttr : public DeclOrStmtAttr {
 private:
  friend class FragmentImpl;
  friend class DeclOrStmtAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AlwaysInlineAttr> in(const Fragment &frag);
  static gap::generator<AlwaysInlineAttr> in(const File &file);
  static gap::generator<AlwaysInlineAttr> in(const Index &index);
  static gap::generator<AlwaysInlineAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AlwaysInlineAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALWAYS_INLINE;
  }

  static std::optional<AlwaysInlineAttr> from(const Attr &parent);

  inline static std::optional<AlwaysInlineAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlwaysInlineAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<AlwaysInlineAttr> from(const Reference &r) {
    return AlwaysInlineAttr::from(r.as_attribute());
  }

  inline static std::optional<AlwaysInlineAttr> from(const TokenContext &t) {
    return AlwaysInlineAttr::from(t.as_attribute());
  }

  AlwaysInlineAttrSpelling semantic_spelling(void) const;
  bool is_clang_always_inline(void) const;
};

static_assert(sizeof(AlwaysInlineAttr) == sizeof(DeclOrStmtAttr));

#endif
} // namespace mx
