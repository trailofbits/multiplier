
// This tests the bounds on an empty function-like macro

int EmptyFunctionMacro(void) {
#define EMPTY()
  return EMPTY() 0;
}
