
// This test uses C99 variadic arguments `__VA_ARGS__` and also does a token
// paste with them, using the `, ## __VA_ARGS__` pattern.

extern int log_func(int level, const char *file, int line,
                     const char *func, const char *fmt, ...);

int C99VarArgsTokenPaste(void) {
#define LEVEL 0
#define FMT "hi"
#define FILENAME __FILE_NAME__
#define sc_log(a, b, args...) \
    log_func(a, FILENAME, __LINE__, __FUNCTION__, b, ##__VA_ARGS__)

  return sc_log(LEVEL, FMT);
}
