// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Macro.h>

#include <cassert>

#include "Token.h"
#include "File.h"
#include "Fragment.h"

namespace mx {

gap::generator<MacroSubstitutionEntry> MacroSubstitution::before(void) const {
  auto nodes = impl->Fragment().getSubstitutions()[offset].getBeforeIds();
  for(auto node : nodes) {
    VariantId id = EntityId(node).Unpack();

    if (std::holds_alternative<ParsedTokenId>(id)) {
      auto tok = std::get<ParsedTokenId>(id);
      co_yield Token(impl->TokenReader(impl), tok.offset);

    } else if (std::holds_alternative<MacroTokenId>(id)) {
      auto tok = std::get<MacroTokenId>(id);
      co_yield Token(impl->TokenReader(impl), tok.offset);

    } else if (std::holds_alternative<FileTokenId>(id)) {
      auto tok = std::get<FileTokenId>(id);
      auto file = File::containing(impl);
      co_yield Token(file.impl->TokenReader(file.impl), tok.offset);

    } else if (std::holds_alternative<MacroSubstitutionId>(id)) {
      auto sub = std::get<MacroSubstitutionId>(id);
      assert(sub.fragment_id == impl->fragment_id);
      co_yield MacroSubstitution(impl, sub.offset, sub.kind);

    } else {
      assert(false);
      __builtin_unreachable();
    }
  }
}

bool MacroSubstitution::has_after(void) const {
  switch (kind_) {
    case MacroSubstitutionKind::OTHER_DIRECTIVE:
    case MacroSubstitutionKind::DEFINE_DIRECTIVE:
    case MacroSubstitutionKind::UNDEF_DIRECTIVE:
    case MacroSubstitutionKind::PRAGMA_DIRECTIVE:
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
      return false;
    default:
      break;
  }

  auto nodes = impl->Fragment().getSubstitutions()[offset].getAfterIds();
  if (!nodes.size()) {
    return false;
  }

  return true;
}

gap::generator<MacroSubstitutionEntry> MacroSubstitution::after(void) const {
  if(!has_after()) {
    co_return;
  }

  auto nodes = impl->Fragment().getSubstitutions()[offset].getAfterIds();

  for(auto node : nodes) {
    VariantId id = EntityId(node).Unpack();

    if (std::holds_alternative<ParsedTokenId>(id)) {
      auto tok = std::get<ParsedTokenId>(id);
      co_yield Token(impl->TokenReader(impl), tok.offset);

    } else if (std::holds_alternative<MacroTokenId>(id)) {
      auto tok = std::get<MacroTokenId>(id);
      co_yield Token(impl->TokenReader(impl), tok.offset);

    } else if (std::holds_alternative<FileTokenId>(id)) {
      auto tok = std::get<FileTokenId>(id);
      auto file = File::containing(impl);
      co_yield Token(file.impl->TokenReader(file.impl), tok.offset);

    } else if (std::holds_alternative<MacroSubstitutionId>(id)) {
      auto sub = std::get<MacroSubstitutionId>(id);
      assert(sub.fragment_id == impl->fragment_id);
      co_yield MacroSubstitution(impl, sub.offset, sub.kind);

    } else {
      assert(false);
      __builtin_unreachable();
    }
  }
}

}  // namespace mx
