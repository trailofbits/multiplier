
// 1
template <typename T>
struct a {
};
extern template class a<int>;

// 2
template <typename T>
struct b {
};
extern template class b<int>;
b<int> bi;

// 3
template <typename T>
struct c {
  void f() {}
};
extern template class c<int>;
c<int> ci;

//
template <typename T>
struct d {
  void f();
};
extern template class d<int>;
d<int> di;

//
template <typename T>
struct e {
  void f();
};
template <typename T>
void e<T>::f() {
}
extern template class e<int>;
e<int> ei;

//
template <typename T>
struct g {
  void f();
};
template <>
void g<int>::f();
extern template class g<int>;
g<int> gi;

template <typename T>
struct h {
};
template class h<int>;

template <typename T>
struct i {
  void f() {}
};
template<> void i<int>::f();
extern template class i<int>;
i<int> ii;

template <typename T1, typename T2 = T1>
struct j {
};
extern template class j<int>;
j<int> jj;
template <typename T>
struct j_wrap {
};
j_wrap<j<int>> j_wrap_j;


template <typename T>
struct k {
};
template <>
struct k<int>;
template struct k<int>;

