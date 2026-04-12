// Tests: all CAST sub-opcodes — sign extension (SEXT), zero extension (ZEXT),
// truncation (TRUNC), int-to-float, float-to-int, float widening/narrowing,
// pointer-to-int, int-to-pointer, bitcast, and identity casts.

/*
 * Expected IR:
 *
 * function test_casts (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=1 align=1 (sc)
 *     obj_1 LOCAL_VALUE size=4 align=4 (sext)
 *     obj_2 LOCAL_VALUE size=1 align=1 (uc)
 *     obj_3 LOCAL_VALUE size=4 align=4 (zext)
 *     obj_4 LOCAL_VALUE size=4 align=4 (big)
 *     obj_5 LOCAL_VALUE size=1 align=1 (trunc)
 *     obj_6 LOCAL_VALUE size=4 align=4 (ival)
 *     obj_7 LOCAL_VALUE size=8 align=8 (dval)
 *     obj_8 LOCAL_VALUE size=4 align=4 (back)
 *     obj_9 LOCAL_VALUE size=8 align=8 (pi)
 *     obj_10 LOCAL_VALUE size=4 align=4 (ipi)
 *     obj_11 LOCAL_VALUE size=4 align=4 (f)
 *     obj_12 LOCAL_VALUE size=8 align=8 (d)
 *     obj_13 LOCAL_VALUE size=4 align=4 (id)
 *     obj_14 LOCAL size=4 align=4 (x)
 *     obj_15 LOCAL_VALUE size=8 align=8 (ptr_as_int)
 *     obj_16 LOCAL_VALUE size=8 align=8 (a)
 *     obj_17 LOCAL_VALUE size=8 align=8 (b)
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %sc.0 = ALLOCA/LOCAL size=1 align=1
 *     >> %sext.1 = ALLOCA/LOCAL size=4 align=4
 *     >> %uc.2 = ALLOCA/LOCAL size=1 align=1
 *     >> %zext.3 = ALLOCA/LOCAL size=4 align=4
 *     >> %big.4 = ALLOCA/LOCAL size=4 align=4
 *     >> %trunc.5 = ALLOCA/LOCAL size=1 align=1
 *     >> %ival.6 = ALLOCA/LOCAL size=4 align=4
 *     >> %dval.7 = ALLOCA/LOCAL size=8 align=8
 *     >> %back.8 = ALLOCA/LOCAL size=4 align=4
 *     >> %pi.9 = ALLOCA/LOCAL size=8 align=8
 *     >> %ipi.10 = ALLOCA/LOCAL size=4 align=4
 *     >> %f.11 = ALLOCA/LOCAL size=4 align=4
 *     >> %d.12 = ALLOCA/LOCAL size=8 align=8
 *     >> %id.13 = ALLOCA/LOCAL size=4 align=4
 *     >> %x.14 = ALLOCA/LOCAL size=4 align=4
 *     >> %ptr_as_int.15 = ALLOCA/LOCAL size=8 align=8
 *     >> %a.16 = ALLOCA/LOCAL size=8 align=8
 *     >> %b.17 = ALLOCA/LOCAL size=8 align=8
 *     >> %18 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %19 = ENTER_SCOPE  // {     // Sign extension.     signed char sc = -...
 *          %sc.0 = ALLOCA/LOCAL size=1 align=1
 *          %20 = CONST/INT32 5  // 5
 *          %21 = NEG [%20]  // -5
 *          %22 = CAST/TRUNC_I32_I8 [%21]  // -5
 *     >> %sc.23 = MEMORY/STORE_LE_8 [%sc.0, %22]
 *          %sext.1 = ALLOCA/LOCAL size=4 align=4
 *          %24 = MEMORY/LOAD_LE_8 [%sc.0]  // sc
 *          %25 = CAST/SEXT_I8_I32 [%24]  // (int)sc
 *     >> %sext.26 = MEMORY/STORE_LE_32 [%sext.1, %25]
 *          %27 = MEMORY/LOAD_LE_32 [%sext.1]  // sext
 *          %28 = CONST/INT32 5  // 5
 *          %29 = NEG [%28]  // -5
 *          %30 = CMP_NE [%27, %29]  // sext != -5
 *     >> %31 = COND_BRANCH [%30]  // if (sext != -5) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %37 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %uc.2 = ALLOCA/LOCAL size=1 align=1
 *          %38 = CONST/INT32 200  // 200
 *          %39 = CAST/TRUNC_I32_I8 [%38]  // 200
 *     >> %uc.40 = MEMORY/STORE_LE_8 [%uc.2, %39]
 *          %zext.3 = ALLOCA/LOCAL size=4 align=4
 *          %41 = MEMORY/LOAD_LE_8 [%uc.2]  // uc
 *          %42 = CAST/ZEXT_I8_I32 [%41]  // (unsigned int)uc
 *     >> %zext.43 = MEMORY/STORE_LE_32 [%zext.3, %42]
 *          %44 = MEMORY/LOAD_LE_32 [%zext.3]  // zext
 *          %45 = CONST/INT32 200  // 200
 *          %46 = CAST/IDENTITY [%45]  // 200
 *          %47 = CMP_NE [%44, %46]  // zext != 200
 *     >> %48 = COND_BRANCH [%47]  // if (zext != 200) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %54 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %big.4 = ALLOCA/LOCAL size=4 align=4
 *          %55 = CONST/INT32 305419896  // 0x12345678
 *     >> %big.56 = MEMORY/STORE_LE_32 [%big.4, %55]
 *          %trunc.5 = ALLOCA/LOCAL size=1 align=1
 *          %57 = MEMORY/LOAD_LE_32 [%big.4]  // big
 *          %58 = CAST/TRUNC_I32_I8 [%57]  // (char)big
 *     >> %trunc.59 = MEMORY/STORE_LE_8 [%trunc.5, %58]
 *          %60 = MEMORY/LOAD_LE_8 [%trunc.5]  // trunc
 *          %61 = CAST/SEXT_I8_I32 [%60]  // trunc
 *          %62 = CONST/INT32 120  // 0x78
 *          %63 = CMP_NE [%61, %62]  // trunc != 0x78
 *          %64 = MEMORY/LOAD_LE_8 [%trunc.5]  // trunc
 *          %65 = CAST/SEXT_I8_I32 [%64]  // trunc
 *          %66 = CONST/INT32 120  // 120
 *          %67 = CMP_NE [%65, %66]  // trunc != 120
 *          %68 = LOGICAL_AND [%63, %67]  // trunc != 0x78 && trunc != 120
 *     >> %69 = COND_BRANCH [%68]  // if (trunc != 0x78 && trunc != 120) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %75 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %ival.6 = ALLOCA/LOCAL size=4 align=4
 *          %76 = CONST/INT32 42  // 42
 *     >> %ival.77 = MEMORY/STORE_LE_32 [%ival.6, %76]
 *          %dval.7 = ALLOCA/LOCAL size=8 align=8
 *          %78 = MEMORY/LOAD_LE_32 [%ival.6]  // ival
 *          %79 = CAST/SI32_TO_F64 [%78]  // (double)ival
 *     >> %dval.80 = MEMORY/STORE_F64_LE [%dval.7, %79]
 *          %back.8 = ALLOCA/LOCAL size=4 align=4
 *          %81 = MEMORY/LOAD_F64_LE [%dval.7]  // dval
 *          %82 = CAST/F64_TO_SI32 [%81]  // (int)dval
 *     >> %back.83 = MEMORY/STORE_LE_32 [%back.8, %82]
 *          %84 = MEMORY/LOAD_LE_32 [%back.8]  // back
 *          %85 = CONST/INT32 42  // 42
 *          %86 = CMP_NE [%84, %85]  // back != 42
 *     >> %87 = COND_BRANCH [%86]  // if (back != 42) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %93 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %pi.9 = ALLOCA/LOCAL size=8 align=8
 *          %94 = CONST/FLOAT64 3.14  // 3.14
 *     >> %pi.95 = MEMORY/STORE_F64_LE [%pi.9, %94]
 *          %ipi.10 = ALLOCA/LOCAL size=4 align=4
 *          %96 = MEMORY/LOAD_F64_LE [%pi.9]  // pi
 *          %97 = CAST/F64_TO_SI32 [%96]  // (int)pi
 *     >> %ipi.98 = MEMORY/STORE_LE_32 [%ipi.10, %97]
 *          %99 = MEMORY/LOAD_LE_32 [%ipi.10]  // ipi
 *          %100 = CONST/INT32 3  // 3
 *          %101 = CMP_NE [%99, %100]  // ipi != 3
 *     >> %102 = COND_BRANCH [%101]  // if (ipi != 3) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %108 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %f.11 = ALLOCA/LOCAL size=4 align=4
 *          %109 = CONST/FLOAT32 1.5  // 1.5f
 *     >> %f.110 = MEMORY/STORE_F32_LE [%f.11, %109]
 *          %d.12 = ALLOCA/LOCAL size=8 align=8
 *          %111 = MEMORY/LOAD_F32_LE [%f.11]  // f
 *          %112 = CAST/F32_TO_F64 [%111]  // (double)f
 *     >> %d.113 = MEMORY/STORE_F64_LE [%d.12, %112]
 *          %id.13 = ALLOCA/LOCAL size=4 align=4
 *          %114 = MEMORY/LOAD_F64_LE [%d.12]  // d
 *          %115 = CONST/FLOAT64 2  // 2.0
 *          %116 = FMUL_64 [%114, %115]  // d * 2.0
 *          %117 = CAST/F64_TO_SI32 [%116]  // (int)(d * 2.0)
 *     >> %id.118 = MEMORY/STORE_LE_32 [%id.13, %117]
 *          %119 = MEMORY/LOAD_LE_32 [%id.13]  // id
 *          %120 = CONST/INT32 3  // 3
 *          %121 = CMP_NE [%119, %120]  // id != 3
 *     >> %122 = COND_BRANCH [%121]  // if (id != 3) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %128 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %x.14 = ALLOCA/LOCAL size=4 align=4
 *          %129 = CONST/INT32 99  // 99
 *     >> %x.130 = MEMORY/STORE_LE_32 [%x.14, %129]
 *          %ptr_as_int.15 = ALLOCA/LOCAL size=8 align=8
 *          %131 = CAST/PTR_TO_I64 [%x.14]  // (long)&x
 *     >> %ptr_as_int.132 = MEMORY/STORE_LE_64 [%ptr_as_int.15, %131]
 *          %a.16 = ALLOCA/LOCAL size=8 align=8
 *          %133 = CONST/FLOAT64 3.14  // 3.14
 *     >> %a.134 = MEMORY/STORE_F64_LE [%a.16, %133]
 *          %b.17 = ALLOCA/LOCAL size=8 align=8
 *          %135 = CONST/FLOAT64 2.71  // 2.71
 *     >> %b.136 = MEMORY/STORE_F64_LE [%b.17, %135]
 *          %137 = MEMORY/LOAD_F64_LE [%a.16]  // a
 *          %138 = MEMORY/LOAD_F64_LE [%b.17]  // b
 *          %139 = FCMP_GT_64 [%137, %138]  // a > b
 *          %140 = LOGICAL_NOT [%139]  // !(a > b)
 *     >> %141 = COND_BRANCH [%140]  // if (!(a > b)) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %147 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %a.16 = ALLOCA/LOCAL size=8 align=8
 *          %148 = MEMORY/LOAD_F64_LE [%a.16]  // a
 *          %b.17 = ALLOCA/LOCAL size=8 align=8
 *          %149 = MEMORY/LOAD_F64_LE [%b.17]  // b
 *          %150 = FCMP_LT_64 [%148, %149]  // a < b
 *     >> %151 = COND_BRANCH [%150]  // if (a < b) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %157 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %a.16 = ALLOCA/LOCAL size=8 align=8
 *          %158 = MEMORY/LOAD_F64_LE [%a.16]  // a
 *          %b.17 = ALLOCA/LOCAL size=8 align=8
 *          %159 = MEMORY/LOAD_F64_LE [%b.17]  // b
 *          %160 = FCMP_EQ_64 [%158, %159]  // a == b
 *     >> %161 = COND_BRANCH [%160]  // if (a == b) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %167 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %a.16 = ALLOCA/LOCAL size=8 align=8
 *          %168 = MEMORY/LOAD_F64_LE [%a.16]  // a
 *          %b.17 = ALLOCA/LOCAL size=8 align=8
 *          %169 = MEMORY/LOAD_F64_LE [%b.17]  // b
 *          %170 = FCMP_NE_64 [%168, %169]  // a != b
 *          %171 = LOGICAL_NOT [%170]  // !(a != b)
 *     >> %172 = COND_BRANCH [%171]  // if (!(a != b)) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %178 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %a.16 = ALLOCA/LOCAL size=8 align=8
 *          %179 = MEMORY/LOAD_F64_LE [%a.16]  // a
 *          %b.17 = ALLOCA/LOCAL size=8 align=8
 *          %180 = MEMORY/LOAD_F64_LE [%b.17]  // b
 *          %181 = FCMP_GE_64 [%179, %180]  // a >= b
 *          %182 = LOGICAL_NOT [%181]  // !(a >= b)
 *     >> %183 = COND_BRANCH [%182]  // if (!(a >= b)) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %189 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %a.16 = ALLOCA/LOCAL size=8 align=8
 *          %190 = MEMORY/LOAD_F64_LE [%a.16]  // a
 *          %b.17 = ALLOCA/LOCAL size=8 align=8
 *          %191 = MEMORY/LOAD_F64_LE [%b.17]  // b
 *          %192 = FCMP_LE_64 [%190, %191]  // a <= b
 *     >> %193 = COND_BRANCH [%192]  // if (a <= b) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %199 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %201 = RETURN_PTR  // return 0
 *          %200 = CONST/INT32 0  // 0
 *     >> %202 = MEMORY/STORE_LE_32 [%201, %200]  // return 0
 *     >> %203 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %204 = RET [%200]  // return 0
 *   block_35 IF_THEN  <- [block_34]:
 *          %195 = RETURN_PTR  // return 12
 *          %194 = CONST/INT32 12  // 12
 *     >> %196 = MEMORY/STORE_LE_32 [%195, %194]  // return 12
 *     >> %197 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %198 = RET [%194]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %185 = RETURN_PTR  // return 11
 *          %184 = CONST/INT32 11  // 11
 *     >> %186 = MEMORY/STORE_LE_32 [%185, %184]  // return 11
 *     >> %187 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %188 = RET [%184]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %174 = RETURN_PTR  // return 10
 *          %173 = CONST/INT32 10  // 10
 *     >> %175 = MEMORY/STORE_LE_32 [%174, %173]  // return 10
 *     >> %176 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %177 = RET [%173]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %163 = RETURN_PTR  // return 9
 *          %162 = CONST/INT32 9  // 9
 *     >> %164 = MEMORY/STORE_LE_32 [%163, %162]  // return 9
 *     >> %165 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %166 = RET [%162]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %153 = RETURN_PTR  // return 8
 *          %152 = CONST/INT32 8  // 8
 *     >> %154 = MEMORY/STORE_LE_32 [%153, %152]  // return 8
 *     >> %155 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %156 = RET [%152]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %143 = RETURN_PTR  // return 7
 *          %142 = CONST/INT32 7  // 7
 *     >> %144 = MEMORY/STORE_LE_32 [%143, %142]  // return 7
 *     >> %145 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %146 = RET [%142]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %124 = RETURN_PTR  // return 6
 *          %123 = CONST/INT32 6  // 6
 *     >> %125 = MEMORY/STORE_LE_32 [%124, %123]  // return 6
 *     >> %126 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %127 = RET [%123]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %104 = RETURN_PTR  // return 5
 *          %103 = CONST/INT32 5  // 5
 *     >> %105 = MEMORY/STORE_LE_32 [%104, %103]  // return 5
 *     >> %106 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %107 = RET [%103]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %89 = RETURN_PTR  // return 4
 *          %88 = CONST/INT32 4  // 4
 *     >> %90 = MEMORY/STORE_LE_32 [%89, %88]  // return 4
 *     >> %91 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %92 = RET [%88]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %71 = RETURN_PTR  // return 3
 *          %70 = CONST/INT32 3  // 3
 *     >> %72 = MEMORY/STORE_LE_32 [%71, %70]  // return 3
 *     >> %73 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %74 = RET [%70]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %50 = RETURN_PTR  // return 2
 *          %49 = CONST/INT32 2  // 2
 *     >> %51 = MEMORY/STORE_LE_32 [%50, %49]  // return 2
 *     >> %52 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %53 = RET [%49]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %33 = RETURN_PTR  // return 1
 *          %32 = CONST/INT32 1  // 1
 *     >> %34 = MEMORY/STORE_LE_32 [%33, %32]  // return 1
 *     >> %35 = EXIT_SCOPE  // {     // Sign extension.     signed char sc = -...
 *     >> %36 = RET [%32]  // return 1
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

    // Float comparisons (FCMP opcodes).
    double a = 3.14, b = 2.71;
    if (!(a > b)) return 7;    // 3.14 > 2.71
    if (a < b) return 8;       // !(3.14 < 2.71)
    if (a == b) return 9;      // !(3.14 == 2.71)
    if (!(a != b)) return 10;  // 3.14 != 2.71
    if (!(a >= b)) return 11;  // 3.14 >= 2.71
    if (a <= b) return 12;     // !(3.14 <= 2.71)

    return 0;
}
