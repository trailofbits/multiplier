#include <stdint.h>

/* BSWAP */
uint16_t symbolic_test_bswap_16(uint16_t a) { return __builtin_bswap16(a); }
uint32_t symbolic_test_bswap_32(uint32_t a) { return __builtin_bswap32(a); }
uint64_t symbolic_test_bswap_64(uint64_t a) { return __builtin_bswap64(a); }

/* POPCOUNT */
int symbolic_test_popcount_8(uint8_t a)   { return __builtin_popcount(a); }
int symbolic_test_popcount_16(uint16_t a) { return __builtin_popcount(a); }
int symbolic_test_popcount_32(uint32_t a) { return __builtin_popcount(a); }
int symbolic_test_popcount_64(uint64_t a) { return __builtin_popcountll(a); }

/* CLZ (undefined for 0) */
int symbolic_test_clz_8(uint8_t a)   { return __builtin_clz(a) - 24; }
int symbolic_test_clz_16(uint16_t a) { return __builtin_clzs(a); }
int symbolic_test_clz_32(uint32_t a) { return __builtin_clz(a); }
int symbolic_test_clz_64(uint64_t a) { return __builtin_clzll(a); }

/* CTZ (undefined for 0) */
int symbolic_test_ctz_32(uint32_t a) { return __builtin_ctz(a); }
int symbolic_test_ctz_64(uint64_t a) { return __builtin_ctzll(a); }

/* FFS (returns 0 for input 0) */
int symbolic_test_ffs_32(uint32_t a) { return __builtin_ffs(a); }
int symbolic_test_ffs_64(uint64_t a) { return __builtin_ffsll(a); }

/* PARITY */
int symbolic_test_parity_32(uint32_t a) { return __builtin_parity(a); }
int symbolic_test_parity_64(uint64_t a) { return __builtin_parityll(a); }

/* ROTL */
uint32_t symbolic_test_rotl_32(uint32_t a, uint32_t b) {
    return (a << (b & 31)) | (a >> ((32 - b) & 31));
}
uint64_t symbolic_test_rotl_64(uint64_t a, uint64_t b) {
    return (a << (b & 63)) | (a >> ((64 - b) & 63));
}

/* ROTR */
uint32_t symbolic_test_rotr_32(uint32_t a, uint32_t b) {
    return (a >> (b & 31)) | (a << ((32 - b) & 31));
}
uint64_t symbolic_test_rotr_64(uint64_t a, uint64_t b) {
    return (a >> (b & 63)) | (a << ((64 - b) & 63));
}
