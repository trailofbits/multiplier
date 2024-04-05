template<typename X>
class SplitToken {};

using Split1 = SplitToken<SplitToken<int>>;
using Split2 = SplitToken<SplitToken<SplitToken<int>>>;
using Split3 = SplitToken<SplitToken<SplitToken<SplitToken<int>>>>;
using Split4 = SplitToken<SplitToken<SplitToken<SplitToken<SplitToken<int>>>>>;
using Split5 = SplitToken<SplitToken<SplitToken<SplitToken<SplitToken<SplitToken<int>>>>>>;

template <>
class SplitToken<SplitToken<int>> {};

struct Operator {
  template <typename T>
  T operator<<(T x) { return x; };
};

int x = Operator{}.operator<<<int>(1);