// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ArgumentWithTypeTagAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class ArgumentWithTypeTagAttr;
class Attr;
class InheritableAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ArgumentWithTypeTagAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ArgumentWithTypeTagAttr> in(const Fragment &frag);
  static gap::generator<ArgumentWithTypeTagAttr> in(const File &file);
  static gap::generator<ArgumentWithTypeTagAttr> in(const Index &index);
  static gap::generator<ArgumentWithTypeTagAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArgumentWithTypeTagAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARGUMENT_WITH_TYPE_TAG;
  }

  static std::optional<ArgumentWithTypeTagAttr> from(const Attr &parent);

  inline static std::optional<ArgumentWithTypeTagAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ArgumentWithTypeTagAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArgumentWithTypeTagAttr> from(const Reference &r);
  static std::optional<ArgumentWithTypeTagAttr> from(const TokenContext &t);

  bool is_pointer(void) const;
  ArgumentWithTypeTagAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(ArgumentWithTypeTagAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
