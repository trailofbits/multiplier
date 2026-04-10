// Tests: sizeof and alignof lowered to CONST, offsetof lowered via
// EvaluateAsInt, and various type size queries.

/*
 * Expected IR:
 *
 * function test_sizeof_alignof (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=40 align=1 (arr)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %arr.0 = ALLOCA/LOCAL size=40 align=1
 *     >> %1 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %2 = ENTER_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %6 = CMP_NE [%3, %5]  // sizeof(char) != 1
 *     >> %7 = COND_BRANCH [%6]  // if (sizeof(char) != 1) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %13 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %17 = CMP_LT [%14, %16]  // sizeof(int) < 2
 *     >> %18 = COND_BRANCH [%17]  // if (sizeof(int) < 2) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %24 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %28 = CMP_LT [%25, %27]  // sizeof(long long) < 8
 *     >> %29 = COND_BRANCH [%28]  // if (sizeof(long long) < 8) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %35 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %39 = CMP_LT [%36, %38]  // sizeof(struct Packed) < 6
 *     >> %40 = COND_BRANCH [%39]  // if (sizeof(struct Packed) < 6) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %46 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %52 = CMP_NE [%47, %51]  // sizeof(arr) != 10 * sizeof(int)
 *     >> %53 = COND_BRANCH [%52]  // if (sizeof(arr) != 10 * sizeof(int)) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %59 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %62 = CMP_NE [%60, %61]  // sizeof(int *) != sizeof(void *)
 *     >> %63 = COND_BRANCH [%62]  // if (sizeof(int *) != sizeof(void *)) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %69 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %73 = CMP_LT [%70, %72]  // _Alignof(int) < 1
 *     >> %74 = COND_BRANCH [%73]  // if (_Alignof(int) < 1) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %80 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %84 = CMP_LT [%81, %83]  // _Alignof(double) < 1
 *     >> %85 = COND_BRANCH [%84]  // if (_Alignof(double) < 1) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %91 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %95 = CMP_NE [%92, %94]  // __builtin_offsetof(structPacked,a) != 0
 *     >> %96 = COND_BRANCH [%95]  // if (__builtin_offsetof(structPacked,a) != 0) re...
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %102 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %106 = CMP_LT [%103, %105]  // __builtin_offsetof(structPacked,b) < 1
 *     >> %107 = COND_BRANCH [%106]  // if (__builtin_offsetof(structPacked,b) < 1) ret...
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %113 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %115 = RETURN_PTR  // return 0
 *          %114 = CONST/INT32 0  // 0
 *     >> %116 = MEMORY/STORE_LE_32 [%115, %114]  // return 0
 *     >> %117 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %114 = CONST/INT32 0  // 0
 *     >> %118 = RET [%114]  // return 0
 *   block_29 IF_THEN  <- [block_28]:
 *          %109 = RETURN_PTR  // return 10
 *          %108 = CONST/INT32 10  // 10
 *     >> %110 = MEMORY/STORE_LE_32 [%109, %108]  // return 10
 *     >> %111 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %108 = CONST/INT32 10  // 10
 *     >> %112 = RET [%108]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %98 = RETURN_PTR  // return 9
 *          %97 = CONST/INT32 9  // 9
 *     >> %99 = MEMORY/STORE_LE_32 [%98, %97]  // return 9
 *     >> %100 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %97 = CONST/INT32 9  // 9
 *     >> %101 = RET [%97]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %87 = RETURN_PTR  // return 8
 *          %86 = CONST/INT32 8  // 8
 *     >> %88 = MEMORY/STORE_LE_32 [%87, %86]  // return 8
 *     >> %89 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %86 = CONST/INT32 8  // 8
 *     >> %90 = RET [%86]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %76 = RETURN_PTR  // return 7
 *          %75 = CONST/INT32 7  // 7
 *     >> %77 = MEMORY/STORE_LE_32 [%76, %75]  // return 7
 *     >> %78 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %75 = CONST/INT32 7  // 7
 *     >> %79 = RET [%75]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %65 = RETURN_PTR  // return 6
 *          %64 = CONST/INT32 6  // 6
 *     >> %66 = MEMORY/STORE_LE_32 [%65, %64]  // return 6
 *     >> %67 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %64 = CONST/INT32 6  // 6
 *     >> %68 = RET [%64]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %55 = RETURN_PTR  // return 5
 *          %54 = CONST/INT32 5  // 5
 *     >> %56 = MEMORY/STORE_LE_32 [%55, %54]  // return 5
 *     >> %57 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %54 = CONST/INT32 5  // 5
 *     >> %58 = RET [%54]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %42 = RETURN_PTR  // return 4
 *          %41 = CONST/INT32 4  // 4
 *     >> %43 = MEMORY/STORE_LE_32 [%42, %41]  // return 4
 *     >> %44 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %41 = CONST/INT32 4  // 4
 *     >> %45 = RET [%41]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %31 = RETURN_PTR  // return 3
 *          %30 = CONST/INT32 3  // 3
 *     >> %32 = MEMORY/STORE_LE_32 [%31, %30]  // return 3
 *     >> %33 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %30 = CONST/INT32 3  // 3
 *     >> %34 = RET [%30]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %20 = RETURN_PTR  // return 2
 *          %19 = CONST/INT32 2  // 2
 *     >> %21 = MEMORY/STORE_LE_32 [%20, %19]  // return 2
 *     >> %22 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %19 = CONST/INT32 2  // 2
 *     >> %23 = RET [%19]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %9 = RETURN_PTR  // return 1
 *          %8 = CONST/INT32 1  // 1
 *     >> %10 = MEMORY/STORE_LE_32 [%9, %8]  // return 1
 *     >> %11 = EXIT_SCOPE  // {     // sizeof basic types.     if (sizeof(cha...
 *          %8 = CONST/INT32 1  // 1
 *     >> %12 = RET [%8]  // return 1
 * }
 */




#define offsetof(type, member) __builtin_offsetof(type, member)

struct Packed {
    char a;
    int b;
    char c;
};

int test_sizeof_alignof(void) {
    // sizeof basic types.
    if (sizeof(char) != 1) return 1;
    if (sizeof(int) < 2) return 2;
    if (sizeof(long long) < 8) return 3;

    // sizeof struct.
    if (sizeof(struct Packed) < 6) return 4;

    // sizeof array.
    int arr[10];
    if (sizeof(arr) != 10 * sizeof(int)) return 5;

    // sizeof pointer.
    if (sizeof(int *) != sizeof(void *)) return 6;

    // alignof.
    if (_Alignof(int) < 1) return 7;
    if (_Alignof(double) < 1) return 8;

    // offsetof.
    if (offsetof(struct Packed, a) != 0) return 9;
    if (offsetof(struct Packed, b) < 1) return 10;

    return 0;
}
