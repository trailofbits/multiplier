// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Reference.h"

#include <cassert>

#include "Attr.h"
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

}  // namespace

std::pair<OpaqueImplPtr, EntityCategory> ReferencedEntity(
    const EntityProviderPtr &ep, RawEntityId raw_id) {

  VariantId vid = EntityId(raw_id).Unpack();

  if (false) {

#define MX_DISPATCH_GETTER(type_name, lower_name, enum_name, category_) \
    } else if (std::holds_alternative<type_name ## Id>(vid)) { \
      return {OpaqueImplPtr(ep->type_name ## For(ep, raw_id)), \
              EntityCategory::enum_name}; \

    MX_FOR_EACH_ENTITY_CATEGORY(MX_DISPATCH_GETTER, MX_IGNORE_ENTITY_CATEGORY,
                                MX_DISPATCH_GETTER, MX_DISPATCH_GETTER, MX_DISPATCH_GETTER,
                                MX_DISPATCH_GETTER)
#undef MX_DISPATCH_GETTER

  // It's a reference to a parsed token resident in a fragment.
  } else if (std::holds_alternative<ParsedTokenId>(vid)) {
    ParsedTokenId id = std::get<ParsedTokenId>(vid);
    FragmentId fid(id.fragment_id);

    if (FragmentImplPtr fptr = ep->FragmentFor(ep, fid);
        id.offset < fptr->num_parsed_tokens) {
      return {OpaqueImplPtr(fptr->ParsedTokenReader(fptr)),
              EntityCategory::TOKEN};
    }
    assert(false);

  // It's a reference to a macro token resident in a fragment.
  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    MacroTokenId id = std::get<MacroTokenId>(vid);
    FragmentId fid(id.fragment_id);

    if (FragmentImplPtr frag_ptr = ep->FragmentFor(ep, fid);
        frag_ptr && id.offset < frag_ptr->num_tokens) {
      return {OpaqueImplPtr(frag_ptr->MacroTokenReader(frag_ptr)),
              EntityCategory::TOKEN};
    }
    assert(false);

  // It's a reference to a file token.
  } else if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId id = std::get<FileTokenId>(vid);
    FileId fid(id.file_id);

    if (FileImplPtr file_ptr = ep->FileFor(ep, fid);
        file_ptr && id.offset < file_ptr->num_tokens) {
      return {OpaqueImplPtr(file_ptr->TokenReader(file_ptr)),
              EntityCategory::TOKEN};
    }
    assert(false);

  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(raw_id == kInvalidEntityId);

  } else {
    assert(false);  // Should have been handled above.
  }

  return {{}, EntityCategory::NOT_AN_ENTITY};
}

// Get or create a reference kind.
ReferenceKind ReferenceKind::get(const Index &index, std::string_view name) {
  const EntityProviderPtr &ep = index.impl;
  ReferenceKindImplPtr rptr = ep->ReferenceKindFor(ep, name);
  if (!rptr) {
    assert(false);
    rptr = std::make_shared<ReferenceKindImpl>(
        kInvalidEP, ~0ull, "<invalid>");
  }

  return rptr;
}

// Was this reference added by the code?
bool ReferenceKind::is_explicit_code_reference(void) const noexcept {
  return !impl->kind_id;
}

// The name of this reference kind.
const std::string &ReferenceKind::kind(void) const & noexcept {
  return impl->kind_data;
}

// The name of this reference kind.
std::string ReferenceKind::kind(void) const && noexcept {
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
    rptr = std::make_shared<ReferenceKindImpl>(
        kInvalidEP, ~0ull, "<invalid>");
  }

  return rptr;
}

// Add a reference between two entities.
bool Reference::add(const ReferenceKind &kind, RawEntityId from_id,
                    RawEntityId to_id, int) {
  const EntityProviderPtr &ep = kind.impl->ep;
  auto found = false;
  for (RawEntityId redecl_id : ep->Redeclarations(ep, from_id)) {
    from_id = redecl_id;
    found = true;
    break;
  }

  if (!found) {
    return false;
  }

  found = false;
  for (RawEntityId redecl_id : ep->Redeclarations(ep, to_id)) {
    to_id = redecl_id;
    found = true;
    break;
  }

  if (!found) {
    return false;
  }

  return ep->AddReference(ep, kind.impl->kind_id, from_id, to_id);
}

// Return this reference as a `VariantEntity`.
VariantEntity Reference::as_variant(void) const noexcept {
  switch (category_) {
    case EntityCategory::NOT_AN_ENTITY: break;

#define DEFINE_REF_GETTER(type_name, lower_name, enum_name, category) \
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
                                DEFINE_REF_GETTER)
#undef DEFINE_REF_GETTER
  }
  return NotAnEntity{};
}

std::optional<Token> Reference::as_token(void) const noexcept {
  if (category_ != EntityCategory::TOKEN) {
    return std::nullopt;
  }

  if (!impl) {
    assert(false);
    return std::nullopt;
  }

  auto offset = FragmentOffsetFromEntityId(eid);
  if (!offset) {
    assert(false);
    return std::nullopt;
  }

  return Token(
      TokenReader::Ptr(impl, reinterpret_cast<const TokenReader *>(impl.get())),
      offset.value());
}

#define DEFINE_REF_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> \
    Reference::as_ ## lower_name (void) const noexcept { \
      if (category_ != EntityCategory::enum_name) { \
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
                            DEFINE_REF_GETTER)

#undef DEFINE_REF_GETTER

}  // namespace mx
