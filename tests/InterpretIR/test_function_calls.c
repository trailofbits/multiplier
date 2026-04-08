// Tests: function calls (CALL), parameter passing (PARAM_READ + STORE),
// return values, recursive calls, indirect calls via function pointers
// (FUNC_PTR), and variadic functions (VA_PACK, VA_START, VA_ARG, VA_END).

#include <stdarg.h>

static int add(int a, int b) {
    return a + b;
}

static int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

static int apply(int (*fn)(int, int), int x, int y) {
    return fn(x, y);
}

static int va_sum(int count, ...) {
    va_list ap;
    va_start(ap, count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(ap, int);
    }
    va_end(ap);
    return sum;
}

int test_function_calls(void) {
    // Direct call.
    if (add(3, 4) != 7) return 1;

    // Recursive call.
    if (factorial(5) != 120) return 2;

    // Function pointer (indirect call).
    int (*fp)(int, int) = add;
    if (fp(10, 20) != 30) return 3;

    // Higher-order function.
    if (apply(add, 5, 6) != 11) return 4;

    // Variadic call.
    if (va_sum(3, 10, 20, 30) != 60) return 5;

    return 0;
}
