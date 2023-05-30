
// This is a pretty evil case showing how the macro processor is really a
// token stream processor.
int NonTreeCallCallableCrazy(void) {
#define L_PAREN (
#define R_PAREN )
#define A(r_paren, l_paren) B(L_PAREN) r_paren l_paren
#define B(l_paren) C l_paren
#define C() D
#define D(x) x

  return A(R_PAREN, L_PAREN) 2 );
}
