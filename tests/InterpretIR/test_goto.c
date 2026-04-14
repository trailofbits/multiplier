// Tests: goto (GOTO), labels (LABEL), goto compensation blocks
// (COMPENSATION) for cross-scope jumps, forward gotos, backward gotos,
// and goto into nested scopes.

/*
 * Expected IR:
 *
 * function test_goto (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=4 align=4 (result)
 *     obj_1 LOCAL_VALUE size=4 align=4 (count)
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %result.0 = ALLOCA/LOCAL size=4 align=4
 *     >> %count.1 = ALLOCA/LOCAL size=4 align=4
 *     >> %2 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %3 = ENTER_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %4 = CONST/INT32 0  // 0
 *     >> %result.5 = MEMORY/STORE_LE_32 [%result.0, %4]
 *     >> %6 = GOTO  // goto forward
 *     -> [block_2]
 *   block_2 LABEL  <- [block_1]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %8 = MEMORY/LOAD_LE_32 [%result.0]  // result
 *          %9 = CONST/INT32 0  // 0
 *          %10 = CMP_NE [%8, %9]  // result != 0
 *     >> %11 = COND_BRANCH [%10]  // if (result != 0) return 1
 *     -> [block_4, block_5]
 *   block_5 IF_ELSE  <- [block_2]:
 *     >> %17 = IMPLICIT_GOTO
 *     -> [block_6]
 *   block_6 IF_MERGE  <- [block_5]:
 *          %count.1 = ALLOCA/LOCAL size=4 align=4
 *          %18 = CONST/INT32 0  // 0
 *     >> %count.19 = MEMORY/STORE_LE_32 [%count.1, %18]
 *     >> %20 = IMPLICIT_GOTO  // loop:     if (count >= 5) goto done
 *     -> [block_7]
 *   block_7 LABEL  <- [block_6, block_12]:
 *          %count.1 = ALLOCA/LOCAL size=4 align=4
 *          %21 = MEMORY/LOAD_LE_32 [%count.1]  // count
 *          %22 = CONST/INT32 5  // 5
 *          %23 = CMP_GE [%21, %22]  // count >= 5
 *     >> %24 = COND_BRANCH [%23]  // if (count >= 5) goto done
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %27 = IMPLICIT_GOTO
 *     -> [block_12]
 *   block_12 IF_MERGE  <- [block_9]:
 *          %count.1 = ALLOCA/LOCAL size=4 align=4
 *          %28 = CONST/INT32 1  // count++
 *     >> %29 = READ_MODIFY_WRITE(ADD old) [%count.1, %28]  // count++
 *     >> %30 = GOTO  // goto loop
 *     -> [block_7]
 *   block_8 IF_THEN  <- [block_7]:
 *     >> %25 = GOTO  // goto done
 *     -> [block_10]
 *   block_10 LABEL  <- [block_8]:
 *          %count.1 = ALLOCA/LOCAL size=4 align=4
 *          %32 = MEMORY/LOAD_LE_32 [%count.1]  // count
 *          %33 = CONST/INT32 5  // 5
 *          %34 = CMP_NE [%32, %33]  // count != 5
 *     >> %35 = COND_BRANCH [%34]  // if (count != 5) return 2
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_10]:
 *     >> %41 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %42 = CONST/INT32 0  // 0
 *     >> %43 = MEMORY/STORE_LE_32 [%result.0, %42]  // result = 0
 *     >> %44 = ENTER_SCOPE  // {         result = 10;         goto skip_inner;...
 *          %45 = CONST/INT32 10  // 10
 *     >> %46 = MEMORY/STORE_LE_32 [%result.0, %45]  // result = 10
 *     >> %47 = GOTO  // goto skip_inner
 *     -> [block_38]
 *   block_38 COMPENSATION  <- [block_16]:
 *     >> %119 = EXIT_SCOPE  // {         result = 10;         goto skip_inner;...
 *     >> %120 = IMPLICIT_GOTO
 *     -> [block_17]
 *   block_17 LABEL  <- [block_38]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %49 = MEMORY/LOAD_LE_32 [%result.0]  // result
 *          %50 = CONST/INT32 10  // 10
 *          %51 = CMP_NE [%49, %50]  // result != 10
 *     >> %52 = COND_BRANCH [%51]  // if (result != 10) return 3
 *     -> [block_19, block_20]
 *   block_20 IF_ELSE  <- [block_17]:
 *     >> %58 = IMPLICIT_GOTO
 *     -> [block_21]
 *   block_21 IF_MERGE  <- [block_20]:
 *     >> %59 = ENTER_SCOPE  // {         {             goto escape;         } ...
 *     >> %60 = ENTER_SCOPE  // {             goto escape;         }
 *     >> %61 = GOTO  // goto escape
 *     -> [block_39]
 *   block_39 COMPENSATION  <- [block_21]:
 *     >> %121 = EXIT_SCOPE  // {             goto escape;         }
 *     >> %122 = EXIT_SCOPE  // {         {             goto escape;         } ...
 *     >> %123 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 LABEL  <- [block_39]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %63 = CONST/INT32 99  // 99
 *     >> %64 = MEMORY/STORE_LE_32 [%result.0, %63]  // result = 99
 *          %65 = MEMORY/LOAD_LE_32 [%result.0]  // result
 *          %66 = CONST/INT32 99  // 99
 *          %67 = CMP_NE [%65, %66]  // result != 99
 *     >> %68 = COND_BRANCH [%67]  // if (result != 99) return 4
 *     -> [block_24, block_25]
 *   block_25 IF_ELSE  <- [block_22]:
 *     >> %74 = IMPLICIT_GOTO
 *     -> [block_26]
 *   block_26 IF_MERGE  <- [block_25]:
 *     >> %75 = ENTER_SCOPE  // {         result = 200;         goto after_dead...
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %76 = CONST/INT32 200  // 200
 *     >> %77 = MEMORY/STORE_LE_32 [%result.0, %76]  // result = 200
 *     >> %78 = GOTO  // goto after_dead
 *     -> [block_40]
 *   block_40 COMPENSATION  <- [block_26]:
 *     >> %124 = EXIT_SCOPE  // {         result = 200;         goto after_dead...
 *     >> %125 = IMPLICIT_GOTO
 *     -> [block_27]
 *   block_27 LABEL  <- [block_40]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %80 = MEMORY/LOAD_LE_32 [%result.0]  // result
 *          %81 = CONST/INT32 200  // 200
 *          %82 = CMP_NE [%80, %81]  // result != 200
 *     >> %83 = COND_BRANCH [%82]  // if (result != 200) return 5
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_27]:
 *     >> %89 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *     >> %90 = ENTER_SCOPE  // {         {             result = 300;          ...
 *     >> %91 = ENTER_SCOPE  // {             result = 300;             if (res...
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %92 = CONST/INT32 300  // 300
 *     >> %93 = MEMORY/STORE_LE_32 [%result.0, %92]  // result = 300
 *          %94 = MEMORY/LOAD_LE_32 [%result.0]  // result
 *          %95 = CONST/INT32 300  // 300
 *          %96 = CMP_EQ [%94, %95]  // result == 300
 *     >> %97 = COND_BRANCH [%96]  // if (result == 300) {                 // The ret...
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %101 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_32 IF_THEN  <- [block_31]:
 *     >> %98 = ENTER_SCOPE  // {                 // The return terminates; sco...
 *     >> %99 = EXIT_SCOPE  // {                 // The return terminates; sco...
 *     >> %100 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_32, block_33]:
 *     >> %102 = EXIT_SCOPE  // {             result = 300;             if (res...
 *     >> %103 = EXIT_SCOPE  // {         {             result = 300;          ...
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %104 = MEMORY/LOAD_LE_32 [%result.0]  // result
 *          %105 = CONST/INT32 300  // 300
 *          %106 = CMP_NE [%104, %105]  // result != 300
 *     >> %107 = COND_BRANCH [%106]  // if (result != 300) return 6
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %113 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %115 = RETURN_PTR  // return 0
 *          %114 = CONST/INT32 0  // 0
 *     >> %116 = MEMORY/STORE_LE_32 [%115, %114]  // return 0
 *     >> %117 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *     >> %118 = RET [%114]  // return 0
 *   block_35 IF_THEN  <- [block_34]:
 *          %109 = RETURN_PTR  // return 6
 *          %108 = CONST/INT32 6  // 6
 *     >> %110 = MEMORY/STORE_LE_32 [%109, %108]  // return 6
 *     >> %111 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *     >> %112 = RET [%108]  // return 6
 *   block_29 IF_THEN  <- [block_27]:
 *          %85 = RETURN_PTR  // return 5
 *          %84 = CONST/INT32 5  // 5
 *     >> %86 = MEMORY/STORE_LE_32 [%85, %84]  // return 5
 *     >> %87 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *     >> %88 = RET [%84]  // return 5
 *   block_24 IF_THEN  <- [block_22]:
 *          %70 = RETURN_PTR  // return 4
 *          %69 = CONST/INT32 4  // 4
 *     >> %71 = MEMORY/STORE_LE_32 [%70, %69]  // return 4
 *     >> %72 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *     >> %73 = RET [%69]  // return 4
 *   block_19 IF_THEN  <- [block_17]:
 *          %54 = RETURN_PTR  // return 3
 *          %53 = CONST/INT32 3  // 3
 *     >> %55 = MEMORY/STORE_LE_32 [%54, %53]  // return 3
 *     >> %56 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *     >> %57 = RET [%53]  // return 3
 *   block_14 IF_THEN  <- [block_10]:
 *          %37 = RETURN_PTR  // return 2
 *          %36 = CONST/INT32 2  // 2
 *     >> %38 = MEMORY/STORE_LE_32 [%37, %36]  // return 2
 *     >> %39 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *     >> %40 = RET [%36]  // return 2
 *   block_4 IF_THEN  <- [block_2]:
 *          %13 = RETURN_PTR  // return 1
 *          %12 = CONST/INT32 1  // 1
 *     >> %14 = MEMORY/STORE_LE_32 [%13, %12]  // return 1
 *     >> %15 = EXIT_SCOPE  // {     int result = 0;      // Forward goto.    ...
 *     >> %16 = RET [%12]  // return 1
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

    // Goto inside a scope with dead code after it.
    // The scope's EXIT_SCOPE must not appear after the goto terminator.
    {
        result = 200;
        goto after_dead;
        result = -1;  // dead code
    }
after_dead:
    if (result != 200) return 5;

    // Return inside a nested scope: all enclosing scopes must be exited
    // before the return, and no EXIT_SCOPE should trail the terminator.
    {
        {
            result = 300;
            if (result == 300) {
                // The return terminates; scope exits are emitted before it.
                // After return, remaining code in enclosing scopes is dead.
            }
        }
    }
    if (result != 300) return 6;

    return 0;
}
