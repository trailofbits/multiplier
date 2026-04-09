// Tests: global variable initialization (GLOBAL_INITIALIZER functions),
// global pointer access (GLOBAL_PTR), static local variables,
// and aggregate global initialization (MEMSET + element stores).

/*
 * Expected IR:
 *
 * function test_globals (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %0 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %1 = ENTER_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %5 = CMP_NE [%3, %4]  // g_simple != 42
 *     >> %6 = COND_BRANCH [%5]  // if (g_simple != 42) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %12 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %18 = CMP_NE [%16, %17]  // g_array[0] != 1
 *     >> %19 = COND_BRANCH [%18]  // if (g_array[0] != 1) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %25 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %31 = CMP_NE [%29, %30]  // g_array[1] != 2
 *     >> %32 = COND_BRANCH [%31]  // if (g_array[1] != 2) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %38 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %44 = CMP_NE [%42, %43]  // g_array[2] != 3
 *     >> %45 = COND_BRANCH [%44]  // if (g_array[2] != 3) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %51 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %56 = CMP_NE [%54, %55]  // g_config.width != 640
 *     >> %57 = COND_BRANCH [%56]  // if (g_config.width != 640) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %63 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %68 = CMP_NE [%66, %67]  // g_config.height != 480
 *     >> %69 = COND_BRANCH [%68]  // if (g_config.height != 480) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %75 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %80 = CMP_NE [%78, %79]  // g_config.depth != 32
 *     >> %81 = COND_BRANCH [%80]  // if (g_config.depth != 32) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %87 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %91 = CMP_NE [%89, %90]  // s_local != 77
 *     >> %92 = COND_BRANCH [%91]  // if (s_local != 77) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %98 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %102 = CMP_NE [%100, %101]  // g_static != 100
 *     >> %103 = COND_BRANCH [%102]  // if (g_static != 100) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %109 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %110 = GLOBAL_PTR  // g_simple
 *          %111 = CONST/INT32 99  // 99
 *     >> %112 = MEMORY/STORE_LE_32 [%110, %111]  // g_simple = 99
 *          %116 = CMP_NE [%114, %115]  // g_simple != 99
 *     >> %117 = COND_BRANCH [%116]  // if (g_simple != 99) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %123 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %125 = RETURN_PTR  // return 0
 *          %124 = CONST/INT32 0  // 0
 *     >> %126 = MEMORY/STORE_LE_32 [%125, %124]  // return 0
 *     >> %127 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %124 = CONST/INT32 0  // 0
 *     >> %128 = RET [%124]  // return 0
 *   block_29 IF_THEN  <- [block_28]:
 *          %119 = RETURN_PTR  // return 10
 *          %118 = CONST/INT32 10  // 10
 *     >> %120 = MEMORY/STORE_LE_32 [%119, %118]  // return 10
 *     >> %121 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %118 = CONST/INT32 10  // 10
 *     >> %122 = RET [%118]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %105 = RETURN_PTR  // return 9
 *          %104 = CONST/INT32 9  // 9
 *     >> %106 = MEMORY/STORE_LE_32 [%105, %104]  // return 9
 *     >> %107 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %104 = CONST/INT32 9  // 9
 *     >> %108 = RET [%104]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %94 = RETURN_PTR  // return 8
 *          %93 = CONST/INT32 8  // 8
 *     >> %95 = MEMORY/STORE_LE_32 [%94, %93]  // return 8
 *     >> %96 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %93 = CONST/INT32 8  // 8
 *     >> %97 = RET [%93]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %83 = RETURN_PTR  // return 7
 *          %82 = CONST/INT32 7  // 7
 *     >> %84 = MEMORY/STORE_LE_32 [%83, %82]  // return 7
 *     >> %85 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %82 = CONST/INT32 7  // 7
 *     >> %86 = RET [%82]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %71 = RETURN_PTR  // return 6
 *          %70 = CONST/INT32 6  // 6
 *     >> %72 = MEMORY/STORE_LE_32 [%71, %70]  // return 6
 *     >> %73 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %70 = CONST/INT32 6  // 6
 *     >> %74 = RET [%70]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %59 = RETURN_PTR  // return 5
 *          %58 = CONST/INT32 5  // 5
 *     >> %60 = MEMORY/STORE_LE_32 [%59, %58]  // return 5
 *     >> %61 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %58 = CONST/INT32 5  // 5
 *     >> %62 = RET [%58]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %47 = RETURN_PTR  // return 4
 *          %46 = CONST/INT32 4  // 4
 *     >> %48 = MEMORY/STORE_LE_32 [%47, %46]  // return 4
 *     >> %49 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %46 = CONST/INT32 4  // 4
 *     >> %50 = RET [%46]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %34 = RETURN_PTR  // return 3
 *          %33 = CONST/INT32 3  // 3
 *     >> %35 = MEMORY/STORE_LE_32 [%34, %33]  // return 3
 *     >> %36 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %33 = CONST/INT32 3  // 3
 *     >> %37 = RET [%33]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %21 = RETURN_PTR  // return 2
 *          %20 = CONST/INT32 2  // 2
 *     >> %22 = MEMORY/STORE_LE_32 [%21, %20]  // return 2
 *     >> %23 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %20 = CONST/INT32 2  // 2
 *     >> %24 = RET [%20]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %8 = RETURN_PTR  // return 1
 *          %7 = CONST/INT32 1  // 1
 *     >> %9 = MEMORY/STORE_LE_32 [%8, %7]  // return 1
 *     >> %10 = EXIT_SCOPE  // {     // Simple global.     if (g_simple != 42)...
 *          %7 = CONST/INT32 1  // 1
 *     >> %11 = RET [%7]  // return 1
 * }
 */

int g_simple = 42;
int g_array[3] = {1, 2, 3};

struct Config {
    int width;
    int height;
    int depth;
};
struct Config g_config = {640, 480, 32};

static int g_static = 100;

int test_globals(void) {
    // Simple global.
    if (g_simple != 42) return 1;

    // Global array.
    if (g_array[0] != 1) return 2;
    if (g_array[1] != 2) return 3;
    if (g_array[2] != 3) return 4;

    // Global struct.
    if (g_config.width != 640) return 5;
    if (g_config.height != 480) return 6;
    if (g_config.depth != 32) return 7;

    // Static local.
    static int s_local = 77;
    if (s_local != 77) return 8;

    // File-scope static.
    if (g_static != 100) return 9;

    // Modify global.
    g_simple = 99;
    if (g_simple != 99) return 10;

    return 0;
}
