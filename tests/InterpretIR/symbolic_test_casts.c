#include <stdint.h>
#include <stddef.h>

/* Sign extension (6) */
int16_t symbolic_test_sext_i8_i16(int8_t a)   { return a; }
int32_t symbolic_test_sext_i8_i32(int8_t a)   { return a; }
int64_t symbolic_test_sext_i8_i64(int8_t a)   { return a; }
int32_t symbolic_test_sext_i16_i32(int16_t a) { return a; }
int64_t symbolic_test_sext_i16_i64(int16_t a) { return a; }
int64_t symbolic_test_sext_i32_i64(int32_t a) { return a; }

/* Zero extension (6) */
uint16_t symbolic_test_zext_u8_u16(uint8_t a)   { return a; }
uint32_t symbolic_test_zext_u8_u32(uint8_t a)   { return a; }
uint64_t symbolic_test_zext_u8_u64(uint8_t a)   { return a; }
uint32_t symbolic_test_zext_u16_u32(uint16_t a) { return a; }
uint64_t symbolic_test_zext_u16_u64(uint16_t a) { return a; }
uint64_t symbolic_test_zext_u32_u64(uint32_t a) { return a; }

/* Truncation (6) */
int8_t  symbolic_test_trunc_i16_i8(int16_t a)  { return (int8_t)a; }
int8_t  symbolic_test_trunc_i32_i8(int32_t a)  { return (int8_t)a; }
int8_t  symbolic_test_trunc_i64_i8(int64_t a)  { return (int8_t)a; }
int16_t symbolic_test_trunc_i32_i16(int32_t a) { return (int16_t)a; }
int16_t symbolic_test_trunc_i64_i16(int64_t a) { return (int16_t)a; }
int32_t symbolic_test_trunc_i64_i32(int64_t a) { return (int32_t)a; }

/* Signed int to float (8) */
float  symbolic_test_si_to_fp_i8_f32(int8_t a)   { return (float)a; }
double symbolic_test_si_to_fp_i8_f64(int8_t a)   { return (double)a; }
float  symbolic_test_si_to_fp_i16_f32(int16_t a) { return (float)a; }
double symbolic_test_si_to_fp_i16_f64(int16_t a) { return (double)a; }
float  symbolic_test_si_to_fp_i32_f32(int32_t a) { return (float)a; }
double symbolic_test_si_to_fp_i32_f64(int32_t a) { return (double)a; }
float  symbolic_test_si_to_fp_i64_f32(int64_t a) { return (float)a; }
double symbolic_test_si_to_fp_i64_f64(int64_t a) { return (double)a; }

/* Unsigned int to float (8) */
float  symbolic_test_ui_to_fp_u8_f32(uint8_t a)   { return (float)a; }
double symbolic_test_ui_to_fp_u8_f64(uint8_t a)   { return (double)a; }
float  symbolic_test_ui_to_fp_u16_f32(uint16_t a) { return (float)a; }
double symbolic_test_ui_to_fp_u16_f64(uint16_t a) { return (double)a; }
float  symbolic_test_ui_to_fp_u32_f32(uint32_t a) { return (float)a; }
double symbolic_test_ui_to_fp_u32_f64(uint32_t a) { return (double)a; }
float  symbolic_test_ui_to_fp_u64_f32(uint64_t a) { return (float)a; }
double symbolic_test_ui_to_fp_u64_f64(uint64_t a) { return (double)a; }

/* Float to signed int (8) */
int8_t  symbolic_test_fp_to_si_f32_i8(float a)   { return (int8_t)a; }
int16_t symbolic_test_fp_to_si_f32_i16(float a)  { return (int16_t)a; }
int32_t symbolic_test_fp_to_si_f32_i32(float a)  { return (int32_t)a; }
int64_t symbolic_test_fp_to_si_f32_i64(float a)  { return (int64_t)a; }
int8_t  symbolic_test_fp_to_si_f64_i8(double a)  { return (int8_t)a; }
int16_t symbolic_test_fp_to_si_f64_i16(double a) { return (int16_t)a; }
int32_t symbolic_test_fp_to_si_f64_i32(double a) { return (int32_t)a; }
int64_t symbolic_test_fp_to_si_f64_i64(double a) { return (int64_t)a; }

/* Float to unsigned int (8) */
uint8_t  symbolic_test_fp_to_ui_f32_u8(float a)   { return (uint8_t)a; }
uint16_t symbolic_test_fp_to_ui_f32_u16(float a)  { return (uint16_t)a; }
uint32_t symbolic_test_fp_to_ui_f32_u32(float a)  { return (uint32_t)a; }
uint64_t symbolic_test_fp_to_ui_f32_u64(float a)  { return (uint64_t)a; }
uint8_t  symbolic_test_fp_to_ui_f64_u8(double a)  { return (uint8_t)a; }
uint16_t symbolic_test_fp_to_ui_f64_u16(double a) { return (uint16_t)a; }
uint32_t symbolic_test_fp_to_ui_f64_u32(double a) { return (uint32_t)a; }
uint64_t symbolic_test_fp_to_ui_f64_u64(double a) { return (uint64_t)a; }

/* Float truncation and extension (2) */
float  symbolic_test_fptrunc_f64_f32(double a) { return (float)a; }
double symbolic_test_fpext_f32_f64(float a)    { return (double)a; }

/* Pointer conversions (4) */
int64_t  symbolic_test_ptr_to_int(void *p)     { return (int64_t)(intptr_t)p; }
void    *symbolic_test_int_to_ptr(int64_t a)   { return (void *)(intptr_t)a; }
uint64_t symbolic_test_ptr_to_uint(void *p)    { return (uint64_t)(uintptr_t)p; }
void    *symbolic_test_uint_to_ptr(uint64_t a) { return (void *)(uintptr_t)a; }

/* Identity and bitcast (2) */
int32_t symbolic_test_identity_i32(int32_t a) { return a; }

int32_t symbolic_test_bitcast_f32_i32(float a) {
    int32_t r;
    __builtin_memcpy(&r, &a, sizeof(r));
    return r;
}
