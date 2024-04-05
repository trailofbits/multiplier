// By default, Clang will generate a class template specialization that is a
// definition when it comes across the `extern template class` below. That
// definition specialization will have a mixed set of source locations.

template <typename T>
class LexicalExternSpecialization {
    T x;
};

namespace dummy {}

extern template class LexicalExternSpecialization<char>;
