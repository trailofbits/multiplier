#include <stdint.h>

int symbolic_test_ult_u8 (uint8_t a,  uint8_t b)  { return a < b; }
int symbolic_test_ult_u16(uint16_t a, uint16_t b) { return a < b; }
int symbolic_test_ult_u32(uint32_t a, uint32_t b) { return a < b; }
int symbolic_test_ult_u64(uint64_t a, uint64_t b) { return a < b; }

int symbolic_test_ule_u8 (uint8_t a,  uint8_t b)  { return a <= b; }
int symbolic_test_ule_u16(uint16_t a, uint16_t b) { return a <= b; }
int symbolic_test_ule_u32(uint32_t a, uint32_t b) { return a <= b; }
int symbolic_test_ule_u64(uint64_t a, uint64_t b) { return a <= b; }

int symbolic_test_ugt_u8 (uint8_t a,  uint8_t b)  { return a > b; }
int symbolic_test_ugt_u16(uint16_t a, uint16_t b) { return a > b; }
int symbolic_test_ugt_u32(uint32_t a, uint32_t b) { return a > b; }
int symbolic_test_ugt_u64(uint64_t a, uint64_t b) { return a > b; }

int symbolic_test_uge_u8 (uint8_t a,  uint8_t b)  { return a >= b; }
int symbolic_test_uge_u16(uint16_t a, uint16_t b) { return a >= b; }
int symbolic_test_uge_u32(uint32_t a, uint32_t b) { return a >= b; }
int symbolic_test_uge_u64(uint64_t a, uint64_t b) { return a >= b; }
