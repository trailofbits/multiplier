// Tests: if/else (COND_BRANCH), while loop (LOOP_PREHEADER, LOOP_CONDITION,
// LOOP_BODY, LOOP_EXIT), for loop (FOR_INIT, LOOP_INCREMENT), do-while,
// break (BREAK), continue (CONTINUE), nested loops, early return (RET),
// and the ternary operator (SELECT).

/*
 * Expected IR:
 *
 * function test_control_flow (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=4 align=1 (result)
 *     obj_1 LOCAL_VALUE size=4 align=1 (sum)
 *     obj_2 LOCAL_VALUE size=4 align=1 (i)
 *     obj_3 LOCAL_VALUE size=4 align=1 (fact)
 *     obj_4 LOCAL_VALUE size=4 align=1 (j)
 *     obj_5 LOCAL_VALUE size=4 align=1 (count)
 *     obj_6 LOCAL_VALUE size=4 align=1 (brk)
 *     obj_7 LOCAL_VALUE size=4 align=1 (k)
 *     obj_8 LOCAL_VALUE size=4 align=1 (cont)
 *     obj_9 LOCAL_VALUE size=4 align=1 (k)
 *     obj_10 LOCAL_VALUE size=4 align=1 (nested)
 *     obj_11 LOCAL_VALUE size=4 align=1 (a)
 *     obj_12 LOCAL_VALUE size=4 align=1 (b)
 *     obj_13 LOCAL_VALUE size=4 align=1 (sel)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %14 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %15 = ENTER_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %16 = CONST/INT32 0  // 0
 *     >> %result.17 = MEMORY/STORE_LE_32 [%result.0, %16]
 *          %18 = CONST/INT32 1  // 1
 *     >> %19 = COND_BRANCH [%18]  // if (1) result = 1;     else result = -1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %24 = NEG [%23]  // -1
 *     >> %25 = MEMORY/STORE_LE_32 [%result.0, %24]  // result = -1
 *     >> %26 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_2 IF_THEN  <- [block_1]:
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %20 = CONST/INT32 1  // 1
 *     >> %21 = MEMORY/STORE_LE_32 [%result.0, %20]  // result = 1
 *     >> %22 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_2, block_3]:
 *          %29 = CMP_NE [%27, %28]  // result != 1
 *     >> %30 = COND_BRANCH [%29]  // if (result != 1) return 1
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %36 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %sum.1 = ALLOCA/LOCAL size=4 align=1
 *          %37 = CONST/INT32 0  // 0
 *     >> %sum.38 = MEMORY/STORE_LE_32 [%sum.1, %37]
 *          %i.2 = ALLOCA/LOCAL size=4 align=1
 *          %39 = CONST/INT32 1  // 1
 *     >> %i.40 = MEMORY/STORE_LE_32 [%i.2, %39]
 *     >> %41 = IMPLICIT_GOTO
 *     -> [block_8]
 *   block_8 LOOP_PREHEADER  <- [block_7]:
 *     >> %42 = IMPLICIT_GOTO
 *     -> [block_9]
 *   block_9 LOOP_CONDITION  <- [block_8, block_10]:
 *          %45 = CMP_LE [%43, %44]  // i <= 5
 *     >> %46 = COND_BRANCH [%45]  // while (i <= 5) {         sum += i;         i++;...
 *     -> [block_10, block_11]
 *   block_11 LOOP_EXIT  <- [block_9]:
 *          %56 = CMP_NE [%54, %55]  // sum != 15
 *     >> %57 = COND_BRANCH [%56]  // if (sum != 15) return 2
 *     -> [block_12, block_13]
 *   block_13 IF_ELSE  <- [block_11]:
 *     >> %63 = IMPLICIT_GOTO
 *     -> [block_14]
 *   block_14 IF_MERGE  <- [block_13]:
 *          %fact.3 = ALLOCA/LOCAL size=4 align=1
 *          %64 = CONST/INT32 1  // 1
 *     >> %fact.65 = MEMORY/STORE_LE_32 [%fact.3, %64]
 *     >> %66 = ENTER_SCOPE  // for (int j = 1; j <= 5; j++) {         fact *= ...
 *     >> %67 = IMPLICIT_GOTO
 *     -> [block_15]
 *   block_15 LOOP_PREHEADER  <- [block_14]:
 *          %j.4 = ALLOCA/LOCAL size=4 align=1
 *          %68 = CONST/INT32 1  // 1
 *     >> %j.69 = MEMORY/STORE_LE_32 [%j.4, %68]
 *     >> %70 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 LOOP_CONDITION  <- [block_15, block_18]:
 *          %73 = CMP_LE [%71, %72]  // j <= 5
 *     >> %74 = COND_BRANCH [%73]  // for (int j = 1; j <= 5; j++) {         fact *= ...
 *     -> [block_17, block_19]
 *   block_19 LOOP_EXIT  <- [block_16]:
 *     >> %83 = EXIT_SCOPE  // for (int j = 1; j <= 5; j++) {         fact *= ...
 *          %86 = CMP_NE [%84, %85]  // fact != 120
 *     >> %87 = COND_BRANCH [%86]  // if (fact != 120) return 3
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %93 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %count.5 = ALLOCA/LOCAL size=4 align=1
 *          %94 = CONST/INT32 0  // 0
 *     >> %count.95 = MEMORY/STORE_LE_32 [%count.5, %94]
 *     >> %96 = IMPLICIT_GOTO
 *     -> [block_23]
 *   block_23 LOOP_PREHEADER  <- [block_22]:
 *     >> %97 = IMPLICIT_GOTO
 *     -> [block_24]
 *   block_24 LOOP_BODY  <- [block_23, block_25]:
 *     >> %98 = ENTER_SCOPE  // {         count++;     }
 *          %count.5 = ALLOCA/LOCAL size=4 align=1
 *          %99 = CONST/INT64 1  // count++
 *     >> %100 = READ_MODIFY_WRITE(ADD old) [%count.5, %99]  // count++
 *     >> %101 = EXIT_SCOPE  // {         count++;     }
 *     >> %102 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 LOOP_CONDITION  <- [block_24]:
 *          %105 = CMP_LT [%103, %104]  // count < 3
 *     >> %106 = COND_BRANCH [%105]  // do {         count++;     } while (count < 3)
 *     -> [block_24, block_26]
 *   block_26 LOOP_EXIT  <- [block_25]:
 *          %109 = CMP_NE [%107, %108]  // count != 3
 *     >> %110 = COND_BRANCH [%109]  // if (count != 3) return 4
 *     -> [block_27, block_28]
 *   block_28 IF_ELSE  <- [block_26]:
 *     >> %116 = IMPLICIT_GOTO
 *     -> [block_29]
 *   block_29 IF_MERGE  <- [block_28]:
 *          %brk.6 = ALLOCA/LOCAL size=4 align=1
 *          %117 = CONST/INT32 0  // 0
 *     >> %brk.118 = MEMORY/STORE_LE_32 [%brk.6, %117]
 *     >> %119 = ENTER_SCOPE  // for (int k = 0; k < 100; k++) {         if (k =...
 *     >> %120 = IMPLICIT_GOTO
 *     -> [block_30]
 *   block_30 LOOP_PREHEADER  <- [block_29]:
 *          %k.7 = ALLOCA/LOCAL size=4 align=1
 *          %121 = CONST/INT32 0  // 0
 *     >> %k.122 = MEMORY/STORE_LE_32 [%k.7, %121]
 *     >> %123 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 LOOP_CONDITION  <- [block_30, block_33]:
 *          %126 = CMP_LT [%124, %125]  // k < 100
 *     >> %127 = COND_BRANCH [%126]  // for (int k = 0; k < 100; k++) {         if (k =...
 *     -> [block_32, block_34]
 *   block_32 LOOP_BODY  <- [block_31]:
 *     >> %128 = ENTER_SCOPE  // {         if (k == 5) break;         brk++;     }
 *          %131 = CMP_EQ [%129, %130]  // k == 5
 *     >> %132 = COND_BRANCH [%131]  // if (k == 5) break
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_32]:
 *     >> %136 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_38, block_36]:
 *          %brk.6 = ALLOCA/LOCAL size=4 align=1
 *          %137 = CONST/INT64 1  // brk++
 *     >> %138 = READ_MODIFY_WRITE(ADD old) [%brk.6, %137]  // brk++
 *     >> %139 = EXIT_SCOPE  // {         if (k == 5) break;         brk++;     }
 *     >> %140 = IMPLICIT_GOTO
 *     -> [block_33]
 *   block_33 LOOP_INCREMENT  <- [block_37]:
 *          %k.7 = ALLOCA/LOCAL size=4 align=1
 *          %141 = CONST/INT64 1  // k++
 *     >> %142 = READ_MODIFY_WRITE(ADD old) [%k.7, %141]  // k++
 *     >> %143 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_35 IF_THEN  <- [block_32]:
 *     >> %133 = EXIT_SCOPE  // {         if (k == 5) break;         brk++;     }
 *     >> %134 = BREAK  // break
 *     -> [block_34]
 *   block_34 LOOP_EXIT  <- [block_31, block_35]:
 *     >> %144 = EXIT_SCOPE  // for (int k = 0; k < 100; k++) {         if (k =...
 *          %147 = CMP_NE [%145, %146]  // brk != 5
 *     >> %148 = COND_BRANCH [%147]  // if (brk != 5) return 5
 *     -> [block_39, block_40]
 *   block_40 IF_ELSE  <- [block_34]:
 *     >> %154 = IMPLICIT_GOTO
 *     -> [block_41]
 *   block_41 IF_MERGE  <- [block_40]:
 *          %cont.8 = ALLOCA/LOCAL size=4 align=1
 *          %155 = CONST/INT32 0  // 0
 *     >> %cont.156 = MEMORY/STORE_LE_32 [%cont.8, %155]
 *     >> %157 = ENTER_SCOPE  // for (int k = 0; k < 10; k++) {         if (k % ...
 *     >> %158 = IMPLICIT_GOTO
 *     -> [block_42]
 *   block_42 LOOP_PREHEADER  <- [block_41]:
 *          %k.9 = ALLOCA/LOCAL size=4 align=1
 *          %159 = CONST/INT32 0  // 0
 *     >> %k.160 = MEMORY/STORE_LE_32 [%k.9, %159]
 *     >> %161 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 LOOP_CONDITION  <- [block_42, block_45]:
 *          %164 = CMP_LT [%162, %163]  // k < 10
 *     >> %165 = COND_BRANCH [%164]  // for (int k = 0; k < 10; k++) {         if (k % ...
 *     -> [block_44, block_46]
 *   block_46 LOOP_EXIT  <- [block_43]:
 *     >> %184 = EXIT_SCOPE  // for (int k = 0; k < 10; k++) {         if (k % ...
 *          %187 = CMP_NE [%185, %186]  // cont != 5
 *     >> %188 = COND_BRANCH [%187]  // if (cont != 5) return 6
 *     -> [block_51, block_52]
 *   block_52 IF_ELSE  <- [block_46]:
 *     >> %194 = IMPLICIT_GOTO
 *     -> [block_53]
 *   block_53 IF_MERGE  <- [block_52]:
 *          %nested.10 = ALLOCA/LOCAL size=4 align=1
 *          %195 = CONST/INT32 0  // 0
 *     >> %nested.196 = MEMORY/STORE_LE_32 [%nested.10, %195]
 *     >> %197 = ENTER_SCOPE  // for (int a = 0; a < 3; a++) {         for (int ...
 *     >> %198 = IMPLICIT_GOTO
 *     -> [block_54]
 *   block_54 LOOP_PREHEADER  <- [block_53]:
 *          %a.11 = ALLOCA/LOCAL size=4 align=1
 *          %199 = CONST/INT32 0  // 0
 *     >> %a.200 = MEMORY/STORE_LE_32 [%a.11, %199]
 *     >> %201 = IMPLICIT_GOTO
 *     -> [block_55]
 *   block_55 LOOP_CONDITION  <- [block_54, block_57]:
 *          %204 = CMP_LT [%202, %203]  // a < 3
 *     >> %205 = COND_BRANCH [%204]  // for (int a = 0; a < 3; a++) {         for (int ...
 *     -> [block_56, block_58]
 *   block_58 LOOP_EXIT  <- [block_55]:
 *     >> %230 = EXIT_SCOPE  // for (int a = 0; a < 3; a++) {         for (int ...
 *          %233 = CMP_NE [%231, %232]  // nested != 9
 *     >> %234 = COND_BRANCH [%233]  // if (nested != 9) return 7
 *     -> [block_64, block_65]
 *   block_65 IF_ELSE  <- [block_58]:
 *     >> %240 = IMPLICIT_GOTO
 *     -> [block_66]
 *   block_66 IF_MERGE  <- [block_65]:
 *          %sel.13 = ALLOCA/LOCAL size=4 align=1
 *          %247 = SELECT [%243, %244, %246]  // (1 > 0) ? 42 : -1
 *     >> %sel.248 = MEMORY/STORE_LE_32 [%sel.13, %247]
 *          %251 = CMP_NE [%249, %250]  // sel != 42
 *     >> %252 = COND_BRANCH [%251]  // if (sel != 42) return 8
 *     -> [block_67, block_68]
 *   block_68 IF_ELSE  <- [block_66]:
 *     >> %258 = IMPLICIT_GOTO
 *     -> [block_69]
 *   block_69 IF_MERGE  <- [block_68]:
 *          %260 = RETURN_PTR  // return 0
 *          %259 = CONST/INT32 0  // 0
 *     >> %261 = MEMORY/STORE_LE_32 [%260, %259]  // return 0
 *     >> %262 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %259 = CONST/INT32 0  // 0
 *     >> %263 = RET [%259]  // return 0
 *   block_67 IF_THEN  <- [block_66]:
 *          %254 = RETURN_PTR  // return 8
 *          %253 = CONST/INT32 8  // 8
 *     >> %255 = MEMORY/STORE_LE_32 [%254, %253]  // return 8
 *     >> %256 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %253 = CONST/INT32 8  // 8
 *     >> %257 = RET [%253]  // return 8
 *   block_64 IF_THEN  <- [block_58]:
 *          %236 = RETURN_PTR  // return 7
 *          %235 = CONST/INT32 7  // 7
 *     >> %237 = MEMORY/STORE_LE_32 [%236, %235]  // return 7
 *     >> %238 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %235 = CONST/INT32 7  // 7
 *     >> %239 = RET [%235]  // return 7
 *   block_56 LOOP_BODY  <- [block_55]:
 *     >> %206 = ENTER_SCOPE  // {         for (int b = 0; b < 3; b++) {        ...
 *     >> %207 = ENTER_SCOPE  // for (int b = 0; b < 3; b++) {             neste...
 *     >> %208 = IMPLICIT_GOTO
 *     -> [block_59]
 *   block_59 LOOP_PREHEADER  <- [block_56]:
 *          %b.12 = ALLOCA/LOCAL size=4 align=1
 *          %209 = CONST/INT32 0  // 0
 *     >> %b.210 = MEMORY/STORE_LE_32 [%b.12, %209]
 *     >> %211 = IMPLICIT_GOTO
 *     -> [block_60]
 *   block_60 LOOP_CONDITION  <- [block_59, block_62]:
 *          %214 = CMP_LT [%212, %213]  // b < 3
 *     >> %215 = COND_BRANCH [%214]  // for (int b = 0; b < 3; b++) {             neste...
 *     -> [block_61, block_63]
 *   block_63 LOOP_EXIT  <- [block_60]:
 *     >> %224 = EXIT_SCOPE  // for (int b = 0; b < 3; b++) {             neste...
 *     >> %225 = EXIT_SCOPE  // {         for (int b = 0; b < 3; b++) {        ...
 *     >> %226 = IMPLICIT_GOTO
 *     -> [block_57]
 *   block_57 LOOP_INCREMENT  <- [block_63]:
 *          %a.11 = ALLOCA/LOCAL size=4 align=1
 *          %227 = CONST/INT64 1  // a++
 *     >> %228 = READ_MODIFY_WRITE(ADD old) [%a.11, %227]  // a++
 *     >> %229 = IMPLICIT_GOTO
 *     -> [block_55]
 *   block_61 LOOP_BODY  <- [block_60]:
 *     >> %216 = ENTER_SCOPE  // {             nested++;         }
 *          %nested.10 = ALLOCA/LOCAL size=4 align=1
 *          %217 = CONST/INT64 1  // nested++
 *     >> %218 = READ_MODIFY_WRITE(ADD old) [%nested.10, %217]  // nested++
 *     >> %219 = EXIT_SCOPE  // {             nested++;         }
 *     >> %220 = IMPLICIT_GOTO
 *     -> [block_62]
 *   block_62 LOOP_INCREMENT  <- [block_61]:
 *          %b.12 = ALLOCA/LOCAL size=4 align=1
 *          %221 = CONST/INT64 1  // b++
 *     >> %222 = READ_MODIFY_WRITE(ADD old) [%b.12, %221]  // b++
 *     >> %223 = IMPLICIT_GOTO
 *     -> [block_60]
 *   block_51 IF_THEN  <- [block_46]:
 *          %190 = RETURN_PTR  // return 6
 *          %189 = CONST/INT32 6  // 6
 *     >> %191 = MEMORY/STORE_LE_32 [%190, %189]  // return 6
 *     >> %192 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %189 = CONST/INT32 6  // 6
 *     >> %193 = RET [%189]  // return 6
 *   block_44 LOOP_BODY  <- [block_43]:
 *     >> %166 = ENTER_SCOPE  // {         if (k % 2 == 0) continue;         con...
 *          %171 = CMP_EQ [%169, %170]  // k % 2 == 0
 *     >> %172 = COND_BRANCH [%171]  // if (k % 2 == 0) continue
 *     -> [block_47, block_48]
 *   block_48 IF_ELSE  <- [block_44]:
 *     >> %176 = IMPLICIT_GOTO
 *     -> [block_49]
 *   block_49 IF_MERGE  <- [block_50, block_48]:
 *          %cont.8 = ALLOCA/LOCAL size=4 align=1
 *          %177 = CONST/INT64 1  // cont++
 *     >> %178 = READ_MODIFY_WRITE(ADD old) [%cont.8, %177]  // cont++
 *     >> %179 = EXIT_SCOPE  // {         if (k % 2 == 0) continue;         con...
 *     >> %180 = IMPLICIT_GOTO
 *     -> [block_45]
 *   block_47 IF_THEN  <- [block_44]:
 *     >> %173 = EXIT_SCOPE  // {         if (k % 2 == 0) continue;         con...
 *     >> %174 = CONTINUE  // continue
 *     -> [block_45]
 *   block_45 LOOP_INCREMENT  <- [block_47, block_49]:
 *          %k.9 = ALLOCA/LOCAL size=4 align=1
 *          %181 = CONST/INT64 1  // k++
 *     >> %182 = READ_MODIFY_WRITE(ADD old) [%k.9, %181]  // k++
 *     >> %183 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_39 IF_THEN  <- [block_34]:
 *          %150 = RETURN_PTR  // return 5
 *          %149 = CONST/INT32 5  // 5
 *     >> %151 = MEMORY/STORE_LE_32 [%150, %149]  // return 5
 *     >> %152 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %149 = CONST/INT32 5  // 5
 *     >> %153 = RET [%149]  // return 5
 *   block_27 IF_THEN  <- [block_26]:
 *          %112 = RETURN_PTR  // return 4
 *          %111 = CONST/INT32 4  // 4
 *     >> %113 = MEMORY/STORE_LE_32 [%112, %111]  // return 4
 *     >> %114 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %111 = CONST/INT32 4  // 4
 *     >> %115 = RET [%111]  // return 4
 *   block_20 IF_THEN  <- [block_19]:
 *          %89 = RETURN_PTR  // return 3
 *          %88 = CONST/INT32 3  // 3
 *     >> %90 = MEMORY/STORE_LE_32 [%89, %88]  // return 3
 *     >> %91 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %88 = CONST/INT32 3  // 3
 *     >> %92 = RET [%88]  // return 3
 *   block_17 LOOP_BODY  <- [block_16]:
 *     >> %75 = ENTER_SCOPE  // {         fact *= j;     }
 *          %fact.3 = ALLOCA/LOCAL size=4 align=1
 *          %76 = MEMORY/LOAD_LE_32 [%j.4]  // j
 *     >> %77 = READ_MODIFY_WRITE(MUL new) [%fact.3, %76]  // fact *= j
 *     >> %78 = EXIT_SCOPE  // {         fact *= j;     }
 *     >> %79 = IMPLICIT_GOTO
 *     -> [block_18]
 *   block_18 LOOP_INCREMENT  <- [block_17]:
 *          %j.4 = ALLOCA/LOCAL size=4 align=1
 *          %80 = CONST/INT64 1  // j++
 *     >> %81 = READ_MODIFY_WRITE(ADD old) [%j.4, %80]  // j++
 *     >> %82 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_12 IF_THEN  <- [block_11]:
 *          %59 = RETURN_PTR  // return 2
 *          %58 = CONST/INT32 2  // 2
 *     >> %60 = MEMORY/STORE_LE_32 [%59, %58]  // return 2
 *     >> %61 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %58 = CONST/INT32 2  // 2
 *     >> %62 = RET [%58]  // return 2
 *   block_10 LOOP_BODY  <- [block_9]:
 *     >> %47 = ENTER_SCOPE  // {         sum += i;         i++;     }
 *          %sum.1 = ALLOCA/LOCAL size=4 align=1
 *          %48 = MEMORY/LOAD_LE_32 [%i.2]  // i
 *     >> %49 = READ_MODIFY_WRITE(ADD new) [%sum.1, %48]  // sum += i
 *          %i.2 = ALLOCA/LOCAL size=4 align=1
 *          %50 = CONST/INT64 1  // i++
 *     >> %51 = READ_MODIFY_WRITE(ADD old) [%i.2, %50]  // i++
 *     >> %52 = EXIT_SCOPE  // {         sum += i;         i++;     }
 *     >> %53 = IMPLICIT_GOTO
 *     -> [block_9]
 *   block_5 IF_THEN  <- [block_4]:
 *          %32 = RETURN_PTR  // return 1
 *          %31 = CONST/INT32 1  // 1
 *     >> %33 = MEMORY/STORE_LE_32 [%32, %31]  // return 1
 *     >> %34 = EXIT_SCOPE  // {     int result = 0;      // If/else.     if (...
 *          %31 = CONST/INT32 1  // 1
 *     >> %35 = RET [%31]  // return 1
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

    return 0;
}
