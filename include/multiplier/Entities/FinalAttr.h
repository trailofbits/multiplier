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
#include "FinalAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class FinalAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using FinalAttrRange = DerivedEntityRange<AttrIterator, FinalAttr>;
using FinalAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, FinalAttr>;
class FinalAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static FinalAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FinalAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : FinalAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::FINAL;
  }

  static std::optional<FinalAttr> from(const TokenContext &c);
  static std::optional<FinalAttr> from(const InheritableAttr &parent);

  inline static std::optional<FinalAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return FinalAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FinalAttr> from(const Attr &parent);

  inline static std::optional<FinalAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return FinalAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  FinalAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
  bool is_spelled_as_sealed(void) const;
};

static_assert(sizeof(FinalAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
