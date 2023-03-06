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

#include "DeclOrStmtAttr.h"

namespace mx {
class Attr;
class DeclOrStmtAttr;
class InheritableAttr;
class NoMergeAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoMergeAttr : public DeclOrStmtAttr {
 private:
  friend class FragmentImpl;
  friend class DeclOrStmtAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoMergeAttr> in(const Fragment &frag);
  static gap::generator<NoMergeAttr> in(const File &file);
  static gap::generator<NoMergeAttr> in(const Index &index);
  static gap::generator<NoMergeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoMergeAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_MERGE;
  }

  static std::optional<NoMergeAttr> from(const Attr &parent);

  inline static std::optional<NoMergeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoMergeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<NoMergeAttr> from(const Reference &r) {
    return NoMergeAttr::from(r.as_attribute());
  }

  inline static std::optional<NoMergeAttr> from(const TokenContext &t) {
    return NoMergeAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(NoMergeAttr) == sizeof(DeclOrStmtAttr));

#endif
} // namespace mx
