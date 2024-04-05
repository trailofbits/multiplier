namespace AutoDeducedMemberExpr {
template <typename T>
class Class {
 public:
  template <typename U>
  auto blah(U x) {
    return x;
  }
};

auto x() {
  return Class<int>().blah(Class<int>()).blah(2.0);
}

}