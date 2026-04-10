// Tests: unsigned integer operations — zero extension, unsigned arithmetic,
// unsigned comparisons, unsigned overflow/wrap-around, mixing signed/unsigned.

/*
 * Expected IR:
 *
 * function test_unsigned (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (ua)
 *     obj_2 LOCAL_VALUE size=4 align=1 (ub)
 *     obj_3 LOCAL_VALUE size=4 align=1 (sum)
 *     obj_4 LOCAL_VALUE size=4 align=1 (diff)
 *     obj_5 LOCAL_VALUE size=4 align=1 (wrapped)
 *     obj_6 LOCAL_VALUE size=1 align=1 (uc)
 *     obj_7 LOCAL_VALUE size=4 align=1 (zext)
 *     obj_8 LOCAL_VALUE size=1 align=1 (sc)
 *     obj_9 LOCAL_VALUE size=4 align=1 (sext)
 *     obj_10 LOCAL_VALUE size=4 align=1 (udiv)
 *     obj_11 LOCAL_VALUE size=4 align=1 (umod)
 *     obj_12 LOCAL_VALUE size=4 align=1 (large)
 *     obj_13 LOCAL_VALUE size=4 align=1 (half)
 *     obj_14 LOCAL_VALUE size=4 align=1 (shifted)
 *     obj_15 LOCAL_VALUE size=4 align=1 (rshifted)
 *     obj_16 LOCAL_VALUE size=4 align=1 (uval)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %16 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %17 = ENTER_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %ua.0 = ALLOCA/LOCAL size=4 align=1
 *          %19 = CAST/IDENTITY [%18]  // 200
 *     >> %ua.20 = MEMORY/STORE_LE_32 [%ua.0, %19]
 *          %ub.1 = ALLOCA/LOCAL size=4 align=1
 *          %22 = CAST/IDENTITY [%21]  // 100
 *     >> %ub.23 = MEMORY/STORE_LE_32 [%ub.1, %22]
 *          %sum.2 = ALLOCA/LOCAL size=4 align=1
 *          %26 = ADD [%24, %25]  // ua + ub
 *     >> %sum.27 = MEMORY/STORE_LE_32 [%sum.2, %26]
 *          %31 = CMP_NE [%28, %30]  // sum != 300
 *     >> %32 = COND_BRANCH [%31]  // if (sum != 300) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %38 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %diff.3 = ALLOCA/LOCAL size=4 align=1
 *          %41 = SUB [%39, %40]  // ua - ub
 *     >> %diff.42 = MEMORY/STORE_LE_32 [%diff.3, %41]
 *          %46 = CMP_NE [%43, %45]  // diff != 100
 *     >> %47 = COND_BRANCH [%46]  // if (diff != 100) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %53 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %57 = LOGICAL_NOT [%56]  // !(ua > ub)
 *     >> %58 = COND_BRANCH [%57]  // if (!(ua > ub)) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %64 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %67 = CMP_LT [%65, %66]  // ua < ub
 *     >> %68 = COND_BRANCH [%67]  // if (ua < ub) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %74 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %77 = CMP_EQ [%75, %76]  // ua == ub
 *     >> %78 = COND_BRANCH [%77]  // if (ua == ub) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %84 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %wrapped.4 = ALLOCA/LOCAL size=4 align=1
 *          %87 = SUB [%85, %86]  // 0u - 1u
 *     >> %wrapped.88 = MEMORY/STORE_LE_32 [%wrapped.4, %87]
 *          %91 = CMP_NE [%89, %90]  // wrapped != 4294967295u
 *     >> %92 = COND_BRANCH [%91]  // if (wrapped != 4294967295u) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %98 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %uc.5 = ALLOCA/LOCAL size=1 align=1
 *          %100 = CAST/TRUNC_I32_I8 [%99]  // 200
 *     >> %uc.101 = MEMORY/STORE_LE_8 [%uc.5, %100]
 *          %zext.6 = ALLOCA/LOCAL size=4 align=1
 *          %103 = CAST/ZEXT_I8_I32 [%102]  // uc
 *     >> %zext.104 = MEMORY/STORE_LE_32 [%zext.6, %103]
 *          %108 = CMP_NE [%105, %107]  // zext != 200
 *     >> %109 = COND_BRANCH [%108]  // if (zext != 200) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %115 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %sc.7 = ALLOCA/LOCAL size=1 align=1
 *          %118 = CAST/TRUNC_I32_I8 [%117]  // -5
 *     >> %sc.119 = MEMORY/STORE_LE_8 [%sc.7, %118]
 *          %sext.8 = ALLOCA/LOCAL size=4 align=1
 *          %121 = CAST/SEXT_I8_I32 [%120]  // sc
 *     >> %sext.122 = MEMORY/STORE_LE_32 [%sext.8, %121]
 *          %126 = CMP_NE [%123, %125]  // sext != -5
 *     >> %127 = COND_BRANCH [%126]  // if (sext != -5) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %133 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %udiv.9 = ALLOCA/LOCAL size=4 align=1
 *          %136 = UDIV [%134, %135]  // 10u / 3u
 *     >> %udiv.137 = MEMORY/STORE_LE_32 [%udiv.9, %136]
 *          %141 = CMP_NE [%138, %140]  // udiv != 3
 *     >> %142 = COND_BRANCH [%141]  // if (udiv != 3) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %148 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %umod.10 = ALLOCA/LOCAL size=4 align=1
 *          %151 = UREM [%149, %150]  // 10u % 3u
 *     >> %umod.152 = MEMORY/STORE_LE_32 [%umod.10, %151]
 *          %156 = CMP_NE [%153, %155]  // umod != 1
 *     >> %157 = COND_BRANCH [%156]  // if (umod != 1) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %163 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %large.11 = ALLOCA/LOCAL size=4 align=1
 *          %164 = CONST/UINT32 4294967295  // 0xFFFFFFFF
 *     >> %large.165 = MEMORY/STORE_LE_32 [%large.11, %164]
 *          %168 = CMP_NE [%166, %167]  // large != 4294967295u
 *     >> %169 = COND_BRANCH [%168]  // if (large != 4294967295u) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %175 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %half.12 = ALLOCA/LOCAL size=4 align=1
 *          %179 = UDIV [%176, %178]  // large / 2
 *     >> %half.180 = MEMORY/STORE_LE_32 [%half.12, %179]
 *          %183 = CMP_NE [%181, %182]  // half != 2147483647u
 *     >> %184 = COND_BRANCH [%183]  // if (half != 2147483647u) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %190 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %shifted.13 = ALLOCA/LOCAL size=4 align=1
 *          %193 = SHL [%191, %192]  // 1u << 31
 *     >> %shifted.194 = MEMORY/STORE_LE_32 [%shifted.13, %193]
 *          %197 = CMP_NE [%195, %196]  // shifted != 2147483648u
 *     >> %198 = COND_BRANCH [%197]  // if (shifted != 2147483648u) return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %204 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *          %rshifted.14 = ALLOCA/LOCAL size=4 align=1
 *          %207 = USHR [%205, %206]  // shifted >> 1
 *     >> %rshifted.208 = MEMORY/STORE_LE_32 [%rshifted.14, %207]
 *          %211 = CMP_NE [%209, %210]  // rshifted != 1073741824u
 *     >> %212 = COND_BRANCH [%211]  // if (rshifted != 1073741824u) return 14
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %218 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *          %uval.15 = ALLOCA/LOCAL size=4 align=1
 *          %220 = CAST/IDENTITY [%219]  // 42
 *     >> %uval.221 = MEMORY/STORE_LE_32 [%uval.15, %220]
 *          %225 = CMP_NE [%222, %224]  // uval != 42
 *     >> %226 = COND_BRANCH [%225]  // if (uval != 42) return 15
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %232 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %234 = RETURN_PTR  // return 0
 *          %233 = CONST/INT32 0  // 0
 *     >> %235 = MEMORY/STORE_LE_32 [%234, %233]  // return 0
 *     >> %236 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %233 = CONST/INT32 0  // 0
 *     >> %237 = RET [%233]  // return 0
 *   block_44 IF_THEN  <- [block_43]:
 *          %228 = RETURN_PTR  // return 15
 *          %227 = CONST/INT32 15  // 15
 *     >> %229 = MEMORY/STORE_LE_32 [%228, %227]  // return 15
 *     >> %230 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %227 = CONST/INT32 15  // 15
 *     >> %231 = RET [%227]  // return 15
 *   block_41 IF_THEN  <- [block_40]:
 *          %214 = RETURN_PTR  // return 14
 *          %213 = CONST/INT32 14  // 14
 *     >> %215 = MEMORY/STORE_LE_32 [%214, %213]  // return 14
 *     >> %216 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %213 = CONST/INT32 14  // 14
 *     >> %217 = RET [%213]  // return 14
 *   block_38 IF_THEN  <- [block_37]:
 *          %200 = RETURN_PTR  // return 13
 *          %199 = CONST/INT32 13  // 13
 *     >> %201 = MEMORY/STORE_LE_32 [%200, %199]  // return 13
 *     >> %202 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %199 = CONST/INT32 13  // 13
 *     >> %203 = RET [%199]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %186 = RETURN_PTR  // return 12
 *          %185 = CONST/INT32 12  // 12
 *     >> %187 = MEMORY/STORE_LE_32 [%186, %185]  // return 12
 *     >> %188 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %185 = CONST/INT32 12  // 12
 *     >> %189 = RET [%185]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %171 = RETURN_PTR  // return 11
 *          %170 = CONST/INT32 11  // 11
 *     >> %172 = MEMORY/STORE_LE_32 [%171, %170]  // return 11
 *     >> %173 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %170 = CONST/INT32 11  // 11
 *     >> %174 = RET [%170]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %159 = RETURN_PTR  // return 10
 *          %158 = CONST/INT32 10  // 10
 *     >> %160 = MEMORY/STORE_LE_32 [%159, %158]  // return 10
 *     >> %161 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %158 = CONST/INT32 10  // 10
 *     >> %162 = RET [%158]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %144 = RETURN_PTR  // return 9
 *          %143 = CONST/INT32 9  // 9
 *     >> %145 = MEMORY/STORE_LE_32 [%144, %143]  // return 9
 *     >> %146 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %143 = CONST/INT32 9  // 9
 *     >> %147 = RET [%143]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %129 = RETURN_PTR  // return 8
 *          %128 = CONST/INT32 8  // 8
 *     >> %130 = MEMORY/STORE_LE_32 [%129, %128]  // return 8
 *     >> %131 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %128 = CONST/INT32 8  // 8
 *     >> %132 = RET [%128]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %111 = RETURN_PTR  // return 7
 *          %110 = CONST/INT32 7  // 7
 *     >> %112 = MEMORY/STORE_LE_32 [%111, %110]  // return 7
 *     >> %113 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %110 = CONST/INT32 7  // 7
 *     >> %114 = RET [%110]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %94 = RETURN_PTR  // return 6
 *          %93 = CONST/INT32 6  // 6
 *     >> %95 = MEMORY/STORE_LE_32 [%94, %93]  // return 6
 *     >> %96 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %93 = CONST/INT32 6  // 6
 *     >> %97 = RET [%93]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %80 = RETURN_PTR  // return 5
 *          %79 = CONST/INT32 5  // 5
 *     >> %81 = MEMORY/STORE_LE_32 [%80, %79]  // return 5
 *     >> %82 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %79 = CONST/INT32 5  // 5
 *     >> %83 = RET [%79]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %70 = RETURN_PTR  // return 4
 *          %69 = CONST/INT32 4  // 4
 *     >> %71 = MEMORY/STORE_LE_32 [%70, %69]  // return 4
 *     >> %72 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %69 = CONST/INT32 4  // 4
 *     >> %73 = RET [%69]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %60 = RETURN_PTR  // return 3
 *          %59 = CONST/INT32 3  // 3
 *     >> %61 = MEMORY/STORE_LE_32 [%60, %59]  // return 3
 *     >> %62 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %59 = CONST/INT32 3  // 3
 *     >> %63 = RET [%59]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %49 = RETURN_PTR  // return 2
 *          %48 = CONST/INT32 2  // 2
 *     >> %50 = MEMORY/STORE_LE_32 [%49, %48]  // return 2
 *     >> %51 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %48 = CONST/INT32 2  // 2
 *     >> %52 = RET [%48]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %34 = RETURN_PTR  // return 1
 *          %33 = CONST/INT32 1  // 1
 *     >> %35 = MEMORY/STORE_LE_32 [%34, %33]  // return 1
 *     >> %36 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %33 = CONST/INT32 1  // 1
 *     >> %37 = RET [%33]  // return 1
 * }
 */




int test_unsigned(void) {
    // Basic unsigned values.
    unsigned int ua = 200;
    unsigned int ub = 100;

    // Unsigned arithmetic.
    unsigned int sum = ua + ub;
    if (sum != 300) return 1;

    unsigned int diff = ua - ub;
    if (diff != 100) return 2;

    // Unsigned comparison.
    if (!(ua > ub)) return 3;
    if (ua < ub) return 4;
    if (ua == ub) return 5;

    // Unsigned wrap-around (underflow).
    unsigned int wrapped = 0u - 1u;
    if (wrapped != 4294967295u) return 6;

    // Unsigned char to unsigned int (zero extension).
    unsigned char uc = 200;
    unsigned int zext = uc;
    if (zext != 200) return 7;

    // Signed char to int (sign extension).
    signed char sc = -5;
    int sext = sc;
    if (sext != -5) return 8;

    // Unsigned division.
    unsigned int udiv = 10u / 3u;
    if (udiv != 3) return 9;

    // Unsigned modulo.
    unsigned int umod = 10u % 3u;
    if (umod != 1) return 10;

    // Large unsigned values.
    unsigned int large = 0xFFFFFFFF;
    if (large != 4294967295u) return 11;

    unsigned int half = large / 2;
    if (half != 2147483647u) return 12;

    // Unsigned shift.
    unsigned int shifted = 1u << 31;
    if (shifted != 2147483648u) return 13;

    unsigned int rshifted = shifted >> 1;
    if (rshifted != 1073741824u) return 14;

    // Mixing: unsigned compared to signed constant.
    unsigned int uval = 42;
    if (uval != 42) return 15;

    return 0;
}
