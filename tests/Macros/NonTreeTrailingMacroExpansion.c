
// This craziness is inspired from Eric Niebler's concepts pre-processor
// library.
//
// Note the extra `)` at the end.
int NonTreeTrailingMacroExpansion(void) {
#define CPP_PP_LPAREN (
#define CPP_PP_EAT(...)
#define EVIL(l_paren) \
    CPP_PP_EAT l_paren \
    /**/
  return EVIL(CPP_PP_LPAREN) mwahahaha ) 1;
}
