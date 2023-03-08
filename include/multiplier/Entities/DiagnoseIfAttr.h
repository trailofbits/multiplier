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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "DiagnoseIfAttrDiagnosticType.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class DiagnoseIfAttr;
class Expr;
class InheritableAttr;
class NamedDecl;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DiagnoseIfAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<DiagnoseIfAttr> in(const Fragment &frag);
  static gap::generator<DiagnoseIfAttr> in(const File &file);
  static gap::generator<DiagnoseIfAttr> in(const Index &index);
  static gap::generator<DiagnoseIfAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DiagnoseIfAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DIAGNOSE_IF;
  }

  static std::optional<DiagnoseIfAttr> from(const Attr &parent);

  inline static std::optional<DiagnoseIfAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return DiagnoseIfAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<DiagnoseIfAttr> from(const Reference &r) {
    return DiagnoseIfAttr::from(r.as_attribute());
  }

  inline static std::optional<DiagnoseIfAttr> from(const TokenContext &t) {
    return DiagnoseIfAttr::from(t.as_attribute());
  }

  bool argument_dependent(void) const;
  Expr condition(void) const;
  DiagnoseIfAttrDiagnosticType diagnostic_type(void) const;
  std::string_view message(void) const;
  NamedDecl parent(void) const;
  bool is_error(void) const;
  bool is_warning(void) const;
};

static_assert(sizeof(DiagnoseIfAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
