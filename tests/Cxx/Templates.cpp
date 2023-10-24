
namespace __1 {
// Out-Of-Line Method definition getting instantiated
template <typename T>
class Foo {
 public:
  void Bar(T x);
};

template <typename U>
void Foo<U>::Bar(U x) {
  x = 0;
}

Foo<int> x;

void test() {
  x.Bar(0);
}

}

namespace __2 {
// Out-Of-Line Method definition not instantiated
template <typename T>
class Foo {
 public:
  void Bar(T x);
};

template <typename U>
void Foo<U>::Bar(U x) {
  x = 0;
}

Foo<int> x;
}

namespace __3 {
// Implicit definition of method gets instantiated
template <typename T>
class Foo {
 public:
  void Bar(T x) {
    x = 0;
  }
};

Foo<int> x;

void test() {
  x.Bar(0);
}

}

namespace __4 {
// Implicit definition of method not instantiated
template <typename T>
class Foo {
 public:
  void Bar(T x) {
    x = 0;
  }
};

Foo<int> x;

}

namespace __5 {
template <typename A>
class Foo {
    public:
    template <typename T>
    class Bar;
};

template <typename A>
template<typename T>
class Foo<A>::Bar {
    public:
      int func(int) {
        return 0;
      }
};

Foo<int> bar;

}


namespace __6 {
template <typename A>
class Foo {
    public:
    template <typename T>
    class Bar;
};

template <typename A>
template<typename T>
class Foo<A>::Bar {
    public:
      int func(T x);
};

template <typename A>
template<typename T>
int Foo<A>::Bar<T>::func(T x) {
    return x;
}

Foo<int> bar;
Foo<int>::Bar<int> bar1;

}


/*template <typename... T>
void f1() {}

template <typename T, T V>
void f2() {}

template <typename... T>
struct t1 {};

extern int x;
int x;
struct t2 {
  template <typename T = float>
  operator t1<int>() { __builtin_unreachable(); }
};

template <template <typename...> class T>
void f3() {}
namespace {
enum LocalEnum { LocalEnum1 };
}

template<typename T, T ... ts>
struct t3 { };
struct t4 {
  t3<LocalEnum, LocalEnum1> m1;
};

t4 v1;
enum { UnnamedEnum1 };
template<decltype(UnnamedEnum1)>
void f4() {}

void f() {
  f1<>();
  f1<int>();
  f1<void()>();
  f2<int, 42>();
  f1<t1<void() noexcept>>();
  f1<__attribute__((__vector_size__((sizeof(int) * 2)))) int>();
  f1<void() noexcept>();

  auto Lambda = [] {};
  f1<decltype(Lambda)>();
  f1<t1<t1<decltype(Lambda)>>>();

  struct {} unnamed_struct;
  f1<decltype(unnamed_struct)>();
  f1<void (decltype(unnamed_struct))>();

  enum {} unnamed_enum;
  f1<decltype(unnamed_enum)>();

  f2<int *, &x>();
  f2<decltype(nullptr), nullptr>();
  f2<__int128, ((__int128)9223372036854775807) * 2>();

  t2().operator t1<int>();

  f3<t1>();

  int fnrt() __attribute__((noreturn));
  f1<decltype(fnrt)>();
  f4<UnnamedEnum1>();
}*/
