namespace TemplatePartialSpecialization {
template <class _Tp, class _Dp, bool > struct __pointer_type1 {};

template <class _Tp, class _Dp> struct __pointer_type1<_Tp, _Dp, false>
{
  typedef _Tp* type;
};

template <class _Tp, class _Dp>
struct __pointer_type2
{
  typedef typename __pointer_type1<_Tp, _Dp, false>::type type;
};

template <class _Tp> struct default_delete {};
template <class _Tp, class _Dp = default_delete<_Tp> > class unique_ptr
{
  typedef typename __pointer_type2<_Tp, _Dp>::type pointer;
  unique_ptr(pointer __p, _Dp __d) {}
};

class C {
  unique_ptr<C> Ptr;
};

void foo(C &c) {}
} // namespace TemplatePartialSpecialization
