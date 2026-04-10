// Tests: string literal handling (STRING_LITERAL objects, ALLOCA for string
// storage, non-power-of-2 sizes → MEMCPY for initialization),
// array initialization from string literals, string pointer assignment.

/*
 * Expected IR:
 *
 * function test_string_literals (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=6 align=1 (buf)
 *     obj_1 LOCAL_VALUE size=8 align=1 (p)
 *     obj_2 LOCAL_VALUE size=4 align=1 (len)
 *     obj_3 LOCAL_VALUE size=16 align=1 (long_buf)
 *     obj_4 LOCAL_VALUE size=1 align=1 (empty)
 *     obj_5 LOCAL_VALUE size=2 align=1 (single)
 *     obj_6 LOCAL_VALUE size=12 align=1 (wbuf)
 *     obj_7 LOCAL_VALUE size=8 align=1 (u16buf)
 *     obj_8 LOCAL_VALUE size=12 align=1 (u32buf)
 *     obj_9 LOCAL_VALUE size=20 align=1 (oversized)
 *     obj_10 STRING_LITERAL size=6 align=1
 *     obj_11 STRING_LITERAL size=6 align=1
 *     obj_12 STRING_LITERAL size=5 align=1
 *     obj_13 PARAMETER size=8 align=1
 *     obj_14 RETURN_SLOT size=4 align=1
 *     obj_15 STRING_LITERAL size=16 align=1
 *     obj_16 STRING_LITERAL size=1 align=1
 *     obj_17 STRING_LITERAL size=2 align=1
 *     obj_18 STRING_LITERAL size=12 align=1
 *     obj_19 STRING_LITERAL size=8 align=1
 *     obj_20 STRING_LITERAL size=12 align=1
 *     obj_21 STRING_LITERAL size=3 align=1
 *   body_scope: FUNCTION_SCOPE
 *   blocks:
 *   block_0 FRAME:
 *     >> %10 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %11 = ENTER_SCOPE  // {     // String literal initialization of char ...
 *          %buf.0 = ALLOCA/LOCAL size=6 align=1
 *          %12 = ALLOCA/LOCAL size=6 align=1  // "hello"
 *          %13 = CONST/UINT64 6
 *     >> %buf.14 = MEMORY/MEMCPY [%buf.0, %12, %13]
 *          %20 = CMP_NE [%18, %19]  // buf[0] != 'h'
 *     >> %21 = COND_BRANCH [%20]  // if (buf[0] != 'h') return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %27 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %33 = CMP_NE [%31, %32]  // buf[4] != 'o'
 *     >> %34 = COND_BRANCH [%33]  // if (buf[4] != 'o') return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %40 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %46 = CMP_NE [%44, %45]  // buf[5] != '\0'
 *     >> %47 = COND_BRANCH [%46]  // if (buf[5] != '\0') return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %53 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %p.1 = ALLOCA/LOCAL size=8 align=1
 *          %54 = ALLOCA/LOCAL size=6 align=1  // "world"
 *     >> %p.55 = MEMORY/STORE_LE_64 [%p.1, %54]
 *          %62 = CMP_NE [%60, %61]  // p[0] != 'w'
 *     >> %63 = COND_BRANCH [%62]  // if (p[0] != 'w') return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %69 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %76 = CMP_NE [%74, %75]  // p[4] != 'd'
 *     >> %77 = COND_BRANCH [%76]  // if (p[4] != 'd') return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %83 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *     >> %84 = ENTER_SCOPE  // my_strlen("test")
 *          %86 = ALLOCA/ARG size=8 align=1  // "test"
 *          %85 = ALLOCA/LOCAL size=5 align=1  // "test"
 *     >> %87 = MEMORY/STORE_LE_64 [%86, %85]  // "test"
 *          %len.2 = ALLOCA/LOCAL size=4 align=1
 *          %89 = CALL @my_strlen [%86]  // my_strlen("test")
 *     >> %len.90 = MEMORY/STORE_LE_32 [%len.2, %89]
 *     >> %94 = EXIT_SCOPE
 *          %93 = CMP_NE [%91, %92]  // len != 4
 *     >> %95 = COND_BRANCH [%93]  // if (len != 4) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %102 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %long_buf.3 = ALLOCA/LOCAL size=16 align=1
 *          %103 = ALLOCA/LOCAL size=16 align=1  // "0123456789abcde"
 *          %104 = CONST/UINT64 16
 *     >> %long_buf.105 = MEMORY/MEMCPY [%long_buf.3, %103, %104]
 *          %111 = CMP_NE [%109, %110]  // long_buf[0] != '0'
 *     >> %112 = COND_BRANCH [%111]  // if (long_buf[0] != '0') return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %118 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %124 = CMP_NE [%122, %123]  // long_buf[9] != '9'
 *     >> %125 = COND_BRANCH [%124]  // if (long_buf[9] != '9') return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %131 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %137 = CMP_NE [%135, %136]  // long_buf[14] != 'e'
 *     >> %138 = COND_BRANCH [%137]  // if (long_buf[14] != 'e') return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %144 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %150 = CMP_NE [%148, %149]  // long_buf[15] != '\0'
 *     >> %151 = COND_BRANCH [%150]  // if (long_buf[15] != '\0') return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %157 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %empty.4 = ALLOCA/LOCAL size=1 align=1
 *          %158 = ALLOCA/LOCAL size=1 align=1  // ""
 *          %159 = CONST/UINT64 1
 *     >> %empty.160 = MEMORY/MEMCPY [%empty.4, %158, %159]
 *          %166 = CMP_NE [%164, %165]  // empty[0] != '\0'
 *     >> %167 = COND_BRANCH [%166]  // if (empty[0] != '\0') return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %173 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %single.5 = ALLOCA/LOCAL size=2 align=1
 *          %174 = ALLOCA/LOCAL size=2 align=1  // "x"
 *          %175 = CONST/UINT64 2
 *     >> %single.176 = MEMORY/MEMCPY [%single.5, %174, %175]
 *          %182 = CMP_NE [%180, %181]  // single[0] != 'x'
 *     >> %183 = COND_BRANCH [%182]  // if (single[0] != 'x') return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %189 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %195 = CMP_NE [%193, %194]  // single[1] != '\0'
 *     >> %196 = COND_BRANCH [%195]  // if (single[1] != '\0') return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %202 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *          %wbuf.6 = ALLOCA/LOCAL size=12 align=1
 *          %203 = ALLOCA/LOCAL size=12 align=1  // L"hi"
 *          %204 = CONST/UINT64 12
 *     >> %wbuf.205 = MEMORY/MEMCPY [%wbuf.6, %203, %204]
 *          %210 = CMP_NE [%208, %209]  // wbuf[0] != L'h'
 *     >> %211 = COND_BRANCH [%210]  // if (wbuf[0] != L'h') return 14
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %217 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *          %222 = CMP_NE [%220, %221]  // wbuf[1] != L'i'
 *     >> %223 = COND_BRANCH [%222]  // if (wbuf[1] != L'i') return 15
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %229 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %234 = CMP_NE [%232, %233]  // wbuf[2] != L'\0'
 *     >> %235 = COND_BRANCH [%234]  // if (wbuf[2] != L'\0') return 16
 *     -> [block_47, block_48]
 *   block_48 IF_ELSE  <- [block_46]:
 *     >> %241 = IMPLICIT_GOTO
 *     -> [block_49]
 *   block_49 IF_MERGE  <- [block_48]:
 *          %u16buf.7 = ALLOCA/LOCAL size=8 align=1
 *          %242 = ALLOCA/LOCAL size=8 align=1  // u"abc"
 *          %243 = CONST/UINT64 8
 *     >> %u16buf.244 = MEMORY/MEMCPY [%u16buf.7, %242, %243]
 *          %251 = CMP_NE [%248, %250]  // u16buf[0] != u'a'
 *     >> %252 = COND_BRANCH [%251]  // if (u16buf[0] != u'a') return 17
 *     -> [block_50, block_51]
 *   block_51 IF_ELSE  <- [block_49]:
 *     >> %258 = IMPLICIT_GOTO
 *     -> [block_52]
 *   block_52 IF_MERGE  <- [block_51]:
 *          %264 = CMP_NE [%262, %263]  // u16buf[3] != 0
 *     >> %265 = COND_BRANCH [%264]  // if (u16buf[3] != 0) return 18
 *     -> [block_53, block_54]
 *   block_54 IF_ELSE  <- [block_52]:
 *     >> %271 = IMPLICIT_GOTO
 *     -> [block_55]
 *   block_55 IF_MERGE  <- [block_54]:
 *          %u32buf.8 = ALLOCA/LOCAL size=12 align=1
 *          %272 = ALLOCA/LOCAL size=12 align=1  // U"ab"
 *          %273 = CONST/UINT64 12
 *     >> %u32buf.274 = MEMORY/MEMCPY [%u32buf.8, %272, %273]
 *          %279 = CMP_NE [%277, %278]  // u32buf[0] != U'a'
 *     >> %280 = COND_BRANCH [%279]  // if (u32buf[0] != U'a') return 19
 *     -> [block_56, block_57]
 *   block_57 IF_ELSE  <- [block_55]:
 *     >> %286 = IMPLICIT_GOTO
 *     -> [block_58]
 *   block_58 IF_MERGE  <- [block_57]:
 *          %292 = CMP_NE [%289, %291]  // u32buf[2] != 0
 *     >> %293 = COND_BRANCH [%292]  // if (u32buf[2] != 0) return 20
 *     -> [block_59, block_60]
 *   block_60 IF_ELSE  <- [block_58]:
 *     >> %299 = IMPLICIT_GOTO
 *     -> [block_61]
 *   block_61 IF_MERGE  <- [block_60]:
 *          %oversized.9 = ALLOCA/LOCAL size=20 align=1
 *          %300 = ALLOCA/LOCAL size=3 align=1  // "hi"
 *          %301 = CONST/UINT64 3
 *     >> %oversized.302 = MEMORY/MEMCPY [%oversized.9, %300, %301]
 *          %308 = CMP_NE [%306, %307]  // oversized[0] != 'h'
 *     >> %309 = COND_BRANCH [%308]  // if (oversized[0] != 'h') return 21
 *     -> [block_62, block_63]
 *   block_63 IF_ELSE  <- [block_61]:
 *     >> %315 = IMPLICIT_GOTO
 *     -> [block_64]
 *   block_64 IF_MERGE  <- [block_63]:
 *          %321 = CMP_NE [%319, %320]  // oversized[2] != '\0'
 *     >> %322 = COND_BRANCH [%321]  // if (oversized[2] != '\0') return 22
 *     -> [block_65, block_66]
 *   block_66 IF_ELSE  <- [block_64]:
 *     >> %328 = IMPLICIT_GOTO
 *     -> [block_67]
 *   block_67 IF_MERGE  <- [block_66]:
 *          %334 = CMP_NE [%332, %333]  // oversized[19] != '\0'
 *     >> %335 = COND_BRANCH [%334]  // if (oversized[19] != '\0') return 23
 *     -> [block_68, block_69]
 *   block_69 IF_ELSE  <- [block_67]:
 *     >> %341 = IMPLICIT_GOTO
 *     -> [block_70]
 *   block_70 IF_MERGE  <- [block_69]:
 *          %343 = RETURN_PTR  // return 0
 *          %342 = CONST/INT32 0  // 0
 *     >> %344 = MEMORY/STORE_LE_32 [%343, %342]  // return 0
 *     >> %345 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %342 = CONST/INT32 0  // 0
 *     >> %346 = RET [%342]  // return 0
 *   block_68 IF_THEN  <- [block_67]:
 *          %337 = RETURN_PTR  // return 23
 *          %336 = CONST/INT32 23  // 23
 *     >> %338 = MEMORY/STORE_LE_32 [%337, %336]  // return 23
 *     >> %339 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %336 = CONST/INT32 23  // 23
 *     >> %340 = RET [%336]  // return 23
 *   block_65 IF_THEN  <- [block_64]:
 *          %324 = RETURN_PTR  // return 22
 *          %323 = CONST/INT32 22  // 22
 *     >> %325 = MEMORY/STORE_LE_32 [%324, %323]  // return 22
 *     >> %326 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %323 = CONST/INT32 22  // 22
 *     >> %327 = RET [%323]  // return 22
 *   block_62 IF_THEN  <- [block_61]:
 *          %311 = RETURN_PTR  // return 21
 *          %310 = CONST/INT32 21  // 21
 *     >> %312 = MEMORY/STORE_LE_32 [%311, %310]  // return 21
 *     >> %313 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %310 = CONST/INT32 21  // 21
 *     >> %314 = RET [%310]  // return 21
 *   block_59 IF_THEN  <- [block_58]:
 *          %295 = RETURN_PTR  // return 20
 *          %294 = CONST/INT32 20  // 20
 *     >> %296 = MEMORY/STORE_LE_32 [%295, %294]  // return 20
 *     >> %297 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %294 = CONST/INT32 20  // 20
 *     >> %298 = RET [%294]  // return 20
 *   block_56 IF_THEN  <- [block_55]:
 *          %282 = RETURN_PTR  // return 19
 *          %281 = CONST/INT32 19  // 19
 *     >> %283 = MEMORY/STORE_LE_32 [%282, %281]  // return 19
 *     >> %284 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %281 = CONST/INT32 19  // 19
 *     >> %285 = RET [%281]  // return 19
 *   block_53 IF_THEN  <- [block_52]:
 *          %267 = RETURN_PTR  // return 18
 *          %266 = CONST/INT32 18  // 18
 *     >> %268 = MEMORY/STORE_LE_32 [%267, %266]  // return 18
 *     >> %269 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %266 = CONST/INT32 18  // 18
 *     >> %270 = RET [%266]  // return 18
 *   block_50 IF_THEN  <- [block_49]:
 *          %254 = RETURN_PTR  // return 17
 *          %253 = CONST/INT32 17  // 17
 *     >> %255 = MEMORY/STORE_LE_32 [%254, %253]  // return 17
 *     >> %256 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %253 = CONST/INT32 17  // 17
 *     >> %257 = RET [%253]  // return 17
 *   block_47 IF_THEN  <- [block_46]:
 *          %237 = RETURN_PTR  // return 16
 *          %236 = CONST/INT32 16  // 16
 *     >> %238 = MEMORY/STORE_LE_32 [%237, %236]  // return 16
 *     >> %239 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %236 = CONST/INT32 16  // 16
 *     >> %240 = RET [%236]  // return 16
 *   block_44 IF_THEN  <- [block_43]:
 *          %225 = RETURN_PTR  // return 15
 *          %224 = CONST/INT32 15  // 15
 *     >> %226 = MEMORY/STORE_LE_32 [%225, %224]  // return 15
 *     >> %227 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %224 = CONST/INT32 15  // 15
 *     >> %228 = RET [%224]  // return 15
 *   block_41 IF_THEN  <- [block_40]:
 *          %213 = RETURN_PTR  // return 14
 *          %212 = CONST/INT32 14  // 14
 *     >> %214 = MEMORY/STORE_LE_32 [%213, %212]  // return 14
 *     >> %215 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %212 = CONST/INT32 14  // 14
 *     >> %216 = RET [%212]  // return 14
 *   block_38 IF_THEN  <- [block_37]:
 *          %198 = RETURN_PTR  // return 13
 *          %197 = CONST/INT32 13  // 13
 *     >> %199 = MEMORY/STORE_LE_32 [%198, %197]  // return 13
 *     >> %200 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %197 = CONST/INT32 13  // 13
 *     >> %201 = RET [%197]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %185 = RETURN_PTR  // return 12
 *          %184 = CONST/INT32 12  // 12
 *     >> %186 = MEMORY/STORE_LE_32 [%185, %184]  // return 12
 *     >> %187 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %184 = CONST/INT32 12  // 12
 *     >> %188 = RET [%184]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %169 = RETURN_PTR  // return 11
 *          %168 = CONST/INT32 11  // 11
 *     >> %170 = MEMORY/STORE_LE_32 [%169, %168]  // return 11
 *     >> %171 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %168 = CONST/INT32 11  // 11
 *     >> %172 = RET [%168]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %153 = RETURN_PTR  // return 10
 *          %152 = CONST/INT32 10  // 10
 *     >> %154 = MEMORY/STORE_LE_32 [%153, %152]  // return 10
 *     >> %155 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %152 = CONST/INT32 10  // 10
 *     >> %156 = RET [%152]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %140 = RETURN_PTR  // return 9
 *          %139 = CONST/INT32 9  // 9
 *     >> %141 = MEMORY/STORE_LE_32 [%140, %139]  // return 9
 *     >> %142 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %139 = CONST/INT32 9  // 9
 *     >> %143 = RET [%139]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %127 = RETURN_PTR  // return 8
 *          %126 = CONST/INT32 8  // 8
 *     >> %128 = MEMORY/STORE_LE_32 [%127, %126]  // return 8
 *     >> %129 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %126 = CONST/INT32 8  // 8
 *     >> %130 = RET [%126]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %114 = RETURN_PTR  // return 7
 *          %113 = CONST/INT32 7  // 7
 *     >> %115 = MEMORY/STORE_LE_32 [%114, %113]  // return 7
 *     >> %116 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %113 = CONST/INT32 7  // 7
 *     >> %117 = RET [%113]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %97 = RETURN_PTR  // return 6
 *          %96 = CONST/INT32 6  // 6
 *     >> %98 = MEMORY/STORE_LE_32 [%97, %96]  // return 6
 *     >> %99 = EXIT_SCOPE  // my_strlen("test")
 *     >> %100 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %96 = CONST/INT32 6  // 6
 *     >> %101 = RET [%96]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %79 = RETURN_PTR  // return 5
 *          %78 = CONST/INT32 5  // 5
 *     >> %80 = MEMORY/STORE_LE_32 [%79, %78]  // return 5
 *     >> %81 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %78 = CONST/INT32 5  // 5
 *     >> %82 = RET [%78]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %65 = RETURN_PTR  // return 4
 *          %64 = CONST/INT32 4  // 4
 *     >> %66 = MEMORY/STORE_LE_32 [%65, %64]  // return 4
 *     >> %67 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %64 = CONST/INT32 4  // 4
 *     >> %68 = RET [%64]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %49 = RETURN_PTR  // return 3
 *          %48 = CONST/INT32 3  // 3
 *     >> %50 = MEMORY/STORE_LE_32 [%49, %48]  // return 3
 *     >> %51 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %48 = CONST/INT32 3  // 3
 *     >> %52 = RET [%48]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %36 = RETURN_PTR  // return 2
 *          %35 = CONST/INT32 2  // 2
 *     >> %37 = MEMORY/STORE_LE_32 [%36, %35]  // return 2
 *     >> %38 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %35 = CONST/INT32 2  // 2
 *     >> %39 = RET [%35]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %23 = RETURN_PTR  // return 1
 *          %22 = CONST/INT32 1  // 1
 *     >> %24 = MEMORY/STORE_LE_32 [%23, %22]  // return 1
 *     >> %25 = EXIT_SCOPE  // {     // String literal initialization of char ...
 *          %22 = CONST/INT32 1  // 1
 *     >> %26 = RET [%22]  // return 1
 * }
 */










static int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int test_string_literals(void) {
    // String literal initialization of char array.
    // "hello" is char[6] (5 chars + null) — non-power-of-2 → MEMCPY.
    char buf[6] = "hello";
    if (buf[0] != 'h') return 1;
    if (buf[4] != 'o') return 2;
    if (buf[5] != '\0') return 3;

    // String pointer (decays to pointer to string literal storage).
    const char *p = "world";
    if (p[0] != 'w') return 4;
    if (p[4] != 'd') return 5;

    // String literal in function call.
    int len = my_strlen("test");
    if (len != 4) return 6;

    // Longer string (> 8 bytes, definitely MEMCPY).
    char long_buf[16] = "0123456789abcde";
    if (long_buf[0] != '0') return 7;
    if (long_buf[9] != '9') return 8;
    if (long_buf[14] != 'e') return 9;
    if (long_buf[15] != '\0') return 10;

    // Empty string.
    char empty[1] = "";
    if (empty[0] != '\0') return 11;

    // Single character string.
    char single[2] = "x";
    if (single[0] != 'x') return 12;
    if (single[1] != '\0') return 13;

    // Wide string literal (wchar_t, typically 4 bytes per char on this platform).
    // L"hi" is 3 wchar_t values: 'h', 'i', '\0'.
    typedef __WCHAR_TYPE__ wchar_t;
    _Static_assert(sizeof(L'x') == 4, "wchar_t must be 4 bytes");
    wchar_t wbuf[3] = L"hi";
    if (wbuf[0] != L'h') return 14;
    if (wbuf[1] != L'i') return 15;
    if (wbuf[2] != L'\0') return 16;

    // char16_t string (C11 u"..." — 2 bytes per char).
    // Requires <uchar.h> but we can use __CHAR16_TYPE__ directly.
    typedef __CHAR16_TYPE__ char16_t;
    char16_t u16buf[4] = u"abc";
    if (u16buf[0] != u'a') return 17;
    if (u16buf[3] != 0) return 18;

    // char32_t string (C11 U"..." — 4 bytes per char).
    typedef __CHAR32_TYPE__ char32_t;
    char32_t u32buf[3] = U"ab";
    if (u32buf[0] != U'a') return 19;
    if (u32buf[2] != 0) return 20;

    // Oversized destination: char x[20] = "hi" — 3 bytes copied, rest zero.
    char oversized[20] = "hi";
    if (oversized[0] != 'h') return 21;
    if (oversized[2] != '\0') return 22;
    if (oversized[19] != '\0') return 23;

    return 0;
}
