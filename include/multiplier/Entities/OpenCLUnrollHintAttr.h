// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "StmtAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class OpenCLUnrollHintAttr;
class StmtAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpenCLUnrollHintAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<OpenCLUnrollHintAttr> in(const Fragment &frag);
  static gap::generator<OpenCLUnrollHintAttr> in(const File &file);
  static gap::generator<OpenCLUnrollHintAttr> in(const Index &index);
  static gap::generator<OpenCLUnrollHintAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OpenCLUnrollHintAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_UNROLL_HINT;
  }

  static std::optional<OpenCLUnrollHintAttr> from(const Attr &parent);

  inline static std::optional<OpenCLUnrollHintAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLUnrollHintAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpenCLUnrollHintAttr> from(const Reference &r);
  static std::optional<OpenCLUnrollHintAttr> from(const TokenContext &t);

};

static_assert(sizeof(OpenCLUnrollHintAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
