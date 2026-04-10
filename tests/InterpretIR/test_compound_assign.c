// Tests: read-modify-write (READ_MODIFY_WRITE) for compound assignment
// operators (+=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=),
// pre/post increment/decrement (++x, x++, --x, x--),
// and pointer increment/decrement.

/*
 * Expected IR:
 *
 * function test_compound_assign (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (x)
 *     obj_2 LOCAL_VALUE size=4 align=1 (pre)
 *     obj_3 LOCAL_VALUE size=4 align=1 (post)
 *     obj_4 LOCAL_VALUE size=12 align=1 (arr)
 *     obj_5 LOCAL_VALUE size=8 align=1 (p)
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %5 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %6 = ENTER_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %7 = CONST/INT32 10  // 10
 *     >> %x.8 = MEMORY/STORE_LE_32 [%x.0, %7]
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %9 = CONST/INT32 5  // 5
 *     >> %10 = READ_MODIFY_WRITE(ADD new) [%x.0, %9]  // x += 5
 *          %13 = CMP_NE [%11, %12]  // x != 15
 *     >> %14 = COND_BRANCH [%13]  // if (x != 15) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %20 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %21 = CONST/INT32 3  // 3
 *     >> %22 = READ_MODIFY_WRITE(SUB new) [%x.0, %21]  // x -= 3
 *          %25 = CMP_NE [%23, %24]  // x != 12
 *     >> %26 = COND_BRANCH [%25]  // if (x != 12) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %32 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %33 = CONST/INT32 2  // 2
 *     >> %34 = READ_MODIFY_WRITE(MUL new) [%x.0, %33]  // x *= 2
 *          %37 = CMP_NE [%35, %36]  // x != 24
 *     >> %38 = COND_BRANCH [%37]  // if (x != 24) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %44 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %45 = CONST/INT32 6  // 6
 *     >> %46 = READ_MODIFY_WRITE(DIV new) [%x.0, %45]  // x /= 6
 *          %49 = CMP_NE [%47, %48]  // x != 4
 *     >> %50 = COND_BRANCH [%49]  // if (x != 4) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %56 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %57 = CONST/INT32 3  // 3
 *     >> %58 = READ_MODIFY_WRITE(REM new) [%x.0, %57]  // x %= 3
 *          %61 = CMP_NE [%59, %60]  // x != 1
 *     >> %62 = COND_BRANCH [%61]  // if (x != 1) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %68 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %69 = CONST/INT32 255  // 0xFF
 *     >> %70 = MEMORY/STORE_LE_32 [%x.0, %69]  // x = 0xFF
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %71 = CONST/INT32 15  // 0x0F
 *     >> %72 = READ_MODIFY_WRITE(BIT_AND new) [%x.0, %71]  // x &= 0x0F
 *          %75 = CMP_NE [%73, %74]  // x != 0x0F
 *     >> %76 = COND_BRANCH [%75]  // if (x != 0x0F) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %82 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %83 = CONST/INT32 240  // 0xF0
 *     >> %84 = READ_MODIFY_WRITE(BIT_OR new) [%x.0, %83]  // x |= 0xF0
 *          %87 = CMP_NE [%85, %86]  // x != 0xFF
 *     >> %88 = COND_BRANCH [%87]  // if (x != 0xFF) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %94 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %95 = CONST/INT32 255  // 0xFF
 *     >> %96 = READ_MODIFY_WRITE(BIT_XOR new) [%x.0, %95]  // x ^= 0xFF
 *          %99 = CMP_NE [%97, %98]  // x != 0x00
 *     >> %100 = COND_BRANCH [%99]  // if (x != 0x00) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %106 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %107 = CONST/INT32 1  // 1
 *     >> %108 = MEMORY/STORE_LE_32 [%x.0, %107]  // x = 1
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %109 = CONST/INT32 4  // 4
 *     >> %110 = READ_MODIFY_WRITE(SHL new) [%x.0, %109]  // x <<= 4
 *          %113 = CMP_NE [%111, %112]  // x != 16
 *     >> %114 = COND_BRANCH [%113]  // if (x != 16) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %120 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %121 = CONST/INT32 2  // 2
 *     >> %122 = READ_MODIFY_WRITE(SHR new) [%x.0, %121]  // x >>= 2
 *          %125 = CMP_NE [%123, %124]  // x != 4
 *     >> %126 = COND_BRANCH [%125]  // if (x != 4) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %132 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %133 = CONST/INT32 5  // 5
 *     >> %134 = MEMORY/STORE_LE_32 [%x.0, %133]  // x = 5
 *          %pre.1 = ALLOCA/LOCAL size=4 align=1
 *          %136 = READ_MODIFY_WRITE(ADD new) [%x.0, %135]  // ++x
 *     >> %pre.137 = MEMORY/STORE_LE_32 [%pre.1, %136]
 *          %140 = CMP_NE [%138, %139]  // pre != 6
 *     >> %141 = COND_BRANCH [%140]  // if (pre != 6) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %147 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %150 = CMP_NE [%148, %149]  // x != 6
 *     >> %151 = COND_BRANCH [%150]  // if (x != 6) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %157 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %158 = CONST/INT32 5  // 5
 *     >> %159 = MEMORY/STORE_LE_32 [%x.0, %158]  // x = 5
 *          %post.2 = ALLOCA/LOCAL size=4 align=1
 *          %161 = READ_MODIFY_WRITE(ADD old) [%x.0, %160]  // x++
 *     >> %post.162 = MEMORY/STORE_LE_32 [%post.2, %161]
 *          %165 = CMP_NE [%163, %164]  // post != 5
 *     >> %166 = COND_BRANCH [%165]  // if (post != 5) return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %172 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *          %175 = CMP_NE [%173, %174]  // x != 6
 *     >> %176 = COND_BRANCH [%175]  // if (x != 6) return 14
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %182 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %183 = CONST/INT32 5  // 5
 *     >> %184 = MEMORY/STORE_LE_32 [%x.0, %183]  // x = 5
 *          %pre.1 = ALLOCA/LOCAL size=4 align=1
 *          %186 = READ_MODIFY_WRITE(SUB new) [%x.0, %185]  // --x
 *     >> %187 = MEMORY/STORE_LE_32 [%pre.1, %186]  // pre = --x
 *          %190 = CMP_NE [%188, %189]  // pre != 4
 *     >> %191 = COND_BRANCH [%190]  // if (pre != 4) return 15
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %197 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %x.0 = ALLOCA/LOCAL size=4 align=1
 *          %198 = CONST/INT32 5  // 5
 *     >> %199 = MEMORY/STORE_LE_32 [%x.0, %198]  // x = 5
 *          %post.2 = ALLOCA/LOCAL size=4 align=1
 *          %201 = READ_MODIFY_WRITE(SUB old) [%x.0, %200]  // x--
 *     >> %202 = MEMORY/STORE_LE_32 [%post.2, %201]  // post = x--
 *          %205 = CMP_NE [%203, %204]  // post != 5
 *     >> %206 = COND_BRANCH [%205]  // if (post != 5) return 16
 *     -> [block_47, block_48]
 *   block_48 IF_ELSE  <- [block_46]:
 *     >> %212 = IMPLICIT_GOTO
 *     -> [block_49]
 *   block_49 IF_MERGE  <- [block_48]:
 *          %215 = CMP_NE [%213, %214]  // x != 4
 *     >> %216 = COND_BRANCH [%215]  // if (x != 4) return 17
 *     -> [block_50, block_51]
 *   block_51 IF_ELSE  <- [block_49]:
 *     >> %222 = IMPLICIT_GOTO
 *     -> [block_52]
 *   block_52 IF_MERGE  <- [block_51]:
 *          %arr.3 = ALLOCA/LOCAL size=12 align=1
 *          %arr.223 = CONST/UINT8 0
 *          %arr.224 = CONST/UINT64 12
 *     >> %arr.225 = MEMORY/MEMSET [%arr.3, %arr.223, %arr.224]
 *          %arr.3 = ALLOCA/LOCAL size=12 align=1
 *          %226 = CONST/INT32 10  // 10
 *     >> %arr.227 = MEMORY/STORE_LE_32 [%arr.3, %226]
 *          %arr.229 = PTR_ADD elem_size=4 [%arr.3, %arr.228]
 *          %230 = CONST/INT32 20  // 20
 *     >> %arr.231 = MEMORY/STORE_LE_32 [%arr.229, %230]
 *          %arr.233 = PTR_ADD elem_size=4 [%arr.3, %arr.232]
 *          %234 = CONST/INT32 30  // 30
 *     >> %arr.235 = MEMORY/STORE_LE_32 [%arr.233, %234]
 *          %p.4 = ALLOCA/LOCAL size=8 align=1
 *          %arr.3 = ALLOCA/LOCAL size=12 align=1
 *     >> %p.236 = MEMORY/STORE_LE_64 [%p.4, %arr.3]
 *          %p.4 = ALLOCA/LOCAL size=8 align=1
 *          %237 = CONST/INT64 1  // p++
 *     >> %238 = READ_MODIFY_WRITE(PTR_ADD old) [%p.4, %237]  // p++
 *          %242 = CMP_NE [%240, %241]  // *p != 20
 *     >> %243 = COND_BRANCH [%242]  // if (*p != 20) return 18
 *     -> [block_53, block_54]
 *   block_54 IF_ELSE  <- [block_52]:
 *     >> %249 = IMPLICIT_GOTO
 *     -> [block_55]
 *   block_55 IF_MERGE  <- [block_54]:
 *          %p.4 = ALLOCA/LOCAL size=8 align=1
 *          %251 = PTR_ADD elem_size=4 [%arr.3, %250]  // arr[2]
 *     >> %252 = MEMORY/STORE_LE_64 [%p.4, %251]  // p = &arr[2]
 *          %p.4 = ALLOCA/LOCAL size=8 align=1
 *          %253 = CONST/INT64 -1  // p--
 *     >> %254 = READ_MODIFY_WRITE(PTR_ADD old) [%p.4, %253]  // p--
 *          %258 = CMP_NE [%256, %257]  // *p != 20
 *     >> %259 = COND_BRANCH [%258]  // if (*p != 20) return 19
 *     -> [block_56, block_57]
 *   block_57 IF_ELSE  <- [block_55]:
 *     >> %265 = IMPLICIT_GOTO
 *     -> [block_58]
 *   block_58 IF_MERGE  <- [block_57]:
 *          %p.4 = ALLOCA/LOCAL size=8 align=1
 *          %arr.3 = ALLOCA/LOCAL size=12 align=1
 *     >> %266 = MEMORY/STORE_LE_64 [%p.4, %arr.3]  // p = arr
 *          %p.4 = ALLOCA/LOCAL size=8 align=1
 *          %267 = CONST/INT32 2  // 2
 *     >> %268 = READ_MODIFY_WRITE(PTR_ADD new) [%p.4, %267]  // p += 2
 *          %272 = CMP_NE [%270, %271]  // *p != 30
 *     >> %273 = COND_BRANCH [%272]  // if (*p != 30) return 20
 *     -> [block_59, block_60]
 *   block_60 IF_ELSE  <- [block_58]:
 *     >> %279 = IMPLICIT_GOTO
 *     -> [block_61]
 *   block_61 IF_MERGE  <- [block_60]:
 *          %p.4 = ALLOCA/LOCAL size=8 align=1
 *          %281 = NEG [%280]  // p -= 1
 *     >> %282 = READ_MODIFY_WRITE(PTR_ADD new) [%p.4, %281]  // p -= 1
 *          %286 = CMP_NE [%284, %285]  // *p != 20
 *     >> %287 = COND_BRANCH [%286]  // if (*p != 20) return 21
 *     -> [block_62, block_63]
 *   block_63 IF_ELSE  <- [block_61]:
 *     >> %293 = IMPLICIT_GOTO
 *     -> [block_64]
 *   block_64 IF_MERGE  <- [block_63]:
 *          %295 = RETURN_PTR  // return 0
 *          %294 = CONST/INT32 0  // 0
 *     >> %296 = MEMORY/STORE_LE_32 [%295, %294]  // return 0
 *     >> %297 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %294 = CONST/INT32 0  // 0
 *     >> %298 = RET [%294]  // return 0
 *   block_62 IF_THEN  <- [block_61]:
 *          %289 = RETURN_PTR  // return 21
 *          %288 = CONST/INT32 21  // 21
 *     >> %290 = MEMORY/STORE_LE_32 [%289, %288]  // return 21
 *     >> %291 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %288 = CONST/INT32 21  // 21
 *     >> %292 = RET [%288]  // return 21
 *   block_59 IF_THEN  <- [block_58]:
 *          %275 = RETURN_PTR  // return 20
 *          %274 = CONST/INT32 20  // 20
 *     >> %276 = MEMORY/STORE_LE_32 [%275, %274]  // return 20
 *     >> %277 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %274 = CONST/INT32 20  // 20
 *     >> %278 = RET [%274]  // return 20
 *   block_56 IF_THEN  <- [block_55]:
 *          %261 = RETURN_PTR  // return 19
 *          %260 = CONST/INT32 19  // 19
 *     >> %262 = MEMORY/STORE_LE_32 [%261, %260]  // return 19
 *     >> %263 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %260 = CONST/INT32 19  // 19
 *     >> %264 = RET [%260]  // return 19
 *   block_53 IF_THEN  <- [block_52]:
 *          %245 = RETURN_PTR  // return 18
 *          %244 = CONST/INT32 18  // 18
 *     >> %246 = MEMORY/STORE_LE_32 [%245, %244]  // return 18
 *     >> %247 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %244 = CONST/INT32 18  // 18
 *     >> %248 = RET [%244]  // return 18
 *   block_50 IF_THEN  <- [block_49]:
 *          %218 = RETURN_PTR  // return 17
 *          %217 = CONST/INT32 17  // 17
 *     >> %219 = MEMORY/STORE_LE_32 [%218, %217]  // return 17
 *     >> %220 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %217 = CONST/INT32 17  // 17
 *     >> %221 = RET [%217]  // return 17
 *   block_47 IF_THEN  <- [block_46]:
 *          %208 = RETURN_PTR  // return 16
 *          %207 = CONST/INT32 16  // 16
 *     >> %209 = MEMORY/STORE_LE_32 [%208, %207]  // return 16
 *     >> %210 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %207 = CONST/INT32 16  // 16
 *     >> %211 = RET [%207]  // return 16
 *   block_44 IF_THEN  <- [block_43]:
 *          %193 = RETURN_PTR  // return 15
 *          %192 = CONST/INT32 15  // 15
 *     >> %194 = MEMORY/STORE_LE_32 [%193, %192]  // return 15
 *     >> %195 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %192 = CONST/INT32 15  // 15
 *     >> %196 = RET [%192]  // return 15
 *   block_41 IF_THEN  <- [block_40]:
 *          %178 = RETURN_PTR  // return 14
 *          %177 = CONST/INT32 14  // 14
 *     >> %179 = MEMORY/STORE_LE_32 [%178, %177]  // return 14
 *     >> %180 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %177 = CONST/INT32 14  // 14
 *     >> %181 = RET [%177]  // return 14
 *   block_38 IF_THEN  <- [block_37]:
 *          %168 = RETURN_PTR  // return 13
 *          %167 = CONST/INT32 13  // 13
 *     >> %169 = MEMORY/STORE_LE_32 [%168, %167]  // return 13
 *     >> %170 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %167 = CONST/INT32 13  // 13
 *     >> %171 = RET [%167]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %153 = RETURN_PTR  // return 12
 *          %152 = CONST/INT32 12  // 12
 *     >> %154 = MEMORY/STORE_LE_32 [%153, %152]  // return 12
 *     >> %155 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %152 = CONST/INT32 12  // 12
 *     >> %156 = RET [%152]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %143 = RETURN_PTR  // return 11
 *          %142 = CONST/INT32 11  // 11
 *     >> %144 = MEMORY/STORE_LE_32 [%143, %142]  // return 11
 *     >> %145 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %142 = CONST/INT32 11  // 11
 *     >> %146 = RET [%142]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %128 = RETURN_PTR  // return 10
 *          %127 = CONST/INT32 10  // 10
 *     >> %129 = MEMORY/STORE_LE_32 [%128, %127]  // return 10
 *     >> %130 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %127 = CONST/INT32 10  // 10
 *     >> %131 = RET [%127]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %116 = RETURN_PTR  // return 9
 *          %115 = CONST/INT32 9  // 9
 *     >> %117 = MEMORY/STORE_LE_32 [%116, %115]  // return 9
 *     >> %118 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %115 = CONST/INT32 9  // 9
 *     >> %119 = RET [%115]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %102 = RETURN_PTR  // return 8
 *          %101 = CONST/INT32 8  // 8
 *     >> %103 = MEMORY/STORE_LE_32 [%102, %101]  // return 8
 *     >> %104 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %101 = CONST/INT32 8  // 8
 *     >> %105 = RET [%101]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %90 = RETURN_PTR  // return 7
 *          %89 = CONST/INT32 7  // 7
 *     >> %91 = MEMORY/STORE_LE_32 [%90, %89]  // return 7
 *     >> %92 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %89 = CONST/INT32 7  // 7
 *     >> %93 = RET [%89]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %78 = RETURN_PTR  // return 6
 *          %77 = CONST/INT32 6  // 6
 *     >> %79 = MEMORY/STORE_LE_32 [%78, %77]  // return 6
 *     >> %80 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %77 = CONST/INT32 6  // 6
 *     >> %81 = RET [%77]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %64 = RETURN_PTR  // return 5
 *          %63 = CONST/INT32 5  // 5
 *     >> %65 = MEMORY/STORE_LE_32 [%64, %63]  // return 5
 *     >> %66 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %63 = CONST/INT32 5  // 5
 *     >> %67 = RET [%63]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %52 = RETURN_PTR  // return 4
 *          %51 = CONST/INT32 4  // 4
 *     >> %53 = MEMORY/STORE_LE_32 [%52, %51]  // return 4
 *     >> %54 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %51 = CONST/INT32 4  // 4
 *     >> %55 = RET [%51]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %40 = RETURN_PTR  // return 3
 *          %39 = CONST/INT32 3  // 3
 *     >> %41 = MEMORY/STORE_LE_32 [%40, %39]  // return 3
 *     >> %42 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %39 = CONST/INT32 3  // 3
 *     >> %43 = RET [%39]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %28 = RETURN_PTR  // return 2
 *          %27 = CONST/INT32 2  // 2
 *     >> %29 = MEMORY/STORE_LE_32 [%28, %27]  // return 2
 *     >> %30 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %27 = CONST/INT32 2  // 2
 *     >> %31 = RET [%27]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %16 = RETURN_PTR  // return 1
 *          %15 = CONST/INT32 1  // 1
 *     >> %17 = MEMORY/STORE_LE_32 [%16, %15]  // return 1
 *     >> %18 = EXIT_SCOPE  // {     int x = 10;      // Compound assignment o...
 *          %15 = CONST/INT32 1  // 1
 *     >> %19 = RET [%15]  // return 1
 * }
 */



int test_compound_assign(void) {
    int x = 10;

    // Compound assignment operators.
    x += 5;   if (x != 15) return 1;
    x -= 3;   if (x != 12) return 2;
    x *= 2;   if (x != 24) return 3;
    x /= 6;   if (x != 4) return 4;
    x %= 3;   if (x != 1) return 5;

    x = 0xFF;
    x &= 0x0F;  if (x != 0x0F) return 6;
    x |= 0xF0;  if (x != 0xFF) return 7;
    x ^= 0xFF;  if (x != 0x00) return 8;

    x = 1;
    x <<= 4;  if (x != 16) return 9;
    x >>= 2;  if (x != 4) return 10;

    // Pre-increment.
    x = 5;
    int pre = ++x;
    if (pre != 6) return 11;
    if (x != 6) return 12;

    // Post-increment.
    x = 5;
    int post = x++;
    if (post != 5) return 13;
    if (x != 6) return 14;

    // Pre-decrement.
    x = 5;
    pre = --x;
    if (pre != 4) return 15;

    // Post-decrement.
    x = 5;
    post = x--;
    if (post != 5) return 16;
    if (x != 4) return 17;

    // Pointer increment.
    int arr[3] = {10, 20, 30};
    int *p = arr;
    p++;
    if (*p != 20) return 18;

    // Pointer decrement.
    p = &arr[2];
    p--;
    if (*p != 20) return 19;

    // Pointer compound assign.
    p = arr;
    p += 2;
    if (*p != 30) return 20;
    p -= 1;
    if (*p != 20) return 21;

    return 0;
}
