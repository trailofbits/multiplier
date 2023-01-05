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

#include "File.h"
#include "Re2Impl.h"
#include "WeggliImpl.h"

namespace mx {

// Advance to the next valid fragment.
void FileFragmentListIterator::Advance(void) {
  for (; index < num_fragments; ++index) {
    frag = impl->ep->FragmentFor(impl->ep, impl->fragment_ids[index]);
    if (frag) {
      return;
    }
  }
}

// Return the list of fragments in a file.
FragmentList Fragment::in(const File &file) {
  return file.fragments();
}

// Return the fragment containing a query match.
Fragment Fragment::containing(const WeggliQueryMatch &match) {
  return Fragment(match.frag);
}

// Return the fragment containing a query match.
Fragment Fragment::containing(const RegexQueryMatch &match) {
  return Fragment(match.frag);
}

Fragment Fragment::containing(const Decl &entity) {
  return Fragment(entity.fragment);
}

Fragment Fragment::containing(const Stmt &entity) {
  return Fragment(entity.fragment);
}

Fragment Fragment::containing(const Type &entity) {
  return Fragment(entity.fragment);
}

Fragment Fragment::containing(const Attr &entity) {
  return Fragment(entity.fragment);
}

Fragment Fragment::containing(const Designator &entity) {
  return Fragment(entity.fragment);
}

std::optional<Fragment> Fragment::containing(const Token &entity) {
  if (auto frag = entity.impl->OwningFragment()) {
    std::shared_ptr<const FragmentImpl> ptr(entity.impl, frag);
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

Fragment Fragment::containing(const Macro &entity) {
  return Fragment(entity.fragment);
}

Fragment Fragment::containing(const UseBase &use) {
  return Fragment(use.fragment);
}

Fragment Fragment::containing(const StmtReference &ref) {
  return Fragment(ref.fragment);
}

// Return the ID of this fragment.
SpecificEntityId<FragmentId> Fragment::id(void) const noexcept {
  return FragmentId{impl->fragment_id};
}

// The range of file tokens in this fragment.
TokenRange Fragment::file_tokens(void) const {
  auto fr = impl->Fragment();
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
  auto file = impl->ep->FileFor(impl->ep, fid);
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
  EntityIdListReader decl_ids = impl->Fragment().getTopLevelDeclarations();
  decls.reserve(decl_ids.size());
  for (RawEntityId eid_ : decl_ids) {
    EntityId eid(eid_);
    VariantId vid = eid.Unpack();
    if (std::holds_alternative<DeclarationId>(vid)) {
      DeclarationId decl_id = std::get<DeclarationId>(vid);
      if (decl_id.fragment_id == impl->fragment_id) {
        decls.emplace_back(impl, decl_id.offset);
      } else {
        assert(false);
      }
    } else {
      assert(false);
    }
  }
  return decls;
}

// Return the list of top-level macros in this fragment.
// This will return a mix of `Macro` or `Token` values.
std::vector<MacroOrToken> Fragment::preprocessed_code(void) const {
  std::vector<std::variant<Macro, Token>> macros;
  EntityIdListReader macro_ids = impl->Fragment().getTopLevelMacros();
  macros.reserve(macro_ids.size());
  for (RawEntityId eid_ : macro_ids) {
    EntityId eid(eid_);
    VariantId vid = eid.Unpack();
    if (std::holds_alternative<MacroId>(vid)) {
      MacroId macro_id = std::get<MacroId>(vid);
      if (macro_id.fragment_id == impl->fragment_id) {
        macros.emplace_back(Macro(impl, macro_id.offset));
      } else {
        assert(false);
      }

    } else if (std::holds_alternative<MacroTokenId>(vid)) {
      MacroTokenId macro_id = std::get<MacroTokenId>(vid);
      if (macro_id.fragment_id == impl->fragment_id) {
        macros.emplace_back(Token(impl->MacroTokenReader(impl), macro_id.offset));
      } else {
        assert(false);
      }

    } else if (std::holds_alternative<ParsedTokenId>(vid)) {
      ParsedTokenId macro_id = std::get<ParsedTokenId>(vid);
      if (macro_id.fragment_id == impl->fragment_id) {
        macros.emplace_back(Token(impl->ParsedTokenReader(impl), macro_id.offset));
      } else {
        assert(false);
      }

    } else if (std::holds_alternative<FileTokenId>(vid)) {
      assert(false);

    } else {
      assert(false);
    }
  }
  return macros;
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
WeggliQueryResult Fragment::query(const WeggliQuery &query) const {
  return WeggliQueryResult(
      std::make_shared<WeggliQueryResultImpl>(query, impl));
}

// Run a regular expression search over this fragment.
RegexQueryResult Fragment::query(const RegexQuery &query) const {
  return RegexQueryResult(std::make_shared<RegexQueryResultImpl>(query, impl));
}

}  // namespace mx
