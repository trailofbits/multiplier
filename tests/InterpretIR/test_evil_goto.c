// Tests: evil goto patterns, Duff's device, gotos crossing scope boundaries,
// gotos into/out of switch cases, interleaved loops and gotos.

/*
 * Expected IR:
 *
 * function duffs_copy (NORMAL) {
 *   objects:
 *     obj_0 PARAMETER_VALUE size=8 align=1 (dst)
 *     obj_1 PARAMETER_VALUE size=8 align=1 (src)
 *     obj_2 PARAMETER_VALUE size=4 align=1 (n)
 *     obj_3 LOCAL_VALUE size=4 align=1 (remaining)
 *     obj_4 LOCAL_VALUE size=4 align=1 (chunks)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %dst.0 = ALLOCA/LOCAL size=8 align=1
 *     >> %src.1 = ALLOCA/LOCAL size=8 align=1
 *     >> %n.2 = ALLOCA/LOCAL size=4 align=1
 *     >> %5 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %6 = ENTER_SCOPE  // {     int remaining = n;     if (remaining <= 0...
 *          %remaining.3 = ALLOCA/LOCAL size=4 align=1
 *          %10 = MEMORY/LOAD_LE_32 [%n.9]  // n
 *     >> %remaining.11 = MEMORY/STORE_LE_32 [%remaining.3, %10]
 *          %14 = CMP_LE [%12, %13]  // remaining <= 0
 *     >> %15 = COND_BRANCH [%14]  // if (remaining <= 0) return
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %18 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %chunks.4 = ALLOCA/LOCAL size=4 align=1
 *          %23 = DIV [%21, %22]  // (remaining + 7) / 8
 *     >> %chunks.24 = MEMORY/STORE_LE_32 [%chunks.4, %23]
 *          %27 = REM [%25, %26]  // remaining % 8
 *     >> %28 = SWITCH cases=1 [%27]  // switch (remaining % 8) {         case 0: do { *...
 *     -> [block_6]
 *   block_6 SWITCH_CASE  <- [block_4]:
 *     >> %29 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 LOOP_PREHEADER  <- [block_6]:
 *     >> %30 = IMPLICIT_GOTO
 *     -> [block_8]
 *   block_8 LOOP_BODY  <- [block_7, block_9]:
 *     >> %31 = ENTER_SCOPE  // { *dst++ = *src++;         case 7:      *dst++ ...
 *          %33 = READ_MODIFY_WRITE(PTR_ADD old) [%dst.7, %32]  // dst++
 *          %36 = MEMORY/LOAD_LE_8 [%35]  // *src++
 *     >> %37 = MEMORY/STORE_LE_8 [%33, %36]  // *dst++ = *src++
 *          %39 = READ_MODIFY_WRITE(PTR_ADD old) [%dst.7, %38]  // dst++
 *          %42 = MEMORY/LOAD_LE_8 [%41]  // *src++
 *     >> %43 = MEMORY/STORE_LE_8 [%39, %42]  // *dst++ = *src++
 *          %45 = READ_MODIFY_WRITE(PTR_ADD old) [%dst.7, %44]  // dst++
 *          %48 = MEMORY/LOAD_LE_8 [%47]  // *src++
 *     >> %49 = MEMORY/STORE_LE_8 [%45, %48]  // *dst++ = *src++
 *          %51 = READ_MODIFY_WRITE(PTR_ADD old) [%dst.7, %50]  // dst++
 *          %54 = MEMORY/LOAD_LE_8 [%53]  // *src++
 *     >> %55 = MEMORY/STORE_LE_8 [%51, %54]  // *dst++ = *src++
 *          %57 = READ_MODIFY_WRITE(PTR_ADD old) [%dst.7, %56]  // dst++
 *          %60 = MEMORY/LOAD_LE_8 [%59]  // *src++
 *     >> %61 = MEMORY/STORE_LE_8 [%57, %60]  // *dst++ = *src++
 *          %63 = READ_MODIFY_WRITE(PTR_ADD old) [%dst.7, %62]  // dst++
 *          %66 = MEMORY/LOAD_LE_8 [%65]  // *src++
 *     >> %67 = MEMORY/STORE_LE_8 [%63, %66]  // *dst++ = *src++
 *          %69 = READ_MODIFY_WRITE(PTR_ADD old) [%dst.7, %68]  // dst++
 *          %72 = MEMORY/LOAD_LE_8 [%71]  // *src++
 *     >> %73 = MEMORY/STORE_LE_8 [%69, %72]  // *dst++ = *src++
 *          %75 = READ_MODIFY_WRITE(PTR_ADD old) [%dst.7, %74]  // dst++
 *          %78 = MEMORY/LOAD_LE_8 [%77]  // *src++
 *     >> %79 = MEMORY/STORE_LE_8 [%75, %78]  // *dst++ = *src++
 *     >> %80 = EXIT_SCOPE  // { *dst++ = *src++;         case 7:      *dst++ ...
 *     >> %81 = IMPLICIT_GOTO
 *     -> [block_9]
 *   block_9 LOOP_CONDITION  <- [block_8]:
 *          %85 = CMP_GT [%83, %84]  // --chunks > 0
 *     >> %86 = COND_BRANCH [%85]  // do { *dst++ = *src++;         case 7:      *dst...
 *     -> [block_8, block_10]
 *   block_10 LOOP_EXIT  <- [block_9]:
 *     >> %87 = IMPLICIT_FALLTHROUGH
 *     -> [block_5]
 *   block_5 SWITCH_EXIT  <- [block_10]:
 *     >> %88 = EXIT_SCOPE  // {     int remaining = n;     if (remaining <= 0...
 *     >> %89 = RET
 *   block_2 IF_THEN  <- [block_1]:
 *     >> %16 = EXIT_SCOPE  // {     int remaining = n;     if (remaining <= 0...
 *     >> %17 = RET  // return
 * }
 * function goto_into_scope (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (result)
 *     obj_2 LOCAL_VALUE size=4 align=1 (x)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %2 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %3 = ENTER_SCOPE  // {     int result = 0;     goto inside;     {   ...
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %4 = CONST/INT32 0  // 0
 *     >> %result.5 = MEMORY/STORE_LE_32 [%result.0, %4]
 *     >> %6 = GOTO  // goto inside
 *     -> [block_4]
 *   block_4 COMPENSATION  <- [block_1]:
 *     >> %19 = ENTER_SCOPE  // {         int x = 99;  // skipped by goto insid...
 *     >> %20 = IMPLICIT_GOTO
 *     -> [block_2]
 *   block_2 LABEL  <- [block_3, block_4]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %11 = CONST/INT32 42  // 42
 *     >> %12 = MEMORY/STORE_LE_32 [%result.0, %11]  // result = 42
 *     >> %13 = EXIT_SCOPE  // {         int x = 99;  // skipped by goto insid...
 *          %15 = RETURN_PTR  // return result
 *          %14 = MEMORY/LOAD_LE_32 [%result.0]  // result
 *     >> %16 = MEMORY/STORE_LE_32 [%15, %14]  // return result
 *     >> %17 = EXIT_SCOPE  // {     int result = 0;     goto inside;     {   ...
 *          %14 = MEMORY/LOAD_LE_32 [%result.0]  // result
 *     >> %18 = RET [%14]  // return result
 * }
 * function goto_escape_nested (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (val)
 *     obj_2 LOCAL_VALUE size=4 align=1 (a)
 *     obj_3 LOCAL_VALUE size=4 align=1 (b)
 *     obj_4 LOCAL_VALUE size=4 align=1 (c)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %4 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %5 = ENTER_SCOPE  // {     int val = 0;     {         int a = 1;    ...
 *          %val.0 = ALLOCA/LOCAL size=4 align=1
 *          %6 = CONST/INT32 0  // 0
 *     >> %val.7 = MEMORY/STORE_LE_32 [%val.0, %6]
 *     >> %8 = ENTER_SCOPE  // {         int a = 1;         {             int ...
 *          %a.1 = ALLOCA/LOCAL size=4 align=1
 *          %9 = CONST/INT32 1  // 1
 *     >> %a.10 = MEMORY/STORE_LE_32 [%a.1, %9]
 *     >> %11 = ENTER_SCOPE  // {             int b = 2;             {         ...
 *          %b.2 = ALLOCA/LOCAL size=4 align=1
 *          %12 = CONST/INT32 2  // 2
 *     >> %b.13 = MEMORY/STORE_LE_32 [%b.2, %12]
 *     >> %14 = ENTER_SCOPE  // {                 int c = 3;                 va...
 *          %c.3 = ALLOCA/LOCAL size=4 align=1
 *          %15 = CONST/INT32 3  // 3
 *     >> %c.16 = MEMORY/STORE_LE_32 [%c.3, %15]
 *          %val.0 = ALLOCA/LOCAL size=4 align=1
 *          %21 = ADD [%19, %20]  // a + b + c
 *     >> %22 = MEMORY/STORE_LE_32 [%val.0, %21]  // val = a + b + c
 *     >> %23 = GOTO  // goto escape
 *     -> [block_4]
 *   block_4 COMPENSATION  <- [block_1]:
 *     >> %39 = EXIT_SCOPE  // {                 int c = 3;                 va...
 *     >> %40 = EXIT_SCOPE  // {             int b = 2;             {         ...
 *     >> %41 = EXIT_SCOPE  // {         int a = 1;         {             int ...
 *     >> %42 = IMPLICIT_GOTO
 *     -> [block_2]
 *   block_2 LABEL  <- [block_3, block_4]:
 *          %35 = RETURN_PTR  // return val
 *          %34 = MEMORY/LOAD_LE_32 [%val.0]  // val
 *     >> %36 = MEMORY/STORE_LE_32 [%35, %34]  // return val
 *     >> %37 = EXIT_SCOPE  // {     int val = 0;     {         int a = 1;    ...
 *          %34 = MEMORY/LOAD_LE_32 [%val.0]  // val
 *     >> %38 = RET [%34]  // return val
 * }
 * function goto_skip_decls (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (r)
 *     obj_2 LOCAL_VALUE size=4 align=1 (x)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %2 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %3 = ENTER_SCOPE  // {     int r = 0;     goto skip;     int x = 10;...
 *          %r.0 = ALLOCA/LOCAL size=4 align=1
 *          %4 = CONST/INT32 0  // 0
 *     >> %r.5 = MEMORY/STORE_LE_32 [%r.0, %4]
 *     >> %6 = GOTO  // goto skip
 *     -> [block_2]
 *   block_2 LABEL  <- [block_1, block_3]:
 *          %13 = RETURN_PTR  // return r
 *          %12 = MEMORY/LOAD_LE_32 [%r.0]  // r
 *     >> %14 = MEMORY/STORE_LE_32 [%13, %12]  // return r
 *     >> %15 = EXIT_SCOPE  // {     int r = 0;     goto skip;     int x = 10;...
 *          %12 = MEMORY/LOAD_LE_32 [%r.0]  // r
 *     >> %16 = RET [%12]  // return r
 * }
 * function goto_loop_with_scope (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (total)
 *     obj_2 LOCAL_VALUE size=4 align=1 (i)
 *     obj_3 LOCAL_VALUE size=4 align=1 (increment)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %3 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %4 = ENTER_SCOPE  // {     int total = 0;     int i = 0; loop_top:  ...
 *          %total.0 = ALLOCA/LOCAL size=4 align=1
 *          %5 = CONST/INT32 0  // 0
 *     >> %total.6 = MEMORY/STORE_LE_32 [%total.0, %5]
 *          %i.1 = ALLOCA/LOCAL size=4 align=1
 *          %7 = CONST/INT32 0  // 0
 *     >> %i.8 = MEMORY/STORE_LE_32 [%i.1, %7]
 *     >> %9 = IMPLICIT_GOTO  // loop_top:     if (i >= 5) goto loop_done
 *     -> [block_2]
 *   block_2 LABEL  <- [block_1, block_5]:
 *          %12 = CMP_GE [%10, %11]  // i >= 5
 *     >> %13 = COND_BRANCH [%12]  // if (i >= 5) goto loop_done
 *     -> [block_3, block_4]
 *   block_4 IF_ELSE  <- [block_2]:
 *     >> %16 = IMPLICIT_GOTO
 *     -> [block_5]
 *   block_5 IF_MERGE  <- [block_7, block_4]:
 *     >> %17 = ENTER_SCOPE  // {         int increment = i + 1;         total ...
 *          %increment.2 = ALLOCA/LOCAL size=4 align=1
 *          %20 = ADD [%18, %19]  // i + 1
 *     >> %increment.21 = MEMORY/STORE_LE_32 [%increment.2, %20]
 *          %total.0 = ALLOCA/LOCAL size=4 align=1
 *          %22 = MEMORY/LOAD_LE_32 [%increment.2]  // increment
 *     >> %23 = READ_MODIFY_WRITE(ADD new) [%total.0, %22]  // total += increment
 *          %i.1 = ALLOCA/LOCAL size=4 align=1
 *          %24 = CONST/INT64 1  // i++
 *     >> %25 = READ_MODIFY_WRITE(ADD old) [%i.1, %24]  // i++
 *     >> %26 = EXIT_SCOPE  // {         int increment = i + 1;         total ...
 *     >> %27 = GOTO  // goto loop_top
 *     -> [block_2]
 *   block_3 IF_THEN  <- [block_2]:
 *     >> %14 = GOTO  // goto loop_done
 *     -> [block_6]
 *   block_6 LABEL  <- [block_3, block_8]:
 *          %30 = RETURN_PTR  // return total
 *          %29 = MEMORY/LOAD_LE_32 [%total.0]  // total
 *     >> %31 = MEMORY/STORE_LE_32 [%30, %29]  // return total
 *     >> %32 = EXIT_SCOPE  // {     int total = 0;     int i = 0; loop_top:  ...
 *          %29 = MEMORY/LOAD_LE_32 [%total.0]  // total
 *     >> %33 = RET [%29]  // return total
 * }
 * function goto_between_cases (NORMAL) {
 *   objects:
 *     obj_0 PARAMETER_VALUE size=4 align=1 (selector)
 *     obj_1 RETURN_SLOT size=4 align=1
 *     obj_2 LOCAL_VALUE size=4 align=1 (result)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %selector.0 = ALLOCA/LOCAL size=4 align=1
 *     >> %2 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %3 = ENTER_SCOPE  // {     int result = 0;     switch (selector) {  ...
 *          %result.1 = ALLOCA/LOCAL size=4 align=1
 *          %5 = CONST/INT32 0  // 0
 *     >> %result.6 = MEMORY/STORE_LE_32 [%result.1, %5]
 *          %7 = MEMORY/LOAD_LE_32 [%selector.4]  // selector
 *     >> %8 = SWITCH cases=3 [%7]  // switch (selector) {         case 1:            ...
 *     -> [block_3, block_4, block_5]
 *   block_5 SWITCH_CASE  <- [block_1, block_8]:
 *     >> %17 = IMPLICIT_GOTO  // case3_body:             result += 100
 *     -> [block_6]
 *   block_4 SWITCH_CASE  <- [block_1, block_7]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=1
 *          %13 = CONST/INT32 20  // 20
 *     >> %14 = MEMORY/STORE_LE_32 [%result.1, %13]  // result = 20
 *     >> %15 = BREAK  // break
 *     -> [block_2]
 *   block_3 SWITCH_CASE  <- [block_1]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=1
 *          %9 = CONST/INT32 10  // 10
 *     >> %10 = MEMORY/STORE_LE_32 [%result.1, %9]  // result = 10
 *     >> %11 = GOTO  // goto case3_body
 *     -> [block_6]
 *   block_6 LABEL  <- [block_3, block_5]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=1
 *          %18 = CONST/INT32 100  // 100
 *     >> %19 = READ_MODIFY_WRITE(ADD new) [%result.1, %18]  // result += 100
 *     >> %20 = BREAK  // break
 *     -> [block_2]
 *   block_2 SWITCH_EXIT  <- [block_4, block_6, block_9]:
 *          %23 = RETURN_PTR  // return result
 *          %22 = MEMORY/LOAD_LE_32 [%result.1]  // result
 *     >> %24 = MEMORY/STORE_LE_32 [%23, %22]  // return result
 *     >> %25 = EXIT_SCOPE  // {     int result = 0;     switch (selector) {  ...
 *          %22 = MEMORY/LOAD_LE_32 [%result.1]  // result
 *     >> %26 = RET [%22]  // return result
 * }
 * function multi_source_goto (NORMAL) {
 *   objects:
 *     obj_0 PARAMETER_VALUE size=4 align=1 (path)
 *     obj_1 RETURN_SLOT size=4 align=1
 *     obj_2 LOCAL_VALUE size=4 align=1 (result)
 *     obj_3 LOCAL_VALUE size=4 align=1 (x)
 *     obj_4 LOCAL_VALUE size=4 align=1 (y)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %path.0 = ALLOCA/LOCAL size=4 align=1
 *     >> %4 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %5 = ENTER_SCOPE  // {     int result = 0;     if (path == 1) {     ...
 *          %result.1 = ALLOCA/LOCAL size=4 align=1
 *          %7 = CONST/INT32 0  // 0
 *     >> %result.8 = MEMORY/STORE_LE_32 [%result.1, %7]
 *          %11 = CMP_EQ [%9, %10]  // path == 1
 *     >> %12 = COND_BRANCH [%11]  // if (path == 1) {         int x = 10;         re...
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %21 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_6, block_3]:
 *          %24 = CMP_EQ [%22, %23]  // path == 2
 *     >> %25 = COND_BRANCH [%24]  // if (path == 2) {         int y = 20;         re...
 *     -> [block_7, block_8]
 *   block_8 IF_ELSE  <- [block_4]:
 *     >> %34 = IMPLICIT_GOTO
 *     -> [block_9]
 *   block_9 IF_MERGE  <- [block_10, block_8]:
 *          %result.1 = ALLOCA/LOCAL size=4 align=1
 *          %35 = CONST/INT32 30  // 30
 *     >> %36 = MEMORY/STORE_LE_32 [%result.1, %35]  // result = 30
 *     >> %37 = IMPLICIT_GOTO  // merge:     return result
 *     -> [block_5]
 *   block_7 IF_THEN  <- [block_4]:
 *     >> %26 = ENTER_SCOPE  // {         int y = 20;         result = y;      ...
 *          %y.3 = ALLOCA/LOCAL size=4 align=1
 *          %27 = CONST/INT32 20  // 20
 *     >> %y.28 = MEMORY/STORE_LE_32 [%y.3, %27]
 *          %result.1 = ALLOCA/LOCAL size=4 align=1
 *          %29 = MEMORY/LOAD_LE_32 [%y.3]  // y
 *     >> %30 = MEMORY/STORE_LE_32 [%result.1, %29]  // result = y
 *     >> %31 = GOTO  // goto merge
 *     -> [block_12]
 *   block_12 COMPENSATION  <- [block_7]:
 *     >> %45 = EXIT_SCOPE  // {         int y = 20;         result = y;      ...
 *     >> %46 = IMPLICIT_GOTO
 *     -> [block_5]
 *   block_2 IF_THEN  <- [block_1]:
 *     >> %13 = ENTER_SCOPE  // {         int x = 10;         result = x;      ...
 *          %x.2 = ALLOCA/LOCAL size=4 align=1
 *          %14 = CONST/INT32 10  // 10
 *     >> %x.15 = MEMORY/STORE_LE_32 [%x.2, %14]
 *          %result.1 = ALLOCA/LOCAL size=4 align=1
 *          %16 = MEMORY/LOAD_LE_32 [%x.2]  // x
 *     >> %17 = MEMORY/STORE_LE_32 [%result.1, %16]  // result = x
 *     >> %18 = GOTO  // goto merge
 *     -> [block_11]
 *   block_11 COMPENSATION  <- [block_2]:
 *     >> %43 = EXIT_SCOPE  // {         int x = 10;         result = x;      ...
 *     >> %44 = IMPLICIT_GOTO
 *     -> [block_5]
 *   block_5 LABEL  <- [block_9, block_11, block_12]:
 *          %39 = RETURN_PTR  // return result
 *          %38 = MEMORY/LOAD_LE_32 [%result.1]  // result
 *     >> %40 = MEMORY/STORE_LE_32 [%39, %38]  // return result
 *     >> %41 = EXIT_SCOPE  // {     int result = 0;     if (path == 1) {     ...
 *          %38 = MEMORY/LOAD_LE_32 [%result.1]  // result
 *     >> %42 = RET [%38]  // return result
 * }
 * function test_evil_goto (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=11 align=1 (src)
 *     obj_2 LOCAL_VALUE size=11 align=1 (dst)
 *     obj_3 LOCAL_VALUE size=4 align=1 (dst2)
 *     obj_4 STRING_LITERAL size=12 align=1
 *     obj_5 PARAMETER size=8 align=1
 *     obj_6 PARAMETER size=8 align=1
 *     obj_7 PARAMETER size=4 align=1
 *     obj_8 PARAMETER size=8 align=1
 *     obj_9 PARAMETER size=8 align=1
 *     obj_10 PARAMETER size=4 align=1
 *     obj_11 RETURN_SLOT size=4 align=1
 *     obj_12 RETURN_SLOT size=4 align=1
 *     obj_13 RETURN_SLOT size=4 align=1
 *     obj_14 RETURN_SLOT size=4 align=1
 *     obj_15 PARAMETER size=4 align=1
 *     obj_16 RETURN_SLOT size=4 align=1
 *     obj_17 PARAMETER size=4 align=1
 *     obj_18 RETURN_SLOT size=4 align=1
 *     obj_19 PARAMETER size=4 align=1
 *     obj_20 RETURN_SLOT size=4 align=1
 *     obj_21 PARAMETER size=4 align=1
 *     obj_22 RETURN_SLOT size=4 align=1
 *     obj_23 PARAMETER size=4 align=1
 *     obj_24 RETURN_SLOT size=4 align=1
 *     obj_25 PARAMETER size=4 align=1
 *     obj_26 RETURN_SLOT size=4 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %3 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %4 = ENTER_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %5 = ENTER_SCOPE  // {         char src[11] = "0123456789";         ...
 *          %src.0 = ALLOCA/LOCAL size=11 align=1
 *          %6 = ALLOCA/LOCAL size=12 align=1  // "0123456789"
 *          %7 = CONST/UINT64 11
 *     >> %src.8 = MEMORY/MEMCPY [%src.0, %6, %7]
 *          %dst.1 = ALLOCA/LOCAL size=11 align=1
 *          %dst.9 = CONST/UINT8 0
 *          %dst.10 = CONST/UINT64 11
 *     >> %dst.11 = MEMORY/MEMSET [%dst.1, %dst.9, %dst.10]
 *          %dst.1 = ALLOCA/LOCAL size=11 align=1
 *          %13 = CAST/TRUNC_I32_I8 [%12]  // 0
 *     >> %dst.14 = MEMORY/STORE_LE_8 [%dst.1, %13]
 *     >> %15 = ENTER_SCOPE  // duffs_copy(dst, src, 10)
 *          %16 = ALLOCA/ARG size=8 align=1  // dst
 *          %dst.1 = ALLOCA/LOCAL size=11 align=1
 *     >> %17 = MEMORY/STORE_LE_64 [%16, %dst.1]  // dst
 *          %18 = ALLOCA/ARG size=8 align=1  // src
 *          %src.0 = ALLOCA/LOCAL size=11 align=1
 *     >> %19 = MEMORY/STORE_LE_64 [%18, %src.0]  // src
 *          %21 = ALLOCA/ARG size=4 align=1  // 10
 *          %20 = CONST/INT32 10  // 10
 *     >> %22 = MEMORY/STORE_LE_32 [%21, %20]  // 10
 *          %16 = ALLOCA/ARG size=8 align=1  // dst
 *          %18 = ALLOCA/ARG size=8 align=1  // src
 *          %21 = ALLOCA/ARG size=4 align=1  // 10
 *     >> %23 = CALL @duffs_copy [%16, %18, %21]  // duffs_copy(dst, src, 10)
 *     >> %24 = EXIT_SCOPE
 *          %30 = CMP_NE [%28, %29]  // dst[0] != '0'
 *     >> %31 = COND_BRANCH [%30]  // if (dst[0] != '0') return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %38 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %44 = CMP_NE [%42, %43]  // dst[9] != '9'
 *     >> %45 = COND_BRANCH [%44]  // if (dst[9] != '9') return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %52 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %58 = CMP_NE [%56, %57]  // dst[10] != '\0'
 *     >> %59 = COND_BRANCH [%58]  // if (dst[10] != '\0') return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %66 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %dst2.2 = ALLOCA/LOCAL size=4 align=1
 *          %dst2.67 = CONST/UINT8 0
 *          %dst2.68 = CONST/UINT64 4
 *     >> %dst2.69 = MEMORY/MEMSET [%dst2.2, %dst2.67, %dst2.68]
 *          %dst2.2 = ALLOCA/LOCAL size=4 align=1
 *          %71 = CAST/TRUNC_I32_I8 [%70]  // 0
 *     >> %dst2.72 = MEMORY/STORE_LE_8 [%dst2.2, %71]
 *     >> %73 = ENTER_SCOPE  // duffs_copy(dst2, src, 3)
 *          %74 = ALLOCA/ARG size=8 align=1  // dst2
 *          %dst2.2 = ALLOCA/LOCAL size=4 align=1
 *     >> %75 = MEMORY/STORE_LE_64 [%74, %dst2.2]  // dst2
 *          %76 = ALLOCA/ARG size=8 align=1  // src
 *          %src.0 = ALLOCA/LOCAL size=11 align=1
 *     >> %77 = MEMORY/STORE_LE_64 [%76, %src.0]  // src
 *          %79 = ALLOCA/ARG size=4 align=1  // 3
 *          %78 = CONST/INT32 3  // 3
 *     >> %80 = MEMORY/STORE_LE_32 [%79, %78]  // 3
 *          %74 = ALLOCA/ARG size=8 align=1  // dst2
 *          %76 = ALLOCA/ARG size=8 align=1  // src
 *          %79 = ALLOCA/ARG size=4 align=1  // 3
 *     >> %81 = CALL @duffs_copy [%74, %76, %79]  // duffs_copy(dst2, src, 3)
 *     >> %82 = EXIT_SCOPE
 *          %88 = CMP_NE [%86, %87]  // dst2[0] != '0'
 *     >> %89 = COND_BRANCH [%88]  // if (dst2[0] != '0') return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %96 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %102 = CMP_NE [%100, %101]  // dst2[2] != '2'
 *     >> %103 = COND_BRANCH [%102]  // if (dst2[2] != '2') return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %110 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *     >> %111 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %112 = ENTER_SCOPE  // goto_into_scope()
 *     >> %117 = EXIT_SCOPE
 *          %116 = CMP_NE [%114, %115]  // goto_into_scope() != 42
 *     >> %118 = COND_BRANCH [%116]  // if (goto_into_scope() != 42) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %124 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *     >> %125 = ENTER_SCOPE  // goto_escape_nested()
 *     >> %130 = EXIT_SCOPE
 *          %129 = CMP_NE [%127, %128]  // goto_escape_nested() != 6
 *     >> %131 = COND_BRANCH [%129]  // if (goto_escape_nested() != 6) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %137 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *     >> %138 = ENTER_SCOPE  // goto_skip_decls()
 *     >> %143 = EXIT_SCOPE
 *          %142 = CMP_NE [%140, %141]  // goto_skip_decls() != 0
 *     >> %144 = COND_BRANCH [%142]  // if (goto_skip_decls() != 0) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %150 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *     >> %151 = ENTER_SCOPE  // goto_loop_with_scope()
 *     >> %156 = EXIT_SCOPE
 *          %155 = CMP_NE [%153, %154]  // goto_loop_with_scope() != 15
 *     >> %157 = COND_BRANCH [%155]  // if (goto_loop_with_scope() != 15) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %163 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *     >> %164 = ENTER_SCOPE  // goto_between_cases(1)
 *          %166 = ALLOCA/ARG size=4 align=1  // 1
 *          %165 = CONST/INT32 1  // 1
 *     >> %167 = MEMORY/STORE_LE_32 [%166, %165]  // 1
 *     >> %172 = EXIT_SCOPE
 *          %171 = CMP_NE [%169, %170]  // goto_between_cases(1) != 110
 *     >> %173 = COND_BRANCH [%171]  // if (goto_between_cases(1) != 110) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %179 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *     >> %180 = ENTER_SCOPE  // goto_between_cases(2)
 *          %182 = ALLOCA/ARG size=4 align=1  // 2
 *          %181 = CONST/INT32 2  // 2
 *     >> %183 = MEMORY/STORE_LE_32 [%182, %181]  // 2
 *     >> %188 = EXIT_SCOPE
 *          %187 = CMP_NE [%185, %186]  // goto_between_cases(2) != 20
 *     >> %189 = COND_BRANCH [%187]  // if (goto_between_cases(2) != 20) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %195 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *     >> %196 = ENTER_SCOPE  // goto_between_cases(3)
 *          %198 = ALLOCA/ARG size=4 align=1  // 3
 *          %197 = CONST/INT32 3  // 3
 *     >> %199 = MEMORY/STORE_LE_32 [%198, %197]  // 3
 *     >> %204 = EXIT_SCOPE
 *          %203 = CMP_NE [%201, %202]  // goto_between_cases(3) != 100
 *     >> %205 = COND_BRANCH [%203]  // if (goto_between_cases(3) != 100) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %211 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *     >> %212 = ENTER_SCOPE  // multi_source_goto(1)
 *          %214 = ALLOCA/ARG size=4 align=1  // 1
 *          %213 = CONST/INT32 1  // 1
 *     >> %215 = MEMORY/STORE_LE_32 [%214, %213]  // 1
 *     >> %220 = EXIT_SCOPE
 *          %219 = CMP_NE [%217, %218]  // multi_source_goto(1) != 10
 *     >> %221 = COND_BRANCH [%219]  // if (multi_source_goto(1) != 10) return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %227 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *     >> %228 = ENTER_SCOPE  // multi_source_goto(2)
 *          %230 = ALLOCA/ARG size=4 align=1  // 2
 *          %229 = CONST/INT32 2  // 2
 *     >> %231 = MEMORY/STORE_LE_32 [%230, %229]  // 2
 *     >> %236 = EXIT_SCOPE
 *          %235 = CMP_NE [%233, %234]  // multi_source_goto(2) != 20
 *     >> %237 = COND_BRANCH [%235]  // if (multi_source_goto(2) != 20) return 14
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %243 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *     >> %244 = ENTER_SCOPE  // multi_source_goto(0)
 *          %246 = ALLOCA/ARG size=4 align=1  // 0
 *          %245 = CONST/INT32 0  // 0
 *     >> %247 = MEMORY/STORE_LE_32 [%246, %245]  // 0
 *     >> %252 = EXIT_SCOPE
 *          %251 = CMP_NE [%249, %250]  // multi_source_goto(0) != 30
 *     >> %253 = COND_BRANCH [%251]  // if (multi_source_goto(0) != 30) return 15
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %259 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %261 = RETURN_PTR  // return 0
 *          %260 = CONST/INT32 0  // 0
 *     >> %262 = MEMORY/STORE_LE_32 [%261, %260]  // return 0
 *     >> %263 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %260 = CONST/INT32 0  // 0
 *     >> %264 = RET [%260]  // return 0
 *   block_44 IF_THEN  <- [block_43]:
 *          %255 = RETURN_PTR  // return 15
 *          %254 = CONST/INT32 15  // 15
 *     >> %256 = MEMORY/STORE_LE_32 [%255, %254]  // return 15
 *     >> %257 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %254 = CONST/INT32 15  // 15
 *     >> %258 = RET [%254]  // return 15
 *   block_41 IF_THEN  <- [block_40]:
 *          %239 = RETURN_PTR  // return 14
 *          %238 = CONST/INT32 14  // 14
 *     >> %240 = MEMORY/STORE_LE_32 [%239, %238]  // return 14
 *     >> %241 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %238 = CONST/INT32 14  // 14
 *     >> %242 = RET [%238]  // return 14
 *   block_38 IF_THEN  <- [block_37]:
 *          %223 = RETURN_PTR  // return 13
 *          %222 = CONST/INT32 13  // 13
 *     >> %224 = MEMORY/STORE_LE_32 [%223, %222]  // return 13
 *     >> %225 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %222 = CONST/INT32 13  // 13
 *     >> %226 = RET [%222]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %207 = RETURN_PTR  // return 12
 *          %206 = CONST/INT32 12  // 12
 *     >> %208 = MEMORY/STORE_LE_32 [%207, %206]  // return 12
 *     >> %209 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %206 = CONST/INT32 12  // 12
 *     >> %210 = RET [%206]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %191 = RETURN_PTR  // return 11
 *          %190 = CONST/INT32 11  // 11
 *     >> %192 = MEMORY/STORE_LE_32 [%191, %190]  // return 11
 *     >> %193 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %190 = CONST/INT32 11  // 11
 *     >> %194 = RET [%190]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %175 = RETURN_PTR  // return 10
 *          %174 = CONST/INT32 10  // 10
 *     >> %176 = MEMORY/STORE_LE_32 [%175, %174]  // return 10
 *     >> %177 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %174 = CONST/INT32 10  // 10
 *     >> %178 = RET [%174]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %159 = RETURN_PTR  // return 9
 *          %158 = CONST/INT32 9  // 9
 *     >> %160 = MEMORY/STORE_LE_32 [%159, %158]  // return 9
 *     >> %161 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %158 = CONST/INT32 9  // 9
 *     >> %162 = RET [%158]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %146 = RETURN_PTR  // return 8
 *          %145 = CONST/INT32 8  // 8
 *     >> %147 = MEMORY/STORE_LE_32 [%146, %145]  // return 8
 *     >> %148 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %145 = CONST/INT32 8  // 8
 *     >> %149 = RET [%145]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %133 = RETURN_PTR  // return 7
 *          %132 = CONST/INT32 7  // 7
 *     >> %134 = MEMORY/STORE_LE_32 [%133, %132]  // return 7
 *     >> %135 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %132 = CONST/INT32 7  // 7
 *     >> %136 = RET [%132]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %120 = RETURN_PTR  // return 6
 *          %119 = CONST/INT32 6  // 6
 *     >> %121 = MEMORY/STORE_LE_32 [%120, %119]  // return 6
 *     >> %122 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %119 = CONST/INT32 6  // 6
 *     >> %123 = RET [%119]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %105 = RETURN_PTR  // return 5
 *          %104 = CONST/INT32 5  // 5
 *     >> %106 = MEMORY/STORE_LE_32 [%105, %104]  // return 5
 *     >> %107 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %108 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %104 = CONST/INT32 5  // 5
 *     >> %109 = RET [%104]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %91 = RETURN_PTR  // return 4
 *          %90 = CONST/INT32 4  // 4
 *     >> %92 = MEMORY/STORE_LE_32 [%91, %90]  // return 4
 *     >> %93 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %94 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %90 = CONST/INT32 4  // 4
 *     >> %95 = RET [%90]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %61 = RETURN_PTR  // return 3
 *          %60 = CONST/INT32 3  // 3
 *     >> %62 = MEMORY/STORE_LE_32 [%61, %60]  // return 3
 *     >> %63 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %64 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %60 = CONST/INT32 3  // 3
 *     >> %65 = RET [%60]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %47 = RETURN_PTR  // return 2
 *          %46 = CONST/INT32 2  // 2
 *     >> %48 = MEMORY/STORE_LE_32 [%47, %46]  // return 2
 *     >> %49 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %50 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %46 = CONST/INT32 2  // 2
 *     >> %51 = RET [%46]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %33 = RETURN_PTR  // return 1
 *          %32 = CONST/INT32 1  // 1
 *     >> %34 = MEMORY/STORE_LE_32 [%33, %32]  // return 1
 *     >> %35 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %36 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *          %32 = CONST/INT32 1  // 1
 *     >> %37 = RET [%32]  // return 1
 * }
 */



// Classic Duff's device: copy n bytes from src to dst.
static void duffs_copy(char *dst, const char *src, int n) {
    int remaining = n;
    if (remaining <= 0) return;
    int chunks = (remaining + 7) / 8;
    switch (remaining % 8) {
        case 0: do { *dst++ = *src++;
        case 7:      *dst++ = *src++;
        case 6:      *dst++ = *src++;
        case 5:      *dst++ = *src++;
        case 4:      *dst++ = *src++;
        case 3:      *dst++ = *src++;
        case 2:      *dst++ = *src++;
        case 1:      *dst++ = *src++;
                } while (--chunks > 0);
    }
}

// Goto into a nested scope — variable declared in scope, goto skips init.
static int goto_into_scope(void) {
    int result = 0;
    goto inside;
    {
        int x = 99;  // skipped by goto
inside:
        // x is uninitialized here (skipped), but result is valid.
        result = 42;
    }
    return result;
}

// Goto out of deeply nested scopes.
static int goto_escape_nested(void) {
    int val = 0;
    {
        int a = 1;
        {
            int b = 2;
            {
                int c = 3;
                val = a + b + c;  // 6
                goto escape;
                val = 999;  // unreachable
            }
            val = 888;  // unreachable
        }
        val = 777;  // unreachable
    }
escape:
    return val;
}

// Forward goto skipping variable declarations.
static int goto_skip_decls(void) {
    int r = 0;
    goto skip;
    int x = 10;  // skipped
    r = x;       // skipped
skip:
    // x exists but was never initialized. r should still be 0.
    return r;
}

// Goto used as a loop with scope entry/exit each iteration.
static int goto_loop_with_scope(void) {
    int total = 0;
    int i = 0;
loop_top:
    if (i >= 5) goto loop_done;
    {
        int increment = i + 1;
        total += increment;
        i++;
    }
    goto loop_top;
loop_done:
    // total = 1 + 2 + 3 + 4 + 5 = 15
    return total;
}

// Goto between switch cases (not fallthrough — explicit goto).
static int goto_between_cases(int selector) {
    int result = 0;
    switch (selector) {
        case 1:
            result = 10;
            goto case3_body;
        case 2:
            result = 20;
            break;
        case 3:
case3_body:
            result += 100;
            break;
    }
    return result;
}

// Multiple gotos to the same label from different scopes.
static int multi_source_goto(int path) {
    int result = 0;
    if (path == 1) {
        int x = 10;
        result = x;
        goto merge;
    }
    if (path == 2) {
        int y = 20;
        result = y;
        goto merge;
    }
    result = 30;
merge:
    return result;
}

int test_evil_goto(void) {
    // Duff's device.
    {
        char src[11] = "0123456789";
        char dst[11] = {0};
        duffs_copy(dst, src, 10);
        if (dst[0] != '0') return 1;
        if (dst[9] != '9') return 2;
        if (dst[10] != '\0') return 3;

        // Duff with non-multiple-of-8 count.
        char dst2[4] = {0};
        duffs_copy(dst2, src, 3);
        if (dst2[0] != '0') return 4;
        if (dst2[2] != '2') return 5;
    }

    // Goto into scope.
    if (goto_into_scope() != 42) return 6;

    // Goto escaping nested scopes.
    if (goto_escape_nested() != 6) return 7;

    // Goto skipping declarations.
    if (goto_skip_decls() != 0) return 8;

    // Goto loop with scope entry/exit.
    if (goto_loop_with_scope() != 15) return 9;

    // Goto between switch cases: case 1 → goto case3_body → result = 10 + 100 = 110.
    if (goto_between_cases(1) != 110) return 10;
    // Case 2 → result = 20.
    if (goto_between_cases(2) != 20) return 11;
    // Case 3 → result = 0 + 100 = 100.
    if (goto_between_cases(3) != 100) return 12;

    // Multi-source goto.
    if (multi_source_goto(1) != 10) return 13;
    if (multi_source_goto(2) != 20) return 14;
    if (multi_source_goto(0) != 30) return 15;

    return 0;
}
