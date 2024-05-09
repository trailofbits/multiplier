namespace AutoDeduce {
template <typename T>
auto add(T a, T b) {
    return a + b;
}

void test() {
    // Example usage with integers
    auto result_int = add(3, 5);
    (void)result_int;

    // Example usage with floating-point numbers
    auto result_float = add(3.5, 2.5);
    (void)result_float;
}

}