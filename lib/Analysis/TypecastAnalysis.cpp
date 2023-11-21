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
#include "multiplier/Reference.h"
#include "multiplier/Token.h"
#include "multiplier/Types.h"
#include <multiplier/Analysis/TypecastAnalysis.h>

#include <multiplier/Entities/ImplicitCastExpr.h>
#include <multiplier/Entities/BuiltinType.h>
#include <optional>
#include <stdexcept>
#include <unordered_set>
#include <utility>
#include <iostream>
#include <stack>
#include <variant>

namespace mx {

CastState::CastState(const CastExpr &cast_expr) : cast_expr(cast_expr) {}

const CastExpr& CastState::get_cast_expr() {
    return cast_expr;
}

// Recovers the entity where the casting operation is performed on.
// e.g running on `foo((size_t) bar)` would return the entity `bar`.
EntityId CastState::source_entity() {
    return cast_expr.sub_expression_as_written().id();
}

// Attempts to recover a destination entity where the casted value is written to.
// Certain casting behaviors may not result in a destination.
std::optional<EntityId> CastState::destination_entity() {
    if (auto parent = cast_expr.parent_statement()) {

        // ie. foo((size_t) bar)
        // CallExprs don't have a real destination entity
        // TODO: maybe get the FunctionDecl's specific argument?
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
            return binop->lhs().id();
        }
    }

    // ie. int bar = (int) foo();
    if (auto parent = cast_expr.parent_declaration()) {
        if (auto var_decl = NamedDecl::from(parent)) {
            return var_decl->id();
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


Type CastState::type_before_conversion() {
    return cast_expr.sub_expression().type()->canonical_type();
}

Type CastState::type_after_conversion() {
    if (auto explicit_expr = ExplicitCastExpr::from(cast_expr)) {
        return explicit_expr->type_as_written().canonical_type();
    }

    std::optional<mx::Type> maybe_type_after = cast_expr.type();
    if (!maybe_type_after) {
        throw std::runtime_error("no destination type for CastExpr, this should be unreachable");
    }
    return maybe_type_after->canonical_type();
}

CastTypeWidth CastState::determine_width_cast(Type &source, Type &dest) {
    std::optional<uint64_t> before_size_in_bits = source.size_in_bits();
    std::optional<uint64_t> after_size_in_bits = dest.size_in_bits();
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
    Type type_before = type_before_conversion();
    Type type_after = type_after_conversion();
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
            Type type_before = type_before_conversion();
            Type type_after = type_after_conversion();

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
    Type type_before = type_before_conversion();
    Type type_after = type_after_conversion();

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
    Type type_before = type_before_conversion();
    Type type_after = type_after_conversion();

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
        if (implicit->is_part_of_explicit_cast()) {
            return false;
        }
        return true;
    } else if (auto explicit_cast = ExplicitCastExpr::from(cast_expr)) {
        return false;
    } else {
        return false;
    }
}

CastSignChange CastState::sign_change() {
    Type source_type = type_before_conversion();
    Type dest_type = type_after_conversion();

    // TODO: do sign changes only happen on built-ins?
    std::optional<BuiltinType> source_builtin =
        BuiltinType::from(source_type);
    std::optional<BuiltinType> dest_builtin =
        BuiltinType::from(dest_type);
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

void TypecastChain::add_new_transition(CastState &cast_state) {
    CastState& last_cast_state = cast_state_transitions.back();

    // TODO: error if otherwise?
    if (last_cast_state.type_after_conversion() == cast_state.type_before_conversion()) {
        cast_state_transitions.push_back(cast_state);
        current_resolved_type = cast_state.type_after_conversion();
    }
}

std::optional<Type> TypecastChain::get_current_resolved_type() {
    return current_resolved_type;
}

bool TypecastChain::is_identity_preserving() {
    if (cast_state_transitions.empty())
        return true;

    if (cast_state_transitions.size() == 1) {
        return cast_state_transitions.at(0).type_before_conversion() == cast_state_transitions.at(0).type_after_conversion();
    }
    return cast_state_transitions.front().type_after_conversion() == cast_state_transitions.back().type_after_conversion();
}

TypecastAnalysis::TypecastAnalysis() {}

CastStateMap TypecastAnalysis::cast_instances(const Stmt &stmt) {
    CastStateMap cast_state_map;

    std::stack<Stmt> seen_stmts;
    std::unordered_set<PackedStmtId> seen_stmt_ids;

    seen_stmts.push(stmt);
    seen_stmt_ids.insert(stmt.id());

    while (!seen_stmts.empty()) {
        Stmt curr_stmt = seen_stmts.top();
        seen_stmts.pop();

        if (auto cast_expr = CastExpr::from(curr_stmt)) {

            // ignore conversions not happening between values
            bool skip_this_cast = false;
            for (const auto &elem : kNoneTypeCasts) {
                if (cast_expr->cast_kind() == elem) {
                    skip_this_cast = true;
                    break;
                }
            }
            if (skip_this_cast)
                continue;

            CastState state(*cast_expr);
            cast_state_map.insert(std::make_pair(cast_expr->id(), state));
        }

        for (Stmt child : curr_stmt.children()) {
            seen_stmts.push(child);
        }
    }
    return cast_state_map;
}

// For a reference of a data variable, determine all casting
TypecastChain TypecastAnalysis::forward_cast_chain(const VariantEntity &id) {
    TypecastChain chain(true);
    for (Reference ref : Reference::to(id)) {
        if (std::optional<BuiltinReferenceKind> ref_kind = ref.builtin_reference_kind()) {
            if (ref_kind == BuiltinReferenceKind::TYPE_CASTS) {
                VariantEntity ref_entity = ref.as_variant();
                if (const auto stmt = std::get_if<Stmt>(&ref_entity); stmt) {
                    if (auto cast_expr = CastExpr::from(*stmt)) {
                        CastState cast_state(*cast_expr);
                        chain.add_new_transition(cast_state);
                    }
                }
            }
        }
    }
    return chain;
}

TypecastChain TypecastAnalysis::backward_cast_chain(const VariantEntity &id) {
    TypecastChain chain(false);
    return chain;
}

} // namespace mx