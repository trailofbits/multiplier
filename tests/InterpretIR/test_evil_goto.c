// Tests: evil goto patterns, Duff's device, gotos crossing scope boundaries,
// gotos into/out of switch cases, interleaved loops and gotos.

/*
 * Expected IR:
 *
 * function test_evil_goto (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=11 align=1 (src)
 *     obj_1 LOCAL_VALUE size=11 align=1 (dst)
 *     obj_2 LOCAL_VALUE size=4 align=1 (dst2)
 *     obj_3 PARAMETER size=8 align=8
 *     obj_4 PARAMETER size=8 align=8
 *     obj_5 PARAMETER size=4 align=4
 *     obj_6 PARAMETER size=8 align=8
 *     obj_7 PARAMETER size=8 align=8
 *     obj_8 PARAMETER size=4 align=4
 *     obj_9 RETURN_SLOT size=4 align=4
 *     obj_10 RETURN_SLOT size=4 align=4
 *     obj_11 RETURN_SLOT size=4 align=4
 *     obj_12 RETURN_SLOT size=4 align=4
 *     obj_13 PARAMETER size=4 align=4
 *     obj_14 RETURN_SLOT size=4 align=4
 *     obj_15 PARAMETER size=4 align=4
 *     obj_16 RETURN_SLOT size=4 align=4
 *     obj_17 PARAMETER size=4 align=4
 *     obj_18 RETURN_SLOT size=4 align=4
 *     obj_19 PARAMETER size=4 align=4
 *     obj_20 RETURN_SLOT size=4 align=4
 *     obj_21 PARAMETER size=4 align=4
 *     obj_22 RETURN_SLOT size=4 align=4
 *     obj_23 PARAMETER size=4 align=4
 *     obj_24 RETURN_SLOT size=4 align=4
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %src.0 = ALLOCA/LOCAL size=11 align=1
 *     >> %dst.1 = ALLOCA/LOCAL size=11 align=1
 *     >> %dst2.2 = ALLOCA/LOCAL size=4 align=1
 *     >> %3 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %4 = ENTER_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %5 = ENTER_SCOPE  // {         char src[11] = "0123456789";         ...
 *          %src.0 = ALLOCA/LOCAL size=11 align=1
 *          %6 = STRING_PTR  // "0123456789"
 *          %7 = CONST/UINT64 11
 *     >> %src.8 = MEMORY/MEMCPY [%src.0, %6, %7]
 *          %dst.1 = ALLOCA/LOCAL size=11 align=1
 *          %dst.9 = CONST/UINT8 0
 *          %dst.10 = CONST/UINT64 11
 *     >> %dst.11 = MEMORY/MEMSET [%dst.1, %dst.9, %dst.10]
 *          %12 = CONST/INT32 0  // 0
 *          %13 = CAST/TRUNC_I32_I8 [%12]  // 0
 *     >> %dst.14 = MEMORY/STORE_LE_8 [%dst.1, %13]
 *     >> %15 = ENTER_SCOPE  // duffs_copy(dst, src, 10)
 *          %16 = ALLOCA/ARG size=8 align=8  // dst
 *     >> %17 = MEMORY/STORE_LE_64 [%16, %dst.1]  // dst
 *          %18 = ALLOCA/ARG size=8 align=8  // src
 *     >> %19 = MEMORY/STORE_LE_64 [%18, %src.0]  // src
 *          %21 = ALLOCA/ARG size=4 align=4  // 10
 *          %20 = CONST/INT32 10  // 10
 *     >> %22 = MEMORY/STORE_LE_32 [%21, %20]  // 10
 *     >> %23 = CALL @duffs_copy [%16, %18, %21]  // duffs_copy(dst, src, 10)
 *     >> %24 = EXIT_SCOPE
 *          %25 = CONST/INT32 0  // 0
 *          %26 = PTR_ADD elem_size=1 [%dst.1, %25]  // dst[0]
 *          %27 = MEMORY/LOAD_LE_8 [%26]  // dst[0]
 *          %28 = CAST/SEXT_I8_I32 [%27]  // dst[0]
 *          %29 = CONST/UINT8 48  // '0'
 *          %30 = CMP_NE [%28, %29]  // dst[0] != '0'
 *     >> %31 = COND_BRANCH [%30]  // if (dst[0] != '0') return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %38 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %dst.1 = ALLOCA/LOCAL size=11 align=1
 *          %39 = CONST/INT32 9  // 9
 *          %40 = PTR_ADD elem_size=1 [%dst.1, %39]  // dst[9]
 *          %41 = MEMORY/LOAD_LE_8 [%40]  // dst[9]
 *          %42 = CAST/SEXT_I8_I32 [%41]  // dst[9]
 *          %43 = CONST/UINT8 57  // '9'
 *          %44 = CMP_NE [%42, %43]  // dst[9] != '9'
 *     >> %45 = COND_BRANCH [%44]  // if (dst[9] != '9') return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %52 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %dst.1 = ALLOCA/LOCAL size=11 align=1
 *          %53 = CONST/INT32 10  // 10
 *          %54 = PTR_ADD elem_size=1 [%dst.1, %53]  // dst[10]
 *          %55 = MEMORY/LOAD_LE_8 [%54]  // dst[10]
 *          %56 = CAST/SEXT_I8_I32 [%55]  // dst[10]
 *          %57 = CONST/UINT8 0  // '\0'
 *          %58 = CMP_NE [%56, %57]  // dst[10] != '\0'
 *     >> %59 = COND_BRANCH [%58]  // if (dst[10] != '\0') return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %66 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %dst2.2 = ALLOCA/LOCAL size=4 align=1
 *          %dst2.67 = CONST/UINT8 0
 *          %dst2.68 = CONST/UINT64 4
 *     >> %dst2.69 = MEMORY/MEMSET [%dst2.2, %dst2.67, %dst2.68]
 *          %70 = CONST/INT32 0  // 0
 *          %71 = CAST/TRUNC_I32_I8 [%70]  // 0
 *     >> %dst2.72 = MEMORY/STORE_LE_8 [%dst2.2, %71]
 *     >> %73 = ENTER_SCOPE  // duffs_copy(dst2, src, 3)
 *          %74 = ALLOCA/ARG size=8 align=8  // dst2
 *     >> %75 = MEMORY/STORE_LE_64 [%74, %dst2.2]  // dst2
 *          %76 = ALLOCA/ARG size=8 align=8  // src
 *          %src.0 = ALLOCA/LOCAL size=11 align=1
 *     >> %77 = MEMORY/STORE_LE_64 [%76, %src.0]  // src
 *          %79 = ALLOCA/ARG size=4 align=4  // 3
 *          %78 = CONST/INT32 3  // 3
 *     >> %80 = MEMORY/STORE_LE_32 [%79, %78]  // 3
 *     >> %81 = CALL @duffs_copy [%74, %76, %79]  // duffs_copy(dst2, src, 3)
 *     >> %82 = EXIT_SCOPE
 *          %83 = CONST/INT32 0  // 0
 *          %84 = PTR_ADD elem_size=1 [%dst2.2, %83]  // dst2[0]
 *          %85 = MEMORY/LOAD_LE_8 [%84]  // dst2[0]
 *          %86 = CAST/SEXT_I8_I32 [%85]  // dst2[0]
 *          %87 = CONST/UINT8 48  // '0'
 *          %88 = CMP_NE [%86, %87]  // dst2[0] != '0'
 *     >> %89 = COND_BRANCH [%88]  // if (dst2[0] != '0') return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %96 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %dst2.2 = ALLOCA/LOCAL size=4 align=1
 *          %97 = CONST/INT32 2  // 2
 *          %98 = PTR_ADD elem_size=1 [%dst2.2, %97]  // dst2[2]
 *          %99 = MEMORY/LOAD_LE_8 [%98]  // dst2[2]
 *          %100 = CAST/SEXT_I8_I32 [%99]  // dst2[2]
 *          %101 = CONST/UINT8 50  // '2'
 *          %102 = CMP_NE [%100, %101]  // dst2[2] != '2'
 *     >> %103 = COND_BRANCH [%102]  // if (dst2[2] != '2') return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %110 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *     >> %111 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %112 = ENTER_SCOPE  // goto_into_scope()
 *     >> %117 = EXIT_SCOPE
 *          %114 = CALL @goto_into_scope  // goto_into_scope()
 *          %115 = CONST/INT32 42  // 42
 *          %116 = CMP_NE [%114, %115]  // goto_into_scope() != 42
 *     >> %118 = COND_BRANCH [%116]  // if (goto_into_scope() != 42) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %124 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *     >> %125 = ENTER_SCOPE  // goto_escape_nested()
 *     >> %130 = EXIT_SCOPE
 *          %127 = CALL @goto_escape_nested  // goto_escape_nested()
 *          %128 = CONST/INT32 6  // 6
 *          %129 = CMP_NE [%127, %128]  // goto_escape_nested() != 6
 *     >> %131 = COND_BRANCH [%129]  // if (goto_escape_nested() != 6) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %137 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *     >> %138 = ENTER_SCOPE  // goto_skip_decls()
 *     >> %143 = EXIT_SCOPE
 *          %140 = CALL @goto_skip_decls  // goto_skip_decls()
 *          %141 = CONST/INT32 0  // 0
 *          %142 = CMP_NE [%140, %141]  // goto_skip_decls() != 0
 *     >> %144 = COND_BRANCH [%142]  // if (goto_skip_decls() != 0) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %150 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *     >> %151 = ENTER_SCOPE  // goto_loop_with_scope()
 *     >> %156 = EXIT_SCOPE
 *          %153 = CALL @goto_loop_with_scope  // goto_loop_with_scope()
 *          %154 = CONST/INT32 15  // 15
 *          %155 = CMP_NE [%153, %154]  // goto_loop_with_scope() != 15
 *     >> %157 = COND_BRANCH [%155]  // if (goto_loop_with_scope() != 15) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %163 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *     >> %164 = ENTER_SCOPE  // goto_between_cases(1)
 *          %166 = ALLOCA/ARG size=4 align=4  // 1
 *          %165 = CONST/INT32 1  // 1
 *     >> %167 = MEMORY/STORE_LE_32 [%166, %165]  // 1
 *     >> %172 = EXIT_SCOPE
 *          %169 = CALL @goto_between_cases [%166]  // goto_between_cases(1)
 *          %170 = CONST/INT32 110  // 110
 *          %171 = CMP_NE [%169, %170]  // goto_between_cases(1) != 110
 *     >> %173 = COND_BRANCH [%171]  // if (goto_between_cases(1) != 110) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %179 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *     >> %180 = ENTER_SCOPE  // goto_between_cases(2)
 *          %182 = ALLOCA/ARG size=4 align=4  // 2
 *          %181 = CONST/INT32 2  // 2
 *     >> %183 = MEMORY/STORE_LE_32 [%182, %181]  // 2
 *     >> %188 = EXIT_SCOPE
 *          %185 = CALL @goto_between_cases [%182]  // goto_between_cases(2)
 *          %186 = CONST/INT32 20  // 20
 *          %187 = CMP_NE [%185, %186]  // goto_between_cases(2) != 20
 *     >> %189 = COND_BRANCH [%187]  // if (goto_between_cases(2) != 20) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %195 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *     >> %196 = ENTER_SCOPE  // goto_between_cases(3)
 *          %198 = ALLOCA/ARG size=4 align=4  // 3
 *          %197 = CONST/INT32 3  // 3
 *     >> %199 = MEMORY/STORE_LE_32 [%198, %197]  // 3
 *     >> %204 = EXIT_SCOPE
 *          %201 = CALL @goto_between_cases [%198]  // goto_between_cases(3)
 *          %202 = CONST/INT32 100  // 100
 *          %203 = CMP_NE [%201, %202]  // goto_between_cases(3) != 100
 *     >> %205 = COND_BRANCH [%203]  // if (goto_between_cases(3) != 100) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %211 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *     >> %212 = ENTER_SCOPE  // multi_source_goto(1)
 *          %214 = ALLOCA/ARG size=4 align=4  // 1
 *          %213 = CONST/INT32 1  // 1
 *     >> %215 = MEMORY/STORE_LE_32 [%214, %213]  // 1
 *     >> %220 = EXIT_SCOPE
 *          %217 = CALL @multi_source_goto [%214]  // multi_source_goto(1)
 *          %218 = CONST/INT32 10  // 10
 *          %219 = CMP_NE [%217, %218]  // multi_source_goto(1) != 10
 *     >> %221 = COND_BRANCH [%219]  // if (multi_source_goto(1) != 10) return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %227 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *     >> %228 = ENTER_SCOPE  // multi_source_goto(2)
 *          %230 = ALLOCA/ARG size=4 align=4  // 2
 *          %229 = CONST/INT32 2  // 2
 *     >> %231 = MEMORY/STORE_LE_32 [%230, %229]  // 2
 *     >> %236 = EXIT_SCOPE
 *          %233 = CALL @multi_source_goto [%230]  // multi_source_goto(2)
 *          %234 = CONST/INT32 20  // 20
 *          %235 = CMP_NE [%233, %234]  // multi_source_goto(2) != 20
 *     >> %237 = COND_BRANCH [%235]  // if (multi_source_goto(2) != 20) return 14
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %243 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *     >> %244 = ENTER_SCOPE  // multi_source_goto(0)
 *          %246 = ALLOCA/ARG size=4 align=4  // 0
 *          %245 = CONST/INT32 0  // 0
 *     >> %247 = MEMORY/STORE_LE_32 [%246, %245]  // 0
 *     >> %252 = EXIT_SCOPE
 *          %249 = CALL @multi_source_goto [%246]  // multi_source_goto(0)
 *          %250 = CONST/INT32 30  // 30
 *          %251 = CMP_NE [%249, %250]  // multi_source_goto(0) != 30
 *     >> %253 = COND_BRANCH [%251]  // if (multi_source_goto(0) != 30) return 15
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %259 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %261 = RETURN_PTR  // return 0
 *          %260 = CONST/INT32 0  // 0
 *     >> %262 = MEMORY/STORE_LE_32 [%261, %260]  // return 0
 *     >> %263 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %264 = RET [%260]  // return 0
 *   block_44 IF_THEN  <- [block_43]:
 *          %255 = RETURN_PTR  // return 15
 *          %254 = CONST/INT32 15  // 15
 *     >> %256 = MEMORY/STORE_LE_32 [%255, %254]  // return 15
 *     >> %257 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %258 = RET [%254]  // return 15
 *   block_41 IF_THEN  <- [block_40]:
 *          %239 = RETURN_PTR  // return 14
 *          %238 = CONST/INT32 14  // 14
 *     >> %240 = MEMORY/STORE_LE_32 [%239, %238]  // return 14
 *     >> %241 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %242 = RET [%238]  // return 14
 *   block_38 IF_THEN  <- [block_37]:
 *          %223 = RETURN_PTR  // return 13
 *          %222 = CONST/INT32 13  // 13
 *     >> %224 = MEMORY/STORE_LE_32 [%223, %222]  // return 13
 *     >> %225 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %226 = RET [%222]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %207 = RETURN_PTR  // return 12
 *          %206 = CONST/INT32 12  // 12
 *     >> %208 = MEMORY/STORE_LE_32 [%207, %206]  // return 12
 *     >> %209 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %210 = RET [%206]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %191 = RETURN_PTR  // return 11
 *          %190 = CONST/INT32 11  // 11
 *     >> %192 = MEMORY/STORE_LE_32 [%191, %190]  // return 11
 *     >> %193 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %194 = RET [%190]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %175 = RETURN_PTR  // return 10
 *          %174 = CONST/INT32 10  // 10
 *     >> %176 = MEMORY/STORE_LE_32 [%175, %174]  // return 10
 *     >> %177 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %178 = RET [%174]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %159 = RETURN_PTR  // return 9
 *          %158 = CONST/INT32 9  // 9
 *     >> %160 = MEMORY/STORE_LE_32 [%159, %158]  // return 9
 *     >> %161 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %162 = RET [%158]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %146 = RETURN_PTR  // return 8
 *          %145 = CONST/INT32 8  // 8
 *     >> %147 = MEMORY/STORE_LE_32 [%146, %145]  // return 8
 *     >> %148 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %149 = RET [%145]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %133 = RETURN_PTR  // return 7
 *          %132 = CONST/INT32 7  // 7
 *     >> %134 = MEMORY/STORE_LE_32 [%133, %132]  // return 7
 *     >> %135 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %136 = RET [%132]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %120 = RETURN_PTR  // return 6
 *          %119 = CONST/INT32 6  // 6
 *     >> %121 = MEMORY/STORE_LE_32 [%120, %119]  // return 6
 *     >> %122 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %123 = RET [%119]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %105 = RETURN_PTR  // return 5
 *          %104 = CONST/INT32 5  // 5
 *     >> %106 = MEMORY/STORE_LE_32 [%105, %104]  // return 5
 *     >> %107 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %108 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %109 = RET [%104]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %91 = RETURN_PTR  // return 4
 *          %90 = CONST/INT32 4  // 4
 *     >> %92 = MEMORY/STORE_LE_32 [%91, %90]  // return 4
 *     >> %93 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %94 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %95 = RET [%90]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %61 = RETURN_PTR  // return 3
 *          %60 = CONST/INT32 3  // 3
 *     >> %62 = MEMORY/STORE_LE_32 [%61, %60]  // return 3
 *     >> %63 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %64 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %65 = RET [%60]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %47 = RETURN_PTR  // return 2
 *          %46 = CONST/INT32 2  // 2
 *     >> %48 = MEMORY/STORE_LE_32 [%47, %46]  // return 2
 *     >> %49 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %50 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %51 = RET [%46]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %33 = RETURN_PTR  // return 1
 *          %32 = CONST/INT32 1  // 1
 *     >> %34 = MEMORY/STORE_LE_32 [%33, %32]  // return 1
 *     >> %35 = EXIT_SCOPE  // {         char src[11] = "0123456789";         ...
 *     >> %36 = EXIT_SCOPE  // {     // Duff's device.     {         char src[...
 *     >> %37 = RET [%32]  // return 1
 * }
 */










// Classic Duff's device: copy n bytes from src to dst.
static void duffs_copy(char *dst, const char *src, int n) {
    int remaining = n;
    if (remaining <= 0) return;
    int chunks = (remaining + 7) / 8;
    switch (remaining % 8) {
        case 0: do { *dst++ = *src++;
        case 7:      *dst++ = *src++;
        case 6:      *dst++ = *src++;
        case 5:      *dst++ = *src++;
        case 4:      *dst++ = *src++;
        case 3:      *dst++ = *src++;
        case 2:      *dst++ = *src++;
        case 1:      *dst++ = *src++;
                } while (--chunks > 0);
    }
}

// Goto into a nested scope — variable declared in scope, goto skips init.
static int goto_into_scope(void) {
    int result = 0;
    goto inside;
    {
        int x = 99;  // skipped by goto
inside:
        // x is uninitialized here (skipped), but result is valid.
        result = 42;
    }
    return result;
}

// Goto out of deeply nested scopes.
static int goto_escape_nested(void) {
    int val = 0;
    {
        int a = 1;
        {
            int b = 2;
            {
                int c = 3;
                val = a + b + c;  // 6
                goto escape;
                val = 999;  // unreachable
            }
            val = 888;  // unreachable
        }
        val = 777;  // unreachable
    }
escape:
    return val;
}

// Forward goto skipping variable declarations.
static int goto_skip_decls(void) {
    int r = 0;
    goto skip;
    int x = 10;  // skipped
    r = x;       // skipped
skip:
    // x exists but was never initialized. r should still be 0.
    return r;
}

// Goto used as a loop with scope entry/exit each iteration.
static int goto_loop_with_scope(void) {
    int total = 0;
    int i = 0;
loop_top:
    if (i >= 5) goto loop_done;
    {
        int increment = i + 1;
        total += increment;
        i++;
    }
    goto loop_top;
loop_done:
    // total = 1 + 2 + 3 + 4 + 5 = 15
    return total;
}

// Goto between switch cases (not fallthrough — explicit goto).
static int goto_between_cases(int selector) {
    int result = 0;
    switch (selector) {
        case 1:
            result = 10;
            goto case3_body;
        case 2:
            result = 20;
            break;
        case 3:
case3_body:
            result += 100;
            break;
    }
    return result;
}

// Multiple gotos to the same label from different scopes.
static int multi_source_goto(int path) {
    int result = 0;
    if (path == 1) {
        int x = 10;
        result = x;
        goto merge;
    }
    if (path == 2) {
        int y = 20;
        result = y;
        goto merge;
    }
    result = 30;
merge:
    return result;
}

int test_evil_goto(void) {
    // Duff's device.
    {
        char src[11] = "0123456789";
        char dst[11] = {0};
        duffs_copy(dst, src, 10);
        if (dst[0] != '0') return 1;
        if (dst[9] != '9') return 2;
        if (dst[10] != '\0') return 3;

        // Duff with non-multiple-of-8 count.
        char dst2[4] = {0};
        duffs_copy(dst2, src, 3);
        if (dst2[0] != '0') return 4;
        if (dst2[2] != '2') return 5;
    }

    // Goto into scope.
    if (goto_into_scope() != 42) return 6;

    // Goto escaping nested scopes.
    if (goto_escape_nested() != 6) return 7;

    // Goto skipping declarations.
    if (goto_skip_decls() != 0) return 8;

    // Goto loop with scope entry/exit.
    if (goto_loop_with_scope() != 15) return 9;

    // Goto between switch cases: case 1 → goto case3_body → result = 10 + 100 = 110.
    if (goto_between_cases(1) != 110) return 10;
    // Case 2 → result = 20.
    if (goto_between_cases(2) != 20) return 11;
    // Case 3 → result = 0 + 100 = 100.
    if (goto_between_cases(3) != 100) return 12;

    // Multi-source goto.
    if (multi_source_goto(1) != 10) return 13;
    if (multi_source_goto(2) != 20) return 14;
    if (multi_source_goto(0) != 30) return 15;

    return 0;
}
