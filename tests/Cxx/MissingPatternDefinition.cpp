namespace MissingPatternDefinition {

template <typename T>
class istreambuf_iterator {};

template <class _CharT, class _InputIterator>
class time_get {
public:
  typedef _CharT char_type;
  typedef _InputIterator iter_type;

  iter_type
  get(iter_type __b,
      iter_type __e,
      const char_type* __fmtb,
      const char_type* __fmte) const;
};

// time_get end primitives
template <class _CharT, class _InputIterator>
_InputIterator time_get<_CharT, _InputIterator>::get(
    iter_type __b,
    iter_type __e,
    const char_type* __fmtb,
    const char_type* __fmte) const {
        return {};
}

time_get<char, istreambuf_iterator<char>> time;

}
