namespace PartialOrdering {
class partial_ordering {};
class weak_ordering {};
class strong_ordering {};

template <class _Tp, class _Up>
inline constexpr bool is_same_v = __is_same(_Tp, _Up);

enum _ClassifyCompCategory : unsigned {
  _None,
  _PartialOrd,
  _WeakOrd,
  _StrongOrd,
  _CCC_Size
};

template <class _Tp>
__attribute__((__visibility__("hidden"))) __attribute__((__exclude_from_explicit_instantiation__)) __attribute__((__abi_tag__("v160006")))
constexpr _ClassifyCompCategory __type_to_enum() noexcept {
  if (is_same_v<_Tp, partial_ordering>)
    return _PartialOrd;
  if (is_same_v<_Tp, weak_ordering>)
    return _WeakOrd;
  if (is_same_v<_Tp, strong_ordering>)
    return _StrongOrd;
  return _None;
}
}