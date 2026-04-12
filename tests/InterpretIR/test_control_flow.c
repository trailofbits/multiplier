// Tests: if/else (COND_BRANCH), while loop (LOOP_PREHEADER, LOOP_CONDITION,
// LOOP_BODY, LOOP_EXIT), for loop (FOR_INIT, LOOP_INCREMENT), do-while,
// break (BREAK), continue (CONTINUE), nested loops, early return (RET),
// and the ternary operator (SELECT).

/*
 * Expected IR:
 *
 * function test_control_flow (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=4 align=4 (result)
 *     obj_1 LOCAL_VALUE size=4 align=4 (sum)
 *     obj_2 LOCAL_VALUE size=4 align=4 (i)
 *     obj_3 LOCAL_VALUE size=4 align=4 (fact)
 *     obj_4 LOCAL_VALUE size=4 align=4 (j)
 *     obj_5 LOCAL_VALUE size=4 align=4 (count)
 *     obj_6 LOCAL_VALUE size=4 align=4 (brk)
 *     obj_7 LOCAL_VALUE size=4 align=4 (k)
 *     obj_8 LOCAL_VALUE size=4 align=4 (cont)
 *     obj_9 LOCAL_VALUE size=4 align=4 (k)
 *     obj_10 LOCAL_VALUE size=4 align=4 (nested)
 *     obj_11 LOCAL_VALUE size=4 align=4 (a)
 *     obj_12 LOCAL_VALUE size=4 align=4 (b)
 *     obj_13 LOCAL_VALUE size=4 align=4 (sel)
 *     obj_14 LOCAL_VALUE size=4 align=4 (inner)
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %result.0 = ALLOCA/LOCAL size=4 align=4
 *     >> %sum.1 = ALLOCA/LOCAL size=4 align=4
 *     >> %i.2 = ALLOCA/LOCAL size=4 align=4
 *     >> %fact.3 = ALLOCA/LOCAL size=4 align=4
 *     >> %j.4 = ALLOCA/LOCAL size=4 align=4
 *     >> %count.5 = ALLOCA/LOCAL size=4 align=4
 *     >> %brk.6 = ALLOCA/LOCAL size=4 align=4
 *     >> %k.7 = ALLOCA/LOCAL size=4 align=4
 *     >> %cont.8 = ALLOCA/LOCAL size=4 align=4
 *     >> %k.9 = ALLOCA/LOCAL size=4 align=4
 *     >> %nested.10 = ALLOCA/LOCAL size=4 align=4
 *     >> %a.11 = ALLOCA/LOCAL size=4 align=4
 *     >> %b.12 = ALLOCA/LOCAL size=4 align=4
 *     >> %sel.13 = ALLOCA/LOCAL size=4 align=4
 *     >> %inner.14 = ALLOCA/LOCAL size=4 align=4
 *     >> %15 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %16 = ENTER_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %17 = CONST/INT32 0  // 0
 *     >> %result.18 = MEMORY/STORE_LE_32 [%result.0, %17]
 *          %19 = CONST/INT32 1  // 1
 *     >> %20 = COND_BRANCH [%19]  // if (1) result = 1;     else result = -1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %24 = CONST/INT32 1  // 1
 *          %25 = NEG [%24]  // -1
 *     >> %26 = MEMORY/STORE_LE_32 [%result.0, %25]  // result = -1
 *     >> %27 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_2 IF_THEN  <- [block_1]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %21 = CONST/INT32 1  // 1
 *     >> %22 = MEMORY/STORE_LE_32 [%result.0, %21]  // result = 1
 *     >> %23 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_2, block_3]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=4
 *          %28 = MEMORY/LOAD_LE_32 [%result.0]  // result
 *          %29 = CONST/INT32 1  // 1
 *          %30 = CMP_NE [%28, %29]  // result != 1
 *     >> %31 = COND_BRANCH [%30]  // if (result != 1) return 1
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %37 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %sum.1 = ALLOCA/LOCAL size=4 align=4
 *          %38 = CONST/INT32 0  // 0
 *     >> %sum.39 = MEMORY/STORE_LE_32 [%sum.1, %38]
 *          %i.2 = ALLOCA/LOCAL size=4 align=4
 *          %40 = CONST/INT32 1  // 1
 *     >> %i.41 = MEMORY/STORE_LE_32 [%i.2, %40]
 *     >> %42 = IMPLICIT_GOTO
 *     -> [block_8]
 *   block_8 LOOP_PREHEADER  <- [block_7]:
 *     >> %43 = IMPLICIT_GOTO
 *     -> [block_9]
 *   block_9 LOOP_CONDITION  <- [block_8, block_10]:
 *          %i.2 = ALLOCA/LOCAL size=4 align=4
 *          %44 = MEMORY/LOAD_LE_32 [%i.2]  // i
 *          %45 = CONST/INT32 5  // 5
 *          %46 = CMP_LE [%44, %45]  // i <= 5
 *     >> %47 = COND_BRANCH [%46]  // while (i <= 5) {         sum += i;         i++;...
 *     -> [block_10, block_11]
 *   block_11 LOOP_EXIT  <- [block_9]:
 *          %sum.1 = ALLOCA/LOCAL size=4 align=4
 *          %55 = MEMORY/LOAD_LE_32 [%sum.1]  // sum
 *          %56 = CONST/INT32 15  // 15
 *          %57 = CMP_NE [%55, %56]  // sum != 15
 *     >> %58 = COND_BRANCH [%57]  // if (sum != 15) return 2
 *     -> [block_12, block_13]
 *   block_13 IF_ELSE  <- [block_11]:
 *     >> %64 = IMPLICIT_GOTO
 *     -> [block_14]
 *   block_14 IF_MERGE  <- [block_13]:
 *          %fact.3 = ALLOCA/LOCAL size=4 align=4
 *          %65 = CONST/INT32 1  // 1
 *     >> %fact.66 = MEMORY/STORE_LE_32 [%fact.3, %65]
 *     >> %67 = ENTER_SCOPE  // for (int j = 1; j <= 5; j++) {         fact *= ...
 *     >> %68 = IMPLICIT_GOTO
 *     -> [block_15]
 *   block_15 LOOP_PREHEADER  <- [block_14]:
 *          %j.4 = ALLOCA/LOCAL size=4 align=4
 *          %69 = CONST/INT32 1  // 1
 *     >> %j.70 = MEMORY/STORE_LE_32 [%j.4, %69]
 *     >> %71 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 LOOP_CONDITION  <- [block_15, block_18]:
 *          %j.4 = ALLOCA/LOCAL size=4 align=4
 *          %72 = MEMORY/LOAD_LE_32 [%j.4]  // j
 *          %73 = CONST/INT32 5  // 5
 *          %74 = CMP_LE [%72, %73]  // j <= 5
 *     >> %75 = COND_BRANCH [%74]  // for (int j = 1; j <= 5; j++) {         fact *= ...
 *     -> [block_17, block_19]
 *   block_19 LOOP_EXIT  <- [block_16]:
 *     >> %84 = EXIT_SCOPE  // for (int j = 1; j <= 5; j++) {         fact *= ...
 *          %fact.3 = ALLOCA/LOCAL size=4 align=4
 *          %85 = MEMORY/LOAD_LE_32 [%fact.3]  // fact
 *          %86 = CONST/INT32 120  // 120
 *          %87 = CMP_NE [%85, %86]  // fact != 120
 *     >> %88 = COND_BRANCH [%87]  // if (fact != 120) return 3
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %94 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %count.5 = ALLOCA/LOCAL size=4 align=4
 *          %95 = CONST/INT32 0  // 0
 *     >> %count.96 = MEMORY/STORE_LE_32 [%count.5, %95]
 *     >> %97 = IMPLICIT_GOTO
 *     -> [block_23]
 *   block_23 LOOP_PREHEADER  <- [block_22]:
 *     >> %98 = IMPLICIT_GOTO
 *     -> [block_24]
 *   block_24 LOOP_BODY  <- [block_23, block_25]:
 *     >> %99 = ENTER_SCOPE  // {         count++;     }
 *          %count.5 = ALLOCA/LOCAL size=4 align=4
 *          %100 = CONST/INT32 1  // count++
 *     >> %101 = READ_MODIFY_WRITE(ADD old) [%count.5, %100]  // count++
 *     >> %102 = EXIT_SCOPE  // {         count++;     }
 *     >> %103 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 LOOP_CONDITION  <- [block_24]:
 *          %count.5 = ALLOCA/LOCAL size=4 align=4
 *          %104 = MEMORY/LOAD_LE_32 [%count.5]  // count
 *          %105 = CONST/INT32 3  // 3
 *          %106 = CMP_LT [%104, %105]  // count < 3
 *     >> %107 = COND_BRANCH [%106]  // do {         count++;     } while (count < 3)
 *     -> [block_24, block_26]
 *   block_26 LOOP_EXIT  <- [block_25]:
 *          %count.5 = ALLOCA/LOCAL size=4 align=4
 *          %108 = MEMORY/LOAD_LE_32 [%count.5]  // count
 *          %109 = CONST/INT32 3  // 3
 *          %110 = CMP_NE [%108, %109]  // count != 3
 *     >> %111 = COND_BRANCH [%110]  // if (count != 3) return 4
 *     -> [block_27, block_28]
 *   block_28 IF_ELSE  <- [block_26]:
 *     >> %117 = IMPLICIT_GOTO
 *     -> [block_29]
 *   block_29 IF_MERGE  <- [block_28]:
 *          %brk.6 = ALLOCA/LOCAL size=4 align=4
 *          %118 = CONST/INT32 0  // 0
 *     >> %brk.119 = MEMORY/STORE_LE_32 [%brk.6, %118]
 *     >> %120 = ENTER_SCOPE  // for (int k = 0; k < 100; k++) {         if (k =...
 *     >> %121 = IMPLICIT_GOTO
 *     -> [block_30]
 *   block_30 LOOP_PREHEADER  <- [block_29]:
 *          %k.7 = ALLOCA/LOCAL size=4 align=4
 *          %122 = CONST/INT32 0  // 0
 *     >> %k.123 = MEMORY/STORE_LE_32 [%k.7, %122]
 *     >> %124 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 LOOP_CONDITION  <- [block_30, block_33]:
 *          %k.7 = ALLOCA/LOCAL size=4 align=4
 *          %125 = MEMORY/LOAD_LE_32 [%k.7]  // k
 *          %126 = CONST/INT32 100  // 100
 *          %127 = CMP_LT [%125, %126]  // k < 100
 *     >> %128 = COND_BRANCH [%127]  // for (int k = 0; k < 100; k++) {         if (k =...
 *     -> [block_32, block_34]
 *   block_32 LOOP_BODY  <- [block_31]:
 *     >> %129 = ENTER_SCOPE  // {         if (k == 5) break;         brk++;     }
 *          %k.7 = ALLOCA/LOCAL size=4 align=4
 *          %130 = MEMORY/LOAD_LE_32 [%k.7]  // k
 *          %131 = CONST/INT32 5  // 5
 *          %132 = CMP_EQ [%130, %131]  // k == 5
 *     >> %133 = COND_BRANCH [%132]  // if (k == 5) break
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_32]:
 *     >> %137 = IMPLICIT_GOTO
 *     -> [block_38]
 *   block_38 IF_MERGE  <- [block_36]:
 *          %brk.6 = ALLOCA/LOCAL size=4 align=4
 *          %138 = CONST/INT32 1  // brk++
 *     >> %139 = READ_MODIFY_WRITE(ADD old) [%brk.6, %138]  // brk++
 *     >> %140 = EXIT_SCOPE  // {         if (k == 5) break;         brk++;     }
 *     >> %141 = IMPLICIT_GOTO
 *     -> [block_33]
 *   block_33 LOOP_INCREMENT  <- [block_38]:
 *          %k.7 = ALLOCA/LOCAL size=4 align=4
 *          %142 = CONST/INT32 1  // k++
 *     >> %143 = READ_MODIFY_WRITE(ADD old) [%k.7, %142]  // k++
 *     >> %144 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_35 IF_THEN  <- [block_32]:
 *     >> %134 = EXIT_SCOPE  // {         if (k == 5) break;         brk++;     }
 *     >> %135 = BREAK  // break
 *     -> [block_34]
 *   block_34 LOOP_EXIT  <- [block_31, block_35]:
 *     >> %145 = EXIT_SCOPE  // for (int k = 0; k < 100; k++) {         if (k =...
 *          %brk.6 = ALLOCA/LOCAL size=4 align=4
 *          %146 = MEMORY/LOAD_LE_32 [%brk.6]  // brk
 *          %147 = CONST/INT32 5  // 5
 *          %148 = CMP_NE [%146, %147]  // brk != 5
 *     >> %149 = COND_BRANCH [%148]  // if (brk != 5) return 5
 *     -> [block_39, block_40]
 *   block_40 IF_ELSE  <- [block_34]:
 *     >> %155 = IMPLICIT_GOTO
 *     -> [block_41]
 *   block_41 IF_MERGE  <- [block_40]:
 *          %cont.8 = ALLOCA/LOCAL size=4 align=4
 *          %156 = CONST/INT32 0  // 0
 *     >> %cont.157 = MEMORY/STORE_LE_32 [%cont.8, %156]
 *     >> %158 = ENTER_SCOPE  // for (int k = 0; k < 10; k++) {         if (k % ...
 *     >> %159 = IMPLICIT_GOTO
 *     -> [block_42]
 *   block_42 LOOP_PREHEADER  <- [block_41]:
 *          %k.9 = ALLOCA/LOCAL size=4 align=4
 *          %160 = CONST/INT32 0  // 0
 *     >> %k.161 = MEMORY/STORE_LE_32 [%k.9, %160]
 *     >> %162 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 LOOP_CONDITION  <- [block_42, block_45]:
 *          %k.9 = ALLOCA/LOCAL size=4 align=4
 *          %163 = MEMORY/LOAD_LE_32 [%k.9]  // k
 *          %164 = CONST/INT32 10  // 10
 *          %165 = CMP_LT [%163, %164]  // k < 10
 *     >> %166 = COND_BRANCH [%165]  // for (int k = 0; k < 10; k++) {         if (k % ...
 *     -> [block_44, block_46]
 *   block_46 LOOP_EXIT  <- [block_43]:
 *     >> %185 = EXIT_SCOPE  // for (int k = 0; k < 10; k++) {         if (k % ...
 *          %cont.8 = ALLOCA/LOCAL size=4 align=4
 *          %186 = MEMORY/LOAD_LE_32 [%cont.8]  // cont
 *          %187 = CONST/INT32 5  // 5
 *          %188 = CMP_NE [%186, %187]  // cont != 5
 *     >> %189 = COND_BRANCH [%188]  // if (cont != 5) return 6
 *     -> [block_51, block_52]
 *   block_52 IF_ELSE  <- [block_46]:
 *     >> %195 = IMPLICIT_GOTO
 *     -> [block_53]
 *   block_53 IF_MERGE  <- [block_52]:
 *          %nested.10 = ALLOCA/LOCAL size=4 align=4
 *          %196 = CONST/INT32 0  // 0
 *     >> %nested.197 = MEMORY/STORE_LE_32 [%nested.10, %196]
 *     >> %198 = ENTER_SCOPE  // for (int a = 0; a < 3; a++) {         for (int ...
 *     >> %199 = IMPLICIT_GOTO
 *     -> [block_54]
 *   block_54 LOOP_PREHEADER  <- [block_53]:
 *          %a.11 = ALLOCA/LOCAL size=4 align=4
 *          %200 = CONST/INT32 0  // 0
 *     >> %a.201 = MEMORY/STORE_LE_32 [%a.11, %200]
 *     >> %202 = IMPLICIT_GOTO
 *     -> [block_55]
 *   block_55 LOOP_CONDITION  <- [block_54, block_57]:
 *          %a.11 = ALLOCA/LOCAL size=4 align=4
 *          %203 = MEMORY/LOAD_LE_32 [%a.11]  // a
 *          %204 = CONST/INT32 3  // 3
 *          %205 = CMP_LT [%203, %204]  // a < 3
 *     >> %206 = COND_BRANCH [%205]  // for (int a = 0; a < 3; a++) {         for (int ...
 *     -> [block_56, block_58]
 *   block_58 LOOP_EXIT  <- [block_55]:
 *     >> %231 = EXIT_SCOPE  // for (int a = 0; a < 3; a++) {         for (int ...
 *          %nested.10 = ALLOCA/LOCAL size=4 align=4
 *          %232 = MEMORY/LOAD_LE_32 [%nested.10]  // nested
 *          %233 = CONST/INT32 9  // 9
 *          %234 = CMP_NE [%232, %233]  // nested != 9
 *     >> %235 = COND_BRANCH [%234]  // if (nested != 9) return 7
 *     -> [block_64, block_65]
 *   block_65 IF_ELSE  <- [block_58]:
 *     >> %241 = IMPLICIT_GOTO
 *     -> [block_66]
 *   block_66 IF_MERGE  <- [block_65]:
 *          %sel.13 = ALLOCA/LOCAL size=4 align=4
 *          %242 = CONST/INT32 1  // 1
 *          %243 = CONST/INT32 0  // 0
 *          %244 = CMP_GT [%242, %243]  // 1 > 0
 *          %245 = CONST/INT32 42  // 42
 *          %246 = CONST/INT32 1  // 1
 *          %247 = NEG [%246]  // -1
 *          %248 = SELECT [%244, %245, %247]  // (1 > 0) ? 42 : -1
 *     >> %sel.249 = MEMORY/STORE_LE_32 [%sel.13, %248]
 *          %250 = MEMORY/LOAD_LE_32 [%sel.13]  // sel
 *          %251 = CONST/INT32 42  // 42
 *          %252 = CMP_NE [%250, %251]  // sel != 42
 *     >> %253 = COND_BRANCH [%252]  // if (sel != 42) return 8
 *     -> [block_67, block_68]
 *   block_68 IF_ELSE  <- [block_66]:
 *     >> %259 = IMPLICIT_GOTO
 *     -> [block_69]
 *   block_69 IF_MERGE  <- [block_68]:
 *     >> %260 = ENTER_SCOPE  // {         int inner = 0;         {             ...
 *          %inner.14 = ALLOCA/LOCAL size=4 align=4
 *          %261 = CONST/INT32 0  // 0
 *     >> %inner.262 = MEMORY/STORE_LE_32 [%inner.14, %261]
 *     >> %263 = ENTER_SCOPE  // {             inner = 77;             if (inner...
 *          %264 = CONST/INT32 77  // 77
 *     >> %265 = MEMORY/STORE_LE_32 [%inner.14, %264]  // inner = 77
 *          %266 = MEMORY/LOAD_LE_32 [%inner.14]  // inner
 *          %267 = CONST/INT32 77  // 77
 *          %268 = CMP_EQ [%266, %267]  // inner == 77
 *     >> %269 = COND_BRANCH [%268]  // if (inner == 77) return 0
 *     -> [block_70, block_71]
 *   block_71 IF_ELSE  <- [block_69]:
 *     >> %277 = IMPLICIT_GOTO
 *     -> [block_72]
 *   block_72 IF_MERGE  <- [block_71]:
 *          %inner.14 = ALLOCA/LOCAL size=4 align=4
 *          %278 = CONST/INT32 1  // 1
 *          %279 = NEG [%278]  // -1
 *     >> %280 = MEMORY/STORE_LE_32 [%inner.14, %279]  // inner = -1
 *     >> %281 = EXIT_SCOPE  // {             inner = 77;             if (inner...
 *          %282 = CONST/INT32 1  // 1
 *          %283 = NEG [%282]  // -1
 *     >> %284 = MEMORY/STORE_LE_32 [%inner.14, %283]  // inner = -1
 *     >> %285 = EXIT_SCOPE  // {         int inner = 0;         {             ...
 *          %287 = RETURN_PTR  // return 0
 *          %286 = CONST/INT32 0  // 0
 *     >> %288 = MEMORY/STORE_LE_32 [%287, %286]  // return 0
 *     >> %289 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *     >> %290 = RET [%286]  // return 0
 *   block_70 IF_THEN  <- [block_69]:
 *          %271 = RETURN_PTR  // return 0
 *          %270 = CONST/INT32 0  // 0
 *     >> %272 = MEMORY/STORE_LE_32 [%271, %270]  // return 0
 *     >> %273 = EXIT_SCOPE  // {             inner = 77;             if (inner...
 *     >> %274 = EXIT_SCOPE  // {         int inner = 0;         {             ...
 *     >> %275 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *     >> %276 = RET [%270]  // return 0
 *   block_67 IF_THEN  <- [block_66]:
 *          %255 = RETURN_PTR  // return 8
 *          %254 = CONST/INT32 8  // 8
 *     >> %256 = MEMORY/STORE_LE_32 [%255, %254]  // return 8
 *     >> %257 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *     >> %258 = RET [%254]  // return 8
 *   block_64 IF_THEN  <- [block_58]:
 *          %237 = RETURN_PTR  // return 7
 *          %236 = CONST/INT32 7  // 7
 *     >> %238 = MEMORY/STORE_LE_32 [%237, %236]  // return 7
 *     >> %239 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *     >> %240 = RET [%236]  // return 7
 *   block_56 LOOP_BODY  <- [block_55]:
 *     >> %207 = ENTER_SCOPE  // {         for (int b = 0; b < 3; b++) {        ...
 *     >> %208 = ENTER_SCOPE  // for (int b = 0; b < 3; b++) {             neste...
 *     >> %209 = IMPLICIT_GOTO
 *     -> [block_59]
 *   block_59 LOOP_PREHEADER  <- [block_56]:
 *          %b.12 = ALLOCA/LOCAL size=4 align=4
 *          %210 = CONST/INT32 0  // 0
 *     >> %b.211 = MEMORY/STORE_LE_32 [%b.12, %210]
 *     >> %212 = IMPLICIT_GOTO
 *     -> [block_60]
 *   block_60 LOOP_CONDITION  <- [block_59, block_62]:
 *          %b.12 = ALLOCA/LOCAL size=4 align=4
 *          %213 = MEMORY/LOAD_LE_32 [%b.12]  // b
 *          %214 = CONST/INT32 3  // 3
 *          %215 = CMP_LT [%213, %214]  // b < 3
 *     >> %216 = COND_BRANCH [%215]  // for (int b = 0; b < 3; b++) {             neste...
 *     -> [block_61, block_63]
 *   block_63 LOOP_EXIT  <- [block_60]:
 *     >> %225 = EXIT_SCOPE  // for (int b = 0; b < 3; b++) {             neste...
 *     >> %226 = EXIT_SCOPE  // {         for (int b = 0; b < 3; b++) {        ...
 *     >> %227 = IMPLICIT_GOTO
 *     -> [block_57]
 *   block_57 LOOP_INCREMENT  <- [block_63]:
 *          %a.11 = ALLOCA/LOCAL size=4 align=4
 *          %228 = CONST/INT32 1  // a++
 *     >> %229 = READ_MODIFY_WRITE(ADD old) [%a.11, %228]  // a++
 *     >> %230 = IMPLICIT_GOTO
 *     -> [block_55]
 *   block_61 LOOP_BODY  <- [block_60]:
 *     >> %217 = ENTER_SCOPE  // {             nested++;         }
 *          %nested.10 = ALLOCA/LOCAL size=4 align=4
 *          %218 = CONST/INT32 1  // nested++
 *     >> %219 = READ_MODIFY_WRITE(ADD old) [%nested.10, %218]  // nested++
 *     >> %220 = EXIT_SCOPE  // {             nested++;         }
 *     >> %221 = IMPLICIT_GOTO
 *     -> [block_62]
 *   block_62 LOOP_INCREMENT  <- [block_61]:
 *          %b.12 = ALLOCA/LOCAL size=4 align=4
 *          %222 = CONST/INT32 1  // b++
 *     >> %223 = READ_MODIFY_WRITE(ADD old) [%b.12, %222]  // b++
 *     >> %224 = IMPLICIT_GOTO
 *     -> [block_60]
 *   block_51 IF_THEN  <- [block_46]:
 *          %191 = RETURN_PTR  // return 6
 *          %190 = CONST/INT32 6  // 6
 *     >> %192 = MEMORY/STORE_LE_32 [%191, %190]  // return 6
 *     >> %193 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *     >> %194 = RET [%190]  // return 6
 *   block_44 LOOP_BODY  <- [block_43]:
 *     >> %167 = ENTER_SCOPE  // {         if (k % 2 == 0) continue;         con...
 *          %k.9 = ALLOCA/LOCAL size=4 align=4
 *          %168 = MEMORY/LOAD_LE_32 [%k.9]  // k
 *          %169 = CONST/INT32 2  // 2
 *          %170 = REM [%168, %169]  // k % 2
 *          %171 = CONST/INT32 0  // 0
 *          %172 = CMP_EQ [%170, %171]  // k % 2 == 0
 *     >> %173 = COND_BRANCH [%172]  // if (k % 2 == 0) continue
 *     -> [block_47, block_48]
 *   block_48 IF_ELSE  <- [block_44]:
 *     >> %177 = IMPLICIT_GOTO
 *     -> [block_50]
 *   block_50 IF_MERGE  <- [block_48]:
 *          %cont.8 = ALLOCA/LOCAL size=4 align=4
 *          %178 = CONST/INT32 1  // cont++
 *     >> %179 = READ_MODIFY_WRITE(ADD old) [%cont.8, %178]  // cont++
 *     >> %180 = EXIT_SCOPE  // {         if (k % 2 == 0) continue;         con...
 *     >> %181 = IMPLICIT_GOTO
 *     -> [block_45]
 *   block_47 IF_THEN  <- [block_44]:
 *     >> %174 = EXIT_SCOPE  // {         if (k % 2 == 0) continue;         con...
 *     >> %175 = CONTINUE  // continue
 *     -> [block_45]
 *   block_45 LOOP_INCREMENT  <- [block_47, block_50]:
 *          %k.9 = ALLOCA/LOCAL size=4 align=4
 *          %182 = CONST/INT32 1  // k++
 *     >> %183 = READ_MODIFY_WRITE(ADD old) [%k.9, %182]  // k++
 *     >> %184 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_39 IF_THEN  <- [block_34]:
 *          %151 = RETURN_PTR  // return 5
 *          %150 = CONST/INT32 5  // 5
 *     >> %152 = MEMORY/STORE_LE_32 [%151, %150]  // return 5
 *     >> %153 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *     >> %154 = RET [%150]  // return 5
 *   block_27 IF_THEN  <- [block_26]:
 *          %113 = RETURN_PTR  // return 4
 *          %112 = CONST/INT32 4  // 4
 *     >> %114 = MEMORY/STORE_LE_32 [%113, %112]  // return 4
 *     >> %115 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *     >> %116 = RET [%112]  // return 4
 *   block_20 IF_THEN  <- [block_19]:
 *          %90 = RETURN_PTR  // return 3
 *          %89 = CONST/INT32 3  // 3
 *     >> %91 = MEMORY/STORE_LE_32 [%90, %89]  // return 3
 *     >> %92 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *     >> %93 = RET [%89]  // return 3
 *   block_17 LOOP_BODY  <- [block_16]:
 *     >> %76 = ENTER_SCOPE  // {         fact *= j;     }
 *          %fact.3 = ALLOCA/LOCAL size=4 align=4
 *          %j.4 = ALLOCA/LOCAL size=4 align=4
 *          %77 = MEMORY/LOAD_LE_32 [%j.4]  // j
 *     >> %78 = READ_MODIFY_WRITE(MUL new) [%fact.3, %77]  // fact *= j
 *     >> %79 = EXIT_SCOPE  // {         fact *= j;     }
 *     >> %80 = IMPLICIT_GOTO
 *     -> [block_18]
 *   block_18 LOOP_INCREMENT  <- [block_17]:
 *          %j.4 = ALLOCA/LOCAL size=4 align=4
 *          %81 = CONST/INT32 1  // j++
 *     >> %82 = READ_MODIFY_WRITE(ADD old) [%j.4, %81]  // j++
 *     >> %83 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_12 IF_THEN  <- [block_11]:
 *          %60 = RETURN_PTR  // return 2
 *          %59 = CONST/INT32 2  // 2
 *     >> %61 = MEMORY/STORE_LE_32 [%60, %59]  // return 2
 *     >> %62 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *     >> %63 = RET [%59]  // return 2
 *   block_10 LOOP_BODY  <- [block_9]:
 *     >> %48 = ENTER_SCOPE  // {         sum += i;         i++;     }
 *          %sum.1 = ALLOCA/LOCAL size=4 align=4
 *          %i.2 = ALLOCA/LOCAL size=4 align=4
 *          %49 = MEMORY/LOAD_LE_32 [%i.2]  // i
 *     >> %50 = READ_MODIFY_WRITE(ADD new) [%sum.1, %49]  // sum += i
 *          %51 = CONST/INT32 1  // i++
 *     >> %52 = READ_MODIFY_WRITE(ADD old) [%i.2, %51]  // i++
 *     >> %53 = EXIT_SCOPE  // {         sum += i;         i++;     }
 *     >> %54 = IMPLICIT_GOTO
 *     -> [block_9]
 *   block_5 IF_THEN  <- [block_4]:
 *          %33 = RETURN_PTR  // return 1
 *          %32 = CONST/INT32 1  // 1
 *     >> %34 = MEMORY/STORE_LE_32 [%33, %32]  // return 1
 *     >> %35 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *     >> %36 = RET [%32]  // return 1
 * }
 */










int test_control_flow(void) {
    int result = 0;

    // If/else.
    if (1) result = 1;
    else result = -1;
    if (result != 1) return 1;

    // While loop: sum 1..5.
    int sum = 0;
    int i = 1;
    while (i <= 5) {
        sum += i;
        i++;
    }
    if (sum != 15) return 2;

    // For loop: factorial of 5.
    int fact = 1;
    for (int j = 1; j <= 5; j++) {
        fact *= j;
    }
    if (fact != 120) return 3;

    // Do-while: count to 3.
    int count = 0;
    do {
        count++;
    } while (count < 3);
    if (count != 3) return 4;

    // Break.
    int brk = 0;
    for (int k = 0; k < 100; k++) {
        if (k == 5) break;
        brk++;
    }
    if (brk != 5) return 5;

    // Continue.
    int cont = 0;
    for (int k = 0; k < 10; k++) {
        if (k % 2 == 0) continue;
        cont++;
    }
    if (cont != 5) return 6;

    // Nested loops.
    int nested = 0;
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            nested++;
        }
    }
    if (nested != 9) return 7;

    // Ternary (SELECT).
    int sel = (1 > 0) ? 42 : -1;
    if (sel != 42) return 8;

    // Early return inside nested scopes: exercises EXIT_SCOPE placement.
    // If EXIT_SCOPE is emitted after the return terminator, verification fails.
    {
        int inner = 0;
        {
            inner = 77;
            if (inner == 77) return 0;  // early return from nested scope
            inner = -1;  // dead code
        }
        inner = -1;  // also dead
    }

    return 0;
}
