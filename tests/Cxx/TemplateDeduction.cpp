
// Template deduce specialization
namespace TemplateDeduction {
template <class T>
struct S {
  S(T) {}
};

S<int> s2(40);

template<typename ...T> struct X {};

template<typename T, typename U> struct P {};

namespace _1 {

template<typename ...T> int f1(X<T, T...>... a);
template<typename ...T> int f2(P<X<T...>, T> ...a);

int a1 = f1(X<int, int, double>(), X<double, int, double>());
int a2 = f1(X<int, int>());
int b1 = f2(P<X<int, double>, int>(), P<X<int, double>, double>());
}
} // namespace TemplateDeduction