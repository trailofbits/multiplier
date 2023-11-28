// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableParamAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class AnnotateAttr;
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AnnotateAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AnnotateAttr> in(const Index &index);
  static gap::generator<AnnotateAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AnnotateAttr> by_id(const Index &, EntityId);
  static gap::generator<AnnotateAttr> in(const Fragment &frag);
  static gap::generator<AnnotateAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ANNOTATE;
  }

  static std::optional<AnnotateAttr> from_base(const Attr &parent);
  inline static std::optional<AnnotateAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AnnotateAttr> from(const std::optional<Attr> &parent);
  static std::optional<AnnotateAttr> from(const Reference &r);
  static std::optional<AnnotateAttr> from(const VariantEntity &e);
  static std::optional<AnnotateAttr> from(const TokenContext &t);

  std::string_view annotation(void) const;
};

static_assert(sizeof(AnnotateAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
