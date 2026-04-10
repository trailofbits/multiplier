// Tests: direct struct assignment using MEMCPY (not LOAD+STORE),
// struct parameter passing, struct return values, nested struct assignment,
// non-power-of-2 sized structs.

/*
 * Expected IR:
 *
 * function test_struct_assign (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=8 align=1 (a)
 *     obj_1 LOCAL_VALUE size=8 align=1 (b)
 *     obj_2 LOCAL_VALUE size=20 align=1 (la)
 *     obj_3 LOCAL_VALUE size=20 align=1 (lb)
 *     obj_4 LOCAL_VALUE size=4 align=1 (total)
 *     obj_5 LOCAL_VALUE size=8 align=1 (c)
 *     obj_6 LOCAL_VALUE size=12 align=1 (n1)
 *     obj_7 LOCAL_VALUE size=12 align=1 (n2)
 *     obj_8 LOCAL_VALUE size=8 align=1 (d)
 *     obj_9 PARAMETER size=20 align=1
 *     obj_10 RETURN_SLOT size=4 align=1
 *     obj_11 PARAMETER size=4 align=1
 *     obj_12 PARAMETER size=4 align=1
 *     obj_13 RETURN_SLOT size=8 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %9 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %10 = ENTER_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %11 = GEP_FIELD offset=0 .x [%a.0]  // a.x
 *          %12 = CONST/INT32 10  // 10
 *     >> %13 = MEMORY/STORE_LE_32 [%11, %12]  // a.x = 10
 *          %14 = GEP_FIELD offset=4 .y [%a.0]  // a.y
 *          %15 = CONST/INT32 20  // 20
 *     >> %16 = MEMORY/STORE_LE_32 [%14, %15]  // a.y = 20
 *          %b.1 = ALLOCA/LOCAL size=8 align=1
 *          %17 = MEMORY/LOAD_LE_64 [%a.0]  // a
 *     >> %b.18 = MEMORY/STORE_LE_64 [%b.1, %17]
 *          %22 = CMP_NE [%20, %21]  // b.x != 10
 *     >> %23 = COND_BRANCH [%22]  // if (b.x != 10) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %29 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %33 = CMP_NE [%31, %32]  // b.y != 20
 *     >> %34 = COND_BRANCH [%33]  // if (b.y != 20) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %40 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %41 = GEP_FIELD offset=0 .x [%b.1]  // b.x
 *          %42 = CONST/INT32 99  // 99
 *     >> %43 = MEMORY/STORE_LE_32 [%41, %42]  // b.x = 99
 *          %47 = CMP_NE [%45, %46]  // a.x != 10
 *     >> %48 = COND_BRANCH [%47]  // if (a.x != 10) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %54 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %55 = GEP_FIELD offset=0 .a [%la.2]  // la.a
 *          %56 = CONST/INT32 1  // 1
 *     >> %57 = MEMORY/STORE_LE_32 [%55, %56]  // la.a = 1
 *          %58 = GEP_FIELD offset=4 .b [%la.2]  // la.b
 *          %59 = CONST/INT32 2  // 2
 *     >> %60 = MEMORY/STORE_LE_32 [%58, %59]  // la.b = 2
 *          %61 = GEP_FIELD offset=8 .c [%la.2]  // la.c
 *          %62 = CONST/INT32 3  // 3
 *     >> %63 = MEMORY/STORE_LE_32 [%61, %62]  // la.c = 3
 *          %64 = GEP_FIELD offset=12 .d [%la.2]  // la.d
 *          %65 = CONST/INT32 4  // 4
 *     >> %66 = MEMORY/STORE_LE_32 [%64, %65]  // la.d = 4
 *          %67 = GEP_FIELD offset=16 .e [%la.2]  // la.e
 *          %68 = CONST/INT32 5  // 5
 *     >> %69 = MEMORY/STORE_LE_32 [%67, %68]  // la.e = 5
 *          %lb.3 = ALLOCA/LOCAL size=20 align=1
 *          %la.2 = ALLOCA/LOCAL size=20 align=1
 *          %70 = CONST/UINT64 20
 *     >> %lb.71 = MEMORY/MEMCPY [%lb.3, %la.2, %70]
 *          %75 = CMP_NE [%73, %74]  // lb.a != 1
 *     >> %76 = COND_BRANCH [%75]  // if (lb.a != 1) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %82 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %86 = CMP_NE [%84, %85]  // lb.e != 5
 *     >> %87 = COND_BRANCH [%86]  // if (lb.e != 5) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %93 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *     >> %94 = ENTER_SCOPE  // sum_large(la)
 *          %95 = ALLOCA/ARG size=20 align=1  // la
 *          %la.2 = ALLOCA/LOCAL size=20 align=1
 *          %96 = CONST/UINT64 20
 *     >> %97 = MEMORY/MEMCPY [%95, %la.2, %96]  // la
 *          %total.4 = ALLOCA/LOCAL size=4 align=1
 *          %99 = CALL @sum_large [%95]  // sum_large(la)
 *     >> %total.100 = MEMORY/STORE_LE_32 [%total.4, %99]
 *     >> %104 = EXIT_SCOPE
 *          %103 = CMP_NE [%101, %102]  // total != 15
 *     >> %105 = COND_BRANCH [%103]  // if (total != 15) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %112 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *     >> %113 = ENTER_SCOPE  // make_small(100, 200)
 *          %115 = ALLOCA/ARG size=4 align=1  // 100
 *          %114 = CONST/INT32 100  // 100
 *     >> %116 = MEMORY/STORE_LE_32 [%115, %114]  // 100
 *          %118 = ALLOCA/ARG size=4 align=1  // 200
 *          %117 = CONST/INT32 200  // 200
 *     >> %119 = MEMORY/STORE_LE_32 [%118, %117]  // 200
 *          %c.5 = ALLOCA/LOCAL size=8 align=1
 *          %121 = CALL @make_small [%115, %118]  // make_small(100, 200)
 *     >> %c.122 = MEMORY/STORE_LE_64 [%c.5, %121]
 *     >> %127 = EXIT_SCOPE
 *          %126 = CMP_NE [%124, %125]  // c.x != 100
 *     >> %128 = COND_BRANCH [%126]  // if (c.x != 100) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %135 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %139 = CMP_NE [%137, %138]  // c.y != 200
 *     >> %140 = COND_BRANCH [%139]  // if (c.y != 200) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %146 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %148 = GEP_FIELD offset=0 .x [%147]  // n1.s.x
 *          %149 = CONST/INT32 1  // 1
 *     >> %150 = MEMORY/STORE_LE_32 [%148, %149]  // n1.s.x = 1
 *          %152 = GEP_FIELD offset=4 .y [%151]  // n1.s.y
 *          %153 = CONST/INT32 2  // 2
 *     >> %154 = MEMORY/STORE_LE_32 [%152, %153]  // n1.s.y = 2
 *          %155 = GEP_FIELD offset=8 .z [%n1.6]  // n1.z
 *          %156 = CONST/INT32 3  // 3
 *     >> %157 = MEMORY/STORE_LE_32 [%155, %156]  // n1.z = 3
 *          %n2.7 = ALLOCA/LOCAL size=12 align=1
 *          %n1.6 = ALLOCA/LOCAL size=12 align=1
 *          %158 = CONST/UINT64 12
 *     >> %n2.159 = MEMORY/MEMCPY [%n2.7, %n1.6, %158]
 *          %164 = CMP_NE [%162, %163]  // n2.s.x != 1
 *     >> %165 = COND_BRANCH [%164]  // if (n2.s.x != 1) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %171 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %175 = CMP_NE [%173, %174]  // n2.z != 3
 *     >> %176 = COND_BRANCH [%175]  // if (n2.z != 3) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %182 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %183 = GEP_FIELD offset=0 .x [%d.8]  // d.x
 *          %184 = CONST/INT32 0  // 0
 *     >> %185 = MEMORY/STORE_LE_32 [%183, %184]  // d.x = 0
 *          %186 = GEP_FIELD offset=4 .y [%d.8]  // d.y
 *          %187 = CONST/INT32 0  // 0
 *     >> %188 = MEMORY/STORE_LE_32 [%186, %187]  // d.y = 0
 *          %d.8 = ALLOCA/LOCAL size=8 align=1
 *          %189 = MEMORY/LOAD_LE_64 [%a.0]  // a
 *     >> %190 = MEMORY/STORE_LE_64 [%d.8, %189]  // d = a
 *          %194 = CMP_NE [%192, %193]  // d.x != 10
 *     >> %195 = COND_BRANCH [%194]  // if (d.x != 10) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %201 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %205 = CMP_NE [%203, %204]  // d.y != 20
 *     >> %206 = COND_BRANCH [%205]  // if (d.y != 20) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %212 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %214 = RETURN_PTR  // return 0
 *          %213 = CONST/INT32 0  // 0
 *     >> %215 = MEMORY/STORE_LE_32 [%214, %213]  // return 0
 *     >> %216 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %213 = CONST/INT32 0  // 0
 *     >> %217 = RET [%213]  // return 0
 *   block_35 IF_THEN  <- [block_34]:
 *          %208 = RETURN_PTR  // return 12
 *          %207 = CONST/INT32 12  // 12
 *     >> %209 = MEMORY/STORE_LE_32 [%208, %207]  // return 12
 *     >> %210 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %207 = CONST/INT32 12  // 12
 *     >> %211 = RET [%207]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %197 = RETURN_PTR  // return 11
 *          %196 = CONST/INT32 11  // 11
 *     >> %198 = MEMORY/STORE_LE_32 [%197, %196]  // return 11
 *     >> %199 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %196 = CONST/INT32 11  // 11
 *     >> %200 = RET [%196]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %178 = RETURN_PTR  // return 10
 *          %177 = CONST/INT32 10  // 10
 *     >> %179 = MEMORY/STORE_LE_32 [%178, %177]  // return 10
 *     >> %180 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %177 = CONST/INT32 10  // 10
 *     >> %181 = RET [%177]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %167 = RETURN_PTR  // return 9
 *          %166 = CONST/INT32 9  // 9
 *     >> %168 = MEMORY/STORE_LE_32 [%167, %166]  // return 9
 *     >> %169 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %166 = CONST/INT32 9  // 9
 *     >> %170 = RET [%166]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %142 = RETURN_PTR  // return 8
 *          %141 = CONST/INT32 8  // 8
 *     >> %143 = MEMORY/STORE_LE_32 [%142, %141]  // return 8
 *     >> %144 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %141 = CONST/INT32 8  // 8
 *     >> %145 = RET [%141]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %130 = RETURN_PTR  // return 7
 *          %129 = CONST/INT32 7  // 7
 *     >> %131 = MEMORY/STORE_LE_32 [%130, %129]  // return 7
 *     >> %132 = EXIT_SCOPE  // make_small(100, 200)
 *     >> %133 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %129 = CONST/INT32 7  // 7
 *     >> %134 = RET [%129]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %107 = RETURN_PTR  // return 6
 *          %106 = CONST/INT32 6  // 6
 *     >> %108 = MEMORY/STORE_LE_32 [%107, %106]  // return 6
 *     >> %109 = EXIT_SCOPE  // sum_large(la)
 *     >> %110 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %106 = CONST/INT32 6  // 6
 *     >> %111 = RET [%106]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %89 = RETURN_PTR  // return 5
 *          %88 = CONST/INT32 5  // 5
 *     >> %90 = MEMORY/STORE_LE_32 [%89, %88]  // return 5
 *     >> %91 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %88 = CONST/INT32 5  // 5
 *     >> %92 = RET [%88]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %78 = RETURN_PTR  // return 4
 *          %77 = CONST/INT32 4  // 4
 *     >> %79 = MEMORY/STORE_LE_32 [%78, %77]  // return 4
 *     >> %80 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %77 = CONST/INT32 4  // 4
 *     >> %81 = RET [%77]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %50 = RETURN_PTR  // return 3
 *          %49 = CONST/INT32 3  // 3
 *     >> %51 = MEMORY/STORE_LE_32 [%50, %49]  // return 3
 *     >> %52 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %49 = CONST/INT32 3  // 3
 *     >> %53 = RET [%49]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %36 = RETURN_PTR  // return 2
 *          %35 = CONST/INT32 2  // 2
 *     >> %37 = MEMORY/STORE_LE_32 [%36, %35]  // return 2
 *     >> %38 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %35 = CONST/INT32 2  // 2
 *     >> %39 = RET [%35]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %25 = RETURN_PTR  // return 1
 *          %24 = CONST/INT32 1  // 1
 *     >> %26 = MEMORY/STORE_LE_32 [%25, %24]  // return 1
 *     >> %27 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %24 = CONST/INT32 1  // 1
 *     >> %28 = RET [%24]  // return 1
 * }
 */








struct Small {
    int x;
    int y;
};

struct Large {
    int a;
    int b;
    int c;
    int d;
    int e;  // 20 bytes — too big for scalar LOAD/STORE
};

struct Packed {
    char a;
    short b;
    char c;
    // 4 bytes with padding, but some ABIs may pack to 4 or 5 bytes
};

struct Nested {
    struct Small s;
    int z;
};

static struct Small make_small(int x, int y) {
    struct Small s;
    s.x = x;
    s.y = y;
    return s;
}

static int sum_large(struct Large l) {
    return l.a + l.b + l.c + l.d + l.e;
}

int test_struct_assign(void) {
    // Direct struct assignment: a = b → MEMCPY.
    struct Small a;
    a.x = 10;
    a.y = 20;
    struct Small b = a;  // MEMCPY(b, a, sizeof(Small))
    if (b.x != 10) return 1;
    if (b.y != 20) return 2;

    // Modify copy, original unchanged.
    b.x = 99;
    if (a.x != 10) return 3;

    // Large struct assignment.
    struct Large la;
    la.a = 1; la.b = 2; la.c = 3; la.d = 4; la.e = 5;
    struct Large lb = la;  // MEMCPY for 20-byte struct
    if (lb.a != 1) return 4;
    if (lb.e != 5) return 5;

    // Pass large struct to function (by value).
    int total = sum_large(la);
    if (total != 15) return 6;

    // Struct return.
    struct Small c = make_small(100, 200);
    if (c.x != 100) return 7;
    if (c.y != 200) return 8;

    // Nested struct assignment.
    struct Nested n1;
    n1.s.x = 1;
    n1.s.y = 2;
    n1.z = 3;
    struct Nested n2 = n1;
    if (n2.s.x != 1) return 9;
    if (n2.z != 3) return 10;

    // Re-assignment.
    struct Small d;
    d.x = 0; d.y = 0;
    d = a;  // a = b style assignment → MEMCPY
    if (d.x != 10) return 11;
    if (d.y != 20) return 12;

    return 0;
}
