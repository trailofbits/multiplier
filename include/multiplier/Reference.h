// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/coro/generator.hpp>
#include <memory>
#include <string>
#include <string_view>

#include "Entity.h"

namespace mx {

class Index;
class EntityProvider;
class Reference;
class ReferenceKindImpl;

using OpaqueImplPtr = std::shared_ptr<const void>;
using ReferenceKindImplPtr = std::shared_ptr<const ReferenceKindImpl>;
using WeakReferenceKindImplPtr = std::weak_ptr<const ReferenceKindImpl>;

// Multiplier's builtin reference kinds are slightly odd. In practice, an
// automatically added reference always has the referenced entity as a
// `Decl`, and the referencing entity as a `Stmt`, specifically one of
// `DeclRefExpr`, `MemberExpr`, `AddrLabelExpr`, `CXXConstructExpr`,
// `DesignatedInitExpr`, or `InitListExpr`. And yet, the builtin reference kind
// presents higher level "verbs" that describe the context of the reference.
//
// This can be understood in terms of our reference representation, specifically
// the `context` field:
//
//      from:     Entity which refers to `to`.
//      kind:     The kind of the reference.
//      to:       Entity referenced by `from`.
//      context:  For builtin reference kinds, this is either `from`, or it is
//                a parent of `from`.
//
// Thus, with builtin reference kinds, one is to understand the `kind` as a verb
// of the form "`from` is or is in `context`, and `kind` `to`". For example,
// "`DeclRefExpr` is or is in `CallExpr`, and `CALLS` `FunctionDecl`".
//
// This is a bit of a funny representation, but it provides useful baseline
// classification of the reference, while maintaining the precision of `from`,
// i.e. via the `from` entity, we should always be able to find the `to` entity
// (or a redeclaration thereof), e.g. via a method call.
enum class BuiltinReferenceKind : int {

  // Default kind when the `to` entity is a `ValueDecl`.
  USES_VALUE,

  // Default kind when the `to` entity is a `TypeDecl`. Generally, this
  // corresponds to a use of type in a declarator.
  USES_TYPE,

  // Used in a cast expression.
  CASTS_WITH_TYPE,

  // Corresponds to an assignment. E.g. if `... = b`, then we say that the
  // expression `... = ...` copies the value of `b`.
  COPIES_VALUE,

  // If we have something like `while (a) ...` or `do ... while (a);` or
  // `switch(a) ...` or `for(; a; ) ...` or `if (a) ...` or `a ? ... : ...`
  // then we say that the expression, e.g. `while (...) ...`, tests the value
  // `a`. This is a special form of `READS_VALUE`.
  TESTS_VALUE,

  // If we have `a = ...` then we say that the expression `... = ...` writes
  // to the value `a`.
  WRITES_VALUE,

  // If an expression mutates something in place, e.g. `++a`, then we say that
  // the expression `++...` updates `a`.
  UPDATES_VALUE,

  // If we have something like `*a`, `a. ...`, `a->...`, or `a[...]` then we say
  // that the exression `*...`, `... . ...`, `...->...`, or `...[...]` accesses
  // the value `a`, respectively.
  ACCESSES_VALUE,

  // If we have `...(a)`, or `...[a]`, then we say that the expression
  // `...(...)` and `...[...]` takes the value `a`, respectively. This is
  // similar to `COPIES_VALUE`.
  TAKES_VALUE,

  // If we have `a(...)` then we say that the expression `...(...)` calls `a`.
  CALLS,

  // In the case of variables, this corresponds to `&var`. We say that the
  // expression `&...` takes the address of `var`.
  //
  // In the case of fields, this corresponds to `&....field` or
  // `&...->field`, and we say that the expression `&...` takes the address
  // of `field`. This also applies through reference casts and paren
  // expressions.
  //
  // In the case of functions, this corresponds to raw uses of function/method
  // pointers, and the `&` unary operation. For example, if we have `... = func`,
  // or `&func`, or `...(func)` then we say the expression `... = ...`,
  // `&...`, or `...(...)` takes the address of `func`, respectively.
  // `func`.
  TAKES_ADDRESS,

  // If there is a `#include "a"`, `#include <a>`, `#include_next ...`,
  // `#import ...`, then we say the macro `#include ...` includes the
  // entity `a`.
  INCLUDES_FILE,

  // If there is a use of a macro like `a` or `a(...)` then we say the macro
  // `...` or `...(...)` is an expansion of `a`.
  EXPANSION_OF,

  // In C++, if you have `class Child : Parent`, then we say the derived class
  // `Child` extends `Parent`. The context will point to the
  // `CXXBaseClassSpecifier`.
  EXTENDS,

  // In C++, if you have a class `Child` that derives from a class `Parent`,
  // and `Parent` defines a virtual method `Method`, and `Child` has an
  // `override`- or `final`-marked version of `Method`, then we say that
  // `Child::Method` overrides `Parent::Method`.
  OVERRIDES,

  // In C++, an instantiation `Class<ConcreteType>` is said to specialize the
  // template class `Class<TemplateTypeParam>`. This also applies for function
  // templates and variable templates. Due to Clang not representing them, this
  // doesn't apply to using type templates. In the case of class and variable
  // template specializations, if this is a specialization of a partial
  // specialization, then the partial specialization is the context, otherwise
  // the template itself is the context.
  //
  // TODO(pag): Consider whether or not the `ClassTemplate` should be the
  //            context, and the `CXXRecordDecl` that is the class pattern be
  //            to the `to`. Ditto for variable and functions. This, however,
  //            doesn't fit well with specializations of members.
  SPECIALIZES,

  // A relation used to implement `*::contained_declarations`. `A` is a
  // declaration, e.g. a variable declaration, in the body of a function `B`,
  // then we say that `B` contains `A`.
  CONTAINS,
};

inline static const char *EnumerationName(BuiltinReferenceKind) {
  return "BuiltinReferenceKind";
}

MX_EXPORT const char *EnumeratorName(BuiltinReferenceKind);

inline static constexpr unsigned NumEnumerators(BuiltinReferenceKind) {
  return 17;
}

class MX_EXPORT ReferenceKind {
 private:
  friend class Reference;
  friend class ReferenceKindImpl;

  ReferenceKindImplPtr impl;

  ReferenceKind(void) = delete;

  /* implicit */ inline ReferenceKind(ReferenceKindImplPtr impl_)
      : impl(std::move(impl_)) {}

  RawEntityId id(void) const noexcept;

 public:

  // Get a reference kind for a builtin kind.
  static ReferenceKind get(const Index &, BuiltinReferenceKind kind);

  // Get or create a reference kind.
  static ReferenceKind get(const Index &, std::string_view name);

  // Is this a built-in reference kind?
  std::optional<BuiltinReferenceKind> builtin_reference_kind(void) const noexcept;

  // The name of this reference kind.
  std::string_view data(void) const & noexcept;

  // The name of this reference kind.
  std::string data(void) const && noexcept;
};

// A reference is an arbitrarily named/kinded relation between two entities,
// inducing a directed graph. Normally, the edges between entities are via
// built-in method calls on entity objects. These methods are generally derived
// from the PASTA API / Clang API, by way of the indexer serializing
// ASTs. References, however, enable more semantic relationships between
// entities to be expressed. By default, the indexer fills in several built-in
// references, e.g. between callers and callees. Most of these correspond to
// explicit references that appear in the code itself. Users, however, can
// use the reference API to augment the built-in graph, e.g. expressing patterns
// such as function pointer de-virtualization, by introducing their own
// reference edges using built-in kinds, or by creating entirely custom
// reference kinds for the sake of analysis result persistence.
//
// Although references are logically a `(from, kind, to)` triple, we store an
// additional `context` field. By default, `context` matches `from`. However,
// sometimes it differs. When it does, it's good to think about it as providing
// *visual* context for `from`, and thus is should be an entity that is a
// parent of `from`.
class MX_EXPORT Reference {
 private:
  OpaqueImplPtr impl;
  // The reference context will have entity id of referrer that references the
  // entity of interest.
  RawEntityId context_id;
  RawEntityId entity_id;
  RawEntityId kind_id;

#define MX_FRIEND(ns_path, type_name, ...) \
    friend class ns_path type_name;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND)
#undef MX_FRIEND

  Reference(void) = delete;

  inline static RawEntityId reference_kind_id(RawEntityId kind_id) noexcept {
    return kind_id;
  }

  inline static RawEntityId reference_kind_id(
      const ReferenceKind &kind) noexcept {
    return kind.id();
  }

 public:

  inline explicit Reference(OpaqueImplPtr impl_,
                            RawEntityId context_id_,
                            RawEntityId entity_id_,
                            RawEntityId kind_id_)
      : impl(std::move(impl_)),
        context_id(context_id_),
        entity_id(entity_id_),
        kind_id(kind_id_) {}

  static bool add(const ReferenceKind &kind, const VariantEntity &from,
                  const VariantEntity &to);

  static bool add(const ReferenceKind &kind, const VariantEntity &from,
                  const VariantEntity &to, const VariantEntity &context);

  EntityCategory category(void) const noexcept;

  // Is this a built-in reference kind?
  inline std::optional<BuiltinReferenceKind>
  builtin_reference_kind(void) const noexcept {
    if (kind_id >= NumEnumerators(BuiltinReferenceKind{})) {
      return std::nullopt;
    }
    return static_cast<BuiltinReferenceKind>(kind_id);
  }

  // The ID of the referenced entity.
  inline EntityId referenced_entity_id(void) const noexcept {
    return entity_id;
  }

  // Return the kind of this reference.
  ReferenceKind kind(void) const noexcept;

  // The contextual entity associated with this reference.
  VariantEntity context(void) const noexcept;

  // Generate all references from some kind of entity.
  static gap::generator<Reference> from(const VariantEntity &entity);

  // Generate all references to some kind of entity.
  static gap::generator<Reference> to(const VariantEntity &entity);

  // Return this reference as a `VariantEntity`.
  VariantEntity as_variant(void) const noexcept;

#define MX_DECLARE_REF_GETTER(ns_path, type_name, lower_name, ...) \
    std::optional<ns_path type_name> as_ ## lower_name (void) const noexcept;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER)
#undef MX_DECLARE_REF_GETTER

  // Implemented in `Index.h`.
  template <typename T>
  inline std::optional<T> as(void) const noexcept;
};

}  // namespace mx
