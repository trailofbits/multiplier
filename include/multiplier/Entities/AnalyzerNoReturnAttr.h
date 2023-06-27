// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class AnalyzerNoReturnAttr;
class Attr;
class InheritableAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AnalyzerNoReturnAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AnalyzerNoReturnAttr> in(const Fragment &frag);
  static gap::generator<AnalyzerNoReturnAttr> in(const File &file);
  static gap::generator<AnalyzerNoReturnAttr> in(const Index &index);
  static gap::generator<AnalyzerNoReturnAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AnalyzerNoReturnAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ANALYZER_NO_RETURN;
  }

  static std::optional<AnalyzerNoReturnAttr> from(const Attr &parent);

  inline static std::optional<AnalyzerNoReturnAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AnalyzerNoReturnAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AnalyzerNoReturnAttr> from(const Reference &r);
  static std::optional<AnalyzerNoReturnAttr> from(const TokenContext &t);

};

static_assert(sizeof(AnalyzerNoReturnAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
