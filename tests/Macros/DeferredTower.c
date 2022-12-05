
// In this test case, we have a tower of deferred expansions, which require
// a cascade of tree rotations in PASTA.

int DeferredTower(void) {
#define ONE TWO
#define TWO THREE
#define THREE FOUR
#define FOUR(five) five
  return ONE(5);
}
