// Tests: variadic function handling (VA_START, VA_END, VA_COPY,
// CONSUME_VA_PARAM via MEMORY sub-opcode), va_arg with different types.

#include <stdarg.h>

static int va_sum(int count, ...) {
    va_list ap;
    va_start(ap, count);
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(ap, int);
    }
    va_end(ap);
    return total;
}

static int va_first_int(int dummy, ...) {
    va_list ap;
    va_start(ap, dummy);
    int result = va_arg(ap, int);
    va_end(ap);
    return result;
}

static double va_sum_doubles(int count, ...) {
    va_list ap;
    va_start(ap, count);
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total;
}

static int va_copy_test(int count, ...) {
    va_list ap, ap2;
    va_start(ap, count);

    // Read first element.
    int first = va_arg(ap, int);

    // Copy va_list and read from copy.
    va_copy(ap2, ap);
    int second_from_copy = va_arg(ap2, int);
    va_end(ap2);

    // Read from original (should give same second element).
    int second_from_orig = va_arg(ap, int);

    va_end(ap);
    return first + second_from_copy + second_from_orig;
}

int test_variadics(void) {
    // Basic variadic sum.
    int s1 = va_sum(3, 10, 20, 30);
    if (s1 != 60) return 1;

    // Single variadic arg.
    int s2 = va_sum(1, 42);
    if (s2 != 42) return 2;

    // Zero variadic args.
    int s3 = va_sum(0);
    if (s3 != 0) return 3;

    // First int extraction.
    int first = va_first_int(0, 99);
    if (first != 99) return 4;

    // va_copy: first=10, second=20, result = 10 + 20 + 20 = 50.
    int copy_result = va_copy_test(3, 10, 20, 30);
    if (copy_result != 50) return 5;

    return 0;
}
