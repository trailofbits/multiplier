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
  val140 @0 :UInt32;
  val186 @1 :UInt32;
  val3 @2 :List(UInt64);
  val49 @3 :List(UInt64);
  val50 @4 :List(UInt64);
  val60 @5 :List(UInt64);
  val175 @6 :List(UInt64);
  val183 @7 :List(UInt64);
  val184 @8 :List(UInt64);
  val185 @9 :List(UInt64);
  val313 @10 :List(UInt64);
  val339 @11 :List(UInt64);
  val341 @12 :List(UInt64);
  val342 @13 :List(UInt64);
  val347 @14 :List(UInt64);
  val348 @15 :List(UInt64);
  val349 @16 :List(UInt64);
  val350 @17 :List(UInt64);
  val4 @18 :UInt8;
  val5 @19 :UInt8;
  val10 @20 :UInt8;
  val11 @21 :UInt8;
  val42 @22 :UInt8;
  val43 @23 :UInt8;
  val63 @24 :UInt8;
  val67 @25 :UInt8;
  val68 @26 :UInt8;
  val78 @27 :UInt8;
  val83 @28 :UInt8;
  val85 @29 :UInt8;
  val86 @30 :UInt8;
  val87 @31 :UInt8;
  val88 @32 :UInt8;
  val90 @33 :UInt8;
  val91 @34 :UInt8;
  val129 @35 :UInt8;
  val164 @36 :UInt8;
  val61 @37 :Text;
  val62 @38 :Text;
  val71 @39 :Text;
  val2 @40 :Bool;
  val13 @41 :Bool;
  val14 @42 :Bool;
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
  val48 @70 :Bool;
  val51 @71 :Bool;
  val52 @72 :Bool;
  val53 @73 :Bool;
  val57 @74 :Bool;
  val58 @75 :Bool;
  val59 @76 :Bool;
  val69 @77 :Bool;
  val70 @78 :Bool;
  val72 @79 :Bool;
  val73 @80 :Bool;
  val74 @81 :Bool;
  val75 @82 :Bool;
  val92 @83 :Bool;
  val93 @84 :Bool;
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
  val132 @117 :Bool;
  val133 @118 :Bool;
  val134 @119 :Bool;
  val135 @120 :Bool;
  val136 @121 :Bool;
  val137 @122 :Bool;
  val138 @123 :Bool;
  val145 @124 :Bool;
  val146 @125 :Bool;
  val147 @126 :Bool;
  val148 @127 :Bool;
  val149 @128 :Bool;
  val150 @129 :Bool;
  val151 @130 :Bool;
  val152 @131 :Bool;
  val153 @132 :Bool;
  val154 @133 :Bool;
  val155 @134 :Bool;
  val156 @135 :Bool;
  val157 @136 :Bool;
  val158 @137 :Bool;
  val159 @138 :Bool;
  val160 @139 :Bool;
  val161 @140 :Bool;
  val162 @141 :Bool;
  val167 @142 :Bool;
  val168 @143 :Bool;
  val169 @144 :Bool;
  val170 @145 :Bool;
  val171 @146 :Bool;
  val172 @147 :Bool;
  val173 @148 :Bool;
  val174 @149 :Bool;
  val178 @150 :Bool;
  val179 @151 :Bool;
  val180 @152 :Bool;
  val181 @153 :Bool;
  val182 @154 :Bool;
  val187 @155 :Bool;
  val188 @156 :Bool;
  val189 @157 :Bool;
  val190 @158 :Bool;
  val191 @159 :Bool;
  val192 @160 :Bool;
  val193 @161 :Bool;
  val194 @162 :Bool;
  val195 @163 :Bool;
  val196 @164 :Bool;
  val197 @165 :Bool;
  val198 @166 :Bool;
  val199 @167 :Bool;
  val200 @168 :Bool;
  val201 @169 :Bool;
  val202 @170 :Bool;
  val203 @171 :Bool;
  val204 @172 :Bool;
  val205 @173 :Bool;
  val206 @174 :Bool;
  val207 @175 :Bool;
  val208 @176 :Bool;
  val209 @177 :Bool;
  val210 @178 :Bool;
  val211 @179 :Bool;
  val212 @180 :Bool;
  val213 @181 :Bool;
  val214 @182 :Bool;
  val215 @183 :Bool;
  val216 @184 :Bool;
  val217 @185 :Bool;
  val218 @186 :Bool;
  val219 @187 :Bool;
  val220 @188 :Bool;
  val221 @189 :Bool;
  val222 @190 :Bool;
  val223 @191 :Bool;
  val224 @192 :Bool;
  val225 @193 :Bool;
  val226 @194 :Bool;
  val227 @195 :Bool;
  val228 @196 :Bool;
  val229 @197 :Bool;
  val230 @198 :Bool;
  val231 @199 :Bool;
  val232 @200 :Bool;
  val233 @201 :Bool;
  val234 @202 :Bool;
  val235 @203 :Bool;
  val236 @204 :Bool;
  val237 @205 :Bool;
  val238 @206 :Bool;
  val239 @207 :Bool;
  val240 @208 :Bool;
  val241 @209 :Bool;
  val242 @210 :Bool;
  val243 @211 :Bool;
  val244 @212 :Bool;
  val245 @213 :Bool;
  val246 @214 :Bool;
  val247 @215 :Bool;
  val248 @216 :Bool;
  val249 @217 :Bool;
  val250 @218 :Bool;
  val251 @219 :Bool;
  val252 @220 :Bool;
  val253 @221 :Bool;
  val254 @222 :Bool;
  val255 @223 :Bool;
  val256 @224 :Bool;
  val257 @225 :Bool;
  val258 @226 :Bool;
  val259 @227 :Bool;
  val260 @228 :Bool;
  val261 @229 :Bool;
  val262 @230 :Bool;
  val263 @231 :Bool;
  val264 @232 :Bool;
  val265 @233 :Bool;
  val266 @234 :Bool;
  val267 @235 :Bool;
  val268 @236 :Bool;
  val269 @237 :Bool;
  val270 @238 :Bool;
  val271 @239 :Bool;
  val272 @240 :Bool;
  val273 @241 :Bool;
  val274 @242 :Bool;
  val275 @243 :Bool;
  val276 @244 :Bool;
  val277 @245 :Bool;
  val278 @246 :Bool;
  val279 @247 :Bool;
  val280 @248 :Bool;
  val281 @249 :Bool;
  val282 @250 :Bool;
  val283 @251 :Bool;
  val284 @252 :Bool;
  val285 @253 :Bool;
  val286 @254 :Bool;
  val287 @255 :Bool;
  val288 @256 :Bool;
  val289 @257 :Bool;
  val290 @258 :Bool;
  val291 @259 :Bool;
  val292 @260 :Bool;
  val293 @261 :Bool;
  val294 @262 :Bool;
  val295 @263 :Bool;
  val296 @264 :Bool;
  val297 @265 :Bool;
  val298 @266 :Bool;
  val299 @267 :Bool;
  val300 @268 :Bool;
  val301 @269 :Bool;
  val302 @270 :Bool;
  val303 @271 :Bool;
  val304 @272 :Bool;
  val305 @273 :Bool;
  val306 @274 :Bool;
  val307 @275 :Bool;
  val308 @276 :Bool;
  val309 @277 :Bool;
  val310 @278 :Bool;
  val311 @279 :Bool;
  val312 @280 :Bool;
  val314 @281 :Bool;
  val315 @282 :Bool;
  val316 @283 :Bool;
  val317 @284 :Bool;
  val318 @285 :Bool;
  val319 @286 :Bool;
  val320 @287 :Bool;
  val321 @288 :Bool;
  val322 @289 :Bool;
  val323 @290 :Bool;
  val324 @291 :Bool;
  val325 @292 :Bool;
  val326 @293 :Bool;
  val327 @294 :Bool;
  val328 @295 :Bool;
  val329 @296 :Bool;
  val330 @297 :Bool;
  val331 @298 :Bool;
  val332 @299 :Bool;
  val333 @300 :Bool;
  val334 @301 :Bool;
  val335 @302 :Bool;
  val336 @303 :Bool;
  val337 @304 :Bool;
  val338 @305 :Bool;
  val340 @306 :Bool;
  val343 @307 :Bool;
  val344 @308 :Bool;
  val345 @309 :Bool;
  val346 @310 :Bool;
  val0 @311 :UInt64;
  val1 @312 :UInt64;
  val6 @313 :UInt64;
  val7 @314 :UInt64;
  val8 @315 :UInt64;
  val9 @316 :UInt64;
  val12 @317 :UInt64;
  val44 @318 :UInt64;
  val45 @319 :UInt64;
  val46 @320 :UInt64;
  val47 @321 :UInt64;
  val54 @322 :UInt64;
  val55 @323 :UInt64;
  val56 @324 :UInt64;
  val64 @325 :UInt64;
  val65 @326 :UInt64;
  val66 @327 :UInt64;
  val76 @328 :UInt64;
  val77 @329 :UInt64;
  val79 @330 :UInt64;
  val80 @331 :UInt64;
  val81 @332 :UInt64;
  val82 @333 :UInt64;
  val84 @334 :UInt64;
  val89 @335 :UInt64;
  val126 @336 :UInt64;
  val127 @337 :UInt64;
  val128 @338 :UInt64;
  val130 @339 :UInt64;
  val131 @340 :UInt64;
  val139 @341 :UInt64;
  val141 @342 :UInt64;
  val142 @343 :UInt64;
  val143 @344 :UInt64;
  val144 @345 :UInt64;
  val163 @346 :UInt64;
  val165 @347 :UInt64;
  val166 @348 :UInt64;
  val176 @349 :UInt64;
  val177 @350 :UInt64;
}

struct Stmt @0x91127d30fade9a32{
  val108 @0 :UInt32;
  val64 @1 :List(Text);
  val65 @2 :List(Text);
  val66 @3 :List(Text);
  val67 @4 :List(Text);
  val69 @5 :List(Text);
  val71 @6 :List(Text);
  val5 @7 :List(UInt64);
  val7 @8 :List(UInt64);
  val18 @9 :List(UInt64);
  val29 @10 :List(UInt64);
  val30 @11 :List(UInt64);
  val31 @12 :List(UInt64);
  val32 @13 :List(UInt64);
  val55 @14 :List(UInt64);
  val56 @15 :List(UInt64);
  val57 @16 :List(UInt64);
  val70 @17 :List(UInt64);
  val10 @18 :UInt8;
  val59 @19 :UInt8;
  val72 @20 :UInt8;
  val73 @21 :UInt8;
  val97 @22 :UInt8;
  val99 @23 :UInt8;
  val63 @24 :Text;
  val68 @25 :Text;
  val15 @26 :Bool;
  val19 @27 :Bool;
  val26 @28 :Bool;
  val27 @29 :Bool;
  val28 @30 :Bool;
  val60 @31 :Bool;
  val61 @32 :Bool;
  val62 @33 :Bool;
  val74 @34 :Bool;
  val75 @35 :Bool;
  val76 @36 :Bool;
  val77 @37 :Bool;
  val78 @38 :Bool;
  val79 @39 :Bool;
  val80 @40 :Bool;
  val81 @41 :Bool;
  val82 @42 :Bool;
  val83 @43 :Bool;
  val84 @44 :Bool;
  val85 @45 :Bool;
  val86 @46 :Bool;
  val87 @47 :Bool;
  val88 @48 :Bool;
  val89 @49 :Bool;
  val90 @50 :Bool;
  val91 @51 :Bool;
  val92 @52 :Bool;
  val93 @53 :Bool;
  val94 @54 :Bool;
  val95 @55 :Bool;
  val96 @56 :Bool;
  val98 @57 :Bool;
  val100 @58 :Bool;
  val101 @59 :Bool;
  val102 @60 :Bool;
  val103 @61 :Bool;
  val104 @62 :Bool;
  val105 @63 :Bool;
  val106 @64 :Bool;
  val107 @65 :Bool;
  val0 @66 :UInt64;
  val1 @67 :UInt64;
  val2 @68 :UInt64;
  val3 @69 :UInt64;
  val4 @70 :UInt64;
  val6 @71 :UInt64;
  val8 @72 :UInt64;
  val9 @73 :UInt64;
  val11 @74 :UInt64;
  val12 @75 :UInt64;
  val13 @76 :UInt64;
  val14 @77 :UInt64;
  val16 @78 :UInt64;
  val17 @79 :UInt64;
  val20 @80 :UInt64;
  val21 @81 :UInt64;
  val22 @82 :UInt64;
  val23 @83 :UInt64;
  val24 @84 :UInt64;
  val25 @85 :UInt64;
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
  val53 @106 :UInt64;
  val54 @107 :UInt64;
  val58 @108 :UInt64;
}

struct Type @0xd739e808bc1b3fd7{
  val275 @0 :UInt16;
  val10 @1 :UInt8;
  val11 @2 :UInt8;
  val16 @3 :UInt8;
  val19 @4 :UInt8;
  val21 @5 :UInt8;
  val238 @6 :UInt8;
  val271 @7 :UInt8;
  val272 @8 :UInt8;
  val274 @9 :UInt8;
  val234 @10 :List(UInt64);
  val266 @11 :List(UInt64);
  val269 @12 :List(UInt64);
  val270 @13 :List(UInt64);
  val0 @14 :UInt64;
  val1 @15 :UInt64;
  val3 @16 :UInt64;
  val9 @17 :UInt64;
  val13 @18 :UInt64;
  val14 @19 :UInt64;
  val15 @20 :UInt64;
  val18 @21 :UInt64;
  val20 @22 :UInt64;
  val229 @23 :UInt64;
  val230 @24 :UInt64;
  val236 @25 :UInt64;
  val237 @26 :UInt64;
  val267 @27 :UInt64;
  val268 @28 :UInt64;
  val273 @29 :UInt64;
  val2 @30 :Bool;
  val4 @31 :Bool;
  val5 @32 :Bool;
  val6 @33 :Bool;
  val7 @34 :Bool;
  val8 @35 :Bool;
  val12 @36 :Bool;
  val17 @37 :Bool;
  val22 @38 :Bool;
  val23 @39 :Bool;
  val24 @40 :Bool;
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
  val231 @245 :Bool;
  val232 @246 :Bool;
  val233 @247 :Bool;
  val239 @248 :Bool;
  val240 @249 :Bool;
  val241 @250 :Bool;
  val242 @251 :Bool;
  val243 @252 :Bool;
  val244 @253 :Bool;
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
  val235 @275 :UInt32;
}

struct Attr @0xe5b70746662da9f3{
  val10 @0 :UInt8;
  val14 @1 :UInt8;
  val15 @2 :UInt8;
  val9 @3 :Text;
  val17 @4 :Text;
  val5 @5 :UInt16;
  val1 @6 :Bool;
  val2 @7 :Bool;
  val3 @8 :Bool;
  val4 @9 :Bool;
  val11 @10 :Bool;
  val12 @11 :Bool;
  val13 @12 :Bool;
  val18 @13 :Bool;
  val19 @14 :Bool;
  val20 @15 :Bool;
  val21 @16 :Bool;
  val22 @17 :Bool;
  val0 @18 :UInt64;
  val6 @19 :UInt64;
  val7 @20 :UInt64;
  val8 @21 :UInt64;
  val16 @22 :UInt64;
}

struct Macro @0xf88157fb8bf2eeff{
  val3 @0 :Bool;
  val14 @1 :Bool;
  val2 @2 :List(UInt64);
  val4 @3 :List(UInt64);
  val10 @4 :List(UInt64);
  val11 @5 :List(UInt64);
  val13 @6 :UInt32;
  val1 @7 :UInt64;
  val5 @8 :UInt64;
  val6 @9 :UInt64;
  val7 @10 :UInt64;
  val8 @11 :UInt64;
  val9 @12 :UInt64;
  val12 @13 :UInt64;
  val0 @14 :UInt8;
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
  val11 @0 :UInt32;
  val3 @1 :UInt64;
  val4 @2 :UInt64;
  val5 @3 :UInt64;
  val6 @4 :UInt64;
  val7 @5 :UInt64;
  val8 @6 :UInt64;
  val9 @7 :UInt64;
  val10 @8 :UInt64;
  val0 @9 :Bool;
  val1 @10 :Bool;
  val2 @11 :Bool;
  val12 @12 :Bool;
}

