// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "API.h"

#include "File.h"
#include "Fragment.h"
#include "Token.h"

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

  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid == kInvalidEntityId);
    return Token();

  } else {
    assert(false);
    return Token();
  }
}

}  // namespace mx
