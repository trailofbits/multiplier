// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class ObjCRuntimeNameAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCRuntimeNameAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCRuntimeNameAttr> in(const Index &index);
  static gap::generator<ObjCRuntimeNameAttr> in(const Fragment &frag);
  static gap::generator<ObjCRuntimeNameAttr> in(const File &file);
  static gap::generator<ObjCRuntimeNameAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_RUNTIME_NAME;
  }

  static std::optional<ObjCRuntimeNameAttr> by_id(const Index &, EntityId);

  static std::optional<ObjCRuntimeNameAttr> from_base(const Attr &parent);
  inline static std::optional<ObjCRuntimeNameAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCRuntimeNameAttr> from(const std::optional<Attr> &parent);
  static std::optional<ObjCRuntimeNameAttr> from(const Reference &r);
  static std::optional<ObjCRuntimeNameAttr> from(const VariantEntity &e);
  static std::optional<ObjCRuntimeNameAttr> from(const TokenContext &t);

  std::string_view metadata_name(void) const;
  uint32_t metadata_name_length(void) const;
};

static_assert(sizeof(ObjCRuntimeNameAttr) == sizeof(Attr));

#endif
} // namespace mx
