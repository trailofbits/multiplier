
// Check that `#pragma` directives are retained across pre-processing.
void PragmasAreRetained(void) {
#pragma pack(push, 1)
  struct foo {
    unsigned char id;
    unsigned int version;
  };
  _Static_assert(sizeof(struct foo) == 5, "Not 5");
#pragma pack(pop)
}
