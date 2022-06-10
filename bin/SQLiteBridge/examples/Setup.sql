.load bin/SQLiteBridge/libsqlitebridge
CREATE VIRTUAL TABLE File              USING multiplier(File, localhost, 50051);
CREATE VIRTUAL TABLE RegexQuery        USING multiplier(RegexQuery, localhost, 50051);
CREATE VIRTUAL TABLE WeggliQuery       USING multiplier(WeggliQuery, localhost, 50051);
CREATE VIRTUAL TABLE Fragment          USING multiplier(Fragment, localhost, 50051);
CREATE VIRTUAL TABLE Reference         USING multiplier(Reference, localhost, 50051);
CREATE VIRTUAL TABLE Decl              USING multiplier(Decl, localhost, 50051);
CREATE VIRTUAL TABLE NamedDecl         USING multiplier(NamedDecl, localhost, 50051);
CREATE VIRTUAL TABLE Expr              USING multiplier(Expr, localhost, 50051);
CREATE VIRTUAL TABLE Stmt              USING multiplier(Stmt, localhost, 50051);
CREATE VIRTUAL TABLE CallExpr          USING multiplier(CallExpr, localhost, 50051);
CREATE VIRTUAL TABLE ImplicitCastExpr  USING multiplier(ImplicitCastExpr, localhost, 50051);
CREATE VIRTUAL TABLE Type              USING multiplier(Type, localhost, 50051);
CREATE VIRTUAL TABLE BuiltinType       USING multiplier(BuiltinType, localhost, 50051);
CREATE VIRTUAL TABLE CallExprArguments USING multiplier(CallExprArguments, localhost, 50051);