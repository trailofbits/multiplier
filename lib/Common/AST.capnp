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
  val74 @0 :List(UInt32);
  val136 @1 :List(UInt32);
  val137 @2 :List(UInt32);
  val339 @3 :List(UInt32);
  val340 @4 :List(UInt32);
  val4 @5 :UInt8;
  val5 @6 :UInt8;
  val10 @7 :UInt8;
  val11 @8 :UInt8;
  val39 @9 :UInt8;
  val40 @10 :UInt8;
  val60 @11 :UInt8;
  val64 @12 :UInt8;
  val65 @13 :UInt8;
  val73 @14 :UInt8;
  val78 @15 :UInt8;
  val80 @16 :UInt8;
  val81 @17 :UInt8;
  val82 @18 :UInt8;
  val83 @19 :UInt8;
  val85 @20 :UInt8;
  val86 @21 :UInt8;
  val122 @22 :UInt8;
  val126 @23 :UInt8;
  val3 @24 :List(UInt64);
  val46 @25 :List(UInt64);
  val47 @26 :List(UInt64);
  val57 @27 :List(UInt64);
  val168 @28 :List(UInt64);
  val176 @29 :List(UInt64);
  val312 @30 :List(UInt64);
  val344 @31 :List(UInt64);
  val345 @32 :List(UInt64);
  val346 @33 :List(UInt64);
  val347 @34 :List(UInt64);
  val348 @35 :List(UInt64);
  val349 @36 :List(UInt64);
  val350 @37 :List(UInt64);
  val351 @38 :List(UInt64);
  val352 @39 :List(UInt64);
  val58 @40 :Text;
  val59 @41 :Text;
  val68 @42 :Text;
  val0 @43 :UInt64;
  val1 @44 :UInt64;
  val6 @45 :UInt64;
  val9 @46 :UInt64;
  val12 @47 :UInt64;
  val41 @48 :UInt64;
  val42 @49 :UInt64;
  val43 @50 :UInt64;
  val44 @51 :UInt64;
  val51 @52 :UInt64;
  val52 @53 :UInt64;
  val53 @54 :UInt64;
  val61 @55 :UInt64;
  val62 @56 :UInt64;
  val63 @57 :UInt64;
  val72 @58 :UInt64;
  val75 @59 :UInt64;
  val76 @60 :UInt64;
  val77 @61 :UInt64;
  val79 @62 :UInt64;
  val84 @63 :UInt64;
  val123 @64 :UInt64;
  val124 @65 :UInt64;
  val125 @66 :UInt64;
  val127 @67 :UInt64;
  val128 @68 :UInt64;
  val139 @69 :UInt64;
  val140 @70 :UInt64;
  val141 @71 :UInt64;
  val157 @72 :UInt64;
  val158 @73 :UInt64;
  val159 @74 :UInt64;
  val169 @75 :UInt64;
  val170 @76 :UInt64;
  val2 @77 :Bool;
  val8 @78 :Bool;
  val13 @79 :Bool;
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
  val45 @105 :Bool;
  val48 @106 :Bool;
  val49 @107 :Bool;
  val50 @108 :Bool;
  val54 @109 :Bool;
  val55 @110 :Bool;
  val56 @111 :Bool;
  val66 @112 :Bool;
  val67 @113 :Bool;
  val69 @114 :Bool;
  val70 @115 :Bool;
  val71 @116 :Bool;
  val87 @117 :Bool;
  val88 @118 :Bool;
  val89 @119 :Bool;
  val90 @120 :Bool;
  val91 @121 :Bool;
  val92 @122 :Bool;
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
  val129 @152 :Bool;
  val130 @153 :Bool;
  val131 @154 :Bool;
  val132 @155 :Bool;
  val133 @156 :Bool;
  val134 @157 :Bool;
  val135 @158 :Bool;
  val142 @159 :Bool;
  val143 @160 :Bool;
  val144 @161 :Bool;
  val145 @162 :Bool;
  val146 @163 :Bool;
  val147 @164 :Bool;
  val148 @165 :Bool;
  val149 @166 :Bool;
  val150 @167 :Bool;
  val151 @168 :Bool;
  val152 @169 :Bool;
  val153 @170 :Bool;
  val154 @171 :Bool;
  val155 @172 :Bool;
  val156 @173 :Bool;
  val160 @174 :Bool;
  val161 @175 :Bool;
  val162 @176 :Bool;
  val163 @177 :Bool;
  val164 @178 :Bool;
  val165 @179 :Bool;
  val166 @180 :Bool;
  val167 @181 :Bool;
  val171 @182 :Bool;
  val172 @183 :Bool;
  val173 @184 :Bool;
  val174 @185 :Bool;
  val175 @186 :Bool;
  val181 @187 :Bool;
  val182 @188 :Bool;
  val183 @189 :Bool;
  val184 @190 :Bool;
  val185 @191 :Bool;
  val186 @192 :Bool;
  val187 @193 :Bool;
  val188 @194 :Bool;
  val189 @195 :Bool;
  val190 @196 :Bool;
  val191 @197 :Bool;
  val192 @198 :Bool;
  val193 @199 :Bool;
  val194 @200 :Bool;
  val195 @201 :Bool;
  val196 @202 :Bool;
  val197 @203 :Bool;
  val198 @204 :Bool;
  val199 @205 :Bool;
  val200 @206 :Bool;
  val201 @207 :Bool;
  val202 @208 :Bool;
  val203 @209 :Bool;
  val204 @210 :Bool;
  val205 @211 :Bool;
  val206 @212 :Bool;
  val207 @213 :Bool;
  val208 @214 :Bool;
  val209 @215 :Bool;
  val210 @216 :Bool;
  val211 @217 :Bool;
  val212 @218 :Bool;
  val213 @219 :Bool;
  val214 @220 :Bool;
  val215 @221 :Bool;
  val216 @222 :Bool;
  val217 @223 :Bool;
  val218 @224 :Bool;
  val219 @225 :Bool;
  val220 @226 :Bool;
  val221 @227 :Bool;
  val222 @228 :Bool;
  val223 @229 :Bool;
  val224 @230 :Bool;
  val225 @231 :Bool;
  val226 @232 :Bool;
  val227 @233 :Bool;
  val228 @234 :Bool;
  val229 @235 :Bool;
  val230 @236 :Bool;
  val231 @237 :Bool;
  val232 @238 :Bool;
  val233 @239 :Bool;
  val234 @240 :Bool;
  val235 @241 :Bool;
  val236 @242 :Bool;
  val237 @243 :Bool;
  val238 @244 :Bool;
  val239 @245 :Bool;
  val240 @246 :Bool;
  val241 @247 :Bool;
  val242 @248 :Bool;
  val243 @249 :Bool;
  val244 @250 :Bool;
  val245 @251 :Bool;
  val246 @252 :Bool;
  val247 @253 :Bool;
  val248 @254 :Bool;
  val249 @255 :Bool;
  val250 @256 :Bool;
  val251 @257 :Bool;
  val252 @258 :Bool;
  val253 @259 :Bool;
  val254 @260 :Bool;
  val255 @261 :Bool;
  val256 @262 :Bool;
  val257 @263 :Bool;
  val258 @264 :Bool;
  val259 @265 :Bool;
  val260 @266 :Bool;
  val261 @267 :Bool;
  val262 @268 :Bool;
  val263 @269 :Bool;
  val264 @270 :Bool;
  val265 @271 :Bool;
  val266 @272 :Bool;
  val267 @273 :Bool;
  val268 @274 :Bool;
  val269 @275 :Bool;
  val270 @276 :Bool;
  val271 @277 :Bool;
  val272 @278 :Bool;
  val273 @279 :Bool;
  val274 @280 :Bool;
  val275 @281 :Bool;
  val276 @282 :Bool;
  val277 @283 :Bool;
  val278 @284 :Bool;
  val279 @285 :Bool;
  val280 @286 :Bool;
  val281 @287 :Bool;
  val282 @288 :Bool;
  val283 @289 :Bool;
  val284 @290 :Bool;
  val285 @291 :Bool;
  val286 @292 :Bool;
  val287 @293 :Bool;
  val288 @294 :Bool;
  val289 @295 :Bool;
  val290 @296 :Bool;
  val291 @297 :Bool;
  val292 @298 :Bool;
  val293 @299 :Bool;
  val294 @300 :Bool;
  val295 @301 :Bool;
  val296 @302 :Bool;
  val297 @303 :Bool;
  val298 @304 :Bool;
  val299 @305 :Bool;
  val300 @306 :Bool;
  val301 @307 :Bool;
  val302 @308 :Bool;
  val303 @309 :Bool;
  val304 @310 :Bool;
  val305 @311 :Bool;
  val306 @312 :Bool;
  val307 @313 :Bool;
  val308 @314 :Bool;
  val309 @315 :Bool;
  val310 @316 :Bool;
  val311 @317 :Bool;
  val313 @318 :Bool;
  val314 @319 :Bool;
  val315 @320 :Bool;
  val316 @321 :Bool;
  val317 @322 :Bool;
  val318 @323 :Bool;
  val319 @324 :Bool;
  val320 @325 :Bool;
  val321 @326 :Bool;
  val322 @327 :Bool;
  val323 @328 :Bool;
  val324 @329 :Bool;
  val325 @330 :Bool;
  val326 @331 :Bool;
  val327 @332 :Bool;
  val328 @333 :Bool;
  val329 @334 :Bool;
  val330 @335 :Bool;
  val331 @336 :Bool;
  val332 @337 :Bool;
  val333 @338 :Bool;
  val334 @339 :Bool;
  val335 @340 :Bool;
  val336 @341 :Bool;
  val337 @342 :Bool;
  val338 @343 :Bool;
  val341 @344 :Bool;
  val342 @345 :Bool;
  val343 @346 :Bool;
  val7 @347 :UInt32;
  val138 @348 :UInt32;
  val177 @349 :UInt32;
  val178 @350 :UInt32;
  val179 @351 :UInt32;
  val180 @352 :UInt32;
}

struct Stmt @0x91127d30fade9a32 {
  val101 @0 :UInt32;
  val89 @1 :List(UInt32);
  val62 @2 :List(Text);
  val63 @3 :List(Text);
  val64 @4 :List(Text);
  val65 @5 :List(Text);
  val67 @6 :List(Text);
  val69 @7 :List(Text);
  val4 @8 :List(UInt64);
  val15 @9 :List(UInt64);
  val26 @10 :List(UInt64);
  val27 @11 :List(UInt64);
  val28 @12 :List(UInt64);
  val29 @13 :List(UInt64);
  val53 @14 :List(UInt64);
  val54 @15 :List(UInt64);
  val55 @16 :List(UInt64);
  val68 @17 :List(UInt64);
  val7 @18 :UInt8;
  val57 @19 :UInt8;
  val70 @20 :UInt8;
  val95 @21 :UInt8;
  val97 @22 :UInt8;
  val61 @23 :Text;
  val66 @24 :Text;
  val12 @25 :Bool;
  val16 @26 :Bool;
  val23 @27 :Bool;
  val24 @28 :Bool;
  val25 @29 :Bool;
  val58 @30 :Bool;
  val59 @31 :Bool;
  val60 @32 :Bool;
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
  val90 @51 :Bool;
  val91 @52 :Bool;
  val92 @53 :Bool;
  val93 @54 :Bool;
  val94 @55 :Bool;
  val96 @56 :Bool;
  val98 @57 :Bool;
  val99 @58 :Bool;
  val100 @59 :Bool;
  val102 @60 :Bool;
  val103 @61 :Bool;
  val104 @62 :Bool;
  val105 @63 :Bool;
  val106 @64 :Bool;
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
  val52 @105 :UInt64;
  val56 @106 :UInt64;
}

struct Type @0xd739e808bc1b3fd7 {
  val327 @0 :UInt16;
  val296 @1 :List(UInt32);
  val300 @2 :List(UInt64);
  val301 @3 :List(UInt64);
  val315 @4 :List(UInt64);
  val316 @5 :List(UInt64);
  val22 @6 :UInt8;
  val24 @7 :UInt8;
  val29 @8 :UInt8;
  val32 @9 :UInt8;
  val34 @10 :UInt8;
  val242 @11 :UInt8;
  val267 @12 :UInt8;
  val271 @13 :UInt8;
  val272 @14 :UInt8;
  val273 @15 :UInt8;
  val317 @16 :UInt8;
  val318 @17 :UInt8;
  val319 @18 :UInt8;
  val321 @19 :UInt8;
  val298 @20 :UInt32;
  val1 @21 :UInt64;
  val7 @22 :UInt64;
  val8 @23 :UInt64;
  val9 @24 :UInt64;
  val10 @25 :UInt64;
  val11 @26 :UInt64;
  val12 @27 :UInt64;
  val13 @28 :UInt64;
  val14 @29 :UInt64;
  val15 @30 :UInt64;
  val16 @31 :UInt64;
  val17 @32 :UInt64;
  val18 @33 :UInt64;
  val19 @34 :UInt64;
  val20 @35 :UInt64;
  val21 @36 :UInt64;
  val23 @37 :UInt64;
  val26 @38 :UInt64;
  val27 @39 :UInt64;
  val28 @40 :UInt64;
  val31 @41 :UInt64;
  val33 @42 :UInt64;
  val241 @43 :UInt64;
  val243 @44 :UInt64;
  val244 @45 :UInt64;
  val245 @46 :UInt64;
  val246 @47 :UInt64;
  val247 @48 :UInt64;
  val248 @49 :UInt64;
  val249 @50 :UInt64;
  val250 @51 :UInt64;
  val286 @52 :UInt64;
  val287 @53 :UInt64;
  val288 @54 :UInt64;
  val289 @55 :UInt64;
  val290 @56 :UInt64;
  val291 @57 :UInt64;
  val292 @58 :UInt64;
  val297 @59 :UInt64;
  val299 @60 :UInt64;
  val313 @61 :UInt64;
  val314 @62 :UInt64;
  val320 @63 :UInt64;
  val0 @64 :Bool;
  val2 @65 :Bool;
  val3 @66 :Bool;
  val4 @67 :Bool;
  val5 @68 :Bool;
  val6 @69 :Bool;
  val25 @70 :Bool;
  val30 @71 :Bool;
  val35 @72 :Bool;
  val36 @73 :Bool;
  val37 @74 :Bool;
  val38 @75 :Bool;
  val39 @76 :Bool;
  val40 @77 :Bool;
  val41 @78 :Bool;
  val42 @79 :Bool;
  val43 @80 :Bool;
  val44 @81 :Bool;
  val45 @82 :Bool;
  val46 @83 :Bool;
  val47 @84 :Bool;
  val48 @85 :Bool;
  val49 @86 :Bool;
  val50 @87 :Bool;
  val51 @88 :Bool;
  val52 @89 :Bool;
  val53 @90 :Bool;
  val54 @91 :Bool;
  val55 @92 :Bool;
  val56 @93 :Bool;
  val57 @94 :Bool;
  val58 @95 :Bool;
  val59 @96 :Bool;
  val60 @97 :Bool;
  val61 @98 :Bool;
  val62 @99 :Bool;
  val63 @100 :Bool;
  val64 @101 :Bool;
  val65 @102 :Bool;
  val66 @103 :Bool;
  val67 @104 :Bool;
  val68 @105 :Bool;
  val69 @106 :Bool;
  val70 @107 :Bool;
  val71 @108 :Bool;
  val72 @109 :Bool;
  val73 @110 :Bool;
  val74 @111 :Bool;
  val75 @112 :Bool;
  val76 @113 :Bool;
  val77 @114 :Bool;
  val78 @115 :Bool;
  val79 @116 :Bool;
  val80 @117 :Bool;
  val81 @118 :Bool;
  val82 @119 :Bool;
  val83 @120 :Bool;
  val84 @121 :Bool;
  val85 @122 :Bool;
  val86 @123 :Bool;
  val87 @124 :Bool;
  val88 @125 :Bool;
  val89 @126 :Bool;
  val90 @127 :Bool;
  val91 @128 :Bool;
  val92 @129 :Bool;
  val93 @130 :Bool;
  val94 @131 :Bool;
  val95 @132 :Bool;
  val96 @133 :Bool;
  val97 @134 :Bool;
  val98 @135 :Bool;
  val99 @136 :Bool;
  val100 @137 :Bool;
  val101 @138 :Bool;
  val102 @139 :Bool;
  val103 @140 :Bool;
  val104 @141 :Bool;
  val105 @142 :Bool;
  val106 @143 :Bool;
  val107 @144 :Bool;
  val108 @145 :Bool;
  val109 @146 :Bool;
  val110 @147 :Bool;
  val111 @148 :Bool;
  val112 @149 :Bool;
  val113 @150 :Bool;
  val114 @151 :Bool;
  val115 @152 :Bool;
  val116 @153 :Bool;
  val117 @154 :Bool;
  val118 @155 :Bool;
  val119 @156 :Bool;
  val120 @157 :Bool;
  val121 @158 :Bool;
  val122 @159 :Bool;
  val123 @160 :Bool;
  val124 @161 :Bool;
  val125 @162 :Bool;
  val126 @163 :Bool;
  val127 @164 :Bool;
  val128 @165 :Bool;
  val129 @166 :Bool;
  val130 @167 :Bool;
  val131 @168 :Bool;
  val132 @169 :Bool;
  val133 @170 :Bool;
  val134 @171 :Bool;
  val135 @172 :Bool;
  val136 @173 :Bool;
  val137 @174 :Bool;
  val138 @175 :Bool;
  val139 @176 :Bool;
  val140 @177 :Bool;
  val141 @178 :Bool;
  val142 @179 :Bool;
  val143 @180 :Bool;
  val144 @181 :Bool;
  val145 @182 :Bool;
  val146 @183 :Bool;
  val147 @184 :Bool;
  val148 @185 :Bool;
  val149 @186 :Bool;
  val150 @187 :Bool;
  val151 @188 :Bool;
  val152 @189 :Bool;
  val153 @190 :Bool;
  val154 @191 :Bool;
  val155 @192 :Bool;
  val156 @193 :Bool;
  val157 @194 :Bool;
  val158 @195 :Bool;
  val159 @196 :Bool;
  val160 @197 :Bool;
  val161 @198 :Bool;
  val162 @199 :Bool;
  val163 @200 :Bool;
  val164 @201 :Bool;
  val165 @202 :Bool;
  val166 @203 :Bool;
  val167 @204 :Bool;
  val168 @205 :Bool;
  val169 @206 :Bool;
  val170 @207 :Bool;
  val171 @208 :Bool;
  val172 @209 :Bool;
  val173 @210 :Bool;
  val174 @211 :Bool;
  val175 @212 :Bool;
  val176 @213 :Bool;
  val177 @214 :Bool;
  val178 @215 :Bool;
  val179 @216 :Bool;
  val180 @217 :Bool;
  val181 @218 :Bool;
  val182 @219 :Bool;
  val183 @220 :Bool;
  val184 @221 :Bool;
  val185 @222 :Bool;
  val186 @223 :Bool;
  val187 @224 :Bool;
  val188 @225 :Bool;
  val189 @226 :Bool;
  val190 @227 :Bool;
  val191 @228 :Bool;
  val192 @229 :Bool;
  val193 @230 :Bool;
  val194 @231 :Bool;
  val195 @232 :Bool;
  val196 @233 :Bool;
  val197 @234 :Bool;
  val198 @235 :Bool;
  val199 @236 :Bool;
  val200 @237 :Bool;
  val201 @238 :Bool;
  val202 @239 :Bool;
  val203 @240 :Bool;
  val204 @241 :Bool;
  val205 @242 :Bool;
  val206 @243 :Bool;
  val207 @244 :Bool;
  val208 @245 :Bool;
  val209 @246 :Bool;
  val210 @247 :Bool;
  val211 @248 :Bool;
  val212 @249 :Bool;
  val213 @250 :Bool;
  val214 @251 :Bool;
  val215 @252 :Bool;
  val216 @253 :Bool;
  val217 @254 :Bool;
  val218 @255 :Bool;
  val219 @256 :Bool;
  val220 @257 :Bool;
  val221 @258 :Bool;
  val222 @259 :Bool;
  val223 @260 :Bool;
  val224 @261 :Bool;
  val225 @262 :Bool;
  val226 @263 :Bool;
  val227 @264 :Bool;
  val228 @265 :Bool;
  val229 @266 :Bool;
  val230 @267 :Bool;
  val231 @268 :Bool;
  val232 @269 :Bool;
  val233 @270 :Bool;
  val234 @271 :Bool;
  val235 @272 :Bool;
  val236 @273 :Bool;
  val237 @274 :Bool;
  val238 @275 :Bool;
  val239 @276 :Bool;
  val240 @277 :Bool;
  val251 @278 :Bool;
  val252 @279 :Bool;
  val253 @280 :Bool;
  val254 @281 :Bool;
  val255 @282 :Bool;
  val256 @283 :Bool;
  val257 @284 :Bool;
  val258 @285 :Bool;
  val259 @286 :Bool;
  val260 @287 :Bool;
  val261 @288 :Bool;
  val262 @289 :Bool;
  val263 @290 :Bool;
  val264 @291 :Bool;
  val265 @292 :Bool;
  val266 @293 :Bool;
  val268 @294 :Bool;
  val269 @295 :Bool;
  val270 @296 :Bool;
  val274 @297 :Bool;
  val275 @298 :Bool;
  val276 @299 :Bool;
  val277 @300 :Bool;
  val278 @301 :Bool;
  val279 @302 :Bool;
  val280 @303 :Bool;
  val281 @304 :Bool;
  val282 @305 :Bool;
  val283 @306 :Bool;
  val284 @307 :Bool;
  val285 @308 :Bool;
  val293 @309 :Bool;
  val294 @310 :Bool;
  val295 @311 :Bool;
  val302 @312 :Bool;
  val303 @313 :Bool;
  val304 @314 :Bool;
  val305 @315 :Bool;
  val306 @316 :Bool;
  val307 @317 :Bool;
  val308 @318 :Bool;
  val309 @319 :Bool;
  val310 @320 :Bool;
  val311 @321 :Bool;
  val312 @322 :Bool;
  val322 @323 :Bool;
  val323 @324 :Bool;
  val324 @325 :Bool;
  val325 @326 :Bool;
  val326 @327 :Bool;
}

struct Attr @0xe5b70746662da9f3 {
  val11 @0 :UInt8;
  val15 @1 :UInt8;
  val16 @2 :UInt8;
  val9 @3 :Text;
  val10 @4 :Text;
  val18 @5 :Text;
  val5 @6 :UInt16;
  val1 @7 :Bool;
  val2 @8 :Bool;
  val3 @9 :Bool;
  val4 @10 :Bool;
  val12 @11 :Bool;
  val13 @12 :Bool;
  val14 @13 :Bool;
  val19 @14 :Bool;
  val20 @15 :Bool;
  val21 @16 :Bool;
  val22 @17 :Bool;
  val23 @18 :Bool;
  val0 @19 :UInt64;
  val6 @20 :UInt64;
  val7 @21 :UInt64;
  val8 @22 :UInt64;
  val17 @23 :UInt64;
}

struct Macro @0xf88157fb8bf2eeff {
  val6 @0 :Bool;
  val10 @1 :Bool;
  val2 @2 :List(UInt64);
  val3 @3 :List(UInt64);
  val5 @4 :List(UInt64);
  val7 @5 :UInt32;
  val1 @6 :UInt64;
  val4 @7 :UInt64;
  val8 @8 :UInt64;
  val9 @9 :UInt64;
  val0 @10 :UInt8;
}

struct Pseudo @0xa5b20a8972c73a6b {
  val12 @0 :UInt32;
  val14 @1 :UInt32;
  val15 @2 :UInt32;
  val4 @3 :UInt64;
  val5 @4 :UInt64;
  val6 @5 :UInt64;
  val7 @6 :UInt64;
  val8 @7 :UInt64;
  val9 @8 :UInt64;
  val10 @9 :UInt64;
  val11 @10 :UInt64;
  val16 @11 :List(UInt64);
  val1 @12 :Bool;
  val2 @13 :Bool;
  val3 @14 :Bool;
  val13 @15 :Bool;
  val18 @16 :Bool;
  val0 @17 :UInt8;
  val17 @18 :UInt8;
  val19 @19 :UInt8;
  val20 @20 :UInt8;
}

