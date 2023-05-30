
// This is a pretty evil case showing how the macro processor is really a
// token stream processor.
int NonTreeCallCallable(void) {
#define A B )(
#define B C(
#define C() D
#define D(x) x

  return A 2);
}
