template<typename T> struct A { A(); A(T); };
A() -> A<int>;