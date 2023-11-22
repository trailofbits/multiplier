// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
#include "multiplier/Entities/BinaryOperator.h"
#include "multiplier/Entities/CXXRecordDecl.h"
#include "multiplier/Entities/CastExpr.h"
#include "multiplier/Entities/CastKind.h"
#include "multiplier/Entities/CallExpr.h"
#include "multiplier/Entities/ExplicitCastExpr.h"
#include "multiplier/Entities/PointerType.h"
#include "multiplier/Entities/Stmt.h"
#include "multiplier/Entities/StmtKind.h"
#include "multiplier/Entity.h"
#include "multiplier/Reference.h"
#include "multiplier/Token.h"
#include "multiplier/Types.h"
#include <multiplier/Analysis/TypecastAnalysis.h>

#include <multiplier/Entities/ImplicitCastExpr.h>
#include <multiplier/Entities/BuiltinType.h>
#include <optional>
#include <stdexcept>
#include <stack>
#include <variant>

namespace mx {

CastState::CastState(const CastExpr &cast_expr) : cast_expr(cast_expr) {}

const CastExpr& CastState::get_cast_expr() {
    return cast_expr;
}

// Recovers the entity where the casting operation is performed on.
// e.g running on `foo((size_t) bar)` would return the entity `bar`.
VariantEntity CastState::source_entity() {
    VariantEntity ve(cast_expr.sub_expression_as_written());
    return ve;
}

// Attempts to recover a destination entity where the casted value is written to.
// Certain casting behaviors may not result in a destination.
std::optional<VariantEntity> CastState::destination_entity() {
    if (auto parent = cast_expr.parent_statement()) {

        // ie. foo((size_t) bar)
        // in-argument CallExpr casting doesn't have a real destination entity
        if (parent->kind() == mx::StmtKind::CALL_EXPR) {
            return std::nullopt;
        }

        // ie. return (int) bar;
        // ReturnStmts don't have a "real" destination entity
        if (parent->kind() == mx::StmtKind::RETURN_STMT) {
            return std::nullopt;
        }

        // TODO: what else?

        // ie. foo = (int) bar;
        if (auto binop = BinaryOperator::from(parent)) {
            VariantEntity ve(binop->lhs());
            return ve;
        }
    }

    // ie. int bar = (int) foo();
    if (auto parent = cast_expr.parent_declaration()) {
        if (auto var_decl = NamedDecl::from(parent)) {
            VariantEntity ve(*var_decl);
            return ve;
        }
    }
    return std::nullopt;
}

// If the casting is performed during a function call's argument conversion, recover the
// originating CallExpr and the index of the argument where the casting is occuring.
std::optional<std::pair<PackedStmtId, unsigned>> CastState::is_part_of_call_arg() {
    if (auto parent = cast_expr.parent_statement()) {
        if (auto call_expr = CallExpr::from(parent)) {

            // need to figure out specific argument number, can't use `.contains()`
            for (unsigned int iarg = 0; auto arg : call_expr->arguments()) {
                if (arg.id() == cast_expr.id()) {
                    return std::make_pair(call_expr->id(), iarg);
                }
                iarg++;
            }
        }
    }
    return std::nullopt;
}

std::pair<Type, Type> CastState::types_before_after_conversion() const {
    auto type_before = cast_expr.sub_expression().type()->canonical_type();
    auto type_after = [&](auto cast_expr){
        if (auto explicit_expr = ExplicitCastExpr::from(cast_expr)) {
            return explicit_expr->type_as_written().canonical_type();
        }

        auto maybe_type_after = cast_expr.type();
        if (!maybe_type_after) {
            throw std::runtime_error("no destination type for CastExpr, this should be unreachable");
        }
        return maybe_type_after->canonical_type();
    }(cast_expr);

    return std::make_pair(type_before, type_after);
}

CastTypeWidth CastState::determine_width_cast(Type &source, Type &dest) {
    auto before_size_in_bits = source.size_in_bits();
    auto after_size_in_bits = dest.size_in_bits();
    if (!before_size_in_bits || !after_size_in_bits) {
        return CastTypeWidth::NO_WIDTH_CHANGE;
    }

    if (before_size_in_bits > after_size_in_bits) {
        return CastTypeWidth::DOWNCAST;
    } else if (before_size_in_bits < after_size_in_bits) {
        return CastTypeWidth::UPCAST;
    } else {
        return CastTypeWidth::NO_WIDTH_CHANGE;
    }
}

// For the source and destination types' sizes, determine down/upcast.
// This does not work off of dereferenced pointer type for pointer-to-pointer casting.
CastTypeWidth CastState::width_cast() {
    auto [type_before, type_after] = types_before_after_conversion();
    return determine_width_cast(type_before, type_after);
}

CastCXXObjKind CastState::cxx_obj_cast() {
    if (auto cxx_cast_kind = cxx_object_cast_kind()) {
        switch (*cxx_cast_kind) {

        // these CastKinds give us up/downcast behavior for free
        case CastKind::BASE_TO_DERIVED:
        case CastKind::BASE_TO_DERIVED_MEMBER_POINTER:
            return CastCXXObjKind::BASE_TO_DERIVED_DOWNCAST;
        case CastKind::DERIVED_TO_BASE:
        case CastKind::UNCHECKED_DERIVED_TO_BASE:
        case CastKind::DERIVED_TO_BASE_MEMBER_POINTER:
            return CastCXXObjKind::BASE_TO_DERIVED_DOWNCAST;

        // reinterpret_cast and dynamic needs special handling
        case CastKind::REINTERPRET_MEMBER_POINTER:
        case CastKind::DYNAMIC: {
            auto [type_before, type_after] = types_before_after_conversion();

            // TODO need to retrieve the CXXRecordDecl associated
            // enrich PASTA first with .cxx_record_decl()
            /*
            auto before_decl = type_before.cxx_record_decl();
            auto after_decl = type_before.cxx_record_decl();
            if (!before_decl || !after_decl) {
                return CastCXXObjKind::NO_CXX_OBJ_CAST;
            }

            // check if we're downcasting by looking to see if the type after is a base class
            // of the source type
            for (auto base : before_decl.bases()) {
                if (auto base_decl = base->type().cxx_record_decl()) {
                    if (base_decl.canonical_decl() == before_decl.canonical_decl()) {
                        return CastCXXObjKind::BASE_TO_DERIVED_DOWNCAST;
                    }
                }
            }
            for (auto base : after_decl.bases()) {
                if (auto base_decl = base->type().cxx_record_decl()) {
                    if (base_decl.canonical_decl() == after_decl.canonical_decl()) {
                        return CastCXXObjKind::DERIVED_TO_BASE_UPCAST;
                    }
                }
            }
            */

            // NOTE: do we care about CXX-style casting on builtins?
            // ie. char* p = reinterpret_cast<char*>(i);
            return CastCXXObjKind::NO_CXX_OBJ_CAST;
        }
        default:
            return CastCXXObjKind::NO_CXX_OBJ_CAST;
        }
    }
    return CastCXXObjKind::NO_CXX_OBJ_CAST;
}

bool CastState::is_pointer_cast() {
    auto [type_before, type_after] = types_before_after_conversion();
    if (auto pointee = PointerType::from(type_before)) {
        return true;
    }
    if (auto pointee = PointerType::from(type_after)) {
        return true;
    }
    return false;
}

// If either source or destination types are pointer types, deference it and determine
// down/casting from those types instead. If not, behaves like `CastState::width_cast()`.
CastTypeWidth CastState::deferenced_width_cast() {
    auto [type_before, type_after] = types_before_after_conversion();

    if (auto pointee = PointerType::from(type_before)) {
        type_before = pointee->pointee_type();
    }
    if (auto pointee = PointerType::from(type_after)) {
        type_after = pointee->pointee_type();
    }
    return determine_width_cast(type_before, type_after);
}

std::optional<CastKind> CastState::cxx_object_cast_kind() {
    auto cast_kind = cast_expr.cast_kind();
    for (const auto& elem : kCXXObjectCasts) {
        if (cast_kind == elem) {
            return cast_kind;
        }
    }
    return std::nullopt;
}

std::optional<bool> CastState::is_implicit_cast() {
    if (auto implicit = ImplicitCastExpr::from(cast_expr)) {
        // Might be a part of a parent ExplicitCastExpr
        if (implicit->is_part_of_explicit_cast()) {
            return false;
        }
        return true;
    }
    return false;
}

CastSignChange CastState::sign_change() {
    auto [type_before, type_after] = types_before_after_conversion();

    // TODO: do sign changes only happen on built-ins?
    auto source_builtin =
        BuiltinType::from(type_before);
    auto dest_builtin =
        BuiltinType::from(type_after);
    if (!source_builtin || !dest_builtin) {
        return CastSignChange::NO_SIGN_CHANGE;
    }

    if (source_builtin->is_signed_integer() && dest_builtin->is_unsigned_integer()) {
        return CastSignChange::C_SIGNED_TO_UNSIGNED;
    } else if (source_builtin->is_unsigned_integer() && dest_builtin->is_signed_integer()) {
        return CastSignChange::C_UNSIGNED_TO_SIGNED;
    } else {
        return CastSignChange::NO_SIGN_CHANGE;
    }
}

TypecastChain::TypecastChain(bool is_forward) : is_forward(is_forward) {};

void TypecastChain::add_new_transition(EntityId reference, const CastState &cast_state, bool is_leaf) {
    auto [curr_type_before, curr_type_after ] = cast_state.types_before_after_conversion();

    // find key with CastState has a destination entity of `reference` and validate that the last type
    // and this current state's type are the same.
    // TODO: this might be a bit expensive?
    if (!cast_state_nodes.empty()) {
        for (auto iter : cast_state_nodes) {
            auto [key, states] = iter;
            for (auto state : states) {
                if (state.destination_entity() == reference) {
                    auto [state_before, state_after] = state.types_before_after_conversion();
                    if (state_after != curr_type_before) {
                        throw std::runtime_error("last type in chain does not match with current state's first type.");
                    }
                }
            }
        }
    }

    // the very first transition added sets up the root_type
    else if (cast_state_nodes.empty()) {
        root_type = &curr_type_before;
    }

    // if this is a leaf node + entity is a sink, cache final type
    if (is_leaf) {
        last_resolved_types.emplace(&curr_type_after);
    }

    cast_state_nodes[reference].push_back(cast_state);
    current_resolved_type = &curr_type_after;
}

Type* TypecastChain::get_current_resolved_type() {
    return current_resolved_type;
}

bool TypecastChain::is_identity_preserving() {
    if (cast_state_nodes.empty())
        return true;

    // check if any of the last resolved types match up the root_type,
    // meaning that it is possible that the type cast chain resolved ultimately
    // to its data source's initial type.
    if (last_resolved_types.contains(root_type)) {
        return true;
    }
    return false;
}

CastStateMap TypecastAnalysis::cast_instances(const Stmt &stmt) {
    CastStateMap cast_state_map;

    std::stack<Stmt> seen_stmts;
    std::unordered_set<PackedStmtId> seen_stmt_ids;

    seen_stmts.push(stmt);
    seen_stmt_ids.insert(stmt.id());

    /*
    // retrieve the original underlying Decl
    auto data_source_entity = [&](auto ve) -> std::optional<Decl> {

        // ie. VarDecl
        if (std::holds_alternative<Decl>(ve)) {
            return std::optional<Decl>(std::get<mx::Decl>(ve));

        // if a Stmt, get the original backing Decl
        // TODO: we should probably get a lvalue or rvalue??
        // TODO: we might want to not deal with these
        } else if (std::holds_alternative<Stmt>(ve)) {
            auto stmt = std::get<mx::Stmt>(ve);
            auto decls = mx::Decl::containing(stmt);
            auto decl = decls.begin();
            if (decl != decls.end()) {
                return std::optional<Decl>(decl->canonical_declaration());
            }
        }

        // TODO Token
        return std::nullopt;
    }(ve);

    if (!data_source_entity) {
        return std::nullopt;
    }
    */

    // ignore conversions not happening between values
    auto skip_cast = [&](const auto &cast_expr) {
        for (const auto &elem : kNoneTypeCasts) {
            if (cast_expr->cast_kind() == elem) {
                return true;
            }
        }
        return false;
    };

    while (!seen_stmts.empty()) {
        Stmt curr_stmt = seen_stmts.top();
        seen_stmts.pop();

        if (auto cast_expr = CastExpr::from(curr_stmt)) {
            if (skip_cast(cast_expr)) {
                continue;
            }
            CastState state(*cast_expr);
            cast_state_map.emplace(cast_expr->id(), state);
        }

        for (Stmt child : curr_stmt.children()) {
            seen_stmts.push(child);
        }
    }
    return cast_state_map;
}

// For a reference of a data variable, determine all casting transitions including in
// subsequent data sources
TypecastChain TypecastAnalysis::cast_chain(const VariantEntity &ve, bool backwards) {
    TypecastChain chain(backwards == false);

    // each time there is a typecast with a known destination, continue to visit it's references
    std::stack<VariantEntity> visit_entities;
    visit_entities.push(ve);

    while (!visit_entities.empty()) {
        auto to_visit = visit_entities.top();
        visit_entities.pop();

        // find typecasting references to the current data source
        for (Reference ref : Reference::to(to_visit)) {
            auto ref_kind = ref.builtin_reference_kind();
            if (!ref_kind) {
                continue;
            }
            if (ref_kind != BuiltinReferenceKind::TYPE_CASTS) {
                continue;
            }

            // TODO: how do check if reference is forward/backward?
            if (backwards) {
            }

            // retrieve the actual CastExpr
            auto ref_entity = ref.as_variant();
            auto cast_stmt = std::get_if<Stmt>(&ref_entity);
            auto cast_expr = CastExpr::from(*cast_stmt);
            if (!cast_expr) {
                continue;
            }

            CastState cast_state(*cast_expr);

            // does this cast have a destination? if not it will be a sink/leaf node
            if (auto dest_entity = cast_state.destination_entity()) {
                visit_entities.push(*dest_entity);
                chain.add_new_transition(to_visit, cast_state, true);
            } else {
                chain.add_new_transition(to_visit, cast_state, false);
            }
        }
    }
    return chain;
}
} // namespace mx