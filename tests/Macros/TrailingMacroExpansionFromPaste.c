
// This test emulates various macros in the Linux kernel related to jump labels.

int TrailingMacroExpansionFromPaste(void) {
#define __ARG_PLACEHOLDER_1 0,
#define __take_second_arg(__ignored, val, ...) val
#define __and(x, y)     ___and(x, y)
#define ___and(x, y)      ____and(__ARG_PLACEHOLDER_##x, y)
#define ____and(arg1_or_junk, y)  __take_second_arg(arg1_or_junk y, 0)
#define __or(x, y)      ___or(x, y)
#define ___or(x, y)     ____or(__ARG_PLACEHOLDER_##x, y)
#define ____or(arg1_or_junk, y)   __take_second_arg(arg1_or_junk 1, y)
#define __is_defined(x)     ___is_defined(x)
#define ___is_defined(val)    ____is_defined(__ARG_PLACEHOLDER_##val)
#define ____is_defined(arg1_or_junk)  __take_second_arg(arg1_or_junk 1, 0)
#define IS_BUILTIN(option) __is_defined(option)
#define IS_MODULE(option) __is_defined(option##_MODULE)
#define IS_REACHABLE(option) __or(IS_BUILTIN(option), \
        __and(IS_MODULE(option), __is_defined(MODULE)))
#define IS_ENABLED(option) __or(IS_BUILTIN(option), IS_MODULE(option))

#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)

#define DEFINE_STATIC_KEY_TRUE(name) int name = 1
#define DEFINE_STATIC_KEY_FALSE(name) int name = 0

#define _DEFINE_STATIC_KEY_1(name)  DEFINE_STATIC_KEY_TRUE(name)
#define _DEFINE_STATIC_KEY_0(name)  DEFINE_STATIC_KEY_FALSE(name)
#define DEFINE_STATIC_KEY_MAYBE(cfg, name)      \
  __PASTE(_DEFINE_STATIC_KEY_, IS_ENABLED(cfg))(name)

#define CONFIG_INIT_ON_FREE_DEFAULT_ON y

  DEFINE_STATIC_KEY_MAYBE(CONFIG_INIT_ON_FREE_DEFAULT_ON, enabled);
  DEFINE_STATIC_KEY_MAYBE(CONFIG_INIT_ON_FREE_DEFAULT_OFF, disabled);

  return enabled + disabled;
}
