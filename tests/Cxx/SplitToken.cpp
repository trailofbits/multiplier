namespace SplitToken {

template<typename X>
class ST {};

using Split1 = ST<ST<int>>;
using Split2 = ST<ST<ST<int>>>;
using Split3 = ST<ST<ST<ST<int>>>>;
using Split4 = ST<ST<ST<ST<ST<int>>>>>;
using Split5 = ST<ST<ST<ST<ST<ST<int>>>>>>;

template <>
class ST<ST<int>> {};

struct Operator {
  template <typename T>
  T operator<<(T x) { return x; };
};

int SplitToken_x = Operator{}.operator<<<int>(1);

}