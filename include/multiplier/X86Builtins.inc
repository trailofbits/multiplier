// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef char qi __attribute__ ((mode(QI)));
typedef short hi __attribute__ ((mode(HI)));
typedef int si __attribute__ ((mode(SI)));
typedef long long di __attribute__ ((mode(DI)));

typedef float sf __attribute__ ((mode(SF)));
typedef double df __attribute__ ((mode(DF)));

typedef qi v8qi __attribute__ ((vector_size (8)));
typedef hi v4hi __attribute__ ((vector_size (8)));
typedef si v2si __attribute__ ((vector_size (8)));
typedef di v1di __attribute__ ((vector_size (8)));
typedef sf v2sf __attribute__ ((vector_size (8)));

typedef qi v16qi __attribute__ ((vector_size (16)));
typedef hi v8hi __attribute__ ((vector_size (16)));
typedef si v4si __attribute__ ((vector_size (16)));
typedef di v2di __attribute__ ((vector_size (16)));
typedef sf v4sf __attribute__ ((vector_size (16)));
typedef df v2df __attribute__ ((vector_size (16)));

typedef qi v32qi __attribute__ ((vector_size (32)));
typedef hi v16hi __attribute__ ((vector_size (32)));
typedef si v8si __attribute__ ((vector_size (32)));
typedef di v4di __attribute__ ((vector_size (32)));
typedef sf v8sf __attribute__ ((vector_size (32)));
typedef df v4df __attribute__ ((vector_size (32)));

typedef qi v64qi __attribute__ ((vector_size (64)));
typedef hi v32hi __attribute__ ((vector_size (64)));
typedef si v16si __attribute__ ((vector_size (64)));
typedef di v8di __attribute__ ((vector_size (64)));
typedef sf v16sf __attribute__ ((vector_size (64)));
typedef df v8df __attribute__ ((vector_size (64)));

#define pcfloat const float *
#define pcdouble const double *
#define pcv2df const v2df *
#define pcv2di const v2di *
#define pcint64 const long long *
#define pcchar const char *
#define pcv4df const v4df *
#define pcv4di const v4di *
#define pv4di v4di *
#define pcv4sf const v4sf *
#define pcint const int *
#define pchar char *
#define pdouble double *
#define pfloat float *
#define pcv4si const v4si *
#define pv4si v4si *
#define pv2di v2di *
#define pcv8sf const v8sf *
#define pcv8si const v8si *
#define pv8si v8si *
#define pv2df v2df *
#define pv4df v4df *
#define pv4sf v4sf *
#define pv8sf v8sf *
#define ptest ...

// This list was created by scraping the GCC documentation for X86-specific
// built-ins, then extracting out the approximate declarations, making them
// valid, then defining the above types.
//
// CProver has a lot of excellent information which is useful for cross-
// checking, e.g.:
//
//    http://cprover.diffblue.com/gcc__builtin__headers__ia32-2_8h.html


#if !__has_builtin(__builtin_cpu_init)
void __builtin_cpu_init ();
#endif
#if !__has_builtin(__builtin_copysignq) && __is_identifier(__float128)
__float128 __builtin_copysignq (__float128, __float128);
#endif
#if !__has_builtin(__builtin_fabsq) && __is_identifier(__float128)
__float128 __builtin_fabsq (__float128);
#endif
#if !__has_builtin(__builtin_huge_valq) && __is_identifier(__float128)
__float128 __builtin_huge_valq (void);
#endif
#if !__has_builtin(__builtin_infq) && __is_identifier(__float128)
__float128 __builtin_infq (void);
#endif
#if !__has_builtin(__builtin_nanq) && __is_identifier(__float128)
__float128 __builtin_nanq (void);
#endif
#if !__has_builtin(__builtin_nansq) && __is_identifier(__float128)
__float128 __builtin_nansq (void);
#endif
#if !__has_builtin(__builtin_ia32_pand)
di __builtin_ia32_pand (di, di);
#endif
#if !__has_builtin(__builtin_ia32_pandn)
di __builtin_ia32_pandn (di,di);
#endif
#if !__has_builtin(__builtin_ia32_por)
di __builtin_ia32_por (di, di);
#endif
#if !__has_builtin(__builtin_ia32_pxor)
di __builtin_ia32_pxor (di, di);
#endif
#if !__has_builtin(__builtin_ia32_vec_ext_v4sf)
float __builtin_ia32_vec_ext_v4sf (v4sf, const int);
#endif
#if !__has_builtin(__builtin_ia32_comieq)
int __builtin_ia32_comieq (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comige)
int __builtin_ia32_comige (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comigt)
int __builtin_ia32_comigt (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comile)
int __builtin_ia32_comile (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comilt)
int __builtin_ia32_comilt (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comineq)
int __builtin_ia32_comineq (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comisdeq)
int __builtin_ia32_comisdeq (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comisdge)
int __builtin_ia32_comisdge (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comisdgt)
int __builtin_ia32_comisdgt (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comisdle)
int __builtin_ia32_comisdle (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comisdlt)
int __builtin_ia32_comisdlt (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comisdneq)
int __builtin_ia32_comisdneq (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvtsd2si)
int __builtin_ia32_cvtsd2si (v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvtss2si)
int __builtin_ia32_cvtss2si (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cvttsd2si)
int __builtin_ia32_cvttsd2si (v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvttss2si)
int __builtin_ia32_cvttss2si (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_movmskpd)
int __builtin_ia32_movmskpd (v2df);
#endif
#if !__has_builtin(__builtin_ia32_movmskpd256)
int __builtin_ia32_movmskpd256 (v4df);
#endif
#if !__has_builtin(__builtin_ia32_movmskps)
int __builtin_ia32_movmskps (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_movmskps256)
int __builtin_ia32_movmskps256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_pcmpestri128)
int __builtin_ia32_pcmpestri128 (v16qi, int, v16qi, int, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpestria128)
int __builtin_ia32_pcmpestria128 (v16qi, int, v16qi, int, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpestric128)
int __builtin_ia32_pcmpestric128 (v16qi, int, v16qi, int, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpestrio128)
int __builtin_ia32_pcmpestrio128 (v16qi, int, v16qi, int, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpestris128)
int __builtin_ia32_pcmpestris128 (v16qi, int, v16qi, int, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpestriz128)
int __builtin_ia32_pcmpestriz128 (v16qi, int, v16qi, int, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpistri128)
int __builtin_ia32_pcmpistri128 (v16qi, v16qi, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpistria128)
int __builtin_ia32_pcmpistria128 (v16qi, v16qi, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpistric128)
int __builtin_ia32_pcmpistric128 (v16qi, v16qi, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpistrio128)
int __builtin_ia32_pcmpistrio128 (v16qi, v16qi, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpistris128)
int __builtin_ia32_pcmpistris128 (v16qi, v16qi, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpistriz128)
int __builtin_ia32_pcmpistriz128 (v16qi, v16qi, const int);
#endif
#if !__has_builtin(__builtin_ia32_pextrw)
int __builtin_ia32_pextrw (v4hi, int);
#endif
#if !__has_builtin(__builtin_ia32_pmovmskb)
int __builtin_ia32_pmovmskb (v8qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovmskb128)
int __builtin_ia32_pmovmskb128 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovmskb256)
int __builtin_ia32_pmovmskb256 (v32qi);
#endif
#if !__has_builtin(__builtin_ia32_ptestc128)
int __builtin_ia32_ptestc128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_ptestc256)
int __builtin_ia32_ptestc256 (v4di,v4di,ptest);
#endif
#if !__has_builtin(__builtin_ia32_ptestnzc128)
int __builtin_ia32_ptestnzc128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_ptestnzc256)
int __builtin_ia32_ptestnzc256 (v4di,v4di,ptest);
#endif
#if !__has_builtin(__builtin_ia32_ptestz128)
int __builtin_ia32_ptestz128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_ptestz256)
int __builtin_ia32_ptestz256 (v4di,v4di,ptest);
#endif
#if !__has_builtin(__builtin_ia32_ucomieq)
int __builtin_ia32_ucomieq (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_ucomige)
int __builtin_ia32_ucomige (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_ucomigt)
int __builtin_ia32_ucomigt (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_ucomile)
int __builtin_ia32_ucomile (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_ucomilt)
int __builtin_ia32_ucomilt (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_ucomineq)
int __builtin_ia32_ucomineq (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_ucomisdeq)
int __builtin_ia32_ucomisdeq (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_ucomisdge)
int __builtin_ia32_ucomisdge (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_ucomisdgt)
int __builtin_ia32_ucomisdgt (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_ucomisdle)
int __builtin_ia32_ucomisdle (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_ucomisdlt)
int __builtin_ia32_ucomisdlt (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_ucomisdneq)
int __builtin_ia32_ucomisdneq (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vec_ext_v16qi)
int __builtin_ia32_vec_ext_v16qi (v16qi, const int);
#endif
#if !__has_builtin(__builtin_ia32_vec_ext_v4si)
int __builtin_ia32_vec_ext_v4si (v4si, const int);
#endif
#if !__has_builtin(__builtin_ia32_vtestcpd)
int __builtin_ia32_vtestcpd (v2df,v2df,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestcpd256)
int __builtin_ia32_vtestcpd256 (v4df,v4df,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestcps)
int __builtin_ia32_vtestcps (v4sf,v4sf,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestcps256)
int __builtin_ia32_vtestcps256 (v8sf,v8sf,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestnzcpd)
int __builtin_ia32_vtestnzcpd (v2df,v2df,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestnzcpd256)
int __builtin_ia32_vtestnzcpd256 (v4df,v4df,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestnzcps)
int __builtin_ia32_vtestnzcps (v4sf,v4sf,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestnzcps256)
int __builtin_ia32_vtestnzcps256 (v8sf,v8sf,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestzpd)
int __builtin_ia32_vtestzpd (v2df,v2df,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestzpd256)
int __builtin_ia32_vtestzpd256 (v4df,v4df,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestzps)
int __builtin_ia32_vtestzps (v4sf,v4sf,ptest);
#endif
#if !__has_builtin(__builtin_ia32_vtestzps256)
int __builtin_ia32_vtestzps256 (v8sf,v8sf,ptest);
#endif
#if !__has_builtin(__builtin_ia32_xbegin)
int __builtin_ia32_xbegin ();
#endif
#if !__has_builtin(__builtin_ia32_xtest)
int __builtin_ia32_xtest ();
#endif
#if !__has_builtin(__builtin_popcount)
int __builtin_popcount (unsigned int);
#endif
#if !__has_builtin(__builtin_popcountl)
int __builtin_popcountl (unsigned long);
#endif
#if !__has_builtin(__builtin_popcountll)
int __builtin_popcountll (unsigned long long);
#endif
#if !__has_builtin(__builtin_ia32_cvtsd2si64)
long __builtin_ia32_cvtsd2si64 (v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvttsd2si64)
long long __builtin_ia32_cvttsd2si64 (v2df);
#endif
#if !__has_builtin(__builtin_ia32_palignr)
long long __builtin_ia32_palignr (long long, long long, int);
#endif
#if !__has_builtin(__builtin_ia32_vec_ext_v2di)
long long __builtin_ia32_vec_ext_v2di (v2di, const int);
#endif
#if !__has_builtin(__builtin_ia32_lwpins16)
unsigned char __builtin_ia32_lwpins16 (unsigned short, unsigned int, unsigned short);
#endif
#if !__has_builtin(__builtin_ia32_lwpins32)
unsigned char __builtin_ia32_lwpins32 (unsigned int, unsigned int, unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_lwpins64)
unsigned char __builtin_ia32_lwpins64 (unsigned __int64, unsigned int, unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_bextr_u32)
unsigned int __builtin_ia32_bextr_u32(unsigned int, unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_bextri_u32)
unsigned int __builtin_ia32_bextri_u32 (unsigned int, const unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_crc32hi)
unsigned int __builtin_ia32_crc32hi (unsigned int, unsigned short);
#endif
#if !__has_builtin(__builtin_ia32_crc32qi)
unsigned int __builtin_ia32_crc32qi (unsigned int, unsigned char);
#endif
#if !__has_builtin(__builtin_ia32_crc32si)
unsigned int __builtin_ia32_crc32si (unsigned int, unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_lzcnt_u32)
unsigned int __builtin_ia32_lzcnt_u32(unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_rdfsbase32)
unsigned int __builtin_ia32_rdfsbase32 (void);
#endif
#if !__has_builtin(__builtin_ia32_rdgsbase32)
unsigned int __builtin_ia32_rdgsbase32 (void);
#endif
#if !__has_builtin(__builtin_ia32_rdpkru)
unsigned int __builtin_ia32_rdpkru ();
#endif
#if !__has_builtin(__builtin_ia32_rdrand16_step)
unsigned int __builtin_ia32_rdrand16_step (unsigned short *);
#endif
#if !__has_builtin(__builtin_ia32_rdrand32_step)
unsigned int __builtin_ia32_rdrand32_step (unsigned int *);
#endif
#if !__has_builtin(__builtin_ia32_rdrand64_step)
unsigned int __builtin_ia32_rdrand64_step (unsigned long long *);
#endif
#if !__has_builtin(__builtin_ia32_rdsspd)
unsigned int __builtin_ia32_rdsspd (void);
#endif
#if !__has_builtin(__builtin_ia32_bextr_u64)
unsigned long long __builtin_ia32_bextr_u64 (unsigned long long, unsigned long long);
#endif
#if !__has_builtin(__builtin_ia32_bextri_u64)
unsigned long long __builtin_ia32_bextri_u64 (unsigned long long, const unsigned long long);
#endif
#if !__has_builtin(__builtin_ia32_crc32di)
unsigned long long __builtin_ia32_crc32di (unsigned long long, unsigned long long);
#endif
#if !__has_builtin(__builtin_ia32_lzcnt_u64)
unsigned long long __builtin_ia32_lzcnt_u64 (unsigned long long);
#endif
#if !__has_builtin(__builtin_ia32_pmuludq)
unsigned long long __builtin_ia32_pmuludq (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_rdfsbase64)
unsigned long long __builtin_ia32_rdfsbase64 (void);
#endif
#if !__has_builtin(__builtin_ia32_rdgsbase64)
unsigned long long __builtin_ia32_rdgsbase64 (void);
#endif
#if !__has_builtin(__builtin_ia32_rdsspq)
unsigned long long __builtin_ia32_rdsspq (void);
#endif
#if !__has_builtin(__builtin_ia32_lzcnt_16)
unsigned short __builtin_ia32_lzcnt_16(unsigned short);
#endif
#if !__has_builtin(__builtin_ia32_lzcnt_u16)
unsigned short __builtin_ia32_lzcnt_u16(unsigned short);
#endif
#if !__has_builtin(__builtin_ia32_pabsw256)
v16hi __builtin_ia32_pabsw256 (v16hi);
#endif
#if !__has_builtin(__builtin_ia32_packssdw256)
v16hi __builtin_ia32_packssdw256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_packusdw256)
v16hi __builtin_ia32_packusdw256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_paddsw256)
v16hi __builtin_ia32_paddsw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_paddusw256)
v16hi __builtin_ia32_paddusw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_paddw256)
v16hi __builtin_ia32_paddw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pavgw256)
v16hi __builtin_ia32_pavgw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pblendw256)
v16hi __builtin_ia32_pblendw256 (v16hi,v16hi,int);
#endif
#if !__has_builtin(__builtin_ia32_pbroadcastw256)
v16hi __builtin_ia32_pbroadcastw256 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqw256)
v16hi __builtin_ia32_pcmpeqw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtw256)
v16hi __builtin_ia32_pcmpgtw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_phaddsw256)
v16hi __builtin_ia32_phaddsw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_phaddw256)
v16hi __builtin_ia32_phaddw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_phsubsw256)
v16hi __builtin_ia32_phsubsw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_phsubw256)
v16hi __builtin_ia32_phsubw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pmaddwd256)
v16hi __builtin_ia32_pmaddwd256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxsw256)
v16hi __builtin_ia32_pmaxsw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxuw256)
v16hi __builtin_ia32_pmaxuw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pminsw256)
v16hi __builtin_ia32_pminsw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pminuw256)
v16hi __builtin_ia32_pminuw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxbw256)
v16hi __builtin_ia32_pmovsxbw256 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxbw256)
v16hi __builtin_ia32_pmovzxbw256 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmulhrsw256)
v16hi __builtin_ia32_pmulhrsw256 (v16hi, v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pmulhuw256)
v16hi __builtin_ia32_pmulhuw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pmulhw256)
v16hi __builtin_ia32_pmulhw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_pmullw256)
v16hi __builtin_ia32_pmullw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_psadbw256)
v16hi __builtin_ia32_psadbw256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pshufhw256)
v16hi __builtin_ia32_pshufhw256 (v16hi,int);
#endif
#if !__has_builtin(__builtin_ia32_pshuflw256)
v16hi __builtin_ia32_pshuflw256 (v16hi,int);
#endif
#if !__has_builtin(__builtin_ia32_psignw256)
v16hi __builtin_ia32_psignw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_psllw256)
v16hi __builtin_ia32_psllw256(v16hi,v8hi);
#endif
#if !__has_builtin(__builtin_ia32_psllwi256)
v16hi __builtin_ia32_psllwi256 (v16hi,int);
#endif
#if !__has_builtin(__builtin_ia32_psraw256)
v16hi __builtin_ia32_psraw256 (v16hi,v8hi);
#endif
#if !__has_builtin(__builtin_ia32_psrawi256)
v16hi __builtin_ia32_psrawi256 (v16hi,int);
#endif
#if !__has_builtin(__builtin_ia32_psrlw256)
v16hi __builtin_ia32_psrlw256 (v16hi,v8hi);
#endif
#if !__has_builtin(__builtin_ia32_psrlwi256)
v16hi __builtin_ia32_psrlwi256 (v16hi,int);
#endif
#if !__has_builtin(__builtin_ia32_psubsw256)
v16hi __builtin_ia32_psubsw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_psubusw256)
v16hi __builtin_ia32_psubusw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_punpckhwd256)
v16hi __builtin_ia32_punpckhwd256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_punpcklwd256)
v16hi __builtin_ia32_punpcklwd256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v16hi256)
v16hi __builtin_ia32_vpcmov_v16hi256 (v16hi, v16hi, v16hi);
#endif
#if !__has_builtin(__builtin_ia32_lddqu)
v16qi __builtin_ia32_lddqu (char const *);
#endif
#if !__has_builtin(__builtin_ia32_loaddqu)
v16qi __builtin_ia32_loaddqu (const char *);
#endif
#if !__has_builtin(__builtin_ia32_mpsadbw128)
v16qi __builtin_ia32_mpsadbw128 (v16qi, v16qi, const int);
#endif
#if !__has_builtin(__builtin_ia32_pabsb128)
v16qi __builtin_ia32_pabsb128 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_packsswb128)
v16qi __builtin_ia32_packsswb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_packsswb128)
v16qi __builtin_ia32_packsswb128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_packuswb128)
v16qi __builtin_ia32_packuswb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_packuswb128)
v16qi __builtin_ia32_packuswb128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_paddb128)
v16qi __builtin_ia32_paddb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pavgb128)
v16qi __builtin_ia32_pavgb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pblendvb128)
v16qi __builtin_ia32_pblendvb128 (v16qi, v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pbroadcastb128)
v16qi __builtin_ia32_pbroadcastb128 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcmov_v16qi)
v16qi __builtin_ia32_pcmov_v16qi (v16qi, v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqb128)
v16qi __builtin_ia32_pcmpeqb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpestrm128)
v16qi __builtin_ia32_pcmpestrm128 (v16qi, int, v16qi, int, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtb128)
v16qi __builtin_ia32_pcmpgtb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpistrm128)
v16qi __builtin_ia32_pcmpistrm128 (v16qi, v16qi, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcomeqb)
v16qi __builtin_ia32_pcomeqb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomequb)
v16qi __builtin_ia32_pcomequb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomfalseb)
v16qi __builtin_ia32_pcomfalseb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomfalseub)
v16qi __builtin_ia32_pcomfalseub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomgeb)
v16qi __builtin_ia32_pcomgeb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomgeub)
v16qi __builtin_ia32_pcomgeub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomgtb)
v16qi __builtin_ia32_pcomgtb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomgtub)
v16qi __builtin_ia32_pcomgtub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomleb)
v16qi __builtin_ia32_pcomleb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomleub)
v16qi __builtin_ia32_pcomleub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomltb)
v16qi __builtin_ia32_pcomltb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomltub)
v16qi __builtin_ia32_pcomltub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomneb)
v16qi __builtin_ia32_pcomneb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomneub)
v16qi __builtin_ia32_pcomneub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomtrueb)
v16qi __builtin_ia32_pcomtrueb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcomtrueub)
v16qi __builtin_ia32_pcomtrueub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmaddubsw128)
v16qi __builtin_ia32_pmaddubsw128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxsb128)
v16qi __builtin_ia32_pmaxsb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxub128)
v16qi __builtin_ia32_pmaxub128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pminsb128)
v16qi __builtin_ia32_pminsb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pminub128)
v16qi __builtin_ia32_pminub128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pperm)
v16qi __builtin_ia32_pperm (v16qi, v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_protb)
v16qi __builtin_ia32_protb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_protb_imm)
v16qi __builtin_ia32_protb_imm (v16qi, int);
#endif
#if !__has_builtin(__builtin_ia32_pshab)
v16qi __builtin_ia32_pshab (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pshlb)
v16qi __builtin_ia32_pshlb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pshufb128)
v16qi __builtin_ia32_pshufb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_psignb128)
v16qi __builtin_ia32_psignb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_psubb128)
v16qi __builtin_ia32_psubb128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_punpckhbw128)
v16qi __builtin_ia32_punpckhbw128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_punpcklbw128)
v16qi __builtin_ia32_punpcklbw128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vec_set_v16qi)
v16qi __builtin_ia32_vec_set_v16qi (v16qi, int, const int);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v16qi)
v16qi __builtin_ia32_vpcmov_v16qi (v16qi, v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomeqb)
v16qi __builtin_ia32_vpcomeqb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomequb)
v16qi __builtin_ia32_vpcomequb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomfalseb)
v16qi __builtin_ia32_vpcomfalseb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomfalseub)
v16qi __builtin_ia32_vpcomfalseub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgeb)
v16qi __builtin_ia32_vpcomgeb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgeub)
v16qi __builtin_ia32_vpcomgeub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgtb)
v16qi __builtin_ia32_vpcomgtb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgtub)
v16qi __builtin_ia32_vpcomgtub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomleb)
v16qi __builtin_ia32_vpcomleb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomleub)
v16qi __builtin_ia32_vpcomleub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomltb)
v16qi __builtin_ia32_vpcomltb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomltub)
v16qi __builtin_ia32_vpcomltub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomneb)
v16qi __builtin_ia32_vpcomneb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomneub)
v16qi __builtin_ia32_vpcomneub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomtrueb)
v16qi __builtin_ia32_vpcomtrueb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomtrueub)
v16qi __builtin_ia32_vpcomtrueub (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpperm)
v16qi __builtin_ia32_vpperm (v16qi, v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vprotb)
v16qi __builtin_ia32_vprotb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpshab)
v16qi __builtin_ia32_vpshab (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpshlb)
v16qi __builtin_ia32_vpshlb (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_palignr)
v1di __builtin_ia32_palignr (v1di, v1di, int);
#endif
#if !__has_builtin(__builtin_ia32_pmuludq)
v1di __builtin_ia32_pmuludq (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_psadbw)
v1di __builtin_ia32_psadbw (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_psllq)
v1di __builtin_ia32_psllq (v1di, v1di);
#endif
#if !__has_builtin(__builtin_ia32_psllqi)
v1di __builtin_ia32_psllqi (v1di, int);
#endif
#if !__has_builtin(__builtin_ia32_psrlq)
v1di __builtin_ia32_psrlq (v1di, v1di);
#endif
#if !__has_builtin(__builtin_ia32_psrlqi)
v1di __builtin_ia32_psrlqi (v1di, int);
#endif
#if !__has_builtin(__builtin_ia32_addpd)
v2df __builtin_ia32_addpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_addsd)
v2df __builtin_ia32_addsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_addsubpd)
v2df __builtin_ia32_addsubpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_andnpd)
v2df __builtin_ia32_andnpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_andpd)
v2df __builtin_ia32_andpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_blendpd)
v2df __builtin_ia32_blendpd (v2df, v2df, const int);
#endif
#if !__has_builtin(__builtin_ia32_blendvpd)
v2df __builtin_ia32_blendvpd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpeqpd)
v2df __builtin_ia32_cmpeqpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpeqsd)
v2df __builtin_ia32_cmpeqsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpgepd)
v2df __builtin_ia32_cmpgepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpgtpd)
v2df __builtin_ia32_cmpgtpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmplepd)
v2df __builtin_ia32_cmplepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmplesd)
v2df __builtin_ia32_cmplesd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpltpd)
v2df __builtin_ia32_cmpltpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpltsd)
v2df __builtin_ia32_cmpltsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpneqpd)
v2df __builtin_ia32_cmpneqpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpneqsd)
v2df __builtin_ia32_cmpneqsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpngepd)
v2df __builtin_ia32_cmpngepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpngtpd)
v2df __builtin_ia32_cmpngtpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpnlepd)
v2df __builtin_ia32_cmpnlepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpnlesd)
v2df __builtin_ia32_cmpnlesd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpnltpd)
v2df __builtin_ia32_cmpnltpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpnltsd)
v2df __builtin_ia32_cmpnltsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpordpd)
v2df __builtin_ia32_cmpordpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpordsd)
v2df __builtin_ia32_cmpordsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmppd)
v2df __builtin_ia32_cmppd (v2df,v2df,int);
#endif
#if !__has_builtin(__builtin_ia32_cmpsd)
v2df __builtin_ia32_cmpsd (v2df,v2df,int);
#endif
#if !__has_builtin(__builtin_ia32_cmpunordpd)
v2df __builtin_ia32_cmpunordpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cmpunordsd)
v2df __builtin_ia32_cmpunordsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comeqpd)
v2df __builtin_ia32_comeqpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comeqps)
v2df __builtin_ia32_comeqps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comfalsepd)
v2df __builtin_ia32_comfalsepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comfalseps)
v2df __builtin_ia32_comfalseps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comgepd)
v2df __builtin_ia32_comgepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comgeps)
v2df __builtin_ia32_comgeps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comgtpd)
v2df __builtin_ia32_comgtpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comgtps)
v2df __builtin_ia32_comgtps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comlepd)
v2df __builtin_ia32_comlepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comleps)
v2df __builtin_ia32_comleps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comltpd)
v2df __builtin_ia32_comltpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comltps)
v2df __builtin_ia32_comltps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comnepd)
v2df __builtin_ia32_comnepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comneps)
v2df __builtin_ia32_comneps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comordpd)
v2df __builtin_ia32_comordpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comordps)
v2df __builtin_ia32_comordps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comtruepd)
v2df __builtin_ia32_comtruepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comtrueps)
v2df __builtin_ia32_comtrueps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comueqpd)
v2df __builtin_ia32_comueqpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comueqps)
v2df __builtin_ia32_comueqps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comugepd)
v2df __builtin_ia32_comugepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comugeps)
v2df __builtin_ia32_comugeps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comugtpd)
v2df __builtin_ia32_comugtpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comugtps)
v2df __builtin_ia32_comugtps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comulepd)
v2df __builtin_ia32_comulepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comuleps)
v2df __builtin_ia32_comuleps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comultpd)
v2df __builtin_ia32_comultpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comultps)
v2df __builtin_ia32_comultps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comunepd)
v2df __builtin_ia32_comunepd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comuneps)
v2df __builtin_ia32_comuneps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comunordpd)
v2df __builtin_ia32_comunordpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_comunordps)
v2df __builtin_ia32_comunordps (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvtdq2pd)
v2df __builtin_ia32_cvtdq2pd (v4si);
#endif
#if !__has_builtin(__builtin_ia32_cvtpi2pd)
v2df __builtin_ia32_cvtpi2pd (v2si);
#endif
#if !__has_builtin(__builtin_ia32_cvtps2pd)
v2df __builtin_ia32_cvtps2pd (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cvtsi2sd)
v2df __builtin_ia32_cvtsi2sd (v2df, int);
#endif
#if !__has_builtin(__builtin_ia32_cvtsi642sd)
v2df __builtin_ia32_cvtsi642sd (v2df, long long);
#endif
#if !__has_builtin(__builtin_ia32_cvtss2sd)
v2df __builtin_ia32_cvtss2sd (v2df, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_divpd)
v2df __builtin_ia32_divpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_divsd)
v2df __builtin_ia32_divsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_dppd)
v2df __builtin_ia32_dppd (v2df, v2df, const int);
#endif
#if !__has_builtin(__builtin_ia32_fmaddpd)
v2df __builtin_ia32_fmaddpd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_fmaddsd)
v2df __builtin_ia32_fmaddsd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_fmaddsubpd)
v2df __builtin_ia32_fmaddsubpd  (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_fmsubaddpd)
v2df __builtin_ia32_fmsubaddpd  (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_fmsubpd)
v2df __builtin_ia32_fmsubpd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_fmsubsd)
v2df __builtin_ia32_fmsubsd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_fnmaddpd)
v2df __builtin_ia32_fnmaddpd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_fnmaddsd)
v2df __builtin_ia32_fnmaddsd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_fnmsubpd)
v2df __builtin_ia32_fnmsubpd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_fnmsubsd)
v2df __builtin_ia32_fnmsubsd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_frczpd)
v2df __builtin_ia32_frczpd (v2df);
#endif
#if !__has_builtin(__builtin_ia32_frczsd)
v2df __builtin_ia32_frczsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_gatherdiv2df)
v2df __builtin_ia32_gatherdiv2df (v2df, pcdouble,v2di,v2df,int);
#endif
#if !__has_builtin(__builtin_ia32_gathersiv2df)
v2df __builtin_ia32_gathersiv2df (v2df, pcdouble,v4si,v2df,int);
#endif
#if !__has_builtin(__builtin_ia32_haddpd)
v2df __builtin_ia32_haddpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_hsubpd)
v2df __builtin_ia32_hsubpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_loadddup)
v2df __builtin_ia32_loadddup (double const *);
#endif
#if !__has_builtin(__builtin_ia32_loadhpd)
v2df __builtin_ia32_loadhpd (v2df, double const *);
#endif
#if !__has_builtin(__builtin_ia32_loadlpd)
v2df __builtin_ia32_loadlpd (v2df, double const *);
#endif
#if !__has_builtin(__builtin_ia32_loadupd)
v2df __builtin_ia32_loadupd (double *);
#endif
#if !__has_builtin(__builtin_ia32_maskloadpd)
v2df __builtin_ia32_maskloadpd (pcv2df,v2df);
#endif
#if !__has_builtin(__builtin_ia32_maxpd)
v2df __builtin_ia32_maxpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_maxsd)
v2df __builtin_ia32_maxsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_minpd)
v2df __builtin_ia32_minpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_minsd)
v2df __builtin_ia32_minsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_movddup)
v2df __builtin_ia32_movddup (v2df);
#endif
#if !__has_builtin(__builtin_ia32_movsd)
v2df __builtin_ia32_movsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_mulpd)
v2df __builtin_ia32_mulpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_mulsd)
v2df __builtin_ia32_mulsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_orpd)
v2df __builtin_ia32_orpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_pcmov_v2df)
v2df __builtin_ia32_pcmov_v2df (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_pd_pd256)
v2df __builtin_ia32_pd_pd256 (v4df);
#endif
#if !__has_builtin(__builtin_ia32_roundpd)
v2df __builtin_ia32_roundpd (v2df, const int);
#endif
#if !__has_builtin(__builtin_ia32_roundsd)
v2df __builtin_ia32_roundsd (v2df, v2df, const int);
#endif
#if !__has_builtin(__builtin_ia32_shufpd)
v2df __builtin_ia32_shufpd (v2df, v2df, int);
#endif
#if !__has_builtin(__builtin_ia32_sqrtpd)
v2df __builtin_ia32_sqrtpd (v2df);
#endif
#if !__has_builtin(__builtin_ia32_sqrtsd)
v2df __builtin_ia32_sqrtsd (v2df);
#endif
#if !__has_builtin(__builtin_ia32_subpd)
v2df __builtin_ia32_subpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_subsd)
v2df __builtin_ia32_subsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_unpckhpd)
v2df __builtin_ia32_unpckhpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_unpcklpd)
v2df __builtin_ia32_unpcklpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vextractf128_pd256)
v2df __builtin_ia32_vextractf128_pd256 (v4df,int);
#endif
#if !__has_builtin(__builtin_ia32_vfmaddpd)
v2df __builtin_ia32_vfmaddpd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfmaddsd)
v2df __builtin_ia32_vfmaddsd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfmaddsubpd)
v2df __builtin_ia32_vfmaddsubpd  (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfmsubaddpd)
v2df __builtin_ia32_vfmsubaddpd  (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfmsubpd)
v2df __builtin_ia32_vfmsubpd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfmsubsd)
v2df __builtin_ia32_vfmsubsd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfnmaddpd)
v2df __builtin_ia32_vfnmaddpd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfnmaddsd)
v2df __builtin_ia32_vfnmaddsd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfnmsubpd)
v2df __builtin_ia32_vfnmsubpd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfnmsubsd)
v2df __builtin_ia32_vfnmsubsd (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfrczpd)
v2df __builtin_ia32_vfrczpd (v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfrczsd)
v2df __builtin_ia32_vfrczsd (v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfrczsd)
v2df __builtin_ia32_vfrczsd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v2df)
v2df __builtin_ia32_vpcmov_v2df (v2df, v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_vpermil2pd)
v2df __builtin_ia32_vpermil2pd (v2df,v2df,v2di,int);
#endif
#if !__has_builtin(__builtin_ia32_vpermilpd)
v2df __builtin_ia32_vpermilpd (v2df,int);
#endif
#if !__has_builtin(__builtin_ia32_vpermilvarpd)
v2df __builtin_ia32_vpermilvarpd (v2df,v2di);
#endif
#if !__has_builtin(__builtin_ia32_xorpd)
v2df __builtin_ia32_xorpd (v2df, v2df);
#endif
#if !__has_builtin(__builtin_ia32_aesdec128)
v2di __builtin_ia32_aesdec128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_aesdeclast128)
v2di __builtin_ia32_aesdeclast128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_aesenc128)
v2di __builtin_ia32_aesenc128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_aesenclast128)
v2di __builtin_ia32_aesenclast128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_aesimc128)
v2di __builtin_ia32_aesimc128 (v2di);
#endif
#if !__has_builtin(__builtin_ia32_aeskeygenassist128)
v2di __builtin_ia32_aeskeygenassist128 (v2di, const int);
#endif
#if !__has_builtin(__builtin_ia32_extrq)
v2di __builtin_ia32_extrq  (v2di, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_extrqi)
v2di __builtin_ia32_extrqi (v2di, const unsigned int, const unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_gatherdiv2di)
v2di __builtin_ia32_gatherdiv2di (v2di, pcint64,v2di,v2di,int);
#endif
#if !__has_builtin(__builtin_ia32_gathersiv2di)
v2di __builtin_ia32_gathersiv2di (v2di, pcint64,v4si,v2di,int);
#endif
#if !__has_builtin(__builtin_ia32_insertq)
v2di __builtin_ia32_insertq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_insertqi)
v2di __builtin_ia32_insertqi (v2di, v2di, const unsigned int, const unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_maskloadq)
v2di __builtin_ia32_maskloadq (pcv2di,v2di);
#endif
#if !__has_builtin(__builtin_ia32_movntdqa)
v2di __builtin_ia32_movntdqa (v2di *);
#endif
#if !__has_builtin(__builtin_ia32_movq128)
v2di __builtin_ia32_movq128 (v2di);
#endif
#if !__has_builtin(__builtin_ia32_paddq)
v2di __builtin_ia32_paddq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_paddq128)
v2di __builtin_ia32_paddq128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_palignr)
v2di __builtin_ia32_palignr (v2di, v2di, int);
#endif
#if !__has_builtin(__builtin_ia32_palignr128)
v2di __builtin_ia32_palignr128 (v2di, v2di, int);
#endif
#if !__has_builtin(__builtin_ia32_pand128)
v2di __builtin_ia32_pand128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pandn128)
v2di __builtin_ia32_pandn128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pbroadcastq128)
v2di __builtin_ia32_pbroadcastq128 (v2di);
#endif
#if !__has_builtin(__builtin_ia32_pclmulqdq128)
v2di __builtin_ia32_pclmulqdq128 (v2di, v2di, const int);
#endif
#if !__has_builtin(__builtin_ia32_pcmov)
v2di __builtin_ia32_pcmov (v2di, v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcmov_v2di)
v2di __builtin_ia32_pcmov_v2di (v2di, v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqq)
v2di __builtin_ia32_pcmpeqq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtq)
v2di __builtin_ia32_pcmpgtq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomeqq)
v2di __builtin_ia32_pcomeqq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomequq)
v2di __builtin_ia32_pcomequq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomfalseq)
v2di __builtin_ia32_pcomfalseq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomfalseuq)
v2di __builtin_ia32_pcomfalseuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomgeq)
v2di __builtin_ia32_pcomgeq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomgeuq)
v2di __builtin_ia32_pcomgeuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomgtq)
v2di __builtin_ia32_pcomgtq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomgtuq)
v2di __builtin_ia32_pcomgtuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomleq)
v2di __builtin_ia32_pcomleq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomleuq)
v2di __builtin_ia32_pcomleuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomltq)
v2di __builtin_ia32_pcomltq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomltuq)
v2di __builtin_ia32_pcomltuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomneq)
v2di __builtin_ia32_pcomneq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomneuq)
v2di __builtin_ia32_pcomneuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomtrueq)
v2di __builtin_ia32_pcomtrueq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcomtrueuq)
v2di __builtin_ia32_pcomtrueuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_phaddbq)
v2di __builtin_ia32_phaddbq (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_phadddq)
v2di __builtin_ia32_phadddq (v4si);
#endif
#if !__has_builtin(__builtin_ia32_phaddubq)
v2di __builtin_ia32_phaddubq (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_phaddudq)
v2di __builtin_ia32_phaddudq (v4si);
#endif
#if !__has_builtin(__builtin_ia32_phadduwq)
v2di __builtin_ia32_phadduwq (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_phaddwq)
v2di __builtin_ia32_phaddwq (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_phsubdq)
v2di __builtin_ia32_phsubdq (v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmacsdqh)
v2di __builtin_ia32_pmacsdqh (v4si, v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pmacsdql)
v2di __builtin_ia32_pmacsdql (v4si, v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pmacssdqh)
v2di __builtin_ia32_pmacssdqh (v4si, v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pmacssdql)
v2di __builtin_ia32_pmacssdql (v4si, v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxbq128)
v2di __builtin_ia32_pmovsxbq128 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxdq128)
v2di __builtin_ia32_pmovsxdq128 (v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxwq128)
v2di __builtin_ia32_pmovsxwq128 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxbq128)
v2di __builtin_ia32_pmovzxbq128 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxdq128)
v2di __builtin_ia32_pmovzxdq128 (v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxwq128)
v2di __builtin_ia32_pmovzxwq128 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmuldq128)
v2di __builtin_ia32_pmuldq128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmuludq128)
v2di __builtin_ia32_pmuludq128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_por128)
v2di __builtin_ia32_por128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_protq)
v2di __builtin_ia32_protq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_protq_imm)
v2di __builtin_ia32_protq_imm (v2di, int);
#endif
#if !__has_builtin(__builtin_ia32_psadbw128)
v2di __builtin_ia32_psadbw128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pshaq)
v2di __builtin_ia32_pshaq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pshlq)
v2di __builtin_ia32_pshlq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pslldqi128)
v2di __builtin_ia32_pslldqi128 (v2di, int);
#endif
#if !__has_builtin(__builtin_ia32_psllq128)
v2di __builtin_ia32_psllq128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_psllq128)
v2di __builtin_ia32_psllq128 (v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_psllqi128)
v2di __builtin_ia32_psllqi128 (v2di, int);
#endif
#if !__has_builtin(__builtin_ia32_psllv2di)
v2di __builtin_ia32_psllv2di (v2di,v2di);
#endif
#if !__has_builtin(__builtin_ia32_psrldqi128)
v2di __builtin_ia32_psrldqi128 (v2di, int);
#endif
#if !__has_builtin(__builtin_ia32_psrlq128)
v2di __builtin_ia32_psrlq128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_psrlqi128)
v2di __builtin_ia32_psrlqi128 (v2di, int);
#endif
#if !__has_builtin(__builtin_ia32_psrlv2di)
v2di __builtin_ia32_psrlv2di (v2di,v2di);
#endif
#if !__has_builtin(__builtin_ia32_psubq)
v2di __builtin_ia32_psubq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_psubq128)
v2di __builtin_ia32_psubq128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_punpckhqdq128)
v2di __builtin_ia32_punpckhqdq128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_punpcklqdq128)
v2di __builtin_ia32_punpcklqdq128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pxor128)
v2di __builtin_ia32_pxor128 (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vec_set_v2di)
v2di __builtin_ia32_vec_set_v2di (v2di, long long, const int);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov)
v2di __builtin_ia32_vpcmov (v2di, v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v2di)
v2di __builtin_ia32_vpcmov_v2di (v2di, v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomeqq)
v2di __builtin_ia32_vpcomeqq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomequq)
v2di __builtin_ia32_vpcomequq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomfalseq)
v2di __builtin_ia32_vpcomfalseq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomfalseuq)
v2di __builtin_ia32_vpcomfalseuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgeq)
v2di __builtin_ia32_vpcomgeq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgeuq)
v2di __builtin_ia32_vpcomgeuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgtq)
v2di __builtin_ia32_vpcomgtq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgtuq)
v2di __builtin_ia32_vpcomgtuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomleq)
v2di __builtin_ia32_vpcomleq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomleuq)
v2di __builtin_ia32_vpcomleuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomltq)
v2di __builtin_ia32_vpcomltq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomltuq)
v2di __builtin_ia32_vpcomltuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomneq)
v2di __builtin_ia32_vpcomneq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomneuq)
v2di __builtin_ia32_vpcomneuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomtrueq)
v2di __builtin_ia32_vpcomtrueq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcomtrueuq)
v2di __builtin_ia32_vpcomtrueuq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vphaddbq)
v2di __builtin_ia32_vphaddbq (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vphadddq)
v2di __builtin_ia32_vphadddq (v4si);
#endif
#if !__has_builtin(__builtin_ia32_vphaddubq)
v2di __builtin_ia32_vphaddubq (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vphaddudq)
v2di __builtin_ia32_vphaddudq (v4si);
#endif
#if !__has_builtin(__builtin_ia32_vphadduwq)
v2di __builtin_ia32_vphadduwq (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vphaddwq)
v2di __builtin_ia32_vphaddwq (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vphsubdq)
v2di __builtin_ia32_vphsubdq (v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpmacsdqh)
v2di __builtin_ia32_vpmacsdqh (v4si, v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpmacsdql)
v2di __builtin_ia32_vpmacsdql (v4si, v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpmacssdqh)
v2di __builtin_ia32_vpmacssdqh (v4si, v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpmacssdql)
v2di __builtin_ia32_vpmacssdql (v4si, v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vprotq)
v2di __builtin_ia32_vprotq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpshaq)
v2di __builtin_ia32_vpshaq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpshlq)
v2di __builtin_ia32_vpshlq (v2di, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pfacc)
v2sf __builtin_ia32_pfacc (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfadd)
v2sf __builtin_ia32_pfadd (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfmax)
v2sf __builtin_ia32_pfmax (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfmin)
v2sf __builtin_ia32_pfmin (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfmul)
v2sf __builtin_ia32_pfmul (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfnacc)
v2sf __builtin_ia32_pfnacc (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfpnacc)
v2sf __builtin_ia32_pfpnacc (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfrcp)
v2sf __builtin_ia32_pfrcp (v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfrcpit1)
v2sf __builtin_ia32_pfrcpit1 (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfrcpit2)
v2sf __builtin_ia32_pfrcpit2 (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfrsqrt)
v2sf __builtin_ia32_pfrsqrt (v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfrsqrtit1)
v2sf __builtin_ia32_pfrsqrtit1 (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfsub)
v2sf __builtin_ia32_pfsub (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfsubr)
v2sf __builtin_ia32_pfsubr (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pi2fd)
v2sf __builtin_ia32_pi2fd (v2si);
#endif
#if !__has_builtin(__builtin_ia32_pi2fw)
v2sf __builtin_ia32_pi2fw (v2si);
#endif
#if !__has_builtin(__builtin_ia32_pswapdsf)
v2sf __builtin_ia32_pswapdsf (v2sf);
#endif
#if !__has_builtin(__builtin_ia32_cvtpd2pi)
v2si __builtin_ia32_cvtpd2pi (v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvtps2pi)
v2si __builtin_ia32_cvtps2pi (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cvttpd2pi)
v2si __builtin_ia32_cvttpd2pi (v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvttps2pi)
v2si __builtin_ia32_cvttps2pi (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_pabsd)
v2si __builtin_ia32_pabsd (v2si);
#endif
#if !__has_builtin(__builtin_ia32_paddd)
v2si __builtin_ia32_paddd (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqd)
v2si __builtin_ia32_pcmpeqd (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtd)
v2si __builtin_ia32_pcmpgtd (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_pf2id)
v2si __builtin_ia32_pf2id (v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pf2iw)
v2si __builtin_ia32_pf2iw (v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfcmpeq)
v2si __builtin_ia32_pfcmpeq (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfcmpge)
v2si __builtin_ia32_pfcmpge (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_pfcmpgt)
v2si __builtin_ia32_pfcmpgt (v2sf, v2sf);
#endif
#if !__has_builtin(__builtin_ia32_phaddd)
v2si __builtin_ia32_phaddd (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_phsubd)
v2si __builtin_ia32_phsubd (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_psignd)
v2si __builtin_ia32_psignd (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_pslld)
v2si __builtin_ia32_pslld (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_pslldi)
v2si __builtin_ia32_pslldi (v2si, int);
#endif
#if !__has_builtin(__builtin_ia32_psrad)
v2si __builtin_ia32_psrad (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_psradi)
v2si __builtin_ia32_psradi (v2si, int);
#endif
#if !__has_builtin(__builtin_ia32_psrld)
v2si __builtin_ia32_psrld (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_psrldi)
v2si __builtin_ia32_psrldi (v2si, int);
#endif
#if !__has_builtin(__builtin_ia32_psubd)
v2si __builtin_ia32_psubd (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_pswapdsi)
v2si __builtin_ia32_pswapdsi (v2si);
#endif
#if !__has_builtin(__builtin_ia32_punpckhdq)
v2si __builtin_ia32_punpckhdq (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_punpckldq)
v2si __builtin_ia32_punpckldq (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_psubw256)
v32hi __builtin_ia32_psubw256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_lddqu256)
v32qi __builtin_ia32_lddqu256 (pcchar);
#endif
#if !__has_builtin(__builtin_ia32_loaddqu256)
v32qi __builtin_ia32_loaddqu256 (pcchar);
#endif
#if !__has_builtin(__builtin_ia32_mpsadbw256)
v32qi __builtin_ia32_mpsadbw256 (v32qi,v32qi,int);
#endif
#if !__has_builtin(__builtin_ia32_mpsadbw256)
v32qi __builtin_ia32_mpsadbw256 (v32qi,v32qi,v32qi,int);
#endif
#if !__has_builtin(__builtin_ia32_pabsb256)
v32qi __builtin_ia32_pabsb256 (v32qi);
#endif
#if !__has_builtin(__builtin_ia32_packsswb256)
v32qi __builtin_ia32_packsswb256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_packuswb256)
v32qi __builtin_ia32_packuswb256 (v16hi,v16hi);
#endif
#if !__has_builtin(__builtin_ia32_paddb256)
v32qi __builtin_ia32_paddb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_paddsb256)
v32qi __builtin_ia32_paddsb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_paddusb256)
v32qi __builtin_ia32_paddusb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pavgb256)
v32qi __builtin_ia32_pavgb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pblendvb256)
v32qi __builtin_ia32_pblendvb256 (v32qi,v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pbroadcastb256)
v32qi __builtin_ia32_pbroadcastb256 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqb256)
v32qi __builtin_ia32_pcmpeqb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtb256)
v32qi __builtin_ia32_pcmpgtb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pmaddubsw256)
v32qi __builtin_ia32_pmaddubsw256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxsb256)
v32qi __builtin_ia32_pmaxsb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxub256)
v32qi __builtin_ia32_pmaxub256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pminsb256)
v32qi __builtin_ia32_pminsb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pminub256)
v32qi __builtin_ia32_pminub256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_pshufb256)
v32qi __builtin_ia32_pshufb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_psignb256)
v32qi __builtin_ia32_psignb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_psubb256)
v32qi __builtin_ia32_psubb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_psubsb256)
v32qi __builtin_ia32_psubsb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_psubusb256)
v32qi __builtin_ia32_psubusb256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_punpckhbw256)
v32qi __builtin_ia32_punpckhbw256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_punpcklbw256)
v32qi __builtin_ia32_punpcklbw256 (v32qi,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v32qi256)
v32qi __builtin_ia32_vpcmov_v32qi256 (v32qi, v32qi, v32qi);
#endif
#if !__has_builtin(__builtin_ia32_addpd256)
v4df __builtin_ia32_addpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_addsubpd256)
v4df __builtin_ia32_addsubpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_andnpd256)
v4df __builtin_ia32_andnpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_andpd256)
v4df __builtin_ia32_andpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_blendpd256)
v4df __builtin_ia32_blendpd256 (v4df,v4df,int);
#endif
#if !__has_builtin(__builtin_ia32_blendvpd256)
v4df __builtin_ia32_blendvpd256 (v4df,v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_cmppd256)
v4df __builtin_ia32_cmppd256 (v4df,v4df,int);
#endif
#if !__has_builtin(__builtin_ia32_cvtdq2pd256)
v4df __builtin_ia32_cvtdq2pd256 (v4si);
#endif
#if !__has_builtin(__builtin_ia32_cvtps2pd256)
v4df __builtin_ia32_cvtps2pd256 (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_divpd256)
v4df __builtin_ia32_divpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_fmaddpd256)
v4df __builtin_ia32_fmaddpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_fmaddsubpd256)
v4df __builtin_ia32_fmaddsubpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_fmsubaddpd256)
v4df __builtin_ia32_fmsubaddpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_fmsubpd256)
v4df __builtin_ia32_fmsubpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_fnmaddpd256)
v4df __builtin_ia32_fnmaddpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_fnmsubpd256)
v4df __builtin_ia32_fnmsubpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_gatherdiv4df)
v4df __builtin_ia32_gatherdiv4df (v4df, pcdouble,v4di,v4df,int);
#endif
#if !__has_builtin(__builtin_ia32_gathersiv4df)
v4df __builtin_ia32_gathersiv4df (v4df, pcdouble,v4si,v4df,int);
#endif
#if !__has_builtin(__builtin_ia32_haddpd256)
v4df __builtin_ia32_haddpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_hsubpd256)
v4df __builtin_ia32_hsubpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_loadupd256)
v4df __builtin_ia32_loadupd256 (pcdouble);
#endif
#if !__has_builtin(__builtin_ia32_maskloadpd256)
v4df __builtin_ia32_maskloadpd256 (pcv4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_maxpd256)
v4df __builtin_ia32_maxpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_minpd256)
v4df __builtin_ia32_minpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_movddup256)
v4df __builtin_ia32_movddup256 (v4df);
#endif
#if !__has_builtin(__builtin_ia32_mulpd256)
v4df __builtin_ia32_mulpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_orpd256)
v4df __builtin_ia32_orpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_pd256_pd)
v4df __builtin_ia32_pd256_pd (v2df);
#endif
#if !__has_builtin(__builtin_ia32_permdf256)
v4df __builtin_ia32_permdf256 (v4df,int);
#endif
#if !__has_builtin(__builtin_ia32_permpd)
v4df __builtin_ia32_permpd (v2df, v2df, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_roundpd256)
v4df __builtin_ia32_roundpd256 (v4df,int);
#endif
#if !__has_builtin(__builtin_ia32_shufpd256)
v4df __builtin_ia32_shufpd256 (v4df,v4df,int);
#endif
#if !__has_builtin(__builtin_ia32_sqrtpd256)
v4df __builtin_ia32_sqrtpd256 (v4df);
#endif
#if !__has_builtin(__builtin_ia32_subpd256)
v4df __builtin_ia32_subpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_unpckhpd256)
v4df __builtin_ia32_unpckhpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_unpcklpd256)
v4df __builtin_ia32_unpcklpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_vbroadcastf128_pd256)
v4df __builtin_ia32_vbroadcastf128_pd256 (pcv2df);
#endif
#if !__has_builtin(__builtin_ia32_vbroadcastsd256)
v4df __builtin_ia32_vbroadcastsd256 (pcdouble);
#endif
#if !__has_builtin(__builtin_ia32_vbroadcastsd_pd256)
v4df __builtin_ia32_vbroadcastsd_pd256 (v2df);
#endif
#if !__has_builtin(__builtin_ia32_vfmaddpd256)
v4df __builtin_ia32_vfmaddpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_vfmaddsubpd256)
v4df __builtin_ia32_vfmaddsubpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_vfmsubaddpd256)
v4df __builtin_ia32_vfmsubaddpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_vfmsubpd256)
v4df __builtin_ia32_vfmsubpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_vfnmaddpd256)
v4df __builtin_ia32_vfnmaddpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_vfnmsubpd256)
v4df __builtin_ia32_vfnmsubpd256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_vfrczpd256)
v4df __builtin_ia32_vfrczpd256 (v4df);
#endif
#if !__has_builtin(__builtin_ia32_vinsertf128_pd256)
v4df __builtin_ia32_vinsertf128_pd256 (v4df,v2df,int);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v4df256)
v4df __builtin_ia32_vpcmov_v4df256 (v4df, v4df, v4df);
#endif
#if !__has_builtin(__builtin_ia32_vperm2f128_pd256)
v4df __builtin_ia32_vperm2f128_pd256 (v4df,v4df,int);
#endif
#if !__has_builtin(__builtin_ia32_vpermil2pd256)
v4df __builtin_ia32_vpermil2pd256 (v4df,v4df,v4di,int);
#endif
#if !__has_builtin(__builtin_ia32_vpermilpd256)
v4df __builtin_ia32_vpermilpd256 (v4df,int);
#endif
#if !__has_builtin(__builtin_ia32_vpermilvarpd256)
v4df __builtin_ia32_vpermilvarpd256 (v4df,v4di);
#endif
#if !__has_builtin(__builtin_ia32_xorpd256)
v4df __builtin_ia32_xorpd256 (v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_andnotsi256)
v4di __builtin_ia32_andnotsi256 (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_andsi256)
v4di __builtin_ia32_andsi256 (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_extract128i256)
v4di __builtin_ia32_extract128i256 (v4di,int);
#endif
#if !__has_builtin(__builtin_ia32_gatherdiv4di)
v4di __builtin_ia32_gatherdiv4di (v4di, pcint64,v4di,v4di,int);
#endif
#if !__has_builtin(__builtin_ia32_gathersiv4di)
v4di __builtin_ia32_gathersiv4di (v4di, pcint64,v4si,v4di,int);
#endif
#if !__has_builtin(__builtin_ia32_insert128i256)
v4di __builtin_ia32_insert128i256 (v4di,v2di,int);
#endif
#if !__has_builtin(__builtin_ia32_maskloadq256)
v4di __builtin_ia32_maskloadq256 (pcv4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_movntdqa256)
v4di __builtin_ia32_movntdqa256 (pv4di);
#endif
#if !__has_builtin(__builtin_ia32_paddq256)
v4di __builtin_ia32_paddq256 (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_palignr256)
v4di __builtin_ia32_palignr256 (v4di,v4di,int);
#endif
#if !__has_builtin(__builtin_ia32_pbroadcastq256)
v4di __builtin_ia32_pbroadcastq256 (v2di);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqq256)
v4di __builtin_ia32_pcmpeqq256 (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtq256)
v4di __builtin_ia32_pcmpgtq256 (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_permdi256)
v4di __builtin_ia32_permdi256 (v4di,int);
#endif
#if !__has_builtin(__builtin_ia32_permti256)
v4di __builtin_ia32_permti256 (v4di,v4di,int);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxbq256)
v4di __builtin_ia32_pmovsxbq256 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxdq256)
v4di __builtin_ia32_pmovsxdq256 (v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxwq256)
v4di __builtin_ia32_pmovsxwq256 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxbq256)
v4di __builtin_ia32_pmovzxbq256 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxdq256)
v4di __builtin_ia32_pmovzxdq256 (v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxwq256)
v4di __builtin_ia32_pmovzxwq256 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmuldq256)
v4di __builtin_ia32_pmuldq256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pmuludq256)
v4di __builtin_ia32_pmuludq256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_por256)
v4di __builtin_ia32_por256 (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_pslldqi256)
v4di __builtin_ia32_pslldqi256 (v4di,int);
#endif
#if !__has_builtin(__builtin_ia32_psllq256)
v4di __builtin_ia32_psllq256(v4di,v2di);
#endif
#if !__has_builtin(__builtin_ia32_psllqi256)
v4di __builtin_ia32_psllqi256 (v4di,int);
#endif
#if !__has_builtin(__builtin_ia32_psllv4di)
v4di __builtin_ia32_psllv4di (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_psrldqi256)
v4di __builtin_ia32_psrldqi256 (v4di, int);
#endif
#if !__has_builtin(__builtin_ia32_psrlq256)
v4di __builtin_ia32_psrlq256(v4di,v2di);
#endif
#if !__has_builtin(__builtin_ia32_psrlqi256)
v4di __builtin_ia32_psrlqi256 (v4di,int);
#endif
#if !__has_builtin(__builtin_ia32_psrlv4di)
v4di __builtin_ia32_psrlv4di (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_psubq256)
v4di __builtin_ia32_psubq256 (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_punpckhqdq256)
v4di __builtin_ia32_punpckhqdq256 (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_punpcklqdq256)
v4di __builtin_ia32_punpcklqdq256 (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_pxor256)
v4di __builtin_ia32_pxor256 (v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_vbroadcastsi256)
v4di __builtin_ia32_vbroadcastsi256 (v2di);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v4di256)
v4di __builtin_ia32_vpcmov_v4di256 (v4di, v4di, v4di);
#endif
#if !__has_builtin(__builtin_ia32_pabsw)
v4hi __builtin_ia32_pabsw (v4hi);
#endif
#if !__has_builtin(__builtin_ia32_packssdw)
v4hi __builtin_ia32_packssdw (v2si, v2si);
#endif
#if !__has_builtin(__builtin_ia32_paddsw)
v4hi __builtin_ia32_paddsw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_paddusw)
v4hi __builtin_ia32_paddusw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_paddw)
v4hi __builtin_ia32_paddw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_pavgw)
v4hi __builtin_ia32_pavgw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqw)
v4hi __builtin_ia32_pcmpeqw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtw)
v4hi __builtin_ia32_pcmpgtw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_phaddsw)
v4hi __builtin_ia32_phaddsw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_phaddw)
v4hi __builtin_ia32_phaddw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_phsubsw)
v4hi __builtin_ia32_phsubsw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_phsubw)
v4hi __builtin_ia32_phsubw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_pinsrw)
v4hi __builtin_ia32_pinsrw (v4hi, int, int);
#endif
#if !__has_builtin(__builtin_ia32_pmaddubsw)
v4hi __builtin_ia32_pmaddubsw (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxsw)
v4hi __builtin_ia32_pmaxsw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_pminsw)
v4hi __builtin_ia32_pminsw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_pmulhrsw)
v4hi __builtin_ia32_pmulhrsw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_pmulhrw)
v4hi __builtin_ia32_pmulhrw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_pmulhuw)
v4hi __builtin_ia32_pmulhuw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_pmulhw)
v4hi __builtin_ia32_pmulhw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_pmullw)
v4hi __builtin_ia32_pmullw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_psadbw)
v4hi __builtin_ia32_psadbw (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_psignw)
v4hi __builtin_ia32_psignw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_psllw)
v4hi __builtin_ia32_psllw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_psllwi)
v4hi __builtin_ia32_psllwi (v4hi, int);
#endif
#if !__has_builtin(__builtin_ia32_psraw)
v4hi __builtin_ia32_psraw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_psrawi)
v4hi __builtin_ia32_psrawi (v4hi, int);
#endif
#if !__has_builtin(__builtin_ia32_psrlw)
v4hi __builtin_ia32_psrlw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_psrlwi)
v4hi __builtin_ia32_psrlwi (v4hi, int);
#endif
#if !__has_builtin(__builtin_ia32_psubsw)
v4hi __builtin_ia32_psubsw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_psubusw)
v4hi __builtin_ia32_psubusw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_psubw)
v4hi __builtin_ia32_psubw (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_punpckhwd)
v4hi __builtin_ia32_punpckhwd (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_punpcklwd)
v4hi __builtin_ia32_punpcklwd (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_addps)
v4sf __builtin_ia32_addps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_addss)
v4sf __builtin_ia32_addss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_addsubps)
v4sf __builtin_ia32_addsubps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_andnps)
v4sf __builtin_ia32_andnps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_andps)
v4sf __builtin_ia32_andps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_blendps)
v4sf __builtin_ia32_blendps (v4sf, v4sf, const int);
#endif
#if !__has_builtin(__builtin_ia32_blendvps)
v4sf __builtin_ia32_blendvps (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpeqps)
v4sf __builtin_ia32_cmpeqps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpeqss)
v4sf __builtin_ia32_cmpeqss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpgeps)
v4sf __builtin_ia32_cmpgeps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpgtps)
v4sf __builtin_ia32_cmpgtps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpleps)
v4sf __builtin_ia32_cmpleps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpless)
v4sf __builtin_ia32_cmpless (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpltps)
v4sf __builtin_ia32_cmpltps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpltss)
v4sf __builtin_ia32_cmpltss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpneqps)
v4sf __builtin_ia32_cmpneqps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpneqss)
v4sf __builtin_ia32_cmpneqss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpngeps)
v4sf __builtin_ia32_cmpngeps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpngtps)
v4sf __builtin_ia32_cmpngtps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpnleps)
v4sf __builtin_ia32_cmpnleps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpnless)
v4sf __builtin_ia32_cmpnless (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpnltps)
v4sf __builtin_ia32_cmpnltps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpnltss)
v4sf __builtin_ia32_cmpnltss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpordps)
v4sf __builtin_ia32_cmpordps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpordss)
v4sf __builtin_ia32_cmpordss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpps)
v4sf __builtin_ia32_cmpps (v4sf,v4sf,int);
#endif
#if !__has_builtin(__builtin_ia32_cmpss)
v4sf __builtin_ia32_cmpss (v4sf,v4sf,int);
#endif
#if !__has_builtin(__builtin_ia32_cmpunordps)
v4sf __builtin_ia32_cmpunordps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpunordss)
v4sf __builtin_ia32_cmpunordss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comeqsd)
v4sf __builtin_ia32_comeqsd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comeqss)
v4sf __builtin_ia32_comeqss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comfalsesd)
v4sf __builtin_ia32_comfalsesd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comfalsess)
v4sf __builtin_ia32_comfalsess (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comgesd)
v4sf __builtin_ia32_comgesd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comgess)
v4sf __builtin_ia32_comgess (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comgtsd)
v4sf __builtin_ia32_comgtsd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comgtss)
v4sf __builtin_ia32_comgtss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comlesd)
v4sf __builtin_ia32_comlesd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comless)
v4sf __builtin_ia32_comless (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comltsd)
v4sf __builtin_ia32_comltsd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comltss)
v4sf __builtin_ia32_comltss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comnesd)
v4sf __builtin_ia32_comnesd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comness)
v4sf __builtin_ia32_comness (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comordsd)
v4sf __builtin_ia32_comordsd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comordss)
v4sf __builtin_ia32_comordss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comtruesd)
v4sf __builtin_ia32_comtruesd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comtruess)
v4sf __builtin_ia32_comtruess (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comueqsd)
v4sf __builtin_ia32_comueqsd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comueqss)
v4sf __builtin_ia32_comueqss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comugesd)
v4sf __builtin_ia32_comugesd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comugess)
v4sf __builtin_ia32_comugess (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comugtsd)
v4sf __builtin_ia32_comugtsd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comugtss)
v4sf __builtin_ia32_comugtss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comulesd)
v4sf __builtin_ia32_comulesd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comuless)
v4sf __builtin_ia32_comuless (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comultsd)
v4sf __builtin_ia32_comultsd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comultss)
v4sf __builtin_ia32_comultss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comunesd)
v4sf __builtin_ia32_comunesd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comuness)
v4sf __builtin_ia32_comuness (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comunordsd)
v4sf __builtin_ia32_comunordsd (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_comunordss)
v4sf __builtin_ia32_comunordss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cvtdq2ps)
v4sf __builtin_ia32_cvtdq2ps (v4si);
#endif
#if !__has_builtin(__builtin_ia32_cvtpd2ps)
v4sf __builtin_ia32_cvtpd2ps (v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvtpd2ps256)
v4sf __builtin_ia32_cvtpd2ps256 (v4df);
#endif
#if !__has_builtin(__builtin_ia32_cvtpi2ps)
v4sf __builtin_ia32_cvtpi2ps (v4sf, v2si);
#endif
#if !__has_builtin(__builtin_ia32_cvtsd2ss)
v4sf __builtin_ia32_cvtsd2ss (v4sf, v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvtsi2ss)
v4sf __builtin_ia32_cvtsi2ss (v4sf, int);
#endif
#if !__has_builtin(__builtin_ia32_divps)
v4sf __builtin_ia32_divps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_divss)
v4sf __builtin_ia32_divss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_dpps)
v4sf __builtin_ia32_dpps (v4sf, v4sf, const int);
#endif
#if !__has_builtin(__builtin_ia32_fmaddps)
v4sf __builtin_ia32_fmaddps (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_fmaddss)
v4sf __builtin_ia32_fmaddss (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_fmaddsubps)
v4sf __builtin_ia32_fmaddsubps  (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_fmsubaddps)
v4sf __builtin_ia32_fmsubaddps  (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_fmsubps)
v4sf __builtin_ia32_fmsubps (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_fmsubss)
v4sf __builtin_ia32_fmsubss (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_fnmaddps)
v4sf __builtin_ia32_fnmaddps (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_fnmaddss)
v4sf __builtin_ia32_fnmaddss (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_fnmsubps)
v4sf __builtin_ia32_fnmsubps (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_fnmsubss)
v4sf __builtin_ia32_fnmsubss (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_frczps)
v4sf __builtin_ia32_frczps (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_frczss)
v4sf __builtin_ia32_frczss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_gatherdiv4sf)
v4sf __builtin_ia32_gatherdiv4sf (v4sf, pcfloat,v2di,v4sf,int);
#endif
#if !__has_builtin(__builtin_ia32_gatherdiv4sf256)
v4sf __builtin_ia32_gatherdiv4sf256 (v4sf, pcfloat,v4di,v4sf,int);
#endif
#if !__has_builtin(__builtin_ia32_gathersiv4sf)
v4sf __builtin_ia32_gathersiv4sf (v4sf, pcfloat,v4si,v4sf,int);
#endif
#if !__has_builtin(__builtin_ia32_haddps)
v4sf __builtin_ia32_haddps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_hsubps)
v4sf __builtin_ia32_hsubps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_insertps128)
v4sf __builtin_ia32_insertps128 (v4sf, v4sf, const int);
#endif
#if !__has_builtin(__builtin_ia32_loadaps)
v4sf __builtin_ia32_loadaps (float *);
#endif
#if !__has_builtin(__builtin_ia32_loadhps)
v4sf __builtin_ia32_loadhps (v4sf, const v2sf *);
#endif
#if !__has_builtin(__builtin_ia32_loadlps)
v4sf __builtin_ia32_loadlps (v4sf, const v2sf *);
#endif
#if !__has_builtin(__builtin_ia32_loadss)
v4sf __builtin_ia32_loadss (float *);
#endif
#if !__has_builtin(__builtin_ia32_loadsss)
v4sf __builtin_ia32_loadsss (float *);
#endif
#if !__has_builtin(__builtin_ia32_loadups)
v4sf __builtin_ia32_loadups (float *);
#endif
#if !__has_builtin(__builtin_ia32_maskloadps)
v4sf __builtin_ia32_maskloadps (pcv4sf,v4sf);
#endif
#if !__has_builtin(__builtin_ia32_maxps)
v4sf __builtin_ia32_maxps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_maxss)
v4sf __builtin_ia32_maxss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_minps)
v4sf __builtin_ia32_minps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_minss)
v4sf __builtin_ia32_minss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_movhlps)
v4sf __builtin_ia32_movhlps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_movlhps)
v4sf __builtin_ia32_movlhps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_movshdup)
v4sf __builtin_ia32_movshdup (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_movsldup)
v4sf __builtin_ia32_movsldup (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_movss)
v4sf __builtin_ia32_movss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_mulps)
v4sf __builtin_ia32_mulps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_mulss)
v4sf __builtin_ia32_mulss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_orps)
v4sf __builtin_ia32_orps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_pcmov_v4sf)
v4sf __builtin_ia32_pcmov_v4sf (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_permps)
v4sf __builtin_ia32_permps (v4sf, v4sf, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_ps_ps256)
v4sf __builtin_ia32_ps_ps256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_rcpps)
v4sf __builtin_ia32_rcpps (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_rcpss)
v4sf __builtin_ia32_rcpss (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_roundps)
v4sf __builtin_ia32_roundps (v4sf, const int);
#endif
#if !__has_builtin(__builtin_ia32_roundss)
v4sf __builtin_ia32_roundss (v4sf, v4sf, const int);
#endif
#if !__has_builtin(__builtin_ia32_rsqrtps)
v4sf __builtin_ia32_rsqrtps (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_rsqrtss)
v4sf __builtin_ia32_rsqrtss (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_shufps)
v4sf __builtin_ia32_shufps (v4sf, v4sf, int);
#endif
#if !__has_builtin(__builtin_ia32_sqrtps)
v4sf __builtin_ia32_sqrtps (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_sqrtss)
v4sf __builtin_ia32_sqrtss (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_subps)
v4sf __builtin_ia32_subps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_subss)
v4sf __builtin_ia32_subss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_unpckhps)
v4sf __builtin_ia32_unpckhps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_unpcklps)
v4sf __builtin_ia32_unpcklps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vbroadcastss)
v4sf __builtin_ia32_vbroadcastss (pcfloat);
#endif
#if !__has_builtin(__builtin_ia32_vbroadcastss_ps)
v4sf __builtin_ia32_vbroadcastss_ps (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vec_set_v4sf)
v4sf __builtin_ia32_vec_set_v4sf (v4sf, float, const int);
#endif
#if !__has_builtin(__builtin_ia32_vextractf128_ps256)
v4sf __builtin_ia32_vextractf128_ps256 (v8sf,int);
#endif
#if !__has_builtin(__builtin_ia32_vfmaddps)
v4sf __builtin_ia32_vfmaddps (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfmaddss)
v4sf __builtin_ia32_vfmaddss (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfmaddsubps)
v4sf __builtin_ia32_vfmaddsubps  (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfmsubaddps)
v4sf __builtin_ia32_vfmsubaddps  (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfmsubps)
v4sf __builtin_ia32_vfmsubps (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfmsubss)
v4sf __builtin_ia32_vfmsubss (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfnmaddps)
v4sf __builtin_ia32_vfnmaddps (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfnmaddss)
v4sf __builtin_ia32_vfnmaddss (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfnmsubps)
v4sf __builtin_ia32_vfnmsubps (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfnmsubss)
v4sf __builtin_ia32_vfnmsubss (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfrczps)
v4sf __builtin_ia32_vfrczps (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfrczss)
v4sf __builtin_ia32_vfrczss (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfrczss)
v4sf __builtin_ia32_vfrczss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v4sf)
v4sf __builtin_ia32_vpcmov_v4sf (v4sf, v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vpermil2ps)
v4sf __builtin_ia32_vpermil2ps (v4sf,v4sf,v4si,int);
#endif
#if !__has_builtin(__builtin_ia32_vpermilps)
v4sf __builtin_ia32_vpermilps (v4sf,int);
#endif
#if !__has_builtin(__builtin_ia32_vpermilvarps)
v4sf __builtin_ia32_vpermilvarps (v4sf,v4si);
#endif
#if !__has_builtin(__builtin_ia32_xorps)
v4sf __builtin_ia32_xorps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpnlts)
v4si __builtin_ia32_cmpnlts (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpordps)
v4si __builtin_ia32_cmpordps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpordss)
v4si __builtin_ia32_cmpordss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpunordps)
v4si __builtin_ia32_cmpunordps (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpunordss)
v4si __builtin_ia32_cmpunordss (v4sf, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cvtpd2dq)
v4si __builtin_ia32_cvtpd2dq (v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvtpd2dq256)
v4si __builtin_ia32_cvtpd2dq256 (v4df);
#endif
#if !__has_builtin(__builtin_ia32_cvtps2dq)
v4si __builtin_ia32_cvtps2dq (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_cvttpd2dq)
v4si __builtin_ia32_cvttpd2dq (v2df);
#endif
#if !__has_builtin(__builtin_ia32_cvttpd2dq256)
v4si __builtin_ia32_cvttpd2dq256 (v4df);
#endif
#if !__has_builtin(__builtin_ia32_cvttps2dq)
v4si __builtin_ia32_cvttps2dq (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_gatherdiv4si)
v4si __builtin_ia32_gatherdiv4si (v4si, pcint,v2di,v4si,int);
#endif
#if !__has_builtin(__builtin_ia32_gatherdiv4si256)
v4si __builtin_ia32_gatherdiv4si256 (v4si, pcint,v4di,v4si,int);
#endif
#if !__has_builtin(__builtin_ia32_gathersiv4si)
v4si __builtin_ia32_gathersiv4si (v4si, pcint,v4si,v4si,int);
#endif
#if !__has_builtin(__builtin_ia32_maskloadd)
v4si __builtin_ia32_maskloadd (pcv4si,v4si);
#endif
#if !__has_builtin(__builtin_ia32_pabsd128)
v4si __builtin_ia32_pabsd128 (v4si);
#endif
#if !__has_builtin(__builtin_ia32_paddd128)
v4si __builtin_ia32_paddd128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pblendd128)
v4si __builtin_ia32_pblendd128 (v4si,v4si);
#endif
#if !__has_builtin(__builtin_ia32_pbroadcastd128)
v4si __builtin_ia32_pbroadcastd128 (v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcmov_v4si)
v4si __builtin_ia32_pcmov_v4si (v4si, v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqd128)
v4si __builtin_ia32_pcmpeqd128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtd128)
v4si __builtin_ia32_pcmpgtd128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomeqd)
v4si __builtin_ia32_pcomeqd (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomequd)
v4si __builtin_ia32_pcomequd (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomfalsed)
v4si __builtin_ia32_pcomfalsed (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomfalseud)
v4si __builtin_ia32_pcomfalseud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomged)
v4si __builtin_ia32_pcomged (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomgeud)
v4si __builtin_ia32_pcomgeud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomgtd)
v4si __builtin_ia32_pcomgtd (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomgtud)
v4si __builtin_ia32_pcomgtud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomled)
v4si __builtin_ia32_pcomled (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomleud)
v4si __builtin_ia32_pcomleud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomltd)
v4si __builtin_ia32_pcomltd (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomltud)
v4si __builtin_ia32_pcomltud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomned)
v4si __builtin_ia32_pcomned (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomneud)
v4si __builtin_ia32_pcomneud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomtrued)
v4si __builtin_ia32_pcomtrued (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcomtrueud)
v4si __builtin_ia32_pcomtrueud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_phaddbd)
v4si __builtin_ia32_phaddbd (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_phaddd128)
v4si __builtin_ia32_phaddd128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_phaddubd)
v4si __builtin_ia32_phaddubd (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_phadduwd)
v4si __builtin_ia32_phadduwd (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_phaddwd)
v4si __builtin_ia32_phaddwd (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_phsubd128)
v4si __builtin_ia32_phsubd128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_phsubwd)
v4si __builtin_ia32_phsubwd (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmacsdd)
v4si __builtin_ia32_pmacsdd (v4si, v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmacssdd)
v4si __builtin_ia32_pmacssdd (v4si, v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmacsswd)
v4si __builtin_ia32_pmacsswd (v8hi, v8hi, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmacswd)
v4si __builtin_ia32_pmacswd (v8hi, v8hi, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmadcsswd)
v4si __builtin_ia32_pmadcsswd (v8hi, v8hi, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmadcswd)
v4si __builtin_ia32_pmadcswd (v8hi, v8hi, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmaddwd128)
v4si __builtin_ia32_pmaddwd128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxsd128)
v4si __builtin_ia32_pmaxsd128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmaxud128)
v4si __builtin_ia32_pmaxud128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pminsd128)
v4si __builtin_ia32_pminsd128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pminud128)
v4si __builtin_ia32_pminud128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxbd128)
v4si __builtin_ia32_pmovsxbd128 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxwd128)
v4si __builtin_ia32_pmovsxwd128 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxbd128)
v4si __builtin_ia32_pmovzxbd128 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxwd128)
v4si __builtin_ia32_pmovzxwd128 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmulld128)
v4si __builtin_ia32_pmulld128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_protd)
v4si __builtin_ia32_protd (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_protd_imm)
v4si __builtin_ia32_protd_imm (v4si, int);
#endif
#if !__has_builtin(__builtin_ia32_pshad)
v4si __builtin_ia32_pshad (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pshld)
v4si __builtin_ia32_pshld (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pshufd)
v4si __builtin_ia32_pshufd (v4si, int);
#endif
#if !__has_builtin(__builtin_ia32_psignd128)
v4si __builtin_ia32_psignd128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pslld128)
v4si __builtin_ia32_pslld128 (v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_pslld128)
v4si __builtin_ia32_pslld128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pslldi128)
v4si __builtin_ia32_pslldi128 (v4si, int);
#endif
#if !__has_builtin(__builtin_ia32_psllv4si)
v4si __builtin_ia32_psllv4si (v4si,v4si);
#endif
#if !__has_builtin(__builtin_ia32_psrad128)
v4si __builtin_ia32_psrad128 (v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_psrad128)
v4si __builtin_ia32_psrad128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_psradi128)
v4si __builtin_ia32_psradi128 (v4si, int);
#endif
#if !__has_builtin(__builtin_ia32_psrav4si)
v4si __builtin_ia32_psrav4si (v4si,v4si);
#endif
#if !__has_builtin(__builtin_ia32_psrld128)
v4si __builtin_ia32_psrld128 (v4si, v2di);
#endif
#if !__has_builtin(__builtin_ia32_psrld128)
v4si __builtin_ia32_psrld128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_psrldi128)
v4si __builtin_ia32_psrldi128 (v4si, int);
#endif
#if !__has_builtin(__builtin_ia32_psrlv4si)
v4si __builtin_ia32_psrlv4si (v4si,v4si);
#endif
#if !__has_builtin(__builtin_ia32_psubd128)
v4si __builtin_ia32_psubd128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_punpckhdq128)
v4si __builtin_ia32_punpckhdq128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_punpckldq128)
v4si __builtin_ia32_punpckldq128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_si_si256)
v4si __builtin_ia32_si_si256 (v8si);
#endif
#if !__has_builtin(__builtin_ia32_vec_set_v4si)
v4si __builtin_ia32_vec_set_v4si (v4si, int, const int);
#endif
#if !__has_builtin(__builtin_ia32_vextractf128_si256)
v4si __builtin_ia32_vextractf128_si256 (v8si,int);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v4si)
v4si __builtin_ia32_vpcmov_v4si (v4si, v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomeqd)
v4si __builtin_ia32_vpcomeqd (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomequd)
v4si __builtin_ia32_vpcomequd (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomfalsed)
v4si __builtin_ia32_vpcomfalsed (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomfalseud)
v4si __builtin_ia32_vpcomfalseud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomged)
v4si __builtin_ia32_vpcomged (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgeud)
v4si __builtin_ia32_vpcomgeud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgtd)
v4si __builtin_ia32_vpcomgtd (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgtud)
v4si __builtin_ia32_vpcomgtud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomled)
v4si __builtin_ia32_vpcomled (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomleud)
v4si __builtin_ia32_vpcomleud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomltd)
v4si __builtin_ia32_vpcomltd (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomltud)
v4si __builtin_ia32_vpcomltud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomned)
v4si __builtin_ia32_vpcomned (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomneud)
v4si __builtin_ia32_vpcomneud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomtrued)
v4si __builtin_ia32_vpcomtrued (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpcomtrueud)
v4si __builtin_ia32_vpcomtrueud (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vphaddbd)
v4si __builtin_ia32_vphaddbd (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vphaddubd)
v4si __builtin_ia32_vphaddubd (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vphadduwd)
v4si __builtin_ia32_vphadduwd (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vphaddwd)
v4si __builtin_ia32_vphaddwd (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vphsubwd)
v4si __builtin_ia32_vphsubwd (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpmacsdd)
v4si __builtin_ia32_vpmacsdd (v4si, v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpmacssdd)
v4si __builtin_ia32_vpmacssdd (v4si, v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpmacsswd)
v4si __builtin_ia32_vpmacsswd (v8hi, v8hi, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpmacswd)
v4si __builtin_ia32_vpmacswd (v8hi, v8hi, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpmadcsswd)
v4si __builtin_ia32_vpmadcsswd (v8hi, v8hi, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpmadcswd)
v4si __builtin_ia32_vpmadcswd (v8hi, v8hi, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vprotd)
v4si __builtin_ia32_vprotd (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpshad)
v4si __builtin_ia32_vpshad (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_vpshld)
v4si __builtin_ia32_vpshld (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_pabsw128)
v8hi __builtin_ia32_pabsw128 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_packssdw128)
v8hi __builtin_ia32_packssdw128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_packssdw128)
v8hi __builtin_ia32_packssdw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_packusdw128)
v8hi __builtin_ia32_packusdw128 (v4si, v4si);
#endif
#if !__has_builtin(__builtin_ia32_paddw128)
v8hi __builtin_ia32_paddw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pavgw128)
v8hi __builtin_ia32_pavgw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pblendw128)
v8hi __builtin_ia32_pblendw128 (v8hi, v8hi, const int);
#endif
#if !__has_builtin(__builtin_ia32_pbroadcastw128)
v8hi __builtin_ia32_pbroadcastw128 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcmov_v8hi)
v8hi __builtin_ia32_pcmov_v8hi (v8hi, v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqw128)
v8hi __builtin_ia32_pcmpeqw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtw128)
v8hi __builtin_ia32_pcmpgtw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomequw)
v8hi __builtin_ia32_pcomequw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomeqw)
v8hi __builtin_ia32_pcomeqw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomfalseuw)
v8hi __builtin_ia32_pcomfalseuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomfalsew)
v8hi __builtin_ia32_pcomfalsew (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomgeuw)
v8hi __builtin_ia32_pcomgeuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomgew)
v8hi __builtin_ia32_pcomgew (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomgtuw)
v8hi __builtin_ia32_pcomgtuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomgtw)
v8hi __builtin_ia32_pcomgtw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomleuw)
v8hi __builtin_ia32_pcomleuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomlew)
v8hi __builtin_ia32_pcomlew (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomltuw)
v8hi __builtin_ia32_pcomltuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomltw)
v8hi __builtin_ia32_pcomltw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomneuw)
v8hi __builtin_ia32_pcomneuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomnew)
v8hi __builtin_ia32_pcomnew (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomtrueuw)
v8hi __builtin_ia32_pcomtrueuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pcomtruew)
v8hi __builtin_ia32_pcomtruew (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_phaddbw)
v8hi __builtin_ia32_phaddbw (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_phaddsw128)
v8hi __builtin_ia32_phaddsw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_phaddubw)
v8hi __builtin_ia32_phaddubw (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_phaddw128)
v8hi __builtin_ia32_phaddw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_phminposuw128)
v8hi __builtin_ia32_phminposuw128 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_phsubbw)
v8hi __builtin_ia32_phsubbw (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_phsubsw128)
v8hi __builtin_ia32_phsubsw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_phsubw128)
v8hi __builtin_ia32_phsubw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmacssww)
v8hi __builtin_ia32_pmacssww (v8hi, v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmacsww)
v8hi __builtin_ia32_pmacsww (v8hi, v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmaddubsw128)
v8hi __builtin_ia32_pmaddubsw128 (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxsw128)
v8hi __builtin_ia32_pmaxsw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxuw128)
v8hi __builtin_ia32_pmaxuw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pminsw128)
v8hi __builtin_ia32_pminsw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pminuw128)
v8hi __builtin_ia32_pminuw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxbw128)
v8hi __builtin_ia32_pmovsxbw128 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxbw128)
v8hi __builtin_ia32_pmovzxbw128 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmulhrsw128)
v8hi __builtin_ia32_pmulhrsw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmulhuw128)
v8hi __builtin_ia32_pmulhuw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmulhw128)
v8hi __builtin_ia32_pmulhw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmullw128)
v8hi __builtin_ia32_pmullw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_protw)
v8hi __builtin_ia32_protw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_protw_imm)
v8hi __builtin_ia32_protw_imm (v8hi, int);
#endif
#if !__has_builtin(__builtin_ia32_pshaw)
v8hi __builtin_ia32_pshaw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pshlw)
v8hi __builtin_ia32_pshlw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pshufhw)
v8hi __builtin_ia32_pshufhw (v8hi, int);
#endif
#if !__has_builtin(__builtin_ia32_pshuflw)
v8hi __builtin_ia32_pshuflw (v8hi, int);
#endif
#if !__has_builtin(__builtin_ia32_psignw128)
v8hi __builtin_ia32_psignw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_psllw128)
v8hi __builtin_ia32_psllw128 (v8hi, v2di);
#endif
#if !__has_builtin(__builtin_ia32_psllw128)
v8hi __builtin_ia32_psllw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_psllwi128)
v8hi __builtin_ia32_psllwi128 (v8hi, int);
#endif
#if !__has_builtin(__builtin_ia32_psraw128)
v8hi __builtin_ia32_psraw128 (v8hi, v2di);
#endif
#if !__has_builtin(__builtin_ia32_psraw128)
v8hi __builtin_ia32_psraw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_psrawi128)
v8hi __builtin_ia32_psrawi128 (v8hi, int);
#endif
#if !__has_builtin(__builtin_ia32_psrlw128)
v8hi __builtin_ia32_psrlw128 (v8hi, v2di);
#endif
#if !__has_builtin(__builtin_ia32_psrlw128)
v8hi __builtin_ia32_psrlw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_psrlwi128)
v8hi __builtin_ia32_psrlwi128 (v8hi, int);
#endif
#if !__has_builtin(__builtin_ia32_psubw128)
v8hi __builtin_ia32_psubw128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_punpckhwd128)
v8hi __builtin_ia32_punpckhwd128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_punpcklwd128)
v8hi __builtin_ia32_punpcklwd128 (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v8hi)
v8hi __builtin_ia32_vpcmov_v8hi (v8hi, v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomequw)
v8hi __builtin_ia32_vpcomequw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomeqw)
v8hi __builtin_ia32_vpcomeqw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomfalseuw)
v8hi __builtin_ia32_vpcomfalseuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomfalsew)
v8hi __builtin_ia32_vpcomfalsew (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgeuw)
v8hi __builtin_ia32_vpcomgeuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgew)
v8hi __builtin_ia32_vpcomgew (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgtuw)
v8hi __builtin_ia32_vpcomgtuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomgtw)
v8hi __builtin_ia32_vpcomgtw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomleuw)
v8hi __builtin_ia32_vpcomleuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomlew)
v8hi __builtin_ia32_vpcomlew (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomltuw)
v8hi __builtin_ia32_vpcomltuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomltw)
v8hi __builtin_ia32_vpcomltw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomneuw)
v8hi __builtin_ia32_vpcomneuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomnew)
v8hi __builtin_ia32_vpcomnew (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomtrueuw)
v8hi __builtin_ia32_vpcomtrueuw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpcomtruew)
v8hi __builtin_ia32_vpcomtruew (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vphaddbw)
v8hi __builtin_ia32_vphaddbw (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vphaddubw)
v8hi __builtin_ia32_vphaddubw (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vphsubbw)
v8hi __builtin_ia32_vphsubbw (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_vpmacssww)
v8hi __builtin_ia32_vpmacssww (v8hi, v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpmacsww)
v8hi __builtin_ia32_vpmacsww (v8hi, v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vprotw)
v8hi __builtin_ia32_vprotw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpshaw)
v8hi __builtin_ia32_vpshaw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_vpshlw)
v8hi __builtin_ia32_vpshlw (v8hi, v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pabsb)
v8qi __builtin_ia32_pabsb (v8qi);
#endif
#if !__has_builtin(__builtin_ia32_packsswb)
v8qi __builtin_ia32_packsswb (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_packuswb)
v8qi __builtin_ia32_packuswb (v4hi, v4hi);
#endif
#if !__has_builtin(__builtin_ia32_paddb)
v8qi __builtin_ia32_paddb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_paddsb)
v8qi __builtin_ia32_paddsb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_paddusb)
v8qi __builtin_ia32_paddusb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_pavgb)
v8qi __builtin_ia32_pavgb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_pavgusb)
v8qi __builtin_ia32_pavgusb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqb)
v8qi __builtin_ia32_pcmpeqb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtb)
v8qi __builtin_ia32_pcmpgtb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_pmaddubsw)
v8qi __builtin_ia32_pmaddubsw (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_pmaxub)
v8qi __builtin_ia32_pmaxub (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_pminub)
v8qi __builtin_ia32_pminub (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_pshufb)
v8qi __builtin_ia32_pshufb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_psignb)
v8qi __builtin_ia32_psignb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_psubb)
v8qi __builtin_ia32_psubb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_psubsb)
v8qi __builtin_ia32_psubsb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_psubusb)
v8qi __builtin_ia32_psubusb (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_punpckhbw)
v8qi __builtin_ia32_punpckhbw (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_punpcklbw)
v8qi __builtin_ia32_punpcklbw (v8qi, v8qi);
#endif
#if !__has_builtin(__builtin_ia32_addps256)
v8sf __builtin_ia32_addps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_addsubps256)
v8sf __builtin_ia32_addsubps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_andnps256)
v8sf __builtin_ia32_andnps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_andps256)
v8sf __builtin_ia32_andps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_blendps256)
v8sf __builtin_ia32_blendps256 (v8sf,v8sf,int);
#endif
#if !__has_builtin(__builtin_ia32_blendvps256)
v8sf __builtin_ia32_blendvps256 (v8sf,v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_cmpps256)
v8sf __builtin_ia32_cmpps256 (v8sf,v8sf,int);
#endif
#if !__has_builtin(__builtin_ia32_cvtdq2ps256)
v8sf __builtin_ia32_cvtdq2ps256 (v8si);
#endif
#if !__has_builtin(__builtin_ia32_divps256)
v8sf __builtin_ia32_divps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_dpps256)
v8sf __builtin_ia32_dpps256 (v8sf,v8sf,int);
#endif
#if !__has_builtin(__builtin_ia32_fmaddps256)
v8sf __builtin_ia32_fmaddps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_fmaddsubps256)
v8sf __builtin_ia32_fmaddsubps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_fmsubaddps256)
v8sf __builtin_ia32_fmsubaddps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_fmsubps256)
v8sf __builtin_ia32_fmsubps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_fnmaddps256)
v8sf __builtin_ia32_fnmaddps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_fnmsubps256)
v8sf __builtin_ia32_fnmsubps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_gathersiv8sf)
v8sf __builtin_ia32_gathersiv8sf (v8sf, pcfloat,v8si,v8sf,int);
#endif
#if !__has_builtin(__builtin_ia32_haddps256)
v8sf __builtin_ia32_haddps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_hsubps256)
v8sf __builtin_ia32_hsubps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_loadups256)
v8sf __builtin_ia32_loadups256 (pcfloat);
#endif
#if !__has_builtin(__builtin_ia32_maskloadps256)
v8sf __builtin_ia32_maskloadps256 (pcv8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_maxps256)
v8sf __builtin_ia32_maxps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_minps256)
v8sf __builtin_ia32_minps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_movshdup256)
v8sf __builtin_ia32_movshdup256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_movsldup256)
v8sf __builtin_ia32_movsldup256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_mulps256)
v8sf __builtin_ia32_mulps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_orps256)
v8sf __builtin_ia32_orps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_permvarsf256)
v8sf __builtin_ia32_permvarsf256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_ps256_ps)
v8sf __builtin_ia32_ps256_ps (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_rcpps256)
v8sf __builtin_ia32_rcpps256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_roundps256)
v8sf __builtin_ia32_roundps256 (v8sf,int);
#endif
#if !__has_builtin(__builtin_ia32_rsqrtps256)
v8sf __builtin_ia32_rsqrtps256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_rsqrtps_nr256)
v8sf __builtin_ia32_rsqrtps_nr256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_shufps256)
v8sf __builtin_ia32_shufps256 (v8sf,v8sf,int);
#endif
#if !__has_builtin(__builtin_ia32_sqrtps256)
v8sf __builtin_ia32_sqrtps256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_sqrtps_nr256)
v8sf __builtin_ia32_sqrtps_nr256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_subps256)
v8sf __builtin_ia32_subps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_unpckhps256)
v8sf __builtin_ia32_unpckhps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_unpcklps256)
v8sf __builtin_ia32_unpcklps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_vbroadcastf128_ps256)
v8sf __builtin_ia32_vbroadcastf128_ps256 (pcv4sf);
#endif
#if !__has_builtin(__builtin_ia32_vbroadcastss256)
v8sf __builtin_ia32_vbroadcastss256 (pcfloat);
#endif
#if !__has_builtin(__builtin_ia32_vbroadcastss_ps256)
v8sf __builtin_ia32_vbroadcastss_ps256 (v4sf);
#endif
#if !__has_builtin(__builtin_ia32_vfmaddps256)
v8sf __builtin_ia32_vfmaddps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_vfmaddsubps256)
v8sf __builtin_ia32_vfmaddsubps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_vfmsubaddps256)
v8sf __builtin_ia32_vfmsubaddps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_vfmsubps256)
v8sf __builtin_ia32_vfmsubps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_vfnmaddps256)
v8sf __builtin_ia32_vfnmaddps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_vfnmsubps256)
v8sf __builtin_ia32_vfnmsubps256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_vfrczps256)
v8sf __builtin_ia32_vfrczps256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_vinsertf128_ps256)
v8sf __builtin_ia32_vinsertf128_ps256 (v8sf,v4sf,int);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v8sf256)
v8sf __builtin_ia32_vpcmov_v8sf256 (v8sf, v8sf, v8sf);
#endif
#if !__has_builtin(__builtin_ia32_vperm2f128_ps256)
v8sf __builtin_ia32_vperm2f128_ps256 (v8sf,v8sf,int);
#endif
#if !__has_builtin(__builtin_ia32_vpermil2ps256)
v8sf __builtin_ia32_vpermil2ps256 (v8sf,v8sf,v8si,int);
#endif
#if !__has_builtin(__builtin_ia32_vpermilps256)
v8sf __builtin_ia32_vpermilps256 (v8sf,int);
#endif
#if !__has_builtin(__builtin_ia32_vpermilvarps256)
v8sf __builtin_ia32_vpermilvarps256 (v8sf,v8si);
#endif
#if !__has_builtin(__builtin_ia32_xorps256)
v8sf __builtin_ia32_xorps256 (v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_cvtps2dq256)
v8si __builtin_ia32_cvtps2dq256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_cvttps2dq256)
v8si __builtin_ia32_cvttps2dq256 (v8sf);
#endif
#if !__has_builtin(__builtin_ia32_gathersiv8si)
v8si __builtin_ia32_gathersiv8si (v8si, pcint,v8si,v8si,int);
#endif
#if !__has_builtin(__builtin_ia32_maskloadd256)
v8si __builtin_ia32_maskloadd256 (pcv8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pabsd256)
v8si __builtin_ia32_pabsd256 (v8si);
#endif
#if !__has_builtin(__builtin_ia32_paddd256)
v8si __builtin_ia32_paddd256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pblendd256)
v8si __builtin_ia32_pblendd256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pbroadcastd256)
v8si __builtin_ia32_pbroadcastd256 (v4si);
#endif
#if !__has_builtin(__builtin_ia32_pcmpeqd256)
v8si __builtin_ia32_pcmpeqd256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pcmpgtd256)
v8si __builtin_ia32_pcmpgtd256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_permvarsi256)
v8si __builtin_ia32_permvarsi256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_phaddd256)
v8si __builtin_ia32_phaddd256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_phsubd256)
v8si __builtin_ia32_phsubd256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pmaxsd256)
v8si __builtin_ia32_pmaxsd256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pmaxud256)
v8si __builtin_ia32_pmaxud256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pminsd256)
v8si __builtin_ia32_pminsd256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pminud256)
v8si __builtin_ia32_pminud256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxbd256)
v8si __builtin_ia32_pmovsxbd256 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovsxwd256)
v8si __builtin_ia32_pmovsxwd256 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxbd256)
v8si __builtin_ia32_pmovzxbd256 (v16qi);
#endif
#if !__has_builtin(__builtin_ia32_pmovzxwd256)
v8si __builtin_ia32_pmovzxwd256 (v8hi);
#endif
#if !__has_builtin(__builtin_ia32_pmulld256)
v8si __builtin_ia32_pmulld256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pshufd256)
v8si __builtin_ia32_pshufd256 (v8si,int);
#endif
#if !__has_builtin(__builtin_ia32_psignd256)
v8si __builtin_ia32_psignd256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_pslld256)
v8si __builtin_ia32_pslld256(v8si,v4si);
#endif
#if !__has_builtin(__builtin_ia32_pslldi256)
v8si __builtin_ia32_pslldi256 (v8si,int);
#endif
#if !__has_builtin(__builtin_ia32_psllv8si)
v8si __builtin_ia32_psllv8si (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_psrad256)
v8si __builtin_ia32_psrad256 (v8si,v4si);
#endif
#if !__has_builtin(__builtin_ia32_psradi256)
v8si __builtin_ia32_psradi256 (v8si,int);
#endif
#if !__has_builtin(__builtin_ia32_psrav8si)
v8si __builtin_ia32_psrav8si (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_psrld256)
v8si __builtin_ia32_psrld256 (v8si,v4si);
#endif
#if !__has_builtin(__builtin_ia32_psrldi256)
v8si __builtin_ia32_psrldi256 (v8si,int);
#endif
#if !__has_builtin(__builtin_ia32_psrlv8si)
v8si __builtin_ia32_psrlv8si (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_psubd256)
v8si __builtin_ia32_psubd256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_punpckhdq256)
v8si __builtin_ia32_punpckhdq256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_punpckldq256)
v8si __builtin_ia32_punpckldq256 (v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_si256_si)
v8si __builtin_ia32_si256_si (v4si);
#endif
#if !__has_builtin(__builtin_ia32_vinsertf128_si256)
v8si __builtin_ia32_vinsertf128_si256 (v8si,v4si,int);
#endif
#if !__has_builtin(__builtin_ia32_vpcmov_v8si256)
v8si __builtin_ia32_vpcmov_v8si256 (v8si, v8si, v8si);
#endif
#if !__has_builtin(__builtin_ia32_vperm2f128_si256)
v8si __builtin_ia32_vperm2f128_si256 (v8si,v8si,int);
#endif
#if !__has_builtin(__builtin_i32_clzero)
void __builtin_i32_clzero (void *);
#endif
#if !__has_builtin(__builtin_ia32_clflush)
void __builtin_ia32_clflush (const void *);
#endif
#if !__has_builtin(__builtin_ia32_clrssbsy)
void __builtin_ia32_clrssbsy(void *);
#endif
#if !__has_builtin(__builtin_ia32_femms)
void __builtin_ia32_femms (void);
#endif
#if !__has_builtin(__builtin_ia32_fxrstor)
void __builtin_ia32_fxrstor (void *);
#endif
#if !__has_builtin(__builtin_ia32_fxrstor64)
void __builtin_ia32_fxrstor64 (void *);
#endif
#if !__has_builtin(__builtin_ia32_fxsave)
void __builtin_ia32_fxsave (void *);
#endif
#if !__has_builtin(__builtin_ia32_fxsave64)
void __builtin_ia32_fxsave64 (void *);
#endif
#if !__has_builtin(__builtin_ia32_incsspd)
void __builtin_ia32_incsspd (unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_incsspq)
void __builtin_ia32_incsspq (unsigned long long);
#endif
#if !__has_builtin(__builtin_ia32_lfence)
void __builtin_ia32_lfence (void);
#endif
#if !__has_builtin(__builtin_ia32_llwpcb16)
void __builtin_ia32_llwpcb16 (void *);
#endif
#if !__has_builtin(__builtin_ia32_llwpcb32)
void __builtin_ia32_llwpcb32 (void *);
#endif
#if !__has_builtin(__builtin_ia32_llwpcb64)
void __builtin_ia32_llwpcb64 (void *);
#endif
#if !__has_builtin(__builtin_ia32_lwpval16)
void __builtin_ia32_lwpval16 (unsigned short, unsigned int, unsigned short);
#endif
#if !__has_builtin(__builtin_ia32_lwpval32)
void __builtin_ia32_lwpval32 (unsigned int, unsigned int, unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_lwpval64)
void __builtin_ia32_lwpval64 (unsigned __int64, unsigned int, unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_maskmovdqu)
void __builtin_ia32_maskmovdqu (v16qi, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_maskmovq)
void __builtin_ia32_maskmovq (v8qi, v8qi, char *);
#endif
#if !__has_builtin(__builtin_ia32_maskstored)
void __builtin_ia32_maskstored (pv4si,v4si,v4si);
#endif
#if !__has_builtin(__builtin_ia32_maskstored256)
void __builtin_ia32_maskstored256 (pv8si,v8si,v8si);
#endif
#if !__has_builtin(__builtin_ia32_maskstorepd)
void __builtin_ia32_maskstorepd (pv2df,v2df,v2df);
#endif
#if !__has_builtin(__builtin_ia32_maskstorepd256)
void __builtin_ia32_maskstorepd256 (pv4df,v4df,v4df);
#endif
#if !__has_builtin(__builtin_ia32_maskstoreps)
void __builtin_ia32_maskstoreps (pv4sf,v4sf,v4sf);
#endif
#if !__has_builtin(__builtin_ia32_maskstoreps256)
void __builtin_ia32_maskstoreps256 (pv8sf,v8sf,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_maskstoreq)
void __builtin_ia32_maskstoreq (pv2di,v2di,v2di);
#endif
#if !__has_builtin(__builtin_ia32_maskstoreq256)
void __builtin_ia32_maskstoreq256 (pv4di,v4di,v4di);
#endif
#if !__has_builtin(__builtin_ia32_mfence)
void __builtin_ia32_mfence (void);
#endif
#if !__has_builtin(__builtin_ia32_monitor)
void __builtin_ia32_monitor (void *, unsigned int, unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_monitorx)
void __builtin_ia32_monitorx (void *, unsigned int, unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_movntdq)
void __builtin_ia32_movntdq (v2df *, v2df);
#endif
#if !__has_builtin(__builtin_ia32_movnti)
void __builtin_ia32_movnti (int *, int);
#endif
#if !__has_builtin(__builtin_ia32_movnti64)
void __builtin_ia32_movnti64 (long long int *, long long int);
#endif
#if !__has_builtin(__builtin_ia32_movntpd)
void __builtin_ia32_movntpd (double *, v2df);
#endif
#if !__has_builtin(__builtin_ia32_movntps)
void __builtin_ia32_movntps (float *, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_movntq)
void __builtin_ia32_movntq (di *, di);
#endif
#if !__has_builtin(__builtin_ia32_movntsd)
void __builtin_ia32_movntsd (double *, v2df);
#endif
#if !__has_builtin(__builtin_ia32_movntss)
void __builtin_ia32_movntss (float *, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_mwait)
void __builtin_ia32_mwait (unsigned int, unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_mwaitx)
void __builtin_ia32_mwaitx (unsigned int, unsigned int, unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_pause)
void __builtin_ia32_pause (void);
#endif
#if !__has_builtin(__builtin_ia32_ptwrite32)
void __builtin_ia32_ptwrite32 (unsigned);
#endif
#if !__has_builtin(__builtin_ia32_ptwrite64)
void __builtin_ia32_ptwrite64 (unsigned long long);
#endif
#if !__has_builtin(__builtin_ia32_rstorssp)
void __builtin_ia32_rstorssp(void *);
#endif
#if !__has_builtin(__builtin_ia32_saveprevssp)
void __builtin_ia32_saveprevssp(void);
#endif
#if !__has_builtin(__builtin_ia32_setssbsy)
void __builtin_ia32_setssbsy(void);
#endif
#if !__has_builtin(__builtin_ia32_sfence)
void __builtin_ia32_sfence (void);
#endif
#if !__has_builtin(__builtin_ia32_storeaps)
void __builtin_ia32_storeaps (float *, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_storedqu)
void __builtin_ia32_storedqu (char *, v16qi);
#endif
#if !__has_builtin(__builtin_ia32_storedqu256)
void __builtin_ia32_storedqu256 (pchar,v32qi);
#endif
#if !__has_builtin(__builtin_ia32_storehps)
void __builtin_ia32_storehps (v2sf *, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_storelps)
void __builtin_ia32_storelps (v2sf *, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_storess)
void __builtin_ia32_storess (float *, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_storeupd)
void __builtin_ia32_storeupd (double *, v2df);
#endif
#if !__has_builtin(__builtin_ia32_storeupd256)
void __builtin_ia32_storeupd256 (pdouble,v4df);
#endif
#if !__has_builtin(__builtin_ia32_storeups)
void __builtin_ia32_storeups (float *, v4sf);
#endif
#if !__has_builtin(__builtin_ia32_storeups256)
void __builtin_ia32_storeups256 (pfloat,v8sf);
#endif
#if !__has_builtin(__builtin_ia32_vzeroall)
void __builtin_ia32_vzeroall (void);
#endif
#if !__has_builtin(__builtin_ia32_vzeroupper)
void __builtin_ia32_vzeroupper (void);
#endif
#if !__has_builtin(__builtin_ia32_wrpkru)
void __builtin_ia32_wrpkru (unsigned int);
#endif
#if !__has_builtin(__builtin_ia32_wrssd)
void __builtin_ia32_wrssd(unsigned int, void *);
#endif
#if !__has_builtin(__builtin_ia32_wrssq)
void __builtin_ia32_wrssq(unsigned long long, void *);
#endif
#if !__has_builtin(__builtin_ia32_wrussd)
void __builtin_ia32_wrussd(unsigned int, void *);
#endif
#if !__has_builtin(__builtin_ia32_wrussq)
void __builtin_ia32_wrussq(unsigned long long, void *);
#endif
#if !__has_builtin(__builtin_ia32_xabort)
void __builtin_ia32_xabort (unsigned);
#endif
#if !__has_builtin(__builtin_ia32_xend)
void __builtin_ia32_xend ();
#endif
#if !__has_builtin(__builtin_ia32_xrstor)
void __builtin_ia32_xrstor (void *, long long);
#endif
#if !__has_builtin(__builtin_ia32_xrstor64)
void __builtin_ia32_xrstor64 (void *, long long);
#endif
#if !__has_builtin(__builtin_ia32_xsave)
void __builtin_ia32_xsave (void *, long long);
#endif
#if !__has_builtin(__builtin_ia32_xsave64)
void __builtin_ia32_xsave64 (void *, long long);
#endif
#if !__has_builtin(__builtin_ia32_xsaveopt)
void __builtin_ia32_xsaveopt (void *, long long);
#endif
#if !__has_builtin(__builtin_ia32_xsaveopt64)
void __builtin_ia32_xsaveopt64 (void *, long long);
#endif

#undef pcfloat
#undef pcdouble
#undef pcv2df
#undef pcv2di
#undef pcint64
#undef pcchar
#undef pcv4df
#undef pcv4di
#undef pv4di
#undef pcv4sf
#undef pcint
#undef pchar
#undef pdouble
#undef pfloat
#undef pcv4si
#undef pv4si
#undef pv2di
#undef pcv8sf
#undef pcv8si
#undef pv8si
#undef pv2df
#undef pv4df
#undef pv4sf
#undef pv8sf
#undef ptest

#ifdef __cplusplus
}  // extern C
#endif
