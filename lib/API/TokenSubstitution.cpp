// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Token.h"
#include "File.h"
#include "Fragment.h"

#include <cassert>

namespace mx {

std::variant<Token, TokenSubstitution>
TokenSubstitutionListIterator::operator*(void) const {
  VariantId id = EntityId(impl->nodes[index]).Unpack();

  if (std::holds_alternative<FragmentTokenId>(id)) {
    auto tok = std::get<FragmentTokenId>(id);
    return Token(impl->fragment->TokenReader(impl->fragment), tok.offset);

  } else if (std::holds_alternative<FileTokenId>(id)) {
    auto tok = std::get<FileTokenId>(id);
    auto file = File::containing(impl->fragment);
    return Token(file.impl->TokenReader(file.impl), tok.offset);

  } else if (std::holds_alternative<TokenSubstitutionId>(id)) {
    auto sub = std::get<TokenSubstitutionId>(id);
    assert(sub.fragment_id == impl->fragment->fragment_id);
    return TokenSubstitution(impl->fragment, sub.offset, sub.kind);

  } else {
    assert(false);
    __builtin_unreachable();
  }
}

TokenSubstitutionListImpl::TokenSubstitutionListImpl(
    std::shared_ptr<const FragmentImpl> fragment_)
    : fragment(std::move(fragment_)),
      nodes(fragment->Fragment().getUnparsedTokens()) {}

TokenSubstitutionListImpl::TokenSubstitutionListImpl(
    std::shared_ptr<const FragmentImpl> fragment_, unsigned offset, BeforeTag)
    : fragment(std::move(fragment_)),
      nodes(fragment->Fragment().getTokenSubstitutions()[offset].getBeforeTokens()) {}

TokenSubstitutionListImpl::TokenSubstitutionListImpl(
    std::shared_ptr<const FragmentImpl> fragment_, unsigned offset, AfterTag)
    : fragment(std::move(fragment_)),
      nodes(fragment->Fragment().getTokenSubstitutions()[offset].getAfterTokens()) {}

TokenSubstitutionList TokenSubstitution::before(void) const {
  auto ret = std::make_shared<const TokenSubstitutionListImpl>(
      impl, offset, BeforeTag{});
  auto num_nodes = ret->nodes.size();
  return TokenSubstitutionList(std::move(ret), num_nodes);
}

TokenSubstitutionList TokenSubstitution::after(void) const {
  auto ret = std::make_shared<const TokenSubstitutionListImpl>(
      impl, offset, AfterTag{});
  auto num_nodes = ret->nodes.size();
  return TokenSubstitutionList(std::move(ret), num_nodes);
}


}  // namespace mx
