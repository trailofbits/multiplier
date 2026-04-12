// Tests: by-value struct parameters and returns, exercising the full
// EXPRESSION_SCOPE → ALLOCA/ARG → PARAM_PTR → RETURN_PTR → ALLOCA/RETURN
// chain for both small (≤8 byte) and large (>8 byte) structs.

/*
 * Expected IR:
 *
 * function test_byvalue (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=8 align=4 (s)
 *     obj_1 LOCAL_VALUE size=4 align=4 (sum)
 *     obj_2 LOCAL_VALUE size=20 align=4 (l)
 *     obj_3 LOCAL_VALUE size=4 align=4 (lsum)
 *     obj_4 LOCAL_VALUE size=3 align=1 (p)
 *     obj_5 LOCAL_VALUE size=4 align=4 (psum)
 *     obj_6 LOCAL_VALUE size=8 align=4 (s2)
 *     obj_7 LOCAL_VALUE size=4 align=4 (chained)
 *     obj_8 LOCAL_VALUE size=4 align=4 (nested)
 *     obj_9 PARAMETER size=4 align=4
 *     obj_10 PARAMETER size=4 align=4
 *     obj_11 RETURN_SLOT size=8 align=4
 *     obj_12 PARAMETER size=8 align=4
 *     obj_13 RETURN_SLOT size=4 align=4
 *     obj_14 PARAMETER size=4 align=4
 *     obj_15 RETURN_SLOT size=20 align=4
 *     obj_16 PARAMETER size=20 align=4
 *     obj_17 RETURN_SLOT size=4 align=4
 *     obj_18 PARAMETER size=3 align=1
 *     obj_19 RETURN_SLOT size=4 align=4
 *     obj_20 PARAMETER size=8 align=4
 *     obj_21 RETURN_SLOT size=8 align=4
 *     obj_22 PARAMETER size=4 align=4
 *     obj_23 PARAMETER size=4 align=4
 *     obj_24 RETURN_SLOT size=4 align=4
 *     obj_25 PARAMETER size=4 align=4
 *     obj_26 PARAMETER size=4 align=4
 *     obj_27 RETURN_SLOT size=8 align=4
 *     obj_28 PARAMETER size=8 align=4
 *     obj_29 RETURN_SLOT size=4 align=4
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %s.0 = ALLOCA/LOCAL size=8 align=4
 *     >> %sum.1 = ALLOCA/LOCAL size=4 align=4
 *     >> %l.2 = ALLOCA/LOCAL size=20 align=4
 *     >> %lsum.3 = ALLOCA/LOCAL size=4 align=4
 *     >> %p.4 = ALLOCA/LOCAL size=3 align=1
 *     >> %psum.5 = ALLOCA/LOCAL size=4 align=4
 *     >> %s2.6 = ALLOCA/LOCAL size=8 align=4
 *     >> %chained.7 = ALLOCA/LOCAL size=4 align=4
 *     >> %nested.8 = ALLOCA/LOCAL size=4 align=4
 *     >> %9 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %10 = ENTER_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %11 = ENTER_SCOPE  // make_small(10, 20)
 *          %13 = ALLOCA/ARG size=4 align=4  // 10
 *          %12 = CONST/INT32 10  // 10
 *     >> %14 = MEMORY/STORE_LE_32 [%13, %12]  // 10
 *          %16 = ALLOCA/ARG size=4 align=4  // 20
 *          %15 = CONST/INT32 20  // 20
 *     >> %17 = MEMORY/STORE_LE_32 [%16, %15]  // 20
 *          %s.0 = ALLOCA/LOCAL size=8 align=4
 *          %19 = CALL @make_small [%13, %16]  // make_small(10, 20)
 *          %20 = CONST/UINT64 8
 *     >> %s.21 = MEMORY/MEMCPY [%s.0, %19, %20]
 *     >> %26 = EXIT_SCOPE
 *          %22 = GEP_FIELD offset=0 .x [%s.0]  // s.x
 *          %23 = MEMORY/LOAD_LE_32 [%22]  // s.x
 *          %24 = CONST/INT32 10  // 10
 *          %25 = CMP_NE [%23, %24]  // s.x != 10
 *     >> %27 = COND_BRANCH [%25]  // if (s.x != 10) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %34 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %s.0 = ALLOCA/LOCAL size=8 align=4
 *          %35 = GEP_FIELD offset=4 .y [%s.0]  // s.y
 *          %36 = MEMORY/LOAD_LE_32 [%35]  // s.y
 *          %37 = CONST/INT32 20  // 20
 *          %38 = CMP_NE [%36, %37]  // s.y != 20
 *     >> %39 = COND_BRANCH [%38]  // if (s.y != 20) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %45 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *     >> %46 = ENTER_SCOPE  // sum_small(s)
 *          %48 = ALLOCA/ARG size=8 align=4  // s
 *          %s.0 = ALLOCA/LOCAL size=8 align=4
 *          %47 = MEMORY/LOAD_LE_64 [%s.0]  // s
 *     >> %49 = MEMORY/STORE_LE_64 [%48, %47]  // s
 *          %sum.1 = ALLOCA/LOCAL size=4 align=4
 *          %51 = CALL @sum_small [%48]  // sum_small(s)
 *     >> %sum.52 = MEMORY/STORE_LE_32 [%sum.1, %51]
 *     >> %56 = EXIT_SCOPE
 *          %53 = MEMORY/LOAD_LE_32 [%sum.1]  // sum
 *          %54 = CONST/INT32 30  // 30
 *          %55 = CMP_NE [%53, %54]  // sum != 30
 *     >> %57 = COND_BRANCH [%55]  // if (sum != 30) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %64 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *     >> %65 = ENTER_SCOPE  // make_large(100)
 *          %67 = ALLOCA/ARG size=4 align=4  // 100
 *          %66 = CONST/INT32 100  // 100
 *     >> %68 = MEMORY/STORE_LE_32 [%67, %66]  // 100
 *          %l.2 = ALLOCA/LOCAL size=20 align=4
 *          %70 = CALL @make_large [%67]  // make_large(100)
 *          %71 = CONST/UINT64 20
 *     >> %l.72 = MEMORY/MEMCPY [%l.2, %70, %71]
 *     >> %77 = EXIT_SCOPE
 *          %73 = GEP_FIELD offset=0 .a [%l.2]  // l.a
 *          %74 = MEMORY/LOAD_LE_32 [%73]  // l.a
 *          %75 = CONST/INT32 100  // 100
 *          %76 = CMP_NE [%74, %75]  // l.a != 100
 *     >> %78 = COND_BRANCH [%76]  // if (l.a != 100) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %85 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %l.2 = ALLOCA/LOCAL size=20 align=4
 *          %86 = GEP_FIELD offset=16 .e [%l.2]  // l.e
 *          %87 = MEMORY/LOAD_LE_32 [%86]  // l.e
 *          %88 = CONST/INT32 104  // 104
 *          %89 = CMP_NE [%87, %88]  // l.e != 104
 *     >> %90 = COND_BRANCH [%89]  // if (l.e != 104) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %96 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *     >> %97 = ENTER_SCOPE  // sum_large(l)
 *          %98 = ALLOCA/ARG size=20 align=4  // l
 *          %l.2 = ALLOCA/LOCAL size=20 align=4
 *          %99 = CONST/UINT64 20
 *     >> %100 = MEMORY/MEMCPY [%98, %l.2, %99]  // l
 *          %lsum.3 = ALLOCA/LOCAL size=4 align=4
 *          %102 = CALL @sum_large [%98]  // sum_large(l)
 *     >> %lsum.103 = MEMORY/STORE_LE_32 [%lsum.3, %102]
 *     >> %107 = EXIT_SCOPE
 *          %104 = MEMORY/LOAD_LE_32 [%lsum.3]  // lsum
 *          %105 = CONST/INT32 510  // 510
 *          %106 = CMP_NE [%104, %105]  // lsum != 510
 *     >> %108 = COND_BRANCH [%106]  // if (lsum != 510) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %115 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %p.4 = ALLOCA/LOCAL size=3 align=1
 *          %116 = GEP_FIELD offset=0 .a [%p.4]  // p.a
 *          %117 = CONST/INT32 1  // 1
 *          %118 = CAST/TRUNC_I32_I8 [%117]  // 1
 *     >> %119 = MEMORY/STORE_LE_8 [%116, %118]  // p.a = 1
 *          %120 = GEP_FIELD offset=1 .b [%p.4]  // p.b
 *          %121 = CONST/INT32 2  // 2
 *          %122 = CAST/TRUNC_I32_I8 [%121]  // 2
 *     >> %123 = MEMORY/STORE_LE_8 [%120, %122]  // p.b = 2
 *          %124 = GEP_FIELD offset=2 .c [%p.4]  // p.c
 *          %125 = CONST/INT32 3  // 3
 *          %126 = CAST/TRUNC_I32_I8 [%125]  // 3
 *     >> %127 = MEMORY/STORE_LE_8 [%124, %126]  // p.c = 3
 *     >> %128 = ENTER_SCOPE  // sum_packed3(p)
 *          %129 = ALLOCA/ARG size=3 align=1  // p
 *          %130 = CONST/UINT64 3
 *     >> %131 = MEMORY/MEMCPY [%129, %p.4, %130]  // p
 *          %psum.5 = ALLOCA/LOCAL size=4 align=4
 *          %133 = CALL @sum_packed3 [%129]  // sum_packed3(p)
 *     >> %psum.134 = MEMORY/STORE_LE_32 [%psum.5, %133]
 *     >> %138 = EXIT_SCOPE
 *          %135 = MEMORY/LOAD_LE_32 [%psum.5]  // psum
 *          %136 = CONST/INT32 6  // 6
 *          %137 = CMP_NE [%135, %136]  // psum != 6
 *     >> %139 = COND_BRANCH [%137]  // if (psum != 6) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %146 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *     >> %147 = ENTER_SCOPE  // identity_small(s)
 *          %149 = ALLOCA/ARG size=8 align=4  // s
 *          %s.0 = ALLOCA/LOCAL size=8 align=4
 *          %148 = MEMORY/LOAD_LE_64 [%s.0]  // s
 *     >> %150 = MEMORY/STORE_LE_64 [%149, %148]  // s
 *          %s2.6 = ALLOCA/LOCAL size=8 align=4
 *          %152 = CALL @identity_small [%149]  // identity_small(s)
 *          %153 = CONST/UINT64 8
 *     >> %s2.154 = MEMORY/MEMCPY [%s2.6, %152, %153]
 *     >> %159 = EXIT_SCOPE
 *          %155 = GEP_FIELD offset=0 .x [%s2.6]  // s2.x
 *          %156 = MEMORY/LOAD_LE_32 [%155]  // s2.x
 *          %157 = CONST/INT32 10  // 10
 *          %158 = CMP_NE [%156, %157]  // s2.x != 10
 *     >> %160 = COND_BRANCH [%158]  // if (s2.x != 10) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %167 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %s2.6 = ALLOCA/LOCAL size=8 align=4
 *          %168 = GEP_FIELD offset=4 .y [%s2.6]  // s2.y
 *          %169 = MEMORY/LOAD_LE_32 [%168]  // s2.y
 *          %170 = CONST/INT32 20  // 20
 *          %171 = CMP_NE [%169, %170]  // s2.y != 20
 *     >> %172 = COND_BRANCH [%171]  // if (s2.y != 20) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %178 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *     >> %179 = ENTER_SCOPE  // chain_test(5, 15)
 *          %181 = ALLOCA/ARG size=4 align=4  // 5
 *          %180 = CONST/INT32 5  // 5
 *     >> %182 = MEMORY/STORE_LE_32 [%181, %180]  // 5
 *          %184 = ALLOCA/ARG size=4 align=4  // 15
 *          %183 = CONST/INT32 15  // 15
 *     >> %185 = MEMORY/STORE_LE_32 [%184, %183]  // 15
 *          %chained.7 = ALLOCA/LOCAL size=4 align=4
 *          %187 = CALL @chain_test [%181, %184]  // chain_test(5, 15)
 *     >> %chained.188 = MEMORY/STORE_LE_32 [%chained.7, %187]
 *     >> %192 = EXIT_SCOPE
 *          %189 = MEMORY/LOAD_LE_32 [%chained.7]  // chained
 *          %190 = CONST/INT32 20  // 20
 *          %191 = CMP_NE [%189, %190]  // chained != 20
 *     >> %193 = COND_BRANCH [%191]  // if (chained != 20) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %200 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *     >> %201 = ENTER_SCOPE  // sum_small(make_small(1, 2))
 *          %203 = ALLOCA/ARG size=4 align=4  // 1
 *          %202 = CONST/INT32 1  // 1
 *     >> %204 = MEMORY/STORE_LE_32 [%203, %202]  // 1
 *          %206 = ALLOCA/ARG size=4 align=4  // 2
 *          %205 = CONST/INT32 2  // 2
 *     >> %207 = MEMORY/STORE_LE_32 [%206, %205]  // 2
 *          %210 = ALLOCA/ARG size=8 align=4  // make_small(1, 2)
 *          %209 = CALL @make_small [%203, %206]  // make_small(1, 2)
 *     >> %211 = MEMORY/STORE_LE_64 [%210, %209]  // make_small(1, 2)
 *          %nested.8 = ALLOCA/LOCAL size=4 align=4
 *          %213 = CALL @sum_small [%210]  // sum_small(make_small(1, 2))
 *     >> %nested.214 = MEMORY/STORE_LE_32 [%nested.8, %213]
 *     >> %218 = EXIT_SCOPE
 *          %215 = MEMORY/LOAD_LE_32 [%nested.8]  // nested
 *          %216 = CONST/INT32 3  // 3
 *          %217 = CMP_NE [%215, %216]  // nested != 3
 *     >> %219 = COND_BRANCH [%217]  // if (nested != 3) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %226 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %228 = RETURN_PTR  // return 0
 *          %227 = CONST/INT32 0  // 0
 *     >> %229 = MEMORY/STORE_LE_32 [%228, %227]  // return 0
 *     >> %230 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %231 = RET [%227]  // return 0
 *   block_32 IF_THEN  <- [block_31]:
 *          %221 = RETURN_PTR  // return 11
 *          %220 = CONST/INT32 11  // 11
 *     >> %222 = MEMORY/STORE_LE_32 [%221, %220]  // return 11
 *     >> %223 = EXIT_SCOPE  // sum_small(make_small(1, 2))
 *     >> %224 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %225 = RET [%220]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %195 = RETURN_PTR  // return 10
 *          %194 = CONST/INT32 10  // 10
 *     >> %196 = MEMORY/STORE_LE_32 [%195, %194]  // return 10
 *     >> %197 = EXIT_SCOPE  // chain_test(5, 15)
 *     >> %198 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %199 = RET [%194]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %174 = RETURN_PTR  // return 9
 *          %173 = CONST/INT32 9  // 9
 *     >> %175 = MEMORY/STORE_LE_32 [%174, %173]  // return 9
 *     >> %176 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %177 = RET [%173]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %162 = RETURN_PTR  // return 8
 *          %161 = CONST/INT32 8  // 8
 *     >> %163 = MEMORY/STORE_LE_32 [%162, %161]  // return 8
 *     >> %164 = EXIT_SCOPE  // identity_small(s)
 *     >> %165 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %166 = RET [%161]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %141 = RETURN_PTR  // return 7
 *          %140 = CONST/INT32 7  // 7
 *     >> %142 = MEMORY/STORE_LE_32 [%141, %140]  // return 7
 *     >> %143 = EXIT_SCOPE  // sum_packed3(p)
 *     >> %144 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %145 = RET [%140]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %110 = RETURN_PTR  // return 6
 *          %109 = CONST/INT32 6  // 6
 *     >> %111 = MEMORY/STORE_LE_32 [%110, %109]  // return 6
 *     >> %112 = EXIT_SCOPE  // sum_large(l)
 *     >> %113 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %114 = RET [%109]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %92 = RETURN_PTR  // return 5
 *          %91 = CONST/INT32 5  // 5
 *     >> %93 = MEMORY/STORE_LE_32 [%92, %91]  // return 5
 *     >> %94 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %95 = RET [%91]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %80 = RETURN_PTR  // return 4
 *          %79 = CONST/INT32 4  // 4
 *     >> %81 = MEMORY/STORE_LE_32 [%80, %79]  // return 4
 *     >> %82 = EXIT_SCOPE  // make_large(100)
 *     >> %83 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %84 = RET [%79]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %59 = RETURN_PTR  // return 3
 *          %58 = CONST/INT32 3  // 3
 *     >> %60 = MEMORY/STORE_LE_32 [%59, %58]  // return 3
 *     >> %61 = EXIT_SCOPE  // sum_small(s)
 *     >> %62 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %63 = RET [%58]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %41 = RETURN_PTR  // return 2
 *          %40 = CONST/INT32 2  // 2
 *     >> %42 = MEMORY/STORE_LE_32 [%41, %40]  // return 2
 *     >> %43 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %44 = RET [%40]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %29 = RETURN_PTR  // return 1
 *          %28 = CONST/INT32 1  // 1
 *     >> %30 = MEMORY/STORE_LE_32 [%29, %28]  // return 1
 *     >> %31 = EXIT_SCOPE  // make_small(10, 20)
 *     >> %32 = EXIT_SCOPE  // {     // Small struct return.     struct Small ...
 *     >> %33 = RET [%28]  // return 1
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
