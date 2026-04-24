#include <stdint.h>

uint8_t  symbolic_test_and_u8 (uint8_t a,  uint8_t b)  { return a & b; }
uint16_t symbolic_test_and_u16(uint16_t a, uint16_t b) { return a & b; }
uint32_t symbolic_test_and_u32(uint32_t a, uint32_t b) { return a & b; }
uint64_t symbolic_test_and_u64(uint64_t a, uint64_t b) { return a & b; }

uint8_t  symbolic_test_or_u8 (uint8_t a,  uint8_t b)  { return a | b; }
uint16_t symbolic_test_or_u16(uint16_t a, uint16_t b) { return a | b; }
uint32_t symbolic_test_or_u32(uint32_t a, uint32_t b) { return a | b; }
uint64_t symbolic_test_or_u64(uint64_t a, uint64_t b) { return a | b; }

uint8_t  symbolic_test_xor_u8 (uint8_t a,  uint8_t b)  { return a ^ b; }
uint16_t symbolic_test_xor_u16(uint16_t a, uint16_t b) { return a ^ b; }
uint32_t symbolic_test_xor_u32(uint32_t a, uint32_t b) { return a ^ b; }
uint64_t symbolic_test_xor_u64(uint64_t a, uint64_t b) { return a ^ b; }
