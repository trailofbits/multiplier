// Tests: unsigned integer operations — zero extension, unsigned arithmetic,
// unsigned comparisons, unsigned overflow/wrap-around, mixing signed/unsigned.

/*
 * Expected IR:
 *
 * function test_unsigned (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=4 align=4 (ua)
 *     obj_1 LOCAL_VALUE size=4 align=4 (ub)
 *     obj_2 LOCAL_VALUE size=4 align=4 (sum)
 *     obj_3 LOCAL_VALUE size=4 align=4 (diff)
 *     obj_4 LOCAL_VALUE size=4 align=4 (wrapped)
 *     obj_5 LOCAL_VALUE size=1 align=1 (uc)
 *     obj_6 LOCAL_VALUE size=4 align=4 (zext)
 *     obj_7 LOCAL_VALUE size=1 align=1 (sc)
 *     obj_8 LOCAL_VALUE size=4 align=4 (sext)
 *     obj_9 LOCAL_VALUE size=4 align=4 (udiv)
 *     obj_10 LOCAL_VALUE size=4 align=4 (umod)
 *     obj_11 LOCAL_VALUE size=4 align=4 (large)
 *     obj_12 LOCAL_VALUE size=4 align=4 (half)
 *     obj_13 LOCAL_VALUE size=4 align=4 (shifted)
 *     obj_14 LOCAL_VALUE size=4 align=4 (rshifted)
 *     obj_15 LOCAL_VALUE size=4 align=4 (uval)
 *     obj_16 LOCAL_VALUE size=4 align=4 (high)
 *     obj_17 LOCAL_VALUE size=4 align=4 (low)
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %ua.0 = ALLOCA/LOCAL size=4 align=4
 *     >> %ub.1 = ALLOCA/LOCAL size=4 align=4
 *     >> %sum.2 = ALLOCA/LOCAL size=4 align=4
 *     >> %diff.3 = ALLOCA/LOCAL size=4 align=4
 *     >> %wrapped.4 = ALLOCA/LOCAL size=4 align=4
 *     >> %uc.5 = ALLOCA/LOCAL size=1 align=1
 *     >> %zext.6 = ALLOCA/LOCAL size=4 align=4
 *     >> %sc.7 = ALLOCA/LOCAL size=1 align=1
 *     >> %sext.8 = ALLOCA/LOCAL size=4 align=4
 *     >> %udiv.9 = ALLOCA/LOCAL size=4 align=4
 *     >> %umod.10 = ALLOCA/LOCAL size=4 align=4
 *     >> %large.11 = ALLOCA/LOCAL size=4 align=4
 *     >> %half.12 = ALLOCA/LOCAL size=4 align=4
 *     >> %shifted.13 = ALLOCA/LOCAL size=4 align=4
 *     >> %rshifted.14 = ALLOCA/LOCAL size=4 align=4
 *     >> %uval.15 = ALLOCA/LOCAL size=4 align=4
 *     >> %high.16 = ALLOCA/LOCAL size=4 align=4
 *     >> %low.17 = ALLOCA/LOCAL size=4 align=4
 *     >> %18 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %19 = ENTER_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *          %ua.0 = ALLOCA/LOCAL size=4 align=4
 *          %20 = CONST/INT32 200  // 200
 *          %21 = CAST/IDENTITY [%20]  // 200
 *     >> %ua.22 = MEMORY/STORE_LE_32 [%ua.0, %21]
 *          %ub.1 = ALLOCA/LOCAL size=4 align=4
 *          %23 = CONST/INT32 100  // 100
 *          %24 = CAST/IDENTITY [%23]  // 100
 *     >> %ub.25 = MEMORY/STORE_LE_32 [%ub.1, %24]
 *          %sum.2 = ALLOCA/LOCAL size=4 align=4
 *          %26 = MEMORY/LOAD_LE_32 [%ua.0]  // ua
 *          %27 = MEMORY/LOAD_LE_32 [%ub.1]  // ub
 *          %28 = ADD [%26, %27]  // ua + ub
 *     >> %sum.29 = MEMORY/STORE_LE_32 [%sum.2, %28]
 *          %30 = MEMORY/LOAD_LE_32 [%sum.2]  // sum
 *          %31 = CONST/INT32 300  // 300
 *          %32 = CAST/IDENTITY [%31]  // 300
 *          %33 = CMP_NE [%30, %32]  // sum != 300
 *     >> %34 = COND_BRANCH [%33]  // if (sum != 300) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %40 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %diff.3 = ALLOCA/LOCAL size=4 align=4
 *          %ua.0 = ALLOCA/LOCAL size=4 align=4
 *          %41 = MEMORY/LOAD_LE_32 [%ua.0]  // ua
 *          %ub.1 = ALLOCA/LOCAL size=4 align=4
 *          %42 = MEMORY/LOAD_LE_32 [%ub.1]  // ub
 *          %43 = SUB [%41, %42]  // ua - ub
 *     >> %diff.44 = MEMORY/STORE_LE_32 [%diff.3, %43]
 *          %45 = MEMORY/LOAD_LE_32 [%diff.3]  // diff
 *          %46 = CONST/INT32 100  // 100
 *          %47 = CAST/IDENTITY [%46]  // 100
 *          %48 = CMP_NE [%45, %47]  // diff != 100
 *     >> %49 = COND_BRANCH [%48]  // if (diff != 100) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %55 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %ua.0 = ALLOCA/LOCAL size=4 align=4
 *          %56 = MEMORY/LOAD_LE_32 [%ua.0]  // ua
 *          %ub.1 = ALLOCA/LOCAL size=4 align=4
 *          %57 = MEMORY/LOAD_LE_32 [%ub.1]  // ub
 *          %58 = UCMP_GT [%56, %57]  // ua > ub
 *          %59 = LOGICAL_NOT [%58]  // !(ua > ub)
 *     >> %60 = COND_BRANCH [%59]  // if (!(ua > ub)) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %66 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %ua.0 = ALLOCA/LOCAL size=4 align=4
 *          %67 = MEMORY/LOAD_LE_32 [%ua.0]  // ua
 *          %ub.1 = ALLOCA/LOCAL size=4 align=4
 *          %68 = MEMORY/LOAD_LE_32 [%ub.1]  // ub
 *          %69 = UCMP_LT [%67, %68]  // ua < ub
 *     >> %70 = COND_BRANCH [%69]  // if (ua < ub) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %76 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %ua.0 = ALLOCA/LOCAL size=4 align=4
 *          %77 = MEMORY/LOAD_LE_32 [%ua.0]  // ua
 *          %ub.1 = ALLOCA/LOCAL size=4 align=4
 *          %78 = MEMORY/LOAD_LE_32 [%ub.1]  // ub
 *          %79 = CMP_EQ [%77, %78]  // ua == ub
 *     >> %80 = COND_BRANCH [%79]  // if (ua == ub) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %86 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %wrapped.4 = ALLOCA/LOCAL size=4 align=4
 *          %87 = CONST/UINT32 0  // 0u
 *          %88 = CONST/UINT32 1  // 1u
 *          %89 = SUB [%87, %88]  // 0u - 1u
 *     >> %wrapped.90 = MEMORY/STORE_LE_32 [%wrapped.4, %89]
 *          %91 = MEMORY/LOAD_LE_32 [%wrapped.4]  // wrapped
 *          %92 = CONST/UINT32 4294967295  // 4294967295u
 *          %93 = CMP_NE [%91, %92]  // wrapped != 4294967295u
 *     >> %94 = COND_BRANCH [%93]  // if (wrapped != 4294967295u) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %100 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %uc.5 = ALLOCA/LOCAL size=1 align=1
 *          %101 = CONST/INT32 200  // 200
 *          %102 = CAST/TRUNC_I32_I8 [%101]  // 200
 *     >> %uc.103 = MEMORY/STORE_LE_8 [%uc.5, %102]
 *          %zext.6 = ALLOCA/LOCAL size=4 align=4
 *          %104 = MEMORY/LOAD_LE_8 [%uc.5]  // uc
 *          %105 = CAST/ZEXT_I8_I32 [%104]  // uc
 *     >> %zext.106 = MEMORY/STORE_LE_32 [%zext.6, %105]
 *          %107 = MEMORY/LOAD_LE_32 [%zext.6]  // zext
 *          %108 = CONST/INT32 200  // 200
 *          %109 = CAST/IDENTITY [%108]  // 200
 *          %110 = CMP_NE [%107, %109]  // zext != 200
 *     >> %111 = COND_BRANCH [%110]  // if (zext != 200) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %117 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %sc.7 = ALLOCA/LOCAL size=1 align=1
 *          %118 = CONST/INT32 5  // 5
 *          %119 = NEG [%118]  // -5
 *          %120 = CAST/TRUNC_I32_I8 [%119]  // -5
 *     >> %sc.121 = MEMORY/STORE_LE_8 [%sc.7, %120]
 *          %sext.8 = ALLOCA/LOCAL size=4 align=4
 *          %122 = MEMORY/LOAD_LE_8 [%sc.7]  // sc
 *          %123 = CAST/SEXT_I8_I32 [%122]  // sc
 *     >> %sext.124 = MEMORY/STORE_LE_32 [%sext.8, %123]
 *          %125 = MEMORY/LOAD_LE_32 [%sext.8]  // sext
 *          %126 = CONST/INT32 5  // 5
 *          %127 = NEG [%126]  // -5
 *          %128 = CMP_NE [%125, %127]  // sext != -5
 *     >> %129 = COND_BRANCH [%128]  // if (sext != -5) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %135 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %udiv.9 = ALLOCA/LOCAL size=4 align=4
 *          %136 = CONST/UINT32 10  // 10u
 *          %137 = CONST/UINT32 3  // 3u
 *          %138 = UDIV [%136, %137]  // 10u / 3u
 *     >> %udiv.139 = MEMORY/STORE_LE_32 [%udiv.9, %138]
 *          %140 = MEMORY/LOAD_LE_32 [%udiv.9]  // udiv
 *          %141 = CONST/INT32 3  // 3
 *          %142 = CAST/IDENTITY [%141]  // 3
 *          %143 = CMP_NE [%140, %142]  // udiv != 3
 *     >> %144 = COND_BRANCH [%143]  // if (udiv != 3) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %150 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %umod.10 = ALLOCA/LOCAL size=4 align=4
 *          %151 = CONST/UINT32 10  // 10u
 *          %152 = CONST/UINT32 3  // 3u
 *          %153 = UREM [%151, %152]  // 10u % 3u
 *     >> %umod.154 = MEMORY/STORE_LE_32 [%umod.10, %153]
 *          %155 = MEMORY/LOAD_LE_32 [%umod.10]  // umod
 *          %156 = CONST/INT32 1  // 1
 *          %157 = CAST/IDENTITY [%156]  // 1
 *          %158 = CMP_NE [%155, %157]  // umod != 1
 *     >> %159 = COND_BRANCH [%158]  // if (umod != 1) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %165 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %large.11 = ALLOCA/LOCAL size=4 align=4
 *          %166 = CONST/UINT32 4294967295  // 0xFFFFFFFF
 *     >> %large.167 = MEMORY/STORE_LE_32 [%large.11, %166]
 *          %168 = MEMORY/LOAD_LE_32 [%large.11]  // large
 *          %169 = CONST/UINT32 4294967295  // 4294967295u
 *          %170 = CMP_NE [%168, %169]  // large != 4294967295u
 *     >> %171 = COND_BRANCH [%170]  // if (large != 4294967295u) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %177 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %half.12 = ALLOCA/LOCAL size=4 align=4
 *          %large.11 = ALLOCA/LOCAL size=4 align=4
 *          %178 = MEMORY/LOAD_LE_32 [%large.11]  // large
 *          %179 = CONST/INT32 2  // 2
 *          %180 = CAST/IDENTITY [%179]  // 2
 *          %181 = UDIV [%178, %180]  // large / 2
 *     >> %half.182 = MEMORY/STORE_LE_32 [%half.12, %181]
 *          %183 = MEMORY/LOAD_LE_32 [%half.12]  // half
 *          %184 = CONST/UINT32 2147483647  // 2147483647u
 *          %185 = CMP_NE [%183, %184]  // half != 2147483647u
 *     >> %186 = COND_BRANCH [%185]  // if (half != 2147483647u) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %192 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %shifted.13 = ALLOCA/LOCAL size=4 align=4
 *          %193 = CONST/UINT32 1  // 1u
 *          %194 = CONST/INT32 31  // 31
 *          %195 = SHL [%193, %194]  // 1u << 31
 *     >> %shifted.196 = MEMORY/STORE_LE_32 [%shifted.13, %195]
 *          %197 = MEMORY/LOAD_LE_32 [%shifted.13]  // shifted
 *          %198 = CONST/UINT32 2147483648  // 2147483648u
 *          %199 = CMP_NE [%197, %198]  // shifted != 2147483648u
 *     >> %200 = COND_BRANCH [%199]  // if (shifted != 2147483648u) return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %206 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *          %rshifted.14 = ALLOCA/LOCAL size=4 align=4
 *          %shifted.13 = ALLOCA/LOCAL size=4 align=4
 *          %207 = MEMORY/LOAD_LE_32 [%shifted.13]  // shifted
 *          %208 = CONST/INT32 1  // 1
 *          %209 = USHR [%207, %208]  // shifted >> 1
 *     >> %rshifted.210 = MEMORY/STORE_LE_32 [%rshifted.14, %209]
 *          %211 = MEMORY/LOAD_LE_32 [%rshifted.14]  // rshifted
 *          %212 = CONST/UINT32 1073741824  // 1073741824u
 *          %213 = CMP_NE [%211, %212]  // rshifted != 1073741824u
 *     >> %214 = COND_BRANCH [%213]  // if (rshifted != 1073741824u) return 14
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %220 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *          %uval.15 = ALLOCA/LOCAL size=4 align=4
 *          %221 = CONST/INT32 42  // 42
 *          %222 = CAST/IDENTITY [%221]  // 42
 *     >> %uval.223 = MEMORY/STORE_LE_32 [%uval.15, %222]
 *          %224 = MEMORY/LOAD_LE_32 [%uval.15]  // uval
 *          %225 = CONST/INT32 42  // 42
 *          %226 = CAST/IDENTITY [%225]  // 42
 *          %227 = CMP_NE [%224, %226]  // uval != 42
 *     >> %228 = COND_BRANCH [%227]  // if (uval != 42) return 15
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %234 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %high.16 = ALLOCA/LOCAL size=4 align=4
 *          %235 = CONST/UINT32 2147483649  // 0x80000001u
 *     >> %high.236 = MEMORY/STORE_LE_32 [%high.16, %235]
 *          %low.17 = ALLOCA/LOCAL size=4 align=4
 *          %237 = CONST/UINT32 1  // 1u
 *     >> %low.238 = MEMORY/STORE_LE_32 [%low.17, %237]
 *          %239 = MEMORY/LOAD_LE_32 [%high.16]  // high
 *          %240 = MEMORY/LOAD_LE_32 [%low.17]  // low
 *          %241 = UCMP_GT [%239, %240]  // high > low
 *          %242 = LOGICAL_NOT [%241]  // !(high > low)
 *     >> %243 = COND_BRANCH [%242]  // if (!(high > low)) return 16
 *     -> [block_47, block_48]
 *   block_48 IF_ELSE  <- [block_46]:
 *     >> %249 = IMPLICIT_GOTO
 *     -> [block_49]
 *   block_49 IF_MERGE  <- [block_48]:
 *          %high.16 = ALLOCA/LOCAL size=4 align=4
 *          %250 = MEMORY/LOAD_LE_32 [%high.16]  // high
 *          %low.17 = ALLOCA/LOCAL size=4 align=4
 *          %251 = MEMORY/LOAD_LE_32 [%low.17]  // low
 *          %252 = UCMP_LT [%250, %251]  // high < low
 *     >> %253 = COND_BRANCH [%252]  // if (high < low) return 17
 *     -> [block_50, block_51]
 *   block_51 IF_ELSE  <- [block_49]:
 *     >> %259 = IMPLICIT_GOTO
 *     -> [block_52]
 *   block_52 IF_MERGE  <- [block_51]:
 *          %high.16 = ALLOCA/LOCAL size=4 align=4
 *          %260 = MEMORY/LOAD_LE_32 [%high.16]  // high
 *          %low.17 = ALLOCA/LOCAL size=4 align=4
 *          %261 = MEMORY/LOAD_LE_32 [%low.17]  // low
 *          %262 = UCMP_LE [%260, %261]  // high <= low
 *     >> %263 = COND_BRANCH [%262]  // if (high <= low) return 18
 *     -> [block_53, block_54]
 *   block_54 IF_ELSE  <- [block_52]:
 *     >> %269 = IMPLICIT_GOTO
 *     -> [block_55]
 *   block_55 IF_MERGE  <- [block_54]:
 *          %high.16 = ALLOCA/LOCAL size=4 align=4
 *          %270 = MEMORY/LOAD_LE_32 [%high.16]  // high
 *          %low.17 = ALLOCA/LOCAL size=4 align=4
 *          %271 = MEMORY/LOAD_LE_32 [%low.17]  // low
 *          %272 = UCMP_GE [%270, %271]  // high >= low
 *          %273 = LOGICAL_NOT [%272]  // !(high >= low)
 *     >> %274 = COND_BRANCH [%273]  // if (!(high >= low)) return 19
 *     -> [block_56, block_57]
 *   block_57 IF_ELSE  <- [block_55]:
 *     >> %280 = IMPLICIT_GOTO
 *     -> [block_58]
 *   block_58 IF_MERGE  <- [block_57]:
 *          %282 = RETURN_PTR  // return 0
 *          %281 = CONST/INT32 0  // 0
 *     >> %283 = MEMORY/STORE_LE_32 [%282, %281]  // return 0
 *     >> %284 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %285 = RET [%281]  // return 0
 *   block_56 IF_THEN  <- [block_55]:
 *          %276 = RETURN_PTR  // return 19
 *          %275 = CONST/INT32 19  // 19
 *     >> %277 = MEMORY/STORE_LE_32 [%276, %275]  // return 19
 *     >> %278 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %279 = RET [%275]  // return 19
 *   block_53 IF_THEN  <- [block_52]:
 *          %265 = RETURN_PTR  // return 18
 *          %264 = CONST/INT32 18  // 18
 *     >> %266 = MEMORY/STORE_LE_32 [%265, %264]  // return 18
 *     >> %267 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %268 = RET [%264]  // return 18
 *   block_50 IF_THEN  <- [block_49]:
 *          %255 = RETURN_PTR  // return 17
 *          %254 = CONST/INT32 17  // 17
 *     >> %256 = MEMORY/STORE_LE_32 [%255, %254]  // return 17
 *     >> %257 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %258 = RET [%254]  // return 17
 *   block_47 IF_THEN  <- [block_46]:
 *          %245 = RETURN_PTR  // return 16
 *          %244 = CONST/INT32 16  // 16
 *     >> %246 = MEMORY/STORE_LE_32 [%245, %244]  // return 16
 *     >> %247 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %248 = RET [%244]  // return 16
 *   block_44 IF_THEN  <- [block_43]:
 *          %230 = RETURN_PTR  // return 15
 *          %229 = CONST/INT32 15  // 15
 *     >> %231 = MEMORY/STORE_LE_32 [%230, %229]  // return 15
 *     >> %232 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %233 = RET [%229]  // return 15
 *   block_41 IF_THEN  <- [block_40]:
 *          %216 = RETURN_PTR  // return 14
 *          %215 = CONST/INT32 14  // 14
 *     >> %217 = MEMORY/STORE_LE_32 [%216, %215]  // return 14
 *     >> %218 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %219 = RET [%215]  // return 14
 *   block_38 IF_THEN  <- [block_37]:
 *          %202 = RETURN_PTR  // return 13
 *          %201 = CONST/INT32 13  // 13
 *     >> %203 = MEMORY/STORE_LE_32 [%202, %201]  // return 13
 *     >> %204 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %205 = RET [%201]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %188 = RETURN_PTR  // return 12
 *          %187 = CONST/INT32 12  // 12
 *     >> %189 = MEMORY/STORE_LE_32 [%188, %187]  // return 12
 *     >> %190 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %191 = RET [%187]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %173 = RETURN_PTR  // return 11
 *          %172 = CONST/INT32 11  // 11
 *     >> %174 = MEMORY/STORE_LE_32 [%173, %172]  // return 11
 *     >> %175 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %176 = RET [%172]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %161 = RETURN_PTR  // return 10
 *          %160 = CONST/INT32 10  // 10
 *     >> %162 = MEMORY/STORE_LE_32 [%161, %160]  // return 10
 *     >> %163 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %164 = RET [%160]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %146 = RETURN_PTR  // return 9
 *          %145 = CONST/INT32 9  // 9
 *     >> %147 = MEMORY/STORE_LE_32 [%146, %145]  // return 9
 *     >> %148 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %149 = RET [%145]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %131 = RETURN_PTR  // return 8
 *          %130 = CONST/INT32 8  // 8
 *     >> %132 = MEMORY/STORE_LE_32 [%131, %130]  // return 8
 *     >> %133 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %134 = RET [%130]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %113 = RETURN_PTR  // return 7
 *          %112 = CONST/INT32 7  // 7
 *     >> %114 = MEMORY/STORE_LE_32 [%113, %112]  // return 7
 *     >> %115 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %116 = RET [%112]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %96 = RETURN_PTR  // return 6
 *          %95 = CONST/INT32 6  // 6
 *     >> %97 = MEMORY/STORE_LE_32 [%96, %95]  // return 6
 *     >> %98 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %99 = RET [%95]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %82 = RETURN_PTR  // return 5
 *          %81 = CONST/INT32 5  // 5
 *     >> %83 = MEMORY/STORE_LE_32 [%82, %81]  // return 5
 *     >> %84 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %85 = RET [%81]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %72 = RETURN_PTR  // return 4
 *          %71 = CONST/INT32 4  // 4
 *     >> %73 = MEMORY/STORE_LE_32 [%72, %71]  // return 4
 *     >> %74 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %75 = RET [%71]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %62 = RETURN_PTR  // return 3
 *          %61 = CONST/INT32 3  // 3
 *     >> %63 = MEMORY/STORE_LE_32 [%62, %61]  // return 3
 *     >> %64 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %65 = RET [%61]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %51 = RETURN_PTR  // return 2
 *          %50 = CONST/INT32 2  // 2
 *     >> %52 = MEMORY/STORE_LE_32 [%51, %50]  // return 2
 *     >> %53 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %54 = RET [%50]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %36 = RETURN_PTR  // return 1
 *          %35 = CONST/INT32 1  // 1
 *     >> %37 = MEMORY/STORE_LE_32 [%36, %35]  // return 1
 *     >> %38 = EXIT_SCOPE  // {     // Basic unsigned values.     unsigned in...
 *     >> %39 = RET [%35]  // return 1
 * }
 */










int test_unsigned(void) {
    // Basic unsigned values.
    unsigned int ua = 200;
    unsigned int ub = 100;

    // Unsigned arithmetic.
    unsigned int sum = ua + ub;
    if (sum != 300) return 1;

    unsigned int diff = ua - ub;
    if (diff != 100) return 2;

    // Unsigned comparison.
    if (!(ua > ub)) return 3;
    if (ua < ub) return 4;
    if (ua == ub) return 5;

    // Unsigned wrap-around (underflow).
    unsigned int wrapped = 0u - 1u;
    if (wrapped != 4294967295u) return 6;

    // Unsigned char to unsigned int (zero extension).
    unsigned char uc = 200;
    unsigned int zext = uc;
    if (zext != 200) return 7;

    // Signed char to int (sign extension).
    signed char sc = -5;
    int sext = sc;
    if (sext != -5) return 8;

    // Unsigned division.
    unsigned int udiv = 10u / 3u;
    if (udiv != 3) return 9;

    // Unsigned modulo.
    unsigned int umod = 10u % 3u;
    if (umod != 1) return 10;

    // Large unsigned values.
    unsigned int large = 0xFFFFFFFF;
    if (large != 4294967295u) return 11;

    unsigned int half = large / 2;
    if (half != 2147483647u) return 12;

    // Unsigned shift.
    unsigned int shifted = 1u << 31;
    if (shifted != 2147483648u) return 13;

    unsigned int rshifted = shifted >> 1;
    if (rshifted != 1073741824u) return 14;

    // Mixing: unsigned compared to signed constant.
    unsigned int uval = 42;
    if (uval != 42) return 15;

    // Unsigned comparison with high-bit values (would fail with signed CMP).
    unsigned int high = 0x80000001u;
    unsigned int low = 1u;
    if (!(high > low)) return 16;   // 2147483649 > 1, true unsigned
    if (high < low) return 17;      // false unsigned
    if (high <= low) return 18;     // false unsigned
    if (!(high >= low)) return 19;  // true unsigned

    return 0;
}
