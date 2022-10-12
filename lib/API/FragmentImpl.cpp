// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"
#include "File.h"
#include <multiplier/entities/Attr.h>
#include <multiplier/entities/Type.h>

#include <cassert>

namespace mx {

FragmentImpl::~FragmentImpl(void) noexcept {}

// Return the token associated with a specific entity ID.
std::optional<Token> FragmentImpl::TokenFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  VariantId vid = eid.Unpack();

  // It's a fragment token.
  if (std::holds_alternative<FragmentTokenId>(vid)) {
    const FragmentTokenId tid = std::get<FragmentTokenId>(vid);

    // It's a token inside of the current fragment.
    if (tid.fragment_id == fragment_id) {
      auto reader = this->TokenReader(self);
      if (tid.offset < reader->NumTokens()) {
        Token tok(std::move(reader), tid.offset);
        if (tok.id() == eid) {
          return tok;
        } else {
          assert(false);
        }
      }

    // It's a token inside of another fragment, go get the other fragment.
    } else {
      auto other_frag = ep->FragmentFor(ep, tid.fragment_id);
      auto reader = other_frag->TokenReader(other_frag);
      if (tid.offset < reader->NumTokens()) {
        Token tok(std::move(reader), tid.offset);
        if (tok.id() == eid) {
          return tok;
        } else {
          assert(false);
        }
      }
    }

  // It's a file token; go get the file.
  } else if (std::holds_alternative<FileTokenId>(vid)) {
    const FileTokenId tid = std::get<FileTokenId>(vid);
    FileImpl::Ptr file = ep->FileFor(ep, tid.file_id);

    auto reader = file->TokenReader(file);
    if (tid.offset < reader->NumTokens()) {
      Token tok(std::move(reader), tid.offset);
      if (tok.id() == eid) {
        return tok;
      } else {
        assert(false);
      }
    }
  }

  if (can_fail) {
    assert(false);
    return Token();
  }

  return std::nullopt;
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
    if (bfid.fragment_id != efid.fragment_id || bfid.offset > efid.offset) {
      return TokenRange();
    }

    // It's a token inside of the current fragment.
    if (bfid.fragment_id == fragment_id) {
      if (efid.offset < num_tokens) {
        return TokenRange(this->TokenReader(self),
                          bfid.offset, efid.offset + 1u);
      }

    // It's a token inside of another fragment, go get the other fragment.
    } else {
      auto other_frag = ep->FragmentFor(ep, bfid.fragment_id);
      auto other_reader = other_frag->TokenReader(other_frag);
      if (auto other_num_tokens = other_reader->NumTokens();
          efid.offset < other_num_tokens) {
        return TokenRange(std::move(other_reader), bfid.offset,
                          efid.offset + 1u);
      }
    }

  // It's a file token; go get the file.
  } else if (std::holds_alternative<FileTokenId>(bvid)) {
    if (!std::holds_alternative<FileTokenId>(evid)) {
      return TokenRange();
    }

    auto bfid = std::get<FileTokenId>(bvid);
    auto efid = std::get<FileTokenId>(evid);
    if (bfid.file_id != efid.file_id || bfid.offset > efid.offset) {
      return TokenRange();
    }

    auto file = ep->FileFor(ep, bfid.file_id);
    auto file_reader = file->TokenReader(file);
    if (auto file_num_tokens = file_reader->NumTokens();
        efid.offset < file_num_tokens) {
      return TokenRange(std::move(file_reader), bfid.offset, efid.offset + 1u);
    }
  }

  return TokenRange();
}

// Return the declaration associated with a specific entity ID.
std::optional<Decl> FragmentImpl::DeclFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  VariantId vid = eid.Unpack();

  if (std::holds_alternative<DeclarationId>(vid)) {
    DeclarationId decl_id = std::get<DeclarationId>(vid);

    if (decl_id.fragment_id == fragment_id) {
      if (decl_id.offset < num_decls) {
        Decl decl(self, decl_id.offset);
        if (decl.id() == eid) {
          return decl;
        } else {
          assert(false);
        }
      }

    // It's a decl inside of another fragment, go get the other fragment.
    } else {
      auto frag = ep->FragmentFor(ep, decl_id.fragment_id);
      if (frag && decl_id.offset < frag->num_decls) {
        Decl decl(std::move(frag), decl_id.offset);
        if (decl.id() == eid) {
          return decl;
        } else {
          assert(false);
        }
      }
    }
  }

  if (!can_fail) {
    // TODO(pag): Check version number, do back-off to wait for indexer to
    //            finish. 
  }

  return std::nullopt;
}

// Return the statement associated with a specific entity ID.
std::optional<Stmt> FragmentImpl::StmtFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  VariantId vid = eid.Unpack();

  if (std::holds_alternative<StatementId>(vid)) {
    StatementId stmt_id = std::get<StatementId>(vid);

    // It's a statement inside of the current fragment.
    if (stmt_id.fragment_id == fragment_id) {
      if (stmt_id.offset < num_stmts) {
        Stmt stmt(self, stmt_id.offset);
        if (stmt.id() == eid) {
          return stmt;
        } else {
          assert(false);
        }
      }
    // It's a statement inside of another fragment, go get the other fragment.
    } else {
      auto frag = ep->FragmentFor(ep, stmt_id.fragment_id);
      if (frag && stmt_id.offset < frag->num_stmts) {
        Stmt stmt(std::move(frag), stmt_id.offset);
        if (stmt.id() == eid) {
          return stmt;
        } else {
          assert(false);
        }
      }
    }
  }

  if (!can_fail) {
    // TODO(pag): Check version number, do back-off to wait for indexer to
    //            finish. 
  }

  return std::nullopt;
}

// Return the type associated with a specific entity ID.
std::optional<Type> FragmentImpl::TypeFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  VariantId vid = eid.Unpack();

  // It's a fragment token.
  if (std::holds_alternative<TypeId>(vid)) {
    TypeId type_id = std::get<TypeId>(vid);

    // It's a type inside of the current fragment.
    if (type_id.fragment_id == fragment_id) {
      if (type_id.offset < num_types) {
        Type type(self, type_id.offset);
        if (type.id() == eid) {
          return type;
        } else {
          assert(false);
        }
      }

    // It's a type inside of another fragment, go get the other fragment.
    } else {
      auto frag = ep->FragmentFor(ep, type_id.fragment_id);
      if (frag && type_id.offset < frag->num_types) {
        Type type(std::move(frag), type_id.offset);
        if (type.id() == eid) {
          return type;
        } else {
          assert(false);
        }
      }
    }
  }

  if (!can_fail) {
    // TODO(pag): Check version number, do back-off to wait for indexer to
    //            finish. 
  }

  return std::nullopt;
}

// Return the type associated with a specific entity ID.
std::optional<Attr> FragmentImpl::AttrFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  VariantId vid = eid.Unpack();

  // It's a fragment token.
  if (std::holds_alternative<AttributeId>(vid)) {
    AttributeId attr_id = std::get<AttributeId>(vid);

    // It's an attribute inside of the current fragment.
    if (attr_id.fragment_id == fragment_id) {
      if (attr_id.offset < num_attrs) {
        Attr attr(self, attr_id.offset);
        if (attr.id() == eid) {
          return attr;
        } else {
          assert(false);
        }
      }

    // It's an attribute inside of another fragment, go get the other fragment.
    } else {
      auto frag = ep->FragmentFor(ep, attr_id.fragment_id);
      if (frag && attr_id.offset < frag->num_attrs) {
        Attr attr(std::move(frag), attr_id.offset);
        if (attr.id() == eid) {
          return attr;
        } else {
          assert(false);
        }
      }
    }
  }

  if (!can_fail) {
    // TODO(pag): Check version number, do back-off to wait for indexer to
    //            finish. 
  }

  return std::nullopt;
}

}  // namespace mx
