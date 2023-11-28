// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableParamAttr.h>
#include <multiplier/AST/PassObjectSizeAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class PassObjectSizeAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PassObjectSizeAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PassObjectSizeAttr> in(const Index &index);
  static gap::generator<PassObjectSizeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PassObjectSizeAttr> by_id(const Index &, EntityId);
  static gap::generator<PassObjectSizeAttr> in(const Fragment &frag);
  static gap::generator<PassObjectSizeAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PASS_OBJECT_SIZE;
  }

  static std::optional<PassObjectSizeAttr> from_base(const Attr &parent);
  inline static std::optional<PassObjectSizeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<PassObjectSizeAttr> from(const std::optional<Attr> &parent);
  static std::optional<PassObjectSizeAttr> from(const Reference &r);
  static std::optional<PassObjectSizeAttr> from(const VariantEntity &e);
  static std::optional<PassObjectSizeAttr> from(const TokenContext &t);

  PassObjectSizeAttrSpelling semantic_spelling(void) const;
  bool is_dynamic(void) const;
};

static_assert(sizeof(PassObjectSizeAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
