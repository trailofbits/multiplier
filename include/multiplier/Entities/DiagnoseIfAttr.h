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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "DiagnoseIfAttrDiagnosticType.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class DiagnoseIfAttr;
class Expr;
class InheritableAttr;
class NamedDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DiagnoseIfAttrRange = DerivedEntityRange<AttrIterator, DiagnoseIfAttr>;
using DiagnoseIfAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, DiagnoseIfAttr>;
class DiagnoseIfAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static DiagnoseIfAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DiagnoseIfAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DiagnoseIfAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DIAGNOSE_IF;
  }

  static std::optional<DiagnoseIfAttr> from(const TokenContext &c);
  static std::optional<DiagnoseIfAttr> from(const InheritableAttr &parent);

  inline static std::optional<DiagnoseIfAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return DiagnoseIfAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DiagnoseIfAttr> from(const Attr &parent);

  inline static std::optional<DiagnoseIfAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return DiagnoseIfAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool argument_dependent(void) const;
  Expr condition(void) const;
  DiagnoseIfAttrDiagnosticType diagnostic_type(void) const;
  std::string_view message(void) const;
  NamedDecl parent(void) const;
  std::string_view spelling(void) const;
  bool is_error(void) const;
  bool is_warning(void) const;
};

static_assert(sizeof(DiagnoseIfAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
