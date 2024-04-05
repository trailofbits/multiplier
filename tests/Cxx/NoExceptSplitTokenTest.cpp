namespace NoExceptSplitTokenTest {

#define _GLIBCXX_NOEXCEPT_IF(...) noexcept(__VA_ARGS__)

template <typename _Tp>
struct type_var {};

template<typename _Tp>
struct is_nothrow_move_constructible {};

template<typename _Tp>
struct is_nothrow_move_assignable {};

template<typename _Tp1, typename _Tp2>
struct __and_ {
    static constexpr bool value = true;
};

template<typename _Tp>
struct __swap_result_t {};

template<typename _Tp>
inline
constexpr __swap_result_t<_Tp>
swap(_Tp& __a, _Tp& __b) _GLIBCXX_NOEXCEPT_IF(__and_<is_nothrow_move_constructible<_Tp>, is_nothrow_move_assignable<type_var<_Tp>>>::value)
{
}

void test() {
    int a1 = 5, b1 = 10;
    swap(a1, b1);
}

}