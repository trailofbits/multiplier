
// This test checks that we properly handle `defined`, which can optionally
// has parentheses.
void Defined(void) {
#if defined X
#endif
#if defined(X)
#endif
}

