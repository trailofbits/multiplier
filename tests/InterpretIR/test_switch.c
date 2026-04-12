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
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %111 = CONST/INT32 0  // 0
 *     >> %112 = MEMORY/STORE_LE_32 [%result.1, %111]  // result = 0
 *          %113 = CONST/INT32 1  // 1
 *     >> %114 = SWITCH cases=3 { 1->block_43, 2->block_44, default->block_45 } [%113]  // switch (1) {         case 1:             switch...
 *     -> [block_43, block_44, block_45]
 *   block_45 SWITCH_DEFAULT  <- [block_41]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %135 = CONST/INT32 90  // 90
 *     >> %136 = MEMORY/STORE_LE_32 [%result.1, %135]  // result = 90
 *     >> %137 = BREAK  // break
 *     -> [block_42]
 *   block_44 SWITCH_CASE  <- [block_41]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %131 = CONST/INT32 80  // 80
 *     >> %132 = MEMORY/STORE_LE_32 [%result.1, %131]  // result = 80
 *     >> %133 = BREAK  // break
 *     -> [block_42]
 *   block_43 SWITCH_CASE  <- [block_41]:
 *          %115 = CONST/INT32 10  // 10
 *     >> %116 = SWITCH cases=3 { 10->block_47, 20->block_48, default->block_49 } [%115]  // switch (10) {                 case 10: result =...
 *     -> [block_47, block_48, block_49]
 *   block_49 SWITCH_DEFAULT  <- [block_43]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %125 = CONST/INT32 70  // 70
 *     >> %126 = MEMORY/STORE_LE_32 [%result.1, %125]  // result = 70
 *     >> %127 = BREAK  // break
 *     -> [block_46]
 *   block_48 SWITCH_CASE  <- [block_43]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %121 = CONST/INT32 60  // 60
 *     >> %122 = MEMORY/STORE_LE_32 [%result.1, %121]  // result = 60
 *     >> %123 = BREAK  // break
 *     -> [block_46]
 *   block_47 SWITCH_CASE  <- [block_43]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %117 = CONST/INT32 50  // 50
 *     >> %118 = MEMORY/STORE_LE_32 [%result.1, %117]  // result = 50
 *     >> %119 = BREAK  // break
 *     -> [block_46]
 *   block_46 SWITCH_EXIT  <- [block_47, block_48, block_49]:
 *     >> %129 = BREAK  // break
 *     -> [block_42]
 *   block_42 SWITCH_EXIT  <- [block_46, block_44, block_45]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %139 = MEMORY/LOAD_LE_32 [%result.1]  // result
 *          %140 = CONST/INT32 50  // 50
 *          %141 = CMP_NE [%139, %140]  // result != 50
 *     >> %142 = COND_BRANCH [%141]  // if (result != 50) return 5
 *     -> [block_56, block_57]
 *   block_57 IF_ELSE  <- [block_42]:
 *     >> %148 = IMPLICIT_GOTO
 *     -> [block_58]
 *   block_58 IF_MERGE  <- [block_57]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %149 = CONST/INT32 0  // 0
 *     >> %150 = MEMORY/STORE_LE_32 [%result.1, %149]  // result = 0
 *          %151 = CONST/INT32 2  // 2
 *     >> %152 = SWITCH cases=3 { 1->block_60, 2->block_61, 3->block_62 } [%151]  // switch (2) {         case 1:             result...
 *     -> [block_60, block_61, block_62]
 *   block_62 SWITCH_CASE  <- [block_58]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %168 = CONST/INT32 1000  // 1000
 *     >> %169 = READ_MODIFY_WRITE(ADD new) [%result.1, %168]  // result += 1000
 *     >> %170 = BREAK  // break
 *     -> [block_59]
 *   block_60 SWITCH_CASE  <- [block_58]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %153 = CONST/INT32 1  // 1
 *     >> %154 = READ_MODIFY_WRITE(ADD new) [%result.1, %153]  // result += 1
 *     >> %155 = IMPLICIT_FALLTHROUGH
 *     -> [block_61]
 *   block_61 SWITCH_CASE  <- [block_58, block_60]:
 *          %156 = CONST/INT32 20  // 20
 *     >> %157 = SWITCH cases=2 { 10->block_64, 20->block_65 } [%156]  // switch (20) {                 case 10: result +...
 *     -> [block_64, block_65]
 *   block_65 SWITCH_CASE  <- [block_61]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %162 = CONST/INT32 200  // 200
 *     >> %163 = READ_MODIFY_WRITE(ADD new) [%result.1, %162]  // result += 200
 *     >> %164 = BREAK  // break
 *     -> [block_63]
 *   block_64 SWITCH_CASE  <- [block_61]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %158 = CONST/INT32 100  // 100
 *     >> %159 = READ_MODIFY_WRITE(ADD new) [%result.1, %158]  // result += 100
 *     >> %160 = BREAK  // break
 *     -> [block_63]
 *   block_63 SWITCH_EXIT  <- [block_64, block_65]:
 *     >> %166 = BREAK  // break
 *     -> [block_59]
 *   block_59 SWITCH_EXIT  <- [block_63, block_62]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=4
 *          %172 = MEMORY/LOAD_LE_32 [%result.1]  // result
 *          %173 = CONST/INT32 200  // 200
 *          %174 = CMP_NE [%172, %173]  // result != 200
 *     >> %175 = COND_BRANCH [%174]  // if (result != 200) return 6
 *     -> [block_70, block_71]
 *   block_71 IF_ELSE  <- [block_59]:
 *     >> %181 = IMPLICIT_GOTO
 *     -> [block_72]
 *   block_72 IF_MERGE  <- [block_71]:
 *          %183 = RETURN_PTR  // return 0
 *          %182 = CONST/INT32 0  // 0
 *     >> %184 = MEMORY/STORE_LE_32 [%183, %182]  // return 0
 *     >> %185 = EXIT_SCOPE  // {     // Basic switch.     int val = 2;     int...
 *     >> %186 = RET [%182]  // return 0
 *   block_70 IF_THEN  <- [block_59]:
 *          %177 = RETURN_PTR  // return 6
 *          %176 = CONST/INT32 6  // 6
 *     >> %178 = MEMORY/STORE_LE_32 [%177, %176]  // return 6
 *     >> %179 = EXIT_SCOPE  // {     // Basic switch.     int val = 2;     int...
 *     >> %180 = RET [%176]  // return 6
 *   block_56 IF_THEN  <- [block_42]:
 *          %144 = RETURN_PTR  // return 5
 *          %143 = CONST/INT32 5  // 5
 *     >> %145 = MEMORY/STORE_LE_32 [%144, %143]  // return 5
 *     >> %146 = EXIT_SCOPE  // {     // Basic switch.     int val = 2;     int...
 *     >> %147 = RET [%143]  // return 5
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

    // Nested switch: inner switch cases must not leak into outer switch.
    result = 0;
    switch (1) {
        case 1:
            switch (10) {
                case 10: result = 50; break;
                case 20: result = 60; break;
                default: result = 70; break;
            }
            break;
        case 2:
            result = 80;
            break;
        default:
            result = 90;
            break;
    }
    if (result != 50) return 5;

    // Nested switch with outer fallthrough.
    result = 0;
    switch (2) {
        case 1:
            result += 1;
        case 2:
            switch (20) {
                case 10: result += 100; break;
                case 20: result += 200; break;
            }
            break;
        case 3:
            result += 1000;
            break;
    }
    if (result != 200) return 6;

    return 0;
}
