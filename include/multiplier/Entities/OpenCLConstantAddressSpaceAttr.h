// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OpenCLConstantAddressSpaceAttrSpelling.h"
#include "TypeAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class OpenCLConstantAddressSpaceAttr;
class Token;
class TypeAttr;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpenCLConstantAddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<OpenCLConstantAddressSpaceAttr> in(const Fragment &frag);
  static gap::generator<OpenCLConstantAddressSpaceAttr> in(const File &file);
  static gap::generator<OpenCLConstantAddressSpaceAttr> in(const Index &index);
  static gap::generator<OpenCLConstantAddressSpaceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OpenCLConstantAddressSpaceAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_CONSTANT_ADDRESS_SPACE;
  }

  static std::optional<OpenCLConstantAddressSpaceAttr> from(const Attr &parent);

  inline static std::optional<OpenCLConstantAddressSpaceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLConstantAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpenCLConstantAddressSpaceAttr> from(const Reference &r);
  static std::optional<OpenCLConstantAddressSpaceAttr> from(const TokenContext &t);

  OpenCLConstantAddressSpaceAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(OpenCLConstantAddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
