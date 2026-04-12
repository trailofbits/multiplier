// Tests: direct struct assignment using MEMCPY (not LOAD+STORE),
// struct parameter passing, struct return values, nested struct assignment,
// non-power-of-2 sized structs.

/*
 * Expected IR:
 *
 * function test_struct_assign (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=8 align=4 (a)
 *     obj_1 LOCAL_VALUE size=8 align=4 (b)
 *     obj_2 LOCAL_VALUE size=20 align=4 (la)
 *     obj_3 LOCAL_VALUE size=20 align=4 (lb)
 *     obj_4 LOCAL_VALUE size=4 align=4 (total)
 *     obj_5 LOCAL_VALUE size=8 align=4 (c)
 *     obj_6 LOCAL_VALUE size=12 align=4 (n1)
 *     obj_7 LOCAL_VALUE size=12 align=4 (n2)
 *     obj_8 LOCAL_VALUE size=8 align=4 (d)
 *     obj_9 PARAMETER size=20 align=4
 *     obj_10 RETURN_SLOT size=4 align=4
 *     obj_11 PARAMETER size=4 align=4
 *     obj_12 PARAMETER size=4 align=4
 *     obj_13 RETURN_SLOT size=8 align=4
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %a.0 = ALLOCA/LOCAL size=8 align=4
 *     >> %b.1 = ALLOCA/LOCAL size=8 align=4
 *     >> %la.2 = ALLOCA/LOCAL size=20 align=4
 *     >> %lb.3 = ALLOCA/LOCAL size=20 align=4
 *     >> %total.4 = ALLOCA/LOCAL size=4 align=4
 *     >> %c.5 = ALLOCA/LOCAL size=8 align=4
 *     >> %n1.6 = ALLOCA/LOCAL size=12 align=4
 *     >> %n2.7 = ALLOCA/LOCAL size=12 align=4
 *     >> %d.8 = ALLOCA/LOCAL size=8 align=4
 *     >> %9 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %10 = ENTER_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *          %a.0 = ALLOCA/LOCAL size=8 align=4
 *          %11 = GEP_FIELD offset=0 .x [%a.0]  // a.x
 *          %12 = CONST/INT32 10  // 10
 *     >> %13 = MEMORY/STORE_LE_32 [%11, %12]  // a.x = 10
 *          %14 = GEP_FIELD offset=4 .y [%a.0]  // a.y
 *          %15 = CONST/INT32 20  // 20
 *     >> %16 = MEMORY/STORE_LE_32 [%14, %15]  // a.y = 20
 *          %b.1 = ALLOCA/LOCAL size=8 align=4
 *          %17 = CONST/UINT64 8
 *     >> %b.18 = MEMORY/MEMCPY [%b.1, %a.0, %17]
 *          %19 = GEP_FIELD offset=0 .x [%b.1]  // b.x
 *          %20 = MEMORY/LOAD_LE_32 [%19]  // b.x
 *          %21 = CONST/INT32 10  // 10
 *          %22 = CMP_NE [%20, %21]  // b.x != 10
 *     >> %23 = COND_BRANCH [%22]  // if (b.x != 10) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %29 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %b.1 = ALLOCA/LOCAL size=8 align=4
 *          %30 = GEP_FIELD offset=4 .y [%b.1]  // b.y
 *          %31 = MEMORY/LOAD_LE_32 [%30]  // b.y
 *          %32 = CONST/INT32 20  // 20
 *          %33 = CMP_NE [%31, %32]  // b.y != 20
 *     >> %34 = COND_BRANCH [%33]  // if (b.y != 20) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %40 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %b.1 = ALLOCA/LOCAL size=8 align=4
 *          %41 = GEP_FIELD offset=0 .x [%b.1]  // b.x
 *          %42 = CONST/INT32 99  // 99
 *     >> %43 = MEMORY/STORE_LE_32 [%41, %42]  // b.x = 99
 *          %a.0 = ALLOCA/LOCAL size=8 align=4
 *          %44 = GEP_FIELD offset=0 .x [%a.0]  // a.x
 *          %45 = MEMORY/LOAD_LE_32 [%44]  // a.x
 *          %46 = CONST/INT32 10  // 10
 *          %47 = CMP_NE [%45, %46]  // a.x != 10
 *     >> %48 = COND_BRANCH [%47]  // if (a.x != 10) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %54 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %la.2 = ALLOCA/LOCAL size=20 align=4
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
 *          %lb.3 = ALLOCA/LOCAL size=20 align=4
 *          %70 = CONST/UINT64 20
 *     >> %lb.71 = MEMORY/MEMCPY [%lb.3, %la.2, %70]
 *          %72 = GEP_FIELD offset=0 .a [%lb.3]  // lb.a
 *          %73 = MEMORY/LOAD_LE_32 [%72]  // lb.a
 *          %74 = CONST/INT32 1  // 1
 *          %75 = CMP_NE [%73, %74]  // lb.a != 1
 *     >> %76 = COND_BRANCH [%75]  // if (lb.a != 1) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %82 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %lb.3 = ALLOCA/LOCAL size=20 align=4
 *          %83 = GEP_FIELD offset=16 .e [%lb.3]  // lb.e
 *          %84 = MEMORY/LOAD_LE_32 [%83]  // lb.e
 *          %85 = CONST/INT32 5  // 5
 *          %86 = CMP_NE [%84, %85]  // lb.e != 5
 *     >> %87 = COND_BRANCH [%86]  // if (lb.e != 5) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %93 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *     >> %94 = ENTER_SCOPE  // sum_large(la)
 *          %95 = ALLOCA/ARG size=20 align=4  // la
 *          %la.2 = ALLOCA/LOCAL size=20 align=4
 *          %96 = CONST/UINT64 20
 *     >> %97 = MEMORY/MEMCPY [%95, %la.2, %96]  // la
 *          %total.4 = ALLOCA/LOCAL size=4 align=4
 *          %99 = CALL @sum_large [%95]  // sum_large(la)
 *     >> %total.100 = MEMORY/STORE_LE_32 [%total.4, %99]
 *     >> %104 = EXIT_SCOPE
 *          %101 = MEMORY/LOAD_LE_32 [%total.4]  // total
 *          %102 = CONST/INT32 15  // 15
 *          %103 = CMP_NE [%101, %102]  // total != 15
 *     >> %105 = COND_BRANCH [%103]  // if (total != 15) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %112 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *     >> %113 = ENTER_SCOPE  // make_small(100, 200)
 *          %115 = ALLOCA/ARG size=4 align=4  // 100
 *          %114 = CONST/INT32 100  // 100
 *     >> %116 = MEMORY/STORE_LE_32 [%115, %114]  // 100
 *          %118 = ALLOCA/ARG size=4 align=4  // 200
 *          %117 = CONST/INT32 200  // 200
 *     >> %119 = MEMORY/STORE_LE_32 [%118, %117]  // 200
 *          %c.5 = ALLOCA/LOCAL size=8 align=4
 *          %121 = CALL @make_small [%115, %118]  // make_small(100, 200)
 *          %122 = CONST/UINT64 8
 *     >> %c.123 = MEMORY/MEMCPY [%c.5, %121, %122]
 *     >> %128 = EXIT_SCOPE
 *          %124 = GEP_FIELD offset=0 .x [%c.5]  // c.x
 *          %125 = MEMORY/LOAD_LE_32 [%124]  // c.x
 *          %126 = CONST/INT32 100  // 100
 *          %127 = CMP_NE [%125, %126]  // c.x != 100
 *     >> %129 = COND_BRANCH [%127]  // if (c.x != 100) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %136 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %c.5 = ALLOCA/LOCAL size=8 align=4
 *          %137 = GEP_FIELD offset=4 .y [%c.5]  // c.y
 *          %138 = MEMORY/LOAD_LE_32 [%137]  // c.y
 *          %139 = CONST/INT32 200  // 200
 *          %140 = CMP_NE [%138, %139]  // c.y != 200
 *     >> %141 = COND_BRANCH [%140]  // if (c.y != 200) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %147 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %n1.6 = ALLOCA/LOCAL size=12 align=4
 *          %148 = GEP_FIELD offset=0 .s [%n1.6]  // n1.s
 *          %149 = GEP_FIELD offset=0 .x [%148]  // n1.s.x
 *          %150 = CONST/INT32 1  // 1
 *     >> %151 = MEMORY/STORE_LE_32 [%149, %150]  // n1.s.x = 1
 *          %152 = GEP_FIELD offset=0 .s [%n1.6]  // n1.s
 *          %153 = GEP_FIELD offset=4 .y [%152]  // n1.s.y
 *          %154 = CONST/INT32 2  // 2
 *     >> %155 = MEMORY/STORE_LE_32 [%153, %154]  // n1.s.y = 2
 *          %156 = GEP_FIELD offset=8 .z [%n1.6]  // n1.z
 *          %157 = CONST/INT32 3  // 3
 *     >> %158 = MEMORY/STORE_LE_32 [%156, %157]  // n1.z = 3
 *          %n2.7 = ALLOCA/LOCAL size=12 align=4
 *          %159 = CONST/UINT64 12
 *     >> %n2.160 = MEMORY/MEMCPY [%n2.7, %n1.6, %159]
 *          %161 = GEP_FIELD offset=0 .s [%n2.7]  // n2.s
 *          %162 = GEP_FIELD offset=0 .x [%161]  // n2.s.x
 *          %163 = MEMORY/LOAD_LE_32 [%162]  // n2.s.x
 *          %164 = CONST/INT32 1  // 1
 *          %165 = CMP_NE [%163, %164]  // n2.s.x != 1
 *     >> %166 = COND_BRANCH [%165]  // if (n2.s.x != 1) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %172 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %n2.7 = ALLOCA/LOCAL size=12 align=4
 *          %173 = GEP_FIELD offset=8 .z [%n2.7]  // n2.z
 *          %174 = MEMORY/LOAD_LE_32 [%173]  // n2.z
 *          %175 = CONST/INT32 3  // 3
 *          %176 = CMP_NE [%174, %175]  // n2.z != 3
 *     >> %177 = COND_BRANCH [%176]  // if (n2.z != 3) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %183 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %d.8 = ALLOCA/LOCAL size=8 align=4
 *          %184 = GEP_FIELD offset=0 .x [%d.8]  // d.x
 *          %185 = CONST/INT32 0  // 0
 *     >> %186 = MEMORY/STORE_LE_32 [%184, %185]  // d.x = 0
 *          %187 = GEP_FIELD offset=4 .y [%d.8]  // d.y
 *          %188 = CONST/INT32 0  // 0
 *     >> %189 = MEMORY/STORE_LE_32 [%187, %188]  // d.y = 0
 *          %a.0 = ALLOCA/LOCAL size=8 align=4
 *          %190 = MEMORY/LOAD_LE_64 [%a.0]  // a
 *     >> %191 = MEMORY/STORE_LE_64 [%d.8, %190]  // d = a
 *          %192 = GEP_FIELD offset=0 .x [%d.8]  // d.x
 *          %193 = MEMORY/LOAD_LE_32 [%192]  // d.x
 *          %194 = CONST/INT32 10  // 10
 *          %195 = CMP_NE [%193, %194]  // d.x != 10
 *     >> %196 = COND_BRANCH [%195]  // if (d.x != 10) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %202 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %d.8 = ALLOCA/LOCAL size=8 align=4
 *          %203 = GEP_FIELD offset=4 .y [%d.8]  // d.y
 *          %204 = MEMORY/LOAD_LE_32 [%203]  // d.y
 *          %205 = CONST/INT32 20  // 20
 *          %206 = CMP_NE [%204, %205]  // d.y != 20
 *     >> %207 = COND_BRANCH [%206]  // if (d.y != 20) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %213 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %215 = RETURN_PTR  // return 0
 *          %214 = CONST/INT32 0  // 0
 *     >> %216 = MEMORY/STORE_LE_32 [%215, %214]  // return 0
 *     >> %217 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %218 = RET [%214]  // return 0
 *   block_35 IF_THEN  <- [block_34]:
 *          %209 = RETURN_PTR  // return 12
 *          %208 = CONST/INT32 12  // 12
 *     >> %210 = MEMORY/STORE_LE_32 [%209, %208]  // return 12
 *     >> %211 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %212 = RET [%208]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %198 = RETURN_PTR  // return 11
 *          %197 = CONST/INT32 11  // 11
 *     >> %199 = MEMORY/STORE_LE_32 [%198, %197]  // return 11
 *     >> %200 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %201 = RET [%197]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %179 = RETURN_PTR  // return 10
 *          %178 = CONST/INT32 10  // 10
 *     >> %180 = MEMORY/STORE_LE_32 [%179, %178]  // return 10
 *     >> %181 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %182 = RET [%178]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %168 = RETURN_PTR  // return 9
 *          %167 = CONST/INT32 9  // 9
 *     >> %169 = MEMORY/STORE_LE_32 [%168, %167]  // return 9
 *     >> %170 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %171 = RET [%167]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %143 = RETURN_PTR  // return 8
 *          %142 = CONST/INT32 8  // 8
 *     >> %144 = MEMORY/STORE_LE_32 [%143, %142]  // return 8
 *     >> %145 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %146 = RET [%142]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %131 = RETURN_PTR  // return 7
 *          %130 = CONST/INT32 7  // 7
 *     >> %132 = MEMORY/STORE_LE_32 [%131, %130]  // return 7
 *     >> %133 = EXIT_SCOPE  // make_small(100, 200)
 *     >> %134 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %135 = RET [%130]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %107 = RETURN_PTR  // return 6
 *          %106 = CONST/INT32 6  // 6
 *     >> %108 = MEMORY/STORE_LE_32 [%107, %106]  // return 6
 *     >> %109 = EXIT_SCOPE  // sum_large(la)
 *     >> %110 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %111 = RET [%106]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %89 = RETURN_PTR  // return 5
 *          %88 = CONST/INT32 5  // 5
 *     >> %90 = MEMORY/STORE_LE_32 [%89, %88]  // return 5
 *     >> %91 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %92 = RET [%88]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %78 = RETURN_PTR  // return 4
 *          %77 = CONST/INT32 4  // 4
 *     >> %79 = MEMORY/STORE_LE_32 [%78, %77]  // return 4
 *     >> %80 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %81 = RET [%77]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %50 = RETURN_PTR  // return 3
 *          %49 = CONST/INT32 3  // 3
 *     >> %51 = MEMORY/STORE_LE_32 [%50, %49]  // return 3
 *     >> %52 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %53 = RET [%49]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %36 = RETURN_PTR  // return 2
 *          %35 = CONST/INT32 2  // 2
 *     >> %37 = MEMORY/STORE_LE_32 [%36, %35]  // return 2
 *     >> %38 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
 *     >> %39 = RET [%35]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %25 = RETURN_PTR  // return 1
 *          %24 = CONST/INT32 1  // 1
 *     >> %26 = MEMORY/STORE_LE_32 [%25, %24]  // return 1
 *     >> %27 = EXIT_SCOPE  // {     // Direct struct assignment: a = b → ME...
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
