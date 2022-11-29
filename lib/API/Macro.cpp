// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Macro.h"

#include <cassert>

#include "Token.h"
#include "File.h"
#include "Fragment.h"

namespace mx {

std::variant<Token, MacroSubstitution>
MacroSubstitutionListIterator::operator*(void) const {
  VariantId id = EntityId(impl->nodes[index]).Unpack();

  if (std::holds_alternative<ParsedTokenId>(id)) {
    auto tok = std::get<ParsedTokenId>(id);
    return Token(impl->fragment->TokenReader(impl->fragment), tok.offset);

  } else if (std::holds_alternative<MacroTokenId>(id)) {
    auto tok = std::get<MacroTokenId>(id);
    return Token(impl->fragment->TokenReader(impl->fragment), tok.offset);

  } else if (std::holds_alternative<FileTokenId>(id)) {
    auto tok = std::get<FileTokenId>(id);
    auto file = File::containing(impl->fragment);
    return Token(file.impl->TokenReader(file.impl), tok.offset);

  } else if (std::holds_alternative<MacroSubstitutionId>(id)) {
    auto sub = std::get<MacroSubstitutionId>(id);
    assert(sub.fragment_id == impl->fragment->fragment_id);
    return MacroSubstitution(impl->fragment, sub.offset, sub.kind);

  } else {
    assert(false);
    __builtin_unreachable();
  }
}

MacroSubstitutionListImpl::MacroSubstitutionListImpl(
    std::shared_ptr<const FragmentImpl> fragment_, unsigned offset, BeforeTag)
    : fragment(std::move(fragment_)),
      nodes(fragment->Fragment().getSubstitutions()[offset].getBeforeIds()) {}

MacroSubstitutionListImpl::MacroSubstitutionListImpl(
    std::shared_ptr<const FragmentImpl> fragment_, unsigned offset, AfterTag)
    : fragment(std::move(fragment_)),
      nodes(fragment->Fragment().getSubstitutions()[offset].getAfterIds()) {}

MacroSubstitutionList MacroSubstitution::before(void) const {
  auto ret = std::make_shared<const MacroSubstitutionListImpl>(
      impl, offset, BeforeTag{});
  auto num_nodes = ret->nodes.size();
  return MacroSubstitutionList(std::move(ret), num_nodes);
}

std::optional<MacroSubstitutionList> MacroSubstitution::after(void) const {
  switch (kind_) {
    case MacroSubstitutionKind::OTHER_DIRECTIVE:
    case MacroSubstitutionKind::DEFINE_DIRECTIVE:
    case MacroSubstitutionKind::UNDEF_DIRECTIVE:
    case MacroSubstitutionKind::PRAGMA_DIRECTIVE:
    case MacroSubstitutionKind::C99_PRAGMA_DIRECTIVE:
    case MacroSubstitutionKind::MICROSOFT_PRAGMA_DIRECTIVE:
    case MacroSubstitutionKind::IF_DIRECTIVE:
    case MacroSubstitutionKind::IFDEF_DIRECTIVE:
    case MacroSubstitutionKind::IFNDEF_DIRECTIVE:
    case MacroSubstitutionKind::ELIF_DIRECTIVE:
    case MacroSubstitutionKind::ELIFDEF_DIRECTIVE:
    case MacroSubstitutionKind::ELIFNDEF_DIRECTIVE:
    case MacroSubstitutionKind::ELSE_DIRECTIVE:
    case MacroSubstitutionKind::ENDIF_DIRECTIVE:
    case MacroSubstitutionKind::VA_OPT_ARGUMENT:
    case MacroSubstitutionKind::MACRO_ARGUMENT:
      return std::nullopt;
    default:
      break;
  }

  auto ret = std::make_shared<const MacroSubstitutionListImpl>(
      impl, offset, AfterTag{});
  auto num_nodes = ret->nodes.size();
  if (!num_nodes) {
    return std::nullopt;
  }

  return MacroSubstitutionList(std::move(ret), num_nodes);
}

}  // namespace mx
