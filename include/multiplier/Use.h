// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <bitset>
#include <new>
#include <variant>

#include "Iterator.h"

namespace mx {

class Attr;
class CXXBaseSpecifier;
class Decl;
class EntityProvider;
class File;
class FragmentImpl;
class Macro;
class Stmt;
class TemplateArgument;
class TemplateParameterList;
class Token;
class MacroSubstitution;
class Type;

using UseSelectorSet = std::bitset<256>;

// NOTE(pag): Files don't use other files, hence the absence.
enum class UseKind : unsigned char {
  DECLARATION,
  STATEMENT,
  TYPE,
  CXX_BASE_SPECIFIER,
  TEMPLATE_ARGUMENT,
  TEMPLATE_PARAMETER_LIST,
  DESIGNATOR,
  ATTRIBUTE,
  MACRO,
};

inline static const char *EnumerationName(UseKind) {
  return "UseKind";
}

inline static constexpr unsigned NumEnumerators(UseKind) {
  return 9u;
}

const char *EnumeratorName(UseKind);

using NotAnEntity = std::monostate;

using VariantUse = std::variant<NotAnEntity, Decl, Stmt, Type, Attr, Macro,
                                CXXBaseSpecifier, TemplateArgument,
                                TemplateParameterList, Designator>;

// Base for uses. Uses represent AST methods that return a specific entity
// ID.
//
// TODO(pag): Rename to `UserBase`?
class UseBase {
 private:
  friend class Decl;
  friend class Designator;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Macro;
  friend class Stmt;
  friend class UseIteratorImpl;

 protected:
  UseSelectorSet selectors;
  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset{0};
  UseKind kind{UseKind::DECLARATION};

 public:
  UseBase(void) = default;

  UseBase(Decl decl, UseSelectorSet selectors_);
  UseBase(Stmt stmt, UseSelectorSet selectors_);
  UseBase(Type type, UseSelectorSet selectors_);
  UseBase(Attr attr, UseSelectorSet selectors_);
  UseBase(Macro attr, UseSelectorSet selectors_);
  UseBase(CXXBaseSpecifier decl, UseSelectorSet selectors_);
  UseBase(TemplateArgument decl, UseSelectorSet selectors_);
  UseBase(TemplateParameterList decl, UseSelectorSet selectors_);
  UseBase(Designator designator, UseSelectorSet selectors_);

  ~UseBase(void);

  VariantUse entity(void) const;
  std::optional<Decl> as_declaration(void) const;
  std::optional<Stmt> as_statement(void) const;
  std::optional<Type> as_type(void) const;
  std::optional<Attr> as_attribute(void) const;
  std::optional<Macro> as_macro(void) const;
  std::optional<CXXBaseSpecifier> as_cxx_base_specifier(void) const;
  std::optional<TemplateArgument> as_template_argument(void) const;
  std::optional<TemplateParameterList> as_template_parameter_list(void) const;
  std::optional<Designator> as_designator(void) const;
};

enum class AttrUseSelector : unsigned short;
enum class DeclUseSelector : unsigned short;
enum class StmtUseSelector : unsigned short;
enum class TypeUseSelector : unsigned short;
enum class TokenUseSelector : unsigned short;
enum class MacroUseSelector : unsigned short;
enum class FileUseSelector : unsigned short;

// A declaration or statement use, along with the usage selector.
//
// TODO(pag): Rename to `User`?
template <typename Selector>
class Use : public UseBase {
 private:
  friend class Attr;
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Macro;
  friend class Stmt;

 protected:
  using UseBase::UseBase;

 public:
  inline bool has_selector(Selector sel0) const noexcept {
    return selectors.test(static_cast<unsigned>(sel0));
  }

  template <typename... S>
  inline bool has_any_selector(Selector sel0, S... selN) const noexcept {
    return has_selector(sel0) || (has_selector(selN) || ...);
  }

  inline static mx::EnumerationRange<Selector> all_selectors(void) noexcept {
    return mx::EnumerationRange<Selector>();
  }
};

}  // namespace mx
