// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "EntityProvider.h"

#include "Compilation.h"
#include "Attr.h"
#include "Decl.h"
#include "EntityProvider.h"
#include "File.h"
#include "Fragment.h"
#include "Macro.h"
#include "Pseudo.h"
#include "Reference.h"
#include "SQLiteStore.h"
#include "Stmt.h"
#include "Type.h"

namespace mx {

EntityProvider::~EntityProvider(void) noexcept {}

// Get a token by its entity ID.
Token EntityProvider::TokenFor(const Ptr &self, RawEntityId id) {
  VariantId vid = EntityId(id).Unpack();
  if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId tid = std::get<FileTokenId>(vid);
    FileId fid(tid.file_id);
    FileImplPtr fptr = self->FileFor(self, fid);
    if (!fptr) {
      assert(false);
      return Token();
    }

    if (tid.offset >= fptr->num_tokens) {
      assert(false);
      return Token();
    }

    return Token(fptr->TokenReader(fptr), tid.offset);

  } else if (std::holds_alternative<ParsedTokenId>(vid)) {
    ParsedTokenId tid = std::get<ParsedTokenId>(vid);
    FragmentId fid(tid.fragment_id);
    FragmentImplPtr fptr = self->FragmentFor(self, fid);
    if (!fptr) {
      assert(false);
      return Token();
    }

    if (tid.offset >= fptr->num_parsed_tokens) {
      assert(false);
      return Token();
    }

    return Token(fptr->ParsedTokenReader(fptr), tid.offset);

  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    MacroTokenId tid = std::get<MacroTokenId>(vid);
    FragmentId fid(tid.fragment_id);
    FragmentImplPtr fptr = self->FragmentFor(self, fid);
    if (!fptr) {
      assert(false);
      return Token();
    }

    if (tid.offset >= fptr->num_tokens) {
      assert(false);
      return Token();
    }

    return Token(fptr->MacroTokenReader(fptr), tid.offset);

  } else if (std::holds_alternative<TypeTokenId>(vid)) {
    TypeTokenId ttid = std::get<TypeTokenId>(vid);
    TypeId tid(ttid);
    TypeImplPtr tptr = self->TypeFor(self, tid);
    if (!tptr) {
      assert(false);
      return Token();
    }

    return Token(tptr->TypeTokenReader(tptr), ttid.offset);

  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(id == kInvalidEntityId);
    return Token();

  } else {
    assert(false);
    return Token();
  }
}

// Get a token by its entity ID, and given the presence of an existing reader
// that can be used as a hint for being the current reader for the token.
Token EntityProvider::TokenFor(
    const Ptr &self, const std::shared_ptr<const TokenReader> &reader,
    RawEntityId eid) {
  VariantId vid = EntityId(eid).Unpack();
  if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId tid = std::get<FileTokenId>(vid);
    FileId fid(tid.file_id);
    FileImplPtr fptr;

    if (const FileImpl *raw_file = reader->OwningFile();
        raw_file && raw_file->file_id == tid.file_id) {
      fptr = FileImplPtr(reader, raw_file);
    } else {
      fptr = self->FileFor(self, fid);
    }

    if (!fptr) {
      assert(false);
      return Token();
    }

    if (tid.offset >= fptr->num_tokens) {
      assert(false);
      return Token();
    }

    return Token(fptr->TokenReader(fptr), tid.offset);

  } else if (std::holds_alternative<ParsedTokenId>(vid)) {
    ParsedTokenId tid = std::get<ParsedTokenId>(vid);
    FragmentId fid(tid.fragment_id);
    FragmentImplPtr fptr;

    if (const FragmentImpl *raw_frag = reader->OwningFragment();
        raw_frag && raw_frag->fragment_id == tid.fragment_id) {
      fptr = FragmentImplPtr(reader, raw_frag);
    } else {
      fptr = self->FragmentFor(self, fid);
    }

    if (!fptr) {
      assert(false);
      return Token();
    }

    if (tid.offset >= fptr->num_parsed_tokens) {
      assert(false);
      return Token();
    }

    return Token(fptr->ParsedTokenReader(fptr), tid.offset);

  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    MacroTokenId tid = std::get<MacroTokenId>(vid);
    FragmentId fid(tid.fragment_id);
    FragmentImplPtr fptr;

    if (const FragmentImpl *raw_frag = reader->OwningFragment();
        raw_frag && raw_frag->fragment_id == tid.fragment_id) {
      fptr = FragmentImplPtr(reader, raw_frag);
    } else {
      fptr = self->FragmentFor(self, fid);
    }

    if (!fptr) {
      assert(false);
      return Token();
    }

    if (tid.offset >= fptr->num_tokens) {
      assert(false);
      return Token();
    }

    return Token(fptr->MacroTokenReader(fptr), tid.offset);

  } else if (std::holds_alternative<TypeTokenId>(vid)) {
    TypeTokenId ttid = std::get<TypeTokenId>(vid);
    TypeId tid(ttid);
    TypeImplPtr tptr = self->TypeFor(self, tid);
    if (!tptr) {
      assert(false);
      return Token();
    }

    // fix-me
    return Token();
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid == kInvalidEntityId);
    return Token();

  } else {
    assert(false);
    return Token();
  }
}

// Get the inclusive token range associated with two entity IDs.
TokenRange EntityProvider::TokenRangeFor(
    const Ptr &self, EntityId begin_id, EntityId end_id) const {
  VariantId bvid = EntityId(begin_id).Unpack();
  VariantId evid = EntityId(begin_id).Unpack();

  if (std::holds_alternative<FileTokenId>(bvid)) {
    if (!std::holds_alternative<FileTokenId>(evid)) {
      return TokenRange();
    }

    auto bfid = std::get<FileTokenId>(bvid);
    auto efid = std::get<FileTokenId>(evid);
    if (bfid.file_id != efid.file_id || bfid.offset > efid.offset) {
      return TokenRange();
    }

    FileId fid(bfid.file_id);
    if (FileImplPtr file = self->FileFor(self, fid);
        file && efid.offset < file->num_tokens) {
      return TokenRange(file->TokenReader(file), bfid.offset, efid.offset + 1u);
    }

  } else if (std::holds_alternative<ParsedTokenId>(bvid)) {
    if (!std::holds_alternative<ParsedTokenId>(evid)) {
      return TokenRange();
    }

    auto bfid = std::get<ParsedTokenId>(bvid);
    FragmentId fid(bfid.fragment_id);
    auto fragment = self->FragmentFor(self, fid);
    return fragment->TokenRangeFor(fragment, begin_id, end_id);

  } else if (std::holds_alternative<MacroTokenId>(bvid)) {
    if (!std::holds_alternative<MacroTokenId>(evid)) {
      return TokenRange();
    }

    auto bfid = std::get<MacroTokenId>(bvid);
    FragmentId fid(bfid.fragment_id);
    auto fragment = self->FragmentFor(self, fid);
    return fragment->TokenRangeFor(fragment, begin_id, end_id);

  } else if (std::holds_alternative<TypeTokenId>(bvid)) {
    if (!std::holds_alternative<TypeTokenId>(evid)) {
      return TokenRange();
    }

    auto btid = std::get<TypeTokenId>(bvid);
    TypeId fid(btid);
    auto type = self->TypeFor(self, fid);
    return type->TokenRangeFor(type, begin_id, end_id);

  }

  return TokenRange();
}

namespace {

// This is super ugly, but we need to figure out if the declaration is a
// definition, because that is a component of the entity id. That knowledge is
// stored inside of the serialized form of the `Decl` itself, accessible via
// `Decl::is_definition()`. We can pass in a mostly-right id, `id`, fake a
// `DeclImplPtr` that aliases `frag`, and then ask for its "true" ID.
inline static RawEntityId DefinitionId(FragmentImplPtr frag, RawEntityId id,
                                       ast::Decl::Reader reader) {
  DeclImpl fake_impl(frag, kj::mv(reader), id);
  return Decl(DeclImplPtr(frag, &fake_impl)).id().Pack();
}

template <typename... Args>
inline static RawEntityId DefinitionId(const Args&...) {
  return kInvalidEntityId;
}

}  // namespace

// Something like `EntityFor(ep, kind)`, e.g. get all declarations of a specific
// kind.
#define MX_DECLARE_FRAGMENT_OFFSET_LISTERS(type_name, lower_name, enum_name, category) \
    gap::generator<type_name ## ImplPtr> EntityProvider::type_name ## sFor( \
        const Ptr &self, type_name ## Kind kind, PackedFragmentId frag_id) & { \
      \
      auto ep = self; \
      auto frag = ep->FragmentFor(ep, frag_id); \
      if (!frag) { \
        assert(false); \
        co_return; \
      } \
      \
      auto kind_index = static_cast<unsigned>(kind); \
      auto kind_list_reader = frag->reader.get ## type_name ## s(); \
      if (kind_index >= kind_list_reader.size()) { \
        co_return; \
      } \
      \
      auto list_reader = kind_list_reader[kind_index]; \
      for (auto i = 0u, max_i = list_reader.size(); i < max_i; ++i) { \
        type_name ## Id id = {}; \
        id.fragment_id = frag->fragment_id; \
        id.kind = kind; \
        id.offset = i; \
        RawEntityId raw_id = EntityId(id).Pack(); \
        \
        auto reader = list_reader[i]; \
        if constexpr (std::is_same_v<type_name ## Id, DeclId>) { \
          raw_id = DefinitionId(frag, raw_id, reader); \
        } \
        \
        if (auto eptr = ep->type_name ## For(ep, raw_id)) { \
          co_yield eptr; \
          continue; \
        } \
        \
        assert(false); \
        co_yield std::make_shared<type_name ## Impl>( \
            frag, kj::mv(reader), raw_id); \
      } \
    } \
    \
    gap::generator<type_name ## ImplPtr> EntityProvider::type_name ## sFor( \
        const Ptr &self, PackedFragmentId frag_id) & { \
      \
      auto ep = self; \
      auto frag = ep->FragmentFor(ep, frag_id); \
      if (!frag) { \
        assert(false); \
        co_return; \
      } \
      \
      auto kind_list_reader = frag->reader.get ## type_name ## s(); \
      for (auto kind_index = 0u, num_kinds = kind_list_reader.size(); \
           kind_index < num_kinds; ++kind_index) { \
        \
        auto list_reader = kind_list_reader[kind_index]; \
        for (auto i = 0u, max_i = list_reader.size(); i < max_i; ++i) { \
          type_name ## Id id = {}; \
          id.fragment_id = frag->fragment_id; \
          id.kind = static_cast<type_name ## Kind>(kind_index); \
          id.offset = i; \
          RawEntityId raw_id = EntityId(id).Pack(); \
          \
          auto reader = list_reader[i]; \
          if constexpr (std::is_same_v<type_name ## Id, DeclId>) { \
            raw_id = DefinitionId(frag, raw_id, reader); \
          } \
          \
          if (auto eptr = ep->type_name ## For(ep, raw_id)) { \
            co_yield eptr; \
            continue; \
          } \
          \
          assert(false); \
          co_yield std::make_shared<type_name ## Impl>( \
              frag, kj::mv(reader), raw_id); \
        } \
      } \
    }

#define MX_DECLARE_FRAGMENT_PSEUDO_LISTERS(type_name, lower_name, enum_name, category) \
    gap::generator<type_name ## ImplPtr> EntityProvider::type_name ## sFor( \
        const Ptr &self, PackedFragmentId frag_id) & { \
      \
      auto ep = self; \
      auto frag = ep->FragmentFor(ep, frag_id); \
      if (!frag) { \
        assert(false); \
        co_return; \
      } \
      \
      auto list_reader = frag->reader.get ## type_name ## s(); \
      for (auto i = 0u, max_i = list_reader.size(); i < max_i; ++i) { \
        type_name ## Id id = {}; \
        id.fragment_id = frag->fragment_id; \
        id.offset = i; \
        RawEntityId raw_id = EntityId(id).Pack(); \
        \
        if (auto eptr = ep->type_name ## For(ep, raw_id)) { \
          co_yield eptr; \
          continue; \
        } \
        \
        assert(false); \
        co_yield std::make_shared<type_name ## Impl>( \
            frag, list_reader[i], raw_id); \
      } \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_FRAGMENT_OFFSET_LISTERS,
                            MX_DECLARE_FRAGMENT_PSEUDO_LISTERS,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_FRAGMENT_OFFSET_LISTERS
#undef MX_DECLARE_FRAGMENT_PSEUDO_LISTERS

}  // namespace mx
