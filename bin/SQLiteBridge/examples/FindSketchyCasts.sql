
CREATE VIRTUAL TABLE File              USING multiplier(File, localhost, 50051);
CREATE VIRTUAL TABLE Fragment          USING multiplier(Fragment, localhost, 50051);
CREATE VIRTUAL TABLE Reference         USING multiplier(Reference, localhost, 50051);
CREATE VIRTUAL TABLE Decl              USING multiplier(Decl, localhost, 50051);
CREATE VIRTUAL TABLE Expr              USING multiplier(Expr, localhost, 50051);
CREATE VIRTUAL TABLE Stmt              USING multiplier(Expr, localhost, 50051);
CREATE VIRTUAL TABLE CallExpr          USING multiplier(CallExpr, localhost, 50051);
CREATE VIRTUAL TABLE ImplicitCastExpr  USING multiplier(ImplicitCastExpr, localhost, 50051);
CREATE VIRTUAL TABLE CastExpr          USING multiplier(CastExpr, localhost, 50051);
CREATE VIRTUAL TABLE Type              USING multiplier(Type, localhost, 50051);
CREATE VIRTUAL TABLE BuiltinType       USING multiplier(BuiltinType, localhost, 50051);
CREATE VIRTUAL TABLE CallExprArguments USING multiplier(CallExprArguments, localhost, 50051);

--JOIN CastExpr AS casts ON casts.fragment_id = fragment.id
SELECT call_expr.id, cast_expr.cast_kind_name, source_type.builtin_kind AS source, dest_type.builtin_kind AS dest FROM File
JOIN Fragment AS fragment ON File.id = fragment.file_id
JOIN CallExpr AS call_expr ON call_expr.fragment_id = fragment.id
JOIN CallExprArguments AS argument ON argument.parent_id = call_expr.id
JOIN CastExpr AS cast_expr ON cast_expr.id = argument.value
JOIN ImplicitCastExpr AS implicit_cast ON implicit_cast.id = cast_expr.id
JOIN Expr AS sub_expr ON sub_expr.id = cast_expr.sub_expression
JOIN Type AS sub_type ON sub_type.id = sub_expr.type
JOIN Expr AS cast_expr_down ON cast_expr_down.id = cast_expr.id
JOIN BuiltinType AS source_type ON source_type.id = sub_type.canonical_type
JOIN BuiltinType AS dest_type ON dest_type.id = cast_expr_down.type
WHERE cast_expr.cast_kind_name = "IntegralCast"
    AND NOT implicit_cast.is_part_of_explicit_cast
    AND (source_type.builtin_kind = 176 OR source_type.builtin_kind = 175)
    AND dest_type.builtin_kind = 182;

SELECT Stmt.*
FROM File, Fragment, Decl, Reference, Stmt
WHERE Fragment.file_id = File.id
AND Decl.fragment_id = Fragment.id
AND Reference.use_id = Decl.id
AND Stmt.id = Reference.user_id;
