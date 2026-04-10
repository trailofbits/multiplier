// Tests: dynamic stack allocation (ALLOCA/DYNAMIC), VLAs, alloca() builtin,
// scope-tracked dynamic objects.

/*
 * Expected IR:
 *
 * function test_dynamic_alloca (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (n)
 *     obj_2 LOCAL_VALUE size=0 align=1 (vla)
 *     obj_3 LOCAL_VALUE size=4 align=1 (i)
 *     obj_4 LOCAL_VALUE size=4 align=1 (m)
 *     obj_5 LOCAL_VALUE size=0 align=1 (inner_vla)
 *     obj_6 LOCAL_VALUE size=4 align=1 (sz)
 *     obj_7 LOCAL_VALUE size=0 align=1 (bigger_vla)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %7 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %8 = ENTER_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %n.0 = ALLOCA/LOCAL size=4 align=1
 *          %9 = CONST/INT32 5  // 5
 *     >> %n.10 = MEMORY/STORE_LE_32 [%n.0, %9]
 *     >> %11 = ENTER_SCOPE  // for (int i = 0; i < n; i++) {         vla[i] = ...
 *     >> %12 = IMPLICIT_GOTO
 *     -> [block_2]
 *   block_2 LOOP_PREHEADER  <- [block_1]:
 *          %i.2 = ALLOCA/LOCAL size=4 align=1
 *          %13 = CONST/INT32 0  // 0
 *     >> %i.14 = MEMORY/STORE_LE_32 [%i.2, %13]
 *     >> %15 = IMPLICIT_GOTO
 *     -> [block_3]
 *   block_3 LOOP_CONDITION  <- [block_2, block_5]:
 *          %18 = CMP_LT [%16, %17]  // i < n
 *     >> %19 = COND_BRANCH [%18]  // for (int i = 0; i < n; i++) {         vla[i] = ...
 *     -> [block_4, block_6]
 *   block_6 LOOP_EXIT  <- [block_3]:
 *     >> %32 = EXIT_SCOPE  // for (int i = 0; i < n; i++) {         vla[i] = ...
 *          %37 = CMP_NE [%35, %36]  // vla[0] != 0
 *     >> %38 = COND_BRANCH [%37]  // if (vla[0] != 0) return 1
 *     -> [block_7, block_8]
 *   block_8 IF_ELSE  <- [block_6]:
 *     >> %44 = IMPLICIT_GOTO
 *     -> [block_9]
 *   block_9 IF_MERGE  <- [block_8]:
 *          %49 = CMP_NE [%47, %48]  // vla[4] != 40
 *     >> %50 = COND_BRANCH [%49]  // if (vla[4] != 40) return 2
 *     -> [block_10, block_11]
 *   block_11 IF_ELSE  <- [block_9]:
 *     >> %56 = IMPLICIT_GOTO
 *     -> [block_12]
 *   block_12 IF_MERGE  <- [block_11]:
 *     >> %57 = ENTER_SCOPE  // {         int m = 3;         int inner_vla[m]; ...
 *          %m.3 = ALLOCA/LOCAL size=4 align=1
 *          %58 = CONST/INT32 3  // 3
 *     >> %m.59 = MEMORY/STORE_LE_32 [%m.3, %58]
 *          %61 = PTR_ADD elem_size=4 [%inner_vla.4, %60]  // inner_vla[0]
 *          %62 = CONST/INT32 100  // 100
 *     >> %63 = MEMORY/STORE_LE_32 [%61, %62]  // inner_vla[0] = 100
 *          %65 = PTR_ADD elem_size=4 [%inner_vla.4, %64]  // inner_vla[2]
 *          %66 = CONST/INT32 300  // 300
 *     >> %67 = MEMORY/STORE_LE_32 [%65, %66]  // inner_vla[2] = 300
 *          %72 = CMP_NE [%70, %71]  // inner_vla[0] != 100
 *     >> %73 = COND_BRANCH [%72]  // if (inner_vla[0] != 100) return 3
 *     -> [block_13, block_14]
 *   block_14 IF_ELSE  <- [block_12]:
 *     >> %80 = IMPLICIT_GOTO
 *     -> [block_15]
 *   block_15 IF_MERGE  <- [block_14]:
 *          %85 = CMP_NE [%83, %84]  // inner_vla[2] != 300
 *     >> %86 = COND_BRANCH [%85]  // if (inner_vla[2] != 300) return 4
 *     -> [block_16, block_17]
 *   block_17 IF_ELSE  <- [block_15]:
 *     >> %93 = IMPLICIT_GOTO
 *     -> [block_18]
 *   block_18 IF_MERGE  <- [block_17]:
 *     >> %94 = EXIT_SCOPE  // {         int m = 3;         int inner_vla[m]; ...
 *          %sz.5 = ALLOCA/LOCAL size=4 align=1
 *          %97 = ADD [%95, %96]  // n + 3
 *     >> %sz.98 = MEMORY/STORE_LE_32 [%sz.5, %97]
 *          %100 = PTR_ADD elem_size=4 [%bigger_vla.6, %99]  // bigger_vla[0]
 *          %101 = CONST/INT32 1  // 1
 *     >> %102 = MEMORY/STORE_LE_32 [%100, %101]  // bigger_vla[0] = 1
 *          %106 = PTR_ADD elem_size=4 [%bigger_vla.6, %105]  // bigger_vla[sz - 1]
 *          %107 = CONST/INT32 99  // 99
 *     >> %108 = MEMORY/STORE_LE_32 [%106, %107]  // bigger_vla[sz - 1] = 99
 *          %113 = CMP_NE [%111, %112]  // bigger_vla[0] != 1
 *     >> %114 = COND_BRANCH [%113]  // if (bigger_vla[0] != 1) return 5
 *     -> [block_19, block_20]
 *   block_20 IF_ELSE  <- [block_18]:
 *     >> %120 = IMPLICIT_GOTO
 *     -> [block_21]
 *   block_21 IF_MERGE  <- [block_20]:
 *          %125 = CMP_NE [%123, %124]  // bigger_vla[7] != 99
 *     >> %126 = COND_BRANCH [%125]  // if (bigger_vla[7] != 99) return 6
 *     -> [block_22, block_23]
 *   block_23 IF_ELSE  <- [block_21]:
 *     >> %132 = IMPLICIT_GOTO
 *     -> [block_24]
 *   block_24 IF_MERGE  <- [block_23]:
 *          %134 = RETURN_PTR  // return 0
 *          %133 = CONST/INT32 0  // 0
 *     >> %135 = MEMORY/STORE_LE_32 [%134, %133]  // return 0
 *     >> %136 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %133 = CONST/INT32 0  // 0
 *     >> %137 = RET [%133]  // return 0
 *   block_22 IF_THEN  <- [block_21]:
 *          %128 = RETURN_PTR  // return 6
 *          %127 = CONST/INT32 6  // 6
 *     >> %129 = MEMORY/STORE_LE_32 [%128, %127]  // return 6
 *     >> %130 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %127 = CONST/INT32 6  // 6
 *     >> %131 = RET [%127]  // return 6
 *   block_19 IF_THEN  <- [block_18]:
 *          %116 = RETURN_PTR  // return 5
 *          %115 = CONST/INT32 5  // 5
 *     >> %117 = MEMORY/STORE_LE_32 [%116, %115]  // return 5
 *     >> %118 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %115 = CONST/INT32 5  // 5
 *     >> %119 = RET [%115]  // return 5
 *   block_16 IF_THEN  <- [block_15]:
 *          %88 = RETURN_PTR  // return 4
 *          %87 = CONST/INT32 4  // 4
 *     >> %89 = MEMORY/STORE_LE_32 [%88, %87]  // return 4
 *     >> %90 = EXIT_SCOPE  // {         int m = 3;         int inner_vla[m]; ...
 *     >> %91 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %87 = CONST/INT32 4  // 4
 *     >> %92 = RET [%87]  // return 4
 *   block_13 IF_THEN  <- [block_12]:
 *          %75 = RETURN_PTR  // return 3
 *          %74 = CONST/INT32 3  // 3
 *     >> %76 = MEMORY/STORE_LE_32 [%75, %74]  // return 3
 *     >> %77 = EXIT_SCOPE  // {         int m = 3;         int inner_vla[m]; ...
 *     >> %78 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %74 = CONST/INT32 3  // 3
 *     >> %79 = RET [%74]  // return 3
 *   block_10 IF_THEN  <- [block_9]:
 *          %52 = RETURN_PTR  // return 2
 *          %51 = CONST/INT32 2  // 2
 *     >> %53 = MEMORY/STORE_LE_32 [%52, %51]  // return 2
 *     >> %54 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %51 = CONST/INT32 2  // 2
 *     >> %55 = RET [%51]  // return 2
 *   block_7 IF_THEN  <- [block_6]:
 *          %40 = RETURN_PTR  // return 1
 *          %39 = CONST/INT32 1  // 1
 *     >> %41 = MEMORY/STORE_LE_32 [%40, %39]  // return 1
 *     >> %42 = EXIT_SCOPE  // {     int n = 5;      // VLA — ALLOCA/DYNAMIC...
 *          %39 = CONST/INT32 1  // 1
 *     >> %43 = RET [%39]  // return 1
 *   block_4 LOOP_BODY  <- [block_3]:
 *     >> %20 = ENTER_SCOPE  // {         vla[i] = i * 10;     }
 *          %22 = PTR_ADD elem_size=4 [%vla.1, %21]  // vla[i]
 *          %25 = MUL [%23, %24]  // i * 10
 *     >> %26 = MEMORY/STORE_LE_32 [%22, %25]  // vla[i] = i * 10
 *     >> %27 = EXIT_SCOPE  // {         vla[i] = i * 10;     }
 *     >> %28 = IMPLICIT_GOTO
 *     -> [block_5]
 *   block_5 LOOP_INCREMENT  <- [block_4]:
 *          %i.2 = ALLOCA/LOCAL size=4 align=1
 *          %29 = CONST/INT64 1  // i++
 *     >> %30 = READ_MODIFY_WRITE(ADD old) [%i.2, %29]  // i++
 *     >> %31 = IMPLICIT_GOTO
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
