
int VAArgsPasteInVAOpt(void) {
#define BAR(a, ...) a
#define FOO(...) BAR(1 __VA_OPT__(, ## __VA_ARGS__))
  return FOO(1, 2, 3);
}
