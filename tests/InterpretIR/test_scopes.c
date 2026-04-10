// Tests: scope tracking (ENTER_SCOPE, EXIT_SCOPE), nested scopes,
// for-init implicit scope, variable lifetime, compound statements,
// and GNU block expressions ({ ... }).

/*
 * Expected IR:
 *
 * function test_scopes (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=4 align=1 (result)
 *     obj_1 LOCAL_VALUE size=4 align=1 (x)
 *     obj_2 LOCAL_VALUE size=4 align=1 (x)
 *     obj_3 LOCAL_VALUE size=4 align=1 (sum)
 *     obj_4 LOCAL_VALUE size=4 align=1 (i)
 *     obj_5 LOCAL_VALUE size=4 align=1 (total)
 *     obj_6 LOCAL_VALUE size=4 align=1 (i)
 *     obj_7 LOCAL_VALUE size=4 align=1 (i)
 *     obj_8 LOCAL_VALUE size=4 align=1 (block_val)
 *     obj_9 LOCAL_VALUE size=4 align=1 (a)
 *     obj_10 LOCAL_VALUE size=4 align=1 (b)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %11 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %12 = ENTER_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %13 = CONST/INT32 0  // 0
 *     >> %result.14 = MEMORY/STORE_LE_32 [%result.0, %13]
 *     >> %15 = ENTER_SCOPE  // {         int x = 10;         result += x;     }
 *          %x.1 = ALLOCA/LOCAL size=4 align=1
 *          %16 = CONST/INT32 10  // 10
 *     >> %x.17 = MEMORY/STORE_LE_32 [%x.1, %16]
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %18 = MEMORY/LOAD_LE_32 [%x.1]  // x
 *     >> %19 = READ_MODIFY_WRITE(ADD new) [%result.0, %18]  // result += x
 *     >> %20 = EXIT_SCOPE  // {         int x = 10;         result += x;     }
 *     >> %21 = ENTER_SCOPE  // {         int x = 20;         result += x;     }
 *          %x.2 = ALLOCA/LOCAL size=4 align=1
 *          %22 = CONST/INT32 20  // 20
 *     >> %x.23 = MEMORY/STORE_LE_32 [%x.2, %22]
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %24 = MEMORY/LOAD_LE_32 [%x.2]  // x
 *     >> %25 = READ_MODIFY_WRITE(ADD new) [%result.0, %24]  // result += x
 *     >> %26 = EXIT_SCOPE  // {         int x = 20;         result += x;     }
 *          %29 = CMP_NE [%27, %28]  // result != 30
 *     >> %30 = COND_BRANCH [%29]  // if (result != 30) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %36 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %sum.3 = ALLOCA/LOCAL size=4 align=1
 *          %37 = CONST/INT32 0  // 0
 *     >> %sum.38 = MEMORY/STORE_LE_32 [%sum.3, %37]
 *     >> %39 = ENTER_SCOPE  // for (int i = 0; i < 5; i++) {         sum += i;...
 *     >> %40 = IMPLICIT_GOTO
 *     -> [block_5]
 *   block_5 LOOP_PREHEADER  <- [block_4]:
 *          %i.4 = ALLOCA/LOCAL size=4 align=1
 *          %41 = CONST/INT32 0  // 0
 *     >> %i.42 = MEMORY/STORE_LE_32 [%i.4, %41]
 *     >> %43 = IMPLICIT_GOTO
 *     -> [block_6]
 *   block_6 LOOP_CONDITION  <- [block_5, block_8]:
 *          %46 = CMP_LT [%44, %45]  // i < 5
 *     >> %47 = COND_BRANCH [%46]  // for (int i = 0; i < 5; i++) {         sum += i;...
 *     -> [block_7, block_9]
 *   block_9 LOOP_EXIT  <- [block_6]:
 *     >> %56 = EXIT_SCOPE  // for (int i = 0; i < 5; i++) {         sum += i;...
 *          %59 = CMP_NE [%57, %58]  // sum != 10
 *     >> %60 = COND_BRANCH [%59]  // if (sum != 10) return 2
 *     -> [block_10, block_11]
 *   block_11 IF_ELSE  <- [block_9]:
 *     >> %66 = IMPLICIT_GOTO
 *     -> [block_12]
 *   block_12 IF_MERGE  <- [block_11]:
 *          %total.5 = ALLOCA/LOCAL size=4 align=1
 *          %67 = CONST/INT32 0  // 0
 *     >> %total.68 = MEMORY/STORE_LE_32 [%total.5, %67]
 *     >> %69 = ENTER_SCOPE  // for (int i = 0; i < 3; i++) {         for (int ...
 *     >> %70 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 LOOP_PREHEADER  <- [block_12]:
 *          %i.6 = ALLOCA/LOCAL size=4 align=1
 *          %71 = CONST/INT32 0  // 0
 *     >> %i.72 = MEMORY/STORE_LE_32 [%i.6, %71]
 *     >> %73 = IMPLICIT_GOTO
 *     -> [block_14]
 *   block_14 LOOP_CONDITION  <- [block_13, block_16]:
 *          %76 = CMP_LT [%74, %75]  // i < 3
 *     >> %77 = COND_BRANCH [%76]  // for (int i = 0; i < 3; i++) {         for (int ...
 *     -> [block_15, block_17]
 *   block_17 LOOP_EXIT  <- [block_14]:
 *     >> %102 = EXIT_SCOPE  // for (int i = 0; i < 3; i++) {         for (int ...
 *          %105 = CMP_NE [%103, %104]  // total != 6
 *     >> %106 = COND_BRANCH [%105]  // if (total != 6) return 3
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_17]:
 *     >> %112 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *     >> %113 = ENTER_SCOPE  // {         int a = 5;         int b = 7;        ...
 *          %a.9 = ALLOCA/LOCAL size=4 align=1
 *          %114 = CONST/INT32 5  // 5
 *     >> %a.115 = MEMORY/STORE_LE_32 [%a.9, %114]
 *          %b.10 = ALLOCA/LOCAL size=4 align=1
 *          %116 = CONST/INT32 7  // 7
 *     >> %b.117 = MEMORY/STORE_LE_32 [%b.10, %116]
 *     >> %121 = EXIT_SCOPE  // {         int a = 5;         int b = 7;        ...
 *          %block_val.8 = ALLOCA/LOCAL size=4 align=1
 *          %120 = ADD [%118, %119]  // a + b
 *     >> %block_val.122 = MEMORY/STORE_LE_32 [%block_val.8, %120]
 *          %125 = CMP_NE [%123, %124]  // block_val != 12
 *     >> %126 = COND_BRANCH [%125]  // if (block_val != 12) return 4
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %132 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %134 = RETURN_PTR  // return 0
 *          %133 = CONST/INT32 0  // 0
 *     >> %135 = MEMORY/STORE_LE_32 [%134, %133]  // return 0
 *     >> %136 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *          %133 = CONST/INT32 0  // 0
 *     >> %137 = RET [%133]  // return 0
 *   block_26 IF_THEN  <- [block_25]:
 *          %128 = RETURN_PTR  // return 4
 *          %127 = CONST/INT32 4  // 4
 *     >> %129 = MEMORY/STORE_LE_32 [%128, %127]  // return 4
 *     >> %130 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *          %127 = CONST/INT32 4  // 4
 *     >> %131 = RET [%127]  // return 4
 *   block_23 IF_THEN  <- [block_17]:
 *          %108 = RETURN_PTR  // return 3
 *          %107 = CONST/INT32 3  // 3
 *     >> %109 = MEMORY/STORE_LE_32 [%108, %107]  // return 3
 *     >> %110 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *          %107 = CONST/INT32 3  // 3
 *     >> %111 = RET [%107]  // return 3
 *   block_15 LOOP_BODY  <- [block_14]:
 *     >> %78 = ENTER_SCOPE  // {         for (int i = 0; i < 2; i++) {        ...
 *     >> %79 = ENTER_SCOPE  // for (int i = 0; i < 2; i++) {             total...
 *     >> %80 = IMPLICIT_GOTO
 *     -> [block_18]
 *   block_18 LOOP_PREHEADER  <- [block_15]:
 *          %i.7 = ALLOCA/LOCAL size=4 align=1
 *          %81 = CONST/INT32 0  // 0
 *     >> %i.82 = MEMORY/STORE_LE_32 [%i.7, %81]
 *     >> %83 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 LOOP_CONDITION  <- [block_18, block_21]:
 *          %86 = CMP_LT [%84, %85]  // i < 2
 *     >> %87 = COND_BRANCH [%86]  // for (int i = 0; i < 2; i++) {             total...
 *     -> [block_20, block_22]
 *   block_22 LOOP_EXIT  <- [block_19]:
 *     >> %96 = EXIT_SCOPE  // for (int i = 0; i < 2; i++) {             total...
 *     >> %97 = EXIT_SCOPE  // {         for (int i = 0; i < 2; i++) {        ...
 *     >> %98 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 LOOP_INCREMENT  <- [block_22]:
 *          %i.6 = ALLOCA/LOCAL size=4 align=1
 *          %99 = CONST/INT64 1  // i++
 *     >> %100 = READ_MODIFY_WRITE(ADD old) [%i.6, %99]  // i++
 *     >> %101 = IMPLICIT_GOTO
 *     -> [block_14]
 *   block_20 LOOP_BODY  <- [block_19]:
 *     >> %88 = ENTER_SCOPE  // {             total++;         }
 *          %total.5 = ALLOCA/LOCAL size=4 align=1
 *          %89 = CONST/INT64 1  // total++
 *     >> %90 = READ_MODIFY_WRITE(ADD old) [%total.5, %89]  // total++
 *     >> %91 = EXIT_SCOPE  // {             total++;         }
 *     >> %92 = IMPLICIT_GOTO
 *     -> [block_21]
 *   block_21 LOOP_INCREMENT  <- [block_20]:
 *          %i.7 = ALLOCA/LOCAL size=4 align=1
 *          %93 = CONST/INT64 1  // i++
 *     >> %94 = READ_MODIFY_WRITE(ADD old) [%i.7, %93]  // i++
 *     >> %95 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_10 IF_THEN  <- [block_9]:
 *          %62 = RETURN_PTR  // return 2
 *          %61 = CONST/INT32 2  // 2
 *     >> %63 = MEMORY/STORE_LE_32 [%62, %61]  // return 2
 *     >> %64 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *          %61 = CONST/INT32 2  // 2
 *     >> %65 = RET [%61]  // return 2
 *   block_7 LOOP_BODY  <- [block_6]:
 *     >> %48 = ENTER_SCOPE  // {         sum += i;     }
 *          %sum.3 = ALLOCA/LOCAL size=4 align=1
 *          %49 = MEMORY/LOAD_LE_32 [%i.4]  // i
 *     >> %50 = READ_MODIFY_WRITE(ADD new) [%sum.3, %49]  // sum += i
 *     >> %51 = EXIT_SCOPE  // {         sum += i;     }
 *     >> %52 = IMPLICIT_GOTO
 *     -> [block_8]
 *   block_8 LOOP_INCREMENT  <- [block_7]:
 *          %i.4 = ALLOCA/LOCAL size=4 align=1
 *          %53 = CONST/INT64 1  // i++
 *     >> %54 = READ_MODIFY_WRITE(ADD old) [%i.4, %53]  // i++
 *     >> %55 = IMPLICIT_GOTO
 *     -> [block_6]
 *   block_2 IF_THEN  <- [block_1]:
 *          %32 = RETURN_PTR  // return 1
 *          %31 = CONST/INT32 1  // 1
 *     >> %33 = MEMORY/STORE_LE_32 [%32, %31]  // return 1
 *     >> %34 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *          %31 = CONST/INT32 1  // 1
 *     >> %35 = RET [%31]  // return 1
 * }
 */










int test_scopes(void) {
    int result = 0;

    // Nested scopes with same variable names.
    {
        int x = 10;
        result += x;
    }
    {
        int x = 20;
        result += x;
    }
    if (result != 30) return 1;

    // For-init scope: 'i' is scoped to the for loop.
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += i;
    }
    if (sum != 10) return 2;

    // Nested for loops with same variable name.
    int total = 0;
    for (int i = 0; i < 3; i++) {
        for (int i = 0; i < 2; i++) {
            total++;
        }
    }
    if (total != 6) return 3;

    // GNU block expression.
    int block_val = ({
        int a = 5;
        int b = 7;
        a + b;
    });
    if (block_val != 12) return 4;

    return 0;
}
