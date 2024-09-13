// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/FinalAttrSpelling.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class FinalAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT FinalAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<FinalAttr> in(const Index &index);
  static gap::generator<FinalAttr> in(const Fragment &frag);
  static gap::generator<FinalAttr> in(const File &file);
  static gap::generator<FinalAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::FINAL;
  }

  static std::optional<FinalAttr> by_id(const Index &, EntityId);

  static std::optional<FinalAttr> from_base(const Attr &parent);
  inline static std::optional<FinalAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<FinalAttr> from(const std::optional<Attr> &parent);
  static std::optional<FinalAttr> from(const Reference &r);
  static std::optional<FinalAttr> from(const VariantEntity &e);
  static std::optional<FinalAttr> from(const TokenContext &t);

  FinalAttrSpelling semantic_spelling(void) const;
  bool is_spelled_as_sealed(void) const;
};

static_assert(sizeof(FinalAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
