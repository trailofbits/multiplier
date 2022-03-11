# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

# Auto-generated file; do not modify!

@0xa04be7b45e95b659;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::ast");
enum AccessSpecifier @0xea31fabcef869ac6 {
  public @0;
  protected @1;
  private @2;
  none @3;
}

enum AvailabilityResult @0xe8c6cd388f86c217 {
  available @0;
  notUcYetUcIntroduced @1;
  deprecated @2;
  unavailable @3;
}

enum FriendObjectKind @0xc74745b68a910aa9 {
  none @0;
  declared @1;
  undeclared @2;
}

enum ModuleOwnershipKind @0x94f1123366f439d2 {
  unowned @0;
  visible @1;
  visibleUcWhenUcImported @2;
  moduleUcPrivate @3;
}

enum DeclKind @0x96ac187aac5afe4d {
  accessUcSpec @0;
  baseUcUsing @1;
  binding @2;
  block @3;
  builtinUcTemplate @4;
  cxxConstructor @5;
  cxxConversion @6;
  cxxDeductionUcGuide @7;
  cxxDestructor @8;
  cxxMethod @9;
  cxxRecord @10;
  captured @11;
  classUcScopeUcFunctionUcSpecialization @12;
  classUcTemplate @13;
  classUcTemplateUcPartialUcSpecialization @14;
  classUcTemplateUcSpecialization @15;
  concept @16;
  constructorUcUsingUcShadow @17;
  declarator @18;
  decomposition @19;
  empty @20;
  enumUcConstant @21;
  enum @22;
  export @23;
  externCContext @24;
  field @25;
  fileUcScopeUcAsm @26;
  friend @27;
  friendUcTemplate @28;
  function @29;
  functionUcTemplate @30;
  implicitUcParam @31;
  import @32;
  indirectUcField @33;
  label @34;
  lifetimeUcExtendedUcTemporary @35;
  linkageUcSpec @36;
  msGuid @37;
  msProperty @38;
  named @39;
  namespaceUcAlias @40;
  namespace @41;
  nonUcTypeUcTemplateUcParm @42;
  ompAllocate @43;
  ompCapturedUcExpr @44;
  ompDeclareUcMapper @45;
  ompDeclareUcReduction @46;
  ompRequires @47;
  ompThreadUcPrivate @48;
  objCAtUcDefsUcField @49;
  objCCategory @50;
  objCCategoryUcImpl @51;
  objCCompatibleUcAlias @52;
  objCContainer @53;
  objCImpl @54;
  objCImplementation @55;
  objCInterface @56;
  objCIvar @57;
  objCMethod @58;
  objCProperty @59;
  objCPropertyUcImpl @60;
  objCProtocol @61;
  objCTypeUcParam @62;
  parmUcVar @63;
  pragmaUcComment @64;
  pragmaUcDetectUcMismatch @65;
  record @66;
  redeclarableUcTemplate @67;
  requiresUcExprUcBody @68;
  staticUcAssert @69;
  tag @70;
  template @71;
  templateUcParamUcObject @72;
  templateUcTemplateUcParm @73;
  templateUcTypeUcParm @74;
  translationUcUnit @75;
  typeUcAlias @76;
  typeUcAliasUcTemplate @77;
  type @78;
  typedef @79;
  typedefUcName @80;
  unresolvedUcUsingUcIfUcExists @81;
  unresolvedUcUsingUcTypename @82;
  unresolvedUcUsingUcValue @83;
  using @84;
  usingUcDirective @85;
  usingUcEnum @86;
  usingUcPack @87;
  usingUcShadow @88;
  value @89;
  var @90;
  varUcTemplate @91;
  varUcTemplateUcPartialUcSpecialization @92;
  varUcTemplateUcSpecialization @93;
}

enum PragmaMSCommentKind @0xe09b297844ff08bb {
  unknown @0;
  linker @1;
  lib @2;
  compiler @3;
  exeUcString @4;
  user @5;
}

enum Linkage @0xd7f90485cbd67b8c {
  noUcLinkage @0;
  internalUcLinkage @1;
  uniqueUcExternalUcLinkage @2;
  visibleUcNoUcLinkage @3;
  moduleUcInternalUcLinkage @4;
  moduleUcLinkage @5;
  externalUcLinkage @6;
}

enum ObjCStringFormatFamily @0xdde65f902899f0f0 {
  none @0;
  nsString @1;
  cfString @2;
}

enum Visibility @0x9f55e79df4f9996e {
  hiddenUcVisibility @0;
  protectedUcVisibility @1;
  defaultUcVisibility @2;
}

enum LanguageLinkage @0xa1e45a6941f17018 {
  cLanguageUcLinkage @0;
  cxxLanguageUcLinkage @1;
  noUcLanguageUcLinkage @2;
}

enum StorageClass @0xda0542391be3aa63 {
  none @0;
  extern @1;
  static @2;
  privateUcExtern @3;
  auto @4;
  register @5;
}

enum StorageDuration @0xe1a5462cfd90bc60 {
  fullUcExpression @0;
  automatic @1;
  thread @2;
  static @3;
  dynamic @4;
}

enum ThreadStorageClassSpecifier @0xa5e43d0340490a97 {
  unspecified @0;
  ucThread @1;
  threadUcLocal @2;
  ucThreadUcLocal @3;
}

enum TemplateSpecializationKind @0xc45c2bfe2b2d2105 {
  undeclared @0;
  implicitUcInstantiation @1;
  explicitUcSpecialization @2;
  explicitUcInstantiationUcDeclaration @3;
  explicitUcInstantiationUcDefinition @4;
}

enum ImplicitParamKind @0xab95d72fdf3ce08d {
  objCSelf @0;
  objCCmd @1;
  cxxThis @2;
  cxxvtt @3;
  capturedUcContext @4;
  other @5;
}

enum ConstexprSpecKind @0x9b968674fb4c29be {
  unspecified @0;
  constexpr @1;
  consteval @2;
  constinit @3;
}

enum ExceptionSpecificationType @0xd5391f397240ed4d {
  none @0;
  dynamicUcNone @1;
  dynamic @2;
  msAny @3;
  noUcThrow @4;
  basicUcNoexcept @5;
  dependentUcNoexcept @6;
  noexceptUcFalse @7;
  noexceptUcTrue @8;
  unevaluated @9;
  uninstantiated @10;
  unparsed @11;
}

enum MultiVersionKind @0xd6aa1ba55a8d79af {
  none @0;
  target @1;
  cpuSpecific @2;
  cpuDispatch @3;
}

enum OverloadedOperatorKind @0x899b59d4c33ece1a {
  none @0;
  new @1;
  delete @2;
  arrayUcNew @3;
  arrayUcDelete @4;
  plus @5;
  minus @6;
  star @7;
  slash @8;
  percent @9;
  caret @10;
  amp @11;
  pipe @12;
  tilde @13;
  exclaim @14;
  equal @15;
  less @16;
  greater @17;
  plusUcEqual @18;
  minusUcEqual @19;
  starUcEqual @20;
  slashUcEqual @21;
  percentUcEqual @22;
  caretUcEqual @23;
  ampUcEqual @24;
  pipeUcEqual @25;
  lessUcLess @26;
  greaterUcGreater @27;
  lessUcLessUcEqual @28;
  greaterUcGreaterUcEqual @29;
  equalUcEqual @30;
  exclaimUcEqual @31;
  lessUcEqual @32;
  greaterUcEqual @33;
  spaceship @34;
  ampUcAmp @35;
  pipeUcPipe @36;
  plusUcPlus @37;
  minusUcMinus @38;
  comma @39;
  arrowUcStar @40;
  arrow @41;
  call @42;
  subscript @43;
  conditional @44;
  coawait @45;
  numoverloadedoperators @46;
}

enum RefQualifierKind @0xe49bd7951a6ae539 {
  none @0;
  lValue @1;
  rValue @2;
}

enum InClassInitStyle @0xfd30164f4a13d25c {
  noUcInitializer @0;
  copyUcInitializer @1;
  listUcInitializer @2;
}

enum TagTypeKind @0xbfa845fcdbd00864 {
  struct @0;
  interface @1;
  union @2;
  class @3;
  enum @4;
}

enum ArgPassingKind @0xfc581c2eded85fa9 {
  canUcPassUcInUcRegs @0;
  cannotUcPassUcInUcRegs @1;
  canUcNeverUcPassUcInUcRegs @2;
}

enum MSInheritanceModel @0x9e63c392cec08405 {
  single @0;
  multiple @1;
  virtual @2;
  unspecified @3;
}

enum LambdaCaptureDefault @0xc5ffb9f76dbfab4d {
  none @0;
  byUcCopy @1;
  byUcReference @2;
}

enum MSVtorDispMode @0xd30e950dab28014f {
  never @0;
  forUcVirtualUcBaseUcOverride @1;
  forVfTable @2;
}

enum ObjCTypeParamVariance @0x922a77f8ad69d2ca {
  invariant @0;
  covariant @1;
  contravariant @2;
}

enum PropertyControl @0x80dbe303a4591128 {
  none @0;
  required @1;
  optional @2;
}

enum ObjCPropertyQueryKind @0xa276e57d28cfccfe {
  queryUcUnknown @0;
  queryUcInstance @1;
  queryUcClass @2;
}

enum SetterKind @0x9b24373b205d21f4 {
  assign @0;
  retain @1;
  copy @2;
  weak @3;
}

enum ImplementationControl @0x8d100537007bc5a0 {
  none @0;
  required @1;
  optional @2;
}

enum ObjCMethodFamily @0xce49434a6017454c {
  none @0;
  alloc @1;
  copy @2;
  initializer @3;
  mutableUcCopy @4;
  new @5;
  autorelease @6;
  dealloc @7;
  finalize @8;
  release @9;
  retain @10;
  retainUcCount @11;
  self @12;
  initialize @13;
  performUcSelector @14;
}

enum LanguageIDs @0xe48de286671b0833 {
  c @0;
  cxx @1;
}

enum StmtKind @0xc9755b9a053563b9 {
  gccAsmUcStmt @0;
  msAsmUcStmt @1;
  breakUcStmt @2;
  cxxCatchUcStmt @3;
  cxxForUcRangeUcStmt @4;
  cxxTryUcStmt @5;
  capturedUcStmt @6;
  compoundUcStmt @7;
  continueUcStmt @8;
  coreturnUcStmt @9;
  coroutineUcBodyUcStmt @10;
  declUcStmt @11;
  doUcStmt @12;
  forUcStmt @13;
  gotoUcStmt @14;
  ifUcStmt @15;
  indirectUcGotoUcStmt @16;
  msDependentUcExistsUcStmt @17;
  nullUcStmt @18;
  ompCanonicalUcLoop @19;
  ompAtomicUcDirective @20;
  ompBarrierUcDirective @21;
  ompCancelUcDirective @22;
  ompCancellationUcPointUcDirective @23;
  ompCriticalUcDirective @24;
  ompDepobjUcDirective @25;
  ompDispatchUcDirective @26;
  ompFlushUcDirective @27;
  ompInteropUcDirective @28;
  ompDistributeUcDirective @29;
  ompDistributeUcParallelUcForUcDirective @30;
  ompDistributeUcParallelUcForUcSimdUcDirective @31;
  ompDistributeUcSimdUcDirective @32;
  ompForUcDirective @33;
  ompForUcSimdUcDirective @34;
  ompMasterUcTaskUcLoopUcDirective @35;
  ompMasterUcTaskUcLoopUcSimdUcDirective @36;
  ompParallelUcForUcDirective @37;
  ompParallelUcForUcSimdUcDirective @38;
  ompParallelUcMasterUcTaskUcLoopUcDirective @39;
  ompParallelUcMasterUcTaskUcLoopUcSimdUcDirective @40;
  ompSimdUcDirective @41;
  ompTargetUcParallelUcForUcSimdUcDirective @42;
  ompTargetUcSimdUcDirective @43;
  ompTargetUcTeamsUcDistributeUcDirective @44;
  ompTargetUcTeamsUcDistributeUcParallelUcForUcDirective @45;
  ompTargetUcTeamsUcDistributeUcParallelUcForUcSimdUcDirective @46;
  ompTargetUcTeamsUcDistributeUcSimdUcDirective @47;
  ompTaskUcLoopUcDirective @48;
  ompTaskUcLoopUcSimdUcDirective @49;
  ompTeamsUcDistributeUcDirective @50;
  ompTeamsUcDistributeUcParallelUcForUcDirective @51;
  ompTeamsUcDistributeUcParallelUcForUcSimdUcDirective @52;
  ompTeamsUcDistributeUcSimdUcDirective @53;
  ompTileUcDirective @54;
  ompUnrollUcDirective @55;
  ompMaskedUcDirective @56;
  ompMasterUcDirective @57;
  ompOrderedUcDirective @58;
  ompParallelUcDirective @59;
  ompParallelUcMasterUcDirective @60;
  ompParallelUcSectionsUcDirective @61;
  ompScanUcDirective @62;
  ompSectionUcDirective @63;
  ompSectionsUcDirective @64;
  ompSingleUcDirective @65;
  ompTargetUcDataUcDirective @66;
  ompTargetUcDirective @67;
  ompTargetUcEnterUcDataUcDirective @68;
  ompTargetUcExitUcDataUcDirective @69;
  ompTargetUcParallelUcDirective @70;
  ompTargetUcParallelUcForUcDirective @71;
  ompTargetUcTeamsUcDirective @72;
  ompTargetUcUpdateUcDirective @73;
  ompTaskUcDirective @74;
  ompTaskgroupUcDirective @75;
  ompTaskwaitUcDirective @76;
  ompTaskyieldUcDirective @77;
  ompTeamsUcDirective @78;
  objCAtUcCatchUcStmt @79;
  objCAtUcFinallyUcStmt @80;
  objCAtUcSynchronizedUcStmt @81;
  objCAtUcThrowUcStmt @82;
  objCAtUcTryUcStmt @83;
  objCAutoreleaseUcPoolUcStmt @84;
  objCForUcCollectionUcStmt @85;
  returnUcStmt @86;
  sehExceptUcStmt @87;
  sehFinallyUcStmt @88;
  sehLeaveUcStmt @89;
  sehTryUcStmt @90;
  caseUcStmt @91;
  defaultUcStmt @92;
  switchUcStmt @93;
  attributedUcStmt @94;
  binaryUcConditionalUcOperator @95;
  conditionalUcOperator @96;
  addrUcLabelUcExpr @97;
  arrayUcInitUcIndexUcExpr @98;
  arrayUcInitUcLoopUcExpr @99;
  arrayUcSubscriptUcExpr @100;
  arrayUcTypeUcTraitUcExpr @101;
  asUcTypeUcExpr @102;
  atomicUcExpr @103;
  binaryUcOperator @104;
  compoundUcAssignUcOperator @105;
  blockUcExpr @106;
  cxxBindUcTemporaryUcExpr @107;
  cxxBoolUcLiteralUcExpr @108;
  cxxConstructUcExpr @109;
  cxxTemporaryUcObjectUcExpr @110;
  cxxDefaultUcArgUcExpr @111;
  cxxDefaultUcInitUcExpr @112;
  cxxDeleteUcExpr @113;
  cxxDependentUcScopeUcMemberUcExpr @114;
  cxxFoldUcExpr @115;
  cxxInheritedUcCtorUcInitUcExpr @116;
  cxxNewUcExpr @117;
  cxxNoexceptUcExpr @118;
  cxxNullUcPtrUcLiteralUcExpr @119;
  cxxPseudoUcDestructorUcExpr @120;
  cxxRewrittenUcBinaryUcOperator @121;
  cxxScalarUcValueUcInitUcExpr @122;
  cxxStdUcInitializerUcListUcExpr @123;
  cxxThisUcExpr @124;
  cxxThrowUcExpr @125;
  cxxTypeidUcExpr @126;
  cxxUnresolvedUcConstructUcExpr @127;
  cxxUuidofUcExpr @128;
  callUcExpr @129;
  cudaKernelUcCallUcExpr @130;
  cxxMemberUcCallUcExpr @131;
  cxxOperatorUcCallUcExpr @132;
  userUcDefinedUcLiteral @133;
  builtinUcBitUcCastUcExpr @134;
  cStyleUcCastUcExpr @135;
  cxxFunctionalUcCastUcExpr @136;
  cxxAddrspaceUcCastUcExpr @137;
  cxxConstUcCastUcExpr @138;
  cxxDynamicUcCastUcExpr @139;
  cxxReinterpretUcCastUcExpr @140;
  cxxStaticUcCastUcExpr @141;
  objCBridgedUcCastUcExpr @142;
  implicitUcCastUcExpr @143;
  characterUcLiteral @144;
  chooseUcExpr @145;
  compoundUcLiteralUcExpr @146;
  conceptUcSpecializationUcExpr @147;
  convertUcVectorUcExpr @148;
  coawaitUcExpr @149;
  coyieldUcExpr @150;
  declUcRefUcExpr @151;
  dependentUcCoawaitUcExpr @152;
  dependentUcScopeUcDeclUcRefUcExpr @153;
  designatedUcInitUcExpr @154;
  designatedUcInitUcUpdateUcExpr @155;
  expressionUcTraitUcExpr @156;
  extUcVectorUcElementUcExpr @157;
  fixedUcPointUcLiteral @158;
  floatingUcLiteral @159;
  constantUcExpr @160;
  exprUcWithUcCleanups @161;
  functionUcParmUcPackUcExpr @162;
  gnuNullUcExpr @163;
  genericUcSelectionUcExpr @164;
  imaginaryUcLiteral @165;
  implicitUcValueUcInitUcExpr @166;
  initUcListUcExpr @167;
  integerUcLiteral @168;
  lambdaUcExpr @169;
  msPropertyUcRefUcExpr @170;
  msPropertyUcSubscriptUcExpr @171;
  materializeUcTemporaryUcExpr @172;
  matrixUcSubscriptUcExpr @173;
  memberUcExpr @174;
  noUcInitUcExpr @175;
  ompArrayUcSectionUcExpr @176;
  ompArrayUcShapingUcExpr @177;
  ompIteratorUcExpr @178;
  objCArrayUcLiteral @179;
  objCAvailabilityUcCheckUcExpr @180;
  objCBoolUcLiteralUcExpr @181;
  objCBoxedUcExpr @182;
  objCDictionaryUcLiteral @183;
  objCEncodeUcExpr @184;
  objCIndirectUcCopyUcRestoreUcExpr @185;
  objCIsaUcExpr @186;
  objCIvarUcRefUcExpr @187;
  objCMessageUcExpr @188;
  objCPropertyUcRefUcExpr @189;
  objCProtocolUcExpr @190;
  objCSelectorUcExpr @191;
  objCStringUcLiteral @192;
  objCSubscriptUcRefUcExpr @193;
  offsetUcOfUcExpr @194;
  opaqueUcValueUcExpr @195;
  unresolvedUcLookupUcExpr @196;
  unresolvedUcMemberUcExpr @197;
  packUcExpansionUcExpr @198;
  parenUcExpr @199;
  parenUcListUcExpr @200;
  predefinedUcExpr @201;
  pseudoUcObjectUcExpr @202;
  recoveryUcExpr @203;
  requiresUcExpr @204;
  syclUniqueUcStableUcNameUcExpr @205;
  shuffleUcVectorUcExpr @206;
  sizeUcOfUcPackUcExpr @207;
  sourceUcLocUcExpr @208;
  stmtUcExpr @209;
  stringUcLiteral @210;
  substUcNonUcTypeUcTemplateUcParmUcExpr @211;
  substUcNonUcTypeUcTemplateUcParmUcPackUcExpr @212;
  typeUcTraitUcExpr @213;
  typoUcExpr @214;
  unaryUcExprUcOrUcTypeUcTraitUcExpr @215;
  unaryUcOperator @216;
  vaArgUcExpr @217;
  labelUcStmt @218;
  whileUcStmt @219;
}

enum CapturedRegionKind @0x9c1102e218ed4271 {
  default @0;
  objCAtUcFinally @1;
  openMp @2;
}

enum ExprObjectKind @0xf9211f9356023995 {
  ordinary @0;
  bitUcField @1;
  vectorUcComponent @2;
  objCProperty @3;
  objCSubscript @4;
  matrixUcComponent @5;
}

enum ExprValueKind @0xb10e40f0a807354a {
  prValue @0;
  lValue @1;
  xValue @2;
}

enum NonOdrUseReason @0xbc90b6da0c76be85 {
  none @0;
  unevaluated @1;
  constant @2;
  discarded @3;
}

enum CastKind @0xc1c8bbecc0c79f1b {
  dependent @0;
  bitUcCast @1;
  lValueUcBitUcCast @2;
  lValueUcToRValueUcBitUcCast @3;
  lValueUcToRValue @4;
  noUcOperation @5;
  baseUcToUcDerived @6;
  derivedUcToUcBase @7;
  uncheckedUcDerivedUcToUcBase @8;
  dynamic @9;
  toUcUnion @10;
  arrayUcToUcPointerUcDecay @11;
  functionUcToUcPointerUcDecay @12;
  nullUcToUcPointer @13;
  nullUcToUcMemberUcPointer @14;
  baseUcToUcDerivedUcMemberUcPointer @15;
  derivedUcToUcBaseUcMemberUcPointer @16;
  memberUcPointerUcToUcBoolean @17;
  reinterpretUcMemberUcPointer @18;
  userUcDefinedUcConversion @19;
  constructorUcConversion @20;
  integralUcToUcPointer @21;
  pointerUcToUcIntegral @22;
  pointerUcToUcBoolean @23;
  toUcVoid @24;
  matrixUcCast @25;
  vectorUcSplat @26;
  integralUcCast @27;
  integralUcToUcBoolean @28;
  integralUcToUcFloating @29;
  floatingUcToUcFixedUcPoint @30;
  fixedUcPointUcToUcFloating @31;
  fixedUcPointUcCast @32;
  fixedUcPointUcToUcIntegral @33;
  integralUcToUcFixedUcPoint @34;
  fixedUcPointUcToUcBoolean @35;
  floatingUcToUcIntegral @36;
  floatingUcToUcBoolean @37;
  booleanUcToUcSignedUcIntegral @38;
  floatingUcCast @39;
  cPointerUcToUcObjCPointerUcCast @40;
  blockUcPointerUcToUcObjCPointerUcCast @41;
  anyUcPointerUcToUcBlockUcPointerUcCast @42;
  objCObjectLValueUcCast @43;
  floatingUcRealUcToUcComplex @44;
  floatingUcComplexUcToUcReal @45;
  floatingUcComplexUcToUcBoolean @46;
  floatingUcComplexUcCast @47;
  floatingUcComplexUcToUcIntegralUcComplex @48;
  integralUcRealUcToUcComplex @49;
  integralUcComplexUcToUcReal @50;
  integralUcComplexUcToUcBoolean @51;
  integralUcComplexUcCast @52;
  integralUcComplexUcToUcFloatingUcComplex @53;
  arcProduceUcObject @54;
  arcConsumeUcObject @55;
  arcReclaimUcReturnedUcObject @56;
  arcExtendUcBlockUcObject @57;
  atomicUcToUcNonUcAtomic @58;
  nonUcAtomicUcToUcAtomic @59;
  copyUcAndUcAutoreleaseUcBlockUcObject @60;
  builtinUcFnUcToUcFnUcPointer @61;
  zeroUcToOclOpaqueUcType @62;
  addressUcSpaceUcConversion @63;
  intUcToOclSampler @64;
}

enum ObjCBridgeCastKind @0xfe79ee651274349f {
  bridge @0;
  bridgeUcTransfer @1;
  bridgeUcRetained @2;
}

enum ADLCallKind @0xc8253fdf892ab117 {
  notAdl @0;
  usesAdl @1;
}

enum BinaryOperatorKind @0xbb08cc41f7a56597 {
  pointerUcMemoryD @0;
  pointerUcMemoryI @1;
  mul @2;
  div @3;
  rem @4;
  add @5;
  sub @6;
  shl @7;
  shr @8;
  cmp @9;
  lt @10;
  gt @11;
  le @12;
  ge @13;
  eq @14;
  ne @15;
  and @16;
  xor @17;
  or @18;
  lAnd @19;
  lOr @20;
  assign @21;
  mulUcAssign @22;
  divUcAssign @23;
  remUcAssign @24;
  addUcAssign @25;
  subUcAssign @26;
  shlUcAssign @27;
  shrUcAssign @28;
  andUcAssign @29;
  xorUcAssign @30;
  orUcAssign @31;
  comma @32;
}

enum InitializationStyle @0x8ec30c1abc0c19a6 {
  cInit @0;
  callUcInitializer @1;
  listUcInitializer @2;
}

enum ConstructionKind @0xda989eff233a33e2 {
  complete @0;
  nonUcVirtualUcBase @1;
  virtualUcBase @2;
  delegating @3;
}

enum ArrayTypeTrait @0xd6960ffdc6f9f29f {
  arrayUcRank @0;
  arrayUcExtent @1;
}

enum UnaryOperatorKind @0xd9e4cf844656d8e6 {
  postUcIncrement @0;
  postUcDec @1;
  preUcIncrement @2;
  preUcDec @3;
  addrUcOf @4;
  deref @5;
  plus @6;
  minus @7;
  not @8;
  lNot @9;
  real @10;
  imag @11;
  extension @12;
  coawait @13;
}

enum TypeTrait @0xf7e0a1b4b1fe1e7a {
  isUcInterfaceUcClass @0;
  isUcSealed @1;
  isUcDestructible @2;
  isUcTriviallyUcDestructible @3;
  isUcNothrowUcDestructible @4;
  hasUcNothrowUcMoveUcAssign @5;
  hasUcTrivialUcMoveUcAssign @6;
  hasUcTrivialUcMoveUcConstructor @7;
  hasUcNothrowUcAssign @8;
  hasUcNothrowUcCopy @9;
  hasUcNothrowUcConstructor @10;
  hasUcTrivialUcAssign @11;
  hasUcTrivialUcCopy @12;
  hasUcTrivialUcDefaultUcConstructor @13;
  hasUcTrivialUcDestructor @14;
  hasUcVirtualUcDestructor @15;
  isUcAbstract @16;
  isUcAggregate @17;
  isUcClass @18;
  isUcEmpty @19;
  isUcEnum @20;
  isUcFinal @21;
  isUcLiteral @22;
  isPod @23;
  isUcPolymorphic @24;
  isUcStandardUcLayout @25;
  isUcTrivial @26;
  isUcTriviallyUcCopyable @27;
  isUcUnion @28;
  hasUcUniqueUcObjectUcRepresentations @29;
  isUcArithmetic @30;
  isUcFloatingUcPoint @31;
  isUcIntegral @32;
  isUcCompleteUcType @33;
  isUcVoid @34;
  isUcArray @35;
  isUcFunction @36;
  isUcReference @37;
  isUcLvalueUcReference @38;
  isUcRvalueUcReference @39;
  isUcFundamental @40;
  isUcObject @41;
  isUcScalar @42;
  isUcCompound @43;
  isUcPointer @44;
  isUcMemberUcObjectUcPointer @45;
  isUcMemberUcFunctionUcPointer @46;
  isUcMemberUcPointer @47;
  isUcConst @48;
  isUcVolatile @49;
  isUcSigned @50;
  isUcUnsigned @51;
  typeUcCompatible @52;
  isUcNothrowUcAssignable @53;
  isUcAssignable @54;
  isUcBaseUcOf @55;
  isUcConvertibleUcTo @56;
  isUcTriviallyUcAssignable @57;
  referenceUcBindsUcToUcTemporary @58;
  isUcSame @59;
  isUcConvertible @60;
  isUcConstructible @61;
  isUcNothrowUcConstructible @62;
  isUcTriviallyUcConstructible @63;
}

enum APValueKind @0xcb98d416d4611f2f {
  none @0;
  indeterminate @1;
  int @2;
  float @3;
  fixedUcPoint @4;
  complexUcInt @5;
  complexUcFloat @6;
  lValue @7;
  vector @8;
  array @9;
  struct @10;
  union @11;
  memberUcPointer @12;
  addrUcLabelUcDiff @13;
}

enum ResultStorageKind @0xbb78b2b258534591 {
  none @0;
  int64 @1;
  apValue @2;
}

enum ExpressionTrait @0xc0206beabf974c92 {
  isLValueUcExpression @0;
  isRValueUcExpression @1;
}

enum TypeDependence @0xcba0ba47ac5b69e3 {
  unexpandedUcPack @0;
  instantiation @1;
  dependent @2;
  variablyUcModified @3;
  error @4;
  none @5;
  all @6;
  dependentUcInstantiation @7;
}

enum ObjCLifetime @0xa408eab661edd8cd {
  none @0;
  explicitUcNone @1;
  strong @2;
  weak @3;
  autoreleasing @4;
}

enum ScalarTypeKind @0xdacaafd6791835aa {
  cPointer @0;
  blockUcPointer @1;
  objCObjectUcPointer @2;
  memberUcPointer @3;
  boolean @4;
  integral @5;
  floating @6;
  integralUcComplex @7;
  floatingUcComplex @8;
  fixedUcPoint @9;
}

enum TypeKind @0x8eb229be4c525aa3 {
  adjusted @0;
  decayed @1;
  constantUcArray @2;
  dependentUcSizedUcArray @3;
  incompleteUcArray @4;
  variableUcArray @5;
  atomic @6;
  attributed @7;
  blockUcPointer @8;
  builtin @9;
  complex @10;
  decltype @11;
  auto @12;
  deducedUcTemplateUcSpecialization @13;
  dependentUcAddressUcSpace @14;
  dependentUcExtUcInt @15;
  dependentUcName @16;
  dependentUcSizedUcExtUcVector @17;
  dependentUcTemplateUcSpecialization @18;
  dependentUcVector @19;
  elaborated @20;
  extUcInt @21;
  functionUcNoUcProto @22;
  functionUcProto @23;
  injectedUcClassUcName @24;
  macroUcQualified @25;
  constantUcMatrix @26;
  dependentUcSizedUcMatrix @27;
  memberUcPointer @28;
  objCObjectUcPointer @29;
  objCObject @30;
  objCInterface @31;
  objCTypeUcParam @32;
  packUcExpansion @33;
  paren @34;
  pipe @35;
  pointer @36;
  lValueUcReference @37;
  rValueUcReference @38;
  substUcTemplateUcTypeUcParmUcPack @39;
  substUcTemplateUcTypeUcParm @40;
  enum @41;
  record @42;
  templateUcSpecialization @43;
  templateUcTypeUcParm @44;
  typeUcOfUcExpr @45;
  typeUcOf @46;
  typedef @47;
  unaryUcTransform @48;
  unresolvedUcUsing @49;
  vector @50;
  extUcVector @51;
}

enum LangAS @0xbe9184d23b40adbf {
  default @0;
  openclUcGlobal @1;
  openclUcLocal @2;
  openclUcConstant @3;
  openclUcPrivate @4;
  openclUcGeneric @5;
  openclUcGlobalUcDevice @6;
  openclUcGlobalUcHost @7;
  cudaUcDevice @8;
  cudaUcConstant @9;
  cudaUcShared @10;
  syclUcGlobal @11;
  syclUcGlobalUcDevice @12;
  syclUcGlobalUcHost @13;
  syclUcLocal @14;
  syclUcPrivate @15;
  ptr32UcSptr @16;
  ptr32UcUptr @17;
  ptr64 @18;
}

enum PrimitiveCopyKind @0xd987c4779543007c {
  trivial @0;
  volatileUcTrivial @1;
  arcStrong @2;
  arcWeak @3;
  struct @4;
}

enum PrimitiveDefaultInitializeKind @0x8939975a5b04dbb3 {
  trivial @0;
  arcStrong @1;
  arcWeak @2;
  struct @3;
}

enum CallingConv @0xfc49dab6441b4ebd {
  c @0;
  x86UcStdUcCall @1;
  x86UcFastUcCall @2;
  x86UcThisUcCall @3;
  x86UcVectorUcCall @4;
  x86UcPascal @5;
  win64 @6;
  x8664UcSysV @7;
  x86UcRegUcCall @8;
  aapcs @9;
  aapcsvfp @10;
  intelUcOclUcBicc @11;
  spirUcFunction @12;
  openClKernel @13;
  swift @14;
  swiftUcAsync @15;
  preserveUcMost @16;
  preserveUcAll @17;
  aArch64UcVectorUcCall @18;
}

enum CanThrowResult @0xade719c14c0fa1a7 {
  cannot @0;
  dependent @1;
  can @2;
}

enum VectorKind @0xa2946b86ad43cc82 {
  genericUcVector @0;
  altiUcVecUcVector @1;
  altiUcVecUcPixel @2;
  altiUcVecUcBoolean @3;
  neonUcVector @4;
  neonUcPolyUcVector @5;
  sveUcFixedUcLengthUcDataUcVector @6;
  sveUcFixedUcLengthUcPredicateUcVector @7;
}

enum AutoTypeKeyword @0x8f3df89531320c02 {
  auto @0;
  decltypeUcAuto @1;
  gnuAutoUcType @2;
}

enum AttributeKind @0xea12979c4469acdf {
  addressUcSpace @0;
  armUcMveUcStrictUcPolymorphism @1;
  cmseNsCall @2;
  noUcDeref @3;
  objCgc @4;
  objCInertUcUnsafeUcUnretained @5;
  objCKindUcOf @6;
  openClConstantUcAddressUcSpace @7;
  openClGenericUcAddressUcSpace @8;
  openClGlobalUcAddressUcSpace @9;
  openClGlobalUcDeviceUcAddressUcSpace @10;
  openClGlobalUcHostUcAddressUcSpace @11;
  openClLocalUcAddressUcSpace @12;
  openClPrivateUcAddressUcSpace @13;
  ptr32 @14;
  ptr64 @15;
  sPtr @16;
  typeUcNonUcNull @17;
  typeUcNullUcUnspecified @18;
  typeUcNullable @19;
  typeUcNullableUcResult @20;
  uPtr @21;
  fallUcThrough @22;
  likely @23;
  mustUcTail @24;
  openClUnrollUcHint @25;
  suppress @26;
  unlikely @27;
  noUcMerge @28;
  aArch64UcVectorUcPcs @29;
  acquireUcHandle @30;
  anyX86UcNoUcCfUcCheck @31;
  cDecl @32;
  fastUcCall @33;
  intelUcOclUcBicc @34;
  lifetimeUcBound @35;
  msabi @36;
  nsReturnsUcRetained @37;
  objCOwnership @38;
  pascal @39;
  pcs @40;
  preserveUcAll @41;
  preserveUcMost @42;
  regUcCall @43;
  stdUcCall @44;
  swiftUcAsyncUcCall @45;
  swiftUcCall @46;
  sysVabi @47;
  thisUcCall @48;
  vectorUcCall @49;
  swiftUcAsyncUcContext @50;
  swiftUcContext @51;
  swiftUcErrorUcResult @52;
  swiftUcIndirectUcResult @53;
  annotate @54;
  cfConsumed @55;
  carriesUcDependency @56;
  nsConsumed @57;
  nonUcNull @58;
  osConsumed @59;
  passUcObjectUcSize @60;
  releaseUcHandle @61;
  useUcHandle @62;
  amdgpuFlatUcWorkUcGroupUcSize @63;
  amdgpuNumSgpr @64;
  amdgpuNumVgpr @65;
  amdgpuWavesUcPerEu @66;
  armInterrupt @67;
  avrInterrupt @68;
  avrSignal @69;
  acquireUcCapability @70;
  acquiredUcAfter @71;
  acquiredUcBefore @72;
  alignUcMac68k @73;
  alignUcNatural @74;
  aligned @75;
  allocUcAlign @76;
  allocUcSize @77;
  alwaysUcDestroy @78;
  alwaysUcInline @79;
  analyzerUcNoUcReturn @80;
  anyX86UcInterrupt @81;
  anyX86UcNoUcCallerUcSavedUcRegisters @82;
  arcUcWeakrefUcUnavailable @83;
  argumentUcWithUcTypeUcTag @84;
  armUcBuiltinUcAlias @85;
  artificial @86;
  assemblyUcLabel @87;
  assertUcCapability @88;
  assertUcExclusiveUcLock @89;
  assertUcSharedUcLock @90;
  assumeUcAligned @91;
  assumption @92;
  availability @93;
  bpfPreserveUcAccessUcIndex @94;
  blocks @95;
  builtin @96;
  c11UcNoUcReturn @97;
  cfAuditedUcTransfer @98;
  cfGuard @99;
  cfiCanonicalUcJumpUcTable @100;
  cfReturnsUcNotUcRetained @101;
  cfReturnsUcRetained @102;
  cfUnknownUcTransfer @103;
  cpuDispatch @104;
  cpuSpecific @105;
  cudaConstant @106;
  cudaDevice @107;
  cudaDeviceUcBuiltinUcSurfaceUcType @108;
  cudaDeviceUcBuiltinUcTextureUcType @109;
  cudaGlobal @110;
  cudaHost @111;
  cudaInvalidUcTarget @112;
  cudaLaunchUcBounds @113;
  cudaShared @114;
  cxx11UcNoUcReturn @115;
  callableUcWhen @116;
  callback @117;
  capability @118;
  capturedUcRecord @119;
  cleanup @120;
  cmseNsEntry @121;
  codeUcSeg @122;
  cold @123;
  common @124;
  const @125;
  constUcInitializer @126;
  constructor @127;
  consumable @128;
  consumableUcAutoUcCast @129;
  consumableUcSetUcOnUcRead @130;
  convergent @131;
  dllExport @132;
  dllExportUcStaticUcLocal @133;
  dllImport @134;
  dllImportUcStaticUcLocal @135;
  deprecated @136;
  destructor @137;
  diagnoseUcIf @138;
  disableUcTailUcCalls @139;
  emptyUcBases @140;
  enableUcIf @141;
  enforceTcb @142;
  enforceTcbLeaf @143;
  enumUcExtensibility @144;
  excludeUcFromUcExplicitUcInstantiation @145;
  exclusiveUcTrylockUcFunction @146;
  externalUcSourceUcSymbol @147;
  final @148;
  flagUcEnum @149;
  flatten @150;
  format @151;
  formatUcArgument @152;
  gnuInline @153;
  guardedUcBy @154;
  guardedUcVariable @155;
  hipManaged @156;
  hot @157;
  ibAction @158;
  ibOutlet @159;
  ibOutletUcCollection @160;
  initializerUcPriority @161;
  internalUcLinkage @162;
  ltoVisibilityUcPublic @163;
  layoutUcVersion @164;
  leaf @165;
  lockUcReturned @166;
  locksUcExcluded @167;
  m68kUcInterrupt @168;
  migServerUcRoutine @169;
  msAllocator @170;
  msInheritance @171;
  msNoVTable @172;
  msp430UcInterrupt @173;
  msStruct @174;
  msVtorUcDisp @175;
  maxUcFieldUcAlignment @176;
  mayUcAlias @177;
  microUcMips @178;
  minUcSize @179;
  minUcVectorUcWidth @180;
  mips16 @181;
  mipsUcInterrupt @182;
  mipsUcLongUcCall @183;
  mipsUcShortUcCall @184;
  nsConsumesUcSelf @185;
  nsErrorUcDomain @186;
  nsReturnsUcAutoreleased @187;
  nsReturnsUcNotUcRetained @188;
  naked @189;
  noUcAlias @190;
  noUcCommon @191;
  noUcDebug @192;
  noUcDestroy @193;
  noUcDuplicate @194;
  noUcInline @195;
  noUcInstrumentUcFunction @196;
  noUcMicroUcMips @197;
  noUcMips16 @198;
  noUcProfileUcFunction @199;
  noUcReturn @200;
  noUcSanitize @201;
  noUcSpeculativeUcLoadUcHardening @202;
  noUcSplitUcStack @203;
  noUcStackUcProtector @204;
  noUcThreadUcSafetyUcAnalysis @205;
  noUcThrow @206;
  noUcUniqueUcAddress @207;
  notUcTailUcCalled @208;
  ompAllocateUcDeclaration @209;
  ompCaptureUcNoUcInitializer @210;
  ompDeclareUcTargetUcDeclaration @211;
  ompDeclareUcVariant @212;
  ompThreadUcPrivateUcDeclaration @213;
  osConsumesUcThis @214;
  osReturnsUcNotUcRetained @215;
  osReturnsUcRetained @216;
  osReturnsUcRetainedUcOnUcNonUcZero @217;
  osReturnsUcRetainedUcOnUcZero @218;
  objCBridge @219;
  objCBridgeUcMutable @220;
  objCBridgeUcRelated @221;
  objCException @222;
  objCExplicitUcProtocolUcImplementation @223;
  objCExternallyUcRetained @224;
  objCIndependentUcClass @225;
  objCMethodUcFamily @226;
  objCnsObject @227;
  objCPreciseUcLifetime @228;
  objCRequiresUcPropertyUcDefinitions @229;
  objCRequiresUcSuper @230;
  objCReturnsUcInnerUcPointer @231;
  objCRootUcClass @232;
  objCSubclassingUcRestricted @233;
  openClIntelUcReqdUcSubUcGroupUcSize @234;
  openClKernel @235;
  optimizeUcNone @236;
  override @237;
  owner @238;
  ownership @239;
  packed @240;
  paramUcTypestate @241;
  patchableUcFunctionUcEntry @242;
  pointer @243;
  pragmaUcClangBssSection @244;
  pragmaUcClangUcDataUcSection @245;
  pragmaUcClangUcRelroUcSection @246;
  pragmaUcClangUcRodataUcSection @247;
  pragmaUcClangUcTextUcSection @248;
  preferredUcName @249;
  ptUcGuardedUcBy @250;
  ptUcGuardedUcVariable @251;
  pure @252;
  riscvInterrupt @253;
  reinitializes @254;
  releaseUcCapability @255;
  reqdUcWorkUcGroupUcSize @256;
  requiresUcCapability @257;
  restrict @258;
  retain @259;
  returnUcTypestate @260;
  returnsUcNonUcNull @261;
  returnsUcTwice @262;
  syclKernel @263;
  scopedUcLockable @264;
  section @265;
  selectUcAny @266;
  sentinel @267;
  setUcTypestate @268;
  sharedUcTrylockUcFunction @269;
  speculativeUcLoadUcHardening @270;
  standaloneUcDebug @271;
  strictFp @272;
  swiftUcAsync @273;
  swiftUcAsyncUcError @274;
  swiftUcAsyncUcName @275;
  swiftUcAttribute @276;
  swiftUcBridge @277;
  swiftUcBridgedUcTypedef @278;
  swiftUcError @279;
  swiftUcName @280;
  swiftUcNewUcType @281;
  swiftUcPrivate @282;
  tlsModel @283;
  target @284;
  testUcTypestate @285;
  transparentUcUnion @286;
  trivialAbi @287;
  tryUcAcquireUcCapability @288;
  typeUcTagUcForUcDatatype @289;
  typeUcVisibility @290;
  unavailable @291;
  uninitialized @292;
  unused @293;
  used @294;
  usingUcIfUcExists @295;
  uuid @296;
  vecUcReturn @297;
  vecUcTypeUcHint @298;
  visibility @299;
  warnUcUnused @300;
  warnUcUnusedUcResult @301;
  weak @302;
  weakUcImport @303;
  weakUcReference @304;
  webUcAssemblyUcExportUcName @305;
  webUcAssemblyUcImportUcModule @306;
  webUcAssemblyUcImportUcName @307;
  workUcGroupUcSizeUcHint @308;
  x86UcForceUcAlignUcArgumentUcPointer @309;
  xRayUcInstrument @310;
  xRayUcLogUcArguments @311;
  abiUcTag @312;
  alias @313;
  alignUcValue @314;
  builtinUcAlias @315;
  calledUcOnce @316;
  iFunc @317;
  initializerUcSeg @318;
  loaderUcUninitialized @319;
  loopUcHint @320;
  mode @321;
  noUcBuiltin @322;
  noUcEscape @323;
  ompCaptureUcKind @324;
  ompDeclareUcSimdUcDeclaration @325;
  ompReferencedUcVariable @326;
  objCBoxable @327;
  objCClassUcStub @328;
  objCDesignatedUcInitializer @329;
  objCDirect @330;
  objCDirectUcMembers @331;
  objCNonUcLazyUcClass @332;
  objCNonUcRuntimeUcProtocol @333;
  objCRuntimeUcName @334;
  objCRuntimeUcVisible @335;
  openClAccess @336;
  overloadable @337;
  renderUcScriptUcKernel @338;
  swiftUcObjCMembers @339;
  thread @340;
}

enum ArraySizeModifier @0xf6f70035a2bc22f6 {
  normal @0;
  static @1;
  star @2;
}

enum UTTKind @0xe3ac3858dbe51a16 {
  enumUcUnderlyingUcType @0;
}

struct TokenOffset @0x8a47d77b57b46cd5 {
  offset @0 :UInt32 $Cxx.name("offset");
}

struct TokenRange @0xfaaa666ba10b6696 {
  beginOffset @0 :UInt32 $Cxx.name("begin_offset");
  endOffset @1 :UInt32 $Cxx.name("end_offset");  # Inclusive.
}

struct Decl @0xfb5879761ffaedb6 {
  access @0 :AccessSpecifier;
  accessUcUnsafe @1 :AccessSpecifier;
  availability @2 :AvailabilityResult;
  beginUcToken @3 :TokenOffset;
  bodyRBrace @4 :TokenOffset;
  endUcToken @5 :TokenOffset;
  friendUcObjectUcKind @6 :FriendObjectKind;
  moduleUcOwnershipUcKind @7 :ModuleOwnershipKind;
  hasUcAttributes @8 :Bool;
  hasUcBody @9 :Bool;
  hasUcDefiningUcAttribute @10 :Bool;
  hasUcOwningUcModule @11 :Bool;
  hasUcTagUcIdentifierUcNamespace @12 :Bool;
  isUcCanonicalUcDeclaration @13 :Bool;
  isUcDefinedUcOutsideUcFunctionUcOrUcMethod @14 :Bool;
  isUcDeprecated @15 :Bool;
  isUcFirstUcDeclaration @16 :Bool;
  isUcFromAstFile @17 :Bool;
  isUcFunctionUcOrUcFunctionUcTemplate @18 :Bool;
  isUcImplicit @19 :Bool;
  isUcInUcAnonymousUcNamespace @20 :Bool;
  isUcInUcLocalUcScopeUcForUcInstantiation @21 :Bool;
  isUcInUcStdUcNamespace @22 :Bool;
  isUcInvalidUcDeclaration @23 :Bool;
  isUcModuleUcPrivate @24 :Bool;
  isUcOutUcOfUcLine @25 :Bool;
  isUcParameterUcPack @26 :Bool;
  isUcReferenced @27 :Bool;
  isUcTemplateUcDeclaration @28 :Bool;
  isUcTemplateUcParameter @29 :Bool;
  isUcTemplateUcParameterUcPack @30 :Bool;
  isUcTemplated @31 :Bool;
  isUcThisUcDeclarationUcReferenced @32 :Bool;
  isUcTopUcLevelUcDeclarationUcInUcObjCContainer @33 :Bool;
  isUcUnavailable @34 :Bool;
  isUcUnconditionallyUcVisible @35 :Bool;
  isUcUsed @36 :Bool;
  isUcWeakUcImported @37 :Bool;
  kind @38 :DeclKind;
  token @39 :TokenOffset;
  tokenUcRange @40 :TokenRange;
}

struct ClassScopeFunctionSpecializationDecl @0x99eb38d6a1065986 {
  decl @0:Decl;
  hasUcExplicitUcTemplateUcArguments @1 :Bool;
}

struct CapturedDecl @0xa1c847e4871d0b0a {
  decl @0:Decl;
  isUcNothrow @1 :Bool;
}

struct BlockDecl @0xd21c906a9e197a51 {
  decl @0:Decl;
  blockUcMissingUcReturnUcType @1 :Bool;
  canUcAvoidUcCopyUcToUcHeap @2 :Bool;
  capturesCxxThis @3 :Bool;
  doesUcNotUcEscape @4 :Bool;
  caretUcToken @5 :TokenOffset;
  hasUcCaptures @6 :Bool;
  isUcConversionUcFromUcLambda @7 :Bool;
  isUcVariadic @8 :Bool;
}

struct AccessSpecDecl @0xe671324616f83d3c {
  decl @0:Decl;
  accessUcSpecifierUcToken @1 :TokenOffset;
  colonUcToken @2 :TokenOffset;
}

struct TranslationUnitDecl @0x84ba694d5be7caa3 {
  decl @0:Decl;
}

struct StaticAssertDecl @0xe3ab98945466226a {
  decl @0:Decl;
  rParenUcToken @1 :TokenOffset;
  isUcFailed @2 :Bool;
}

struct RequiresExprBodyDecl @0x9eea1ed94972a3a6 {
  decl @0:Decl;
}

struct PragmaDetectMismatchDecl @0xc2be564c48472f5d {
  decl @0:Decl;
  name @1 :Text;
  value @2 :Text;
}

struct PragmaCommentDecl @0xa32a66c4f91015cb {
  decl @0:Decl;
  argument @1 :Text;
  commentUcKind @2 :PragmaMSCommentKind;
}

struct ObjCPropertyImplDecl @0x9c45df6dc848c200 {
  decl @0:Decl;
  propertyUcInstanceUcVariableUcDeclarationUcToken @1 :TokenOffset;
  isUcInstanceUcVariableUcNameUcSpecified @2 :Bool;
}

struct NamedDecl @0xee8ff2639c85feae {
  decl @0:Decl;
  formalUcLinkage @1 :Linkage;
  linkageUcInternal @2 :Linkage;
  name @3 :Text;
  objCfStringUcFormattingUcFamily @4 :ObjCStringFormatFamily;
  qualifiedUcNameUcAsUcString @5 :Text;
  visibility @6 :Visibility;
  hasUcExternalUcFormalUcLinkage @7 :Bool;
  hasUcLinkage @8 :Bool;
  hasUcLinkageUcBeenUcComputed @9 :Bool;
  isCxxClassUcMember @10 :Bool;
  isCxxInstanceUcMember @11 :Bool;
  isUcExternallyUcDeclarable @12 :Bool;
  isUcExternallyUcVisible @13 :Bool;
  isUcLinkageUcValid @14 :Bool;
}

struct LabelDecl @0x959116a0b50f04fe {
  namedUcDecl @0:NamedDecl;
  msAssemblyUcLabel @1 :Text;
  isUcGnuUcLocal @2 :Bool;
  isMsAssemblyUcLabel @3 :Bool;
  isUcResolvedMsAssemblyUcLabel @4 :Bool;
}

struct BaseUsingDecl @0xd779d676819e5d07 {
  namedUcDecl @0:NamedDecl;
}

struct UsingEnumDecl @0xa824f691f72f9236 {
  baseUcUsingUcDecl @0:BaseUsingDecl;
  enumUcToken @1 :TokenOffset;
  usingUcToken @2 :TokenOffset;
}

struct UsingDecl @0xb8602dcb3f95c179 {
  baseUcUsingUcDecl @0:BaseUsingDecl;
  usingUcToken @1 :TokenOffset;
  hasUcTypename @2 :Bool;
  isUcAccessUcDeclaration @3 :Bool;
}

struct ValueDecl @0xe2704a366b05e616 {
  namedUcDecl @0:NamedDecl;
  isUcWeak @1 :Bool;
}

struct UnresolvedUsingValueDecl @0x8ad2fc298aa43ab1 {
  valueUcDecl @0:ValueDecl;
  ellipsisUcToken @1 :TokenOffset;
  usingUcToken @2 :TokenOffset;
  isUcAccessUcDeclaration @3 :Bool;
  isUcPackUcExpansion @4 :Bool;
}

struct TemplateParamObjectDecl @0xd09f17939d7cc847 {
  valueUcDecl @0:ValueDecl;
}

struct OMPDeclareReductionDecl @0xf59daefbeeafc092 {
  valueUcDecl @0:ValueDecl;
}

struct MSGuidDecl @0x9ef09ebc4be76711 {
  valueUcDecl @0:ValueDecl;
}

struct IndirectFieldDecl @0xf8f906fde6cb040f {
  valueUcDecl @0:ValueDecl;
}

struct EnumConstantDecl @0xe2b34f222cdb8877 {
  valueUcDecl @0:ValueDecl;
}

struct DeclaratorDecl @0xb95593a177af5810 {
  valueUcDecl @0:ValueDecl;
  innerUcTokenUcStart @1 :TokenOffset;
  outerUcTokenUcStart @2 :TokenOffset;
  typeUcSpecUcEndUcToken @3 :TokenOffset;
  typeUcSpecUcStartUcToken @4 :TokenOffset;
}

struct VarDecl @0xcf9adcbc59a4e339 {
  declaratorUcDecl @0:DeclaratorDecl;
  languageUcLinkage @1 :LanguageLinkage;
  pointUcOfUcInstantiation @2 :TokenOffset;
  storageUcClass @3 :StorageClass;
  storageUcDuration @4 :StorageDuration;
  tscSpec @5 :ThreadStorageClassSpecifier;
  templateUcSpecializationUcKind @6 :TemplateSpecializationKind;
  templateUcSpecializationUcKindUcForUcInstantiation @7 :TemplateSpecializationKind;
  hasUcConstantUcInitialization @8 :Bool;
  hasUcDependentUcAlignment @9 :Bool;
  hasUcExternalUcStorage @10 :Bool;
  hasUcGlobalUcStorage @11 :Bool;
  hasIceInitializer @12 :Bool;
  hasUcInitializer @13 :Bool;
  hasUcLocalUcStorage @14 :Bool;
  isArcPseudoUcStrong @15 :Bool;
  isCxxForUcRangeUcDeclaration @16 :Bool;
  isUcConstexpr @17 :Bool;
  isUcDirectUcInitializer @18 :Bool;
  isUcEscapingUcByref @19 :Bool;
  isUcExceptionUcVariable @20 :Bool;
  isUcExternC @21 :Bool;
  isUcFileUcVariableUcDeclaration @22 :Bool;
  isUcFunctionUcOrUcMethodUcVariableUcDeclaration @23 :Bool;
  isUcInUcExternCContext @24 :Bool;
  isUcInUcExternCxxContext @25 :Bool;
  isUcInitializerUcCapture @26 :Bool;
  isUcInline @27 :Bool;
  isUcInlineUcSpecified @28 :Bool;
  isUcKnownUcToUcBeUcDefined @29 :Bool;
  isUcLocalUcVariableUcDeclaration @30 :Bool;
  isUcLocalUcVariableUcDeclarationUcOrUcParm @31 :Bool;
  isNrvoVariable @32 :Bool;
  isUcNoUcDestroy @33 :Bool;
  isUcNonUcEscapingUcByref @34 :Bool;
  isUcObjCForUcDeclaration @35 :Bool;
  isUcPreviousUcDeclarationUcInUcSameUcBlockUcScope @36 :Bool;
  isUcStaticUcDataUcMember @37 :Bool;
  isUcStaticUcLocal @38 :Bool;
  isUcThisUcDeclarationADemotedUcDefinition @39 :Bool;
  isUcUsableUcInUcConstantUcExpressions @40 :Bool;
  mightUcBeUcUsableUcInUcConstantUcExpressions @41 :Bool;
}

struct ParmVarDecl @0xedf01c1d7684de38 {
  varUcDecl @0:VarDecl;
  defaultUcArgumentUcRange @1 :TokenRange;
  hasUcDefaultUcArgument @2 :Bool;
  hasUcInheritedUcDefaultUcArgument @3 :Bool;
  hasUcUninstantiatedUcDefaultUcArgument @4 :Bool;
  hasUcUnparsedUcDefaultUcArgument @5 :Bool;
  isUcDestroyedUcInUcCallee @6 :Bool;
  isKnrPromoted @7 :Bool;
  isUcObjCMethodUcParameter @8 :Bool;
}

struct OMPCapturedExprDecl @0x8dae8ad443b5cf77 {
  varUcDecl @0:VarDecl;
}

struct ImplicitParamDecl @0x9482ac8d963f562c {
  varUcDecl @0:VarDecl;
  parameterUcKind @1 :ImplicitParamKind;
}

struct DecompositionDecl @0xd32bcfb0d1a2facb {
  varUcDecl @0:VarDecl;
}

struct VarTemplateSpecializationDecl @0xbaf3e3ed90ea85e0 {
  varUcDecl @0:VarDecl;
  externUcToken @1 :TokenOffset;
  specializationUcKind @2 :TemplateSpecializationKind;
  templateUcKeywordUcToken @3 :TokenOffset;
  isUcClassUcScopeUcExplicitUcSpecialization @4 :Bool;
  isUcExplicitUcInstantiationUcOrUcSpecialization @5 :Bool;
  isUcExplicitUcSpecialization @6 :Bool;
}

struct VarTemplatePartialSpecializationDecl @0xe1d0f96cb9fa250f {
  varUcTemplateUcSpecializationUcDecl @0:VarTemplateSpecializationDecl;
  hasUcAssociatedUcConstraints @1 :Bool;
}

struct NonTypeTemplateParmDecl @0x964d2872d52f2d65 {
  declaratorUcDecl @0:DeclaratorDecl;
  defaultUcArgumentUcWasUcInherited @1 :Bool;
  defaultUcArgumentUcToken @2 :TokenOffset;
  hasUcDefaultUcArgument @3 :Bool;
  hasUcPlaceholderUcTypeUcConstraint @4 :Bool;
  isUcExpandedUcParameterUcPack @5 :Bool;
  isUcPackUcExpansion @6 :Bool;
}

struct MSPropertyDecl @0x9a46ca50a3ae900f {
  declaratorUcDecl @0:DeclaratorDecl;
  hasUcGetter @1 :Bool;
  hasUcSetter @2 :Bool;
}

struct FunctionDecl @0x92bd4789888f8ccb {
  declaratorUcDecl @0:DeclaratorDecl;
  doesUcDeclarationUcForceUcExternallyUcVisibleUcDefinition @1 :Bool;
  doesUcThisUcDeclarationUcHaveABody @2 :Bool;
  constexprUcKind @3 :ConstexprSpecKind;
  ellipsisUcToken @4 :TokenOffset;
  exceptionUcSpecUcSourceUcRange @5 :TokenRange;
  exceptionUcSpecUcType @6 :ExceptionSpecificationType;
  languageUcLinkage @7 :LanguageLinkage;
  multiUcVersionUcKind @8 :MultiVersionKind;
  overloadedUcOperator @9 :OverloadedOperatorKind;
  parametersUcSourceUcRange @10 :TokenRange;
  pointUcOfUcInstantiation @11 :TokenOffset;
  returnUcTypeUcSourceUcRange @12 :TokenRange;
  storageUcClass @13 :StorageClass;
  templateUcSpecializationUcKind @14 :TemplateSpecializationKind;
  templateUcSpecializationUcKindUcForUcInstantiation @15 :TemplateSpecializationKind;
  hasUcImplicitUcReturnUcZero @16 :Bool;
  hasUcInheritedUcPrototype @17 :Bool;
  hasUcOneUcParamUcOrUcDefaultUcArguments @18 :Bool;
  hasUcPrototype @19 :Bool;
  hasUcSkippedUcBody @20 :Bool;
  hasUcTrivialUcBody @21 :Bool;
  hasUcWrittenUcPrototype @22 :Bool;
  instantiationUcIsUcPending @23 :Bool;
  isCpuDispatchUcMultiUcVersion @24 :Bool;
  isCpuSpecificUcMultiUcVersion @25 :Bool;
  isUcConsteval @26 :Bool;
  isUcConstexpr @27 :Bool;
  isUcConstexprUcSpecified @28 :Bool;
  isUcDefaulted @29 :Bool;
  isUcDeleted @30 :Bool;
  isUcDeletedUcAsUcWritten @31 :Bool;
  isUcDestroyingUcOperatorUcDelete @32 :Bool;
  isUcExplicitlyUcDefaulted @33 :Bool;
  isUcExternC @34 :Bool;
  isUcFunctionUcTemplateUcSpecialization @35 :Bool;
  isUcGlobal @36 :Bool;
  isUcImplicitlyUcInstantiable @37 :Bool;
  isUcInUcExternCContext @38 :Bool;
  isUcInUcExternCxxContext @39 :Bool;
  isUcInlineUcBuiltinUcDeclaration @40 :Bool;
  isUcInlineUcDefinitionUcExternallyUcVisible @41 :Bool;
  isUcInlineUcSpecified @42 :Bool;
  isUcInlined @43 :Bool;
  isUcLateUcTemplateUcParsed @44 :Bool;
  isMsExternUcInline @45 :Bool;
  isMsvcrtEntryUcPoint @46 :Bool;
  isUcMain @47 :Bool;
  isUcMultiUcVersion @48 :Bool;
  isUcNoUcReturn @49 :Bool;
  isUcOverloadedUcOperator @50 :Bool;
  isUcPure @51 :Bool;
  isUcReplaceableUcGlobalUcAllocationUcFunction @52 :Bool;
  isUcReservedUcGlobalUcPlacementUcOperator @53 :Bool;
  isUcStatic @54 :Bool;
  isUcTargetUcMultiUcVersion @55 :Bool;
  isUcTemplateUcInstantiation @56 :Bool;
  isUcThisUcDeclarationADefinition @57 :Bool;
  isUcThisUcDeclarationUcInstantiatedUcFromAFriendUcDefinition @58 :Bool;
  isUcTrivial @59 :Bool;
  isUcTrivialUcForUcCall @60 :Bool;
  isUcUserUcProvided @61 :Bool;
  isUcVariadic @62 :Bool;
  isUcVirtualUcAsUcWritten @63 :Bool;
  usesSehTry @64 :Bool;
  willUcHaveUcBody @65 :Bool;
}

struct CXXMethodDecl @0xd83d5835cf6512db {
  functionUcDecl @0:FunctionDecl;
  referenceUcQualifier @1 :RefQualifierKind;
  hasUcInlineUcBody @2 :Bool;
  isUcConst @3 :Bool;
  isUcCopyUcAssignmentUcOperator @4 :Bool;
  isUcInstance @5 :Bool;
  isUcLambdaUcStaticUcInvoker @6 :Bool;
  isUcMoveUcAssignmentUcOperator @7 :Bool;
  isUcVirtual @8 :Bool;
  isUcVolatile @9 :Bool;
}

struct CXXDestructorDecl @0xee0fd0438430a21c {
  cxxMethodUcDecl @0:CXXMethodDecl;
}

struct CXXConversionDecl @0xac531836739115b2 {
  cxxMethodUcDecl @0:CXXMethodDecl;
  isUcExplicit @1 :Bool;
  isUcLambdaUcToUcBlockUcPointerUcConversion @2 :Bool;
}

struct CXXConstructorDecl @0xc6bfa2c4650464b8 {
  cxxMethodUcDecl @0:CXXMethodDecl;
  isUcConvertingUcConstructor @1 :Bool;
  isUcDefaultUcConstructor @2 :Bool;
  isUcDelegatingUcConstructor @3 :Bool;
  isUcExplicit @4 :Bool;
  isUcInheritingUcConstructor @5 :Bool;
  isUcSpecializationUcCopyingUcObject @6 :Bool;
}

struct CXXDeductionGuideDecl @0xca6c78b5c1634d9d {
  functionUcDecl @0:FunctionDecl;
  isUcCopyUcDeductionUcCandidate @1 :Bool;
  isUcExplicit @2 :Bool;
}

struct FieldDecl @0xec8d79b82b91a5eb {
  declaratorUcDecl @0:DeclaratorDecl;
  inUcClassUcInitializerUcStyle @1 :InClassInitStyle;
  hasUcCapturedVlaType @2 :Bool;
  hasUcInUcClassUcInitializer @3 :Bool;
  isUcAnonymousUcStructUcOrUcUnion @4 :Bool;
  isUcBitUcField @5 :Bool;
  isUcMutable @6 :Bool;
  isUcUnnamedUcBitfield @7 :Bool;
  isUcZeroUcLengthUcBitUcField @8 :Bool;
  isUcZeroUcSize @9 :Bool;
}

struct ObjCIvarDecl @0xfd0f42a085839510 {
  fieldUcDecl @0:FieldDecl;
  synthesize @1 :Bool;
}

struct ObjCAtDefsFieldDecl @0xd8b002eb70c258c6 {
  fieldUcDecl @0:FieldDecl;
}

struct BindingDecl @0xe77651068f3e1703 {
  valueUcDecl @0:ValueDecl;
}

struct UsingShadowDecl @0xef25bc2e71e7534e {
  namedUcDecl @0:NamedDecl;
}

struct ConstructorUsingShadowDecl @0x8a43df80c48b7033 {
  usingUcShadowUcDecl @0:UsingShadowDecl;
  constructsUcVirtualUcBase @1 :Bool;
}

struct UsingPackDecl @0xf68edcc97d568bee {
  namedUcDecl @0:NamedDecl;
}

struct UsingDirectiveDecl @0xf383b9039044d6f8 {
  namedUcDecl @0:NamedDecl;
  identifierUcToken @1 :TokenOffset;
  namespaceUcKeyUcToken @2 :TokenOffset;
  usingUcToken @3 :TokenOffset;
}

struct UnresolvedUsingIfExistsDecl @0x82421c5826bd81e2 {
  namedUcDecl @0:NamedDecl;
}

struct TypeDecl @0xd349fa911db2de42 {
  namedUcDecl @0:NamedDecl;
}

struct TemplateTypeParmDecl @0x87eba729b34d198a {
  typeUcDecl @0:TypeDecl;
  defaultUcArgumentUcWasUcInherited @1 :Bool;
  defaultUcArgumentUcToken @2 :TokenOffset;
  hasUcDefaultUcArgument @3 :Bool;
  hasUcTypeUcConstraint @4 :Bool;
  isUcExpandedUcParameterUcPack @5 :Bool;
  isUcPackUcExpansion @6 :Bool;
  wasUcDeclaredUcWithUcTypename @7 :Bool;
}

struct TagDecl @0x8e30dcc81a0377d1 {
  typeUcDecl @0:TypeDecl;
  braceUcRange @1 :TokenRange;
  innerUcTokenUcStart @2 :TokenOffset;
  outerUcTokenUcStart @3 :TokenOffset;
  tagUcKind @4 :TagTypeKind;
  hasUcNameUcForUcLinkage @5 :Bool;
  isUcBeingUcDefined @6 :Bool;
  isUcClass @7 :Bool;
  isUcCompleteUcDefinition @8 :Bool;
  isUcCompleteUcDefinitionUcRequired @9 :Bool;
  isUcDependentUcType @10 :Bool;
  isUcEmbeddedUcInUcDeclarator @11 :Bool;
  isUcEnum @12 :Bool;
  isUcFreeUcStanding @13 :Bool;
  isUcInterface @14 :Bool;
  isUcStruct @15 :Bool;
  isUcThisUcDeclarationADefinition @16 :Bool;
  isUcUnion @17 :Bool;
  mayUcHaveUcOutUcOfUcDateUcDefinition @18 :Bool;
}

struct RecordDecl @0xae6dc96296678f51 {
  tagUcDecl @0:TagDecl;
  canUcPassUcInUcRegisters @1 :Bool;
  argumentUcPassingUcRestrictions @2 :ArgPassingKind;
  hasUcFlexibleUcArrayUcMember @3 :Bool;
  hasUcLoadedUcFieldsUcFromUcExternalUcStorage @4 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcCopyCUnion @5 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcDefaultUcInitializeCUnion @6 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcDestructCUnion @7 :Bool;
  hasUcObjectUcMember @8 :Bool;
  hasUcVolatileUcMember @9 :Bool;
  isUcAnonymousUcStructUcOrUcUnion @10 :Bool;
  isUcCapturedUcRecord @11 :Bool;
  isUcInjectedUcClassUcName @12 :Bool;
  isUcLambda @13 :Bool;
  isUcMsUcStruct @14 :Bool;
  isUcNonUcTrivialUcToUcPrimitiveUcCopy @15 :Bool;
  isUcNonUcTrivialUcToUcPrimitiveUcDefaultUcInitialize @16 :Bool;
  isUcNonUcTrivialUcToUcPrimitiveUcDestroy @17 :Bool;
  isUcOrUcContainsUcUnion @18 :Bool;
  isUcParamUcDestroyedUcInUcCallee @19 :Bool;
  mayUcInsertUcExtraUcPadding @20 :Bool;
}

struct CXXRecordDecl @0x9ecc9c9b6a1f56fc {
  recordUcDecl @0:RecordDecl;
  allowUcConstUcDefaultUcInitializer @1 :Bool;
  calculateUcInheritanceUcModel @2 :MSInheritanceModel;
  defaultedUcCopyUcConstructorUcIsUcDeleted @3 :Bool;
  defaultedUcDefaultUcConstructorUcIsUcConstexpr @4 :Bool;
  defaultedUcDestructorUcIsUcConstexpr @5 :Bool;
  defaultedUcDestructorUcIsUcDeleted @6 :Bool;
  defaultedUcMoveUcConstructorUcIsUcDeleted @7 :Bool;
  lambdaUcCaptureUcDefault @8 :LambdaCaptureDefault;
  msInheritanceUcModel @9 :MSInheritanceModel;
  msVtorUcDispUcMode @10 :MSVtorDispMode;
  templateUcSpecializationUcKind @11 :TemplateSpecializationKind;
  hasUcAnyUcDependentUcBases @12 :Bool;
  hasUcConstexprUcDefaultUcConstructor @13 :Bool;
  hasUcConstexprUcDestructor @14 :Bool;
  hasUcConstexprUcNonUcCopyUcMoveUcConstructor @15 :Bool;
  hasUcCopyUcAssignmentUcWithUcConstUcParam @16 :Bool;
  hasUcCopyUcConstructorUcWithUcConstUcParam @17 :Bool;
  hasUcDefaultUcConstructor @18 :Bool;
  hasUcDefinition @19 :Bool;
  hasUcDirectUcFields @20 :Bool;
  hasUcFriends @21 :Bool;
  hasUcInUcClassUcInitializer @22 :Bool;
  hasUcInheritedUcAssignment @23 :Bool;
  hasUcInheritedUcConstructor @24 :Bool;
  hasUcIrrelevantUcDestructor @25 :Bool;
  hasUcKnownUcLambdaUcInternalUcLinkage @26 :Bool;
  hasUcMoveUcAssignment @27 :Bool;
  hasUcMoveUcConstructor @28 :Bool;
  hasUcMutableUcFields @29 :Bool;
  hasUcNonUcLiteralUcTypeUcFieldsUcOrUcBases @30 :Bool;
  hasUcNonUcTrivialUcCopyUcAssignment @31 :Bool;
  hasUcNonUcTrivialUcCopyUcConstructor @32 :Bool;
  hasUcNonUcTrivialUcCopyUcConstructorUcForUcCall @33 :Bool;
  hasUcNonUcTrivialUcDefaultUcConstructor @34 :Bool;
  hasUcNonUcTrivialUcDestructor @35 :Bool;
  hasUcNonUcTrivialUcDestructorUcForUcCall @36 :Bool;
  hasUcNonUcTrivialUcMoveUcAssignment @37 :Bool;
  hasUcNonUcTrivialUcMoveUcConstructor @38 :Bool;
  hasUcNonUcTrivialUcMoveUcConstructorUcForUcCall @39 :Bool;
  hasUcPrivateUcFields @40 :Bool;
  hasUcProtectedUcFields @41 :Bool;
  hasUcSimpleUcCopyUcAssignment @42 :Bool;
  hasUcSimpleUcCopyUcConstructor @43 :Bool;
  hasUcSimpleUcDestructor @44 :Bool;
  hasUcSimpleUcMoveUcAssignment @45 :Bool;
  hasUcSimpleUcMoveUcConstructor @46 :Bool;
  hasUcTrivialUcCopyUcAssignment @47 :Bool;
  hasUcTrivialUcCopyUcConstructor @48 :Bool;
  hasUcTrivialUcCopyUcConstructorUcForUcCall @49 :Bool;
  hasUcTrivialUcDefaultUcConstructor @50 :Bool;
  hasUcTrivialUcDestructor @51 :Bool;
  hasUcTrivialUcDestructorUcForUcCall @52 :Bool;
  hasUcTrivialUcMoveUcAssignment @53 :Bool;
  hasUcTrivialUcMoveUcConstructor @54 :Bool;
  hasUcTrivialUcMoveUcConstructorUcForUcCall @55 :Bool;
  hasUcUninitializedUcReferenceUcMember @56 :Bool;
  hasUcUserUcDeclaredUcConstructor @57 :Bool;
  hasUcUserUcDeclaredUcCopyUcAssignment @58 :Bool;
  hasUcUserUcDeclaredUcCopyUcConstructor @59 :Bool;
  hasUcUserUcDeclaredUcDestructor @60 :Bool;
  hasUcUserUcDeclaredUcMoveUcAssignment @61 :Bool;
  hasUcUserUcDeclaredUcMoveUcConstructor @62 :Bool;
  hasUcUserUcDeclaredUcMoveUcOperation @63 :Bool;
  hasUcUserUcProvidedUcDefaultUcConstructor @64 :Bool;
  hasUcVariantUcMembers @65 :Bool;
  implicitUcCopyUcAssignmentUcHasUcConstUcParam @66 :Bool;
  implicitUcCopyUcConstructorUcHasUcConstUcParam @67 :Bool;
  isUcAbstract @68 :Bool;
  isUcAggregate @69 :Bool;
  isUcAnyUcDestructorUcNoUcReturn @70 :Bool;
  isCLike @71 :Bool;
  isCxx11UcStandardUcLayout @72 :Bool;
  isUcDependentUcLambda @73 :Bool;
  isUcDynamicUcClass @74 :Bool;
  isUcEffectivelyUcFinal @75 :Bool;
  isUcEmpty @76 :Bool;
  isUcGenericUcLambda @77 :Bool;
  isUcInterfaceUcLike @78 :Bool;
  isUcLiteral @79 :Bool;
  isPod @80 :Bool;
  isUcParsingUcBaseUcSpecifiers @81 :Bool;
  isUcPolymorphic @82 :Bool;
  isUcStandardUcLayout @83 :Bool;
  isUcStructural @84 :Bool;
  isUcTrivial @85 :Bool;
  isUcTriviallyUcCopyable @86 :Bool;
  lambdaUcIsUcDefaultUcConstructibleUcAndUcAssignable @87 :Bool;
  mayUcBeUcAbstract @88 :Bool;
  mayUcBeUcDynamicUcClass @89 :Bool;
  mayUcBeUcNonUcDynamicUcClass @90 :Bool;
  needsUcImplicitUcCopyUcAssignment @91 :Bool;
  needsUcImplicitUcCopyUcConstructor @92 :Bool;
  needsUcImplicitUcDefaultUcConstructor @93 :Bool;
  needsUcImplicitUcDestructor @94 :Bool;
  needsUcImplicitUcMoveUcAssignment @95 :Bool;
  needsUcImplicitUcMoveUcConstructor @96 :Bool;
  needsUcOverloadUcResolutionUcForUcCopyUcAssignment @97 :Bool;
  needsUcOverloadUcResolutionUcForUcCopyUcConstructor @98 :Bool;
  needsUcOverloadUcResolutionUcForUcDestructor @99 :Bool;
  needsUcOverloadUcResolutionUcForUcMoveUcAssignment @100 :Bool;
  needsUcOverloadUcResolutionUcForUcMoveUcConstructor @101 :Bool;
  nullUcFieldUcOffsetUcIsUcZero @102 :Bool;
}

struct ClassTemplateSpecializationDecl @0xa81be8b0845933da {
  cxxRecordUcDecl @0:CXXRecordDecl;
  externUcToken @1 :TokenOffset;
  pointUcOfUcInstantiation @2 :TokenOffset;
  specializationUcKind @3 :TemplateSpecializationKind;
  templateUcKeywordUcToken @4 :TokenOffset;
  isUcClassUcScopeUcExplicitUcSpecialization @5 :Bool;
  isUcExplicitUcInstantiationUcOrUcSpecialization @6 :Bool;
  isUcExplicitUcSpecialization @7 :Bool;
}

struct ClassTemplatePartialSpecializationDecl @0x9492104c4b2eff2e {
  classUcTemplateUcSpecializationUcDecl @0:ClassTemplateSpecializationDecl;
  hasUcAssociatedUcConstraints @1 :Bool;
}

struct EnumDecl @0x93540bfa73a13c84 {
  tagUcDecl @0:TagDecl;
  integerUcTypeUcRange @1 :TokenRange;
  templateUcSpecializationUcKind @2 :TemplateSpecializationKind;
  isUcClosed @3 :Bool;
  isUcClosedUcFlag @4 :Bool;
  isUcClosedUcNonUcFlag @5 :Bool;
  isUcComplete @6 :Bool;
  isUcFixed @7 :Bool;
  isUcScoped @8 :Bool;
  isUcScopedUcUsingUcClassUcTag @9 :Bool;
}

struct UnresolvedUsingTypenameDecl @0x8b74c3415940bb24 {
  typeUcDecl @0:TypeDecl;
  ellipsisUcToken @1 :TokenOffset;
  typenameUcToken @2 :TokenOffset;
  usingUcToken @3 :TokenOffset;
  isUcPackUcExpansion @4 :Bool;
}

struct TypedefNameDecl @0xe8f3a8fa9f84b388 {
  typeUcDecl @0:TypeDecl;
  isUcModed @1 :Bool;
  isUcTransparentUcTag @2 :Bool;
}

struct TypedefDecl @0xcabfd592ecdf73ec {
  typedefUcNameUcDecl @0:TypedefNameDecl;
}

struct TypeAliasDecl @0x98b3c141fd82bbdd {
  typedefUcNameUcDecl @0:TypedefNameDecl;
}

struct ObjCTypeParamDecl @0xfea48cce2b1c50cd {
  typedefUcNameUcDecl @0:TypedefNameDecl;
  colonUcToken @1 :TokenOffset;
  variance @2 :ObjCTypeParamVariance;
  varianceUcToken @3 :TokenOffset;
  hasUcExplicitUcBound @4 :Bool;
}

struct TemplateDecl @0x8794861cbdf44fcd {
  namedUcDecl @0:NamedDecl;
  hasUcAssociatedUcConstraints @1 :Bool;
}

struct RedeclarableTemplateDecl @0xeae96325d22b861f {
  templateUcDecl @0:TemplateDecl;
  isUcMemberUcSpecialization @1 :Bool;
}

struct FunctionTemplateDecl @0xc88144c3067080ac {
  redeclarableUcTemplateUcDecl @0:RedeclarableTemplateDecl;
  isUcAbbreviated @1 :Bool;
  isUcThisUcDeclarationADefinition @2 :Bool;
}

struct ClassTemplateDecl @0xd77c8a2532fd776e {
  redeclarableUcTemplateUcDecl @0:RedeclarableTemplateDecl;
  isUcThisUcDeclarationADefinition @1 :Bool;
}

struct VarTemplateDecl @0x983bd212ec53c1f3 {
  redeclarableUcTemplateUcDecl @0:RedeclarableTemplateDecl;
  isUcThisUcDeclarationADefinition @1 :Bool;
}

struct TypeAliasTemplateDecl @0xcafc2a5c9d4a2d22 {
  redeclarableUcTemplateUcDecl @0:RedeclarableTemplateDecl;
}

struct ConceptDecl @0xdbe7c6781c4169e0 {
  templateUcDecl @0:TemplateDecl;
  isUcTypeUcConcept @1 :Bool;
}

struct BuiltinTemplateDecl @0xa84039c6df79998d {
  templateUcDecl @0:TemplateDecl;
}

struct TemplateTemplateParmDecl @0x8481be080ff800b8 {
  templateUcDecl @0:TemplateDecl;
  defaultUcArgumentUcWasUcInherited @1 :Bool;
  defaultUcArgumentUcToken @2 :TokenOffset;
  hasUcDefaultUcArgument @3 :Bool;
  isUcExpandedUcParameterUcPack @4 :Bool;
  isUcPackUcExpansion @5 :Bool;
}

struct ObjCPropertyDecl @0x9eb7f76b62290548 {
  namedUcDecl @0:NamedDecl;
  atUcToken @1 :TokenOffset;
  getterUcNameUcToken @2 :TokenOffset;
  lParenUcToken @3 :TokenOffset;
  propertyUcImplementation @4 :PropertyControl;
  queryUcKind @5 :ObjCPropertyQueryKind;
  setterUcKind @6 :SetterKind;
  setterUcNameUcToken @7 :TokenOffset;
  isUcAtomic @8 :Bool;
  isUcClassUcProperty @9 :Bool;
  isUcDirectUcProperty @10 :Bool;
  isUcInstanceUcProperty @11 :Bool;
  isUcOptional @12 :Bool;
  isUcReadUcOnly @13 :Bool;
  isUcRetaining @14 :Bool;
}

struct ObjCMethodDecl @0xf8c8c7d3c113456e {
  namedUcDecl @0:NamedDecl;
  definedUcInNsObject @1 :Bool;
  declaratorUcEndUcToken @2 :TokenOffset;
  implementationUcControl @3 :ImplementationControl;
  methodUcFamily @4 :ObjCMethodFamily;
  returnUcTypeUcSourceUcRange @5 :TokenRange;
  selectorUcStartUcToken @6 :TokenOffset;
  hasUcRedeclaration @7 :Bool;
  hasUcRelatedUcResultUcType @8 :Bool;
  hasUcSkippedUcBody @9 :Bool;
  isUcClassUcMethod @10 :Bool;
  isUcDefined @11 :Bool;
  isUcDesignatedUcInitializerUcForUcTheUcInterface @12 :Bool;
  isUcDirectUcMethod @13 :Bool;
  isUcInstanceUcMethod @14 :Bool;
  isUcOptional @15 :Bool;
  isUcOverriding @16 :Bool;
  isUcPropertyUcAccessor @17 :Bool;
  isUcRedeclaration @18 :Bool;
  isUcSynthesizedUcAccessorUcStub @19 :Bool;
  isUcThisUcDeclarationADefinition @20 :Bool;
  isUcThisUcDeclarationADesignatedUcInitializer @21 :Bool;
  isUcVariadic @22 :Bool;
}

struct ObjCContainerDecl @0xaf9db5ae0b65ce9e {
  namedUcDecl @0:NamedDecl;
  atUcEndUcRange @1 :TokenRange;
  atUcStartUcToken @2 :TokenOffset;
}

struct ObjCCategoryDecl @0xb673566cbe41a76d {
  objCContainerUcDecl @0:ObjCContainerDecl;
  isUcClassUcExtension @1 :Bool;
  categoryUcNameUcToken @2 :TokenOffset;
  instanceUcVariableLBraceUcToken @3 :TokenOffset;
  instanceUcVariableRBraceUcToken @4 :TokenOffset;
}

struct ObjCProtocolDecl @0xa8d0b0128e3a36e1 {
  objCContainerUcDecl @0:ObjCContainerDecl;
  objCRuntimeUcNameUcAsUcString @1 :Text;
  hasUcDefinition @2 :Bool;
  isUcNonUcRuntimeUcProtocol @3 :Bool;
  isUcThisUcDeclarationADefinition @4 :Bool;
}

struct ObjCInterfaceDecl @0x851a7195d7b1d15e {
  objCContainerUcDecl @0:ObjCContainerDecl;
  declaresUcOrUcInheritsUcDesignatedUcInitializers @1 :Bool;
  endUcOfUcDefinitionUcToken @2 :TokenOffset;
  objCRuntimeUcNameUcAsUcString @3 :Text;
  superUcClassUcToken @4 :TokenOffset;
  hasUcDefinition @5 :Bool;
  hasUcDesignatedUcInitializers @6 :Bool;
  isUcArcUcWeakrefUcUnavailable @7 :Bool;
  isUcImplicitUcInterfaceUcDeclaration @8 :Bool;
  isUcThisUcDeclarationADefinition @9 :Bool;
}

struct ObjCImplDecl @0xfbf2d2598582b4f4 {
  objCContainerUcDecl @0:ObjCContainerDecl;
}

struct ObjCCategoryImplDecl @0xb972fe178fc59d16 {
  objCImplUcDecl @0:ObjCImplDecl;
  categoryUcNameUcToken @1 :TokenOffset;
}

struct ObjCImplementationDecl @0xf2e56fe062561acd {
  objCImplUcDecl @0:ObjCImplDecl;
  instanceUcVariableLBraceUcToken @1 :TokenOffset;
  instanceUcVariableRBraceUcToken @2 :TokenOffset;
  objCRuntimeUcNameUcAsUcString @3 :Text;
  superUcClassUcToken @4 :TokenOffset;
  hasUcDestructors @5 :Bool;
  hasUcNonUcZeroUcConstructors @6 :Bool;
}

struct ObjCCompatibleAliasDecl @0xc484be73cf6be95b {
  namedUcDecl @0:NamedDecl;
}

struct NamespaceDecl @0xd4713edcad196585 {
  namedUcDecl @0:NamedDecl;
  rBraceUcToken @1 :TokenOffset;
  isUcAnonymousUcNamespace @2 :Bool;
  isUcInline @3 :Bool;
  isUcOriginalUcNamespace @4 :Bool;
}

struct NamespaceAliasDecl @0xd8966652a484c480 {
  namedUcDecl @0:NamedDecl;
  aliasUcToken @1 :TokenOffset;
  namespaceUcToken @2 :TokenOffset;
  targetUcNameUcToken @3 :TokenOffset;
}

struct LinkageSpecDecl @0xb0f84c4a56c95eec {
  decl @0:Decl;
  externUcToken @1 :TokenOffset;
  language @2 :LanguageIDs;
  rBraceUcToken @3 :TokenOffset;
  hasUcBraces @4 :Bool;
}

struct LifetimeExtendedTemporaryDecl @0x829a6a0ac2b5baa8 {
  decl @0:Decl;
  storageUcDuration @1 :StorageDuration;
}

struct ImportDecl @0x84f826d506def833 {
  decl @0:Decl;
}

struct FriendTemplateDecl @0x82a920109bdb2178 {
  decl @0:Decl;
  friendUcToken @1 :TokenOffset;
}

struct FriendDecl @0xe6545eb838d810d0 {
  decl @0:Decl;
  friendUcToken @1 :TokenOffset;
  isUcUnsupportedUcFriend @2 :Bool;
}

struct FileScopeAsmDecl @0xa91b82b590024228 {
  decl @0:Decl;
  assemblyUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct ExternCContextDecl @0xd79e4560c3f80cbd {
  decl @0:Decl;
}

struct ExportDecl @0xb9bc9642842c6d81 {
  decl @0:Decl;
  exportUcToken @1 :TokenOffset;
  rBraceUcToken @2 :TokenOffset;
  hasUcBraces @3 :Bool;
}

struct EmptyDecl @0xdb55f7b2f60fd2a7 {
  decl @0:Decl;
}

struct Stmt @0x91127d30fade9a32 {
  beginUcToken @0 :TokenOffset;
  endUcToken @1 :TokenOffset;
  tokenUcRange @2 :TokenRange;
  kind @3 :StmtKind;
}

struct SEHTryStmt @0xf24201c85c654a91 {
  stmt @0:Stmt;
  isCxxTry @1 :Bool;
  tryUcToken @2 :TokenOffset;
}

struct SEHLeaveStmt @0xc4e4ea7e9d86c292 {
  stmt @0:Stmt;
  leaveUcToken @1 :TokenOffset;
}

struct SEHFinallyStmt @0x8331103206247bcd {
  stmt @0:Stmt;
  finallyUcToken @1 :TokenOffset;
}

struct SEHExceptStmt @0xec2050c67aa8fa46 {
  stmt @0:Stmt;
  exceptUcToken @1 :TokenOffset;
}

struct ReturnStmt @0xa64f08dfd7dbc80a {
  stmt @0:Stmt;
  returnUcToken @1 :TokenOffset;
}

struct ObjCForCollectionStmt @0x9eba75a6b3c891a0 {
  stmt @0:Stmt;
  forUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct ObjCAutoreleasePoolStmt @0x9762e1f9121378d2 {
  stmt @0:Stmt;
  atUcToken @1 :TokenOffset;
}

struct ObjCAtTryStmt @0x8a11f497922c60fa {
  stmt @0:Stmt;
  atUcTryUcToken @1 :TokenOffset;
}

struct ObjCAtThrowStmt @0xd0de9b13bfbb829d {
  stmt @0:Stmt;
  throwUcToken @1 :TokenOffset;
}

struct ObjCAtSynchronizedStmt @0xc002bd58ce946b42 {
  stmt @0:Stmt;
  atUcSynchronizedUcToken @1 :TokenOffset;
}

struct ObjCAtFinallyStmt @0xb4641f5dbb7b9c51 {
  stmt @0:Stmt;
  atUcFinallyUcToken @1 :TokenOffset;
}

struct ObjCAtCatchStmt @0xea4d614d29e03f4e {
  stmt @0:Stmt;
  atUcCatchUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
  hasUcEllipsis @3 :Bool;
}

struct OMPExecutableDirective @0xd9ecc0e6e88a888e {
  stmt @0:Stmt;
  hasUcAssociatedUcStatement @1 :Bool;
  isUcStandaloneUcDirective @2 :Bool;
}

struct OMPDispatchDirective @0xf2ebe316be280493 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
  targetUcCallUcToken @1 :TokenOffset;
}

struct OMPDepobjDirective @0xf7901aaea1e59da5 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPCriticalDirective @0xaae7b90454a167f2 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPCancellationPointDirective @0xbd3f65af25cb05ac {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPCancelDirective @0xe9fe3be8b3920583 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPBarrierDirective @0xa561ecfd48037b9f {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPAtomicDirective @0xccfc4e254a9ca2ef {
  ompExecutableUcDirective @0:OMPExecutableDirective;
  isUcPostfixUcUpdate @1 :Bool;
  isXlhsInRhsPart @2 :Bool;
}

struct OMPTeamsDirective @0xb09cbd39c14f104d {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTaskyieldDirective @0xeda0fa85f0053b41 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTaskwaitDirective @0xfab570caa675ad05 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTaskgroupDirective @0x997a52791bc1d2cb {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTaskDirective @0xad4854dc66276a11 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPTargetUpdateDirective @0xce201c1bda195171 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTargetTeamsDirective @0xcad5df87230fb5e1 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTargetParallelDirective @0xe053102edf992ab7 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPTargetExitDataDirective @0xd3f73d9d66855b7c {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTargetEnterDataDirective @0xfaddabf39d71573c {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTargetDirective @0xe61e25c74d351171 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTargetDataDirective @0xffdf74d960adebc3 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPSingleDirective @0x9e31c9d771d11457 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPSectionsDirective @0xa007966bd69b3ef4 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPSectionDirective @0xabfbf1faadf3da79 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPScanDirective @0x8048cf331a56b6fb {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPParallelSectionsDirective @0xdab61036a2e612d3 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPParallelMasterDirective @0xa7869fbfbcb75e30 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPParallelDirective @0xb6332105b1f2102a {
  ompExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPOrderedDirective @0xb97823fb2b0a2176 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPMasterDirective @0xb7b87dfe2df187cd {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPMaskedDirective @0xc1e20133fca4bab7 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPLoopBasedDirective @0xebd7e00926927a85 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPUnrollDirective @0xfde8548a895efed2 {
  ompLoopUcBasedUcDirective @0:OMPLoopBasedDirective;
}

struct OMPTileDirective @0x955f68d0ea4dad7c {
  ompLoopUcBasedUcDirective @0:OMPLoopBasedDirective;
}

struct OMPLoopDirective @0x996557610848d25e {
  ompLoopUcBasedUcDirective @0:OMPLoopBasedDirective;
}

struct OMPForSimdDirective @0xb5d719f282f43408 {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPForDirective @0xafaaf1c5631fa3da {
  ompLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPDistributeSimdDirective @0xfe653c77e8d8d7f8 {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPDistributeParallelForSimdDirective @0xed219e924604e032 {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPDistributeParallelForDirective @0xd4f84c1343cddbc3 {
  ompLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPDistributeDirective @0xa3b58e2e947f68cb {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTeamsDistributeSimdDirective @0xdd9b68bf972afa51 {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTeamsDistributeParallelForSimdDirective @0xb1d522d25bf5e8db {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTeamsDistributeParallelForDirective @0x8113915845154e06 {
  ompLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPTeamsDistributeDirective @0xd57fd7f310c3591a {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTaskLoopSimdDirective @0xf8f593871dfacede {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTaskLoopDirective @0xbeea33eaf08e61de {
  ompLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPTargetTeamsDistributeSimdDirective @0xf160e61a5edc1ff2 {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTargetTeamsDistributeParallelForSimdDirective @0x804e195502d62e5b {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTargetTeamsDistributeParallelForDirective @0xb9ef1d4c32f58988 {
  ompLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPTargetTeamsDistributeDirective @0xdb91542417a3e11b {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTargetSimdDirective @0x82400c65f487fb8a {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTargetParallelForSimdDirective @0x92be3b840fda6c34 {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTargetParallelForDirective @0xb14634030f2d8708 {
  ompLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPSimdDirective @0xb48cdcd37571e590 {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPParallelMasterTaskLoopSimdDirective @0xbbcba5847ff5ba48 {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPParallelMasterTaskLoopDirective @0xa53ad6a3233e8b9d {
  ompLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPParallelForSimdDirective @0xecdb69f0bce900de {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPParallelForDirective @0x8e1e3b1821c0515a {
  ompLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPMasterTaskLoopSimdDirective @0xea7bac26edd3f458 {
  ompLoopUcDirective @0:OMPLoopDirective;
}

struct OMPMasterTaskLoopDirective @0x826300eb6228e8f0 {
  ompLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPInteropDirective @0x86d3370fbc5f7dd0 {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPFlushDirective @0xfa2df93386e63fbe {
  ompExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPCanonicalLoop @0xf3cf896ddd7c46d1 {
  stmt @0:Stmt;
}

struct NullStmt @0xb57ca05aaf806566 {
  stmt @0:Stmt;
  semiUcToken @1 :TokenOffset;
  hasUcLeadingUcEmptyUcMacro @2 :Bool;
}

struct MSDependentExistsStmt @0xb5d9dfc73eeb0939 {
  stmt @0:Stmt;
  keywordUcToken @1 :TokenOffset;
  isUcIfUcExists @2 :Bool;
  isUcIfUcNotUcExists @3 :Bool;
}

struct IndirectGotoStmt @0xca063608491ba1fa {
  stmt @0:Stmt;
  gotoUcToken @1 :TokenOffset;
  starUcToken @2 :TokenOffset;
}

struct IfStmt @0xfc829da66c4e6bb1 {
  stmt @0:Stmt;
  elseUcToken @1 :TokenOffset;
  ifUcToken @2 :TokenOffset;
  lParenUcToken @3 :TokenOffset;
  rParenUcToken @4 :TokenOffset;
  hasUcElseUcStorage @5 :Bool;
  hasUcInitializerUcStorage @6 :Bool;
  hasUcVariableUcStorage @7 :Bool;
  isUcConstexpr @8 :Bool;
  isUcObjCAvailabilityUcCheck @9 :Bool;
}

struct GotoStmt @0xf542902873fc6c2b {
  stmt @0:Stmt;
  gotoUcToken @1 :TokenOffset;
  labelUcToken @2 :TokenOffset;
}

struct ForStmt @0xb6591c23541f6a1e {
  stmt @0:Stmt;
  forUcToken @1 :TokenOffset;
  lParenUcToken @2 :TokenOffset;
  rParenUcToken @3 :TokenOffset;
}

struct DoStmt @0xf6407ae4f3214356 {
  stmt @0:Stmt;
  doUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
  whileUcToken @3 :TokenOffset;
}

struct DeclStmt @0xa672643824ce0ba3 {
  stmt @0:Stmt;
  isUcSingleUcDeclaration @1 :Bool;
}

struct CoroutineBodyStmt @0xac9fd8887bfea7d8 {
  stmt @0:Stmt;
  hasUcDependentUcPromiseUcType @1 :Bool;
}

struct CoreturnStmt @0xfada897216b226f1 {
  stmt @0:Stmt;
  keywordUcToken @1 :TokenOffset;
  isUcImplicit @2 :Bool;
}

struct ContinueStmt @0xb364bd3d9a19cd05 {
  stmt @0:Stmt;
  continueUcToken @1 :TokenOffset;
}

struct CompoundStmt @0xd080c9192fa41c92 {
  stmt @0:Stmt;
  lBracUcToken @1 :TokenOffset;
  rBracUcToken @2 :TokenOffset;
}

struct CapturedStmt @0xa60fffc1366b48e6 {
  stmt @0:Stmt;
  capturedUcRegionUcKind @1 :CapturedRegionKind;
}

struct CXXTryStmt @0xf98f02d4cdc2dd3b {
  stmt @0:Stmt;
  tryUcToken @1 :TokenOffset;
}

struct CXXForRangeStmt @0xa23a75b3c0fa7d86 {
  stmt @0:Stmt;
  coawaitUcToken @1 :TokenOffset;
  colonUcToken @2 :TokenOffset;
  forUcToken @3 :TokenOffset;
  rParenUcToken @4 :TokenOffset;
}

struct CXXCatchStmt @0xac4b9e8390fd3a85 {
  stmt @0:Stmt;
  catchUcToken @1 :TokenOffset;
}

struct BreakStmt @0x940efd4e9770cb41 {
  stmt @0:Stmt;
  breakUcToken @1 :TokenOffset;
}

struct AsmStmt @0xa47714ac2d00fb21 {
  stmt @0:Stmt;
  generateUcAssemblyUcString @1 :Text;
  assemblyUcToken @2 :TokenOffset;
  isUcSimple @3 :Bool;
  isUcVolatile @4 :Bool;
}

struct MSAsmStmt @0xc504268dee34a98f {
  asmUcStmt @0:AsmStmt;
  assemblyUcString @1 :Text;
  lBraceUcToken @2 :TokenOffset;
  hasUcBraces @3 :Bool;
}

struct GCCAsmStmt @0x9d046a0d94b425db {
  asmUcStmt @0:AsmStmt;
  rParenUcToken @1 :TokenOffset;
  isUcAssemblyUcGoto @2 :Bool;
}

struct WhileStmt @0x8f0fb0e808ef8cd3 {
  stmt @0:Stmt;
  lParenUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
  whileUcToken @3 :TokenOffset;
  hasUcVariableUcStorage @4 :Bool;
}

struct ValueStmt @0xc78a8bda41f72525 {
  stmt @0:Stmt;
}

struct LabelStmt @0xed2b87febf6a7cc9 {
  valueUcStmt @0:ValueStmt;
  identifierUcToken @1 :TokenOffset;
  name @2 :Text;
  isUcSideUcEntry @3 :Bool;
}

struct Expr @0x9e4316b5a505b8d6 {
  valueUcStmt @0:ValueStmt;
  hasUcSideUcEffects @1 :Bool;
  containsUcErrors @2 :Bool;
  containsUcUnexpandedUcParameterUcPack @3 :Bool;
  expressionUcToken @4 :TokenOffset;
  objectUcKind @5 :ExprObjectKind;
  valueUcKind @6 :ExprValueKind;
  hasUcNonUcTrivialUcCall @7 :Bool;
  isUcBoundUcMemberUcFunction @8 :Bool;
  isCxx11UcConstantUcExpression @9 :Bool;
  isCxx98UcIntegralUcConstantUcExpression @10 :Bool;
  isUcDefaultUcArgument @11 :Bool;
  isUcEvaluatable @12 :Bool;
  isGlValue @13 :Bool;
  isUcImplicitCxxThis @14 :Bool;
  isUcInstantiationUcDependent @15 :Bool;
  isUcIntegerUcConstantUcExpression @16 :Bool;
  isUcKnownUcToUcHaveUcBooleanUcValue @17 :Bool;
  isLValue @18 :Bool;
  isObjcgcCandidate @19 :Bool;
  isUcObjCSelfUcExpression @20 :Bool;
  isUcOrdinaryUcOrUcBitUcFieldUcObject @21 :Bool;
  isPrValue @22 :Bool;
  isUcReadUcIfUcDiscardedUcInCPlusUcPlus11 @23 :Bool;
  isUcTypeUcDependent @24 :Bool;
  isUcValueUcDependent @25 :Bool;
  isXValue @26 :Bool;
  refersUcToUcBitUcField @27 :Bool;
  refersUcToUcGlobalUcRegisterUcVariable @28 :Bool;
  refersUcToUcMatrixUcElement @29 :Bool;
  refersUcToUcVectorUcElement @30 :Bool;
}

struct DesignatedInitUpdateExpr @0xaa6c77a8da7c4fba {
  expr @0:Expr;
}

struct DesignatedInitExpr @0xeff2c52d9c942ab2 {
  expr @0:Expr;
  designatorsUcSourceUcRange @1 :TokenRange;
  equalUcOrUcColonUcToken @2 :TokenOffset;
  isUcDirectUcInitializer @3 :Bool;
  usesGnuSyntax @4 :Bool;
}

struct DependentScopeDeclRefExpr @0x8fbb6ccb95a3509d {
  expr @0:Expr;
  lAngleUcToken @1 :TokenOffset;
  rAngleUcToken @2 :TokenOffset;
  templateUcKeywordUcToken @3 :TokenOffset;
  hasUcExplicitUcTemplateUcArguments @4 :Bool;
  hasUcTemplateUcKeyword @5 :Bool;
}

struct DependentCoawaitExpr @0x8fd8a27becb59315 {
  expr @0:Expr;
  keywordUcToken @1 :TokenOffset;
}

struct DeclRefExpr @0xec5119d27610b166 {
  expr @0:Expr;
  lAngleUcToken @1 :TokenOffset;
  rAngleUcToken @2 :TokenOffset;
  templateUcKeywordUcToken @3 :TokenOffset;
  hadUcMultipleUcCandidates @4 :Bool;
  hasUcExplicitUcTemplateUcArguments @5 :Bool;
  hasUcQualifier @6 :Bool;
  hasUcTemplateKwAndUcArgumentsUcInfo @7 :Bool;
  hasUcTemplateUcKeyword @8 :Bool;
  isUcNonUcOdrUcUse @9 :NonOdrUseReason;
  refersUcToUcEnclosingUcVariableUcOrUcCapture @10 :Bool;
}

struct CoroutineSuspendExpr @0xbd92ba696775fd54 {
  expr @0:Expr;
  keywordUcToken @1 :TokenOffset;
}

struct CoawaitExpr @0xab62e23bf872526e {
  coroutineUcSuspendUcExpr @0:CoroutineSuspendExpr;
  isUcImplicit @1 :Bool;
}

struct CoyieldExpr @0xe587a5c6d1b766ed {
  coroutineUcSuspendUcExpr @0:CoroutineSuspendExpr;
}

struct ConvertVectorExpr @0x9d71128cb240a509 {
  expr @0:Expr;
  builtinUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct ConceptSpecializationExpr @0xfed5bd9e47227653 {
  expr @0:Expr;
  isUcSatisfied @1 :Bool;
}

struct CompoundLiteralExpr @0x9865eabaf4e2ef8c {
  expr @0:Expr;
  lParenUcToken @1 :TokenOffset;
  isUcFileUcScope @2 :Bool;
}

struct ChooseExpr @0xd4a658caf5a1339e {
  expr @0:Expr;
  builtinUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
  isUcConditionUcDependent @3 :Bool;
  isUcConditionUcTrue @4 :Bool;
}

struct CharacterLiteral @0xbe144b3e9bdba5d9 {
  expr @0:Expr;
  token @1 :TokenOffset;
}

struct CastExpr @0x8cabd91ab4a4dcb3 {
  expr @0:Expr;
  castUcKind @1 :CastKind;
  castUcKindUcName @2 :Text;
  hasUcStoredFpFeatures @3 :Bool;
}

struct ImplicitCastExpr @0xf4659a194c7adcda {
  castUcExpr @0:CastExpr;
  isUcPartUcOfUcExplicitUcCast @1 :Bool;
}

struct ExplicitCastExpr @0xf68e68ae1ee44e91 {
  castUcExpr @0:CastExpr;
}

struct CXXNamedCastExpr @0x9edfd291691d4a7d {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
  angleUcBrackets @1 :TokenRange;
  castUcName @2 :Text;
  operatorUcToken @3 :TokenOffset;
  rParenUcToken @4 :TokenOffset;
}

struct CXXDynamicCastExpr @0xb48d513e0fa1452b {
  cxxNamedUcCastUcExpr @0:CXXNamedCastExpr;
  isUcAlwaysUcNull @1 :Bool;
}

struct CXXConstCastExpr @0x8ee388e71866e008 {
  cxxNamedUcCastUcExpr @0:CXXNamedCastExpr;
}

struct CXXAddrspaceCastExpr @0x8065afafedfafb6a {
  cxxNamedUcCastUcExpr @0:CXXNamedCastExpr;
}

struct CXXStaticCastExpr @0xd307133180b20a1a {
  cxxNamedUcCastUcExpr @0:CXXNamedCastExpr;
}

struct CXXReinterpretCastExpr @0x9ff4423f70d9541a {
  cxxNamedUcCastUcExpr @0:CXXNamedCastExpr;
}

struct CXXFunctionalCastExpr @0xf2c246adc881d86c {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
  lParenUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
  isUcListUcInitialization @3 :Bool;
}

struct CStyleCastExpr @0xddb96d0ba671cd89 {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
  lParenUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct BuiltinBitCastExpr @0xc4d665f00ba3fa8b {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
}

struct ObjCBridgedCastExpr @0xad38ef321a1ce1e3 {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
  bridgeUcKeywordUcToken @1 :TokenOffset;
  bridgeUcKind @2 :ObjCBridgeCastKind;
  bridgeUcKindUcName @3 :Text;
  lParenUcToken @4 :TokenOffset;
}

struct CallExpr @0x8cff24c7f68e334b {
  expr @0:Expr;
  adlCallUcKind @1 :ADLCallKind;
  rParenUcToken @2 :TokenOffset;
  hasUcStoredFpFeatures @3 :Bool;
  hasUcUnusedUcResultUcAttribute @4 :Bool;
  isUcBuiltinUcAssumeUcFalse @5 :Bool;
  isUcCallUcToUcStdUcMove @6 :Bool;
  isUcUnevaluatedUcBuiltinUcCall @7 :Bool;
  usesAdl @8 :Bool;
}

struct CXXOperatorCallExpr @0xb6a5653b33cdf0c5 {
  callUcExpr @0:CallExpr;
  operator @1 :OverloadedOperatorKind;
  operatorUcToken @2 :TokenOffset;
  isUcAssignmentUcOperation @3 :Bool;
  isUcComparisonUcOperation @4 :Bool;
  isUcInfixUcBinaryUcOperation @5 :Bool;
}

struct CXXMemberCallExpr @0x9a761539349dc02f {
  callUcExpr @0:CallExpr;
}

struct CUDAKernelCallExpr @0xd0bc1c26ca1e132f {
  callUcExpr @0:CallExpr;
}

struct UserDefinedLiteral @0xa1af860a6baa1029 {
  callUcExpr @0:CallExpr;
  udSuffixUcToken @1 :TokenOffset;
}

struct CXXUuidofExpr @0xcdde7d28fc7931f6 {
  expr @0:Expr;
  isUcTypeUcOperand @1 :Bool;
}

struct CXXUnresolvedConstructExpr @0x9fbb7e373f171f86 {
  expr @0:Expr;
  lParenUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
  isUcListUcInitialization @3 :Bool;
}

struct CXXTypeidExpr @0xf325d3531a387183 {
  expr @0:Expr;
  isUcMostUcDerived @1 :Bool;
  isUcPotentiallyUcEvaluated @2 :Bool;
  isUcTypeUcOperand @3 :Bool;
}

struct CXXThrowExpr @0x852a841374684e1e {
  expr @0:Expr;
  throwUcToken @1 :TokenOffset;
  isUcThrownUcVariableUcInUcScope @2 :Bool;
}

struct CXXThisExpr @0x959ba6d5fec8b422 {
  expr @0:Expr;
  token @1 :TokenOffset;
  isUcImplicit @2 :Bool;
}

struct CXXStdInitializerListExpr @0xd199eb3b19c592fa {
  expr @0:Expr;
}

struct CXXScalarValueInitExpr @0x9fd4b7d4985831e7 {
  expr @0:Expr;
  rParenUcToken @1 :TokenOffset;
}

struct CXXRewrittenBinaryOperator @0xd00648fa0bd5ccc4 {
  expr @0:Expr;
  opcode @1 :BinaryOperatorKind;
  opcodeUcString @2 :Text;
  operator @3 :BinaryOperatorKind;
  operatorUcToken @4 :TokenOffset;
  isUcAssignmentUcOperation @5 :Bool;
  isUcComparisonUcOperation @6 :Bool;
  isUcReversed @7 :Bool;
}

struct CXXPseudoDestructorExpr @0xfb788932e740ac07 {
  expr @0:Expr;
  colonUcColonUcToken @1 :TokenOffset;
  destroyedUcTypeUcToken @2 :TokenOffset;
  operatorUcToken @3 :TokenOffset;
  tildeUcToken @4 :TokenOffset;
  hasUcQualifier @5 :Bool;
  isUcArrow @6 :Bool;
}

struct CXXNullPtrLiteralExpr @0x80352ea6175b520f {
  expr @0:Expr;
  token @1 :TokenOffset;
}

struct CXXNoexceptExpr @0x97e76c7f0648cbe4 {
  expr @0:Expr;
  value @1 :Bool;
}

struct CXXNewExpr @0x9dca0c0f9404e2b5 {
  expr @0:Expr;
  doesUcUsualUcArrayUcDeleteUcWantUcSize @1 :Bool;
  directUcInitializerUcRange @2 :TokenRange;
  initializationUcStyle @3 :InitializationStyle;
  typeUcIdUcParentheses @4 :TokenRange;
  hasUcInitializer @5 :Bool;
  isUcArray @6 :Bool;
  isUcGlobalUcNew @7 :Bool;
  isUcParenthesisUcTypeUcId @8 :Bool;
  passUcAlignment @9 :Bool;
  shouldUcNullUcCheckUcAllocation @10 :Bool;
}

struct CXXInheritedCtorInitExpr @0xd5db83de022b1ee3 {
  expr @0:Expr;
  constructsUcVirtualUcBase @1 :Bool;
  constructionUcKind @2 :ConstructionKind;
  token @3 :TokenOffset;
  inheritedUcFromUcVirtualUcBase @4 :Bool;
}

struct CXXFoldExpr @0x8a593922e3ea9d50 {
  expr @0:Expr;
  ellipsisUcToken @1 :TokenOffset;
  lParenUcToken @2 :TokenOffset;
  operator @3 :BinaryOperatorKind;
  rParenUcToken @4 :TokenOffset;
  isUcLeftUcFold @5 :Bool;
  isUcRightUcFold @6 :Bool;
}

struct CXXDependentScopeMemberExpr @0xa1a21ac74e691c1f {
  expr @0:Expr;
  lAngleUcToken @1 :TokenOffset;
  memberUcToken @2 :TokenOffset;
  operatorUcToken @3 :TokenOffset;
  rAngleUcToken @4 :TokenOffset;
  templateUcKeywordUcToken @5 :TokenOffset;
  hasUcExplicitUcTemplateUcArguments @6 :Bool;
  hasUcTemplateUcKeyword @7 :Bool;
  isUcArrow @8 :Bool;
  isUcImplicitUcAccess @9 :Bool;
}

struct CXXDeleteExpr @0x80f6cd450a27b9d4 {
  expr @0:Expr;
  doesUcUsualUcArrayUcDeleteUcWantUcSize @1 :Bool;
  isUcArrayUcForm @2 :Bool;
  isUcArrayUcFormUcAsUcWritten @3 :Bool;
  isUcGlobalUcDelete @4 :Bool;
}

struct CXXDefaultInitExpr @0xa78e81b7ba8da8e6 {
  expr @0:Expr;
  usedUcToken @1 :TokenOffset;
}

struct CXXDefaultArgExpr @0x9f9ee9dcf349cbcf {
  expr @0:Expr;
  usedUcToken @1 :TokenOffset;
}

struct CXXConstructExpr @0xb3d036394c09ed48 {
  expr @0:Expr;
  constructionUcKind @1 :ConstructionKind;
  token @2 :TokenOffset;
  parenthesisUcOrUcBraceUcRange @3 :TokenRange;
  hadUcMultipleUcCandidates @4 :Bool;
  isUcElidable @5 :Bool;
  isUcListUcInitialization @6 :Bool;
  isUcStdUcInitializerUcListUcInitialization @7 :Bool;
  requiresUcZeroUcInitialization @8 :Bool;
}

struct CXXTemporaryObjectExpr @0xb4be9b66753a2671 {
  cxxConstructUcExpr @0:CXXConstructExpr;
}

struct CXXBoolLiteralExpr @0x862b8d87bd2905e0 {
  expr @0:Expr;
  token @1 :TokenOffset;
  value @2 :Bool;
}

struct CXXBindTemporaryExpr @0xc6a96978d42dc702 {
  expr @0:Expr;
}

struct BlockExpr @0xc2ae5be0934c61f3 {
  expr @0:Expr;
  caretUcToken @1 :TokenOffset;
}

struct BinaryOperator @0xd858b89bd116f05f {
  expr @0:Expr;
  opcode @1 :BinaryOperatorKind;
  opcodeUcString @2 :Text;
  operatorUcToken @3 :TokenOffset;
  hasUcStoredFpFeatures @4 :Bool;
  isUcAdditiveUcOperation @5 :Bool;
  isUcAssignmentUcOperation @6 :Bool;
  isUcBitwiseUcOperation @7 :Bool;
  isUcCommaUcOperation @8 :Bool;
  isUcComparisonUcOperation @9 :Bool;
  isUcCompoundUcAssignmentUcOperation @10 :Bool;
  isUcEqualityUcOperation @11 :Bool;
  isUcLogicalUcOperation @12 :Bool;
  isUcMultiplicativeUcOperation @13 :Bool;
  isUcPointerUcMemoryUcOperation @14 :Bool;
  isUcRelationalUcOperation @15 :Bool;
  isUcShiftUcAssignUcOperation @16 :Bool;
  isUcShiftUcOperation @17 :Bool;
}

struct CompoundAssignOperator @0xe6e7bc711d327cb9 {
  binaryUcOperator @0:BinaryOperator;
}

struct AtomicExpr @0xc730b6c3f33ecb9f {
  expr @0:Expr;
  builtinUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
  isUcCmpXChg @3 :Bool;
  isUcOpenCl @4 :Bool;
  isUcVolatile @5 :Bool;
}

struct AsTypeExpr @0xf646590167dcf1ab {
  expr @0:Expr;
  builtinUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct ArrayTypeTraitExpr @0xcbcb35a78956a3cc {
  expr @0:Expr;
  trait @1 :ArrayTypeTrait;
}

struct ArraySubscriptExpr @0xb5bb680da7ccce33 {
  expr @0:Expr;
  rBracketUcToken @1 :TokenOffset;
}

struct ArrayInitLoopExpr @0xbe95601783117ebe {
  expr @0:Expr;
}

struct ArrayInitIndexExpr @0xc9bc62bebe2cdbb8 {
  expr @0:Expr;
}

struct AddrLabelExpr @0xc1abc55fece6aa91 {
  expr @0:Expr;
  ampUcAmpUcToken @1 :TokenOffset;
  labelUcToken @2 :TokenOffset;
}

struct AbstractConditionalOperator @0xee7097774f7aaa45 {
  expr @0:Expr;
  colonUcToken @1 :TokenOffset;
  questionUcToken @2 :TokenOffset;
}

struct ConditionalOperator @0xd3810312a3bd13c7 {
  abstractUcConditionalUcOperator @0:AbstractConditionalOperator;
}

struct BinaryConditionalOperator @0xde5f047672b1ac84 {
  abstractUcConditionalUcOperator @0:AbstractConditionalOperator;
}

struct VAArgExpr @0x8fa746d782ee27c9 {
  expr @0:Expr;
  builtinUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
  isUcMicrosoftAbi @3 :Bool;
}

struct UnaryOperator @0xaa78820aaa7f22b8 {
  expr @0:Expr;
  canUcOverflow @1 :Bool;
  opcode @2 :UnaryOperatorKind;
  operatorUcToken @3 :TokenOffset;
  hasUcStoredFpFeatures @4 :Bool;
  isUcArithmeticUcOperation @5 :Bool;
  isUcDecrementUcOperation @6 :Bool;
  isUcIncrementUcDecrementUcOperation @7 :Bool;
  isUcIncrementUcOperation @8 :Bool;
  isUcPostfix @9 :Bool;
  isUcPrefix @10 :Bool;
}

struct UnaryExprOrTypeTraitExpr @0xbc37e32561d53a59 {
  expr @0:Expr;
  operatorUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
  isUcArgumentUcType @3 :Bool;
}

struct TypoExpr @0xb50d73d61e0fd90b {
  expr @0:Expr;
}

struct TypeTraitExpr @0xeeb042141bc436ae {
  expr @0:Expr;
  trait @1 :TypeTrait;
  value @2 :Bool;
}

struct SubstNonTypeTemplateParmPackExpr @0xbffc5dc4488326c8 {
  expr @0:Expr;
  parameterUcPackUcToken @1 :TokenOffset;
}

struct SubstNonTypeTemplateParmExpr @0xad38ba4bfe617a6f {
  expr @0:Expr;
  nameUcToken @1 :TokenOffset;
  isUcReferenceUcParameter @2 :Bool;
}

struct StringLiteral @0xd0cec44e02f59cf2 {
  expr @0:Expr;
  containsUcNonUcAscii @1 :Bool;
  containsUcNonUcAsciiUcOrUcNull @2 :Bool;
  bytes @3 :Text;
  string @4 :Text;
  isUcAscii @5 :Bool;
  isUcPascal @6 :Bool;
  isUtf16 @7 :Bool;
  isUtf32 @8 :Bool;
  isUtf8 @9 :Bool;
  isUcWide @10 :Bool;
}

struct StmtExpr @0xe3606abe04461b8a {
  expr @0:Expr;
  lParenUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct SourceLocExpr @0xd4bebb374e1e6d58 {
  expr @0:Expr;
  builtinUcString @1 :Text;
  token @2 :TokenOffset;
  isUcIntUcType @3 :Bool;
  isUcStringUcType @4 :Bool;
}

struct SizeOfPackExpr @0xa4f777d7b3ce890c {
  expr @0:Expr;
  operatorUcToken @1 :TokenOffset;
  packUcToken @2 :TokenOffset;
  rParenUcToken @3 :TokenOffset;
  isUcPartiallyUcSubstituted @4 :Bool;
}

struct ShuffleVectorExpr @0xdfa87964ccc4abd6 {
  expr @0:Expr;
  builtinUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct SYCLUniqueStableNameExpr @0xfa67d59d16f9a78a {
  expr @0:Expr;
  computeUcName @1 :Text;
  lParenUcToken @2 :TokenOffset;
  token @3 :TokenOffset;
  rParenUcToken @4 :TokenOffset;
}

struct RequiresExpr @0xe4f5db5ba506ab26 {
  expr @0:Expr;
  rBraceUcToken @1 :TokenOffset;
  requiresKwToken @2 :TokenOffset;
  isUcSatisfied @3 :Bool;
}

struct RecoveryExpr @0xa9e048a5bbe9f6bd {
  expr @0:Expr;
}

struct PseudoObjectExpr @0xf7795b8660a50a1e {
  expr @0:Expr;
}

struct PredefinedExpr @0xf512f62d75089164 {
  expr @0:Expr;
  identifierUcKindUcName @1 :Text;
  token @2 :TokenOffset;
}

struct ParenListExpr @0xc7ba76bb20cf6201 {
  expr @0:Expr;
  lParenUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct ParenExpr @0x821bf890921895cd {
  expr @0:Expr;
  lParen @1 :TokenOffset;
  rParen @2 :TokenOffset;
}

struct PackExpansionExpr @0xbf1eafc846bba2e0 {
  expr @0:Expr;
  ellipsisUcToken @1 :TokenOffset;
}

struct OverloadExpr @0xe1320ca92341cff5 {
  expr @0:Expr;
  lAngleUcToken @1 :TokenOffset;
  nameUcToken @2 :TokenOffset;
  rAngleUcToken @3 :TokenOffset;
  templateUcKeywordUcToken @4 :TokenOffset;
  hasUcExplicitUcTemplateUcArguments @5 :Bool;
  hasUcTemplateUcKeyword @6 :Bool;
}

struct UnresolvedMemberExpr @0xbd4aeea6486879d1 {
  overloadUcExpr @0:OverloadExpr;
  memberUcToken @1 :TokenOffset;
  operatorUcToken @2 :TokenOffset;
  hasUcUnresolvedUcUsing @3 :Bool;
  isUcArrow @4 :Bool;
  isUcImplicitUcAccess @5 :Bool;
}

struct UnresolvedLookupExpr @0xd04212a95a4ab25d {
  overloadUcExpr @0:OverloadExpr;
  isUcOverloaded @1 :Bool;
  requiresAdl @2 :Bool;
}

struct OpaqueValueExpr @0xd0ebba3413f46f6d {
  expr @0:Expr;
  token @1 :TokenOffset;
  isUcUnique @2 :Bool;
}

struct OffsetOfExpr @0xe74e51b681474f08 {
  expr @0:Expr;
  operatorUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct ObjCSubscriptRefExpr @0x827d6564c3126c7a {
  expr @0:Expr;
  rBracket @1 :TokenOffset;
  isUcArrayUcSubscriptUcReferenceUcExpression @2 :Bool;
}

struct ObjCStringLiteral @0x84470e968f7365fb {
  expr @0:Expr;
  atUcToken @1 :TokenOffset;
}

struct ObjCSelectorExpr @0xa6687e4a6275988d {
  expr @0:Expr;
  atUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct ObjCProtocolExpr @0xb07709e6d6281804 {
  expr @0:Expr;
  atUcToken @1 :TokenOffset;
  protocolUcIdUcToken @2 :TokenOffset;
  rParenUcToken @3 :TokenOffset;
}

struct ObjCPropertyRefExpr @0x9f75c18ee7f1c7a2 {
  expr @0:Expr;
  token @1 :TokenOffset;
  receiverUcToken @2 :TokenOffset;
  isUcClassUcReceiver @3 :Bool;
  isUcExplicitUcProperty @4 :Bool;
  isUcImplicitUcProperty @5 :Bool;
  isUcMessagingUcGetter @6 :Bool;
  isUcMessagingUcSetter @7 :Bool;
  isUcObjectUcReceiver @8 :Bool;
  isUcSuperUcReceiver @9 :Bool;
}

struct ObjCMessageExpr @0xc53f62c71ed8d723 {
  expr @0:Expr;
  leftUcToken @1 :TokenOffset;
  methodUcFamily @2 :ObjCMethodFamily;
  receiverUcRange @3 :TokenRange;
  rightUcToken @4 :TokenOffset;
  selectorUcStartUcToken @5 :TokenOffset;
  superUcToken @6 :TokenOffset;
  isUcClassUcMessage @7 :Bool;
  isUcDelegateUcInitializerUcCall @8 :Bool;
  isUcImplicit @9 :Bool;
  isUcInstanceUcMessage @10 :Bool;
}

struct ObjCIvarRefExpr @0xec7058b5b38773dd {
  expr @0:Expr;
  token @1 :TokenOffset;
  operationUcToken @2 :TokenOffset;
  isUcArrow @3 :Bool;
  isUcFreeUcInstanceUcVariable @4 :Bool;
}

struct ObjCIsaExpr @0xe3c04c83aef329c8 {
  expr @0:Expr;
  baseUcTokenUcEnd @1 :TokenOffset;
  isaUcMemberUcToken @2 :TokenOffset;
  operationUcToken @3 :TokenOffset;
  isUcArrow @4 :Bool;
}

struct ObjCIndirectCopyRestoreExpr @0x9475cc6d12ba1afb {
  expr @0:Expr;
  shouldUcCopy @1 :Bool;
}

struct ObjCEncodeExpr @0x911855b6fa2d9812 {
  expr @0:Expr;
  atUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct ObjCDictionaryLiteral @0xaef4d291186415b7 {
  expr @0:Expr;
}

struct ObjCBoxedExpr @0xae80861f1a63c950 {
  expr @0:Expr;
  atUcToken @1 :TokenOffset;
  isUcExpressibleUcAsUcConstantUcInitializer @2 :Bool;
}

struct ObjCBoolLiteralExpr @0xb2d027f2c8cad1fb {
  expr @0:Expr;
  token @1 :TokenOffset;
  value @2 :Bool;
}

struct ObjCAvailabilityCheckExpr @0xbd477d54907fe95a {
  expr @0:Expr;
  hasUcVersion @1 :Bool;
}

struct ObjCArrayLiteral @0xa36b5cac081b468a {
  expr @0:Expr;
}

struct OMPIteratorExpr @0xd52a7668addb282d {
  expr @0:Expr;
  iteratorUcKwUcToken @1 :TokenOffset;
  lParenUcToken @2 :TokenOffset;
  rParenUcToken @3 :TokenOffset;
}

struct OMPArrayShapingExpr @0xcddd3cf38d603be1 {
  expr @0:Expr;
  lParenUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
}

struct OMPArraySectionExpr @0xca2808db37aea2e0 {
  expr @0:Expr;
  colonUcTokenUcFirst @1 :TokenOffset;
  colonUcTokenUcSecond @2 :TokenOffset;
  rBracketUcToken @3 :TokenOffset;
}

struct NoInitExpr @0xadedf240a5b5d3d1 {
  expr @0:Expr;
}

struct MemberExpr @0xd8c89de1fe446ed0 {
  expr @0:Expr;
  lAngleUcToken @1 :TokenOffset;
  memberUcToken @2 :TokenOffset;
  operatorUcToken @3 :TokenOffset;
  rAngleUcToken @4 :TokenOffset;
  templateUcKeywordUcToken @5 :TokenOffset;
  hadUcMultipleUcCandidates @6 :Bool;
  hasUcExplicitUcTemplateUcArguments @7 :Bool;
  hasUcQualifier @8 :Bool;
  hasUcTemplateUcKeyword @9 :Bool;
  isUcArrow @10 :Bool;
  isUcImplicitUcAccess @11 :Bool;
  isUcNonUcOdrUcUse @12 :NonOdrUseReason;
}

struct MatrixSubscriptExpr @0xc6e8f0398e560e56 {
  expr @0:Expr;
  rBracketUcToken @1 :TokenOffset;
  isUcIncomplete @2 :Bool;
}

struct MaterializeTemporaryExpr @0x81f0ffa9f501c48d {
  expr @0:Expr;
  storageUcDuration @1 :StorageDuration;
  isUcBoundUcToUcLvalueUcReference @2 :Bool;
  isUcUsableUcInUcConstantUcExpressions @3 :Bool;
}

struct MSPropertySubscriptExpr @0xdca78c710e8a0bc9 {
  expr @0:Expr;
  rBracketUcToken @1 :TokenOffset;
}

struct MSPropertyRefExpr @0xb14da9f10b21425d {
  expr @0:Expr;
  memberUcToken @1 :TokenOffset;
  isUcArrow @2 :Bool;
  isUcImplicitUcAccess @3 :Bool;
}

struct LambdaExpr @0xd1773aeaaf57de49 {
  expr @0:Expr;
  captureUcDefault @1 :LambdaCaptureDefault;
  captureUcDefaultUcToken @2 :TokenOffset;
  introducerUcRange @3 :TokenRange;
  hasUcExplicitUcParameters @4 :Bool;
  hasUcExplicitUcResultUcType @5 :Bool;
  isUcGenericUcLambda @6 :Bool;
  isUcMutable @7 :Bool;
}

struct IntegerLiteral @0x9555503bb691c665 {
  expr @0:Expr;
  token @1 :TokenOffset;
}

struct InitListExpr @0xee5bc39a46a85bfd {
  expr @0:Expr;
  lBraceUcToken @1 :TokenOffset;
  rBraceUcToken @2 :TokenOffset;
  hadUcArrayUcRangeUcDesignator @3 :Bool;
  hasUcArrayUcFiller @4 :Bool;
  isUcExplicit @5 :Bool;
  isUcSemanticUcForm @6 :Bool;
  isUcStringUcLiteralUcInitializer @7 :Bool;
  isUcSyntacticUcForm @8 :Bool;
  isUcTransparent @9 :Bool;
}

struct ImplicitValueInitExpr @0xa74a9776ddeaccc0 {
  expr @0:Expr;
}

struct ImaginaryLiteral @0xe6373a2b8f6af5f3 {
  expr @0:Expr;
}

struct GenericSelectionExpr @0xb9c714e9030a2703 {
  expr @0:Expr;
  defaultUcToken @1 :TokenOffset;
  genericUcToken @2 :TokenOffset;
  rParenUcToken @3 :TokenOffset;
  isUcResultUcDependent @4 :Bool;
}

struct GNUNullExpr @0xed67a32bfb3e1820 {
  expr @0:Expr;
  tokenUcToken @1 :TokenOffset;
}

struct FunctionParmPackExpr @0x9b1418ed71492c60 {
  expr @0:Expr;
  parameterUcPackUcToken @1 :TokenOffset;
}

struct FullExpr @0x823209f8d52ac4fb {
  expr @0:Expr;
}

struct ExprWithCleanups @0x8caff3daad0879d0 {
  fullUcExpr @0:FullExpr;
  cleanupsUcHaveUcSideUcEffects @1 :Bool;
}

struct ConstantExpr @0xb118d0dca5dbdf6e {
  fullUcExpr @0:FullExpr;
  resultApValueUcKind @1 :APValueKind;
  resultUcStorageUcKind @2 :ResultStorageKind;
  hasApValueUcResult @3 :Bool;
  isUcImmediateUcInvocation @4 :Bool;
}

struct FloatingLiteral @0xf9afab4b69f8f504 {
  expr @0:Expr;
  token @1 :TokenOffset;
  isUcExact @2 :Bool;
}

struct FixedPointLiteral @0xb376f274c18baf5a {
  expr @0:Expr;
  token @1 :TokenOffset;
}

struct ExtVectorElementExpr @0xba6c9e86786ed31a {
  expr @0:Expr;
  containsUcDuplicateUcElements @1 :Bool;
  accessorUcToken @2 :TokenOffset;
  isUcArrow @3 :Bool;
}

struct ExpressionTraitExpr @0xf53890283fc830c0 {
  expr @0:Expr;
  trait @1 :ExpressionTrait;
  value @2 :Bool;
}

struct AttributedStmt @0xc33cd79cc9238608 {
  valueUcStmt @0:ValueStmt;
  attributeUcToken @1 :TokenOffset;
}

struct SwitchStmt @0x8f2566a2d81612cd {
  stmt @0:Stmt;
  lParenUcToken @1 :TokenOffset;
  rParenUcToken @2 :TokenOffset;
  switchUcToken @3 :TokenOffset;
  hasUcInitializerUcStorage @4 :Bool;
  hasUcVariableUcStorage @5 :Bool;
  isUcAllUcEnumUcCasesUcCovered @6 :Bool;
}

struct SwitchCase @0xeecb8bb11e4c8ed7 {
  stmt @0:Stmt;
  colonUcToken @1 :TokenOffset;
  keywordUcToken @2 :TokenOffset;
}

struct DefaultStmt @0xf8ae119f01317845 {
  switchUcCase @0:SwitchCase;
  defaultUcToken @1 :TokenOffset;
}

struct CaseStmt @0x829897c890006599 {
  switchUcCase @0:SwitchCase;
  caseUcStatementUcIsGnuRange @1 :Bool;
  caseUcToken @2 :TokenOffset;
  ellipsisUcToken @3 :TokenOffset;
}

struct Type @0xd739e808bc1b3fd7 {
  acceptsUcObjCTypeUcParams @0 :Bool;
  canUcDecayUcToUcPointerUcType @1 :Bool;
  canUcHaveUcNullability @2 :Bool;
  containsUcErrors @3 :Bool;
  containsUcUnexpandedUcParameterUcPack @4 :Bool;
  dependence @5 :TypeDependence;
  linkage @6 :Linkage;
  objCarcImplicitUcLifetime @7 :ObjCLifetime;
  scalarUcTypeUcKind @8 :ScalarTypeKind;
  kind @9 :TypeKind;
  visibility @10 :Visibility;
  hasUcAutoUcForUcTrailingUcReturnUcType @11 :Bool;
  hasUcFloatingUcRepresentation @12 :Bool;
  hasUcIntegerUcRepresentation @13 :Bool;
  hasUcObjCPointerUcRepresentation @14 :Bool;
  hasUcPointerUcRepresentation @15 :Bool;
  hasUcSignedUcIntegerUcRepresentation @16 :Bool;
  hasUcSizedVlaType @17 :Bool;
  hasUcUnnamedUcOrUcLocalUcType @18 :Bool;
  hasUcUnsignedUcIntegerUcRepresentation @19 :Bool;
  isUcAggregateUcType @20 :Bool;
  isUcAlignUcValT @21 :Bool;
  isUcAnyUcCharacterUcType @22 :Bool;
  isUcAnyUcComplexUcType @23 :Bool;
  isUcAnyUcPointerUcType @24 :Bool;
  isUcArithmeticUcType @25 :Bool;
  isUcArrayUcType @26 :Bool;
  isUcAtomicUcType @27 :Bool;
  isBFloat16UcType @28 :Bool;
  isUcBlockUcCompatibleUcObjCPointerUcType @29 :Bool;
  isUcBlockUcPointerUcType @30 :Bool;
  isUcBooleanUcType @31 :Bool;
  isUcBuiltinUcType @32 :Bool;
  isCarcBridgableUcType @33 :Bool;
  isCudaDeviceUcBuiltinUcSurfaceUcType @34 :Bool;
  isCudaDeviceUcBuiltinUcTextureUcType @35 :Bool;
  isUcCanonicalUcUnqualified @36 :Bool;
  isUcChar16UcType @37 :Bool;
  isUcChar32UcType @38 :Bool;
  isUcChar8UcType @39 :Bool;
  isUcCharacterUcType @40 :Bool;
  isUcClassUcType @41 :Bool;
  isUcClkUcEventT @42 :Bool;
  isUcComplexUcIntegerUcType @43 :Bool;
  isUcComplexUcType @44 :Bool;
  isUcCompoundUcType @45 :Bool;
  isUcConstantUcArrayUcType @46 :Bool;
  isUcConstantUcMatrixUcType @47 :Bool;
  isUcConstantUcSizeUcType @48 :Bool;
  isUcDecltypeUcType @49 :Bool;
  isUcDependentUcAddressUcSpaceUcType @50 :Bool;
  isUcDependentUcSizedUcArrayUcType @51 :Bool;
  isUcDependentUcType @52 :Bool;
  isUcElaboratedUcTypeUcSpecifier @53 :Bool;
  isUcEnumeralUcType @54 :Bool;
  isUcEventT @55 :Bool;
  isUcExtUcIntUcType @56 :Bool;
  isUcExtUcVectorUcType @57 :Bool;
  isUcFixedUcPointUcOrUcIntegerUcType @58 :Bool;
  isUcFixedUcPointUcType @59 :Bool;
  isUcFloat128UcType @60 :Bool;
  isUcFloat16UcType @61 :Bool;
  isUcFloatingUcType @62 :Bool;
  isUcFromAst @63 :Bool;
  isUcFunctionUcNoUcProtoUcType @64 :Bool;
  isUcFunctionUcPointerUcType @65 :Bool;
  isUcFunctionUcProtoUcType @66 :Bool;
  isUcFunctionUcReferenceUcType @67 :Bool;
  isUcFunctionUcType @68 :Bool;
  isUcFundamentalUcType @69 :Bool;
  isUcHalfUcType @70 :Bool;
  isUcImageUcType @71 :Bool;
  isUcIncompleteUcArrayUcType @72 :Bool;
  isUcIncompleteUcOrUcObjectUcType @73 :Bool;
  isUcIncompleteUcType @74 :Bool;
  isUcInstantiationUcDependentUcType @75 :Bool;
  isUcIntegerUcType @76 :Bool;
  isUcIntegralUcOrUcEnumerationUcType @77 :Bool;
  isUcIntegralUcOrUcUnscopedUcEnumerationUcType @78 :Bool;
  isUcIntegralUcType @79 :Bool;
  isUcInterfaceUcType @80 :Bool;
  isLValueUcReferenceUcType @81 :Bool;
  isUcLinkageUcValid @82 :Bool;
  isUcLiteralUcType @83 :Bool;
  isUcMatrixUcType @84 :Bool;
  isUcMemberUcDataUcPointerUcType @85 :Bool;
  isUcMemberUcFunctionUcPointerUcType @86 :Bool;
  isUcMemberUcPointerUcType @87 :Bool;
  isUcNonUcOverloadUcPlaceholderUcType @88 :Bool;
  isUcNothrowT @89 :Bool;
  isUcNullUcPointerUcType @90 :Bool;
  isOclExtUcOpaqueUcType @91 :Bool;
  isOclImage1dUcArrayRoType @92 :Bool;
  isOclImage1dUcArrayRwType @93 :Bool;
  isOclImage1dUcArrayWoType @94 :Bool;
  isOclImage1dUcBufferRoType @95 :Bool;
  isOclImage1dUcBufferRwType @96 :Bool;
  isOclImage1dUcBufferWoType @97 :Bool;
  isOclImage1dRoType @98 :Bool;
  isOclImage1dRwType @99 :Bool;
  isOclImage1dWoType @100 :Bool;
  isOclImage2dUcArrayUcDepthRoType @101 :Bool;
  isOclImage2dUcArrayUcDepthRwType @102 :Bool;
  isOclImage2dUcArrayUcDepthWoType @103 :Bool;
  isOclImage2dUcArrayMsaaDepthRoType @104 :Bool;
  isOclImage2dUcArrayMsaaDepthRwType @105 :Bool;
  isOclImage2dUcArrayMsaaDepthWoType @106 :Bool;
  isOclImage2dUcArrayMsaaroType @107 :Bool;
  isOclImage2dUcArrayMsaarwType @108 :Bool;
  isOclImage2dUcArrayMsaawoType @109 :Bool;
  isOclImage2dUcArrayRoType @110 :Bool;
  isOclImage2dUcArrayRwType @111 :Bool;
  isOclImage2dUcArrayWoType @112 :Bool;
  isOclImage2dUcDepthRoType @113 :Bool;
  isOclImage2dUcDepthRwType @114 :Bool;
  isOclImage2dUcDepthWoType @115 :Bool;
  isOclImage2dMsaaDepthRoType @116 :Bool;
  isOclImage2dMsaaDepthRwType @117 :Bool;
  isOclImage2dMsaaDepthWoType @118 :Bool;
  isOclImage2dMsaaroType @119 :Bool;
  isOclImage2dMsaarwType @120 :Bool;
  isOclImage2dMsaawoType @121 :Bool;
  isOclImage2dRoType @122 :Bool;
  isOclImage2dRwType @123 :Bool;
  isOclImage2dWoType @124 :Bool;
  isOclImage3dRoType @125 :Bool;
  isOclImage3dRwType @126 :Bool;
  isOclImage3dWoType @127 :Bool;
  isOclIntelUcSubgroupAvcImeUcDualUcReferenceUcStreaminUcType @128 :Bool;
  isOclIntelUcSubgroupAvcImeUcPayloadUcType @129 :Bool;
  isOclIntelUcSubgroupAvcImeUcResultUcDualUcReferenceUcStreamoutUcType @130 :Bool;
  isOclIntelUcSubgroupAvcImeUcResultUcSingleUcReferenceUcStreamoutUcType @131 :Bool;
  isOclIntelUcSubgroupAvcImeUcResultUcType @132 :Bool;
  isOclIntelUcSubgroupAvcImeUcSingleUcReferenceUcStreaminUcType @133 :Bool;
  isOclIntelUcSubgroupAvcMceUcPayloadUcType @134 :Bool;
  isOclIntelUcSubgroupAvcMceUcResultUcType @135 :Bool;
  isOclIntelUcSubgroupAvcRefUcPayloadUcType @136 :Bool;
  isOclIntelUcSubgroupAvcRefUcResultUcType @137 :Bool;
  isOclIntelUcSubgroupAvcSicUcPayloadUcType @138 :Bool;
  isOclIntelUcSubgroupAvcSicUcResultUcType @139 :Bool;
  isOclIntelUcSubgroupAvcType @140 :Bool;
  isUcObjCarcBridgableUcType @141 :Bool;
  isUcObjCarcImplicitlyUcUnretainedUcType @142 :Bool;
  isUcObjCBoxableUcRecordUcType @143 :Bool;
  isUcObjCBuiltinUcType @144 :Bool;
  isUcObjCClassUcOrUcClassUcKindUcOfUcType @145 :Bool;
  isUcObjCClassUcType @146 :Bool;
  isUcObjCIdUcType @147 :Bool;
  isUcObjCIndependentUcClassUcType @148 :Bool;
  isUcObjCIndirectUcLifetimeUcType @149 :Bool;
  isUcObjCInertUcUnsafeUcUnretainedUcType @150 :Bool;
  isUcObjCLifetimeUcType @151 :Bool;
  isUcObjCnsObjectUcType @152 :Bool;
  isUcObjCObjectUcOrUcInterfaceUcType @153 :Bool;
  isUcObjCObjectUcPointerUcType @154 :Bool;
  isUcObjCObjectUcType @155 :Bool;
  isUcObjCQualifiedUcClassUcType @156 :Bool;
  isUcObjCQualifiedUcIdUcType @157 :Bool;
  isUcObjCQualifiedUcInterfaceUcType @158 :Bool;
  isUcObjCRetainableUcType @159 :Bool;
  isUcObjCSelUcType @160 :Bool;
  isUcObjectUcPointerUcType @161 :Bool;
  isUcObjectUcType @162 :Bool;
  isUcOpenClSpecificUcType @163 :Bool;
  isUcOverloadableUcType @164 :Bool;
  isUcPipeUcType @165 :Bool;
  isUcPlaceholderUcType @166 :Bool;
  isUcPointerUcType @167 :Bool;
  isUcPromotableUcIntegerUcType @168 :Bool;
  isUcQueueT @169 :Bool;
  isRValueUcReferenceUcType @170 :Bool;
  isUcRealUcFloatingUcType @171 :Bool;
  isUcRealUcType @172 :Bool;
  isUcRecordUcType @173 :Bool;
  isUcReferenceUcType @174 :Bool;
  isUcReserveIdt @175 :Bool;
  isUcSamplerT @176 :Bool;
  isUcSaturatedUcFixedUcPointUcType @177 :Bool;
  isUcScalarUcType @178 :Bool;
  isUcScopedUcEnumeralUcType @179 :Bool;
  isUcSignedUcFixedUcPointUcType @180 :Bool;
  isUcSignedUcIntegerUcOrUcEnumerationUcType @181 :Bool;
  isUcSignedUcIntegerUcType @182 :Bool;
  isUcSizelessUcBuiltinUcType @183 :Bool;
  isUcSizelessUcType @184 :Bool;
  isUcSpecifierUcType @185 :Bool;
  isUcStandardUcLayoutUcType @186 :Bool;
  isUcStdUcByteUcType @187 :Bool;
  isUcStructuralUcType @188 :Bool;
  isUcStructureUcOrUcClassUcType @189 :Bool;
  isUcStructureUcType @190 :Bool;
  isUcTemplateUcTypeUcParmUcType @191 :Bool;
  isUcTypedefUcNameUcType @192 :Bool;
  isUcUndeducedUcAutoUcType @193 :Bool;
  isUcUndeducedUcType @194 :Bool;
  isUcUnionUcType @195 :Bool;
  isUcUnsaturatedUcFixedUcPointUcType @196 :Bool;
  isUcUnscopedUcEnumerationUcType @197 :Bool;
  isUcUnsignedUcFixedUcPointUcType @198 :Bool;
  isUcUnsignedUcIntegerUcOrUcEnumerationUcType @199 :Bool;
  isUcUnsignedUcIntegerUcType @200 :Bool;
  isVlstBuiltinUcType @201 :Bool;
  isUcVariableUcArrayUcType @202 :Bool;
  isUcVariablyUcModifiedUcType @203 :Bool;
  isUcVectorUcType @204 :Bool;
  isUcVisibilityUcExplicit @205 :Bool;
  isUcVoidUcPointerUcType @206 :Bool;
  isUcVoidUcType @207 :Bool;
  isUcWideUcCharacterUcType @208 :Bool;
  isUcQualified @209 :Bool;
  addressUcSpace @210 :LangAS;
  objCLifetime @211 :ObjCLifetime;
  hasUcAddressUcSpace @212 :Bool;
  hasUcLocalUcNonUcFastUcQualifiers @213 :Bool;
  hasUcLocalUcQualifiers @214 :Bool;
  hasUcNonUcTrivialUcObjCLifetime @215 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcCopyCUnion @216 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcDefaultUcInitializeCUnion @217 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcDestructCUnion @218 :Bool;
  hasUcQualifiers @219 :Bool;
  hasUcStrongUcOrUcWeakUcObjCLifetime @220 :Bool;
  isCForbiddenLValueUcType @221 :Bool;
  isCxx11PodType @222 :Bool;
  isCxx98PodType @223 :Bool;
  isUcCanonical @224 :Bool;
  isUcCanonicalUcAsUcParam @225 :Bool;
  isUcConstUcQualified @226 :Bool;
  isUcConstant @227 :Bool;
  isUcLocalUcConstUcQualified @228 :Bool;
  isUcLocalUcRestrictUcQualified @229 :Bool;
  isUcLocalUcVolatileUcQualified @230 :Bool;
  isUcNonUcTrivialUcToUcPrimitiveUcCopy @231 :PrimitiveCopyKind;
  isUcNonUcTrivialUcToUcPrimitiveUcDefaultUcInitialize @232 :PrimitiveDefaultInitializeKind;
  isUcNonUcTrivialUcToUcPrimitiveUcDestructiveUcMove @233 :PrimitiveCopyKind;
  isUcNonUcWeakUcInMrrWithUcObjCWeak @234 :Bool;
  isUcNull @235 :Bool;
  isUcObjCgcStrong @236 :Bool;
  isUcObjCgcWeak @237 :Bool;
  isPodType @238 :Bool;
  isUcRestrictUcQualified @239 :Bool;
  isUcTrivialUcType @240 :Bool;
  isUcTriviallyUcCopyableUcType @241 :Bool;
  isUcVolatileUcQualified @242 :Bool;
  mayUcBeUcDynamicUcClass @243 :Bool;
  mayUcBeUcNotUcDynamicUcClass @244 :Bool;
}

struct TemplateTypeParmType @0xe786690ae408805f {
  type @0:Type;
  isUcParameterUcPack @1 :Bool;
  isUcSugared @2 :Bool;
}

struct TemplateSpecializationType @0xfa056c60dc6c1e09 {
  type @0:Type;
  isUcCurrentUcInstantiation @1 :Bool;
  isUcSugared @2 :Bool;
  isUcTypeUcAlias @3 :Bool;
}

struct TagType @0xc5f6e35856974d9c {
  type @0:Type;
  isUcBeingUcDefined @1 :Bool;
}

struct RecordType @0xa5a5c23895050f69 {
  tagUcType @0:TagType;
  hasUcConstUcFields @1 :Bool;
  isUcSugared @2 :Bool;
}

struct EnumType @0xeceb1819da64112c {
  tagUcType @0:TagType;
  isUcSugared @1 :Bool;
}

struct SubstTemplateTypeParmType @0x8be567616218a913 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct SubstTemplateTypeParmPackType @0x8e845eb2b04a7eee {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct ReferenceType @0xf0b00042a60e0b80 {
  type @0:Type;
  isUcInnerUcReference @1 :Bool;
  isUcSpelledUcAsLValue @2 :Bool;
}

struct RValueReferenceType @0xbecf2238a530256c {
  referenceUcType @0:ReferenceType;
  isUcSugared @1 :Bool;
}

struct LValueReferenceType @0xc3ffdde8d840e1f8 {
  referenceUcType @0:ReferenceType;
  isUcSugared @1 :Bool;
}

struct PointerType @0xbfb931627d65b65e {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct PipeType @0xa153518ebe860937 {
  type @0:Type;
  isUcReadUcOnly @1 :Bool;
  isUcSugared @2 :Bool;
}

struct ParenType @0xff7efc28ab285ec4 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct PackExpansionType @0xd267d004a8c359b6 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct ObjCTypeParamType @0xac0ad54259298e1c {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct ObjCObjectType @0xdb7630160ba51f56 {
  type @0:Type;
  isUcKindUcOfUcType @1 :Bool;
  isUcKindUcOfUcTypeUcAsUcWritten @2 :Bool;
  isUcObjCClass @3 :Bool;
  isUcObjCId @4 :Bool;
  isUcObjCQualifiedUcClass @5 :Bool;
  isUcObjCQualifiedUcId @6 :Bool;
  isUcObjCUnqualifiedUcClass @7 :Bool;
  isUcObjCUnqualifiedUcId @8 :Bool;
  isUcObjCUnqualifiedUcIdUcOrUcClass @9 :Bool;
  isUcSpecialized @10 :Bool;
  isUcSpecializedUcAsUcWritten @11 :Bool;
  isUcSugared @12 :Bool;
  isUcUnspecialized @13 :Bool;
  isUcUnspecializedUcAsUcWritten @14 :Bool;
}

struct ObjCInterfaceType @0xeaf73283b88684f2 {
  objCObjectUcType @0:ObjCObjectType;
}

struct ObjCObjectPointerType @0x83fd17147f556ba9 {
  type @0:Type;
  isUcKindUcOfUcType @1 :Bool;
  isUcObjCIdUcOrUcClassUcType @2 :Bool;
  isUcSpecialized @3 :Bool;
  isUcSpecializedUcAsUcWritten @4 :Bool;
  isUcSugared @5 :Bool;
  isUcUnspecialized @6 :Bool;
  isUcUnspecializedUcAsUcWritten @7 :Bool;
}

struct MemberPointerType @0xcd7316ac3d809b66 {
  type @0:Type;
  isUcMemberUcDataUcPointer @1 :Bool;
  isUcMemberUcFunctionUcPointer @2 :Bool;
  isUcSugared @3 :Bool;
}

struct MatrixType @0xfce6c7a94952d4ac {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct DependentSizedMatrixType @0xa068a0de73cc64b1 {
  matrixUcType @0:MatrixType;
  attributeUcToken @1 :TokenOffset;
}

struct ConstantMatrixType @0x9fe8639dcd3a4d9e {
  matrixUcType @0:MatrixType;
}

struct MacroQualifiedType @0x8494e2a4b85c9f19 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct InjectedClassNameType @0xa6c2e5edfcbf618a {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct FunctionType @0x948975919b3cdebd {
  type @0:Type;
  callUcConv @1 :CallingConv;
  cmseNsCallUcAttribute @2 :Bool;
  hasUcRegUcParm @3 :Bool;
  noUcReturnUcAttribute @4 :Bool;
  isUcConst @5 :Bool;
  isUcRestrict @6 :Bool;
  isUcVolatile @7 :Bool;
}

struct FunctionProtoType @0xfbd27cbfbac5efbb {
  functionUcType @0:FunctionType;
  canUcThrow @1 :CanThrowResult;
  ellipsisUcToken @2 :TokenOffset;
  exceptionUcSpecUcType @3 :ExceptionSpecificationType;
  referenceUcQualifier @4 :RefQualifierKind;
  hasUcDependentUcExceptionUcSpec @5 :Bool;
  hasUcDynamicUcExceptionUcSpec @6 :Bool;
  hasUcExceptionUcSpec @7 :Bool;
  hasUcExtUcParameterUcInfos @8 :Bool;
  hasUcInstantiationUcDependentUcExceptionUcSpec @9 :Bool;
  hasUcNoexceptUcExceptionUcSpec @10 :Bool;
  hasUcTrailingUcReturn @11 :Bool;
  isUcNothrow @12 :Bool;
  isUcSugared @13 :Bool;
  isUcTemplateUcVariadic @14 :Bool;
  isUcVariadic @15 :Bool;
}

struct FunctionNoProtoType @0x8290ca5570d70e02 {
  functionUcType @0:FunctionType;
  isUcSugared @1 :Bool;
}

struct ExtIntType @0xc48fbfce9c3676d5 {
  type @0:Type;
  isUcSigned @1 :Bool;
  isUcSugared @2 :Bool;
  isUcUnsigned @3 :Bool;
}

struct DependentVectorType @0xc6ccf5cfae8940a4 {
  type @0:Type;
  attributeUcToken @1 :TokenOffset;
  vectorUcKind @2 :VectorKind;
  isUcSugared @3 :Bool;
}

struct DependentSizedExtVectorType @0xd1e2872240f527b7 {
  type @0:Type;
  attributeUcToken @1 :TokenOffset;
  isUcSugared @2 :Bool;
}

struct DependentExtIntType @0xedfca4126b0a36ef {
  type @0:Type;
  isUcSigned @1 :Bool;
  isUcSugared @2 :Bool;
  isUcUnsigned @3 :Bool;
}

struct DependentAddressSpaceType @0xadb13a8d42ac14c8 {
  type @0:Type;
  attributeUcToken @1 :TokenOffset;
  isUcSugared @2 :Bool;
}

struct DeducedType @0x9b62aead3bf58839 {
  type @0:Type;
  isUcDeduced @1 :Bool;
  isUcSugared @2 :Bool;
}

struct DeducedTemplateSpecializationType @0x9a096862188ecc6e {
  deducedUcType @0:DeducedType;
}

struct AutoType @0x84e063e662c52b4b {
  deducedUcType @0:DeducedType;
  keyword @1 :AutoTypeKeyword;
  isUcConstrained @2 :Bool;
  isUcDecltypeUcAuto @3 :Bool;
}

struct DecltypeType @0x8167d2682b1df777 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct ComplexType @0xedb0c5447bfbabbd {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct BuiltinType @0xb9df1f7a0b9bd785 {
  type @0:Type;
  isUcFloatingUcPoint @1 :Bool;
  isUcInteger @2 :Bool;
  isUcSignedUcInteger @3 :Bool;
  isUcSugared @4 :Bool;
  isUcUnsignedUcInteger @5 :Bool;
}

struct BlockPointerType @0xcf1a6a054f3aaac3 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct AttributedType @0xfae2a754903efb8f {
  type @0:Type;
  attributeUcKind @1 :AttributeKind;
  isUcCallingUcConv @2 :Bool;
  isMsTypeUcSpec @3 :Bool;
  isUcQualifier @4 :Bool;
  isUcSugared @5 :Bool;
}

struct AtomicType @0x856d35fbcc3358de {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct ArrayType @0xf51c56dc11dd4d5a {
  type @0:Type;
  sizeUcModifier @1 :ArraySizeModifier;
}

struct VariableArrayType @0x82d4d76c013109f5 {
  arrayUcType @0:ArrayType;
  bracketsUcRange @1 :TokenRange;
  lBracketUcToken @2 :TokenOffset;
  rBracketUcToken @3 :TokenOffset;
  isUcSugared @4 :Bool;
}

struct IncompleteArrayType @0xd4f7a93527ce975e {
  arrayUcType @0:ArrayType;
  isUcSugared @1 :Bool;
}

struct DependentSizedArrayType @0xeb3238fd4299c322 {
  arrayUcType @0:ArrayType;
  bracketsUcRange @1 :TokenRange;
  lBracketUcToken @2 :TokenOffset;
  rBracketUcToken @3 :TokenOffset;
  isUcSugared @4 :Bool;
}

struct ConstantArrayType @0xa122a9fa825e1120 {
  arrayUcType @0:ArrayType;
  isUcSugared @1 :Bool;
}

struct AdjustedType @0x85459004973a94cc {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct DecayedType @0x9500bc81a552e7af {
  adjustedUcType @0:AdjustedType;
}

struct VectorType @0xeb831d4f2ea047d6 {
  type @0:Type;
  vectorUcKind @1 :VectorKind;
  isUcSugared @2 :Bool;
}

struct ExtVectorType @0x9822bb6b9f91b427 {
  vectorUcType @0:VectorType;
}

struct UnresolvedUsingType @0xb008cd48c50f310f {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct UnaryTransformType @0xf3f137ad71547e38 {
  type @0:Type;
  uttKind @1 :UTTKind;
  isUcSugared @2 :Bool;
}

struct TypedefType @0x9983fc1d3106ae9c {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct TypeOfType @0xc82d0038e5e0ea52 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct TypeOfExprType @0x9be487fb240a6fe1 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct EntityList @0xf26db0d046aab9c9 {
  decl @0 :List(Decl);
  classUcScopeUcFunctionUcSpecializationUcDecl @1 :List(ClassScopeFunctionSpecializationDecl);
  capturedUcDecl @2 :List(CapturedDecl);
  blockUcDecl @3 :List(BlockDecl);
  accessUcSpecUcDecl @4 :List(AccessSpecDecl);
  translationUcUnitUcDecl @5 :List(TranslationUnitDecl);
  staticUcAssertUcDecl @6 :List(StaticAssertDecl);
  requiresUcExprUcBodyUcDecl @7 :List(RequiresExprBodyDecl);
  pragmaUcDetectUcMismatchUcDecl @8 :List(PragmaDetectMismatchDecl);
  pragmaUcCommentUcDecl @9 :List(PragmaCommentDecl);
  objCPropertyUcImplUcDecl @10 :List(ObjCPropertyImplDecl);
  namedUcDecl @11 :List(NamedDecl);
  labelUcDecl @12 :List(LabelDecl);
  baseUcUsingUcDecl @13 :List(BaseUsingDecl);
  usingUcEnumUcDecl @14 :List(UsingEnumDecl);
  usingUcDecl @15 :List(UsingDecl);
  valueUcDecl @16 :List(ValueDecl);
  unresolvedUcUsingUcValueUcDecl @17 :List(UnresolvedUsingValueDecl);
  templateUcParamUcObjectUcDecl @18 :List(TemplateParamObjectDecl);
  ompDeclareUcReductionUcDecl @19 :List(OMPDeclareReductionDecl);
  msGuidUcDecl @20 :List(MSGuidDecl);
  indirectUcFieldUcDecl @21 :List(IndirectFieldDecl);
  enumUcConstantUcDecl @22 :List(EnumConstantDecl);
  declaratorUcDecl @23 :List(DeclaratorDecl);
  varUcDecl @24 :List(VarDecl);
  parmUcVarUcDecl @25 :List(ParmVarDecl);
  ompCapturedUcExprUcDecl @26 :List(OMPCapturedExprDecl);
  implicitUcParamUcDecl @27 :List(ImplicitParamDecl);
  decompositionUcDecl @28 :List(DecompositionDecl);
  varUcTemplateUcSpecializationUcDecl @29 :List(VarTemplateSpecializationDecl);
  varUcTemplateUcPartialUcSpecializationUcDecl @30 :List(VarTemplatePartialSpecializationDecl);
  nonUcTypeUcTemplateUcParmUcDecl @31 :List(NonTypeTemplateParmDecl);
  msPropertyUcDecl @32 :List(MSPropertyDecl);
  functionUcDecl @33 :List(FunctionDecl);
  cxxMethodUcDecl @34 :List(CXXMethodDecl);
  cxxDestructorUcDecl @35 :List(CXXDestructorDecl);
  cxxConversionUcDecl @36 :List(CXXConversionDecl);
  cxxConstructorUcDecl @37 :List(CXXConstructorDecl);
  cxxDeductionUcGuideUcDecl @38 :List(CXXDeductionGuideDecl);
  fieldUcDecl @39 :List(FieldDecl);
  objCIvarUcDecl @40 :List(ObjCIvarDecl);
  objCAtUcDefsUcFieldUcDecl @41 :List(ObjCAtDefsFieldDecl);
  bindingUcDecl @42 :List(BindingDecl);
  usingUcShadowUcDecl @43 :List(UsingShadowDecl);
  constructorUcUsingUcShadowUcDecl @44 :List(ConstructorUsingShadowDecl);
  usingUcPackUcDecl @45 :List(UsingPackDecl);
  usingUcDirectiveUcDecl @46 :List(UsingDirectiveDecl);
  unresolvedUcUsingUcIfUcExistsUcDecl @47 :List(UnresolvedUsingIfExistsDecl);
  typeUcDecl @48 :List(TypeDecl);
  templateUcTypeUcParmUcDecl @49 :List(TemplateTypeParmDecl);
  tagUcDecl @50 :List(TagDecl);
  recordUcDecl @51 :List(RecordDecl);
  cxxRecordUcDecl @52 :List(CXXRecordDecl);
  classUcTemplateUcSpecializationUcDecl @53 :List(ClassTemplateSpecializationDecl);
  classUcTemplateUcPartialUcSpecializationUcDecl @54 :List(ClassTemplatePartialSpecializationDecl);
  enumUcDecl @55 :List(EnumDecl);
  unresolvedUcUsingUcTypenameUcDecl @56 :List(UnresolvedUsingTypenameDecl);
  typedefUcNameUcDecl @57 :List(TypedefNameDecl);
  typedefUcDecl @58 :List(TypedefDecl);
  typeUcAliasUcDecl @59 :List(TypeAliasDecl);
  objCTypeUcParamUcDecl @60 :List(ObjCTypeParamDecl);
  templateUcDecl @61 :List(TemplateDecl);
  redeclarableUcTemplateUcDecl @62 :List(RedeclarableTemplateDecl);
  functionUcTemplateUcDecl @63 :List(FunctionTemplateDecl);
  classUcTemplateUcDecl @64 :List(ClassTemplateDecl);
  varUcTemplateUcDecl @65 :List(VarTemplateDecl);
  typeUcAliasUcTemplateUcDecl @66 :List(TypeAliasTemplateDecl);
  conceptUcDecl @67 :List(ConceptDecl);
  builtinUcTemplateUcDecl @68 :List(BuiltinTemplateDecl);
  templateUcTemplateUcParmUcDecl @69 :List(TemplateTemplateParmDecl);
  objCPropertyUcDecl @70 :List(ObjCPropertyDecl);
  objCMethodUcDecl @71 :List(ObjCMethodDecl);
  objCContainerUcDecl @72 :List(ObjCContainerDecl);
  objCCategoryUcDecl @73 :List(ObjCCategoryDecl);
  objCProtocolUcDecl @74 :List(ObjCProtocolDecl);
  objCInterfaceUcDecl @75 :List(ObjCInterfaceDecl);
  objCImplUcDecl @76 :List(ObjCImplDecl);
  objCCategoryUcImplUcDecl @77 :List(ObjCCategoryImplDecl);
  objCImplementationUcDecl @78 :List(ObjCImplementationDecl);
  objCCompatibleUcAliasUcDecl @79 :List(ObjCCompatibleAliasDecl);
  namespaceUcDecl @80 :List(NamespaceDecl);
  namespaceUcAliasUcDecl @81 :List(NamespaceAliasDecl);
  linkageUcSpecUcDecl @82 :List(LinkageSpecDecl);
  lifetimeUcExtendedUcTemporaryUcDecl @83 :List(LifetimeExtendedTemporaryDecl);
  importUcDecl @84 :List(ImportDecl);
  friendUcTemplateUcDecl @85 :List(FriendTemplateDecl);
  friendUcDecl @86 :List(FriendDecl);
  fileUcScopeUcAsmUcDecl @87 :List(FileScopeAsmDecl);
  externCContextUcDecl @88 :List(ExternCContextDecl);
  exportUcDecl @89 :List(ExportDecl);
  emptyUcDecl @90 :List(EmptyDecl);
  stmt @91 :List(Stmt);
  sehTryUcStmt @92 :List(SEHTryStmt);
  sehLeaveUcStmt @93 :List(SEHLeaveStmt);
  sehFinallyUcStmt @94 :List(SEHFinallyStmt);
  sehExceptUcStmt @95 :List(SEHExceptStmt);
  returnUcStmt @96 :List(ReturnStmt);
  objCForUcCollectionUcStmt @97 :List(ObjCForCollectionStmt);
  objCAutoreleaseUcPoolUcStmt @98 :List(ObjCAutoreleasePoolStmt);
  objCAtUcTryUcStmt @99 :List(ObjCAtTryStmt);
  objCAtUcThrowUcStmt @100 :List(ObjCAtThrowStmt);
  objCAtUcSynchronizedUcStmt @101 :List(ObjCAtSynchronizedStmt);
  objCAtUcFinallyUcStmt @102 :List(ObjCAtFinallyStmt);
  objCAtUcCatchUcStmt @103 :List(ObjCAtCatchStmt);
  ompExecutableUcDirective @104 :List(OMPExecutableDirective);
  ompDispatchUcDirective @105 :List(OMPDispatchDirective);
  ompDepobjUcDirective @106 :List(OMPDepobjDirective);
  ompCriticalUcDirective @107 :List(OMPCriticalDirective);
  ompCancellationUcPointUcDirective @108 :List(OMPCancellationPointDirective);
  ompCancelUcDirective @109 :List(OMPCancelDirective);
  ompBarrierUcDirective @110 :List(OMPBarrierDirective);
  ompAtomicUcDirective @111 :List(OMPAtomicDirective);
  ompTeamsUcDirective @112 :List(OMPTeamsDirective);
  ompTaskyieldUcDirective @113 :List(OMPTaskyieldDirective);
  ompTaskwaitUcDirective @114 :List(OMPTaskwaitDirective);
  ompTaskgroupUcDirective @115 :List(OMPTaskgroupDirective);
  ompTaskUcDirective @116 :List(OMPTaskDirective);
  ompTargetUcUpdateUcDirective @117 :List(OMPTargetUpdateDirective);
  ompTargetUcTeamsUcDirective @118 :List(OMPTargetTeamsDirective);
  ompTargetUcParallelUcDirective @119 :List(OMPTargetParallelDirective);
  ompTargetUcExitUcDataUcDirective @120 :List(OMPTargetExitDataDirective);
  ompTargetUcEnterUcDataUcDirective @121 :List(OMPTargetEnterDataDirective);
  ompTargetUcDirective @122 :List(OMPTargetDirective);
  ompTargetUcDataUcDirective @123 :List(OMPTargetDataDirective);
  ompSingleUcDirective @124 :List(OMPSingleDirective);
  ompSectionsUcDirective @125 :List(OMPSectionsDirective);
  ompSectionUcDirective @126 :List(OMPSectionDirective);
  ompScanUcDirective @127 :List(OMPScanDirective);
  ompParallelUcSectionsUcDirective @128 :List(OMPParallelSectionsDirective);
  ompParallelUcMasterUcDirective @129 :List(OMPParallelMasterDirective);
  ompParallelUcDirective @130 :List(OMPParallelDirective);
  ompOrderedUcDirective @131 :List(OMPOrderedDirective);
  ompMasterUcDirective @132 :List(OMPMasterDirective);
  ompMaskedUcDirective @133 :List(OMPMaskedDirective);
  ompLoopUcBasedUcDirective @134 :List(OMPLoopBasedDirective);
  ompUnrollUcDirective @135 :List(OMPUnrollDirective);
  ompTileUcDirective @136 :List(OMPTileDirective);
  ompLoopUcDirective @137 :List(OMPLoopDirective);
  ompForUcSimdUcDirective @138 :List(OMPForSimdDirective);
  ompForUcDirective @139 :List(OMPForDirective);
  ompDistributeUcSimdUcDirective @140 :List(OMPDistributeSimdDirective);
  ompDistributeUcParallelUcForUcSimdUcDirective @141 :List(OMPDistributeParallelForSimdDirective);
  ompDistributeUcParallelUcForUcDirective @142 :List(OMPDistributeParallelForDirective);
  ompDistributeUcDirective @143 :List(OMPDistributeDirective);
  ompTeamsUcDistributeUcSimdUcDirective @144 :List(OMPTeamsDistributeSimdDirective);
  ompTeamsUcDistributeUcParallelUcForUcSimdUcDirective @145 :List(OMPTeamsDistributeParallelForSimdDirective);
  ompTeamsUcDistributeUcParallelUcForUcDirective @146 :List(OMPTeamsDistributeParallelForDirective);
  ompTeamsUcDistributeUcDirective @147 :List(OMPTeamsDistributeDirective);
  ompTaskUcLoopUcSimdUcDirective @148 :List(OMPTaskLoopSimdDirective);
  ompTaskUcLoopUcDirective @149 :List(OMPTaskLoopDirective);
  ompTargetUcTeamsUcDistributeUcSimdUcDirective @150 :List(OMPTargetTeamsDistributeSimdDirective);
  ompTargetUcTeamsUcDistributeUcParallelUcForUcSimdUcDirective @151 :List(OMPTargetTeamsDistributeParallelForSimdDirective);
  ompTargetUcTeamsUcDistributeUcParallelUcForUcDirective @152 :List(OMPTargetTeamsDistributeParallelForDirective);
  ompTargetUcTeamsUcDistributeUcDirective @153 :List(OMPTargetTeamsDistributeDirective);
  ompTargetUcSimdUcDirective @154 :List(OMPTargetSimdDirective);
  ompTargetUcParallelUcForUcSimdUcDirective @155 :List(OMPTargetParallelForSimdDirective);
  ompTargetUcParallelUcForUcDirective @156 :List(OMPTargetParallelForDirective);
  ompSimdUcDirective @157 :List(OMPSimdDirective);
  ompParallelUcMasterUcTaskUcLoopUcSimdUcDirective @158 :List(OMPParallelMasterTaskLoopSimdDirective);
  ompParallelUcMasterUcTaskUcLoopUcDirective @159 :List(OMPParallelMasterTaskLoopDirective);
  ompParallelUcForUcSimdUcDirective @160 :List(OMPParallelForSimdDirective);
  ompParallelUcForUcDirective @161 :List(OMPParallelForDirective);
  ompMasterUcTaskUcLoopUcSimdUcDirective @162 :List(OMPMasterTaskLoopSimdDirective);
  ompMasterUcTaskUcLoopUcDirective @163 :List(OMPMasterTaskLoopDirective);
  ompInteropUcDirective @164 :List(OMPInteropDirective);
  ompFlushUcDirective @165 :List(OMPFlushDirective);
  ompCanonicalUcLoop @166 :List(OMPCanonicalLoop);
  nullUcStmt @167 :List(NullStmt);
  msDependentUcExistsUcStmt @168 :List(MSDependentExistsStmt);
  indirectUcGotoUcStmt @169 :List(IndirectGotoStmt);
  ifUcStmt @170 :List(IfStmt);
  gotoUcStmt @171 :List(GotoStmt);
  forUcStmt @172 :List(ForStmt);
  doUcStmt @173 :List(DoStmt);
  declUcStmt @174 :List(DeclStmt);
  coroutineUcBodyUcStmt @175 :List(CoroutineBodyStmt);
  coreturnUcStmt @176 :List(CoreturnStmt);
  continueUcStmt @177 :List(ContinueStmt);
  compoundUcStmt @178 :List(CompoundStmt);
  capturedUcStmt @179 :List(CapturedStmt);
  cxxTryUcStmt @180 :List(CXXTryStmt);
  cxxForUcRangeUcStmt @181 :List(CXXForRangeStmt);
  cxxCatchUcStmt @182 :List(CXXCatchStmt);
  breakUcStmt @183 :List(BreakStmt);
  asmUcStmt @184 :List(AsmStmt);
  msAsmUcStmt @185 :List(MSAsmStmt);
  gccAsmUcStmt @186 :List(GCCAsmStmt);
  whileUcStmt @187 :List(WhileStmt);
  valueUcStmt @188 :List(ValueStmt);
  labelUcStmt @189 :List(LabelStmt);
  expr @190 :List(Expr);
  designatedUcInitUcUpdateUcExpr @191 :List(DesignatedInitUpdateExpr);
  designatedUcInitUcExpr @192 :List(DesignatedInitExpr);
  dependentUcScopeUcDeclUcRefUcExpr @193 :List(DependentScopeDeclRefExpr);
  dependentUcCoawaitUcExpr @194 :List(DependentCoawaitExpr);
  declUcRefUcExpr @195 :List(DeclRefExpr);
  coroutineUcSuspendUcExpr @196 :List(CoroutineSuspendExpr);
  coawaitUcExpr @197 :List(CoawaitExpr);
  coyieldUcExpr @198 :List(CoyieldExpr);
  convertUcVectorUcExpr @199 :List(ConvertVectorExpr);
  conceptUcSpecializationUcExpr @200 :List(ConceptSpecializationExpr);
  compoundUcLiteralUcExpr @201 :List(CompoundLiteralExpr);
  chooseUcExpr @202 :List(ChooseExpr);
  characterUcLiteral @203 :List(CharacterLiteral);
  castUcExpr @204 :List(CastExpr);
  implicitUcCastUcExpr @205 :List(ImplicitCastExpr);
  explicitUcCastUcExpr @206 :List(ExplicitCastExpr);
  cxxNamedUcCastUcExpr @207 :List(CXXNamedCastExpr);
  cxxDynamicUcCastUcExpr @208 :List(CXXDynamicCastExpr);
  cxxConstUcCastUcExpr @209 :List(CXXConstCastExpr);
  cxxAddrspaceUcCastUcExpr @210 :List(CXXAddrspaceCastExpr);
  cxxStaticUcCastUcExpr @211 :List(CXXStaticCastExpr);
  cxxReinterpretUcCastUcExpr @212 :List(CXXReinterpretCastExpr);
  cxxFunctionalUcCastUcExpr @213 :List(CXXFunctionalCastExpr);
  cStyleUcCastUcExpr @214 :List(CStyleCastExpr);
  builtinUcBitUcCastUcExpr @215 :List(BuiltinBitCastExpr);
  objCBridgedUcCastUcExpr @216 :List(ObjCBridgedCastExpr);
  callUcExpr @217 :List(CallExpr);
  cxxOperatorUcCallUcExpr @218 :List(CXXOperatorCallExpr);
  cxxMemberUcCallUcExpr @219 :List(CXXMemberCallExpr);
  cudaKernelUcCallUcExpr @220 :List(CUDAKernelCallExpr);
  userUcDefinedUcLiteral @221 :List(UserDefinedLiteral);
  cxxUuidofUcExpr @222 :List(CXXUuidofExpr);
  cxxUnresolvedUcConstructUcExpr @223 :List(CXXUnresolvedConstructExpr);
  cxxTypeidUcExpr @224 :List(CXXTypeidExpr);
  cxxThrowUcExpr @225 :List(CXXThrowExpr);
  cxxThisUcExpr @226 :List(CXXThisExpr);
  cxxStdUcInitializerUcListUcExpr @227 :List(CXXStdInitializerListExpr);
  cxxScalarUcValueUcInitUcExpr @228 :List(CXXScalarValueInitExpr);
  cxxRewrittenUcBinaryUcOperator @229 :List(CXXRewrittenBinaryOperator);
  cxxPseudoUcDestructorUcExpr @230 :List(CXXPseudoDestructorExpr);
  cxxNullUcPtrUcLiteralUcExpr @231 :List(CXXNullPtrLiteralExpr);
  cxxNoexceptUcExpr @232 :List(CXXNoexceptExpr);
  cxxNewUcExpr @233 :List(CXXNewExpr);
  cxxInheritedUcCtorUcInitUcExpr @234 :List(CXXInheritedCtorInitExpr);
  cxxFoldUcExpr @235 :List(CXXFoldExpr);
  cxxDependentUcScopeUcMemberUcExpr @236 :List(CXXDependentScopeMemberExpr);
  cxxDeleteUcExpr @237 :List(CXXDeleteExpr);
  cxxDefaultUcInitUcExpr @238 :List(CXXDefaultInitExpr);
  cxxDefaultUcArgUcExpr @239 :List(CXXDefaultArgExpr);
  cxxConstructUcExpr @240 :List(CXXConstructExpr);
  cxxTemporaryUcObjectUcExpr @241 :List(CXXTemporaryObjectExpr);
  cxxBoolUcLiteralUcExpr @242 :List(CXXBoolLiteralExpr);
  cxxBindUcTemporaryUcExpr @243 :List(CXXBindTemporaryExpr);
  blockUcExpr @244 :List(BlockExpr);
  binaryUcOperator @245 :List(BinaryOperator);
  compoundUcAssignUcOperator @246 :List(CompoundAssignOperator);
  atomicUcExpr @247 :List(AtomicExpr);
  asUcTypeUcExpr @248 :List(AsTypeExpr);
  arrayUcTypeUcTraitUcExpr @249 :List(ArrayTypeTraitExpr);
  arrayUcSubscriptUcExpr @250 :List(ArraySubscriptExpr);
  arrayUcInitUcLoopUcExpr @251 :List(ArrayInitLoopExpr);
  arrayUcInitUcIndexUcExpr @252 :List(ArrayInitIndexExpr);
  addrUcLabelUcExpr @253 :List(AddrLabelExpr);
  abstractUcConditionalUcOperator @254 :List(AbstractConditionalOperator);
  conditionalUcOperator @255 :List(ConditionalOperator);
  binaryUcConditionalUcOperator @256 :List(BinaryConditionalOperator);
  vaArgUcExpr @257 :List(VAArgExpr);
  unaryUcOperator @258 :List(UnaryOperator);
  unaryUcExprUcOrUcTypeUcTraitUcExpr @259 :List(UnaryExprOrTypeTraitExpr);
  typoUcExpr @260 :List(TypoExpr);
  typeUcTraitUcExpr @261 :List(TypeTraitExpr);
  substUcNonUcTypeUcTemplateUcParmUcPackUcExpr @262 :List(SubstNonTypeTemplateParmPackExpr);
  substUcNonUcTypeUcTemplateUcParmUcExpr @263 :List(SubstNonTypeTemplateParmExpr);
  stringUcLiteral @264 :List(StringLiteral);
  stmtUcExpr @265 :List(StmtExpr);
  sourceUcLocUcExpr @266 :List(SourceLocExpr);
  sizeUcOfUcPackUcExpr @267 :List(SizeOfPackExpr);
  shuffleUcVectorUcExpr @268 :List(ShuffleVectorExpr);
  syclUniqueUcStableUcNameUcExpr @269 :List(SYCLUniqueStableNameExpr);
  requiresUcExpr @270 :List(RequiresExpr);
  recoveryUcExpr @271 :List(RecoveryExpr);
  pseudoUcObjectUcExpr @272 :List(PseudoObjectExpr);
  predefinedUcExpr @273 :List(PredefinedExpr);
  parenUcListUcExpr @274 :List(ParenListExpr);
  parenUcExpr @275 :List(ParenExpr);
  packUcExpansionUcExpr @276 :List(PackExpansionExpr);
  overloadUcExpr @277 :List(OverloadExpr);
  unresolvedUcMemberUcExpr @278 :List(UnresolvedMemberExpr);
  unresolvedUcLookupUcExpr @279 :List(UnresolvedLookupExpr);
  opaqueUcValueUcExpr @280 :List(OpaqueValueExpr);
  offsetUcOfUcExpr @281 :List(OffsetOfExpr);
  objCSubscriptUcRefUcExpr @282 :List(ObjCSubscriptRefExpr);
  objCStringUcLiteral @283 :List(ObjCStringLiteral);
  objCSelectorUcExpr @284 :List(ObjCSelectorExpr);
  objCProtocolUcExpr @285 :List(ObjCProtocolExpr);
  objCPropertyUcRefUcExpr @286 :List(ObjCPropertyRefExpr);
  objCMessageUcExpr @287 :List(ObjCMessageExpr);
  objCIvarUcRefUcExpr @288 :List(ObjCIvarRefExpr);
  objCIsaUcExpr @289 :List(ObjCIsaExpr);
  objCIndirectUcCopyUcRestoreUcExpr @290 :List(ObjCIndirectCopyRestoreExpr);
  objCEncodeUcExpr @291 :List(ObjCEncodeExpr);
  objCDictionaryUcLiteral @292 :List(ObjCDictionaryLiteral);
  objCBoxedUcExpr @293 :List(ObjCBoxedExpr);
  objCBoolUcLiteralUcExpr @294 :List(ObjCBoolLiteralExpr);
  objCAvailabilityUcCheckUcExpr @295 :List(ObjCAvailabilityCheckExpr);
  objCArrayUcLiteral @296 :List(ObjCArrayLiteral);
  ompIteratorUcExpr @297 :List(OMPIteratorExpr);
  ompArrayUcShapingUcExpr @298 :List(OMPArrayShapingExpr);
  ompArrayUcSectionUcExpr @299 :List(OMPArraySectionExpr);
  noUcInitUcExpr @300 :List(NoInitExpr);
  memberUcExpr @301 :List(MemberExpr);
  matrixUcSubscriptUcExpr @302 :List(MatrixSubscriptExpr);
  materializeUcTemporaryUcExpr @303 :List(MaterializeTemporaryExpr);
  msPropertyUcSubscriptUcExpr @304 :List(MSPropertySubscriptExpr);
  msPropertyUcRefUcExpr @305 :List(MSPropertyRefExpr);
  lambdaUcExpr @306 :List(LambdaExpr);
  integerUcLiteral @307 :List(IntegerLiteral);
  initUcListUcExpr @308 :List(InitListExpr);
  implicitUcValueUcInitUcExpr @309 :List(ImplicitValueInitExpr);
  imaginaryUcLiteral @310 :List(ImaginaryLiteral);
  genericUcSelectionUcExpr @311 :List(GenericSelectionExpr);
  gnuNullUcExpr @312 :List(GNUNullExpr);
  functionUcParmUcPackUcExpr @313 :List(FunctionParmPackExpr);
  fullUcExpr @314 :List(FullExpr);
  exprUcWithUcCleanups @315 :List(ExprWithCleanups);
  constantUcExpr @316 :List(ConstantExpr);
  floatingUcLiteral @317 :List(FloatingLiteral);
  fixedUcPointUcLiteral @318 :List(FixedPointLiteral);
  extUcVectorUcElementUcExpr @319 :List(ExtVectorElementExpr);
  expressionUcTraitUcExpr @320 :List(ExpressionTraitExpr);
  attributedUcStmt @321 :List(AttributedStmt);
  switchUcStmt @322 :List(SwitchStmt);
  switchUcCase @323 :List(SwitchCase);
  defaultUcStmt @324 :List(DefaultStmt);
  caseUcStmt @325 :List(CaseStmt);
  type @326 :List(Type);
  templateUcTypeUcParmUcType @327 :List(TemplateTypeParmType);
  templateUcSpecializationUcType @328 :List(TemplateSpecializationType);
  tagUcType @329 :List(TagType);
  recordUcType @330 :List(RecordType);
  enumUcType @331 :List(EnumType);
  substUcTemplateUcTypeUcParmUcType @332 :List(SubstTemplateTypeParmType);
  substUcTemplateUcTypeUcParmUcPackUcType @333 :List(SubstTemplateTypeParmPackType);
  referenceUcType @334 :List(ReferenceType);
  rValueUcReferenceUcType @335 :List(RValueReferenceType);
  lValueUcReferenceUcType @336 :List(LValueReferenceType);
  pointerUcType @337 :List(PointerType);
  pipeUcType @338 :List(PipeType);
  parenUcType @339 :List(ParenType);
  packUcExpansionUcType @340 :List(PackExpansionType);
  objCTypeUcParamUcType @341 :List(ObjCTypeParamType);
  objCObjectUcType @342 :List(ObjCObjectType);
  objCInterfaceUcType @343 :List(ObjCInterfaceType);
  objCObjectUcPointerUcType @344 :List(ObjCObjectPointerType);
  memberUcPointerUcType @345 :List(MemberPointerType);
  matrixUcType @346 :List(MatrixType);
  dependentUcSizedUcMatrixUcType @347 :List(DependentSizedMatrixType);
  constantUcMatrixUcType @348 :List(ConstantMatrixType);
  macroUcQualifiedUcType @349 :List(MacroQualifiedType);
  injectedUcClassUcNameUcType @350 :List(InjectedClassNameType);
  functionUcType @351 :List(FunctionType);
  functionUcProtoUcType @352 :List(FunctionProtoType);
  functionUcNoUcProtoUcType @353 :List(FunctionNoProtoType);
  extUcIntUcType @354 :List(ExtIntType);
  dependentUcVectorUcType @355 :List(DependentVectorType);
  dependentUcSizedUcExtUcVectorUcType @356 :List(DependentSizedExtVectorType);
  dependentUcExtUcIntUcType @357 :List(DependentExtIntType);
  dependentUcAddressUcSpaceUcType @358 :List(DependentAddressSpaceType);
  deducedUcType @359 :List(DeducedType);
  deducedUcTemplateUcSpecializationUcType @360 :List(DeducedTemplateSpecializationType);
  autoUcType @361 :List(AutoType);
  decltypeUcType @362 :List(DecltypeType);
  complexUcType @363 :List(ComplexType);
  builtinUcType @364 :List(BuiltinType);
  blockUcPointerUcType @365 :List(BlockPointerType);
  attributedUcType @366 :List(AttributedType);
  atomicUcType @367 :List(AtomicType);
  arrayUcType @368 :List(ArrayType);
  variableUcArrayUcType @369 :List(VariableArrayType);
  incompleteUcArrayUcType @370 :List(IncompleteArrayType);
  dependentUcSizedUcArrayUcType @371 :List(DependentSizedArrayType);
  constantUcArrayUcType @372 :List(ConstantArrayType);
  adjustedUcType @373 :List(AdjustedType);
  decayedUcType @374 :List(DecayedType);
  vectorUcType @375 :List(VectorType);
  extUcVectorUcType @376 :List(ExtVectorType);
  unresolvedUcUsingUcType @377 :List(UnresolvedUsingType);
  unaryUcTransformUcType @378 :List(UnaryTransformType);
  typedefUcType @379 :List(TypedefType);
  typeUcOfUcType @380 :List(TypeOfType);
  typeUcOfUcExprUcType @381 :List(TypeOfExprType);
}
