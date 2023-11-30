# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

# Auto-generated file; do not modify!

@0xa04be7b45e95b659;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::ast");

struct Decl @0xef9a64d1b4a7bcff{
  val63 @0 :Text;
  val64 @1 :Text;
  val73 @2 :Text;
  val11 @3 :UInt32;
  val142 @4 :UInt32;
  val190 @5 :UInt32;
  val4 @6 :UInt8;
  val5 @7 :UInt8;
  val10 @8 :UInt8;
  val13 @9 :UInt8;
  val44 @10 :UInt8;
  val45 @11 :UInt8;
  val65 @12 :UInt8;
  val69 @13 :UInt8;
  val70 @14 :UInt8;
  val80 @15 :UInt8;
  val85 @16 :UInt8;
  val87 @17 :UInt8;
  val88 @18 :UInt8;
  val89 @19 :UInt8;
  val90 @20 :UInt8;
  val92 @21 :UInt8;
  val93 @22 :UInt8;
  val131 @23 :UInt8;
  val168 @24 :UInt8;
  val3 @25 :List(UInt64);
  val51 @26 :List(UInt64);
  val52 @27 :List(UInt64);
  val62 @28 :List(UInt64);
  val179 @29 :List(UInt64);
  val187 @30 :List(UInt64);
  val188 @31 :List(UInt64);
  val189 @32 :List(UInt64);
  val315 @33 :List(UInt64);
  val341 @34 :List(UInt64);
  val352 @35 :List(UInt64);
  val353 @36 :List(UInt64);
  val360 @37 :List(UInt64);
  val361 @38 :List(UInt64);
  val362 @39 :List(UInt64);
  val363 @40 :List(UInt64);
  val2 @41 :Bool;
  val12 @42 :Bool;
  val15 @43 :Bool;
  val16 @44 :Bool;
  val17 @45 :Bool;
  val18 @46 :Bool;
  val19 @47 :Bool;
  val20 @48 :Bool;
  val21 @49 :Bool;
  val22 @50 :Bool;
  val23 @51 :Bool;
  val24 @52 :Bool;
  val25 @53 :Bool;
  val26 @54 :Bool;
  val27 @55 :Bool;
  val28 @56 :Bool;
  val29 @57 :Bool;
  val30 @58 :Bool;
  val31 @59 :Bool;
  val32 @60 :Bool;
  val33 @61 :Bool;
  val34 @62 :Bool;
  val35 @63 :Bool;
  val36 @64 :Bool;
  val37 @65 :Bool;
  val38 @66 :Bool;
  val39 @67 :Bool;
  val40 @68 :Bool;
  val41 @69 :Bool;
  val42 @70 :Bool;
  val43 @71 :Bool;
  val50 @72 :Bool;
  val53 @73 :Bool;
  val54 @74 :Bool;
  val55 @75 :Bool;
  val59 @76 :Bool;
  val60 @77 :Bool;
  val61 @78 :Bool;
  val71 @79 :Bool;
  val72 @80 :Bool;
  val74 @81 :Bool;
  val75 @82 :Bool;
  val76 @83 :Bool;
  val77 @84 :Bool;
  val94 @85 :Bool;
  val95 @86 :Bool;
  val96 @87 :Bool;
  val97 @88 :Bool;
  val98 @89 :Bool;
  val99 @90 :Bool;
  val100 @91 :Bool;
  val101 @92 :Bool;
  val102 @93 :Bool;
  val103 @94 :Bool;
  val104 @95 :Bool;
  val105 @96 :Bool;
  val106 @97 :Bool;
  val107 @98 :Bool;
  val108 @99 :Bool;
  val109 @100 :Bool;
  val110 @101 :Bool;
  val111 @102 :Bool;
  val112 @103 :Bool;
  val113 @104 :Bool;
  val114 @105 :Bool;
  val115 @106 :Bool;
  val116 @107 :Bool;
  val117 @108 :Bool;
  val118 @109 :Bool;
  val119 @110 :Bool;
  val120 @111 :Bool;
  val121 @112 :Bool;
  val122 @113 :Bool;
  val123 @114 :Bool;
  val124 @115 :Bool;
  val125 @116 :Bool;
  val126 @117 :Bool;
  val127 @118 :Bool;
  val134 @119 :Bool;
  val135 @120 :Bool;
  val136 @121 :Bool;
  val137 @122 :Bool;
  val138 @123 :Bool;
  val139 @124 :Bool;
  val140 @125 :Bool;
  val145 @126 :Bool;
  val146 @127 :Bool;
  val147 @128 :Bool;
  val148 @129 :Bool;
  val149 @130 :Bool;
  val150 @131 :Bool;
  val151 @132 :Bool;
  val152 @133 :Bool;
  val153 @134 :Bool;
  val154 @135 :Bool;
  val155 @136 :Bool;
  val156 @137 :Bool;
  val157 @138 :Bool;
  val158 @139 :Bool;
  val159 @140 :Bool;
  val160 @141 :Bool;
  val161 @142 :Bool;
  val162 @143 :Bool;
  val163 @144 :Bool;
  val164 @145 :Bool;
  val165 @146 :Bool;
  val166 @147 :Bool;
  val171 @148 :Bool;
  val172 @149 :Bool;
  val173 @150 :Bool;
  val174 @151 :Bool;
  val175 @152 :Bool;
  val176 @153 :Bool;
  val177 @154 :Bool;
  val178 @155 :Bool;
  val182 @156 :Bool;
  val183 @157 :Bool;
  val184 @158 :Bool;
  val185 @159 :Bool;
  val186 @160 :Bool;
  val191 @161 :Bool;
  val192 @162 :Bool;
  val193 @163 :Bool;
  val194 @164 :Bool;
  val195 @165 :Bool;
  val196 @166 :Bool;
  val197 @167 :Bool;
  val198 @168 :Bool;
  val199 @169 :Bool;
  val200 @170 :Bool;
  val201 @171 :Bool;
  val202 @172 :Bool;
  val203 @173 :Bool;
  val204 @174 :Bool;
  val205 @175 :Bool;
  val206 @176 :Bool;
  val207 @177 :Bool;
  val208 @178 :Bool;
  val209 @179 :Bool;
  val210 @180 :Bool;
  val211 @181 :Bool;
  val212 @182 :Bool;
  val213 @183 :Bool;
  val214 @184 :Bool;
  val215 @185 :Bool;
  val216 @186 :Bool;
  val217 @187 :Bool;
  val218 @188 :Bool;
  val219 @189 :Bool;
  val220 @190 :Bool;
  val221 @191 :Bool;
  val222 @192 :Bool;
  val223 @193 :Bool;
  val224 @194 :Bool;
  val225 @195 :Bool;
  val226 @196 :Bool;
  val227 @197 :Bool;
  val228 @198 :Bool;
  val229 @199 :Bool;
  val230 @200 :Bool;
  val231 @201 :Bool;
  val232 @202 :Bool;
  val233 @203 :Bool;
  val234 @204 :Bool;
  val235 @205 :Bool;
  val236 @206 :Bool;
  val237 @207 :Bool;
  val238 @208 :Bool;
  val239 @209 :Bool;
  val240 @210 :Bool;
  val241 @211 :Bool;
  val242 @212 :Bool;
  val243 @213 :Bool;
  val244 @214 :Bool;
  val245 @215 :Bool;
  val246 @216 :Bool;
  val247 @217 :Bool;
  val248 @218 :Bool;
  val249 @219 :Bool;
  val250 @220 :Bool;
  val251 @221 :Bool;
  val252 @222 :Bool;
  val253 @223 :Bool;
  val254 @224 :Bool;
  val255 @225 :Bool;
  val256 @226 :Bool;
  val257 @227 :Bool;
  val258 @228 :Bool;
  val259 @229 :Bool;
  val260 @230 :Bool;
  val261 @231 :Bool;
  val262 @232 :Bool;
  val263 @233 :Bool;
  val264 @234 :Bool;
  val265 @235 :Bool;
  val266 @236 :Bool;
  val267 @237 :Bool;
  val268 @238 :Bool;
  val269 @239 :Bool;
  val270 @240 :Bool;
  val271 @241 :Bool;
  val272 @242 :Bool;
  val273 @243 :Bool;
  val274 @244 :Bool;
  val275 @245 :Bool;
  val276 @246 :Bool;
  val277 @247 :Bool;
  val278 @248 :Bool;
  val279 @249 :Bool;
  val280 @250 :Bool;
  val281 @251 :Bool;
  val282 @252 :Bool;
  val283 @253 :Bool;
  val284 @254 :Bool;
  val285 @255 :Bool;
  val286 @256 :Bool;
  val287 @257 :Bool;
  val288 @258 :Bool;
  val289 @259 :Bool;
  val290 @260 :Bool;
  val291 @261 :Bool;
  val292 @262 :Bool;
  val293 @263 :Bool;
  val294 @264 :Bool;
  val295 @265 :Bool;
  val296 @266 :Bool;
  val297 @267 :Bool;
  val298 @268 :Bool;
  val299 @269 :Bool;
  val300 @270 :Bool;
  val301 @271 :Bool;
  val302 @272 :Bool;
  val303 @273 :Bool;
  val304 @274 :Bool;
  val305 @275 :Bool;
  val306 @276 :Bool;
  val307 @277 :Bool;
  val308 @278 :Bool;
  val309 @279 :Bool;
  val310 @280 :Bool;
  val311 @281 :Bool;
  val312 @282 :Bool;
  val313 @283 :Bool;
  val314 @284 :Bool;
  val316 @285 :Bool;
  val317 @286 :Bool;
  val318 @287 :Bool;
  val319 @288 :Bool;
  val320 @289 :Bool;
  val321 @290 :Bool;
  val322 @291 :Bool;
  val323 @292 :Bool;
  val324 @293 :Bool;
  val325 @294 :Bool;
  val326 @295 :Bool;
  val327 @296 :Bool;
  val328 @297 :Bool;
  val329 @298 :Bool;
  val330 @299 :Bool;
  val331 @300 :Bool;
  val332 @301 :Bool;
  val333 @302 :Bool;
  val334 @303 :Bool;
  val335 @304 :Bool;
  val336 @305 :Bool;
  val337 @306 :Bool;
  val338 @307 :Bool;
  val339 @308 :Bool;
  val340 @309 :Bool;
  val342 @310 :Bool;
  val343 @311 :Bool;
  val344 @312 :Bool;
  val345 @313 :Bool;
  val346 @314 :Bool;
  val347 @315 :Bool;
  val348 @316 :Bool;
  val349 @317 :Bool;
  val350 @318 :Bool;
  val351 @319 :Bool;
  val354 @320 :Bool;
  val355 @321 :Bool;
  val356 @322 :Bool;
  val359 @323 :Bool;
  val0 @324 :UInt64;
  val1 @325 :UInt64;
  val6 @326 :UInt64;
  val7 @327 :UInt64;
  val8 @328 :UInt64;
  val9 @329 :UInt64;
  val14 @330 :UInt64;
  val46 @331 :UInt64;
  val47 @332 :UInt64;
  val48 @333 :UInt64;
  val49 @334 :UInt64;
  val56 @335 :UInt64;
  val57 @336 :UInt64;
  val58 @337 :UInt64;
  val66 @338 :UInt64;
  val67 @339 :UInt64;
  val68 @340 :UInt64;
  val78 @341 :UInt64;
  val79 @342 :UInt64;
  val81 @343 :UInt64;
  val82 @344 :UInt64;
  val83 @345 :UInt64;
  val84 @346 :UInt64;
  val86 @347 :UInt64;
  val91 @348 :UInt64;
  val128 @349 :UInt64;
  val129 @350 :UInt64;
  val130 @351 :UInt64;
  val132 @352 :UInt64;
  val133 @353 :UInt64;
  val141 @354 :UInt64;
  val143 @355 :UInt64;
  val144 @356 :UInt64;
  val167 @357 :UInt64;
  val169 @358 :UInt64;
  val170 @359 :UInt64;
  val180 @360 :UInt64;
  val181 @361 :UInt64;
  val357 @362 :UInt64;
  val358 @363 :UInt64;
}

struct Stmt @0x9eb7852034fb27d4{
  val105 @0 :UInt32;
  val61 @1 :List(Text);
  val62 @2 :List(Text);
  val63 @3 :List(Text);
  val64 @4 :List(Text);
  val66 @5 :List(Text);
  val68 @6 :List(Text);
  val60 @7 :Text;
  val65 @8 :Text;
  val12 @9 :Bool;
  val16 @10 :Bool;
  val23 @11 :Bool;
  val24 @12 :Bool;
  val25 @13 :Bool;
  val57 @14 :Bool;
  val58 @15 :Bool;
  val59 @16 :Bool;
  val71 @17 :Bool;
  val72 @18 :Bool;
  val73 @19 :Bool;
  val74 @20 :Bool;
  val75 @21 :Bool;
  val76 @22 :Bool;
  val77 @23 :Bool;
  val78 @24 :Bool;
  val79 @25 :Bool;
  val80 @26 :Bool;
  val81 @27 :Bool;
  val82 @28 :Bool;
  val83 @29 :Bool;
  val84 @30 :Bool;
  val85 @31 :Bool;
  val86 @32 :Bool;
  val87 @33 :Bool;
  val88 @34 :Bool;
  val89 @35 :Bool;
  val90 @36 :Bool;
  val91 @37 :Bool;
  val92 @38 :Bool;
  val93 @39 :Bool;
  val94 @40 :Bool;
  val96 @41 :Bool;
  val98 @42 :Bool;
  val99 @43 :Bool;
  val100 @44 :Bool;
  val101 @45 :Bool;
  val102 @46 :Bool;
  val103 @47 :Bool;
  val104 @48 :Bool;
  val7 @49 :UInt8;
  val56 @50 :UInt8;
  val69 @51 :UInt8;
  val70 @52 :UInt8;
  val95 @53 :UInt8;
  val97 @54 :UInt8;
  val4 @55 :List(UInt64);
  val15 @56 :List(UInt64);
  val26 @57 :List(UInt64);
  val27 @58 :List(UInt64);
  val28 @59 :List(UInt64);
  val29 @60 :List(UInt64);
  val52 @61 :List(UInt64);
  val53 @62 :List(UInt64);
  val54 @63 :List(UInt64);
  val67 @64 :List(UInt64);
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

struct Type @0xd867d86f4cc1f3be{
  val70 @0 :UInt16;
  val27 @1 :UInt32;
  val26 @2 :List(UInt64);
  val61 @3 :List(UInt64);
  val64 @4 :List(UInt64);
  val66 @5 :List(UInt64);
  val14 @6 :UInt8;
  val15 @7 :UInt8;
  val17 @8 :UInt8;
  val30 @9 :UInt8;
  val67 @10 :UInt8;
  val68 @11 :UInt8;
  val69 @12 :UInt8;
  val2 @13 :Bool;
  val5 @14 :Bool;
  val7 @15 :Bool;
  val8 @16 :Bool;
  val9 @17 :Bool;
  val10 @18 :Bool;
  val11 @19 :Bool;
  val12 @20 :Bool;
  val18 @21 :Bool;
  val19 @22 :Bool;
  val20 @23 :Bool;
  val23 @24 :Bool;
  val24 @25 :Bool;
  val25 @26 :Bool;
  val31 @27 :Bool;
  val32 @28 :Bool;
  val33 @29 :Bool;
  val34 @30 :Bool;
  val35 @31 :Bool;
  val36 @32 :Bool;
  val37 @33 :Bool;
  val38 @34 :Bool;
  val39 @35 :Bool;
  val40 @36 :Bool;
  val41 @37 :Bool;
  val42 @38 :Bool;
  val43 @39 :Bool;
  val44 @40 :Bool;
  val45 @41 :Bool;
  val46 @42 :Bool;
  val47 @43 :Bool;
  val48 @44 :Bool;
  val49 @45 :Bool;
  val50 @46 :Bool;
  val51 @47 :Bool;
  val52 @48 :Bool;
  val53 @49 :Bool;
  val54 @50 :Bool;
  val55 @51 :Bool;
  val56 @52 :Bool;
  val57 @53 :Bool;
  val58 @54 :Bool;
  val59 @55 :Bool;
  val60 @56 :Bool;
  val0 @57 :UInt64;
  val1 @58 :UInt64;
  val3 @59 :UInt64;
  val4 @60 :UInt64;
  val6 @61 :UInt64;
  val13 @62 :UInt64;
  val16 @63 :UInt64;
  val21 @64 :UInt64;
  val22 @65 :UInt64;
  val28 @66 :UInt64;
  val29 @67 :UInt64;
  val62 @68 :UInt64;
  val63 @69 :UInt64;
  val65 @70 :UInt64;
}

struct Attr @0xdc4122d52efb837d{
  val20 @0 :UInt32;
  val10 @1 :UInt8;
  val14 @2 :UInt8;
  val15 @3 :UInt8;
  val9 @4 :Text;
  val17 @5 :Text;
  val18 @6 :Text;
  val5 @7 :UInt16;
  val1 @8 :Bool;
  val2 @9 :Bool;
  val3 @10 :Bool;
  val4 @11 :Bool;
  val11 @12 :Bool;
  val12 @13 :Bool;
  val13 @14 :Bool;
  val19 @15 :Bool;
  val21 @16 :Bool;
  val22 @17 :Bool;
  val23 @18 :Bool;
  val24 @19 :Bool;
  val25 @20 :Bool;
  val0 @21 :UInt64;
  val6 @22 :UInt64;
  val7 @23 :UInt64;
  val8 @24 :UInt64;
  val16 @25 :UInt64;
}

struct Macro @0xf231a64b583a84a9{
  val12 @0 :UInt32;
  val3 @1 :Bool;
  val13 @2 :Bool;
  val2 @3 :List(UInt64);
  val4 @4 :List(UInt64);
  val9 @5 :List(UInt64);
  val10 @6 :List(UInt64);
  val1 @7 :UInt64;
  val5 @8 :UInt64;
  val6 @9 :UInt64;
  val7 @10 :UInt64;
  val8 @11 :UInt64;
  val11 @12 :UInt64;
  val0 @13 :UInt8;
}

struct TemplateArgument @0xdf52497060e3a0c9{
  val3 @0 :Bool;
  val4 @1 :Bool;
  val5 @2 :Bool;
  val6 @3 :Bool;
  val7 @4 :Bool;
  val2 @5 :UInt8;
  val0 @6 :UInt64;
  val1 @7 :UInt64;
  val8 @8 :UInt64;
  val9 @9 :UInt64;
  val10 @10 :UInt64;
  val11 @11 :UInt64;
}

struct TemplateParameterList @0xd46761f28f76341d{
  val9 @0 :List(UInt64);
  val3 @1 :UInt64;
  val4 @2 :UInt64;
  val5 @3 :UInt64;
  val6 @4 :UInt64;
  val7 @5 :UInt64;
  val8 @6 :UInt64;
  val1 @7 :Bool;
  val2 @8 :Bool;
  val0 @9 :UInt32;
}

struct CXXBaseSpecifier @0xe64f2324009d801a{
  val5 @0 :UInt8;
  val9 @1 :UInt8;
  val10 @2 :UInt8;
  val4 @3 :Bool;
  val6 @4 :Bool;
  val7 @5 :Bool;
  val0 @6 :UInt64;
  val1 @7 :UInt64;
  val2 @8 :UInt64;
  val3 @9 :UInt64;
  val8 @10 :UInt64;
  val11 @11 :UInt64;
}

struct Designator @0xa35e80c8a0ccb419{
  val2 @0 :Bool;
  val3 @1 :Bool;
  val4 @2 :Bool;
  val0 @3 :UInt64;
  val1 @4 :UInt64;
  val5 @5 :UInt64;
  val6 @6 :UInt64;
  val7 @7 :UInt64;
  val8 @8 :UInt64;
  val9 @9 :UInt64;
  val10 @10 :UInt64;
  val11 @11 :UInt64;
  val12 @12 :UInt64;
}

