// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/WarnUnusedResultAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class Token;
class WarnUnusedResultAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT WarnUnusedResultAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<WarnUnusedResultAttr> in(const Index &index);
  static gap::generator<WarnUnusedResultAttr> in(const Fragment &frag);
  static gap::generator<WarnUnusedResultAttr> in(const File &file);
  static gap::generator<WarnUnusedResultAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WARN_UNUSED_RESULT;
  }

  static std::optional<WarnUnusedResultAttr> by_id(const Index &, EntityId);

  static std::optional<WarnUnusedResultAttr> from_base(const Attr &parent);
  inline static std::optional<WarnUnusedResultAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<WarnUnusedResultAttr> from(const std::optional<Attr> &parent);
  static std::optional<WarnUnusedResultAttr> from(const Reference &r);
  static std::optional<WarnUnusedResultAttr> from(const VariantEntity &e);
  static std::optional<WarnUnusedResultAttr> from(const TokenContext &t);

  bool is_cxx11_no_discard(void) const;
  std::string_view message(void) const;
  uint32_t message_length(void) const;
  WarnUnusedResultAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(WarnUnusedResultAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
