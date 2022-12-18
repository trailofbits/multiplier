// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

#include "File.h"
#include <multiplier/Entities/TokenKind.h>

namespace mx {

PackedFragmentImpl::~PackedFragmentImpl(void) noexcept {}

PackedFragmentImpl::PackedFragmentImpl(RawEntityId id_,
                                       EntityProvider::Ptr ep_,
                                       const capnp::Data::Reader &reader_)
    : FragmentImpl(id_, std::move(ep_)),
      package(reader_),
      reader(package.Reader<rpc::Fragment>()),
      parsed_token_reader(this),
      macro_token_reader(this) {

  // For bounds checking.
  num_decls = reader.getDeclarations().size();
  num_stmts = reader.getStatements().size();
  num_types = reader.getTypes().size();
  num_attrs = reader.getAttributes().size();
  num_macros = reader.getMacros().size();
  num_pseudos = reader.getOthers().size();
  num_parsed_tokens = reader.getParsedTokenContextOffsets().size();
  num_tokens = reader.getTokenKinds().size();

  assert(num_parsed_tokens <= num_tokens);
  assert(num_tokens == reader.getDerivedTokenIds().size());
  assert((num_tokens + 1u) == reader.getTokenOffsets().size());
  assert(num_parsed_tokens == reader.getParsedTokenOffsetToIndex().size());
  assert(num_tokens == reader.getMacroTokenIndexToParsedTokenOffset().size());
}

// Return the ID of the file containing the first token.
//
// NOTE(pag): This returns the raw, unpacked file id.
RawEntityId PackedFragmentImpl::FileContaingFirstToken(void) const {
  EntityId id(reader.getFirstFileTokenId());
  if (VariantId unpacked_id = id.Unpack();
      std::holds_alternative<FileTokenId>(unpacked_id)) {
    return std::get<FileTokenId>(unpacked_id).file_id;
  } else {
    return kInvalidEntityId;
  }
}

// Return a reader for the parsed tokens in the fragment. This doesn't
// include all tokens, i.e. macro use tokens, comments, etc.
TokenReader::Ptr PackedFragmentImpl::ParsedTokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReader::Ptr(self, &parsed_token_reader);
}

// Return a reader for the macro tokens in the fragment.
TokenReader::Ptr PackedFragmentImpl::MacroTokenReader(
    const FragmentImpl::Ptr &self) const {
  return TokenReader::Ptr(self, &macro_token_reader);
}

// Return the number of tokens in the fragment.
unsigned ReadMacroTokensFromFragment::NumTokens(void) const {
  return fragment->num_tokens;
}

// Return the kind of the Nth token.
TokenKind ReadMacroTokensFromFragment::NthTokenKind(unsigned ti) const {
  if (ti >= fragment->num_tokens) {
    assert(false);
    return TokenKind::UNKNOWN;
  }
  return static_cast<TokenKind>(fragment->Fragment().getTokenKinds()[ti]);
}

// Return the data of the Nth token.
std::string_view ReadMacroTokensFromFragment::NthTokenData(unsigned ti) const {
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
EntityId ReadMacroTokensFromFragment::NthDerivedTokenId(unsigned ti) const {
  if (ti >= fragment->num_tokens) {
    assert(false);
    return kInvalidEntityId;
  }
  return fragment->Fragment().getDerivedTokenIds()[ti];
}

// Return the id of the parsed token which is derived from the Nth token.
EntityId ReadMacroTokensFromFragment::NthParsedTokenId(unsigned ti) const {
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
EntityId ReadMacroTokensFromFragment::NthContainingMacroId(unsigned ti) const {
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
  if (mo >= fragment->num_macros) {
    return kInvalidEntityId;
  }

  // NOTE(pag): This is a huge hack. We can't let this `frag` pointer leak.
  FragmentImpl::Ptr frag(fragment->ep, fragment);
  Macro m(std::move(frag), mo);
  return m.id().Pack();
}

// Return the id of the Nth token.
EntityId ReadMacroTokensFromFragment::NthTokenId(unsigned ti) const {
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

EntityId ReadMacroTokensFromFragment::NthFileTokenId(unsigned ti) const {
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

      mx::ParsedTokenId fid = std::get<mx::ParsedTokenId>(vid);
      if (fid.fragment_id == fragment->fragment_id) {
        if (fid.offset < fragment->num_parsed_tokens) {
          // Follow to the next one.
          ti = reader.getParsedTokenOffsetToIndex()[fid.offset];
        } else {
          assert(false);
          return kInvalidEntityId;
        }

      } else if (FragmentImpl::Ptr frag = fragment->ep->FragmentFor(
          fragment->ep, fid.fragment_id)) {
        assert(false);
        return frag->ParsedTokenReader(frag)->NthFileTokenId(fid.offset);
      } else {
        assert(false);
        return kInvalidEntityId;
      }

    } else if (std::holds_alternative<mx::MacroTokenId>(vid)) {
      mx::MacroTokenId fid = std::get<mx::MacroTokenId>(vid);
      if (fid.fragment_id == fragment->fragment_id) {
        ti = fid.offset;  // Follow to the next one.

      } else if (FragmentImpl::Ptr frag =
          fragment->ep->FragmentFor(fragment->ep, fid.fragment_id)) {
        assert(false);
        return frag->MacroTokenReader(frag)->NthFileTokenId(fid.offset);
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
  }

  auto that = that_->OwningFragment();
  if (!that || that->fragment_id != fragment->fragment_id ||
      that->ep.get() != fragment->ep.get()) {
    return false;
  }

  return !dynamic_cast<const ReadParsedTokensFromFragment *>(that_);
}

const FragmentImpl *
ReadMacroTokensFromFragment::OwningFragment(void) const noexcept {
  return fragment;
}

// Return the number of tokens in the fragment.
unsigned ReadParsedTokensFromFragment::NumTokens(void) const {
  return fragment->num_parsed_tokens;
}

// Return the kind of the Nth token.
TokenKind ReadParsedTokensFromFragment::NthTokenKind(unsigned to) const {
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
std::string_view ReadParsedTokensFromFragment::NthTokenData(unsigned to) const {
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
EntityId ReadParsedTokensFromFragment::NthDerivedTokenId(unsigned to) const {
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
EntityId ReadParsedTokensFromFragment::NthParsedTokenId(unsigned to) const {
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
EntityId ReadParsedTokensFromFragment::NthContainingMacroId(unsigned to) const {
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
  if (mo >= fragment->num_macros) {
    return kInvalidEntityId;
  }

  // NOTE(pag): This is a huge hack. We can't let this `frag` pointer leak.
  FragmentImpl::Ptr frag(fragment->ep, fragment);
  Macro m(std::move(frag), mo);
  return m.id().Pack();
}

// Return the id of the Nth token.
EntityId ReadParsedTokensFromFragment::NthTokenId(unsigned to) const {
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

EntityId ReadParsedTokensFromFragment::NthFileTokenId(unsigned to) const {
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
  if (!that || that->fragment_id != fragment->fragment_id ||
      that->ep.get() != fragment->ep.get()) {
    return false;
  }

  return true;
}

// Return a reader for the whole fragment.
const FragmentReader &PackedFragmentImpl::Fragment(void) const {
  return reader;
}

// Return a specific type of entity.
DeclReader PackedFragmentImpl::NthDecl(unsigned offset) const {
  return reader.getDeclarations()[offset];
}

StmtReader PackedFragmentImpl::NthStmt(unsigned offset) const {
  return reader.getStatements()[offset];
}

TypeReader PackedFragmentImpl::NthType(unsigned offset) const {
  return reader.getTypes()[offset];
}

AttrReader PackedFragmentImpl::NthAttr(unsigned offset) const {
  return reader.getAttributes()[offset];
}

MacroReader PackedFragmentImpl::NthMacro(unsigned offset) const {
  return reader.getMacros()[offset];
}

PseudoReader PackedFragmentImpl::NthPseudo(unsigned offset) const {
  return reader.getOthers()[offset];
}

std::string_view PackedFragmentImpl::SourceIR(void) const {
  if (reader.hasMlir()) {
    return std::string_view(reader.getMlir().cStr(), reader.getMlir().size());
  } else {
    return {};
  }
}

std::string_view PackedFragmentImpl::Data(void) const {
  if (reader.hasTokenData()) {
    return std::string_view(reader.getTokenData().cStr(),
                            reader.getTokenData().size());
  } else {
    return {};
  }
}

}  // namespace mx
