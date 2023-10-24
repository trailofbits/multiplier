
template <class _CharT>
struct char_traits;
template <>
struct char_traits<char>;

template <class _CharT, class _Traits>
class basic_string {
public:
    inline constexpr
    void __init(const char* __s, int __sz, int __reserve);
    inline constexpr
    void __init(const char* __s, int __sz);
    inline constexpr
    void __init(int __n, char __c);

};

template <class _CharT, class _Traits>
constexpr
void basic_string<_CharT, _Traits>::__init(const char* __s,
                                                       int __sz,
                                                       int __reserve) {}

template <class _CharT, class _Traits>
constexpr
void
basic_string<_CharT, _Traits>::__init(const char* __s, int __sz)
{
}

template <class _CharT, class _Traits>
constexpr
void
basic_string<_CharT, _Traits>::__init(int __n, char __c)
{
}

void test(void) {
    char *value = "abcd";
    basic_string<char, char_traits<char>> str;
    str.__init(value, 4);
}