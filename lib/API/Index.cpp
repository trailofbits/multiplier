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

// Clear any internal caches.
void Index::clear_caches(void) const {
  impl->ClearCache();
}

FilePathList Index::file_paths(void) const {
  return impl->ListFiles(impl);
}

std::optional<File> Index::file(FileId id) const {
  if (auto ptr = impl->FileFor(impl, id)) {
    return File(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

std::optional<Fragment> Index::fragment(FragmentId id) const {
  if (auto ptr = impl->FragmentFor(impl, id)) {
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

// Download a fragment based off of an entity ID.
std::optional<Fragment> Index::fragment_containing(EntityId id) const {
  mx::VariantId opt_id = id.Unpack();
  FragmentImpl::Ptr ptr;
  if (std::holds_alternative<mx::DeclarationId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::DeclarationId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::StatementId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::StatementId>(opt_id).fragment_id);

  } else if (std::holds_alternative<mx::FragmentTokenId>(opt_id)) {
    ptr = impl->FragmentFor(
        impl, std::get<mx::FragmentTokenId>(opt_id).fragment_id);
  }

  if (ptr) {
    return Fragment(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

// Return an entity given its ID.
std::variant<Decl, Stmt, Type, Token, TokenSubstitution, NotAnEntity>
Index::entity(EntityId eid) const {

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
  }

  return NotAnEntity{};
}

WeggliQueryResult Index::query_fragments(const WeggliQuery &query) const {
  return WeggliQueryResult(impl->Query(impl, query));
}

RegexQueryResult Index::query_fragments(const RegexQuery &query) const {
  return RegexQueryResult(impl->Query(impl, query));
}

}  // namespace mx
