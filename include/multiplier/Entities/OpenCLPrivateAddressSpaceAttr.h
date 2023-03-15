// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OpenCLPrivateAddressSpaceAttrSpelling.h"
#include "TypeAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class OpenCLPrivateAddressSpaceAttr;
class Token;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpenCLPrivateAddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<OpenCLPrivateAddressSpaceAttr> in(const Fragment &frag);
  static gap::generator<OpenCLPrivateAddressSpaceAttr> in(const File &file);
  static gap::generator<OpenCLPrivateAddressSpaceAttr> in(const Index &index);
  static gap::generator<OpenCLPrivateAddressSpaceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OpenCLPrivateAddressSpaceAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_PRIVATE_ADDRESS_SPACE;
  }

  static std::optional<OpenCLPrivateAddressSpaceAttr> from(const Attr &parent);

  inline static std::optional<OpenCLPrivateAddressSpaceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLPrivateAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpenCLPrivateAddressSpaceAttr> from(const Reference &r);
  static std::optional<OpenCLPrivateAddressSpaceAttr> from(const TokenContext &t);

  OpenCLPrivateAddressSpaceAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(OpenCLPrivateAddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
