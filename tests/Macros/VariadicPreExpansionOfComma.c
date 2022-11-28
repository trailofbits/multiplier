extern int printf(const char *, ...);

int VariadicPreExpansionOfComma() {
#define printf_to_stdout(a, ...)  printf(a __VA_OPT__(,) __VA_ARGS__)
#define exp(a,b) ,
#define annoying(comma) "a" exp comma "b"
  return printf_to_stdout(annoying((,)));
}
