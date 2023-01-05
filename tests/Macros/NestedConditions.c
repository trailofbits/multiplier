
// This test checks that we properly handle nested conditionals.

void NestedMacroConditionsOffNoElse(void) {
#if defined(NOT_DEFINED_ANYWHERE)
# if defined(__clang__)
  return;
# endif
#endif
}

void NestedMacroConditionsWithElse(void) {
#if defined(NOT_DEFINED_ANYWHERE)
# if defined(__clang__)
  return;
# endif
#else
  return;
#endif
}

void NestedMacroConditionsWithElseNestedOff(void) {
#if defined(NOT_DEFINED_ANYWHERE)
# if defined(__clang__)
  return;
# endif
#else
#  if defined(NOT_DEFINED_ANYWHERE)
  return;
#  endif
#endif
}

void NestedMacroConditionsWithElseNestedOn(void) {
#if defined(NOT_DEFINED_ANYWHERE)
# if defined(__clang__)
  return;
# endif
#else
#  if defined(__clang__)
  return;
#  endif
#endif
}

void NestedMacroConditionsOnNoElse(void) {
#if defined(__clang__)
# if defined(__clang__)
  return;
# endif
#endif
}

void NestedMacroConditionsOnNoElseNestedOffNoElse(void) {
#if defined(__clang__)
# if defined(NOT_DEFINED_ANYWHERE)
  return;
# endif
#endif
}

void NestedMacroConditionsOnNoElseNestedOffWithElse(void) {
#if defined(__clang__)
# if defined(NOT_DEFINED_ANYWHERE)
  return;
# else
  return;
# endif
#endif
}

void NestedMacroConditionsOnNoElseNestedOnWithElse(void) {
#if defined(__clang__)
# if defined(__clang__)
  return;
# else
  return;
# endif
#endif
}

void NestedMacroConditionsOnWithElse(void) {
#if defined(__clang__)
# if defined(__clang__)
  return;
# endif
#else
  return;
#endif
}

void NestedMacroConditionsOnWithElseNestedOffNoElse(void) {
#if defined(__clang__)
# if defined(NOT_DEFINED_ANYWHERE)
  return;
# endif
#else
  return;
#endif
}

void NestedMacroConditionsOnWithElseNestedOffWithElse(void) {
#if defined(__clang__)
# if defined(NOT_DEFINED_ANYWHERE)
  return;
# else
  return;
# endif
#else
  return;
#endif
}

void NestedMacroConditionsOnWithElseNestedOnWithElse(void) {
#if defined(__clang__)
# if defined(__clang__)
  return;
# else
  return;
# endif
#else
  return;
#endif
}
