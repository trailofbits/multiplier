// Tests: function calls (CALL), parameter passing (PARAM_READ + STORE),
// return values, recursive calls, indirect calls via function pointers
// (FUNC_PTR), and variadic functions (VA_PACK, VA_START, VA_ARG, VA_END).

/*
 * Expected IR:
 *
 * function test_function_calls (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=8 align=1 (fp)
 *     obj_1 PARAMETER size=4 align=1
 *     obj_2 PARAMETER size=4 align=1
 *     obj_3 RETURN_SLOT size=4 align=1
 *     obj_4 PARAMETER size=4 align=1
 *     obj_5 RETURN_SLOT size=4 align=1
 *     obj_6 PARAMETER size=4 align=1
 *     obj_7 PARAMETER size=4 align=1
 *     obj_8 RETURN_SLOT size=4 align=1
 *     obj_9 PARAMETER size=8 align=1
 *     obj_10 PARAMETER size=4 align=1
 *     obj_11 PARAMETER size=4 align=1
 *     obj_12 RETURN_SLOT size=4 align=1
 *     obj_13 PARAMETER size=4 align=1
 *     obj_14 PARAMETER size=4 align=1
 *     obj_15 PARAMETER size=4 align=1
 *     obj_16 PARAMETER size=4 align=1
 *     obj_17 RETURN_SLOT size=4 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %1 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %2 = ENTER_SCOPE  // {     // Direct call.     if (add(3, 4) != 7) r...
 *     >> %3 = ENTER_SCOPE  // add(3, 4)
 *          %5 = ALLOCA/ARG size=4 align=1  // 3
 *          %4 = CONST/INT32 3  // 3
 *     >> %6 = MEMORY/STORE_LE_32 [%5, %4]  // 3
 *          %8 = ALLOCA/ARG size=4 align=1  // 4
 *          %7 = CONST/INT32 4  // 4
 *     >> %9 = MEMORY/STORE_LE_32 [%8, %7]  // 4
 *     >> %14 = EXIT_SCOPE
 *          %13 = CMP_NE [%11, %12]  // add(3, 4) != 7
 *     >> %15 = COND_BRANCH [%13]  // if (add(3, 4) != 7) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %21 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *     >> %22 = ENTER_SCOPE  // factorial(5)
 *          %24 = ALLOCA/ARG size=4 align=1  // 5
 *          %23 = CONST/INT32 5  // 5
 *     >> %25 = MEMORY/STORE_LE_32 [%24, %23]  // 5
 *     >> %30 = EXIT_SCOPE
 *          %29 = CMP_NE [%27, %28]  // factorial(5) != 120
 *     >> %31 = COND_BRANCH [%29]  // if (factorial(5) != 120) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %37 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %fp.0 = ALLOCA/LOCAL size=8 align=1
 *          %38 = FUNC_PTR  // add
 *     >> %fp.39 = MEMORY/STORE_LE_64 [%fp.0, %38]
 *     >> %40 = ENTER_SCOPE  // fp(10, 20)
 *          %43 = ALLOCA/ARG size=4 align=1  // 10
 *          %42 = CONST/INT32 10  // 10
 *     >> %44 = MEMORY/STORE_LE_32 [%43, %42]  // 10
 *          %46 = ALLOCA/ARG size=4 align=1  // 20
 *          %45 = CONST/INT32 20  // 20
 *     >> %47 = MEMORY/STORE_LE_32 [%46, %45]  // 20
 *     >> %52 = EXIT_SCOPE
 *          %51 = CMP_NE [%49, %50]  // fp(10, 20) != 30
 *     >> %53 = COND_BRANCH [%51]  // if (fp(10, 20) != 30) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %59 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *     >> %60 = ENTER_SCOPE  // apply(add, 5, 6)
 *          %62 = ALLOCA/ARG size=8 align=1  // add
 *          %61 = FUNC_PTR  // add
 *     >> %63 = MEMORY/STORE_LE_64 [%62, %61]  // add
 *          %65 = ALLOCA/ARG size=4 align=1  // 5
 *          %64 = CONST/INT32 5  // 5
 *     >> %66 = MEMORY/STORE_LE_32 [%65, %64]  // 5
 *          %68 = ALLOCA/ARG size=4 align=1  // 6
 *          %67 = CONST/INT32 6  // 6
 *     >> %69 = MEMORY/STORE_LE_32 [%68, %67]  // 6
 *     >> %74 = EXIT_SCOPE
 *          %73 = CMP_NE [%71, %72]  // apply(add, 5, 6) != 11
 *     >> %75 = COND_BRANCH [%73]  // if (apply(add, 5, 6) != 11) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %81 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *     >> %82 = ENTER_SCOPE  // va_sum(3, 10, 20, 30)
 *          %84 = ALLOCA/ARG size=4 align=1  // 3
 *          %83 = CONST/INT32 3  // 3
 *     >> %85 = MEMORY/STORE_LE_32 [%84, %83]  // 3
 *          %87 = ALLOCA/ARG size=4 align=1  // 10
 *          %86 = CONST/INT32 10  // 10
 *     >> %88 = MEMORY/STORE_LE_32 [%87, %86]  // 10
 *          %90 = ALLOCA/ARG size=4 align=1  // 20
 *          %89 = CONST/INT32 20  // 20
 *     >> %91 = MEMORY/STORE_LE_32 [%90, %89]  // 20
 *          %93 = ALLOCA/ARG size=4 align=1  // 30
 *          %92 = CONST/INT32 30  // 30
 *     >> %94 = MEMORY/STORE_LE_32 [%93, %92]  // 30
 *     >> %99 = EXIT_SCOPE
 *          %98 = CMP_NE [%96, %97]  // va_sum(3, 10, 20, 30) != 60
 *     >> %100 = COND_BRANCH [%98]  // if (va_sum(3, 10, 20, 30) != 60) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %106 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %108 = RETURN_PTR  // return 0
 *          %107 = CONST/INT32 0  // 0
 *     >> %109 = MEMORY/STORE_LE_32 [%108, %107]  // return 0
 *     >> %110 = EXIT_SCOPE  // {     // Direct call.     if (add(3, 4) != 7) r...
 *          %107 = CONST/INT32 0  // 0
 *     >> %111 = RET [%107]  // return 0
 *   block_14 IF_THEN  <- [block_13]:
 *          %102 = RETURN_PTR  // return 5
 *          %101 = CONST/INT32 5  // 5
 *     >> %103 = MEMORY/STORE_LE_32 [%102, %101]  // return 5
 *     >> %104 = EXIT_SCOPE  // {     // Direct call.     if (add(3, 4) != 7) r...
 *          %101 = CONST/INT32 5  // 5
 *     >> %105 = RET [%101]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %77 = RETURN_PTR  // return 4
 *          %76 = CONST/INT32 4  // 4
 *     >> %78 = MEMORY/STORE_LE_32 [%77, %76]  // return 4
 *     >> %79 = EXIT_SCOPE  // {     // Direct call.     if (add(3, 4) != 7) r...
 *          %76 = CONST/INT32 4  // 4
 *     >> %80 = RET [%76]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %55 = RETURN_PTR  // return 3
 *          %54 = CONST/INT32 3  // 3
 *     >> %56 = MEMORY/STORE_LE_32 [%55, %54]  // return 3
 *     >> %57 = EXIT_SCOPE  // {     // Direct call.     if (add(3, 4) != 7) r...
 *          %54 = CONST/INT32 3  // 3
 *     >> %58 = RET [%54]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %33 = RETURN_PTR  // return 2
 *          %32 = CONST/INT32 2  // 2
 *     >> %34 = MEMORY/STORE_LE_32 [%33, %32]  // return 2
 *     >> %35 = EXIT_SCOPE  // {     // Direct call.     if (add(3, 4) != 7) r...
 *          %32 = CONST/INT32 2  // 2
 *     >> %36 = RET [%32]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %17 = RETURN_PTR  // return 1
 *          %16 = CONST/INT32 1  // 1
 *     >> %18 = MEMORY/STORE_LE_32 [%17, %16]  // return 1
 *     >> %19 = EXIT_SCOPE  // {     // Direct call.     if (add(3, 4) != 7) r...
 *          %16 = CONST/INT32 1  // 1
 *     >> %20 = RET [%16]  // return 1
 * }
 */








typedef __builtin_va_list va_list;
#define va_start(ap, param) __builtin_va_start(ap, param)
#define va_arg(ap, type)    __builtin_va_arg(ap, type)
#define va_end(ap)          __builtin_va_end(ap)

static int add(int a, int b) {
    return a + b;
}

static int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

static int apply(int (*fn)(int, int), int x, int y) {
    return fn(x, y);
}

static int va_sum(int count, ...) {
    va_list ap;
    va_start(ap, count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(ap, int);
    }
    va_end(ap);
    return sum;
}

int test_function_calls(void) {
    // Direct call.
    if (add(3, 4) != 7) return 1;

    // Recursive call.
    if (factorial(5) != 120) return 2;

    // Function pointer (indirect call).
    int (*fp)(int, int) = add;
    if (fp(10, 20) != 30) return 3;

    // Higher-order function.
    if (apply(add, 5, 6) != 11) return 4;

    // Variadic call.
    if (va_sum(3, 10, 20, 30) != 60) return 5;

    return 0;
}
