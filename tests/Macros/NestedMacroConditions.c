
// This test checks that we properly handle nested conditionals.

void NestedConditionsOffNoElse(void) {
#if 0
# if 1
  return;
# endif
#endif
}

void NestedConditionsWithElse(void) {
#if 0
# if 1
  return;
# endif
#else
  return;
#endif
}

void NestedConditionsWithElseNestedOff(void) {
#if 0
# if 1
  return;
# endif
#else
#  if 0
  return;
#  endif
#endif
}

void NestedConditionsWithElseNestedOn(void) {
#if 0
# if 1
  return;
# endif
#else
#  if 1
  return;
#  endif
#endif
}

void NestedConditionsOnNoElse(void) {
#if 1
# if 1
  return;
# endif
#endif
}

void NestedConditionsOnNoElseNestedOffNoElse(void) {
#if 1
# if 0
  return;
# endif
#endif
}

void NestedConditionsOnNoElseNestedOffWithElse(void) {
#if 1
# if 0
  return;
# else
  return;
# endif
#endif
}

void NestedConditionsOnNoElseNestedOnWithElse(void) {
#if 1
# if 1
  return;
# else
  return;
# endif
#endif
}

void NestedConditionsOnWithElse(void) {
#if 1
# if 1
  return;
# endif
#else
  return;
#endif
}

void NestedConditionsOnWithElseNestedOffNoElse(void) {
#if 1
# if 0
  return;
# endif
#else
  return;
#endif
}

void NestedConditionsOnWithElseNestedOffWithElse(void) {
#if 1
# if 0
  return;
# else
  return;
# endif
#else
  return;
#endif
}

void NestedConditionsOnWithElseNestedOnWithElse(void) {
#if 1
# if 1
  return;
# else
  return;
# endif
#else
  return;
#endif
}
