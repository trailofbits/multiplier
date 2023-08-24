// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <capnp/common.h>
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <kj/io.h>
#include <unordered_set>

#include <multiplier/AST.h>
#include <multiplier/AST.capnp.h>
#include <multiplier/Database.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/Types.h>
#include <multiplier/Entities/TokenKind.h>

#include <pasta/AST/AST.h>
#include <pasta/AST/Printer.h>

#include "EntityMapper.h"
#include "Hash.h"
#include "Context.h"
#include "PASTA.h"
#include "PendingFragment.h"
#include "TypeMapper.h"

namespace indexer {

extern void SerializeType(const pasta::Type &entity,
                          const EntityMapper &em,
                          mx::RawEntityId type_index,
                          mx::ast::Type::Builder builder);

extern bool AcceptOOK(pasta::OverloadedOperatorKind ook,
                      pasta::TokenKind tk);

namespace {

// This is re-implementation of VisitStmt from Provenance.cpp that will
// get the related entity ids for the Printed tokens.
static const void *VisitStmt(const pasta::Stmt &stmt,
                             const pasta::PrintedToken &token,
                             unsigned depth) {
  std::string_view token_data = token.Data();
  bool is_identifier = ((token.Kind() == pasta::TokenKind::kIdentifier) ||
                        (token.Kind() == pasta::TokenKind::kRawIdentifier));
  if (auto dre = pasta::DeclRefExpr::From(stmt)) {
    if (auto named_decl = pasta::NamedDecl::From(dre->Declaration())) {
      if (dre->ExpressionToken().Data() == token_data && is_identifier) {
        return named_decl->RawDecl();
      }
    }
  } else if (auto me = pasta::MemberExpr::From(stmt)) {
    pasta::ValueDecl member_decl = me->MemberDeclaration();
    if (me->MemberToken().Data() == token_data) {
      return member_decl.RawDecl();
    } else {
      return VisitStmt(me->Base(), token, depth);
    }
  } else if (auto ce = pasta::CXXConstructExpr::From(stmt)) {
    pasta::CXXConstructorDecl constructor_decl = ce->Constructor();
    if (ce->Token().Data() == token_data) {
      return constructor_decl.RawDecl();
    }
  } else if (auto gt = pasta::GotoStmt::From(stmt)) {
    if (gt->LabelToken().Data() == token_data) {
      return gt->Label().RawDecl();
    }
  } else if (auto di = pasta::DesignatedInitExpr::From(stmt)) {
    for (pasta::Designator de : di->Designators()) {
      if (auto f = de.Field(); f && de.FieldToken().Data() == token_data) {
        return f->RawDecl();
      }
    }

  } else if (auto ili = pasta::InitListExpr::From(stmt)) {
    // TODO: not handled yet
  } else if (auto ls = pasta::LabelStmt::From(stmt)) {
    if (ls->IdentifierToken().Data() == token_data) {
      return ls->Declaration().RawDecl();
    }

  } else if (auto pde = pasta::PredefinedExpr::From(stmt)) {
    if (dre->ExpressionToken().Data() == token_data && is_identifier) {
      return pde->RawStmt();
    }

  } else if (auto call = pasta::CallExpr::From(stmt)) {
    auto called_decl = call->CalleeDeclaration();
    if (!called_decl) {
      return nullptr;
    }

    auto raw_decl = called_decl->RawDecl();

    // TODO(pag): Re-consider this identifier check. This manifested with
    //
    //                void (*func)(void);
    //                (*func)();
    //
    //            Here, the issue is that the first `(` was the expression
    //            token of the call.
    if (call->ExpressionToken().Data() == token_data && is_identifier) {
      return raw_decl;
    }

    // If the first context for this token is a method call, then see if it's
    // an overloaded operator.
    if (!depth) {
      if (auto meth = pasta::CXXMethodDecl::From(called_decl.value())) {
        if (AcceptOOK(meth->OverloadedOperator(), token.Kind())) {
          return raw_decl;
        }
      }
    }
  }

  return nullptr;
}

// This is re-implementation of VisitType from Provenance.cpp that will
// get the related entity ids for the Printed tokens.
static const void *VisitType(const pasta::Type &type,
                             const pasta::PrintedToken &token) {
  const std::string_view tok_data = token.Data();

  if (auto typedef_type = pasta::TypedefType::From(type)) {
    auto typedef_decl = typedef_type->Declaration();
    if (typedef_decl.Name() == tok_data) {
      return typedef_decl.RawDecl();
    }

  } else if (auto tag_type = pasta::TagType::From(type)) {
    auto tag_decl = tag_type->Declaration();
    if (tag_decl.Name() == tok_data) {
      return tag_decl.RawDecl();
    }

  } else if (auto deduced_type = pasta::DeducedType::From(type)) {
    return VisitType(deduced_type.value(), token);

  } else if (auto unqual_type = type.UnqualifiedType();
             unqual_type.RawType() != type.RawType()) {
    return VisitType(unqual_type, token);
  }

  return nullptr;
}

// Find the entity ID of the declaration that is most related to a particular
// printed token.
static mx::RawEntityId RelatedEntityIdToPrintedToken(
    const EntityMapper &em, const pasta::PrintedToken &token) {

  std::string_view token_data = token.Data();
  const void *related_entity = nullptr;
  mx::RawEntityId eid = mx::kInvalidEntityId;
  bool is_literal = false;

  switch (mx::FromPasta(token.Kind())) {
    default:
      return eid;

    case mx::TokenKind::NUMERIC_CONSTANT:
    case mx::TokenKind::CHARACTER_CONSTANT:
    case mx::TokenKind::WIDE_CHARACTER_CONSTANT:
    case mx::TokenKind::UTF8_CHARACTER_CONSTANT:
    case mx::TokenKind::UTF16_CHARACTER_CONSTANT:
    case mx::TokenKind::UTF32_CHARACTER_CONSTANT:
    case mx::TokenKind::STRING_LITERAL:
    case mx::TokenKind::WIDE_STRING_LITERAL:
    case mx::TokenKind::UTF8_STRING_LITERAL:
    case mx::TokenKind::UTF16_STRING_LITERAL:
    case mx::TokenKind::UTF32_STRING_LITERAL:
    case mx::TokenKind::KEYWORD___FUNC__:
    case mx::TokenKind::KEYWORD___FUNCTION__:
    case mx::TokenKind::KEYWORD___FUNCDNAME__:
    case mx::TokenKind::KEYWORD___FUNCSIG__:
    case mx::TokenKind::KEYWORD_LFUNCTION__:
    case mx::TokenKind::KEYWORD_LFUNCSIG__:
      is_literal = true;
      break;

    case mx::TokenKind::L_SQUARE:
    case mx::TokenKind::R_SQUARE:
    case mx::TokenKind::L_PARENTHESIS:
    case mx::TokenKind::R_PARENTHESIS:
    case mx::TokenKind::L_BRACE:
    case mx::TokenKind::R_BRACE:
    case mx::TokenKind::AMP:
    case mx::TokenKind::AMP_AMP:
    case mx::TokenKind::AMP_EQUAL:
    case mx::TokenKind::STAR:
    case mx::TokenKind::STAR_EQUAL:
    case mx::TokenKind::PLUS:
    case mx::TokenKind::PLUS_PLUS:
    case mx::TokenKind::PLUS_EQUAL:
    case mx::TokenKind::MINUS:
    case mx::TokenKind::ARROW:
    case mx::TokenKind::MINUS_MINUS:
    case mx::TokenKind::MINUS_EQUAL:
    case mx::TokenKind::TILDE:
    case mx::TokenKind::EXCLAIM:
    case mx::TokenKind::EXCLAIM_EQUAL:
    case mx::TokenKind::SLASH:
    case mx::TokenKind::SLASH_EQUAL:
    case mx::TokenKind::PERCENT:
    case mx::TokenKind::PERCENT_EQUAL:
    case mx::TokenKind::LESS:
    case mx::TokenKind::LESS_LESS:
    case mx::TokenKind::LESS_EQUAL:
    case mx::TokenKind::LESS_LESS_EQUAL:
    case mx::TokenKind::SPACESHIP:
    case mx::TokenKind::GREATER:
    case mx::TokenKind::GREATER_GREATER:
    case mx::TokenKind::GREATER_EQUAL:
    case mx::TokenKind::GREATER_GREATER_EQUAL:
    case mx::TokenKind::CARET:
    case mx::TokenKind::CARET_EQUAL:
    case mx::TokenKind::PIPE:
    case mx::TokenKind::PIPE_PIPE:
    case mx::TokenKind::PIPE_EQUAL:
    case mx::TokenKind::EQUAL:
    case mx::TokenKind::EQUAL_EQUAL:
    case mx::TokenKind::COMMA:
    case mx::TokenKind::PERIOD_STAR:
    case mx::TokenKind::ARROW_STAR:
    case mx::TokenKind::LESS_LESS_LESS:
    case mx::TokenKind::GREATER_GREATER_GREATER:
    case mx::TokenKind::CARETCARET:
    case mx::TokenKind::KEYWORD_DELETE:
    case mx::TokenKind::KEYWORD_NEW:
    case mx::TokenKind::KEYWORD_OPERATOR:
    case mx::TokenKind::IDENTIFIER: break;
  }

  unsigned depth = 0u;
  (void)depth;
  for (auto context = token.Context();
       !related_entity && eid == mx::kInvalidEntityId && context;
       ++depth, context = context->Parent()) {
    switch (context->Kind()) {
      case pasta::TokenContextKind::kStmt:
        if (std::optional<pasta::Stmt> stmt =
                pasta::Stmt::From(context.value())) {
          if (is_literal) {
            switch (stmt->Kind()) {
              default: break;
              case pasta::StmtKind::kUserDefinedLiteral:
              case pasta::StmtKind::kCharacterLiteral:
              case pasta::StmtKind::kIntegerLiteral:
              case pasta::StmtKind::kFixedPointLiteral:
              case pasta::StmtKind::kFloatingLiteral:
              case pasta::StmtKind::kStringLiteral:
              case pasta::StmtKind::kPredefinedExpr:
                related_entity = stmt->RawStmt();
                break;
            }
          } else {
            related_entity =  VisitStmt(stmt.value(), token, depth);
          }
        }
        break;
      case pasta::TokenContextKind::kType:
        if (!is_literal) {
          if (std::optional<pasta::Type> type =
              pasta::Type::From(context.value())) {
            related_entity = VisitType(type.value(), token);
          }
        }
        break;
      case pasta::TokenContextKind::kDecl:
        if (!is_literal) {
          if (std::optional<pasta::Decl> decl =
                  pasta::Decl::From(context.value())) {
            if (auto nd = pasta::NamedDecl::From(decl.value());
                nd && nd->Name() == token.Data()) {
              related_entity = nd->RawDecl();
            }
            if (!related_entity && decl->Token().Data() == token_data) {
              related_entity = decl->RawDecl();
            }
          }
        }
        break;
      case pasta::TokenContextKind::kAttr:
        if (std::optional<pasta::Attr> attr =
                pasta::Attr::From(context.value())) {
          if (attr->Token().Data() == token_data) {
            eid = em.EntityId(attr.value());
          } else {
            for (pasta::Token tok : attr->Tokens()) {
              if (tok.Data() == token_data) {
                eid = em.EntityId(attr.value());
                break;
              }
            }
          }
        }
        break;
      case pasta::TokenContextKind::kDesignator:
        if (!is_literal) {
          if (std::optional<pasta::Designator> d =
                  pasta::Designator::From(context.value())) {
            if (d->FieldToken().Data() == token_data) {
              if (auto field = d->Field()) {
                related_entity = field->RawDecl();
                break;
              }
            }
          }
        }
        break;

      default:
        break;
    }
  }

  if (related_entity && eid == mx::kInvalidEntityId) {
    eid = em.EntityId(related_entity);
  }

  return eid;
}

// Persist the printed tokens in the fragment builder if not
// creating Token tree for printed tokens
static void PersistPrintedTokens(
    EntityMapper &em, mx::rpc::Type::Builder &fb,
    const pasta::PrintedTokenRange &range, const mx::TypeId type_id) {

  std::string utf8_fragment_data;
  (void)em;

  unsigned num_parsed_tokens = static_cast<unsigned>(range.size());
  unsigned num_tokens = num_parsed_tokens;
  auto tk = fb.initTokenKinds(num_tokens);
  auto to = fb.initTokenOffsets(num_tokens + 1u);
  auto re = fb.initRelatedEntityId(num_tokens);
  mx::EntityOffset i = 0u;

  mx::TypeTokenId token_id;
  token_id.type_id = type_id.type_id;
  token_id.type_kind = type_id.kind;

  // Serialize the tokens.
  for (pasta::PrintedToken tok : range) {
    token_id.kind = TokenKindFromPasta(tok);
    token_id.offset = i;

    to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
    tk.set(i, static_cast<uint16_t>(token_id.kind));
    re.set(i, RelatedEntityIdToPrintedToken(em, tok));

    AccumulateTokenData<pasta::PrintedToken>(utf8_fragment_data, tok);
    ++i;
    
    // When persisting the types, some lookups will find tokens, e.g. `...`
    // in a `FunctionProtoType` for a variadic function. These will reference
    // parsed locations, but we want to arrange for them to instead reference
    // the type tokens.
    if (std::optional<pasta::Token> pt = tok.DerivedLocation()) {
      CHECK(em.token_tree_ids.emplace(pt->RawToken(),
                                      mx::EntityId(token_id)).second);
    }
  }

  to.set(i, static_cast<unsigned>(utf8_fragment_data.size()));
  fb.setTokenData(utf8_fragment_data);
}

// The implementation of PersistTokenContexts is same as for parsed tokens. Some
// of the checks here are redundant for printed token. Move to the specialized
// implementation for printed tokens

static void PersistTokenContexts(
    EntityMapper &em, const pasta::PrintedTokenRange &printed_tokens,
    mx::rpc::Type::Builder &fb) {

  using DeclContextSet = std::unordered_set<pasta::TokenContext>;
  std::map<mx::RawEntityId, DeclContextSet> contexts;

  // First, collect only the relevant contexts for this fragment. Group them by
  // entity ID, as we store the context list inline inside of the entities.
  unsigned num_tokens = 0u;
  for (const pasta::PrintedToken &tok : printed_tokens) {
    ++num_tokens;

    std::optional<pasta::TokenContext> next_context;
    for (auto context = tok.Context(); context;
         context = std::move(next_context)) {

      next_context = context->Parent();
      pasta::TokenContext c = context.value();
      if (auto alias_context = c.Aliasee()) {
        c = std::move(alias_context.value());
      }

      switch(c.Kind()) {
        case pasta::TokenContextKind::kAST:
          assert(!next_context);
          break;  // Should always be the root.
        case pasta::TokenContextKind::kInvalid:
          assert(false); // Don't expect these context kind
          break;
        case pasta::TokenContextKind::kDecl:
        case pasta::TokenContextKind::kStmt:
        case pasta::TokenContextKind::kType:
        case pasta::TokenContextKind::kAttr:
        case pasta::TokenContextKind::kDesignator:
        case pasta::TokenContextKind::kTemplateArgument:
        case pasta::TokenContextKind::kTemplateParameterList:
        case pasta::TokenContextKind::kCXXBaseSpecifier:
        case pasta::TokenContextKind::kTypeConstraint: {
          const mx::RawEntityId eid = em.EntityId(c.Data());
          if (eid != mx::kInvalidEntityId) {
            contexts[eid].insert(context.value());
          }
          break;
        }
        /* It is possible for context to be of Alias kind. We don't get entity id
         *  in that case. */
        case pasta::TokenContextKind::kAlias:
        case pasta::TokenContextKind::kString:
          break;
      }
    }
  }

  struct PendingTokenContext {
    mx::RawEntityId entity_id{mx::kInvalidEntityId};
    bool is_alias{false};
    unsigned offset{0};
    unsigned alias_offset{0};
  };

  std::unordered_map<pasta::TokenContext, PendingTokenContext>
      pending_contexts;

  unsigned num_contexts = 0;

  // Figure out the kinds of the contexts (stmt, decl, type), the index into the
  // respective entity list in the serialized fragment where the contexts will
  // be placed, the offset at which each context will reside within an entity-
  // specific list, etc.
  for (const auto &entry : contexts) {
    const DeclContextSet &entity_contexts = entry.second;

    // First, make a "template" of the context info, based on the entity kind
    // and fragment info.
    PendingTokenContext tpl;
    tpl.entity_id = entry.first;

    // Then, specialize this template for each context we encounter.
    for (const pasta::TokenContext &context : entity_contexts) {
      PendingTokenContext &info = pending_contexts[context];
      info = tpl;  // Copy the template.

      // Adjust the kind to be an aliasee.
      if (context.Aliasee()) {
        info.is_alias = true;
      }

      info.offset = num_contexts++;
    }
  }

  // Now resolve the aliasee targets, if any. Token contexts and their aliases
  // will end up in the same entity-specific lists. This is because the entity
  // in which the context resides will tell us its type.
  for (const auto &entry : contexts) {
    for (const pasta::TokenContext &context : entry.second) {
      auto pc_it = pending_contexts.find(context);
      if (pc_it == pending_contexts.end()) {
        continue;  // E.g. translation unit contexts.
      }

      PendingTokenContext &info = pc_it->second;
      CHECK_NE(info.entity_id, mx::kInvalidEntityId);

      if (!info.is_alias) {
        DCHECK(!context.Aliasee());
        continue;
      }

      auto alias_context = context.Aliasee();
      CHECK(alias_context.has_value());

      PendingTokenContext &alias_info = pending_contexts[alias_context.value()];
      CHECK_EQ(info.entity_id, alias_info.entity_id);
      CHECK_NE(info.offset, alias_info.offset);
      CHECK_LT(alias_info.offset, num_contexts);
      info.alias_offset = alias_info.offset;
    }
  }

  // Allocate as many token contexts as there are parsed tokens.
  auto tcb_list = fb.initTypeTokenContexts(num_contexts);
  auto tco_list = fb.initTypeTokenContextOffsets(num_tokens);

  // Finally, serialize the contexts.
  num_tokens = 0u;
  for (const pasta::PrintedToken &tok : printed_tokens) {
    tco_list.set(num_tokens, 0u);

    std::optional<mx::rpc::TokenContext::Builder> tcb;
    for (auto context = tok.Context(); context; context = context->Parent()) {

      pasta::TokenContext c = *context;
      auto pc_it = pending_contexts.find(c);
      if (pc_it == pending_contexts.end()) {
        continue;  // E.g. translation unit contexts, attributes.
      }

      const PendingTokenContext &info = pc_it->second;

      CHECK_LT(info.offset, num_contexts);
      if (!tcb) {
        tco_list.set(num_tokens, (info.offset << 1u) | 1u);
      } else {
        tcb->setParentIndex((info.offset << 1u) | 1u);
      }

      CHECK_NE(info.entity_id, mx::kInvalidEntityId);

      tcb.reset();
      tcb.emplace(tcb_list[info.offset]);
      tcb->setEntityId(info.entity_id);
      tcb->setParentIndex(0u);

      if (info.is_alias) {
        CHECK_LT(info.alias_offset, num_contexts);
        tcb->setAliasIndex((info.alias_offset << 1u) | 1u);
      } else {
        tcb->setAliasIndex(0u);
      }
    }

    ++num_tokens;
  }

  DCHECK_GT(fb.getTokenKinds().size(), 0u);
}

} // namespace

void GlobalIndexingState::PersistTypes(
    const pasta::AST &, NameMangler &, EntityMapper &em,
    const PendingFragment &pf) {

  for (const pasta::Type &type : pf.types_to_serialize) {
    em.ResetForFragment();

    ProgressBarWork type_progress_tracker(type_progress);

    auto maybe_token_range = em.tm.TypeTokenRange(type);
    CHECK(maybe_token_range.has_value());

    mx::PackedTypeId ptid = em.tm.TypeId(type);
    mx::TypeId tid = ptid.Unpack();

    capnp::MallocMessageBuilder message;
    mx::rpc::Type::Builder fb = message.initRoot<mx::rpc::Type>();

    auto tb = fb.initType();
    PersistPrintedTokens(em, fb, maybe_token_range.value(), tid);
    PersistTokenContexts(em, maybe_token_range.value(), fb);

    (void) SerializeType(type, em, tid.type_id, tb);

    database.AddAsync(
        mx::EntityRecord{ptid.Pack(), GetSerializedData(message)});
  }
}

}  // namespace indexer
