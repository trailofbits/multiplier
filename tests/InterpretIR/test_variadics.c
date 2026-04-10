// Tests: variadic function handling (VA_START, VA_END, VA_COPY,
// CONSUME_VA_PARAM via MEMORY sub-opcode), va_arg with different types.

/*
 * Expected IR:
 *
 * function test_variadics (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (s1)
 *     obj_2 LOCAL_VALUE size=4 align=1 (s2)
 *     obj_3 LOCAL_VALUE size=4 align=1 (s3)
 *     obj_4 LOCAL_VALUE size=4 align=1 (first)
 *     obj_5 LOCAL_VALUE size=4 align=1 (copy_result)
 *     obj_6 PARAMETER size=4 align=1
 *     obj_7 PARAMETER size=4 align=1
 *     obj_8 PARAMETER size=4 align=1
 *     obj_9 PARAMETER size=4 align=1
 *     obj_10 RETURN_SLOT size=4 align=1
 *     obj_11 PARAMETER size=4 align=1
 *     obj_12 PARAMETER size=4 align=1
 *     obj_13 RETURN_SLOT size=4 align=1
 *     obj_14 PARAMETER size=4 align=1
 *     obj_15 RETURN_SLOT size=4 align=1
 *     obj_16 PARAMETER size=4 align=1
 *     obj_17 PARAMETER size=4 align=1
 *     obj_18 RETURN_SLOT size=4 align=1
 *     obj_19 PARAMETER size=4 align=1
 *     obj_20 PARAMETER size=4 align=1
 *     obj_21 PARAMETER size=4 align=1
 *     obj_22 PARAMETER size=4 align=1
 *     obj_23 RETURN_SLOT size=4 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %5 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %6 = ENTER_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *     >> %7 = ENTER_SCOPE  // va_sum(3, 10, 20, 30)
 *          %9 = ALLOCA/ARG size=4 align=1  // 3
 *          %8 = CONST/INT32 3  // 3
 *     >> %10 = MEMORY/STORE_LE_32 [%9, %8]  // 3
 *          %12 = ALLOCA/ARG size=4 align=1  // 10
 *          %11 = CONST/INT32 10  // 10
 *     >> %13 = MEMORY/STORE_LE_32 [%12, %11]  // 10
 *          %15 = ALLOCA/ARG size=4 align=1  // 20
 *          %14 = CONST/INT32 20  // 20
 *     >> %16 = MEMORY/STORE_LE_32 [%15, %14]  // 20
 *          %18 = ALLOCA/ARG size=4 align=1  // 30
 *          %17 = CONST/INT32 30  // 30
 *     >> %19 = MEMORY/STORE_LE_32 [%18, %17]  // 30
 *          %s1.0 = ALLOCA/LOCAL size=4 align=1
 *          %21 = CALL @va_sum [%9, %12, %15, %18]  // va_sum(3, 10, 20, 30)
 *     >> %s1.22 = MEMORY/STORE_LE_32 [%s1.0, %21]
 *     >> %26 = EXIT_SCOPE
 *          %25 = CMP_NE [%23, %24]  // s1 != 60
 *     >> %27 = COND_BRANCH [%25]  // if (s1 != 60) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %34 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *     >> %35 = ENTER_SCOPE  // va_sum(1, 42)
 *          %37 = ALLOCA/ARG size=4 align=1  // 1
 *          %36 = CONST/INT32 1  // 1
 *     >> %38 = MEMORY/STORE_LE_32 [%37, %36]  // 1
 *          %40 = ALLOCA/ARG size=4 align=1  // 42
 *          %39 = CONST/INT32 42  // 42
 *     >> %41 = MEMORY/STORE_LE_32 [%40, %39]  // 42
 *          %s2.1 = ALLOCA/LOCAL size=4 align=1
 *          %43 = CALL @va_sum [%37, %40]  // va_sum(1, 42)
 *     >> %s2.44 = MEMORY/STORE_LE_32 [%s2.1, %43]
 *     >> %48 = EXIT_SCOPE
 *          %47 = CMP_NE [%45, %46]  // s2 != 42
 *     >> %49 = COND_BRANCH [%47]  // if (s2 != 42) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %56 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *     >> %57 = ENTER_SCOPE  // va_sum(0)
 *          %59 = ALLOCA/ARG size=4 align=1  // 0
 *          %58 = CONST/INT32 0  // 0
 *     >> %60 = MEMORY/STORE_LE_32 [%59, %58]  // 0
 *          %s3.2 = ALLOCA/LOCAL size=4 align=1
 *          %62 = CALL @va_sum [%59]  // va_sum(0)
 *     >> %s3.63 = MEMORY/STORE_LE_32 [%s3.2, %62]
 *     >> %67 = EXIT_SCOPE
 *          %66 = CMP_NE [%64, %65]  // s3 != 0
 *     >> %68 = COND_BRANCH [%66]  // if (s3 != 0) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %75 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *     >> %76 = ENTER_SCOPE  // va_first_int(0, 99)
 *          %78 = ALLOCA/ARG size=4 align=1  // 0
 *          %77 = CONST/INT32 0  // 0
 *     >> %79 = MEMORY/STORE_LE_32 [%78, %77]  // 0
 *          %81 = ALLOCA/ARG size=4 align=1  // 99
 *          %80 = CONST/INT32 99  // 99
 *     >> %82 = MEMORY/STORE_LE_32 [%81, %80]  // 99
 *          %first.3 = ALLOCA/LOCAL size=4 align=1
 *          %84 = CALL @va_first_int [%78, %81]  // va_first_int(0, 99)
 *     >> %first.85 = MEMORY/STORE_LE_32 [%first.3, %84]
 *     >> %89 = EXIT_SCOPE
 *          %88 = CMP_NE [%86, %87]  // first != 99
 *     >> %90 = COND_BRANCH [%88]  // if (first != 99) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %97 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *     >> %98 = ENTER_SCOPE  // va_copy_test(3, 10, 20, 30)
 *          %100 = ALLOCA/ARG size=4 align=1  // 3
 *          %99 = CONST/INT32 3  // 3
 *     >> %101 = MEMORY/STORE_LE_32 [%100, %99]  // 3
 *          %103 = ALLOCA/ARG size=4 align=1  // 10
 *          %102 = CONST/INT32 10  // 10
 *     >> %104 = MEMORY/STORE_LE_32 [%103, %102]  // 10
 *          %106 = ALLOCA/ARG size=4 align=1  // 20
 *          %105 = CONST/INT32 20  // 20
 *     >> %107 = MEMORY/STORE_LE_32 [%106, %105]  // 20
 *          %109 = ALLOCA/ARG size=4 align=1  // 30
 *          %108 = CONST/INT32 30  // 30
 *     >> %110 = MEMORY/STORE_LE_32 [%109, %108]  // 30
 *          %copy_result.4 = ALLOCA/LOCAL size=4 align=1
 *          %112 = CALL @va_copy_test [%100, %103, %106, %109]  // va_copy_test(3, 10, 20, 30)
 *     >> %copy_result.113 = MEMORY/STORE_LE_32 [%copy_result.4, %112]
 *     >> %117 = EXIT_SCOPE
 *          %116 = CMP_NE [%114, %115]  // copy_result != 50
 *     >> %118 = COND_BRANCH [%116]  // if (copy_result != 50) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %125 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %127 = RETURN_PTR  // return 0
 *          %126 = CONST/INT32 0  // 0
 *     >> %128 = MEMORY/STORE_LE_32 [%127, %126]  // return 0
 *     >> %129 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %126 = CONST/INT32 0  // 0
 *     >> %130 = RET [%126]  // return 0
 *   block_14 IF_THEN  <- [block_13]:
 *          %120 = RETURN_PTR  // return 5
 *          %119 = CONST/INT32 5  // 5
 *     >> %121 = MEMORY/STORE_LE_32 [%120, %119]  // return 5
 *     >> %122 = EXIT_SCOPE  // va_copy_test(3, 10, 20, 30)
 *     >> %123 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %119 = CONST/INT32 5  // 5
 *     >> %124 = RET [%119]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %92 = RETURN_PTR  // return 4
 *          %91 = CONST/INT32 4  // 4
 *     >> %93 = MEMORY/STORE_LE_32 [%92, %91]  // return 4
 *     >> %94 = EXIT_SCOPE  // va_first_int(0, 99)
 *     >> %95 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %91 = CONST/INT32 4  // 4
 *     >> %96 = RET [%91]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %70 = RETURN_PTR  // return 3
 *          %69 = CONST/INT32 3  // 3
 *     >> %71 = MEMORY/STORE_LE_32 [%70, %69]  // return 3
 *     >> %72 = EXIT_SCOPE  // va_sum(0)
 *     >> %73 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %69 = CONST/INT32 3  // 3
 *     >> %74 = RET [%69]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %51 = RETURN_PTR  // return 2
 *          %50 = CONST/INT32 2  // 2
 *     >> %52 = MEMORY/STORE_LE_32 [%51, %50]  // return 2
 *     >> %53 = EXIT_SCOPE  // va_sum(1, 42)
 *     >> %54 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %50 = CONST/INT32 2  // 2
 *     >> %55 = RET [%50]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %29 = RETURN_PTR  // return 1
 *          %28 = CONST/INT32 1  // 1
 *     >> %30 = MEMORY/STORE_LE_32 [%29, %28]  // return 1
 *     >> %31 = EXIT_SCOPE  // va_sum(3, 10, 20, 30)
 *     >> %32 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %28 = CONST/INT32 1  // 1
 *     >> %33 = RET [%28]  // return 1
 * }
 */




#include <stdarg.h>

static int va_sum(int count, ...) {
    va_list ap;
    va_start(ap, count);
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(ap, int);
    }
    va_end(ap);
    return total;
}

static int va_first_int(int dummy, ...) {
    va_list ap;
    va_start(ap, dummy);
    int result = va_arg(ap, int);
    va_end(ap);
    return result;
}

static double va_sum_doubles(int count, ...) {
    va_list ap;
    va_start(ap, count);
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total;
}

static int va_copy_test(int count, ...) {
    va_list ap, ap2;
    va_start(ap, count);

    // Read first element.
    int first = va_arg(ap, int);

    // Copy va_list and read from copy.
    va_copy(ap2, ap);
    int second_from_copy = va_arg(ap2, int);
    va_end(ap2);

    // Read from original (should give same second element).
    int second_from_orig = va_arg(ap, int);

    va_end(ap);
    return first + second_from_copy + second_from_orig;
}

int test_variadics(void) {
    // Basic variadic sum.
    int s1 = va_sum(3, 10, 20, 30);
    if (s1 != 60) return 1;

    // Single variadic arg.
    int s2 = va_sum(1, 42);
    if (s2 != 42) return 2;

    // Zero variadic args.
    int s3 = va_sum(0);
    if (s3 != 0) return 3;

    // First int extraction.
    int first = va_first_int(0, 99);
    if (first != 99) return 4;

    // va_copy: first=10, second=20, result = 10 + 20 + 20 = 50.
    int copy_result = va_copy_test(3, 10, 20, 30);
    if (copy_result != 50) return 5;

    return 0;
}
