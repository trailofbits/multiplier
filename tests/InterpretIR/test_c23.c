// Tests: C23-specific features — true/false keywords, typeof,
// constexpr, u8 character literals, nullptr, auto type inference,
// digit separators, binary literals, static_assert without message.

/*
 * Expected IR:
 *
 * function test_c23 (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=1 align=1 (b1)
 *     obj_1 LOCAL_VALUE size=1 align=1 (b2)
 *     obj_2 LOCAL_VALUE size=4 align=4 (x)
 *     obj_3 LOCAL_VALUE size=4 align=4 (y)
 *     obj_4 LOCAL_VALUE size=4 align=4 (bin)
 *     obj_5 LOCAL_VALUE size=4 align=4 (big)
 *     obj_6 LOCAL_VALUE size=8 align=8 (np)
 *     obj_7 LOCAL_VALUE size=1 align=1 (u8c)
 *     obj_8 LOCAL_VALUE size=4 align=4 (z)
 *     obj_9 LOCAL_VALUE size=8 align=8 (ull)
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %b1.0 = ALLOCA/LOCAL size=1 align=1
 *     >> %b2.1 = ALLOCA/LOCAL size=1 align=1
 *     >> %x.2 = ALLOCA/LOCAL size=4 align=4
 *     >> %y.3 = ALLOCA/LOCAL size=4 align=4
 *     >> %bin.4 = ALLOCA/LOCAL size=4 align=4
 *     >> %big.5 = ALLOCA/LOCAL size=4 align=4
 *     >> %np.6 = ALLOCA/LOCAL size=8 align=8
 *     >> %u8c.7 = ALLOCA/LOCAL size=1 align=1
 *     >> %z.8 = ALLOCA/LOCAL size=4 align=4
 *     >> %ull.9 = ALLOCA/LOCAL size=8 align=8
 *     >> %10 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %11 = ENTER_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *          %b1.0 = ALLOCA/LOCAL size=1 align=1
 *          %12 = CONST/BOOL 1  // true
 *     >> %b1.13 = MEMORY/STORE_LE_8 [%b1.0, %12]
 *          %b2.1 = ALLOCA/LOCAL size=1 align=1
 *          %14 = CONST/BOOL 0  // false
 *     >> %b2.15 = MEMORY/STORE_LE_8 [%b2.1, %14]
 *          %16 = MEMORY/LOAD_LE_8 [%b1.0]  // b1
 *          %17 = CAST/ZEXT_I8_I32 [%16]  // b1
 *          %18 = CONST/INT32 1  // 1
 *          %19 = CMP_NE [%17, %18]  // b1 != 1
 *     >> %20 = COND_BRANCH [%19]  // if (b1 != 1) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %26 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %b2.1 = ALLOCA/LOCAL size=1 align=1
 *          %27 = MEMORY/LOAD_LE_8 [%b2.1]  // b2
 *          %28 = CAST/ZEXT_I8_I32 [%27]  // b2
 *          %29 = CONST/INT32 0  // 0
 *          %30 = CMP_NE [%28, %29]  // b2 != 0
 *     >> %31 = COND_BRANCH [%30]  // if (b2 != 0) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %37 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %x.2 = ALLOCA/LOCAL size=4 align=4
 *          %38 = CONST/INT32 42  // 42
 *     >> %x.39 = MEMORY/STORE_LE_32 [%x.2, %38]
 *          %y.3 = ALLOCA/LOCAL size=4 align=4
 *          %40 = MEMORY/LOAD_LE_32 [%x.2]  // x
 *          %41 = CONST/INT32 1  // 1
 *          %42 = ADD [%40, %41]  // x + 1
 *     >> %y.43 = MEMORY/STORE_LE_32 [%y.3, %42]
 *          %44 = MEMORY/LOAD_LE_32 [%y.3]  // y
 *          %45 = CONST/INT32 43  // 43
 *          %46 = CMP_NE [%44, %45]  // y != 43
 *     >> %47 = COND_BRANCH [%46]  // if (y != 43) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %53 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %bin.4 = ALLOCA/LOCAL size=4 align=4
 *          %54 = CONST/INT32 170  // 0b10101010
 *     >> %bin.55 = MEMORY/STORE_LE_32 [%bin.4, %54]
 *          %56 = MEMORY/LOAD_LE_32 [%bin.4]  // bin
 *          %57 = CONST/INT32 170  // 170
 *          %58 = CMP_NE [%56, %57]  // bin != 170
 *     >> %59 = COND_BRANCH [%58]  // if (bin != 170) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %65 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %big.5 = ALLOCA/LOCAL size=4 align=4
 *          %66 = CONST/INT32 1000000  // 1'000'000
 *     >> %big.67 = MEMORY/STORE_LE_32 [%big.5, %66]
 *          %68 = MEMORY/LOAD_LE_32 [%big.5]  // big
 *          %69 = CONST/INT32 1000000  // 1000000
 *          %70 = CMP_NE [%68, %69]  // big != 1000000
 *     >> %71 = COND_BRANCH [%70]  // if (big != 1000000) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %77 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %np.6 = ALLOCA/LOCAL size=8 align=8
 *          %78 = CONST/NULL_PTR  // nullptr
 *     >> %np.79 = MEMORY/STORE_LE_64 [%np.6, %78]
 *          %80 = MEMORY/LOAD_LE_64 [%np.6]  // np
 *          %81 = CONST/NULL_PTR  // 0
 *          %82 = CMP_NE [%80, %81]  // np != 0
 *     >> %83 = COND_BRANCH [%82]  // if (np != 0) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %89 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %u8c.7 = ALLOCA/LOCAL size=1 align=1
 *          %90 = CONST/UINT8 65  // u8'A'
 *     >> %u8c.91 = MEMORY/STORE_LE_8 [%u8c.7, %90]
 *          %92 = MEMORY/LOAD_LE_8 [%u8c.7]  // u8c
 *          %93 = CAST/ZEXT_I8_I32 [%92]  // u8c
 *          %94 = CONST/INT32 65  // 65
 *          %95 = CMP_NE [%93, %94]  // u8c != 65
 *     >> %96 = COND_BRANCH [%95]  // if (u8c != 65) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %102 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %z.8 = ALLOCA/LOCAL size=4 align=4
 *          %103 = CONST/INT32 100  // 100
 *     >> %z.104 = MEMORY/STORE_LE_32 [%z.8, %103]
 *          %105 = MEMORY/LOAD_LE_32 [%z.8]  // z
 *          %106 = CONST/INT32 100  // 100
 *          %107 = CMP_NE [%105, %106]  // z != 100
 *     >> %108 = COND_BRANCH [%107]  // if (z != 100) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %114 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %ull.9 = ALLOCA/LOCAL size=8 align=8
 *          %115 = CONST/UINT32 4294967295  // 0xFF'FF'FF'FF
 *          %116 = CAST/ZEXT_I32_I64 [%115]  // 0xFF'FF'FF'FF
 *     >> %ull.117 = MEMORY/STORE_LE_64 [%ull.9, %116]
 *          %118 = MEMORY/LOAD_LE_64 [%ull.9]  // ull
 *          %119 = CONST/UINT64 4294967295  // 4294967295ULL
 *          %120 = CMP_NE [%118, %119]  // ull != 4294967295ULL
 *     >> %121 = COND_BRANCH [%120]  // if (ull != 4294967295ULL) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %127 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %129 = RETURN_PTR  // return 0
 *          %128 = CONST/INT32 0  // 0
 *     >> %130 = MEMORY/STORE_LE_32 [%129, %128]  // return 0
 *     >> %131 = EXIT_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *     >> %132 = RET [%128]  // return 0
 *   block_26 IF_THEN  <- [block_25]:
 *          %123 = RETURN_PTR  // return 9
 *          %122 = CONST/INT32 9  // 9
 *     >> %124 = MEMORY/STORE_LE_32 [%123, %122]  // return 9
 *     >> %125 = EXIT_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *     >> %126 = RET [%122]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %110 = RETURN_PTR  // return 8
 *          %109 = CONST/INT32 8  // 8
 *     >> %111 = MEMORY/STORE_LE_32 [%110, %109]  // return 8
 *     >> %112 = EXIT_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *     >> %113 = RET [%109]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %98 = RETURN_PTR  // return 7
 *          %97 = CONST/INT32 7  // 7
 *     >> %99 = MEMORY/STORE_LE_32 [%98, %97]  // return 7
 *     >> %100 = EXIT_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *     >> %101 = RET [%97]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %85 = RETURN_PTR  // return 6
 *          %84 = CONST/INT32 6  // 6
 *     >> %86 = MEMORY/STORE_LE_32 [%85, %84]  // return 6
 *     >> %87 = EXIT_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *     >> %88 = RET [%84]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %73 = RETURN_PTR  // return 5
 *          %72 = CONST/INT32 5  // 5
 *     >> %74 = MEMORY/STORE_LE_32 [%73, %72]  // return 5
 *     >> %75 = EXIT_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *     >> %76 = RET [%72]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %61 = RETURN_PTR  // return 4
 *          %60 = CONST/INT32 4  // 4
 *     >> %62 = MEMORY/STORE_LE_32 [%61, %60]  // return 4
 *     >> %63 = EXIT_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *     >> %64 = RET [%60]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %49 = RETURN_PTR  // return 3
 *          %48 = CONST/INT32 3  // 3
 *     >> %50 = MEMORY/STORE_LE_32 [%49, %48]  // return 3
 *     >> %51 = EXIT_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *     >> %52 = RET [%48]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %33 = RETURN_PTR  // return 2
 *          %32 = CONST/INT32 2  // 2
 *     >> %34 = MEMORY/STORE_LE_32 [%33, %32]  // return 2
 *     >> %35 = EXIT_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *     >> %36 = RET [%32]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %22 = RETURN_PTR  // return 1
 *          %21 = CONST/INT32 1  // 1
 *     >> %23 = MEMORY/STORE_LE_32 [%22, %21]  // return 1
 *     >> %24 = EXIT_SCOPE  // {     // true/false are keywords in C23 (not ma...
 *     >> %25 = RET [%21]  // return 1
 * }
 */


#include <stddef.h>

int test_c23(void) {
    // true/false are keywords in C23 (not macros from stdbool.h).
    bool b1 = true;
    bool b2 = false;
    if (b1 != 1) return 1;
    if (b2 != 0) return 2;

    // typeof (C23 keyword, was GNU extension).
    int x = 42;
    typeof(x) y = x + 1;
    if (y != 43) return 3;

    // Binary literals (0b prefix).
    int bin = 0b10101010;
    if (bin != 170) return 4;

    // Digit separators.
    int big = 1'000'000;
    if (big != 1000000) return 5;

    // static_assert without message (C23).
    static_assert(sizeof(int) >= 4);

    // nullptr (C23).
    int *np = nullptr;
    if (np != 0) return 6;

    // u8 character literal (C23 — produces unsigned char value).
    unsigned char u8c = u8'A';
    if (u8c != 65) return 7;

    // auto type inference (C23).
    auto z = 100;
    if (z != 100) return 8;

    // Underscore in numeric literals.
    unsigned long long ull = 0xFF'FF'FF'FF;
    if (ull != 4294967295ULL) return 9;

    return 0;
}
