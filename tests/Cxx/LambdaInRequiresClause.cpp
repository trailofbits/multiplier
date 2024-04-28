namespace LambdaInRequiresClause {

template <typename T>
class Optional {};

class Bar : public Optional<int> {};

template <class _Tp>
concept IsDerivedFromOptional = requires(const _Tp& __t) { []<class _Up>(const Optional<_Up>&) {}(__t); };

template <typename X>
requires(IsDerivedFromOptional<X>)
void Foo(const X &) {}

int main() {
  Bar x;
  Foo(x);
  return 0;
}

}  // namespace LambdaInRequiresClause
