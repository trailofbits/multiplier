// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

#include <iostream>
#include <cassert>
#include <multiplier/AST/Attr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Designator.h>
#include <multiplier/AST/Type.h>
#include <multiplier/Frontend/Compilation.h>
#include <multiplier/Frontend/Macro.h>
#include <multiplier/Frontend/Query.h>

#include "Attr.h"
#include "Pseudo.h"
#include "Decl.h"
#include "File.h"
#include "Macro.h"
#include "Reference.h"
#include "Re2Impl.h"
#include "Stmt.h"
#include "Type.h"

namespace mx {
namespace ir {
class SourceIRImpl;
}  // namespace ir

std::optional<Fragment> Fragment::containing(const Fragment &child) noexcept {
  auto parent_id = child.impl->parent_fragment_id;
  auto parent_fid = EntityId(parent_id).Extract<FragmentId>();
  if (!parent_fid) {
    return std::nullopt;
  }

  auto eptr = child.impl->ep->FragmentFor(child.impl->ep, parent_id);
  if (!eptr) {
    assert(false);
    return std::nullopt;
  }

  return Fragment(std::move(eptr));
}

// A fragment can be nested inside of another fragment. This is very common
// with C++ templates, but can also happen in C due to elaborated type uses,
// such as `struct foo`, acting as forward declarations upon their first use.
std::optional<Fragment> Fragment::parent(void) const noexcept {
  return Fragment::containing(*this);
}

std::optional<PackedFragmentId> Fragment::parent_id(void) const noexcept {
  auto parent_id = impl->parent_fragment_id;
  if (auto parent_fid = EntityId(parent_id).Extract<FragmentId>()) {
    return parent_fid.value();
  } else {
    return std::nullopt;
  }
}

// Return the fragment containing a query match.
Fragment Fragment::containing(const RegexQueryMatch &match) noexcept {
  return Fragment(
      dynamic_cast<const RegexQueryMatchImpl *>(match.impl.get())->frag);
}

Fragment Fragment::containing(const Decl &entity) noexcept {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const Stmt &entity) noexcept {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const Attr &entity) noexcept {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id.Pack()));
}

Fragment Fragment::containing(const TemplateArgument &entity) noexcept {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const TemplateParameterList &entity) noexcept {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const CXXBaseSpecifier &entity) noexcept {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const CXXCtorInitializer &entity) noexcept {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const Designator &entity) noexcept {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

Fragment Fragment::containing(const Macro &entity) noexcept {
  return Fragment(entity.impl->ep->FragmentFor(
      entity.impl->ep, entity.impl->fragment_id));
}

std::optional<Fragment> Fragment::containing(const Token &entity) noexcept {
  if (auto frag = entity.impl->NthOwningFragment(entity.offset)) {
    return Fragment(FragmentImplPtr(entity.impl, frag));
  } else {
    return std::nullopt;
  }
}

// Return the fragment containing an operation.
std::optional<Fragment> Fragment::containing(
    const ir::Operation &op) noexcept {
  if (auto decl = Decl::from(op)) {
    return Fragment::containing(decl.value());
  } else if (auto stmt = Stmt::from(op)) {
    return Fragment::containing(stmt.value());
  }

  return std::nullopt;
}

std::optional<Fragment> Fragment::containing(
    const VariantEntity &entity) noexcept {
#define GET_FRAGMENT(ns_path, type_name, lower_name, enum_name, category) \
    if (auto lower_name ## _ptr = std::get_if<ns_path type_name>(&entity)) { \
      return Fragment::containing(*lower_name ## _ptr); \
    }

  // TODO(pag): Pseudo entities have a fragment id.

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              GET_FRAGMENT,
                              MX_IGNORE_ENTITY_CATEGORY,
                              GET_FRAGMENT,
                              GET_FRAGMENT,
                              GET_FRAGMENT,
                              MX_IGNORE_ENTITY_CATEGORY,
                              GET_FRAGMENT)
  return std::nullopt;
#undef GET_FRAGMENT
}

// Return the fragment containing a token tree.
std::optional<Fragment> Fragment::containing(const TokenTree &tree) noexcept {
  if (tree.impl->fragment) {
    return Fragment(tree.impl->fragment);
  } else {
    return std::nullopt;
  }
}

// Generate all fragments in the index.
gap::generator<Fragment> Fragment::in(const Index &index) {
  auto impl = index.impl;
  for (auto eptr : impl->FragmentsFor(impl)) {
    co_yield Fragment(std::move(eptr));
  }
}

// Try to convert a variant entity into a fragment.
std::optional<Fragment> Fragment::from(const VariantEntity &entity) noexcept {
  if (std::holds_alternative<Fragment>(entity)) {
    return std::get<Fragment>(entity);
  }
  return std::nullopt;
}

// Return the ID of this fragment.
SpecificEntityId<FragmentId> Fragment::id(void) const noexcept {
  return FragmentId(impl->fragment_id);
}

// Returns the unique owning compilation that produced this fragment. There
// may be many compilations which produced equivalent/redundant fragments, but
// those redundancies are eliminated by the indexer.
Compilation Fragment::compilation(void) const noexcept {
  return Compilation(impl->ep->CompilationFor(
      impl->ep, impl->reader.getCompilationId()));
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
gap::generator<Decl> Fragment::top_level_declarations(void) const & {
  auto ep = impl->ep;
  auto frag_id = impl->fragment_id;
  auto tlds = impl->reader.getTopLevelDeclarations();
  for (RawEntityId eid : tlds) {
    VariantId vid = EntityId(eid).Unpack();
    if (!std::holds_alternative<DeclId>(vid)) {
      assert(false);
      continue;
    }

    DeclId decl_id = std::get<DeclId>(vid);
    if (decl_id.fragment_id != frag_id) {
      assert(false);
      continue;
    }

    DeclImplPtr decl_ptr = ep->DeclFor(ep, eid);
    if (!decl_ptr) {
      assert(false);
      continue;
    }

    co_yield Decl(std::move(decl_ptr));
  }
}

// Return child fragments.
gap::generator<Fragment> Fragment::nested_fragments(void) const & {
  auto ep = impl->ep;
  for (PackedFragmentId fid : ep->ListNestedFragmentIds(ep, id())) {
    if (FragmentImplPtr fptr = ep->FragmentFor(ep, fid)) {
      co_yield Fragment(std::move(fptr));
    } else {
      assert(false);
    }
  }
}

// Return the list of top-level macros in this fragment.
// This will return a mix of `Macro` or `Token` values.
gap::generator<PreprocessedEntity> Fragment::preprocessed_code(void) const & {
  EntityIdListReader macro_ids = impl->reader.getTopLevelMacros();

  const EntityProviderPtr ep = impl->ep;
  for (RawEntityId eid : macro_ids) {
    VariantId vid = EntityId(eid).Unpack();
    if (std::holds_alternative<MacroId>(vid)) {
      MacroImplPtr eptr = ep->MacroFor(ep, eid);
      
      // NOTE(pag): We don't check for fragments matching as we might have
      //            macros (e.g. `#define` in nested macros that we inject as
      //            top-level macros).
      if (!eptr) {
        assert(false);
        continue;
      }
      
      co_yield Macro(std::move(eptr));

    } else if (std::holds_alternative<MacroTokenId>(vid)) {
      MacroTokenId tid = std::get<MacroTokenId>(vid);
      if (tid.fragment_id != impl->fragment_id ||
          tid.offset >= impl->num_tokens) {
        assert(false);
        continue;
      }

      co_yield Token(impl->MacroTokenReader(impl), tid.offset);

    } else if (std::holds_alternative<ParsedTokenId>(vid)) {
      ParsedTokenId tid = std::get<ParsedTokenId>(vid);
      if (tid.fragment_id != impl->fragment_id ||
          tid.offset >= impl->num_parsed_tokens) {
        assert(false);
        continue;
      }

      co_yield Token(impl->ParsedTokenReader(impl), tid.offset);

    // File tokens can come up via whitespace injection.
    } else if (std::holds_alternative<FileTokenId>(vid)) {
      FileTokenId tid = std::get<FileTokenId>(vid);
      FileId fid(tid.file_id);
      FileImplPtr eptr = ep->FileFor(ep, fid);
      if (!eptr) {
        assert(false);
        continue;
      }

      if (tid.offset >= eptr->num_tokens) {
        assert(false);
        continue;
      }

      co_yield Token(eptr->TokenReader(eptr), tid.offset);

    // Nested fragment.
    } else if (std::holds_alternative<FragmentId>(vid)) {
      FragmentId fid = std::get<FragmentId>(vid);
      if (fid.fragment_id == impl->fragment_id) {
        assert(false);
        continue;
      }

      FragmentImplPtr eptr = ep->FragmentFor(ep, eid);
      if (!eptr) {
        assert(false);
        continue;
      }

      co_yield Fragment(std::move(eptr));

    } else {
      //assert(false);
    }
  }
}

// Run a regular expression search over this fragment.
gap::generator<RegexQueryMatch> Fragment::query(
    const RegexQuery &query) const & {
  RegexQueryResultImpl res(query, impl);
  for (auto match : res.Enumerate()) {
    co_yield match;
  }
}

}  // namespace mx
