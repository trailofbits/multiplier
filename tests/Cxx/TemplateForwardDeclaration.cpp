
template <class A> class Derived;

template <class A> class Base {
  static Derived<A> *create();
};

template <class A> struct Derived : Base<A> {
};

Base<int> *f;

Derived<int> d;
