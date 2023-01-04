
// This test checks that we properly handle empty directives. This is something
// that we observe in SQLite's `shell.c` near its `utf8_to_utf16` function.

void EmptyDirective(void) {
#if 0
#
# /* comment */
#endif
}
