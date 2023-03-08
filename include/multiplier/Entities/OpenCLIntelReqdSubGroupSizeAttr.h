// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class OpenCLIntelReqdSubGroupSizeAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpenCLIntelReqdSubGroupSizeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OpenCLIntelReqdSubGroupSizeAttr> in(const Fragment &frag);
  static gap::generator<OpenCLIntelReqdSubGroupSizeAttr> in(const File &file);
  static gap::generator<OpenCLIntelReqdSubGroupSizeAttr> in(const Index &index);
  static gap::generator<OpenCLIntelReqdSubGroupSizeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OpenCLIntelReqdSubGroupSizeAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE;
  }

  static std::optional<OpenCLIntelReqdSubGroupSizeAttr> from(const Attr &parent);

  inline static std::optional<OpenCLIntelReqdSubGroupSizeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLIntelReqdSubGroupSizeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpenCLIntelReqdSubGroupSizeAttr> from(const Reference &r);
  static std::optional<OpenCLIntelReqdSubGroupSizeAttr> from(const TokenContext &t);

};

static_assert(sizeof(OpenCLIntelReqdSubGroupSizeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
