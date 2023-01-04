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

#include "AttrKind.h"
#include "FunctionReturnThunksAttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class FunctionReturnThunksAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using FunctionReturnThunksAttrRange = DerivedEntityRange<AttrIterator, FunctionReturnThunksAttr>;
using FunctionReturnThunksAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, FunctionReturnThunksAttr>;
class FunctionReturnThunksAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static FunctionReturnThunksAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FunctionReturnThunksAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : FunctionReturnThunksAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::FUNCTION_RETURN_THUNKS;
  }

  static std::optional<FunctionReturnThunksAttr> from(const TokenContext &c);
  static std::optional<FunctionReturnThunksAttr> from(const InheritableAttr &parent);

  inline static std::optional<FunctionReturnThunksAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return FunctionReturnThunksAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionReturnThunksAttr> from(const Attr &parent);

  inline static std::optional<FunctionReturnThunksAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return FunctionReturnThunksAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
  FunctionReturnThunksAttrKind thunk_type(void) const;
};

static_assert(sizeof(FunctionReturnThunksAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
