
// In this test, we trigger macro expansion cancellation of the `_Pragma`
// because the `_Pragma` is being expanded during the macro pre-argument
// expansion phase.

void PragmaCancellation() {
#define MACRO(...) __VA_ARGS__
MACRO(_Pragma("clang diagnostic push"))
}
