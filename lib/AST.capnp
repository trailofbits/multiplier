# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

# Auto-generated file; do not modify!

@0xa04be7b45e95b659;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::ast");

struct Decl @0xfb5879761ffaedb6 {
  val84 @0 :List(UInt32);
  val150 @1 :List(UInt32);
  val151 @2 :List(UInt32);
  val349 @3 :List(UInt32);
  val350 @4 :List(UInt32);
  val48 @5 :List(UInt64);
  val55 @6 :List(UInt64);
  val56 @7 :List(UInt64);
  val64 @8 :List(UInt64);
  val184 @9 :List(UInt64);
  val185 @10 :List(UInt64);
  val322 @11 :List(UInt64);
  val354 @12 :List(UInt64);
  val355 @13 :List(UInt64);
  val356 @14 :List(UInt64);
  val357 @15 :List(UInt64);
  val358 @16 :List(UInt64);
  val359 @17 :List(UInt64);
  val360 @18 :List(UInt64);
  val361 @19 :List(UInt64);
  val362 @20 :List(UInt64);
  val66 @21 :Text;
  val67 @22 :Text;
  val78 @23 :Text;
  val0 @24 :UInt64;
  val1 @25 :UInt64;
  val5 @26 :UInt64;
  val6 @27 :UInt64;
  val7 @28 :UInt64;
  val10 @29 :UInt64;
  val13 @30 :UInt64;
  val14 @31 :UInt64;
  val16 @32 :UInt64;
  val18 @33 :UInt64;
  val50 @34 :UInt64;
  val51 @35 :UInt64;
  val52 @36 :UInt64;
  val53 @37 :UInt64;
  val60 @38 :UInt64;
  val65 @39 :UInt64;
  val69 @40 :UInt64;
  val70 @41 :UInt64;
  val71 @42 :UInt64;
  val72 @43 :UInt64;
  val83 @44 :UInt64;
  val86 @45 :UInt64;
  val88 @46 :UInt64;
  val91 @47 :UInt64;
  val96 @48 :UInt64;
  val136 @49 :UInt64;
  val138 @50 :UInt64;
  val139 @51 :UInt64;
  val141 @52 :UInt64;
  val153 @53 :UInt64;
  val165 @54 :UInt64;
  val167 @55 :UInt64;
  val176 @56 :UInt64;
  val178 @57 :UInt64;
  val9 @58 :Bool;
  val15 @59 :Bool;
  val17 @60 :Bool;
  val19 @61 :Bool;
  val20 @62 :Bool;
  val21 @63 :Bool;
  val22 @64 :Bool;
  val23 @65 :Bool;
  val24 @66 :Bool;
  val25 @67 :Bool;
  val26 @68 :Bool;
  val27 @69 :Bool;
  val28 @70 :Bool;
  val29 @71 :Bool;
  val30 @72 :Bool;
  val31 @73 :Bool;
  val32 @74 :Bool;
  val33 @75 :Bool;
  val34 @76 :Bool;
  val35 @77 :Bool;
  val36 @78 :Bool;
  val37 @79 :Bool;
  val38 @80 :Bool;
  val39 @81 :Bool;
  val40 @82 :Bool;
  val41 @83 :Bool;
  val42 @84 :Bool;
  val43 @85 :Bool;
  val44 @86 :Bool;
  val45 @87 :Bool;
  val46 @88 :Bool;
  val47 @89 :Bool;
  val54 @90 :Bool;
  val57 @91 :Bool;
  val58 @92 :Bool;
  val59 @93 :Bool;
  val61 @94 :Bool;
  val62 @95 :Bool;
  val63 @96 :Bool;
  val76 @97 :Bool;
  val77 @98 :Bool;
  val79 @99 :Bool;
  val80 @100 :Bool;
  val81 @101 :Bool;
  val85 @102 :Bool;
  val87 @103 :Bool;
  val89 @104 :Bool;
  val97 @105 :Bool;
  val100 @106 :Bool;
  val101 @107 :Bool;
  val102 @108 :Bool;
  val103 @109 :Bool;
  val104 @110 :Bool;
  val105 @111 :Bool;
  val106 @112 :Bool;
  val107 @113 :Bool;
  val108 @114 :Bool;
  val109 @115 :Bool;
  val110 @116 :Bool;
  val111 @117 :Bool;
  val112 @118 :Bool;
  val113 @119 :Bool;
  val114 @120 :Bool;
  val115 @121 :Bool;
  val116 @122 :Bool;
  val117 @123 :Bool;
  val118 @124 :Bool;
  val119 @125 :Bool;
  val120 @126 :Bool;
  val121 @127 :Bool;
  val122 @128 :Bool;
  val123 @129 :Bool;
  val124 @130 :Bool;
  val125 @131 :Bool;
  val126 @132 :Bool;
  val127 @133 :Bool;
  val128 @134 :Bool;
  val129 @135 :Bool;
  val130 @136 :Bool;
  val131 @137 :Bool;
  val132 @138 :Bool;
  val133 @139 :Bool;
  val134 @140 :Bool;
  val137 @141 :Bool;
  val142 @142 :Bool;
  val143 @143 :Bool;
  val144 @144 :Bool;
  val145 @145 :Bool;
  val146 @146 :Bool;
  val147 @147 :Bool;
  val148 @148 :Bool;
  val149 @149 :Bool;
  val154 @150 :Bool;
  val155 @151 :Bool;
  val156 @152 :Bool;
  val157 @153 :Bool;
  val158 @154 :Bool;
  val159 @155 :Bool;
  val160 @156 :Bool;
  val161 @157 :Bool;
  val162 @158 :Bool;
  val163 @159 :Bool;
  val164 @160 :Bool;
  val166 @161 :Bool;
  val168 @162 :Bool;
  val169 @163 :Bool;
  val170 @164 :Bool;
  val171 @165 :Bool;
  val172 @166 :Bool;
  val173 @167 :Bool;
  val174 @168 :Bool;
  val175 @169 :Bool;
  val177 @170 :Bool;
  val179 @171 :Bool;
  val180 @172 :Bool;
  val181 @173 :Bool;
  val182 @174 :Bool;
  val183 @175 :Bool;
  val190 @176 :Bool;
  val191 @177 :Bool;
  val192 @178 :Bool;
  val193 @179 :Bool;
  val194 @180 :Bool;
  val195 @181 :Bool;
  val196 @182 :Bool;
  val197 @183 :Bool;
  val198 @184 :Bool;
  val199 @185 :Bool;
  val200 @186 :Bool;
  val201 @187 :Bool;
  val202 @188 :Bool;
  val203 @189 :Bool;
  val204 @190 :Bool;
  val205 @191 :Bool;
  val206 @192 :Bool;
  val207 @193 :Bool;
  val208 @194 :Bool;
  val209 @195 :Bool;
  val210 @196 :Bool;
  val211 @197 :Bool;
  val212 @198 :Bool;
  val213 @199 :Bool;
  val214 @200 :Bool;
  val215 @201 :Bool;
  val216 @202 :Bool;
  val217 @203 :Bool;
  val218 @204 :Bool;
  val219 @205 :Bool;
  val220 @206 :Bool;
  val221 @207 :Bool;
  val222 @208 :Bool;
  val223 @209 :Bool;
  val224 @210 :Bool;
  val225 @211 :Bool;
  val226 @212 :Bool;
  val227 @213 :Bool;
  val228 @214 :Bool;
  val229 @215 :Bool;
  val230 @216 :Bool;
  val231 @217 :Bool;
  val232 @218 :Bool;
  val233 @219 :Bool;
  val234 @220 :Bool;
  val235 @221 :Bool;
  val236 @222 :Bool;
  val237 @223 :Bool;
  val238 @224 :Bool;
  val239 @225 :Bool;
  val240 @226 :Bool;
  val241 @227 :Bool;
  val242 @228 :Bool;
  val243 @229 :Bool;
  val244 @230 :Bool;
  val245 @231 :Bool;
  val246 @232 :Bool;
  val247 @233 :Bool;
  val248 @234 :Bool;
  val249 @235 :Bool;
  val250 @236 :Bool;
  val251 @237 :Bool;
  val252 @238 :Bool;
  val253 @239 :Bool;
  val254 @240 :Bool;
  val255 @241 :Bool;
  val256 @242 :Bool;
  val257 @243 :Bool;
  val258 @244 :Bool;
  val259 @245 :Bool;
  val260 @246 :Bool;
  val261 @247 :Bool;
  val262 @248 :Bool;
  val263 @249 :Bool;
  val264 @250 :Bool;
  val265 @251 :Bool;
  val266 @252 :Bool;
  val267 @253 :Bool;
  val268 @254 :Bool;
  val269 @255 :Bool;
  val270 @256 :Bool;
  val271 @257 :Bool;
  val272 @258 :Bool;
  val273 @259 :Bool;
  val274 @260 :Bool;
  val275 @261 :Bool;
  val276 @262 :Bool;
  val277 @263 :Bool;
  val278 @264 :Bool;
  val279 @265 :Bool;
  val280 @266 :Bool;
  val281 @267 :Bool;
  val282 @268 :Bool;
  val283 @269 :Bool;
  val284 @270 :Bool;
  val285 @271 :Bool;
  val286 @272 :Bool;
  val287 @273 :Bool;
  val288 @274 :Bool;
  val289 @275 :Bool;
  val290 @276 :Bool;
  val291 @277 :Bool;
  val292 @278 :Bool;
  val293 @279 :Bool;
  val294 @280 :Bool;
  val295 @281 :Bool;
  val296 @282 :Bool;
  val297 @283 :Bool;
  val298 @284 :Bool;
  val299 @285 :Bool;
  val300 @286 :Bool;
  val301 @287 :Bool;
  val302 @288 :Bool;
  val303 @289 :Bool;
  val304 @290 :Bool;
  val305 @291 :Bool;
  val306 @292 :Bool;
  val307 @293 :Bool;
  val308 @294 :Bool;
  val309 @295 :Bool;
  val310 @296 :Bool;
  val311 @297 :Bool;
  val312 @298 :Bool;
  val313 @299 :Bool;
  val314 @300 :Bool;
  val315 @301 :Bool;
  val316 @302 :Bool;
  val317 @303 :Bool;
  val318 @304 :Bool;
  val319 @305 :Bool;
  val320 @306 :Bool;
  val321 @307 :Bool;
  val323 @308 :Bool;
  val324 @309 :Bool;
  val325 @310 :Bool;
  val326 @311 :Bool;
  val327 @312 :Bool;
  val328 @313 :Bool;
  val329 @314 :Bool;
  val330 @315 :Bool;
  val331 @316 :Bool;
  val332 @317 :Bool;
  val333 @318 :Bool;
  val334 @319 :Bool;
  val335 @320 :Bool;
  val336 @321 :Bool;
  val337 @322 :Bool;
  val338 @323 :Bool;
  val339 @324 :Bool;
  val340 @325 :Bool;
  val341 @326 :Bool;
  val342 @327 :Bool;
  val343 @328 :Bool;
  val344 @329 :Bool;
  val345 @330 :Bool;
  val346 @331 :Bool;
  val347 @332 :Bool;
  val348 @333 :Bool;
  val351 @334 :Bool;
  val352 @335 :Bool;
  val353 @336 :Bool;
  val2 @337 :UInt16;
  val3 @338 :UInt16;
  val4 @339 :UInt16;
  val11 @340 :UInt16;
  val12 @341 :UInt16;
  val49 @342 :UInt16;
  val68 @343 :UInt16;
  val73 @344 :UInt16;
  val74 @345 :UInt16;
  val75 @346 :UInt16;
  val82 @347 :UInt16;
  val90 @348 :UInt16;
  val92 @349 :UInt16;
  val93 @350 :UInt16;
  val94 @351 :UInt16;
  val95 @352 :UInt16;
  val98 @353 :UInt16;
  val99 @354 :UInt16;
  val135 @355 :UInt16;
  val140 @356 :UInt16;
  val8 @357 :UInt32;
  val152 @358 :UInt32;
  val186 @359 :UInt32;
  val187 @360 :UInt32;
  val188 @361 :UInt32;
  val189 @362 :UInt32;
}

struct Stmt @0x91127d30fade9a32 {
  val112 @0 :UInt32;
  val105 @1 :List(UInt32);
  val64 @2 :List(Text);
  val65 @3 :List(Text);
  val66 @4 :List(Text);
  val67 @5 :List(Text);
  val69 @6 :List(Text);
  val71 @7 :List(Text);
  val3 @8 :List(UInt64);
  val17 @9 :List(UInt64);
  val23 @10 :List(UInt64);
  val24 @11 :List(UInt64);
  val25 @12 :List(UInt64);
  val26 @13 :List(UInt64);
  val53 @14 :List(UInt64);
  val54 @15 :List(UInt64);
  val55 @16 :List(UInt64);
  val70 @17 :List(UInt64);
  val8 @18 :UInt8;
  val62 @19 :UInt8;
  val72 @20 :UInt8;
  val103 @21 :UInt8;
  val106 @22 :UInt8;
  val63 @23 :Text;
  val68 @24 :Text;
  val13 @25 :Bool;
  val16 @26 :Bool;
  val21 @27 :Bool;
  val22 @28 :Bool;
  val57 @29 :Bool;
  val58 @30 :Bool;
  val59 @31 :Bool;
  val60 @32 :Bool;
  val61 @33 :Bool;
  val73 @34 :Bool;
  val74 @35 :Bool;
  val75 @36 :Bool;
  val76 @37 :Bool;
  val77 @38 :Bool;
  val78 @39 :Bool;
  val79 @40 :Bool;
  val80 @41 :Bool;
  val81 @42 :Bool;
  val82 @43 :Bool;
  val83 @44 :Bool;
  val84 @45 :Bool;
  val85 @46 :Bool;
  val86 @47 :Bool;
  val87 @48 :Bool;
  val88 @49 :Bool;
  val89 @50 :Bool;
  val90 @51 :Bool;
  val91 @52 :Bool;
  val92 @53 :Bool;
  val93 @54 :Bool;
  val94 @55 :Bool;
  val95 @56 :Bool;
  val96 @57 :Bool;
  val97 @58 :Bool;
  val98 @59 :Bool;
  val99 @60 :Bool;
  val100 @61 :Bool;
  val101 @62 :Bool;
  val102 @63 :Bool;
  val104 @64 :Bool;
  val107 @65 :Bool;
  val108 @66 :Bool;
  val109 @67 :Bool;
  val110 @68 :Bool;
  val111 @69 :Bool;
  val113 @70 :Bool;
  val114 @71 :Bool;
  val115 @72 :Bool;
  val0 @73 :UInt64;
  val1 @74 :UInt64;
  val2 @75 :UInt64;
  val4 @76 :UInt64;
  val5 @77 :UInt64;
  val6 @78 :UInt64;
  val7 @79 :UInt64;
  val9 @80 :UInt64;
  val10 @81 :UInt64;
  val11 @82 :UInt64;
  val12 @83 :UInt64;
  val14 @84 :UInt64;
  val15 @85 :UInt64;
  val18 @86 :UInt64;
  val19 @87 :UInt64;
  val20 @88 :UInt64;
  val27 @89 :UInt64;
  val28 @90 :UInt64;
  val29 @91 :UInt64;
  val30 @92 :UInt64;
  val31 @93 :UInt64;
  val32 @94 :UInt64;
  val33 @95 :UInt64;
  val34 @96 :UInt64;
  val35 @97 :UInt64;
  val36 @98 :UInt64;
  val37 @99 :UInt64;
  val38 @100 :UInt64;
  val39 @101 :UInt64;
  val40 @102 :UInt64;
  val41 @103 :UInt64;
  val42 @104 :UInt64;
  val43 @105 :UInt64;
  val44 @106 :UInt64;
  val45 @107 :UInt64;
  val46 @108 :UInt64;
  val47 @109 :UInt64;
  val48 @110 :UInt64;
  val49 @111 :UInt64;
  val50 @112 :UInt64;
  val51 @113 :UInt64;
  val52 @114 :UInt64;
  val56 @115 :UInt64;
}

struct Pseudo @0xa5b20a8972c73a6b {
  val13 @0 :UInt8;
  val17 @1 :UInt8;
  val18 @2 :UInt8;
  val12 @3 :List(UInt64);
  val3 @4 :Bool;
  val4 @5 :Bool;
  val6 @6 :Bool;
  val14 @7 :Bool;
  val15 @8 :Bool;
  val16 @9 :Bool;
  val5 @10 :UInt64;
  val7 @11 :UInt64;
  val8 @12 :UInt64;
  val9 @13 :UInt64;
  val10 @14 :UInt64;
  val11 @15 :UInt64;
  val0 @16 :UInt32;
  val1 @17 :UInt32;
  val2 @18 :UInt32;
}

