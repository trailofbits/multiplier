// Tests: by-value struct parameters and returns, exercising the full
// EXPRESSION_SCOPE → ALLOCA/ARG → PARAM_PTR → RETURN_PTR → ALLOCA/RETURN
// chain for both small (≤8 byte) and large (>8 byte) structs.

/*
 * Expected IR:
 *
 * function test_byvalue (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=8 align=1 (s)
 *     obj_2 LOCAL_VALUE size=4 align=1 (sum)
 *     obj_3 LOCAL_VALUE size=20 align=1 (l)
 *     obj_4 LOCAL_VALUE size=4 align=1 (lsum)
 *     obj_5 LOCAL_VALUE size=3 align=1 (p)
 *     obj_6 LOCAL_VALUE size=4 align=1 (psum)
 *     obj_7 LOCAL_VALUE size=8 align=1 (s2)
 *     obj_8 LOCAL_VALUE size=4 align=1 (chained)
 *     obj_9 LOCAL_VALUE size=4 align=1 (nested)
 *     obj_10 PARAMETER size=4 align=1
 *     obj_11 PARAMETER size=4 align=1
 *     obj_12 RETURN_SLOT size=8 align=1
 *     obj_13 PARAMETER size=8 align=1
 *     obj_14 RETURN_SLOT size=4 align=1
 *     obj_15 PARAMETER size=4 align=1
 *     obj_16 RETURN_SLOT size=20 align=1
 *     obj_17 PARAMETER size=20 align=1
 *     obj_18 RETURN_SLOT size=4 align=1
 *     obj_19 PARAMETER size=3 align=1
 *     obj_20 RETURN_SLOT size=4 align=1
 *     obj_21 PARAMETER size=8 align=1
 *     obj_22 RETURN_SLOT size=8 align=1
 *     obj_23 PARAMETER size=4 align=1
 *     obj_24 PARAMETER size=4 align=1
 *     obj_25 RETURN_SLOT size=4 align=1
 *     obj_26 PARAMETER size=4 align=1
 *     obj_27 PARAMETER size=4 align=1
 *     obj_28 RETURN_SLOT size=8 align=1
 *     obj_29 PARAMETER size=8 align=1
 *     obj_30 RETURN_SLOT size=4 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %9 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %10 = ENTER_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %11 = ENTER_SCOPE  // make_small(10, 20)
 *          %13 = ALLOCA/ARG size=4 align=1  // 10
 *          %12 = CONST/INT32 10  // 10
 *     >> %14 = MEMORY/STORE_LE_32 [%13, %12]  // 10
 *          %16 = ALLOCA/ARG size=4 align=1  // 20
 *          %15 = CONST/INT32 20  // 20
 *     >> %17 = MEMORY/STORE_LE_32 [%16, %15]  // 20
 *          %s.0 = ALLOCA/LOCAL size=8 align=1
 *          %19 = CALL @make_small [%13, %16]  // make_small(10, 20)
 *     >> %s.20 = MEMORY/STORE_LE_64 [%s.0, %19]
 *     >> %25 = EXIT_SCOPE
 *          %24 = CMP_NE [%22, %23]  // s.x != 10
 *     >> %26 = COND_BRANCH [%24]  // if (s.x != 10) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %33 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %37 = CMP_NE [%35, %36]  // s.y != 20
 *     >> %38 = COND_BRANCH [%37]  // if (s.y != 20) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %44 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *     >> %45 = ENTER_SCOPE  // sum_small(s)
 *          %47 = ALLOCA/ARG size=8 align=1  // s
 *          %46 = MEMORY/LOAD_LE_64 [%s.0]  // s
 *     >> %48 = MEMORY/STORE_LE_64 [%47, %46]  // s
 *          %sum.1 = ALLOCA/LOCAL size=4 align=1
 *          %50 = CALL @sum_small [%47]  // sum_small(s)
 *     >> %sum.51 = MEMORY/STORE_LE_32 [%sum.1, %50]
 *     >> %55 = EXIT_SCOPE
 *          %54 = CMP_NE [%52, %53]  // sum != 30
 *     >> %56 = COND_BRANCH [%54]  // if (sum != 30) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %63 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *     >> %64 = ENTER_SCOPE  // make_large(100)
 *          %66 = ALLOCA/ARG size=4 align=1  // 100
 *          %65 = CONST/INT32 100  // 100
 *     >> %67 = MEMORY/STORE_LE_32 [%66, %65]  // 100
 *          %l.2 = ALLOCA/LOCAL size=20 align=1
 *          %69 = CALL @make_large [%66]  // make_large(100)
 *          %70 = CONST/UINT64 20
 *     >> %l.71 = MEMORY/MEMCPY [%l.2, %69, %70]
 *     >> %76 = EXIT_SCOPE
 *          %75 = CMP_NE [%73, %74]  // l.a != 100
 *     >> %77 = COND_BRANCH [%75]  // if (l.a != 100) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %84 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %88 = CMP_NE [%86, %87]  // l.e != 104
 *     >> %89 = COND_BRANCH [%88]  // if (l.e != 104) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %95 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *     >> %96 = ENTER_SCOPE  // sum_large(l)
 *          %97 = ALLOCA/ARG size=20 align=1  // l
 *          %l.2 = ALLOCA/LOCAL size=20 align=1
 *          %98 = CONST/UINT64 20
 *     >> %99 = MEMORY/MEMCPY [%97, %l.2, %98]  // l
 *          %lsum.3 = ALLOCA/LOCAL size=4 align=1
 *          %101 = CALL @sum_large [%97]  // sum_large(l)
 *     >> %lsum.102 = MEMORY/STORE_LE_32 [%lsum.3, %101]
 *     >> %106 = EXIT_SCOPE
 *          %105 = CMP_NE [%103, %104]  // lsum != 510
 *     >> %107 = COND_BRANCH [%105]  // if (lsum != 510) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %114 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %115 = GEP_FIELD offset=0 .a [%p.4]  // p.a
 *          %117 = CAST/TRUNC_I32_I8 [%116]  // 1
 *     >> %118 = MEMORY/STORE_LE_8 [%115, %117]  // p.a = 1
 *          %119 = GEP_FIELD offset=1 .b [%p.4]  // p.b
 *          %121 = CAST/TRUNC_I32_I8 [%120]  // 2
 *     >> %122 = MEMORY/STORE_LE_8 [%119, %121]  // p.b = 2
 *          %123 = GEP_FIELD offset=2 .c [%p.4]  // p.c
 *          %125 = CAST/TRUNC_I32_I8 [%124]  // 3
 *     >> %126 = MEMORY/STORE_LE_8 [%123, %125]  // p.c = 3
 *     >> %127 = ENTER_SCOPE  // sum_packed3(p)
 *          %128 = ALLOCA/ARG size=3 align=1  // p
 *          %p.4 = ALLOCA/LOCAL size=3 align=1
 *          %129 = CONST/UINT64 3
 *     >> %130 = MEMORY/MEMCPY [%128, %p.4, %129]  // p
 *          %psum.5 = ALLOCA/LOCAL size=4 align=1
 *          %132 = CALL @sum_packed3 [%128]  // sum_packed3(p)
 *     >> %psum.133 = MEMORY/STORE_LE_32 [%psum.5, %132]
 *     >> %137 = EXIT_SCOPE
 *          %136 = CMP_NE [%134, %135]  // psum != 6
 *     >> %138 = COND_BRANCH [%136]  // if (psum != 6) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %145 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *     >> %146 = ENTER_SCOPE  // identity_small(s)
 *          %148 = ALLOCA/ARG size=8 align=1  // s
 *          %147 = MEMORY/LOAD_LE_64 [%s.0]  // s
 *     >> %149 = MEMORY/STORE_LE_64 [%148, %147]  // s
 *          %s2.6 = ALLOCA/LOCAL size=8 align=1
 *          %151 = CALL @identity_small [%148]  // identity_small(s)
 *     >> %s2.152 = MEMORY/STORE_LE_64 [%s2.6, %151]
 *     >> %157 = EXIT_SCOPE
 *          %156 = CMP_NE [%154, %155]  // s2.x != 10
 *     >> %158 = COND_BRANCH [%156]  // if (s2.x != 10) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %165 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %169 = CMP_NE [%167, %168]  // s2.y != 20
 *     >> %170 = COND_BRANCH [%169]  // if (s2.y != 20) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %176 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *     >> %177 = ENTER_SCOPE  // chain_test(5, 15)
 *          %179 = ALLOCA/ARG size=4 align=1  // 5
 *          %178 = CONST/INT32 5  // 5
 *     >> %180 = MEMORY/STORE_LE_32 [%179, %178]  // 5
 *          %182 = ALLOCA/ARG size=4 align=1  // 15
 *          %181 = CONST/INT32 15  // 15
 *     >> %183 = MEMORY/STORE_LE_32 [%182, %181]  // 15
 *          %chained.7 = ALLOCA/LOCAL size=4 align=1
 *          %185 = CALL @chain_test [%179, %182]  // chain_test(5, 15)
 *     >> %chained.186 = MEMORY/STORE_LE_32 [%chained.7, %185]
 *     >> %190 = EXIT_SCOPE
 *          %189 = CMP_NE [%187, %188]  // chained != 20
 *     >> %191 = COND_BRANCH [%189]  // if (chained != 20) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %198 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *     >> %199 = ENTER_SCOPE  // sum_small(make_small(1, 2))
 *          %201 = ALLOCA/ARG size=4 align=1  // 1
 *          %200 = CONST/INT32 1  // 1
 *     >> %202 = MEMORY/STORE_LE_32 [%201, %200]  // 1
 *          %204 = ALLOCA/ARG size=4 align=1  // 2
 *          %203 = CONST/INT32 2  // 2
 *     >> %205 = MEMORY/STORE_LE_32 [%204, %203]  // 2
 *          %208 = ALLOCA/ARG size=8 align=1  // make_small(1, 2)
 *          %207 = CALL @make_small [%201, %204]  // make_small(1, 2)
 *     >> %209 = MEMORY/STORE_LE_64 [%208, %207]  // make_small(1, 2)
 *          %nested.8 = ALLOCA/LOCAL size=4 align=1
 *          %211 = CALL @sum_small [%208]  // sum_small(make_small(1, 2))
 *     >> %nested.212 = MEMORY/STORE_LE_32 [%nested.8, %211]
 *     >> %216 = EXIT_SCOPE
 *          %215 = CMP_NE [%213, %214]  // nested != 3
 *     >> %217 = COND_BRANCH [%215]  // if (nested != 3) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %224 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %226 = RETURN_PTR  // return 0
 *          %225 = CONST/INT32 0  // 0
 *     >> %227 = MEMORY/STORE_LE_32 [%226, %225]  // return 0
 *     >> %228 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %225 = CONST/INT32 0  // 0
 *     >> %229 = RET [%225]  // return 0
 *   block_32 IF_THEN  <- [block_31]:
 *          %219 = RETURN_PTR  // return 11
 *          %218 = CONST/INT32 11  // 11
 *     >> %220 = MEMORY/STORE_LE_32 [%219, %218]  // return 11
 *     >> %221 = EXIT_SCOPE  // sum_small(make_small(1, 2))
 *     >> %222 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %218 = CONST/INT32 11  // 11
 *     >> %223 = RET [%218]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %193 = RETURN_PTR  // return 10
 *          %192 = CONST/INT32 10  // 10
 *     >> %194 = MEMORY/STORE_LE_32 [%193, %192]  // return 10
 *     >> %195 = EXIT_SCOPE  // chain_test(5, 15)
 *     >> %196 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %192 = CONST/INT32 10  // 10
 *     >> %197 = RET [%192]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %172 = RETURN_PTR  // return 9
 *          %171 = CONST/INT32 9  // 9
 *     >> %173 = MEMORY/STORE_LE_32 [%172, %171]  // return 9
 *     >> %174 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %171 = CONST/INT32 9  // 9
 *     >> %175 = RET [%171]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %160 = RETURN_PTR  // return 8
 *          %159 = CONST/INT32 8  // 8
 *     >> %161 = MEMORY/STORE_LE_32 [%160, %159]  // return 8
 *     >> %162 = EXIT_SCOPE  // identity_small(s)
 *     >> %163 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %159 = CONST/INT32 8  // 8
 *     >> %164 = RET [%159]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %140 = RETURN_PTR  // return 7
 *          %139 = CONST/INT32 7  // 7
 *     >> %141 = MEMORY/STORE_LE_32 [%140, %139]  // return 7
 *     >> %142 = EXIT_SCOPE  // sum_packed3(p)
 *     >> %143 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %139 = CONST/INT32 7  // 7
 *     >> %144 = RET [%139]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %109 = RETURN_PTR  // return 6
 *          %108 = CONST/INT32 6  // 6
 *     >> %110 = MEMORY/STORE_LE_32 [%109, %108]  // return 6
 *     >> %111 = EXIT_SCOPE  // sum_large(l)
 *     >> %112 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %108 = CONST/INT32 6  // 6
 *     >> %113 = RET [%108]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %91 = RETURN_PTR  // return 5
 *          %90 = CONST/INT32 5  // 5
 *     >> %92 = MEMORY/STORE_LE_32 [%91, %90]  // return 5
 *     >> %93 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %90 = CONST/INT32 5  // 5
 *     >> %94 = RET [%90]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %79 = RETURN_PTR  // return 4
 *          %78 = CONST/INT32 4  // 4
 *     >> %80 = MEMORY/STORE_LE_32 [%79, %78]  // return 4
 *     >> %81 = EXIT_SCOPE  // make_large(100)
 *     >> %82 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %78 = CONST/INT32 4  // 4
 *     >> %83 = RET [%78]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %58 = RETURN_PTR  // return 3
 *          %57 = CONST/INT32 3  // 3
 *     >> %59 = MEMORY/STORE_LE_32 [%58, %57]  // return 3
 *     >> %60 = EXIT_SCOPE  // sum_small(s)
 *     >> %61 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %57 = CONST/INT32 3  // 3
 *     >> %62 = RET [%57]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %40 = RETURN_PTR  // return 2
 *          %39 = CONST/INT32 2  // 2
 *     >> %41 = MEMORY/STORE_LE_32 [%40, %39]  // return 2
 *     >> %42 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %39 = CONST/INT32 2  // 2
 *     >> %43 = RET [%39]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %28 = RETURN_PTR  // return 1
 *          %27 = CONST/INT32 1  // 1
 *     >> %29 = MEMORY/STORE_LE_32 [%28, %27]  // return 1
 *     >> %30 = EXIT_SCOPE  // make_small(10, 20)
 *     >> %31 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *          %27 = CONST/INT32 1  // 1
 *     >> %32 = RET [%27]  // return 1
 * }
 */




struct Small {
    int x;
    int y;
};

struct Large {
    int a, b, c, d, e;  // 20 bytes
};

struct Packed3 {
    char a, b, c;  // 3 bytes — non-power-of-2, must use MEMCPY
};

// Return a small struct by value.
static struct Small make_small(int x, int y) {
    struct Small s;
    s.x = x;
    s.y = y;
    return s;
}

// Return a large struct by value.
static struct Large make_large(int base) {
    struct Large l;
    l.a = base;
    l.b = base + 1;
    l.c = base + 2;
    l.d = base + 3;
    l.e = base + 4;
    return l;
}

// Take a small struct by value, return sum.
static int sum_small(struct Small s) {
    return s.x + s.y;
}

// Take a large struct by value, return sum.
static int sum_large(struct Large l) {
    return l.a + l.b + l.c + l.d + l.e;
}

// Take a 3-byte struct by value.
static int sum_packed3(struct Packed3 p) {
    return p.a + p.b + p.c;
}

// Pass struct through: take by value, return by value.
static struct Small identity_small(struct Small s) {
    return s;
}

// Chain: make → pass → sum.
static int chain_test(int x, int y) {
    struct Small s = make_small(x, y);
    return sum_small(s);
}

int test_byvalue(void) {
    // Small struct return.
    struct Small s = make_small(10, 20);
    if (s.x != 10) return 1;
    if (s.y != 20) return 2;

    // Small struct parameter.
    int sum = sum_small(s);
    if (sum != 30) return 3;

    // Large struct return.
    struct Large l = make_large(100);
    if (l.a != 100) return 4;
    if (l.e != 104) return 5;

    // Large struct parameter.
    int lsum = sum_large(l);
    if (lsum != 510) return 6;

    // Non-power-of-2 struct.
    struct Packed3 p;
    p.a = 1;
    p.b = 2;
    p.c = 3;
    int psum = sum_packed3(p);
    if (psum != 6) return 7;

    // Pass-through (param → return).
    struct Small s2 = identity_small(s);
    if (s2.x != 10) return 8;
    if (s2.y != 20) return 9;

    // Chained calls.
    int chained = chain_test(5, 15);
    if (chained != 20) return 10;

    // Nested call in expression: sum_small(make_small(1, 2)).
    int nested = sum_small(make_small(1, 2));
    if (nested != 3) return 11;

    return 0;
}
