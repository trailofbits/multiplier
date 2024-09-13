// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/DiagnoseIfAttrDiagnosticType.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class DiagnoseIfAttr;
class Expr;
class File;
class InheritableAttr;
class NamedDecl;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DiagnoseIfAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<DiagnoseIfAttr> in(const Index &index);
  static gap::generator<DiagnoseIfAttr> in(const Fragment &frag);
  static gap::generator<DiagnoseIfAttr> in(const File &file);
  static gap::generator<DiagnoseIfAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DIAGNOSE_IF;
  }

  static std::optional<DiagnoseIfAttr> by_id(const Index &, EntityId);

  static std::optional<DiagnoseIfAttr> from_base(const Attr &parent);
  inline static std::optional<DiagnoseIfAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<DiagnoseIfAttr> from(const std::optional<Attr> &parent);
  static std::optional<DiagnoseIfAttr> from(const Reference &r);
  static std::optional<DiagnoseIfAttr> from(const VariantEntity &e);
  static std::optional<DiagnoseIfAttr> from(const TokenContext &t);

  bool argument_dependent(void) const;
  Expr condition(void) const;
  DiagnoseIfAttrDiagnosticType diagnostic_type(void) const;
  std::string_view message(void) const;
  uint32_t message_length(void) const;
  NamedDecl parent(void) const;
  bool is_error(void) const;
  bool is_warning(void) const;
};

static_assert(sizeof(DiagnoseIfAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
