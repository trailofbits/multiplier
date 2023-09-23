# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

# Auto-generated file; do not modify!

@0xa04be7b45e95b659;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::ast");

struct Decl @0xfb5879761ffaedb6{
  val4 @0 :UInt8;
  val5 @1 :UInt8;
  val10 @2 :UInt8;
  val13 @3 :UInt8;
  val47 @4 :UInt8;
  val48 @5 :UInt8;
  val68 @6 :UInt8;
  val72 @7 :UInt8;
  val73 @8 :UInt8;
  val83 @9 :UInt8;
  val88 @10 :UInt8;
  val90 @11 :UInt8;
  val91 @12 :UInt8;
  val92 @13 :UInt8;
  val93 @14 :UInt8;
  val95 @15 :UInt8;
  val96 @16 :UInt8;
  val134 @17 :UInt8;
  val171 @18 :UInt8;
  val3 @19 :List(UInt64);
  val54 @20 :List(UInt64);
  val55 @21 :List(UInt64);
  val65 @22 :List(UInt64);
  val182 @23 :List(UInt64);
  val190 @24 :List(UInt64);
  val191 @25 :List(UInt64);
  val192 @26 :List(UInt64);
  val318 @27 :List(UInt64);
  val344 @28 :List(UInt64);
  val355 @29 :List(UInt64);
  val356 @30 :List(UInt64);
  val364 @31 :List(UInt64);
  val365 @32 :List(UInt64);
  val366 @33 :List(UInt64);
  val367 @34 :List(UInt64);
  val66 @35 :Text;
  val67 @36 :Text;
  val76 @37 :Text;
  val0 @38 :UInt64;
  val1 @39 :UInt64;
  val6 @40 :UInt64;
  val7 @41 :UInt64;
  val8 @42 :UInt64;
  val9 @43 :UInt64;
  val14 @44 :UInt64;
  val49 @45 :UInt64;
  val50 @46 :UInt64;
  val51 @47 :UInt64;
  val52 @48 :UInt64;
  val59 @49 :UInt64;
  val60 @50 :UInt64;
  val61 @51 :UInt64;
  val69 @52 :UInt64;
  val70 @53 :UInt64;
  val71 @54 :UInt64;
  val81 @55 :UInt64;
  val82 @56 :UInt64;
  val84 @57 :UInt64;
  val85 @58 :UInt64;
  val86 @59 :UInt64;
  val87 @60 :UInt64;
  val89 @61 :UInt64;
  val94 @62 :UInt64;
  val131 @63 :UInt64;
  val132 @64 :UInt64;
  val133 @65 :UInt64;
  val135 @66 :UInt64;
  val136 @67 :UInt64;
  val144 @68 :UInt64;
  val146 @69 :UInt64;
  val147 @70 :UInt64;
  val170 @71 :UInt64;
  val172 @72 :UInt64;
  val173 @73 :UInt64;
  val183 @74 :UInt64;
  val184 @75 :UInt64;
  val360 @76 :UInt64;
  val361 @77 :UInt64;
  val362 @78 :UInt64;
  val2 @79 :Bool;
  val12 @80 :Bool;
  val15 @81 :Bool;
  val16 @82 :Bool;
  val17 @83 :Bool;
  val18 @84 :Bool;
  val19 @85 :Bool;
  val20 @86 :Bool;
  val21 @87 :Bool;
  val22 @88 :Bool;
  val23 @89 :Bool;
  val24 @90 :Bool;
  val25 @91 :Bool;
  val26 @92 :Bool;
  val27 @93 :Bool;
  val28 @94 :Bool;
  val29 @95 :Bool;
  val30 @96 :Bool;
  val31 @97 :Bool;
  val32 @98 :Bool;
  val33 @99 :Bool;
  val34 @100 :Bool;
  val35 @101 :Bool;
  val36 @102 :Bool;
  val37 @103 :Bool;
  val38 @104 :Bool;
  val39 @105 :Bool;
  val40 @106 :Bool;
  val41 @107 :Bool;
  val42 @108 :Bool;
  val43 @109 :Bool;
  val44 @110 :Bool;
  val45 @111 :Bool;
  val46 @112 :Bool;
  val53 @113 :Bool;
  val56 @114 :Bool;
  val57 @115 :Bool;
  val58 @116 :Bool;
  val62 @117 :Bool;
  val63 @118 :Bool;
  val64 @119 :Bool;
  val74 @120 :Bool;
  val75 @121 :Bool;
  val77 @122 :Bool;
  val78 @123 :Bool;
  val79 @124 :Bool;
  val80 @125 :Bool;
  val97 @126 :Bool;
  val98 @127 :Bool;
  val99 @128 :Bool;
  val100 @129 :Bool;
  val101 @130 :Bool;
  val102 @131 :Bool;
  val103 @132 :Bool;
  val104 @133 :Bool;
  val105 @134 :Bool;
  val106 @135 :Bool;
  val107 @136 :Bool;
  val108 @137 :Bool;
  val109 @138 :Bool;
  val110 @139 :Bool;
  val111 @140 :Bool;
  val112 @141 :Bool;
  val113 @142 :Bool;
  val114 @143 :Bool;
  val115 @144 :Bool;
  val116 @145 :Bool;
  val117 @146 :Bool;
  val118 @147 :Bool;
  val119 @148 :Bool;
  val120 @149 :Bool;
  val121 @150 :Bool;
  val122 @151 :Bool;
  val123 @152 :Bool;
  val124 @153 :Bool;
  val125 @154 :Bool;
  val126 @155 :Bool;
  val127 @156 :Bool;
  val128 @157 :Bool;
  val129 @158 :Bool;
  val130 @159 :Bool;
  val137 @160 :Bool;
  val138 @161 :Bool;
  val139 @162 :Bool;
  val140 @163 :Bool;
  val141 @164 :Bool;
  val142 @165 :Bool;
  val143 @166 :Bool;
  val148 @167 :Bool;
  val149 @168 :Bool;
  val150 @169 :Bool;
  val151 @170 :Bool;
  val152 @171 :Bool;
  val153 @172 :Bool;
  val154 @173 :Bool;
  val155 @174 :Bool;
  val156 @175 :Bool;
  val157 @176 :Bool;
  val158 @177 :Bool;
  val159 @178 :Bool;
  val160 @179 :Bool;
  val161 @180 :Bool;
  val162 @181 :Bool;
  val163 @182 :Bool;
  val164 @183 :Bool;
  val165 @184 :Bool;
  val166 @185 :Bool;
  val167 @186 :Bool;
  val168 @187 :Bool;
  val169 @188 :Bool;
  val174 @189 :Bool;
  val175 @190 :Bool;
  val176 @191 :Bool;
  val177 @192 :Bool;
  val178 @193 :Bool;
  val179 @194 :Bool;
  val180 @195 :Bool;
  val181 @196 :Bool;
  val185 @197 :Bool;
  val186 @198 :Bool;
  val187 @199 :Bool;
  val188 @200 :Bool;
  val189 @201 :Bool;
  val194 @202 :Bool;
  val195 @203 :Bool;
  val196 @204 :Bool;
  val197 @205 :Bool;
  val198 @206 :Bool;
  val199 @207 :Bool;
  val200 @208 :Bool;
  val201 @209 :Bool;
  val202 @210 :Bool;
  val203 @211 :Bool;
  val204 @212 :Bool;
  val205 @213 :Bool;
  val206 @214 :Bool;
  val207 @215 :Bool;
  val208 @216 :Bool;
  val209 @217 :Bool;
  val210 @218 :Bool;
  val211 @219 :Bool;
  val212 @220 :Bool;
  val213 @221 :Bool;
  val214 @222 :Bool;
  val215 @223 :Bool;
  val216 @224 :Bool;
  val217 @225 :Bool;
  val218 @226 :Bool;
  val219 @227 :Bool;
  val220 @228 :Bool;
  val221 @229 :Bool;
  val222 @230 :Bool;
  val223 @231 :Bool;
  val224 @232 :Bool;
  val225 @233 :Bool;
  val226 @234 :Bool;
  val227 @235 :Bool;
  val228 @236 :Bool;
  val229 @237 :Bool;
  val230 @238 :Bool;
  val231 @239 :Bool;
  val232 @240 :Bool;
  val233 @241 :Bool;
  val234 @242 :Bool;
  val235 @243 :Bool;
  val236 @244 :Bool;
  val237 @245 :Bool;
  val238 @246 :Bool;
  val239 @247 :Bool;
  val240 @248 :Bool;
  val241 @249 :Bool;
  val242 @250 :Bool;
  val243 @251 :Bool;
  val244 @252 :Bool;
  val245 @253 :Bool;
  val246 @254 :Bool;
  val247 @255 :Bool;
  val248 @256 :Bool;
  val249 @257 :Bool;
  val250 @258 :Bool;
  val251 @259 :Bool;
  val252 @260 :Bool;
  val253 @261 :Bool;
  val254 @262 :Bool;
  val255 @263 :Bool;
  val256 @264 :Bool;
  val257 @265 :Bool;
  val258 @266 :Bool;
  val259 @267 :Bool;
  val260 @268 :Bool;
  val261 @269 :Bool;
  val262 @270 :Bool;
  val263 @271 :Bool;
  val264 @272 :Bool;
  val265 @273 :Bool;
  val266 @274 :Bool;
  val267 @275 :Bool;
  val268 @276 :Bool;
  val269 @277 :Bool;
  val270 @278 :Bool;
  val271 @279 :Bool;
  val272 @280 :Bool;
  val273 @281 :Bool;
  val274 @282 :Bool;
  val275 @283 :Bool;
  val276 @284 :Bool;
  val277 @285 :Bool;
  val278 @286 :Bool;
  val279 @287 :Bool;
  val280 @288 :Bool;
  val281 @289 :Bool;
  val282 @290 :Bool;
  val283 @291 :Bool;
  val284 @292 :Bool;
  val285 @293 :Bool;
  val286 @294 :Bool;
  val287 @295 :Bool;
  val288 @296 :Bool;
  val289 @297 :Bool;
  val290 @298 :Bool;
  val291 @299 :Bool;
  val292 @300 :Bool;
  val293 @301 :Bool;
  val294 @302 :Bool;
  val295 @303 :Bool;
  val296 @304 :Bool;
  val297 @305 :Bool;
  val298 @306 :Bool;
  val299 @307 :Bool;
  val300 @308 :Bool;
  val301 @309 :Bool;
  val302 @310 :Bool;
  val303 @311 :Bool;
  val304 @312 :Bool;
  val305 @313 :Bool;
  val306 @314 :Bool;
  val307 @315 :Bool;
  val308 @316 :Bool;
  val309 @317 :Bool;
  val310 @318 :Bool;
  val311 @319 :Bool;
  val312 @320 :Bool;
  val313 @321 :Bool;
  val314 @322 :Bool;
  val315 @323 :Bool;
  val316 @324 :Bool;
  val317 @325 :Bool;
  val319 @326 :Bool;
  val320 @327 :Bool;
  val321 @328 :Bool;
  val322 @329 :Bool;
  val323 @330 :Bool;
  val324 @331 :Bool;
  val325 @332 :Bool;
  val326 @333 :Bool;
  val327 @334 :Bool;
  val328 @335 :Bool;
  val329 @336 :Bool;
  val330 @337 :Bool;
  val331 @338 :Bool;
  val332 @339 :Bool;
  val333 @340 :Bool;
  val334 @341 :Bool;
  val335 @342 :Bool;
  val336 @343 :Bool;
  val337 @344 :Bool;
  val338 @345 :Bool;
  val339 @346 :Bool;
  val340 @347 :Bool;
  val341 @348 :Bool;
  val342 @349 :Bool;
  val343 @350 :Bool;
  val345 @351 :Bool;
  val346 @352 :Bool;
  val347 @353 :Bool;
  val348 @354 :Bool;
  val349 @355 :Bool;
  val350 @356 :Bool;
  val351 @357 :Bool;
  val352 @358 :Bool;
  val353 @359 :Bool;
  val354 @360 :Bool;
  val357 @361 :Bool;
  val358 @362 :Bool;
  val359 @363 :Bool;
  val363 @364 :Bool;
  val11 @365 :UInt32;
  val145 @366 :UInt32;
  val193 @367 :UInt32;
}

struct Stmt @0x91127d30fade9a32{
  val105 @0 :UInt32;
  val61 @1 :List(Text);
  val62 @2 :List(Text);
  val63 @3 :List(Text);
  val64 @4 :List(Text);
  val66 @5 :List(Text);
  val68 @6 :List(Text);
  val4 @7 :List(UInt64);
  val15 @8 :List(UInt64);
  val26 @9 :List(UInt64);
  val27 @10 :List(UInt64);
  val28 @11 :List(UInt64);
  val29 @12 :List(UInt64);
  val52 @13 :List(UInt64);
  val53 @14 :List(UInt64);
  val54 @15 :List(UInt64);
  val67 @16 :List(UInt64);
  val7 @17 :UInt8;
  val56 @18 :UInt8;
  val69 @19 :UInt8;
  val70 @20 :UInt8;
  val95 @21 :UInt8;
  val97 @22 :UInt8;
  val60 @23 :Text;
  val65 @24 :Text;
  val12 @25 :Bool;
  val16 @26 :Bool;
  val23 @27 :Bool;
  val24 @28 :Bool;
  val25 @29 :Bool;
  val57 @30 :Bool;
  val58 @31 :Bool;
  val59 @32 :Bool;
  val71 @33 :Bool;
  val72 @34 :Bool;
  val73 @35 :Bool;
  val74 @36 :Bool;
  val75 @37 :Bool;
  val76 @38 :Bool;
  val77 @39 :Bool;
  val78 @40 :Bool;
  val79 @41 :Bool;
  val80 @42 :Bool;
  val81 @43 :Bool;
  val82 @44 :Bool;
  val83 @45 :Bool;
  val84 @46 :Bool;
  val85 @47 :Bool;
  val86 @48 :Bool;
  val87 @49 :Bool;
  val88 @50 :Bool;
  val89 @51 :Bool;
  val90 @52 :Bool;
  val91 @53 :Bool;
  val92 @54 :Bool;
  val93 @55 :Bool;
  val94 @56 :Bool;
  val96 @57 :Bool;
  val98 @58 :Bool;
  val99 @59 :Bool;
  val100 @60 :Bool;
  val101 @61 :Bool;
  val102 @62 :Bool;
  val103 @63 :Bool;
  val104 @64 :Bool;
  val0 @65 :UInt64;
  val1 @66 :UInt64;
  val2 @67 :UInt64;
  val3 @68 :UInt64;
  val5 @69 :UInt64;
  val6 @70 :UInt64;
  val8 @71 :UInt64;
  val9 @72 :UInt64;
  val10 @73 :UInt64;
  val11 @74 :UInt64;
  val13 @75 :UInt64;
  val14 @76 :UInt64;
  val17 @77 :UInt64;
  val18 @78 :UInt64;
  val19 @79 :UInt64;
  val20 @80 :UInt64;
  val21 @81 :UInt64;
  val22 @82 :UInt64;
  val30 @83 :UInt64;
  val31 @84 :UInt64;
  val32 @85 :UInt64;
  val33 @86 :UInt64;
  val34 @87 :UInt64;
  val35 @88 :UInt64;
  val36 @89 :UInt64;
  val37 @90 :UInt64;
  val38 @91 :UInt64;
  val39 @92 :UInt64;
  val40 @93 :UInt64;
  val41 @94 :UInt64;
  val42 @95 :UInt64;
  val43 @96 :UInt64;
  val44 @97 :UInt64;
  val45 @98 :UInt64;
  val46 @99 :UInt64;
  val47 @100 :UInt64;
  val48 @101 :UInt64;
  val49 @102 :UInt64;
  val50 @103 :UInt64;
  val51 @104 :UInt64;
  val55 @105 :UInt64;
}

struct Type @0xd739e808bc1b3fd7{
  val284 @0 :UInt16;
  val13 @1 :UInt8;
  val14 @2 :UInt8;
  val19 @3 :UInt8;
  val22 @4 :UInt8;
  val24 @5 :UInt8;
  val244 @6 :UInt8;
  val280 @7 :UInt8;
  val281 @8 :UInt8;
  val283 @9 :UInt8;
  val240 @10 :List(UInt64);
  val275 @11 :List(UInt64);
  val278 @12 :List(UInt64);
  val279 @13 :List(UInt64);
  val0 @14 :UInt64;
  val1 @15 :UInt64;
  val3 @16 :UInt64;
  val4 @17 :UInt64;
  val6 @18 :UInt64;
  val16 @19 :UInt64;
  val17 @20 :UInt64;
  val18 @21 :UInt64;
  val21 @22 :UInt64;
  val23 @23 :UInt64;
  val235 @24 :UInt64;
  val236 @25 :UInt64;
  val242 @26 :UInt64;
  val243 @27 :UInt64;
  val276 @28 :UInt64;
  val277 @29 :UInt64;
  val282 @30 :UInt64;
  val2 @31 :Bool;
  val5 @32 :Bool;
  val7 @33 :Bool;
  val8 @34 :Bool;
  val9 @35 :Bool;
  val10 @36 :Bool;
  val11 @37 :Bool;
  val12 @38 :Bool;
  val15 @39 :Bool;
  val20 @40 :Bool;
  val25 @41 :Bool;
  val26 @42 :Bool;
  val27 @43 :Bool;
  val28 @44 :Bool;
  val29 @45 :Bool;
  val30 @46 :Bool;
  val31 @47 :Bool;
  val32 @48 :Bool;
  val33 @49 :Bool;
  val34 @50 :Bool;
  val35 @51 :Bool;
  val36 @52 :Bool;
  val37 @53 :Bool;
  val38 @54 :Bool;
  val39 @55 :Bool;
  val40 @56 :Bool;
  val41 @57 :Bool;
  val42 @58 :Bool;
  val43 @59 :Bool;
  val44 @60 :Bool;
  val45 @61 :Bool;
  val46 @62 :Bool;
  val47 @63 :Bool;
  val48 @64 :Bool;
  val49 @65 :Bool;
  val50 @66 :Bool;
  val51 @67 :Bool;
  val52 @68 :Bool;
  val53 @69 :Bool;
  val54 @70 :Bool;
  val55 @71 :Bool;
  val56 @72 :Bool;
  val57 @73 :Bool;
  val58 @74 :Bool;
  val59 @75 :Bool;
  val60 @76 :Bool;
  val61 @77 :Bool;
  val62 @78 :Bool;
  val63 @79 :Bool;
  val64 @80 :Bool;
  val65 @81 :Bool;
  val66 @82 :Bool;
  val67 @83 :Bool;
  val68 @84 :Bool;
  val69 @85 :Bool;
  val70 @86 :Bool;
  val71 @87 :Bool;
  val72 @88 :Bool;
  val73 @89 :Bool;
  val74 @90 :Bool;
  val75 @91 :Bool;
  val76 @92 :Bool;
  val77 @93 :Bool;
  val78 @94 :Bool;
  val79 @95 :Bool;
  val80 @96 :Bool;
  val81 @97 :Bool;
  val82 @98 :Bool;
  val83 @99 :Bool;
  val84 @100 :Bool;
  val85 @101 :Bool;
  val86 @102 :Bool;
  val87 @103 :Bool;
  val88 @104 :Bool;
  val89 @105 :Bool;
  val90 @106 :Bool;
  val91 @107 :Bool;
  val92 @108 :Bool;
  val93 @109 :Bool;
  val94 @110 :Bool;
  val95 @111 :Bool;
  val96 @112 :Bool;
  val97 @113 :Bool;
  val98 @114 :Bool;
  val99 @115 :Bool;
  val100 @116 :Bool;
  val101 @117 :Bool;
  val102 @118 :Bool;
  val103 @119 :Bool;
  val104 @120 :Bool;
  val105 @121 :Bool;
  val106 @122 :Bool;
  val107 @123 :Bool;
  val108 @124 :Bool;
  val109 @125 :Bool;
  val110 @126 :Bool;
  val111 @127 :Bool;
  val112 @128 :Bool;
  val113 @129 :Bool;
  val114 @130 :Bool;
  val115 @131 :Bool;
  val116 @132 :Bool;
  val117 @133 :Bool;
  val118 @134 :Bool;
  val119 @135 :Bool;
  val120 @136 :Bool;
  val121 @137 :Bool;
  val122 @138 :Bool;
  val123 @139 :Bool;
  val124 @140 :Bool;
  val125 @141 :Bool;
  val126 @142 :Bool;
  val127 @143 :Bool;
  val128 @144 :Bool;
  val129 @145 :Bool;
  val130 @146 :Bool;
  val131 @147 :Bool;
  val132 @148 :Bool;
  val133 @149 :Bool;
  val134 @150 :Bool;
  val135 @151 :Bool;
  val136 @152 :Bool;
  val137 @153 :Bool;
  val138 @154 :Bool;
  val139 @155 :Bool;
  val140 @156 :Bool;
  val141 @157 :Bool;
  val142 @158 :Bool;
  val143 @159 :Bool;
  val144 @160 :Bool;
  val145 @161 :Bool;
  val146 @162 :Bool;
  val147 @163 :Bool;
  val148 @164 :Bool;
  val149 @165 :Bool;
  val150 @166 :Bool;
  val151 @167 :Bool;
  val152 @168 :Bool;
  val153 @169 :Bool;
  val154 @170 :Bool;
  val155 @171 :Bool;
  val156 @172 :Bool;
  val157 @173 :Bool;
  val158 @174 :Bool;
  val159 @175 :Bool;
  val160 @176 :Bool;
  val161 @177 :Bool;
  val162 @178 :Bool;
  val163 @179 :Bool;
  val164 @180 :Bool;
  val165 @181 :Bool;
  val166 @182 :Bool;
  val167 @183 :Bool;
  val168 @184 :Bool;
  val169 @185 :Bool;
  val170 @186 :Bool;
  val171 @187 :Bool;
  val172 @188 :Bool;
  val173 @189 :Bool;
  val174 @190 :Bool;
  val175 @191 :Bool;
  val176 @192 :Bool;
  val177 @193 :Bool;
  val178 @194 :Bool;
  val179 @195 :Bool;
  val180 @196 :Bool;
  val181 @197 :Bool;
  val182 @198 :Bool;
  val183 @199 :Bool;
  val184 @200 :Bool;
  val185 @201 :Bool;
  val186 @202 :Bool;
  val187 @203 :Bool;
  val188 @204 :Bool;
  val189 @205 :Bool;
  val190 @206 :Bool;
  val191 @207 :Bool;
  val192 @208 :Bool;
  val193 @209 :Bool;
  val194 @210 :Bool;
  val195 @211 :Bool;
  val196 @212 :Bool;
  val197 @213 :Bool;
  val198 @214 :Bool;
  val199 @215 :Bool;
  val200 @216 :Bool;
  val201 @217 :Bool;
  val202 @218 :Bool;
  val203 @219 :Bool;
  val204 @220 :Bool;
  val205 @221 :Bool;
  val206 @222 :Bool;
  val207 @223 :Bool;
  val208 @224 :Bool;
  val209 @225 :Bool;
  val210 @226 :Bool;
  val211 @227 :Bool;
  val212 @228 :Bool;
  val213 @229 :Bool;
  val214 @230 :Bool;
  val215 @231 :Bool;
  val216 @232 :Bool;
  val217 @233 :Bool;
  val218 @234 :Bool;
  val219 @235 :Bool;
  val220 @236 :Bool;
  val221 @237 :Bool;
  val222 @238 :Bool;
  val223 @239 :Bool;
  val224 @240 :Bool;
  val225 @241 :Bool;
  val226 @242 :Bool;
  val227 @243 :Bool;
  val228 @244 :Bool;
  val229 @245 :Bool;
  val230 @246 :Bool;
  val231 @247 :Bool;
  val232 @248 :Bool;
  val233 @249 :Bool;
  val234 @250 :Bool;
  val237 @251 :Bool;
  val238 @252 :Bool;
  val239 @253 :Bool;
  val245 @254 :Bool;
  val246 @255 :Bool;
  val247 @256 :Bool;
  val248 @257 :Bool;
  val249 @258 :Bool;
  val250 @259 :Bool;
  val251 @260 :Bool;
  val252 @261 :Bool;
  val253 @262 :Bool;
  val254 @263 :Bool;
  val255 @264 :Bool;
  val256 @265 :Bool;
  val257 @266 :Bool;
  val258 @267 :Bool;
  val259 @268 :Bool;
  val260 @269 :Bool;
  val261 @270 :Bool;
  val262 @271 :Bool;
  val263 @272 :Bool;
  val264 @273 :Bool;
  val265 @274 :Bool;
  val266 @275 :Bool;
  val267 @276 :Bool;
  val268 @277 :Bool;
  val269 @278 :Bool;
  val270 @279 :Bool;
  val271 @280 :Bool;
  val272 @281 :Bool;
  val273 @282 :Bool;
  val274 @283 :Bool;
  val241 @284 :UInt32;
}

struct Attr @0xe5b70746662da9f3{
  val20 @0 :UInt32;
  val10 @1 :UInt8;
  val14 @2 :UInt8;
  val15 @3 :UInt8;
  val0 @4 :UInt64;
  val6 @5 :UInt64;
  val7 @6 :UInt64;
  val8 @7 :UInt64;
  val16 @8 :UInt64;
  val1 @9 :Bool;
  val2 @10 :Bool;
  val3 @11 :Bool;
  val4 @12 :Bool;
  val11 @13 :Bool;
  val12 @14 :Bool;
  val13 @15 :Bool;
  val19 @16 :Bool;
  val21 @17 :Bool;
  val22 @18 :Bool;
  val23 @19 :Bool;
  val24 @20 :Bool;
  val25 @21 :Bool;
  val9 @22 :Text;
  val17 @23 :Text;
  val18 @24 :Text;
  val5 @25 :UInt16;
}

struct Macro @0xf88157fb8bf2eeff{
  val3 @0 :Bool;
  val13 @1 :Bool;
  val2 @2 :List(UInt64);
  val4 @3 :List(UInt64);
  val9 @4 :List(UInt64);
  val10 @5 :List(UInt64);
  val12 @6 :UInt32;
  val1 @7 :UInt64;
  val5 @8 :UInt64;
  val6 @9 :UInt64;
  val7 @10 :UInt64;
  val8 @11 :UInt64;
  val11 @12 :UInt64;
  val0 @13 :UInt8;
}

struct TemplateArgument @0xb5127dad01992f67{
  val6 @0 :UInt64;
  val7 @1 :UInt64;
  val8 @2 :UInt64;
  val9 @3 :UInt64;
  val1 @4 :Bool;
  val2 @5 :Bool;
  val3 @6 :Bool;
  val4 @7 :Bool;
  val5 @8 :Bool;
  val0 @9 :UInt8;
}

struct TemplateParameterList @0xee0d4e6aba92fdde{
  val9 @0 :List(UInt64);
  val1 @1 :Bool;
  val2 @2 :Bool;
  val3 @3 :UInt64;
  val4 @4 :UInt64;
  val5 @5 :UInt64;
  val6 @6 :UInt64;
  val7 @7 :UInt64;
  val8 @8 :UInt64;
  val0 @9 :UInt32;
}

struct CXXBaseSpecifier @0x8e0e4024ab6be99f{
  val4 @0 :UInt8;
  val8 @1 :UInt8;
  val9 @2 :UInt8;
  val3 @3 :Bool;
  val5 @4 :Bool;
  val6 @5 :Bool;
  val0 @6 :UInt64;
  val1 @7 :UInt64;
  val2 @8 :UInt64;
  val7 @9 :UInt64;
  val10 @10 :UInt64;
}

struct Designator @0x8fa2d595d812339e{
  val3 @0 :UInt64;
  val4 @1 :UInt64;
  val5 @2 :UInt64;
  val6 @3 :UInt64;
  val7 @4 :UInt64;
  val8 @5 :UInt64;
  val9 @6 :UInt64;
  val10 @7 :UInt64;
  val0 @8 :Bool;
  val1 @9 :Bool;
  val2 @10 :Bool;
}

