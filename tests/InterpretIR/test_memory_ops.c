// Tests: memory and string operations (MEMORY sub-opcodes) —
// memset, memcpy, memmove, memcmp, memchr, strlen, strcmp, strncmp,
// strchr, strrchr, strcpy, strcat.
// Uses __builtin_ variants to avoid needing system headers.

/*
 * Expected IR:
 *
 * function test_memory_ops (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=16 align=1 (buf)
 *     obj_2 LOCAL_VALUE size=6 align=1 (src)
 *     obj_3 LOCAL_VALUE size=16 align=1 (dst)
 *     obj_4 LOCAL_VALUE size=9 align=1 (overlap)
 *     obj_5 LOCAL_VALUE size=8 align=1 (sc)
 *     obj_6 LOCAL_VALUE size=16 align=1 (dest2)
 *     obj_7 LOCAL_VALUE size=32 align=1 (dest3)
 *     obj_8 STRING_LITERAL size=7 align=1
 *     obj_9 STRING_LITERAL size=10 align=1
 *     obj_10 STRING_LITERAL size=5 align=1
 *     obj_11 STRING_LITERAL size=5 align=1
 *     obj_12 STRING_LITERAL size=5 align=1
 *     obj_13 STRING_LITERAL size=5 align=1
 *     obj_14 STRING_LITERAL size=7 align=1
 *     obj_15 STRING_LITERAL size=2 align=1
 *     obj_16 STRING_LITERAL size=5 align=1
 *     obj_17 STRING_LITERAL size=5 align=1
 *     obj_18 STRING_LITERAL size=5 align=1
 *     obj_19 STRING_LITERAL size=5 align=1
 *     obj_20 STRING_LITERAL size=8 align=1
 *     obj_21 STRING_LITERAL size=8 align=1
 *     obj_22 STRING_LITERAL size=13 align=1
 *     obj_23 STRING_LITERAL size=6 align=1
 *     obj_24 STRING_LITERAL size=7 align=1
 *     obj_25 STRING_LITERAL size=8 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %7 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %8 = ENTER_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %9 = CAST/BITCAST [%buf.0]  // buf
 *          %10 = CONST/UINT8 65  // 'A'
 *          %12 = CAST/SEXT_I32_I64 [%11]  // 10
 *     >> %13 = MEMORY/MEMSET [%9, %10, %12]  // __builtin_memset(buf, 'A', 10)
 *          %15 = PTR_ADD elem_size=1 [%buf.0, %14]  // buf[10]
 *          %17 = CAST/TRUNC_I32_I8 [%16]  // '\0'
 *     >> %18 = MEMORY/STORE_LE_8 [%15, %17]  // buf[10] = '\0'
 *          %24 = CMP_NE [%22, %23]  // buf[0] != 'A'
 *     >> %25 = COND_BRANCH [%24]  // if (buf[0] != 'A') return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %31 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %37 = CMP_NE [%35, %36]  // buf[9] != 'A'
 *     >> %38 = COND_BRANCH [%37]  // if (buf[9] != 'A') return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %44 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %src.1 = ALLOCA/LOCAL size=6 align=1
 *          %45 = ALLOCA/LOCAL size=7 align=1  // "hello"
 *          %46 = CONST/UINT64 0
 *     >> %src.47 = MEMORY/MEMCPY [%src.1, %45, %46]
 *          %48 = CAST/BITCAST [%dst.2]  // dst
 *          %49 = CAST/BITCAST [%src.1]  // src
 *          %51 = CAST/SEXT_I32_I64 [%50]  // 6
 *     >> %52 = MEMORY/MEMCPY [%48, %49, %51]  // __builtin_memcpy(dst, src, 6)
 *          %58 = CMP_NE [%56, %57]  // dst[0] != 'h'
 *     >> %59 = COND_BRANCH [%58]  // if (dst[0] != 'h') return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %65 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %71 = CMP_NE [%69, %70]  // dst[4] != 'o'
 *     >> %72 = COND_BRANCH [%71]  // if (dst[4] != 'o') return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %78 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %overlap.3 = ALLOCA/LOCAL size=9 align=1
 *          %79 = ALLOCA/LOCAL size=10 align=1  // "abcdefgh"
 *          %80 = CONST/UINT64 0
 *     >> %overlap.81 = MEMORY/MEMCPY [%overlap.3, %79, %80]
 *          %84 = CAST/BITCAST [%83]  // overlap + 2
 *          %85 = CAST/BITCAST [%overlap.3]  // overlap
 *          %87 = CAST/SEXT_I32_I64 [%86]  // 4
 *     >> %88 = MEMORY/MEMMOVE [%84, %85, %87]  // __builtin_memmove(overlap + 2, overlap, 4)
 *          %94 = CMP_NE [%92, %93]  // overlap[2] != 'a'
 *     >> %95 = COND_BRANCH [%94]  // if (overlap[2] != 'a') return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %101 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %107 = CMP_NE [%105, %106]  // overlap[5] != 'd'
 *     >> %108 = COND_BRANCH [%107]  // if (overlap[5] != 'd') return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %114 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %123 = CMP_NE [%121, %122]  // __builtin_memcmp("abc", "abc", 3) != 0
 *     >> %124 = COND_BRANCH [%123]  // if (__builtin_memcmp("abc", "abc", 3) != 0) ret...
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %130 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %139 = CMP_GE [%137, %138]  // __builtin_memcmp("abc", "abd", 3) >= 0
 *     >> %140 = COND_BRANCH [%139]  // if (__builtin_memcmp("abc", "abd", 3) >= 0) ret...
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %146 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %151 = CMP_NE [%148, %150]  // __builtin_strlen("hello") != 5
 *     >> %152 = COND_BRANCH [%151]  // if (__builtin_strlen("hello") != 5) return 10
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %158 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %163 = CMP_NE [%160, %162]  // __builtin_strlen("") != 0
 *     >> %164 = COND_BRANCH [%163]  // if (__builtin_strlen("") != 0) return 11
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %170 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %175 = CMP_NE [%173, %174]  // __builtin_strcmp("abc", "abc") != 0
 *     >> %176 = COND_BRANCH [%175]  // if (__builtin_strcmp("abc", "abc") != 0) return 12
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %182 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %187 = CMP_GE [%185, %186]  // __builtin_strcmp("abc", "abd") >= 0
 *     >> %188 = COND_BRANCH [%187]  // if (__builtin_strcmp("abc", "abd") >= 0) return 13
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %194 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %201 = CMP_NE [%199, %200]  // __builtin_strncmp("abcXXX", "abcYYY", 3) != 0
 *     >> %202 = COND_BRANCH [%201]  // if (__builtin_strncmp("abcXXX", "abcYYY", 3) !=...
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %208 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *          %sc.4 = ALLOCA/LOCAL size=8 align=1
 *          %211 = MEMORY/STRCHR [%209, %210]  // __builtin_strchr("hello world", 'w')
 *     >> %sc.212 = MEMORY/STORE_LE_64 [%sc.4, %211]
 *          %215 = CMP_EQ [%213, %214]  // sc == 0
 *     >> %216 = COND_BRANCH [%215]  // if (sc == 0) return 15
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %222 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *          %dest2.5 = ALLOCA/LOCAL size=16 align=1
 *          %223 = ALLOCA/LOCAL size=6 align=1  // "test"
 *     >> %224 = MEMORY/STRCPY [%dest2.5, %223]  // __builtin_strcpy(dest2, "test")
 *          %230 = CMP_NE [%228, %229]  // dest2[0] != 't'
 *     >> %231 = COND_BRANCH [%230]  // if (dest2[0] != 't') return 17
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %237 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %dest3.6 = ALLOCA/LOCAL size=32 align=1
 *          %238 = ALLOCA/LOCAL size=7 align=1  // "hello"
 *          %239 = CONST/UINT64 0
 *     >> %dest3.240 = MEMORY/MEMCPY [%dest3.6, %238, %239]
 *          %dest3.6 = ALLOCA/LOCAL size=32 align=1
 *          %241 = ALLOCA/LOCAL size=8 align=1  // " world"
 *     >> %242 = MEMORY/STRCAT [%dest3.6, %241]  // __builtin_strcat(dest3, " world")
 *          %246 = CMP_NE [%243, %245]  // __builtin_strlen(dest3) != 11
 *     >> %247 = COND_BRANCH [%246]  // if (__builtin_strlen(dest3) != 11) return 18
 *     -> [block_47, block_48]
 *   block_48 IF_ELSE  <- [block_46]:
 *     >> %253 = IMPLICIT_GOTO
 *     -> [block_49]
 *   block_49 IF_MERGE  <- [block_48]:
 *          %255 = RETURN_PTR  // return 0
 *          %254 = CONST/INT32 0  // 0
 *     >> %256 = MEMORY/STORE_LE_32 [%255, %254]  // return 0
 *     >> %257 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %254 = CONST/INT32 0  // 0
 *     >> %258 = RET [%254]  // return 0
 *   block_47 IF_THEN  <- [block_46]:
 *          %249 = RETURN_PTR  // return 18
 *          %248 = CONST/INT32 18  // 18
 *     >> %250 = MEMORY/STORE_LE_32 [%249, %248]  // return 18
 *     >> %251 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %248 = CONST/INT32 18  // 18
 *     >> %252 = RET [%248]  // return 18
 *   block_44 IF_THEN  <- [block_43]:
 *          %233 = RETURN_PTR  // return 17
 *          %232 = CONST/INT32 17  // 17
 *     >> %234 = MEMORY/STORE_LE_32 [%233, %232]  // return 17
 *     >> %235 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %232 = CONST/INT32 17  // 17
 *     >> %236 = RET [%232]  // return 17
 *   block_41 IF_THEN  <- [block_40]:
 *          %218 = RETURN_PTR  // return 15
 *          %217 = CONST/INT32 15  // 15
 *     >> %219 = MEMORY/STORE_LE_32 [%218, %217]  // return 15
 *     >> %220 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %217 = CONST/INT32 15  // 15
 *     >> %221 = RET [%217]  // return 15
 *   block_38 IF_THEN  <- [block_37]:
 *          %204 = RETURN_PTR  // return 14
 *          %203 = CONST/INT32 14  // 14
 *     >> %205 = MEMORY/STORE_LE_32 [%204, %203]  // return 14
 *     >> %206 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %203 = CONST/INT32 14  // 14
 *     >> %207 = RET [%203]  // return 14
 *   block_35 IF_THEN  <- [block_34]:
 *          %190 = RETURN_PTR  // return 13
 *          %189 = CONST/INT32 13  // 13
 *     >> %191 = MEMORY/STORE_LE_32 [%190, %189]  // return 13
 *     >> %192 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %189 = CONST/INT32 13  // 13
 *     >> %193 = RET [%189]  // return 13
 *   block_32 IF_THEN  <- [block_31]:
 *          %178 = RETURN_PTR  // return 12
 *          %177 = CONST/INT32 12  // 12
 *     >> %179 = MEMORY/STORE_LE_32 [%178, %177]  // return 12
 *     >> %180 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %177 = CONST/INT32 12  // 12
 *     >> %181 = RET [%177]  // return 12
 *   block_29 IF_THEN  <- [block_28]:
 *          %166 = RETURN_PTR  // return 11
 *          %165 = CONST/INT32 11  // 11
 *     >> %167 = MEMORY/STORE_LE_32 [%166, %165]  // return 11
 *     >> %168 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %165 = CONST/INT32 11  // 11
 *     >> %169 = RET [%165]  // return 11
 *   block_26 IF_THEN  <- [block_25]:
 *          %154 = RETURN_PTR  // return 10
 *          %153 = CONST/INT32 10  // 10
 *     >> %155 = MEMORY/STORE_LE_32 [%154, %153]  // return 10
 *     >> %156 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %153 = CONST/INT32 10  // 10
 *     >> %157 = RET [%153]  // return 10
 *   block_23 IF_THEN  <- [block_22]:
 *          %142 = RETURN_PTR  // return 8
 *          %141 = CONST/INT32 8  // 8
 *     >> %143 = MEMORY/STORE_LE_32 [%142, %141]  // return 8
 *     >> %144 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %141 = CONST/INT32 8  // 8
 *     >> %145 = RET [%141]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %126 = RETURN_PTR  // return 7
 *          %125 = CONST/INT32 7  // 7
 *     >> %127 = MEMORY/STORE_LE_32 [%126, %125]  // return 7
 *     >> %128 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %125 = CONST/INT32 7  // 7
 *     >> %129 = RET [%125]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %110 = RETURN_PTR  // return 6
 *          %109 = CONST/INT32 6  // 6
 *     >> %111 = MEMORY/STORE_LE_32 [%110, %109]  // return 6
 *     >> %112 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %109 = CONST/INT32 6  // 6
 *     >> %113 = RET [%109]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %97 = RETURN_PTR  // return 5
 *          %96 = CONST/INT32 5  // 5
 *     >> %98 = MEMORY/STORE_LE_32 [%97, %96]  // return 5
 *     >> %99 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %96 = CONST/INT32 5  // 5
 *     >> %100 = RET [%96]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %74 = RETURN_PTR  // return 4
 *          %73 = CONST/INT32 4  // 4
 *     >> %75 = MEMORY/STORE_LE_32 [%74, %73]  // return 4
 *     >> %76 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %73 = CONST/INT32 4  // 4
 *     >> %77 = RET [%73]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %61 = RETURN_PTR  // return 3
 *          %60 = CONST/INT32 3  // 3
 *     >> %62 = MEMORY/STORE_LE_32 [%61, %60]  // return 3
 *     >> %63 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %60 = CONST/INT32 3  // 3
 *     >> %64 = RET [%60]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %40 = RETURN_PTR  // return 2
 *          %39 = CONST/INT32 2  // 2
 *     >> %41 = MEMORY/STORE_LE_32 [%40, %39]  // return 2
 *     >> %42 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %39 = CONST/INT32 2  // 2
 *     >> %43 = RET [%39]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %27 = RETURN_PTR  // return 1
 *          %26 = CONST/INT32 1  // 1
 *     >> %28 = MEMORY/STORE_LE_32 [%27, %26]  // return 1
 *     >> %29 = EXIT_SCOPE  // {     // memset.     char buf[16];     __builti...
 *          %26 = CONST/INT32 1  // 1
 *     >> %30 = RET [%26]  // return 1
 * }
 */

typedef unsigned long size_t;

int test_memory_ops(void) {
    // memset.
    char buf[16];
    __builtin_memset(buf, 'A', 10);
    buf[10] = '\0';
    if (buf[0] != 'A') return 1;
    if (buf[9] != 'A') return 2;

    // memcpy.
    char src[] = "hello";
    char dst[16];
    __builtin_memcpy(dst, src, 6);
    if (dst[0] != 'h') return 3;
    if (dst[4] != 'o') return 4;

    // memmove (overlapping).
    char overlap[] = "abcdefgh";
    __builtin_memmove(overlap + 2, overlap, 4);
    if (overlap[2] != 'a') return 5;
    if (overlap[5] != 'd') return 6;

    // memcmp.
    if (__builtin_memcmp("abc", "abc", 3) != 0) return 7;
    if (__builtin_memcmp("abc", "abd", 3) >= 0) return 8;

    // strlen.
    if (__builtin_strlen("hello") != 5) return 10;
    if (__builtin_strlen("") != 0) return 11;

    // strcmp.
    if (__builtin_strcmp("abc", "abc") != 0) return 12;
    if (__builtin_strcmp("abc", "abd") >= 0) return 13;

    // strncmp.
    if (__builtin_strncmp("abcXXX", "abcYYY", 3) != 0) return 14;

    // strchr.
    const char *sc = __builtin_strchr("hello world", 'w');
    if (sc == 0) return 15;

    // strcpy.
    char dest2[16];
    __builtin_strcpy(dest2, "test");
    if (dest2[0] != 't') return 17;

    // strcat.
    char dest3[32] = "hello";
    __builtin_strcat(dest3, " world");
    if (__builtin_strlen(dest3) != 11) return 18;

    return 0;
}
