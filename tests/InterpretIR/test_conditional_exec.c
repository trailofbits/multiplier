// Tests: conditional execution semantics — short-circuit evaluation,
// ternary operator, and ensuring side effects in unreachable branches
// don't corrupt state.

/*
 * Expected IR:
 *
 * function increment_and_return (NORMAL) {
 *   objects:
 *     obj_0 PARAMETER_VALUE size=4 align=1 (val)
 *     obj_1 RETURN_SLOT size=4 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %val.0 = ALLOCA/LOCAL size=4 align=1
 *     >> %1 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %2 = ENTER_SCOPE  // {     side_effect_counter++;     return val; }
 *          %4 = GLOBAL_PTR  // side_effect_counter
 *          %5 = CONST/INT64 1  // side_effect_counter++
 *     >> %6 = READ_MODIFY_WRITE(ADD old) [%4, %5]  // side_effect_counter++
 *          %8 = RETURN_PTR  // return val
 *          %7 = MEMORY/LOAD_LE_32 [%val.3]  // val
 *     >> %9 = MEMORY/STORE_LE_32 [%8, %7]  // return val
 *     >> %10 = EXIT_SCOPE  // {     side_effect_counter++;     return val; }
 *          %7 = MEMORY/LOAD_LE_32 [%val.3]  // val
 *     >> %11 = RET [%7]  // return val
 * }
 * function unreachable_function (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %0 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %1 = ENTER_SCOPE  // {     // If this is ever "executed" by the inte...
 *          %3 = RETURN_PTR  // return 99999
 *          %2 = CONST/INT32 99999  // 99999
 *     >> %4 = MEMORY/STORE_LE_32 [%3, %2]  // return 99999
 *     >> %5 = EXIT_SCOPE  // {     // If this is ever "executed" by the inte...
 *          %2 = CONST/INT32 99999  // 99999
 *     >> %6 = RET [%2]  // return 99999
 * }
 * function test_conditional_exec (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (r1)
 *     obj_2 LOCAL_VALUE size=4 align=1 (r2)
 *     obj_3 LOCAL_VALUE size=4 align=1 (r3)
 *     obj_4 LOCAL_VALUE size=4 align=1 (r4)
 *     obj_5 LOCAL_VALUE size=4 align=1 (r5)
 *     obj_6 LOCAL_VALUE size=4 align=1 (r6)
 *     obj_7 LOCAL_VALUE size=4 align=1 (r7)
 *     obj_8 LOCAL_VALUE size=4 align=1 (r8)
 *     obj_9 LOCAL_VALUE size=4 align=1 (r9)
 *     obj_10 LOCAL_VALUE size=4 align=1 (x)
 *     obj_11 LOCAL_VALUE size=4 align=1 (r10)
 *     obj_12 LOCAL_VALUE size=4 align=1 (r11)
 *     obj_13 LOCAL_VALUE size=4 align=1 (r12)
 *     obj_14 LOCAL_VALUE size=4 align=1 (r13)
 *     obj_15 LOCAL_VALUE size=4 align=1 (r14)
 *     obj_16 LOCAL_VALUE size=4 align=1 (r15)
 *     obj_17 LOCAL_VALUE size=4 align=1 (a)
 *     obj_18 LOCAL_VALUE size=4 align=1 (b)
 *     obj_19 LOCAL_VALUE size=4 align=1 (c)
 *     obj_20 LOCAL_VALUE size=4 align=1 (r16)
 *     obj_21 LOCAL_VALUE size=4 align=1 (r17)
 *     obj_22 LOCAL_VALUE size=4 align=1 (r18)
 *     obj_23 LOCAL_VALUE size=4 align=1 (r19)
 *     obj_24 LOCAL_VALUE size=4 align=1 (r20)
 *     obj_25 PARAMETER size=4 align=1
 *     obj_26 RETURN_SLOT size=4 align=1
 *     obj_27 RETURN_SLOT size=4 align=1
 *     obj_28 RETURN_SLOT size=4 align=1
 *     obj_29 RETURN_SLOT size=4 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %24 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %25 = ENTER_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %26 = GLOBAL_PTR  // side_effect_counter
 *          %27 = CONST/INT32 0  // 0
 *     >> %28 = MEMORY/STORE_LE_32 [%26, %27]  // side_effect_counter = 0
 *     >> %30 = ENTER_SCOPE  // increment_and_return(1)
 *          %32 = ALLOCA/ARG size=4 align=1  // 1
 *          %31 = CONST/INT32 1  // 1
 *     >> %33 = MEMORY/STORE_LE_32 [%32, %31]  // 1
 *          %r1.0 = ALLOCA/LOCAL size=4 align=1
 *          %36 = LOGICAL_AND [%29, %35]  // 0 && increment_and_return(1)
 *     >> %r1.37 = MEMORY/STORE_LE_32 [%r1.0, %36]
 *     >> %41 = EXIT_SCOPE
 *          %40 = CMP_NE [%38, %39]  // r1 != 0
 *     >> %42 = COND_BRANCH [%40]  // if (r1 != 0) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %49 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %r2.1 = ALLOCA/LOCAL size=4 align=1
 *          %52 = LOGICAL_AND [%50, %51]  // 1 && 1
 *     >> %r2.53 = MEMORY/STORE_LE_32 [%r2.1, %52]
 *          %56 = CMP_NE [%54, %55]  // r2 != 1
 *     >> %57 = COND_BRANCH [%56]  // if (r2 != 1) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %63 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %r3.2 = ALLOCA/LOCAL size=4 align=1
 *          %66 = LOGICAL_AND [%64, %65]  // 1 && 0
 *     >> %r3.67 = MEMORY/STORE_LE_32 [%r3.2, %66]
 *          %70 = CMP_NE [%68, %69]  // r3 != 0
 *     >> %71 = COND_BRANCH [%70]  // if (r3 != 0) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %77 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *     >> %79 = ENTER_SCOPE  // unreachable_function()
 *          %r4.3 = ALLOCA/LOCAL size=4 align=1
 *          %82 = LOGICAL_OR [%78, %81]  // 1 || unreachable_function()
 *     >> %r4.83 = MEMORY/STORE_LE_32 [%r4.3, %82]
 *     >> %87 = EXIT_SCOPE
 *          %86 = CMP_NE [%84, %85]  // r4 != 1
 *     >> %88 = COND_BRANCH [%86]  // if (r4 != 1) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %95 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %r5.4 = ALLOCA/LOCAL size=4 align=1
 *          %98 = LOGICAL_OR [%96, %97]  // 0 || 1
 *     >> %r5.99 = MEMORY/STORE_LE_32 [%r5.4, %98]
 *          %102 = CMP_NE [%100, %101]  // r5 != 1
 *     >> %103 = COND_BRANCH [%102]  // if (r5 != 1) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %109 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %r6.5 = ALLOCA/LOCAL size=4 align=1
 *          %112 = LOGICAL_OR [%110, %111]  // 0 || 0
 *     >> %r6.113 = MEMORY/STORE_LE_32 [%r6.5, %112]
 *          %116 = CMP_NE [%114, %115]  // r6 != 0
 *     >> %117 = COND_BRANCH [%116]  // if (r6 != 0) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %123 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *     >> %126 = ENTER_SCOPE  // unreachable_function()
 *          %r7.6 = ALLOCA/LOCAL size=4 align=1
 *          %129 = SELECT [%124, %125, %128]  // 1 ? 42 : unreachable_function()
 *     >> %r7.130 = MEMORY/STORE_LE_32 [%r7.6, %129]
 *     >> %134 = EXIT_SCOPE
 *          %133 = CMP_NE [%131, %132]  // r7 != 42
 *     >> %135 = COND_BRANCH [%133]  // if (r7 != 42) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %142 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *     >> %144 = ENTER_SCOPE  // unreachable_function()
 *          %r8.7 = ALLOCA/LOCAL size=4 align=1
 *          %148 = SELECT [%143, %146, %147]  // 0 ? unreachable_function() : 43
 *     >> %r8.149 = MEMORY/STORE_LE_32 [%r8.7, %148]
 *     >> %153 = EXIT_SCOPE
 *          %152 = CMP_NE [%150, %151]  // r8 != 43
 *     >> %154 = COND_BRANCH [%152]  // if (r8 != 43) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %161 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %r9.8 = ALLOCA/LOCAL size=4 align=1
 *          %168 = SELECT [%162, %166, %167]  // 1 ? (0 ? 100 : 200) : 300
 *     >> %r9.169 = MEMORY/STORE_LE_32 [%r9.8, %168]
 *          %172 = CMP_NE [%170, %171]  // r9 != 200
 *     >> %173 = COND_BRANCH [%172]  // if (r9 != 200) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %179 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %x.9 = ALLOCA/LOCAL size=4 align=1
 *          %180 = CONST/INT32 10  // 10
 *     >> %x.181 = MEMORY/STORE_LE_32 [%x.9, %180]
 *          %r10.10 = ALLOCA/LOCAL size=4 align=1
 *          %191 = SELECT [%184, %187, %190]  // (x > 5) ? (x + 1) : (x - 1)
 *     >> %r10.192 = MEMORY/STORE_LE_32 [%r10.10, %191]
 *          %195 = CMP_NE [%193, %194]  // r10 != 11
 *     >> %196 = COND_BRANCH [%195]  // if (r10 != 11) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %202 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %r11.11 = ALLOCA/LOCAL size=4 align=1
 *          %212 = SELECT [%205, %208, %211]  // (x < 5) ? (x + 1) : (x - 1)
 *     >> %r11.213 = MEMORY/STORE_LE_32 [%r11.11, %212]
 *          %216 = CMP_NE [%214, %215]  // r11 != 9
 *     >> %217 = COND_BRANCH [%216]  // if (r11 != 9) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %223 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %r12.12 = ALLOCA/LOCAL size=4 align=1
 *          %228 = LOGICAL_OR [%226, %227]  // (1 && 0) || 1
 *     >> %r12.229 = MEMORY/STORE_LE_32 [%r12.12, %228]
 *          %232 = CMP_NE [%230, %231]  // r12 != 1
 *     >> %233 = COND_BRANCH [%232]  // if (r12 != 1) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %239 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %r13.13 = ALLOCA/LOCAL size=4 align=1
 *          %244 = LOGICAL_OR [%240, %243]  // 0 || (1 && 1)
 *     >> %r13.245 = MEMORY/STORE_LE_32 [%r13.13, %244]
 *          %248 = CMP_NE [%246, %247]  // r13 != 1
 *     >> %249 = COND_BRANCH [%248]  // if (r13 != 1) return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %255 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *          %r14.14 = ALLOCA/LOCAL size=4 align=1
 *          %260 = LOGICAL_AND [%257, %259]  // !0 && !0
 *     >> %r14.261 = MEMORY/STORE_LE_32 [%r14.14, %260]
 *          %264 = CMP_NE [%262, %263]  // r14 != 1
 *     >> %265 = COND_BRANCH [%264]  // if (r14 != 1) return 14
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %271 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *          %r15.15 = ALLOCA/LOCAL size=4 align=1
 *          %276 = LOGICAL_OR [%273, %275]  // !1 || !0
 *     >> %r15.277 = MEMORY/STORE_LE_32 [%r15.15, %276]
 *          %280 = CMP_NE [%278, %279]  // r15 != 1
 *     >> %281 = COND_BRANCH [%280]  // if (r15 != 1) return 15
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %287 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %a.16 = ALLOCA/LOCAL size=4 align=1
 *          %288 = CONST/INT32 5  // 5
 *     >> %a.289 = MEMORY/STORE_LE_32 [%a.16, %288]
 *          %b.17 = ALLOCA/LOCAL size=4 align=1
 *          %290 = CONST/INT32 0  // 0
 *     >> %b.291 = MEMORY/STORE_LE_32 [%b.17, %290]
 *          %c.18 = ALLOCA/LOCAL size=4 align=1
 *          %292 = CONST/INT32 3  // 3
 *     >> %c.293 = MEMORY/STORE_LE_32 [%c.18, %292]
 *          %r16.19 = ALLOCA/LOCAL size=4 align=1
 *          %296 = LOGICAL_AND [%294, %295]  // a && b
 *     >> %r16.297 = MEMORY/STORE_LE_32 [%r16.19, %296]
 *          %300 = CMP_NE [%298, %299]  // r16 != 0
 *     >> %301 = COND_BRANCH [%300]  // if (r16 != 0) return 16
 *     -> [block_47, block_48]
 *   block_48 IF_ELSE  <- [block_46]:
 *     >> %307 = IMPLICIT_GOTO
 *     -> [block_49]
 *   block_49 IF_MERGE  <- [block_48]:
 *          %r17.20 = ALLOCA/LOCAL size=4 align=1
 *          %310 = LOGICAL_OR [%308, %309]  // a || b
 *     >> %r17.311 = MEMORY/STORE_LE_32 [%r17.20, %310]
 *          %314 = CMP_NE [%312, %313]  // r17 != 1
 *     >> %315 = COND_BRANCH [%314]  // if (r17 != 1) return 17
 *     -> [block_50, block_51]
 *   block_51 IF_ELSE  <- [block_49]:
 *     >> %321 = IMPLICIT_GOTO
 *     -> [block_52]
 *   block_52 IF_MERGE  <- [block_51]:
 *          %r18.21 = ALLOCA/LOCAL size=4 align=1
 *          %324 = LOGICAL_OR [%322, %323]  // b || c
 *     >> %r18.325 = MEMORY/STORE_LE_32 [%r18.21, %324]
 *          %328 = CMP_NE [%326, %327]  // r18 != 1
 *     >> %329 = COND_BRANCH [%328]  // if (r18 != 1) return 18
 *     -> [block_53, block_54]
 *   block_54 IF_ELSE  <- [block_52]:
 *     >> %335 = IMPLICIT_GOTO
 *     -> [block_55]
 *   block_55 IF_MERGE  <- [block_54]:
 *          %r19.22 = ALLOCA/LOCAL size=4 align=1
 *          %339 = SELECT [%336, %337, %338]  // a ? b : c
 *     >> %r19.340 = MEMORY/STORE_LE_32 [%r19.22, %339]
 *          %343 = CMP_NE [%341, %342]  // r19 != 0
 *     >> %344 = COND_BRANCH [%343]  // if (r19 != 0) return 19
 *     -> [block_56, block_57]
 *   block_57 IF_ELSE  <- [block_55]:
 *     >> %350 = IMPLICIT_GOTO
 *     -> [block_58]
 *   block_58 IF_MERGE  <- [block_57]:
 *          %r20.23 = ALLOCA/LOCAL size=4 align=1
 *          %354 = SELECT [%351, %352, %353]  // b ? a : c
 *     >> %r20.355 = MEMORY/STORE_LE_32 [%r20.23, %354]
 *          %358 = CMP_NE [%356, %357]  // r20 != 3
 *     >> %359 = COND_BRANCH [%358]  // if (r20 != 3) return 20
 *     -> [block_59, block_60]
 *   block_60 IF_ELSE  <- [block_58]:
 *     >> %365 = IMPLICIT_GOTO
 *     -> [block_61]
 *   block_61 IF_MERGE  <- [block_60]:
 *          %367 = RETURN_PTR  // return 0
 *          %366 = CONST/INT32 0  // 0
 *     >> %368 = MEMORY/STORE_LE_32 [%367, %366]  // return 0
 *     >> %369 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %366 = CONST/INT32 0  // 0
 *     >> %370 = RET [%366]  // return 0
 *   block_59 IF_THEN  <- [block_58]:
 *          %361 = RETURN_PTR  // return 20
 *          %360 = CONST/INT32 20  // 20
 *     >> %362 = MEMORY/STORE_LE_32 [%361, %360]  // return 20
 *     >> %363 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %360 = CONST/INT32 20  // 20
 *     >> %364 = RET [%360]  // return 20
 *   block_56 IF_THEN  <- [block_55]:
 *          %346 = RETURN_PTR  // return 19
 *          %345 = CONST/INT32 19  // 19
 *     >> %347 = MEMORY/STORE_LE_32 [%346, %345]  // return 19
 *     >> %348 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %345 = CONST/INT32 19  // 19
 *     >> %349 = RET [%345]  // return 19
 *   block_53 IF_THEN  <- [block_52]:
 *          %331 = RETURN_PTR  // return 18
 *          %330 = CONST/INT32 18  // 18
 *     >> %332 = MEMORY/STORE_LE_32 [%331, %330]  // return 18
 *     >> %333 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %330 = CONST/INT32 18  // 18
 *     >> %334 = RET [%330]  // return 18
 *   block_50 IF_THEN  <- [block_49]:
 *          %317 = RETURN_PTR  // return 17
 *          %316 = CONST/INT32 17  // 17
 *     >> %318 = MEMORY/STORE_LE_32 [%317, %316]  // return 17
 *     >> %319 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %316 = CONST/INT32 17  // 17
 *     >> %320 = RET [%316]  // return 17
 *   block_47 IF_THEN  <- [block_46]:
 *          %303 = RETURN_PTR  // return 16
 *          %302 = CONST/INT32 16  // 16
 *     >> %304 = MEMORY/STORE_LE_32 [%303, %302]  // return 16
 *     >> %305 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %302 = CONST/INT32 16  // 16
 *     >> %306 = RET [%302]  // return 16
 *   block_44 IF_THEN  <- [block_43]:
 *          %283 = RETURN_PTR  // return 15
 *          %282 = CONST/INT32 15  // 15
 *     >> %284 = MEMORY/STORE_LE_32 [%283, %282]  // return 15
 *     >> %285 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %282 = CONST/INT32 15  // 15
 *     >> %286 = RET [%282]  // return 15
 *   block_41 IF_THEN  <- [block_40]:
 *          %267 = RETURN_PTR  // return 14
 *          %266 = CONST/INT32 14  // 14
 *     >> %268 = MEMORY/STORE_LE_32 [%267, %266]  // return 14
 *     >> %269 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %266 = CONST/INT32 14  // 14
 *     >> %270 = RET [%266]  // return 14
 *   block_38 IF_THEN  <- [block_37]:
 *          %251 = RETURN_PTR  // return 13
 *          %250 = CONST/INT32 13  // 13
 *     >> %252 = MEMORY/STORE_LE_32 [%251, %250]  // return 13
 *     >> %253 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %250 = CONST/INT32 13  // 13
 *     >> %254 = RET [%250]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %235 = RETURN_PTR  // return 12
 *          %234 = CONST/INT32 12  // 12
 *     >> %236 = MEMORY/STORE_LE_32 [%235, %234]  // return 12
 *     >> %237 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %234 = CONST/INT32 12  // 12
 *     >> %238 = RET [%234]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %219 = RETURN_PTR  // return 11
 *          %218 = CONST/INT32 11  // 11
 *     >> %220 = MEMORY/STORE_LE_32 [%219, %218]  // return 11
 *     >> %221 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %218 = CONST/INT32 11  // 11
 *     >> %222 = RET [%218]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %198 = RETURN_PTR  // return 10
 *          %197 = CONST/INT32 10  // 10
 *     >> %199 = MEMORY/STORE_LE_32 [%198, %197]  // return 10
 *     >> %200 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %197 = CONST/INT32 10  // 10
 *     >> %201 = RET [%197]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %175 = RETURN_PTR  // return 9
 *          %174 = CONST/INT32 9  // 9
 *     >> %176 = MEMORY/STORE_LE_32 [%175, %174]  // return 9
 *     >> %177 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %174 = CONST/INT32 9  // 9
 *     >> %178 = RET [%174]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %156 = RETURN_PTR  // return 8
 *          %155 = CONST/INT32 8  // 8
 *     >> %157 = MEMORY/STORE_LE_32 [%156, %155]  // return 8
 *     >> %158 = EXIT_SCOPE  // unreachable_function()
 *     >> %159 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %155 = CONST/INT32 8  // 8
 *     >> %160 = RET [%155]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %137 = RETURN_PTR  // return 7
 *          %136 = CONST/INT32 7  // 7
 *     >> %138 = MEMORY/STORE_LE_32 [%137, %136]  // return 7
 *     >> %139 = EXIT_SCOPE  // unreachable_function()
 *     >> %140 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %136 = CONST/INT32 7  // 7
 *     >> %141 = RET [%136]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %119 = RETURN_PTR  // return 6
 *          %118 = CONST/INT32 6  // 6
 *     >> %120 = MEMORY/STORE_LE_32 [%119, %118]  // return 6
 *     >> %121 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %118 = CONST/INT32 6  // 6
 *     >> %122 = RET [%118]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %105 = RETURN_PTR  // return 5
 *          %104 = CONST/INT32 5  // 5
 *     >> %106 = MEMORY/STORE_LE_32 [%105, %104]  // return 5
 *     >> %107 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %104 = CONST/INT32 5  // 5
 *     >> %108 = RET [%104]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %90 = RETURN_PTR  // return 4
 *          %89 = CONST/INT32 4  // 4
 *     >> %91 = MEMORY/STORE_LE_32 [%90, %89]  // return 4
 *     >> %92 = EXIT_SCOPE  // unreachable_function()
 *     >> %93 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %89 = CONST/INT32 4  // 4
 *     >> %94 = RET [%89]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %73 = RETURN_PTR  // return 3
 *          %72 = CONST/INT32 3  // 3
 *     >> %74 = MEMORY/STORE_LE_32 [%73, %72]  // return 3
 *     >> %75 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %72 = CONST/INT32 3  // 3
 *     >> %76 = RET [%72]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %59 = RETURN_PTR  // return 2
 *          %58 = CONST/INT32 2  // 2
 *     >> %60 = MEMORY/STORE_LE_32 [%59, %58]  // return 2
 *     >> %61 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %58 = CONST/INT32 2  // 2
 *     >> %62 = RET [%58]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %44 = RETURN_PTR  // return 1
 *          %43 = CONST/INT32 1  // 1
 *     >> %45 = MEMORY/STORE_LE_32 [%44, %43]  // return 1
 *     >> %46 = EXIT_SCOPE  // increment_and_return(1)
 *     >> %47 = EXIT_SCOPE  // {     // --- Short-circuit AND ---     // false...
 *          %43 = CONST/INT32 1  // 1
 *     >> %48 = RET [%43]  // return 1
 * }
 */



static int side_effect_counter;

static int increment_and_return(int val) {
    side_effect_counter++;
    return val;
}

static int unreachable_function(void) {
    // If this is ever "executed" by the interpreter, something is wrong.
    // We can't trap here, but we return a sentinel value.
    return 99999;
}

int test_conditional_exec(void) {
    // --- Short-circuit AND ---
    // false && X: X should not be evaluated.
    side_effect_counter = 0;
    int r1 = 0 && increment_and_return(1);
    if (r1 != 0) return 1;
    // side_effect_counter would be 0 if short-circuit works,
    // but our IR evaluates both sides (they're marked conditionally executed).
    // The result should still be 0 regardless.

    // true && true: both evaluated, result = 1.
    int r2 = 1 && 1;
    if (r2 != 1) return 2;

    // true && false: result = 0.
    int r3 = 1 && 0;
    if (r3 != 0) return 3;

    // --- Short-circuit OR ---
    // true || X: X should not be evaluated.
    int r4 = 1 || unreachable_function();
    if (r4 != 1) return 4;

    // false || true: result = 1.
    int r5 = 0 || 1;
    if (r5 != 1) return 5;

    // false || false: result = 0.
    int r6 = 0 || 0;
    if (r6 != 0) return 6;

    // --- Ternary operator ---
    // true ? a : b → a.
    int r7 = 1 ? 42 : unreachable_function();
    if (r7 != 42) return 7;

    // false ? a : b → b.
    int r8 = 0 ? unreachable_function() : 43;
    if (r8 != 43) return 8;

    // Nested ternary.
    int r9 = 1 ? (0 ? 100 : 200) : 300;
    if (r9 != 200) return 9;

    // Ternary with side effects in the chosen branch only.
    int x = 10;
    int r10 = (x > 5) ? (x + 1) : (x - 1);
    if (r10 != 11) return 10;

    int r11 = (x < 5) ? (x + 1) : (x - 1);
    if (r11 != 9) return 11;

    // --- Complex combinations ---
    // (a && b) || c
    int r12 = (1 && 0) || 1;
    if (r12 != 1) return 12;

    // a || (b && c)
    int r13 = 0 || (1 && 1);
    if (r13 != 1) return 13;

    // Negated conditions.
    int r14 = !0 && !0;
    if (r14 != 1) return 14;

    int r15 = !1 || !0;
    if (r15 != 1) return 15;

    // --- Variables in conditions ---
    int a = 5, b = 0, c = 3;

    // a && b: 5 && 0 = 0.
    int r16 = a && b;
    if (r16 != 0) return 16;

    // a || b: 5 || 0 = 1.
    int r17 = a || b;
    if (r17 != 1) return 17;

    // b || c: 0 || 3 = 1.
    int r18 = b || c;
    if (r18 != 1) return 18;

    // a ? b : c → 0 (because a is truthy, picks b which is 0).
    int r19 = a ? b : c;
    if (r19 != 0) return 19;

    // b ? a : c → 3 (because b is falsy, picks c).
    int r20 = b ? a : c;
    if (r20 != 3) return 20;

    return 0;
}
