
// This tests the bounds on an empty function-like macro that has parameters.

int EmptyFunctionMacroWithParams(void) {
#define EMPTY(a, b)
  return EMPTY(1, 2) 0;
}
