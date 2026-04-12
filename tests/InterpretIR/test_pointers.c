// Tests: pointer arithmetic (PTR_ADD, PTR_DIFF), pointer increment/decrement
// (RMW with PTR_ADD), pointer compound assignment (ptr += n, ptr -= n),
// array subscript, dereferencing, address-of (ALLOCA as pointer),
// GEP_FIELD for struct member access.

/*
 * Expected IR:
 *
 * function test_pointers (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=20 align=4 (arr)
 *     obj_1 LOCAL_VALUE size=8 align=8 (p)
 *     obj_2 LOCAL_VALUE size=8 align=8 (q)
 *     obj_3 LOCAL_VALUE size=8 align=8 (diff)
 *     obj_4 LOCAL_VALUE size=8 align=8 (r)
 *     obj_5 LOCAL_VALUE size=8 align=8 (s)
 *     obj_6 LOCAL size=8 align=4 (pt)
 *     obj_7 LOCAL_VALUE size=8 align=8 (pp)
 *     obj_8 LOCAL_VALUE size=8 align=8 (lo)
 *     obj_9 LOCAL_VALUE size=8 align=8 (hi)
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %arr.0 = ALLOCA/LOCAL size=20 align=4
 *     >> %p.1 = ALLOCA/LOCAL size=8 align=8
 *     >> %q.2 = ALLOCA/LOCAL size=8 align=8
 *     >> %diff.3 = ALLOCA/LOCAL size=8 align=8
 *     >> %r.4 = ALLOCA/LOCAL size=8 align=8
 *     >> %s.5 = ALLOCA/LOCAL size=8 align=8
 *     >> %pt.6 = ALLOCA/LOCAL size=8 align=4
 *     >> %pp.7 = ALLOCA/LOCAL size=8 align=8
 *     >> %lo.8 = ALLOCA/LOCAL size=8 align=8
 *     >> %hi.9 = ALLOCA/LOCAL size=8 align=8
 *     >> %10 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %11 = ENTER_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *          %arr.0 = ALLOCA/LOCAL size=20 align=4
 *          %arr.12 = CONST/UINT8 0
 *          %arr.13 = CONST/UINT64 20
 *     >> %arr.14 = MEMORY/MEMSET [%arr.0, %arr.12, %arr.13]
 *          %15 = CONST/INT32 10  // 10
 *     >> %arr.16 = MEMORY/STORE_LE_32 [%arr.0, %15]
 *          %arr.17 = CONST/INT64 1
 *          %arr.18 = PTR_ADD elem_size=4 [%arr.0, %arr.17]
 *          %19 = CONST/INT32 20  // 20
 *     >> %arr.20 = MEMORY/STORE_LE_32 [%arr.18, %19]
 *          %arr.21 = CONST/INT64 2
 *          %arr.22 = PTR_ADD elem_size=4 [%arr.0, %arr.21]
 *          %23 = CONST/INT32 30  // 30
 *     >> %arr.24 = MEMORY/STORE_LE_32 [%arr.22, %23]
 *          %arr.25 = CONST/INT64 3
 *          %arr.26 = PTR_ADD elem_size=4 [%arr.0, %arr.25]
 *          %27 = CONST/INT32 40  // 40
 *     >> %arr.28 = MEMORY/STORE_LE_32 [%arr.26, %27]
 *          %arr.29 = CONST/INT64 4
 *          %arr.30 = PTR_ADD elem_size=4 [%arr.0, %arr.29]
 *          %31 = CONST/INT32 50  // 50
 *     >> %arr.32 = MEMORY/STORE_LE_32 [%arr.30, %31]
 *          %33 = CONST/INT32 0  // 0
 *          %34 = PTR_ADD elem_size=4 [%arr.0, %33]  // arr[0]
 *          %35 = MEMORY/LOAD_LE_32 [%34]  // arr[0]
 *          %36 = CONST/INT32 10  // 10
 *          %37 = CMP_NE [%35, %36]  // arr[0] != 10
 *     >> %38 = COND_BRANCH [%37]  // if (arr[0] != 10) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %44 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %arr.0 = ALLOCA/LOCAL size=20 align=4
 *          %45 = CONST/INT32 4  // 4
 *          %46 = PTR_ADD elem_size=4 [%arr.0, %45]  // arr[4]
 *          %47 = MEMORY/LOAD_LE_32 [%46]  // arr[4]
 *          %48 = CONST/INT32 50  // 50
 *          %49 = CMP_NE [%47, %48]  // arr[4] != 50
 *     >> %50 = COND_BRANCH [%49]  // if (arr[4] != 50) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %56 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %p.1 = ALLOCA/LOCAL size=8 align=8
 *          %arr.0 = ALLOCA/LOCAL size=20 align=4
 *     >> %p.57 = MEMORY/STORE_LE_64 [%p.1, %arr.0]
 *          %58 = MEMORY/LOAD_LE_64 [%p.1]  // p
 *          %59 = CONST/INT32 2  // 2
 *          %60 = PTR_ADD elem_size=4 [%58, %59]  // p + 2
 *     >> %61 = MEMORY/STORE_LE_64 [%p.1, %60]  // p = p + 2
 *          %62 = MEMORY/LOAD_LE_64 [%p.1]  // p
 *          %63 = MEMORY/LOAD_LE_32 [%62]  // *p
 *          %64 = CONST/INT32 30  // 30
 *          %65 = CMP_NE [%63, %64]  // *p != 30
 *     >> %66 = COND_BRANCH [%65]  // if (*p != 30) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %72 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %q.2 = ALLOCA/LOCAL size=8 align=8
 *          %arr.0 = ALLOCA/LOCAL size=20 align=4
 *          %73 = CONST/INT32 4  // 4
 *          %74 = PTR_ADD elem_size=4 [%arr.0, %73]  // arr[4]
 *     >> %q.75 = MEMORY/STORE_LE_64 [%q.2, %74]
 *          %diff.3 = ALLOCA/LOCAL size=8 align=8
 *          %76 = MEMORY/LOAD_LE_64 [%q.2]  // q
 *          %p.1 = ALLOCA/LOCAL size=8 align=8
 *          %77 = MEMORY/LOAD_LE_64 [%p.1]  // p
 *          %78 = PTR_DIFF [%76, %77]  // q - p
 *     >> %diff.79 = MEMORY/STORE_LE_64 [%diff.3, %78]
 *          %80 = MEMORY/LOAD_LE_64 [%diff.3]  // diff
 *          %81 = CONST/INT32 2  // 2
 *          %82 = CAST/SEXT_I32_I64 [%81]  // 2
 *          %83 = CMP_NE [%80, %82]  // diff != 2
 *     >> %84 = COND_BRANCH [%83]  // if (diff != 2) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %90 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %r.4 = ALLOCA/LOCAL size=8 align=8
 *          %arr.0 = ALLOCA/LOCAL size=20 align=4
 *     >> %r.91 = MEMORY/STORE_LE_64 [%r.4, %arr.0]
 *          %92 = CONST/INT64 1  // r++
 *     >> %93 = READ_MODIFY_WRITE(PTR_ADD old) [%r.4, %92]  // r++
 *          %94 = MEMORY/LOAD_LE_64 [%r.4]  // r
 *          %95 = MEMORY/LOAD_LE_32 [%94]  // *r
 *          %96 = CONST/INT32 20  // 20
 *          %97 = CMP_NE [%95, %96]  // *r != 20
 *     >> %98 = COND_BRANCH [%97]  // if (*r != 20) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %104 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %r.4 = ALLOCA/LOCAL size=8 align=8
 *          %arr.0 = ALLOCA/LOCAL size=20 align=4
 *          %105 = CONST/INT32 3  // 3
 *          %106 = PTR_ADD elem_size=4 [%arr.0, %105]  // arr[3]
 *     >> %107 = MEMORY/STORE_LE_64 [%r.4, %106]  // r = &arr[3]
 *          %108 = CONST/INT64 -1  // r--
 *     >> %109 = READ_MODIFY_WRITE(PTR_ADD old) [%r.4, %108]  // r--
 *          %110 = MEMORY/LOAD_LE_64 [%r.4]  // r
 *          %111 = MEMORY/LOAD_LE_32 [%110]  // *r
 *          %112 = CONST/INT32 30  // 30
 *          %113 = CMP_NE [%111, %112]  // *r != 30
 *     >> %114 = COND_BRANCH [%113]  // if (*r != 30) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %120 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %s.5 = ALLOCA/LOCAL size=8 align=8
 *          %arr.0 = ALLOCA/LOCAL size=20 align=4
 *     >> %s.121 = MEMORY/STORE_LE_64 [%s.5, %arr.0]
 *          %122 = CONST/INT32 3  // 3
 *     >> %123 = READ_MODIFY_WRITE(PTR_ADD new) [%s.5, %122]  // s += 3
 *          %124 = MEMORY/LOAD_LE_64 [%s.5]  // s
 *          %125 = MEMORY/LOAD_LE_32 [%124]  // *s
 *          %126 = CONST/INT32 40  // 40
 *          %127 = CMP_NE [%125, %126]  // *s != 40
 *     >> %128 = COND_BRANCH [%127]  // if (*s != 40) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %134 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %s.5 = ALLOCA/LOCAL size=8 align=8
 *          %135 = CONST/INT32 2  // 2
 *          %136 = NEG [%135]  // s -= 2
 *     >> %137 = READ_MODIFY_WRITE(PTR_ADD new) [%s.5, %136]  // s -= 2
 *          %138 = MEMORY/LOAD_LE_64 [%s.5]  // s
 *          %139 = MEMORY/LOAD_LE_32 [%138]  // *s
 *          %140 = CONST/INT32 20  // 20
 *          %141 = CMP_NE [%139, %140]  // *s != 20
 *     >> %142 = COND_BRANCH [%141]  // if (*s != 20) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %148 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %pt.6 = ALLOCA/LOCAL size=8 align=4
 *          %149 = GEP_FIELD offset=0 .x [%pt.6]  // pt.x
 *          %150 = CONST/INT32 100  // 100
 *     >> %151 = MEMORY/STORE_LE_32 [%149, %150]  // pt.x = 100
 *          %152 = GEP_FIELD offset=4 .y [%pt.6]  // pt.y
 *          %153 = CONST/INT32 200  // 200
 *     >> %154 = MEMORY/STORE_LE_32 [%152, %153]  // pt.y = 200
 *          %155 = GEP_FIELD offset=0 .x [%pt.6]  // pt.x
 *          %156 = MEMORY/LOAD_LE_32 [%155]  // pt.x
 *          %157 = CONST/INT32 100  // 100
 *          %158 = CMP_NE [%156, %157]  // pt.x != 100
 *     >> %159 = COND_BRANCH [%158]  // if (pt.x != 100) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %165 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %pt.6 = ALLOCA/LOCAL size=8 align=4
 *          %166 = GEP_FIELD offset=4 .y [%pt.6]  // pt.y
 *          %167 = MEMORY/LOAD_LE_32 [%166]  // pt.y
 *          %168 = CONST/INT32 200  // 200
 *          %169 = CMP_NE [%167, %168]  // pt.y != 200
 *     >> %170 = COND_BRANCH [%169]  // if (pt.y != 200) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %176 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %pp.7 = ALLOCA/LOCAL size=8 align=8
 *          %pt.6 = ALLOCA/LOCAL size=8 align=4
 *     >> %pp.177 = MEMORY/STORE_LE_64 [%pp.7, %pt.6]
 *          %178 = MEMORY/LOAD_LE_64 [%pp.7]  // pp
 *          %179 = GEP_FIELD offset=0 .x [%178]  // pp->x
 *          %180 = CONST/INT32 300  // 300
 *     >> %181 = MEMORY/STORE_LE_32 [%179, %180]  // pp->x = 300
 *          %182 = GEP_FIELD offset=0 .x [%pt.6]  // pt.x
 *          %183 = MEMORY/LOAD_LE_32 [%182]  // pt.x
 *          %184 = CONST/INT32 300  // 300
 *          %185 = CMP_NE [%183, %184]  // pt.x != 300
 *     >> %186 = COND_BRANCH [%185]  // if (pt.x != 300) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %192 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %lo.8 = ALLOCA/LOCAL size=8 align=8
 *          %arr.0 = ALLOCA/LOCAL size=20 align=4
 *          %193 = CONST/INT32 0  // 0
 *          %194 = PTR_ADD elem_size=4 [%arr.0, %193]  // arr[0]
 *     >> %lo.195 = MEMORY/STORE_LE_64 [%lo.8, %194]
 *          %hi.9 = ALLOCA/LOCAL size=8 align=8
 *          %196 = CONST/INT32 4  // 4
 *          %197 = PTR_ADD elem_size=4 [%arr.0, %196]  // arr[4]
 *     >> %hi.198 = MEMORY/STORE_LE_64 [%hi.9, %197]
 *          %199 = MEMORY/LOAD_LE_64 [%hi.9]  // hi
 *          %200 = MEMORY/LOAD_LE_64 [%lo.8]  // lo
 *          %201 = UCMP_GT [%199, %200]  // hi > lo
 *          %202 = LOGICAL_NOT [%201]  // !(hi > lo)
 *     >> %203 = COND_BRANCH [%202]  // if (!(hi > lo)) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %209 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %hi.9 = ALLOCA/LOCAL size=8 align=8
 *          %210 = MEMORY/LOAD_LE_64 [%hi.9]  // hi
 *          %lo.8 = ALLOCA/LOCAL size=8 align=8
 *          %211 = MEMORY/LOAD_LE_64 [%lo.8]  // lo
 *          %212 = UCMP_LT [%210, %211]  // hi < lo
 *     >> %213 = COND_BRANCH [%212]  // if (hi < lo) return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %219 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *          %hi.9 = ALLOCA/LOCAL size=8 align=8
 *          %220 = MEMORY/LOAD_LE_64 [%hi.9]  // hi
 *          %lo.8 = ALLOCA/LOCAL size=8 align=8
 *          %221 = MEMORY/LOAD_LE_64 [%lo.8]  // lo
 *          %222 = UCMP_LE [%220, %221]  // hi <= lo
 *     >> %223 = COND_BRANCH [%222]  // if (hi <= lo) return 14
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %229 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *          %hi.9 = ALLOCA/LOCAL size=8 align=8
 *          %230 = MEMORY/LOAD_LE_64 [%hi.9]  // hi
 *          %lo.8 = ALLOCA/LOCAL size=8 align=8
 *          %231 = MEMORY/LOAD_LE_64 [%lo.8]  // lo
 *          %232 = UCMP_GE [%230, %231]  // hi >= lo
 *          %233 = LOGICAL_NOT [%232]  // !(hi >= lo)
 *     >> %234 = COND_BRANCH [%233]  // if (!(hi >= lo)) return 15
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %240 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %lo.8 = ALLOCA/LOCAL size=8 align=8
 *          %241 = MEMORY/LOAD_LE_64 [%lo.8]  // lo
 *          %hi.9 = ALLOCA/LOCAL size=8 align=8
 *          %242 = MEMORY/LOAD_LE_64 [%hi.9]  // hi
 *          %243 = UCMP_GT [%241, %242]  // lo > hi
 *     >> %244 = COND_BRANCH [%243]  // if (lo > hi) return 16
 *     -> [block_47, block_48]
 *   block_48 IF_ELSE  <- [block_46]:
 *     >> %250 = IMPLICIT_GOTO
 *     -> [block_49]
 *   block_49 IF_MERGE  <- [block_48]:
 *          %lo.8 = ALLOCA/LOCAL size=8 align=8
 *          %251 = MEMORY/LOAD_LE_64 [%lo.8]  // lo
 *          %hi.9 = ALLOCA/LOCAL size=8 align=8
 *          %252 = MEMORY/LOAD_LE_64 [%hi.9]  // hi
 *          %253 = UCMP_LT [%251, %252]  // lo < hi
 *          %254 = LOGICAL_NOT [%253]  // !(lo < hi)
 *     >> %255 = COND_BRANCH [%254]  // if (!(lo < hi)) return 17
 *     -> [block_50, block_51]
 *   block_51 IF_ELSE  <- [block_49]:
 *     >> %261 = IMPLICIT_GOTO
 *     -> [block_52]
 *   block_52 IF_MERGE  <- [block_51]:
 *          %263 = RETURN_PTR  // return 0
 *          %262 = CONST/INT32 0  // 0
 *     >> %264 = MEMORY/STORE_LE_32 [%263, %262]  // return 0
 *     >> %265 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %266 = RET [%262]  // return 0
 *   block_50 IF_THEN  <- [block_49]:
 *          %257 = RETURN_PTR  // return 17
 *          %256 = CONST/INT32 17  // 17
 *     >> %258 = MEMORY/STORE_LE_32 [%257, %256]  // return 17
 *     >> %259 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %260 = RET [%256]  // return 17
 *   block_47 IF_THEN  <- [block_46]:
 *          %246 = RETURN_PTR  // return 16
 *          %245 = CONST/INT32 16  // 16
 *     >> %247 = MEMORY/STORE_LE_32 [%246, %245]  // return 16
 *     >> %248 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %249 = RET [%245]  // return 16
 *   block_44 IF_THEN  <- [block_43]:
 *          %236 = RETURN_PTR  // return 15
 *          %235 = CONST/INT32 15  // 15
 *     >> %237 = MEMORY/STORE_LE_32 [%236, %235]  // return 15
 *     >> %238 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %239 = RET [%235]  // return 15
 *   block_41 IF_THEN  <- [block_40]:
 *          %225 = RETURN_PTR  // return 14
 *          %224 = CONST/INT32 14  // 14
 *     >> %226 = MEMORY/STORE_LE_32 [%225, %224]  // return 14
 *     >> %227 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %228 = RET [%224]  // return 14
 *   block_38 IF_THEN  <- [block_37]:
 *          %215 = RETURN_PTR  // return 13
 *          %214 = CONST/INT32 13  // 13
 *     >> %216 = MEMORY/STORE_LE_32 [%215, %214]  // return 13
 *     >> %217 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %218 = RET [%214]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %205 = RETURN_PTR  // return 12
 *          %204 = CONST/INT32 12  // 12
 *     >> %206 = MEMORY/STORE_LE_32 [%205, %204]  // return 12
 *     >> %207 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %208 = RET [%204]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %188 = RETURN_PTR  // return 11
 *          %187 = CONST/INT32 11  // 11
 *     >> %189 = MEMORY/STORE_LE_32 [%188, %187]  // return 11
 *     >> %190 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %191 = RET [%187]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %172 = RETURN_PTR  // return 10
 *          %171 = CONST/INT32 10  // 10
 *     >> %173 = MEMORY/STORE_LE_32 [%172, %171]  // return 10
 *     >> %174 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %175 = RET [%171]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %161 = RETURN_PTR  // return 9
 *          %160 = CONST/INT32 9  // 9
 *     >> %162 = MEMORY/STORE_LE_32 [%161, %160]  // return 9
 *     >> %163 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %164 = RET [%160]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %144 = RETURN_PTR  // return 8
 *          %143 = CONST/INT32 8  // 8
 *     >> %145 = MEMORY/STORE_LE_32 [%144, %143]  // return 8
 *     >> %146 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %147 = RET [%143]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %130 = RETURN_PTR  // return 7
 *          %129 = CONST/INT32 7  // 7
 *     >> %131 = MEMORY/STORE_LE_32 [%130, %129]  // return 7
 *     >> %132 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %133 = RET [%129]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %116 = RETURN_PTR  // return 6
 *          %115 = CONST/INT32 6  // 6
 *     >> %117 = MEMORY/STORE_LE_32 [%116, %115]  // return 6
 *     >> %118 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %119 = RET [%115]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %100 = RETURN_PTR  // return 5
 *          %99 = CONST/INT32 5  // 5
 *     >> %101 = MEMORY/STORE_LE_32 [%100, %99]  // return 5
 *     >> %102 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %103 = RET [%99]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %86 = RETURN_PTR  // return 4
 *          %85 = CONST/INT32 4  // 4
 *     >> %87 = MEMORY/STORE_LE_32 [%86, %85]  // return 4
 *     >> %88 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %89 = RET [%85]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %68 = RETURN_PTR  // return 3
 *          %67 = CONST/INT32 3  // 3
 *     >> %69 = MEMORY/STORE_LE_32 [%68, %67]  // return 3
 *     >> %70 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %71 = RET [%67]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %52 = RETURN_PTR  // return 2
 *          %51 = CONST/INT32 2  // 2
 *     >> %53 = MEMORY/STORE_LE_32 [%52, %51]  // return 2
 *     >> %54 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %55 = RET [%51]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %40 = RETURN_PTR  // return 1
 *          %39 = CONST/INT32 1  // 1
 *     >> %41 = MEMORY/STORE_LE_32 [%40, %39]  // return 1
 *     >> %42 = EXIT_SCOPE  // {     int arr[5] = {10, 20, 30, 40, 50};      /...
 *     >> %43 = RET [%39]  // return 1
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

    // Pointer ordered comparisons (must use unsigned semantics).
    int *lo = &arr[0];
    int *hi = &arr[4];
    if (!(hi > lo)) return 12;   // hi > lo
    if (hi < lo) return 13;      // !(hi < lo)
    if (hi <= lo) return 14;     // !(hi <= lo)
    if (!(hi >= lo)) return 15;  // hi >= lo
    if (lo > hi) return 16;      // !(lo > hi)
    if (!(lo < hi)) return 17;   // lo < hi

    return 0;
}
