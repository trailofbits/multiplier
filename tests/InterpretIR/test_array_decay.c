// Tests: array-to-pointer decay (ArrayToPointerDecay → EmitLValue, not EmitRValue),
// passing arrays to functions, array parameters adjusted to pointers by Clang.

/*
 * Expected IR:
 *
 * function test_array_decay (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=20 align=1 (arr)
 *     obj_1 LOCAL_VALUE size=4 align=1 (total)
 *     obj_2 LOCAL_VALUE size=4 align=1 (first)
 *     obj_3 LOCAL_VALUE size=12 align=1 (buf)
 *     obj_4 LOCAL_VALUE size=8 align=1 (p)
 *     obj_5 LOCAL_VALUE size=8 align=1 (q)
 *     obj_6 PARAMETER size=8 align=1
 *     obj_7 PARAMETER size=4 align=1
 *     obj_8 RETURN_SLOT size=4 align=1
 *     obj_9 PARAMETER size=8 align=1
 *     obj_10 RETURN_SLOT size=4 align=1
 *     obj_11 PARAMETER size=8 align=1
 *     obj_12 PARAMETER size=4 align=1
 *     obj_13 PARAMETER size=4 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %6 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %7 = ENTER_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *          %arr.8 = CONST/UINT8 0
 *          %arr.9 = CONST/UINT64 20
 *     >> %arr.10 = MEMORY/MEMSET [%arr.0, %arr.8, %arr.9]
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *          %11 = CONST/INT32 10  // 10
 *     >> %arr.12 = MEMORY/STORE_LE_32 [%arr.0, %11]
 *          %arr.14 = PTR_ADD elem_size=4 [%arr.0, %arr.13]
 *          %15 = CONST/INT32 20  // 20
 *     >> %arr.16 = MEMORY/STORE_LE_32 [%arr.14, %15]
 *          %arr.18 = PTR_ADD elem_size=4 [%arr.0, %arr.17]
 *          %19 = CONST/INT32 30  // 30
 *     >> %arr.20 = MEMORY/STORE_LE_32 [%arr.18, %19]
 *          %arr.22 = PTR_ADD elem_size=4 [%arr.0, %arr.21]
 *          %23 = CONST/INT32 40  // 40
 *     >> %arr.24 = MEMORY/STORE_LE_32 [%arr.22, %23]
 *          %arr.26 = PTR_ADD elem_size=4 [%arr.0, %arr.25]
 *          %27 = CONST/INT32 50  // 50
 *     >> %arr.28 = MEMORY/STORE_LE_32 [%arr.26, %27]
 *     >> %29 = ENTER_SCOPE  // sum_array(arr, 5)
 *          %30 = ALLOCA/ARG size=8 align=1  // arr
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *     >> %31 = MEMORY/STORE_LE_64 [%30, %arr.0]  // arr
 *          %33 = ALLOCA/ARG size=4 align=1  // 5
 *          %32 = CONST/INT32 5  // 5
 *     >> %34 = MEMORY/STORE_LE_32 [%33, %32]  // 5
 *          %total.1 = ALLOCA/LOCAL size=4 align=1
 *          %36 = CALL @sum_array [%30, %33]  // sum_array(arr, 5)
 *     >> %total.37 = MEMORY/STORE_LE_32 [%total.1, %36]
 *     >> %41 = EXIT_SCOPE
 *          %40 = CMP_NE [%38, %39]  // total != 150
 *     >> %42 = COND_BRANCH [%40]  // if (total != 150) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %49 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *     >> %50 = ENTER_SCOPE  // first_element(arr)
 *          %51 = ALLOCA/ARG size=8 align=1  // arr
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *     >> %52 = MEMORY/STORE_LE_64 [%51, %arr.0]  // arr
 *          %first.2 = ALLOCA/LOCAL size=4 align=1
 *          %54 = CALL @first_element [%51]  // first_element(arr)
 *     >> %first.55 = MEMORY/STORE_LE_32 [%first.2, %54]
 *     >> %59 = EXIT_SCOPE
 *          %58 = CMP_NE [%56, %57]  // first != 10
 *     >> %60 = COND_BRANCH [%58]  // if (first != 10) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %67 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *     >> %68 = ENTER_SCOPE  // fill_array(buf, 42, 3)
 *          %69 = ALLOCA/ARG size=8 align=1  // buf
 *          %buf.3 = ALLOCA/LOCAL size=12 align=1
 *     >> %70 = MEMORY/STORE_LE_64 [%69, %buf.3]  // buf
 *          %72 = ALLOCA/ARG size=4 align=1  // 42
 *          %71 = CONST/INT32 42  // 42
 *     >> %73 = MEMORY/STORE_LE_32 [%72, %71]  // 42
 *          %75 = ALLOCA/ARG size=4 align=1  // 3
 *          %74 = CONST/INT32 3  // 3
 *     >> %76 = MEMORY/STORE_LE_32 [%75, %74]  // 3
 *          %69 = ALLOCA/ARG size=8 align=1  // buf
 *          %72 = ALLOCA/ARG size=4 align=1  // 42
 *          %75 = ALLOCA/ARG size=4 align=1  // 3
 *     >> %77 = CALL @fill_array [%69, %72, %75]  // fill_array(buf, 42, 3)
 *     >> %78 = EXIT_SCOPE
 *          %83 = CMP_NE [%81, %82]  // buf[0] != 42
 *     >> %84 = COND_BRANCH [%83]  // if (buf[0] != 42) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %90 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %95 = CMP_NE [%93, %94]  // buf[1] != 42
 *     >> %96 = COND_BRANCH [%95]  // if (buf[1] != 42) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %102 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %107 = CMP_NE [%105, %106]  // buf[2] != 42
 *     >> %108 = COND_BRANCH [%107]  // if (buf[2] != 42) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %114 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %p.4 = ALLOCA/LOCAL size=8 align=1
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *     >> %p.115 = MEMORY/STORE_LE_64 [%p.4, %arr.0]
 *          %118 = PTR_ADD elem_size=4 [%116, %117]  // p[2]
 *          %119 = CONST/INT32 99  // 99
 *     >> %120 = MEMORY/STORE_LE_32 [%118, %119]  // p[2] = 99
 *          %125 = CMP_NE [%123, %124]  // arr[2] != 99
 *     >> %126 = COND_BRANCH [%125]  // if (arr[2] != 99) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %132 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %q.5 = ALLOCA/LOCAL size=8 align=1
 *          %134 = PTR_ADD elem_size=4 [%arr.0, %133]  // arr + 3
 *     >> %q.135 = MEMORY/STORE_LE_64 [%q.5, %134]
 *          %139 = CMP_NE [%137, %138]  // *q != 40
 *     >> %140 = COND_BRANCH [%139]  // if (*q != 40) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %146 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %148 = RETURN_PTR  // return 0
 *          %147 = CONST/INT32 0  // 0
 *     >> %149 = MEMORY/STORE_LE_32 [%148, %147]  // return 0
 *     >> %150 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %147 = CONST/INT32 0  // 0
 *     >> %151 = RET [%147]  // return 0
 *   block_20 IF_THEN  <- [block_19]:
 *          %142 = RETURN_PTR  // return 7
 *          %141 = CONST/INT32 7  // 7
 *     >> %143 = MEMORY/STORE_LE_32 [%142, %141]  // return 7
 *     >> %144 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %141 = CONST/INT32 7  // 7
 *     >> %145 = RET [%141]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %128 = RETURN_PTR  // return 6
 *          %127 = CONST/INT32 6  // 6
 *     >> %129 = MEMORY/STORE_LE_32 [%128, %127]  // return 6
 *     >> %130 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %127 = CONST/INT32 6  // 6
 *     >> %131 = RET [%127]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %110 = RETURN_PTR  // return 5
 *          %109 = CONST/INT32 5  // 5
 *     >> %111 = MEMORY/STORE_LE_32 [%110, %109]  // return 5
 *     >> %112 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %109 = CONST/INT32 5  // 5
 *     >> %113 = RET [%109]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %98 = RETURN_PTR  // return 4
 *          %97 = CONST/INT32 4  // 4
 *     >> %99 = MEMORY/STORE_LE_32 [%98, %97]  // return 4
 *     >> %100 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %97 = CONST/INT32 4  // 4
 *     >> %101 = RET [%97]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %86 = RETURN_PTR  // return 3
 *          %85 = CONST/INT32 3  // 3
 *     >> %87 = MEMORY/STORE_LE_32 [%86, %85]  // return 3
 *     >> %88 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %85 = CONST/INT32 3  // 3
 *     >> %89 = RET [%85]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %62 = RETURN_PTR  // return 2
 *          %61 = CONST/INT32 2  // 2
 *     >> %63 = MEMORY/STORE_LE_32 [%62, %61]  // return 2
 *     >> %64 = EXIT_SCOPE  // first_element(arr)
 *     >> %65 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %61 = CONST/INT32 2  // 2
 *     >> %66 = RET [%61]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %44 = RETURN_PTR  // return 1
 *          %43 = CONST/INT32 1  // 1
 *     >> %45 = MEMORY/STORE_LE_32 [%44, %43]  // return 1
 *     >> %46 = EXIT_SCOPE  // sum_array(arr, 5)
 *     >> %47 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %43 = CONST/INT32 1  // 1
 *     >> %48 = RET [%43]  // return 1
 * }
 */








static int sum_array(int *arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

static int first_element(int arr[10]) {
    // Clang adjusts int arr[10] to int *arr.
    return arr[0];
}

static void fill_array(int *dst, int val, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = val;
    }
}

int test_array_decay(void) {
    int arr[5] = {10, 20, 30, 40, 50};

    // Pass array to function — array decays to pointer.
    // The ALLOCA for arr IS the decayed pointer.
    int total = sum_array(arr, 5);
    if (total != 150) return 1;

    // Pass array with explicit size in parameter type.
    int first = first_element(arr);
    if (first != 10) return 2;

    // Pass array to function that modifies it.
    int buf[3];
    fill_array(buf, 42, 3);
    if (buf[0] != 42) return 3;
    if (buf[1] != 42) return 4;
    if (buf[2] != 42) return 5;

    // Assign array element via decayed pointer.
    int *p = arr;
    p[2] = 99;
    if (arr[2] != 99) return 6;

    // Array decay in expressions.
    int *q = arr + 3;
    if (*q != 40) return 7;

    return 0;
}
