// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Index.h>

#include <cassert>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Designator.h>
#include <multiplier/Entities/Type.h>

#include "Attr.h"
#include "Decl.h"
#include "File.h"
#include "Fragment.h"
#include "Macro.h"
#include "Pseudo.h"
#include "Stmt.h"
#include "Type.h"
#include "Types.h"

namespace mx {

const char *EnumeratorName(IndexStatus status) {
  switch (status) {
    case IndexStatus::UNINITIALIZED: return "UNINITIALIZED";
    case IndexStatus::INDEXING_IN_PROGRESS: return "INDEXING_IN_PROGRESS";
    case IndexStatus::INDEXED: return "INDEXED";
  }
  return "<invalid>";
}

Index::~Index(void) {}

IndexStatus Index::status(bool block) const {

  // Return the version number of the index. A version number of `0` is
  // invalid, a version number of `1` means we've connected to a fresh/empty
  // indexer with nothing indexed, a version number `2 * n` for `n >= 1` means
  // that indexing is underway, and a version number of `(2 * n) + 1` for
  // `n >= 1` means that indexing is done.
  unsigned version = 0u;
  if (block) {
    version = impl->VersionNumber(impl);
  } else {
    version = impl->VersionNumber();
  }

  if (!version) {
    return IndexStatus::UNINITIALIZED;
  }

  if ((version - 1u) % 1u) {
    return IndexStatus::INDEXING_IN_PROGRESS;
  } else {
    return IndexStatus::INDEXED;
  }
}

// Create an in-memory caching index provider.
Index Index::in_memory_cache(Index next, unsigned timeout_s) {
  return EntityProvider::CreateInMemoryCache(std::move(next.impl), timeout_s);
}

Index Index::from_database(std::filesystem::path path) {
  return EntityProvider::CreateFromDatabase(std::move(path));
}

Index Index::containing(const Fragment &fragment) {
  return Index(fragment.impl->ep);
}

Index Index::containing(const File &file) {
  return Index(file.impl->ep);
}

Index Index::containing(const Decl &entity) {
  return Index(entity.impl->ep);
}

Index Index::containing(const Stmt &entity) {
  return Index(entity.impl->ep);
}

Index Index::containing(const Type &entity) {
  return Index(entity.impl->ep);
}

Index Index::containing(const Attr &entity) {
  return Index(entity.impl->ep);
}

Index Index::containing(const Macro &entity) {
  return Index(entity.impl->ep);
}

Index Index::containing(const Designator &entity) {
  return Index(entity.impl->ep);
}

std::optional<Index> Index::containing(const Token &entity) {
  if (auto frag = entity.impl->NthOwningFragment(entity.offset)) {
    return Index(frag->ep);

  } else if (auto frag2 = entity.impl->OwningFragment()) {
    return Index(frag2->ep);

  } else if (auto file = entity.impl->NthOwningFile(entity.offset)) {
    return Index(file->ep);

  } else if (auto file2 = entity.impl->OwningFile()) {
    return Index(file2->ep);

  } else {
    return std::nullopt;
  }
}

namespace {

struct IndexFromEntityVisitor {
  inline std::optional<Index> operator()(const NotAnEntity &) const {
    return std::nullopt;
  }
  template <typename T>
  inline std::optional<Index> operator()(const T &ent) const {
    return Index::containing(ent);
  }
};

}  // namespace

std::optional<Index> Index::containing(const VariantEntity &entity) {
  return std::visit<std::optional<Index>>(
      IndexFromEntityVisitor{}, entity);
}

// Clear any internal caches.
void Index::clear_caches(void) const {
  impl->ClearCache();
}

FilePathMap Index::file_paths(void) const {
  return impl->ListFiles(impl);
}

gap::generator<File> Index::files(void) const & {
  std::vector<SpecificEntityId<FileId>> file_ids;
  auto file_paths = impl->ListFiles(impl);
  file_ids.reserve(file_paths.size());
  for (const auto &[path, file_id] : file_paths) {
    file_ids.emplace_back(file_id);
  }

  std::sort(file_ids.begin(), file_ids.end());
  auto it = std::unique(file_ids.begin(), file_ids.end());
  file_ids.erase(it, file_ids.end());

  for (PackedFileId file_id : file_ids) {
    auto file = impl->FileFor(impl, file_id.Pack());
    if (file) {
      co_yield file;
    }
  }
}

#define MX_DEFINE_GETTER(type_name, lower_name, enum_name, category) \
  std::optional<type_name> Index::lower_name(RawEntityId id) const { \
    if (type_name ## ImplPtr ptr = impl->type_name ## For(impl, id)) { \
      return type_name(std::move(ptr)); \
    } else { \
      return std::nullopt; \
    } \
  }

MX_FOR_EACH_ENTITY_CATEGORY(MX_DEFINE_GETTER, MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_GETTER, MX_DEFINE_GETTER,
                            MX_DEFINE_GETTER)
#undef MX_DEFINE_GETTER

// Download a fragment based off of an entity ID.
std::optional<Fragment> Index::fragment_containing(EntityId eid) const {
  auto fid = mx::FragmentIdFromEntityId(eid.Pack());
  if (!fid) {
    return std::nullopt;
  }

  FragmentImplPtr eptr = impl->FragmentFor(impl, fid->Pack());
  if (!eptr) {
    assert(false);
    return std::nullopt;
  }

  return Fragment(std::move(eptr));
}

// Return an entity given its ID.
VariantEntity Index::entity(EntityId eid) const {

  RawEntityId raw_id = eid.Pack();
  VariantId vid = eid.Unpack();

  // It's a reference to a parsed token resident in a fragment.
  if (std::holds_alternative<ParsedTokenId>(vid)) {
    ParsedTokenId tid = std::get<ParsedTokenId>(vid);
    FragmentId fid(tid.fragment_id);

    if (FragmentImplPtr fptr = impl->FragmentFor(impl, fid);
        tid.offset < fptr->num_parsed_tokens) {
      Token tok(fptr->ParsedTokenReader(fptr), tid.offset);
      if (tok.id() == eid) {
        return tok;
      }
    }
    assert(false);

  // It's a reference to a macro token resident in a fragment.
  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    MacroTokenId tid = std::get<MacroTokenId>(vid);
    FragmentId fid(tid.fragment_id);

    if (FragmentImplPtr frag_ptr = impl->FragmentFor(impl, fid);
        frag_ptr && tid.offset < frag_ptr->num_tokens) {
      Token tok(frag_ptr->MacroTokenReader(frag_ptr), tid.offset);
      if (tok.id() == eid) {
        return tok;
      }
    }
    assert(false);

  // It's a reference to a file token.
  } else if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId tid = std::get<FileTokenId>(vid);
    FileId fid(tid.file_id);

    if (FileImplPtr file_ptr = impl->FileFor(impl, fid);
        file_ptr && tid.offset < file_ptr->num_tokens) {
      Token tok(file_ptr->TokenReader(file_ptr), tid.offset);
      if (tok.id() == eid) {
        return tok;
      }
    }
    assert(false);


#define MX_DISPATCH_GETTER(type_name, lower_name, enum_name, category) \
    } else if (std::holds_alternative<type_name ## Id>(vid)) { \
      if (type_name ## ImplPtr eptr = impl->type_name ## For(impl, raw_id)) { \
        type_name ret(std::move(eptr)); \
        if (ret.id().Pack() == raw_id) { \
          return ret; \
        } \
      } \
      assert(false);

    MX_FOR_EACH_ENTITY_CATEGORY(MX_DISPATCH_GETTER, MX_IGNORE_ENTITY_CATEGORY,
                                MX_DISPATCH_GETTER, MX_DISPATCH_GETTER,
                                MX_DISPATCH_GETTER)
#undef MX_DISPATCH_GETTER


  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(raw_id == kInvalidEntityId);
  }

  return NotAnEntity{};
}

// Search for entities by their name and category.
//
// NOTE(pag): This might return redeclarations.
gap::generator<NamedEntity> Index::query_entities(std::string name) const & {

  for (RawEntityId eid : impl->FindSymbol(impl, std::move(name))) {
    VariantId vid = EntityId(eid).Unpack();
    if (std::holds_alternative<DeclId>(vid)) {
      DeclImplPtr decl_ptr = impl->DeclFor(impl, eid);
      if (!decl_ptr) {
        assert(false);
        continue;
      }

      std::optional<NamedDecl> nd = NamedDecl::from(Decl(std::move(decl_ptr)));
      if (!nd) {
        assert(false);
        continue;
      }

      co_yield std::move(nd.value());

    } else if (std::holds_alternative<MacroId>(vid)) {
      MacroImplPtr macro_ptr = impl->MacroFor(impl, eid);
      if (!macro_ptr) {
        assert(false);
        continue;
      }

      std::optional<DefineMacroDirective> def =
          DefineMacroDirective::from(Macro(std::move(macro_ptr)));
      if (!def) {
        assert(false);
        continue;
      }

      co_yield std::move(def.value());

    } else if (std::holds_alternative<FileId>(vid)) {
      FileImplPtr file_ptr = impl->FileFor(impl, eid);
      if (!file_ptr) {
        assert(false);
        continue;
      }

      co_yield File(std::move(file_ptr));

    } else {
      assert(false);
    }
  }
}

}  // namespace mx
