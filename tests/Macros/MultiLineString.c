
// This test tests our ability to fixup multi-line strings in macros.

int MultiLineString(void) {
#define pr(...) __VA_ARGS__
  return pr("hello\n\
world")[0];
}
