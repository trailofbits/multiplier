// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

#include <cassert>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Designator.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/Type.h>

#include "Attr.h"
#include "Pseudo.h"
#include "Decl.h"
#include "File.h"
#include "Macro.h"
#include "Re2Impl.h"
#include "Stmt.h"
#include "Type.h"
#include "WeggliImpl.h"

namespace mx {

// Return the fragment containing a query match.
Fragment Fragment::containing(const WeggliQueryMatch &match) {
  return Fragment(match.frag);
}

// Return the fragment containing a query match.
Fragment Fragment::containing(const RegexQueryMatch &match) {
  return Fragment(match.frag);
}

Fragment Fragment::containing(const Decl &entity) {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const Stmt &entity) {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const Type &entity) {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const Attr &entity) {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id.Pack()));
}

Fragment Fragment::containing(const TemplateArgument &entity) {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const TemplateParameterList &entity) {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const CXXBaseSpecifier &entity) {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const Designator &entity) {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const Macro &entity) {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

std::optional<Fragment> Fragment::containing(const Token &entity) {
  if (auto frag = entity.impl->OwningFragment()) {
    return Fragment(FragmentImplPtr(entity.impl, frag));
  } else {
    return std::nullopt;
  }
}

// Return the ID of this fragment.
SpecificEntityId<FragmentId> Fragment::id(void) const noexcept {
  return FragmentId(impl->fragment_id);
}

// The range of file tokens in this fragment.
TokenRange Fragment::file_tokens(void) const {
  const auto &fr = impl->reader;
  VariantId first_vid = EntityId(fr.getFirstFileTokenId()).Unpack();
  VariantId last_vid = EntityId(fr.getLastFileTokenId()).Unpack();
  if (!std::holds_alternative<FileTokenId>(first_vid) ||
      !std::holds_alternative<FileTokenId>(last_vid)) {
    return TokenRange();
  }

  FileTokenId first_fid = std::get<FileTokenId>(first_vid);
  FileTokenId last_fid = std::get<FileTokenId>(last_vid);
  if (first_fid.file_id != last_fid.file_id ||
      first_fid.offset > last_fid.offset) {
    return TokenRange();
  }

  FileId fid(first_fid.file_id);
  FileImplPtr file = impl->ep->FileFor(impl->ep, EntityId(fid).Pack());
  auto raw_file = file.get();
  return TokenRange(
      raw_file->TokenReader(std::move(file)),
      first_fid.offset, last_fid.offset + 1u);
}

// The range of parsed tokens in this fragment.
TokenRange Fragment::parsed_tokens(void) const {
  if (!impl->num_parsed_tokens) {
    return TokenRange();
  }

  return TokenRange(impl->ParsedTokenReader(impl), 0u, impl->num_parsed_tokens);
}

// Return the list of top-level declarations in this fragment.
std::vector<Decl> Fragment::top_level_declarations(void) const {
  std::vector<Decl> decls;
  EntityIdListReader decl_ids = impl->reader.getTopLevelDeclarations();
  decls.reserve(decl_ids.size());

  auto &ep = impl->ep;
  for (RawEntityId eid : decl_ids) {
    VariantId vid = EntityId(eid).Unpack();
    if (!std::holds_alternative<DeclId>(vid)) {
      assert(false);
      continue;
    }

    DeclId decl_id = std::get<DeclId>(vid);
    if (decl_id.fragment_id != impl->fragment_id) {
      assert(false);
      continue;
    }

    DeclImplPtr decl_ptr = ep->DeclFor(ep, eid);
    if (!decl_ptr) {
      assert(false);
      continue;
    }

    decls.emplace_back(std::move(decl_ptr));
  }
  return decls;
}

// Return the list of top-level macros in this fragment.
// This will return a mix of `Macro` or `Token` values.
gap::generator<MacroOrToken> Fragment::preprocessed_code(void) const {
  EntityIdListReader macro_ids = impl->reader.getTopLevelMacros();

  auto &ep = impl->ep;
  for (RawEntityId eid : macro_ids) {
    VariantId vid = EntityId(eid).Unpack();
    if (std::holds_alternative<MacroId>(vid)) {
      MacroId macro_id = std::get<MacroId>(vid);
      MacroImplPtr eptr = ep->MacroFor(ep, eid);
      if (macro_id.fragment_id == impl->fragment_id && eptr) {
        co_yield Macro(std::move(eptr));
      } else {
        assert(false);
      }

    } else if (std::holds_alternative<MacroTokenId>(vid)) {
      MacroTokenId macro_id = std::get<MacroTokenId>(vid);
      if (macro_id.fragment_id == impl->fragment_id &&
          macro_id.offset < impl->num_tokens) {
        co_yield Token(impl->MacroTokenReader(impl), macro_id.offset);
      } else {
        assert(false);
      }

    } else if (std::holds_alternative<ParsedTokenId>(vid)) {
      ParsedTokenId macro_id = std::get<ParsedTokenId>(vid);
      if (macro_id.fragment_id == impl->fragment_id &&
          macro_id.offset < impl->num_parsed_tokens) {
        co_yield Token(impl->ParsedTokenReader(impl), macro_id.offset);
      } else {
        assert(false);
      }

    } else if (std::holds_alternative<FileTokenId>(vid)) {
      assert(false);

    } else {
      assert(false);
    }
  }
}

// Returns source IR for the fragment.
std::optional<std::string_view> Fragment::source_ir(void) const noexcept {
  auto mlir = impl->SourceIR();
  if (!mlir.empty()) {
    return mlir;
  }
  return std::nullopt;
}

// Run a Weggli search over this fragment.
gap::generator<WeggliQueryMatch> Fragment::query(const WeggliQuery &query) const {
  WeggliQueryResultImpl res(query, impl);
  for (auto match : res.Enumerate()) {
    co_yield match;
  }
}

// Run a regular expression search over this fragment.
gap::generator<RegexQueryMatch> Fragment::query(const RegexQuery &query) const {
  RegexQueryResultImpl res(query, impl);
  for (auto match : res.Enumerate()) {
    co_yield match;
  }
}

}  // namespace mx
