// Tests: switch statement (SWITCH, SWITCH_CASE, SWITCH_DEFAULT, SWITCH_EXIT),
// fallthrough (IMPLICIT_FALLTHROUGH), explicit fallthrough (FALLTHROUGH),
// break within switch (BREAK), nested switch, and switch with ranges (GNU).

/*
 * Expected IR:
 *
 * function test_switch (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=4 align=4 (val)
 *     obj_1 LOCAL_VALUE size=4 align=4 (result)
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %val.0 = ALLOCA/LOCAL size=4 align=4
 *     >> %result.1 = ALLOCA/LOCAL size=4 align=4
 *     >> %2 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %3 = ENTER_SCOPE  // {     // Basic switch.     int val = 2;     int...
 *          %val.0 = ALLOCA/LOCAL size=4 align=4
 *          %4 = CONST/INT32 2  // 2
 *     >> %val.5 = MEMORY/STORE_LE_32 [%val.0, %4]
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %6 = CONST/INT32 0  // 0
 *     >> %result.7 = MEMORY/STORE_LE_32 [%result.1, %6]
 *          %8 = MEMORY/LOAD_LE_32 [%val.0]  // val
 *     >> %9 = SWITCH cases=4 { 1->block_3, 2->block_4, 3->block_5, default->block_6 } [%8]  // switch (val) {         case 1: result = 10; bre...
 *     -> [block_3, block_4, block_5, block_6]
 *   block_6 SWITCH_DEFAULT  <- [block_1]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %22 = CONST/INT32 1  // 1
 *          %23 = NEG [%22]  // -1
 *     >> %24 = MEMORY/STORE_LE_32 [%result.1, %23]  // result = -1
 *     >> %25 = BREAK  // break
 *     -> [block_2]
 *   block_5 SWITCH_CASE  <- [block_1]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %18 = CONST/INT32 30  // 30
 *     >> %19 = MEMORY/STORE_LE_32 [%result.1, %18]  // result = 30
 *     >> %20 = BREAK  // break
 *     -> [block_2]
 *   block_4 SWITCH_CASE  <- [block_1]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %14 = CONST/INT32 20  // 20
 *     >> %15 = MEMORY/STORE_LE_32 [%result.1, %14]  // result = 20
 *     >> %16 = BREAK  // break
 *     -> [block_2]
 *   block_3 SWITCH_CASE  <- [block_1]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %10 = CONST/INT32 10  // 10
 *     >> %11 = MEMORY/STORE_LE_32 [%result.1, %10]  // result = 10
 *     >> %12 = BREAK  // break
 *     -> [block_2]
 *   block_2 SWITCH_EXIT  <- [block_3, block_4, block_5, block_6]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %27 = MEMORY/LOAD_LE_32 [%result.1]  // result
 *          %28 = CONST/INT32 20  // 20
 *          %29 = CMP_NE [%27, %28]  // result != 20
 *     >> %30 = COND_BRANCH [%29]  // if (result != 20) return 1
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_2]:
 *     >> %36 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %37 = CONST/INT32 99  // 99
 *     >> %38 = SWITCH cases=2 { 1->block_15, default->block_16 } [%37]  // switch (99) {         case 1: result = 10; brea...
 *     -> [block_15, block_16]
 *   block_16 SWITCH_DEFAULT  <- [block_13]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %43 = CONST/INT32 42  // 42
 *     >> %44 = MEMORY/STORE_LE_32 [%result.1, %43]  // result = 42
 *     >> %45 = BREAK  // break
 *     -> [block_14]
 *   block_15 SWITCH_CASE  <- [block_13]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %39 = CONST/INT32 10  // 10
 *     >> %40 = MEMORY/STORE_LE_32 [%result.1, %39]  // result = 10
 *     >> %41 = BREAK  // break
 *     -> [block_14]
 *   block_14 SWITCH_EXIT  <- [block_15, block_16]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %47 = MEMORY/LOAD_LE_32 [%result.1]  // result
 *          %48 = CONST/INT32 42  // 42
 *          %49 = CMP_NE [%47, %48]  // result != 42
 *     >> %50 = COND_BRANCH [%49]  // if (result != 42) return 2
 *     -> [block_19, block_20]
 *   block_20 IF_ELSE  <- [block_14]:
 *     >> %56 = IMPLICIT_GOTO
 *     -> [block_21]
 *   block_21 IF_MERGE  <- [block_20]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %57 = CONST/INT32 0  // 0
 *     >> %58 = MEMORY/STORE_LE_32 [%result.1, %57]  // result = 0
 *          %59 = CONST/INT32 1  // 1
 *     >> %60 = SWITCH cases=4 { 1->block_23, 2->block_24, 3->block_25, default->block_26 } [%59]  // switch (1) {         case 1: result += 1;      ...
 *     -> [block_23, block_24, block_25, block_26]
 *   block_26 SWITCH_DEFAULT  <- [block_21]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %71 = CONST/INT32 1  // 1
 *          %72 = NEG [%71]  // -1
 *     >> %73 = MEMORY/STORE_LE_32 [%result.1, %72]  // result = -1
 *     >> %74 = BREAK  // break
 *     -> [block_22]
 *   block_23 SWITCH_CASE  <- [block_21]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %61 = CONST/INT32 1  // 1
 *     >> %62 = READ_MODIFY_WRITE(ADD new) [%result.1, %61]  // result += 1
 *     >> %63 = IMPLICIT_FALLTHROUGH
 *     -> [block_24]
 *   block_24 SWITCH_CASE  <- [block_21, block_23]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %64 = CONST/INT32 2  // 2
 *     >> %65 = READ_MODIFY_WRITE(ADD new) [%result.1, %64]  // result += 2
 *     >> %66 = IMPLICIT_FALLTHROUGH
 *     -> [block_25]
 *   block_25 SWITCH_CASE  <- [block_21, block_24]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %67 = CONST/INT32 3  // 3
 *     >> %68 = READ_MODIFY_WRITE(ADD new) [%result.1, %67]  // result += 3
 *     >> %69 = BREAK  // break
 *     -> [block_22]
 *   block_22 SWITCH_EXIT  <- [block_25, block_26]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %76 = MEMORY/LOAD_LE_32 [%result.1]  // result
 *          %77 = CONST/INT32 6  // 6
 *          %78 = CMP_NE [%76, %77]  // result != 6
 *     >> %79 = COND_BRANCH [%78]  // if (result != 6) return 3
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_22]:
 *     >> %85 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %86 = CONST/INT32 0  // 0
 *     >> %87 = MEMORY/STORE_LE_32 [%result.1, %86]  // result = 0
 *          %88 = CONST/INT32 2  // 2
 *     >> %89 = SWITCH cases=4 { 1->block_33, 2->block_34, 3->block_35, default->block_36 } [%88]  // switch (2) {         case 1:         case 2:   ...
 *     -> [block_33, block_34, block_35, block_36]
 *   block_36 SWITCH_DEFAULT  <- [block_31]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %96 = CONST/INT32 1  // 1
 *          %97 = NEG [%96]  // -1
 *     >> %98 = MEMORY/STORE_LE_32 [%result.1, %97]  // result = -1
 *     >> %99 = BREAK  // break
 *     -> [block_32]
 *   block_33 SWITCH_CASE  <- [block_31]:
 *     >> %90 = IMPLICIT_FALLTHROUGH
 *     -> [block_34]
 *   block_34 SWITCH_CASE  <- [block_31, block_33]:
 *     >> %91 = IMPLICIT_FALLTHROUGH
 *     -> [block_35]
 *   block_35 SWITCH_CASE  <- [block_31, block_34]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %92 = CONST/INT32 100  // 100
 *     >> %93 = MEMORY/STORE_LE_32 [%result.1, %92]  // result = 100
 *     >> %94 = BREAK  // break
 *     -> [block_32]
 *   block_32 SWITCH_EXIT  <- [block_35, block_36]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %101 = MEMORY/LOAD_LE_32 [%result.1]  // result
 *          %102 = CONST/INT32 100  // 100
 *          %103 = CMP_NE [%101, %102]  // result != 100
 *     >> %104 = COND_BRANCH [%103]  // if (result != 100) return 4
 *     -> [block_39, block_40]
 *   block_40 IF_ELSE  <- [block_32]:
 *     >> %110 = IMPLICIT_GOTO
 *     -> [block_41]
 *   block_41 IF_MERGE  <- [block_40]:
 *          %112 = RETURN_PTR  // return 0
 *          %111 = CONST/INT32 0  // 0
 *     >> %113 = MEMORY/STORE_LE_32 [%112, %111]  // return 0
 *     >> %114 = EXIT_SCOPE  // {     // Basic switch.     int val = 2;     int...
 *     >> %115 = RET [%111]  // return 0
 *   block_39 IF_THEN  <- [block_32]:
 *          %106 = RETURN_PTR  // return 4
 *          %105 = CONST/INT32 4  // 4
 *     >> %107 = MEMORY/STORE_LE_32 [%106, %105]  // return 4
 *     >> %108 = EXIT_SCOPE  // {     // Basic switch.     int val = 2;     int...
 *     >> %109 = RET [%105]  // return 4
 *   block_29 IF_THEN  <- [block_22]:
 *          %81 = RETURN_PTR  // return 3
 *          %80 = CONST/INT32 3  // 3
 *     >> %82 = MEMORY/STORE_LE_32 [%81, %80]  // return 3
 *     >> %83 = EXIT_SCOPE  // {     // Basic switch.     int val = 2;     int...
 *     >> %84 = RET [%80]  // return 3
 *   block_19 IF_THEN  <- [block_14]:
 *          %52 = RETURN_PTR  // return 2
 *          %51 = CONST/INT32 2  // 2
 *     >> %53 = MEMORY/STORE_LE_32 [%52, %51]  // return 2
 *     >> %54 = EXIT_SCOPE  // {     // Basic switch.     int val = 2;     int...
 *     >> %55 = RET [%51]  // return 2
 *   block_11 IF_THEN  <- [block_2]:
 *          %32 = RETURN_PTR  // return 1
 *          %31 = CONST/INT32 1  // 1
 *     >> %33 = MEMORY/STORE_LE_32 [%32, %31]  // return 1
 *     >> %34 = EXIT_SCOPE  // {     // Basic switch.     int val = 2;     int...
 *     >> %35 = RET [%31]  // return 1
 * }
 */










int test_switch(void) {
    // Basic switch.
    int val = 2;
    int result = 0;
    switch (val) {
        case 1: result = 10; break;
        case 2: result = 20; break;
        case 3: result = 30; break;
        default: result = -1; break;
    }
    if (result != 20) return 1;

    // Default case.
    switch (99) {
        case 1: result = 10; break;
        default: result = 42; break;
    }
    if (result != 42) return 2;

    // Fallthrough (implicit).
    result = 0;
    switch (1) {
        case 1: result += 1;
        case 2: result += 2;
        case 3: result += 3; break;
        default: result = -1; break;
    }
    if (result != 6) return 3;  // 1+2+3 from fallthrough

    // Empty cases.
    result = 0;
    switch (2) {
        case 1:
        case 2:
        case 3:
            result = 100;
            break;
        default:
            result = -1;
            break;
    }
    if (result != 100) return 4;

    return 0;
}
