// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "EntityProvider.h"

#include "File.h"
#include "Fragment.h"
#include "Token.h"
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

}  // namespace mx
