
// Here we have a deferred macro expansion resulting from a token concatenation.
// Deferred expansion for us looks like the expansion of `ONE` ending inside
// the middle of the expansion of `TWO`. This happens because Clang will do the
// token concatenation of `T` and `WO` forming `TWO`, identify that it's a
// function-like macro, then try to lex the opening parenthesis. In doing so,
// it will hit `eof` in the current token lexer for the macro expansion of
// `ONE`, and that is how we observe the unusual out-of-order events, which
// require tree-rotation in PASTA.

int DeferredExpansionFromConcatenation() {
#define ONE(two) two
#define TWO(zero) zero
#define ZERO(t, wo) ONE(t ## wo)(0)
  return ZERO(T, WO);
}
