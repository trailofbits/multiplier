// Tests: variadic function handling (VA_START, VA_END, VA_COPY,
// CONSUME_VA_PARAM via MEMORY sub-opcode), va_arg with different types.

/*
 * Expected IR:
 *
 * function va_sum (NORMAL) {
 *   objects:
 *     obj_0 PARAMETER_VALUE size=4 align=1 (count)
 *     obj_1 RETURN_SLOT size=4 align=1
 *     obj_2 LOCAL_VALUE size=8 align=1 (ap)
 *     obj_3 LOCAL_VALUE size=4 align=1 (total)
 *     obj_4 LOCAL_VALUE size=4 align=1 (i)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %count.0 = ALLOCA/LOCAL size=4 align=1
 *     >> %4 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %5 = ENTER_SCOPE  // {     va_list ap;     __builtin_va_start(ap,cou...
 *          %7 = MEMORY/LOAD_LE_64 [%ap.1]  // ap
 *     >> %8 = VA_START [%7]  // __builtin_va_start(ap,count)
 *          %total.2 = ALLOCA/LOCAL size=4 align=1
 *          %9 = CONST/INT32 0  // 0
 *     >> %total.10 = MEMORY/STORE_LE_32 [%total.2, %9]
 *     >> %11 = ENTER_SCOPE  // for (int i = 0; i < count; i++) {         total...
 *     >> %12 = IMPLICIT_GOTO
 *     -> [block_2]
 *   block_2 LOOP_PREHEADER  <- [block_1]:
 *          %i.3 = ALLOCA/LOCAL size=4 align=1
 *          %13 = CONST/INT32 0  // 0
 *     >> %i.14 = MEMORY/STORE_LE_32 [%i.3, %13]
 *     >> %15 = IMPLICIT_GOTO
 *     -> [block_3]
 *   block_3 LOOP_CONDITION  <- [block_2, block_5]:
 *          %18 = CMP_LT [%16, %17]  // i < count
 *     >> %19 = COND_BRANCH [%18]  // for (int i = 0; i < count; i++) {         total...
 *     -> [block_4, block_6]
 *   block_6 LOOP_EXIT  <- [block_3]:
 *     >> %29 = EXIT_SCOPE  // for (int i = 0; i < count; i++) {         total...
 *          %30 = MEMORY/LOAD_LE_64 [%ap.1]  // ap
 *     >> %31 = VA_END [%30]  // __builtin_va_end(ap)
 *          %33 = RETURN_PTR  // return total
 *          %32 = MEMORY/LOAD_LE_32 [%total.2]  // total
 *     >> %34 = MEMORY/STORE_LE_32 [%33, %32]  // return total
 *     >> %35 = EXIT_SCOPE  // {     va_list ap;     __builtin_va_start(ap,cou...
 *          %32 = MEMORY/LOAD_LE_32 [%total.2]  // total
 *     >> %36 = RET [%32]  // return total
 *   block_4 LOOP_BODY  <- [block_3]:
 *     >> %20 = ENTER_SCOPE  // {         total += __builtin_va_arg(ap,int);     }
 *          %total.2 = ALLOCA/LOCAL size=4 align=1
 *          %22 = MEMORY/CONSUME_VA_PARAM [%21]  // __builtin_va_arg(ap,int)
 *     >> %23 = READ_MODIFY_WRITE(ADD new) [%total.2, %22]  // total += __builtin_va_arg(ap,int)
 *     >> %24 = EXIT_SCOPE  // {         total += __builtin_va_arg(ap,int);     }
 *     >> %25 = IMPLICIT_GOTO
 *     -> [block_5]
 *   block_5 LOOP_INCREMENT  <- [block_4]:
 *          %i.3 = ALLOCA/LOCAL size=4 align=1
 *          %26 = CONST/INT64 1  // i++
 *     >> %27 = READ_MODIFY_WRITE(ADD old) [%i.3, %26]  // i++
 *     >> %28 = IMPLICIT_GOTO
 *     -> [block_3]
 * }
 * function va_first_int (NORMAL) {
 *   objects:
 *     obj_0 PARAMETER_VALUE size=4 align=1 (dummy)
 *     obj_1 RETURN_SLOT size=4 align=1
 *     obj_2 LOCAL_VALUE size=8 align=1 (ap)
 *     obj_3 LOCAL_VALUE size=4 align=1 (result)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %dummy.0 = ALLOCA/LOCAL size=4 align=1
 *     >> %3 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %4 = ENTER_SCOPE  // {     va_list ap;     __builtin_va_start(ap,dum...
 *          %6 = MEMORY/LOAD_LE_64 [%ap.1]  // ap
 *     >> %7 = VA_START [%6]  // __builtin_va_start(ap,dummy)
 *          %result.2 = ALLOCA/LOCAL size=4 align=1
 *          %9 = MEMORY/CONSUME_VA_PARAM [%8]  // __builtin_va_arg(ap,int)
 *     >> %result.10 = MEMORY/STORE_LE_32 [%result.2, %9]
 *          %11 = MEMORY/LOAD_LE_64 [%ap.1]  // ap
 *     >> %12 = VA_END [%11]  // __builtin_va_end(ap)
 *          %14 = RETURN_PTR  // return result
 *          %13 = MEMORY/LOAD_LE_32 [%result.2]  // result
 *     >> %15 = MEMORY/STORE_LE_32 [%14, %13]  // return result
 *     >> %16 = EXIT_SCOPE  // {     va_list ap;     __builtin_va_start(ap,dum...
 *          %13 = MEMORY/LOAD_LE_32 [%result.2]  // result
 *     >> %17 = RET [%13]  // return result
 * }
 * function va_sum_doubles (NORMAL) {
 *   objects:
 *     obj_0 PARAMETER_VALUE size=4 align=1 (count)
 *     obj_1 RETURN_SLOT size=8 align=1
 *     obj_2 LOCAL_VALUE size=8 align=1 (ap)
 *     obj_3 LOCAL_VALUE size=8 align=1 (total)
 *     obj_4 LOCAL_VALUE size=4 align=1 (i)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %count.0 = ALLOCA/LOCAL size=4 align=1
 *     >> %4 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %5 = ENTER_SCOPE  // {     va_list ap;     __builtin_va_start(ap,cou...
 *          %7 = MEMORY/LOAD_LE_64 [%ap.1]  // ap
 *     >> %8 = VA_START [%7]  // __builtin_va_start(ap,count)
 *          %total.2 = ALLOCA/LOCAL size=8 align=1
 *          %9 = CONST/FLOAT64 0  // 0.0
 *     >> %total.10 = MEMORY/STORE_LE_64 [%total.2, %9]
 *     >> %11 = ENTER_SCOPE  // for (int i = 0; i < count; i++) {         total...
 *     >> %12 = IMPLICIT_GOTO
 *     -> [block_2]
 *   block_2 LOOP_PREHEADER  <- [block_1]:
 *          %i.3 = ALLOCA/LOCAL size=4 align=1
 *          %13 = CONST/INT32 0  // 0
 *     >> %i.14 = MEMORY/STORE_LE_32 [%i.3, %13]
 *     >> %15 = IMPLICIT_GOTO
 *     -> [block_3]
 *   block_3 LOOP_CONDITION  <- [block_2, block_5]:
 *          %18 = CMP_LT [%16, %17]  // i < count
 *     >> %19 = COND_BRANCH [%18]  // for (int i = 0; i < count; i++) {         total...
 *     -> [block_4, block_6]
 *   block_6 LOOP_EXIT  <- [block_3]:
 *     >> %29 = EXIT_SCOPE  // for (int i = 0; i < count; i++) {         total...
 *          %30 = MEMORY/LOAD_LE_64 [%ap.1]  // ap
 *     >> %31 = VA_END [%30]  // __builtin_va_end(ap)
 *          %33 = RETURN_PTR  // return total
 *          %32 = MEMORY/LOAD_F64_LE [%total.2]  // total
 *     >> %34 = MEMORY/STORE_LE_64 [%33, %32]  // return total
 *     >> %35 = EXIT_SCOPE  // {     va_list ap;     __builtin_va_start(ap,cou...
 *          %32 = MEMORY/LOAD_F64_LE [%total.2]  // total
 *     >> %36 = RET [%32]  // return total
 *   block_4 LOOP_BODY  <- [block_3]:
 *     >> %20 = ENTER_SCOPE  // {         total += __builtin_va_arg(ap,double);...
 *          %total.2 = ALLOCA/LOCAL size=8 align=1
 *          %22 = MEMORY/CONSUME_VA_PARAM [%21]  // __builtin_va_arg(ap,double)
 *     >> %23 = READ_MODIFY_WRITE(ADD new) [%total.2, %22]  // total += __builtin_va_arg(ap,double)
 *     >> %24 = EXIT_SCOPE  // {         total += __builtin_va_arg(ap,double);...
 *     >> %25 = IMPLICIT_GOTO
 *     -> [block_5]
 *   block_5 LOOP_INCREMENT  <- [block_4]:
 *          %i.3 = ALLOCA/LOCAL size=4 align=1
 *          %26 = CONST/INT64 1  // i++
 *     >> %27 = READ_MODIFY_WRITE(ADD old) [%i.3, %26]  // i++
 *     >> %28 = IMPLICIT_GOTO
 *     -> [block_3]
 * }
 * function va_copy_test (NORMAL) {
 *   objects:
 *     obj_0 PARAMETER_VALUE size=4 align=1 (count)
 *     obj_1 RETURN_SLOT size=4 align=1
 *     obj_2 LOCAL_VALUE size=8 align=1 (ap)
 *     obj_3 LOCAL_VALUE size=8 align=1 (ap2)
 *     obj_4 LOCAL_VALUE size=4 align=1 (first)
 *     obj_5 LOCAL_VALUE size=4 align=1 (second_from_copy)
 *     obj_6 LOCAL_VALUE size=4 align=1 (second_from_orig)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %count.0 = ALLOCA/LOCAL size=4 align=1
 *     >> %6 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %7 = ENTER_SCOPE  // {     va_list ap, ap2;     __builtin_va_start(a...
 *          %9 = MEMORY/LOAD_LE_64 [%ap.1]  // ap
 *     >> %10 = VA_START [%9]  // __builtin_va_start(ap,count)
 *          %first.3 = ALLOCA/LOCAL size=4 align=1
 *          %12 = MEMORY/CONSUME_VA_PARAM [%11]  // __builtin_va_arg(ap,int)
 *     >> %first.13 = MEMORY/STORE_LE_32 [%first.3, %12]
 *          %14 = MEMORY/LOAD_LE_64 [%ap2.2]  // ap2
 *          %15 = MEMORY/LOAD_LE_64 [%ap.1]  // ap
 *     >> %16 = VA_COPY [%14, %15]  // __builtin_va_copy(ap2,ap)
 *          %second_from_copy.4 = ALLOCA/LOCAL size=4 align=1
 *          %18 = MEMORY/CONSUME_VA_PARAM [%17]  // __builtin_va_arg(ap2,int)
 *     >> %second_from_copy.19 = MEMORY/STORE_LE_32 [%second_from_copy.4, %18]
 *          %20 = MEMORY/LOAD_LE_64 [%ap2.2]  // ap2
 *     >> %21 = VA_END [%20]  // __builtin_va_end(ap2)
 *          %second_from_orig.5 = ALLOCA/LOCAL size=4 align=1
 *          %23 = MEMORY/CONSUME_VA_PARAM [%22]  // __builtin_va_arg(ap,int)
 *     >> %second_from_orig.24 = MEMORY/STORE_LE_32 [%second_from_orig.5, %23]
 *          %25 = MEMORY/LOAD_LE_64 [%ap.1]  // ap
 *     >> %26 = VA_END [%25]  // __builtin_va_end(ap)
 *          %32 = RETURN_PTR  // return first + second_from_copy + second_from_orig
 *          %31 = ADD [%29, %30]  // first + second_from_copy + second_from_orig
 *     >> %33 = MEMORY/STORE_LE_32 [%32, %31]  // return first + second_from_copy + second_from_orig
 *     >> %34 = EXIT_SCOPE  // {     va_list ap, ap2;     __builtin_va_start(a...
 *          %31 = ADD [%29, %30]  // first + second_from_copy + second_from_orig
 *     >> %35 = RET [%31]  // return first + second_from_copy + second_from_orig
 * }
 * function test_variadics (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (s1)
 *     obj_2 LOCAL_VALUE size=4 align=1 (s2)
 *     obj_3 LOCAL_VALUE size=4 align=1 (s3)
 *     obj_4 LOCAL_VALUE size=4 align=1 (first)
 *     obj_5 LOCAL_VALUE size=4 align=1 (copy_result)
 *     obj_6 PARAMETER size=4 align=1
 *     obj_7 PARAMETER size=4 align=1
 *     obj_8 PARAMETER size=4 align=1
 *     obj_9 PARAMETER size=4 align=1
 *     obj_10 RETURN_SLOT size=4 align=1
 *     obj_11 PARAMETER size=4 align=1
 *     obj_12 PARAMETER size=4 align=1
 *     obj_13 RETURN_SLOT size=4 align=1
 *     obj_14 PARAMETER size=4 align=1
 *     obj_15 RETURN_SLOT size=4 align=1
 *     obj_16 PARAMETER size=4 align=1
 *     obj_17 PARAMETER size=4 align=1
 *     obj_18 RETURN_SLOT size=4 align=1
 *     obj_19 PARAMETER size=4 align=1
 *     obj_20 PARAMETER size=4 align=1
 *     obj_21 PARAMETER size=4 align=1
 *     obj_22 PARAMETER size=4 align=1
 *     obj_23 RETURN_SLOT size=4 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %5 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %6 = ENTER_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *     >> %7 = ENTER_SCOPE  // va_sum(3, 10, 20, 30)
 *          %9 = ALLOCA/ARG size=4 align=1  // 3
 *          %8 = CONST/INT32 3  // 3
 *     >> %10 = MEMORY/STORE_LE_32 [%9, %8]  // 3
 *          %12 = ALLOCA/ARG size=4 align=1  // 10
 *          %11 = CONST/INT32 10  // 10
 *     >> %13 = MEMORY/STORE_LE_32 [%12, %11]  // 10
 *          %15 = ALLOCA/ARG size=4 align=1  // 20
 *          %14 = CONST/INT32 20  // 20
 *     >> %16 = MEMORY/STORE_LE_32 [%15, %14]  // 20
 *          %18 = ALLOCA/ARG size=4 align=1  // 30
 *          %17 = CONST/INT32 30  // 30
 *     >> %19 = MEMORY/STORE_LE_32 [%18, %17]  // 30
 *          %s1.0 = ALLOCA/LOCAL size=4 align=1
 *          %21 = CALL @va_sum [%9, %12, %15, %18]  // va_sum(3, 10, 20, 30)
 *     >> %s1.22 = MEMORY/STORE_LE_32 [%s1.0, %21]
 *     >> %26 = EXIT_SCOPE
 *          %25 = CMP_NE [%23, %24]  // s1 != 60
 *     >> %27 = COND_BRANCH [%25]  // if (s1 != 60) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %34 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *     >> %35 = ENTER_SCOPE  // va_sum(1, 42)
 *          %37 = ALLOCA/ARG size=4 align=1  // 1
 *          %36 = CONST/INT32 1  // 1
 *     >> %38 = MEMORY/STORE_LE_32 [%37, %36]  // 1
 *          %40 = ALLOCA/ARG size=4 align=1  // 42
 *          %39 = CONST/INT32 42  // 42
 *     >> %41 = MEMORY/STORE_LE_32 [%40, %39]  // 42
 *          %s2.1 = ALLOCA/LOCAL size=4 align=1
 *          %43 = CALL @va_sum [%37, %40]  // va_sum(1, 42)
 *     >> %s2.44 = MEMORY/STORE_LE_32 [%s2.1, %43]
 *     >> %48 = EXIT_SCOPE
 *          %47 = CMP_NE [%45, %46]  // s2 != 42
 *     >> %49 = COND_BRANCH [%47]  // if (s2 != 42) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %56 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *     >> %57 = ENTER_SCOPE  // va_sum(0)
 *          %59 = ALLOCA/ARG size=4 align=1  // 0
 *          %58 = CONST/INT32 0  // 0
 *     >> %60 = MEMORY/STORE_LE_32 [%59, %58]  // 0
 *          %s3.2 = ALLOCA/LOCAL size=4 align=1
 *          %62 = CALL @va_sum [%59]  // va_sum(0)
 *     >> %s3.63 = MEMORY/STORE_LE_32 [%s3.2, %62]
 *     >> %67 = EXIT_SCOPE
 *          %66 = CMP_NE [%64, %65]  // s3 != 0
 *     >> %68 = COND_BRANCH [%66]  // if (s3 != 0) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %75 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *     >> %76 = ENTER_SCOPE  // va_first_int(0, 99)
 *          %78 = ALLOCA/ARG size=4 align=1  // 0
 *          %77 = CONST/INT32 0  // 0
 *     >> %79 = MEMORY/STORE_LE_32 [%78, %77]  // 0
 *          %81 = ALLOCA/ARG size=4 align=1  // 99
 *          %80 = CONST/INT32 99  // 99
 *     >> %82 = MEMORY/STORE_LE_32 [%81, %80]  // 99
 *          %first.3 = ALLOCA/LOCAL size=4 align=1
 *          %84 = CALL @va_first_int [%78, %81]  // va_first_int(0, 99)
 *     >> %first.85 = MEMORY/STORE_LE_32 [%first.3, %84]
 *     >> %89 = EXIT_SCOPE
 *          %88 = CMP_NE [%86, %87]  // first != 99
 *     >> %90 = COND_BRANCH [%88]  // if (first != 99) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %97 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *     >> %98 = ENTER_SCOPE  // va_copy_test(3, 10, 20, 30)
 *          %100 = ALLOCA/ARG size=4 align=1  // 3
 *          %99 = CONST/INT32 3  // 3
 *     >> %101 = MEMORY/STORE_LE_32 [%100, %99]  // 3
 *          %103 = ALLOCA/ARG size=4 align=1  // 10
 *          %102 = CONST/INT32 10  // 10
 *     >> %104 = MEMORY/STORE_LE_32 [%103, %102]  // 10
 *          %106 = ALLOCA/ARG size=4 align=1  // 20
 *          %105 = CONST/INT32 20  // 20
 *     >> %107 = MEMORY/STORE_LE_32 [%106, %105]  // 20
 *          %109 = ALLOCA/ARG size=4 align=1  // 30
 *          %108 = CONST/INT32 30  // 30
 *     >> %110 = MEMORY/STORE_LE_32 [%109, %108]  // 30
 *          %copy_result.4 = ALLOCA/LOCAL size=4 align=1
 *          %112 = CALL @va_copy_test [%100, %103, %106, %109]  // va_copy_test(3, 10, 20, 30)
 *     >> %copy_result.113 = MEMORY/STORE_LE_32 [%copy_result.4, %112]
 *     >> %117 = EXIT_SCOPE
 *          %116 = CMP_NE [%114, %115]  // copy_result != 50
 *     >> %118 = COND_BRANCH [%116]  // if (copy_result != 50) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %125 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %127 = RETURN_PTR  // return 0
 *          %126 = CONST/INT32 0  // 0
 *     >> %128 = MEMORY/STORE_LE_32 [%127, %126]  // return 0
 *     >> %129 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %126 = CONST/INT32 0  // 0
 *     >> %130 = RET [%126]  // return 0
 *   block_14 IF_THEN  <- [block_13]:
 *          %120 = RETURN_PTR  // return 5
 *          %119 = CONST/INT32 5  // 5
 *     >> %121 = MEMORY/STORE_LE_32 [%120, %119]  // return 5
 *     >> %122 = EXIT_SCOPE  // va_copy_test(3, 10, 20, 30)
 *     >> %123 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %119 = CONST/INT32 5  // 5
 *     >> %124 = RET [%119]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %92 = RETURN_PTR  // return 4
 *          %91 = CONST/INT32 4  // 4
 *     >> %93 = MEMORY/STORE_LE_32 [%92, %91]  // return 4
 *     >> %94 = EXIT_SCOPE  // va_first_int(0, 99)
 *     >> %95 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %91 = CONST/INT32 4  // 4
 *     >> %96 = RET [%91]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %70 = RETURN_PTR  // return 3
 *          %69 = CONST/INT32 3  // 3
 *     >> %71 = MEMORY/STORE_LE_32 [%70, %69]  // return 3
 *     >> %72 = EXIT_SCOPE  // va_sum(0)
 *     >> %73 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %69 = CONST/INT32 3  // 3
 *     >> %74 = RET [%69]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %51 = RETURN_PTR  // return 2
 *          %50 = CONST/INT32 2  // 2
 *     >> %52 = MEMORY/STORE_LE_32 [%51, %50]  // return 2
 *     >> %53 = EXIT_SCOPE  // va_sum(1, 42)
 *     >> %54 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %50 = CONST/INT32 2  // 2
 *     >> %55 = RET [%50]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %29 = RETURN_PTR  // return 1
 *          %28 = CONST/INT32 1  // 1
 *     >> %30 = MEMORY/STORE_LE_32 [%29, %28]  // return 1
 *     >> %31 = EXIT_SCOPE  // va_sum(3, 10, 20, 30)
 *     >> %32 = EXIT_SCOPE  // {     // Basic variadic sum.     int s1 = va_su...
 *          %28 = CONST/INT32 1  // 1
 *     >> %33 = RET [%28]  // return 1
 * }
 */



#include <stdarg.h>

static int va_sum(int count, ...) {
    va_list ap;
    va_start(ap, count);
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(ap, int);
    }
    va_end(ap);
    return total;
}

static int va_first_int(int dummy, ...) {
    va_list ap;
    va_start(ap, dummy);
    int result = va_arg(ap, int);
    va_end(ap);
    return result;
}

static double va_sum_doubles(int count, ...) {
    va_list ap;
    va_start(ap, count);
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total;
}

static int va_copy_test(int count, ...) {
    va_list ap, ap2;
    va_start(ap, count);

    // Read first element.
    int first = va_arg(ap, int);

    // Copy va_list and read from copy.
    va_copy(ap2, ap);
    int second_from_copy = va_arg(ap2, int);
    va_end(ap2);

    // Read from original (should give same second element).
    int second_from_orig = va_arg(ap, int);

    va_end(ap);
    return first + second_from_copy + second_from_orig;
}

int test_variadics(void) {
    // Basic variadic sum.
    int s1 = va_sum(3, 10, 20, 30);
    if (s1 != 60) return 1;

    // Single variadic arg.
    int s2 = va_sum(1, 42);
    if (s2 != 42) return 2;

    // Zero variadic args.
    int s3 = va_sum(0);
    if (s3 != 0) return 3;

    // First int extraction.
    int first = va_first_int(0, 99);
    if (first != 99) return 4;

    // va_copy: first=10, second=20, result = 10 + 20 + 20 = 50.
    int copy_result = va_copy_test(3, 10, 20, 30);
    if (copy_result != 50) return 5;

    return 0;
}
