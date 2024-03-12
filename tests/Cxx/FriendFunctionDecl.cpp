namespace FriendFunctionDecl {
class _char {};

template<class T>
class _traits{};

class Alloc{};

template<class _CharT, class _Traits, class _Allocator>
class basic_string
{
  public:
    inline ~basic_string();

  friend basic_string operator+(const basic_string&, const basic_string&);
};

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>::~basic_string() {}

basic_string<_char, _traits<char>, Alloc> operator+(
    const basic_string<_char, _traits<char>, Alloc>&,
    const basic_string<_char, _traits<char>, Alloc>&) {
      return {};
}

void test(void) {
    basic_string<_char, _traits<char>, Alloc> str;
}
} // namespace FriendFunctionDecl