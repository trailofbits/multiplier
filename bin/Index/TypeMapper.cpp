// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TypeMapper.h"
#include "PendingFragment.h"

#include <sstream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <clang/AST/ASTContext.h>
#include <clang/AST/Decl.h>
#include <clang/AST/Type.h>
#include <llvm/Support/Casting.h>
#pragma clang diagnostic pop

#include <pasta/AST/AST.h>

#include "EntityMapper.h"
#include "IdStore.h"
#include "PASTA.h"

namespace indexer {
namespace {

static bool IsSizedBuiltinType(const pasta::Type &type) {
  auto bt = pasta::BuiltinType::From(type);
  if (!bt) {
    return false;
  }

  if (bt->BuiltinKind() == pasta::BuiltinTypeKind::kBuiltinFn) {
    return false;
  } else {
    return !bt->IsSizelessType();
  }
}

// When serializing types, we'd ideally like to be able to remove "fluff"
// that doesn't really benefit us. This can involve stuff like drilling through
// `auto` or `decltype(...)` types to the true underlying type, or selecting
// the adjusted version of an adjusted type. This also helps us persist fewer
// overall types.
static clang::Type *BasicTypeDeduplication(clang::Type *type,
                                           uint32_t &up_quals,
                                           EntityList<const clang::Stmt*> *list = nullptr);

static clang::Type *BasicTypeDeduplication(clang::QualType type,
                                           uint32_t &up_quals,
                                           EntityList<const clang::Stmt*> *list = nullptr) {
  clang::Type *tp = const_cast<clang::Type *>(type.getTypePtrOrNull());
  if (!tp) {
    return tp;
  }

  up_quals |= type.getQualifiers().getAsOpaqueValue();
  return BasicTypeDeduplication(tp, up_quals);
}

clang::Type *BasicTypeDeduplication(clang::Type *type, uint32_t &up_quals,
                                    EntityList<const clang::Stmt*> *list) {
  if (!type) {
    return nullptr;
  }

  if (type->isDependentType()) {
    return type;
  }

  clang::Type *new_type = type;
  switch (type->getTypeClass()) {
    case clang::Type::Auto: {
      clang::AutoType *at = clang::dyn_cast<clang::AutoType>(type);
      if (at->isSugared()) {
        new_type = BasicTypeDeduplication(at->desugar(), up_quals);
      }
      break;
    }

    case clang::Type::TypeOfExpr: {
      clang::TypeOfExprType *et = clang::dyn_cast<clang::TypeOfExprType>(type);
      if (et->isSugared()) {
        new_type = BasicTypeDeduplication(et->desugar(), up_quals);
      }
      if (auto underlying_expr = et->getUnderlyingExpr()) {
        if (list) {
          list->emplace_back(reinterpret_cast<const clang::Stmt*>(underlying_expr));
        }
      }
      break;
    }

    case clang::Type::TypeOf:
      new_type = BasicTypeDeduplication(
          clang::dyn_cast<clang::TypeOfType>(type)->desugar(), up_quals);
      break;

    case clang::Type::Decltype: {
      clang::DecltypeType *dt = clang::dyn_cast<clang::DecltypeType>(type);
      if (auto underlying_expr = dt->getUnderlyingExpr()) {
        if (dt->isSugared()) {
          new_type = BasicTypeDeduplication(dt->desugar(), up_quals);
        }
        if (list) {
          list->emplace_back(reinterpret_cast<const clang::Stmt*>(underlying_expr));
        }
      } else {
        new_type = BasicTypeDeduplication(dt->getUnderlyingType(), up_quals);
      }
      break;
    }

    case clang::Type::Adjusted:
      new_type = BasicTypeDeduplication(
          clang::dyn_cast<clang::AdjustedType>(type)->desugar(),
          up_quals);
      break;

    case clang::Type::UnaryTransform: {
      auto ut = clang::dyn_cast<clang::UnaryTransformType>(type);
      if (ut->isSugared()) {
        new_type = BasicTypeDeduplication(ut->desugar(), up_quals);
      }
      break;
    }

    // We don't really care about the elaborator, e.g. `struct`, `union`, etc.
    // and Clang also embeds typedef types within elaborated types.
    case clang::Type::Elaborated: {
      clang::ElaboratedType *et = clang::dyn_cast<clang::ElaboratedType>(type);
      
      // If this represents a tag, e.g. `struct { ... }`, that has no name,
      // then we don't want to desugar this.
      if (auto decl = et->getOwnedTagDecl()) {
        if (!decl->getIdentifier()) {
          break;
        }
      }
      new_type = BasicTypeDeduplication(et->desugar(), up_quals);
      break;
    }
    case clang::Type::DeducedTemplateSpecialization: {
      auto dt = clang::dyn_cast<clang::DeducedTemplateSpecializationType>(type);
      if (dt->isSugared()) {
        new_type = BasicTypeDeduplication(dt->desugar(), up_quals);
      }
      break;
    }

    case clang::Type::Decayed:
      new_type = BasicTypeDeduplication(
          clang::dyn_cast<clang::DecayedType>(type)->desugar(),
          up_quals);
      break;

    default:
      break;
  }

  if (!new_type) {
    new_type = type;
  }

  return new_type;
}

}  // namespace

TypePrintingPolicy::~TypePrintingPolicy(void) {}

bool TypePrintingPolicy::ShouldPrintTagBodies(void) const {
  return false;
}

bool TypePrintingPolicy::ShouldPrintConstantExpressionsInTypes(void) const {
  return false;
}

bool TypePrintingPolicy::ShouldPrintOriginalTypeOfAdjustedType(void) const {
  return false;
}

bool TypePrintingPolicy::ShouldPrintOriginalTypeOfDecayedType(void) const {
  return false;
}

clang::QualType TypeMapper::Compress(clang::ASTContext &context,
                                     const clang::QualType &type) {
  uint32_t qualifiers = 0u;
  clang::Type *type_ptr = BasicTypeDeduplication(type, qualifiers);
  clang::QualType fast_qtype(type_ptr, qualifiers & clang::Qualifiers::FastMask);
  return context.getQualifiedType(
      fast_qtype, clang::Qualifiers::fromOpaqueValue(qualifiers));
}

clang::QualType TypeMapper::Compress(clang::ASTContext &context,
                                     const clang::Type *type) {
  return Compress(context, clang::QualType(type, 0u));
}

// Hash a type.
std::string TypeMapper::HashType(
    PendingFragment &pf, const pasta::Type &type,
    const pasta::PrintedTokenRange &range) {

  decls.clear();

  std::stringstream ss;
  ss << 'k' << static_cast<int>(type.Kind())
     << 'q' << type.RawQualifiers();

  pasta::Type canonical_type = type.CanonicalType();
  
  if (IsSizedBuiltinType(canonical_type) || canonical_type.IsPointerType()) {
    if (auto size = canonical_type.SizeInBits()) {
      ss << 's' << size.value();
    }
    if (auto align = canonical_type.Alignment()) {
      ss << 'a' << align.value();
    }
  }

  // Integrate the printed tokens, while also opaquely keeping track of
  // the declarations which we've come across.
  unsigned i = 0u;
  ss << 't';
  const void *last_decl = nullptr;
  for (pasta::PrintedToken tok : range) {
    ss << ' ' << tok.Data();

    for (std::optional<pasta::TokenContext> c = tok.Context();
         c; c = c->Parent()) {
      if (c->Kind() == pasta::TokenContextKind::kDecl) {
        if (const void *decl = c->Data(); decl != last_decl) {
          last_decl = decl;
          if (!ShouldHideFromIndexer(pasta::Decl::From(c.value()).value()) &&
            !ShouldSerializeDeclContext(pasta::Decl::From(c.value()).value())) {
            decls.emplace_back(decl, i++);
          }
        }

        // We only care about the shallowest decl in the context chain; anything
        // deeper (i.e. closer to the root of the AST) will end up being present
        // somewhere in `decls`.
        break;
      }
    }
  }

  // Now go and unique the decls and convert them to entity IDs, preserving
  // their original order.
  if (!decls.empty()) {
    std::stable_sort(decls.begin(), decls.end(),
                     [] (OpaqueOrderedDecl a, OpaqueOrderedDecl b) {
                       return a.first < b.first;
                     });

    auto it = std::unique(decls.begin(), decls.end(),
                          [] (OpaqueOrderedDecl a, OpaqueOrderedDecl b) {
                            return a.first == b.first;
                          });

    decls.erase(it, decls.end());

    std::sort(decls.begin(), decls.end(),
              [] (OpaqueOrderedDecl a, OpaqueOrderedDecl b) {
                return a.second < b.second;
              });

    ss << " d";
    for (OpaqueOrderedDecl od : decls) {
      auto eid = pf.em.EntityId(od.first);

      // NOTE(pag): Eventually this may trigger as a result of top-level
      //            decls that are ignored due to `ShouldHideFromIndexer`.

      // NOTE(kumarak): The assert will eventually trigger if there are underlying
      //                or replacable decls beneith types. These decls may not be
      //                visited because we stop visiting after seeing types while
      //                building fragments.
      // e.g:
      //  SubstTemplateTypeParmType 0x7ffc4ae9c470 'class mx::AcquiredAfterAttr' typename depth 0 index 0 _Up
      //  |-ClassTemplateSpecialization 0x7ffc4ae9ad90 '_Storage'
      //  `-RecordType 0x7ffc4ae69270 'class mx::AcquiredAfterAttr'
      //  `-CXXRecord 0x7ffc4ae69708 'AcquiredAfterAttr'
      //
      //assert(eid != mx::kInvalidEntityId || ((clang::Decl*)od.first)->isImplicit());
      if ((eid == mx::kInvalidEntityId) && ((clang::Decl*)od.first)->isImplicit()) {
        pf.TryAdd(pasta::AST::From(type).Adopt(
          reinterpret_cast<const clang::Decl*>(od.first)));
      } else if (eid == mx::kInvalidEntityId) {
        pf.TryAdd(pasta::AST::From(type).Adopt(
          reinterpret_cast<const clang::Decl*>(od.first)));
      }

      ss << ' ' << eid;
    }
  }

  return ss.str();
}

mx::RawEntityId TypeMapper::EntityId(const void *raw_type_,
                                     uint32_t raw_qualifiers) const {

  clang::Type *raw_type = BasicTypeDeduplication(
      reinterpret_cast<clang::Type *>(const_cast<void *>(raw_type_)),
      raw_qualifiers);

  TypeKey type_key(raw_type, raw_qualifiers);
  if (auto it = type_ids.find(type_key); it != type_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId TypeMapper::EntityId(const pasta::Type &entity) const {
  uint32_t raw_qualifiers = entity.RawQualifiers();
  clang::Type *raw_type = BasicTypeDeduplication(
      const_cast<clang::Type *>(entity.RawType()), raw_qualifiers);

  TypeKey type_key(raw_type, raw_qualifiers);
  if (auto it = type_ids.find(type_key); it != type_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

// NOTE(pag): `entity` may be updated.
bool TypeMapper::AddEntityId(PendingFragment &pf, pasta::Type *entity_) {
  assert(!read_only);

  pasta::Type &entity = *entity_;

  // First, check the non-shallow deduplicatd type.
  uint32_t raw_qualifiers = entity.RawQualifiers();
  TypeKey orig_type_key(entity.RawType(), raw_qualifiers);
  auto it = type_ids.find(orig_type_key);
  if (it != type_ids.end()) {
    return false;
  }

  EntityList<const clang::Stmt*> underlying_stmts;
  clang::Type *raw_type = BasicTypeDeduplication(
      const_cast<clang::Type *>(entity.RawType()), raw_qualifiers, &underlying_stmts);

  // If there are underlying stmts in type, add them to pending fragment
  // to serialize.
  for (auto stmt : underlying_stmts) {
    pf.TryAdd(pasta::AST::From(entity).Adopt(stmt));
  }


  TypeKey dedup_type_key(raw_type, raw_qualifiers);
  assert(dedup_type_key.first != nullptr);

  // Make sure we didn't bring in random new qualifiers.
  if (orig_type_key.first == dedup_type_key.first) {
    assert(orig_type_key.second == dedup_type_key.second);
  }

  // Found a hit in our cache.
  it = type_ids.find(dedup_type_key);
  if (it != type_ids.end()) {
    type_ids.emplace(orig_type_key, it->second);
    return false;
  }

  TypePrintingPolicy pp;

  entity = pasta::AST::From(entity).Adopt(raw_type, raw_qualifiers);

  auto token_range = pasta::PrintedTokenRange::Create(entity, pp);
  auto [type_id, is_new_type_id] = id_store.GetOrCreateTypeIdForHash(
      mx::FromPasta(entity.Kind()),
      raw_qualifiers,
      HashType(pf, entity, token_range),
      token_range.size());

  auto tid = type_id.Unpack();
  type_ids.emplace(orig_type_key, tid);
  type_ids.emplace(dedup_type_key, tid);

  return is_new_type_id;
}

mx::PackedTypeId TypeMapper::TypeId(const pasta::Type &type) const {
  mx::VariantId vid = mx::EntityId(this->EntityId(type)).Unpack();
  assert(std::holds_alternative<mx::TypeId>(vid));
  return std::get<mx::TypeId>(vid);
}

} // namespace
