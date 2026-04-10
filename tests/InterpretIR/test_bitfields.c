// Tests: bit-field access (BIT_READ_LE/BE, BIT_WRITE_LE/BE),
// bit-field initialization, reading back bit-field values,
// and bit-field in compound expressions.

/*
 * Expected IR:
 *
 * function test_bitfields (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (f)
 *     obj_2 LOCAL_VALUE size=4 align=1 (g)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %2 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %3 = ENTER_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %f.4 = CONST/UINT8 0
 *          %f.5 = CONST/UINT64 4
 *     >> %f.6 = MEMORY/MEMSET [%f.0, %f.4, %f.5]
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %8 = CAST/IDENTITY [%7]  // 0
 *     >> %f.9 = MEMORY/BIT_WRITE_LE off=0 w=1 [%f.0, %8]
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %10 = CONST/INT64 0
 *     >> %f.11 = MEMORY/BIT_WRITE_LE off=1 w=1 [%f.0, %10]
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %12 = CONST/INT64 0
 *     >> %f.13 = MEMORY/BIT_WRITE_LE off=2 w=1 [%f.0, %12]
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %14 = CONST/INT64 0
 *     >> %f.15 = MEMORY/BIT_WRITE_LE off=3 w=4 [%f.0, %14]
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %16 = CONST/INT64 0
 *     >> %f.17 = MEMORY/BIT_WRITE_LE off=7 w=25 [%f.0, %16]
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %19 = CAST/IDENTITY [%18]  // 1
 *     >> %20 = MEMORY/BIT_WRITE_LE off=0 w=1 [%f.0, %19]  // f.read = 1
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %22 = CAST/IDENTITY [%21]  // 0
 *     >> %23 = MEMORY/BIT_WRITE_LE off=1 w=1 [%f.0, %22]  // f.write = 0
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %25 = CAST/IDENTITY [%24]  // 1
 *     >> %26 = MEMORY/BIT_WRITE_LE off=2 w=1 [%f.0, %25]  // f.exec = 1
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %28 = CAST/IDENTITY [%27]  // 7
 *     >> %29 = MEMORY/BIT_WRITE_LE off=3 w=4 [%f.0, %28]  // f.mode = 7
 *          %33 = CMP_NE [%31, %32]  // f.read != 1
 *     >> %34 = COND_BRANCH [%33]  // if (f.read != 1) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %40 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %44 = CMP_NE [%42, %43]  // f.write != 0
 *     >> %45 = COND_BRANCH [%44]  // if (f.write != 0) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %51 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %55 = CMP_NE [%53, %54]  // f.exec != 1
 *     >> %56 = COND_BRANCH [%55]  // if (f.exec != 1) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %62 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %66 = CMP_NE [%64, %65]  // f.mode != 7
 *     >> %67 = COND_BRANCH [%66]  // if (f.mode != 7) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %73 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %g.1 = ALLOCA/LOCAL size=4 align=1
 *          %g.74 = CONST/UINT8 0
 *          %g.75 = CONST/UINT64 4
 *     >> %g.76 = MEMORY/MEMSET [%g.1, %g.74, %g.75]
 *          %g.1 = ALLOCA/LOCAL size=4 align=1
 *          %78 = CAST/IDENTITY [%77]  // 1
 *     >> %g.79 = MEMORY/BIT_WRITE_LE off=0 w=1 [%g.1, %78]
 *          %g.1 = ALLOCA/LOCAL size=4 align=1
 *          %81 = CAST/IDENTITY [%80]  // 1
 *     >> %g.82 = MEMORY/BIT_WRITE_LE off=1 w=1 [%g.1, %81]
 *          %g.1 = ALLOCA/LOCAL size=4 align=1
 *          %84 = CAST/IDENTITY [%83]  // 0
 *     >> %g.85 = MEMORY/BIT_WRITE_LE off=2 w=1 [%g.1, %84]
 *          %g.1 = ALLOCA/LOCAL size=4 align=1
 *          %87 = CAST/IDENTITY [%86]  // 5
 *     >> %g.88 = MEMORY/BIT_WRITE_LE off=3 w=4 [%g.1, %87]
 *          %g.1 = ALLOCA/LOCAL size=4 align=1
 *          %89 = CONST/INT64 0
 *     >> %g.90 = MEMORY/BIT_WRITE_LE off=7 w=25 [%g.1, %89]
 *          %94 = CMP_NE [%92, %93]  // g.read != 1
 *     >> %95 = COND_BRANCH [%94]  // if (g.read != 1) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %101 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %105 = CMP_NE [%103, %104]  // g.write != 1
 *     >> %106 = COND_BRANCH [%105]  // if (g.write != 1) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %112 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %116 = CMP_NE [%114, %115]  // g.exec != 0
 *     >> %117 = COND_BRANCH [%116]  // if (g.exec != 0) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %123 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %127 = CMP_NE [%125, %126]  // g.mode != 5
 *     >> %128 = COND_BRANCH [%127]  // if (g.mode != 5) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %134 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %f.0 = ALLOCA/LOCAL size=4 align=1
 *          %139 = CAST/IDENTITY [%138]  // f.mode & 3
 *     >> %140 = MEMORY/BIT_WRITE_LE off=3 w=4 [%f.0, %139]  // f.mode = f.mode & 3
 *          %144 = CMP_NE [%142, %143]  // f.mode != 3
 *     >> %145 = COND_BRANCH [%144]  // if (f.mode != 3) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %151 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %153 = RETURN_PTR  // return 0
 *          %152 = CONST/INT32 0  // 0
 *     >> %154 = MEMORY/STORE_LE_32 [%153, %152]  // return 0
 *     >> %155 = EXIT_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %152 = CONST/INT32 0  // 0
 *     >> %156 = RET [%152]  // return 0
 *   block_26 IF_THEN  <- [block_25]:
 *          %147 = RETURN_PTR  // return 9
 *          %146 = CONST/INT32 9  // 9
 *     >> %148 = MEMORY/STORE_LE_32 [%147, %146]  // return 9
 *     >> %149 = EXIT_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %146 = CONST/INT32 9  // 9
 *     >> %150 = RET [%146]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %130 = RETURN_PTR  // return 8
 *          %129 = CONST/INT32 8  // 8
 *     >> %131 = MEMORY/STORE_LE_32 [%130, %129]  // return 8
 *     >> %132 = EXIT_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %129 = CONST/INT32 8  // 8
 *     >> %133 = RET [%129]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %119 = RETURN_PTR  // return 7
 *          %118 = CONST/INT32 7  // 7
 *     >> %120 = MEMORY/STORE_LE_32 [%119, %118]  // return 7
 *     >> %121 = EXIT_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %118 = CONST/INT32 7  // 7
 *     >> %122 = RET [%118]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %108 = RETURN_PTR  // return 6
 *          %107 = CONST/INT32 6  // 6
 *     >> %109 = MEMORY/STORE_LE_32 [%108, %107]  // return 6
 *     >> %110 = EXIT_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %107 = CONST/INT32 6  // 6
 *     >> %111 = RET [%107]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %97 = RETURN_PTR  // return 5
 *          %96 = CONST/INT32 5  // 5
 *     >> %98 = MEMORY/STORE_LE_32 [%97, %96]  // return 5
 *     >> %99 = EXIT_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %96 = CONST/INT32 5  // 5
 *     >> %100 = RET [%96]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %69 = RETURN_PTR  // return 4
 *          %68 = CONST/INT32 4  // 4
 *     >> %70 = MEMORY/STORE_LE_32 [%69, %68]  // return 4
 *     >> %71 = EXIT_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %68 = CONST/INT32 4  // 4
 *     >> %72 = RET [%68]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %58 = RETURN_PTR  // return 3
 *          %57 = CONST/INT32 3  // 3
 *     >> %59 = MEMORY/STORE_LE_32 [%58, %57]  // return 3
 *     >> %60 = EXIT_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %57 = CONST/INT32 3  // 3
 *     >> %61 = RET [%57]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %47 = RETURN_PTR  // return 2
 *          %46 = CONST/INT32 2  // 2
 *     >> %48 = MEMORY/STORE_LE_32 [%47, %46]  // return 2
 *     >> %49 = EXIT_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %46 = CONST/INT32 2  // 2
 *     >> %50 = RET [%46]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %36 = RETURN_PTR  // return 1
 *          %35 = CONST/INT32 1  // 1
 *     >> %37 = MEMORY/STORE_LE_32 [%36, %35]  // return 1
 *     >> %38 = EXIT_SCOPE  // {     struct Flags f = {0};      // Write indiv...
 *          %35 = CONST/INT32 1  // 1
 *     >> %39 = RET [%35]  // return 1
 * }
 */




struct Flags {
    unsigned int read  : 1;
    unsigned int write : 1;
    unsigned int exec  : 1;
    unsigned int mode  : 4;
    unsigned int pad   : 25;
};

int test_bitfields(void) {
    struct Flags f = {0};

    // Write individual bit-fields.
    f.read = 1;
    f.write = 0;
    f.exec = 1;
    f.mode = 7;

    // Read back.
    if (f.read != 1) return 1;
    if (f.write != 0) return 2;
    if (f.exec != 1) return 3;
    if (f.mode != 7) return 4;

    // Init list for bit-fields.
    struct Flags g = {1, 1, 0, 5};
    if (g.read != 1) return 5;
    if (g.write != 1) return 6;
    if (g.exec != 0) return 7;
    if (g.mode != 5) return 8;

    // Modify via compound assignment.
    f.mode = f.mode & 3;
    if (f.mode != 3) return 9;

    return 0;
}
