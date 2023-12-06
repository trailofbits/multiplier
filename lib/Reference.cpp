// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Reference.h"

#include <cassert>

#include "Attr.h"
#include "Compilation.h"
#include "Decl.h"
#include "File.h"
#include "Fragment.h"
#include "InvalidEntityProvider.h"
#include "Macro.h"
#include "Pseudo.h"
#include "Stmt.h"
#include "Token.h"
#include "Type.h"
#include "Types.h"

namespace mx {
namespace {

static const auto kInvalidEP = std::make_shared<InvalidEntityProvider>();

static OpaqueImplPtr ReferencedEntity(const EntityProviderPtr &ep,
                                      RawEntityId raw_id) {

  VariantId vid = EntityId(raw_id).Unpack();

  if (false) {

#define MX_DISPATCH_GETTER(type_name, lower_name, enum_name, category_) \
    } else if (std::holds_alternative<type_name ## Id>(vid)) { \
      return OpaqueImplPtr(ep->type_name ## For(ep, raw_id)); \

    MX_FOR_EACH_ENTITY_CATEGORY(MX_DISPATCH_GETTER, MX_IGNORE_ENTITY_CATEGORY,
                                MX_DISPATCH_GETTER, MX_DISPATCH_GETTER,
                                MX_DISPATCH_GETTER, MX_DISPATCH_GETTER,
                                MX_DISPATCH_GETTER)
#undef MX_DISPATCH_GETTER

  // It's a reference to a parsed token resident in a fragment.
  } else if (std::holds_alternative<ParsedTokenId>(vid)) {
    ParsedTokenId id = std::get<ParsedTokenId>(vid);
    FragmentId fid(id.fragment_id);

    if (FragmentImplPtr fptr = ep->FragmentFor(ep, fid);
        id.offset < fptr->num_parsed_tokens) {
      return OpaqueImplPtr(fptr->ParsedTokenReader(fptr));
    }
    assert(false);

  // It's a reference to a macro token resident in a fragment.
  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    MacroTokenId id = std::get<MacroTokenId>(vid);
    FragmentId fid(id.fragment_id);

    if (FragmentImplPtr frag_ptr = ep->FragmentFor(ep, fid);
        frag_ptr && id.offset < frag_ptr->num_tokens) {
      return OpaqueImplPtr(frag_ptr->MacroTokenReader(frag_ptr));
    }
    assert(false);

  // It's a reference to a file token.
  } else if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId id = std::get<FileTokenId>(vid);
    FileId fid(id.file_id);

    if (FileImplPtr file_ptr = ep->FileFor(ep, fid);
        file_ptr && id.offset < file_ptr->num_tokens) {
      return OpaqueImplPtr(file_ptr->TokenReader(file_ptr));
    }
    assert(false);

  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(raw_id == kInvalidEntityId);

  } else {
    assert(false);  // Should have been handled above.
  }

  return {};
}

// Add a reference between two entities.
static bool AddReference(const EntityProviderPtr &ep, RawEntityId kind_id,
                         RawEntityId from_id, RawEntityId to_id,
                         RawEntityId context_id) {
  if (from_id == kInvalidEntityId || to_id == kInvalidEntityId) {
    return false;
  }
  if (context_id == kInvalidEntityId) {
    context_id = from_id;
  }
  return ep->AddReference(ep, kind_id, from_id, to_id, context_id);
}

}  // namespace

const char *EnumeratorName(BuiltinReferenceKind kind) {
  switch (kind) {
    case BuiltinReferenceKind::USES_VALUE: return "USES_VALUE";
    case BuiltinReferenceKind::USES_TYPE: return "USES_TYPE";
    case BuiltinReferenceKind::CASTS_WITH_TYPE: return "CASTS_WITH_TYPE";
    case BuiltinReferenceKind::COPIES_VALUE: return "COPIES_VALUE";
    case BuiltinReferenceKind::TESTS_VALUE: return "TESTS_VALUE";
    case BuiltinReferenceKind::WRITES_VALUE: return "WRITES_VALUE";
    case BuiltinReferenceKind::UPDATES_VALUE: return "UPDATES_VALUE";
    case BuiltinReferenceKind::ACCESSES_VALUE: return "ACCESSES_VALUE";
    case BuiltinReferenceKind::TAKES_VALUE: return "TAKES_VALUE";
    case BuiltinReferenceKind::CALLS: return "CALLS";
    case BuiltinReferenceKind::TAKES_ADDRESS: return "TAKES_ADDRESS";
    case BuiltinReferenceKind::INCLUDES_FILE: return "INCLUDES_FILE";
    case BuiltinReferenceKind::EXPANSION_OF: return "EXPANSION_OF";
  }
}

gap::generator<Reference> EmptyReferences(void) {
  co_return;
}

gap::generator<Reference> References(EntityProviderPtr ep, RawEntityId raw_id,
                                     EntityProvider::ReferenceDirection dir) {
  for (auto [entity_id, context_id, kind_id] : ep->References(ep, raw_id, dir)) {
    if (auto eptr = ReferencedEntity(ep, entity_id)) {
      co_yield Reference(std::move(eptr), context_id, entity_id, kind_id);
    }
  }
}

RawEntityId ReferenceKind::id(void) const noexcept {
  return impl->kind_id;
}

// Get a reference kind for a builtin kind.
ReferenceKind ReferenceKind::get(const Index &index,
                                 BuiltinReferenceKind kind) {
  const auto &ep = index.impl;
  if (auto rptr = ep->ReferenceKindFor(ep, static_cast<RawEntityId>(kind))) {
    return rptr;
  }

  assert(false);
  return std::make_shared<const ReferenceKindImpl>(
      kInvalidEP, ~0ull, "<invalid>");
}

// Get or create a reference kind.
ReferenceKind ReferenceKind::get(const Index &index, std::string_view name) {
  const auto &ep = index.impl;
  if (ReferenceKindImplPtr rptr = ep->ReferenceKindFor(ep, name)) {
    return rptr;
  }

  assert(false);
  return std::make_shared<const ReferenceKindImpl>(
      kInvalidEP, ~0ull, "<invalid>");
}

// Is this a built-in reference kind?
std::optional<BuiltinReferenceKind>
ReferenceKind::builtin_reference_kind(void) const noexcept {
  if (impl->kind_id >= NumEnumerators(BuiltinReferenceKind{})) {
    return std::nullopt;
  }

  return static_cast<BuiltinReferenceKind>(impl->kind_id);
}

// The name of this reference kind.
std::string_view ReferenceKind::data(void) const & noexcept {
  return impl->kind_data;
}

// The name of this reference kind.
std::string ReferenceKind::data(void) const && noexcept {
  return impl->kind_data;
}

// Return the kind of this reference.
ReferenceKind Reference::kind(void) const noexcept {
  ReferenceKindImplPtr rptr;
  if (std::optional<Index> index = Index::containing(as_variant())) {
    const EntityProviderPtr &ep = index->impl;
    rptr = ep->ReferenceKindFor(ep, kind_id);
  }

  if (!rptr) {
    assert(false);
    rptr = std::make_shared<ReferenceKindImpl>(kInvalidEP, ~0ull, "<invalid>");
  }

  return rptr;
}

bool Reference::add(const ReferenceKind &kind, const VariantEntity &from,
                    const VariantEntity &to) {
  auto from_id = EntityId(from).Pack();
  return AddReference(kind.impl->ep, reference_kind_id(kind), from_id,
                      EntityId(to).Pack(), from_id);
}

bool Reference::add(const ReferenceKind &kind, const VariantEntity &from,
                    const VariantEntity &to, const VariantEntity &context) {
  return AddReference(kind.impl->ep, reference_kind_id(kind),
                      EntityId(from).Pack(), EntityId(to).Pack(),
                      EntityId(context).Pack());
}

EntityCategory Reference::category(void) const noexcept {
  return CategoryFromEntityId(entity_id);
}

VariantEntity Reference::context(void) const noexcept {
  if (context_id == entity_id) {
    return as_variant();
  }

  if (auto index = Index::containing(as_variant())) {
    return index->entity(context_id);
  }

  assert(false);
  return NotAnEntity{};
}

// Return this reference as a `VariantEntity`.
VariantEntity Reference::as_variant(void) const noexcept {
  switch (category()) {
    case EntityCategory::NOT_AN_ENTITY: break;

#define DEFINE_REF_GETTER(type_name, lower_name, enum_name, category_) \
    case EntityCategory::enum_name: \
      if (auto ent_ ## lower_name = as_ ## lower_name()) { \
        return std::move(ent_ ## lower_name.value()); \
      } \
      break;

    MX_FOR_EACH_ENTITY_CATEGORY(DEFINE_REF_GETTER,
                                DEFINE_REF_GETTER,
                                DEFINE_REF_GETTER,
                                DEFINE_REF_GETTER,
                                DEFINE_REF_GETTER,
                                DEFINE_REF_GETTER,
                                DEFINE_REF_GETTER)
#undef DEFINE_REF_GETTER
  }
  return NotAnEntity{};
}

std::optional<Token> Reference::as_token(void) const noexcept {
  if (category() != EntityCategory::TOKEN) {
    return std::nullopt;
  }

  if (!impl) {
    assert(false);
    return std::nullopt;
  }

  auto offset = FragmentOffsetFromEntityId(entity_id);
  if (!offset) {
    assert(false);
    return std::nullopt;
  }

  return Token(
      TokenReaderPtr(impl, reinterpret_cast<const TokenReader *>(impl.get())),
      offset.value());
}

// Generate all references to some kind of entity.
gap::generator<Reference> Reference::to(const VariantEntity &entity) {
  if (auto index = Index::containing(entity)) {
    return References(index->impl, EntityId(entity).Pack(),
                      EntityProvider::kReferenceTo);
  }
  return EmptyReferences();
}

// Generate all references from some kind of entity.
gap::generator<Reference> Reference::from(const VariantEntity &entity) {
  if (auto index = Index::containing(entity)) {
    return References(index->impl, EntityId(entity).Pack(),
                      EntityProvider::kReferenceFrom);
  }
  return EmptyReferences();
}

#define DEFINE_REF_GETTER(type_name, lower_name, enum_name, category_) \
    std::optional<type_name> \
    Reference::as_ ## lower_name (void) const noexcept { \
      if (category() != EntityCategory::enum_name) { \
        return std::nullopt; \
      } \
      if (!impl) { \
        assert(false); \
        return std::nullopt; \
      } \
      return type_name(type_name ## ImplPtr( \
          impl, reinterpret_cast<const type_name ## Impl *>(impl.get()))); \
    }

MX_FOR_EACH_ENTITY_CATEGORY(DEFINE_REF_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            DEFINE_REF_GETTER,
                            DEFINE_REF_GETTER,
                            DEFINE_REF_GETTER,
                            DEFINE_REF_GETTER,
                            DEFINE_REF_GETTER)

#undef DEFINE_REF_GETTER

}  // namespace mx
