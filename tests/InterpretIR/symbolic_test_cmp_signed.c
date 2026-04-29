#include <stdint.h>

int symbolic_test_eq_i8 (int8_t a,  int8_t b)  { return a == b; }
int symbolic_test_eq_i16(int16_t a, int16_t b) { return a == b; }
int symbolic_test_eq_i32(int32_t a, int32_t b) { return a == b; }
int symbolic_test_eq_i64(int64_t a, int64_t b) { return a == b; }

int symbolic_test_ne_i8 (int8_t a,  int8_t b)  { return a != b; }
int symbolic_test_ne_i16(int16_t a, int16_t b) { return a != b; }
int symbolic_test_ne_i32(int32_t a, int32_t b) { return a != b; }
int symbolic_test_ne_i64(int64_t a, int64_t b) { return a != b; }

int symbolic_test_lt_i8 (int8_t a,  int8_t b)  { return a < b; }
int symbolic_test_lt_i16(int16_t a, int16_t b) { return a < b; }
int symbolic_test_lt_i32(int32_t a, int32_t b) { return a < b; }
int symbolic_test_lt_i64(int64_t a, int64_t b) { return a < b; }

int symbolic_test_le_i8 (int8_t a,  int8_t b)  { return a <= b; }
int symbolic_test_le_i16(int16_t a, int16_t b) { return a <= b; }
int symbolic_test_le_i32(int32_t a, int32_t b) { return a <= b; }
int symbolic_test_le_i64(int64_t a, int64_t b) { return a <= b; }

int symbolic_test_gt_i8 (int8_t a,  int8_t b)  { return a > b; }
int symbolic_test_gt_i16(int16_t a, int16_t b) { return a > b; }
int symbolic_test_gt_i32(int32_t a, int32_t b) { return a > b; }
int symbolic_test_gt_i64(int64_t a, int64_t b) { return a > b; }

int symbolic_test_ge_i8 (int8_t a,  int8_t b)  { return a >= b; }
int symbolic_test_ge_i16(int16_t a, int16_t b) { return a >= b; }
int symbolic_test_ge_i32(int32_t a, int32_t b) { return a >= b; }
int symbolic_test_ge_i64(int64_t a, int64_t b) { return a >= b; }
