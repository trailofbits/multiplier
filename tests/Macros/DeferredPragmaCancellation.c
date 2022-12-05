
// In this test, we trigger macro expansion cancellation of the `_Pragma`
// because the `_Pragma` is being expanded during the macro pre-argument
// expansion phase. What is unique about this test is that the `_Pragma`
// expansion is cancelled, but the expansion of `PRAGMA` to `_Pragma` and
// `DATA` to `"clang diagnostic push"` must be retained, as those tokens
// are later re-injected.

void DeferredPragmaCancellation() {
#define PRAGMA _Pragma
#define DATA "clang diagnostic push"
#define MACRO(...) __VA_ARGS__
MACRO(PRAGMA(DATA))
}
