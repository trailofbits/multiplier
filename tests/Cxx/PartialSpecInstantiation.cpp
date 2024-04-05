
// Template partial specialization instantiation
namespace PartialSpecInstantiation {
template <class T> struct X {};

template <> struct X<char>
{
  static char* g();
};

template <class T> struct X2 {};

template <class U>
struct X2<U*> {
  static void f() {
    X<U>::g();
  }
};

void a(char *a, char *b) {X2<char*>::f();}

namespace _1 {
  template<typename T>
  struct X {
    int m;
  };

  template<typename U>
  class Y;

  template<typename U>
  struct Y<U*> : X<U> {};

  template<>
  struct Y<float*> : X<float> {};

  int f(Y<int*> y, Y<float*> y2) {
    return y.m + y2.m;
  }
}

namespace _2 {
  template <typename T, typename U>
  struct enable_if_not_same
  {
    typedef void type;
  };

  template <typename T>
  struct enable_if_not_same<T, T>;

  template <typename T>
  struct Wrapper {
    template <class U>
    Wrapper(const Wrapper<U>& other,
            typename enable_if_not_same<U, T>::type* = 0) {}
    explicit Wrapper(int i) {}
  };


  template <class T>
  struct Container {
    Container() : x() {}
    template <class U>
    Container(const Container<U>& other) : x(static_cast<T>(other.x)) {}
    T x;
  };

  void takesWrapperInContainer(const Container<Wrapper<int>> &c) {(void)c;}
  void test() {
    Container<int> c;
    takesWrapperInContainer(c);
  }
}
} // namespace PartialSpecInstantiation