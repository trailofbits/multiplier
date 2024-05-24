// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>
#include <multiplier/AST/OpenCLAccessAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class OpenCLAccessAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OpenCLAccessAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<OpenCLAccessAttr> in(const Index &index);
  static gap::generator<OpenCLAccessAttr> in(const Fragment &frag);
  static gap::generator<OpenCLAccessAttr> in(const File &file);
  static gap::generator<OpenCLAccessAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_ACCESS;
  }

  static std::optional<OpenCLAccessAttr> by_id(const Index &, EntityId);

  static std::optional<OpenCLAccessAttr> from_base(const Attr &parent);
  inline static std::optional<OpenCLAccessAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<OpenCLAccessAttr> from(const std::optional<Attr> &parent);
  static std::optional<OpenCLAccessAttr> from(const Reference &r);
  static std::optional<OpenCLAccessAttr> from(const VariantEntity &e);
  static std::optional<OpenCLAccessAttr> from(const TokenContext &t);

  OpenCLAccessAttrSpelling semantic_spelling(void) const;
  bool is_read_only(void) const;
  bool is_read_write(void) const;
  bool is_write_only(void) const;
};

static_assert(sizeof(OpenCLAccessAttr) == sizeof(Attr));

#endif
} // namespace mx
