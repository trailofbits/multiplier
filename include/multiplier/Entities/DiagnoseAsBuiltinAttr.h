// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class DiagnoseAsBuiltinAttr;
class FunctionDecl;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DiagnoseAsBuiltinAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<DiagnoseAsBuiltinAttr> in(const Fragment &frag);
  static gap::generator<DiagnoseAsBuiltinAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DIAGNOSE_AS_BUILTIN;
  }

  static gap::generator<AttrKind> derived_kinds(void);
  inline static std::optional<DiagnoseAsBuiltinAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<DiagnoseAsBuiltinAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<DiagnoseAsBuiltinAttr> from(const InheritableAttr &parent);

  inline static std::optional<DiagnoseAsBuiltinAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return DiagnoseAsBuiltinAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DiagnoseAsBuiltinAttr> from(const Attr &parent);

  inline static std::optional<DiagnoseAsBuiltinAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return DiagnoseAsBuiltinAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  FunctionDecl function(void) const;
};

static_assert(sizeof(DiagnoseAsBuiltinAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
