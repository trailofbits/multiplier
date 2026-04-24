#include <stdint.h>

int symbolic_test_add_overflow_i8(int8_t a, int8_t b) {
    int8_t result;
    return __builtin_add_overflow(a, b, &result);
}
int symbolic_test_add_overflow_i16(int16_t a, int16_t b) {
    int16_t result;
    return __builtin_add_overflow(a, b, &result);
}
int symbolic_test_add_overflow_i32(int32_t a, int32_t b) {
    int32_t result;
    return __builtin_add_overflow(a, b, &result);
}
int symbolic_test_add_overflow_i64(int64_t a, int64_t b) {
    int64_t result;
    return __builtin_add_overflow(a, b, &result);
}

int symbolic_test_sub_overflow_i8(int8_t a, int8_t b) {
    int8_t result;
    return __builtin_sub_overflow(a, b, &result);
}
int symbolic_test_sub_overflow_i16(int16_t a, int16_t b) {
    int16_t result;
    return __builtin_sub_overflow(a, b, &result);
}
int symbolic_test_sub_overflow_i32(int32_t a, int32_t b) {
    int32_t result;
    return __builtin_sub_overflow(a, b, &result);
}
int symbolic_test_sub_overflow_i64(int64_t a, int64_t b) {
    int64_t result;
    return __builtin_sub_overflow(a, b, &result);
}

int symbolic_test_mul_overflow_i8(int8_t a, int8_t b) {
    int8_t result;
    return __builtin_mul_overflow(a, b, &result);
}
int symbolic_test_mul_overflow_i16(int16_t a, int16_t b) {
    int16_t result;
    return __builtin_mul_overflow(a, b, &result);
}
int symbolic_test_mul_overflow_i32(int32_t a, int32_t b) {
    int32_t result;
    return __builtin_mul_overflow(a, b, &result);
}
int symbolic_test_mul_overflow_i64(int64_t a, int64_t b) {
    int64_t result;
    return __builtin_mul_overflow(a, b, &result);
}
