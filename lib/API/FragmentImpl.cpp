// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"
#include "File.h"

namespace mx {

FragmentImpl::~FragmentImpl(void) noexcept {}

// Return the token associated with a specific entity ID.
Token FragmentImpl::TokenFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  VariantId vid = eid.Unpack();

  // It's a fragment token.
  if (std::holds_alternative<FragmentTokenId>(vid)) {
    const FragmentTokenId tid = std::get<FragmentTokenId>(vid);

    // It's a token inside of the current fragment.
    if (tid.fragment_id == fragment_id) {
      return Token(this->TokenReader(self), tid.offset);

    // It's a token inside of another fragment, go get the other fragment.
    } else {
      auto other_frag = ep->FragmentFor(ep, tid.fragment_id);
      auto reader = other_frag->TokenReader(other_frag);
      return Token(std::move(reader), tid.offset);
    }

  // It's a file token; go get the file.
  } else if (std::holds_alternative<FileTokenId>(vid)) {
    const FileTokenId tid = std::get<FileTokenId>(vid);
    FileImpl::Ptr file;
    if (containing_file && containing_file->file_id == tid.file_id) {
      file = containing_file;  // Try to use the containing file if it matches.
    } else {
      file = ep->FileFor(ep, tid.file_id);
    }

    auto reader = file->TokenReader(file);
    return Token(std::move(reader), tid.offset);

  // An invalid ID.
  } else if (std::holds_alternative<InvalidId>(vid)) {
    if (can_fail) {
      return {};
    } else {
      throw std::domain_error(
          "Invalid entity ID passed to FragmentImpl::TokenFor");
    }

  // A non-token ID.
  } else {
    throw std::domain_error(
        "Non-token entity ID passed to FragmentImpl::TokenFor");
  }
}

// Return the inclusive token range associated with two entity IDs.
TokenRange FragmentImpl::TokenRangeFor(
    const FragmentImpl::Ptr &self, EntityId begin_id, EntityId end_id) const {
  VariantId bvid = begin_id.Unpack();
  VariantId evid = end_id.Unpack();

  // It's a fragment token.
  if (std::holds_alternative<FragmentTokenId>(bvid)) {
    if (!std::holds_alternative<FragmentTokenId>(evid)) {
      return TokenRange();
    }

    auto bfid = std::get<FragmentTokenId>(bvid);
    auto efid = std::get<FragmentTokenId>(evid);
    if (bfid.fragment_id != efid.fragment_id ||
        bfid.offset > efid.offset) {
      return TokenRange();
    }

    // It's a token inside of the current fragment.
    if (bfid.fragment_id == fragment_id) {
      return TokenRange(this->TokenReader(self), bfid.offset, efid.offset + 1u);

    // It's a token inside of another fragment, go get the other fragment.
    } else {
      auto other_frag = ep->FragmentFor(ep, bfid.fragment_id);
      auto reader = other_frag->TokenReader(other_frag);
      return TokenRange(std::move(reader), bfid.offset, efid.offset + 1u);
    }

  // It's a file token; go get the file.
  } else if (std::holds_alternative<FileTokenId>(bvid)) {
    if (!std::holds_alternative<FileTokenId>(evid)) {
      return TokenRange();
    }

    auto bfid = std::get<FileTokenId>(bvid);
    auto efid = std::get<FileTokenId>(evid);
    if (bfid.file_id != efid.file_id ||
        bfid.offset > efid.offset) {
      return TokenRange();
    }

    FileImpl::Ptr file;
    if (containing_file && containing_file->file_id == bfid.file_id) {
      file = containing_file;  // Try to use the containing file if it matches.
    } else {
      file = ep->FileFor(ep, bfid.file_id);
    }

    auto reader = file->TokenReader(file);
    return TokenRange(std::move(reader), bfid.offset, efid.offset + 1u);

  // An invalid ID.
  } else if (std::holds_alternative<InvalidId>(bvid) &&
             std::holds_alternative<InvalidId>(evid)) {
    return TokenRange();

  // A non-token ID.
  } else {
    assert(false);
    return TokenRange();
  }
}

// Return the declaration associated with a specific entity ID.
Decl FragmentImpl::DeclFor(const FragmentImpl::Ptr &self, EntityId eid) const {
  VariantId vid = eid.Unpack();

  // It's a fragment token.
  if (!std::holds_alternative<DeclarationId>(vid)) {
    assert(false);
    abort();
  }

  DeclarationId decl_id = std::get<DeclarationId>(vid);

#ifndef NDEBUG  // It's a token inside of the current fragment.
  if (decl_id.fragment_id == fragment_id) {
    Decl decl(self, decl_id.offset);
    return decl;

  // It's a token inside of another fragment, go get the other fragment.
  } else {
    Decl decl(ep->FragmentFor(ep, decl_id.fragment_id), decl_id.offset);
    return decl;
  }
#else
  // It's a token inside of the current fragment.
  if (decl_id.fragment_id == fragment_id) {
    return Decl(self, decl_id.offset);

  // It's a token inside of another fragment, go get the other fragment.
  } else {
    return Decl(ep->FragmentFor(ep, decl_id.fragment_id), decl_id.offset);
  }
#endif
}

// Return the statement associated with a specific entity ID.
Stmt FragmentImpl::StmtFor(const FragmentImpl::Ptr &self, EntityId eid) const {
  VariantId vid = eid.Unpack();

  // It's a fragment token.
  if (!std::holds_alternative<StatementId>(vid)) {
    assert(false);
    abort();
  }

  StatementId stmt_id = std::get<StatementId>(vid);

  // It's a token inside of the current fragment.
  if (stmt_id.fragment_id == fragment_id) {
    return Stmt(self, stmt_id.offset);

  // It's a token inside of another fragment, go get the other fragment.
  } else {
    return Stmt(ep->FragmentFor(ep, stmt_id.fragment_id), stmt_id.offset);
  }
}


// Return the type associated with a specific entity ID.
Type FragmentImpl::TypeFor(const FragmentImpl::Ptr &self, EntityId eid) const {
  VariantId vid = eid.Unpack();

  // It's a fragment token.
  if (!std::holds_alternative<TypeId>(vid)) {
    assert(false);
    abort();
  }

  TypeId type_id = std::get<TypeId>(vid);

  // It's a token inside of the current fragment.
  if (type_id.fragment_id == fragment_id) {
    return Type(self, type_id.offset);

  // It's a token inside of another fragment, go get the other fragment.
  } else {
    return Type(ep->FragmentFor(ep, type_id.fragment_id), type_id.offset);
  }
}

}  // namespace mx
