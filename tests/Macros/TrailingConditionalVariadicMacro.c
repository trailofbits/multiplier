
// This tests a `dprintk`-type issue that we've observed in the Linux kernel.

void TrailingConditionalVariadicMacro(void) {
  extern void _printk(const char *, ...);

  int debug = 1;
#define printk_index_wrap(_p_func, _fmt, ...) \
    ({ _p_func(_fmt, ##__VA_ARGS__); })

#define printk(fmt, ...) printk_index_wrap(_printk, fmt, ##__VA_ARGS__)
#define dprintk if (debug) printk
#define BAR(...) __VA_OPT__(,)
#define FOO BAR
  dprintk("Hello from %s:%s:%u", __func__ FOO(a) __FILE__, __LINE__);
}
