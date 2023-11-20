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
  val44 @4 :UInt8;
  val45 @5 :UInt8;
  val65 @6 :UInt8;
  val69 @7 :UInt8;
  val70 @8 :UInt8;
  val80 @9 :UInt8;
  val85 @10 :UInt8;
  val87 @11 :UInt8;
  val88 @12 :UInt8;
  val89 @13 :UInt8;
  val90 @14 :UInt8;
  val92 @15 :UInt8;
  val93 @16 :UInt8;
  val131 @17 :UInt8;
  val168 @18 :UInt8;
  val3 @19 :List(UInt64);
  val51 @20 :List(UInt64);
  val52 @21 :List(UInt64);
  val62 @22 :List(UInt64);
  val179 @23 :List(UInt64);
  val187 @24 :List(UInt64);
  val188 @25 :List(UInt64);
  val189 @26 :List(UInt64);
  val315 @27 :List(UInt64);
  val341 @28 :List(UInt64);
  val352 @29 :List(UInt64);
  val353 @30 :List(UInt64);
  val360 @31 :List(UInt64);
  val361 @32 :List(UInt64);
  val362 @33 :List(UInt64);
  val363 @34 :List(UInt64);
  val63 @35 :Text;
  val64 @36 :Text;
  val73 @37 :Text;
  val0 @38 :UInt64;
  val1 @39 :UInt64;
  val6 @40 :UInt64;
  val7 @41 :UInt64;
  val8 @42 :UInt64;
  val9 @43 :UInt64;
  val14 @44 :UInt64;
  val46 @45 :UInt64;
  val47 @46 :UInt64;
  val48 @47 :UInt64;
  val49 @48 :UInt64;
  val56 @49 :UInt64;
  val57 @50 :UInt64;
  val58 @51 :UInt64;
  val66 @52 :UInt64;
  val67 @53 :UInt64;
  val68 @54 :UInt64;
  val78 @55 :UInt64;
  val79 @56 :UInt64;
  val81 @57 :UInt64;
  val82 @58 :UInt64;
  val83 @59 :UInt64;
  val84 @60 :UInt64;
  val86 @61 :UInt64;
  val91 @62 :UInt64;
  val128 @63 :UInt64;
  val129 @64 :UInt64;
  val130 @65 :UInt64;
  val132 @66 :UInt64;
  val133 @67 :UInt64;
  val141 @68 :UInt64;
  val143 @69 :UInt64;
  val144 @70 :UInt64;
  val167 @71 :UInt64;
  val169 @72 :UInt64;
  val170 @73 :UInt64;
  val180 @74 :UInt64;
  val181 @75 :UInt64;
  val357 @76 :UInt64;
  val358 @77 :UInt64;
  val2 @78 :Bool;
  val12 @79 :Bool;
  val15 @80 :Bool;
  val16 @81 :Bool;
  val17 @82 :Bool;
  val18 @83 :Bool;
  val19 @84 :Bool;
  val20 @85 :Bool;
  val21 @86 :Bool;
  val22 @87 :Bool;
  val23 @88 :Bool;
  val24 @89 :Bool;
  val25 @90 :Bool;
  val26 @91 :Bool;
  val27 @92 :Bool;
  val28 @93 :Bool;
  val29 @94 :Bool;
  val30 @95 :Bool;
  val31 @96 :Bool;
  val32 @97 :Bool;
  val33 @98 :Bool;
  val34 @99 :Bool;
  val35 @100 :Bool;
  val36 @101 :Bool;
  val37 @102 :Bool;
  val38 @103 :Bool;
  val39 @104 :Bool;
  val40 @105 :Bool;
  val41 @106 :Bool;
  val42 @107 :Bool;
  val43 @108 :Bool;
  val50 @109 :Bool;
  val53 @110 :Bool;
  val54 @111 :Bool;
  val55 @112 :Bool;
  val59 @113 :Bool;
  val60 @114 :Bool;
  val61 @115 :Bool;
  val71 @116 :Bool;
  val72 @117 :Bool;
  val74 @118 :Bool;
  val75 @119 :Bool;
  val76 @120 :Bool;
  val77 @121 :Bool;
  val94 @122 :Bool;
  val95 @123 :Bool;
  val96 @124 :Bool;
  val97 @125 :Bool;
  val98 @126 :Bool;
  val99 @127 :Bool;
  val100 @128 :Bool;
  val101 @129 :Bool;
  val102 @130 :Bool;
  val103 @131 :Bool;
  val104 @132 :Bool;
  val105 @133 :Bool;
  val106 @134 :Bool;
  val107 @135 :Bool;
  val108 @136 :Bool;
  val109 @137 :Bool;
  val110 @138 :Bool;
  val111 @139 :Bool;
  val112 @140 :Bool;
  val113 @141 :Bool;
  val114 @142 :Bool;
  val115 @143 :Bool;
  val116 @144 :Bool;
  val117 @145 :Bool;
  val118 @146 :Bool;
  val119 @147 :Bool;
  val120 @148 :Bool;
  val121 @149 :Bool;
  val122 @150 :Bool;
  val123 @151 :Bool;
  val124 @152 :Bool;
  val125 @153 :Bool;
  val126 @154 :Bool;
  val127 @155 :Bool;
  val134 @156 :Bool;
  val135 @157 :Bool;
  val136 @158 :Bool;
  val137 @159 :Bool;
  val138 @160 :Bool;
  val139 @161 :Bool;
  val140 @162 :Bool;
  val145 @163 :Bool;
  val146 @164 :Bool;
  val147 @165 :Bool;
  val148 @166 :Bool;
  val149 @167 :Bool;
  val150 @168 :Bool;
  val151 @169 :Bool;
  val152 @170 :Bool;
  val153 @171 :Bool;
  val154 @172 :Bool;
  val155 @173 :Bool;
  val156 @174 :Bool;
  val157 @175 :Bool;
  val158 @176 :Bool;
  val159 @177 :Bool;
  val160 @178 :Bool;
  val161 @179 :Bool;
  val162 @180 :Bool;
  val163 @181 :Bool;
  val164 @182 :Bool;
  val165 @183 :Bool;
  val166 @184 :Bool;
  val171 @185 :Bool;
  val172 @186 :Bool;
  val173 @187 :Bool;
  val174 @188 :Bool;
  val175 @189 :Bool;
  val176 @190 :Bool;
  val177 @191 :Bool;
  val178 @192 :Bool;
  val182 @193 :Bool;
  val183 @194 :Bool;
  val184 @195 :Bool;
  val185 @196 :Bool;
  val186 @197 :Bool;
  val191 @198 :Bool;
  val192 @199 :Bool;
  val193 @200 :Bool;
  val194 @201 :Bool;
  val195 @202 :Bool;
  val196 @203 :Bool;
  val197 @204 :Bool;
  val198 @205 :Bool;
  val199 @206 :Bool;
  val200 @207 :Bool;
  val201 @208 :Bool;
  val202 @209 :Bool;
  val203 @210 :Bool;
  val204 @211 :Bool;
  val205 @212 :Bool;
  val206 @213 :Bool;
  val207 @214 :Bool;
  val208 @215 :Bool;
  val209 @216 :Bool;
  val210 @217 :Bool;
  val211 @218 :Bool;
  val212 @219 :Bool;
  val213 @220 :Bool;
  val214 @221 :Bool;
  val215 @222 :Bool;
  val216 @223 :Bool;
  val217 @224 :Bool;
  val218 @225 :Bool;
  val219 @226 :Bool;
  val220 @227 :Bool;
  val221 @228 :Bool;
  val222 @229 :Bool;
  val223 @230 :Bool;
  val224 @231 :Bool;
  val225 @232 :Bool;
  val226 @233 :Bool;
  val227 @234 :Bool;
  val228 @235 :Bool;
  val229 @236 :Bool;
  val230 @237 :Bool;
  val231 @238 :Bool;
  val232 @239 :Bool;
  val233 @240 :Bool;
  val234 @241 :Bool;
  val235 @242 :Bool;
  val236 @243 :Bool;
  val237 @244 :Bool;
  val238 @245 :Bool;
  val239 @246 :Bool;
  val240 @247 :Bool;
  val241 @248 :Bool;
  val242 @249 :Bool;
  val243 @250 :Bool;
  val244 @251 :Bool;
  val245 @252 :Bool;
  val246 @253 :Bool;
  val247 @254 :Bool;
  val248 @255 :Bool;
  val249 @256 :Bool;
  val250 @257 :Bool;
  val251 @258 :Bool;
  val252 @259 :Bool;
  val253 @260 :Bool;
  val254 @261 :Bool;
  val255 @262 :Bool;
  val256 @263 :Bool;
  val257 @264 :Bool;
  val258 @265 :Bool;
  val259 @266 :Bool;
  val260 @267 :Bool;
  val261 @268 :Bool;
  val262 @269 :Bool;
  val263 @270 :Bool;
  val264 @271 :Bool;
  val265 @272 :Bool;
  val266 @273 :Bool;
  val267 @274 :Bool;
  val268 @275 :Bool;
  val269 @276 :Bool;
  val270 @277 :Bool;
  val271 @278 :Bool;
  val272 @279 :Bool;
  val273 @280 :Bool;
  val274 @281 :Bool;
  val275 @282 :Bool;
  val276 @283 :Bool;
  val277 @284 :Bool;
  val278 @285 :Bool;
  val279 @286 :Bool;
  val280 @287 :Bool;
  val281 @288 :Bool;
  val282 @289 :Bool;
  val283 @290 :Bool;
  val284 @291 :Bool;
  val285 @292 :Bool;
  val286 @293 :Bool;
  val287 @294 :Bool;
  val288 @295 :Bool;
  val289 @296 :Bool;
  val290 @297 :Bool;
  val291 @298 :Bool;
  val292 @299 :Bool;
  val293 @300 :Bool;
  val294 @301 :Bool;
  val295 @302 :Bool;
  val296 @303 :Bool;
  val297 @304 :Bool;
  val298 @305 :Bool;
  val299 @306 :Bool;
  val300 @307 :Bool;
  val301 @308 :Bool;
  val302 @309 :Bool;
  val303 @310 :Bool;
  val304 @311 :Bool;
  val305 @312 :Bool;
  val306 @313 :Bool;
  val307 @314 :Bool;
  val308 @315 :Bool;
  val309 @316 :Bool;
  val310 @317 :Bool;
  val311 @318 :Bool;
  val312 @319 :Bool;
  val313 @320 :Bool;
  val314 @321 :Bool;
  val316 @322 :Bool;
  val317 @323 :Bool;
  val318 @324 :Bool;
  val319 @325 :Bool;
  val320 @326 :Bool;
  val321 @327 :Bool;
  val322 @328 :Bool;
  val323 @329 :Bool;
  val324 @330 :Bool;
  val325 @331 :Bool;
  val326 @332 :Bool;
  val327 @333 :Bool;
  val328 @334 :Bool;
  val329 @335 :Bool;
  val330 @336 :Bool;
  val331 @337 :Bool;
  val332 @338 :Bool;
  val333 @339 :Bool;
  val334 @340 :Bool;
  val335 @341 :Bool;
  val336 @342 :Bool;
  val337 @343 :Bool;
  val338 @344 :Bool;
  val339 @345 :Bool;
  val340 @346 :Bool;
  val342 @347 :Bool;
  val343 @348 :Bool;
  val344 @349 :Bool;
  val345 @350 :Bool;
  val346 @351 :Bool;
  val347 @352 :Bool;
  val348 @353 :Bool;
  val349 @354 :Bool;
  val350 @355 :Bool;
  val351 @356 :Bool;
  val354 @357 :Bool;
  val355 @358 :Bool;
  val356 @359 :Bool;
  val359 @360 :Bool;
  val11 @361 :UInt32;
  val142 @362 :UInt32;
  val190 @363 :UInt32;
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
  val67 @0 :UInt16;
  val13 @1 :UInt8;
  val14 @2 :UInt8;
  val16 @3 :UInt8;
  val27 @4 :UInt8;
  val64 @5 :UInt8;
  val65 @6 :UInt8;
  val66 @7 :UInt8;
  val23 @8 :List(UInt64);
  val58 @9 :List(UInt64);
  val61 @10 :List(UInt64);
  val63 @11 :List(UInt64);
  val0 @12 :UInt64;
  val1 @13 :UInt64;
  val3 @14 :UInt64;
  val4 @15 :UInt64;
  val6 @16 :UInt64;
  val15 @17 :UInt64;
  val18 @18 :UInt64;
  val19 @19 :UInt64;
  val25 @20 :UInt64;
  val26 @21 :UInt64;
  val59 @22 :UInt64;
  val60 @23 :UInt64;
  val62 @24 :UInt64;
  val2 @25 :Bool;
  val5 @26 :Bool;
  val7 @27 :Bool;
  val8 @28 :Bool;
  val9 @29 :Bool;
  val10 @30 :Bool;
  val11 @31 :Bool;
  val12 @32 :Bool;
  val17 @33 :Bool;
  val20 @34 :Bool;
  val21 @35 :Bool;
  val22 @36 :Bool;
  val28 @37 :Bool;
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
  val24 @67 :UInt32;
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

