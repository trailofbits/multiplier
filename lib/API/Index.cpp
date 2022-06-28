// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"
#include "Fragment.h"

#include <cassert>

namespace mx {

Index::~Index(void) {}

Index Index::containing(const Fragment &fragment) {
  return Index(fragment.impl->ep);
}

Index Index::containing(const File &file) {
  return Index(file.impl->ep);
}

// Clear any internal caches.
void Index::clear_caches(void) const {
  impl->ClearCache();
}

FilePathList Index::file_paths(void) const {
  return impl->ListFiles(impl);
}

std::optional<File> Index::file(FileId id) const {
  if (auto ptr = impl->FileFor(impl, id.file_id)) {
    return File(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

std::optional<File> Index::file(RawEntityId id) const {
  VariantId vid = EntityId(id).Unpack();
  if (std::holds_alternative<FileId>(vid)) {
    return file(std::get<FileId>(vid));
  } else {
    return std::nullopt;
  }
}

std::optional<Fragment> Index::fragment(FragmentId id) const {
  if (auto ptr = impl->FragmentFor(impl, id.fragment_id)) {
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

std::optional<Fragment> Index::fragment(RawEntityId id) const {
  VariantId vid = EntityId(id).Unpack();
  if (std::holds_alternative<FragmentId>(vid)) {
    return fragment(std::get<FragmentId>(vid));
  } else {
    return std::nullopt;
  }
}

// Download a fragment based off of an entity ID.
std::optional<Fragment> Index::fragment_containing(EntityId id) const {
  mx::VariantId opt_id = id.Unpack();
  FragmentImpl::Ptr ptr;
  if (std::holds_alternative<FragmentId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::FragmentId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::DeclarationId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::DeclarationId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::StatementId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::StatementId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::FragmentTokenId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::FragmentTokenId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::DesignatorId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::DesignatorId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::TokenSubstitutionId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::TokenSubstitutionId>(opt_id).fragment_id);
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
    assert(id == EntityId(id));
    if (FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, id.fragment_id)) {
      if (id.offset < frag_ptr->num_decls) {
        Decl decl(std::move(frag_ptr), id.offset);
        if (decl.id() == eid) {
          return decl;
        } else {
          assert(false);
        }
      }
    }

  // It's a reference to a statement.
  } else if (std::holds_alternative<StatementId>(vid)) {
    StatementId id = std::get<StatementId>(vid);
    assert(id == EntityId(id));
    if (FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, id.fragment_id)) {
      if (id.offset < frag_ptr->num_stmts) {
        Stmt stmt(std::move(frag_ptr), id.offset);
        if (stmt.id() == eid) {
          return stmt;
        } else {
          assert(false);
        }
      }
    }

  // It's a reference to a type.
  } else if (std::holds_alternative<TypeId>(vid)) {
    TypeId id = std::get<TypeId>(vid);
    assert(id == EntityId(id));
    if (FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, id.fragment_id)) {
      if (id.offset < frag_ptr->num_types) {
        Type type(std::move(frag_ptr), id.offset);
        if (type.id() == eid) {
          return type;
        } else {
          assert(false);
        }
      }
    }

  // It's a reference to a fragment token.
  } else if (std::holds_alternative<FragmentTokenId>(vid)) {
    FragmentTokenId id = std::get<FragmentTokenId>(vid);
    assert(id == EntityId(id));
    if (FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, id.fragment_id)) {
      auto tok_reader = frag_ptr->TokenReader(frag_ptr);
      if (id.offset < tok_reader->NumTokens()) {
        Token tok(std::move(tok_reader), id.offset);
        if (tok.id() == eid) {
          return tok;
        } else {
          assert(false);
        }
      }
    }

  // It's a reference to a token substitution.
  } else if (std::holds_alternative<TokenSubstitutionId>(vid)) {
    TokenSubstitutionId id = std::get<TokenSubstitutionId>(vid);
    assert(id == EntityId(id));

    // TODO(pag): Bounds check.
    if (FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, id.fragment_id)) {
      return TokenSubstitution(frag_ptr, id.offset, id.kind);
    }

  // It's a reference to a file token.
  } else if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId id = std::get<FileTokenId>(vid);
    if (FileImpl::Ptr file_ptr = impl->FileFor(impl, id.file_id)) {
      auto tok_reader = file_ptr->TokenReader(file_ptr);
      if (id.offset < tok_reader->NumTokens()) {
        Token tok(std::move(tok_reader), id.offset);
        if (tok.id() == eid) {
          return tok;
        } else {
          assert(false);
        }
      }
    }
  
  } else if (std::holds_alternative<DesignatorId>(vid)) {
    DesignatorId id = std::get<DesignatorId>(vid);
    if (FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, id.fragment_id);
        frag_ptr && id.offset < frag_ptr->num_pseudos) {
      return Designator(std::move(frag_ptr), id.offset);
    }
 
  } else if (std::holds_alternative<FragmentId>(vid)) {
    FragmentId id = std::get<FragmentId>(vid);
    if (FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, id.fragment_id)) {
      return Fragment(std::move(frag_ptr));
    }

  } else if (std::holds_alternative<FileId>(vid)) {
    FileId id = std::get<FileId>(vid);
    if (FileImpl::Ptr file_ptr = impl->FileFor(impl, id.file_id)) {
      return File(std::move(file_ptr));
    }
  }

  return NotAnEntity{};
}

WeggliQueryResult Index::query_fragments(const WeggliQuery &query) const {
  return WeggliQueryResult(impl->Query(impl, query));
}

RegexQueryResult Index::query_fragments(const RegexQuery &query) const {
  return RegexQueryResult(impl->Query(impl, query));
}

// Search for entities by their name and category.
NamedDeclList Index::query_entities(
    std::string name, mx::DeclCategory category) const {
  std::vector<RawEntityId> entity_ids;
  impl->FindSymbol(impl, std::move(name), category, entity_ids);
  
  NamedDeclList decls;
  decls.reserve(entity_ids.size());

  for (RawEntityId eid : entity_ids) {
    VariantId vid = EntityId(eid).Unpack();
    if (!std::holds_alternative<DeclarationId>(vid)) {
      assert(false);
      continue;
    }

    DeclarationId id = std::get<DeclarationId>(vid);
    FragmentImpl::Ptr frag_ptr = impl->FragmentFor(impl, id.fragment_id);
    if (!frag_ptr) {
      assert(false);
      continue;
    }

    if (id.offset >= frag_ptr->num_decls) {
      assert(false);
      continue;
    }

    Decl decl(std::move(frag_ptr), id.offset);
    if (decl.id() != eid) {
      assert(false);
      continue;
    }

    auto nd = NamedDecl::from(decl);
    if (!nd) {
      assert(false);
      continue;
    }

    if (!id.is_definition) {
      if (auto def = decl.definition()) {
        decls.emplace_back(std::move(NamedDecl::from(def.value()).value()));
      } else {
        decls.emplace_back(std::move(nd.value())); 
      }
    } else {
      decls.emplace_back(std::move(nd.value()));
    }
  }

  std::sort(
      decls.begin(), decls.end(),
      [] (const NamedDecl &a, const NamedDecl &b) {
        return a.id() < b.id();
      });

  auto it = std::unique(
      decls.begin(), decls.end(),
      [] (const NamedDecl &a, const NamedDecl &b) {
        return a.id() == b.id();
      });

  decls.erase(it, decls.end());
  
  return decls;
}

}  // namespace mx
