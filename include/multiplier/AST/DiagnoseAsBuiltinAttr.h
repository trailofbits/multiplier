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
class DiagnoseAsBuiltinAttr;
class FunctionDecl;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DiagnoseAsBuiltinAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<DiagnoseAsBuiltinAttr> in(const Index &index);
  static gap::generator<DiagnoseAsBuiltinAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DiagnoseAsBuiltinAttr> by_id(const Index &, EntityId);
  static gap::generator<DiagnoseAsBuiltinAttr> in(const Fragment &frag);
  static gap::generator<DiagnoseAsBuiltinAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DIAGNOSE_AS_BUILTIN;
  }

  static std::optional<DiagnoseAsBuiltinAttr> from_base(const Attr &parent);
  inline static std::optional<DiagnoseAsBuiltinAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<DiagnoseAsBuiltinAttr> from(const std::optional<Attr> &parent);
  static std::optional<DiagnoseAsBuiltinAttr> from(const Reference &r);
  static std::optional<DiagnoseAsBuiltinAttr> from(const VariantEntity &e);
  static std::optional<DiagnoseAsBuiltinAttr> from(const TokenContext &t);

  FunctionDecl function(void) const;
};

static_assert(sizeof(DiagnoseAsBuiltinAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
