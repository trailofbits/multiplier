// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TypeAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class AnnotateTypeAttr;
class Attr;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AnnotateTypeAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<AnnotateTypeAttr> in(const Index &index);
  static gap::generator<AnnotateTypeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AnnotateTypeAttr> by_id(const Index &, EntityId);
  static gap::generator<AnnotateTypeAttr> in(const Fragment &frag);
  static gap::generator<AnnotateTypeAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ANNOTATE_TYPE;
  }

  static std::optional<AnnotateTypeAttr> from_base(const Attr &parent);
  inline static std::optional<AnnotateTypeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AnnotateTypeAttr> from(const std::optional<Attr> &parent);
  static std::optional<AnnotateTypeAttr> from(const Reference &r);
  static std::optional<AnnotateTypeAttr> from(const VariantEntity &e);
  static std::optional<AnnotateTypeAttr> from(const TokenContext &t);

  std::string_view annotation(void) const;
};

static_assert(sizeof(AnnotateTypeAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
