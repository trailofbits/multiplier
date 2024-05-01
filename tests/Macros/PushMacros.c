// This test case is derived from libc++.

#  define _LIBCPP_PUSH_MACROS _Pragma("push_macro(\"min\")") _Pragma("push_macro(\"max\")") _Pragma("push_macro(\"refresh()\")") _Pragma("push_macro(\"move(int, int)\")") _Pragma("push_macro(\"erase()\")")
#  define _LIBCPP_POP_MACROS _Pragma("pop_macro(\"min\")") _Pragma("pop_macro(\"max\")") _Pragma("pop_macro(\"refresh()\")") _Pragma("pop_macro(\"move(int, int)\")") _Pragma("pop_macro(\"erase()\")")


_LIBCPP_PUSH_MACROS
int PushMacros(void) {}
_LIBCPP_POP_MACROS
