// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include <llvm/ADT/APSInt.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/raw_ostream.h>
#include <map>
#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Bootstrap.h"

#include "../Index/Entity.h"

#define IGNORE(name)
#define DECL_NAME(name) #name "Decl",
#define TYPE_NAME(name) #name "Type",
#define ATTR_NAME(name) #name "Attr",
#define MACRO_NAME(name) "Macro" #name,
#define MACRO_DIRECTIVE_NAME(name) #name "MacroDirective",
#define STR_NAME(name) #name,

// We want these things to exist inside of Multiplier, so we will add them
// here.
namespace pasta {

enum class TokenCategory : unsigned char {
  kUnknown,
  kIdentifier,
  kMacroName,
  kMacroParameterName,
  kMacroDirectiveName,
  kKeyword,
  kObjectiveCKeyword,
  kBuiltinTypeName,
  kPunctuation,
  kLiteral,
  kComment,

  // These line up with `DeclCategory`.
  kLocalVariable,
  kGlobalVariable,
  kParameterVariable,
  kFunction,
  kInstanceMethod,
  kInstanceMember,
  kClassMethod,
  kClassMember,
  kThis,
  kClass,
  kStruct,
  kUnion,
  kConcept,
  kInterface,
  kEnum,
  kEnumerator,
  kNamespace,
  kTypeAlias,
  kTemplateParameterType,
  kTemplateParameterValue,
  kLabel,

  // Extra.
  kWhitespace,
  kFileName,
  kLineNumber,
  kColumnNumber,
  kInformation,
  kWarning,
  kError,
};

}  // namespace pasta

// These are types with no corresponding enumeration for the respective `kind`
// methods.
static const std::unordered_set<std::string> gAbstractTypes{
  PASTA_FOR_EACH_DECL_IMPL(IGNORE, STR_NAME)
  PASTA_FOR_EACH_STMT_IMPL(IGNORE, IGNORE, IGNORE, IGNORE, IGNORE, STR_NAME)
  PASTA_FOR_EACH_TYPE_IMPL(IGNORE, STR_NAME)
  PASTA_FOR_EACH_ATTR_IMPL(IGNORE, STR_NAME)
  PASTA_FOR_EACH_MACRO_IMPL(IGNORE, IGNORE, IGNORE, IGNORE, IGNORE,
                            IGNORE, STR_NAME)
};

static const std::unordered_set<std::string> gUnserializableTypes{
  // These are not contained in fragments.
  "TranslationUnitDecl",
};

// These are replicated into fragments.
static const std::unordered_set<std::string> gSpecialDeclContexts{
  "NamespaceDecl",
  "ExternCContextDecl",
  "LinkageSpecDecl",
};

static const std::unordered_set<std::string> gFragmentEntityTypes{
#define FRAG_ENT_TYPE(type_name, lower_name) #type_name ,
  FOR_EACH_ENTITY_CATEGORY(FRAG_ENT_TYPE)
#undef FRAG_ENT_TYPE
};

static const std::unordered_set<std::string> gDeclNames{
  PASTA_FOR_EACH_DECL_IMPL(DECL_NAME, STR_NAME)
};

static const std::unordered_set<std::string> gStmtNames{
  PASTA_FOR_EACH_STMT_IMPL(STR_NAME, STR_NAME, STR_NAME, STR_NAME, STR_NAME, STR_NAME)
};

static const std::unordered_set<std::string> gTypeNames{
  PASTA_FOR_EACH_TYPE_IMPL(TYPE_NAME, STR_NAME)
};

static const std::unordered_set<std::string> gAttrNames{
  PASTA_FOR_EACH_ATTR_IMPL(ATTR_NAME, STR_NAME)
};

static const std::unordered_set<std::string> gMacroNames{
  PASTA_FOR_EACH_MACRO_IMPL(MACRO_NAME, IGNORE, MACRO_DIRECTIVE_NAME,
                            MACRO_DIRECTIVE_NAME, MACRO_DIRECTIVE_NAME,
                            MACRO_DIRECTIVE_NAME, STR_NAME)
};

static const std::unordered_set<std::string> gTemplateArgumentNames{
  "TemplateArgument"
};

static const std::unordered_set<std::string> gTemplateParameterListNames{
  "TemplateParameterList"
};

static const std::unordered_set<std::string> gCXXBaseSpecifierNames{
  "CXXBaseSpecifier"
};

static const std::unordered_set<std::string> gDesignatorNames{
  "Designator"
};

static const std::unordered_set<std::string> gCXXCtorInitializerNames{
  "CXXCtorInitializer"
};

static const std::unordered_set<std::string> gFileNames{
  "File"
};

static const std::unordered_set<std::string> gFragmentNames{
  "Fragment"
};

static const std::unordered_set<std::string> gTokenNames{
  "Token"
};

//#define NON_REF_TYPES \
//    "IncludePath", \
//    "Compiler", \
//    "CompileCommand", \
//    "CompileJob",

static const std::unordered_set<std::string> gNotReferenceTypesRelatedToEntities{

};

static const std::unordered_set<std::string> gNotReferenceTypes{

};

static const std::unordered_set<std::string> gFrontendTypes{
  "Compilation",
  "CompilerName",
  "IncludePathLocation",
  "TargetLanguage",
  "IncludePath",
  "ArgumentVector",
  "CompileCommand",
  "CompileJob",
  "Compiler",
  "Token",
  "TokenRange",
  "TokenTree",
  "MacroToken",
  "FileToken",
  "MacroKind",
  "TokenKind",
  "TokenRole",
  "TokenCategory",
  "PPKeywordKind",
  "ObjCKeywordKind",
  "File",
  "PathKind",
  "FileType",
  "Stat",
  PASTA_FOR_EACH_MACRO_IMPL(MACRO_NAME, IGNORE, MACRO_DIRECTIVE_NAME,
                            MACRO_DIRECTIVE_NAME, MACRO_DIRECTIVE_NAME,
                            MACRO_DIRECTIVE_NAME, STR_NAME)
};

static const std::unordered_set<std::string> kDeclContextTypes{
  "BlockDecl",
  "CXXConstructorDecl",
  "CXXConversionDecl",
  "CXXDeductionGuideDecl",
  "CXXDestructorDecl",
  "CXXMethodDecl",
  "CXXRecordDecl",
  "CapturedDecl",
  "ClassTemplatePartialSpecializationDecl",
  "ClassTemplateSpecializationDecl",
  "EnumDecl",
  "ExportDecl",
  "ExternCContextDecl",
  "FunctionDecl",
  "LinkageSpecDecl",
  "NamespaceDecl",
  "OMPDeclareMapperDecl",
  "OMPDeclareReductionDecl",
  "ObjCCategoryDecl",
  "ObjCCategoryImplDecl",
  "ObjCContainerDecl",
  "ObjCImplDecl",
  "ObjCImplementationDecl",
  "ObjCInterfaceDecl",
  "ObjCMethodDecl",
  "ObjCProtocolDecl",
  "RecordDecl",
  "RequiresExprBodyDecl",
  "TagDecl",
  "TranslationUnitDecl",
};

static const std::unordered_set<std::string> gConcreteClassNames{
  "Token",
  "TokenRange",
  "FileToken",
  "MacroToken",
  "MacroRange",
  FOR_EACH_PSEUDO_ENTITY_TYPE(STR_NAME)
  PASTA_FOR_EACH_DECL_IMPL(DECL_NAME, IGNORE)
  PASTA_FOR_EACH_STMT_IMPL(STR_NAME, STR_NAME, STR_NAME, STR_NAME, STR_NAME, IGNORE)
  PASTA_FOR_EACH_TYPE_IMPL(TYPE_NAME, IGNORE)
  PASTA_FOR_EACH_ATTR_IMPL(ATTR_NAME, IGNORE)
  PASTA_FOR_EACH_MACRO_IMPL(MACRO_NAME, IGNORE, MACRO_DIRECTIVE_NAME,
                            MACRO_DIRECTIVE_NAME, MACRO_DIRECTIVE_NAME,
                            MACRO_DIRECTIVE_NAME, IGNORE)
};

static const std::unordered_set<std::string> gEntityClassNames{
  "Token",
  "FileToken",
  "MacroToken",
  "File",
  FOR_EACH_PSEUDO_ENTITY_TYPE(STR_NAME)
  PASTA_FOR_EACH_DECL_IMPL(DECL_NAME, STR_NAME)
  PASTA_FOR_EACH_STMT_IMPL(STR_NAME, STR_NAME, STR_NAME, STR_NAME, STR_NAME, STR_NAME)
  PASTA_FOR_EACH_TYPE_IMPL(TYPE_NAME, STR_NAME)
  PASTA_FOR_EACH_ATTR_IMPL(ATTR_NAME, STR_NAME)
  PASTA_FOR_EACH_MACRO_IMPL(MACRO_NAME, IGNORE, MACRO_DIRECTIVE_NAME,
                            MACRO_DIRECTIVE_NAME, MACRO_DIRECTIVE_NAME,
                            MACRO_DIRECTIVE_NAME, STR_NAME)
};

// These methods can trigger asserts deep in their internals that are hard
// to design around in PASTA. The auto-generated serialization code tries to
// call most methods, and we don't want to call a method that will crash the
// process with an assertion failure. So we just blacklist those methods here.
//
// Sometimes, those methods can be handled because their assertions are
// "shallow" and appear in the method body itself (and not inside of an
// internally called method), and in those cases, we can often modify PASTA
// itself (`pasta/bin/BootstrapTypes/Globals.cpp`, `kConditionalNullptr`)
// to check the conditions that would be asserted, and if those conditions
// aren't satisfied, then return `std::nullopt`.
static std::set<std::pair<std::string, std::string>> kMethodBlackList{
  {"Expr", "ClassifyLValue"},  // Calls `clang::Expr::ClassifyImpl`.
  {"Expr", "IsBoundMemberFunction"},  // Calls `clang::Expr::ClassifyImpl`.
  {"Expr", "IsModifiableLvalue"},  // Calls `clang::Expr::ClassifyImpl`.

  // Internally can call all sorts of stuff, e.g. `InitListExpr::isTransparent`.
  {"Expr", "IsCXX11ConstantExpression"},
  {"Expr", "EvaluateAsRValue"},
  {"Expr", "IsEvaluatable"},
  {"Expr", "AsBuiltinConstantDeclarationReference"},

  // These are methods that we just don't want, e.g. they don't provide
  // relevant info.
  {"Decl", "GlobalID"},  // Related to loading from an AST file.
  {"Decl", "ID"},  // Related to the ASTContext allocation.
  {"Decl", "IsFromASTFile"},
  {"Decl", "HasBody"},
  {"Decl", "AsFunction"},
  {"Decl", "FunctionType"},
  {"Decl", "TranslationUnitDeclaration"},
  {"Decl", "NextDeclarationInContext"},
  {"Decl", "HasDefiningAttribute"},  // Already have `Decl::DefiningAttribute`.

  {"Decl", "Redeclarations"},  // Implement it ourselves.
  {"Decl", "MostRecentDeclaration"},
  {"NamedDecl", "MostRecentDeclaration"},
  {"VarTemplateDecl", "MostRecentDeclaration"},
  {"CXXMethodDecl", "MostRecentDeclaration"},
  {"ClassTemplateDecl", "MostRecentDeclaration"},
  {"EnumDecl", "MostRecentDeclaration"},
  {"FunctionTemplateDecl", "MostRecentDeclaration"},
  {"CXXRecordDecl", "MostRecentDeclaration"},
  {"RecordDecl", "MostRecentDeclaration"},
  {"Decl", "PreviousDeclaration"},
  {"TypeAliasTemplateDecl", "PreviousDeclaration"},
  {"VarTemplateDecl", "PreviousDeclaration"},
  {"ClassTemplateDecl", "PreviousDeclaration"},
  {"FunctionTemplateDecl", "PreviousDeclaration"},
  {"CXXRecordDecl", "PreviousDeclaration"},
  {"EnumDecl", "PreviousDeclaration"},
  {"RecordDecl", "PreviousDeclaration"},
  {"RecordDecl", "FirstNamedDataMember"},

  // We hoist forward declarations embedded in declarators out into their own
  // freestanding fragments that aren't associated with files, and so the return
  // value of this method loses its meaning in those cases.
  {"TagDecl", "IsEmbeddedInDeclarator"},

  // These are redundant.
  {"FunctionDecl", "ParameterDeclarations"},

  // These can crash?
  {"Expr", "BestDynamicClassType"},
  {"Expr", "IsCXX98IntegralConstantExpression"},

  // These are odd.
  {"CXXRecordDecl", "IsParsingBaseSpecifiers"},

  // These have assertions related to FIXME comments, and so we don't want them.
  {"CXXRecordDecl", "MostRecentNonInjectedDeclaration"},

  // We want to make sure we get the most derived spelling.
  {"Attr", "Spelling"},
  {"Attr", "SpellingListIndex"},
  {"InheritableAttr", "Spelling"},
  {"InheritableParamAttr", "Spelling"},

  // These are problematic for indexing, where our model is to deduplicate
  // inherted attributes, and also treat attributes as being specific to
  // fragments, and thus not observable across fragments.
  {"CallExpr", "UnusedResultAttribute"},

  // These have complicated assertions in them.
  {"CXXRecordDecl", "DefaultedCopyConstructorIsDeleted"},
  {"CXXRecordDecl", "DefaultedDefaultConstructorIsConstexpr"},
  {"CXXRecordDecl", "DefaultedDestructorIsConstexpr"},
  {"CXXRecordDecl", "DefaultedDestructorIsDeleted"},
  {"CXXRecordDecl", "DefaultedMoveConstructorIsDeleted"},
  {"Type", "ObjCSubstitutions"},

  // These are redundant.
  {"FunctionProtoType", "Exceptions"},

  // The indexer, in `Persist.cpp`, doesn't maintain a less-equal relationship
  // between `BeginToken` and `EndToken` for macros. In PASTA, `BeginToken`
  // and `EndToken` point to the usage tokens, but in our indexer, we focus on
  // ordering the expansion tokens.
  {"Macro", "BeginToken"},
  {"Macro", "EndToken"},
  {"MacroDirective", "ParsedLocation"},

  // We'll manually record these in the indexer.
  {"DefineMacroDirective", "Uses"},

  // Our indexer tries to merge expansions are argument pre-expansions via
  // the TokenTree.
  {"MacroExpansion", "IsArgumentPreExpansion"},
  {"MacroExpansion", "ArgumentPreExpansion"},

  // TODO(pag): We'll eventually have to re-introduce these manually.
  {"ClassTemplateDecl", "Specializations"},
  {"VarTemplateDecl", "Specializations"},
  {"FunctionTemplateDecl", "Specializations"},

  // We just don't want these. We want types to be subtractive, not additive.
  // When we have these, it pollutes our database with all sorts of stuff that
  // isn't necessarily in the code.
  //
  // NOTE(pag): `AtomicUnqualifiedType` is special.
  {"QualifiedType", "IgnoreParentheses"},
  {"QualifiedType", "LocalUnqualifiedType"},
  {"QualifiedType", "NonLValueExpressionType"},
  {"QualifiedType", "NonPackExpansionType"},
  {"QualifiedType", "NonPackExpansionType"},
  {"QualifiedType", "NonReferenceType"},
  {"QualifiedType", "SingleStepDesugaredType"},
  {"QualifiedType", "HasLocalNonFastQualifiers"},
  {"QualifiedType", "HasLocalQualifiers"},
  {"QualifiedType", "StripObjCKindOfType"},
  {"QualifiedType", "WithConst"},
  {"QualifiedType", "WithRestrict"},
  {"QualifiedType", "WithVolatile"},
  {"QualifiedType", "WithoutLocalFastQualifiers"},

  // End up being a bit spammy in serialization, and we support `::from`.
  {"Type", "ArrayElementTypeNoTypeQualified"},
  {"Type", "AsCXXRecordDeclaration"},
  {"Type", "AsComplexIntegerType"},
  {"Type", "AsObjCInterfacePointerType"},
  {"Type", "AsObjCInterfaceType"},
  {"Type", "AsObjCQualifiedClassType"},
  {"Type", "AsObjCQualifiedIdType"},
  {"Type", "AsObjCQualifiedInterfaceType"},
  {"Type", "AsPlaceholderType"},
  {"Type", "AsRecordDeclaration"},
  {"Type", "AsStructureType"},
  {"Type", "AsTagDeclaration"},
  {"Type", "AsUnionType"},
  {"Type", "LocallyUnqualifiedSingleStepDesugaredType"},
  {"Type", "PointeeType"},  // NOTE(pag): Has special handling below.
  {"Type", "ArrayElementTypeNoTypeQualified"},
  {"Type", "AsCXXRecordDeclaration"},
  {"Type", "AsComplexIntegerType"},
  {"Type", "AsObjCInterfacePointerType"},
  {"Type", "AsObjCInterfaceType"},
  {"Type", "AsObjCQualifiedClassType"},
  {"Type", "AsObjCQualifiedIdType"},
  {"Type", "AsObjCQualifiedInterfaceType"},
  {"Type", "AsPlaceholderType"},
  {"Type", "AsRecordDeclaration"},
  {"Type", "AsStructureType"},
  {"Type", "AsTagDeclaration"},
  {"Type", "AsUnionType"},
  {"Type", "ContainedAutoType"},
  {"Type", "ContainedDeducedType"},
  {"Type", "Nullability"},
  {"Type", "PointeeCXXRecordDeclaration"},
  {"Type", "PointeeOrArrayElementType"},
  {"Type", "RVVElementType"},
  {"Type", "ScalarTypeKind"},
  {"Type", "SveElementType"},
  {"Type", "RVVElementType"},
  {"Type", "CanonicalTypeInternal"},
  {"Type", "LocallyUnqualifiedSingleStepDesugaredType"},
  {"Type", "IsAggregateType"},
  {"Type", "HasAutoForTrailingReturnType"},
  {"Type", "HasFloatingRepresentation"},
  {"Type", "HasIntegerRepresentation"},
  {"Type", "HasObjCPointerRepresentation"},
  {"Type", "HasPointerRepresentation"},
  {"Type", "HasSignedIntegerRepresentation"},
  {"Type", "HasSizedVLAType"},
  {"Type", "HasUnnamedOrLocalType"},
  {"Type", "HasUnsignedIntegerRepresentation"},
  {"Type", "IsAlignValueT"},
  {"Type", "IsAnyCharacterType"},
  {"Type", "IsAnyComplexType"},
  {"Type", "IsAnyPointerType"},
  {"Type", "IsArithmeticType"},
  {"Type", "IsArrayType"},
  {"Type", "IsAtomicType"},
  {"Type", "IsBFloat16Type"},
  {"Type", "IsBitIntType"},
  {"Type", "IsBlockCompatibleObjCPointerType"},
  {"Type", "IsBlockPointerType"},
  {"Type", "IsBooleanType"},
  {"Type", "IsBuiltinType"},
  {"Type", "IsCARCBridgableType"},
  {"Type", "IsCUDADeviceBuiltinSurfaceType"},
  {"Type", "IsCUDADeviceBuiltinTextureType"},
  {"Type", "IsCanonicalUnqualified"},
  {"Type", "IsChar16Type"},
  {"Type", "IsChar32Type"},
  {"Type", "IsChar8Type"},
  {"Type", "IsCharacterType"},
  {"Type", "IsClassType"},
  {"Type", "IsClkEventT"},
  {"Type", "IsComplexIntegerType"},
  {"Type", "IsComplexType"},
  {"Type", "IsCompoundType"},
  {"Type", "IsConstantArrayType"},
  {"Type", "IsConstantMatrixType"},
  {"Type", "IsConstantSizeType"},
  {"Type", "IsDecltypeType"},
  {"Type", "IsDependentAddressSpaceType"},
  {"Type", "IsDependentSizedArrayType"},
  {"Type", "IsDependentType"},
  {"Type", "IsElaboratedTypeSpecifier"},
  {"Type", "IsEnumeralType"},
  {"Type", "IsEventT"},
  {"Type", "IsExtVectorBooleanType"},
  {"Type", "IsExtVectorType"},
  {"Type", "IsFixedPointOrIntegerType"},
  {"Type", "IsFixedPointType"},
  {"Type", "IsFloat128Type"},
  {"Type", "IsFloat16Type"},
  {"Type", "IsFloatingType"},
  {"Type", "IsFromAST"},
  {"Type", "IsFunctionNoProtoType"},
  {"Type", "IsFunctionPointerType"},
  {"Type", "IsFunctionProtoType"},
  {"Type", "IsFunctionReferenceType"},
  {"Type", "IsFunctionType"},
  {"Type", "IsFundamentalType"},
  {"Type", "IsHalfType"},
  {"Type", "IsIbm128Type"},
  {"Type", "IsImageType"},
  {"Type", "IsIncompleteArrayType"},
  {"Type", "IsIncompleteOrObjectType"},
  {"Type", "IsIncompleteType"},
  {"Type", "IsInstantiationDependentType"},
  {"Type", "IsIntegerType"},
  {"Type", "IsIntegralOrEnumerationType"},
  {"Type", "IsIntegralOrUnscopedEnumerationType"},
  {"Type", "IsIntegralType"},
  {"Type", "IsInterfaceType"},
  {"Type", "IsLValueReferenceType"},
  {"Type", "IsLinkageValid"},
  {"Type", "IsLiteralType"},
  {"Type", "IsMatrixType"},
  {"Type", "IsMemberDataPointerType"},
  {"Type", "IsMemberFunctionPointerType"},
  {"Type", "IsMemberPointerType"},
  {"Type", "IsNonOverloadPlaceholderType"},
  {"Type", "IsNothrowT"},
  {"Type", "IsNullPointerType"},
  {"Type", "IsOCLExtOpaqueType"},
  {"Type", "IsOCLImage1dArrayROType"},
  {"Type", "IsOCLImage1dArrayRWType"},
  {"Type", "IsOCLImage1dArrayWOType"},
  {"Type", "IsOCLImage1dBufferROType"},
  {"Type", "IsOCLImage1dBufferRWType"},
  {"Type", "IsOCLImage1dBufferWOType"},
  {"Type", "IsOCLImage1dROType"},
  {"Type", "IsOCLImage1dRWType"},
  {"Type", "IsOCLImage1dWOType"},
  {"Type", "IsOCLImage2dArrayDepthROType"},
  {"Type", "IsOCLImage2dArrayDepthRWType"},
  {"Type", "IsOCLImage2dArrayDepthWOType"},
  {"Type", "IsOCLImage2dArrayMSAADepthROType"},
  {"Type", "IsOCLImage2dArrayMSAADepthRWType"},
  {"Type", "IsOCLImage2dArrayMSAADepthWOType"},
  {"Type", "IsOCLImage2dArrayMSAAROType"},
  {"Type", "IsOCLImage2dArrayMSAARWType"},
  {"Type", "IsOCLImage2dArrayMSAAWOType"},
  {"Type", "IsOCLImage2dArrayROType"},
  {"Type", "IsOCLImage2dArrayRWType"},
  {"Type", "IsOCLImage2dArrayWOType"},
  {"Type", "IsOCLImage2dDepthROType"},
  {"Type", "IsOCLImage2dDepthRWType"},
  {"Type", "IsOCLImage2dDepthWOType"},
  {"Type", "IsOCLImage2dMSAADepthROType"},
  {"Type", "IsOCLImage2dMSAADepthRWType"},
  {"Type", "IsOCLImage2dMSAADepthWOType"},
  {"Type", "IsOCLImage2dMSAAROType"},
  {"Type", "IsOCLImage2dMSAARWType"},
  {"Type", "IsOCLImage2dMSAAWOType"},
  {"Type", "IsOCLImage2dROType"},
  {"Type", "IsOCLImage2dRWType"},
  {"Type", "IsOCLImage2dWOType"},
  {"Type", "IsOCLImage3dROType"},
  {"Type", "IsOCLImage3dRWType"},
  {"Type", "IsOCLImage3dWOType"},
  {"Type", "IsOCLIntelSubgroupAVCImeDualReferenceStreaminType"},
  {"Type", "IsOCLIntelSubgroupAVCImePayloadType"},
  {"Type", "IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType"},
  {"Type", "IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType"},
  {"Type", "IsOCLIntelSubgroupAVCImeResultType"},
  {"Type", "IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType"},
  {"Type", "IsOCLIntelSubgroupAVCMcePayloadType"},
  {"Type", "IsOCLIntelSubgroupAVCMceResultType"},
  {"Type", "IsOCLIntelSubgroupAVCRefPayloadType"},
  {"Type", "IsOCLIntelSubgroupAVCRefResultType"},
  {"Type", "IsOCLIntelSubgroupAVCSicPayloadType"},
  {"Type", "IsOCLIntelSubgroupAVCSicResultType"},
  {"Type", "IsOCLIntelSubgroupAVCType"},
  {"Type", "IsObjCARCBridgableType"},
  {"Type", "IsObjCARCImplicitlyUnretainedType"},
  {"Type", "IsObjCBoxableRecordType"},
  {"Type", "IsObjCBuiltinType"},
  {"Type", "IsObjCClassOrClassKindOfType"},
  {"Type", "IsObjCClassType"},
  {"Type", "IsObjCIdType"},
  {"Type", "IsObjCIndependentClassType"},
  {"Type", "IsObjCIndirectLifetimeType"},
  {"Type", "IsObjCInertUnsafeUnretainedType"},
  {"Type", "IsObjCLifetimeType"},
  {"Type", "IsObjCNSObjectType"},
  {"Type", "IsObjCObjectOrInterfaceType"},
  {"Type", "IsObjCObjectPointerType"},
  {"Type", "IsObjCObjectType"},
  {"Type", "IsObjCQualifiedClassType"},
  {"Type", "IsObjCQualifiedIdType"},
  {"Type", "IsObjCQualifiedInterfaceType"},
  {"Type", "IsObjCRetainableType"},
  {"Type", "IsObjCSelType"},
  {"Type", "IsObjectPointerType"},
  {"Type", "IsObjectType"},
  {"Type", "IsOpenCLSpecificType"},
  {"Type", "IsOverloadableType"},
  {"Type", "IsPipeType"},
  {"Type", "IsPlaceholderType"},
  {"Type", "IsPointerType"},
  {"Type", "IsQueueT"},
  {"Type", "IsRVVSizelessBuiltinType"},
  {"Type", "IsRVVVLSBuiltinType"},
  {"Type", "IsRValueReferenceType"},
  {"Type", "IsRealFloatingType"},
  {"Type", "IsRealType"},
  {"Type", "IsRecordType"},
  {"Type", "IsReferenceType"},
  {"Type", "IsReserveIDT"},
  {"Type", "IsSVESizelessBuiltinType"},
  {"Type", "IsSamplerT"},
  {"Type", "IsSaturatedFixedPointType"},
  {"Type", "IsScalarType"},
  {"Type", "IsScopedEnumeralType"},
  {"Type", "IsSignedFixedPointType"},
  {"Type", "IsSignedIntegerOrEnumerationType"},
  {"Type", "IsSignedIntegerType"},
  {"Type", "IsSizelessBuiltinType"},
  {"Type", "IsSizelessType"},
  {"Type", "IsSpecifierType"},
  {"Type", "IsStandardLayoutType"},
  {"Type", "IsStdByteType"},
  {"Type", "IsStructuralType"},
  {"Type", "IsStructureOrClassType"},
  {"Type", "IsStructureType"},
  {"Type", "IsSveVLSBuiltinType"},
  {"Type", "IsTemplateTypeParmType"},
  {"Type", "IsTypedefNameType"},
  {"Type", "IsUndeducedAutoType"},
  {"Type", "IsUndeducedType"},
  {"Type", "IsUnionType"},
  {"Type", "IsUnsaturatedFixedPointType"},
  {"Type", "IsUnscopedEnumerationType"},
  {"Type", "IsUnsignedFixedPointType"},
  {"Type", "IsUnsignedIntegerOrEnumerationType"},
  {"Type", "IsUnsignedIntegerType"},
  {"Type", "IsVariableArrayType"},
  {"Type", "IsVariablyModifiedType"},
  {"Type", "IsVectorType"},
  {"Type", "IsVisibilityExplicit"},
  {"Type", "IsVoidPointerType"},
  {"Type", "IsVoidType"},
  {"Type", "IsWebAssemblyExternrefType"},
  {"Type", "IsWebAssemblyTableType"},
  {"Type", "IsWideCharacterType"},
  {"Type", "CanonicalTypeInternal"},
  {"Type", "ContainedAutoType"},
  {"Type", "ContainedDeducedType"},
  {"Type", "Desugar"},  // Already have `Type::DesugaredType`.

  // The bit packing in here are not well described, so we should just omit
  // them.
  {"QualifiedType", "CVRQualifiers"},
  {"QualifiedType", "LocalCVRQualifiers"},
  {"QualifiedType", "LocalFastQualifiers"},

  // These have bad time complexity.
  {"Decl", "AlignedSubstitutions"},
  {"Stmt", "AlignedSubstitutions"},

  // These don't make sense because their results are specific to a translation
  // unit.
  {"Decl", "IsThisDeclarationReferenced"},
  {"Decl", "IsUsed"},
  {"Decl", "IsReferenced"},
  {"Decl", "IsReachable"},
  {"Decl", "IsInvalidDeclaration"},
  {"Decl", "IsCanonicalDeclaration"},
  {"Decl", "IsFirstDeclaration"},
  {"Decl", "IdentifierNamespace"},

  {"MemberPointerType", "MostRecentCXXRecordDeclaration"},
  {"Expr", "Dependence"},
  {"Expr", "IsIntegerConstantExpression"},
  {"VarDecl", "HasICEInitializer"},
  {"UnresolvedMemberExpr", "Base"}, // asserts because of isImplicitAccess() is true
  {"CXXDefaultArgExpr", "AdjustedRewrittenExpression"},
  {"CXXNewExpr", "ShouldNullCheckAllocation"},
  {"RequiresExpr", "IsSatisfied"},
  {"ConceptSpecializationExpr", "IsSatisfied"},
  {"Decl", "Access"},
  {"Expr","IsKnownToHaveBooleanValue"},

  {"NamespaceDecl","AlreadyLoadedDeclarations"},
  {"LinkageSpecDecl","AlreadyLoadedDeclarations"},
  {"ExternCContextDecl","AlreadyLoadedDeclarations"},

  {"EnumDecl", "ODRHash"},
  {"CXXRecordDecl", "ODRHash"},
  {"FunctionDecl", "ODRHash"},
  {"CXXRecordDecl", "VisibleConversionFunctions"},
  {"FunctionDecl", "WillHaveBody"},

  // These will apply to functions, enums, classes, etc.
  {"Decl", "TypeAsWritten"},
  {"Decl", "PointOfInstantiation"},
  {"Decl", "TemplateSpecialization"},
  {"Decl", "TemplateSpecializationKind"},
  {"Decl", "TemplateSpecializationKindForInstantiation"},
  {"Decl", "TemplateInstantiationPattern"},
  {"Decl", "TemplateSpecializationKindForInstantiation"},
  {"Decl", "TemplateInstantiationArguments"},
  {"Decl", "InstantiatedFrom"},
  {"Decl", "InstantiatedFromMember"},
  {"Decl", "InstantiatedFromMemberTemplate"},
  {"Decl", "PrimaryTemplate"},
  {"EnumDecl", "InstantiatedFromMemberEnum"},
  {"UsingPackDecl", "InstantiatedFromUsingDeclaration"},
  {"FunctionDecl", "InstantiatedFromDeclaration"},
  {"FunctionDecl", "InstantiatedFromMemberFunction"},
  {"FunctionDecl", "IsThisDeclarationInstantiatedFromAFriendDefinition"},
  {"VarDecl", "InstantiatedFromStaticDataMember"},

  // Add stuff here to avoid waiting for PASTA bootstrap, and also add it into
  // PASTA's nullptr checking stuff.
};

static const char *SchemaIntType(pasta::Type type) {
  auto t = type;
  if (auto bt = pasta::BuiltinType::From(type.UnqualifiedType())) {
    switch (bt->BuiltinKind()) {
      case pasta::BuiltinTypeKind::kBoolean: return "Bool";
      case pasta::BuiltinTypeKind::kCharacterS: return "Int8";  // `char`.
      case pasta::BuiltinTypeKind::kCharacterU: return "UInt8";  // `char`.
      case pasta::BuiltinTypeKind::kSChar: return "Int8";  // `signed char`.
      case pasta::BuiltinTypeKind::kUChar: return "UInt8";  // `unsigned char`.
      case pasta::BuiltinTypeKind::kShort: return "Int16";
      case pasta::BuiltinTypeKind::kUShort: return "UInt16";
      case pasta::BuiltinTypeKind::kInt: return "Int32";
      case pasta::BuiltinTypeKind::kUInt: return "UInt32";
      case pasta::BuiltinTypeKind::kLong: return "Int64";
      case pasta::BuiltinTypeKind::kULong: return "UInt64";
      case pasta::BuiltinTypeKind::kLongLong: return "Int64";
      case pasta::BuiltinTypeKind::kULongLong: return "UInt64";
      default: break;
    }
  }
  return nullptr;
}

static std::string NameAndHash(std::string name) {
  std::hash<std::string> hasher;
  std::stringstream ss;
  uint64_t hash_val = hasher(name);
  if (static_cast<int64_t>(hash_val) > 0) {
    hash_val = ~hash_val;
  }
  ss << name << " @0x" << std::hex << hash_val;
  return ss.str();
}

using MethodList = std::unordered_set<std::string>;
using MethodListPtr = std::shared_ptr<MethodList>;

class CodeGenerator {
 private:
  std::filesystem::path lib_dir; // `lib/`
  std::filesystem::path include_dir; // `include/multiplier`

  std::vector<ClassHierarchy *> roots;

  std::unordered_set<std::string> enum_names;
  std::set<std::string> forward_decls;
  std::set<std::string> derived_decls;
  std::set<std::string> needed_decls;
  bool needs_reference{false};

  std::ofstream schema_os;  // `lib/Common/AST.capnp`
  std::stringstream lib_cpp_os;  // Implementation file for each entity.
  std::ofstream ast_h_os;  // `include/multiplier/AST.h`
  std::ofstream frontend_h_os;  // `include/multiplier/Frontend.h`
  std::ofstream serialize_h_os;  // `bin/Index/Serialize.h`
  std::ofstream serialize_cpp_os;  // `bin/Index/Serialize.cpp`
  std::ofstream serialize_inc_os;  // `include/multiplier/Visitor.inc.h`
  std::ofstream lib_pasta_cpp_os;  // `bin/Index/PASTA.cpp`
  std::ofstream lib_pasta_h_os;  // `bin/Index/PASTA.h`
  std::stringstream late_serialize_inc_os;

  std::vector<pasta::NamespaceDecl> pastas;

  std::vector<pasta::EnumDecl> enums;

#define DECLARE_ENTITY_LIST(name, lower_name) \
    std::vector<pasta::CXXRecordDecl> lower_name ## s;

  FOR_EACH_ENTITY_CATEGORY(DECLARE_ENTITY_LIST)
#undef DECLARE_ENTITY_LIST

  // We extend `TokenKind` with these.
  std::optional<pasta::EnumDecl> pp_keyword_kinds;
  std::optional<pasta::EnumDecl> objc_at_keywords;

  std::unordered_map<std::string, std::pair<const char *, const char *>>
      enum_type;

  std::stringstream header_enum_ss;

  bool RunOnEnum(pasta::EnumDecl enum_decl);

#define DECLARE_STORAGE(name, lower_name) \
    AnyEntityStorage root_ ## lower_name ## _storage;

  FOR_EACH_ENTITY_CATEGORY(DECLARE_STORAGE)
#undef DECLARE_STORAGE

  std::unordered_map<ClassHierarchy *, SpecificEntityStorage> specific_storage;

  MethodListPtr RunOnClass(ClassHierarchy *, MethodListPtr parent_methods);
  void RunOnClassHierarchies(void);
  void RunOnClasses(void);
  int RunOnNamespaces(void);

  void RunOnOptional(
      std::ostream &os, ClassHierarchy *cls, SpecificEntityStorage &storage,
      const std::optional<pasta::RecordDecl> &record,
      const std::string &class_name, const std::string &api_name,
      const std::string &method_name, const std::string &nth_entity_reader,
      const std::string &base_name, const MethodListPtr &seen_methods);

  void RunOnVector(
      std::ostream &os, SpecificEntityStorage &storage,
      const std::optional<pasta::RecordDecl> &record,
      const std::string &class_name, const std::string &api_name,
      const std::string &method_name, const std::string &nth_entity_reader,
      bool optional, const std::string &base_name,
      const MethodListPtr &seen_methods);

 public:
  CodeGenerator(char *argv[]);
  int RunOnTranslationUnit(pasta::TranslationUnitDecl tu);
};

bool CodeGenerator::RunOnEnum(pasta::EnumDecl enum_decl) {
  std::string enum_name = enum_decl.Name();

  // NOTE(pag): We fold these into `TokenKind`.
  if (enum_name == "TokenRole" || enum_name == "ObjCKeywordKind" ||
      enum_name == "PPKeywordKind") {
    return false;
  }

  auto is_frontend_type = gFrontendTypes.find(enum_name) != gFrontendTypes.end();
  auto dir_name = is_frontend_type ? "Frontend" : "AST";

  std::ofstream os(include_dir / dir_name / (enum_name + ".h"), std::ios::trunc | std::ios::out);
  os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "#include \"../Compiler.h\"\n\n"
      << "#include <cstdint>\n\n"
      << "namespace mx {\n";

  if (is_frontend_type) {
    frontend_h_os << "#include \"" << dir_name << '/' << enum_name << ".h\"\n";
  } else {
    ast_h_os << "#include \"" << dir_name << '/' << enum_name << ".h\"\n";
  }

  auto enumerators = enum_decl.Enumerators();
  auto num_enumerators = enumerators.size();
  auto enum_underlying_type = enum_decl.IntegerType();
  auto itype = CxxIntType(enum_underlying_type);

  auto &types = enum_type[enum_name];

  // Try to find the smallest type to rerpesent this enum.
  if (static_cast<uint8_t>(num_enumerators) == num_enumerators) {
    types.first = "unsigned char";
    types.second = "UInt8";
  } else {
    types.first = "unsigned short";
    types.second = "UInt16";
  }

  os << "enum class " << enum_name << " : " << types.first << " {\n";
  serialize_inc_os << "MX_BEGIN_ENUM_CLASS(" << enum_name << ", " << types.first << ")\n";

  // Generate a `switch` to convert from PASTA, as PASTA's version of enums
  // have the same initializer values as Clang does, but in Multiplier, we use
  // default initializers (starting from 0 to `num_enumerators`), and so we need
  // a `switch` to do the mapping.
  lib_pasta_cpp_os
      << enum_name << " FromPasta(pasta::" << enum_name << " e) {\n"
      << "  switch (static_cast<";
  if (!strcmp(itype, "bool")) {
    lib_pasta_cpp_os << "int";  // Avoid switching on `bool` types.
  } else {
    lib_pasta_cpp_os << itype;
  }
  lib_pasta_cpp_os << ">(e)) {\n";

  std::unordered_set<std::string> seen_initializers;
  std::string initializer;
  llvm::raw_string_ostream initializer_ss(initializer);
  std::stringstream name_cases_ss;

  auto i = 0u;
  for (pasta::EnumConstantDecl val : enumerators) {
    initializer.clear();

    std::string val_name = val.Name();
    std::string orig_val_name = val_name;

    // Don't allow repeats of the underlying values.
    llvm::APSInt ap_val = val.InitializerValue();
    ap_val.print(initializer_ss, ap_val.isSigned());
    initializer_ss.flush();
    if (!seen_initializers.emplace(initializer).second) {
      os << "  // Skipped repeat pasta::" << orig_val_name << "\n";
      continue;
    }

    // Some of these are numbers.
    if (enum_name == "SYCLMajorVersion") {
      val_name = "kVersion" + val_name.substr(1);
    }

    std::string_view val_name_view = val_name;

    if (val_name_view[0] == 'k') {
      val_name_view = val_name_view.substr(1);
    }

    auto snake_name = CapitalCaseToSnakeCase(val_name_view);
    auto enum_case = SnakeCaseToEnumCase(snake_name);

    // Take over `kRawIdentifier`, and change it to `kWhitespace`, so that
    // we can use `kUnknown` for errors and such.
    if (val_name == "kRawIdentifier" && enum_name == "TokenKind") {
      snake_name = "whitespace";
      enum_case = "WHITESPACE";

      lib_pasta_cpp_os
          << "    case " << initializer << ": return TokenKind::IDENTIFIER;\n";

    // We represent a `pasta::MacroToken` as an `mx::Token`.
    } else if (val_name == "kToken" && enum_name == "MacroKind") {
      continue;

    } else {
      lib_pasta_cpp_os
          << "    case " << initializer << ": return "
          << enum_name << "::" << enum_case << ";\n";
    }

    os << "  " << enum_case << ",\n";

    name_cases_ss
        << "    case " << enum_name << "::" << enum_case << ": return \""
        << enum_case << "\";\n";

    serialize_inc_os
        << "  MX_ENUM_CLASS_ENTRY(" << enum_name << ", "
        << enum_case << ", " << types.first << ")\n";
    ++i;
  }

  // We'll embed `PPKeywordKind` and `ObjCKeywordKind` at the end of
  // `TokenKind`. We merge this info into `TokenKind` so that we can
  // unify `FileToken` and `Token` without loss of information.
  if (enum_name == "TokenKind") {
    assert(pp_keyword_kinds.has_value());
    assert(objc_at_keywords.has_value());
    auto j = 0u;
    for (pasta::EnumConstantDecl val : pp_keyword_kinds->Enumerators()) {
      if (!j++) {
        continue;  // Skip `PPKeywordKind::kNotKeyword`.
      }

      auto val_name = val.Name();
      assert(val_name[0] == 'k');
      val_name = "Pp" + val_name.substr(1);

      auto snake_name = CapitalCaseToSnakeCase(val_name);
      auto enum_case = SnakeCaseToEnumCase(snake_name);

      os << "  " << enum_case << ",\n";

      name_cases_ss
          << "    case " << enum_name << "::" << enum_case << ": return \""
          << enum_case << "\";\n";

      serialize_inc_os
          << "  MX_ENUM_CLASS_ENTRY(" << enum_name << ", " << enum_case
          << ", " << types.first << ")\n";
      ++i;
    }

    j = 0u;
    for (pasta::EnumConstantDecl val : objc_at_keywords->Enumerators()) {
      if (!j++) {
        continue;  // Skip `ObjCKeywordKind::kNotKeyword`.
      }

      auto val_name = val.Name();
      assert(val_name[0] == 'k');
      val_name = "ObjcAt" + val_name.substr(1);

      auto snake_name = CapitalCaseToSnakeCase(val_name);
      auto enum_case = SnakeCaseToEnumCase(snake_name);

      os << "  " << enum_case << ",\n";

      name_cases_ss
          << "    case " << enum_name << "::" << enum_case << ": return \""
          << enum_case << "\";\n";

      serialize_inc_os
          << "  MX_ENUM_CLASS_ENTRY(" << enum_name << ", " << enum_case << ", "
          << types.first << ")\n";
      ++i;
    }
  }

  lib_pasta_cpp_os
      << "    default: __builtin_unreachable();\n"
      << "  }\n"  // End of `switch`.
      << "}\n\n";  // End of `FromPasta`

  lib_cpp_os
      << "const char *EnumeratorName(" << enum_name << " e) {\n"
      << "  switch (e) {\n"
      << name_cases_ss.str()
      << "    default: return \"<invalid>\";\n"
      << "  }\n"  // End of `switch`.
      << "}\n\n";  // End of `EnumeratorName`

  lib_pasta_h_os
      << "enum class " << enum_name << " : " << types.first << ";\n"
      << enum_name << " FromPasta(pasta::" << enum_name << " pasta_val);\n\n";

  os
      << "};\n\n"
      << "inline static const char *EnumerationName(" << enum_name << ") {\n"
      << "  return \"" << enum_name << "\";\n"
      << "}\n\n"
      << "inline static constexpr unsigned NumEnumerators(" << enum_name
      << ") {\n"
      << "  return " << i << ";\n"
      << "}\n\n"
      << "MX_EXPORT const char *EnumeratorName(" << enum_name << ");\n\n"
      << "} // namespace mx\n";

  serialize_inc_os << "MX_END_ENUM_CLASS(" << enum_name << ")\n\n";

  enum_names.insert(std::move(enum_name));
  return true;
}

static std::optional<std::string> GetFirstTemplateParameterType(
    const std::optional<pasta::RecordDecl> &record) {
  if (record) {
    if (auto cspec = pasta::ClassTemplateSpecializationDecl::From(*record)) {
      for (pasta::TemplateArgument arg : cspec->TemplateArguments()) {
        if (auto arg_type = arg.AsType()) {
          if (auto arg_record = arg_type->AsTagDeclaration()) {
            return arg_record->Name();
          } else if (auto itype = CxxIntType(*arg_type)) {
            return std::string(itype);
          }
        }
      }
    }
  }
  return std::nullopt;
}

static std::optional<pasta::RecordDecl> GetTemplateParameterRecord(
    const std::optional<pasta::RecordDecl> &record) {
  if (record) {
    if (auto cspec = pasta::ClassTemplateSpecializationDecl::From(*record)) {
      for (pasta::TemplateArgument arg : cspec->TemplateArguments()) {
        if (auto arg_type = arg.AsType()) {
          return arg_type->AsRecordDeclaration();
        }
      }
    }
  }
  return std::nullopt;
}

static std::tuple<std::string, std::string, std::string>
NamesFor(unsigned meth_id) {
  std::string field = "val" + std::to_string(meth_id);
  std::string getter_name = "get" + Capitalize(field);
  std::string setter_name = "set" + Capitalize(field);
  std::string init_name = "init" + Capitalize(field);
  return std::make_tuple(std::move(getter_name),
                         std::move(setter_name),
                         std::move(init_name));
}

void CodeGenerator::RunOnOptional(
    std::ostream &os, ClassHierarchy *cls, SpecificEntityStorage &storage,
    const std::optional<pasta::RecordDecl> &record,
    const std::string &class_name, const std::string &api_name,
    const std::string &method_name,
    const std::string &nth_entity_reader, const std::string &base_name,
    const MethodListPtr &seen_methods) {

  std::optional<std::string> element_name =
      GetFirstTemplateParameterType(record);
  std::string capn_element_name;
  std::string cxx_element_name;
  std::string cxx_underlying_name;

  bool is_enum = false;
  bool is_bool = false;
  bool is_token = false;
  bool needs_test = true;
  if (!element_name) {

  } else if (*element_name == "bool") {
    is_bool = true;
    capn_element_name = "Bool";
    cxx_element_name = "bool";
    cxx_underlying_name = cxx_element_name;

  } else if (*element_name == "uint64_t") {
    capn_element_name = "UInt64";
    cxx_element_name = std::move(element_name.value());
    cxx_underlying_name = cxx_element_name;

  } else if (*element_name == "int64_t") {
    capn_element_name = "Int64";
    cxx_element_name = std::move(element_name.value());
    cxx_underlying_name = cxx_element_name;

  } else if (*element_name == "uint32_t") {
    capn_element_name = "UInt32";
    cxx_element_name = std::move(element_name.value());
    cxx_underlying_name = cxx_element_name;

  } else if (*element_name == "int32_t") {
    capn_element_name = "Int32";
    cxx_element_name = std::move(element_name.value());
    cxx_underlying_name = cxx_element_name;

  } else if (*element_name == "uint8_t") {
    capn_element_name = "UInt8";
    cxx_element_name = std::move(element_name.value());
    cxx_underlying_name = cxx_element_name;

  } else if (*element_name == "int8_t") {
    capn_element_name = "Int8";
    cxx_element_name = std::move(element_name.value());
    cxx_underlying_name = cxx_element_name;

  // } else if (*element_name == "double") {
  //   capn_element_name = "Float64";
  //   cxx_element_name = std::move(element_name.value());
  //   cxx_underlying_name = cxx_element_name;

  // } else if (*element_name == "float") {
  //   capn_element_name = "Float32";
  //   cxx_element_name = std::move(element_name.value());
  //   cxx_underlying_name = cxx_element_name;

  } else if (enum_names.count(*element_name)) {
    auto &types = enum_type[*element_name];
    capn_element_name = types.second;
    cxx_element_name = *element_name;
    cxx_underlying_name = types.first;
    is_enum = true;

  // E.g. `optional<vector<CXXBaseSpecifier>>`, `optional<vector<FriendDecl>>`.
  } else if (*element_name == "vector") {
    if (auto sub_record = GetTemplateParameterRecord(record)) {
      RunOnVector(os, storage, sub_record, class_name, api_name, method_name,
                  nth_entity_reader, true, base_name, seen_methods);
      return;
    }

  // Optional strings will be empty.
  } else if (*element_name == "string" ||
             *element_name == "basic_string" ||
             *element_name == "string_view" ||
             *element_name == "basic_string_view" ||
             *element_name == "path") {

    capn_element_name = "Text";
    cxx_element_name = "std::string_view";

  // Optional references will be left as `0` if they're not present.
  } else if (gEntityClassNames.count(element_name.value())) {
    needs_test = false;

    if (!gUnserializableTypes.count(element_name.value())) {
      capn_element_name = "UInt64";  // Reference.
      cxx_element_name = element_name.value();
    }

    if (*element_name == "Token" || *element_name == "FileToken" ||
        *element_name == "MacroToken") {
      capn_element_name = "UInt64";  // Reference.
      cxx_element_name = "Token";
      is_token = true;
    }

  } else if (gNotReferenceTypesRelatedToEntities.count(element_name.value())) {
    capn_element_name = "UInt32";  // Offset.
    cxx_element_name = element_name.value();
  }

  if (capn_element_name.empty()) {
    return;
  }

  const auto i = storage.AddMethod(capn_element_name);
  auto [getter_name, setter_name, init_name] = NamesFor(i);

  unsigned is_present_i = ~0u;
  if (needs_test) {
    is_present_i = storage.AddMethod("Bool");
  }

  auto [ip_getter_name, ip_setter_name, ip_init_name] = NamesFor(is_present_i);

  // Tokens are nullable-ish.
  if (is_token) {
    os
        << "  Token " << api_name << "(void) const;\n";

    lib_cpp_os
        << "Token " << class_name << "::" << api_name
        << "(void) const {\n";
  } else {
    os
        << "  std::optional<" << cxx_element_name << "> "
        << api_name << "(void) const;\n";

    lib_cpp_os
        << "std::optional<" << cxx_element_name << "> "
        << class_name << "::" << api_name
        << "(void) const {\n";
  }

  if (needs_test) {
    if (is_token) {
      lib_cpp_os
          << "  if (!impl->reader." << ip_getter_name << "()) {\n"
          << "    return Token();\n"
          << "  } else {\n";
    } else {
      lib_cpp_os
          << "  if (!impl->reader." << ip_getter_name << "()) {\n"
          << "    return std::nullopt;\n"
          << "  } else {\n";
    }
  } else {
    lib_cpp_os
        << "  if (true) {\n";
  }

  // Take the parent from the `TokenTree` if we have it.
  if (base_name == "Macro" && method_name == "Parent") {
    serialize_cpp_os
        << "  std::optional<const void *> v" << i << ";\n"
        << "  if (tt) {\n"
        << "    auto x" << i << " = tt->" << method_name << "();\n"
        << "    if (x" << i << ") {\n"
        << "      v" << i << " = x" << i << "->RawNode();\n"
        << "    }\n"
        << "  } else {\n"
        << "    auto x" << i << " = e." << method_name << "();\n"
        << "    if (x" << i << ") {\n"
        << "      v" << i << " = x" << i << "->RawMacro();\n"
        << "    }\n"
        << "  }\n";

  } else if (class_name == "MacroSubstitution" &&
             (method_name == "FirstFullySubstitutedToken" ||
              method_name == "LastFullySubstitutedToken")) {
    serialize_cpp_os
        << "  std::optional<pasta::MacroToken> v" << i << ";\n"
        << "  if (tt) {\n"
        << "    v" << i << " = tt->" << method_name << "();\n"
        << "  } else {\n"
        << "    v" << i << " = e." << method_name << "();\n"
        << "  }\n";

  } else if (class_name == "MacroSubstitution" &&
             method_name == "NameOrOperator") {
    serialize_cpp_os
        << "  std::optional<pasta::MacroToken> v" << i << ";\n"
        << "  if (tt) {\n"
        << "    v" << i << " = tt->" << method_name << "();\n"
        << "  } else {\n"
        << "    v" << i << " = e." << method_name << "();\n"
        << "  }\n";


  } else {
    serialize_cpp_os
        << "  auto v" << i << " = e." << method_name << "();\n";
  }

  const char *serializer = nullptr;

  // Strings.
  if (element_name.value() == "string" ||
      element_name.value() == "basic_string") {
    assert(needs_test);
    serializer = "MX_VISIT_OPTIONAL_TEXT";

    serialize_cpp_os
        << "  if (v" << i << ") {\n"
        << "    b." << setter_name << "(v" << i << ".value());\n"
        << "    b." << ip_setter_name << "(true);\n"
        << "  } else {\n"
        << "    b." << ip_setter_name << "(false);\n"
        << "  }\n";

    lib_cpp_os
        << "    capnp::Text::Reader data = impl->reader." << getter_name
        << "();\n"
        << "    return " << cxx_element_name
        << "(data.cStr(), data.size());\n";

  // String views need to be converted to `std::string` because Cap'n
  // Proto requires `:Text` fields to be `NUL`-terminated.
  } else if (*element_name == "string_view" ||
             *element_name == "basic_string_view") {
    assert(needs_test);

    serializer = "MX_VISIT_OPTIONAL_TEXT";

    serialize_cpp_os
        << "  if (v" << i << ") {\n"
        << "    if (v" << i << "->empty()) {\n"
        << "      b." << setter_name << "(\"\");\n"
        << "    } else {\n"
        << "      std::string s" << i << "(v" << i << "->data(), v"
        << i << "->size());\n"
        << "      b." << setter_name << "(s" << i << ");\n"
        << "    }\n"
        << "    b." << ip_setter_name << "(true);\n"
        << "  } else {\n"
        << "    b." << ip_setter_name << "(false);\n"
        << "  }\n";

    lib_cpp_os
        << "    capnp::Text::Reader data = impl->reader." << getter_name
        << "();\n"
        << "    return " << cxx_element_name
        << "(data.cStr(), data.size());\n";

  // Filesystem paths.
  } else if (*element_name == "path") {
    assert(needs_test);

    serializer = "MX_VISIT_OPTIONAL_PATH";

    serialize_cpp_os
        << "  if (v" << i << ") {\n"
        << "    b." << setter_name
        << "(v" << i << ".value().lexically_normal().generic_string());\n"
        << "    b." << ip_setter_name << "(true);\n"
        << "  } else {\n"
        << "    b." << ip_setter_name << "(false);\n"
        << "  }\n";

    lib_cpp_os
        << "    capnp::Text::Reader data = impl->reader." << getter_name
        << "();\n"
        << "    return data.cStr();\n";

  // Reference types.
  } else if (gEntityClassNames.count(element_name.value())) {
    assert(!needs_test);
    forward_decls.insert(cxx_element_name);

    if (is_token) {
      serializer = "MX_VISIT_ENTITY";
    } else {
      serializer = "MX_VISIT_OPTIONAL_ENTITY";
    }

    serialize_cpp_os
        << "  if (v" << i << ") {\n"
        << "    auto id" << i << " = es.EntityId(v" << i << ".value());\n"
        << "    b." << setter_name << "(id" << i << ");\n"
        << "  } else {\n"
        << "    b." << setter_name << "(mx::kInvalidEntityId);\n"
        << "  }\n";

    lib_cpp_os
        << "    RawEntityId eid = impl->reader." << getter_name << "();\n"
        << "    if (eid == kInvalidEntityId) {\n";

    if (is_token) {
      lib_cpp_os
          << "      return Token();\n";
    } else {
      lib_cpp_os
          << "      return std::nullopt;\n";
    }

    lib_cpp_os
        << "    }\n";

    // Tokens are more like pseudo-entities but whatever.
    if (is_token) {
      element_name = "Token";
      lib_cpp_os
          << "    return impl->ep->TokenFor(impl->ep, eid);\n";

#define OPTIONAL_ENTITY(name, lower_name) \
    } else if (*element_name == #name) { \
      lib_cpp_os \
          << "    if (auto eptr = impl->ep->" #name "For(impl->ep, eid)) {\n" \
          << "      return " #name "(std::move(eptr));\n" \
          << "    }\n"; \
    \
    } else if (g ## name ## Names.count(element_name.value())) { \
      lib_cpp_os \
          << "    if (auto eptr = impl->ep->" #name "For(impl->ep, eid)) {\n" \
          << "      return " << element_name.value() << "::from_base(std::move(eptr));\n" \
          << "    }\n";


    OPTIONAL_ENTITY(File, file)
    FOR_EACH_ENTITY_CATEGORY(OPTIONAL_ENTITY)
#undef OPTIONAL_ENTITY

    } else {
      std::cerr << "??? optional element_name=" << (*element_name) << '\n';
      abort();
    }

  // Pseudo-entities.
  } else if (gNotReferenceTypesRelatedToEntities.count(element_name.value())) {
    assert(false);

  // Enums, bools, ints, etc.
  } else {
    assert(needs_test);
    assert(!cxx_underlying_name.empty());

    if (is_enum) {
      needed_decls.insert(cxx_element_name);
      serializer = "MX_VISIT_OPTIONAL_ENUM";
    } else if (is_bool) {
      serializer = "MX_VISIT_OPTIONAL_BOOL";
    } else {
      serializer = "MX_VISIT_OPTIONAL_INT";
    }

    serialize_cpp_os
        << "  if (v" << i << ") {\n"
        << "    b." << setter_name << "(static_cast<"
        << cxx_underlying_name << ">(v" << i << ".value()));\n"
        << "    b." << ip_setter_name << "(true);\n"
        << "  } else {\n"
        << "    b." << ip_setter_name << "(false);\n"
        << "  }\n";

    lib_cpp_os
        << "    return static_cast<" << cxx_element_name
        << ">(impl->reader." << getter_name << "());\n";
  }

  lib_cpp_os
      << "  }\n";

  if (is_token) {
    lib_cpp_os
        << "  return Token();\n";
  } else {
    lib_cpp_os
        << "  return std::nullopt;\n";
  }

  lib_cpp_os
      << "}\n\n";

  serialize_inc_os
      << "  " << serializer << "(" << class_name << ", " << api_name
      << ", " << i << ", MX_APPLY_METHOD, " << method_name << ", "
      << element_name.value() << ", " << nth_entity_reader << ")\n";
}

void CodeGenerator::RunOnVector(
    std::ostream &os, SpecificEntityStorage &storage,
    const std::optional<pasta::RecordDecl> &record,
    const std::string &class_name, const std::string &api_name,
    const std::string &method_name, const std::string &nth_entity_reader,
    bool optional, const std::string &base_name,
    const MethodListPtr &seen_methods) {

  std::optional<std::string> element_name =
      GetFirstTemplateParameterType(record);
  std::string capn_element_name;
  std::string cxx_element_name;

  const char **serializer = nullptr;

  if (!element_name) {
    if (optional) {
      std::cerr << "no optional element name?\n";
      abort();
    }

  } else if (*element_name == "string" ||
             *element_name == "basic_string" ||
             *element_name == "string_view" ||
             *element_name == "basic_string_view" ||
             *element_name == "path") {

    capn_element_name = "Text";
    cxx_element_name = "std::string_view";

  } else if (gNotReferenceTypesRelatedToEntities.count(element_name.value())) {
    capn_element_name = "UInt32";  // Offset.
    cxx_element_name = element_name.value();

  } else if (gEntityClassNames.count(element_name.value())) {
    if (!gUnserializableTypes.count(element_name.value())) {
      capn_element_name = "UInt64";  // Reference.
      cxx_element_name = element_name.value();
    }

  } else if (gNotReferenceTypes.count(element_name.value())) {
    std::cerr << element_name.value() << " not a reference type?\n";
    abort();
//          capn_element_name = element_name.value();
//          cxx_element_name = element_name.value();
  } else {
    std::cerr
        << "??? " << class_name << "::" << api_name << " -> vector of "
        << (*element_name) << '\n';
  }

  if (capn_element_name.empty()) {
    return;
  }

  auto is_token = *element_name == "Token" || *element_name == "FileToken" ||
                  *element_name == "MacroToken";

  const auto i = storage.AddMethod("List(" + capn_element_name + ")");
  unsigned opt_i = 0;
  if (optional) {
    opt_i = storage.AddMethod("Bool");
  }
  auto [getter_name, setter_name, init_name] = NamesFor(i);
  auto [opt_getter_name, opt_setter_name, opt_init_name] = NamesFor(opt_i);

  if (optional) {
    os
        << "  std::optional<std::vector<" << cxx_element_name << ">> "
        << api_name << "(void) const;\n";

    lib_cpp_os
        << "std::optional<std::vector<" << cxx_element_name << ">> ";

  } else {

    // Try to auto-generate an `nth_*` method.
    if (api_name.ends_with('s') && gEntityClassNames.count(*element_name)) {
      auto singular_api = api_name;
      singular_api.pop_back();
      os
          << "  std::optional<" << cxx_element_name << "> nth_"
          << singular_api << "(unsigned n) const;\n"
          << "  unsigned num_" << api_name << "(void) const;\n";

      (void) seen_methods->emplace("num_" + api_name);

      lib_cpp_os
          << "unsigned " << class_name
          << "::num_" << api_name << "(void) const {\n"
          << "  return impl->reader." << getter_name << "().size();\n"
          << "}\n\n"
          << "std::optional<" << cxx_element_name << "> " << class_name
          << "::nth_" << singular_api << "(unsigned n) const {\n"
          << "  auto list = impl->reader." << getter_name << "();\n"
          << "  if (n >= list.size()) {\n"
          << "    return std::nullopt;\n"
          << "  }\n"
          << "  const EntityProviderPtr &ep = impl->ep;\n"
          << "  auto v = list[n];\n";

      if (false) {

#define YIELD_ENTITY(name, lower_name) \
      } else if (*element_name == #name) { \
        lib_cpp_os \
            << "  auto e = ep->" #name "For(ep, v);\n" \
            << "  if (!e) {\n" \
            << "    return std::nullopt;\n" \
            << "  }\n" \
            << "  return " << #name << "(std::move(e));\n"; \
      \
      } else if (g ## name ## Names.count(*element_name)) { \
        lib_cpp_os \
            << "  auto e = ep->" #name "For(ep, v);\n" \
            << "  if (!e) {\n" \
            << "    return std::nullopt;\n" \
            << "  }\n" \
            << "  return " << element_name.value() << "::from_base(std::move(e));\n";

    YIELD_ENTITY(File, file)
    YIELD_ENTITY(Token, token)
    FOR_EACH_ENTITY_CATEGORY(YIELD_ENTITY)
      }

#undef YIELD_ENTITY
      lib_cpp_os
          << "}\n\n";
    }

    os
        << "  gap::generator<" << cxx_element_name << "> "
        << api_name << "(void) const &;\n";

    lib_cpp_os
        << "gap::generator<" << cxx_element_name << "> ";
  }

  lib_cpp_os
      << class_name << "::" << api_name
      << "(void) const ";
  if (!optional) {
    lib_cpp_os << "& ";  // Generators are `&`-qualified.
  }
  lib_cpp_os << "{\n";

  if (optional) {
    lib_cpp_os
        << "  if (!impl->reader." << opt_getter_name << "()) {\n"
        << "    return std::nullopt;\n"
        << "  }\n"
        << "  auto list = impl->reader." << getter_name << "();\n"
        << "  std::vector<" << cxx_element_name << "> vec;\n"
        << "  vec.reserve(list.size());\n";
  } else {
    lib_cpp_os
        << "  auto list = impl->reader." << getter_name << "();\n";
  }

  lib_cpp_os
      << "  EntityProviderPtr ep = impl->ep;\n";
  if (is_token) {
    lib_cpp_os
        << "  auto fragment = ep->FragmentFor(ep, impl->fragment_id);\n"
        << "  if (!fragment) {\n"
        << "    assert(false);\n";
    if (optional) {
      lib_cpp_os
          << "    return std::nullopt;\n";
    } else {
      lib_cpp_os
          << "    co_return;\n";
    }
    lib_cpp_os
        << "  }\n";

    // Triggers a `lib/Fragment.h` import.
    forward_decls.insert("TokenRange");

    if (base_name == "Macro") {
      lib_cpp_os
          << "  auto tok_reader = fragment->MacroTokenReader(fragment);\n";
    } else {
      lib_cpp_os
          << "  auto tok_reader = fragment->ParsedTokenReader(fragment);\n";
    }
  }

  lib_cpp_os
      << "  for (auto v : list) {\n";

  serialize_cpp_os << "  do {\n";

  if (optional) {
    serialize_cpp_os
        << "    auto ov" << i << " = e." << method_name << "();\n"
        << "    if (!ov" << i << ") {\n"
        << "      b." << opt_setter_name << "(false);\n"
        << "      break;\n"
        << "    }\n"
        << "    b." << opt_setter_name << "(true);\n"
        << "    auto v" << i << " = std::move(*ov" << i << ");\n";

  } else {
    serialize_cpp_os
        << "    auto v" << i << " = e." << method_name << "();\n";
  }
  serialize_cpp_os
      << "    auto sv" << i << " = b." << init_name
      << "(static_cast<unsigned>(v" << i << ".size()));\n"
      << "    auto i" << i << " = 0u;\n"
      << "    for (const auto &e" << i << " : v" << i << ") {\n";

  if (*element_name == "string" || *element_name == "basic_string") {

    static const char *_serializer[] = {"MX_VISIT_TEXT_LIST",
                                        "MX_VISIT_OPTIONAL_TEXT_LIST"};
    serializer = _serializer;

    serialize_cpp_os
        << "      sv" << i << ".set(i" << i << ", e" << i << ");\n";

    if (optional) {
      lib_cpp_os
          << "vec.emplace_back(v.cStr(), v.size());\n";
    } else {
      lib_cpp_os
          << "co_yield std::string_view(v.cStr(), v.size());\n";
    }

  // String views need to be converted to `std::string` because Cap'n
  // Proto requires `:Text` fields to be `NUL`-terminated.
  } else if (*element_name == "string_view" ||
             *element_name == "basic_string_view") {

    static const char *_serializer[] = {"MX_VISIT_TEXT_LIST",
                                        "MX_VISIT_OPTIONAL_TEXT_LIST"};
    serializer = _serializer;

    serialize_cpp_os
        << "      std::string se" << i << "(e" << i << ".data(), e"
        << i << ".size());\n"
        << "      sv" << i << ".set(i" << i << ", se" << i << ");\n";

    if (optional) {
      lib_cpp_os
          << "vec.emplace_back(v.cStr(), v.size());\n";
    } else {
      lib_cpp_os
          << "co_yield std::string_view(v.cStr(), v.size());\n";
    }

  // Filesystem paths.
  } else if (*element_name == "path") {

    static const char *_serializer[] = {"MX_VISIT_PATH_LIST",
                                        "MX_VISIT_OPTIONAL_PATH_LIST"};
    serializer = _serializer;

    serialize_cpp_os
        << "      sv" << i << ".set(i" << i << ", e" << i
        << ".lexically_normal().generic_string());\n";

    if (optional) {
      lib_cpp_os
          << "vec.emplace_back(v.cStr());\n";
    } else {
      lib_cpp_os
          << "co_yield std::filesystem::path(v.cStr());\n";
    }

  // Reference types.
  } else if (gEntityClassNames.count(*element_name)) {

    forward_decls.insert(cxx_element_name);
    static const char *_serializer[] = {"MX_VISIT_ENTITY_LIST",
                                        "MX_VISIT_OPTIONAL_ENTITY_LIST"};
    serializer = _serializer;

    serialize_cpp_os
        << "      sv" << i << ".set(i" << i << ", es.EntityId(e" << i
        << "));\n";

    lib_cpp_os
        << "    EntityId id(v);\n";

    // Tokens are more like pseudo-entities but whatever.
    if (is_token) {
      if (optional) {
        lib_cpp_os
            << "    if (auto t" << i << " = ep->TokenFor(ep, tok_reader, v)) {\n"
            << "      vec.emplace_back(std::move(t" << i << "));\n"
            << "    }\n";
      } else {
        lib_cpp_os
            << "    if (auto t" << i << " = ep->TokenFor(ep, tok_reader, v)) {\n"
            << "      co_yield t" << i << ";\n"
            << "    }\n";
      }


#define YIELD_ENTITY(name, lower_name) \
    } else if (*element_name == #name) { \
      if (optional) { \
        lib_cpp_os \
            << "    if (auto d" << i << " = ep->" #name "For(ep, v)) {\n" \
            << "      vec.emplace_back(std::move(d" << i << "));\n" \
            << "    }\n"; \
      } else { \
        lib_cpp_os \
            << "    if (auto d" << i << " = ep->" #name "For(ep, v)) {\n" \
            << "      co_yield " << #name << "(std::move(d" << i << "));\n" \
            << "    }\n"; \
      }

    YIELD_ENTITY(File, file)
    FOR_EACH_ENTITY_CATEGORY(YIELD_ENTITY)

#undef YIELD_ENTITY

#define YIELD_DERIVED_ENTITY(name, lower_name) \
    } else if (g ## name ## Names.count(*element_name)) { \
      if (optional) { \
        lib_cpp_os \
            << "    if (auto d" << i << " = ep->" #name "For(ep, v)) {\n" \
            << "      if (auto e = " << *element_name << "::from_base(std::move(d" << i << "))) {\n" \
            << "        vec.emplace_back(std::move(*e));\n" \
            << "      }\n" \
            << "    }\n"; \
      } else { \
        lib_cpp_os \
            << "    if (auto d" << i << " = ep->" #name "For(ep, v)) {\n" \
            << "      if (auto e = " << *element_name << "::from_base(std::move(d" << i << "))) {\n" \
            << "        co_yield std::move(*e);\n" \
            << "      }\n" \
            << "    }\n"; \
      }

    YIELD_DERIVED_ENTITY(File, file)
    FOR_EACH_ENTITY_CATEGORY(YIELD_DERIVED_ENTITY)

#undef YIELD_DERIVED_ENTITY

    } else {
      std::cerr << "??? vec " << (*element_name) << '\n';
      abort();
    }

  // Not reference types, need to serialize offsets.
  } else {
    abort();
  }

  lib_cpp_os
      << "  }\n";

  if (optional) {
    lib_cpp_os
        << "  return vec;\n";
  } else {
    lib_cpp_os
        << "  co_return;\n";
  }
  lib_cpp_os
      << "}\n\n";

  serialize_cpp_os
      << "      ++i" << i << ";\n"
      << "    }\n"
      << "  } while (false);\n";

  serialize_inc_os
        << "  " << serializer[optional] << "(" << class_name << ", "
        << api_name << ", " << i << ", MX_APPLY_METHOD, " << method_name << ", "
        << element_name.value() << ", " << nth_entity_reader << ")\n";
}

static const char *FriendOf(std::ostream &os, const std::string &cls,
                            const char *friend_cls) {
  if (cls == friend_cls) {
    return "";
  }
  os << "  friend class " << friend_cls << ";";
  return "\n";
}

static const char *FriendOf(std::ostream &os, const std::string &cls,
                            const std::string &friend_cls) {
  if (cls == friend_cls) {
    return "";
  }
  os << "  friend class " << friend_cls << ";";
  return "\n";
}

MethodListPtr CodeGenerator::RunOnClass(
    ClassHierarchy *cls, MethodListPtr parent_methods) {
  auto seen_methods = std::make_shared<MethodList>(*parent_methods);
  auto class_name = cls->record.Name();
  std::string lower_name;
  std::stringstream class_os;
  std::stringstream late_class_os;

  needs_reference = false;
  forward_decls.clear();
  derived_decls.clear();
  needed_decls.clear();

  std::cerr << "Running on " << class_name << '\n';

  forward_decls.insert(class_name);

#define DECLARE_IS_A(name, lower_name_) \
    const auto is_ ## lower_name_ = g ## name ## Names.count(class_name); \
    if (is_ ## lower_name_) { \
      lower_name = #lower_name_; \
    }

  FOR_EACH_ENTITY_CATEGORY(DECLARE_IS_A)
#undef DECLARE_IS_A

  const auto is_concrete = gConcreteClassNames.count(class_name);

  if (cls->base) {
    specific_storage.try_emplace(cls, specific_storage.find(cls->base)->second);

#define SET_STORAGE(name, lower_name) \
    } else if (is_ ## lower_name) { \
      specific_storage.try_emplace(cls, root_ ## lower_name ## _storage);

  FOR_EACH_ENTITY_CATEGORY(SET_STORAGE)
#undef SET_STORAGE

  }

  auto &storage = specific_storage.find(cls)->second;

  // We have our own representation for these.
  if (class_name == "Token" || class_name == "TokenRange" ||
      class_name == "FileToken" || class_name == "MacroToken" ||
      class_name == "MacroRange" || class_name == "File" ||
      class_name == "Fragment") {
    return parent_methods;
  }

  auto is_frontend_type = gFrontendTypes.find(class_name) != gFrontendTypes.end();
  auto dir_name = is_frontend_type ? "Frontend" : "AST";

  std::string base_name;
  std::string category = "NOT_AN_ENTITY";
  if (false) {

#define SET_BASE_NAME(name, lower_name) \
    } else if (is_ ## lower_name) { \
      base_name = #name; \
      category = SnakeCaseToEnumCase(#lower_name);

  FOR_EACH_ENTITY_CATEGORY(SET_BASE_NAME)
#undef SET_STORAGE
  }

  std::ofstream os(include_dir / dir_name / (class_name + ".h"),
                   std::ios::trunc | std::ios::out);
  os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n";

  if (class_name == base_name) {
    os
        << "#include <compare>\n"
        << "#include <cstdint>\n"
        << "#include <filesystem>\n"
        << "#include <gap/coro/generator.hpp>\n"
        << "#include <memory>\n"
        << "#include <optional>\n"
        << "#include <span>\n"
        << "#include <vector>\n\n"
        << "#include \"../Compiler.h\"\n"
        << "#include \"../Entity.h\"\n"
        << "#include \"../Iterator.h\"\n"
        << "#include \"../Frontend/TokenContext.h\"\n\n";
  }

  if (is_frontend_type) {
    frontend_h_os << "#include \"" << dir_name << '/' << class_name << ".h\"\n";
  } else {
    ast_h_os << "#include \"" << dir_name << '/' << class_name << ".h\"\n";
  }

  std::string nth_entity_reader;
  const char *end_serializer = nullptr;

  serialize_inc_os
      << "#ifndef MX_ENTER_VISIT_" << class_name
      << "\n#  define MX_ENTER_VISIT_" << class_name;

  if (cls->base) {
    serialize_inc_os
      << " MX_ENTER_VISIT_" << cls->base->record.Name();
  }

  serialize_inc_os
      << "\n#endif\n#ifndef MX_EXIT_VISIT_" << class_name
      << "\n#  define MX_EXIT_VISIT_" << class_name;

  if (cls->base) {
    serialize_inc_os
      << " MX_EXIT_VISIT_" << cls->base->record.Name();
  }

  serialize_inc_os
      << "\n#endif\n\n";

  if (is_declaration) {

    if (class_name == "Decl") {
      needed_decls.insert("DeclKind");
    }

    serialize_cpp_os
        << "void Serialize" << class_name
        << "(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::"
        << class_name << " &e, const TokenTree *) {\n"
        << "  (void) pf;\n"
        << "  (void) es;\n"
        << "  (void) b;\n"
        << "  (void) e;\n";

    if (is_concrete) {
      serialize_inc_os
          << "MX_BEGIN_VISIT_DECL";
    } else {
      serialize_inc_os
          << "MX_BEGIN_VISIT_ABSTRACT_DECL";
    }
    serialize_inc_os
        << "(" << class_name << ")\n"
        << "  MX_ENTER_VISIT_" << class_name << "\n";

    end_serializer = "MX_END_VISIT_DECL";

    nth_entity_reader = "NthDecl";

  } else if (is_statement) {

    if (class_name == "Stmt") {
      needed_decls.insert("StmtKind");
    }

    serialize_cpp_os
        << "void Serialize" << class_name
        << "(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::"
        << class_name << " &e, const TokenTree *) {\n"
        << "  (void) pf;\n";

    if (is_concrete) {
      serialize_inc_os
          << "MX_BEGIN_VISIT_STMT";
    } else {
      serialize_inc_os
          << "MX_BEGIN_VISIT_ABSTRACT_STMT";
    }
    serialize_inc_os
        << "(" << class_name << ")\n"
        << "  MX_ENTER_VISIT_" << class_name << "\n";
    end_serializer = "MX_END_VISIT_STMT";

    nth_entity_reader = "NthStmt";
  
  } else if (is_type) {

    if (class_name == "Type") {
      needed_decls.insert("TypeKind");
    }

    serialize_cpp_os
        << "void Serialize" << class_name
        << "(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::"
        << class_name << " &e, const TokenTree *) {\n"
        << "  (void) pf;\n"
        << "  (void) es;\n"
        << "  (void) b;\n"
        << "  (void) e;\n";

    if (is_concrete) {
      serialize_inc_os
          << "MX_BEGIN_VISIT_TYPE";
    } else {
      serialize_inc_os
          << "MX_BEGIN_VISIT_ABSTRACT_TYPE";
    }
    serialize_inc_os
        << "(" << class_name << ")\n"
        << "  MX_ENTER_VISIT_" << class_name << "\n";
    end_serializer = "MX_END_VISIT_TYPE";

    nth_entity_reader = "NthType";

  // Attributes. Treated like entities because they have a class hierarchy.
  } else if (is_attribute) {
    if (class_name == "Attr") {
      needed_decls.insert("AttrKind");
    }
    serialize_cpp_os
        << "void Serialize" << class_name
        << "(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::"
        << class_name << " &e, const TokenTree *) {\n"
        << "  (void) pf;\n"
        << "  (void) es;\n"
        << "  (void) b;\n"
        << "  (void) e;\n";

    if (is_concrete) {
      serialize_inc_os
          << "MX_BEGIN_VISIT_ATTR";
    } else {
      serialize_inc_os
          << "MX_BEGIN_VISIT_ABSTRACT_ATTR";
    }
    serialize_inc_os
        << "(" << class_name << ")\n"
        << "  MX_ENTER_VISIT_" << class_name << "\n";
    end_serializer = "MX_END_VISIT_ATTR";

    nth_entity_reader = "NthAttr";
  
  // Macros. Treated like entities because they have a class hierarchy.
  } else if (is_macro) {
    if (class_name == "Macro") {
      needed_decls.insert("MacroKind");
      class_os << "using MacroOrToken = std::variant<Macro, Token>;\n";
    }

    serialize_cpp_os
        << "void Serialize" << class_name
        << "(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, "
        << "const pasta::" << class_name << " &e, const TokenTree *tt) {\n"
        << "  (void) pf;\n"
        << "  (void) tt;\n"
        << "  (void) es;\n"
        << "  (void) b;\n"
        << "  (void) e;\n";

    if (is_concrete) {
      serialize_inc_os
          << "MX_BEGIN_VISIT_MACRO";
    } else {
      serialize_inc_os
          << "MX_BEGIN_VISIT_ABSTRACT_MACRO";
    }
    serialize_inc_os
        << "(" << class_name << ")\n"
        << "  MX_ENTER_VISIT_" << class_name << "\n";
    end_serializer = "MX_END_VISIT_MACRO";

    nth_entity_reader = "NthMacro";

#define HANDLE_PSEUDO(type_name, lower_name) \
    } else if (is_ ## lower_name) { \
      needed_decls.insert("PseudoKind"); \
      serialize_cpp_os \
          << "void Serialize" << class_name \
          << "(const PendingFragment &pf, const EntityMapper &es, mx::ast::" #type_name \
          << "::Builder b, const pasta::" \
          << class_name << " &e, const TokenTree *) {\n" \
          << "  (void) pf;\n" \
          << "  (void) es;\n" \
          << "  (void) b;\n" \
          << "  (void) e;\n"; \
      \
      if (is_concrete) { \
        serialize_inc_os << "MX_BEGIN_VISIT_PSEUDO"; \
      } else { \
        serialize_inc_os << "MX_BEGIN_VISIT_ABSTRACT_PSEUDO"; \
      } \
      serialize_inc_os \
          << "(" << class_name << ")\n" \
          << "  MX_ENTER_VISIT_" << class_name << "\n"; \
      end_serializer = "MX_END_VISIT_PSEUDO"; \
      \
      nth_entity_reader = "Nth" #type_name;

  FOR_EACH_ENTITY_CATEGORY(HANDLE_PSEUDO)
#undef HANDLE_PSEUDO

  } else {
    std::cerr << "Unhandled top-level entity type: " << class_name << '\n';
    abort();
  }

  std::vector<const ClassHierarchy *> wl;
  wl.push_back(cls);

  if (is_declaration || is_statement || is_attribute || is_type || is_macro) {
    if (class_name != base_name) {
      lib_cpp_os
          << "namespace {\n"
          << "static const " << base_name << "Kind k"
          << class_name << "DerivedKinds[] = {\n";

      for (auto i = 0u; i < wl.size(); ++i) {
        const ClassHierarchy *c = wl[i];
        std::string c_name = c->record.Name();
        if (gConcreteClassNames.count(c_name)) {
          derived_decls.insert(c_name);
          lib_cpp_os << "    " << c_name << "::static_kind(),\n";
        }
        for (const ClassHierarchy *d : c->derived) {
          wl.push_back(d);
        }
      }
      lib_cpp_os
          << "};\n"
          << "}  // namespace\n\n";
    }
  }

  class_os
      << "class MX_EXPORT " << class_name;

//  std::stringstream dummy_ss;
//  std::ostream &maybe_serialize_cpp_os =
//      gUnserializableTypes.count(class_name) ? dummy_ss : serialize_cpp_os;

  auto dont_serialize = !!gUnserializableTypes.count(class_name);

  if (cls->base) {
    std::string base_class_name = cls->base->record.Name();
    needed_decls.insert(base_class_name);

    // Inheritance.
    class_os
        << " : public " << base_class_name << " {\n"
        << " private:\n"
        << FriendOf(class_os, class_name, "FragmentImpl");

    // Derived classes are friends with all of their parents.
    for (auto parent = cls->base; parent; parent = parent->base) {
      forward_decls.insert(parent->record.Name());
      class_os
          << FriendOf(class_os, class_name, parent->record.Name());
    }

    // Parent class serialization.
    if (!dont_serialize) {
      if (is_macro) {
        serialize_cpp_os
            << "  Serialize" << base_class_name << "(pf, es, b, e, tt);\n";
      } else {
        serialize_cpp_os
            << "  Serialize" << base_class_name << "(pf, es, b, e, nullptr);\n";
      }

      serialize_inc_os
          << "  MX_VISIT_BASE(" << class_name << ", " << base_class_name << ")\n";
    }

    class_os
        << " public:\n";

    late_class_os
        << "static_assert(sizeof(" << class_name
        << ") == sizeof(" << base_class_name << "));\n\n";

  // Things like `TemplateParameterList`, that aren't themselves entities, but
  // are derived from entities in fragments, and link to entities in fragments,
  // and so we need to carry around a fragment pointer.
  } else if (gFragmentEntityTypes.count(class_name)) {
    auto make_parent = [&] (const char *name, const char *link, const char *ent_kind) {
      auto sd = storage.AddMethod("UInt64");  // Reference.
      auto [cd_getter_name, cd_setter_name, cd_init_name] = NamesFor(sd);

      class_os
          << "  std::optional<" << ent_kind << "> " << name << "(void) const;\n";

      serialize_inc_os
          << "  " << link << "(" << class_name
          << ", " << name << ", " << sd << ")\n";

      serialize_cpp_os
          << "  b." << cd_setter_name << "(es.Parent" << ent_kind << "Id(e));\n";

      lib_cpp_os
          << "std::optional<" << ent_kind << "> " << class_name << "::" << name << "(void) const {\n"
          << "  if (auto id = impl->reader." << cd_getter_name << "(); "
          << "id != kInvalidEntityId) {\n"
          << "    if (auto eptr = impl->ep->" << ent_kind << "For(impl->ep, id)) {\n"
          << "      return " << ent_kind << "(std::move(eptr));\n"
          << "    }\n"
          << "    assert(false);\n"
          << "  }\n"
          << "  return std::nullopt;\n"
          << "}\n\n";
      return sd;
    };

    class_os
        << " {\n"
        << " public:\n";

    // `*::parent_declaration()`.
    if (class_name == "Decl" || class_name == "Stmt" ||
        class_name == "CXXBaseSpecifier" ||
        class_name == "CXXTemplateParameterList" ||
        class_name == "Designator" || class_name == "TemplateArgument") {
      make_parent("parent_declaration", "MX_VISIT_DECL_LINK", "Decl");
    }

    // `*::parent_statement()`.
    if (class_name == "Decl" || class_name == "Stmt" ||
        class_name == "Designator" || class_name == "TemplateArgument") {
      make_parent("parent_statement", "MX_VISIT_STMT_LINK", "Stmt");
    }

    // `Decl::is_definition`
    if (class_name == "Decl") {
      const auto def = storage.AddMethod("Bool");
      auto [def_getter_name, def_setter_name, def_init_name] = NamesFor(def);

      serialize_inc_os
          << "  MX_VISIT_BOOL(Decl, is_definition, " << def
          << ", MX_APPLY_FUNC, IsDefinition, bool, NthDecl)\n";

      lib_cpp_os
          << "bool Decl::is_definition(void) const {\n"
          << "  return impl->reader." << def_getter_name << "();\n"
          << "}\n\n";

      serialize_cpp_os
          << "  b." << def_setter_name << "(IsDefinition(e));\n";
    }

    class_os
        << " protected:\n"
        << FriendOf(class_os, class_name, "Attr")
        << FriendOf(class_os, class_name, "Decl")
        << FriendOf(class_os, class_name, "File")
        << FriendOf(class_os, class_name, "Fragment")
        << FriendOf(class_os, class_name, "FragmentImpl")
        << FriendOf(class_os, class_name, "Index")
        << FriendOf(class_os, class_name, "Macro")
        << FriendOf(class_os, class_name, "Reference")
        << FriendOf(class_os, class_name, "Stmt")
        << FriendOf(class_os, class_name, "TokenContext")
        << FriendOf(class_os, class_name, "Type")
        << FriendOf(class_os, class_name, class_name + "Impl")
        << "  friend class ir::Operation;\n"
        << "  friend class ir::Value;\n\n"
        << "  std::shared_ptr<const " << class_name << "Impl> impl;\n";

    if (class_name == base_name) {
      forward_decls.insert("File");
      class_os
          << "  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);\n"
          << "  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);\n"
          << "  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);\n";
    }

    class_os
        << " public:\n"
        << "  " << class_name << "(" << class_name << " &&) noexcept = default;\n"
        << "  " << class_name << "(const " << class_name << " &) = default;\n"
        << "  " << class_name << " &operator=(" << class_name << " &&) noexcept = default;\n"
        << "  " << class_name << " &operator=(const " << class_name << " &) = default;\n\n"
        << "  inline bool operator==(const " << class_name << " &rhs) const noexcept {\n";

      // Equality on Decls need to be tested in its canonicalized form
      // if (class_name == "Decl") {
      //   class_os
      //       << "    return canonical_declaration().id().Pack() ==\n"
      //       << "           rhs.canonical_declaration().id().Pack();\n";
      // } else {
      class_os
          << "    return id().Pack() == rhs.id().Pack();\n";
      //}

      class_os
          << "  }\n\n"
          << "  /* implicit */ inline " << class_name
          << "(std::shared_ptr<const " << class_name << "Impl> impl_)\n"
          << "      : impl(std::move(impl_)) {}\n\n";

    if (base_name == class_name) {
      forward_decls.insert(class_name + "Impl");

      lib_cpp_os
          << "std::shared_ptr<EntityProvider> "
          << class_name << "::entity_provider_of(const Index &index_) {\n"
          << "  return index_.impl;\n"
          << "}\n\n"
          << "std::shared_ptr<EntityProvider> "
          << class_name << "::entity_provider_of(const Fragment &frag_) {\n"
          << "  return frag_.impl->ep;\n"
          << "}\n\n"
          << "std::shared_ptr<EntityProvider> "
          << class_name << "::entity_provider_of(const File &file_) {\n"
          << "  return file_.impl->ep;\n"
          << "}\n\n";
    }

    needs_reference = true;

    class_os
        << "  constexpr inline static EntityCategory static_category(void) {\n"
        << "    return EntityCategory::" << category << ";\n"
        << "  }\n\n"
        << "  Packed" << class_name << "Id id(void) const;\n\n";

    seen_methods->emplace("id");  // Manual.
    seen_methods->emplace("references");  // Manual.

    if (class_name == "Decl") {
      class_os
          << "  std::optional<Decl> definition(void) const;\n"
          << "  bool is_definition(void) const;\n"
          << "  Decl canonical_declaration(void) const;\n"
          << "  gap::generator<Decl> redeclarations(void) const &;\n"
          << "  gap::generator<Decl> specializations(void) const &;\n"
          << "\n";

      seen_methods->emplace("uses");  // Manual.
      seen_methods->emplace("definition");  // Manual.
      seen_methods->emplace("canonical_declaration");  // Disable this.
      seen_methods->emplace("is_canonical_declaration");  // Disable this.
      seen_methods->emplace("is_referenced");  // Disable this.
      seen_methods->emplace("is_this_declarationaration_referenced");  // Disable this.
      seen_methods->emplace("is_used");  // Disable this.
      seen_methods->emplace("is_first_declaration");  // Disable this.
      seen_methods->emplace("is_definition");  // Disable this; we've added it manually.
      seen_methods->emplace("is_this_declarationaration_a_definition");  // Disable this.
      seen_methods->emplace("parent");  // Disable this.
      seen_methods->emplace("prev_declaration_in_scope");  // TODO(pag): Disable this?
      seen_methods->emplace("most_recent_declaration");  // Disable this.
      seen_methods->emplace("most_recent_cxx_record_declaration");  // Disable this.
      seen_methods->emplace("next_class_category_raw");  // Disable this.
      seen_methods->emplace("begin_token");  // Disable this.
      seen_methods->emplace("end_token");  // Disable this.
      seen_methods->emplace("previous_declaration");  // Disable this.

    } else if (class_name == "Stmt") {
      class_os
          << "  std::optional<PackedDeclId> referenced_declaration_id(void) const;\n"
          << "  std::optional<Decl> referenced_declaration(void) const;\n"
          << "\n";

      // `Stmt::referenced_declaration`.
      const auto ref = storage.AddMethod("UInt64");
      auto [ref_getter_name, ref_setter_name, ref_init_name] = NamesFor(ref);
      serialize_inc_os
          << "  MX_VISIT_OPTIONAL_ENTITY(Stmt, referenced_declaration, " << ref
          << ", MX_APPLY_FUNC, ReferencedDecl, Decl, NthStmt)\n";

      lib_cpp_os
          << "std::optional<PackedDeclId> Stmt::referenced_declaration_id(void) const {\n"
          << "  if (auto id = impl->reader." << ref_getter_name << "();\n"
          << "      id != kInvalidEntityId) {\n"
          << "    VariantId vid = EntityId(id).Unpack();\n"
          << "    if (std::holds_alternative<DeclId>(vid)) {\n"
          << "      return std::get<DeclId>(vid);\n"
          << "    }\n"
          << "    assert(false);\n"
          << "  }\n"
          << "  return std::nullopt;\n"
          << "}\n\n";

      lib_cpp_os
          << "std::optional<Decl> Stmt::referenced_declaration(void) const {\n"
          << "  if (auto id = impl->reader." << ref_getter_name << "();\n"
          << "      id != kInvalidEntityId) {\n"
          << "    if (auto eptr = impl->ep->DeclFor(impl->ep, id)) {\n"
          << "      return Decl(std::move(eptr));\n"
          << "    }\n"
          << "    assert(false);\n"
          << "  }\n"
          << "  return std::nullopt;\n"
          << "}\n\n";

      serialize_cpp_os
          << "  if (auto r" << ref << " = ReferencedDecl(e)) {\n"
          << "    b." << ref_setter_name << "(es.EntityId(r" << ref
          << ".value()));\n"
          << "  }\n";

      seen_methods->emplace("uses");  // Manual.
      seen_methods->emplace("begin_token");  // Disable this.
      seen_methods->emplace("end_token");  // Disable this.

    } else if (class_name == "Type") {
      forward_decls.insert("TokenRange");
      class_os
          << "  TokenRange tokens(void) const;\n\n"
          << " public:\n";

      seen_methods->emplace("uses");  // Manual.
    
    } else if (class_name == "Attr") {
      class_os
          << " public:\n";

      seen_methods->emplace("uses");  // Manual.

    } else if (class_name == "Macro") {
      forward_decls.insert("Token");
      forward_decls.insert("TokenRange");
      class_os
          << " protected:\n"
          << "  static gap::generator<Macro> containing_internal(const Token &token);\n\n"
          << " public:\n"

      // Make it easy to get the root macro expansion.
          << "  Macro root(void) const &;\n"

      // Allow macros to conveniently find the file tokens covering their uses,
      // or their parent uses, etc. If this is a directive then this is just the
      // file tokens.
          << "  TokenRange use_tokens(void) const &;\n"
          << "  gap::generator<Token> generate_use_tokens(void) const &;\n"

      // Allow macros to conveniently find the final parsed expansion tokens
      // that they cover.
          << "  TokenRange expansion_tokens(void) const &;\n"
          << "  gap::generator<Token> generate_expansion_tokens(void) const &;\n\n";

      // Serialization of these tokens is manually performed in
      // `bin/Index/Persist.cpp`.
    }

  } else if (gNotReferenceTypesRelatedToEntities.count(class_name)) {
    std::cerr << class_name << " is a pseudo class?\n";
    abort();

  } else if (gEntityClassNames.count(class_name)) {
    std::cerr << class_name << " is an entity class?\n";
    abort();

  // Hrmm... Not sure what to put as the data for a non-entity.
  } else {
    std::cerr << class_name << " is not an entity class?\n";
    abort();
  }

  if (is_declaration || is_statement || is_attribute || is_macro || is_type) {
    if (class_name == base_name) {
      forward_decls.insert("File");
      class_os
          << "  static gap::generator<"
          << class_name << "> in(const Index &index, std::span<const "
          << class_name << "Kind> kinds);\n";

      if (!is_type) {
        class_os
            << "  static gap::generator<"
            << class_name << "> in(const Fragment &frag, std::span<const "
            << class_name << "Kind> kinds);\n"
            << "  static gap::generator<"
            << class_name << "> in(const File &file, std::span<const "
            << class_name << "Kind> kinds);\n";
      }
    }
  }

  // NOTE(pag): Macro containing a token is handled later.
  if (is_declaration || is_statement || is_attribute || is_type) {
    forward_decls.insert("Token");

    class_os
        << "  static gap::generator<"
        << class_name << "> in(const Index &index);\n"
        << "  static gap::generator<" << class_name
        << "> containing(const Token &tok);\n"
        << "  bool contains(const Token &tok) const;\n"
        << "  static std::optional<" << class_name << "> by_id(const Index &, EntityId);\n";

    if (!is_type) {
      class_os
          << "  static gap::generator<"
          << class_name << "> in(const Fragment &frag);\n"
          << "  static gap::generator<"
          << class_name << "> in(const File &file);\n";
    }
    class_os << "\n";

    lib_cpp_os
        << "gap::generator<" << class_name
        << "> " << class_name << "::containing(const Token &tok) {\n"
        << "  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {\n"
        << "    if (auto d = " << class_name << "::from(*ctx)) {\n"
        << "      co_yield *d;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n"
        << "bool " << class_name << "::contains(const Token &tok) const {\n"
        << "  auto id_ = id();\n"
        << "  for (auto &parent : " << class_name << "::containing(tok)) {\n"
        << "    if (parent.id() == id_) { return true; }\n"
        << "  }\n"
        << "  return false;\n"
        << "}\n\n";

  } else if (is_macro) {
    class_os
        << "  static gap::generator<" << class_name
        << "> in(const Fragment &frag);\n"
        << "  static gap::generator<" << class_name
        << "> in(const File &file);\n\n"
        << "  static gap::generator<"
        << class_name << "> in(const Index &index);\n"
        << "  static std::optional<" << class_name << "> by_id(const Index &, EntityId);\n\n";
  }

  if (is_declaration || is_statement) {
    class_os
        << "  static std::optional<" << class_name
        << "> from(const ir::Operation &op);\n"
        << "  static gap::generator<std::pair<" << class_name
        << ", ir::Operation>> in(const Compilation &tu);\n";

    // The base class methods are all manually implemented.
    if (class_name == base_name) {
      class_os
          << "  static gap::generator<std::pair<" << class_name
          << ", ir::Operation>> in(const Compilation &tu, std::span<const "
          << base_name << "Kind> kinds);\n\n";
    
    } else {

      lib_cpp_os
          << "std::optional<" << class_name
          << "> " << class_name << "::from(const ir::Operation &op) {\n"
          << "  if (auto val = " << base_name << "::from(op)) {\n"
          << "    return from_base(val.value());\n"
          << "  }\n"
          << "  return std::nullopt;\n"
          << "}\n\n"
          << "gap::generator<std::pair<" << class_name << ", ir::Operation>> "
          << class_name << "::in(const Compilation &tu) {\n"
          << "  for (std::pair<" << base_name << ", ir::Operation> res : "
          << base_name << "::in(tu, k" << class_name
          << "DerivedKinds)) {\n"
          << "    if (auto val = from_base(res.first)) {\n"
          << "      co_yield std::pair<" << class_name << ", ir::Operation>("
          << "std::move(val.value()), std::move(res.second));\n"
          << "    }\n"
          << "  }\n"
          << "}\n\n";
    }
  }

  if (is_declaration) {
    forward_decls.insert("Stmt");

    if (is_concrete) {
      auto snake_name = CapitalCaseToSnakeCase(class_name);
      snake_name = snake_name.substr(0u, snake_name.size() - 5u);
      class_os
          << "  inline static constexpr DeclKind static_kind(void) {\n"
          << "    return DeclKind::"
          << SnakeCaseToEnumCase(snake_name) << ";\n"
          << "  }\n\n";
    }

    class_os
        << "  static gap::generator<" << class_name
        << "> containing(const Decl &decl);\n"
        << "  static gap::generator<" << class_name
        << "> containing(const std::optional<Decl> &decl);\n\n"
        << "  static gap::generator<" << class_name
        << "> containing(const Stmt &stmt);\n"
        << "  static gap::generator<" << class_name
        << "> containing(const std::optional<Stmt> &stmt);\n\n"
        << "  bool contains(const Decl &decl);\n"
        << "  bool contains(const Stmt &stmt);\n\n";

    lib_cpp_os
        << "gap::generator<" << class_name << "> " << class_name
        << "::containing(const Decl &decl) {\n"
        << "  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();\n"
        << "       ancestor = ancestor->parent_declaration()) {\n"
        << "    if (auto d = " << class_name << "::from(*ancestor)) {\n"
        << "      co_yield *d;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n"
        << "gap::generator<" << class_name
        << "> " << class_name << "::containing(const std::optional<Decl> &decl) {\n"
        << "  if (decl.has_value()) {\n"
        << "    for (auto res : containing(decl.value())) {\n"
        << "      co_yield res;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n"
        << "gap::generator<" << class_name << "> " << class_name
        << "::containing(const Stmt &stmt) {\n"
        << "  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();\n"
        << "       ancestor = ancestor->parent_declaration()) {\n"
        << "    if (auto d = " << class_name << "::from(*ancestor)) {\n"
        << "      co_yield *d;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n"
        << "gap::generator<" << class_name
        << "> " << class_name << "::containing(const std::optional<Stmt> &stmt) {\n"
        << "  if (stmt.has_value()) {\n"
        << "    for (auto res : containing(stmt.value())) {\n"
        << "      co_yield res;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n"
        << "bool " << class_name << "::contains(const Decl &decl) {\n"
        << "  for (auto &parent : " << class_name << "::containing(decl)) {\n"
        << "    if (*this == parent) { return true; }\n"
        << "  }\n"
        << "  return false;\n"
        << "}\n\n"
        << "bool " << class_name << "::contains(const Stmt &stmt) {\n"
        << "  for (auto &parent : " << class_name << "::containing(stmt)) {\n"
        << "    if (*this == parent) { return true; }\n"
        << "  }\n"
        << "  return false;\n"
        << "}\n\n";

  } else if (is_statement) {

    forward_decls.insert("Decl");

    if (is_concrete) {
      auto snake_name = CapitalCaseToSnakeCase(class_name);
      class_os
          << "  inline static constexpr StmtKind static_kind(void) {\n"
          << "    return StmtKind::" << SnakeCaseToEnumCase(snake_name)
          << ";\n"
          << "  }\n\n";
    }

    class_os
        << "  static gap::generator<" << class_name
        << "> containing(const Decl &decl);\n"
        << "  static gap::generator<" << class_name
        << "> containing(const std::optional<Decl> &decl);\n\n"
        << "  static gap::generator<" << class_name
        << "> containing(const Stmt &stmt);\n"
        << "  static gap::generator<" << class_name
        << "> containing(const std::optional<Stmt> &stmt);\n\n"
        << "  bool contains(const Decl &decl);\n"
        << "  bool contains(const Stmt &stmt);\n\n";

    lib_cpp_os
        << "gap::generator<" << class_name << "> " << class_name
        << "::containing(const Decl &decl) {\n"
        << "  for (auto ancestor = decl.parent_statement(); ancestor.has_value();\n"
        << "       ancestor = ancestor->parent_statement()) {\n"
        << "    if (auto d = " << class_name << "::from(*ancestor)) {\n"
        << "      co_yield *d;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n"
        << "gap::generator<" << class_name
        << "> " << class_name << "::containing(const std::optional<Decl> &decl) {\n"
        << "  if (decl.has_value()) {\n"
        << "    for (auto res : containing(decl.value())) {\n"
        << "      co_yield res;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n"
        << "gap::generator<" << class_name << "> " << class_name
        << "::containing(const Stmt &stmt) {\n"
        << "  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();\n"
        << "       ancestor = ancestor->parent_statement()) {\n"
        << "    if (auto d = " << class_name << "::from(*ancestor)) {\n"
        << "      co_yield *d;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n"
        << "gap::generator<" << class_name
        << "> " << class_name << "::containing(const std::optional<Stmt> &stmt) {\n"
        << "  if (stmt.has_value()) {\n"
        << "    for (auto res : containing(stmt.value())) {\n"
        << "      co_yield res;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n"
        << "bool " << class_name << "::contains(const Decl &decl) {\n"
        << "  for (auto &parent : " << class_name << "::containing(decl)) {\n"
        << "    if (*this == parent) { return true; }\n"
        << "  }\n"
        << "  return false;\n"
        << "}\n\n"
        << "bool " << class_name << "::contains(const Stmt &stmt) {\n"
        << "  for (auto &parent : " << class_name << "::containing(stmt)) {\n"
        << "    if (*this == parent) { return true; }\n"
        << "  }\n"
        << "  return false;\n"
        << "}\n\n";

  } else if (is_type) {

    if (is_concrete) {
      auto snake_name = CapitalCaseToSnakeCase(class_name);
      snake_name = snake_name.substr(0u, snake_name.size() - 5u);

      class_os
          << "  inline static constexpr TypeKind static_kind(void) {\n"
          << "    return TypeKind::"
          << SnakeCaseToEnumCase(snake_name) << ";\n"
          << "  }\n\n";
    }

  } else if (is_attribute) {

    if (is_concrete) {
      auto snake_name = CapitalCaseToSnakeCase(class_name);
      snake_name = snake_name.substr(0u, snake_name.size() - 5u);

      class_os
          << "  inline static constexpr AttrKind static_kind(void) {\n"
          << "    return AttrKind::" 
          << SnakeCaseToEnumCase(snake_name) << ";\n"
          << "  }\n\n";
    }

  } else if (is_macro) {
    if (is_concrete) {

      // NOTE(pag): Weird-ish format for macros.
      std::string enum_class_name = class_name;
      if (class_name.starts_with("Macro")) {
        enum_class_name = class_name.substr(5u);

      } else if (class_name.ends_with("MacroDirective")) {
        enum_class_name = class_name.substr(
            0, class_name.size() - 14u);
        enum_class_name += "Directive";
      }

      auto snake_name = CapitalCaseToSnakeCase(enum_class_name);
      class_os
          << "  inline static constexpr MacroKind static_kind(void) {\n"
          << "    return MacroKind::"
          << SnakeCaseToEnumCase(snake_name) << ";\n"
          << "  }\n\n";
    }

    class_os
        << "  static gap::generator<" << class_name
        << "> containing(const Macro &macro);\n"
        << "  bool contains(const Macro &macro);\n\n"
        << "  static gap::generator<" << class_name
        << "> containing(const Token &token);\n"
        << "  bool contains(const Token &token);\n\n";

    lib_cpp_os
        << "gap::generator<" << class_name << "> " << class_name
        << "::containing(const Macro &macro) {\n"
        << "  for (auto impl = macro.parent(); impl; impl = impl->parent()) {\n"
        << "    if (auto d = " << class_name << "::from(*impl)) {\n"
        << "      co_yield *d;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n"
        << "bool " << class_name << "::contains(const Macro &macro) {\n"
        << "  auto id_ = id();\n"
        << "  for (auto &parent : " << class_name << "::containing(macro)) {\n"
        << "    if (parent.id() == id_) { return true; }\n"
        << "  }\n"
        << "  return false;\n"
        << "}\n\n"
        << "bool " << class_name << "::contains(const Token &token) {\n"
        << "  auto id_ = id();\n"
        << "  for (auto &parent : " << class_name << "::containing(token)) {\n"
        << "    if (parent.id() == id_) { return true; }\n"
        << "  }\n"
        << "  return false;\n"
        << "}\n\n"
        << "gap::generator<" << class_name << "> " << class_name
        << "::containing(const Token &token) {\n"
        << "  for (auto m : Macro::containing_internal(token)) {\n"
        << "    if (auto d = " << class_name << "::from(m)) {\n"
        << "      co_yield *d;\n"
        << "    }\n"
        << "  }\n"
        << "}\n\n";
  }

  // Add derived overrides for redeclarations.
  if (class_name != "Decl" && gDeclNames.count(class_name)) {
    class_os
        << "  " << class_name << " canonical_declaration(void) const;\n"
        << "  std::optional<" << class_name << "> definition(void) const;\n"
        << "  gap::generator<" << class_name
        << "> redeclarations(void) const &;\n";

    lib_cpp_os
        << class_name << " " << class_name << "::canonical_declaration(void) const {\n"
        << "  if (auto canon = from_base(this->Decl::canonical_declaration())) {\n"
        << "    return std::move(canon.value());\n"
        << "  }\n"
        << "  for (" << class_name << " redecl : redeclarations()) {\n"
        << "    return redecl;\n"
        << "  }\n"
        << "  __builtin_unreachable();\n"
        << "}\n\n"
        << "std::optional<" << class_name << "> " << class_name << "::definition(void) const {\n"
        << "  if (auto def = this->Decl::definition()) {\n"
        << "    return from_base(def.value());\n"
        << "  }\n"
        << "  return std::nullopt;\n"
        << "}\n\n"
        << "gap::generator<" << class_name
        << "> " << class_name << "::redeclarations(void) const & {\n"
        << "  for (Decl r : Decl::redeclarations()) {\n"
        << "    if (std::optional<" << class_name << "> dr = from_base(r)) {\n"
        << "      co_yield std::move(dr.value());\n"
        << "      continue;\n"
        << "    }\n"
        << "    assert(false);\n  // Wrong type?\n"
        << "  }\n"
        << "  co_return;\n"
        << "}\n\n";
  }

  // Make a generator for all of the derived kinds of this particular entity.
  if (is_declaration || is_statement || is_attribute || is_type || is_macro) {

    lib_cpp_os
        << "std::optional<" << class_name << "> " << class_name
        << "::by_id(const Index &index, EntityId eid) {\n"
        << "  VariantId vid = eid.Unpack();\n"
        << "  if (std::holds_alternative<" << base_name << "Id>(vid)) {\n";

    if (base_name == class_name) {
      lib_cpp_os
          << "    return index." << lower_name << "(eid.Pack());\n";
    } else {
      lib_cpp_os
          << "    if (auto base = index." << lower_name << "(eid.Pack())) {\n"
          << "      return from_base(base.value());\n"
          << "    }\n";
    }

    lib_cpp_os
        << "  } else if (std::holds_alternative<InvalidId>(vid)) {\n"
        << "    assert(eid.Pack() == kInvalidEntityId);\n"
        << "  }\n"
        << "  return std::nullopt;\n"
        << "}\n\n";

    if (class_name == base_name) {
      lib_cpp_os
          << "gap::generator<" << base_name << "> " << base_name
          << "::in(const Index &index) {\n"
          << "  const EntityProviderPtr ep = entity_provider_of(index);\n"
          << "  for (" << base_name << "ImplPtr eptr : ep->"
          << base_name << "sFor(ep)) {\n"
          << "    co_yield " << base_name << "(std::move(eptr));\n"
          << "  }\n"
          << "}\n\n"
          << "gap::generator<" << base_name << "> " << base_name
          << "::in(const Index &index, std::span<const " << base_name << "Kind> kinds) {\n"
          << "  const EntityProviderPtr ep = entity_provider_of(index);\n"
          << "  for (" << base_name << "Kind k : kinds) {\n"
          << "    for (" << base_name << "ImplPtr eptr : ep->"
          << base_name << "sFor(ep, k)) {\n"
          << "      co_yield " << base_name << "(std::move(eptr));\n"
          << "    }\n"
          << "  }\n"
          << "}\n\n";

      if (!is_type) {
        lib_cpp_os
            << "gap::generator<" << base_name << "> " << base_name
            << "::in(const File &file) {\n"
            << "  const EntityProviderPtr ep = entity_provider_of(file);\n"
            << "  PackedFileId file_id = file.id();\n"
            << "  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {\n"
            << "    for (" << base_name << "ImplPtr eptr : ep->"
            << base_name << "sFor(ep, frag_id)) {\n"
            << "      co_yield " << base_name << "(std::move(eptr));\n"
            << "    }\n"
            << "  }\n"
            << "}\n\n"
            << "gap::generator<" << base_name << "> " << base_name
            << "::in(const Fragment &frag) {\n"
            << "  const EntityProviderPtr ep = entity_provider_of(frag);\n"
            << "  PackedFragmentId frag_id = frag.id();\n"
            << "  for (" << base_name << "ImplPtr eptr : ep->"
            << base_name << "sFor(ep, frag_id)) {\n"
            << "    co_yield " << base_name << "(std::move(eptr));\n"
            << "  }\n"
            << "}\n\n"
            << "gap::generator<" << base_name << "> " << base_name
            << "::in(const Fragment &frag, std::span<const " << base_name << "Kind> kinds) {\n"
            << "  const EntityProviderPtr ep = entity_provider_of(frag);\n"
            << "  PackedFragmentId frag_id = frag.id();\n"
            << "  for (" << base_name << "Kind k : kinds) {\n"
            << "    for (" << base_name << "ImplPtr eptr : ep->"
            << base_name << "sFor(ep, k, frag_id)) {\n"
            << "      co_yield " << base_name << "(std::move(eptr));\n"
            << "    }\n"
            << "  }\n"
            << "}\n\n"
            << "gap::generator<" << base_name << "> " << base_name
            << "::in(const File &file, std::span<const " << base_name << "Kind> kinds) {\n"
            << "  const EntityProviderPtr ep = entity_provider_of(file);\n"
            << "  PackedFileId file_id = file.id();\n"
            << "  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {\n"
            << "    for (" << base_name << "Kind k : kinds) {\n"
            << "      for (" << base_name << "ImplPtr eptr : ep->"
            << base_name << "sFor(ep, k, frag_id)) {\n"
            << "        co_yield " << base_name << "(std::move(eptr));\n"
            << "      }\n"
            << "    }\n"
            << "  }\n"
            << "}\n\n";
      }

    } else {
      // Derived classes have optional conversions that need to account for
      // derived kinds.
      class_os
        << "  static std::optional<" << class_name << "> from_base(const "
        << base_name << " &parent);\n"
        << "  inline static std::optional<" << class_name << "> from(const "
        << base_name << " &parent) {\n"
        << "    return from_base(parent);\n"
        << "  }\n"
        << "  static std::optional<" << class_name
        << "> from(const std::optional<"
        << base_name << "> &parent);\n";

      lib_cpp_os
          << "std::optional<" << class_name << "> " << class_name
          << "::from(const std::optional<"
          << base_name << "> &parent) {\n"
          << "  if (parent) {\n"
          << "    return from_base(parent.value());\n"
          << "  }\n"
          << "  return std::nullopt;\n"
          << "}\n\n"
          << "std::optional<" << class_name << "> " << class_name
          << "::from_base(const " << base_name << " &parent) {\n"
          << "  switch (parent.kind()) {\n";
      for (const ClassHierarchy *c : wl) {
        std::string c_name = c->record.Name();
        if (gConcreteClassNames.count(c_name)) {
          lib_cpp_os << "    case " << c_name << "::static_kind():\n";
        }
      }
      lib_cpp_os
          << "      return reinterpret_cast<const " << class_name << " &>(parent);\n"
          << "    default:\n"
          << "      return std::nullopt;\n"
          << "  }\n"
          << "}\n\n"
          << "gap::generator<" << class_name << "> " << class_name
          << "::in(const Index &index) {\n"
          << "  const EntityProviderPtr ep = entity_provider_of(index);\n"
          << "  for (" << base_name << "Kind k : k" << class_name << "DerivedKinds) {\n"
          << "    for (" << base_name << "ImplPtr eptr : ep->"
          << base_name << "sFor(ep, k)) {\n"
          << "      if (std::optional<" << class_name << "> e = from_base(std::move(eptr))) {\n"
          << "        co_yield std::move(e.value());\n"
          << "      }\n"
          << "    }\n"
          << "  }\n"
          << "}\n\n";

      if (!is_type) {
        lib_cpp_os
            << "gap::generator<" << class_name << "> " << class_name
            << "::in(const Fragment &frag) {\n"
            << "  const EntityProviderPtr ep = entity_provider_of(frag);\n"
            << "  PackedFragmentId frag_id = frag.id();\n"
            << "  for (" << base_name << "Kind k : k" << class_name << "DerivedKinds) {\n"
            << "    for (" << base_name << "ImplPtr eptr : ep->"
            << base_name << "sFor(ep, k, frag_id)) {\n"
            << "      if (std::optional<" << class_name << "> e = from_base(std::move(eptr))) {\n"
            << "        co_yield std::move(e.value());\n"
            << "      }\n"
            << "    }\n"
            << "  }\n"
            << "}\n\n"
            << "gap::generator<" << class_name << "> " << class_name
            << "::in(const File &file) {\n"
            << "  const EntityProviderPtr ep = entity_provider_of(file);\n"
            << "  PackedFileId file_id = file.id();\n"
            << "  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {\n"
            << "    for (" << base_name << "Kind k : k" << class_name << "DerivedKinds) {\n"
            << "      for (" << base_name << "ImplPtr eptr : ep->"
            << base_name << "sFor(ep, k, frag_id)) {\n"
            << "        if (std::optional<" << class_name << "> e = from_base(std::move(eptr))) {\n"
            << "          co_yield std::move(e.value());\n"
            << "        }\n"
            << "      }\n"
            << "    }\n"
            << "  }\n"
            << "}\n\n";
      }
    }
  }

  // Conversions from token contexts and references to entities.
  if (false) {
#define DECLARE_DEFINE_FROM(type_name, lower_name) \
    } else if (class_name == #type_name) { \
      needs_reference = true; \
      forward_decls.insert("Token"); \
      class_os \
          << "  inline static std::optional<" << class_name \
          << "> from(const " << class_name << " &self) {\n" \
          << "    return self;\n" \
          << "  }\n\n" \
          << "  inline static std::optional<" << class_name \
          << "> from(const std::optional<" << class_name \
          << "> &self) {\n" \
          << "    return self;\n" \
          << "  }\n\n" \
          << "  static std::optional<" << class_name \
          << "> from(const Reference &r);\n" \
          << "  static std::optional<" << class_name \
          << "> from(const VariantEntity &e);\n" \
          << "  static std::optional<" << class_name \
          << "> from(const TokenContext &t);\n\n"; \
      \
      lib_cpp_os \
          << "std::optional<" << class_name \
          << "> " << class_name << "::from(const Reference &r) {\n" \
          << "  return r.as_" #lower_name "();\n" \
          << "}\n\n" \
          << "std::optional<" << class_name \
          << "> " << class_name << "::from(const VariantEntity &e) {\n" \
          << "  if (!std::holds_alternative<" << class_name << ">(e)) {\n" \
          << "    return std::nullopt;\n" \
          << "  }\n" \
          << "  return std::get<" << class_name << ">(e);\n" \
          << "}\n\n" \
          << "std::optional<" << class_name \
          << "> " << class_name << "::from(const TokenContext &t) {\n" \
          << "  return t.as_" #lower_name "();\n" \
          << "}\n\n"; \
      \
    } else if (g ## type_name ## Names.count(class_name)) { \
      class_os \
          << "  static std::optional<" << class_name \
          << "> from(const Reference &r);\n" \
          << "  static std::optional<" << class_name \
          << "> from(const VariantEntity &e);\n" \
          << "  static std::optional<" << class_name \
          << "> from(const TokenContext &t);\n\n"; \
      \
      lib_cpp_os \
          << "std::optional<" << class_name \
          << "> " << class_name << "::from(const Reference &r) {\n" \
          << "  return " << class_name << "::from(r.as_" #lower_name "());\n" \
          << "}\n\n" \
          << "std::optional<" << class_name \
          << "> " << class_name << "::from(const VariantEntity &e) {\n" \
          << "  if (!std::holds_alternative<" << base_name << ">(e)) {\n" \
          << "    return std::nullopt;\n" \
          << "  }\n" \
          << "  return from_base(std::get<" \
          << base_name << ">(e));\n" \
          << "}\n\n" \
          << "std::optional<" << class_name \
          << "> " << class_name << "::from(const TokenContext &t) {\n" \
          << "  if (auto base = t.as_" #lower_name "()) {\n" \
          << "    return from_base(base.value());\n" \
          << "  }\n" \
          << "  return std::nullopt;\n" \
          << "}\n\n";

  FOR_EACH_ENTITY_CATEGORY(DECLARE_DEFINE_FROM)
#undef DECLARE_DEFINE_FROM
  }

  auto methods = cls->record.Methods();
  assert(methods);
  for (pasta::CXXMethodDecl method : *methods) {
    if (dont_serialize) {
      continue;
    }

    if (method.NumParameters()) {
      continue;  // Skip methods with parameters.
    }

    auto method_name = method.Name();
    llvm::StringRef method_name_ref(method_name);
    if (method_name == "KindName" ||
        method_name_ref.ends_with("Raw") ||
        method_name_ref.ends_with("Internal") ||
        method_name_ref.starts_with("operator") ||
        method_name_ref.starts_with("~")) {
      continue;  // E.g. `Decl::KindName()`, `operator==`.
    }

    std::string snake_name = CapitalCaseToSnakeCase(method_name);

    // We have a custom implementation of `redeclarations`.
    if (snake_name == "is_this_declarationaration_a_definition") {
      snake_name = "is_definition";

    } else if (snake_name == "is_this_declarationaration_a_demoted_definition") {
      snake_name = "is_demoted_definition";
    
    } else if (snake_name == "kind_name") {
      if (class_name == "TagDecl") {
        snake_name = "tag_kind_name";
      }
    } else if (snake_name == "calculate_inheritance_model") {
      snake_name = "inheritance_model";
    }

    if (snake_name.ends_with("_type_info")) {
      snake_name.pop_back();  // `o`
      snake_name.pop_back();  // `f`
      snake_name.pop_back();  // `n`
      snake_name.pop_back();  // `i`
      snake_name.pop_back();  // `_`.
    }

    if (snake_name.ends_with("type_source_info")) {
      snake_name = snake_name.substr(0, snake_name.size() - 12u);  // Keep `type`.
    }

    if (snake_name.starts_with("type_info_")) {
      snake_name = "type_" + snake_name.substr(10u);
    }

    std::string api_name = SnakeCaseToAPICase(snake_name);

    // Assume we have a vector of this thing, which will make us a `num_*`.
    if (api_name.starts_with("num_") && api_name.ends_with('s')) {
      continue;
    }

    std::pair<std::string, std::string> method_key{class_name, method_name};
    if (kMethodBlackList.count(method_key)) {

      // TODO(pag): `PointeeType` is a different method on a bunch of derived
      //            classes, so we can't black list it on
      if (class_name == "Type" && method_name == "PointeeType") {
        continue;
      }

      (void) seen_methods->emplace(api_name);
      continue;
    }

    if (!seen_methods->emplace(api_name).second) {
      continue;
    }

    std::string camel_name = SnakeCaseToCamelCase(snake_name);

    auto return_type = method.ReturnType().UnqualifiedType();
    if (auto return_type_ref = pasta::ReferenceType::From(return_type)) {
      return_type = return_type_ref->PointeeType().UnqualifiedType();
    }

    if (auto record = return_type.AsRecordDeclaration()) {
      std::string record_name = record->Name();

      // Handle `pasta::Token` and `pasta::FileToken` uniformly. We represent
      // both as references.
      if (record_name == "Token" || record_name == "FileToken" ||
          record_name == "MacroToken") {
        record_name = "Token";

        const auto i = storage.AddMethod("UInt64");  // Reference.
        auto [getter_name, setter_name, init_name] = NamesFor(i);

        serialize_inc_os
            << "  MX_VISIT_ENTITY(" << class_name << ", " << api_name
            << ", " << i << ", MX_APPLY_METHOD, " << method_name
            << ", " << record_name << ", "
            << nth_entity_reader << ")\n";

        class_os
            << "  Token " << api_name << "(void) const;\n";

        lib_cpp_os
            << "Token " << class_name << "::" << api_name
            << "(void) const {\n"
            << "  return impl->ep->TokenFor(impl->ep, impl->reader."
            << getter_name << "());\n"
            << "}\n\n";

        serialize_cpp_os
            << "  auto et" << i << " = es.EntityId(e." << method_name << "());\n";

        // For builtin declarations, we sometimes need to go looking for the
        // token, because it never existed in any parsed representation.
        if (class_name == "Decl" && method_name == "Token") {
          serialize_cpp_os
              << "  if (!et" << i << ") {\n"
              << "    et" << i << " = pf.DeclTokenEntityId(e);\n"
              << "  }\n";
        }

        serialize_cpp_os
            << "  b." << setter_name << "(et" << i << ");\n";

      // Handle `pasta::TokenRange`.
      } else if (record_name == "TokenRange") {
        forward_decls.insert("TokenRange");

        const auto i = storage.AddMethod("UInt64");  // Reference.
        const auto end_i = storage.AddMethod("UInt64");  // Reference.
        auto [begin_getter_name, begin_setter_name, begin_init_name] = NamesFor(i);
        auto [end_getter_name, end_setter_name, end_init_name] = NamesFor(end_i);

        serialize_inc_os
            << "  MX_VISIT_TOKEN_RANGE(" << class_name << ", " << api_name
            << ", " << i << ", " << end_i << ", "
            << nth_entity_reader << ")\n";

        class_os
            << "  TokenRange " << api_name << "(void) const;\n";

        lib_cpp_os
            << "TokenRange " << class_name << "::" << api_name
            << "(void) const {\n"
            << "  return impl->ep->TokenRangeFor(impl->ep, impl->reader."
            << begin_getter_name << "(), impl->reader."
            << end_getter_name << "());\n"
            << "}\n\n";

        serialize_cpp_os
            << "  auto p" << i << " = es.EntityIds(e." << method_name << "());\n"
            << "  b." << begin_setter_name << "(p" << i << ".first);\n"
            << "  b." << end_setter_name << "(p" << i << ".second);\n";

      // Handle `pasta::MacroRange`.
      } else if (record_name == "MacroRange") {
        const auto i = storage.AddMethod("List(UInt64)");  // Reference list.
        auto [getter_name, setter_name, init_name] = NamesFor(i);
        auto cxx_element_name = "MacroOrToken";

        serialize_inc_os
              << "  MX_VISIT_MACRO_RANGE(" << class_name << ", "
              << api_name << ", " << i << ", " << nth_entity_reader << ")\n";

        class_os
            << "  gap::generator<" << cxx_element_name << "> "
            << api_name << "(void) const &;\n";

        lib_cpp_os
            << "gap::generator<" << cxx_element_name << "> "
            << class_name << "::" << api_name
            << "(void) const & {\n"
            << "  Index index(impl->ep);\n"
            << "  auto list = impl->reader." << getter_name << "();\n"
            << "  for (auto v : list) {\n"
            << "    VariantEntity e = index.entity(EntityId(v));\n"
            << "    if (std::holds_alternative<Macro>(e)) {\n"
            << "      co_yield std::move(std::get<Macro>(e));\n"
            << "    } else if (std::holds_alternative<Token>(e)) {\n"
            << "      co_yield std::move(std::get<Token>(e));\n"
            << "    } else {\n"
            << "      assert(false);\n"
            << "    }\n"
            << "  }\n"
            << "}\n\n";

        // If we have a `TokenTree`, then we want to use it for our
        // serialization (e.g. of `Macro::children`).
        if (method_name == "Children" || method_name == "ReplacementChildren" ||
            method_name == "IntermediateChildren") {
          serialize_cpp_os
              << "  if (tt) {\n"
              << "    auto v" << i << " = tt->" << method_name << "();\n"
              << "    auto sv" << i << " = b." << init_name
              << "(static_cast<unsigned>(v" << i << ".size()));\n"
              << "    auto i" << i << " = 0u;\n"
              << "    for (auto n" << i << " : v" << i << ") {\n"
              << "      sv" << i << ".set(i" << i << ", es.EntityId(n" << i
              << ".RawNode()));\n"
              << "      ++i" << i << ";\n"
              << "    }\n"
              << "  } else {\n";
        } else {
          serialize_cpp_os << "  if (true) {\n";
        }
        serialize_cpp_os
            << "    auto v" << i << " = e." << method_name << "();\n"
            << "    auto sv" << i << " = b." << init_name
            << "(static_cast<unsigned>(v" << i << ".size()));\n"
            << "    auto i" << i << " = 0u;\n"
            << "    for (const auto &e" << i << " : v" << i << ") {\n"
            << "      sv" << i << ".set(i" << i << ", es.EntityId(e" << i
            << "));\n"
            << "      ++i" << i << ";\n"
            << "    }\n"
            << "  }\n";

      // Handle `pasta::File`.
      } else if (record_name == "File") {
        const auto i = storage.AddMethod("UInt64");  // Reference.
        auto [getter_name, setter_name, init_name] = NamesFor(i);

        serialize_inc_os
            << "  MX_VISIT_ENTITY(" << class_name << ", " << api_name
            << ", " << i << ", MX_APPLY_METHOD, " << method_name
            << ", " << record_name << ", "
            << nth_entity_reader << ")\n";

        class_os
            << "  File " << api_name << "(void) const;\n";

        lib_cpp_os
            << "File " << class_name << "::" << api_name
            << "(void) const {\n"
            << "  auto &ep = impl->ep;\n"
            << "  auto file = ep->FileFor(ep, impl->reader."
            << getter_name << "());\n"
            << "  return File(std::move(file));\n"
            << "}\n\n";

        serialize_cpp_os
            << "  auto f" << i << " = e." << method_name << "();\n"
            << "  b." << setter_name << "(es.EntityId(f" << i << "));\n";

      // Handle `std::string`
      } else if (record_name == "string" || record_name == "basic_string") {

        const auto i = storage.AddMethod("Text");
        auto [getter_name, setter_name, init_name] = NamesFor(i);

        serialize_inc_os
            << "  MX_VISIT_TEXT(" << class_name << ", " << api_name
            << ", " << i << ", MX_APPLY_METHOD, " << method_name << ", "
            << record_name << ", " << nth_entity_reader << ")\n";

        class_os
            << "  std::string_view " << api_name << "(void) const;\n";

        lib_cpp_os
            << "std::string_view " << class_name << "::" << api_name
            << "(void) const {\n"
            << "  capnp::Text::Reader data = impl->reader." << getter_name
            << "();\n"
            << "  return std::string_view(data.cStr(), data.size());\n"
            << "}\n\n";

        serialize_cpp_os
            << "  b." << setter_name << "(e." << method_name << "());\n";

      // Handle `std::string_view`. Cap'n Proto requires that `:Text` fields
      // are `NUL`-terminated, so we convert the string view into a
      // `std::string`.
      } else if (record_name == "string_view" ||
                 record_name == "basic_string_view") {

        const auto i = storage.AddMethod("Text");
        auto [getter_name, setter_name, init_name] = NamesFor(i);

        serialize_inc_os
            << "  MX_VISIT_TEXT(" << class_name << ", " << api_name
            << ", " << i << ", MX_APPLY_METHOD, " << method_name << ", "
            << record_name << ", " << nth_entity_reader << ")\n";

        class_os
            << "  std::string_view " << api_name << "(void) const;\n";

        lib_cpp_os
            << "std::string_view " << class_name << "::" << api_name
            << "(void) const {\n"
            << "  capnp::Text::Reader data = impl->reader." << getter_name
            << "();\n"
            << "  return std::string_view(data.cStr(), data.size());\n"
            << "}\n\n";

        serialize_cpp_os
            << "  auto v" << i << " = e." << method_name << "();\n"
            << "  std::string s" << i << "(v" << i << ".data(), v"
            << i << ".size());\n  b." << setter_name << "(s" << i << ");\n";

      // In pasta.
      } else if (record_name == "ArgumentVector") {
        std::cerr << "!!! ArgumentVector\n";
        abort();

      // Probably `std::filesystem::path`.
      } else if (record_name == "path") {

        const auto i = storage.AddMethod("Text");
        auto [getter_name, setter_name, init_name] = NamesFor(i);

        serialize_inc_os
            << "  MX_VISIT_PATH(" << class_name << ", " << api_name
            << ", " << i << ", MX_APPLY_METHOD, " << method_name << ", "
            << record_name << ", " << nth_entity_reader << ")\n";

        class_os
            << "  std::filesystem::path " << api_name << "(void) const;\n";

        lib_cpp_os
            << "std::filesystem::path " << class_name << "::" << api_name
            << "(void) const {\n"
            << "  capnp::Text::Reader data = impl->reader." << getter_name
            << "();\n"
            << "  return data.cStr();\n"
            << "}\n\n";

        serialize_cpp_os
            << "  b." << setter_name << "(e." << method_name
            << "().lexically_normal().generic_string());\n";

      // For optionals, we generally represent them as the thing itself, as well
      // as a `*IsPresent` bool parameter. Cap'n Proto can represent optionals
      // with `union`s, but those require an additional 16 bits of storage for
      // the union tag, and the size of the union is the size of its largest
      // member, so the extra `bool` just means 1 bit of overhead.
      } else if (record_name == "optional") {
        RunOnOptional(class_os, cls, storage, record, class_name, api_name,
                      method_name, nth_entity_reader, base_name,
                      seen_methods);

      // List of things; figure out what.
      } else if (record_name == "vector") {
        RunOnVector(class_os, storage, record, class_name, api_name,
                    method_name, nth_entity_reader, false, base_name,
                    seen_methods);

      // E.g. something that returns a `Decl`, `Stmt`, etc.
      } else if (gEntityClassNames.count(record_name)) {
        if (gUnserializableTypes.count(record_name)) {
          continue;
        }

        const auto i = storage.AddMethod("UInt64");
        auto [getter_name, setter_name, init_name] = NamesFor(i);
        forward_decls.insert(record_name);

        class_os
            << "  " << record_name << " " << api_name
            << "(void) const;\n";

        serialize_cpp_os
            << "  b." << setter_name << "(es.EntityId(e." << method_name
            << "()));\n";

        lib_cpp_os
            << record_name << " " << class_name << "::" << api_name
            << "(void) const {\n"
            << "  RawEntityId eid = impl->reader." << getter_name
            << "();\n";

        if (false) {
#define GET_ENTITY(name, lower_name) \
        } else if (record_name == #name) { \
          lib_cpp_os \
              << "  return " #name "(impl->ep->" #name "For(impl->ep, eid));\n"; \
        \
        } else if (g ## name ## Names.count(record_name)) { \
          lib_cpp_os \
              << "  return " << record_name \
              << "::from_base(impl->ep->" #name "For(impl->ep, eid)).value();\n";

        GET_ENTITY(File, file)
        FOR_EACH_ENTITY_CATEGORY(GET_ENTITY)
#undef GET_ENTITY

        } else {
          std::cerr << "??? record " << record_name << '\n';
          abort();
        }

        serialize_inc_os
            << "  MX_VISIT_ENTITY(" << class_name << ", " << api_name
            << ", " << i << ", MX_APPLY_METHOD, " << method_name << ", "
            << record_name << ", " << nth_entity_reader << ")\n";

        lib_cpp_os
            << "}\n\n";

      } else if (gNotReferenceTypesRelatedToEntities.count(record_name)) {
        abort();

      } else if (gNotReferenceTypes.count(record_name)) {
        std::cerr << "unhandled record " << record_name << "\n";
        abort();
      }

    // Handle enumerations return types.
    } else if (auto tag = return_type.AsTagDeclaration()) {
      if (auto enum_decl = pasta::EnumDecl::From(*tag)) {

        std::string enum_name = enum_decl->Name();
        std::pair<const char *, const char *> types = enum_type[enum_name];

        const auto i = storage.AddMethod(types.second);
        auto [getter_name, setter_name, init_name] = NamesFor(i);

        needed_decls.insert(enum_name);
        serialize_inc_os
            << "  MX_VISIT_ENUM(" << class_name << ", " << api_name
            << ", " << i << ", MX_APPLY_METHOD, " << method_name << ", "
            << enum_name << ", " << nth_entity_reader << ")\n";

        class_os
            << "  " << enum_name << " " << api_name
            << "(void) const;\n";

        lib_cpp_os
            << enum_name << " " << class_name << "::" << api_name
            << "(void) const {\n"
            << "  return static_cast<" << enum_name << ">(impl->reader."
            << getter_name << "());\n"
            << "}\n\n";

        // Take the kind from the `TokenTree` if we have it.
        if (is_macro && api_name == "kind") {
          serialize_cpp_os
              << "  if (tt) {\n"
              << "    b." << setter_name << "(static_cast<"
              << types.first << ">(tt->Kind()));\n"
              << "  } else {\n"
              << "    b." << setter_name
              << "(static_cast<" << types.first << ">(mx::FromPasta(e.Kind())));\n"
              << "  }\n";

        } else {
          serialize_cpp_os
              << "  b." << setter_name
              << "(static_cast<" << types.first << ">(mx::FromPasta(e."
              << method_name << "())));\n";
        }
      }

    // Handle integral return types.
    } else if (auto int_type = SchemaIntType(return_type)) {

      std::string cxx_int_type = CxxIntType(return_type);
      const auto i = storage.AddMethod(int_type);
      auto [getter_name, setter_name, init_name] = NamesFor(i);

      if (cxx_int_type == "bool") {
        serialize_inc_os
            << "  MX_VISIT_BOOL(" << class_name << ", " << api_name
            << ", " << i << ", MX_APPLY_METHOD, " << method_name << ", "
            << cxx_int_type << ", " << nth_entity_reader << ")\n";
      } else {
        serialize_inc_os
            << "  MX_VISIT_INT(" << class_name << ", " << api_name
            << ", " << i << ", MX_APPLY_METHOD, " << method_name << ", "
            << cxx_int_type << ", " << nth_entity_reader << ")\n";
      }

      class_os
          << "  " << cxx_int_type << " " << api_name
          << "(void) const;\n";

      lib_cpp_os
          << cxx_int_type << " " << class_name << "::" << api_name
          << "(void) const {\n"
          << "  return impl->reader." << getter_name << "();\n"
          << "}\n\n";

      serialize_cpp_os
          << "  b." << setter_name << "(e." << method_name << "());\n";
    }
  }

  // If this is a `DeclContext`, then try to add the `DeclarationsInContext`
  // method.
  if (kDeclContextTypes.count(class_name) &&
      !gSpecialDeclContexts.count(class_name)) {
    static const std::string method_name = "DeclarationsInContext";
    static const std::string snake_name = "declarations_in_context";
    static const std::string api_name = SnakeCaseToAPICase(snake_name);
    if (seen_methods->emplace(api_name).second) {

      const auto i = storage.AddMethod("List(UInt64)");
      auto [getter_name, setter_name, init_name] = NamesFor(i);

//      static const std::string camel_name = "declarationsInContext";

      serialize_inc_os
          << "  MX_VISIT_DECL_CONTEXT(" << class_name << ", " << api_name
          << ", " << i << ", MX_APPLY_FUNC, DeclarationsInDeclContext, Decl, "
          << nth_entity_reader << ")\n";

      class_os
          << "  gap::generator<Decl> " << api_name << "(void) const &;\n";

      lib_cpp_os
          << "gap::generator<Decl> "
          << class_name << "::" << api_name
          << "(void) const & {\n"
          << "  EntityProviderPtr ep = impl->ep;\n"
          << "  auto list = impl->reader." << getter_name << "();\n"
          << "  for (auto v : list) {\n"
          << "    if (auto eptr = ep->DeclFor(ep, v)) {\n"
          << "      co_yield std::move(eptr);\n"
          << "    }\n"
          << "  }\n"
          << "}\n\n";

      serialize_cpp_os
          << "  pasta::DeclContext dc" << i << "(e);\n"
          << "  auto v" << i << " = DeclarationsInDeclContext(dc" << i << ");\n"
          << "  auto sv" << i << " = b." << init_name << "(static_cast<unsigned>(v"
          << i << ".size()));\n"
          << "  auto i" << i << " = 0u;\n"
          << "  for (const pasta::Decl &e" << i << " : v" << i << ") {\n"
          << "    sv" << i << ".set(i" << i << ", es.EntityId(e" << i << "));\n"
          << "    ++i" << i << ";\n"
          << "  }\n";
    }
  }

  // Additional special methods for specific derived classes go here

  if (class_name == "CXXRecordDecl") {
    class_os
        << "  // List of base and derived classes.\n"
        << "  gap::generator<CXXRecordDecl> derived_classes(void) const &;\n"
        << "  gap::generator<CXXRecordDecl> base_classes(void) const &;\n";
  }

  if (class_name == "CXXMethodDecl") {
    class_os
        << "  // List of methods that can override this method.\n"
        << "  gap::generator<CXXMethodDecl> overridden_by_methods(void) const &;\n"
        << "  gap::generator<CXXMethodDecl> transitive_overridden_by_methods(void) const &;\n";
  }

  // `FunctionDecl::callers`.
  if (class_name == "FunctionDecl") {
    class_os
        << "  // Callers of a `FunctionDecl` can be `CallExpr`, `CxxNewExpr`,\n"
        << "  // `CxxConstructExpr`, etc. Even `CastExpr` can sometimes be a call\n"
        << "  // if it needs to invoke a function call to perform the conversion.\n"
        << "  gap::generator<Stmt> callers(void) const &;\n";
  }

  // Allows CallExpr to conveniently get post-cast types if exists
  if (class_name == "CallExpr") {
    forward_decls.insert("Type");
    forward_decls.insert("CastExpr");
    class_os
        << "  std::optional<Type> casted_return_type(void) const;\n"
        << "  std::optional<CastExpr> casted_return_value(void) const;\n";
  }

  class_os << "};\n\n";

  for (auto needed : needed_decls) {
    if (gFrontendTypes.count(needed)) {
      os << "#include <multiplier/Frontend/" << needed << ".h>\n";
    } else {
      os << "#include <multiplier/AST/" << needed << ".h>\n"; 
    }
  }
  os
      << "\nnamespace mx {\n"
      << "class EntityProvider;\n"
      << "class Fragment;\n"
      << "class Index;\n";

  if (needs_reference) {
    os << "class Reference;\n";
  }

  // Forward declare impl types.
  for (auto fwd : forward_decls) {
    os << "class " << fwd << ";\n"; 
  }

  os
      << "namespace ir {\n"
      << "class Operation;\n"
      << "class Value;\n"
      << "}  // namespace ir\n\n"
      << "#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)\n"
      << class_os.str()
      << late_class_os.str()
      << "#endif\n"
      << "} // namespace mx\n";

  serialize_cpp_os << "}\n\n";

  serialize_inc_os
      << "  MX_EXIT_VISIT_" << class_name << "\n"
      << end_serializer << "(" << class_name << ")\n\n";

  late_serialize_inc_os
      << "#undef MX_ENTER_VISIT_" << class_name << "\n"
      << "#undef MX_EXIT_VISIT_" << class_name << "\n";

  return seen_methods;
}

void CodeGenerator::RunOnClassHierarchies(void) {

  std::vector<std::pair<ClassHierarchy *, std::shared_ptr<MethodList>>>
      work_list;

  auto empty_list = std::make_shared<MethodList>();
  for (ClassHierarchy *root : roots) {
    if (root->record.Name() == "File") {
      continue;
    }
    work_list.emplace_back(root, empty_list);
  }

  schema_os
      << "# Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "# All rights reserved.\n"
      << "#\n"
      << "# This source code is licensed in accordance with the terms specified in\n"
      << "# the LICENSE file found in the root directory of this source tree.\n\n"
      << "# Auto-generated file; do not modify!\n\n"
      << "@0xa04be7b45e95b659;\n\n"
      << "using Cxx = import \"/capnp/c++.capnp\";\n"
      << "$Cxx.namespace(\"mx::ast\");\n\n";

  lib_pasta_cpp_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#include \"PASTA.h\"\n\n"
      << "#include <multiplier/AST.h>\n"
      << "#include <multiplier/Frontend.h>\n\n"
      << "namespace mx {\n";

  serialize_inc_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#ifndef MX_APPLY_METHOD\n"
      << "#  define MX_APPLY_METHOD(obj, meth) obj.meth()\n"
      << "#endif\n"
      << "#ifndef MX_APPLY_FUNC\n"
      << "#  define MX_APPLY_FUNC(obj, meth) meth(obj)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_BOOL\n"
      << "#  define MX_VISIT_BOOL(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_INT\n"
      << "#  define MX_VISIT_INT(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_ENUM\n"
      << "#  define MX_VISIT_ENUM(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_TEXT\n"
      << "#  define MX_VISIT_TEXT(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_PATH\n"
      << "#  define MX_VISIT_PATH(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_BOOL\n"
      << "#  define MX_VISIT_OPTIONAL_BOOL(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_INT\n"
      << "#  define MX_VISIT_OPTIONAL_INT(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_ENUM\n"
      << "#  define MX_VISIT_OPTIONAL_ENUM(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_TEXT\n"
      << "#  define MX_VISIT_OPTIONAL_TEXT(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_PATH\n"
      << "#  define MX_VISIT_OPTIONAL_PATH(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_BOOL_LIST\n"
      << "#  define MX_VISIT_BOOL_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_INT_LIST\n"
      << "#  define MX_VISIT_INT_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_ENUM_LIST\n"
      << "#  define MX_VISIT_ENUM_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_TEXT_LIST\n"
      << "#  define MX_VISIT_TEXT_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_PATH_LIST\n"
      << "#  define MX_VISIT_PATH_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_BOOL_LIST\n"
      << "#  define MX_VISIT_OPTIONAL_BOOL_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_INT_LIST\n"
      << "#  define MX_VISIT_OPTIONAL_INT_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_ENUM_LIST\n"
      << "#  define MX_VISIT_OPTIONAL_ENUM_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_TEXT_LIST\n"
      << "#  define MX_VISIT_OPTIONAL_TEXT_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_PATH_LIST\n"
      << "#  define MX_VISIT_OPTIONAL_PATH_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_ENTITY\n"
      << "#  define MX_VISIT_ENTITY(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_ENTITY\n"
      << "#  define MX_VISIT_OPTIONAL_ENTITY(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_ENTITY_LIST\n"
      << "#  define MX_VISIT_ENTITY_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_ENTITY_LIST\n"
      << "#  define MX_VISIT_OPTIONAL_ENTITY_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_DECL_CONTEXT\n"
      << "#  define MX_VISIT_DECL_CONTEXT(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_TOKEN_RANGE\n"
      << "#  define MX_VISIT_TOKEN_RANGE(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_MACRO_RANGE\n"
      << "#  define MX_VISIT_MACRO_RANGE(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_PSEUDO\n"
      << "#  define MX_VISIT_PSEUDO(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_PSEUDO\n"
      << "#  define MX_VISIT_OPTIONAL_PSEUDO(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_OPTIONAL_PSEUDO_LIST\n"
      << "#  define MX_VISIT_OPTIONAL_PSEUDO_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_PSEUDO_LIST\n"
      << "#  define MX_VISIT_PSEUDO_LIST(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_BASE\n"
      << "#  define MX_VISIT_BASE(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_DECL_LINK\n"
      << "#  define MX_VISIT_DECL_LINK(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_STMT_LINK\n"
      << "#  define MX_VISIT_STMT_LINK(...)\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_DECL\n"
      << "#  define MX_BEGIN_VISIT_DECL(...)\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_STMT\n"
      << "#  define MX_BEGIN_VISIT_STMT(...)\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_TYPE\n"
      << "#  define MX_BEGIN_VISIT_TYPE(...)\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_ATTR\n"
      << "#  define MX_BEGIN_VISIT_ATTR(...)\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_MACRO\n"
      << "#  define MX_BEGIN_VISIT_MACRO(...)\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_ABSTRACT_DECL\n"
      << "#  define MX_BEGIN_VISIT_ABSTRACT_DECL MX_BEGIN_VISIT_DECL\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_ABSTRACT_STMT\n"
      << "#  define MX_BEGIN_VISIT_ABSTRACT_STMT MX_BEGIN_VISIT_STMT\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_ABSTRACT_TYPE\n"
      << "#  define MX_BEGIN_VISIT_ABSTRACT_TYPE MX_BEGIN_VISIT_TYPE\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_ABSTRACT_ATTR\n"
      << "#  define MX_BEGIN_VISIT_ABSTRACT_ATTR MX_BEGIN_VISIT_ATTR\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_ABSTRACT_MACRO\n"
      << "#  define MX_BEGIN_VISIT_ABSTRACT_MACRO MX_BEGIN_VISIT_MACRO\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_VISIT_PSEUDO\n"
      << "#  define MX_BEGIN_VISIT_PSEUDO(...)\n"
      << "#endif\n"
      << "#ifndef MX_END_VISIT_DECL\n"
      << "#  define MX_END_VISIT_DECL(...)\n"
      << "#endif\n"
      << "#ifndef MX_END_VISIT_STMT\n"
      << "#  define MX_END_VISIT_STMT(...)\n"
      << "#endif\n"
      << "#ifndef MX_END_VISIT_TYPE\n"
      << "#  define MX_END_VISIT_TYPE(...)\n"
      << "#endif\n"
      << "#ifndef MX_END_VISIT_ATTR\n"
      << "#  define MX_END_VISIT_ATTR(...)\n"
      << "#endif\n"
      << "#ifndef MX_END_VISIT_MACRO\n"
      << "#  define MX_END_VISIT_MACRO(...)\n"
      << "#endif\n"
      << "#ifndef MX_END_VISIT_PSEUDO\n"
      << "#  define MX_END_VISIT_PSEUDO(...)\n"
      << "#endif\n"
      << "#ifndef MX_VISIT_PSEUDO_KIND\n"
      << "#  define MX_VISIT_PSEUDO_KIND(...)\n"
      << "#endif\n"
      << "#ifndef MX_BEGIN_ENUM_CLASS\n"
      << "#  define MX_BEGIN_ENUM_CLASS(...)\n"
      << "#endif\n"
      << "#ifndef MX_ENUM_CLASS_ENTRY\n"
      << "#  define MX_ENUM_CLASS_ENTRY(...)\n"
      << "#endif\n"
      << "#ifndef MX_END_ENUM_CLASS\n"
      << "#  define MX_END_ENUM_CLASS(...)\n"
      << "#endif\n"
      << "\n";

  serialize_h_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "#include <cstdint>\n"
      << "#include <multiplier/AST.capnp.h>\n"
      << "#include <optional>\n\n"
      << "namespace pasta {\n";

  serialize_cpp_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#include \"Serialize.h\"\n\n"
      << "#include <multiplier/RPC.capnp.h>\n"
      << "#include <pasta/AST/Attr.h>\n"
      << "#include <pasta/AST/Decl.h>\n"
      << "#include <pasta/AST/Macro.h>\n"
      << "#include <pasta/AST/Stmt.h>\n"
      << "#include <pasta/AST/Type.h>\n"
      << "#include <pasta/Compile/Command.h>\n"
      << "#include <pasta/Compile/Compiler.h>\n"
      << "#include <pasta/Compile/Job.h>\n"
      << "#include <pasta/Util/ArgumentVector.h>\n\n"
      << "#include <glog/logging.h>\n"
      << "#include \"Entity.h\"\n"
      << "#include \"EntityMapper.h\"\n"
      << "#include \"PASTA.h\"\n"
      << "#include \"References.h\"\n"
      << "#include \"PendingFragment.h\"\n"
      << "#include \"TokenTree.h\"\n"
      << "#include \"Util.h\"\n"
      << "namespace indexer {\n\n"
      << "#pragma GCC diagnostic push\n"
      << "#pragma GCC diagnostic ignored \"-Wuseless-cast\"\n\n";

  ast_h_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n";

  frontend_h_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "#include \"Frontend/Compilation.h\"\n"
      << "#include \"Frontend/File.h\"\n"
      << "#include \"Frontend/Token.h\"\n"
      << "#include \"Frontend/TokenTree.h\"\n"
      << "#include \"Frontend/Query.h\"\n\n";

  lib_pasta_h_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "#include <cstdint>\n\n"
      << "namespace pasta {\n"
      << "class File;\n";

  // Forward declarations.
#define DECLARE_ENTITY_CLASSES(name, lower_name) \
    for (const pasta::CXXRecordDecl &record : lower_name ## s) { \
      serialize_h_os << "class " << record.Name() << ";\n"; \
    }

  FOR_EACH_ENTITY_CATEGORY(DECLARE_ENTITY_CLASSES)
#undef DECLARE_ENTITY_CLASSES

  for (const pasta::EnumDecl &tag : enums) {
    if (auto itype = tag.IntegerType()) {
      auto ptr = pasta::PrintedTokenRange::Create(itype.value());
      serialize_h_os << "enum class " << tag.Name() << " :";
      lib_pasta_h_os << "enum class " << tag.Name() << " :";
      for (auto tok : ptr) {
        serialize_h_os << ' ' << tok.Data();
        lib_pasta_h_os << ' ' << tok.Data();    
      }
      serialize_h_os << ";\n";
      lib_pasta_h_os << ";\n";
    } else {
      serialize_h_os << "enum class " << tag.Name() << " : int;\n";
      lib_pasta_h_os << "enum class " << tag.Name() << " : int;\n";
    }
  }
  serialize_h_os
      << "}  // namespace pasta\n"
      << "namespace indexer {\n";
  lib_pasta_h_os
      << "}  // namespace pasta\n"
      << "namespace mx {\n";

  std::vector<std::string> class_names;

  for (const pasta::EnumDecl &tag : enums) {
    std::string enum_name = tag.Name();
    if (enum_name == "PPKeywordKind") {
      pp_keyword_kinds = tag;
    } else if (enum_name == "ObjCKeywordKind") {
      objc_at_keywords = tag;
    }
  }

  auto end_libcpp_os = [&] (std::string name, bool is_root, bool is_enum) {
    auto dir_name = gFrontendTypes.count(name) ? "Frontend" : "AST";

    std::ofstream fs(lib_dir / dir_name / (name + ".cpp"),
                     std::ios::trunc | std::ios::out);

    fs
        << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
        << "// All rights reserved.\n"
        << "//\n"
        << "// This source code is licensed in accordance with the terms specified in\n"
        << "// the LICENSE file found in the root directory of this source tree.\n\n"
        << "// Auto-generated file; do not modify!\n\n"
        << "#include <multiplier/" << dir_name << '/' << name << ".h>\n";

    if (needs_reference) {
      fs << "#include <multiplier/Reference.h>\n";
    }

    auto needs_fragment = is_root;
    for (const std::string &other_name : forward_decls) {
      if (other_name == "TokenRange") {
        needs_fragment = true;
      } else if (name != other_name && !other_name.ends_with("Impl")) {
        if (gFrontendTypes.count(other_name)) {
          fs << "#include <multiplier/Frontend/" << other_name << ".h>\n";
        } else {
          fs << "#include <multiplier/AST/" << other_name << ".h>\n";
        }
      }
    }

    for (const std::string &derived_name : derived_decls) {
      if (name != derived_name) {
        if (gFrontendTypes.count(derived_name)) {
          fs << "#include <multiplier/Frontend/" << derived_name << ".h>\n";
        } else {
          fs << "#include <multiplier/AST/" << derived_name << ".h>\n";
        }
      }
    }

    if (gDeclNames.count(name) || gStmtNames.count(name)) {
      fs << "\n#include <multiplier/IR/HighLevel/Operation.h>\n"; 
    }

    if (!is_enum) {
      fs << "\n#include \"../EntityProvider.h\"\n";
    }
    if (is_root) {
      fs << "#include \"../File.h\"\n";
    }
    if (needs_fragment) {
      fs << "#include \"../Fragment.h\"\n";
    }

#define INCLUDE_BASE_KIND(name_, lower_name_) \
    if (g ## name_ ## Names.count(name)) { \
      fs << "#include \"../" #name_ ".h\"\n\n"; \
    }

  FOR_EACH_ENTITY_CATEGORY(INCLUDE_BASE_KIND)
#undef INCLUDE_BASE_KIND

    fs
        << "namespace mx {\n"
        << "#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)\n"
        << "#pragma GCC diagnostic push\n"
        << "#pragma GCC diagnostic ignored \"-Wuseless-cast\"\n\n"
        << lib_cpp_os.str()
        << "#pragma GCC diagnostic pop\n"
        << "#endif\n"
        << "}  // namespace mx\n";

    std::stringstream ss;
    lib_cpp_os.swap(ss);
  };

  for (const pasta::EnumDecl &tag : enums) {
    if (auto itype = CxxIntType(tag.IntegerType())) {
      if (RunOnEnum(tag)) {
        end_libcpp_os(tag.Name(), false, true);
      }
    }
  }

  serialize_h_os
      << "class EntityMapper;\n"
      << "class PendingFragment;\n"
      << "class TokenTree;\n";

  // Forward declarations.
#define DECLARE_ENTITY_SERIALIZERS(type_name, lower_name) \
    for (const pasta::CXXRecordDecl &record : lower_name ## s) { \
      std::string name = record.Name(); \
      serialize_h_os \
          << "void Serialize" << name \
          << "(const PendingFragment &, const EntityMapper &, mx::ast::" #type_name \
          << "::Builder, const pasta::" << name \
          << " &, const TokenTree *);\n"; \
    }

  FOR_EACH_ENTITY_CATEGORY(DECLARE_ENTITY_SERIALIZERS)
#undef DECLARE_ENTITY_SERIALIZERS
  
  while (!work_list.empty()) {
    auto [cls, parent_methods] = work_list.back();
    work_list.pop_back();

    auto seen_methods = RunOnClass(cls, std::move(parent_methods));
    end_libcpp_os(cls->record.Name(), cls->base == nullptr, false);

    for (auto derived_cls : cls->derived) {
      work_list.emplace_back(derived_cls, seen_methods);
    }

    // Collect class names for `EntityList`.
    auto class_name = cls->record.Name();
  }

  auto i = 0u;

#define DEFINE_PROTO(name, lower_name) \
    schema_os << NameAndHash("struct " #name ) << "{\n"; \
    i = 0u; \
    for (const auto &[type, ids] : \
             root_ ## lower_name ## _storage.max_method_count) { \
      for (auto id : ids) { \
        schema_os << "  val" << id << " @" << (i++) << " :" << type << ";\n";\
      } \
    } \
    schema_os << "}\n\n";

  FOR_EACH_ENTITY_CATEGORY(DEFINE_PROTO)
#undef DEFINE_PROTO

  serialize_inc_os
      << late_serialize_inc_os.str()
      << "#undef MX_APPLY_METHOD\n"
      << "#undef MX_APPLY_FUNC\n"
      << "#undef MX_VISIT_BOOL\n"
      << "#undef MX_VISIT_INT\n"
      << "#undef MX_VISIT_ENUM\n"
      << "#undef MX_VISIT_TEXT\n"
      << "#undef MX_VISIT_PATH\n"
      << "#undef MX_VISIT_OPTIONAL_BOOL\n"
      << "#undef MX_VISIT_OPTIONAL_INT\n"
      << "#undef MX_VISIT_OPTIONAL_ENUM\n"
      << "#undef MX_VISIT_OPTIONAL_TEXT\n"
      << "#undef MX_VISIT_OPTIONAL_PATH\n"
      << "#undef MX_VISIT_BOOL_LIST\n"
      << "#undef MX_VISIT_INT_LIST\n"
      << "#undef MX_VISIT_ENUM_LIST\n"
      << "#undef MX_VISIT_TEXT_LIST\n"
      << "#undef MX_VISIT_PATH_LIST\n"
      << "#undef MX_VISIT_OPTIONAL_BOOL_LIST\n"
      << "#undef MX_VISIT_OPTIONAL_INT_LIST\n"
      << "#undef MX_VISIT_OPTIONAL_ENUM_LIST\n"
      << "#undef MX_VISIT_OPTIONAL_TEXT_LIST\n"
      << "#undef MX_VISIT_OPTIONAL_PATH_LIST\n"
      << "#undef MX_VISIT_ENTITY\n"
      << "#undef MX_VISIT_ENTITY_LIST\n"
      << "#undef MX_VISIT_OPTIONAL_ENTITY\n"
      << "#undef MX_VISIT_OPTIONAL_ENTITY_LIST\n"
      << "#undef MX_VISIT_DECL_CONTEXT\n"
      << "#undef MX_VISIT_TOKEN_RANGE\n"
      << "#undef MX_VISIT_MACRO_RANGE\n"
      << "#undef MX_VISIT_PSEUDO\n"
      << "#undef MX_VISIT_PSEUDO_LIST\n"
      << "#undef MX_VISIT_OPTIONAL_PSEUDO\n"
      << "#undef MX_VISIT_OPTIONAL_PSEUDO_LIST\n"
      << "#undef MX_VISIT_BASE\n"
      << "#undef MX_VISIT_DECL_LINK\n"
      << "#undef MX_VISIT_STMT_LINK\n"
      << "#undef MX_BEGIN_VISIT_DECL\n"
      << "#undef MX_BEGIN_VISIT_STMT\n"
      << "#undef MX_BEGIN_VISIT_TYPE\n"
      << "#undef MX_BEGIN_VISIT_ATTR\n"
      << "#undef MX_BEGIN_VISIT_MACRO\n"
      << "#undef MX_BEGIN_VISIT_ABSTRACT_DECL\n"
      << "#undef MX_BEGIN_VISIT_ABSTRACT_STMT\n"
      << "#undef MX_BEGIN_VISIT_ABSTRACT_TYPE\n"
      << "#undef MX_BEGIN_VISIT_ABSTRACT_ATTR\n"
      << "#undef MX_BEGIN_VISIT_ABSTRACT_MACRO\n"
      << "#undef MX_BEGIN_VISIT_PSEUDO\n"
      << "#undef MX_VISIT_PSEUDO_KIND\n"
      << "#undef MX_END_VISIT_DECL\n"
      << "#undef MX_END_VISIT_STMT\n"
      << "#undef MX_END_VISIT_TYPE\n"
      << "#undef MX_END_VISIT_ATTR\n"
      << "#undef MX_END_VISIT_MACRO\n"
      << "#undef MX_END_VISIT_PSEUDO\n"
      << "#undef MX_BEGIN_ENUM_CLASS\n"
      << "#undef MX_ENUM_CLASS_ENTRY\n"
      << "#undef MX_END_ENUM_CLASS\n";

  lib_pasta_h_os << "}  // namespace mx\n";
  lib_pasta_cpp_os << "}  // namespace mx\n";
  serialize_h_os << "}  // namespace indexer\n";
  serialize_cpp_os
      << "#pragma GCC diagnostic pop\n"
      << "}  // namespace indexer\n";
}

void CodeGenerator::RunOnClasses(void) {
  std::vector<std::unique_ptr<ClassHierarchy>> alloc;

  // Make class hierarchies.
#define BUILD_HIERARCHY(name, lower_name) \
    ClassHierarchy::Build(alloc, lower_name ## s, roots);

  FOR_EACH_ENTITY_CATEGORY(BUILD_HIERARCHY)
#undef BUILD_HIERARCHY

  RunOnClassHierarchies();
}

int CodeGenerator::RunOnNamespaces(void) {
  for (pasta::NamespaceDecl pasta : pastas) {
    for (auto decl : pasta::DeclContext(pasta).Declarations()) {
      if (auto cls = pasta::CXXRecordDecl::From(decl);
          cls && cls->IsThisDeclarationADefinition()) {
        auto name = cls->Name();
        if (false) {
#define ADD_TO_LIST(type_name, lower_name) \
    } else if (g ## type_name ## Names.count(name)) { \
      lower_name ## s.emplace_back(std::move(*cls));

  FOR_EACH_ENTITY_CATEGORY(ADD_TO_LIST)
#undef ADD_TO_LIST
        }
      } else if (auto e = pasta::EnumDecl::From(decl);
                 e && e->IsThisDeclarationADefinition()) {
        auto name = e->Name();
        if (name != "TokenContextKind") {
          enums.emplace_back(std::move(*e));
        }
      }
    }
  }

  RunOnClasses();
  return EXIT_SUCCESS;
}

int CodeGenerator::RunOnTranslationUnit(pasta::TranslationUnitDecl tu) {
  for (auto decl : pasta::DeclContext(tu).Declarations()) {
    if (auto ns = pasta::NamespaceDecl::From(decl);
        ns && ns->Name() == "pasta") {
      pastas.emplace_back(std::move(*ns));
    }
  }
  if (pastas.empty()) {
    std::cerr << "Unable to locate 'pasta' namespace.\n";
    return EXIT_FAILURE;
  } else {
    return RunOnNamespaces();
  }
}

CodeGenerator::CodeGenerator(char *argv[])
    : lib_dir(argv[5]),
      include_dir(argv[6]),
      schema_os(argv[4], std::ios::trunc | std::ios::out),
      ast_h_os(include_dir / "AST.h", std::ios::trunc | std::ios::out),
      frontend_h_os(include_dir / "Frontend.h", std::ios::trunc | std::ios::out),
      serialize_h_os(argv[7], std::ios::trunc | std::ios::out),
      serialize_cpp_os(argv[8], std::ios::trunc | std::ios::out),
      serialize_inc_os(argv[9], std::ios::trunc | std::ios::out),
      lib_pasta_cpp_os(argv[10], std::ios::trunc | std::ios::out),
      lib_pasta_h_os(argv[11], std::ios::trunc | std::ios::out) {}

int main(int argc, char *argv[]) {
  if (12 != argc) {
    std::cerr
        << "Usage: " << argv[0]
        << " PASTA_INCLUDE_PATH DEPENDENCIES_INC_PATH LLVM_INCLUDE_PATH LIB_AST_CAPNP LIB_ENTITIES_DIR"
        << " INCLUDE_ENTITIES_DIR SERIALIZE_H SERIALIZE_CPP VISITOR_INC USE_INC "
        << " PASTA_CPP PASTA_H"
        << std::endl;
    return EXIT_FAILURE;
  }

  std::cerr  << "Bootstrap command:\n";
  auto sep = "\t";
  for (auto i = 0; i < argc; ++i) {
    std::cerr << sep << argv[i];
    sep = " ";
  }
  std::cerr << "\n\n";

  // Expand the blacklist from the `MethodsToIngore.txt` file in the
  // `bin/Bootstrap` source directory.
  std::ifstream blacklist(
      std::filesystem::path(__FILE__).parent_path() / "MethodsToIgnore.txt");
  std::pair<std::string, std::string> class_method;
  for (std::string line; std::getline(blacklist, line);) {
    if (class_method.first.empty()) {
      class_method.first = std::move(line);
    } else {
      class_method.second = std::move(line);
      kMethodBlackList.emplace(std::move(class_method));
    }
  }

  pasta::InitPasta initializer;
  pasta::FileManager fm(pasta::FileSystem::CreateNative());
  auto maybe_compiler =
      pasta::Compiler::CreateHostCompiler(fm, pasta::TargetLanguage::kCXX);
  if (!maybe_compiler.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto fs = pasta::FileSystem::From(maybe_compiler.Value());
  auto maybe_cwd = fs->CurrentWorkingDirectory();
  if (!maybe_cwd.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto exe_path = maybe_compiler->ExecutablePath();
  std::vector<const char *> cc_args{
      exe_path.c_str(),
      "-x", "c++",
      "-std=c++20",
      "-c", __FILE__,
      "-o", "/dev/null",
      "-isystem", argv[1],  // Install include dir.
      "-isystem", argv[2],  // Dependencies include dir.
      "-isystem", argv[3],  // LLVM include dir.
      "-DMX_IN_BOOTSTRAP"};

  const pasta::ArgumentVector args(cc_args);
  auto maybe_command = pasta::CompileCommand::CreateFromArguments(
      args, maybe_cwd.TakeValue());
  if (!maybe_command.Succeeded()) {
    std::cerr << maybe_command.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const pasta::CompileCommand command = maybe_command.TakeValue();

  std::cerr
      << "Self-parsing with:\n\t"
      << command.Arguments().Join() << "\n\n";

  auto maybe_jobs = maybe_compiler->CreateJobsForCommand(command);
  if (!maybe_jobs.Succeeded()) {
    std::cerr << maybe_jobs.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  for (const pasta::CompileJob &job : maybe_jobs.TakeValue()) {
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      CodeGenerator cg(argv);
      return cg.RunOnTranslationUnit(maybe_ast.TakeValue().TranslationUnit());
    }
  }

  std::cerr << "No compile jobs.\n";
  return EXIT_FAILURE;
}
