namespace ReaderGetAs {
template <typename T>
struct ReaderFor {};

struct AnyPointer {
  class Reader {
  public:
    template <typename T>
    inline ReaderFor<T> getAs() const;
  };
};

int main() {
  AnyPointer::Reader r;
  r.getAs<int>();
  return 0;
}

template <typename T>
inline ReaderFor<T> AnyPointer::Reader::getAs() const {
  return {};
}
}