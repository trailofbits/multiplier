// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
#include "multiplier/Entities/CastExpr.h"
#include "multiplier/Entities/CompoundStmt.h"
#include "multiplier/Token.h"
#include "multiplier/Types.h"
#include <_types/_uint64_t.h>
#include <multiplier/Analysis/TypecastAnalysis.h>

#include <multiplier/Entities/ImplicitCastExpr.h>
#include <multiplier/Entities/BuiltinType.h>
#include <unordered_set>
#include <utility>
#include <iostream>

namespace mx {

CastState::CastState(const CastExpr &cast_expr) : cast_expr(cast_expr) {}

Type CastState::type_before_conversion() {
    return cast_expr.sub_expression().type()->canonical_type();
}

Type CastState::type_after_conversion() {
    std::optional<mx::Type> maybe_type_after = cast_expr.type();
    if (!maybe_type_after) {
        // throw?
    }
    return maybe_type_after->canonical_type();
}

CastBehavior CastState::get_cast_behavior() {
    Type type_before = type_before_conversion();
    Type type_after = type_after_conversion();

    bool pointer_convert = false;

    // for pointer-to-pointer conversions, do size check on the resolved type
    if (type_before.can_decay_to_pointer_type() && type_after.can_decay_to_pointer_type()) {
        type_before = type_before.desugared_type();
        type_after = type_after.desugared_type();
        pointer_convert = true;
    }

    // get width-based changes
    std::optional<uint64_t> before_size_in_bits = type_before.size_in_bits();
    if (!before_size_in_bits) {
        // throw?
    }

    std::optional<uint64_t> after_size_in_bits = type_after.size_in_bits();
    if (!after_size_in_bits) {
        //throw?
    }

    if (before_size_in_bits > after_size_in_bits) {
        if (pointer_convert) {
            return CastBehavior::C_PTR_TYPE_DOWNCAST;
        } else {
            return CastBehavior::C_TYPE_WIDTH_DOWNCAST;
        }
    } else if (before_size_in_bits < after_size_in_bits) {
        if (pointer_convert) {
            return CastBehavior::C_PTR_TYPE_UPCAST;
        } else {
            return CastBehavior::C_TYPE_WIDTH_UPCAST;
        }
    } else {
        return CastBehavior::NO_CAST_BEHAVIOR;
    }
}

bool CastState::is_implicit_cast() {
    if (auto implicit = ImplicitCastExpr::from(cast_expr)) {
        return true;
    }
    return false;
}

CastSignChange CastState::get_sign_change() {
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
    cast_state_transitions.push_back(cast_state);
}

bool TypecastChain::is_identity_preserving() {
    if (cast_state_transitions.empty())
        return true;
    return cast_state_transitions.front().type_after_conversion() == cast_state_transitions.back().type_after_conversion();
}

TypecastAnalysis::TypecastAnalysis(const Index &) {}

CastStateMap TypecastAnalysis::cast_instances(const Fragment &fragment) {
    CastStateMap cast_state_map;
    std::unordered_set<EntityId> seen_casts;
    for (CastExpr cast_expr : CastExpr::in(fragment)) {

        // make sure cast_exprs are top level

        if (seen_casts.contains(cast_expr.id())) {
            continue;
        }

        // filter on non-typecasting
    }
    return cast_state_map;
}

CastStateMap TypecastAnalysis::cast_instances(const Stmt &stmt) {
    CastStateMap cast_state_map;
    for (Stmt child_stmt : stmt.children()) {
        std::cout << child_stmt.id() << std::endl;
        std::cout << child_stmt.tokens().file_tokens() << std::endl;
        if (auto cast_expr = CastExpr::from(child_stmt)) {
            cast_state_map.insert(std::make_pair(cast_expr->id(), CastState(*cast_expr)));
        }
    }
    return cast_state_map;
}
} // namespace mx