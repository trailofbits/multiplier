
// In this test, we have a sequence of deferrals, one after the other.
int DeferredSequence(void) {
#define ONE(two) two
#define TWO(three) three
#define THREE(four) four
#define FOUR(five) five
  return ONE(TWO)(THREE)(FOUR)(5);
}
