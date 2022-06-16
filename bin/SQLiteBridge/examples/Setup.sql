.load bin/SQLiteBridge/libsqlitebridge

INSERT INTO MultiplierConnection(name, host, port) VALUES ("default", "localhost", "50051");

CREATE VIRTUAL TABLE File              USING multiplier(File, default);
CREATE VIRTUAL TABLE RegexQuery        USING multiplier(RegexQuery, default);
CREATE VIRTUAL TABLE WeggliQuery       USING multiplier(WeggliQuery, default);
CREATE VIRTUAL TABLE Fragment          USING multiplier(Fragment, default);
CREATE VIRTUAL TABLE Reference         USING multiplier(Reference, default);
CREATE VIRTUAL TABLE Decl              USING multiplier(Decl, default);
CREATE VIRTUAL TABLE NamedDecl         USING multiplier(NamedDecl, default);
CREATE VIRTUAL TABLE Expr              USING multiplier(Expr, default);
CREATE VIRTUAL TABLE Stmt              USING multiplier(Stmt, default);
CREATE VIRTUAL TABLE CallExpr          USING multiplier(CallExpr, default);
CREATE VIRTUAL TABLE ImplicitCastExpr  USING multiplier(ImplicitCastExpr, default);
CREATE VIRTUAL TABLE Type              USING multiplier(Type, default);
CREATE VIRTUAL TABLE BuiltinType       USING multiplier(BuiltinType, default);
CREATE VIRTUAL TABLE CallExprArguments USING multiplier(CallExprArguments, default);