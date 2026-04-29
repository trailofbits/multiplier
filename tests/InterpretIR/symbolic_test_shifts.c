#include <stdint.h>

uint8_t  symbolic_test_shl_u8 (uint8_t a,  uint8_t b)  { return a << b; }
uint16_t symbolic_test_shl_u16(uint16_t a, uint16_t b) { return a << b; }
uint32_t symbolic_test_shl_u32(uint32_t a, uint32_t b) { return a << b; }
uint64_t symbolic_test_shl_u64(uint64_t a, uint64_t b) { return a << b; }

int8_t  symbolic_test_shr_i8 (int8_t a,  int8_t b)  { return a >> b; }
int16_t symbolic_test_shr_i16(int16_t a, int16_t b) { return a >> b; }
int32_t symbolic_test_shr_i32(int32_t a, int32_t b) { return a >> b; }
int64_t symbolic_test_shr_i64(int64_t a, int64_t b) { return a >> b; }

uint8_t  symbolic_test_ushr_u8 (uint8_t a,  uint8_t b)  { return a >> b; }
uint16_t symbolic_test_ushr_u16(uint16_t a, uint16_t b) { return a >> b; }
uint32_t symbolic_test_ushr_u32(uint32_t a, uint32_t b) { return a >> b; }
uint64_t symbolic_test_ushr_u64(uint64_t a, uint64_t b) { return a >> b; }
