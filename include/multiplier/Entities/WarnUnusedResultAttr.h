// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "WarnUnusedResultAttrSpelling.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class Token;
class WarnUnusedResultAttr;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class WarnUnusedResultAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<WarnUnusedResultAttr> in(const Fragment &frag);
  static gap::generator<WarnUnusedResultAttr> in(const File &file);
  static gap::generator<WarnUnusedResultAttr> in(const Index &index);
  static gap::generator<WarnUnusedResultAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<WarnUnusedResultAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WARN_UNUSED_RESULT;
  }

  static std::optional<WarnUnusedResultAttr> from(const Attr &parent);

  inline static std::optional<WarnUnusedResultAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return WarnUnusedResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<WarnUnusedResultAttr> from(const Reference &r);
  static std::optional<WarnUnusedResultAttr> from(const TokenContext &t);

  bool is_cxx11_no_discard(void) const;
  std::string_view message(void) const;
  WarnUnusedResultAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(WarnUnusedResultAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
