// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class AsmLabelAttr;
class Attr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT AsmLabelAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AsmLabelAttr> in(const Index &index);
  static gap::generator<AsmLabelAttr> in(const Fragment &frag);
  static gap::generator<AsmLabelAttr> in(const File &file);
  static gap::generator<AsmLabelAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASM_LABEL;
  }

  static std::optional<AsmLabelAttr> by_id(const Index &, EntityId);

  static std::optional<AsmLabelAttr> from_base(const Attr &parent);
  inline static std::optional<AsmLabelAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AsmLabelAttr> from(const std::optional<Attr> &parent);
  static std::optional<AsmLabelAttr> from(const Reference &r);
  static std::optional<AsmLabelAttr> from(const VariantEntity &e);
  static std::optional<AsmLabelAttr> from(const TokenContext &t);

  bool is_literal_label(void) const;
  std::string_view label(void) const;
};

static_assert(sizeof(AsmLabelAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
