// This test is derived from `mkshelllinkc` from ReactOS. We observed an issue
// with the whitespace between the `#pragma pop` and the `int main`.

#pragma pack(push, 1)

/* Specification: ... */

typedef struct X {} X;

#pragma pack(pop)

int WhitespaceAfterPragma() {
  return 0;
}
