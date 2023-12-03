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
class Attr;
class CodeSegAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CodeSegAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CodeSegAttr> in(const Index &index);
  static gap::generator<CodeSegAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CodeSegAttr> by_id(const Index &, EntityId);
  static gap::generator<CodeSegAttr> in(const Fragment &frag);
  static gap::generator<CodeSegAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CODE_SEG;
  }

  static std::optional<CodeSegAttr> from_base(const Attr &parent);
  inline static std::optional<CodeSegAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<CodeSegAttr> from(const std::optional<Attr> &parent);
  static std::optional<CodeSegAttr> from(const Reference &r);
  static std::optional<CodeSegAttr> from(const VariantEntity &e);
  static std::optional<CodeSegAttr> from(const TokenContext &t);

  std::string_view name(void) const;
};

static_assert(sizeof(CodeSegAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
