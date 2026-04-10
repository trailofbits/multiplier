// Tests: goto (GOTO), labels (LABEL), goto compensation blocks
// (COMPENSATION) for cross-scope jumps, forward gotos, backward gotos,
// and goto into nested scopes.

/*
 * Expected IR:
 *
 * function test_goto (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=4 align=1 (result)
 *     obj_1 LOCAL_VALUE size=4 align=1 (count)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %2 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %3 = ENTER_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %4 = CONST/INT32 0  // 0
 *     >> %result.5 = MEMORY/STORE_LE_32 [%result.0, %4]
 *     >> %6 = GOTO  // goto forward
 *     -> [block_2]
 *   block_2 LABEL  <- [block_1, block_3]:
 *          %13 = CMP_NE [%11, %12]  // result != 0
 *     >> %14 = COND_BRANCH [%13]  // if (result != 0) return 1
 *     -> [block_4, block_5]
 *   block_5 IF_ELSE  <- [block_2]:
 *     >> %20 = IMPLICIT_GOTO
 *     -> [block_6]
 *   block_6 IF_MERGE  <- [block_5]:
 *          %count.1 = ALLOCA/LOCAL size=4 align=1
 *          %21 = CONST/INT32 0  // 0
 *     >> %count.22 = MEMORY/STORE_LE_32 [%count.1, %21]
 *     >> %23 = IMPLICIT_GOTO  // loop:     if (count >= 5) goto done
 *     -> [block_7]
 *   block_7 LABEL  <- [block_6, block_10]:
 *          %26 = CMP_GE [%24, %25]  // count >= 5
 *     >> %27 = COND_BRANCH [%26]  // if (count >= 5) goto done
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %30 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_12, block_9]:
 *          %count.1 = ALLOCA/LOCAL size=4 align=1
 *          %31 = CONST/INT64 1  // count++
 *     >> %32 = READ_MODIFY_WRITE(ADD old) [%count.1, %31]  // count++
 *     >> %33 = GOTO  // goto loop
 *     -> [block_7]
 *   block_8 IF_THEN  <- [block_7]:
 *     >> %28 = GOTO  // goto done
 *     -> [block_11]
 *   block_11 LABEL  <- [block_8, block_13]:
 *          %37 = CMP_NE [%35, %36]  // count != 5
 *     >> %38 = COND_BRANCH [%37]  // if (count != 5) return 2
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_11]:
 *     >> %44 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %45 = CONST/INT32 0  // 0
 *     >> %46 = MEMORY/STORE_LE_32 [%result.0, %45]  // result = 0
 *     >> %47 = ENTER_SCOPE  // {         result = 10;         goto skip_inner;...
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %48 = CONST/INT32 10  // 10
 *     >> %49 = MEMORY/STORE_LE_32 [%result.0, %48]  // result = 10
 *     >> %50 = GOTO  // goto skip_inner
 *     -> [block_27]
 *   block_27 COMPENSATION  <- [block_16]:
 *     >> %89 = EXIT_SCOPE  // {         result = 10;         goto skip_inner;...
 *     >> %90 = IMPLICIT_GOTO
 *     -> [block_17]
 *   block_17 LABEL  <- [block_18, block_27]:
 *          %58 = CMP_NE [%56, %57]  // result != 10
 *     >> %59 = COND_BRANCH [%58]  // if (result != 10) return 3
 *     -> [block_19, block_20]
 *   block_20 IF_ELSE  <- [block_17]:
 *     >> %65 = IMPLICIT_GOTO
 *     -> [block_21]
 *   block_21 IF_MERGE  <- [block_20]:
 *     >> %66 = ENTER_SCOPE  // {         {             goto escape;         } ...
 *     >> %67 = ENTER_SCOPE  // {             goto escape;         }
 *     >> %68 = GOTO  // goto escape
 *     -> [block_28]
 *   block_28 COMPENSATION  <- [block_21]:
 *     >> %91 = EXIT_SCOPE  // {             goto escape;         }
 *     >> %92 = EXIT_SCOPE  // {         {             goto escape;         } ...
 *     >> %93 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 LABEL  <- [block_23, block_28]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %72 = CONST/INT32 99  // 99
 *     >> %73 = MEMORY/STORE_LE_32 [%result.0, %72]  // result = 99
 *          %76 = CMP_NE [%74, %75]  // result != 99
 *     >> %77 = COND_BRANCH [%76]  // if (result != 99) return 4
 *     -> [block_24, block_25]
 *   block_25 IF_ELSE  <- [block_22]:
 *     >> %83 = IMPLICIT_GOTO
 *     -> [block_26]
 *   block_26 IF_MERGE  <- [block_25]:
 *          %85 = RETURN_PTR  // return 0
 *          %84 = CONST/INT32 0  // 0
 *     >> %86 = MEMORY/STORE_LE_32 [%85, %84]  // return 0
 *     >> %87 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *          %84 = CONST/INT32 0  // 0
 *     >> %88 = RET [%84]  // return 0
 *   block_24 IF_THEN  <- [block_22]:
 *          %79 = RETURN_PTR  // return 4
 *          %78 = CONST/INT32 4  // 4
 *     >> %80 = MEMORY/STORE_LE_32 [%79, %78]  // return 4
 *     >> %81 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *          %78 = CONST/INT32 4  // 4
 *     >> %82 = RET [%78]  // return 4
 *   block_19 IF_THEN  <- [block_17]:
 *          %61 = RETURN_PTR  // return 3
 *          %60 = CONST/INT32 3  // 3
 *     >> %62 = MEMORY/STORE_LE_32 [%61, %60]  // return 3
 *     >> %63 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *          %60 = CONST/INT32 3  // 3
 *     >> %64 = RET [%60]  // return 3
 *   block_14 IF_THEN  <- [block_11]:
 *          %40 = RETURN_PTR  // return 2
 *          %39 = CONST/INT32 2  // 2
 *     >> %41 = MEMORY/STORE_LE_32 [%40, %39]  // return 2
 *     >> %42 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *          %39 = CONST/INT32 2  // 2
 *     >> %43 = RET [%39]  // return 2
 *   block_4 IF_THEN  <- [block_2]:
 *          %16 = RETURN_PTR  // return 1
 *          %15 = CONST/INT32 1  // 1
 *     >> %17 = MEMORY/STORE_LE_32 [%16, %15]  // return 1
 *     >> %18 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *          %15 = CONST/INT32 1  // 1
 *     >> %19 = RET [%15]  // return 1
 * }
 */










int test_goto(void) {
    int result = 0;

    // Forward goto.
    goto forward;
    result = -1;  // should be skipped
forward:
    if (result != 0) return 1;

    // Backward goto (simple loop).
    int count = 0;
loop:
    if (count >= 5) goto done;
    count++;
    goto loop;
done:
    if (count != 5) return 2;

    // Goto across scope boundaries (compensation block needed).
    result = 0;
    {
        result = 10;
        goto skip_inner;
        result = -1;
    }
skip_inner:
    if (result != 10) return 3;

    // Goto out of nested scopes.
    {
        {
            goto escape;
        }
    }
escape:
    result = 99;
    if (result != 99) return 4;

    return 0;
}
