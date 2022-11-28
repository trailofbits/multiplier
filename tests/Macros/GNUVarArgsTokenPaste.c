
// This test uses GNU named varargs (`args...`) and also does a token paste
// with them, using the `, ## args` pattern.

extern int log_func(int level, const char *file, int line,
                     const char *func, const char *fmt, ...);

int GNUVarArgsTokenPaste(void) {
#define LEVEL 0
#define FMT "hi"
#define FILENAME __FILE_NAME__
#define sc_log(a, b, args...) \
    log_func(a, FILENAME, __LINE__, __FUNCTION__, b, ##args)

  return sc_log(LEVEL, FMT);
}
