// Tests: integer arithmetic (ADD, SUB, MUL, DIV, REM), unary (NEG),
// bitwise (AND, OR, XOR, SHL, SHR, NOT), logical (AND, OR, NOT),
// comparisons (EQ, NE, LT, LE, GT, GE), and the comma operator (LAST_VALUE).

/*
 * Expected IR:
 *
 * function test_arithmetic (NORMAL) {
 *   objects:
 *     obj_0 LOCAL_VALUE size=4 align=4 (a)
 *     obj_1 LOCAL_VALUE size=4 align=4 (b)
 *     obj_2 LOCAL_VALUE size=4 align=4 (add)
 *     obj_3 LOCAL_VALUE size=4 align=4 (sub)
 *     obj_4 LOCAL_VALUE size=4 align=4 (mul)
 *     obj_5 LOCAL_VALUE size=4 align=4 (div)
 *     obj_6 LOCAL_VALUE size=4 align=4 (rem)
 *     obj_7 LOCAL_VALUE size=4 align=4 (neg)
 *     obj_8 LOCAL_VALUE size=4 align=4 (band)
 *     obj_9 LOCAL_VALUE size=4 align=4 (bor)
 *     obj_10 LOCAL_VALUE size=4 align=4 (bxor)
 *     obj_11 LOCAL_VALUE size=4 align=4 (shl)
 *     obj_12 LOCAL_VALUE size=4 align=4 (shr)
 *     obj_13 LOCAL_VALUE size=4 align=4 (bnot)
 *     obj_14 LOCAL_VALUE size=4 align=4 (land)
 *     obj_15 LOCAL_VALUE size=4 align=4 (lor)
 *     obj_16 LOCAL_VALUE size=4 align=4 (lnot)
 *     obj_17 LOCAL_VALUE size=4 align=4 (eq)
 *     obj_18 LOCAL_VALUE size=4 align=4 (ne)
 *     obj_19 LOCAL_VALUE size=4 align=4 (lt)
 *     obj_20 LOCAL_VALUE size=4 align=4 (le)
 *     obj_21 LOCAL_VALUE size=4 align=4 (gt)
 *     obj_22 LOCAL_VALUE size=4 align=4 (ge)
 *     obj_23 LOCAL_VALUE size=4 align=4 (comma)
 *   body_scope: FUNCTION_SCOPE
 * 
 *   blocks:
 *   block_0 FRAME:
 *     >> %a.0 = ALLOCA/LOCAL size=4 align=4
 *     >> %b.1 = ALLOCA/LOCAL size=4 align=4
 *     >> %add.2 = ALLOCA/LOCAL size=4 align=4
 *     >> %sub.3 = ALLOCA/LOCAL size=4 align=4
 *     >> %mul.4 = ALLOCA/LOCAL size=4 align=4
 *     >> %div.5 = ALLOCA/LOCAL size=4 align=4
 *     >> %rem.6 = ALLOCA/LOCAL size=4 align=4
 *     >> %neg.7 = ALLOCA/LOCAL size=4 align=4
 *     >> %band.8 = ALLOCA/LOCAL size=4 align=4
 *     >> %bor.9 = ALLOCA/LOCAL size=4 align=4
 *     >> %bxor.10 = ALLOCA/LOCAL size=4 align=4
 *     >> %shl.11 = ALLOCA/LOCAL size=4 align=4
 *     >> %shr.12 = ALLOCA/LOCAL size=4 align=4
 *     >> %bnot.13 = ALLOCA/LOCAL size=4 align=4
 *     >> %land.14 = ALLOCA/LOCAL size=4 align=4
 *     >> %lor.15 = ALLOCA/LOCAL size=4 align=4
 *     >> %lnot.16 = ALLOCA/LOCAL size=4 align=4
 *     >> %eq.17 = ALLOCA/LOCAL size=4 align=4
 *     >> %ne.18 = ALLOCA/LOCAL size=4 align=4
 *     >> %lt.19 = ALLOCA/LOCAL size=4 align=4
 *     >> %le.20 = ALLOCA/LOCAL size=4 align=4
 *     >> %gt.21 = ALLOCA/LOCAL size=4 align=4
 *     >> %ge.22 = ALLOCA/LOCAL size=4 align=4
 *     >> %comma.23 = ALLOCA/LOCAL size=4 align=4
 *     >> %24 = IMPLICIT_GOTO
 *     -> [block_1]
 *   block_1 ENTRY  <- [block_0]:
 *     >> %25 = ENTER_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *          %a.0 = ALLOCA/LOCAL size=4 align=4
 *          %26 = CONST/INT32 10  // 10
 *     >> %a.27 = MEMORY/STORE_LE_32 [%a.0, %26]
 *          %b.1 = ALLOCA/LOCAL size=4 align=4
 *          %28 = CONST/INT32 3  // 3
 *     >> %b.29 = MEMORY/STORE_LE_32 [%b.1, %28]
 *          %add.2 = ALLOCA/LOCAL size=4 align=4
 *          %30 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %31 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %32 = ADD [%30, %31]  // a + b
 *     >> %add.33 = MEMORY/STORE_LE_32 [%add.2, %32]
 *          %sub.3 = ALLOCA/LOCAL size=4 align=4
 *          %34 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %35 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %36 = SUB [%34, %35]  // a - b
 *     >> %sub.37 = MEMORY/STORE_LE_32 [%sub.3, %36]
 *          %mul.4 = ALLOCA/LOCAL size=4 align=4
 *          %38 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %39 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %40 = MUL [%38, %39]  // a * b
 *     >> %mul.41 = MEMORY/STORE_LE_32 [%mul.4, %40]
 *          %div.5 = ALLOCA/LOCAL size=4 align=4
 *          %42 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %43 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %44 = DIV [%42, %43]  // a / b
 *     >> %div.45 = MEMORY/STORE_LE_32 [%div.5, %44]
 *          %rem.6 = ALLOCA/LOCAL size=4 align=4
 *          %46 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %47 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %48 = REM [%46, %47]  // a % b
 *     >> %rem.49 = MEMORY/STORE_LE_32 [%rem.6, %48]
 *          %neg.7 = ALLOCA/LOCAL size=4 align=4
 *          %50 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %51 = NEG [%50]  // -a
 *     >> %neg.52 = MEMORY/STORE_LE_32 [%neg.7, %51]
 *          %band.8 = ALLOCA/LOCAL size=4 align=4
 *          %53 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %54 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %55 = BIT_AND [%53, %54]  // a & b
 *     >> %band.56 = MEMORY/STORE_LE_32 [%band.8, %55]
 *          %bor.9 = ALLOCA/LOCAL size=4 align=4
 *          %57 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %58 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %59 = BIT_OR [%57, %58]  // a | b
 *     >> %bor.60 = MEMORY/STORE_LE_32 [%bor.9, %59]
 *          %bxor.10 = ALLOCA/LOCAL size=4 align=4
 *          %61 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %62 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %63 = BIT_XOR [%61, %62]  // a ^ b
 *     >> %bxor.64 = MEMORY/STORE_LE_32 [%bxor.10, %63]
 *          %shl.11 = ALLOCA/LOCAL size=4 align=4
 *          %65 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %66 = CONST/INT32 1  // 1
 *          %67 = SHL [%65, %66]  // a << 1
 *     >> %shl.68 = MEMORY/STORE_LE_32 [%shl.11, %67]
 *          %shr.12 = ALLOCA/LOCAL size=4 align=4
 *          %69 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %70 = CONST/INT32 1  // 1
 *          %71 = SHR [%69, %70]  // a >> 1
 *     >> %shr.72 = MEMORY/STORE_LE_32 [%shr.12, %71]
 *          %bnot.13 = ALLOCA/LOCAL size=4 align=4
 *          %73 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %74 = BIT_NOT [%73]  // ~a
 *     >> %bnot.75 = MEMORY/STORE_LE_32 [%bnot.13, %74]
 *          %land.14 = ALLOCA/LOCAL size=4 align=4
 *          %76 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %77 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %78 = LOGICAL_AND [%76, %77]  // a && b
 *     >> %land.79 = MEMORY/STORE_LE_32 [%land.14, %78]
 *          %lor.15 = ALLOCA/LOCAL size=4 align=4
 *          %80 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %81 = CONST/INT32 0  // 0
 *          %82 = LOGICAL_OR [%80, %81]  // a || 0
 *     >> %lor.83 = MEMORY/STORE_LE_32 [%lor.15, %82]
 *          %lnot.16 = ALLOCA/LOCAL size=4 align=4
 *          %84 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %85 = LOGICAL_NOT [%84]  // !a
 *     >> %lnot.86 = MEMORY/STORE_LE_32 [%lnot.16, %85]
 *          %eq.17 = ALLOCA/LOCAL size=4 align=4
 *          %87 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %88 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %89 = CMP_EQ [%87, %88]  // a == b
 *     >> %eq.90 = MEMORY/STORE_LE_32 [%eq.17, %89]
 *          %ne.18 = ALLOCA/LOCAL size=4 align=4
 *          %91 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %92 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %93 = CMP_NE [%91, %92]  // a != b
 *     >> %ne.94 = MEMORY/STORE_LE_32 [%ne.18, %93]
 *          %lt.19 = ALLOCA/LOCAL size=4 align=4
 *          %95 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %96 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %97 = CMP_LT [%95, %96]  // a < b
 *     >> %lt.98 = MEMORY/STORE_LE_32 [%lt.19, %97]
 *          %le.20 = ALLOCA/LOCAL size=4 align=4
 *          %99 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %100 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %101 = CMP_LE [%99, %100]  // a <= b
 *     >> %le.102 = MEMORY/STORE_LE_32 [%le.20, %101]
 *          %gt.21 = ALLOCA/LOCAL size=4 align=4
 *          %103 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %104 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %105 = CMP_GT [%103, %104]  // a > b
 *     >> %gt.106 = MEMORY/STORE_LE_32 [%gt.21, %105]
 *          %ge.22 = ALLOCA/LOCAL size=4 align=4
 *          %107 = MEMORY/LOAD_LE_32 [%a.0]  // a
 *          %108 = MEMORY/LOAD_LE_32 [%b.1]  // b
 *          %109 = CMP_GE [%107, %108]  // a >= b
 *     >> %ge.110 = MEMORY/STORE_LE_32 [%ge.22, %109]
 *          %comma.23 = ALLOCA/LOCAL size=4 align=4
 *          %111 = CONST/INT32 1  // 1
 *          %112 = CONST/INT32 2  // 2
 *          %113 = LAST_VALUE [%111, %112]  // 1, 2
 *          %114 = CONST/INT32 3  // 3
 *          %115 = LAST_VALUE [%113, %114]  // 1, 2, 3
 *     >> %comma.116 = MEMORY/STORE_LE_32 [%comma.23, %115]
 *          %117 = MEMORY/LOAD_LE_32 [%add.2]  // add
 *          %118 = CONST/INT32 13  // 13
 *          %119 = CMP_NE [%117, %118]  // add != 13
 *     >> %120 = COND_BRANCH [%119]  // if (add != 13) return 1
 *     -> [block_2, block_3]
 *   block_3 IF_ELSE  <- [block_1]:
 *     >> %126 = IMPLICIT_GOTO
 *     -> [block_4]
 *   block_4 IF_MERGE  <- [block_3]:
 *          %sub.3 = ALLOCA/LOCAL size=4 align=4
 *          %127 = MEMORY/LOAD_LE_32 [%sub.3]  // sub
 *          %128 = CONST/INT32 7  // 7
 *          %129 = CMP_NE [%127, %128]  // sub != 7
 *     >> %130 = COND_BRANCH [%129]  // if (sub != 7) return 2
 *     -> [block_5, block_6]
 *   block_6 IF_ELSE  <- [block_4]:
 *     >> %136 = IMPLICIT_GOTO
 *     -> [block_7]
 *   block_7 IF_MERGE  <- [block_6]:
 *          %mul.4 = ALLOCA/LOCAL size=4 align=4
 *          %137 = MEMORY/LOAD_LE_32 [%mul.4]  // mul
 *          %138 = CONST/INT32 30  // 30
 *          %139 = CMP_NE [%137, %138]  // mul != 30
 *     >> %140 = COND_BRANCH [%139]  // if (mul != 30) return 3
 *     -> [block_8, block_9]
 *   block_9 IF_ELSE  <- [block_7]:
 *     >> %146 = IMPLICIT_GOTO
 *     -> [block_10]
 *   block_10 IF_MERGE  <- [block_9]:
 *          %div.5 = ALLOCA/LOCAL size=4 align=4
 *          %147 = MEMORY/LOAD_LE_32 [%div.5]  // div
 *          %148 = CONST/INT32 3  // 3
 *          %149 = CMP_NE [%147, %148]  // div != 3
 *     >> %150 = COND_BRANCH [%149]  // if (div != 3) return 4
 *     -> [block_11, block_12]
 *   block_12 IF_ELSE  <- [block_10]:
 *     >> %156 = IMPLICIT_GOTO
 *     -> [block_13]
 *   block_13 IF_MERGE  <- [block_12]:
 *          %rem.6 = ALLOCA/LOCAL size=4 align=4
 *          %157 = MEMORY/LOAD_LE_32 [%rem.6]  // rem
 *          %158 = CONST/INT32 1  // 1
 *          %159 = CMP_NE [%157, %158]  // rem != 1
 *     >> %160 = COND_BRANCH [%159]  // if (rem != 1) return 5
 *     -> [block_14, block_15]
 *   block_15 IF_ELSE  <- [block_13]:
 *     >> %166 = IMPLICIT_GOTO
 *     -> [block_16]
 *   block_16 IF_MERGE  <- [block_15]:
 *          %neg.7 = ALLOCA/LOCAL size=4 align=4
 *          %167 = MEMORY/LOAD_LE_32 [%neg.7]  // neg
 *          %168 = CONST/INT32 10  // 10
 *          %169 = NEG [%168]  // -10
 *          %170 = CMP_NE [%167, %169]  // neg != -10
 *     >> %171 = COND_BRANCH [%170]  // if (neg != -10) return 6
 *     -> [block_17, block_18]
 *   block_18 IF_ELSE  <- [block_16]:
 *     >> %177 = IMPLICIT_GOTO
 *     -> [block_19]
 *   block_19 IF_MERGE  <- [block_18]:
 *          %band.8 = ALLOCA/LOCAL size=4 align=4
 *          %178 = MEMORY/LOAD_LE_32 [%band.8]  // band
 *          %179 = CONST/INT32 2  // 2
 *          %180 = CMP_NE [%178, %179]  // band != 2
 *     >> %181 = COND_BRANCH [%180]  // if (band != 2) return 7
 *     -> [block_20, block_21]
 *   block_21 IF_ELSE  <- [block_19]:
 *     >> %187 = IMPLICIT_GOTO
 *     -> [block_22]
 *   block_22 IF_MERGE  <- [block_21]:
 *          %bor.9 = ALLOCA/LOCAL size=4 align=4
 *          %188 = MEMORY/LOAD_LE_32 [%bor.9]  // bor
 *          %189 = CONST/INT32 11  // 11
 *          %190 = CMP_NE [%188, %189]  // bor != 11
 *     >> %191 = COND_BRANCH [%190]  // if (bor != 11) return 8
 *     -> [block_23, block_24]
 *   block_24 IF_ELSE  <- [block_22]:
 *     >> %197 = IMPLICIT_GOTO
 *     -> [block_25]
 *   block_25 IF_MERGE  <- [block_24]:
 *          %bxor.10 = ALLOCA/LOCAL size=4 align=4
 *          %198 = MEMORY/LOAD_LE_32 [%bxor.10]  // bxor
 *          %199 = CONST/INT32 9  // 9
 *          %200 = CMP_NE [%198, %199]  // bxor != 9
 *     >> %201 = COND_BRANCH [%200]  // if (bxor != 9) return 9
 *     -> [block_26, block_27]
 *   block_27 IF_ELSE  <- [block_25]:
 *     >> %207 = IMPLICIT_GOTO
 *     -> [block_28]
 *   block_28 IF_MERGE  <- [block_27]:
 *          %shl.11 = ALLOCA/LOCAL size=4 align=4
 *          %208 = MEMORY/LOAD_LE_32 [%shl.11]  // shl
 *          %209 = CONST/INT32 20  // 20
 *          %210 = CMP_NE [%208, %209]  // shl != 20
 *     >> %211 = COND_BRANCH [%210]  // if (shl != 20) return 10
 *     -> [block_29, block_30]
 *   block_30 IF_ELSE  <- [block_28]:
 *     >> %217 = IMPLICIT_GOTO
 *     -> [block_31]
 *   block_31 IF_MERGE  <- [block_30]:
 *          %shr.12 = ALLOCA/LOCAL size=4 align=4
 *          %218 = MEMORY/LOAD_LE_32 [%shr.12]  // shr
 *          %219 = CONST/INT32 5  // 5
 *          %220 = CMP_NE [%218, %219]  // shr != 5
 *     >> %221 = COND_BRANCH [%220]  // if (shr != 5) return 11
 *     -> [block_32, block_33]
 *   block_33 IF_ELSE  <- [block_31]:
 *     >> %227 = IMPLICIT_GOTO
 *     -> [block_34]
 *   block_34 IF_MERGE  <- [block_33]:
 *          %bnot.13 = ALLOCA/LOCAL size=4 align=4
 *          %228 = MEMORY/LOAD_LE_32 [%bnot.13]  // bnot
 *          %229 = CONST/INT32 11  // 11
 *          %230 = NEG [%229]  // -11
 *          %231 = CMP_NE [%228, %230]  // bnot != -11
 *     >> %232 = COND_BRANCH [%231]  // if (bnot != -11) return 12
 *     -> [block_35, block_36]
 *   block_36 IF_ELSE  <- [block_34]:
 *     >> %238 = IMPLICIT_GOTO
 *     -> [block_37]
 *   block_37 IF_MERGE  <- [block_36]:
 *          %land.14 = ALLOCA/LOCAL size=4 align=4
 *          %239 = MEMORY/LOAD_LE_32 [%land.14]  // land
 *          %240 = CONST/INT32 1  // 1
 *          %241 = CMP_NE [%239, %240]  // land != 1
 *     >> %242 = COND_BRANCH [%241]  // if (land != 1) return 13
 *     -> [block_38, block_39]
 *   block_39 IF_ELSE  <- [block_37]:
 *     >> %248 = IMPLICIT_GOTO
 *     -> [block_40]
 *   block_40 IF_MERGE  <- [block_39]:
 *          %lor.15 = ALLOCA/LOCAL size=4 align=4
 *          %249 = MEMORY/LOAD_LE_32 [%lor.15]  // lor
 *          %250 = CONST/INT32 1  // 1
 *          %251 = CMP_NE [%249, %250]  // lor != 1
 *     >> %252 = COND_BRANCH [%251]  // if (lor != 1) return 14
 *     -> [block_41, block_42]
 *   block_42 IF_ELSE  <- [block_40]:
 *     >> %258 = IMPLICIT_GOTO
 *     -> [block_43]
 *   block_43 IF_MERGE  <- [block_42]:
 *          %lnot.16 = ALLOCA/LOCAL size=4 align=4
 *          %259 = MEMORY/LOAD_LE_32 [%lnot.16]  // lnot
 *          %260 = CONST/INT32 0  // 0
 *          %261 = CMP_NE [%259, %260]  // lnot != 0
 *     >> %262 = COND_BRANCH [%261]  // if (lnot != 0) return 15
 *     -> [block_44, block_45]
 *   block_45 IF_ELSE  <- [block_43]:
 *     >> %268 = IMPLICIT_GOTO
 *     -> [block_46]
 *   block_46 IF_MERGE  <- [block_45]:
 *          %eq.17 = ALLOCA/LOCAL size=4 align=4
 *          %269 = MEMORY/LOAD_LE_32 [%eq.17]  // eq
 *          %270 = CONST/INT32 0  // 0
 *          %271 = CMP_NE [%269, %270]  // eq != 0
 *     >> %272 = COND_BRANCH [%271]  // if (eq != 0) return 16
 *     -> [block_47, block_48]
 *   block_48 IF_ELSE  <- [block_46]:
 *     >> %278 = IMPLICIT_GOTO
 *     -> [block_49]
 *   block_49 IF_MERGE  <- [block_48]:
 *          %ne.18 = ALLOCA/LOCAL size=4 align=4
 *          %279 = MEMORY/LOAD_LE_32 [%ne.18]  // ne
 *          %280 = CONST/INT32 1  // 1
 *          %281 = CMP_NE [%279, %280]  // ne != 1
 *     >> %282 = COND_BRANCH [%281]  // if (ne != 1) return 17
 *     -> [block_50, block_51]
 *   block_51 IF_ELSE  <- [block_49]:
 *     >> %288 = IMPLICIT_GOTO
 *     -> [block_52]
 *   block_52 IF_MERGE  <- [block_51]:
 *          %lt.19 = ALLOCA/LOCAL size=4 align=4
 *          %289 = MEMORY/LOAD_LE_32 [%lt.19]  // lt
 *          %290 = CONST/INT32 0  // 0
 *          %291 = CMP_NE [%289, %290]  // lt != 0
 *     >> %292 = COND_BRANCH [%291]  // if (lt != 0) return 18
 *     -> [block_53, block_54]
 *   block_54 IF_ELSE  <- [block_52]:
 *     >> %298 = IMPLICIT_GOTO
 *     -> [block_55]
 *   block_55 IF_MERGE  <- [block_54]:
 *          %le.20 = ALLOCA/LOCAL size=4 align=4
 *          %299 = MEMORY/LOAD_LE_32 [%le.20]  // le
 *          %300 = CONST/INT32 0  // 0
 *          %301 = CMP_NE [%299, %300]  // le != 0
 *     >> %302 = COND_BRANCH [%301]  // if (le != 0) return 19
 *     -> [block_56, block_57]
 *   block_57 IF_ELSE  <- [block_55]:
 *     >> %308 = IMPLICIT_GOTO
 *     -> [block_58]
 *   block_58 IF_MERGE  <- [block_57]:
 *          %gt.21 = ALLOCA/LOCAL size=4 align=4
 *          %309 = MEMORY/LOAD_LE_32 [%gt.21]  // gt
 *          %310 = CONST/INT32 1  // 1
 *          %311 = CMP_NE [%309, %310]  // gt != 1
 *     >> %312 = COND_BRANCH [%311]  // if (gt != 1) return 20
 *     -> [block_59, block_60]
 *   block_60 IF_ELSE  <- [block_58]:
 *     >> %318 = IMPLICIT_GOTO
 *     -> [block_61]
 *   block_61 IF_MERGE  <- [block_60]:
 *          %ge.22 = ALLOCA/LOCAL size=4 align=4
 *          %319 = MEMORY/LOAD_LE_32 [%ge.22]  // ge
 *          %320 = CONST/INT32 1  // 1
 *          %321 = CMP_NE [%319, %320]  // ge != 1
 *     >> %322 = COND_BRANCH [%321]  // if (ge != 1) return 21
 *     -> [block_62, block_63]
 *   block_63 IF_ELSE  <- [block_61]:
 *     >> %328 = IMPLICIT_GOTO
 *     -> [block_64]
 *   block_64 IF_MERGE  <- [block_63]:
 *          %comma.23 = ALLOCA/LOCAL size=4 align=4
 *          %329 = MEMORY/LOAD_LE_32 [%comma.23]  // comma
 *          %330 = CONST/INT32 3  // 3
 *          %331 = CMP_NE [%329, %330]  // comma != 3
 *     >> %332 = COND_BRANCH [%331]  // if (comma != 3) return 22
 *     -> [block_65, block_66]
 *   block_66 IF_ELSE  <- [block_64]:
 *     >> %338 = IMPLICIT_GOTO
 *     -> [block_67]
 *   block_67 IF_MERGE  <- [block_66]:
 *          %340 = RETURN_PTR  // return 0
 *          %339 = CONST/INT32 0  // 0
 *     >> %341 = MEMORY/STORE_LE_32 [%340, %339]  // return 0
 *     >> %342 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %343 = RET [%339]  // return 0
 *   block_65 IF_THEN  <- [block_64]:
 *          %334 = RETURN_PTR  // return 22
 *          %333 = CONST/INT32 22  // 22
 *     >> %335 = MEMORY/STORE_LE_32 [%334, %333]  // return 22
 *     >> %336 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %337 = RET [%333]  // return 22
 *   block_62 IF_THEN  <- [block_61]:
 *          %324 = RETURN_PTR  // return 21
 *          %323 = CONST/INT32 21  // 21
 *     >> %325 = MEMORY/STORE_LE_32 [%324, %323]  // return 21
 *     >> %326 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %327 = RET [%323]  // return 21
 *   block_59 IF_THEN  <- [block_58]:
 *          %314 = RETURN_PTR  // return 20
 *          %313 = CONST/INT32 20  // 20
 *     >> %315 = MEMORY/STORE_LE_32 [%314, %313]  // return 20
 *     >> %316 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %317 = RET [%313]  // return 20
 *   block_56 IF_THEN  <- [block_55]:
 *          %304 = RETURN_PTR  // return 19
 *          %303 = CONST/INT32 19  // 19
 *     >> %305 = MEMORY/STORE_LE_32 [%304, %303]  // return 19
 *     >> %306 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %307 = RET [%303]  // return 19
 *   block_53 IF_THEN  <- [block_52]:
 *          %294 = RETURN_PTR  // return 18
 *          %293 = CONST/INT32 18  // 18
 *     >> %295 = MEMORY/STORE_LE_32 [%294, %293]  // return 18
 *     >> %296 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %297 = RET [%293]  // return 18
 *   block_50 IF_THEN  <- [block_49]:
 *          %284 = RETURN_PTR  // return 17
 *          %283 = CONST/INT32 17  // 17
 *     >> %285 = MEMORY/STORE_LE_32 [%284, %283]  // return 17
 *     >> %286 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %287 = RET [%283]  // return 17
 *   block_47 IF_THEN  <- [block_46]:
 *          %274 = RETURN_PTR  // return 16
 *          %273 = CONST/INT32 16  // 16
 *     >> %275 = MEMORY/STORE_LE_32 [%274, %273]  // return 16
 *     >> %276 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %277 = RET [%273]  // return 16
 *   block_44 IF_THEN  <- [block_43]:
 *          %264 = RETURN_PTR  // return 15
 *          %263 = CONST/INT32 15  // 15
 *     >> %265 = MEMORY/STORE_LE_32 [%264, %263]  // return 15
 *     >> %266 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %267 = RET [%263]  // return 15
 *   block_41 IF_THEN  <- [block_40]:
 *          %254 = RETURN_PTR  // return 14
 *          %253 = CONST/INT32 14  // 14
 *     >> %255 = MEMORY/STORE_LE_32 [%254, %253]  // return 14
 *     >> %256 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %257 = RET [%253]  // return 14
 *   block_38 IF_THEN  <- [block_37]:
 *          %244 = RETURN_PTR  // return 13
 *          %243 = CONST/INT32 13  // 13
 *     >> %245 = MEMORY/STORE_LE_32 [%244, %243]  // return 13
 *     >> %246 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %247 = RET [%243]  // return 13
 *   block_35 IF_THEN  <- [block_34]:
 *          %234 = RETURN_PTR  // return 12
 *          %233 = CONST/INT32 12  // 12
 *     >> %235 = MEMORY/STORE_LE_32 [%234, %233]  // return 12
 *     >> %236 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %237 = RET [%233]  // return 12
 *   block_32 IF_THEN  <- [block_31]:
 *          %223 = RETURN_PTR  // return 11
 *          %222 = CONST/INT32 11  // 11
 *     >> %224 = MEMORY/STORE_LE_32 [%223, %222]  // return 11
 *     >> %225 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %226 = RET [%222]  // return 11
 *   block_29 IF_THEN  <- [block_28]:
 *          %213 = RETURN_PTR  // return 10
 *          %212 = CONST/INT32 10  // 10
 *     >> %214 = MEMORY/STORE_LE_32 [%213, %212]  // return 10
 *     >> %215 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %216 = RET [%212]  // return 10
 *   block_26 IF_THEN  <- [block_25]:
 *          %203 = RETURN_PTR  // return 9
 *          %202 = CONST/INT32 9  // 9
 *     >> %204 = MEMORY/STORE_LE_32 [%203, %202]  // return 9
 *     >> %205 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %206 = RET [%202]  // return 9
 *   block_23 IF_THEN  <- [block_22]:
 *          %193 = RETURN_PTR  // return 8
 *          %192 = CONST/INT32 8  // 8
 *     >> %194 = MEMORY/STORE_LE_32 [%193, %192]  // return 8
 *     >> %195 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %196 = RET [%192]  // return 8
 *   block_20 IF_THEN  <- [block_19]:
 *          %183 = RETURN_PTR  // return 7
 *          %182 = CONST/INT32 7  // 7
 *     >> %184 = MEMORY/STORE_LE_32 [%183, %182]  // return 7
 *     >> %185 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %186 = RET [%182]  // return 7
 *   block_17 IF_THEN  <- [block_16]:
 *          %173 = RETURN_PTR  // return 6
 *          %172 = CONST/INT32 6  // 6
 *     >> %174 = MEMORY/STORE_LE_32 [%173, %172]  // return 6
 *     >> %175 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %176 = RET [%172]  // return 6
 *   block_14 IF_THEN  <- [block_13]:
 *          %162 = RETURN_PTR  // return 5
 *          %161 = CONST/INT32 5  // 5
 *     >> %163 = MEMORY/STORE_LE_32 [%162, %161]  // return 5
 *     >> %164 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %165 = RET [%161]  // return 5
 *   block_11 IF_THEN  <- [block_10]:
 *          %152 = RETURN_PTR  // return 4
 *          %151 = CONST/INT32 4  // 4
 *     >> %153 = MEMORY/STORE_LE_32 [%152, %151]  // return 4
 *     >> %154 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %155 = RET [%151]  // return 4
 *   block_8 IF_THEN  <- [block_7]:
 *          %142 = RETURN_PTR  // return 3
 *          %141 = CONST/INT32 3  // 3
 *     >> %143 = MEMORY/STORE_LE_32 [%142, %141]  // return 3
 *     >> %144 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %145 = RET [%141]  // return 3
 *   block_5 IF_THEN  <- [block_4]:
 *          %132 = RETURN_PTR  // return 2
 *          %131 = CONST/INT32 2  // 2
 *     >> %133 = MEMORY/STORE_LE_32 [%132, %131]  // return 2
 *     >> %134 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %135 = RET [%131]  // return 2
 *   block_2 IF_THEN  <- [block_1]:
 *          %122 = RETURN_PTR  // return 1
 *          %121 = CONST/INT32 1  // 1
 *     >> %123 = MEMORY/STORE_LE_32 [%122, %121]  // return 1
 *     >> %124 = EXIT_SCOPE  // {     int a = 10, b = 3;      // Basic arithmet...
 *     >> %125 = RET [%121]  // return 1
 * }
 */










int test_arithmetic(void) {
    int a = 10, b = 3;

    // Basic arithmetic.
    int add = a + b;       // 13
    int sub = a - b;       // 7
    int mul = a * b;       // 30
    int div = a / b;       // 3
    int rem = a % b;       // 1

    // Unary.
    int neg = -a;          // -10

    // Bitwise.
    int band = a & b;      // 2
    int bor  = a | b;      // 11
    int bxor = a ^ b;      // 9
    int shl  = a << 1;     // 20
    int shr  = a >> 1;     // 5
    int bnot = ~a;         // -11

    // Logical.
    int land = a && b;     // 1
    int lor  = a || 0;     // 1
    int lnot = !a;         // 0

    // Comparisons.
    int eq = (a == b);     // 0
    int ne = (a != b);     // 1
    int lt = (a < b);      // 0
    int le = (a <= b);     // 0
    int gt = (a > b);      // 1
    int ge = (a >= b);     // 1

    // Comma operator (LAST_VALUE).
    int comma = (1, 2, 3); // 3

    // Verify all results.
    if (add != 13) return 1;
    if (sub != 7) return 2;
    if (mul != 30) return 3;
    if (div != 3) return 4;
    if (rem != 1) return 5;
    if (neg != -10) return 6;
    if (band != 2) return 7;
    if (bor != 11) return 8;
    if (bxor != 9) return 9;
    if (shl != 20) return 10;
    if (shr != 5) return 11;
    if (bnot != -11) return 12;
    if (land != 1) return 13;
    if (lor != 1) return 14;
    if (lnot != 0) return 15;
    if (eq != 0) return 16;
    if (ne != 1) return 17;
    if (lt != 0) return 18;
    if (le != 0) return 19;
    if (gt != 1) return 20;
    if (ge != 1) return 21;
    if (comma != 3) return 22;

    return 0;
}
