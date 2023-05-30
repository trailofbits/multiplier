const char *StringifyGNUVarArgs(void) {
#define __stringify_1(x...) #x
#define __stringify(x...) __stringify_1(x)
#define __percpu_seg    gs
  return __stringify(__percpu_seg);
}
