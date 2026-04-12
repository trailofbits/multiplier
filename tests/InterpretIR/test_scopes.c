// Tests: scope tracking (ENTER_SCOPE, EXIT_SCOPE), nested scopes,
// for-init implicit scope, variable lifetime, compound statements,
// and GNU block expressions ({ ... }).

/*
 * Expected IR:
 *
 * function test_scopes (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=4 align=4 (result)
 *     obj_1 LOCAL_VALUE size=4 align=4 (x)
 *     obj_2 LOCAL_VALUE size=4 align=4 (x)
 *     obj_3 LOCAL_VALUE size=4 align=4 (sum)
 *     obj_4 LOCAL_VALUE size=4 align=4 (i)
 *     obj_5 LOCAL_VALUE size=4 align=4 (total)
 *     obj_6 LOCAL_VALUE size=4 align=4 (i)
 *     obj_7 LOCAL_VALUE size=4 align=4 (i)
 *     obj_8 LOCAL_VALUE size=4 align=4 (x)
 *     obj_9 LOCAL_VALUE size=4 align=4 (y)
 *     obj_10 LOCAL_VALUE size=4 align=4 (block_val)
 *     obj_11 LOCAL_VALUE size=4 align=4 (a)
 *     obj_12 LOCAL_VALUE size=4 align=4 (b)
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %result.0 = ALLOCA/LOCAL size=4 align=4
 *     >> %x.1 = ALLOCA/LOCAL size=4 align=4
 *     >> %x.2 = ALLOCA/LOCAL size=4 align=4
 *     >> %sum.3 = ALLOCA/LOCAL size=4 align=4
 *     >> %i.4 = ALLOCA/LOCAL size=4 align=4
 *     >> %total.5 = ALLOCA/LOCAL size=4 align=4
 *     >> %i.6 = ALLOCA/LOCAL size=4 align=4
 *     >> %i.7 = ALLOCA/LOCAL size=4 align=4
 *     >> %x.8 = ALLOCA/LOCAL size=4 align=4
 *     >> %y.9 = ALLOCA/LOCAL size=4 align=4
 *     >> %block_val.10 = ALLOCA/LOCAL size=4 align=4
 *     >> %a.11 = ALLOCA/LOCAL size=4 align=4
 *     >> %b.12 = ALLOCA/LOCAL size=4 align=4
 *     >> %13 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %14 = ENTER_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %15 = CONST/INT32 0  // 0
 *     >> %result.16 = MEMORY/STORE_LE_32 [%result.0, %15]
 *     >> %17 = ENTER_SCOPE  // {         int x = 10;         result += x;     }
 *          %x.1 = ALLOCA/LOCAL size=4 align=4
 *          %18 = CONST/INT32 10  // 10
 *     >> %x.19 = MEMORY/STORE_LE_32 [%x.1, %18]
 *          %20 = MEMORY/LOAD_LE_32 [%x.1]  // x
 *     >> %21 = READ_MODIFY_WRITE(ADD new) [%result.0, %20]  // result += x
 *     >> %22 = EXIT_SCOPE  // {         int x = 10;         result += x;     }
 *     >> %23 = ENTER_SCOPE  // {         int x = 20;         result += x;     }
 *          %x.2 = ALLOCA/LOCAL size=4 align=4
 *          %24 = CONST/INT32 20  // 20
 *     >> %x.25 = MEMORY/STORE_LE_32 [%x.2, %24]
 *          %26 = MEMORY/LOAD_LE_32 [%x.2]  // x
 *     >> %27 = READ_MODIFY_WRITE(ADD new) [%result.0, %26]  // result += x
 *     >> %28 = EXIT_SCOPE  // {         int x = 20;         result += x;     }
 *          %29 = MEMORY/LOAD_LE_32 [%result.0]  // result
 *          %30 = CONST/INT32 30  // 30
 *          %31 = CMP_NE [%29, %30]  // result != 30
 *     >> %32 = COND_BRANCH [%31]  // if (result != 30) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %38 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %sum.3 = ALLOCA/LOCAL size=4 align=4
 *          %39 = CONST/INT32 0  // 0
 *     >> %sum.40 = MEMORY/STORE_LE_32 [%sum.3, %39]
 *     >> %41 = ENTER_SCOPE  // for (int i = 0; i < 5; i++) {         sum += i;...
 *     >> %42 = IMPLICIT_GOTO
 *     -> [block_5]
 *   block_5 LOOP_PREHEADER  <- [block_4]:
 *          %i.4 = ALLOCA/LOCAL size=4 align=4
 *          %43 = CONST/INT32 0  // 0
 *     >> %i.44 = MEMORY/STORE_LE_32 [%i.4, %43]
 *     >> %45 = IMPLICIT_GOTO
 *     -> [block_6]
 *   block_6 LOOP_CONDITION  <- [block_5, block_8]:
 *          %i.4 = ALLOCA/LOCAL size=4 align=4
 *          %46 = MEMORY/LOAD_LE_32 [%i.4]  // i
 *          %47 = CONST/INT32 5  // 5
 *          %48 = CMP_LT [%46, %47]  // i < 5
 *     >> %49 = COND_BRANCH [%48]  // for (int i = 0; i < 5; i++) {         sum += i;...
 *     -> [block_7, block_9]
 *   block_9 LOOP_EXIT  <- [block_6]:
 *     >> %58 = EXIT_SCOPE  // for (int i = 0; i < 5; i++) {         sum += i;...
 *          %sum.3 = ALLOCA/LOCAL size=4 align=4
 *          %59 = MEMORY/LOAD_LE_32 [%sum.3]  // sum
 *          %60 = CONST/INT32 10  // 10
 *          %61 = CMP_NE [%59, %60]  // sum != 10
 *     >> %62 = COND_BRANCH [%61]  // if (sum != 10) return 2
 *     -> [block_10, block_11]
 *   block_11 IF_ELSE  <- [block_9]:
 *     >> %68 = IMPLICIT_GOTO
 *     -> [block_12]
 *   block_12 IF_MERGE  <- [block_11]:
 *          %total.5 = ALLOCA/LOCAL size=4 align=4
 *          %69 = CONST/INT32 0  // 0
 *     >> %total.70 = MEMORY/STORE_LE_32 [%total.5, %69]
 *     >> %71 = ENTER_SCOPE  // for (int i = 0; i < 3; i++) {         for (int ...
 *     >> %72 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 LOOP_PREHEADER  <- [block_12]:
 *          %i.6 = ALLOCA/LOCAL size=4 align=4
 *          %73 = CONST/INT32 0  // 0
 *     >> %i.74 = MEMORY/STORE_LE_32 [%i.6, %73]
 *     >> %75 = IMPLICIT_GOTO
 *     -> [block_14]
 *   block_14 LOOP_CONDITION  <- [block_13, block_16]:
 *          %i.6 = ALLOCA/LOCAL size=4 align=4
 *          %76 = MEMORY/LOAD_LE_32 [%i.6]  // i
 *          %77 = CONST/INT32 3  // 3
 *          %78 = CMP_LT [%76, %77]  // i < 3
 *     >> %79 = COND_BRANCH [%78]  // for (int i = 0; i < 3; i++) {         for (int ...
 *     -> [block_15, block_17]
 *   block_17 LOOP_EXIT  <- [block_14]:
 *     >> %104 = EXIT_SCOPE  // for (int i = 0; i < 3; i++) {         for (int ...
 *          %total.5 = ALLOCA/LOCAL size=4 align=4
 *          %105 = MEMORY/LOAD_LE_32 [%total.5]  // total
 *          %106 = CONST/INT32 6  // 6
 *          %107 = CMP_NE [%105, %106]  // total != 6
 *     >> %108 = COND_BRANCH [%107]  // if (total != 6) return 3
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_17]:
 *     >> %114 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *     >> %115 = ENTER_SCOPE  // {         int x = 42;         if (x == 42) {   ...
 *          %x.8 = ALLOCA/LOCAL size=4 align=4
 *          %116 = CONST/INT32 42  // 42
 *     >> %x.117 = MEMORY/STORE_LE_32 [%x.8, %116]
 *          %118 = MEMORY/LOAD_LE_32 [%x.8]  // x
 *          %119 = CONST/INT32 42  // 42
 *          %120 = CMP_EQ [%118, %119]  // x == 42
 *     >> %121 = COND_BRANCH [%120]  // if (x == 42) {             // All paths in this...
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %144 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_26 IF_THEN  <- [block_25]:
 *     >> %122 = ENTER_SCOPE  // {             // All paths in this scope return...
 *     >> %123 = ENTER_SCOPE  // {                 int y = x + 1;               ...
 *          %y.9 = ALLOCA/LOCAL size=4 align=4
 *          %x.8 = ALLOCA/LOCAL size=4 align=4
 *          %124 = MEMORY/LOAD_LE_32 [%x.8]  // x
 *          %125 = CONST/INT32 1  // 1
 *          %126 = ADD [%124, %125]  // x + 1
 *     >> %y.127 = MEMORY/STORE_LE_32 [%y.9, %126]
 *          %128 = MEMORY/LOAD_LE_32 [%y.9]  // y
 *          %129 = CONST/INT32 43  // 43
 *          %130 = CMP_NE [%128, %129]  // y != 43
 *     >> %131 = COND_BRANCH [%130]  // if (y != 43) return 5
 *     -> [block_28, block_29]
 *   block_29 IF_ELSE  <- [block_26]:
 *     >> %140 = IMPLICIT_GOTO
 *     -> [block_30]
 *   block_30 IF_MERGE  <- [block_29]:
 *     >> %141 = EXIT_SCOPE  // {                 int y = x + 1;               ...
 *     >> %142 = EXIT_SCOPE  // {             // All paths in this scope return...
 *     >> %143 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30, block_27]:
 *     >> %145 = EXIT_SCOPE  // {         int x = 42;         if (x == 42) {   ...
 *     >> %146 = ENTER_SCOPE  // {         int a = 5;         int b = 7;        ...
 *          %a.11 = ALLOCA/LOCAL size=4 align=4
 *          %147 = CONST/INT32 5  // 5
 *     >> %a.148 = MEMORY/STORE_LE_32 [%a.11, %147]
 *          %b.12 = ALLOCA/LOCAL size=4 align=4
 *          %149 = CONST/INT32 7  // 7
 *     >> %b.150 = MEMORY/STORE_LE_32 [%b.12, %149]
 *     >> %154 = EXIT_SCOPE  // {         int a = 5;         int b = 7;        ...
 *          %block_val.10 = ALLOCA/LOCAL size=4 align=4
 *          %151 = MEMORY/LOAD_LE_32 [%a.11]  // a
 *          %152 = MEMORY/LOAD_LE_32 [%b.12]  // b
 *          %153 = ADD [%151, %152]  // a + b
 *     >> %block_val.155 = MEMORY/STORE_LE_32 [%block_val.10, %153]
 *          %156 = MEMORY/LOAD_LE_32 [%block_val.10]  // block_val
 *          %157 = CONST/INT32 12  // 12
 *          %158 = CMP_NE [%156, %157]  // block_val != 12
 *     >> %159 = COND_BRANCH [%158]  // if (block_val != 12) return 4
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %165 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %167 = RETURN_PTR  // return 0
 *          %166 = CONST/INT32 0  // 0
 *     >> %168 = MEMORY/STORE_LE_32 [%167, %166]  // return 0
 *     >> %169 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *     >> %170 = RET [%166]  // return 0
 *   block_32 IF_THEN  <- [block_31]:
 *          %161 = RETURN_PTR  // return 4
 *          %160 = CONST/INT32 4  // 4
 *     >> %162 = MEMORY/STORE_LE_32 [%161, %160]  // return 4
 *     >> %163 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *     >> %164 = RET [%160]  // return 4
 *   block_28 IF_THEN  <- [block_26]:
 *          %133 = RETURN_PTR  // return 5
 *          %132 = CONST/INT32 5  // 5
 *     >> %134 = MEMORY/STORE_LE_32 [%133, %132]  // return 5
 *     >> %135 = EXIT_SCOPE  // {                 int y = x + 1;               ...
 *     >> %136 = EXIT_SCOPE  // {             // All paths in this scope return...
 *     >> %137 = EXIT_SCOPE  // {         int x = 42;         if (x == 42) {   ...
 *     >> %138 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *     >> %139 = RET [%132]  // return 5
 *   block_23 IF_THEN  <- [block_17]:
 *          %110 = RETURN_PTR  // return 3
 *          %109 = CONST/INT32 3  // 3
 *     >> %111 = MEMORY/STORE_LE_32 [%110, %109]  // return 3
 *     >> %112 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *     >> %113 = RET [%109]  // return 3
 *   block_15 LOOP_BODY  <- [block_14]:
 *     >> %80 = ENTER_SCOPE  // {         for (int i = 0; i < 2; i++) {        ...
 *     >> %81 = ENTER_SCOPE  // for (int i = 0; i < 2; i++) {             total...
 *     >> %82 = IMPLICIT_GOTO
 *     -> [block_18]
 *   block_18 LOOP_PREHEADER  <- [block_15]:
 *          %i.7 = ALLOCA/LOCAL size=4 align=4
 *          %83 = CONST/INT32 0  // 0
 *     >> %i.84 = MEMORY/STORE_LE_32 [%i.7, %83]
 *     >> %85 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 LOOP_CONDITION  <- [block_18, block_21]:
 *          %i.7 = ALLOCA/LOCAL size=4 align=4
 *          %86 = MEMORY/LOAD_LE_32 [%i.7]  // i
 *          %87 = CONST/INT32 2  // 2
 *          %88 = CMP_LT [%86, %87]  // i < 2
 *     >> %89 = COND_BRANCH [%88]  // for (int i = 0; i < 2; i++) {             total...
 *     -> [block_20, block_22]
 *   block_22 LOOP_EXIT  <- [block_19]:
 *     >> %98 = EXIT_SCOPE  // for (int i = 0; i < 2; i++) {             total...
 *     >> %99 = EXIT_SCOPE  // {         for (int i = 0; i < 2; i++) {        ...
 *     >> %100 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 LOOP_INCREMENT  <- [block_22]:
 *          %i.6 = ALLOCA/LOCAL size=4 align=4
 *          %101 = CONST/INT32 1  // i++
 *     >> %102 = READ_MODIFY_WRITE(ADD old) [%i.6, %101]  // i++
 *     >> %103 = IMPLICIT_GOTO
 *     -> [block_14]
 *   block_20 LOOP_BODY  <- [block_19]:
 *     >> %90 = ENTER_SCOPE  // {             total++;         }
 *          %total.5 = ALLOCA/LOCAL size=4 align=4
 *          %91 = CONST/INT32 1  // total++
 *     >> %92 = READ_MODIFY_WRITE(ADD old) [%total.5, %91]  // total++
 *     >> %93 = EXIT_SCOPE  // {             total++;         }
 *     >> %94 = IMPLICIT_GOTO
 *     -> [block_21]
 *   block_21 LOOP_INCREMENT  <- [block_20]:
 *          %i.7 = ALLOCA/LOCAL size=4 align=4
 *          %95 = CONST/INT32 1  // i++
 *     >> %96 = READ_MODIFY_WRITE(ADD old) [%i.7, %95]  // i++
 *     >> %97 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_10 IF_THEN  <- [block_9]:
 *          %64 = RETURN_PTR  // return 2
 *          %63 = CONST/INT32 2  // 2
 *     >> %65 = MEMORY/STORE_LE_32 [%64, %63]  // return 2
 *     >> %66 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *     >> %67 = RET [%63]  // return 2
 *   block_7 LOOP_BODY  <- [block_6]:
 *     >> %50 = ENTER_SCOPE  // {         sum += i;     }
 *          %sum.3 = ALLOCA/LOCAL size=4 align=4
 *          %i.4 = ALLOCA/LOCAL size=4 align=4
 *          %51 = MEMORY/LOAD_LE_32 [%i.4]  // i
 *     >> %52 = READ_MODIFY_WRITE(ADD new) [%sum.3, %51]  // sum += i
 *     >> %53 = EXIT_SCOPE  // {         sum += i;     }
 *     >> %54 = IMPLICIT_GOTO
 *     -> [block_8]
 *   block_8 LOOP_INCREMENT  <- [block_7]:
 *          %i.4 = ALLOCA/LOCAL size=4 align=4
 *          %55 = CONST/INT32 1  // i++
 *     >> %56 = READ_MODIFY_WRITE(ADD old) [%i.4, %55]  // i++
 *     >> %57 = IMPLICIT_GOTO
 *     -> [block_6]
 *   block_2 IF_THEN  <- [block_1]:
 *          %34 = RETURN_PTR  // return 1
 *          %33 = CONST/INT32 1  // 1
 *     >> %35 = MEMORY/STORE_LE_32 [%34, %33]  // return 1
 *     >> %36 = EXIT_SCOPE  // {     int result = 0;      // Nested scopes wit...
 *     >> %37 = RET [%33]  // return 1
 * }
 */










int test_scopes(void) {
    int result = 0;

    // Nested scopes with same variable names.
    {
        int x = 10;
        result += x;
    }
    {
        int x = 20;
        result += x;
    }
    if (result != 30) return 1;

    // For-init scope: 'i' is scoped to the for loop.
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += i;
    }
    if (sum != 10) return 2;

    // Nested for loops with same variable name.
    int total = 0;
    for (int i = 0; i < 3; i++) {
        for (int i = 0; i < 2; i++) {
            total++;
        }
    }
    if (total != 6) return 3;

    // Early return inside a nested scope: the scope's EXIT_SCOPE must
    // not be emitted after the return terminator.
    {
        int x = 42;
        if (x == 42) {
            // All paths in this scope return; the scope exit is handled
            // by the return paths themselves.
            {
                int y = x + 1;
                if (y != 43) return 5;
            }
        }
    }
    // If we get here, the scope nesting was handled correctly.

    // GNU block expression.
    int block_val = ({
        int a = 5;
        int b = 7;
        a + b;
    });
    if (block_val != 12) return 4;

    return 0;
}
