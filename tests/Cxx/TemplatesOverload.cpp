namespace __7 {

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

void test(void) {
  __7::bar1.func(10);
}



