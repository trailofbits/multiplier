#include <stdint.h>

/* ATOMIC_ADD: returns value after atomic add */
int8_t  symbolic_test_atomic_add_i8 (int8_t  initial, int8_t  val) { int8_t  x = initial; __atomic_fetch_add(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int16_t symbolic_test_atomic_add_i16(int16_t initial, int16_t val) { int16_t x = initial; __atomic_fetch_add(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int32_t symbolic_test_atomic_add_i32(int32_t initial, int32_t val) { int32_t x = initial; __atomic_fetch_add(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int64_t symbolic_test_atomic_add_i64(int64_t initial, int64_t val) { int64_t x = initial; __atomic_fetch_add(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }

/* ATOMIC_SUB */
int8_t  symbolic_test_atomic_sub_i8 (int8_t  initial, int8_t  val) { int8_t  x = initial; __atomic_fetch_sub(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int16_t symbolic_test_atomic_sub_i16(int16_t initial, int16_t val) { int16_t x = initial; __atomic_fetch_sub(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int32_t symbolic_test_atomic_sub_i32(int32_t initial, int32_t val) { int32_t x = initial; __atomic_fetch_sub(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int64_t symbolic_test_atomic_sub_i64(int64_t initial, int64_t val) { int64_t x = initial; __atomic_fetch_sub(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }

/* ATOMIC_AND */
int8_t  symbolic_test_atomic_and_i8 (int8_t  initial, int8_t  val) { int8_t  x = initial; __atomic_fetch_and(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int16_t symbolic_test_atomic_and_i16(int16_t initial, int16_t val) { int16_t x = initial; __atomic_fetch_and(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int32_t symbolic_test_atomic_and_i32(int32_t initial, int32_t val) { int32_t x = initial; __atomic_fetch_and(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int64_t symbolic_test_atomic_and_i64(int64_t initial, int64_t val) { int64_t x = initial; __atomic_fetch_and(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }

/* ATOMIC_OR */
int8_t  symbolic_test_atomic_or_i8 (int8_t  initial, int8_t  val) { int8_t  x = initial; __atomic_fetch_or(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int16_t symbolic_test_atomic_or_i16(int16_t initial, int16_t val) { int16_t x = initial; __atomic_fetch_or(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int32_t symbolic_test_atomic_or_i32(int32_t initial, int32_t val) { int32_t x = initial; __atomic_fetch_or(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int64_t symbolic_test_atomic_or_i64(int64_t initial, int64_t val) { int64_t x = initial; __atomic_fetch_or(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }

/* ATOMIC_XOR */
int8_t  symbolic_test_atomic_xor_i8 (int8_t  initial, int8_t  val) { int8_t  x = initial; __atomic_fetch_xor(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int16_t symbolic_test_atomic_xor_i16(int16_t initial, int16_t val) { int16_t x = initial; __atomic_fetch_xor(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int32_t symbolic_test_atomic_xor_i32(int32_t initial, int32_t val) { int32_t x = initial; __atomic_fetch_xor(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int64_t symbolic_test_atomic_xor_i64(int64_t initial, int64_t val) { int64_t x = initial; __atomic_fetch_xor(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }

/* ATOMIC_NAND */
int8_t  symbolic_test_atomic_nand_i8 (int8_t  initial, int8_t  val) { int8_t  x = initial; __atomic_fetch_nand(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int16_t symbolic_test_atomic_nand_i16(int16_t initial, int16_t val) { int16_t x = initial; __atomic_fetch_nand(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int32_t symbolic_test_atomic_nand_i32(int32_t initial, int32_t val) { int32_t x = initial; __atomic_fetch_nand(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int64_t symbolic_test_atomic_nand_i64(int64_t initial, int64_t val) { int64_t x = initial; __atomic_fetch_nand(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }

/* ATOMIC_EXCHANGE */
int8_t  symbolic_test_atomic_xchg_i8 (int8_t  initial, int8_t  val) { int8_t  x = initial; __atomic_exchange_n(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int16_t symbolic_test_atomic_xchg_i16(int16_t initial, int16_t val) { int16_t x = initial; __atomic_exchange_n(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int32_t symbolic_test_atomic_xchg_i32(int32_t initial, int32_t val) { int32_t x = initial; __atomic_exchange_n(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
int64_t symbolic_test_atomic_xchg_i64(int64_t initial, int64_t val) { int64_t x = initial; __atomic_exchange_n(&x, val, __ATOMIC_SEQ_CST); return __atomic_load_n(&x, __ATOMIC_SEQ_CST); }
