// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
#include <multiplier/Analysis/TypeAnalysis.h>

namespace mx {

TypecastAnalysis::TypecastAnalysis(const Index &) {}

void TypecastAnalysis::cast_instances(const Fragment &fragment) {
    for (CastExpr cast_expr : CastExpr::in(fragment)) {

        // Skip on non-type casts TODO
        if (cast_expr.cast_kind() == CastKind::FUNCTION_TO_POINTER_DECAY) {
            continue;
        }

        // get types and recover properties
        Type type_before = cast_expr.sub_expression().type()->canonical_type();
        std::optional<mx::Type> maybe_type_after = cast_expr.type();
        if (!maybe_type_after) {
            continue;
        }
        mx::Type type_after = maybe_type_after->canonical_type();

        // is this cast implicit?
        bool is_implicit_cast = false;
        if (auto implicit = ImplicitCastExpr::from(cast_expr)) {
            is_implicit_cast = true;
        }
    }
}

}