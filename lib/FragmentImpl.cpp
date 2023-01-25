// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

#include <cassert>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/TokenKind.h>
#include <multiplier/Entities/Type.h>

#include "File.h"

namespace mx {

FragmentImpl::~FragmentImpl(void) noexcept {}


FragmentImpl::FragmentImpl(FragmentId id_,
                           EntityProvider::Ptr ep_,
                           const std::string &data)
    : fragment_id(id_.fragment_id),
      ep(std::move(ep_)),
      package(data),
      reader(package.Reader<rpc::Fragment>()),
      parsed_token_reader(this),
      macro_token_reader(this),
      num_parsed_tokens(reader.getParsedTokenContextOffsets().size()),
      num_tokens(reader.getTokenKinds().size()) {

  assert(num_parsed_tokens <= num_tokens);
  assert(num_tokens == reader.getDerivedTokenIds().size());
  assert((num_tokens + 1u) == reader.getTokenOffsets().size());
  assert(num_parsed_tokens == reader.getParsedTokenOffsetToIndex().size());
  assert(num_tokens == reader.getMacroTokenIndexToParsedTokenOffset().size());
  assert(num_tokens == reader.getRelatedEntityId().size());
}

// Return the ID of the file containing the first token.
//
// NOTE(pag): This returns the raw, unpacked file id.
RawEntityId FragmentImpl::FileContaingFirstToken(void) const {
  EntityId id(reader.getFirstFileTokenId());
  if (VariantId unpacked_id = id.Unpack();
      std::holds_alternative<FileTokenId>(unpacked_id)) {
    FileId fid(std::get<FileTokenId>(unpacked_id).file_id);
    return EntityId(fid).Pack();
  } else {
    return kInvalidEntityId;
  }
}

// Return a reader for the parsed tokens in the fragment. This doesn't
// include all tokens, i.e. macro use tokens, comments, etc.
TokenReader::Ptr FragmentImpl::ParsedTokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReader::Ptr(self, &parsed_token_reader);
}

// Return a reader for the macro tokens in the fragment.
TokenReader::Ptr FragmentImpl::MacroTokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReader::Ptr(self, &macro_token_reader);
}

// Return the number of tokens in the fragment.
EntityOffset ReadMacroTokensFromFragment::NumTokens(void) const {
  return fragment->num_tokens;
}

// Return the kind of the Nth token.
TokenKind ReadMacroTokensFromFragment::NthTokenKind(EntityOffset ti) const {
  if (ti >= fragment->num_tokens) {
    assert(false);
    return TokenKind::UNKNOWN;
  }
  return static_cast<TokenKind>(fragment->Fragment().getTokenKinds()[ti]);
}

// Return the data of the Nth token.
std::string_view ReadMacroTokensFromFragment::NthTokenData(
    EntityOffset ti) const {
  if (ti >= fragment->num_tokens) {
    assert(false);
    return {};
  }

  auto &reader = fragment->Fragment();
  auto tor = reader.getTokenOffsets();
  auto bo = tor[ti];
  auto eo = tor[ti + 1u];
  return std::string_view(&(reader.getTokenData().cStr()[bo]), (eo - bo));
}

// Return the id of the token from which the Nth token is derived.
EntityId ReadMacroTokensFromFragment::NthDerivedTokenId(EntityOffset ti) const {
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }
  return fragment->Fragment().getDerivedTokenIds()[ti];
}

// Return the id of the parsed token which is derived from the Nth token.
EntityId ReadMacroTokensFromFragment::NthParsedTokenId(EntityOffset ti) const {
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  auto &reader = fragment->Fragment();
  auto mti2o = reader.getMacroTokenIndexToParsedTokenOffset();
  auto to = mti2o[ti];

  // NOTE(pag): Not an asserting condition; the serialization code stores
  //            `num_parsed_tokens` for "no relation" and stores
  //            `num_parsed_tokens + 1` for a one-to-many relation.
  if (to >= fragment->num_parsed_tokens) {
    return kInvalidEntityId;
  }

  ParsedTokenId id;
  id.fragment_id = fragment->fragment_id;
  id.kind = static_cast<TokenKind>(reader.getTokenKinds()[ti]);
  id.offset = to;

  return id;
}

// Return the id of the macro containing the Nth token.
EntityId ReadMacroTokensFromFragment::NthContainingMacroId(
    EntityOffset ti) const {
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  auto &reader = fragment->Fragment();
  auto mti2o = reader.getMacroTokenIndexToMacroOffset();
  auto mo = mti2o[ti];

  // NOTE(pag): Not an asserting condition; the serialization code stores
  //            `num_parsed_tokens` for "no relation" and stores
  //            `num_parsed_tokens + 1` for a one-to-many relation.
  auto macro_reader = fragment->NthMacro(mo);
  if (!macro_reader.has_value()) {
    return kInvalidEntityId;
  }

  // NOTE(pag): This is a huge hack. We can't let this `frag` pointer leak.
  FragmentImpl::Ptr frag(fragment->ep, fragment);
  Macro m(std::move(*macro_reader), std::move(frag), mo);
  return m.id().Pack();
}

// Return an entity id associated with the Nth token.
EntityId ReadMacroTokensFromFragment::NthRelatedEntityId(
    EntityOffset ti) const {
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  return fragment->Fragment().getRelatedEntityId()[ti];
}

// Return the id of the Nth token.
EntityId ReadMacroTokensFromFragment::NthTokenId(EntityOffset ti) const {
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  MacroTokenId id;
  id.fragment_id = fragment->fragment_id;
  id.offset = ti;
  id.kind = static_cast<TokenKind>(fragment->Fragment().getTokenKinds()[ti]);
  return id;
}

EntityId ReadMacroTokensFromFragment::NthFileTokenId(EntityOffset ti) const {
  const auto &reader = fragment->Fragment();
  auto dt = reader.getDerivedTokenIds();
  while (ti < fragment->num_tokens) {
    mx::EntityId eid(dt[ti]);
    mx::VariantId vid = eid.Unpack();
    if (std::holds_alternative<mx::FileTokenId>(vid)) {
      return eid;

    } else if (std::holds_alternative<mx::ParsedTokenId>(vid)) {

      // NOTE(pag): a macro token should only ever be derived from another macro
      //            token, or a file token.
      assert(false);

      mx::ParsedTokenId tid = std::get<mx::ParsedTokenId>(vid);
      FragmentId fid(tid.fragment_id);
      if (tid.fragment_id == fragment->fragment_id) {
        if (tid.offset < fragment->num_parsed_tokens) {
          // Follow to the next one.
          ti = reader.getParsedTokenOffsetToIndex()[tid.offset];
        } else {
          assert(false);
          return kInvalidEntityId;
        }

      } else if (FragmentImpl::Ptr frag = fragment->ep->FragmentFor(
          fragment->ep, fid)) {
        assert(false);
        return frag->ParsedTokenReader(frag)->NthFileTokenId(tid.offset);
      } else {
        assert(false);
        return kInvalidEntityId;
      }

    } else if (std::holds_alternative<mx::MacroTokenId>(vid)) {
      mx::MacroTokenId tid = std::get<mx::MacroTokenId>(vid);
      FragmentId fid(tid.fragment_id);
      if (tid.fragment_id == fragment->fragment_id) {
        ti = tid.offset;  // Follow to the next one.

      } else if (FragmentImpl::Ptr frag =
          fragment->ep->FragmentFor(fragment->ep, fid)) {
        assert(false);
        return frag->MacroTokenReader(frag)->NthFileTokenId(tid.offset);
      } else {
        assert(false);
        return kInvalidEntityId;
      }

    } else {
      assert(std::holds_alternative<mx::InvalidId>(vid));
      return kInvalidEntityId;
    }
  }

  assert(false);
  return kInvalidEntityId;
}

// Return the token reader for another file.
TokenReader::Ptr ReadMacroTokensFromFragment::ReaderForToken(
    const TokenReader::Ptr &self, RawEntityId eid) const {
  return TokenReader::ReaderForToken(self, fragment->ep, eid);
}

// Returns `true` if `this` is logically equivalent to `that`.
bool ReadMacroTokensFromFragment::Equals(const class TokenReader *that_) const {
  if (!dynamic_cast<const ReadMacroTokensFromFragment *>(that_)) {
    return false;
  } else if (this == that_) {
    return true;
  } else if (dynamic_cast<const ReadParsedTokensFromFragment *>(that_)) {
    return false;
  }

  auto that = that_->OwningFragment();
  if (fragment == that) {
    return true;
  }

  if (!that || that->fragment_id != fragment->fragment_id ||
      that->ep.get() != fragment->ep.get()) {
    return false;
  }

  return true;
}

const FragmentImpl *
ReadMacroTokensFromFragment::OwningFragment(void) const noexcept {
  return fragment;
}

// Return the number of tokens in the fragment.
EntityOffset ReadParsedTokensFromFragment::NumTokens(void) const {
  return fragment->num_parsed_tokens;
}

// Return the kind of the Nth token.
TokenKind ReadParsedTokensFromFragment::NthTokenKind(EntityOffset to) const {
  if (to >= fragment->num_parsed_tokens) {
    assert(false);
    return TokenKind::UNKNOWN;
  }

  auto &reader = fragment->Fragment();
  auto ti = reader.getParsedTokenOffsetToIndex()[to];
  if (ti >= fragment->num_tokens) {
    assert(false);
    return TokenKind::UNKNOWN;
  }

  return static_cast<TokenKind>(reader.getTokenKinds()[ti]);
}

// Return the data of the Nth token.
std::string_view ReadParsedTokensFromFragment::NthTokenData(
    EntityOffset to) const {
  if (to >= fragment->num_parsed_tokens) {
    assert(false);
    return {};
  }

  auto ti = fragment->Fragment().getParsedTokenOffsetToIndex()[to];
  if (ti >= fragment->num_tokens) {
    assert(false);
    return {};
  }

  return this->ReadMacroTokensFromFragment::NthTokenData(ti);
}

// Return the id of the token from which the Nth token is derived. This is
// basically a self-reference, insofar as all parsed tokens map to a macro
// token. It's the macro tokens who actually have some kind of link to a
// derived token.
EntityId ReadParsedTokensFromFragment::NthDerivedTokenId(
    EntityOffset to) const {
  if (to >= fragment->num_parsed_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  auto &reader = fragment->Fragment();
  auto ti = reader.getParsedTokenOffsetToIndex()[to];
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  MacroTokenId id;
  id.fragment_id = fragment->fragment_id;
  id.offset = ti;
  id.kind = static_cast<TokenKind>(reader.getTokenKinds()[ti]);
  return id;
}

// Return the id of the parsed token which is derived from the Nth token.
EntityId ReadParsedTokensFromFragment::NthParsedTokenId(EntityOffset to) const {
  if (to >= fragment->num_parsed_tokens) {
    return kInvalidEntityId;
  }

  auto &reader = fragment->Fragment();
  auto ti = reader.getParsedTokenOffsetToIndex()[to];
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  ParsedTokenId id;
  id.fragment_id = fragment->fragment_id;
  id.offset = to;
  id.kind = static_cast<TokenKind>(reader.getTokenKinds()[ti]);
  return id;
}

// Return the id of the macro containing the Nth token.
EntityId ReadParsedTokensFromFragment::NthContainingMacroId(
    EntityOffset to) const {
  if (to >= fragment->num_parsed_tokens) {
    return kInvalidEntityId;
  }

  auto &reader = fragment->Fragment();
  auto ti = reader.getParsedTokenOffsetToIndex()[to];
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  auto mti2o = reader.getMacroTokenIndexToMacroOffset();
  auto mo = mti2o[ti];

  // NOTE(pag): Not an asserting condition; the serialization code stores
  //            `num_parsed_tokens` for "no relation" and stores
  //            `num_parsed_tokens + 1` for a one-to-many relation.
  auto macro_reader = fragment->NthMacro(mo);
  if (!macro_reader.has_value()) {
    return kInvalidEntityId;
  }

  // NOTE(pag): This is a huge hack. We can't let this `frag` pointer leak.
  FragmentImpl::Ptr frag(fragment->ep, fragment);
  Macro m(std::move(*macro_reader), std::move(frag), mo);
  return m.id().Pack();
}

// Return an entity id associated with the Nth token.
EntityId ReadParsedTokensFromFragment::NthRelatedEntityId(
    EntityOffset to) const {
  if (to >= fragment->num_parsed_tokens) {
    return kInvalidEntityId;
  }

  auto &reader = fragment->Fragment();
  auto ti = reader.getParsedTokenOffsetToIndex()[to];
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  return reader.getRelatedEntityId()[ti];
}

// Return the id of the Nth token.
EntityId ReadParsedTokensFromFragment::NthTokenId(EntityOffset to) const {
  if (to >= fragment->num_parsed_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  auto &reader = fragment->Fragment();
  auto ti = reader.getParsedTokenOffsetToIndex()[to];
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }

  ParsedTokenId id;
  id.fragment_id = fragment->fragment_id;
  id.offset = to;
  id.kind = static_cast<TokenKind>(reader.getTokenKinds()[ti]);
  return id;
}

EntityId ReadParsedTokensFromFragment::NthFileTokenId(EntityOffset to) const {
  if (to >= fragment->num_parsed_tokens) {
    assert(false);
    return {};
  }

  auto ti = fragment->Fragment().getParsedTokenOffsetToIndex()[to];
  return this->ReadMacroTokensFromFragment::NthFileTokenId(ti);
}

// Returns `true` if `this` is logically equivalent to `that`.
bool ReadParsedTokensFromFragment::Equals(const class TokenReader *that_) const {
  if (!dynamic_cast<const ReadParsedTokensFromFragment *>(that_)) {
    return false;
  } else if (this == that_) {
    return true;
  }

  auto that = that_->OwningFragment();
  if (fragment == that) {
    return true;
  }

  if (!that || that->fragment_id != fragment->fragment_id ||
      that->ep.get() != fragment->ep.get()) {
    return false;
  }

  return true;
}

// Return a specific type of entity.
std::optional<ReaderPtr> FragmentImpl::NthDecl(EntityOffset offset) const {
  return ep->DeclFor(ep, FragmentId(fragment_id), offset);
}

std::optional<ReaderPtr> FragmentImpl::NthStmt(EntityOffset offset) const {
  return ep->StmtFor(ep, FragmentId(fragment_id), offset);
}

std::optional<ReaderPtr> FragmentImpl::NthType(EntityOffset offset) const {
  return ep->TypeFor(ep, FragmentId(fragment_id), offset);
}

std::optional<ReaderPtr> FragmentImpl::NthAttr(EntityOffset offset) const {
  return ep->AttrFor(ep, FragmentId(fragment_id), offset);
}

std::optional<ReaderPtr> FragmentImpl::NthMacro(EntityOffset offset) const {
  return ep->MacroFor(ep, FragmentId(fragment_id), offset);
}

std::optional<ReaderPtr> FragmentImpl::NthPseudo(EntityOffset offset) const {
  return ep->PseudoFor(ep, FragmentId(fragment_id), offset);
}

gap::generator<ReaderPtr> FragmentImpl::Decls() const {
  return ep->DeclsFor(ep, FragmentId(fragment_id));
}

gap::generator<ReaderPtr> FragmentImpl::Stmts() const {
  return ep->StmtsFor(ep, FragmentId(fragment_id));
}

gap::generator<ReaderPtr> FragmentImpl::Types() const {
  return ep->TypesFor(ep, FragmentId(fragment_id));
}

gap::generator<ReaderPtr> FragmentImpl::Attrs() const {
  return ep->AttrsFor(ep, FragmentId(fragment_id));
}

gap::generator<ReaderPtr> FragmentImpl::Macros() const {
  return ep->MacrosFor(ep, FragmentId(fragment_id));
}

gap::generator<ReaderPtr> FragmentImpl::Pseudos() const {
  return ep->PseudosFor(ep, FragmentId(fragment_id));
}

std::string_view FragmentImpl::SourceIR(void) const {
  if (reader.hasMlir()) {
    return std::string_view(reader.getMlir().cStr(), reader.getMlir().size());
  } else {
    return {};
  }
}

std::string_view FragmentImpl::Data(void) const {
  if (reader.hasTokenData()) {
    return std::string_view(reader.getTokenData().cStr(),
                            reader.getTokenData().size());
  } else {
    return {};
  }
}

// Return the token associated with a specific entity ID.
std::optional<Token> FragmentImpl::TokenFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  (void) can_fail;

  VariantId vid = eid.Unpack();

  // It's a fragment token.
  if (std::holds_alternative<ParsedTokenId>(vid)) {
    const ParsedTokenId tid = std::get<ParsedTokenId>(vid);
    FragmentId fid(tid.fragment_id);
    // It's a token inside of the current fragment.
    if (tid.fragment_id == fragment_id) {
      if (tid.offset < num_parsed_tokens) {
        Token tok(this->ParsedTokenReader(self), tid.offset);
        if (tok.id() == eid) {
          return tok;
        } else {
          assert(false);
        }
      }

    // It's a token inside of another fragment, go get the other fragment.
    } else if (auto other_frag = ep->FragmentFor(ep, fid)) {
      return other_frag->TokenFor(other_frag, eid, can_fail);
    }

  // It's a macro token.
  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    const MacroTokenId tid = std::get<MacroTokenId>(vid);
    FragmentId fid(tid.fragment_id);

    // It's a token inside of the current fragment.
    if (tid.fragment_id == fragment_id) {
      if (tid.offset < num_tokens) {
        Token tok(this->MacroTokenReader(self), tid.offset);
        if (tok.id() == eid) {
          return tok;
        } else {
          assert(false);
        }
      }

    // It's a token inside of another fragment, go get the other fragment.
    } else if (auto other_frag = ep->FragmentFor(ep, fid)) {
      return other_frag->TokenFor(other_frag, eid, can_fail);
    }

  // It's a file token; go get the file.
  } else if (std::holds_alternative<FileTokenId>(vid)) {
    const FileTokenId tid = std::get<FileTokenId>(vid);
    FileId fid(tid.file_id);
    if (FileImpl::Ptr file = ep->FileFor(ep, SpecificEntityId<FileId>(fid));
        file && tid.offset < file->num_tokens) {
      Token tok(file->TokenReader(file), tid.offset);
      if (tok.id() == eid) {
        return tok;
      } else {
        assert(false);
      }
    }
  }

  if (can_fail) {
    return Token();
  }

  assert(false);
  return std::nullopt;
}

// Return the inclusive token range associated with two entity IDs.
TokenRange FragmentImpl::TokenRangeFor(
    const FragmentImpl::Ptr &self, EntityId begin_id, EntityId end_id) const {
  VariantId bvid = begin_id.Unpack();
  VariantId evid = end_id.Unpack();

  // It's a parsed fragment token.
  if (std::holds_alternative<ParsedTokenId>(bvid)) {
    if (!std::holds_alternative<ParsedTokenId>(evid)) {
      return TokenRange();
    }

    auto bfid = std::get<ParsedTokenId>(bvid);
    auto efid = std::get<ParsedTokenId>(evid);
    if (bfid.fragment_id != efid.fragment_id || bfid.offset > efid.offset) {
      return TokenRange();
    }

    FragmentId fid(bfid.fragment_id);

    // It's a token inside of the current fragment.
    if (bfid.fragment_id == fragment_id) {
      if (efid.offset < num_parsed_tokens) {
        return TokenRange(this->ParsedTokenReader(self),
                          bfid.offset, efid.offset + 1u);
      }

    // It's a token inside of another fragment, go get the other fragment.
    } else if (auto other_frag = ep->FragmentFor(ep, fid)) {
      return other_frag->TokenRangeFor(self, begin_id, end_id);

    } else {
      return TokenRange();
    }

  // It's a macro token.
  } else if (std::holds_alternative<MacroTokenId>(bvid)) {
    if (!std::holds_alternative<MacroTokenId>(evid)) {
      return TokenRange();
    }

    auto bfid = std::get<MacroTokenId>(bvid);
    auto efid = std::get<MacroTokenId>(evid);
    if (bfid.fragment_id != efid.fragment_id || bfid.offset > efid.offset) {
      return TokenRange();
    }

    FragmentId fid(bfid.fragment_id);

    // It's a token inside of the current fragment.
    if (bfid.fragment_id == fragment_id) {
      if (efid.offset < num_tokens) {
        return TokenRange(this->MacroTokenReader(self),
                          bfid.offset, efid.offset + 1u);
      }

    // It's a token inside of another fragment, go get the other fragment.
    } else if (auto other_frag = ep->FragmentFor(ep, fid)) {
      return other_frag->TokenRangeFor(self, begin_id, end_id);

    } else {
      return TokenRange();
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

    FileId fid(bfid.file_id);
    if (auto file = ep->FileFor(ep, SpecificEntityId<FileId>(fid));
        file && efid.offset < file->num_tokens) {
      return TokenRange(file->TokenReader(file), bfid.offset, efid.offset + 1u);
    }
  }

  return TokenRange();
}

// Return the declaration associated with a specific entity ID.
std::optional<Decl> FragmentImpl::DeclFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  (void) can_fail;

  VariantId vid = eid.Unpack();

  if (!std::holds_alternative<DeclarationId>(vid)) {
    assert(can_fail);
    return std::nullopt;
  }

  DeclarationId decl_id = std::get<DeclarationId>(vid);

  if (decl_id.fragment_id == fragment_id) {
    auto decl_reader = ep->DeclFor(ep, FragmentId(fragment_id), decl_id.offset);
    if (decl_reader.has_value()) {
      Decl decl(std::move(*decl_reader), self, decl_id.offset);
      if (decl.id() == eid) {
        return decl;
      } else {
        assert(false);
      }
    }

  // It's a decl inside of another fragment, go get the other fragment.
  } else if (auto frag = ep->FragmentFor(ep, FragmentId(decl_id.fragment_id))) {
    auto decl_reader = ep->DeclFor(ep, FragmentId(decl_id.fragment_id),
                                   decl_id.offset);
    if (decl_reader.has_value()) {
      Decl decl(std::move(*decl_reader), std::move(frag), decl_id.offset);
      if (decl.id() == eid) {
        return decl;
      } else {
        assert(false);
      }
    }
  }

  assert(can_fail);
  return std::nullopt;
}

// Return the statement associated with a specific entity ID.
std::optional<Stmt> FragmentImpl::StmtFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  (void) can_fail;

  VariantId vid = eid.Unpack();

  if (!std::holds_alternative<StatementId>(vid)) {
    assert(can_fail);
    return std::nullopt;
  }

  StatementId stmt_id = std::get<StatementId>(vid);
  FragmentId fid(stmt_id.fragment_id);

  // It's a statement inside of the current fragment.
  if (stmt_id.fragment_id == fragment_id) {
    auto stmt_reader = ep->StmtFor(ep, FragmentId(fragment_id), stmt_id.offset);
    if (stmt_reader.has_value()) {
      Stmt stmt(std::move(*stmt_reader), self, stmt_id.offset);
      if (stmt.id() == eid) {
        return stmt;
      } else {
        assert(false);
      }
    }
  // It's a statement inside of another fragment, go get the other fragment.
  } else if (auto frag = ep->FragmentFor(ep, fid)) {
    auto stmt_reader = ep->DeclFor(ep, FragmentId(stmt_id.fragment_id),
                                   stmt_id.offset);
    if (stmt_reader.has_value()) {
      Stmt stmt(std::move(*stmt_reader), self, stmt_id.offset);
      if (stmt.id() == eid) {
        return stmt;
      } else {
        assert(false);
      }
    }
  }

  assert(can_fail);
  return std::nullopt;
}

// Return the type associated with a specific entity ID.
std::optional<Type> FragmentImpl::TypeFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  (void) can_fail;

  VariantId vid = eid.Unpack();

  if (!std::holds_alternative<TypeId>(vid)) {
    assert(can_fail);
    return std::nullopt;
  }

  TypeId type_id = std::get<TypeId>(vid);
  FragmentId fid(type_id.fragment_id);

  // It's a type inside of the current fragment.
  if (type_id.fragment_id == fragment_id) {
    auto type_reader = ep->TypeFor(ep, FragmentId(fragment_id), type_id.offset);
    if (type_reader.has_value()) {
      Type type(std::move(*type_reader), self, type_id.offset);
      if (type.id() == eid) {
        return type;
      } else {
        assert(false);
      }
    }

  // It's a type inside of another fragment, go get the other fragment.
  } else if (auto frag = ep->FragmentFor(ep, fid)) {
    auto type_reader = ep->TypeFor(ep, FragmentId(type_id.fragment_id),
                                   type_id.offset);
    if (type_reader.has_value()) {
      Type type(std::move(*type_reader), self, type_id.offset);
      if (type.id() == eid) {
        return type;
      } else {
        assert(false);
      }
    }
  }

  assert(can_fail);
  return std::nullopt;
}

// Return the attribute associated with a specific entity ID.
std::optional<Macro> FragmentImpl::MacroFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  (void) can_fail;

  VariantId vid = eid.Unpack();

  if (!std::holds_alternative<MacroId>(vid)) {
    assert(can_fail);
    return std::nullopt;
  }

  MacroId macro_id = std::get<MacroId>(vid);
  FragmentId fid(macro_id.fragment_id);

  // It's a type inside of the current fragment.
  if (macro_id.fragment_id == fragment_id) {
    auto macro_reader = ep->MacroFor(ep, FragmentId(fragment_id),
                                     macro_id.offset);
    if (macro_reader.has_value()) {
      Macro macro(std::move(*macro_reader), self, macro_id.offset);
      if (macro.id() == eid) {
        return macro;
      } else {
        assert(false);
      }
    }

  // It's a type inside of another fragment, go get the other fragment.
  } else if (auto frag = ep->FragmentFor(ep, fid)) {
    auto macro_reader = ep->MacroFor(ep, FragmentId(macro_id.fragment_id),
                                     macro_id.offset);
    if (macro_reader.has_value()) {
      Macro macro(std::move(*macro_reader), self, macro_id.offset);
      if (macro.id() == eid) {
        return macro;
      } else {
        assert(false);
      }
    }
  }

  assert(can_fail);
  return std::nullopt;
}

// Return the type associated with a specific entity ID.
std::optional<Attr> FragmentImpl::AttrFor(
    const FragmentImpl::Ptr &self, EntityId eid, bool can_fail) const {
  (void) can_fail;

  VariantId vid = eid.Unpack();

  if (!std::holds_alternative<AttributeId>(vid)) {
    assert(can_fail);
    return std::nullopt;
  }

  AttributeId attr_id = std::get<AttributeId>(vid);
  FragmentId fid(attr_id.fragment_id);

  // It's an attribute inside of the current fragment.
  if (attr_id.fragment_id == fragment_id) {
    auto attr_reader = ep->AttrFor(ep, FragmentId(fragment_id), attr_id.offset);
    if (attr_reader.has_value()) {
      Attr attr(std::move(*attr_reader), self, attr_id.offset);
      if (attr.id() == eid) {
        return attr;
      } else {
        assert(false);
      }
    }

  // It's an attribute inside of another fragment, go get the other fragment.
  } else {
    auto frag = ep->FragmentFor(ep, fid);
    auto attr_reader = ep->TypeFor(ep, FragmentId(attr_id.fragment_id),
                                   attr_id.offset);
    if (attr_reader.has_value()) {
      Attr attr(std::move(*attr_reader), self, attr_id.offset);
      if (attr.id() == eid) {
        return attr;
      } else {
        assert(false);
      }
    }
  }

  assert(can_fail);
  return std::nullopt;
}

}  // namespace mx
