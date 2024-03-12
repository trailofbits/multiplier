namespace TemplateSpecialization {
struct A {
  template <typename T>
  static void bar(int) { }
};

struct B {
  template <int i>
  static void foo() {
    int array[i];
    A::template bar(array[0]);
  }
};

int main() {
  B::foo<4>();
  return 0;
}
} // namespace TemplateSpecialization