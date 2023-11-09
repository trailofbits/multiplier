// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
#include "multiplier/Types.h"
#include <_types/_uint64_t.h>
#include <multiplier/Analysis/TypecastAnalysis.h>

#include <multiplier/Entities/ImplicitCastExpr.h>
#include <multiplier/Entities/BuiltinType.h>
#include <unordered_set>

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

    // for pointer-to-pointer conversions, do size check on the resolved type

    // get width-based changes
    std::optional<uint64_t> before_size_in_bits = type_before_conversion().size_in_bits();
    if (!before_size_in_bits) {
        // throw?
    }

    std::optional<uint64_t> after_size_in_bits = type_after_conversion().size_in_bits();
    if (!after_size_in_bits) {
        //throw?
    }

    if (before_size_in_bits > after_size_in_bits) {
        return CastBehavior::C_TYPE_WIDTH_DOWNCAST;
    } else if (before_size_in_bits < after_size_in_bits) {
        return CastBehavior::C_TYPE_WIDTH_UPCAST;
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

    // TODO: sign changes only happen on built-ins?
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


TypecastAnalysis::TypecastAnalysis(const Index &) {}

void TypecastAnalysis::cast_instances(const Fragment &fragment) {
    std::unordered_set<EntityId> seen_casts;

    // walk 
    for (CastExpr cast_expr : CastExpr::in(fragment)) {

        // make sure cast_expr's 

        if (seen_casts.contains(cast_expr.id())) {
            continue;
        }

        // filter on non-typecasting
    }
}

}