// Tests: pointer arithmetic (PTR_ADD, PTR_DIFF), pointer increment/decrement
// (RMW with PTR_ADD), pointer compound assignment (ptr += n, ptr -= n),
// array subscript, dereferencing, address-of (ALLOCA as pointer),
// GEP_FIELD for struct member access.

/*
 * Expected IR:
 *
 * function test_pointers (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=20 align=1 (arr)
 *     obj_2 LOCAL_VALUE size=8 align=1 (p)
 *     obj_3 LOCAL_VALUE size=8 align=1 (q)
 *     obj_4 LOCAL_VALUE size=8 align=1 (diff)
 *     obj_5 LOCAL_VALUE size=8 align=1 (r)
 *     obj_6 LOCAL_VALUE size=8 align=1 (s)
 *     obj_7 LOCAL size=8 align=1 (pt)
 *     obj_8 LOCAL_VALUE size=8 align=1 (pp)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %8 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %9 = ENTER_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *          %arr.10 = CONST/UINT8 0
 *          %arr.11 = CONST/UINT64 20
 *     >> %arr.12 = MEMORY/MEMSET [%arr.0, %arr.10, %arr.11]
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *          %13 = CONST/INT32 10  // 10
 *     >> %arr.14 = MEMORY/STORE_LE_32 [%arr.0, %13]
 *          %arr.16 = PTR_ADD elem_size=4 [%arr.0, %arr.15]
 *          %17 = CONST/INT32 20  // 20
 *     >> %arr.18 = MEMORY/STORE_LE_32 [%arr.16, %17]
 *          %arr.20 = PTR_ADD elem_size=4 [%arr.0, %arr.19]
 *          %21 = CONST/INT32 30  // 30
 *     >> %arr.22 = MEMORY/STORE_LE_32 [%arr.20, %21]
 *          %arr.24 = PTR_ADD elem_size=4 [%arr.0, %arr.23]
 *          %25 = CONST/INT32 40  // 40
 *     >> %arr.26 = MEMORY/STORE_LE_32 [%arr.24, %25]
 *          %arr.28 = PTR_ADD elem_size=4 [%arr.0, %arr.27]
 *          %29 = CONST/INT32 50  // 50
 *     >> %arr.30 = MEMORY/STORE_LE_32 [%arr.28, %29]
 *          %35 = CMP_NE [%33, %34]  // arr[0] != 10
 *     >> %36 = COND_BRANCH [%35]  // if (arr[0] != 10) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %42 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %47 = CMP_NE [%45, %46]  // arr[4] != 50
 *     >> %48 = COND_BRANCH [%47]  // if (arr[4] != 50) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %54 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %p.1 = ALLOCA/LOCAL size=8 align=1
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *     >> %p.55 = MEMORY/STORE_LE_64 [%p.1, %arr.0]
 *          %p.1 = ALLOCA/LOCAL size=8 align=1
 *          %58 = PTR_ADD elem_size=4 [%56, %57]  // p + 2
 *     >> %59 = MEMORY/STORE_LE_64 [%p.1, %58]  // p = p + 2
 *          %63 = CMP_NE [%61, %62]  // *p != 30
 *     >> %64 = COND_BRANCH [%63]  // if (*p != 30) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %70 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %q.2 = ALLOCA/LOCAL size=8 align=1
 *          %72 = PTR_ADD elem_size=4 [%arr.0, %71]  // arr[4]
 *     >> %q.73 = MEMORY/STORE_LE_64 [%q.2, %72]
 *          %diff.3 = ALLOCA/LOCAL size=8 align=1
 *          %76 = PTR_DIFF [%74, %75]  // q - p
 *     >> %diff.77 = MEMORY/STORE_LE_64 [%diff.3, %76]
 *          %81 = CMP_NE [%78, %80]  // diff != 2
 *     >> %82 = COND_BRANCH [%81]  // if (diff != 2) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %88 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %r.4 = ALLOCA/LOCAL size=8 align=1
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *     >> %r.89 = MEMORY/STORE_LE_64 [%r.4, %arr.0]
 *          %r.4 = ALLOCA/LOCAL size=8 align=1
 *          %90 = CONST/INT64 1  // r++
 *     >> %91 = READ_MODIFY_WRITE(PTR_ADD old) [%r.4, %90]  // r++
 *          %95 = CMP_NE [%93, %94]  // *r != 20
 *     >> %96 = COND_BRANCH [%95]  // if (*r != 20) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %102 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %r.4 = ALLOCA/LOCAL size=8 align=1
 *          %104 = PTR_ADD elem_size=4 [%arr.0, %103]  // arr[3]
 *     >> %105 = MEMORY/STORE_LE_64 [%r.4, %104]  // r = &arr[3]
 *          %r.4 = ALLOCA/LOCAL size=8 align=1
 *          %106 = CONST/INT64 -1  // r--
 *     >> %107 = READ_MODIFY_WRITE(PTR_ADD old) [%r.4, %106]  // r--
 *          %111 = CMP_NE [%109, %110]  // *r != 30
 *     >> %112 = COND_BRANCH [%111]  // if (*r != 30) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %118 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %s.5 = ALLOCA/LOCAL size=8 align=1
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *     >> %s.119 = MEMORY/STORE_LE_64 [%s.5, %arr.0]
 *          %s.5 = ALLOCA/LOCAL size=8 align=1
 *          %120 = CONST/INT32 3  // 3
 *     >> %121 = READ_MODIFY_WRITE(PTR_ADD new) [%s.5, %120]  // s += 3
 *          %125 = CMP_NE [%123, %124]  // *s != 40
 *     >> %126 = COND_BRANCH [%125]  // if (*s != 40) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %132 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %s.5 = ALLOCA/LOCAL size=8 align=1
 *          %134 = NEG [%133]  // s -= 2
 *     >> %135 = READ_MODIFY_WRITE(PTR_ADD new) [%s.5, %134]  // s -= 2
 *          %139 = CMP_NE [%137, %138]  // *s != 20
 *     >> %140 = COND_BRANCH [%139]  // if (*s != 20) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %146 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %147 = GEP_FIELD offset=0 .x [%pt.6]  // pt.x
 *          %148 = CONST/INT32 100  // 100
 *     >> %149 = MEMORY/STORE_LE_32 [%147, %148]  // pt.x = 100
 *          %150 = GEP_FIELD offset=4 .y [%pt.6]  // pt.y
 *          %151 = CONST/INT32 200  // 200
 *     >> %152 = MEMORY/STORE_LE_32 [%150, %151]  // pt.y = 200
 *          %156 = CMP_NE [%154, %155]  // pt.x != 100
 *     >> %157 = COND_BRANCH [%156]  // if (pt.x != 100) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %163 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %167 = CMP_NE [%165, %166]  // pt.y != 200
 *     >> %168 = COND_BRANCH [%167]  // if (pt.y != 200) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %174 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %pp.7 = ALLOCA/LOCAL size=8 align=1
 *          %pt.6 = ALLOCA/LOCAL size=8 align=1
 *     >> %pp.175 = MEMORY/STORE_LE_64 [%pp.7, %pt.6]
 *          %177 = GEP_FIELD offset=0 .x [%176]  // pp->x
 *          %178 = CONST/INT32 300  // 300
 *     >> %179 = MEMORY/STORE_LE_32 [%177, %178]  // pp->x = 300
 *          %183 = CMP_NE [%181, %182]  // pt.x != 300
 *     >> %184 = COND_BRANCH [%183]  // if (pt.x != 300) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %190 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %192 = RETURN_PTR  // return 0
 *          %191 = CONST/INT32 0  // 0
 *     >> %193 = MEMORY/STORE_LE_32 [%192, %191]  // return 0
 *     >> %194 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %191 = CONST/INT32 0  // 0
 *     >> %195 = RET [%191]  // return 0
 *   block_32 IF_THEN  <- [block_31]:
 *          %186 = RETURN_PTR  // return 11
 *          %185 = CONST/INT32 11  // 11
 *     >> %187 = MEMORY/STORE_LE_32 [%186, %185]  // return 11
 *     >> %188 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %185 = CONST/INT32 11  // 11
 *     >> %189 = RET [%185]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %170 = RETURN_PTR  // return 10
 *          %169 = CONST/INT32 10  // 10
 *     >> %171 = MEMORY/STORE_LE_32 [%170, %169]  // return 10
 *     >> %172 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %169 = CONST/INT32 10  // 10
 *     >> %173 = RET [%169]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %159 = RETURN_PTR  // return 9
 *          %158 = CONST/INT32 9  // 9
 *     >> %160 = MEMORY/STORE_LE_32 [%159, %158]  // return 9
 *     >> %161 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %158 = CONST/INT32 9  // 9
 *     >> %162 = RET [%158]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %142 = RETURN_PTR  // return 8
 *          %141 = CONST/INT32 8  // 8
 *     >> %143 = MEMORY/STORE_LE_32 [%142, %141]  // return 8
 *     >> %144 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %141 = CONST/INT32 8  // 8
 *     >> %145 = RET [%141]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %128 = RETURN_PTR  // return 7
 *          %127 = CONST/INT32 7  // 7
 *     >> %129 = MEMORY/STORE_LE_32 [%128, %127]  // return 7
 *     >> %130 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %127 = CONST/INT32 7  // 7
 *     >> %131 = RET [%127]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %114 = RETURN_PTR  // return 6
 *          %113 = CONST/INT32 6  // 6
 *     >> %115 = MEMORY/STORE_LE_32 [%114, %113]  // return 6
 *     >> %116 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %113 = CONST/INT32 6  // 6
 *     >> %117 = RET [%113]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %98 = RETURN_PTR  // return 5
 *          %97 = CONST/INT32 5  // 5
 *     >> %99 = MEMORY/STORE_LE_32 [%98, %97]  // return 5
 *     >> %100 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %97 = CONST/INT32 5  // 5
 *     >> %101 = RET [%97]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %84 = RETURN_PTR  // return 4
 *          %83 = CONST/INT32 4  // 4
 *     >> %85 = MEMORY/STORE_LE_32 [%84, %83]  // return 4
 *     >> %86 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %83 = CONST/INT32 4  // 4
 *     >> %87 = RET [%83]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %66 = RETURN_PTR  // return 3
 *          %65 = CONST/INT32 3  // 3
 *     >> %67 = MEMORY/STORE_LE_32 [%66, %65]  // return 3
 *     >> %68 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %65 = CONST/INT32 3  // 3
 *     >> %69 = RET [%65]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %50 = RETURN_PTR  // return 2
 *          %49 = CONST/INT32 2  // 2
 *     >> %51 = MEMORY/STORE_LE_32 [%50, %49]  // return 2
 *     >> %52 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %49 = CONST/INT32 2  // 2
 *     >> %53 = RET [%49]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %38 = RETURN_PTR  // return 1
 *          %37 = CONST/INT32 1  // 1
 *     >> %39 = MEMORY/STORE_LE_32 [%38, %37]  // return 1
 *     >> %40 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %37 = CONST/INT32 1  // 1
 *     >> %41 = RET [%37]  // return 1
 * }
 */

struct Point {
    int x;
    int y;
};

int test_pointers(void) {
    int arr[5] = {10, 20, 30, 40, 50};

    // Array subscript.
    if (arr[0] != 10) return 1;
    if (arr[4] != 50) return 2;

    // Pointer arithmetic.
    int *p = arr;
    p = p + 2;
    if (*p != 30) return 3;

    // Pointer subtraction.
    int *q = &arr[4];
    long diff = q - p;
    if (diff != 2) return 4;

    // Pointer increment.
    int *r = arr;
    r++;
    if (*r != 20) return 5;

    // Pointer decrement.
    r = &arr[3];
    r--;
    if (*r != 30) return 6;

    // Pointer compound assignment.
    int *s = arr;
    s += 3;
    if (*s != 40) return 7;
    s -= 2;
    if (*s != 20) return 8;

    // Struct member access (GEP_FIELD).
    struct Point pt;
    pt.x = 100;
    pt.y = 200;
    if (pt.x != 100) return 9;
    if (pt.y != 200) return 10;

    // Pointer to struct member.
    struct Point *pp = &pt;
    pp->x = 300;
    if (pt.x != 300) return 11;

    return 0;
}
