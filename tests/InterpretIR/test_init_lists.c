// Tests: aggregate initialization via InitListExpr decomposition —
// array init (PTR_ADD + STORE per element), struct init (GEP_FIELD + STORE),
// nested struct/array, partial initialization (MEMSET zeroes rest),
// designated initializers (.field = val), compound literals.

/*
 * Expected IR:
 *
 * function test_init_lists (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=16 align=1 (arr)
 *     obj_2 LOCAL_VALUE size=20 align=1 (partial)
 *     obj_3 LOCAL_VALUE size=8 align=1 (s)
 *     obj_4 LOCAL_VALUE size=12 align=1 (o)
 *     obj_5 LOCAL_VALUE size=8 align=1 (d)
 *     obj_6 LOCAL_VALUE size=8 align=1 (cl)
 *     obj_7 LOCAL_VALUE size=12 align=1 (z)
 *     obj_8 COMPOUND_LITERAL size=8 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %7 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %8 = ENTER_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %arr.0 = ALLOCA/LOCAL size=16 align=1
 *          %arr.9 = CONST/UINT8 0
 *          %arr.10 = CONST/UINT64 16
 *     >> %arr.11 = MEMORY/MEMSET [%arr.0, %arr.9, %arr.10]
 *          %arr.0 = ALLOCA/LOCAL size=16 align=1
 *          %12 = CONST/INT32 10  // 10
 *     >> %arr.13 = MEMORY/STORE_LE_32 [%arr.0, %12]
 *          %arr.15 = PTR_ADD elem_size=4 [%arr.0, %arr.14]
 *          %16 = CONST/INT32 20  // 20
 *     >> %arr.17 = MEMORY/STORE_LE_32 [%arr.15, %16]
 *          %arr.19 = PTR_ADD elem_size=4 [%arr.0, %arr.18]
 *          %20 = CONST/INT32 30  // 30
 *     >> %arr.21 = MEMORY/STORE_LE_32 [%arr.19, %20]
 *          %arr.23 = PTR_ADD elem_size=4 [%arr.0, %arr.22]
 *          %24 = CONST/INT32 40  // 40
 *     >> %arr.25 = MEMORY/STORE_LE_32 [%arr.23, %24]
 *          %30 = CMP_NE [%28, %29]  // arr[0] != 10
 *     >> %31 = COND_BRANCH [%30]  // if (arr[0] != 10) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %37 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %42 = CMP_NE [%40, %41]  // arr[3] != 40
 *     >> %43 = COND_BRANCH [%42]  // if (arr[3] != 40) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %49 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %partial.1 = ALLOCA/LOCAL size=20 align=1
 *          %partial.50 = CONST/UINT8 0
 *          %partial.51 = CONST/UINT64 20
 *     >> %partial.52 = MEMORY/MEMSET [%partial.1, %partial.50, %partial.51]
 *          %partial.1 = ALLOCA/LOCAL size=20 align=1
 *          %53 = CONST/INT32 1  // 1
 *     >> %partial.54 = MEMORY/STORE_LE_32 [%partial.1, %53]
 *          %partial.56 = PTR_ADD elem_size=4 [%partial.1, %partial.55]
 *          %57 = CONST/INT32 2  // 2
 *     >> %partial.58 = MEMORY/STORE_LE_32 [%partial.56, %57]
 *          %63 = CMP_NE [%61, %62]  // partial[0] != 1
 *     >> %64 = COND_BRANCH [%63]  // if (partial[0] != 1) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %70 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %75 = CMP_NE [%73, %74]  // partial[1] != 2
 *     >> %76 = COND_BRANCH [%75]  // if (partial[1] != 2) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %82 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %87 = CMP_NE [%85, %86]  // partial[2] != 0
 *     >> %88 = COND_BRANCH [%87]  // if (partial[2] != 0) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %94 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %99 = CMP_NE [%97, %98]  // partial[4] != 0
 *     >> %100 = COND_BRANCH [%99]  // if (partial[4] != 0) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %106 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %s.2 = ALLOCA/LOCAL size=8 align=1
 *          %s.107 = CONST/UINT8 0
 *          %s.108 = CONST/UINT64 8
 *     >> %s.109 = MEMORY/MEMSET [%s.2, %s.107, %s.108]
 *          %s.110 = GEP_FIELD offset=0 .a [%s.2]
 *          %111 = CONST/INT32 100  // 100
 *     >> %s.112 = MEMORY/STORE_LE_32 [%s.110, %111]
 *          %s.113 = GEP_FIELD offset=4 .b [%s.2]
 *          %114 = CONST/INT32 200  // 200
 *     >> %s.115 = MEMORY/STORE_LE_32 [%s.113, %114]
 *          %119 = CMP_NE [%117, %118]  // s.a != 100
 *     >> %120 = COND_BRANCH [%119]  // if (s.a != 100) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %126 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %130 = CMP_NE [%128, %129]  // s.b != 200
 *     >> %131 = COND_BRANCH [%130]  // if (s.b != 200) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %137 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %o.3 = ALLOCA/LOCAL size=12 align=1
 *          %o.138 = CONST/UINT8 0
 *          %o.139 = CONST/UINT64 12
 *     >> %o.140 = MEMORY/MEMSET [%o.3, %o.138, %o.139]
 *          %o.141 = GEP_FIELD offset=0 .inner [%o.3]
 *          %o.142 = CONST/UINT8 0
 *          %o.143 = CONST/UINT64 8
 *     >> %o.144 = MEMORY/MEMSET [%o.141, %o.142, %o.143]
 *          %o.145 = GEP_FIELD offset=0 .a [%o.141]
 *          %146 = CONST/INT32 5  // 5
 *     >> %o.147 = MEMORY/STORE_LE_32 [%o.145, %146]
 *          %o.148 = GEP_FIELD offset=4 .b [%o.141]
 *          %149 = CONST/INT32 6  // 6
 *     >> %o.150 = MEMORY/STORE_LE_32 [%o.148, %149]
 *          %o.151 = GEP_FIELD offset=8 .c [%o.3]
 *          %152 = CONST/INT32 7  // 7
 *     >> %o.153 = MEMORY/STORE_LE_32 [%o.151, %152]
 *          %158 = CMP_NE [%156, %157]  // o.inner.a != 5
 *     >> %159 = COND_BRANCH [%158]  // if (o.inner.a != 5) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %165 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %170 = CMP_NE [%168, %169]  // o.inner.b != 6
 *     >> %171 = COND_BRANCH [%170]  // if (o.inner.b != 6) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %177 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %181 = CMP_NE [%179, %180]  // o.c != 7
 *     >> %182 = COND_BRANCH [%181]  // if (o.c != 7) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %188 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %d.4 = ALLOCA/LOCAL size=8 align=1
 *          %d.189 = CONST/UINT8 0
 *          %d.190 = CONST/UINT64 8
 *     >> %d.191 = MEMORY/MEMSET [%d.4, %d.189, %d.190]
 *          %d.192 = GEP_FIELD offset=0 .a [%d.4]
 *          %193 = CONST/INT32 10  // 10
 *     >> %d.194 = MEMORY/STORE_LE_32 [%d.192, %193]
 *          %d.195 = GEP_FIELD offset=4 .b [%d.4]
 *          %196 = CONST/INT32 42  // 42
 *     >> %d.197 = MEMORY/STORE_LE_32 [%d.195, %196]
 *          %201 = CMP_NE [%199, %200]  // d.a != 10
 *     >> %202 = COND_BRANCH [%201]  // if (d.a != 10) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %208 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %212 = CMP_NE [%210, %211]  // d.b != 42
 *     >> %213 = COND_BRANCH [%212]  // if (d.b != 42) return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %219 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *          %220 = ALLOCA/LOCAL size=8 align=1  // (struct Inner){99, 88}
 *          %221 = CONST/UINT8 0  // (struct Inner){99, 88}
 *          %222 = CONST/UINT64 8  // (struct Inner){99, 88}
 *     >> %223 = MEMORY/MEMSET [%220, %221, %222]  // (struct Inner){99, 88}
 *          %224 = GEP_FIELD offset=0 .a [%220]  // (struct Inner){99, 88}
 *          %225 = CONST/INT32 99  // 99
 *     >> %226 = MEMORY/STORE_LE_32 [%224, %225]  // (struct Inner){99, 88}
 *          %227 = GEP_FIELD offset=4 .b [%220]  // (struct Inner){99, 88}
 *          %228 = CONST/INT32 88  // 88
 *     >> %229 = MEMORY/STORE_LE_32 [%227, %228]  // (struct Inner){99, 88}
 *          %cl.5 = ALLOCA/LOCAL size=8 align=1
 *          %230 = MEMORY/LOAD_LE_64 [%220]  // (struct Inner){99, 88}
 *     >> %cl.231 = MEMORY/STORE_LE_64 [%cl.5, %230]
 *          %235 = CMP_NE [%233, %234]  // cl.a != 99
 *     >> %236 = COND_BRANCH [%235]  // if (cl.a != 99) return 14
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %242 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *          %246 = CMP_NE [%244, %245]  // cl.b != 88
 *     >> %247 = COND_BRANCH [%246]  // if (cl.b != 88) return 15
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %253 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %z.6 = ALLOCA/LOCAL size=12 align=1
 *          %z.254 = CONST/UINT8 0
 *          %z.255 = CONST/UINT64 12
 *     >> %z.256 = MEMORY/MEMSET [%z.6, %z.254, %z.255]
 *          %z.257 = GEP_FIELD offset=0 .inner [%z.6]
 *          %z.258 = CONST/UINT8 0
 *          %z.259 = CONST/UINT64 8
 *     >> %z.260 = MEMORY/MEMSET [%z.257, %z.258, %z.259]
 *          %z.261 = GEP_FIELD offset=0 .a [%z.257]
 *          %262 = CONST/INT32 0  // 0
 *     >> %z.263 = MEMORY/STORE_LE_32 [%z.261, %262]
 *          %z.264 = GEP_FIELD offset=4 .b [%z.257]
 *          %265 = CONST/INT64 0
 *     >> %z.266 = MEMORY/STORE_LE_32 [%z.264, %265]
 *          %z.267 = GEP_FIELD offset=8 .c [%z.6]
 *          %268 = CONST/INT64 0
 *     >> %z.269 = MEMORY/STORE_LE_32 [%z.267, %268]
 *          %274 = CMP_NE [%272, %273]  // z.inner.a != 0
 *     >> %275 = COND_BRANCH [%274]  // if (z.inner.a != 0) return 16
 *     -> [block_47, block_48]
 *   block_48 IF_ELSE  <- [block_46]:
 *     >> %281 = IMPLICIT_GOTO
 *     -> [block_49]
 *   block_49 IF_MERGE  <- [block_48]:
 *          %285 = CMP_NE [%283, %284]  // z.c != 0
 *     >> %286 = COND_BRANCH [%285]  // if (z.c != 0) return 17
 *     -> [block_50, block_51]
 *   block_51 IF_ELSE  <- [block_49]:
 *     >> %292 = IMPLICIT_GOTO
 *     -> [block_52]
 *   block_52 IF_MERGE  <- [block_51]:
 *          %294 = RETURN_PTR  // return 0
 *          %293 = CONST/INT32 0  // 0
 *     >> %295 = MEMORY/STORE_LE_32 [%294, %293]  // return 0
 *     >> %296 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %293 = CONST/INT32 0  // 0
 *     >> %297 = RET [%293]  // return 0
 *   block_50 IF_THEN  <- [block_49]:
 *          %288 = RETURN_PTR  // return 17
 *          %287 = CONST/INT32 17  // 17
 *     >> %289 = MEMORY/STORE_LE_32 [%288, %287]  // return 17
 *     >> %290 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %287 = CONST/INT32 17  // 17
 *     >> %291 = RET [%287]  // return 17
 *   block_47 IF_THEN  <- [block_46]:
 *          %277 = RETURN_PTR  // return 16
 *          %276 = CONST/INT32 16  // 16
 *     >> %278 = MEMORY/STORE_LE_32 [%277, %276]  // return 16
 *     >> %279 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %276 = CONST/INT32 16  // 16
 *     >> %280 = RET [%276]  // return 16
 *   block_44 IF_THEN  <- [block_43]:
 *          %249 = RETURN_PTR  // return 15
 *          %248 = CONST/INT32 15  // 15
 *     >> %250 = MEMORY/STORE_LE_32 [%249, %248]  // return 15
 *     >> %251 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %248 = CONST/INT32 15  // 15
 *     >> %252 = RET [%248]  // return 15
 *   block_41 IF_THEN  <- [block_40]:
 *          %238 = RETURN_PTR  // return 14
 *          %237 = CONST/INT32 14  // 14
 *     >> %239 = MEMORY/STORE_LE_32 [%238, %237]  // return 14
 *     >> %240 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %237 = CONST/INT32 14  // 14
 *     >> %241 = RET [%237]  // return 14
 *   block_38 IF_THEN  <- [block_37]:
 *          %215 = RETURN_PTR  // return 13
 *          %214 = CONST/INT32 13  // 13
 *     >> %216 = MEMORY/STORE_LE_32 [%215, %214]  // return 13
 *     >> %217 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %214 = CONST/INT32 13  // 13
 *     >> %218 = RET [%214]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %204 = RETURN_PTR  // return 12
 *          %203 = CONST/INT32 12  // 12
 *     >> %205 = MEMORY/STORE_LE_32 [%204, %203]  // return 12
 *     >> %206 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %203 = CONST/INT32 12  // 12
 *     >> %207 = RET [%203]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %184 = RETURN_PTR  // return 11
 *          %183 = CONST/INT32 11  // 11
 *     >> %185 = MEMORY/STORE_LE_32 [%184, %183]  // return 11
 *     >> %186 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %183 = CONST/INT32 11  // 11
 *     >> %187 = RET [%183]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %173 = RETURN_PTR  // return 10
 *          %172 = CONST/INT32 10  // 10
 *     >> %174 = MEMORY/STORE_LE_32 [%173, %172]  // return 10
 *     >> %175 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %172 = CONST/INT32 10  // 10
 *     >> %176 = RET [%172]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %161 = RETURN_PTR  // return 9
 *          %160 = CONST/INT32 9  // 9
 *     >> %162 = MEMORY/STORE_LE_32 [%161, %160]  // return 9
 *     >> %163 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %160 = CONST/INT32 9  // 9
 *     >> %164 = RET [%160]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %133 = RETURN_PTR  // return 8
 *          %132 = CONST/INT32 8  // 8
 *     >> %134 = MEMORY/STORE_LE_32 [%133, %132]  // return 8
 *     >> %135 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %132 = CONST/INT32 8  // 8
 *     >> %136 = RET [%132]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %122 = RETURN_PTR  // return 7
 *          %121 = CONST/INT32 7  // 7
 *     >> %123 = MEMORY/STORE_LE_32 [%122, %121]  // return 7
 *     >> %124 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %121 = CONST/INT32 7  // 7
 *     >> %125 = RET [%121]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %102 = RETURN_PTR  // return 6
 *          %101 = CONST/INT32 6  // 6
 *     >> %103 = MEMORY/STORE_LE_32 [%102, %101]  // return 6
 *     >> %104 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %101 = CONST/INT32 6  // 6
 *     >> %105 = RET [%101]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %90 = RETURN_PTR  // return 5
 *          %89 = CONST/INT32 5  // 5
 *     >> %91 = MEMORY/STORE_LE_32 [%90, %89]  // return 5
 *     >> %92 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %89 = CONST/INT32 5  // 5
 *     >> %93 = RET [%89]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %78 = RETURN_PTR  // return 4
 *          %77 = CONST/INT32 4  // 4
 *     >> %79 = MEMORY/STORE_LE_32 [%78, %77]  // return 4
 *     >> %80 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %77 = CONST/INT32 4  // 4
 *     >> %81 = RET [%77]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %66 = RETURN_PTR  // return 3
 *          %65 = CONST/INT32 3  // 3
 *     >> %67 = MEMORY/STORE_LE_32 [%66, %65]  // return 3
 *     >> %68 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %65 = CONST/INT32 3  // 3
 *     >> %69 = RET [%65]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %45 = RETURN_PTR  // return 2
 *          %44 = CONST/INT32 2  // 2
 *     >> %46 = MEMORY/STORE_LE_32 [%45, %44]  // return 2
 *     >> %47 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %44 = CONST/INT32 2  // 2
 *     >> %48 = RET [%44]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %33 = RETURN_PTR  // return 1
 *          %32 = CONST/INT32 1  // 1
 *     >> %34 = MEMORY/STORE_LE_32 [%33, %32]  // return 1
 *     >> %35 = EXIT_SCOPE  // {     // Array initialization.     int arr[4] =...
 *          %32 = CONST/INT32 1  // 1
 *     >> %36 = RET [%32]  // return 1
 * }
 */

struct Inner {
    int a;
    int b;
};

struct Outer {
    struct Inner inner;
    int c;
};

int test_init_lists(void) {
    // Array initialization.
    int arr[4] = {10, 20, 30, 40};
    if (arr[0] != 10) return 1;
    if (arr[3] != 40) return 2;

    // Partial init (rest zeroed).
    int partial[5] = {1, 2};
    if (partial[0] != 1) return 3;
    if (partial[1] != 2) return 4;
    if (partial[2] != 0) return 5;
    if (partial[4] != 0) return 6;

    // Struct initialization.
    struct Inner s = {100, 200};
    if (s.a != 100) return 7;
    if (s.b != 200) return 8;

    // Nested struct.
    struct Outer o = {{5, 6}, 7};
    if (o.inner.a != 5) return 9;
    if (o.inner.b != 6) return 10;
    if (o.c != 7) return 11;

    // Designated initializer.
    struct Inner d = {.b = 42, .a = 10};
    if (d.a != 10) return 12;
    if (d.b != 42) return 13;

    // Compound literal.
    struct Inner cl = (struct Inner){99, 88};
    if (cl.a != 99) return 14;
    if (cl.b != 88) return 15;

    // Zero initialization.
    struct Outer z = {0};
    if (z.inner.a != 0) return 16;
    if (z.c != 0) return 17;

    return 0;
}
