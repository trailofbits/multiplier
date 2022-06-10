SELECT DISTINCT
    decl.id                  as decl_id,
    call_expr.id             as call_id,
    sub_expr.id              as sub_id,
    source_type.builtin_kind as source_type,
    dest_type.builtin_kind   as dest_type
FROM Decl decl
JOIN Reference AS ref ON ref.use_id = decl.id
JOIN CallExpr AS call_expr ON containing(call_expr.id, ref.user_id)
JOIN CallExprArguments AS argument ON argument.parent_id = call_expr.id
JOIN ImplicitCastExpr AS cast_expr ON cast_expr.id = argument.value
JOIN Expr AS sub_expr ON sub_expr.id = cast_expr.sub_expression
JOIN Type AS sub_type ON sub_type.id = sub_expr.type
JOIN BuiltinType AS source_type ON source_type.id = sub_type.canonical_type
JOIN BuiltinType AS dest_type ON dest_type.id = cast_expr.type
WHERE cast_expr.cast_kind_name = "IntegralCast"
    AND NOT cast_expr.is_part_of_explicit_cast
    AND (source_type.builtin_kind = BuiltinTypeKind("U_LONG") OR source_type.builtin_kind = BuiltinTypeKind("U_LONG_LONG"))
    AND dest_type.builtin_kind = BuiltinTypeKind("INT");
