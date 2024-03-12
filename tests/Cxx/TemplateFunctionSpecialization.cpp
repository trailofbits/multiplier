namespace TemplateFunctionSpecialization {
template <typename T> T Max(T x, T y)
{
  return (x > y) ? x : y;
}

void test_max(void) {
  auto max = Max(3, 5);
  (void)max;
}

namespace mc {

const float b = 3.14;
float value(int r) {
  return b*r*r;
}

}

int test_pi(void) {
  float val = mc::value(2);
  (void)val;
  return 0;
}
} // namespace TemplateFunctionSpecialization
