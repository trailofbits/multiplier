// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "EntityMapper.h"

#include <cassert>
#include <glog/logging.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <clang/AST/DeclBase.h>
#pragma clang diagnostic pop

#include "TypeMapper.h"
#include "Util.h"

namespace indexer {

mx::RawEntityId EntityMapper::ParentDeclId(const void *entity) const {
  if (auto it = parent_decl_ids.find(entity); it != parent_decl_ids.end()) {
    assert(it->second.Extract<mx::DeclId>());
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::ParentStmtId(const void *entity) const {
  if (auto it = parent_stmt_ids.find(entity); it != parent_stmt_ids.end()) {
    assert(it->second.Extract<mx::StmtId>());
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::ParentDeclId(const pasta::Decl &entity) const {
  return ParentDeclId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::ParentDeclId(const pasta::Stmt &entity) const {
  return ParentDeclId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::ParentDeclId(const pasta::Designator &entity) const {
  return ParentDeclId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::ParentDeclId(const pasta::TemplateArgument &entity) const {
  return ParentDeclId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::ParentDeclId(const pasta::TemplateParameterList &entity) const {
  return ParentDeclId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::ParentDeclId(const pasta::CXXBaseSpecifier &entity) const {
  return ParentDeclId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::ParentStmtId(const pasta::Decl &entity) const {
  return ParentStmtId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::ParentStmtId(const pasta::Stmt &entity) const {
  return ParentStmtId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::ParentStmtId(const pasta::Designator &entity) const {
  return ParentStmtId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::ParentStmtId(const pasta::TemplateArgument &entity) const {
  return ParentStmtId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::EntityId(const void *entity) const {
  if (!entity) {
    return mx::kInvalidEntityId;
  }

  if (auto it = entity_ids.find(entity); it != entity_ids.end()) {
    if (mx::RawEntityId eid = it->second.Pack(); eid != mx::kInvalidEntityId) {
      return eid;
    }
  }
  return PerFragmentEntityId(entity);
}


mx::RawEntityId EntityMapper::PerFragmentEntityId(const void *entity) const {
  if (auto it = token_tree_ids.find(entity); it != token_tree_ids.end()) {
    return it->second.Pack();

  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Decl &entity) const {
  return EntityId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Stmt &entity) const {
  return SelectiveEntityId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Attr &entity) const {
  auto raw_attr = RawEntity(entity);
  if (auto it = attr_ids.find(raw_attr); it != attr_ids.end()) {
    return it->second.Pack();
  }
  return SelectiveEntityId(raw_attr);
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Macro &entity) const {
  // NOTE(pag): May be part of a directive, which may be referenced by other
  //            fragments, so we use `EntityId`, which falls back on
  //            `PerFragmentEntityId`.
  auto ret = EntityId(RawEntity(entity));
  if (ret || entity.Kind() != pasta::MacroKind::kExpansion) {
    return ret;
  }

  // The `TokenTree` merges macro expansions with argument pre-expansions, which
  // are separately represented in PASTA. The `TokenTree::Macro()` node
  // preserved is the top-level, non-argument pre-expansion phase of the
  // expansion, just in case `TokenTree` building fails and we revert to a
  // backup path of serialization (where we might already have entity IDs for
  // these top-level expansions from the `EntityLabeller`). However, there
  // may be children nodes of the argument pre-expansion that point to that
  // rather than the top-level node, so here we try to recover to enable
  // `mx::Macro::parent` serialization to succeed.

  auto exp = pasta::MacroExpansion::From(entity);
  if (!exp || !exp->IsArgumentPreExpansion()) {
    return ret;
  }

  if (std::optional<pasta::Macro> parent = exp->Parent()) {
    ret = EntityId(parent.value());
  }

  return ret;
}

mx::RawEntityId EntityMapper::EntityId(const TokenTree &entity) const {
  return EntityId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::EntityId(const TokenTreeNode &entity) const {
  return EntityId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Token &entity) const {
  if (!entity) {
    return mx::kInvalidEntityId;
  }

  auto eid = PerFragmentEntityId(RawEntity(entity));
  if (eid != mx::kInvalidEntityId) {
    return eid;
  }

  // NOTE(pag): Is it technically common to observe these types of issues
  //            when serializing things like namespaces, which are semi-
  //            internalized into fragments.
  if (auto ft = entity.FileLocation()) {
    return EntityId(ft.value());
  }

  return mx::kInvalidEntityId;
}

namespace {

std::pair<mx::RawEntityId, mx::RawEntityId> FirstLastFromDerived(
    const EntityMapper &em, const pasta::Token &tok) {
  auto dt = tok.DerivedLocation();
  auto first_eid = mx::kInvalidEntityId;
  auto last_eid = mx::kInvalidEntityId;

  if (std::holds_alternative<pasta::FileToken>(dt)) {
    first_eid = em.EntityId(std::get<pasta::FileToken>(dt));
    last_eid = first_eid;
  
  // Recover by finding the first/last file tokens associated with the macro
  // use.
  } else if (std::holds_alternative<pasta::MacroToken>(dt)) {
    pasta::Macro root = RootMacroFrom(std::get<pasta::MacroToken>(dt));
    auto ft = root.BeginToken();
    auto et = root.EndToken();
    if (ft && et) {
      auto ft_fl = ft->FileLocation();
      auto et_fl = et->FileLocation();
      if (ft_fl && et_fl) {
        first_eid = em.EntityId(ft_fl.value());
        last_eid = em.EntityId(et_fl.value());
      }
    }
  }

  return {first_eid, last_eid};
}

}  // namespace

// Get a pair of entity IDs given a parsed token range. This will generally
// try to fix up situations where we can't resolve to parsed tokens by falling
// back to ranges of file tokens.
std::pair<mx::RawEntityId, mx::RawEntityId> EntityMapper::EntityIds(
    const pasta::TokenRange &range) const {
  auto size = range.Size();
  if (!size) {
    return {mx::kInvalidEntityId, mx::kInvalidEntityId};
  }

  auto first_tok = range[0];
  auto first_eid = EntityId(RawEntity(first_tok));
  auto last_eid = first_eid;

  if (first_eid == mx::kInvalidEntityId) {
    std::tie(first_eid, last_eid) = FirstLastFromDerived(*this, first_tok);
  }

  if (size == 1u) {
    return {first_eid, last_eid};
  }

  auto last_tok = range[size - 1u];
  last_eid = EntityId(RawEntity(last_tok));
  if (last_eid == mx::kInvalidEntityId) {
    auto new_first_eid = mx::kInvalidEntityId;
    std::tie(new_first_eid, last_eid) = FirstLastFromDerived(*this, last_tok);
    
    if (first_eid == mx::kInvalidEntityId) {
      first_eid = new_first_eid;
    }
  }

  if (last_eid == mx::kInvalidEntityId) {
    last_eid = first_eid;
  }

  return {first_eid, last_eid};
}

mx::RawEntityId EntityMapper::EntityId(const pasta::DerivedToken &entity) const {
  if (std::holds_alternative<std::monostate>(entity)) {
    return mx::kInvalidEntityId;
  } else if (std::holds_alternative<pasta::MacroToken>(entity)) {
    return EntityId(std::get<pasta::MacroToken>(entity));
  } else if (std::holds_alternative<pasta::FileToken>(entity)) {
    return EntityId(std::get<pasta::FileToken>(entity));
  } else {
    assert(false);
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::EntityId(const pasta::PrintedToken &entity) const {
  return PerFragmentEntityId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::EntityId(const pasta::MacroToken &entity) {
  return EntityId(RawEntity(entity));
}

mx::RawEntityId EntityMapper::EntityId(const pasta::File &file) const {
  return EntityId(RawEntity(file));
}

mx::RawEntityId EntityMapper::EntityId(const pasta::FileToken &entity) const {
  auto file = pasta::File::Containing(entity);
  auto fid = SpecificEntityId<mx::FileId>(file);
  if (!fid) {
    return mx::kInvalidEntityId;
  }

  mx::FileTokenId id;
  id.file_id = fid->file_id;
  id.kind = TokenKindFromPasta(entity);
  id.offset = static_cast<mx::EntityOffset>(entity.Index());
  ::mx::EntityId ret_id(id);
  return ret_id.Pack();
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Type &entity) const {
  return tm.EntityId(entity);
}

mx::RawEntityId EntityMapper::EntityId(
    const pasta::TemplateArgument &pseudo) const {
  return PerFragmentEntityId(RawEntity(pseudo));
}

mx::RawEntityId EntityMapper::EntityId(
    const pasta::TemplateParameterList &pseudo) const {
  return PerFragmentEntityId(RawEntity(pseudo));
}

mx::RawEntityId EntityMapper::EntityId(
    const pasta::CXXBaseSpecifier &pseudo) const {
  return PerFragmentEntityId(RawEntity(pseudo));
}

mx::RawEntityId EntityMapper::EntityId(
    const pasta::Designator &pseudo) const {
  return PerFragmentEntityId(RawEntity(pseudo));
}

mx::RawEntityId EntityMapper::EntityId(
    const pasta::CXXCtorInitializer &pseudo) const {
  return PerFragmentEntityId(RawEntity(pseudo));
}

mx::RawEntityId EntityMapper::EntityIdOfType(
    const void *type, uint32_t quals) const {
  return tm.EntityId(type, quals);
}

std::optional<const pasta::Decl> EntityMapper::ParentDecl(
    const pasta::AST &ast, const pasta::Decl &entity) const {
  if (auto it = parent_decls.find(RawEntity(entity));
      it != parent_decls.end() && it->second) {
    return ast.Adopt(static_cast<const clang::Decl *>(it->second));
  }
  return std::nullopt;
}

std::optional<const pasta::Decl> EntityMapper::ParentDecl(
    const pasta::AST &ast, const pasta::Stmt &entity) const {
  if (auto it = parent_decls.find(RawEntity(entity));
      it != parent_decls.end() && it->second) {
    return ast.Adopt(static_cast<const clang::Decl *>(it->second));
  }
  return std::nullopt;
}

std::optional<const pasta::Stmt> EntityMapper::ParentStmt(
    const pasta::AST &ast, const pasta::Decl &entity) const {
  if (auto it = parent_stmts.find(RawEntity(entity));
      it != parent_stmts.end() && it->second) {
    return ast.Adopt(static_cast<const clang::Stmt *>(it->second));
  }
  return std::nullopt;
}

std::optional<const pasta::Stmt> EntityMapper::ParentStmt(
    const pasta::AST &ast, const pasta::Stmt &entity) const {
  if (auto it = parent_stmts.find(RawEntity(entity));
      it != parent_stmts.end() && it->second) {
    return ast.Adopt(static_cast<const clang::Stmt *>(it->second));
  }
  return std::nullopt;
}

// ID of the parent fragment.
mx::RawEntityId EntityMapper::ParentFragmentId(
    const void *parent_entity, const std::vector<pasta::Decl> &decls) const {
  if (!parent_entity) {
    return mx::kInvalidEntityId;
  }

  mx::VariantId vid = mx::EntityId(this->EntityId(parent_entity)).Unpack();
  mx::RawEntityId parent_frag_index = mx::kInvalidEntityId;

  if (std::holds_alternative<mx::DeclId>(vid)) {
    parent_frag_index = std::get<mx::DeclId>(vid).fragment_id;

  } else if (std::holds_alternative<mx::MacroId>(vid)) {
    parent_frag_index = std::get<mx::MacroId>(vid).fragment_id;

  } else if (std::holds_alternative<mx::FragmentId>(vid)) {
    parent_frag_index = std::get<mx::FragmentId>(vid).fragment_id;

  // This generally indicates one of a few problems:
  //
  //    - There is something that was discovered, e.g. via a template
  //      specialization list, that isn't actually discoverable from a decl
  //      context (i.e. it's not added to a `DeclContext` in Clang). This
  //      generally requires a Clang patch. You can test this by checking:
  //
  //        decl->getDeclContext()->containsDecl(decl)
  //        decl->getLexicalDeclContext()->containsDecl(decl)
  //
  //    - There is something wrong in Bounds.cpp in PASTA. This could be that
  //      there is something that shows up with a token location logically
  //      before that of `parent_entity`.
  //
  //    - The bounds of the entity and its parents match, but there is a
  //      heuristic, e.g. `ExpandDeclRange` or a called function in
  //      `IndexCompileJob.cpp`, that goes and expands the range (e.g. to
  //      include leading whitespace), and that triggers a child to somehow
  //      show up before its parent.
  //
  //    - There is some really annoying nesting of lambdas and templates that
  //      screws up the `TLDFinder`.
  } else {
    CHECK(!decls.empty());
    LOG(ERROR)
        << "Couldn't find parent fragment ID of " << decls.front().KindName()
        << " (it " << (IsLambda(decls.front()) ? "is" : "isn't")
        << " a lambda; its parent " << (IsTopLevel(parent_entity) ? "is" : "isn't")
        << " a top-level entity)"
        << PrefixedLocation(decls.front(), " at or near ")
        << " in main job file "
        << pasta::AST::From(decls.front()).MainFile().Path().generic_string();

    return mx::kInvalidEntityId;
  }

  return mx::EntityId(mx::FragmentId(parent_frag_index)).Pack();
}

void EntityMapper::ResetForFragment(void) {
  // clear token tree ids, parent_decl_ids, and parent_stmt_ids before
  // processing new pending fragments. Not clearing them will cause issue
  // with fragment specific token trees and parentage tracking
  token_tree_ids.clear();
  parent_decl_ids.clear();
  parent_stmt_ids.clear();
  parent_decls.clear();
  parent_stmts.clear();
}

}  // namespace indexer
