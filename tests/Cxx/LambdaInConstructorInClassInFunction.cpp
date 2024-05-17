namespace LambdaInConstructorInClassInFunction {

void Function(void) {
  struct Class {
    Class(void) {
      auto x = [] () {

      };
    }
  };
}

}  // namespace LambdaInConstructorInClassInFunction
