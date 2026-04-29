#include <stdint.h>

int8_t  symbolic_test_neg_i8 (int8_t a)  { return -a; }
int16_t symbolic_test_neg_i16(int16_t a) { return -a; }
int32_t symbolic_test_neg_i32(int32_t a) { return -a; }
int64_t symbolic_test_neg_i64(int64_t a) { return -a; }

uint8_t  symbolic_test_bitnot_u8 (uint8_t a)  { return ~a; }
uint16_t symbolic_test_bitnot_u16(uint16_t a) { return ~a; }
uint32_t symbolic_test_bitnot_u32(uint32_t a) { return ~a; }
uint64_t symbolic_test_bitnot_u64(uint64_t a) { return ~a; }

int8_t  symbolic_test_abs_i8 (int8_t a)  { return a < 0 ? -a : a; }
int16_t symbolic_test_abs_i16(int16_t a) { return a < 0 ? -a : a; }
int32_t symbolic_test_abs_i32(int32_t a) { return a < 0 ? -a : a; }
int64_t symbolic_test_abs_i64(int64_t a) { return a < 0 ? -a : a; }

int32_t symbolic_test_lognot_i32(int32_t a) { return !a; }
