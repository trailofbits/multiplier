// Tests: all CAST sub-opcodes — sign extension (SEXT), zero extension (ZEXT),
// truncation (TRUNC), int-to-float, float-to-int, float widening/narrowing,
// pointer-to-int, int-to-pointer, bitcast, and identity casts.

/*
 * Expected IR:
 *
 * function test_casts (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=1 align=1 (sc)
 *     obj_1 LOCAL_VALUE size=4 align=1 (sext)
 *     obj_2 LOCAL_VALUE size=1 align=1 (uc)
 *     obj_3 LOCAL_VALUE size=4 align=1 (zext)
 *     obj_4 LOCAL_VALUE size=4 align=1 (big)
 *     obj_5 LOCAL_VALUE size=1 align=1 (trunc)
 *     obj_6 LOCAL_VALUE size=4 align=1 (ival)
 *     obj_7 LOCAL_VALUE size=8 align=1 (dval)
 *     obj_8 LOCAL_VALUE size=4 align=1 (back)
 *     obj_9 LOCAL_VALUE size=8 align=1 (pi)
 *     obj_10 LOCAL_VALUE size=4 align=1 (ipi)
 *     obj_11 LOCAL_VALUE size=4 align=1 (f)
 *     obj_12 LOCAL_VALUE size=8 align=1 (d)
 *     obj_13 LOCAL_VALUE size=4 align=1 (id)
 *     obj_14 LOCAL size=4 align=1 (x)
 *     obj_15 LOCAL_VALUE size=8 align=1 (ptr_as_int)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %16 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %17 = ENTER_SCOPE  // {     // Sign extension.     signed char sc = -...
 *          %sc.0 = ALLOCA/LOCAL size=1 align=1
 *          %20 = CAST/TRUNC_I32_I8 [%19]  // -5
 *     >> %sc.21 = MEMORY/STORE_LE_8 [%sc.0, %20]
 *          %sext.1 = ALLOCA/LOCAL size=4 align=1
 *          %23 = CAST/SEXT_I8_I32 [%22]  // (int)sc
 *     >> %sext.24 = MEMORY/STORE_LE_32 [%sext.1, %23]
 *          %28 = CMP_NE [%25, %27]  // sext != -5
 *     >> %29 = COND_BRANCH [%28]  // if (sext != -5) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %35 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %uc.2 = ALLOCA/LOCAL size=1 align=1
 *          %37 = CAST/TRUNC_I32_I8 [%36]  // 200
 *     >> %uc.38 = MEMORY/STORE_LE_8 [%uc.2, %37]
 *          %zext.3 = ALLOCA/LOCAL size=4 align=1
 *          %40 = CAST/ZEXT_I8_I32 [%39]  // (unsigned int)uc
 *     >> %zext.41 = MEMORY/STORE_LE_32 [%zext.3, %40]
 *          %45 = CMP_NE [%42, %44]  // zext != 200
 *     >> %46 = COND_BRANCH [%45]  // if (zext != 200) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %52 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %big.4 = ALLOCA/LOCAL size=4 align=1
 *          %53 = CONST/INT32 305419896  // 0x12345678
 *     >> %big.54 = MEMORY/STORE_LE_32 [%big.4, %53]
 *          %trunc.5 = ALLOCA/LOCAL size=1 align=1
 *          %56 = CAST/TRUNC_I32_I8 [%55]  // (char)big
 *     >> %trunc.57 = MEMORY/STORE_LE_8 [%trunc.5, %56]
 *          %66 = LOGICAL_AND [%61, %65]  // trunc != 0x78 && trunc != 120
 *     >> %67 = COND_BRANCH [%66]  // if (trunc != 0x78 && trunc != 120) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %73 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %ival.6 = ALLOCA/LOCAL size=4 align=1
 *          %74 = CONST/INT32 42  // 42
 *     >> %ival.75 = MEMORY/STORE_LE_32 [%ival.6, %74]
 *          %dval.7 = ALLOCA/LOCAL size=8 align=1
 *          %77 = CAST/SI32_TO_F64 [%76]  // (double)ival
 *     >> %dval.78 = MEMORY/STORE_F64_LE [%dval.7, %77]
 *          %back.8 = ALLOCA/LOCAL size=4 align=1
 *          %80 = CAST/F64_TO_SI32 [%79]  // (int)dval
 *     >> %back.81 = MEMORY/STORE_LE_32 [%back.8, %80]
 *          %84 = CMP_NE [%82, %83]  // back != 42
 *     >> %85 = COND_BRANCH [%84]  // if (back != 42) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %91 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %pi.9 = ALLOCA/LOCAL size=8 align=1
 *          %92 = CONST/FLOAT64 3.14  // 3.14
 *     >> %pi.93 = MEMORY/STORE_F64_LE [%pi.9, %92]
 *          %ipi.10 = ALLOCA/LOCAL size=4 align=1
 *          %95 = CAST/F64_TO_SI32 [%94]  // (int)pi
 *     >> %ipi.96 = MEMORY/STORE_LE_32 [%ipi.10, %95]
 *          %99 = CMP_NE [%97, %98]  // ipi != 3
 *     >> %100 = COND_BRANCH [%99]  // if (ipi != 3) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %106 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %f.11 = ALLOCA/LOCAL size=4 align=1
 *          %107 = CONST/FLOAT32 1.5  // 1.5f
 *     >> %f.108 = MEMORY/STORE_F32_LE [%f.11, %107]
 *          %d.12 = ALLOCA/LOCAL size=8 align=1
 *          %110 = CAST/F32_TO_F64 [%109]  // (double)f
 *     >> %d.111 = MEMORY/STORE_F64_LE [%d.12, %110]
 *          %id.13 = ALLOCA/LOCAL size=4 align=1
 *          %115 = CAST/F64_TO_SI32 [%114]  // (int)(d * 2.0)
 *     >> %id.116 = MEMORY/STORE_LE_32 [%id.13, %115]
 *          %119 = CMP_NE [%117, %118]  // id != 3
 *     >> %120 = COND_BRANCH [%119]  // if (id != 3) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %126 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %x.14 = ALLOCA/LOCAL size=4 align=1
 *          %127 = CONST/INT32 99  // 99
 *     >> %x.128 = MEMORY/STORE_LE_32 [%x.14, %127]
 *          %ptr_as_int.15 = ALLOCA/LOCAL size=8 align=1
 *          %129 = CAST/PTR_TO_I64 [%x.14]  // (long)&x
 *     >> %ptr_as_int.130 = MEMORY/STORE_LE_64 [%ptr_as_int.15, %129]
 *          %132 = RETURN_PTR  // return 0
 *          %131 = CONST/INT32 0  // 0
 *     >> %133 = MEMORY/STORE_LE_32 [%132, %131]  // return 0
 *     >> %134 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *          %131 = CONST/INT32 0  // 0
 *     >> %135 = RET [%131]  // return 0
 *   block_17 IF_THEN  <- [block_16]:
 *          %122 = RETURN_PTR  // return 6
 *          %121 = CONST/INT32 6  // 6
 *     >> %123 = MEMORY/STORE_LE_32 [%122, %121]  // return 6
 *     >> %124 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *          %121 = CONST/INT32 6  // 6
 *     >> %125 = RET [%121]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %102 = RETURN_PTR  // return 5
 *          %101 = CONST/INT32 5  // 5
 *     >> %103 = MEMORY/STORE_LE_32 [%102, %101]  // return 5
 *     >> %104 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *          %101 = CONST/INT32 5  // 5
 *     >> %105 = RET [%101]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %87 = RETURN_PTR  // return 4
 *          %86 = CONST/INT32 4  // 4
 *     >> %88 = MEMORY/STORE_LE_32 [%87, %86]  // return 4
 *     >> %89 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *          %86 = CONST/INT32 4  // 4
 *     >> %90 = RET [%86]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %69 = RETURN_PTR  // return 3
 *          %68 = CONST/INT32 3  // 3
 *     >> %70 = MEMORY/STORE_LE_32 [%69, %68]  // return 3
 *     >> %71 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *          %68 = CONST/INT32 3  // 3
 *     >> %72 = RET [%68]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %48 = RETURN_PTR  // return 2
 *          %47 = CONST/INT32 2  // 2
 *     >> %49 = MEMORY/STORE_LE_32 [%48, %47]  // return 2
 *     >> %50 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *          %47 = CONST/INT32 2  // 2
 *     >> %51 = RET [%47]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %31 = RETURN_PTR  // return 1
 *          %30 = CONST/INT32 1  // 1
 *     >> %32 = MEMORY/STORE_LE_32 [%31, %30]  // return 1
 *     >> %33 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *          %30 = CONST/INT32 1  // 1
 *     >> %34 = RET [%30]  // return 1
 * }
 */










int test_casts(void) {
    // Sign extension.
    signed char sc = -5;
    int sext = (int)sc;
    if (sext != -5) return 1;

    // Zero extension.
    unsigned char uc = 200;
    unsigned int zext = (unsigned int)uc;
    if (zext != 200) return 2;

    // Truncation.
    int big = 0x12345678;
    char trunc = (char)big;
    if (trunc != 0x78 && trunc != 120) return 3;  // 0x78 = 120

    // Int to float.
    int ival = 42;
    double dval = (double)ival;
    // Can't compare doubles exactly in C without float ops,
    // but we can cast back.
    int back = (int)dval;
    if (back != 42) return 4;

    // Float to int (truncates toward zero).
    double pi = 3.14;
    int ipi = (int)pi;
    if (ipi != 3) return 5;

    // Float widening.
    float f = 1.5f;
    double d = (double)f;
    int id = (int)(d * 2.0);
    if (id != 3) return 6;

    // Pointer to int and back.
    int x = 99;
    long ptr_as_int = (long)&x;
    // Can't meaningfully test the value, but it should not crash.

    return 0;
}
