// Tests: string literal handling (STRING_LITERAL objects, ALLOCA for string
// storage, non-power-of-2 sizes → MEMCPY for initialization),
// array initialization from string literals, string pointer assignment.

/*
 * Expected IR:
 *
 * function my_strlen (NORMAL) {
 *   objects:
 *     obj_0 PARAMETER_VALUE size=8 align=1 (s)
 *     obj_1 RETURN_SLOT size=4 align=1
 *     obj_2 LOCAL_VALUE size=4 align=1 (len)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %s.0 = ALLOCA/LOCAL size=8 align=1
 *     >> %2 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %3 = ENTER_SCOPE  // {     int len = 0;     while (s[len] != '\0') {...
 *          %len.1 = ALLOCA/LOCAL size=4 align=1
 *          %5 = CONST/INT32 0  // 0
 *     >> %len.6 = MEMORY/STORE_LE_32 [%len.1, %5]
 *     >> %7 = IMPLICIT_GOTO
 *     -> [block_2]
 *   block_2 LOOP_PREHEADER  <- [block_1]:
 *     >> %8 = IMPLICIT_GOTO
 *     -> [block_3]
 *   block_3 LOOP_CONDITION  <- [block_2, block_4]:
 *          %15 = CMP_NE [%13, %14]  // s[len] != '\0'
 *     >> %16 = COND_BRANCH [%15]  // while (s[len] != '\0') {         len++;     }
 *     -> [block_4, block_5]
 *   block_5 LOOP_EXIT  <- [block_3]:
 *          %23 = RETURN_PTR  // return len
 *          %22 = MEMORY/LOAD_LE_32 [%len.1]  // len
 *     >> %24 = MEMORY/STORE_LE_32 [%23, %22]  // return len
 *     >> %25 = EXIT_SCOPE  // {     int len = 0;     while (s[len] != '\0') {...
 *          %22 = MEMORY/LOAD_LE_32 [%len.1]  // len
 *     >> %26 = RET [%22]  // return len
 *   block_4 LOOP_BODY  <- [block_3]:
 *     >> %17 = ENTER_SCOPE  // {         len++;     }
 *          %len.1 = ALLOCA/LOCAL size=4 align=1
 *          %18 = CONST/INT64 1  // len++
 *     >> %19 = READ_MODIFY_WRITE(ADD old) [%len.1, %18]  // len++
 *     >> %20 = EXIT_SCOPE  // {         len++;     }
 *     >> %21 = IMPLICIT_GOTO
 *     -> [block_3]
 * }
 * function test_string_literals (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=6 align=1 (buf)
 *     obj_2 LOCAL_VALUE size=8 align=1 (p)
 *     obj_3 LOCAL_VALUE size=4 align=1 (len)
 *     obj_4 LOCAL_VALUE size=16 align=1 (long_buf)
 *     obj_5 LOCAL_VALUE size=1 align=1 (empty)
 *     obj_6 LOCAL_VALUE size=2 align=1 (single)
 *     obj_7 STRING_LITERAL size=7 align=1
 *     obj_8 STRING_LITERAL size=7 align=1
 *     obj_9 STRING_LITERAL size=6 align=1
 *     obj_10 PARAMETER size=8 align=1
 *     obj_11 RETURN_SLOT size=4 align=1
 *     obj_12 STRING_LITERAL size=17 align=1
 *     obj_13 STRING_LITERAL size=2 align=1
 *     obj_14 STRING_LITERAL size=3 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %6 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %7 = ENTER_SCOPE  // {     // String literal initialization of char ...
 *          %buf.0 = ALLOCA/LOCAL size=6 align=1
 *          %8 = ALLOCA/LOCAL size=7 align=1  // "hello"
 *          %9 = CONST/UINT64 6
 *     >> %buf.10 = MEMORY/MEMCPY [%buf.0, %8, %9]
 *          %16 = CMP_NE [%14, %15]  // buf[0] != 'h'
 *     >> %17 = COND_BRANCH [%16]  // if (buf[0] != 'h') return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %23 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %29 = CMP_NE [%27, %28]  // buf[4] != 'o'
 *     >> %30 = COND_BRANCH [%29]  // if (buf[4] != 'o') return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %36 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %42 = CMP_NE [%40, %41]  // buf[5] != '\0'
 *     >> %43 = COND_BRANCH [%42]  // if (buf[5] != '\0') return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %49 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %p.1 = ALLOCA/LOCAL size=8 align=1
 *          %50 = ALLOCA/LOCAL size=7 align=1  // "world"
 *     >> %p.51 = MEMORY/STORE_LE_64 [%p.1, %50]
 *          %58 = CMP_NE [%56, %57]  // p[0] != 'w'
 *     >> %59 = COND_BRANCH [%58]  // if (p[0] != 'w') return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %65 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %72 = CMP_NE [%70, %71]  // p[4] != 'd'
 *     >> %73 = COND_BRANCH [%72]  // if (p[4] != 'd') return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %79 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *     >> %80 = ENTER_SCOPE  // my_strlen("test")
 *          %82 = ALLOCA/ARG size=8 align=1  // "test"
 *          %81 = ALLOCA/LOCAL size=6 align=1  // "test"
 *     >> %83 = MEMORY/STORE_LE_64 [%82, %81]  // "test"
 *          %len.2 = ALLOCA/LOCAL size=4 align=1
 *          %85 = CALL @my_strlen [%82]  // my_strlen("test")
 *     >> %len.86 = MEMORY/STORE_LE_32 [%len.2, %85]
 *     >> %90 = EXIT_SCOPE
 *          %89 = CMP_NE [%87, %88]  // len != 4
 *     >> %91 = COND_BRANCH [%89]  // if (len != 4) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %98 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %long_buf.3 = ALLOCA/LOCAL size=16 align=1
 *          %99 = ALLOCA/LOCAL size=17 align=1  // "0123456789abcde"
 *          %100 = CONST/UINT64 16
 *     >> %long_buf.101 = MEMORY/MEMCPY [%long_buf.3, %99, %100]
 *          %107 = CMP_NE [%105, %106]  // long_buf[0] != '0'
 *     >> %108 = COND_BRANCH [%107]  // if (long_buf[0] != '0') return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %114 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %120 = CMP_NE [%118, %119]  // long_buf[9] != '9'
 *     >> %121 = COND_BRANCH [%120]  // if (long_buf[9] != '9') return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %127 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %133 = CMP_NE [%131, %132]  // long_buf[14] != 'e'
 *     >> %134 = COND_BRANCH [%133]  // if (long_buf[14] != 'e') return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %140 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %146 = CMP_NE [%144, %145]  // long_buf[15] != '\0'
 *     >> %147 = COND_BRANCH [%146]  // if (long_buf[15] != '\0') return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %153 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %empty.4 = ALLOCA/LOCAL size=1 align=1
 *          %154 = ALLOCA/LOCAL size=2 align=1  // ""
 *     >> %empty.155 = MEMORY/STORE_LE_8 [%empty.4, %154]
 *          %161 = CMP_NE [%159, %160]  // empty[0] != '\0'
 *     >> %162 = COND_BRANCH [%161]  // if (empty[0] != '\0') return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %168 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %single.5 = ALLOCA/LOCAL size=2 align=1
 *          %169 = ALLOCA/LOCAL size=3 align=1  // "x"
 *     >> %single.170 = MEMORY/STORE_LE_16 [%single.5, %169]
 *          %176 = CMP_NE [%174, %175]  // single[0] != 'x'
 *     >> %177 = COND_BRANCH [%176]  // if (single[0] != 'x') return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %183 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %189 = CMP_NE [%187, %188]  // single[1] != '\0'
 *     >> %190 = COND_BRANCH [%189]  // if (single[1] != '\0') return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %196 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *          %198 = RETURN_PTR  // return 0
 *          %197 = CONST/INT32 0  // 0
 *     >> %199 = MEMORY/STORE_LE_32 [%198, %197]  // return 0
 *     >> %200 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %197 = CONST/INT32 0  // 0
 *     >> %201 = RET [%197]  // return 0
 *   block_38 IF_THEN  <- [block_37]:
 *          %192 = RETURN_PTR  // return 13
 *          %191 = CONST/INT32 13  // 13
 *     >> %193 = MEMORY/STORE_LE_32 [%192, %191]  // return 13
 *     >> %194 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %191 = CONST/INT32 13  // 13
 *     >> %195 = RET [%191]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %179 = RETURN_PTR  // return 12
 *          %178 = CONST/INT32 12  // 12
 *     >> %180 = MEMORY/STORE_LE_32 [%179, %178]  // return 12
 *     >> %181 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %178 = CONST/INT32 12  // 12
 *     >> %182 = RET [%178]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %164 = RETURN_PTR  // return 11
 *          %163 = CONST/INT32 11  // 11
 *     >> %165 = MEMORY/STORE_LE_32 [%164, %163]  // return 11
 *     >> %166 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %163 = CONST/INT32 11  // 11
 *     >> %167 = RET [%163]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %149 = RETURN_PTR  // return 10
 *          %148 = CONST/INT32 10  // 10
 *     >> %150 = MEMORY/STORE_LE_32 [%149, %148]  // return 10
 *     >> %151 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %148 = CONST/INT32 10  // 10
 *     >> %152 = RET [%148]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %136 = RETURN_PTR  // return 9
 *          %135 = CONST/INT32 9  // 9
 *     >> %137 = MEMORY/STORE_LE_32 [%136, %135]  // return 9
 *     >> %138 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %135 = CONST/INT32 9  // 9
 *     >> %139 = RET [%135]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %123 = RETURN_PTR  // return 8
 *          %122 = CONST/INT32 8  // 8
 *     >> %124 = MEMORY/STORE_LE_32 [%123, %122]  // return 8
 *     >> %125 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %122 = CONST/INT32 8  // 8
 *     >> %126 = RET [%122]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %110 = RETURN_PTR  // return 7
 *          %109 = CONST/INT32 7  // 7
 *     >> %111 = MEMORY/STORE_LE_32 [%110, %109]  // return 7
 *     >> %112 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %109 = CONST/INT32 7  // 7
 *     >> %113 = RET [%109]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %93 = RETURN_PTR  // return 6
 *          %92 = CONST/INT32 6  // 6
 *     >> %94 = MEMORY/STORE_LE_32 [%93, %92]  // return 6
 *     >> %95 = EXIT_SCOPE  // my_strlen("test")
 *     >> %96 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %92 = CONST/INT32 6  // 6
 *     >> %97 = RET [%92]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %75 = RETURN_PTR  // return 5
 *          %74 = CONST/INT32 5  // 5
 *     >> %76 = MEMORY/STORE_LE_32 [%75, %74]  // return 5
 *     >> %77 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %74 = CONST/INT32 5  // 5
 *     >> %78 = RET [%74]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %61 = RETURN_PTR  // return 4
 *          %60 = CONST/INT32 4  // 4
 *     >> %62 = MEMORY/STORE_LE_32 [%61, %60]  // return 4
 *     >> %63 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %60 = CONST/INT32 4  // 4
 *     >> %64 = RET [%60]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %45 = RETURN_PTR  // return 3
 *          %44 = CONST/INT32 3  // 3
 *     >> %46 = MEMORY/STORE_LE_32 [%45, %44]  // return 3
 *     >> %47 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %44 = CONST/INT32 3  // 3
 *     >> %48 = RET [%44]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %32 = RETURN_PTR  // return 2
 *          %31 = CONST/INT32 2  // 2
 *     >> %33 = MEMORY/STORE_LE_32 [%32, %31]  // return 2
 *     >> %34 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %31 = CONST/INT32 2  // 2
 *     >> %35 = RET [%31]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %19 = RETURN_PTR  // return 1
 *          %18 = CONST/INT32 1  // 1
 *     >> %20 = MEMORY/STORE_LE_32 [%19, %18]  // return 1
 *     >> %21 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %18 = CONST/INT32 1  // 1
 *     >> %22 = RET [%18]  // return 1
 * }
 */


static int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int test_string_literals(void) {
    // String literal initialization of char array.
    // "hello" is char[6] (5 chars + null) — non-power-of-2 → MEMCPY.
    char buf[6] = "hello";
    if (buf[0] != 'h') return 1;
    if (buf[4] != 'o') return 2;
    if (buf[5] != '\0') return 3;

    // String pointer (decays to pointer to string literal storage).
    const char *p = "world";
    if (p[0] != 'w') return 4;
    if (p[4] != 'd') return 5;

    // String literal in function call.
    int len = my_strlen("test");
    if (len != 4) return 6;

    // Longer string (> 8 bytes, definitely MEMCPY).
    char long_buf[16] = "0123456789abcde";
    if (long_buf[0] != '0') return 7;
    if (long_buf[9] != '9') return 8;
    if (long_buf[14] != 'e') return 9;
    if (long_buf[15] != '\0') return 10;

    // Empty string.
    char empty[1] = "";
    if (empty[0] != '\0') return 11;

    // Single character string.
    char single[2] = "x";
    if (single[0] != 'x') return 12;
    if (single[1] != '\0') return 13;

    return 0;
}
