namespace MixingMethodBounds {

class ReturnType {
 public:
  constexpr bool ReturnBool() { return true; }
};

class Class {
 public:
  template<typename T>
  constexpr static ReturnType Method();

  static bool Method2() {
    return Method<int>().ReturnBool();
  }
};

bool x = Class::Method2();

template<typename T>
constexpr ReturnType Class::Method() {
  return {};
}

}
