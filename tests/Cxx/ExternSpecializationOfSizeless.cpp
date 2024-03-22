namespace ExternSpecializationOfSizeless {

template <typename T>
class UsesSize {
  int Foo(void) {
    if constexpr (sizeof(T) == 1) {
      return 1;
    } else {
      return 0;
    }
  }
};

class Sizeless;

extern template class UsesSize<Sizeless>;


class Sizeless {};

int x = UsesSize<Sizeless>{}.Foo();

}