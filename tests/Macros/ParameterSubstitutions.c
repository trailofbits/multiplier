
// For this test, we want to ensure that we can see that the macro parameter
// `c` is substituted with `"c"`, `b` with `"b"`, and `a` with `"a"`. This is
// tricky because we have to rely on a few different heuristics to get at this
// type of info.

int main(void) {
#define PARAMS(a, b, c) c b a
  return (PARAMS("a", "b", "c"))[0];
}
