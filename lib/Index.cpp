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

#include "File.h"
#include "Fragment.h"

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
  if (auto frag = entity.impl->OwningFragment()) {
    return Index(frag->ep);

  } else if (auto file = entity.impl->OwningFile()) {
    return Index(file->ep);

  } else {
    return std::nullopt;
  }
}

// Clear any internal caches.
void Index::clear_caches(void) const {
  impl->ClearCache();
}

FilePathMap Index::file_paths(void) const {
  return impl->ListFiles(impl);
}

gap::generator<File> Index::files(void) const {
  std::vector<SpecificEntityId<FileId>> file_ids;
  auto file_paths = impl->ListFiles(impl);
  file_ids.reserve(file_paths.size());
  for (const auto &[path, file_id] : file_paths) {
    file_ids.emplace_back(file_id);
  }

  std::sort(file_ids.begin(), file_ids.end());
  auto it = std::unique(file_ids.begin(), file_ids.end());
  file_ids.erase(it, file_ids.end());

  for (auto file_id : file_ids) {
    auto file = impl->FileFor(impl, file_id);
    if (file) {
      co_yield file;
    }
  }
}

std::optional<File> Index::file(FileId id) const {
  return file(SpecificEntityId<FileId>(id));
}

std::optional<File> Index::file(SpecificEntityId<FileId> id) const {
  if (auto ptr = impl->FileFor(impl, id)) {
    return File(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

std::optional<File> Index::file(RawEntityId id) const {
  VariantId vid = EntityId(id).Unpack();
  if (std::holds_alternative<FileId>(vid)) {
    return file(SpecificEntityId<FileId>(std::get<FileId>(vid)));
  } else {
    return std::nullopt;
  }
}

std::optional<Fragment> Index::fragment(SpecificEntityId<FragmentId> id) const {
  if (auto ptr = impl->FragmentFor(impl, id)) {
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

std::optional<Fragment> Index::fragment(FragmentId id) const {
  return fragment(SpecificEntityId<FragmentId>(id));
}

std::optional<Fragment> Index::fragment(RawEntityId id) const {
  VariantId vid = EntityId(id).Unpack();
  if (std::holds_alternative<FragmentId>(vid)) {
    return fragment(SpecificEntityId<FragmentId>(std::get<FragmentId>(vid)));
  } else {
    return std::nullopt;
  }
}

// Download a fragment based off of an entity ID.
std::optional<Fragment> Index::fragment_containing(EntityId id) const {
  mx::VariantId opt_id = id.Unpack();
  FragmentImpl::Ptr ptr;
  if (std::holds_alternative<FragmentId>(opt_id)) {
    ptr = impl->FragmentFor(impl, std::get<mx::FragmentId>(opt_id));

  } else if (std::holds_alternative<mx::DeclarationId>(opt_id)) {
    FragmentId fid(std::get<mx::DeclarationId>(opt_id).fragment_id);
    ptr = impl->FragmentFor(impl, fid);

  } else if (std::holds_alternative<mx::StatementId>(opt_id)) {
    FragmentId fid(std::get<mx::StatementId>(opt_id).fragment_id);
    ptr = impl->FragmentFor(impl, fid);

  } else if (std::holds_alternative<mx::TypeId>(opt_id)) {
    FragmentId fid(std::get<mx::TypeId>(opt_id).fragment_id);
    ptr = impl->FragmentFor(impl, fid);

  } else if (std::holds_alternative<mx::AttributeId>(opt_id)) {
    FragmentId fid(std::get<mx::AttributeId>(opt_id).fragment_id);
    ptr = impl->FragmentFor(impl, fid);

  } else if (std::holds_alternative<mx::ParsedTokenId>(opt_id)) {
    FragmentId fid(std::get<mx::ParsedTokenId>(opt_id).fragment_id);
    ptr = impl->FragmentFor(impl, fid);

  } else if (std::holds_alternative<mx::DesignatorId>(opt_id)) {
    FragmentId fid(std::get<mx::DesignatorId>(opt_id).fragment_id);
    ptr = impl->FragmentFor(impl, fid);

  } else if (std::holds_alternative<mx::MacroId>(opt_id)) {
    FragmentId fid(std::get<mx::MacroId>(opt_id).fragment_id);
    ptr = impl->FragmentFor(impl, fid);
  }

  if (ptr) {
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

// Return an entity given its ID.
VariantEntity Index::entity(EntityId eid) const {

  VariantId vid = eid.Unpack();

  // It's a reference to a declaration.
  if (std::holds_alternative<DeclarationId>(vid)) {
    DeclarationId id = std::get<DeclarationId>(vid);
    FragmentId fid(id.fragment_id);
    assert(id == EntityId(id));
    auto frag_ptr = impl->FragmentFor(impl, fid);
    if (!frag_ptr) {
      return NotAnEntity();
    }
    auto reader = frag_ptr->NthDecl(id.offset);
    if (!reader.has_value()) {
      return NotAnEntity();
    }
    Decl decl(std::move(*reader));
    if (decl.id() == eid) {
      return decl;
    } else {
      assert(false);
    }

  // It's a reference to a statement.
  } else if (std::holds_alternative<StatementId>(vid)) {
    StatementId id = std::get<StatementId>(vid);
    FragmentId fid(id.fragment_id);
    assert(id == EntityId(id));
    auto frag_ptr = impl->FragmentFor(impl, fid);
    if (!frag_ptr) {
      return NotAnEntity();
    }
    auto reader = frag_ptr->NthStmt(id.offset);
    if (!reader.has_value()) {
      return NotAnEntity();
    }
    Stmt stmt(std::move(*reader));
    if (stmt.id() == eid) {
      return stmt;
    } else {
      assert(false);
    }

  // It's a reference to a type.
  } else if (std::holds_alternative<TypeId>(vid)) {
    TypeId id = std::get<TypeId>(vid);
    FragmentId fid(id.fragment_id);
    assert(id == EntityId(id));
    auto frag_ptr = impl->FragmentFor(impl, fid);
    if (!frag_ptr) {
      return NotAnEntity();
    }
    auto reader = frag_ptr->NthType(id.offset);
    if (!reader.has_value()) {
      return NotAnEntity();
    }
    Type type(std::move(*reader));
    if (type.id() == eid) {
      return type;
    } else {
      assert(false);
    }

  // It's a reference to an attribute.
  } else if (std::holds_alternative<AttributeId>(vid)) {
    AttributeId id = std::get<AttributeId>(vid);
    FragmentId fid(id.fragment_id);
    assert(id == EntityId(id));
    auto frag_ptr = impl->FragmentFor(impl, fid);
    if (!frag_ptr) {
      return NotAnEntity();
    }
    auto reader = frag_ptr->NthAttr(id.offset);
    if (!reader.has_value()) {
      return NotAnEntity();
    }
    Attr attr(std::move(*reader));
    if (attr.id() == eid) {
      return attr;
    } else {
      assert(false);
    }

  // It's a reference to a parsed token resident in a fragment.
  } else if (std::holds_alternative<ParsedTokenId>(vid)) {
    ParsedTokenId id = std::get<ParsedTokenId>(vid);
    FragmentId fid(id.fragment_id);
    assert(id == EntityId(id));
    if (FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, fid);
        frag_ptr && id.offset < frag_ptr->num_parsed_tokens) {
      Token tok(frag_ptr->ParsedTokenReader(frag_ptr), id.offset);
      if (tok.id() == eid) {
        return tok;
      } else {
        assert(false);
      }
    }

  // It's a reference to a macro token resident in a fragment.
  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    MacroTokenId id = std::get<MacroTokenId>(vid);
    FragmentId fid(id.fragment_id);
    assert(id == EntityId(id));
    if (FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, fid);
        frag_ptr && id.offset < frag_ptr->num_tokens) {
      Token tok(frag_ptr->MacroTokenReader(frag_ptr), id.offset);
      if (tok.id() == eid) {
        return tok;
      } else {
        assert(false);
      }
    }

  // It's a reference to a token substitution.
  } else if (std::holds_alternative<MacroId>(vid)) {
    MacroId id = std::get<MacroId>(vid);
    FragmentId fid(id.fragment_id);
    assert(id == EntityId(id));

    auto frag_ptr = impl->FragmentFor(impl, fid);
    if (!frag_ptr) {
      return NotAnEntity();
    }
    auto reader = frag_ptr->NthMacro(id.offset);
    if (!reader.has_value()) {
      return NotAnEntity();
    }
    Macro macro(std::move(*reader));
    if (macro.id() == eid) {
      return macro;
    } else {
      assert(false);
    }

  // It's a reference to a file token.
  } else if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId id = std::get<FileTokenId>(vid);
    FileId fid(id.file_id);
    if (FileImpl::Ptr file_ptr = impl->FileFor(impl, fid);
        file_ptr && id.offset < file_ptr->num_tokens) {
      Token tok(file_ptr->TokenReader(file_ptr), id.offset);
      if (tok.id() == eid) {
        return tok;
      } else {
        assert(false);
      }
    }
  
  } else if (std::holds_alternative<DesignatorId>(vid)) {
    DesignatorId id = std::get<DesignatorId>(vid);
    FragmentId fid(id.fragment_id);
    auto frag_ptr = impl->FragmentFor(impl, fid);
    if (!frag_ptr) {
      return NotAnEntity();
    }
    auto reader = frag_ptr->NthPseudo(id.offset);
    if (!reader.has_value()) {
      return NotAnEntity();
    }
    return Designator(std::move(*reader));
 
  } else if (std::holds_alternative<FragmentId>(vid)) {
    FragmentId id = std::get<FragmentId>(vid);
    if (FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, id)) {
      return Fragment(std::move(frag_ptr));
    }

  } else if (std::holds_alternative<FileId>(vid)) {
    FileId fid = std::get<FileId>(vid);
    if (FileImpl::Ptr file_ptr = impl->FileFor(
            impl, SpecificEntityId<FileId>(fid))) {
      return File(std::move(file_ptr));
    }
  }

  return NotAnEntity{};
}

// Search for entities by their name and category.
NamedEntityList Index::query_entities(std::string name) const {
  std::vector<RawEntityId> entity_ids;
  impl->FindSymbol(impl, std::move(name), entity_ids);
  
  NamedEntityList entities;
  entities.reserve(entity_ids.size());

  for (RawEntityId eid : entity_ids) {
    VariantId vid = EntityId(eid).Unpack();
    if (std::holds_alternative<DeclarationId>(vid)) {
      auto decl_ptr = impl->DeclFor(impl, eid);
      if (!decl_ptr) {
        assert(false);
        continue;
      }

      auto nd = NamedDecl::from(std::move(decl_ptr));
      if (!nd) {
        assert(false);
        continue;
      }

      entities.emplace_back(std::move(nd.value()));

    } else if (std::holds_alternative<MacroId>(vid)) {
      auto macro_ptr = impl->MacroFor(impl, eid);
      if (!macro_ptr) {
        assert(false);
        continue;
      }

      auto def = DefineMacroDirective::from(std::move(macro_ptr));
      if (!def) {
        assert(false);
        continue;
      }

      entities.emplace_back(std::move(def.value()));

    } else {
      assert(false);
    }
  }

  constexpr auto id_of = +[] (const NamedEntity &a) {
    return std::visit<RawEntityId>([] (auto &&x) { return x.id().Pack(); }, a);
  };

  std::sort(
      entities.begin(), entities.end(),
      [] (const NamedEntity &a, const NamedEntity &b) {
        return id_of(a) < id_of(b);
      });

  auto it = std::unique(
      entities.begin(), entities.end(),
      [] (const NamedEntity &a, const NamedEntity &b) {
        return id_of(a) == id_of(b);
      });

  entities.erase(it, entities.end());
  
  return entities;
}

}  // namespace mx
