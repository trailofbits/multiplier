// Tests: dynamic stack allocation (ALLOCA/DYNAMIC), VLAs, alloca() builtin,
// scope-tracked dynamic objects.

/*
 * Expected IR:
 *
 * function test_dynamic_alloca (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=4 align=1 (n)
 *     obj_1 LOCAL_VALUE size=0 align=1 (vla)
 *     obj_2 LOCAL_VALUE size=4 align=1 (i)
 *     obj_3 LOCAL_VALUE size=4 align=1 (m)
 *     obj_4 LOCAL_VALUE size=0 align=1 (inner_vla)
 *     obj_5 LOCAL_VALUE size=4 align=1 (sz)
 *     obj_6 LOCAL_VALUE size=0 align=1 (bigger_vla)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %4 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %5 = ENTER_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %n.0 = ALLOCA/LOCAL size=4 align=1
 *          %6 = CONST/INT32 5  // 5
 *     >> %n.7 = MEMORY/STORE_LE_32 [%n.0, %6]
 *     >> %12 = ENTER_SCOPE  // for (int i = 0; i < n; i++) {         vla[i] = ...
 *     >> %13 = IMPLICIT_GOTO
 *     -> [block_2]
 *   block_2 LOOP_PREHEADER  <- [block_1]:
 *          %i.1 = ALLOCA/LOCAL size=4 align=1
 *          %14 = CONST/INT32 0  // 0
 *     >> %i.15 = MEMORY/STORE_LE_32 [%i.1, %14]
 *     >> %16 = IMPLICIT_GOTO
 *     -> [block_3]
 *   block_3 LOOP_CONDITION  <- [block_2, block_5]:
 *          %19 = CMP_LT [%17, %18]  // i < n
 *     >> %20 = COND_BRANCH [%19]  // for (int i = 0; i < n; i++) {         vla[i] = ...
 *     -> [block_4, block_6]
 *   block_6 LOOP_EXIT  <- [block_3]:
 *     >> %33 = EXIT_SCOPE  // for (int i = 0; i < n; i++) {         vla[i] = ...
 *          %38 = CMP_NE [%36, %37]  // vla[0] != 0
 *     >> %39 = COND_BRANCH [%38]  // if (vla[0] != 0) return 1
 *     -> [block_7, block_8]
 *   block_8 IF_ELSE  <- [block_6]:
 *     >> %45 = IMPLICIT_GOTO
 *     -> [block_9]
 *   block_9 IF_MERGE  <- [block_8]:
 *          %50 = CMP_NE [%48, %49]  // vla[4] != 40
 *     >> %51 = COND_BRANCH [%50]  // if (vla[4] != 40) return 2
 *     -> [block_10, block_11]
 *   block_11 IF_ELSE  <- [block_9]:
 *     >> %57 = IMPLICIT_GOTO
 *     -> [block_12]
 *   block_12 IF_MERGE  <- [block_11]:
 *     >> %58 = ENTER_SCOPE  // {         int m = 3;         int inner_vla[m]; ...
 *          %m.2 = ALLOCA/LOCAL size=4 align=1
 *          %59 = CONST/INT32 3  // 3
 *     >> %m.60 = MEMORY/STORE_LE_32 [%m.2, %59]
 *          %66 = PTR_ADD elem_size=4 [%inner_vla.64, %65]  // inner_vla[0]
 *          %67 = CONST/INT32 100  // 100
 *     >> %68 = MEMORY/STORE_LE_32 [%66, %67]  // inner_vla[0] = 100
 *          %70 = PTR_ADD elem_size=4 [%inner_vla.64, %69]  // inner_vla[2]
 *          %71 = CONST/INT32 300  // 300
 *     >> %72 = MEMORY/STORE_LE_32 [%70, %71]  // inner_vla[2] = 300
 *          %77 = CMP_NE [%75, %76]  // inner_vla[0] != 100
 *     >> %78 = COND_BRANCH [%77]  // if (inner_vla[0] != 100) return 3
 *     -> [block_13, block_14]
 *   block_14 IF_ELSE  <- [block_12]:
 *     >> %85 = IMPLICIT_GOTO
 *     -> [block_15]
 *   block_15 IF_MERGE  <- [block_14]:
 *          %90 = CMP_NE [%88, %89]  // inner_vla[2] != 300
 *     >> %91 = COND_BRANCH [%90]  // if (inner_vla[2] != 300) return 4
 *     -> [block_16, block_17]
 *   block_17 IF_ELSE  <- [block_15]:
 *     >> %98 = IMPLICIT_GOTO
 *     -> [block_18]
 *   block_18 IF_MERGE  <- [block_17]:
 *     >> %99 = EXIT_SCOPE  // {         int m = 3;         int inner_vla[m]; ...
 *          %sz.3 = ALLOCA/LOCAL size=4 align=1
 *          %102 = ADD [%100, %101]  // n + 3
 *     >> %sz.103 = MEMORY/STORE_LE_32 [%sz.3, %102]
 *          %109 = PTR_ADD elem_size=4 [%bigger_vla.107, %108]  // bigger_vla[0]
 *          %110 = CONST/INT32 1  // 1
 *     >> %111 = MEMORY/STORE_LE_32 [%109, %110]  // bigger_vla[0] = 1
 *          %115 = PTR_ADD elem_size=4 [%bigger_vla.107, %114]  // bigger_vla[sz - 1]
 *          %116 = CONST/INT32 99  // 99
 *     >> %117 = MEMORY/STORE_LE_32 [%115, %116]  // bigger_vla[sz - 1] = 99
 *          %122 = CMP_NE [%120, %121]  // bigger_vla[0] != 1
 *     >> %123 = COND_BRANCH [%122]  // if (bigger_vla[0] != 1) return 5
 *     -> [block_19, block_20]
 *   block_20 IF_ELSE  <- [block_18]:
 *     >> %129 = IMPLICIT_GOTO
 *     -> [block_21]
 *   block_21 IF_MERGE  <- [block_20]:
 *          %134 = CMP_NE [%132, %133]  // bigger_vla[7] != 99
 *     >> %135 = COND_BRANCH [%134]  // if (bigger_vla[7] != 99) return 6
 *     -> [block_22, block_23]
 *   block_23 IF_ELSE  <- [block_21]:
 *     >> %141 = IMPLICIT_GOTO
 *     -> [block_24]
 *   block_24 IF_MERGE  <- [block_23]:
 *          %143 = RETURN_PTR  // return 0
 *          %142 = CONST/INT32 0  // 0
 *     >> %144 = MEMORY/STORE_LE_32 [%143, %142]  // return 0
 *     >> %145 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %142 = CONST/INT32 0  // 0
 *     >> %146 = RET [%142]  // return 0
 *   block_22 IF_THEN  <- [block_21]:
 *          %137 = RETURN_PTR  // return 6
 *          %136 = CONST/INT32 6  // 6
 *     >> %138 = MEMORY/STORE_LE_32 [%137, %136]  // return 6
 *     >> %139 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %136 = CONST/INT32 6  // 6
 *     >> %140 = RET [%136]  // return 6
 *   block_19 IF_THEN  <- [block_18]:
 *          %125 = RETURN_PTR  // return 5
 *          %124 = CONST/INT32 5  // 5
 *     >> %126 = MEMORY/STORE_LE_32 [%125, %124]  // return 5
 *     >> %127 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %124 = CONST/INT32 5  // 5
 *     >> %128 = RET [%124]  // return 5
 *   block_16 IF_THEN  <- [block_15]:
 *          %93 = RETURN_PTR  // return 4
 *          %92 = CONST/INT32 4  // 4
 *     >> %94 = MEMORY/STORE_LE_32 [%93, %92]  // return 4
 *     >> %95 = EXIT_SCOPE  // {         int m = 3;         int inner_vla[m]; ...
 *     >> %96 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %92 = CONST/INT32 4  // 4
 *     >> %97 = RET [%92]  // return 4
 *   block_13 IF_THEN  <- [block_12]:
 *          %80 = RETURN_PTR  // return 3
 *          %79 = CONST/INT32 3  // 3
 *     >> %81 = MEMORY/STORE_LE_32 [%80, %79]  // return 3
 *     >> %82 = EXIT_SCOPE  // {         int m = 3;         int inner_vla[m]; ...
 *     >> %83 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %79 = CONST/INT32 3  // 3
 *     >> %84 = RET [%79]  // return 3
 *   block_10 IF_THEN  <- [block_9]:
 *          %53 = RETURN_PTR  // return 2
 *          %52 = CONST/INT32 2  // 2
 *     >> %54 = MEMORY/STORE_LE_32 [%53, %52]  // return 2
 *     >> %55 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %52 = CONST/INT32 2  // 2
 *     >> %56 = RET [%52]  // return 2
 *   block_7 IF_THEN  <- [block_6]:
 *          %41 = RETURN_PTR  // return 1
 *          %40 = CONST/INT32 1  // 1
 *     >> %42 = MEMORY/STORE_LE_32 [%41, %40]  // return 1
 *     >> %43 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %40 = CONST/INT32 1  // 1
 *     >> %44 = RET [%40]  // return 1
 *   block_4 LOOP_BODY  <- [block_3]:
 *     >> %21 = ENTER_SCOPE  // {         vla[i] = i * 10;     }
 *          %23 = PTR_ADD elem_size=4 [%vla.11, %22]  // vla[i]
 *          %26 = MUL [%24, %25]  // i * 10
 *     >> %27 = MEMORY/STORE_LE_32 [%23, %26]  // vla[i] = i * 10
 *     >> %28 = EXIT_SCOPE  // {         vla[i] = i * 10;     }
 *     >> %29 = IMPLICIT_GOTO
 *     -> [block_5]
 *   block_5 LOOP_INCREMENT  <- [block_4]:
 *          %i.1 = ALLOCA/LOCAL size=4 align=1
 *          %30 = CONST/INT64 1  // i++
 *     >> %31 = READ_MODIFY_WRITE(ADD old) [%i.1, %30]  // i++
 *     >> %32 = IMPLICIT_GOTO
 *     -> [block_3]
 * }
 */










int test_dynamic_alloca(void) {
    int n = 5;

    // VLA — ALLOCA/DYNAMIC with runtime size.
    int vla[n];
    for (int i = 0; i < n; i++) {
        vla[i] = i * 10;
    }
    if (vla[0] != 0) return 1;
    if (vla[4] != 40) return 2;

    // VLA in a nested scope.
    {
        int m = 3;
        int inner_vla[m];
        inner_vla[0] = 100;
        inner_vla[2] = 300;
        if (inner_vla[0] != 100) return 3;
        if (inner_vla[2] != 300) return 4;
    }
    // inner_vla is now out of scope.

    // VLA size from computation.
    int sz = n + 3;
    int bigger_vla[sz];
    bigger_vla[0] = 1;
    bigger_vla[sz - 1] = 99;
    if (bigger_vla[0] != 1) return 5;
    if (bigger_vla[7] != 99) return 6;

    return 0;
}
