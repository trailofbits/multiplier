template <class _T1, class _T2>
struct pair {
    pair(_T1, _T2) { };
};

template<class _T1, class _T2>
pair(_T1, _T2) -> pair<_T1, _T2>;

int test(void) {
    auto p = pair(1, 2);
    return 0;
}
