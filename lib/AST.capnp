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
  val9 @1 :UInt8;
  val12 @2 :UInt8;
  val43 @3 :UInt8;
  val44 @4 :UInt8;
  val64 @5 :UInt8;
  val68 @6 :UInt8;
  val69 @7 :UInt8;
  val80 @8 :UInt8;
  val84 @9 :UInt8;
  val86 @10 :UInt8;
  val87 @11 :UInt8;
  val88 @12 :UInt8;
  val89 @13 :UInt8;
  val91 @14 :UInt8;
  val92 @15 :UInt8;
  val128 @16 :UInt8;
  val162 @17 :UInt8;
  val3 @18 :List(UInt64);
  val50 @19 :List(UInt64);
  val51 @20 :List(UInt64);
  val61 @21 :List(UInt64);
  val173 @22 :List(UInt64);
  val178 @23 :List(UInt64);
  val182 @24 :List(UInt64);
  val183 @25 :List(UInt64);
  val311 @26 :List(UInt64);
  val337 @27 :List(UInt64);
  val348 @28 :List(UInt64);
  val349 @29 :List(UInt64);
  val359 @30 :List(UInt64);
  val360 @31 :List(UInt64);
  val361 @32 :List(UInt64);
  val362 @33 :List(UInt64);
  val62 @34 :Text;
  val63 @35 :Text;
  val73 @36 :Text;
  val0 @37 :UInt64;
  val1 @38 :UInt64;
  val5 @39 :UInt64;
  val6 @40 :UInt64;
  val7 @41 :UInt64;
  val8 @42 :UInt64;
  val13 @43 :UInt64;
  val45 @44 :UInt64;
  val46 @45 :UInt64;
  val47 @46 :UInt64;
  val48 @47 :UInt64;
  val55 @48 :UInt64;
  val56 @49 :UInt64;
  val57 @50 :UInt64;
  val65 @51 :UInt64;
  val66 @52 :UInt64;
  val67 @53 :UInt64;
  val78 @54 :UInt64;
  val79 @55 :UInt64;
  val81 @56 :UInt64;
  val82 @57 :UInt64;
  val83 @58 :UInt64;
  val85 @59 :UInt64;
  val90 @60 :UInt64;
  val125 @61 :UInt64;
  val126 @62 :UInt64;
  val127 @63 :UInt64;
  val129 @64 :UInt64;
  val130 @65 :UInt64;
  val138 @66 :UInt64;
  val139 @67 :UInt64;
  val161 @68 :UInt64;
  val163 @69 :UInt64;
  val164 @70 :UInt64;
  val174 @71 :UInt64;
  val175 @72 :UInt64;
  val350 @73 :UInt64;
  val354 @74 :UInt64;
  val355 @75 :UInt64;
  val356 @76 :UInt64;
  val357 @77 :UInt64;
  val2 @78 :Bool;
  val11 @79 :Bool;
  val14 @80 :Bool;
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
  val49 @109 :Bool;
  val52 @110 :Bool;
  val53 @111 :Bool;
  val54 @112 :Bool;
  val58 @113 :Bool;
  val59 @114 :Bool;
  val60 @115 :Bool;
  val70 @116 :Bool;
  val71 @117 :Bool;
  val72 @118 :Bool;
  val74 @119 :Bool;
  val75 @120 :Bool;
  val76 @121 :Bool;
  val77 @122 :Bool;
  val93 @123 :Bool;
  val94 @124 :Bool;
  val95 @125 :Bool;
  val96 @126 :Bool;
  val97 @127 :Bool;
  val98 @128 :Bool;
  val99 @129 :Bool;
  val100 @130 :Bool;
  val101 @131 :Bool;
  val102 @132 :Bool;
  val103 @133 :Bool;
  val104 @134 :Bool;
  val105 @135 :Bool;
  val106 @136 :Bool;
  val107 @137 :Bool;
  val108 @138 :Bool;
  val109 @139 :Bool;
  val110 @140 :Bool;
  val111 @141 :Bool;
  val112 @142 :Bool;
  val113 @143 :Bool;
  val114 @144 :Bool;
  val115 @145 :Bool;
  val116 @146 :Bool;
  val117 @147 :Bool;
  val118 @148 :Bool;
  val119 @149 :Bool;
  val120 @150 :Bool;
  val121 @151 :Bool;
  val122 @152 :Bool;
  val123 @153 :Bool;
  val124 @154 :Bool;
  val131 @155 :Bool;
  val132 @156 :Bool;
  val133 @157 :Bool;
  val134 @158 :Bool;
  val135 @159 :Bool;
  val136 @160 :Bool;
  val137 @161 :Bool;
  val140 @162 :Bool;
  val141 @163 :Bool;
  val142 @164 :Bool;
  val143 @165 :Bool;
  val144 @166 :Bool;
  val145 @167 :Bool;
  val146 @168 :Bool;
  val147 @169 :Bool;
  val148 @170 :Bool;
  val149 @171 :Bool;
  val150 @172 :Bool;
  val151 @173 :Bool;
  val152 @174 :Bool;
  val153 @175 :Bool;
  val154 @176 :Bool;
  val155 @177 :Bool;
  val156 @178 :Bool;
  val157 @179 :Bool;
  val158 @180 :Bool;
  val159 @181 :Bool;
  val160 @182 :Bool;
  val165 @183 :Bool;
  val166 @184 :Bool;
  val167 @185 :Bool;
  val168 @186 :Bool;
  val169 @187 :Bool;
  val170 @188 :Bool;
  val171 @189 :Bool;
  val172 @190 :Bool;
  val176 @191 :Bool;
  val177 @192 :Bool;
  val179 @193 :Bool;
  val180 @194 :Bool;
  val181 @195 :Bool;
  val185 @196 :Bool;
  val186 @197 :Bool;
  val187 @198 :Bool;
  val188 @199 :Bool;
  val189 @200 :Bool;
  val190 @201 :Bool;
  val191 @202 :Bool;
  val192 @203 :Bool;
  val193 @204 :Bool;
  val194 @205 :Bool;
  val195 @206 :Bool;
  val196 @207 :Bool;
  val197 @208 :Bool;
  val198 @209 :Bool;
  val199 @210 :Bool;
  val200 @211 :Bool;
  val201 @212 :Bool;
  val202 @213 :Bool;
  val203 @214 :Bool;
  val204 @215 :Bool;
  val205 @216 :Bool;
  val206 @217 :Bool;
  val207 @218 :Bool;
  val208 @219 :Bool;
  val209 @220 :Bool;
  val210 @221 :Bool;
  val211 @222 :Bool;
  val212 @223 :Bool;
  val213 @224 :Bool;
  val214 @225 :Bool;
  val215 @226 :Bool;
  val216 @227 :Bool;
  val217 @228 :Bool;
  val218 @229 :Bool;
  val219 @230 :Bool;
  val220 @231 :Bool;
  val221 @232 :Bool;
  val222 @233 :Bool;
  val223 @234 :Bool;
  val224 @235 :Bool;
  val225 @236 :Bool;
  val226 @237 :Bool;
  val227 @238 :Bool;
  val228 @239 :Bool;
  val229 @240 :Bool;
  val230 @241 :Bool;
  val231 @242 :Bool;
  val232 @243 :Bool;
  val233 @244 :Bool;
  val234 @245 :Bool;
  val235 @246 :Bool;
  val236 @247 :Bool;
  val237 @248 :Bool;
  val238 @249 :Bool;
  val239 @250 :Bool;
  val240 @251 :Bool;
  val241 @252 :Bool;
  val242 @253 :Bool;
  val243 @254 :Bool;
  val244 @255 :Bool;
  val245 @256 :Bool;
  val246 @257 :Bool;
  val247 @258 :Bool;
  val248 @259 :Bool;
  val249 @260 :Bool;
  val250 @261 :Bool;
  val251 @262 :Bool;
  val252 @263 :Bool;
  val253 @264 :Bool;
  val254 @265 :Bool;
  val255 @266 :Bool;
  val256 @267 :Bool;
  val257 @268 :Bool;
  val258 @269 :Bool;
  val259 @270 :Bool;
  val260 @271 :Bool;
  val261 @272 :Bool;
  val262 @273 :Bool;
  val263 @274 :Bool;
  val264 @275 :Bool;
  val265 @276 :Bool;
  val266 @277 :Bool;
  val267 @278 :Bool;
  val268 @279 :Bool;
  val269 @280 :Bool;
  val270 @281 :Bool;
  val271 @282 :Bool;
  val272 @283 :Bool;
  val273 @284 :Bool;
  val274 @285 :Bool;
  val275 @286 :Bool;
  val276 @287 :Bool;
  val277 @288 :Bool;
  val278 @289 :Bool;
  val279 @290 :Bool;
  val280 @291 :Bool;
  val281 @292 :Bool;
  val282 @293 :Bool;
  val283 @294 :Bool;
  val284 @295 :Bool;
  val285 @296 :Bool;
  val286 @297 :Bool;
  val287 @298 :Bool;
  val288 @299 :Bool;
  val289 @300 :Bool;
  val290 @301 :Bool;
  val291 @302 :Bool;
  val292 @303 :Bool;
  val293 @304 :Bool;
  val294 @305 :Bool;
  val295 @306 :Bool;
  val296 @307 :Bool;
  val297 @308 :Bool;
  val298 @309 :Bool;
  val299 @310 :Bool;
  val300 @311 :Bool;
  val301 @312 :Bool;
  val302 @313 :Bool;
  val303 @314 :Bool;
  val304 @315 :Bool;
  val305 @316 :Bool;
  val306 @317 :Bool;
  val307 @318 :Bool;
  val308 @319 :Bool;
  val309 @320 :Bool;
  val310 @321 :Bool;
  val312 @322 :Bool;
  val313 @323 :Bool;
  val314 @324 :Bool;
  val315 @325 :Bool;
  val316 @326 :Bool;
  val317 @327 :Bool;
  val318 @328 :Bool;
  val319 @329 :Bool;
  val320 @330 :Bool;
  val321 @331 :Bool;
  val322 @332 :Bool;
  val323 @333 :Bool;
  val324 @334 :Bool;
  val325 @335 :Bool;
  val326 @336 :Bool;
  val327 @337 :Bool;
  val328 @338 :Bool;
  val329 @339 :Bool;
  val330 @340 :Bool;
  val331 @341 :Bool;
  val332 @342 :Bool;
  val333 @343 :Bool;
  val334 @344 :Bool;
  val335 @345 :Bool;
  val336 @346 :Bool;
  val338 @347 :Bool;
  val339 @348 :Bool;
  val340 @349 :Bool;
  val341 @350 :Bool;
  val342 @351 :Bool;
  val343 @352 :Bool;
  val344 @353 :Bool;
  val345 @354 :Bool;
  val346 @355 :Bool;
  val347 @356 :Bool;
  val351 @357 :Bool;
  val352 @358 :Bool;
  val353 @359 :Bool;
  val358 @360 :Bool;
  val10 @361 :UInt32;
  val184 @362 :UInt32;
}

struct Stmt @0x91127d30fade9a32{
  val100 @0 :UInt32;
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
  val90 @20 :UInt8;
  val92 @21 :UInt8;
  val60 @22 :Text;
  val65 @23 :Text;
  val12 @24 :Bool;
  val16 @25 :Bool;
  val23 @26 :Bool;
  val24 @27 :Bool;
  val25 @28 :Bool;
  val57 @29 :Bool;
  val58 @30 :Bool;
  val59 @31 :Bool;
  val70 @32 :Bool;
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
  val91 @52 :Bool;
  val93 @53 :Bool;
  val94 @54 :Bool;
  val95 @55 :Bool;
  val96 @56 :Bool;
  val97 @57 :Bool;
  val98 @58 :Bool;
  val99 @59 :Bool;
  val0 @60 :UInt64;
  val1 @61 :UInt64;
  val2 @62 :UInt64;
  val3 @63 :UInt64;
  val5 @64 :UInt64;
  val6 @65 :UInt64;
  val8 @66 :UInt64;
  val9 @67 :UInt64;
  val10 @68 :UInt64;
  val11 @69 :UInt64;
  val13 @70 :UInt64;
  val14 @71 :UInt64;
  val17 @72 :UInt64;
  val18 @73 :UInt64;
  val19 @74 :UInt64;
  val20 @75 :UInt64;
  val21 @76 :UInt64;
  val22 @77 :UInt64;
  val30 @78 :UInt64;
  val31 @79 :UInt64;
  val32 @80 :UInt64;
  val33 @81 :UInt64;
  val34 @82 :UInt64;
  val35 @83 :UInt64;
  val36 @84 :UInt64;
  val37 @85 :UInt64;
  val38 @86 :UInt64;
  val39 @87 :UInt64;
  val40 @88 :UInt64;
  val41 @89 :UInt64;
  val42 @90 :UInt64;
  val43 @91 :UInt64;
  val44 @92 :UInt64;
  val45 @93 :UInt64;
  val46 @94 :UInt64;
  val47 @95 :UInt64;
  val48 @96 :UInt64;
  val49 @97 :UInt64;
  val50 @98 :UInt64;
  val51 @99 :UInt64;
  val55 @100 :UInt64;
}

struct Type @0xd739e808bc1b3fd7{
  val68 @0 :UInt16;
  val13 @1 :UInt8;
  val14 @2 :UInt8;
  val16 @3 :UInt8;
  val28 @4 :UInt8;
  val65 @5 :UInt8;
  val66 @6 :UInt8;
  val67 @7 :UInt8;
  val24 @8 :List(UInt64);
  val59 @9 :List(UInt64);
  val62 @10 :List(UInt64);
  val64 @11 :List(UInt64);
  val0 @12 :UInt64;
  val1 @13 :UInt64;
  val3 @14 :UInt64;
  val4 @15 :UInt64;
  val6 @16 :UInt64;
  val15 @17 :UInt64;
  val19 @18 :UInt64;
  val20 @19 :UInt64;
  val26 @20 :UInt64;
  val27 @21 :UInt64;
  val60 @22 :UInt64;
  val61 @23 :UInt64;
  val63 @24 :UInt64;
  val2 @25 :Bool;
  val5 @26 :Bool;
  val7 @27 :Bool;
  val8 @28 :Bool;
  val9 @29 :Bool;
  val10 @30 :Bool;
  val11 @31 :Bool;
  val12 @32 :Bool;
  val17 @33 :Bool;
  val18 @34 :Bool;
  val21 @35 :Bool;
  val22 @36 :Bool;
  val23 @37 :Bool;
  val29 @38 :Bool;
  val30 @39 :Bool;
  val31 @40 :Bool;
  val32 @41 :Bool;
  val33 @42 :Bool;
  val34 @43 :Bool;
  val35 @44 :Bool;
  val36 @45 :Bool;
  val37 @46 :Bool;
  val38 @47 :Bool;
  val39 @48 :Bool;
  val40 @49 :Bool;
  val41 @50 :Bool;
  val42 @51 :Bool;
  val43 @52 :Bool;
  val44 @53 :Bool;
  val45 @54 :Bool;
  val46 @55 :Bool;
  val47 @56 :Bool;
  val48 @57 :Bool;
  val49 @58 :Bool;
  val50 @59 :Bool;
  val51 @60 :Bool;
  val52 @61 :Bool;
  val53 @62 :Bool;
  val54 @63 :Bool;
  val55 @64 :Bool;
  val56 @65 :Bool;
  val57 @66 :Bool;
  val58 @67 :Bool;
  val25 @68 :UInt32;
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
  val12 @0 :List(UInt64);
  val3 @1 :Bool;
  val4 @2 :Bool;
  val5 @3 :Bool;
  val6 @4 :Bool;
  val7 @5 :Bool;
  val13 @6 :Bool;
  val2 @7 :UInt8;
  val0 @8 :UInt64;
  val1 @9 :UInt64;
  val8 @10 :UInt64;
  val9 @11 :UInt64;
  val10 @12 :UInt64;
  val11 @13 :UInt64;
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

struct Designator @0x8fa2d595d812339e{
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

struct CXXCtorInitializer @0x96ba2ce1a1157040{
  val9 @0 :UInt64;
  val10 @1 :UInt64;
  val11 @2 :UInt64;
  val12 @3 :UInt64;
  val13 @4 :UInt64;
  val14 @5 :UInt64;
  val15 @6 :UInt64;
  val16 @7 :UInt64;
  val17 @8 :UInt64;
  val18 @9 :UInt64;
  val0 @10 :Bool;
  val1 @11 :Bool;
  val2 @12 :Bool;
  val3 @13 :Bool;
  val4 @14 :Bool;
  val5 @15 :Bool;
  val6 @16 :Bool;
  val7 @17 :Bool;
  val8 @18 :Bool;
}

