// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "../Binding.h"

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
#include <multiplier/Re2.h>
#include <multiplier/Reference.h>

namespace mx {

// This one is manually added; needed by `TokenTreeVisitor` which is manually
// wrapped.
template MX_EXPORT SharedPyObject *mx::to_python<std::vector<mx::Fragment>>(std::vector<mx::Fragment>) noexcept;

// The rest are auto-generated...

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExcludeFromExplicitInstantiationAttrSpelling>::Type>
from_python<mx::ExcludeFromExplicitInstantiationAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnavailableAttrImplicitReason>::Type>
from_python<mx::UnavailableAttrImplicitReason>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AcquiredBeforeAttr>::Type>
from_python<mx::AcquiredBeforeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DecltypeType>::Type>
from_python<mx::DecltypeType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprConstantExprKind>::Type>
from_python<mx::ExprConstantExprKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnavailableAttrSpelling>::Type>
from_python<mx::UnavailableAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AcquiredAfterAttr>::Type>
from_python<mx::AcquiredAfterAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BuiltinType>::Type>
from_python<mx::BuiltinType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprLValueClassification>::Type>
from_python<mx::ExprLValueClassification>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UninitializedAttrSpelling>::Type>
from_python<mx::UninitializedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::Decl>>::Type>
from_python<std::optional<mx::Decl>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AcquireHandleAttr>::Type>
from_python<mx::AcquireHandleAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BlockPointerType>::Type>
from_python<mx::BlockPointerType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::Stmt>>::Type>
from_python<std::optional<mx::Stmt>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprNullPointerConstantKind>::Type>
from_python<mx::ExprNullPointerConstantKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnlikelyAttrSpelling>::Type>
from_python<mx::UnlikelyAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprNullPointerConstantValueDependence>::Type>
from_python<mx::ExprNullPointerConstantValueDependence>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnsafeBufferUsageAttrSpelling>::Type>
from_python<mx::UnsafeBufferUsageAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AcquireCapabilityAttr>::Type>
from_python<mx::AcquireCapabilityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BitIntType>::Type>
from_python<mx::BitIntType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprSideEffectsKind>::Type>
from_python<mx::ExprSideEffectsKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnusedAttrSpelling>::Type>
from_python<mx::UnusedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AVRSignalAttr>::Type>
from_python<mx::AVRSignalAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BTFTagAttributedType>::Type>
from_python<mx::BTFTagAttributedType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprisModifiableLvalueResult>::Type>
from_python<mx::ExprisModifiableLvalueResult>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UseHandleAttrSpelling>::Type>
from_python<mx::UseHandleAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AVRInterruptAttr>::Type>
from_python<mx::AVRInterruptAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AttributedType>::Type>
from_python<mx::AttributedType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExternalSourceSymbolAttrSpelling>::Type>
from_python<mx::ExternalSourceSymbolAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UsedAttrSpelling>::Type>
from_python<mx::UsedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FallThroughAttrSpelling>::Type>
from_python<mx::FallThroughAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UserDefinedLiteralLiteralOperatorKind>::Type>
from_python<mx::UserDefinedLiteralLiteralOperatorKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ARMInterruptAttr>::Type>
from_python<mx::ARMInterruptAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AtomicType>::Type>
from_python<mx::AtomicType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FastCallAttrSpelling>::Type>
from_python<mx::FastCallAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UsingIfExistsAttrSpelling>::Type>
from_python<mx::UsingIfExistsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AMDGPUWavesPerEUAttr>::Type>
from_python<mx::AMDGPUWavesPerEUAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IncompleteArrayType>::Type>
from_python<mx::IncompleteArrayType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FinalAttrSpelling>::Type>
from_python<mx::FinalAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UuidAttrSpelling>::Type>
from_python<mx::UuidAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AMDGPUNumVGPRAttr>::Type>
from_python<mx::AMDGPUNumVGPRAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DependentSizedArrayType>::Type>
from_python<mx::DependentSizedArrayType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FlagEnumAttrSpelling>::Type>
from_python<mx::FlagEnumAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VarDeclDefinitionKind>::Type>
from_python<mx::VarDeclDefinitionKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::File>::Type>
from_python<mx::File>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FlattenAttrSpelling>::Type>
from_python<mx::FlattenAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VarDeclInitializationStyle>::Type>
from_python<mx::VarDeclInitializationStyle>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::Attr>>::Type>
from_python<std::optional<mx::Attr>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AMDGPUNumSGPRAttr>::Type>
from_python<mx::AMDGPUNumSGPRAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstantArrayType>::Type>
from_python<mx::ConstantArrayType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FormatArgAttrSpelling>::Type>
from_python<mx::FormatArgAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VarDeclTLSKind>::Type>
from_python<mx::VarDeclTLSKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AMDGPUKernelCallAttr>::Type>
from_python<mx::AMDGPUKernelCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AdjustedType>::Type>
from_python<mx::AdjustedType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FormatAttrSpelling>::Type>
from_python<mx::FormatAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VecReturnAttrSpelling>::Type>
from_python<mx::VecReturnAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AMDGPUFlatWorkGroupSizeAttr>::Type>
from_python<mx::AMDGPUFlatWorkGroupSizeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DecayedType>::Type>
from_python<mx::DecayedType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionDeclTemplatedKind>::Type>
from_python<mx::FunctionDeclTemplatedKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VectorCallAttrSpelling>::Type>
from_python<mx::VectorCallAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionReturnThunksAttrKind>::Type>
from_python<mx::FunctionReturnThunksAttrKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VisibilityAttrSpelling>::Type>
from_python<mx::VisibilityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AArch64VectorPcsAttr>::Type>
from_python<mx::AArch64VectorPcsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeWithKeyword>::Type>
from_python<mx::TypeWithKeyword>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionReturnThunksAttrSpelling>::Type>
from_python<mx::FunctionReturnThunksAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VisibilityAttrVisibilityType>::Type>
from_python<mx::VisibilityAttrVisibilityType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AArch64SVEPcsAttr>::Type>
from_python<mx::AArch64SVEPcsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ElaboratedType>::Type>
from_python<mx::ElaboratedType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionTypeAArch64SMETypeAttributes>::Type>
from_python<mx::FunctionTypeAArch64SMETypeAttributes>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WarnUnusedAttrSpelling>::Type>
from_python<mx::WarnUnusedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ZeroCallUsedRegsAttr>::Type>
from_python<mx::ZeroCallUsedRegsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DependentTemplateSpecializationType>::Type>
from_python<mx::DependentTemplateSpecializationType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionTypeArmStateValue>::Type>
from_python<mx::FunctionTypeArmStateValue>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WarnUnusedResultAttrSpelling>::Type>
from_python<mx::WarnUnusedResultAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GNUInlineAttrSpelling>::Type>
from_python<mx::GNUInlineAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WeakAttrSpelling>::Type>
from_python<mx::WeakAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::XRayLogArgsAttr>::Type>
from_python<mx::XRayLogArgsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DependentNameType>::Type>
from_python<mx::DependentNameType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GuardedVarAttrSpelling>::Type>
from_python<mx::GuardedVarAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WeakImportAttrSpelling>::Type>
from_python<mx::WeakImportAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::XRayInstrumentAttr>::Type>
from_python<mx::XRayInstrumentAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VectorType>::Type>
from_python<mx::VectorType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HIPManagedAttrSpelling>::Type>
from_python<mx::HIPManagedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WeakRefAttrSpelling>::Type>
from_python<mx::WeakRefAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::X86ForceAlignArgPointerAttr>::Type>
from_python<mx::X86ForceAlignArgPointerAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExtVectorType>::Type>
from_python<mx::ExtVectorType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLParamModifierAttrSpelling>::Type>
from_python<mx::HLSLParamModifierAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WebAssemblyExportNameAttrSpelling>::Type>
from_python<mx::WebAssemblyExportNameAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLShaderAttrShaderType>::Type>
from_python<mx::HLSLShaderAttrShaderType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WebAssemblyImportModuleAttrSpelling>::Type>
from_python<mx::WebAssemblyImportModuleAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WorkGroupSizeHintAttr>::Type>
from_python<mx::WorkGroupSizeHintAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UsingType>::Type>
from_python<mx::UsingType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HotAttrSpelling>::Type>
from_python<mx::HotAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WebAssemblyImportNameAttrSpelling>::Type>
from_python<mx::WebAssemblyImportNameAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WebAssemblyImportNameAttr>::Type>
from_python<mx::WebAssemblyImportNameAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UsingShadowDecl>::Type>
from_python<mx::UsingShadowDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IBActionAttrSpelling>::Type>
from_python<mx::IBActionAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::X86ForceAlignArgPointerAttrSpelling>::Type>
from_python<mx::X86ForceAlignArgPointerAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AllocSizeAttrSpelling>::Type>
from_python<mx::AllocSizeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WebAssemblyImportModuleAttr>::Type>
from_python<mx::WebAssemblyImportModuleAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BaseUsingDecl>::Type>
from_python<mx::BaseUsingDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IBOutletAttrSpelling>::Type>
from_python<mx::IBOutletAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::XRayInstrumentAttrSpelling>::Type>
from_python<mx::XRayInstrumentAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::TemplateArgument>>::Type>
from_python<std::optional<mx::TemplateArgument>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IBOutletCollectionAttrSpelling>::Type>
from_python<mx::IBOutletCollectionAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::XRayLogArgsAttrSpelling>::Type>
from_python<mx::XRayLogArgsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WebAssemblyExportNameAttr>::Type>
from_python<mx::WebAssemblyExportNameAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnresolvedUsingType>::Type>
from_python<mx::UnresolvedUsingType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IFuncAttrSpelling>::Type>
from_python<mx::IFuncAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ZeroCallUsedRegsAttrSpelling>::Type>
from_python<mx::ZeroCallUsedRegsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WeakRefAttr>::Type>
from_python<mx::WeakRefAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnaryTransformType>::Type>
from_python<mx::UnaryTransformType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ImplicitCastExprOnStack>::Type>
from_python<mx::ImplicitCastExprOnStack>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ZeroCallUsedRegsAttrZeroCallUsedRegsKind>::Type>
from_python<mx::ZeroCallUsedRegsAttrZeroCallUsedRegsKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateParameterList>::Type>
from_python<mx::TemplateParameterList>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WeakImportAttr>::Type>
from_python<mx::WeakImportAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnresolvedUsingTypenameDecl>::Type>
from_python<mx::UnresolvedUsingTypenameDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InitPriorityAttrSpelling>::Type>
from_python<mx::InitPriorityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ASTDumpOutputFormat>::Type>
from_python<mx::ASTDumpOutputFormat>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IntelOclBiccAttrSpelling>::Type>
from_python<mx::IntelOclBiccAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AccessSpecifier>::Type>
from_python<mx::AccessSpecifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WeakAttr>::Type>
from_python<mx::WeakAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypedefType>::Type>
from_python<mx::TypedefType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InternalLinkageAttrSpelling>::Type>
from_python<mx::InternalLinkageAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AddrSpaceMapMangling>::Type>
from_python<mx::AddrSpaceMapMangling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WarnUnusedResultAttr>::Type>
from_python<mx::WarnUnusedResultAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeOfType>::Type>
from_python<mx::TypeOfType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LTOVisibilityPublicAttrSpelling>::Type>
from_python<mx::LTOVisibilityPublicAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AlignRequirementKind>::Type>
from_python<mx::AlignRequirementKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WarnUnusedAttr>::Type>
from_python<mx::WarnUnusedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeOfExprType>::Type>
from_python<mx::TypeOfExprType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LeafAttrSpelling>::Type>
from_python<mx::LeafAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AltivecSrcCompatKind>::Type>
from_python<mx::AltivecSrcCompatKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LifetimeBoundAttrSpelling>::Type>
from_python<mx::LifetimeBoundAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArgumentKind>::Type>
from_python<mx::ArgumentKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VisibilityAttr>::Type>
from_python<mx::VisibilityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SEHTryStmt>::Type>
from_python<mx::SEHTryStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LikelyAttrSpelling>::Type>
from_python<mx::LikelyAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArraySizeModifier>::Type>
from_python<mx::ArraySizeModifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VectorCallAttr>::Type>
from_python<mx::VectorCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SEHExceptStmt>::Type>
from_python<mx::SEHExceptStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LoaderUninitializedAttrSpelling>::Type>
from_python<mx::LoaderUninitializedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArrayTypeTrait>::Type>
from_python<mx::ArrayTypeTrait>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Index>::Type>
from_python<mx::Index>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VecTypeHintAttr>::Type>
from_python<mx::VecTypeHintAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CompoundStmt>::Type>
from_python<mx::CompoundStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LoopHintAttrLoopHintState>::Type>
from_python<mx::LoopHintAttrLoopHintState>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AtomicScopeModelKind>::Type>
from_python<mx::AtomicScopeModelKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AMDGPUKernelCallAttrSpelling>::Type>
from_python<mx::AMDGPUKernelCallAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LoopHintAttrOptionType>::Type>
from_python<mx::LoopHintAttrOptionType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AutoTypeKeyword>::Type>
from_python<mx::AutoTypeKeyword>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VecReturnAttr>::Type>
from_python<mx::VecReturnAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SEHFinallyStmt>::Type>
from_python<mx::SEHFinallyStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LoopHintAttrSpelling>::Type>
from_python<mx::LoopHintAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AvailabilityResult>::Type>
from_python<mx::AvailabilityResult>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UuidAttr>::Type>
from_python<mx::UuidAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SEHLeaveStmt>::Type>
from_python<mx::SEHLeaveStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::M68kRTDAttrSpelling>::Type>
from_python<mx::M68kRTDAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BinaryOperatorKind>::Type>
from_python<mx::BinaryOperatorKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReturnStmt>::Type>
from_python<mx::ReturnStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSGuidDecl>::Type>
from_python<mx::MSGuidDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MIGServerRoutineAttrSpelling>::Type>
from_python<mx::MIGServerRoutineAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Bits>::Type>
from_python<mx::Bits>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSABIAttrSpelling>::Type>
from_python<mx::MSABIAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXConstructionKind>::Type>
from_python<mx::CXXConstructionKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UsingIfExistsAttr>::Type>
from_python<mx::UsingIfExistsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCForCollectionStmt>::Type>
from_python<mx::ObjCForCollectionStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RegexQueryMatch>::Type>
from_python<mx::RegexQueryMatch>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSInheritanceAttrSpelling>::Type>
from_python<mx::MSInheritanceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXNewInitializationStyle>::Type>
from_python<mx::CXXNewInitializationStyle>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UsedAttr>::Type>
from_python<mx::UsedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCAutoreleasePoolStmt>::Type>
from_python<mx::ObjCAutoreleasePoolStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSP430InterruptAttrSpelling>::Type>
from_python<mx::MSP430InterruptAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CallingConv>::Type>
from_python<mx::CallingConv>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnusedAttr>::Type>
from_python<mx::UnusedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCAtTryStmt>::Type>
from_python<mx::ObjCAtTryStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSStructAttrSpelling>::Type>
from_python<mx::MSStructAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CanThrowResult>::Type>
from_python<mx::CanThrowResult>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MayAliasAttrSpelling>::Type>
from_python<mx::MayAliasAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CapturedRegionKind>::Type>
from_python<mx::CapturedRegionKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnsafeBufferUsageAttr>::Type>
from_python<mx::UnsafeBufferUsageAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCAtFinallyStmt>::Type>
from_python<mx::ObjCAtFinallyStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MaybeUndefAttrSpelling>::Type>
from_python<mx::MaybeUndefAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CastKind>::Type>
from_python<mx::CastKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UninitializedAttr>::Type>
from_python<mx::UninitializedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCAtCatchStmt>::Type>
from_python<mx::ObjCAtCatchStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MicroMipsAttrSpelling>::Type>
from_python<mx::MicroMipsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CharacterLiteralKind>::Type>
from_python<mx::CharacterLiteralKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnavailableAttr>::Type>
from_python<mx::UnavailableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCAtThrowStmt>::Type>
from_python<mx::ObjCAtThrowStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MinSizeAttrSpelling>::Type>
from_python<mx::MinSizeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ClangABI>::Type>
from_python<mx::ClangABI>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MinVectorWidthAttrSpelling>::Type>
from_python<mx::MinVectorWidthAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CommentKind>::Type>
from_python<mx::CommentKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeVisibilityAttr>::Type>
from_python<mx::TypeVisibilityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCAtSynchronizedStmt>::Type>
from_python<mx::ObjCAtSynchronizedStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::vector<std::variant<UserToken, mx::Token>>>::Type>
from_python<std::vector<std::variant<UserToken, mx::Token>>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Mips16AttrSpelling>::Type>
from_python<mx::Mips16AttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ComparisonCategoryResult>::Type>
from_python<mx::ComparisonCategoryResult>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeTagForDatatypeAttr>::Type>
from_python<mx::TypeTagForDatatypeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPExecutableDirective>::Type>
from_python<mx::OMPExecutableDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MipsInterruptAttrInterruptType>::Type>
from_python<mx::MipsInterruptAttrInterruptType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ComparisonCategoryType>::Type>
from_python<mx::ComparisonCategoryType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TryAcquireCapabilityAttr>::Type>
from_python<mx::TryAcquireCapabilityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CapturedStmt>::Type>
from_python<mx::CapturedStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MipsInterruptAttrSpelling>::Type>
from_python<mx::MipsInterruptAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CompilingModuleKind>::Type>
from_python<mx::CompilingModuleKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MipsLongCallAttrSpelling>::Type>
from_python<mx::MipsLongCallAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ComplexRangeKind>::Type>
from_python<mx::ComplexRangeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TrivialABIAttr>::Type>
from_python<mx::TrivialABIAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CapturedDecl>::Type>
from_python<mx::CapturedDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MipsShortCallAttrSpelling>::Type>
from_python<mx::MipsShortCallAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstantResultStorageKind>::Type>
from_python<mx::ConstantResultStorageKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TransparentUnionAttr>::Type>
from_python<mx::TransparentUnionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPErrorDirective>::Type>
from_python<mx::OMPErrorDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ModeAttrSpelling>::Type>
from_python<mx::ModeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstexprSpecKind>::Type>
from_python<mx::ConstexprSpecKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ThisCallAttr>::Type>
from_python<mx::ThisCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDispatchDirective>::Type>
from_python<mx::OMPDispatchDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MustTailAttrSpelling>::Type>
from_python<mx::MustTailAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoreFoundationABI>::Type>
from_python<mx::CoreFoundationABI>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSConsumedAttrSpelling>::Type>
from_python<mx::NSConsumedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DataPositionTy>::Type>
from_python<mx::DataPositionTy>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TestTypestateAttr>::Type>
from_python<mx::TestTypestateAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDepobjDirective>::Type>
from_python<mx::OMPDepobjDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSConsumesSelfAttrSpelling>::Type>
from_python<mx::NSConsumesSelfAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeductionCandidate>::Type>
from_python<mx::DeductionCandidate>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TargetVersionAttr>::Type>
from_python<mx::TargetVersionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPCriticalDirective>::Type>
from_python<mx::OMPCriticalDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSReturnsAutoreleasedAttrSpelling>::Type>
from_python<mx::NSReturnsAutoreleasedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DefaultArgKind>::Type>
from_python<mx::DefaultArgKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TargetClonesAttr>::Type>
from_python<mx::TargetClonesAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPCancellationPointDirective>::Type>
from_python<mx::OMPCancellationPointDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSReturnsNotRetainedAttrSpelling>::Type>
from_python<mx::NSReturnsNotRetainedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DefaultCallingConvention>::Type>
from_python<mx::DefaultCallingConvention>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSReturnsRetainedAttrSpelling>::Type>
from_python<mx::NSReturnsRetainedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DefaultVisiblityExportMapping>::Type>
from_python<mx::DefaultVisiblityExportMapping>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TargetAttr>::Type>
from_python<mx::TargetAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPCancelDirective>::Type>
from_python<mx::OMPCancelDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NVPTXKernelAttrSpelling>::Type>
from_python<mx::NVPTXKernelAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DesignatorKind>::Type>
from_python<mx::DesignatorKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TLSModelAttr>::Type>
from_python<mx::TLSModelAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPBarrierDirective>::Type>
from_python<mx::OMPBarrierDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::Macro>>::Type>
from_python<std::optional<mx::Macro>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NakedAttrSpelling>::Type>
from_python<mx::NakedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DiagnosticLevelMask>::Type>
from_python<mx::DiagnosticLevelMask>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SysVABIAttr>::Type>
from_python<mx::SysVABIAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPAtomicDirective>::Type>
from_python<mx::OMPAtomicDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NamedDeclExplicitVisibilityKind>::Type>
from_python<mx::NamedDeclExplicitVisibilityKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ElaboratedTypeKeyword>::Type>
from_python<mx::ElaboratedTypeKeyword>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoBuiltinAttrSpelling>::Type>
from_python<mx::NoBuiltinAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EscapeChar>::Type>
from_python<mx::EscapeChar>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftPrivateAttr>::Type>
from_python<mx::SwiftPrivateAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTeamsDirective>::Type>
from_python<mx::OMPTeamsDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoCommonAttrSpelling>::Type>
from_python<mx::NoCommonAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExceptionHandlingKind>::Type>
from_python<mx::ExceptionHandlingKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftNewTypeAttr>::Type>
from_python<mx::SwiftNewTypeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTaskyieldDirective>::Type>
from_python<mx::OMPTaskyieldDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoDebugAttrSpelling>::Type>
from_python<mx::NoDebugAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExceptionSpecificationType>::Type>
from_python<mx::ExceptionSpecificationType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftNameAttr>::Type>
from_python<mx::SwiftNameAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTaskwaitDirective>::Type>
from_python<mx::OMPTaskwaitDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoDerefAttrSpelling>::Type>
from_python<mx::NoDerefAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExcessPrecisionKind>::Type>
from_python<mx::ExcessPrecisionKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoDestroyAttrSpelling>::Type>
from_python<mx::NoDestroyAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExplicitSpecKind>::Type>
from_python<mx::ExplicitSpecKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftImportPropertyAsAccessorsAttr>::Type>
from_python<mx::SwiftImportPropertyAsAccessorsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTaskgroupDirective>::Type>
from_python<mx::OMPTaskgroupDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoDuplicateAttrSpelling>::Type>
from_python<mx::NoDuplicateAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprDependence>::Type>
from_python<mx::ExprDependence>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftImportAsNonGenericAttr>::Type>
from_python<mx::SwiftImportAsNonGenericAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTaskDirective>::Type>
from_python<mx::OMPTaskDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoEscapeAttrSpelling>::Type>
from_python<mx::NoEscapeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprObjectKind>::Type>
from_python<mx::ExprObjectKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftErrorAttr>::Type>
from_python<mx::SwiftErrorAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetUpdateDirective>::Type>
from_python<mx::OMPTargetUpdateDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoInlineAttrSpelling>::Type>
from_python<mx::NoInlineAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprOffsets>::Type>
from_python<mx::ExprOffsets>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoInstrumentFunctionAttrSpelling>::Type>
from_python<mx::NoInstrumentFunctionAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprValueKind>::Type>
from_python<mx::ExprValueKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftCallAttr>::Type>
from_python<mx::SwiftCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetTeamsDirective>::Type>
from_python<mx::OMPTargetTeamsDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoMergeAttrSpelling>::Type>
from_python<mx::NoMergeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExpressionTrait>::Type>
from_python<mx::ExpressionTrait>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Token>::Type>
from_python<mx::Token>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftBridgedTypedefAttr>::Type>
from_python<mx::SwiftBridgedTypedefAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetParallelDirective>::Type>
from_python<mx::OMPTargetParallelDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoMicroMipsAttrSpelling>::Type>
from_python<mx::NoMicroMipsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExtKind>::Type>
from_python<mx::ExtKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Decl>::Type>
from_python<mx::Decl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftBridgeAttr>::Type>
from_python<mx::SwiftBridgeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetExitDataDirective>::Type>
from_python<mx::OMPTargetExitDataDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoMips16AttrSpelling>::Type>
from_python<mx::NoMips16AttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExtendArgsKind>::Type>
from_python<mx::ExtendArgsKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TokenTreeNode>::Type>
from_python<mx::TokenTreeNode>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoProfileFunctionAttrSpelling>::Type>
from_python<mx::NoProfileFunctionAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FPEvalMethodKind>::Type>
from_python<mx::FPEvalMethodKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAttrAttr>::Type>
from_python<mx::SwiftAttrAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelSectionsDirective>::Type>
from_python<mx::OMPParallelSectionsDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<FileLocationCache>::Type>
from_python<FileLocationCache>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoRandomizeLayoutAttrSpelling>::Type>
from_python<mx::NoRandomizeLayoutAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FPExceptionModeKind>::Type>
from_python<mx::FPExceptionModeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncNameAttr>::Type>
from_python<mx::SwiftAsyncNameAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetEnterDataDirective>::Type>
from_python<mx::OMPTargetEnterDataDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoReturnAttrSpelling>::Type>
from_python<mx::NoReturnAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FPModeKind>::Type>
from_python<mx::FPModeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncErrorAttr>::Type>
from_python<mx::SwiftAsyncErrorAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetDirective>::Type>
from_python<mx::OMPTargetDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoSanitizeAttrSpelling>::Type>
from_python<mx::NoSanitizeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Flags>::Type>
from_python<mx::Flags>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoSpeculativeLoadHardeningAttrSpelling>::Type>
from_python<mx::NoSpeculativeLoadHardeningAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GC>::Type>
from_python<mx::GC>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncCallAttr>::Type>
from_python<mx::SwiftAsyncCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetDataDirective>::Type>
from_python<mx::OMPTargetDataDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoSplitStackAttrSpelling>::Type>
from_python<mx::NoSplitStackAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GCMode>::Type>
from_python<mx::GCMode>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::string>::Type>
from_python<std::string>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncAttr>::Type>
from_python<mx::SwiftAsyncAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPSingleDirective>::Type>
from_python<mx::OMPSingleDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoStackProtectorAttrSpelling>::Type>
from_python<mx::NoStackProtectorAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GPUDefaultStreamKind>::Type>
from_python<mx::GPUDefaultStreamKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Stmt>::Type>
from_python<mx::Stmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StrictGuardStackCheckAttr>::Type>
from_python<mx::StrictGuardStackCheckAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPSectionsDirective>::Type>
from_python<mx::OMPSectionsDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoThreadSafetyAnalysisAttrSpelling>::Type>
from_python<mx::NoThreadSafetyAnalysisAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GVALinkage>::Type>
from_python<mx::GVALinkage>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoThrowAttrSpelling>::Type>
from_python<mx::NoThrowAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GetBuiltinTypeError>::Type>
from_python<mx::GetBuiltinTypeError>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StrictFPAttr>::Type>
from_python<mx::StrictFPAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPSectionDirective>::Type>
from_python<mx::OMPSectionDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoUniqueAddressAttrSpelling>::Type>
from_python<mx::NoUniqueAddressAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLLangStd>::Type>
from_python<mx::HLSLLangStd>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StdCallAttr>::Type>
from_python<mx::StdCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Fragment>::Type>
from_python<mx::Fragment>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPScopeDirective>::Type>
from_python<mx::OMPScopeDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoUwtableAttrSpelling>::Type>
from_python<mx::NoUwtableAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ID>::Type>
from_python<mx::ID>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RegexQuery>::Type>
from_python<mx::RegexQuery>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::Fragment>>::Type>
from_python<std::optional<mx::Fragment>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StandaloneDebugAttr>::Type>
from_python<mx::StandaloneDebugAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPScanDirective>::Type>
from_python<mx::OMPScanDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Compilation>::Type>
from_python<mx::Compilation>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NonNullAttrSpelling>::Type>
from_python<mx::NonNullAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IdentifierInfoFlag>::Type>
from_python<mx::IdentifierInfoFlag>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NotTailCalledAttrSpelling>::Type>
from_python<mx::NotTailCalledAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IfStatementKind>::Type>
from_python<mx::IfStatementKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SpeculativeLoadHardeningAttr>::Type>
from_python<mx::SpeculativeLoadHardeningAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelMasterDirective>::Type>
from_python<mx::OMPParallelMasterDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPAllocateDeclAttrAllocatorTypeTy>::Type>
from_python<mx::OMPAllocateDeclAttrAllocatorTypeTy>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ImplicitParamKind>::Type>
from_python<mx::ImplicitParamKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SharedTrylockFunctionAttr>::Type>
from_python<mx::SharedTrylockFunctionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelMaskedDirective>::Type>
from_python<mx::OMPParallelMaskedDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclareSimdDeclAttrBranchStateTy>::Type>
from_python<mx::OMPDeclareSimdDeclAttrBranchStateTy>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InClassInitStyle>::Type>
from_python<mx::InClassInitStyle>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SetTypestateAttr>::Type>
from_python<mx::SetTypestateAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelDirective>::Type>
from_python<mx::OMPParallelDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclareTargetDeclAttrDevTypeTy>::Type>
from_python<mx::OMPDeclareTargetDeclAttrDevTypeTy>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InheritedDesignatedInitializersState>::Type>
from_python<mx::InheritedDesignatedInitializersState>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclareTargetDeclAttrMapTypeTy>::Type>
from_python<mx::OMPDeclareTargetDeclAttrMapTypeTy>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InitStorageKind>::Type>
from_python<mx::InitStorageKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SentinelAttr>::Type>
from_python<mx::SentinelAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPOrderedDirective>::Type>
from_python<mx::OMPOrderedDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSConsumedAttrSpelling>::Type>
from_python<mx::OSConsumedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InlineVariableDefinitionKind>::Type>
from_python<mx::InlineVariableDefinitionKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SelectAnyAttr>::Type>
from_python<mx::SelectAnyAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPMetaDirective>::Type>
from_python<mx::OMPMetaDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSConsumesThisAttrSpelling>::Type>
from_python<mx::OSConsumesThisAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InterestingIdentifierKind>::Type>
from_python<mx::InterestingIdentifierKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SectionAttr>::Type>
from_python<mx::SectionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPMasterDirective>::Type>
from_python<mx::OMPMasterDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSReturnsNotRetainedAttrSpelling>::Type>
from_python<mx::OSReturnsNotRetainedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Kinds>::Type>
from_python<mx::Kinds>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AArch64VectorPcsAttrSpelling>::Type>
from_python<mx::AArch64VectorPcsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSReturnsRetainedAttrSpelling>::Type>
from_python<mx::OSReturnsRetainedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LambdaCaptureDefault>::Type>
from_python<mx::LambdaCaptureDefault>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ScopedLockableAttr>::Type>
from_python<mx::ScopedLockableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPMaskedDirective>::Type>
from_python<mx::OMPMaskedDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSReturnsRetainedOnNonZeroAttrSpelling>::Type>
from_python<mx::OSReturnsRetainedOnNonZeroAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LambdaCaptureKind>::Type>
from_python<mx::LambdaCaptureKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AMDGPUFlatWorkGroupSizeAttrSpelling>::Type>
from_python<mx::AMDGPUFlatWorkGroupSizeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SYCLSpecialClassAttr>::Type>
from_python<mx::SYCLSpecialClassAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPLoopBasedDirective>::Type>
from_python<mx::OMPLoopBasedDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSReturnsRetainedOnZeroAttrSpelling>::Type>
from_python<mx::OSReturnsRetainedOnZeroAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LangAS>::Type>
from_python<mx::LangAS>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AliasAttrSpelling>::Type>
from_python<mx::AliasAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SYCLKernelAttr>::Type>
from_python<mx::SYCLKernelAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPLoopTransformationDirective>::Type>
from_python<mx::OMPLoopTransformationDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBoxableAttrSpelling>::Type>
from_python<mx::ObjCBoxableAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LangFeatures>::Type>
from_python<mx::LangFeatures>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AMDGPUNumSGPRAttrSpelling>::Type>
from_python<mx::AMDGPUNumSGPRAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AlignedAttrSpelling>::Type>
from_python<mx::AlignedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBridgeAttrSpelling>::Type>
from_python<mx::ObjCBridgeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Language>::Type>
from_python<mx::Language>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReturnsTwiceAttr>::Type>
from_python<mx::ReturnsTwiceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPUnrollDirective>::Type>
from_python<mx::OMPUnrollDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBridgeMutableAttrSpelling>::Type>
from_python<mx::ObjCBridgeMutableAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LanguageLinkage>::Type>
from_python<mx::LanguageLinkage>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReturnsNonNullAttr>::Type>
from_python<mx::ReturnsNonNullAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTileDirective>::Type>
from_python<mx::OMPTileDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AMDGPUNumVGPRAttrSpelling>::Type>
from_python<mx::AMDGPUNumVGPRAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::CXXCtorInitializer, mx::Compilation>>::Type>
from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::CXXCtorInitializer, mx::Compilation>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBridgeRelatedAttrSpelling>::Type>
from_python<mx::ObjCBridgeRelatedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LaxVectorConversionKind>::Type>
from_python<mx::LaxVectorConversionKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReturnTypestateAttr>::Type>
from_python<mx::ReturnTypestateAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPLoopDirective>::Type>
from_python<mx::OMPLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCClassStubAttrSpelling>::Type>
from_python<mx::ObjCClassStubAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Level>::Type>
from_python<mx::Level>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCDesignatedInitializerAttrSpelling>::Type>
from_python<mx::ObjCDesignatedInitializerAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Linkage>::Type>
from_python<mx::Linkage>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RetainAttr>::Type>
from_python<mx::RetainAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPGenericLoopDirective>::Type>
from_python<mx::OMPGenericLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCDirectAttrSpelling>::Type>
from_python<mx::ObjCDirectAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LinkageSpecLanguageIDs>::Type>
from_python<mx::LinkageSpecLanguageIDs>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RestrictAttr>::Type>
from_python<mx::RestrictAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPForSimdDirective>::Type>
from_python<mx::OMPForSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCDirectMembersAttrSpelling>::Type>
from_python<mx::ObjCDirectMembersAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSInheritanceModel>::Type>
from_python<mx::MSInheritanceModel>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RequiresCapabilityAttr>::Type>
from_python<mx::RequiresCapabilityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPForDirective>::Type>
from_python<mx::OMPForDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCExceptionAttrSpelling>::Type>
from_python<mx::ObjCExceptionAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSVCMajorVersion>::Type>
from_python<mx::MSVCMajorVersion>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCExplicitProtocolImplAttrSpelling>::Type>
from_python<mx::ObjCExplicitProtocolImplAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSVtorDispMode>::Type>
from_python<mx::MSVtorDispMode>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReqdWorkGroupSizeAttr>::Type>
from_python<mx::ReqdWorkGroupSizeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDistributeSimdDirective>::Type>
from_python<mx::OMPDistributeSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroVAOptArgument>::Type>
from_python<mx::MacroVAOptArgument>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroConcatenate>::Type>
from_python<mx::MacroConcatenate>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroStringify>::Type>
from_python<mx::MacroStringify>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroExpansion>::Type>
from_python<mx::MacroExpansion>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Macro>::Type>
from_python<mx::Macro>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroArgument>::Type>
from_python<mx::MacroArgument>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroParameterSubstitution>::Type>
from_python<mx::MacroParameterSubstitution>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroParameter>::Type>
from_python<mx::MacroParameter>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaMacroDirective>::Type>
from_python<mx::PragmaMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UndefineMacroDirective>::Type>
from_python<mx::UndefineMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OtherMacroDirective>::Type>
from_python<mx::OtherMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConditionalMacroDirective>::Type>
from_python<mx::ConditionalMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EndIfMacroDirective>::Type>
from_python<mx::EndIfMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ElseMacroDirective>::Type>
from_python<mx::ElseMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ElseIfNotDefinedMacroDirective>::Type>
from_python<mx::ElseIfNotDefinedMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ElseIfDefinedMacroDirective>::Type>
from_python<mx::ElseIfDefinedMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AlwaysDestroyAttrSpelling>::Type>
from_python<mx::AlwaysDestroyAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ElseIfMacroDirective>::Type>
from_python<mx::ElseIfMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IfNotDefinedMacroDirective>::Type>
from_python<mx::IfNotDefinedMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AlwaysInlineAttrSpelling>::Type>
from_python<mx::AlwaysInlineAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IfDefinedMacroDirective>::Type>
from_python<mx::IfDefinedMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnnotateAttrSpelling>::Type>
from_python<mx::AnnotateAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnnotateTypeAttrSpelling>::Type>
from_python<mx::AnnotateTypeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IfMacroDirective>::Type>
from_python<mx::IfMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnyX86InterruptAttrSpelling>::Type>
from_python<mx::AnyX86InterruptAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IncludeLikeMacroDirective>::Type>
from_python<mx::IncludeLikeMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnyX86NoCallerSavedRegistersAttrSpelling>::Type>
from_python<mx::AnyX86NoCallerSavedRegistersAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ImportMacroDirective>::Type>
from_python<mx::ImportMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnyX86NoCfCheckAttrSpelling>::Type>
from_python<mx::AnyX86NoCfCheckAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArcWeakrefUnavailableAttrSpelling>::Type>
from_python<mx::ArcWeakrefUnavailableAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<EntityId>::Type>
from_python<EntityId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IncludeMacrosMacroDirective>::Type>
from_python<mx::IncludeMacrosMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArgumentWithTypeTagAttrSpelling>::Type>
from_python<mx::ArgumentWithTypeTagAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IncludeNextMacroDirective>::Type>
from_python<mx::IncludeNextMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmBuiltinAliasAttrSpelling>::Type>
from_python<mx::ArmBuiltinAliasAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXCtorInitializer>::Type>
from_python<mx::CXXCtorInitializer>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TokenContext>::Type>
from_python<mx::TokenContext>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IncludeMacroDirective>::Type>
from_python<mx::IncludeMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmMveStrictPolymorphismAttrSpelling>::Type>
from_python<mx::ArmMveStrictPolymorphismAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArtificialAttrSpelling>::Type>
from_python<mx::ArtificialAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AsmLabelAttrSpelling>::Type>
from_python<mx::AsmLabelAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AssertCapabilityAttrSpelling>::Type>
from_python<mx::AssertCapabilityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AssumeAlignedAttrSpelling>::Type>
from_python<mx::AssumeAlignedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AssumptionAttrSpelling>::Type>
from_python<mx::AssumptionAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::CXXCtorInitializer>>::Type>
from_python<std::optional<mx::CXXCtorInitializer>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AtomicExprAtomicOp>::Type>
from_python<mx::AtomicExprAtomicOp>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AvailabilityAttrSpelling>::Type>
from_python<mx::AvailabilityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AvailableOnlyInDefaultEvalMethodAttrSpelling>::Type>
from_python<mx::AvailableOnlyInDefaultEvalMethodAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedStmtId>::Type>
from_python<PackedStmtId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BPFPreserveAccessIndexAttrSpelling>::Type>
from_python<mx::BPFPreserveAccessIndexAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BPFPreserveStaticOffsetAttrSpelling>::Type>
from_python<mx::BPFPreserveStaticOffsetAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BTFDeclTagAttrSpelling>::Type>
from_python<mx::BTFDeclTagAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BTFTypeTagAttrSpelling>::Type>
from_python<mx::BTFTypeTagAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BlocksAttrBlockType>::Type>
from_python<mx::BlocksAttrBlockType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BlocksAttrSpelling>::Type>
from_python<mx::BlocksAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BuiltinAliasAttrSpelling>::Type>
from_python<mx::BuiltinAliasAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::filesystem::path>::Type>
from_python<std::filesystem::path>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BuiltinTypeKind>::Type>
from_python<mx::BuiltinTypeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CDeclAttrSpelling>::Type>
from_python<mx::CDeclAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFAuditedTransferAttrSpelling>::Type>
from_python<mx::CFAuditedTransferAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFConsumedAttrSpelling>::Type>
from_python<mx::CFConsumedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFGuardAttrGuardArg>::Type>
from_python<mx::CFGuardAttrGuardArg>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedAttrId>::Type>
from_python<PackedAttrId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFGuardAttrSpelling>::Type>
from_python<mx::CFGuardAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFICanonicalJumpTableAttrSpelling>::Type>
from_python<mx::CFICanonicalJumpTableAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedMacroId>::Type>
from_python<PackedMacroId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFReturnsNotRetainedAttrSpelling>::Type>
from_python<mx::CFReturnsNotRetainedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFReturnsRetainedAttrSpelling>::Type>
from_python<mx::CFReturnsRetainedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFUnknownTransferAttrSpelling>::Type>
from_python<mx::CFUnknownTransferAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::span<const mx::MacroKind>>::Type>
from_python<std::span<const mx::MacroKind>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CPUDispatchAttrSpelling>::Type>
from_python<mx::CPUDispatchAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CPUSpecificAttrSpelling>::Type>
from_python<mx::CPUSpecificAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::string_view>::Type>
from_python<std::string_view>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDAConstantAttrSpelling>::Type>
from_python<mx::CUDAConstantAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDADeviceAttrSpelling>::Type>
from_python<mx::CUDADeviceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDADeviceBuiltinSurfaceTypeAttrSpelling>::Type>
from_python<mx::CUDADeviceBuiltinSurfaceTypeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDADeviceBuiltinTextureTypeAttrSpelling>::Type>
from_python<mx::CUDADeviceBuiltinTextureTypeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDAGlobalAttrSpelling>::Type>
from_python<mx::CUDAGlobalAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedTypeId>::Type>
from_python<PackedTypeId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDAHostAttrSpelling>::Type>
from_python<mx::CUDAHostAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDALaunchBoundsAttrSpelling>::Type>
from_python<mx::CUDALaunchBoundsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedTemplateArgumentId>::Type>
from_python<PackedTemplateArgumentId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDASharedAttrSpelling>::Type>
from_python<mx::CUDASharedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXX11NoReturnAttrSpelling>::Type>
from_python<mx::CXX11NoReturnAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedTemplateParameterListId>::Type>
from_python<PackedTemplateParameterListId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXRecordDeclLambdaDependencyKind>::Type>
from_python<mx::CXXRecordDeclLambdaDependencyKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CallExprADLCallKind>::Type>
from_python<mx::CallExprADLCallKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CallableWhenAttrConsumedState>::Type>
from_python<mx::CallableWhenAttrConsumedState>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedCXXBaseSpecifierId>::Type>
from_python<PackedCXXBaseSpecifierId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CallableWhenAttrSpelling>::Type>
from_python<mx::CallableWhenAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CallbackAttrSpelling>::Type>
from_python<mx::CallbackAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedDesignatorId>::Type>
from_python<PackedDesignatorId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CalledOnceAttrSpelling>::Type>
from_python<mx::CalledOnceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CapabilityAttrSpelling>::Type>
from_python<mx::CapabilityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AVRSignalAttrSpelling>::Type>
from_python<mx::AVRSignalAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedCXXCtorInitializerId>::Type>
from_python<PackedCXXCtorInitializerId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CapturedStmtVariableCaptureKind>::Type>
from_python<mx::CapturedStmtVariableCaptureKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CarriesDependencyAttrSpelling>::Type>
from_python<mx::CarriesDependencyAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AbiTagAttrSpelling>::Type>
from_python<mx::AbiTagAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CleanupAttrSpelling>::Type>
from_python<mx::CleanupAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CodeAlignAttrSpelling>::Type>
from_python<mx::CodeAlignAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CodeModelAttrSpelling>::Type>
from_python<mx::CodeModelAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ColdAttrSpelling>::Type>
from_python<mx::ColdAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CommonAttrSpelling>::Type>
from_python<mx::CommonAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstAttrSpelling>::Type>
from_python<mx::ConstAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstInitAttrSpelling>::Type>
from_python<mx::ConstInitAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstructorAttrSpelling>::Type>
from_python<mx::ConstructorAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConsumableAttrConsumedState>::Type>
from_python<mx::ConsumableAttrConsumedState>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConsumableAttrSpelling>::Type>
from_python<mx::ConsumableAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedFileId>::Type>
from_python<PackedFileId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConsumableAutoCastAttrSpelling>::Type>
from_python<mx::ConsumableAutoCastAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConsumableSetOnReadAttrSpelling>::Type>
from_python<mx::ConsumableSetOnReadAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConvergentAttrSpelling>::Type>
from_python<mx::ConvergentAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroDisableLifetimeBoundAttrSpelling>::Type>
from_python<mx::CoroDisableLifetimeBoundAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroLifetimeBoundAttrSpelling>::Type>
from_python<mx::CoroLifetimeBoundAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroOnlyDestroyWhenCompleteAttrSpelling>::Type>
from_python<mx::CoroOnlyDestroyWhenCompleteAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroReturnTypeAttrSpelling>::Type>
from_python<mx::CoroReturnTypeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroWrapperAttrSpelling>::Type>
from_python<mx::CoroWrapperAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CountedByAttrSpelling>::Type>
from_python<mx::CountedByAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedFragmentId>::Type>
from_python<PackedFragmentId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DLLExportAttrSpelling>::Type>
from_python<mx::DLLExportAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DLLImportAttrSpelling>::Type>
from_python<mx::DLLImportAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeclFriendObjectKind>::Type>
from_python<mx::DeclFriendObjectKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedCompilationId>::Type>
from_python<PackedCompilationId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeclIdentifierNamespace>::Type>
from_python<mx::DeclIdentifierNamespace>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeclModuleOwnershipKind>::Type>
from_python<mx::DeclModuleOwnershipKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeclObjCDeclQualifier>::Type>
from_python<mx::DeclObjCDeclQualifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeprecatedAttrSpelling>::Type>
from_python<mx::DeprecatedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<PackedDeclId>::Type>
from_python<PackedDeclId>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DestructorAttrSpelling>::Type>
from_python<mx::DestructorAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DiagnoseAsBuiltinAttrSpelling>::Type>
from_python<mx::DiagnoseAsBuiltinAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DiagnoseIfAttrDiagnosticType>::Type>
from_python<mx::DiagnoseIfAttrDiagnosticType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DisableSanitizerInstrumentationAttrSpelling>::Type>
from_python<mx::DisableSanitizerInstrumentationAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DisableTailCallsAttrSpelling>::Type>
from_python<mx::DisableTailCallsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnforceTCBAttrSpelling>::Type>
from_python<mx::EnforceTCBAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnforceTCBLeafAttrSpelling>::Type>
from_python<mx::EnforceTCBLeafAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnumExtensibilityAttrKind>::Type>
from_python<mx::EnumExtensibilityAttrKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnumExtensibilityAttrSpelling>::Type>
from_python<mx::EnumExtensibilityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ErrorAttrSpelling>::Type>
from_python<mx::ErrorAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReleaseCapabilityAttr>::Type>
from_python<mx::ReleaseCapabilityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CStyleCastExpr>::Type>
from_python<mx::CStyleCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReinitializesAttr>::Type>
from_python<mx::ReinitializesAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BuiltinBitCastExpr>::Type>
from_python<mx::BuiltinBitCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RegCallAttr>::Type>
from_python<mx::RegCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBridgedCastExpr>::Type>
from_python<mx::ObjCBridgedCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReadOnlyPlacementAttr>::Type>
from_python<mx::ReadOnlyPlacementAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CallExpr>::Type>
from_python<mx::CallExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RandomizeLayoutAttr>::Type>
from_python<mx::RandomizeLayoutAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXOperatorCallExpr>::Type>
from_python<mx::CXXOperatorCallExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RISCVInterruptAttr>::Type>
from_python<mx::RISCVInterruptAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXMemberCallExpr>::Type>
from_python<mx::CXXMemberCallExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PureAttr>::Type>
from_python<mx::PureAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDAKernelCallExpr>::Type>
from_python<mx::CUDAKernelCallExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PtGuardedVarAttr>::Type>
from_python<mx::PtGuardedVarAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UserDefinedLiteral>::Type>
from_python<mx::UserDefinedLiteral>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PtGuardedByAttr>::Type>
from_python<mx::PtGuardedByAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXUuidofExpr>::Type>
from_python<mx::CXXUuidofExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PreserveMostAttr>::Type>
from_python<mx::PreserveMostAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXUnresolvedConstructExpr>::Type>
from_python<mx::CXXUnresolvedConstructExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PreserveAllAttr>::Type>
from_python<mx::PreserveAllAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXTypeidExpr>::Type>
from_python<mx::CXXTypeidExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PreferredTypeAttr>::Type>
from_python<mx::PreferredTypeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXThrowExpr>::Type>
from_python<mx::CXXThrowExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PreferredNameAttr>::Type>
from_python<mx::PreferredNameAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXNewExpr>::Type>
from_python<mx::CXXNewExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaClangTextSectionAttr>::Type>
from_python<mx::PragmaClangTextSectionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXThisExpr>::Type>
from_python<mx::CXXThisExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaClangRodataSectionAttr>::Type>
from_python<mx::PragmaClangRodataSectionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXStdInitializerListExpr>::Type>
from_python<mx::CXXStdInitializerListExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaClangRelroSectionAttr>::Type>
from_python<mx::PragmaClangRelroSectionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXScalarValueInitExpr>::Type>
from_python<mx::CXXScalarValueInitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaClangDataSectionAttr>::Type>
from_python<mx::PragmaClangDataSectionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXRewrittenBinaryOperator>::Type>
from_python<mx::CXXRewrittenBinaryOperator>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaClangBSSSectionAttr>::Type>
from_python<mx::PragmaClangBSSSectionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXPseudoDestructorExpr>::Type>
from_python<mx::CXXPseudoDestructorExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PointerAttr>::Type>
from_python<mx::PointerAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXParenListInitExpr>::Type>
from_python<mx::CXXParenListInitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PcsAttr>::Type>
from_python<mx::PcsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXNullPtrLiteralExpr>::Type>
from_python<mx::CXXNullPtrLiteralExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PatchableFunctionEntryAttr>::Type>
from_python<mx::PatchableFunctionEntryAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXNoexceptExpr>::Type>
from_python<mx::CXXNoexceptExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PascalAttr>::Type>
from_python<mx::PascalAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXConstructExpr>::Type>
from_python<mx::CXXConstructExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ParamTypestateAttr>::Type>
from_python<mx::ParamTypestateAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXInheritedCtorInitExpr>::Type>
from_python<mx::CXXInheritedCtorInitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PackedAttr>::Type>
from_python<mx::PackedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXFoldExpr>::Type>
from_python<mx::CXXFoldExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OwnershipAttr>::Type>
from_python<mx::OwnershipAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXDependentScopeMemberExpr>::Type>
from_python<mx::CXXDependentScopeMemberExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OwnerAttr>::Type>
from_python<mx::OwnerAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXDeleteExpr>::Type>
from_python<mx::CXXDeleteExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OverrideAttr>::Type>
from_python<mx::OverrideAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXDefaultInitExpr>::Type>
from_python<mx::CXXDefaultInitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OptimizeNoneAttr>::Type>
from_python<mx::OptimizeNoneAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXDefaultArgExpr>::Type>
from_python<mx::CXXDefaultArgExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLKernelAttr>::Type>
from_python<mx::OpenCLKernelAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXTemporaryObjectExpr>::Type>
from_python<mx::CXXTemporaryObjectExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLIntelReqdSubGroupSizeAttr>::Type>
from_python<mx::OpenCLIntelReqdSubGroupSizeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXBoolLiteralExpr>::Type>
from_python<mx::CXXBoolLiteralExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCSubclassingRestrictedAttr>::Type>
from_python<mx::ObjCSubclassingRestrictedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXBindTemporaryExpr>::Type>
from_python<mx::CXXBindTemporaryExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCRootClassAttr>::Type>
from_python<mx::ObjCRootClassAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BlockExpr>::Type>
from_python<mx::BlockExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCReturnsInnerPointerAttr>::Type>
from_python<mx::ObjCReturnsInnerPointerAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BlockDecl>::Type>
from_python<mx::BlockDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCRequiresSuperAttr>::Type>
from_python<mx::ObjCRequiresSuperAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BinaryOperator>::Type>
from_python<mx::BinaryOperator>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCRequiresPropertyDefsAttr>::Type>
from_python<mx::ObjCRequiresPropertyDefsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CompoundAssignOperator>::Type>
from_python<mx::CompoundAssignOperator>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCPreciseLifetimeAttr>::Type>
from_python<mx::ObjCPreciseLifetimeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AtomicExpr>::Type>
from_python<mx::AtomicExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCOwnershipAttr>::Type>
from_python<mx::ObjCOwnershipAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AsTypeExpr>::Type>
from_python<mx::AsTypeExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCNSObjectAttr>::Type>
from_python<mx::ObjCNSObjectAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArrayTypeTraitExpr>::Type>
from_python<mx::ArrayTypeTraitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCMethodFamilyAttr>::Type>
from_python<mx::ObjCMethodFamilyAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArraySubscriptExpr>::Type>
from_python<mx::ArraySubscriptExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCIndependentClassAttr>::Type>
from_python<mx::ObjCIndependentClassAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArrayInitLoopExpr>::Type>
from_python<mx::ArrayInitLoopExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCExternallyRetainedAttr>::Type>
from_python<mx::ObjCExternallyRetainedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArrayInitIndexExpr>::Type>
from_python<mx::ArrayInitIndexExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCExplicitProtocolImplAttr>::Type>
from_python<mx::ObjCExplicitProtocolImplAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AbstractConditionalOperator>::Type>
from_python<mx::AbstractConditionalOperator>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCExceptionAttr>::Type>
from_python<mx::ObjCExceptionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConditionalOperator>::Type>
from_python<mx::ConditionalOperator>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBridgeRelatedAttr>::Type>
from_python<mx::ObjCBridgeRelatedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BinaryConditionalOperator>::Type>
from_python<mx::BinaryConditionalOperator>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBridgeMutableAttr>::Type>
from_python<mx::ObjCBridgeMutableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VAArgExpr>::Type>
from_python<mx::VAArgExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AllocAlignAttrSpelling>::Type>
from_python<mx::AllocAlignAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBridgeAttr>::Type>
from_python<mx::ObjCBridgeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnaryOperator>::Type>
from_python<mx::UnaryOperator>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSReturnsRetainedOnZeroAttr>::Type>
from_python<mx::OSReturnsRetainedOnZeroAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnaryExprOrTypeTraitExpr>::Type>
from_python<mx::UnaryExprOrTypeTraitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSReturnsRetainedOnNonZeroAttr>::Type>
from_python<mx::OSReturnsRetainedOnNonZeroAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypoExpr>::Type>
from_python<mx::TypoExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSReturnsRetainedAttr>::Type>
from_python<mx::OSReturnsRetainedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeTraitExpr>::Type>
from_python<mx::TypeTraitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSReturnsNotRetainedAttr>::Type>
from_python<mx::OSReturnsNotRetainedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SubstNonTypeTemplateParmPackExpr>::Type>
from_python<mx::SubstNonTypeTemplateParmPackExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSConsumesThisAttr>::Type>
from_python<mx::OSConsumesThisAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NonTypeTemplateParmDecl>::Type>
from_python<mx::NonTypeTemplateParmDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPThreadPrivateDeclAttr>::Type>
from_python<mx::OMPThreadPrivateDeclAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SubstNonTypeTemplateParmExpr>::Type>
from_python<mx::SubstNonTypeTemplateParmExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclareVariantAttr>::Type>
from_python<mx::OMPDeclareVariantAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StmtExpr>::Type>
from_python<mx::StmtExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclareTargetDeclAttr>::Type>
from_python<mx::OMPDeclareTargetDeclAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SourceLocExpr>::Type>
from_python<mx::SourceLocExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPCaptureNoInitAttr>::Type>
from_python<mx::OMPCaptureNoInitAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SizeOfPackExpr>::Type>
from_python<mx::SizeOfPackExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPAllocateDeclAttr>::Type>
from_python<mx::OMPAllocateDeclAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ShuffleVectorExpr>::Type>
from_python<mx::ShuffleVectorExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NotTailCalledAttr>::Type>
from_python<mx::NotTailCalledAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SYCLUniqueStableNameExpr>::Type>
from_python<mx::SYCLUniqueStableNameExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoUwtableAttr>::Type>
from_python<mx::NoUwtableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RequiresExpr>::Type>
from_python<mx::RequiresExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoUniqueAddressAttr>::Type>
from_python<mx::NoUniqueAddressAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RequiresExprBodyDecl>::Type>
from_python<mx::RequiresExprBodyDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoThrowAttr>::Type>
from_python<mx::NoThrowAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RecoveryExpr>::Type>
from_python<mx::RecoveryExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoThreadSafetyAnalysisAttr>::Type>
from_python<mx::NoThreadSafetyAnalysisAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PseudoObjectExpr>::Type>
from_python<mx::PseudoObjectExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoStackProtectorAttr>::Type>
from_python<mx::NoStackProtectorAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PredefinedExpr>::Type>
from_python<mx::PredefinedExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoSplitStackAttr>::Type>
from_python<mx::NoSplitStackAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ParenListExpr>::Type>
from_python<mx::ParenListExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoSpeculativeLoadHardeningAttr>::Type>
from_python<mx::NoSpeculativeLoadHardeningAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ParenExpr>::Type>
from_python<mx::ParenExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoSanitizeAttr>::Type>
from_python<mx::NoSanitizeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PackExpansionExpr>::Type>
from_python<mx::PackExpansionExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoReturnAttr>::Type>
from_python<mx::NoReturnAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnresolvedMemberExpr>::Type>
from_python<mx::UnresolvedMemberExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoRandomizeLayoutAttr>::Type>
from_python<mx::NoRandomizeLayoutAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OffsetOfExpr>::Type>
from_python<mx::OffsetOfExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoProfileFunctionAttr>::Type>
from_python<mx::NoProfileFunctionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCSubscriptRefExpr>::Type>
from_python<mx::ObjCSubscriptRefExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoMips16Attr>::Type>
from_python<mx::NoMips16Attr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCStringLiteral>::Type>
from_python<mx::ObjCStringLiteral>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoMicroMipsAttr>::Type>
from_python<mx::NoMicroMipsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCSelectorExpr>::Type>
from_python<mx::ObjCSelectorExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoInstrumentFunctionAttr>::Type>
from_python<mx::NoInstrumentFunctionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCProtocolExpr>::Type>
from_python<mx::ObjCProtocolExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoDuplicateAttr>::Type>
from_python<mx::NoDuplicateAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCMessageExpr>::Type>
from_python<mx::ObjCMessageExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoDestroyAttr>::Type>
from_python<mx::NoDestroyAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCIvarRefExpr>::Type>
from_python<mx::ObjCIvarRefExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoDebugAttr>::Type>
from_python<mx::NoDebugAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCIsaExpr>::Type>
from_python<mx::ObjCIsaExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoCommonAttr>::Type>
from_python<mx::NoCommonAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCIndirectCopyRestoreExpr>::Type>
from_python<mx::ObjCIndirectCopyRestoreExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoAliasAttr>::Type>
from_python<mx::NoAliasAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCEncodeExpr>::Type>
from_python<mx::ObjCEncodeExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NakedAttr>::Type>
from_python<mx::NakedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCDictionaryLiteral>::Type>
from_python<mx::ObjCDictionaryLiteral>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NVPTXKernelAttr>::Type>
from_python<mx::NVPTXKernelAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBoxedExpr>::Type>
from_python<mx::ObjCBoxedExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSReturnsRetainedAttr>::Type>
from_python<mx::NSReturnsRetainedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBoolLiteralExpr>::Type>
from_python<mx::ObjCBoolLiteralExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSReturnsNotRetainedAttr>::Type>
from_python<mx::NSReturnsNotRetainedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCAvailabilityCheckExpr>::Type>
from_python<mx::ObjCAvailabilityCheckExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSReturnsAutoreleasedAttr>::Type>
from_python<mx::NSReturnsAutoreleasedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCArrayLiteral>::Type>
from_python<mx::ObjCArrayLiteral>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSErrorDomainAttr>::Type>
from_python<mx::NSErrorDomainAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPIteratorExpr>::Type>
from_python<mx::OMPIteratorExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSConsumesSelfAttr>::Type>
from_python<mx::NSConsumesSelfAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPArrayShapingExpr>::Type>
from_python<mx::OMPArrayShapingExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MipsShortCallAttr>::Type>
from_python<mx::MipsShortCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPArraySectionExpr>::Type>
from_python<mx::OMPArraySectionExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MipsLongCallAttr>::Type>
from_python<mx::MipsLongCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoInitExpr>::Type>
from_python<mx::NoInitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCExternallyRetainedAttrSpelling>::Type>
from_python<mx::ObjCExternallyRetainedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDistributeParallelForSimdDirective>::Type>
from_python<mx::OMPDistributeParallelForSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCGCAttrSpelling>::Type>
from_python<mx::ObjCGCAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDistributeParallelForDirective>::Type>
from_python<mx::OMPDistributeParallelForDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCIndependentClassAttrSpelling>::Type>
from_python<mx::ObjCIndependentClassAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDistributeDirective>::Type>
from_python<mx::OMPDistributeDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCIvarDeclAccessControl>::Type>
from_python<mx::ObjCIvarDeclAccessControl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCMessageExprReceiverKind>::Type>
from_python<mx::ObjCMessageExprReceiverKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTeamsGenericLoopDirective>::Type>
from_python<mx::OMPTeamsGenericLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCMethodFamilyAttrFamilyKind>::Type>
from_python<mx::ObjCMethodFamilyAttrFamilyKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTeamsDistributeSimdDirective>::Type>
from_python<mx::OMPTeamsDistributeSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCMethodFamilyAttrSpelling>::Type>
from_python<mx::ObjCMethodFamilyAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTeamsDistributeParallelForSimdDirective>::Type>
from_python<mx::OMPTeamsDistributeParallelForSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCNSObjectAttrSpelling>::Type>
from_python<mx::ObjCNSObjectAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCNonLazyClassAttrSpelling>::Type>
from_python<mx::ObjCNonLazyClassAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTeamsDistributeParallelForDirective>::Type>
from_python<mx::OMPTeamsDistributeParallelForDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCNonRuntimeProtocolAttrSpelling>::Type>
from_python<mx::ObjCNonRuntimeProtocolAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTeamsDistributeDirective>::Type>
from_python<mx::OMPTeamsDistributeDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCOwnershipAttrSpelling>::Type>
from_python<mx::ObjCOwnershipAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTaskLoopSimdDirective>::Type>
from_python<mx::OMPTaskLoopSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCPreciseLifetimeAttrSpelling>::Type>
from_python<mx::ObjCPreciseLifetimeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCPropertyDeclPropertyControl>::Type>
from_python<mx::ObjCPropertyDeclPropertyControl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTaskLoopDirective>::Type>
from_python<mx::OMPTaskLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCPropertyDeclSetterKind>::Type>
from_python<mx::ObjCPropertyDeclSetterKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetTeamsGenericLoopDirective>::Type>
from_python<mx::OMPTargetTeamsGenericLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCPropertyImplDeclKind>::Type>
from_python<mx::ObjCPropertyImplDeclKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetTeamsDistributeSimdDirective>::Type>
from_python<mx::OMPTargetTeamsDistributeSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCRequiresPropertyDefsAttrSpelling>::Type>
from_python<mx::ObjCRequiresPropertyDefsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCRequiresSuperAttrSpelling>::Type>
from_python<mx::ObjCRequiresSuperAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetTeamsDistributeParallelForSimdDirective>::Type>
from_python<mx::OMPTargetTeamsDistributeParallelForSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCReturnsInnerPointerAttrSpelling>::Type>
from_python<mx::ObjCReturnsInnerPointerAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelMasterTaskLoopDirective>::Type>
from_python<mx::OMPParallelMasterTaskLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCRootClassAttrSpelling>::Type>
from_python<mx::ObjCRootClassAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetTeamsDistributeParallelForDirective>::Type>
from_python<mx::OMPTargetTeamsDistributeParallelForDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCRuntimeNameAttrSpelling>::Type>
from_python<mx::ObjCRuntimeNameAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCRuntimeVisibleAttrSpelling>::Type>
from_python<mx::ObjCRuntimeVisibleAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetTeamsDistributeDirective>::Type>
from_python<mx::OMPTargetTeamsDistributeDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCSubclassingRestrictedAttrSpelling>::Type>
from_python<mx::ObjCSubclassingRestrictedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetSimdDirective>::Type>
from_python<mx::OMPTargetSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLAccessAttrSpelling>::Type>
from_python<mx::OpenCLAccessAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetParallelGenericLoopDirective>::Type>
from_python<mx::OMPTargetParallelGenericLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLConstantAddressSpaceAttrSpelling>::Type>
from_python<mx::OpenCLConstantAddressSpaceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLGenericAddressSpaceAttrSpelling>::Type>
from_python<mx::OpenCLGenericAddressSpaceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetParallelForSimdDirective>::Type>
from_python<mx::OMPTargetParallelForSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLGlobalAddressSpaceAttrSpelling>::Type>
from_python<mx::OpenCLGlobalAddressSpaceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPTargetParallelForDirective>::Type>
from_python<mx::OMPTargetParallelForDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLGlobalDeviceAddressSpaceAttrSpelling>::Type>
from_python<mx::OpenCLGlobalDeviceAddressSpaceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPSimdDirective>::Type>
from_python<mx::OMPSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLGlobalHostAddressSpaceAttrSpelling>::Type>
from_python<mx::OpenCLGlobalHostAddressSpaceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLKernelAttrSpelling>::Type>
from_python<mx::OpenCLKernelAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelMasterTaskLoopSimdDirective>::Type>
from_python<mx::OMPParallelMasterTaskLoopSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLLocalAddressSpaceAttrSpelling>::Type>
from_python<mx::OpenCLLocalAddressSpaceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelMaskedTaskLoopSimdDirective>::Type>
from_python<mx::OMPParallelMaskedTaskLoopSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLPrivateAddressSpaceAttrSpelling>::Type>
from_python<mx::OpenCLPrivateAddressSpaceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelMaskedTaskLoopDirective>::Type>
from_python<mx::OMPParallelMaskedTaskLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OptimizeNoneAttrSpelling>::Type>
from_python<mx::OptimizeNoneAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OverloadableAttrSpelling>::Type>
from_python<mx::OverloadableAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelGenericLoopDirective>::Type>
from_python<mx::OMPParallelGenericLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OwnershipAttrOwnershipKind>::Type>
from_python<mx::OwnershipAttrOwnershipKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelForSimdDirective>::Type>
from_python<mx::OMPParallelForSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OwnershipAttrSpelling>::Type>
from_python<mx::OwnershipAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPParallelForDirective>::Type>
from_python<mx::OMPParallelForDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PackedAttrSpelling>::Type>
from_python<mx::PackedAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ParamTypestateAttrConsumedState>::Type>
from_python<mx::ParamTypestateAttrConsumedState>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPMasterTaskLoopSimdDirective>::Type>
from_python<mx::OMPMasterTaskLoopSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ParamTypestateAttrSpelling>::Type>
from_python<mx::ParamTypestateAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPMasterTaskLoopDirective>::Type>
from_python<mx::OMPMasterTaskLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PascalAttrSpelling>::Type>
from_python<mx::PascalAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPMaskedTaskLoopSimdDirective>::Type>
from_python<mx::OMPMaskedTaskLoopSimdDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PassObjectSizeAttrSpelling>::Type>
from_python<mx::PassObjectSizeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PatchableFunctionEntryAttrSpelling>::Type>
from_python<mx::PatchableFunctionEntryAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPMaskedTaskLoopDirective>::Type>
from_python<mx::OMPMaskedTaskLoopDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PcsAttrPCSType>::Type>
from_python<mx::PcsAttrPCSType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Designator>::Type>
from_python<mx::Designator>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPInteropDirective>::Type>
from_python<mx::OMPInteropDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PcsAttrSpelling>::Type>
from_python<mx::PcsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::Designator>>::Type>
from_python<std::optional<mx::Designator>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPFlushDirective>::Type>
from_python<mx::OMPFlushDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PreferredNameAttrSpelling>::Type>
from_python<mx::PreferredNameAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PreferredTypeAttrSpelling>::Type>
from_python<mx::PreferredTypeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPCanonicalLoop>::Type>
from_python<mx::OMPCanonicalLoop>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PreserveAllAttrSpelling>::Type>
from_python<mx::PreserveAllAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeclRefExpr>::Type>
from_python<mx::DeclRefExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PreserveMostAttrSpelling>::Type>
from_python<mx::PreserveMostAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NullStmt>::Type>
from_python<mx::NullStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PtGuardedVarAttrSpelling>::Type>
from_python<mx::PtGuardedVarAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PureAttrSpelling>::Type>
from_python<mx::PureAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSDependentExistsStmt>::Type>
from_python<mx::MSDependentExistsStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::QualifiedTypeDestructionKind>::Type>
from_python<mx::QualifiedTypeDestructionKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IndirectGotoStmt>::Type>
from_python<mx::IndirectGotoStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::QualifiedTypeNonConstantStorageReason>::Type>
from_python<mx::QualifiedTypeNonConstantStorageReason>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LabelDecl>::Type>
from_python<mx::LabelDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::QualifiedTypePrimitiveCopyKind>::Type>
from_python<mx::QualifiedTypePrimitiveCopyKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::QualifiedTypePrimitiveDefaultInitializeKind>::Type>
from_python<mx::QualifiedTypePrimitiveDefaultInitializeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LabelStmt>::Type>
from_python<mx::LabelStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RISCVInterruptAttrInterruptType>::Type>
from_python<mx::RISCVInterruptAttrInterruptType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXTryStmt>::Type>
from_python<mx::CXXTryStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RISCVInterruptAttrSpelling>::Type>
from_python<mx::RISCVInterruptAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IfStmt>::Type>
from_python<mx::IfStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RandomizeLayoutAttrSpelling>::Type>
from_python<mx::RandomizeLayoutAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReadOnlyPlacementAttrSpelling>::Type>
from_python<mx::ReadOnlyPlacementAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeclStmt>::Type>
from_python<mx::DeclStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RegCallAttrSpelling>::Type>
from_python<mx::RegCallAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GotoStmt>::Type>
from_python<mx::GotoStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReinitializesAttrSpelling>::Type>
from_python<mx::ReinitializesAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ForStmt>::Type>
from_python<mx::ForStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReleaseCapabilityAttrSpelling>::Type>
from_python<mx::ReleaseCapabilityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReleaseHandleAttrSpelling>::Type>
from_python<mx::ReleaseHandleAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DoStmt>::Type>
from_python<mx::DoStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RequiresCapabilityAttrSpelling>::Type>
from_python<mx::RequiresCapabilityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroutineBodyStmt>::Type>
from_python<mx::CoroutineBodyStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RestrictAttrSpelling>::Type>
from_python<mx::RestrictAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoreturnStmt>::Type>
from_python<mx::CoreturnStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RetainAttrSpelling>::Type>
from_python<mx::RetainAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReturnTypestateAttrConsumedState>::Type>
from_python<mx::ReturnTypestateAttrConsumedState>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ContinueStmt>::Type>
from_python<mx::ContinueStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReturnTypestateAttrSpelling>::Type>
from_python<mx::ReturnTypestateAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXCatchStmt>::Type>
from_python<mx::CXXCatchStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReturnsNonNullAttrSpelling>::Type>
from_python<mx::ReturnsNonNullAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXForRangeStmt>::Type>
from_python<mx::CXXForRangeStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReturnsTwiceAttrSpelling>::Type>
from_python<mx::ReturnsTwiceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SYCLKernelAttrSpelling>::Type>
from_python<mx::SYCLKernelAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BreakStmt>::Type>
from_python<mx::BreakStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SYCLSpecialClassAttrSpelling>::Type>
from_python<mx::SYCLSpecialClassAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AsmStmt>::Type>
from_python<mx::AsmStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ScopedLockableAttrSpelling>::Type>
from_python<mx::ScopedLockableAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSAsmStmt>::Type>
from_python<mx::MSAsmStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SectionAttrSpelling>::Type>
from_python<mx::SectionAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SelectAnyAttrSpelling>::Type>
from_python<mx::SelectAnyAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GCCAsmStmt>::Type>
from_python<mx::GCCAsmStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SentinelAttrSpelling>::Type>
from_python<mx::SentinelAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StringLiteral>::Type>
from_python<mx::StringLiteral>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SetTypestateAttrConsumedState>::Type>
from_python<mx::SetTypestateAttrConsumedState>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AddrLabelExpr>::Type>
from_python<mx::AddrLabelExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SetTypestateAttrSpelling>::Type>
from_python<mx::SetTypestateAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SpeculativeLoadHardeningAttrSpelling>::Type>
from_python<mx::SpeculativeLoadHardeningAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WhileStmt>::Type>
from_python<mx::WhileStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXBaseSpecifier>::Type>
from_python<mx::CXXBaseSpecifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StandaloneDebugAttrSpelling>::Type>
from_python<mx::StandaloneDebugAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DesignatedInitUpdateExpr>::Type>
from_python<mx::DesignatedInitUpdateExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StdCallAttrSpelling>::Type>
from_python<mx::StdCallAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InitListExpr>::Type>
from_python<mx::InitListExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StmtLikelihood>::Type>
from_python<mx::StmtLikelihood>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StmtKind>::Type>
from_python<mx::StmtKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DesignatedInitExpr>::Type>
from_python<mx::DesignatedInitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SuppressAttrSpelling>::Type>
from_python<mx::SuppressAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DependentScopeDeclRefExpr>::Type>
from_python<mx::DependentScopeDeclRefExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncAttrKind>::Type>
from_python<mx::SwiftAsyncAttrKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DependentCoawaitExpr>::Type>
from_python<mx::DependentCoawaitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncAttrSpelling>::Type>
from_python<mx::SwiftAsyncAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncCallAttrSpelling>::Type>
from_python<mx::SwiftAsyncCallAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnresolvedLookupExpr>::Type>
from_python<mx::UnresolvedLookupExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncContextAttrSpelling>::Type>
from_python<mx::SwiftAsyncContextAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OverloadExpr>::Type>
from_python<mx::OverloadExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncErrorAttrConventionKind>::Type>
from_python<mx::SwiftAsyncErrorAttrConventionKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::CXXBaseSpecifier>>::Type>
from_python<std::optional<mx::CXXBaseSpecifier>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroutineSuspendExpr>::Type>
from_python<mx::CoroutineSuspendExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncErrorAttrSpelling>::Type>
from_python<mx::SwiftAsyncErrorAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftCallAttrSpelling>::Type>
from_python<mx::SwiftCallAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpaqueValueExpr>::Type>
from_python<mx::OpaqueValueExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftContextAttrSpelling>::Type>
from_python<mx::SwiftContextAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoawaitExpr>::Type>
from_python<mx::CoawaitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftErrorAttrConventionKind>::Type>
from_python<mx::SwiftErrorAttrConventionKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoyieldExpr>::Type>
from_python<mx::CoyieldExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftErrorResultAttrSpelling>::Type>
from_python<mx::SwiftErrorResultAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<uint32_t>::Type>
from_python<uint32_t>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftIndirectResultAttrSpelling>::Type>
from_python<mx::SwiftIndirectResultAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConvertVectorExpr>::Type>
from_python<mx::ConvertVectorExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftNewTypeAttrNewtypeKind>::Type>
from_python<mx::SwiftNewTypeAttrNewtypeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConceptSpecializationExpr>::Type>
from_python<mx::ConceptSpecializationExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<uint64_t>::Type>
from_python<uint64_t>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftNewTypeAttrSpelling>::Type>
from_python<mx::SwiftNewTypeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ImplicitConceptSpecializationDecl>::Type>
from_python<mx::ImplicitConceptSpecializationDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SysVABIAttrSpelling>::Type>
from_python<mx::SysVABIAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<bool>::Type>
from_python<bool>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TLSModelAttrSpelling>::Type>
from_python<mx::TLSModelAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CompoundLiteralExpr>::Type>
from_python<mx::CompoundLiteralExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TargetAttrSpelling>::Type>
from_python<mx::TargetAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ChooseExpr>::Type>
from_python<mx::ChooseExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TargetClonesAttrSpelling>::Type>
from_python<mx::TargetClonesAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CharacterLiteral>::Type>
from_python<mx::CharacterLiteral>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TargetVersionAttrSpelling>::Type>
from_python<mx::TargetVersionAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AttrKind>::Type>
from_python<mx::AttrKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateArgumentKind>::Type>
from_python<mx::TemplateArgumentKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CastExpr>::Type>
from_python<mx::CastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TestTypestateAttrConsumedState>::Type>
from_python<mx::TestTypestateAttrConsumedState>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ImplicitCastExpr>::Type>
from_python<mx::ImplicitCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TestTypestateAttrSpelling>::Type>
from_python<mx::TestTypestateAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AArch64SVEPcsAttrSpelling>::Type>
from_python<mx::AArch64SVEPcsAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeclKind>::Type>
from_python<mx::DeclKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExplicitCastExpr>::Type>
from_python<mx::ExplicitCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ThisCallAttrSpelling>::Type>
from_python<mx::ThisCallAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TransparentUnionAttrSpelling>::Type>
from_python<mx::TransparentUnionAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXNamedCastExpr>::Type>
from_python<mx::CXXNamedCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TrivialABIAttrSpelling>::Type>
from_python<mx::TrivialABIAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXDynamicCastExpr>::Type>
from_python<mx::CXXDynamicCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TryAcquireCapabilityAttrSpelling>::Type>
from_python<mx::TryAcquireCapabilityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXConstCastExpr>::Type>
from_python<mx::CXXConstCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeScalarTypeKind>::Type>
from_python<mx::TypeScalarTypeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeKind>::Type>
from_python<mx::TypeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXAddrspaceCastExpr>::Type>
from_python<mx::CXXAddrspaceCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeTagForDatatypeAttrSpelling>::Type>
from_python<mx::TypeTagForDatatypeAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXStaticCastExpr>::Type>
from_python<mx::CXXStaticCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeVisibilityAttrSpelling>::Type>
from_python<mx::TypeVisibilityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXReinterpretCastExpr>::Type>
from_python<mx::CXXReinterpretCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeVisibilityAttrVisibilityType>::Type>
from_python<mx::TypeVisibilityAttrVisibilityType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnaryTransformTypeUTTKind>::Type>
from_python<mx::UnaryTransformTypeUTTKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXFunctionalCastExpr>::Type>
from_python<mx::CXXFunctionalCastExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCGCAttr>::Type>
from_python<mx::ObjCGCAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MemberExpr>::Type>
from_python<mx::MemberExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoDerefAttr>::Type>
from_python<mx::NoDerefAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MatrixSubscriptExpr>::Type>
from_python<mx::MatrixSubscriptExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLParamModifierAttr>::Type>
from_python<mx::HLSLParamModifierAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MaterializeTemporaryExpr>::Type>
from_python<mx::MaterializeTemporaryExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLGroupSharedAddressSpaceAttr>::Type>
from_python<mx::HLSLGroupSharedAddressSpaceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LifetimeExtendedTemporaryDecl>::Type>
from_python<mx::LifetimeExtendedTemporaryDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CmseNSCallAttr>::Type>
from_python<mx::CmseNSCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSPropertySubscriptExpr>::Type>
from_python<mx::MSPropertySubscriptExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::Type>>::Type>
from_python<std::optional<mx::Type>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnnotateTypeAttr>::Type>
from_python<mx::AnnotateTypeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSPropertyRefExpr>::Type>
from_python<mx::MSPropertyRefExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BTFTypeTagAttr>::Type>
from_python<mx::BTFTypeTagAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSPropertyDecl>::Type>
from_python<mx::MSPropertyDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmStreamingCompatibleAttr>::Type>
from_python<mx::ArmStreamingCompatibleAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LambdaExpr>::Type>
from_python<mx::LambdaExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmStreamingAttr>::Type>
from_python<mx::ArmStreamingAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IntegerLiteral>::Type>
from_python<mx::IntegerLiteral>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmPreservesAttr>::Type>
from_python<mx::ArmPreservesAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ImplicitValueInitExpr>::Type>
from_python<mx::ImplicitValueInitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmOutAttr>::Type>
from_python<mx::ArmOutAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ImaginaryLiteral>::Type>
from_python<mx::ImaginaryLiteral>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmMveStrictPolymorphismAttr>::Type>
from_python<mx::ArmMveStrictPolymorphismAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GenericSelectionExpr>::Type>
from_python<mx::GenericSelectionExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::span<const mx::TypeKind>>::Type>
from_python<std::span<const mx::TypeKind>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmInOutAttr>::Type>
from_python<mx::ArmInOutAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GNUNullExpr>::Type>
from_python<mx::GNUNullExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmInAttr>::Type>
from_python<mx::ArmInAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionParmPackExpr>::Type>
from_python<mx::FunctionParmPackExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AddressSpaceAttr>::Type>
from_python<mx::AddressSpaceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FullExpr>::Type>
from_python<mx::FullExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::WebAssemblyFuncrefAttr>::Type>
from_python<mx::WebAssemblyFuncrefAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExprWithCleanups>::Type>
from_python<mx::ExprWithCleanups>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UPtrAttr>::Type>
from_python<mx::UPtrAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstantExpr>::Type>
from_python<mx::ConstantExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeNullableResultAttr>::Type>
from_python<mx::TypeNullableResultAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FloatingLiteral>::Type>
from_python<mx::FloatingLiteral>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeNullableAttr>::Type>
from_python<mx::TypeNullableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FixedPointLiteral>::Type>
from_python<mx::FixedPointLiteral>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeNullUnspecifiedAttr>::Type>
from_python<mx::TypeNullUnspecifiedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExtVectorElementExpr>::Type>
from_python<mx::ExtVectorElementExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::span<const mx::AttrKind>>::Type>
from_python<std::span<const mx::AttrKind>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeNonNullAttr>::Type>
from_python<mx::TypeNonNullAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExpressionTraitExpr>::Type>
from_python<mx::ExpressionTraitExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ThreadAttr>::Type>
from_python<mx::ThreadAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AttributedStmt>::Type>
from_python<mx::AttributedStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftVersionedRemovalAttr>::Type>
from_python<mx::SwiftVersionedRemovalAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwitchStmt>::Type>
from_python<mx::SwitchStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftVersionedAdditionAttr>::Type>
from_python<mx::SwiftVersionedAdditionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwitchCase>::Type>
from_python<mx::SwitchCase>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftObjCMembersAttr>::Type>
from_python<mx::SwiftObjCMembersAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DefaultStmt>::Type>
from_python<mx::DefaultStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StmtAttr>::Type>
from_python<mx::StmtAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CaseStmt>::Type>
from_python<mx::CaseStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLUnrollHintAttr>::Type>
from_python<mx::OpenCLUnrollHintAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AccessSpecDecl>::Type>
from_python<mx::AccessSpecDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MustTailAttr>::Type>
from_python<mx::MustTailAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclarativeDirectiveDecl>::Type>
from_python<mx::OMPDeclarativeDirectiveDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LikelyAttr>::Type>
from_python<mx::LikelyAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPThreadPrivateDecl>::Type>
from_python<mx::OMPThreadPrivateDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FallThroughAttr>::Type>
from_python<mx::FallThroughAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPRequiresDecl>::Type>
from_python<mx::OMPRequiresDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CodeAlignAttr>::Type>
from_python<mx::CodeAlignAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPAllocateDecl>::Type>
from_python<mx::OMPAllocateDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnlikelyAttr>::Type>
from_python<mx::UnlikelyAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TranslationUnitDecl>::Type>
from_python<mx::TranslationUnitDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RenderScriptKernelAttr>::Type>
from_python<mx::RenderScriptKernelAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TopLevelStmtDecl>::Type>
from_python<mx::TopLevelStmtDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OverloadableAttr>::Type>
from_python<mx::OverloadableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StaticAssertDecl>::Type>
from_python<mx::StaticAssertDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLAccessAttr>::Type>
from_python<mx::OpenCLAccessAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaDetectMismatchDecl>::Type>
from_python<mx::PragmaDetectMismatchDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCRuntimeVisibleAttr>::Type>
from_python<mx::ObjCRuntimeVisibleAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaCommentDecl>::Type>
from_python<mx::PragmaCommentDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCRuntimeNameAttr>::Type>
from_python<mx::ObjCRuntimeNameAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLBufferDecl>::Type>
from_python<mx::HLSLBufferDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCNonRuntimeProtocolAttr>::Type>
from_python<mx::ObjCNonRuntimeProtocolAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UsingEnumDecl>::Type>
from_python<mx::UsingEnumDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCNonLazyClassAttr>::Type>
from_python<mx::ObjCNonLazyClassAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnumDecl>::Type>
from_python<mx::EnumDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCDirectMembersAttr>::Type>
from_python<mx::ObjCDirectMembersAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnumConstantDecl>::Type>
from_python<mx::EnumConstantDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoBuiltinAttr>::Type>
from_python<mx::NoBuiltinAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UsingDecl>::Type>
from_python<mx::UsingDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCDirectAttr>::Type>
from_python<mx::ObjCDirectAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnresolvedUsingValueDecl>::Type>
from_python<mx::UnresolvedUsingValueDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCDesignatedInitializerAttr>::Type>
from_python<mx::ObjCDesignatedInitializerAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnnamedGlobalConstantDecl>::Type>
from_python<mx::UnnamedGlobalConstantDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCClassStubAttr>::Type>
from_python<mx::ObjCClassStubAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateParamObjectDecl>::Type>
from_python<mx::TemplateParamObjectDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBoxableAttr>::Type>
from_python<mx::ObjCBoxableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclareReductionDecl>::Type>
from_python<mx::OMPDeclareReductionDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPReferencedVarAttr>::Type>
from_python<mx::OMPReferencedVarAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPCapturedExprDecl>::Type>
from_python<mx::OMPCapturedExprDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclareSimdDeclAttr>::Type>
from_python<mx::OMPDeclareSimdDeclAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DecompositionDecl>::Type>
from_python<mx::DecompositionDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPCaptureKindAttr>::Type>
from_python<mx::OMPCaptureKindAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BindingDecl>::Type>
from_python<mx::BindingDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoEscapeAttr>::Type>
from_python<mx::NoEscapeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VarTemplateSpecializationDecl>::Type>
from_python<mx::VarTemplateSpecializationDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ModeAttr>::Type>
from_python<mx::ModeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VarTemplatePartialSpecializationDecl>::Type>
from_python<mx::VarTemplatePartialSpecializationDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LoopHintAttr>::Type>
from_python<mx::LoopHintAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXConversionDecl>::Type>
from_python<mx::CXXConversionDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Reference>::Type>
from_python<mx::Reference>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LoaderUninitializedAttr>::Type>
from_python<mx::LoaderUninitializedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXDeductionGuideDecl>::Type>
from_python<mx::CXXDeductionGuideDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateArgument>::Type>
from_python<mx::TemplateArgument>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InitSegAttr>::Type>
from_python<mx::InitSegAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCAtDefsFieldDecl>::Type>
from_python<mx::ObjCAtDefsFieldDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IBOutletCollectionAttr>::Type>
from_python<mx::IBOutletCollectionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclarativeDirectiveValueDecl>::Type>
from_python<mx::OMPDeclarativeDirectiveValueDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TokenRange>::Type>
from_python<mx::TokenRange>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TokenTree>::Type>
from_python<mx::TokenTree>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IBOutletAttr>::Type>
from_python<mx::IBOutletAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclareMapperDecl>::Type>
from_python<mx::OMPDeclareMapperDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IBActionAttr>::Type>
from_python<mx::IBActionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstructorUsingShadowDecl>::Type>
from_python<mx::ConstructorUsingShadowDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HotAttr>::Type>
from_python<mx::HotAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UsingPackDecl>::Type>
from_python<mx::UsingPackDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLShaderAttr>::Type>
from_python<mx::HLSLShaderAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UsingDirectiveDecl>::Type>
from_python<mx::UsingDirectiveDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<ProxyTokenTreeVisitor>::Type>
from_python<ProxyTokenTreeVisitor>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLResourceBindingAttr>::Type>
from_python<mx::HLSLResourceBindingAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NamespaceDecl>::Type>
from_python<mx::NamespaceDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLResourceAttr>::Type>
from_python<mx::HLSLResourceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnresolvedUsingIfExistsDecl>::Type>
from_python<mx::UnresolvedUsingIfExistsDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLNumThreadsAttr>::Type>
from_python<mx::HLSLNumThreadsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ClassTemplateSpecializationDecl>::Type>
from_python<mx::ClassTemplateSpecializationDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLAnnotationAttr>::Type>
from_python<mx::HLSLAnnotationAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ClassTemplatePartialSpecializationDecl>::Type>
from_python<mx::ClassTemplatePartialSpecializationDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLSV_GroupIndexAttr>::Type>
from_python<mx::HLSLSV_GroupIndexAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypedefDecl>::Type>
from_python<mx::TypedefDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HLSLSV_DispatchThreadIDAttr>::Type>
from_python<mx::HLSLSV_DispatchThreadIDAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeAliasDecl>::Type>
from_python<mx::TypeAliasDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::HIPManagedAttr>::Type>
from_python<mx::HIPManagedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeAliasTemplateDecl>::Type>
from_python<mx::TypeAliasTemplateDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GuardedVarAttr>::Type>
from_python<mx::GuardedVarAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BuiltinTemplateDecl>::Type>
from_python<mx::BuiltinTemplateDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GuardedByAttr>::Type>
from_python<mx::GuardedByAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateTemplateParmDecl>::Type>
from_python<mx::TemplateTemplateParmDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::GNUInlineAttr>::Type>
from_python<mx::GNUInlineAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCCompatibleAliasDecl>::Type>
from_python<mx::ObjCCompatibleAliasDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionReturnThunksAttr>::Type>
from_python<mx::FunctionReturnThunksAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NamespaceAliasDecl>::Type>
from_python<mx::NamespaceAliasDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FormatAttr>::Type>
from_python<mx::FormatAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LinkageSpecDecl>::Type>
from_python<mx::LinkageSpecDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FormatArgAttr>::Type>
from_python<mx::FormatArgAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ImportDecl>::Type>
from_python<mx::ImportDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FlattenAttr>::Type>
from_python<mx::FlattenAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FriendTemplateDecl>::Type>
from_python<mx::FriendTemplateDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnforceTCBLeafAttr>::Type>
from_python<mx::EnforceTCBLeafAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FlagEnumAttr>::Type>
from_python<mx::FlagEnumAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FileScopeAsmDecl>::Type>
from_python<mx::FileScopeAsmDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FinalAttr>::Type>
from_python<mx::FinalAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExternCContextDecl>::Type>
from_python<mx::ExternCContextDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FastCallAttr>::Type>
from_python<mx::FastCallAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExportDecl>::Type>
from_python<mx::ExportDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExclusiveTrylockFunctionAttr>::Type>
from_python<mx::ExclusiveTrylockFunctionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EmptyDecl>::Type>
from_python<mx::EmptyDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExcludeFromExplicitInstantiationAttr>::Type>
from_python<mx::ExcludeFromExplicitInstantiationAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ErrorAttr>::Type>
from_python<mx::ErrorAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroSubstitution>::Type>
from_python<mx::MacroSubstitution>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnumExtensibilityAttr>::Type>
from_python<mx::EnumExtensibilityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroVAOpt>::Type>
from_python<mx::MacroVAOpt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnforceTCBAttr>::Type>
from_python<mx::EnforceTCBAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EmptyTokenTreeNode>::Type>
from_python<mx::EmptyTokenTreeNode>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AcquireHandleAttrSpelling>::Type>
from_python<mx::AcquireHandleAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnableIfAttr>::Type>
from_python<mx::EnableIfAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TokenTokenTreeNode>::Type>
from_python<mx::TokenTokenTreeNode>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AddressSpaceAttrSpelling>::Type>
from_python<mx::AddressSpaceAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EmptyBasesAttr>::Type>
from_python<mx::EmptyBasesAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ChoiceTokenTreeNode>::Type>
from_python<mx::ChoiceTokenTreeNode>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DisableTailCallsAttr>::Type>
from_python<mx::DisableTailCallsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SubstitutionTokenTreeNode>::Type>
from_python<mx::SubstitutionTokenTreeNode>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DisableSanitizerInstrumentationAttr>::Type>
from_python<mx::DisableSanitizerInstrumentationAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SequenceTokenTreeNode>::Type>
from_python<mx::SequenceTokenTreeNode>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MipsInterruptAttr>::Type>
from_python<mx::MipsInterruptAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Mips16Attr>::Type>
from_python<mx::Mips16Attr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MinVectorWidthAttr>::Type>
from_python<mx::MinVectorWidthAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AMDGPUWavesPerEUAttrSpelling>::Type>
from_python<mx::AMDGPUWavesPerEUAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MinSizeAttr>::Type>
from_python<mx::MinSizeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ARMInterruptAttrInterruptType>::Type>
from_python<mx::ARMInterruptAttrInterruptType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MicroMipsAttr>::Type>
from_python<mx::MicroMipsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MaybeUndefAttr>::Type>
from_python<mx::MaybeUndefAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MayAliasAttr>::Type>
from_python<mx::MayAliasAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MaxFieldAlignmentAttr>::Type>
from_python<mx::MaxFieldAlignmentAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSVtorDispAttr>::Type>
from_python<mx::MSVtorDispAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSStructAttr>::Type>
from_python<mx::MSStructAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSP430InterruptAttr>::Type>
from_python<mx::MSP430InterruptAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSNoVTableAttr>::Type>
from_python<mx::MSNoVTableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSInheritanceAttr>::Type>
from_python<mx::MSInheritanceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSConstexprAttr>::Type>
from_python<mx::MSConstexprAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSAllocatorAttr>::Type>
from_python<mx::MSAllocatorAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MSABIAttr>::Type>
from_python<mx::MSABIAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MIGServerRoutineAttr>::Type>
from_python<mx::MIGServerRoutineAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::M68kRTDAttr>::Type>
from_python<mx::M68kRTDAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::M68kInterruptAttr>::Type>
from_python<mx::M68kInterruptAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LocksExcludedAttr>::Type>
from_python<mx::LocksExcludedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LockReturnedAttr>::Type>
from_python<mx::LockReturnedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LifetimeBoundAttr>::Type>
from_python<mx::LifetimeBoundAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LeafAttr>::Type>
from_python<mx::LeafAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LayoutVersionAttr>::Type>
from_python<mx::LayoutVersionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LTOVisibilityPublicAttr>::Type>
from_python<mx::LTOVisibilityPublicAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InternalLinkageAttr>::Type>
from_python<mx::InternalLinkageAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IntelOclBiccAttr>::Type>
from_python<mx::IntelOclBiccAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InitPriorityAttr>::Type>
from_python<mx::InitPriorityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InheritableParamAttr>::Type>
from_python<mx::InheritableParamAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CarriesDependencyAttr>::Type>
from_python<mx::CarriesDependencyAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFConsumedAttr>::Type>
from_python<mx::CFConsumedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnnotateAttr>::Type>
from_python<mx::AnnotateAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UseHandleAttr>::Type>
from_python<mx::UseHandleAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReleaseHandleAttr>::Type>
from_python<mx::ReleaseHandleAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PassObjectSizeAttr>::Type>
from_python<mx::PassObjectSizeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ParameterABIAttr>::Type>
from_python<mx::ParameterABIAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftIndirectResultAttr>::Type>
from_python<mx::SwiftIndirectResultAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<QualifiedNameRenderOptions>::Type>
from_python<QualifiedNameRenderOptions>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftErrorResultAttr>::Type>
from_python<mx::SwiftErrorResultAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftContextAttr>::Type>
from_python<mx::SwiftContextAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SwiftAsyncContextAttr>::Type>
from_python<mx::SwiftAsyncContextAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OSConsumedAttr>::Type>
from_python<mx::OSConsumedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NonNullAttr>::Type>
from_python<mx::NonNullAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NSConsumedAttr>::Type>
from_python<mx::NSConsumedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IFuncAttr>::Type>
from_python<mx::IFuncAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CalledOnceAttr>::Type>
from_python<mx::CalledOnceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BuiltinAliasAttr>::Type>
from_python<mx::BuiltinAliasAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateTypeParmType>::Type>
from_python<mx::TemplateTypeParmType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateTypeParmDecl>::Type>
from_python<mx::TemplateTypeParmDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateSpecializationType>::Type>
from_python<mx::TemplateSpecializationType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TagType>::Type>
from_python<mx::TagType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RecordType>::Type>
from_python<mx::RecordType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EnumType>::Type>
from_python<mx::EnumType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SubstTemplateTypeParmType>::Type>
from_python<mx::SubstTemplateTypeParmType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SubstTemplateTypeParmPackType>::Type>
from_python<mx::SubstTemplateTypeParmPackType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReferenceType>::Type>
from_python<mx::ReferenceType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RValueReferenceType>::Type>
from_python<mx::RValueReferenceType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::LValueReferenceType>::Type>
from_python<mx::LValueReferenceType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::QualifiedType>::Type>
from_python<mx::QualifiedType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PointerType>::Type>
from_python<mx::PointerType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PipeType>::Type>
from_python<mx::PipeType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ParenType>::Type>
from_python<mx::ParenType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PackExpansionType>::Type>
from_python<mx::PackExpansionType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCTypeParamType>::Type>
from_python<mx::ObjCTypeParamType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCObjectType>::Type>
from_python<mx::ObjCObjectType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCTypeParamDecl>::Type>
from_python<mx::ObjCTypeParamDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCInterfaceType>::Type>
from_python<mx::ObjCInterfaceType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCObjectPointerType>::Type>
from_python<mx::ObjCObjectPointerType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MemberPointerType>::Type>
from_python<mx::MemberPointerType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MatrixType>::Type>
from_python<mx::MatrixType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DependentSizedMatrixType>::Type>
from_python<mx::DependentSizedMatrixType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstantMatrixType>::Type>
from_python<mx::ConstantMatrixType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroQualifiedType>::Type>
from_python<mx::MacroQualifiedType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ComplexType>::Type>
from_python<mx::ComplexType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InjectedClassNameType>::Type>
from_python<mx::InjectedClassNameType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionType>::Type>
from_python<mx::FunctionType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionProtoType>::Type>
from_python<mx::FunctionProtoType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionNoProtoType>::Type>
from_python<mx::FunctionNoProtoType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DependentVectorType>::Type>
from_python<mx::DependentVectorType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DependentSizedExtVectorType>::Type>
from_python<mx::DependentSizedExtVectorType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DependentBitIntType>::Type>
from_python<mx::DependentBitIntType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DependentAddressSpaceType>::Type>
from_python<mx::DependentAddressSpaceType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeducedType>::Type>
from_python<mx::DeducedType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeducedTemplateSpecializationType>::Type>
from_python<mx::DeducedTemplateSpecializationType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AutoType>::Type>
from_python<mx::AutoType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConceptDecl>::Type>
from_python<mx::ConceptDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Attr>::Type>
from_python<mx::Attr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReferenceKind>::Type>
from_python<mx::ReferenceKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Type>::Type>
from_python<mx::Type>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::vector<std::variant<mx::TokenRange, mx::TokenTreeNode>>>::Type>
from_python<std::vector<std::variant<mx::TokenRange, mx::TokenTreeNode>>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::span<const mx::StmtKind>>::Type>
from_python<std::span<const mx::StmtKind>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::span<const mx::DeclKind>>::Type>
from_python<std::span<const mx::DeclKind>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FieldDecl>::Type>
from_python<mx::FieldDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeclaratorDecl>::Type>
from_python<mx::DeclaratorDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ValueDecl>::Type>
from_python<mx::ValueDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NamedDecl>::Type>
from_python<mx::NamedDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VarDecl>::Type>
from_python<mx::VarDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VarTemplateDecl>::Type>
from_python<mx::VarTemplateDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RedeclarableTemplateDecl>::Type>
from_python<mx::RedeclarableTemplateDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateDecl>::Type>
from_python<mx::TemplateDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Expr>::Type>
from_python<mx::Expr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ValueStmt>::Type>
from_python<mx::ValueStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCPropertyRefExpr>::Type>
from_python<mx::ObjCPropertyRefExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCInterfaceDecl>::Type>
from_python<mx::ObjCInterfaceDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCContainerDecl>::Type>
from_python<mx::ObjCContainerDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCMethodDecl>::Type>
from_python<mx::ObjCMethodDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCPropertyDecl>::Type>
from_python<mx::ObjCPropertyDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCIvarDecl>::Type>
from_python<mx::ObjCIvarDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ImplicitParamDecl>::Type>
from_python<mx::ImplicitParamDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ParmVarDecl>::Type>
from_python<mx::ParmVarDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCProtocolDecl>::Type>
from_python<mx::ObjCProtocolDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCImplementationDecl>::Type>
from_python<mx::ObjCImplementationDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCImplDecl>::Type>
from_python<mx::ObjCImplDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCPropertyImplDecl>::Type>
from_python<mx::ObjCPropertyImplDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCCategoryDecl>::Type>
from_python<mx::ObjCCategoryDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCCategoryImplDecl>::Type>
from_python<mx::ObjCCategoryImplDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VariableArrayType>::Type>
from_python<mx::VariableArrayType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArrayType>::Type>
from_python<mx::ArrayType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IndirectFieldDecl>::Type>
from_python<mx::IndirectFieldDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXRecordDecl>::Type>
from_python<mx::CXXRecordDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RecordDecl>::Type>
from_python<mx::RecordDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TagDecl>::Type>
from_python<mx::TagDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeDecl>::Type>
from_python<mx::TypeDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypedefNameDecl>::Type>
from_python<mx::TypedefNameDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXConstructorDecl>::Type>
from_python<mx::CXXConstructorDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXMethodDecl>::Type>
from_python<mx::CXXMethodDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionDecl>::Type>
from_python<mx::FunctionDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FunctionTemplateDecl>::Type>
from_python<mx::FunctionTemplateDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FriendDecl>::Type>
from_python<mx::FriendDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ClassTemplateDecl>::Type>
from_python<mx::ClassTemplateDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXXDestructorDecl>::Type>
from_python<mx::CXXDestructorDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DefineMacroDirective>::Type>
from_python<mx::DefineMacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroDirective>::Type>
from_python<mx::MacroDirective>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ExternalSourceSymbolAttr>::Type>
from_python<mx::ExternalSourceSymbolAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::InheritableAttr>::Type>
from_python<mx::InheritableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AlignValueAttr>::Type>
from_python<mx::AlignValueAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AliasAttr>::Type>
from_python<mx::AliasAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AbiTagAttr>::Type>
from_python<mx::AbiTagAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeAttr>::Type>
from_python<mx::TypeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SPtrAttr>::Type>
from_python<mx::SPtrAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Ptr64Attr>::Type>
from_python<mx::Ptr64Attr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Ptr32Attr>::Type>
from_python<mx::Ptr32Attr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLPrivateAddressSpaceAttr>::Type>
from_python<mx::OpenCLPrivateAddressSpaceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLLocalAddressSpaceAttr>::Type>
from_python<mx::OpenCLLocalAddressSpaceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLGlobalHostAddressSpaceAttr>::Type>
from_python<mx::OpenCLGlobalHostAddressSpaceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLGlobalDeviceAddressSpaceAttr>::Type>
from_python<mx::OpenCLGlobalDeviceAddressSpaceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLGlobalAddressSpaceAttr>::Type>
from_python<mx::OpenCLGlobalAddressSpaceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLGenericAddressSpaceAttr>::Type>
from_python<mx::OpenCLGenericAddressSpaceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenCLConstantAddressSpaceAttr>::Type>
from_python<mx::OpenCLConstantAddressSpaceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCKindOfAttr>::Type>
from_python<mx::ObjCKindOfAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCInertUnsafeUnretainedAttr>::Type>
from_python<mx::ObjCInertUnsafeUnretainedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MethodRefFlags>::Type>
from_python<mx::MethodRefFlags>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeclCategory>::Type>
from_python<mx::DeclCategory>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DiagnoseIfAttr>::Type>
from_python<mx::DiagnoseIfAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ModifiableType>::Type>
from_python<mx::ModifiableType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PseudoKind>::Type>
from_python<mx::PseudoKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DiagnoseAsBuiltinAttr>::Type>
from_python<mx::DiagnoseAsBuiltinAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MultiVersionKind>::Type>
from_python<mx::MultiVersionKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::EntityCategory>::Type>
from_python<mx::EntityCategory>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DestructorAttr>::Type>
from_python<mx::DestructorAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NameKind>::Type>
from_python<mx::NameKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NeedExtraManglingDecl>::Type>
from_python<mx::NeedExtraManglingDecl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeprecatedAttr>::Type>
from_python<mx::DeprecatedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NestedNameSpecifierDependence>::Type>
from_python<mx::NestedNameSpecifierDependence>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::MacroKind>::Type>
from_python<mx::MacroKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DeclOrStmtAttr>::Type>
from_python<mx::DeclOrStmtAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NonOdrUseReason>::Type>
from_python<mx::NonOdrUseReason>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BuiltinReferenceKind>::Type>
from_python<mx::BuiltinReferenceKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AlwaysInlineAttr>::Type>
from_python<mx::AlwaysInlineAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NonceObjCInterface>::Type>
from_python<mx::NonceObjCInterface>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<std::optional<mx::TemplateParameterList>>::Type>
from_python<std::optional<mx::TemplateParameterList>>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NullabilityKind>::Type>
from_python<mx::NullabilityKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SuppressAttr>::Type>
from_python<mx::SuppressAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OMPDeclareReductionInitKind>::Type>
from_python<mx::OMPDeclareReductionInitKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoMergeAttr>::Type>
from_python<mx::NoMergeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCBridgeCastKind>::Type>
from_python<mx::ObjCBridgeCastKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::NoInlineAttr>::Type>
from_python<mx::NoInlineAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCImplementationControl>::Type>
from_python<mx::ObjCImplementationControl>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TokenTreeNodeKind>::Type>
from_python<mx::TokenTreeNodeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCInstanceTypeFamily>::Type>
from_python<mx::ObjCInstanceTypeFamily>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TokenKind>::Type>
from_python<mx::TokenKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DLLImportStaticLocalAttr>::Type>
from_python<mx::DLLImportStaticLocalAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCLifetime>::Type>
from_python<mx::ObjCLifetime>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TokenCategory>::Type>
from_python<mx::TokenCategory>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DLLImportAttr>::Type>
from_python<mx::DLLImportAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCMethodFamily>::Type>
from_python<mx::ObjCMethodFamily>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IndexStatus>::Type>
from_python<mx::IndexStatus>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DLLExportStaticLocalAttr>::Type>
from_python<mx::DLLExportStaticLocalAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCPropertyQueryKind>::Type>
from_python<mx::ObjCPropertyQueryKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::IncludePathLocation>::Type>
from_python<mx::IncludePathLocation>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCStringFormatFamily>::Type>
from_python<mx::ObjCStringFormatFamily>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PathKind>::Type>
from_python<mx::PathKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::DLLExportAttr>::Type>
from_python<mx::DLLExportAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCSubstitutionContext>::Type>
from_python<mx::ObjCSubstitutionContext>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::FileType>::Type>
from_python<mx::FileType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CountedByAttr>::Type>
from_python<mx::CountedByAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ObjCTypeParamVariance>::Type>
from_python<mx::ObjCTypeParamVariance>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CompilerName>::Type>
from_python<mx::CompilerName>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroWrapperAttr>::Type>
from_python<mx::CoroWrapperAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OnOffSwitch>::Type>
from_python<mx::OnOffSwitch>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TargetLanguage>::Type>
from_python<mx::TargetLanguage>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OnStackType>::Type>
from_python<mx::OnStackType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroReturnTypeAttr>::Type>
from_python<mx::CoroReturnTypeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AcquireCapabilityAttrSpelling>::Type>
from_python<mx::AcquireCapabilityAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPAdjustArgsOpKind>::Type>
from_python<mx::OpenMPAdjustArgsOpKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroOnlyDestroyWhenCompleteAttr>::Type>
from_python<mx::CoroOnlyDestroyWhenCompleteAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPAtClauseKind>::Type>
from_python<mx::OpenMPAtClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroLifetimeBoundAttr>::Type>
from_python<mx::CoroLifetimeBoundAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPAtomicDefaultMemOrderClauseKind>::Type>
from_python<mx::OpenMPAtomicDefaultMemOrderClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPBindClauseKind>::Type>
from_python<mx::OpenMPBindClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CoroDisableLifetimeBoundAttr>::Type>
from_python<mx::CoroDisableLifetimeBoundAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPDefaultmapClauseKind>::Type>
from_python<mx::OpenMPDefaultmapClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConvergentAttr>::Type>
from_python<mx::ConvergentAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPDefaultmapClauseModifier>::Type>
from_python<mx::OpenMPDefaultmapClauseModifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConsumableSetOnReadAttr>::Type>
from_python<mx::ConsumableSetOnReadAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPDependClauseKind>::Type>
from_python<mx::OpenMPDependClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPDeviceClauseModifier>::Type>
from_python<mx::OpenMPDeviceClauseModifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConsumableAutoCastAttr>::Type>
from_python<mx::ConsumableAutoCastAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPDeviceType>::Type>
from_python<mx::OpenMPDeviceType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConsumableAttr>::Type>
from_python<mx::ConsumableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPDistScheduleClauseKind>::Type>
from_python<mx::OpenMPDistScheduleClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstructorAttr>::Type>
from_python<mx::ConstructorAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPDoacrossClauseModifier>::Type>
from_python<mx::OpenMPDoacrossClauseModifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPGrainsizeClauseModifier>::Type>
from_python<mx::OpenMPGrainsizeClauseModifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstInitAttr>::Type>
from_python<mx::ConstInitAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPLastprivateModifier>::Type>
from_python<mx::OpenMPLastprivateModifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ConstAttr>::Type>
from_python<mx::ConstAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPLinearClauseKind>::Type>
from_python<mx::OpenMPLinearClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CommonAttr>::Type>
from_python<mx::CommonAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPMapClauseKind>::Type>
from_python<mx::OpenMPMapClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPMapModifierKind>::Type>
from_python<mx::OpenMPMapModifierKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ColdAttr>::Type>
from_python<mx::ColdAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPMotionModifierKind>::Type>
from_python<mx::OpenMPMotionModifierKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CodeSegAttr>::Type>
from_python<mx::CodeSegAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPNumTasksClauseModifier>::Type>
from_python<mx::OpenMPNumTasksClauseModifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CodeModelAttr>::Type>
from_python<mx::CodeModelAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPOrderClauseKind>::Type>
from_python<mx::OpenMPOrderClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPOrderClauseModifier>::Type>
from_python<mx::OpenMPOrderClauseModifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CmseNSEntryAttr>::Type>
from_python<mx::CmseNSEntryAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPReductionClauseModifier>::Type>
from_python<mx::OpenMPReductionClauseModifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CleanupAttr>::Type>
from_python<mx::CleanupAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPScheduleClauseKind>::Type>
from_python<mx::OpenMPScheduleClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CapturedRecordAttr>::Type>
from_python<mx::CapturedRecordAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPScheduleClauseModifier>::Type>
from_python<mx::OpenMPScheduleClauseModifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OpenMPSeverityClauseKind>::Type>
from_python<mx::OpenMPSeverityClauseKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CapabilityAttr>::Type>
from_python<mx::CapabilityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OverloadedOperatorKind>::Type>
from_python<mx::OverloadedOperatorKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CallbackAttr>::Type>
from_python<mx::CallbackAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::OverloadsShown>::Type>
from_python<mx::OverloadsShown>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CallableWhenAttr>::Type>
from_python<mx::CallableWhenAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ParameterABI>::Type>
from_python<mx::ParameterABI>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ParenLocsOffsets>::Type>
from_python<mx::ParenLocsOffsets>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CXX11NoReturnAttr>::Type>
from_python<mx::CXX11NoReturnAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaFPKind>::Type>
from_python<mx::PragmaFPKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDASharedAttr>::Type>
from_python<mx::CUDASharedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaFloatControlKind>::Type>
from_python<mx::PragmaFloatControlKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDALaunchBoundsAttr>::Type>
from_python<mx::CUDALaunchBoundsAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaMSCommentKind>::Type>
from_python<mx::PragmaMSCommentKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaMSPointersToMembersKind>::Type>
from_python<mx::PragmaMSPointersToMembersKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDAInvalidTargetAttr>::Type>
from_python<mx::CUDAInvalidTargetAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaMSStructKind>::Type>
from_python<mx::PragmaMSStructKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDAHostAttr>::Type>
from_python<mx::CUDAHostAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PragmaSectionFlag>::Type>
from_python<mx::PragmaSectionFlag>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDAGlobalAttr>::Type>
from_python<mx::CUDAGlobalAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::PredefinedIdentKind>::Type>
from_python<mx::PredefinedIdentKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Qualified>::Type>
from_python<mx::Qualified>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDADeviceBuiltinTextureTypeAttr>::Type>
from_python<mx::CUDADeviceBuiltinTextureTypeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RangeExprOffset>::Type>
from_python<mx::RangeExprOffset>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDADeviceBuiltinSurfaceTypeAttr>::Type>
from_python<mx::CUDADeviceBuiltinSurfaceTypeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RangeLocOffset>::Type>
from_python<mx::RangeLocOffset>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDADeviceAttr>::Type>
from_python<mx::CUDADeviceAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RecordArgPassingKind>::Type>
from_python<mx::RecordArgPassingKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::RefQualifierKind>::Type>
from_python<mx::RefQualifierKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CUDAConstantAttr>::Type>
from_python<mx::CUDAConstantAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReservedIdentifierStatus>::Type>
from_python<mx::ReservedIdentifierStatus>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CPUSpecificAttr>::Type>
from_python<mx::CPUSpecificAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ReservedLiteralSuffixIdStatus>::Type>
from_python<mx::ReservedLiteralSuffixIdStatus>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CPUDispatchAttr>::Type>
from_python<mx::CPUDispatchAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SFINAEResponse>::Type>
from_python<mx::SFINAEResponse>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SYCLMajorVersion>::Type>
from_python<mx::SYCLMajorVersion>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFUnknownTransferAttr>::Type>
from_python<mx::CFUnknownTransferAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SanitizerOrdinal>::Type>
from_python<mx::SanitizerOrdinal>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFReturnsRetainedAttr>::Type>
from_python<mx::CFReturnsRetainedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SelectorLocationsKind>::Type>
from_python<mx::SelectorLocationsKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFReturnsNotRetainedAttr>::Type>
from_python<mx::CFReturnsNotRetainedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ShaderStage>::Type>
from_python<mx::ShaderStage>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SignReturnAddressKeyKind>::Type>
from_python<mx::SignReturnAddressKeyKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFICanonicalJumpTableAttr>::Type>
from_python<mx::CFICanonicalJumpTableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SignReturnAddressScopeKind>::Type>
from_python<mx::SignReturnAddressScopeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFGuardAttr>::Type>
from_python<mx::CFGuardAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SignedOverflowBehaviorTy>::Type>
from_python<mx::SignedOverflowBehaviorTy>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CFAuditedTransferAttr>::Type>
from_python<mx::CFAuditedTransferAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SourceLocIdentKind>::Type>
from_python<mx::SourceLocIdentKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SpecialMemberFlags>::Type>
from_python<mx::SpecialMemberFlags>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::CDeclAttr>::Type>
from_python<mx::CDeclAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SpecifierKind>::Type>
from_python<mx::SpecifierKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::C11NoReturnAttr>::Type>
from_python<mx::C11NoReturnAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StackProtectorMode>::Type>
from_python<mx::StackProtectorMode>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BuiltinAttr>::Type>
from_python<mx::BuiltinAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StorageClass>::Type>
from_python<mx::StorageClass>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StorageDuration>::Type>
from_python<mx::StorageDuration>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BlocksAttr>::Type>
from_python<mx::BlocksAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StoredNameKind>::Type>
from_python<mx::StoredNameKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BTFDeclTagAttr>::Type>
from_python<mx::BTFDeclTagAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StoredSpecifierKind>::Type>
from_python<mx::StoredSpecifierKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BPFPreserveStaticOffsetAttr>::Type>
from_python<mx::BPFPreserveStaticOffsetAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StrictFlexArraysLevelKind>::Type>
from_python<mx::StrictFlexArraysLevelKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::StringLiteralKind>::Type>
from_python<mx::StringLiteralKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::BPFPreserveAccessIndexAttr>::Type>
from_python<mx::BPFPreserveAccessIndexAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SubExpr>::Type>
from_python<mx::SubExpr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AvailableOnlyInDefaultEvalMethodAttr>::Type>
from_python<mx::AvailableOnlyInDefaultEvalMethodAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SubStmt>::Type>
from_python<mx::SubStmt>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AvailabilityAttr>::Type>
from_python<mx::AvailabilityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::SyncScope>::Type>
from_python<mx::SyncScope>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Syntax>::Type>
from_python<mx::Syntax>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AssumptionAttr>::Type>
from_python<mx::AssumptionAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TQ>::Type>
from_python<mx::TQ>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AssumeAlignedAttr>::Type>
from_python<mx::AssumeAlignedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TagTypeKind>::Type>
from_python<mx::TagTypeKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AVRInterruptAttrSpelling>::Type>
from_python<mx::AVRInterruptAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AssertSharedLockAttr>::Type>
from_python<mx::AssertSharedLockAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TailPaddingUseRules>::Type>
from_python<mx::TailPaddingUseRules>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateArgumentDependence>::Type>
from_python<mx::TemplateArgumentDependence>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AssertExclusiveLockAttr>::Type>
from_python<mx::AssertExclusiveLockAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateNameDependence>::Type>
from_python<mx::TemplateNameDependence>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AssertCapabilityAttr>::Type>
from_python<mx::AssertCapabilityAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TemplateSpecializationKind>::Type>
from_python<mx::TemplateSpecializationKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AsmLabelAttr>::Type>
from_python<mx::AsmLabelAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TextDiagnosticFormat>::Type>
from_python<mx::TextDiagnosticFormat>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ThreadModelKind>::Type>
from_python<mx::ThreadModelKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArtificialAttr>::Type>
from_python<mx::ArtificialAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ThreadStorageClassSpecifier>::Type>
from_python<mx::ThreadStorageClassSpecifier>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmNewAttr>::Type>
from_python<mx::ArmNewAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TrailingAllocKind>::Type>
from_python<mx::TrailingAllocKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmLocallyStreamingAttr>::Type>
from_python<mx::ArmLocallyStreamingAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TranslationUnitKind>::Type>
from_python<mx::TranslationUnitKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TrivialAutoVarInitKind>::Type>
from_python<mx::TrivialAutoVarInitKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArmBuiltinAliasAttr>::Type>
from_python<mx::ArmBuiltinAliasAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeDependence>::Type>
from_python<mx::TypeDependence>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArgumentWithTypeTagAttr>::Type>
from_python<mx::ArgumentWithTypeTagAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeLocClass>::Type>
from_python<mx::TypeLocClass>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ArcWeakrefUnavailableAttr>::Type>
from_python<mx::ArcWeakrefUnavailableAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeOfKind>::Type>
from_python<mx::TypeOfKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeSpecifierSign>::Type>
from_python<mx::TypeSpecifierSign>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnyX86NoCfCheckAttr>::Type>
from_python<mx::AnyX86NoCfCheckAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeSpecifierType>::Type>
from_python<mx::TypeSpecifierType>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnyX86NoCallerSavedRegistersAttr>::Type>
from_python<mx::AnyX86NoCallerSavedRegistersAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeSpecifierWidth>::Type>
from_python<mx::TypeSpecifierWidth>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnyX86InterruptAttr>::Type>
from_python<mx::AnyX86InterruptAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeSpecifiersPipe>::Type>
from_python<mx::TypeSpecifiersPipe>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::ARMInterruptAttrSpelling>::Type>
from_python<mx::ARMInterruptAttrSpelling>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::TypeTrait>::Type>
from_python<mx::TypeTrait>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AnalyzerNoReturnAttr>::Type>
from_python<mx::AnalyzerNoReturnAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnaryExprOrTypeTrait>::Type>
from_python<mx::UnaryExprOrTypeTrait>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AlwaysDestroyAttr>::Type>
from_python<mx::AlwaysDestroyAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::UnaryOperatorKind>::Type>
from_python<mx::UnaryOperatorKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AllocSizeAttr>::Type>
from_python<mx::AllocSizeAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::APValueKind>::Type>
from_python<mx::APValueKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VectorKind>::Type>
from_python<mx::VectorKind>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AllocAlignAttr>::Type>
from_python<mx::AllocAlignAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::Visibility>::Type>
from_python<mx::Visibility>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AlignedAttr>::Type>
from_python<mx::AlignedAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VisibilityForcedKinds>::Type>
from_python<mx::VisibilityForcedKinds>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AlignNaturalAttr>::Type>
from_python<mx::AlignNaturalAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::VisibilityFromDLLStorageClassKinds>::Type>
from_python<mx::VisibilityFromDLLStorageClassKinds>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AttributeSyntax>::Type>
from_python<mx::AttributeSyntax>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT std::optional<FromPythonReturnType<mx::AlignMac68kAttr>::Type>
from_python<mx::AlignMac68kAttr>(BorrowedPyObject *obj) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExcludeFromExplicitInstantiationAttrSpelling>(mx::ExcludeFromExplicitInstantiationAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnavailableAttrImplicitReason>(mx::UnavailableAttrImplicitReason) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AcquiredBeforeAttr>(mx::AcquiredBeforeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DecltypeType>(mx::DecltypeType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPForSimdDirective>>(gap::generator<mx::OMPForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprConstantExprKind>(mx::ExprConstantExprKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnavailableAttrSpelling>(mx::UnavailableAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPGenericLoopDirective>>(gap::generator<mx::OMPGenericLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AcquiredAfterAttr>(mx::AcquiredAfterAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BuiltinType>(mx::BuiltinType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPGenericLoopDirective>>(std::optional<mx::OMPGenericLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypedefDecl>>(gap::generator<mx::TypedefDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprLValueClassification>(mx::ExprLValueClassification) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UninitializedAttrSpelling>(mx::UninitializedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AcquireHandleAttr>(mx::AcquireHandleAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BlockPointerType>(mx::BlockPointerType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypedefDecl>>(std::optional<mx::TypedefDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprNullPointerConstantKind>(mx::ExprNullPointerConstantKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnlikelyAttrSpelling>(mx::UnlikelyAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprNullPointerConstantValueDependence>(mx::ExprNullPointerConstantValueDependence) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnsafeBufferUsageAttrSpelling>(mx::UnsafeBufferUsageAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AcquireCapabilityAttr>(mx::AcquireCapabilityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BitIntType>(mx::BitIntType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPForSimdDirective>>(std::optional<mx::OMPForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeAliasDecl>>(gap::generator<mx::TypeAliasDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprSideEffectsKind>(mx::ExprSideEffectsKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnusedAttrSpelling>(mx::UnusedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AVRSignalAttr>(mx::AVRSignalAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BTFTagAttributedType>(mx::BTFTagAttributedType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprisModifiableLvalueResult>(mx::ExprisModifiableLvalueResult) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UseHandleAttrSpelling>(mx::UseHandleAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPForDirective>>(gap::generator<mx::OMPForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeAliasDecl>>(std::optional<mx::TypeAliasDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AVRInterruptAttr>(mx::AVRInterruptAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AttributedType>(mx::AttributedType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExternalSourceSymbolAttrSpelling>(mx::ExternalSourceSymbolAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UsedAttrSpelling>(mx::UsedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPForDirective>>(std::optional<mx::OMPForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeAliasTemplateDecl>>(std::optional<mx::TypeAliasTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FallThroughAttrSpelling>(mx::FallThroughAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UserDefinedLiteralLiteralOperatorKind>(mx::UserDefinedLiteralLiteralOperatorKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ARMInterruptAttr>(mx::ARMInterruptAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AtomicType>(mx::AtomicType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FastCallAttrSpelling>(mx::FastCallAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UsingIfExistsAttrSpelling>(mx::UsingIfExistsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AMDGPUWavesPerEUAttr>(mx::AMDGPUWavesPerEUAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IncompleteArrayType>(mx::IncompleteArrayType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeAliasTemplateDecl>>(gap::generator<mx::TypeAliasTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FinalAttrSpelling>(mx::FinalAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UuidAttrSpelling>(mx::UuidAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AMDGPUNumVGPRAttr>(mx::AMDGPUNumVGPRAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DependentSizedArrayType>(mx::DependentSizedArrayType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FlagEnumAttrSpelling>(mx::FlagEnumAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VarDeclDefinitionKind>(mx::VarDeclDefinitionKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FlattenAttrSpelling>(mx::FlattenAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VarDeclInitializationStyle>(mx::VarDeclInitializationStyle) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AMDGPUNumSGPRAttr>(mx::AMDGPUNumSGPRAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstantArrayType>(mx::ConstantArrayType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDistributeSimdDirective>>(gap::generator<mx::OMPDistributeSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDistributeSimdDirective>>(std::optional<mx::OMPDistributeSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FormatArgAttrSpelling>(mx::FormatArgAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VarDeclTLSKind>(mx::VarDeclTLSKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AMDGPUKernelCallAttr>(mx::AMDGPUKernelCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AdjustedType>(mx::AdjustedType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BuiltinTemplateDecl>>(gap::generator<mx::BuiltinTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FormatAttrSpelling>(mx::FormatAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VecReturnAttrSpelling>(mx::VecReturnAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDistributeParallelForSimdDirective>>(gap::generator<mx::OMPDistributeParallelForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BuiltinTemplateDecl>>(std::optional<mx::BuiltinTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AMDGPUFlatWorkGroupSizeAttr>(mx::AMDGPUFlatWorkGroupSizeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DecayedType>(mx::DecayedType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionDeclTemplatedKind>(mx::FunctionDeclTemplatedKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VectorCallAttrSpelling>(mx::VectorCallAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDistributeParallelForSimdDirective>>(std::optional<mx::OMPDistributeParallelForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionReturnThunksAttrKind>(mx::FunctionReturnThunksAttrKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VisibilityAttrSpelling>(mx::VisibilityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AArch64VectorPcsAttr>(mx::AArch64VectorPcsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeWithKeyword>(mx::TypeWithKeyword) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionReturnThunksAttrSpelling>(mx::FunctionReturnThunksAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VisibilityAttrVisibilityType>(mx::VisibilityAttrVisibilityType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NamespaceAliasDecl>>(gap::generator<mx::NamespaceAliasDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AArch64SVEPcsAttr>(mx::AArch64SVEPcsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ElaboratedType>(mx::ElaboratedType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TemplateTemplateParmDecl>>(gap::generator<mx::TemplateTemplateParmDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionTypeAArch64SMETypeAttributes>(mx::FunctionTypeAArch64SMETypeAttributes) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WarnUnusedAttrSpelling>(mx::WarnUnusedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TemplateTemplateParmDecl>>(std::optional<mx::TemplateTemplateParmDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ZeroCallUsedRegsAttr>(mx::ZeroCallUsedRegsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DependentTemplateSpecializationType>(mx::DependentTemplateSpecializationType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDistributeParallelForDirective>>(gap::generator<mx::OMPDistributeParallelForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionTypeArmStateValue>(mx::FunctionTypeArmStateValue) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WarnUnusedResultAttrSpelling>(mx::WarnUnusedResultAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDistributeParallelForDirective>>(std::optional<mx::OMPDistributeParallelForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GNUInlineAttrSpelling>(mx::GNUInlineAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WeakAttrSpelling>(mx::WeakAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::XRayLogArgsAttr>(mx::XRayLogArgsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DependentNameType>(mx::DependentNameType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GuardedVarAttrSpelling>(mx::GuardedVarAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WeakImportAttrSpelling>(mx::WeakImportAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::XRayInstrumentAttr>(mx::XRayInstrumentAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VectorType>(mx::VectorType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HIPManagedAttrSpelling>(mx::HIPManagedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WeakRefAttrSpelling>(mx::WeakRefAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::X86ForceAlignArgPointerAttr>(mx::X86ForceAlignArgPointerAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExtVectorType>(mx::ExtVectorType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDistributeDirective>>(gap::generator<mx::OMPDistributeDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLParamModifierAttrSpelling>(mx::HLSLParamModifierAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WebAssemblyExportNameAttrSpelling>(mx::WebAssemblyExportNameAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCCompatibleAliasDecl>>(gap::generator<mx::ObjCCompatibleAliasDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDistributeDirective>>(std::optional<mx::OMPDistributeDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCCompatibleAliasDecl>>(std::optional<mx::ObjCCompatibleAliasDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLShaderAttrShaderType>(mx::HLSLShaderAttrShaderType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WebAssemblyImportModuleAttrSpelling>(mx::WebAssemblyImportModuleAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WorkGroupSizeHintAttr>(mx::WorkGroupSizeHintAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UsingType>(mx::UsingType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HotAttrSpelling>(mx::HotAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WebAssemblyImportNameAttrSpelling>(mx::WebAssemblyImportNameAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WebAssemblyImportNameAttr>(mx::WebAssemblyImportNameAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UsingShadowDecl>(mx::UsingShadowDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IBActionAttrSpelling>(mx::IBActionAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::X86ForceAlignArgPointerAttrSpelling>(mx::X86ForceAlignArgPointerAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NamespaceAliasDecl>>(std::optional<mx::NamespaceAliasDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AllocSizeAttrSpelling>(mx::AllocSizeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WebAssemblyImportModuleAttr>(mx::WebAssemblyImportModuleAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTeamsGenericLoopDirective>>(gap::generator<mx::OMPTeamsGenericLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IBOutletAttrSpelling>(mx::IBOutletAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::XRayInstrumentAttrSpelling>(mx::XRayInstrumentAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTeamsGenericLoopDirective>>(std::optional<mx::OMPTeamsGenericLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BaseUsingDecl>(mx::BaseUsingDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LinkageSpecDecl>>(gap::generator<mx::LinkageSpecDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IBOutletCollectionAttrSpelling>(mx::IBOutletCollectionAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::XRayLogArgsAttrSpelling>(mx::XRayLogArgsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WebAssemblyExportNameAttr>(mx::WebAssemblyExportNameAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnresolvedUsingType>(mx::UnresolvedUsingType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTeamsDistributeParallelForSimdDirective>>(gap::generator<mx::OMPTeamsDistributeParallelForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IFuncAttrSpelling>(mx::IFuncAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ZeroCallUsedRegsAttrSpelling>(mx::ZeroCallUsedRegsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WeakRefAttr>(mx::WeakRefAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnaryTransformType>(mx::UnaryTransformType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LinkageSpecDecl>>(std::optional<mx::LinkageSpecDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ImplicitCastExprOnStack>(mx::ImplicitCastExprOnStack) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ZeroCallUsedRegsAttrZeroCallUsedRegsKind>(mx::ZeroCallUsedRegsAttrZeroCallUsedRegsKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTeamsDistributeSimdDirective>>(gap::generator<mx::OMPTeamsDistributeSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTeamsDistributeSimdDirective>>(std::optional<mx::OMPTeamsDistributeSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WeakImportAttr>(mx::WeakImportAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnresolvedUsingTypenameDecl>(mx::UnresolvedUsingTypenameDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InitPriorityAttrSpelling>(mx::InitPriorityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ASTDumpOutputFormat>(mx::ASTDumpOutputFormat) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ImportDecl>>(gap::generator<mx::ImportDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IntelOclBiccAttrSpelling>(mx::IntelOclBiccAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AccessSpecifier>(mx::AccessSpecifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WeakAttr>(mx::WeakAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypedefType>(mx::TypedefType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTeamsDistributeParallelForSimdDirective>>(std::optional<mx::OMPTeamsDistributeParallelForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ImportDecl>>(std::optional<mx::ImportDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InternalLinkageAttrSpelling>(mx::InternalLinkageAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AddrSpaceMapMangling>(mx::AddrSpaceMapMangling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WarnUnusedResultAttr>(mx::WarnUnusedResultAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeOfType>(mx::TypeOfType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Visibility>>(std::optional<mx::Visibility>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LTOVisibilityPublicAttrSpelling>(mx::LTOVisibilityPublicAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AlignRequirementKind>(mx::AlignRequirementKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ValueDecl>>(std::optional<mx::ValueDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FriendTemplateDecl>>(gap::generator<mx::FriendTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WarnUnusedAttr>(mx::WarnUnusedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeOfExprType>(mx::TypeOfExprType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LeafAttrSpelling>(mx::LeafAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AltivecSrcCompatKind>(mx::AltivecSrcCompatKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTeamsDistributeParallelForDirective>>(gap::generator<mx::OMPTeamsDistributeParallelForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCContainerDecl>>(gap::generator<mx::ObjCContainerDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LifetimeBoundAttrSpelling>(mx::LifetimeBoundAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArgumentKind>(mx::ArgumentKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VisibilityAttr>(mx::VisibilityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SEHTryStmt>(mx::SEHTryStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTeamsDistributeParallelForDirective>>(std::optional<mx::OMPTeamsDistributeParallelForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FriendTemplateDecl>>(std::optional<mx::FriendTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCMethodDecl>>(gap::generator<mx::ObjCMethodDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LikelyAttrSpelling>(mx::LikelyAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArraySizeModifier>(mx::ArraySizeModifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VectorCallAttr>(mx::VectorCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SEHExceptStmt>(mx::SEHExceptStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LoaderUninitializedAttrSpelling>(mx::LoaderUninitializedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArrayTypeTrait>(mx::ArrayTypeTrait) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Index>(mx::Index) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VecTypeHintAttr>(mx::VecTypeHintAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CompoundStmt>(mx::CompoundStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LoopHintAttrLoopHintState>(mx::LoopHintAttrLoopHintState) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AtomicScopeModelKind>(mx::AtomicScopeModelKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AMDGPUKernelCallAttrSpelling>(mx::AMDGPUKernelCallAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LoopHintAttrOptionType>(mx::LoopHintAttrOptionType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AutoTypeKeyword>(mx::AutoTypeKeyword) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VecReturnAttr>(mx::VecReturnAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SEHFinallyStmt>(mx::SEHFinallyStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTeamsDistributeDirective>>(gap::generator<mx::OMPTeamsDistributeDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LoopHintAttrSpelling>(mx::LoopHintAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AvailabilityResult>(mx::AvailabilityResult) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTeamsDistributeDirective>>(std::optional<mx::OMPTeamsDistributeDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UuidAttr>(mx::UuidAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SEHLeaveStmt>(mx::SEHLeaveStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FileScopeAsmDecl>>(gap::generator<mx::FileScopeAsmDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::M68kRTDAttrSpelling>(mx::M68kRTDAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BinaryOperatorKind>(mx::BinaryOperatorKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Token>>(std::optional<mx::Token>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSGuidDecl>(mx::MSGuidDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReturnStmt>(mx::ReturnStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FileScopeAsmDecl>>(std::optional<mx::FileScopeAsmDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MIGServerRoutineAttrSpelling>(mx::MIGServerRoutineAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Bits>(mx::Bits) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTaskLoopSimdDirective>>(gap::generator<mx::OMPTaskLoopSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSABIAttrSpelling>(mx::MSABIAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXConstructionKind>(mx::CXXConstructionKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UsingIfExistsAttr>(mx::UsingIfExistsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCForCollectionStmt>(mx::ObjCForCollectionStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTaskLoopSimdDirective>>(std::optional<mx::OMPTaskLoopSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ExternCContextDecl>>(gap::generator<mx::ExternCContextDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSInheritanceAttrSpelling>(mx::MSInheritanceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXNewInitializationStyle>(mx::CXXNewInitializationStyle) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UsedAttr>(mx::UsedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCAutoreleasePoolStmt>(mx::ObjCAutoreleasePoolStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSP430InterruptAttrSpelling>(mx::MSP430InterruptAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CallingConv>(mx::CallingConv) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTaskLoopDirective>>(gap::generator<mx::OMPTaskLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ExternCContextDecl>>(std::optional<mx::ExternCContextDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnusedAttr>(mx::UnusedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCAtTryStmt>(mx::ObjCAtTryStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSStructAttrSpelling>(mx::MSStructAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CanThrowResult>(mx::CanThrowResult) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTaskLoopDirective>>(std::optional<mx::OMPTaskLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ExportDecl>>(gap::generator<mx::ExportDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MayAliasAttrSpelling>(mx::MayAliasAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CapturedRegionKind>(mx::CapturedRegionKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TemplateArgument>>(gap::generator<mx::TemplateArgument>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnsafeBufferUsageAttr>(mx::UnsafeBufferUsageAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCAtFinallyStmt>(mx::ObjCAtFinallyStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MaybeUndefAttrSpelling>(mx::MaybeUndefAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CastKind>(mx::CastKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UninitializedAttr>(mx::UninitializedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCAtCatchStmt>(mx::ObjCAtCatchStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ExportDecl>>(std::optional<mx::ExportDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MicroMipsAttrSpelling>(mx::MicroMipsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CharacterLiteralKind>(mx::CharacterLiteralKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetTeamsGenericLoopDirective>>(gap::generator<mx::OMPTargetTeamsGenericLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnavailableAttr>(mx::UnavailableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCAtThrowStmt>(mx::ObjCAtThrowStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MinSizeAttrSpelling>(mx::MinSizeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ClangABI>(mx::ClangABI) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetTeamsGenericLoopDirective>>(std::optional<mx::OMPTargetTeamsGenericLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MinVectorWidthAttrSpelling>(mx::MinVectorWidthAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CommentKind>(mx::CommentKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeVisibilityAttr>(mx::TypeVisibilityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCAtSynchronizedStmt>(mx::ObjCAtSynchronizedStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::EmptyDecl>>(gap::generator<mx::EmptyDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetTeamsDistributeSimdDirective>>(gap::generator<mx::OMPTargetTeamsDistributeSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Mips16AttrSpelling>(mx::Mips16AttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ComparisonCategoryResult>(mx::ComparisonCategoryResult) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeTagForDatatypeAttr>(mx::TypeTagForDatatypeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPExecutableDirective>(mx::OMPExecutableDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EmptyDecl>>(std::optional<mx::EmptyDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetTeamsDistributeSimdDirective>>(std::optional<mx::OMPTargetTeamsDistributeSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MipsInterruptAttrInterruptType>(mx::MipsInterruptAttrInterruptType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ComparisonCategoryType>(mx::ComparisonCategoryType) noexcept;

template MX_EXPORT SharedPyObject *to_python<FilePathMap>(FilePathMap) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TryAcquireCapabilityAttr>(mx::TryAcquireCapabilityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CapturedStmt>(mx::CapturedStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MipsInterruptAttrSpelling>(mx::MipsInterruptAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CompilingModuleKind>(mx::CompilingModuleKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetTeamsDistributeParallelForSimdDirective>>(gap::generator<mx::OMPTargetTeamsDistributeParallelForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MipsLongCallAttrSpelling>(mx::MipsLongCallAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ComplexRangeKind>(mx::ComplexRangeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TrivialABIAttr>(mx::TrivialABIAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CapturedDecl>(mx::CapturedDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetTeamsDistributeParallelForSimdDirective>>(std::optional<mx::OMPTargetTeamsDistributeParallelForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MipsShortCallAttrSpelling>(mx::MipsShortCallAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstantResultStorageKind>(mx::ConstantResultStorageKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TransparentUnionAttr>(mx::TransparentUnionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPErrorDirective>(mx::OMPErrorDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ModeAttrSpelling>(mx::ModeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstexprSpecKind>(mx::ConstexprSpecKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetTeamsDistributeParallelForDirective>>(gap::generator<mx::OMPTargetTeamsDistributeParallelForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ThisCallAttr>(mx::ThisCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDispatchDirective>(mx::OMPDispatchDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MustTailAttrSpelling>(mx::MustTailAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoreFoundationABI>(mx::CoreFoundationABI) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetTeamsDistributeParallelForDirective>>(std::optional<mx::OMPTargetTeamsDistributeParallelForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSConsumedAttrSpelling>(mx::NSConsumedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DataPositionTy>(mx::DataPositionTy) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TestTypestateAttr>(mx::TestTypestateAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDepobjDirective>(mx::OMPDepobjDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCInterfaceDecl>>(gap::generator<mx::ObjCInterfaceDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSConsumesSelfAttrSpelling>(mx::NSConsumesSelfAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeductionCandidate>(mx::DeductionCandidate) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TargetVersionAttr>(mx::TargetVersionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPCriticalDirective>(mx::OMPCriticalDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSReturnsAutoreleasedAttrSpelling>(mx::NSReturnsAutoreleasedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DefaultArgKind>(mx::DefaultArgKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TargetClonesAttr>(mx::TargetClonesAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPCancellationPointDirective>(mx::OMPCancellationPointDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroVAOpt>>(gap::generator<mx::MacroVAOpt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSReturnsNotRetainedAttrSpelling>(mx::NSReturnsNotRetainedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DefaultCallingConvention>(mx::DefaultCallingConvention) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroSubstitution>>(gap::generator<mx::MacroSubstitution>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetTeamsDistributeDirective>>(gap::generator<mx::OMPTargetTeamsDistributeDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSReturnsRetainedAttrSpelling>(mx::NSReturnsRetainedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DefaultVisiblityExportMapping>(mx::DefaultVisiblityExportMapping) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TargetAttr>(mx::TargetAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPCancelDirective>(mx::OMPCancelDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetTeamsDistributeDirective>>(std::optional<mx::OMPTargetTeamsDistributeDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroSubstitution>>(std::optional<mx::MacroSubstitution>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NVPTXKernelAttrSpelling>(mx::NVPTXKernelAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DesignatorKind>(mx::DesignatorKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TLSModelAttr>(mx::TLSModelAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPBarrierDirective>(mx::OMPBarrierDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NakedAttrSpelling>(mx::NakedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DiagnosticLevelMask>(mx::DiagnosticLevelMask) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetSimdDirective>>(gap::generator<mx::OMPTargetSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SysVABIAttr>(mx::SysVABIAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPAtomicDirective>(mx::OMPAtomicDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NamedDeclExplicitVisibilityKind>(mx::NamedDeclExplicitVisibilityKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ElaboratedTypeKeyword>(mx::ElaboratedTypeKeyword) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetSimdDirective>>(std::optional<mx::OMPTargetSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoBuiltinAttrSpelling>(mx::NoBuiltinAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EscapeChar>(mx::EscapeChar) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftPrivateAttr>(mx::SwiftPrivateAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTeamsDirective>(mx::OMPTeamsDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroVAOpt>>(std::optional<mx::MacroVAOpt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoCommonAttrSpelling>(mx::NoCommonAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExceptionHandlingKind>(mx::ExceptionHandlingKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftNewTypeAttr>(mx::SwiftNewTypeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTaskyieldDirective>(mx::OMPTaskyieldDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetParallelGenericLoopDirective>>(gap::generator<mx::OMPTargetParallelGenericLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoDebugAttrSpelling>(mx::NoDebugAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExceptionSpecificationType>(mx::ExceptionSpecificationType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetParallelGenericLoopDirective>>(std::optional<mx::OMPTargetParallelGenericLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftNameAttr>(mx::SwiftNameAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTaskwaitDirective>(mx::OMPTaskwaitDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoDerefAttrSpelling>(mx::NoDerefAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExcessPrecisionKind>(mx::ExcessPrecisionKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoDestroyAttrSpelling>(mx::NoDestroyAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExplicitSpecKind>(mx::ExplicitSpecKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftImportPropertyAsAccessorsAttr>(mx::SwiftImportPropertyAsAccessorsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTaskgroupDirective>(mx::OMPTaskgroupDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TokenContext>>(std::optional<mx::TokenContext>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoDuplicateAttrSpelling>(mx::NoDuplicateAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprDependence>(mx::ExprDependence) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftImportAsNonGenericAttr>(mx::SwiftImportAsNonGenericAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTaskDirective>(mx::OMPTaskDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetParallelForSimdDirective>>(gap::generator<mx::OMPTargetParallelForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoEscapeAttrSpelling>(mx::NoEscapeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprObjectKind>(mx::ExprObjectKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetParallelForSimdDirective>>(std::optional<mx::OMPTargetParallelForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftErrorAttr>(mx::SwiftErrorAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetUpdateDirective>(mx::OMPTargetUpdateDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoInlineAttrSpelling>(mx::NoInlineAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprOffsets>(mx::ExprOffsets) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoInstrumentFunctionAttrSpelling>(mx::NoInstrumentFunctionAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprValueKind>(mx::ExprValueKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftCallAttr>(mx::SwiftCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetTeamsDirective>(mx::OMPTargetTeamsDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPSimdDirective>>(gap::generator<mx::OMPSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<std::pair<uint32_t, uint32_t>>>(std::optional<std::pair<uint32_t, uint32_t>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoMergeAttrSpelling>(mx::NoMergeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExpressionTrait>(mx::ExpressionTrait) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetParallelForDirective>>(gap::generator<mx::OMPTargetParallelForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftBridgedTypedefAttr>(mx::SwiftBridgedTypedefAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetParallelDirective>(mx::OMPTargetParallelDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EmptyTokenTreeNode>>(std::optional<mx::EmptyTokenTreeNode>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetParallelForDirective>>(std::optional<mx::OMPTargetParallelForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoMicroMipsAttrSpelling>(mx::NoMicroMipsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExtKind>(mx::ExtKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Decl>(mx::Decl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCProtocolDecl>>(gap::generator<mx::ObjCProtocolDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftBridgeAttr>(mx::SwiftBridgeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetExitDataDirective>(mx::OMPTargetExitDataDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoMips16AttrSpelling>(mx::NoMips16AttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExtendArgsKind>(mx::ExtendArgsKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoProfileFunctionAttrSpelling>(mx::NoProfileFunctionAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FPEvalMethodKind>(mx::FPEvalMethodKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAttrAttr>(mx::SwiftAttrAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelSectionsDirective>(mx::OMPParallelSectionsDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TokenTokenTreeNode>>(std::optional<mx::TokenTokenTreeNode>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoRandomizeLayoutAttrSpelling>(mx::NoRandomizeLayoutAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FPExceptionModeKind>(mx::FPExceptionModeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ChoiceTokenTreeNode>>(std::optional<mx::ChoiceTokenTreeNode>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncNameAttr>(mx::SwiftAsyncNameAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetEnterDataDirective>(mx::OMPTargetEnterDataDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPSimdDirective>>(std::optional<mx::OMPSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<std::pair<mx::Fragment, mx::TokenTreeNode>>>(gap::generator<std::pair<mx::Fragment, mx::TokenTreeNode>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoReturnAttrSpelling>(mx::NoReturnAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FPModeKind>(mx::FPModeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroVAOptArgument>>(gap::generator<mx::MacroVAOptArgument>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncErrorAttr>(mx::SwiftAsyncErrorAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetDirective>(mx::OMPTargetDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SubstitutionTokenTreeNode>>(std::optional<mx::SubstitutionTokenTreeNode>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoSanitizeAttrSpelling>(mx::NoSanitizeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Flags>(mx::Flags) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<uint64_t>>(std::optional<uint64_t>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoSpeculativeLoadHardeningAttrSpelling>(mx::NoSpeculativeLoadHardeningAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GC>(mx::GC) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncCallAttr>(mx::SwiftAsyncCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetDataDirective>(mx::OMPTargetDataDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelMasterTaskLoopSimdDirective>>(gap::generator<mx::OMPParallelMasterTaskLoopSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoSplitStackAttrSpelling>(mx::NoSplitStackAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GCMode>(mx::GCMode) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelMasterTaskLoopSimdDirective>>(std::optional<mx::OMPParallelMasterTaskLoopSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncAttr>(mx::SwiftAsyncAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPSingleDirective>(mx::OMPSingleDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TokenRange>>(std::optional<mx::TokenRange>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TokenTreeNode>>(gap::generator<mx::TokenTreeNode>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SequenceTokenTreeNode>>(std::optional<mx::SequenceTokenTreeNode>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoStackProtectorAttrSpelling>(mx::NoStackProtectorAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GPUDefaultStreamKind>(mx::GPUDefaultStreamKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<std::string_view>>(std::optional<std::string_view>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Stmt>(mx::Stmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StrictGuardStackCheckAttr>(mx::StrictGuardStackCheckAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPSectionsDirective>(mx::OMPSectionsDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoThreadSafetyAnalysisAttrSpelling>(mx::NoThreadSafetyAnalysisAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GVALinkage>(mx::GVALinkage) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroVAOptArgument>>(std::optional<mx::MacroVAOptArgument>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoThrowAttrSpelling>(mx::NoThrowAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GetBuiltinTypeError>(mx::GetBuiltinTypeError) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StrictFPAttr>(mx::StrictFPAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPSectionDirective>(mx::OMPSectionDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelMasterTaskLoopDirective>>(gap::generator<mx::OMPParallelMasterTaskLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroExpansion>>(gap::generator<mx::MacroExpansion>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelMasterTaskLoopDirective>>(std::optional<mx::OMPParallelMasterTaskLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoUniqueAddressAttrSpelling>(mx::NoUniqueAddressAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLLangStd>(mx::HLSLLangStd) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RegexQueryMatch>>(gap::generator<mx::RegexQueryMatch>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StdCallAttr>(mx::StdCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPScopeDirective>(mx::OMPScopeDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroConcatenate>>(gap::generator<mx::MacroConcatenate>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoUwtableAttrSpelling>(mx::NoUwtableAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ID>(mx::ID) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelMaskedTaskLoopSimdDirective>>(gap::generator<mx::OMPParallelMaskedTaskLoopSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StandaloneDebugAttr>(mx::StandaloneDebugAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPScanDirective>(mx::OMPScanDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Compilation>(mx::Compilation) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NonNullAttrSpelling>(mx::NonNullAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IdentifierInfoFlag>(mx::IdentifierInfoFlag) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroConcatenate>>(std::optional<mx::MacroConcatenate>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroStringify>>(gap::generator<mx::MacroStringify>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelMaskedTaskLoopSimdDirective>>(std::optional<mx::OMPParallelMaskedTaskLoopSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NotTailCalledAttrSpelling>(mx::NotTailCalledAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IfStatementKind>(mx::IfStatementKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SpeculativeLoadHardeningAttr>(mx::SpeculativeLoadHardeningAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelMasterDirective>(mx::OMPParallelMasterDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroStringify>>(std::optional<mx::MacroStringify>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPAllocateDeclAttrAllocatorTypeTy>(mx::OMPAllocateDeclAttrAllocatorTypeTy) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ImplicitParamKind>(mx::ImplicitParamKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SharedTrylockFunctionAttr>(mx::SharedTrylockFunctionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelMaskedDirective>(mx::OMPParallelMaskedDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DefineMacroDirective>>(gap::generator<mx::DefineMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclareSimdDeclAttrBranchStateTy>(mx::OMPDeclareSimdDeclAttrBranchStateTy) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InClassInitStyle>(mx::InClassInitStyle) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroExpansion>>(std::optional<mx::MacroExpansion>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroDirective>>(gap::generator<mx::MacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SetTypestateAttr>(mx::SetTypestateAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelDirective>(mx::OMPParallelDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclareTargetDeclAttrDevTypeTy>(mx::OMPDeclareTargetDeclAttrDevTypeTy) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InheritedDesignatedInitializersState>(mx::InheritedDesignatedInitializersState) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelMaskedTaskLoopDirective>>(gap::generator<mx::OMPParallelMaskedTaskLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroArgument>>(gap::generator<mx::MacroArgument>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelMaskedTaskLoopDirective>>(std::optional<mx::OMPParallelMaskedTaskLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroDirective>>(std::optional<mx::MacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclareTargetDeclAttrMapTypeTy>(mx::OMPDeclareTargetDeclAttrMapTypeTy) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InitStorageKind>(mx::InitStorageKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SentinelAttr>(mx::SentinelAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPOrderedDirective>(mx::OMPOrderedDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroArgument>>(std::optional<mx::MacroArgument>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSConsumedAttrSpelling>(mx::OSConsumedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InlineVariableDefinitionKind>(mx::InlineVariableDefinitionKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DefineMacroDirective>>(std::optional<mx::DefineMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SelectAnyAttr>(mx::SelectAnyAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPMetaDirective>(mx::OMPMetaDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSConsumesThisAttrSpelling>(mx::OSConsumesThisAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InterestingIdentifierKind>(mx::InterestingIdentifierKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelGenericLoopDirective>>(gap::generator<mx::OMPParallelGenericLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SectionAttr>(mx::SectionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPMasterDirective>(mx::OMPMasterDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelGenericLoopDirective>>(std::optional<mx::OMPParallelGenericLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSReturnsNotRetainedAttrSpelling>(mx::OSReturnsNotRetainedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Kinds>(mx::Kinds) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AArch64VectorPcsAttrSpelling>(mx::AArch64VectorPcsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OtherMacroDirective>>(gap::generator<mx::OtherMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSReturnsRetainedAttrSpelling>(mx::OSReturnsRetainedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LambdaCaptureDefault>(mx::LambdaCaptureDefault) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ScopedLockableAttr>(mx::ScopedLockableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPMaskedDirective>(mx::OMPMaskedDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroParameterSubstitution>>(gap::generator<mx::MacroParameterSubstitution>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroParameterSubstitution>>(std::optional<mx::MacroParameterSubstitution>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSReturnsRetainedOnNonZeroAttrSpelling>(mx::OSReturnsRetainedOnNonZeroAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LambdaCaptureKind>(mx::LambdaCaptureKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<std::string_view>>(gap::generator<std::string_view>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AMDGPUFlatWorkGroupSizeAttrSpelling>(mx::AMDGPUFlatWorkGroupSizeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SYCLSpecialClassAttr>(mx::SYCLSpecialClassAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPLoopBasedDirective>(mx::OMPLoopBasedDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelForSimdDirective>>(gap::generator<mx::OMPParallelForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<std::pair<mx::IncludePathLocation, std::filesystem::path>>>(gap::generator<std::pair<mx::IncludePathLocation, std::filesystem::path>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroParameter>>(gap::generator<mx::MacroParameter>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSReturnsRetainedOnZeroAttrSpelling>(mx::OSReturnsRetainedOnZeroAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LangAS>(mx::LangAS) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelForSimdDirective>>(std::optional<mx::OMPParallelForSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AliasAttrSpelling>(mx::AliasAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SYCLKernelAttr>(mx::SYCLKernelAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPLoopTransformationDirective>(mx::OMPLoopTransformationDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBoxableAttrSpelling>(mx::ObjCBoxableAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LangFeatures>(mx::LangFeatures) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroParameter>>(std::optional<mx::MacroParameter>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PragmaMacroDirective>>(gap::generator<mx::PragmaMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AMDGPUNumSGPRAttrSpelling>(mx::AMDGPUNumSGPRAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AlignedAttrSpelling>(mx::AlignedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBridgeAttrSpelling>(mx::ObjCBridgeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Language>(mx::Language) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReturnsTwiceAttr>(mx::ReturnsTwiceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPUnrollDirective>(mx::OMPUnrollDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelForDirective>>(gap::generator<mx::OMPParallelForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PragmaMacroDirective>>(std::optional<mx::PragmaMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBridgeMutableAttrSpelling>(mx::ObjCBridgeMutableAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LanguageLinkage>(mx::LanguageLinkage) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelForDirective>>(std::optional<mx::OMPParallelForDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReturnsNonNullAttr>(mx::ReturnsNonNullAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTileDirective>(mx::OMPTileDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UndefineMacroDirective>>(gap::generator<mx::UndefineMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AMDGPUNumVGPRAttrSpelling>(mx::AMDGPUNumVGPRAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBridgeRelatedAttrSpelling>(mx::ObjCBridgeRelatedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LaxVectorConversionKind>(mx::LaxVectorConversionKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UndefineMacroDirective>>(std::optional<mx::UndefineMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReturnTypestateAttr>(mx::ReturnTypestateAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPLoopDirective>(mx::OMPLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OtherMacroDirective>>(std::optional<mx::OtherMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCClassStubAttrSpelling>(mx::ObjCClassStubAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Level>(mx::Level) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Fragment>>(std::optional<mx::Fragment>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCDesignatedInitializerAttrSpelling>(mx::ObjCDesignatedInitializerAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Linkage>(mx::Linkage) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RetainAttr>(mx::RetainAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPGenericLoopDirective>(mx::OMPGenericLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPMasterTaskLoopSimdDirective>>(gap::generator<mx::OMPMasterTaskLoopSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCDirectAttrSpelling>(mx::ObjCDirectAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LinkageSpecLanguageIDs>(mx::LinkageSpecLanguageIDs) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::EndIfMacroDirective>>(gap::generator<mx::EndIfMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RestrictAttr>(mx::RestrictAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPForSimdDirective>(mx::OMPForSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPMasterTaskLoopSimdDirective>>(std::optional<mx::OMPMasterTaskLoopSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Fragment>(mx::Fragment) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<SpecificEntityId<FragmentId>>>(std::optional<SpecificEntityId<FragmentId>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConditionalMacroDirective>>(gap::generator<mx::ConditionalMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCDirectMembersAttrSpelling>(mx::ObjCDirectMembersAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSInheritanceModel>(mx::MSInheritanceModel) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConditionalMacroDirective>>(std::optional<mx::ConditionalMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EndIfMacroDirective>>(std::optional<mx::EndIfMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RequiresCapabilityAttr>(mx::RequiresCapabilityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPForDirective>(mx::OMPForDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCExceptionAttrSpelling>(mx::ObjCExceptionAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSVCMajorVersion>(mx::MSVCMajorVersion) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ElseMacroDirective>>(gap::generator<mx::ElseMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCExplicitProtocolImplAttrSpelling>(mx::ObjCExplicitProtocolImplAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSVtorDispMode>(mx::MSVtorDispMode) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReqdWorkGroupSizeAttr>(mx::ReqdWorkGroupSizeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDistributeSimdDirective>(mx::OMPDistributeSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPMasterTaskLoopDirective>>(gap::generator<mx::OMPMasterTaskLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPMasterTaskLoopDirective>>(std::optional<mx::OMPMasterTaskLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ElseMacroDirective>>(std::optional<mx::ElseMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroVAOptArgument>(mx::MacroVAOptArgument) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TransparentUnionAttr>>(gap::generator<mx::TransparentUnionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PreserveMostAttr>>(std::optional<mx::PreserveMostAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PreserveAllAttr>>(gap::generator<mx::PreserveAllAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroConcatenate>(mx::MacroConcatenate) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TransparentUnionAttr>>(std::optional<mx::TransparentUnionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ElseIfNotDefinedMacroDirective>>(gap::generator<mx::ElseIfNotDefinedMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ElseIfNotDefinedMacroDirective>>(std::optional<mx::ElseIfNotDefinedMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroStringify>(mx::MacroStringify) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PreserveAllAttr>>(std::optional<mx::PreserveAllAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ThisCallAttr>>(std::optional<mx::ThisCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TestTypestateAttr>>(gap::generator<mx::TestTypestateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroExpansion>(mx::MacroExpansion) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ElseIfDefinedMacroDirective>>(gap::generator<mx::ElseIfDefinedMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PreferredTypeAttr>>(std::optional<mx::PreferredTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WhileStmt>>(gap::generator<mx::WhileStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Macro>(mx::Macro) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ElseIfDefinedMacroDirective>>(std::optional<mx::ElseIfDefinedMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PreferredNameAttr>>(gap::generator<mx::PreferredNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ElseIfMacroDirective>>(gap::generator<mx::ElseIfMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroArgument>(mx::MacroArgument) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TestTypestateAttr>>(std::optional<mx::TestTypestateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WhileStmt>>(std::optional<mx::WhileStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TargetVersionAttr>>(gap::generator<mx::TargetVersionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ElseIfMacroDirective>>(std::optional<mx::ElseIfMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PreferredNameAttr>>(std::optional<mx::PreferredNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroParameterSubstitution>(mx::MacroParameterSubstitution) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IfMacroDirective>>(gap::generator<mx::IfMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PointerAttr>>(gap::generator<mx::PointerAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TargetVersionAttr>>(std::optional<mx::TargetVersionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IfNotDefinedMacroDirective>>(gap::generator<mx::IfNotDefinedMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroParameter>(mx::MacroParameter) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TargetClonesAttr>>(gap::generator<mx::TargetClonesAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DesignatedInitExpr>>(gap::generator<mx::DesignatedInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IfNotDefinedMacroDirective>>(std::optional<mx::IfNotDefinedMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DesignatedInitUpdateExpr>>(gap::generator<mx::DesignatedInitUpdateExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IfDefinedMacroDirective>>(gap::generator<mx::IfDefinedMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaMacroDirective>(mx::PragmaMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PragmaClangTextSectionAttr>>(gap::generator<mx::PragmaClangTextSectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DesignatedInitUpdateExpr>>(std::optional<mx::DesignatedInitUpdateExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TargetClonesAttr>>(std::optional<mx::TargetClonesAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PragmaClangTextSectionAttr>>(std::optional<mx::PragmaClangTextSectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IfDefinedMacroDirective>>(std::optional<mx::IfDefinedMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TargetAttr>>(gap::generator<mx::TargetAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UndefineMacroDirective>(mx::UndefineMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::InitListExpr>>(gap::generator<mx::InitListExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PragmaClangRodataSectionAttr>>(gap::generator<mx::PragmaClangRodataSectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IfMacroDirective>>(std::optional<mx::IfMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OtherMacroDirective>(mx::OtherMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TargetAttr>>(std::optional<mx::TargetAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PragmaClangRodataSectionAttr>>(std::optional<mx::PragmaClangRodataSectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TLSModelAttr>>(gap::generator<mx::TLSModelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::InitListExpr>>(std::optional<mx::InitListExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConditionalMacroDirective>(mx::ConditionalMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PragmaClangRelroSectionAttr>>(gap::generator<mx::PragmaClangRelroSectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IncludeLikeMacroDirective>>(gap::generator<mx::IncludeLikeMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TLSModelAttr>>(std::optional<mx::TLSModelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PragmaClangRelroSectionAttr>>(std::optional<mx::PragmaClangRelroSectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EndIfMacroDirective>(mx::EndIfMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IncludeLikeMacroDirective>>(std::optional<mx::IncludeLikeMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SysVABIAttr>>(gap::generator<mx::SysVABIAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ImportMacroDirective>>(gap::generator<mx::ImportMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ElseMacroDirective>(mx::ElseMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PragmaClangDataSectionAttr>>(gap::generator<mx::PragmaClangDataSectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ImportMacroDirective>>(std::optional<mx::ImportMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SysVABIAttr>>(std::optional<mx::SysVABIAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PragmaClangDataSectionAttr>>(std::optional<mx::PragmaClangDataSectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftPrivateAttr>>(gap::generator<mx::SwiftPrivateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ElseIfNotDefinedMacroDirective>(mx::ElseIfNotDefinedMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RedeclarableTemplateDecl>>(std::optional<mx::RedeclarableTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IncludeMacrosMacroDirective>>(gap::generator<mx::IncludeMacrosMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PragmaClangBSSSectionAttr>>(gap::generator<mx::PragmaClangBSSSectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IncludeMacrosMacroDirective>>(std::optional<mx::IncludeMacrosMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ElseIfDefinedMacroDirective>(mx::ElseIfDefinedMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftPrivateAttr>>(std::optional<mx::SwiftPrivateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PragmaClangBSSSectionAttr>>(std::optional<mx::PragmaClangBSSSectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftNewTypeAttr>>(gap::generator<mx::SwiftNewTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PointerAttr>>(std::optional<mx::PointerAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AlwaysDestroyAttrSpelling>(mx::AlwaysDestroyAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DesignatedInitExpr>>(std::optional<mx::DesignatedInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ElseIfMacroDirective>(mx::ElseIfMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IncludeNextMacroDirective>>(gap::generator<mx::IncludeNextMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OwnerAttr>>(gap::generator<mx::OwnerAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IncludeNextMacroDirective>>(std::optional<mx::IncludeNextMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftNewTypeAttr>>(std::optional<mx::SwiftNewTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IncludeMacroDirective>>(gap::generator<mx::IncludeMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IfNotDefinedMacroDirective>(mx::IfNotDefinedMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftNameAttr>>(gap::generator<mx::SwiftNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PcsAttr>>(gap::generator<mx::PcsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AlwaysInlineAttrSpelling>(mx::AlwaysInlineAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IncludeMacroDirective>>(std::optional<mx::IncludeMacroDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IfDefinedMacroDirective>(mx::IfDefinedMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PcsAttr>>(std::optional<mx::PcsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CoawaitExpr>>(gap::generator<mx::CoawaitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnnotateAttrSpelling>(mx::AnnotateAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftNameAttr>>(std::optional<mx::SwiftNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DependentScopeDeclRefExpr>>(gap::generator<mx::DependentScopeDeclRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DependentScopeDeclRefExpr>>(std::optional<mx::DependentScopeDeclRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnnotateTypeAttrSpelling>(mx::AnnotateTypeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IfMacroDirective>(mx::IfMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PascalAttr>>(gap::generator<mx::PascalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnyX86InterruptAttrSpelling>(mx::AnyX86InterruptAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PatchableFunctionEntryAttr>>(gap::generator<mx::PatchableFunctionEntryAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IncludeLikeMacroDirective>(mx::IncludeLikeMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftImportPropertyAsAccessorsAttr>>(gap::generator<mx::SwiftImportPropertyAsAccessorsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PatchableFunctionEntryAttr>>(std::optional<mx::PatchableFunctionEntryAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnyX86NoCallerSavedRegistersAttrSpelling>(mx::AnyX86NoCallerSavedRegistersAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftImportPropertyAsAccessorsAttr>>(std::optional<mx::SwiftImportPropertyAsAccessorsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftErrorAttr>>(gap::generator<mx::SwiftErrorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ImportMacroDirective>(mx::ImportMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnyX86NoCfCheckAttrSpelling>(mx::AnyX86NoCfCheckAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PascalAttr>>(std::optional<mx::PascalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DependentCoawaitExpr>>(gap::generator<mx::DependentCoawaitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftImportAsNonGenericAttr>>(gap::generator<mx::SwiftImportAsNonGenericAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ParamTypestateAttr>>(gap::generator<mx::ParamTypestateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArcWeakrefUnavailableAttrSpelling>(mx::ArcWeakrefUnavailableAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<EntityId>(EntityId) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IncludeMacrosMacroDirective>(mx::IncludeMacrosMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftImportAsNonGenericAttr>>(std::optional<mx::SwiftImportAsNonGenericAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DependentCoawaitExpr>>(std::optional<mx::DependentCoawaitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArgumentWithTypeTagAttrSpelling>(mx::ArgumentWithTypeTagAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IncludeNextMacroDirective>(mx::IncludeNextMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ParamTypestateAttr>>(std::optional<mx::ParamTypestateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmBuiltinAliasAttrSpelling>(mx::ArmBuiltinAliasAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftErrorAttr>>(std::optional<mx::SwiftErrorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PackedAttr>>(gap::generator<mx::PackedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CoroutineSuspendExpr>>(gap::generator<mx::CoroutineSuspendExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftCallAttr>>(gap::generator<mx::SwiftCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IncludeMacroDirective>(mx::IncludeMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmMveStrictPolymorphismAttrSpelling>(mx::ArmMveStrictPolymorphismAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PackedAttr>>(std::optional<mx::PackedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OverloadExpr>>(gap::generator<mx::OverloadExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArtificialAttrSpelling>(mx::ArtificialAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftCallAttr>>(std::optional<mx::SwiftCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OwnershipAttr>>(gap::generator<mx::OwnershipAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftBridgeAttr>>(gap::generator<mx::SwiftBridgeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AsmLabelAttrSpelling>(mx::AsmLabelAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OverloadExpr>>(std::optional<mx::OverloadExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftBridgedTypedefAttr>>(gap::generator<mx::SwiftBridgedTypedefAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AssertCapabilityAttrSpelling>(mx::AssertCapabilityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OwnershipAttr>>(std::optional<mx::OwnershipAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftBridgedTypedefAttr>>(std::optional<mx::SwiftBridgedTypedefAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AssumeAlignedAttrSpelling>(mx::AssumeAlignedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<VariantEntity>(VariantEntity) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OwnerAttr>>(std::optional<mx::OwnerAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXBaseSpecifier>>(std::optional<mx::CXXBaseSpecifier>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AssumptionAttrSpelling>(mx::AssumptionAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftBridgeAttr>>(std::optional<mx::SwiftBridgeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftAttrAttr>>(gap::generator<mx::SwiftAttrAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnresolvedLookupExpr>>(gap::generator<mx::UnresolvedLookupExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AtomicExprAtomicOp>(mx::AtomicExprAtomicOp) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OverrideAttr>>(gap::generator<mx::OverrideAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Decl>>(std::optional<mx::Decl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnresolvedLookupExpr>>(std::optional<mx::UnresolvedLookupExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AvailabilityAttrSpelling>(mx::AvailabilityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftAttrAttr>>(std::optional<mx::SwiftAttrAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OverrideAttr>>(std::optional<mx::OverrideAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftAsyncNameAttr>>(gap::generator<mx::SwiftAsyncNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AvailableOnlyInDefaultEvalMethodAttrSpelling>(mx::AvailableOnlyInDefaultEvalMethodAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OptimizeNoneAttr>>(gap::generator<mx::OptimizeNoneAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CoroutineSuspendExpr>>(std::optional<mx::CoroutineSuspendExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedStmtId>(PackedStmtId) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BPFPreserveAccessIndexAttrSpelling>(mx::BPFPreserveAccessIndexAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftAsyncNameAttr>>(std::optional<mx::SwiftAsyncNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OptimizeNoneAttr>>(std::optional<mx::OptimizeNoneAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BPFPreserveStaticOffsetAttrSpelling>(mx::BPFPreserveStaticOffsetAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftAsyncErrorAttr>>(gap::generator<mx::SwiftAsyncErrorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLKernelAttr>>(gap::generator<mx::OpenCLKernelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpaqueValueExpr>>(gap::generator<mx::OpaqueValueExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BTFDeclTagAttrSpelling>(mx::BTFDeclTagAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftAsyncErrorAttr>>(std::optional<mx::SwiftAsyncErrorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLKernelAttr>>(std::optional<mx::OpenCLKernelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BTFTypeTagAttrSpelling>(mx::BTFTypeTagAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpaqueValueExpr>>(std::optional<mx::OpaqueValueExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftAsyncCallAttr>>(gap::generator<mx::SwiftAsyncCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BlocksAttrBlockType>(mx::BlocksAttrBlockType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Stmt>>(gap::generator<mx::Stmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BlocksAttrSpelling>(mx::BlocksAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftAsyncCallAttr>>(std::optional<mx::SwiftAsyncCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLIntelReqdSubGroupSizeAttr>>(gap::generator<mx::OpenCLIntelReqdSubGroupSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftAsyncAttr>>(gap::generator<mx::SwiftAsyncAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLIntelReqdSubGroupSizeAttr>>(std::optional<mx::OpenCLIntelReqdSubGroupSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CoawaitExpr>>(std::optional<mx::CoawaitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BuiltinAliasAttrSpelling>(mx::BuiltinAliasAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCRootClassAttr>>(gap::generator<mx::ObjCRootClassAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VarDecl>>(gap::generator<mx::VarDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::filesystem::path>(std::filesystem::path) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BuiltinTypeKind>(mx::BuiltinTypeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftAsyncAttr>>(std::optional<mx::SwiftAsyncAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCSubclassingRestrictedAttr>>(gap::generator<mx::ObjCSubclassingRestrictedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CoyieldExpr>>(gap::generator<mx::CoyieldExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCSubclassingRestrictedAttr>>(std::optional<mx::ObjCSubclassingRestrictedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CDeclAttrSpelling>(mx::CDeclAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::StrictFPAttr>>(gap::generator<mx::StrictFPAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFAuditedTransferAttrSpelling>(mx::CFAuditedTransferAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CoyieldExpr>>(std::optional<mx::CoyieldExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::StrictGuardStackCheckAttr>>(gap::generator<mx::StrictGuardStackCheckAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCRootClassAttr>>(std::optional<mx::ObjCRootClassAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFConsumedAttrSpelling>(mx::CFConsumedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::StrictGuardStackCheckAttr>>(std::optional<mx::StrictGuardStackCheckAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConvertVectorExpr>>(gap::generator<mx::ConvertVectorExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFGuardAttrGuardArg>(mx::CFGuardAttrGuardArg) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedAttrId>(PackedAttrId) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::StrictFPAttr>>(std::optional<mx::StrictFPAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCReturnsInnerPointerAttr>>(gap::generator<mx::ObjCReturnsInnerPointerAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFGuardAttrSpelling>(mx::CFGuardAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::StdCallAttr>>(gap::generator<mx::StdCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCReturnsInnerPointerAttr>>(std::optional<mx::ObjCReturnsInnerPointerAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConvertVectorExpr>>(std::optional<mx::ConvertVectorExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCRequiresSuperAttr>>(gap::generator<mx::ObjCRequiresSuperAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TemplateDecl>>(gap::generator<mx::TemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFICanonicalJumpTableAttrSpelling>(mx::CFICanonicalJumpTableAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedMacroId>(PackedMacroId) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::StdCallAttr>>(std::optional<mx::StdCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFReturnsNotRetainedAttrSpelling>(mx::CFReturnsNotRetainedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCRequiresSuperAttr>>(std::optional<mx::ObjCRequiresSuperAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::StandaloneDebugAttr>>(gap::generator<mx::StandaloneDebugAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFReturnsRetainedAttrSpelling>(mx::CFReturnsRetainedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCOwnershipAttr>>(gap::generator<mx::ObjCOwnershipAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CompoundLiteralExpr>>(gap::generator<mx::CompoundLiteralExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConceptSpecializationExpr>>(gap::generator<mx::ConceptSpecializationExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFUnknownTransferAttrSpelling>(mx::CFUnknownTransferAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::StandaloneDebugAttr>>(std::optional<mx::StandaloneDebugAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCRequiresPropertyDefsAttr>>(gap::generator<mx::ObjCRequiresPropertyDefsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConceptSpecializationExpr>>(std::optional<mx::ConceptSpecializationExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCRequiresPropertyDefsAttr>>(std::optional<mx::ObjCRequiresPropertyDefsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CPUDispatchAttrSpelling>(mx::CPUDispatchAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCPreciseLifetimeAttr>>(gap::generator<mx::ObjCPreciseLifetimeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PtGuardedByAttr>>(gap::generator<mx::PtGuardedByAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CPUSpecificAttrSpelling>(mx::CPUSpecificAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::string_view>(std::string_view) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SpeculativeLoadHardeningAttr>>(gap::generator<mx::SpeculativeLoadHardeningAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCPreciseLifetimeAttr>>(std::optional<mx::ObjCPreciseLifetimeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SpeculativeLoadHardeningAttr>>(std::optional<mx::SpeculativeLoadHardeningAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDAConstantAttrSpelling>(mx::CUDAConstantAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SharedTrylockFunctionAttr>>(gap::generator<mx::SharedTrylockFunctionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDADeviceAttrSpelling>(mx::CUDADeviceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCOwnershipAttr>>(std::optional<mx::ObjCOwnershipAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ImplicitConceptSpecializationDecl>>(gap::generator<mx::ImplicitConceptSpecializationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SharedTrylockFunctionAttr>>(std::optional<mx::SharedTrylockFunctionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCNSObjectAttr>>(gap::generator<mx::ObjCNSObjectAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ImplicitConceptSpecializationDecl>>(std::optional<mx::ImplicitConceptSpecializationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDADeviceBuiltinSurfaceTypeAttrSpelling>(mx::CUDADeviceBuiltinSurfaceTypeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SetTypestateAttr>>(gap::generator<mx::SetTypestateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDADeviceBuiltinTextureTypeAttrSpelling>(mx::CUDADeviceBuiltinTextureTypeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCNSObjectAttr>>(std::optional<mx::ObjCNSObjectAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SetTypestateAttr>>(std::optional<mx::SetTypestateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDAGlobalAttrSpelling>(mx::CUDAGlobalAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedTypeId>(PackedTypeId) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SentinelAttr>>(gap::generator<mx::SentinelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCMethodFamilyAttr>>(gap::generator<mx::ObjCMethodFamilyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDAHostAttrSpelling>(mx::CUDAHostAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CompoundLiteralExpr>>(std::optional<mx::CompoundLiteralExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDALaunchBoundsAttrSpelling>(mx::CUDALaunchBoundsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SentinelAttr>>(std::optional<mx::SentinelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCMethodFamilyAttr>>(std::optional<mx::ObjCMethodFamilyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedTemplateArgumentId>(PackedTemplateArgumentId) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SelectAnyAttr>>(gap::generator<mx::SelectAnyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDASharedAttrSpelling>(mx::CUDASharedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ChooseExpr>>(gap::generator<mx::ChooseExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCIndependentClassAttr>>(gap::generator<mx::ObjCIndependentClassAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXX11NoReturnAttrSpelling>(mx::CXX11NoReturnAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SelectAnyAttr>>(std::optional<mx::SelectAnyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCIndependentClassAttr>>(std::optional<mx::ObjCIndependentClassAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedTemplateParameterListId>(PackedTemplateParameterListId) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SectionAttr>>(gap::generator<mx::SectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ChooseExpr>>(std::optional<mx::ChooseExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXRecordDeclLambdaDependencyKind>(mx::CXXRecordDeclLambdaDependencyKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCExternallyRetainedAttr>>(gap::generator<mx::ObjCExternallyRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CallExprADLCallKind>(mx::CallExprADLCallKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SectionAttr>>(std::optional<mx::SectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCExternallyRetainedAttr>>(std::optional<mx::ObjCExternallyRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CharacterLiteral>>(gap::generator<mx::CharacterLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CallableWhenAttrConsumedState>(mx::CallableWhenAttrConsumedState) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedCXXBaseSpecifierId>(PackedCXXBaseSpecifierId) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ScopedLockableAttr>>(gap::generator<mx::ScopedLockableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCExceptionAttr>>(gap::generator<mx::ObjCExceptionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CallableWhenAttrSpelling>(mx::CallableWhenAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCExplicitProtocolImplAttr>>(gap::generator<mx::ObjCExplicitProtocolImplAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CharacterLiteral>>(std::optional<mx::CharacterLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ScopedLockableAttr>>(std::optional<mx::ScopedLockableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCExplicitProtocolImplAttr>>(std::optional<mx::ObjCExplicitProtocolImplAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CallbackAttrSpelling>(mx::CallbackAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SYCLKernelAttr>>(gap::generator<mx::SYCLKernelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedDesignatorId>(PackedDesignatorId) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CastExpr>>(gap::generator<mx::CastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CalledOnceAttrSpelling>(mx::CalledOnceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SYCLSpecialClassAttr>>(gap::generator<mx::SYCLSpecialClassAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCExceptionAttr>>(std::optional<mx::ObjCExceptionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCBridgeAttr>>(gap::generator<mx::ObjCBridgeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CapabilityAttrSpelling>(mx::CapabilityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SYCLSpecialClassAttr>>(std::optional<mx::SYCLSpecialClassAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CastExpr>>(std::optional<mx::CastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AVRSignalAttrSpelling>(mx::AVRSignalAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedCXXCtorInitializerId>(PackedCXXCtorInitializerId) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CapturedStmtVariableCaptureKind>(mx::CapturedStmtVariableCaptureKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCBridgeRelatedAttr>>(gap::generator<mx::ObjCBridgeRelatedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCBridgeRelatedAttr>>(std::optional<mx::ObjCBridgeRelatedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CarriesDependencyAttrSpelling>(mx::CarriesDependencyAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SYCLKernelAttr>>(std::optional<mx::SYCLKernelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AbiTagAttrSpelling>(mx::AbiTagAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ReturnsTwiceAttr>>(gap::generator<mx::ReturnsTwiceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCBridgeMutableAttr>>(gap::generator<mx::ObjCBridgeMutableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CleanupAttrSpelling>(mx::CleanupAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCBridgeMutableAttr>>(std::optional<mx::ObjCBridgeMutableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CodeAlignAttrSpelling>(mx::CodeAlignAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ReturnsTwiceAttr>>(std::optional<mx::ReturnsTwiceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ReturnsNonNullAttr>>(gap::generator<mx::ReturnsNonNullAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CodeModelAttrSpelling>(mx::CodeModelAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ImplicitCastExpr>>(gap::generator<mx::ImplicitCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ColdAttrSpelling>(mx::ColdAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCBridgeAttr>>(std::optional<mx::ObjCBridgeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ImplicitCastExpr>>(std::optional<mx::ImplicitCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ReturnsNonNullAttr>>(std::optional<mx::ReturnsNonNullAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CommonAttrSpelling>(mx::CommonAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ReturnTypestateAttr>>(gap::generator<mx::ReturnTypestateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstAttrSpelling>(mx::ConstAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OSReturnsRetainedOnZeroAttr>>(gap::generator<mx::OSReturnsRetainedOnZeroAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ReturnTypestateAttr>>(std::optional<mx::ReturnTypestateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OSReturnsRetainedOnZeroAttr>>(std::optional<mx::OSReturnsRetainedOnZeroAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstInitAttrSpelling>(mx::ConstInitAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RetainAttr>>(gap::generator<mx::RetainAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ExplicitCastExpr>>(gap::generator<mx::ExplicitCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstructorAttrSpelling>(mx::ConstructorAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OSReturnsRetainedOnNonZeroAttr>>(gap::generator<mx::OSReturnsRetainedOnNonZeroAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ExplicitCastExpr>>(std::optional<mx::ExplicitCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConsumableAttrConsumedState>(mx::ConsumableAttrConsumedState) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RetainAttr>>(std::optional<mx::RetainAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OSReturnsRetainedOnNonZeroAttr>>(std::optional<mx::OSReturnsRetainedOnNonZeroAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RestrictAttr>>(gap::generator<mx::RestrictAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OSReturnsRetainedAttr>>(gap::generator<mx::OSReturnsRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConsumableAttrSpelling>(mx::ConsumableAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXNamedCastExpr>>(gap::generator<mx::CXXNamedCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedFileId>(PackedFileId) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OSReturnsRetainedAttr>>(std::optional<mx::OSReturnsRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConsumableAutoCastAttrSpelling>(mx::ConsumableAutoCastAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RestrictAttr>>(std::optional<mx::RestrictAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ReinitializesAttr>>(gap::generator<mx::ReinitializesAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OSConsumesThisAttr>>(gap::generator<mx::OSConsumesThisAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConsumableSetOnReadAttrSpelling>(mx::ConsumableSetOnReadAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXNamedCastExpr>>(std::optional<mx::CXXNamedCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RequiresCapabilityAttr>>(gap::generator<mx::RequiresCapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConvergentAttrSpelling>(mx::ConvergentAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OSReturnsNotRetainedAttr>>(gap::generator<mx::OSReturnsNotRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RequiresCapabilityAttr>>(std::optional<mx::RequiresCapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OSReturnsNotRetainedAttr>>(std::optional<mx::OSReturnsNotRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXDynamicCastExpr>>(gap::generator<mx::CXXDynamicCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroDisableLifetimeBoundAttrSpelling>(mx::CoroDisableLifetimeBoundAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ReqdWorkGroupSizeAttr>>(gap::generator<mx::ReqdWorkGroupSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroLifetimeBoundAttrSpelling>(mx::CoroLifetimeBoundAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OSConsumesThisAttr>>(std::optional<mx::OSConsumesThisAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXDynamicCastExpr>>(std::optional<mx::CXXDynamicCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ReqdWorkGroupSizeAttr>>(std::optional<mx::ReqdWorkGroupSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroOnlyDestroyWhenCompleteAttrSpelling>(mx::CoroOnlyDestroyWhenCompleteAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ReleaseCapabilityAttr>>(gap::generator<mx::ReleaseCapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDeclareVariantAttr>>(gap::generator<mx::OMPDeclareVariantAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroReturnTypeAttrSpelling>(mx::CoroReturnTypeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXConstCastExpr>>(gap::generator<mx::CXXConstCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPThreadPrivateDeclAttr>>(gap::generator<mx::OMPThreadPrivateDeclAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::variant<mx::MacroSubstitution, mx::MacroVAOpt>>(std::variant<mx::MacroSubstitution, mx::MacroVAOpt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ReleaseCapabilityAttr>>(std::optional<mx::ReleaseCapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroWrapperAttrSpelling>(mx::CoroWrapperAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPThreadPrivateDeclAttr>>(std::optional<mx::OMPThreadPrivateDeclAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDeclareVariantAttr>>(std::optional<mx::OMPDeclareVariantAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXConstCastExpr>>(std::optional<mx::CXXConstCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CountedByAttrSpelling>(mx::CountedByAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedFragmentId>(PackedFragmentId) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DLLExportAttrSpelling>(mx::DLLExportAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ReinitializesAttr>>(std::optional<mx::ReinitializesAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPAllocateDeclAttr>>(gap::generator<mx::OMPAllocateDeclAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXStaticCastExpr>>(gap::generator<mx::CXXStaticCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RegCallAttr>>(gap::generator<mx::RegCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DLLImportAttrSpelling>(mx::DLLImportAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDeclareTargetDeclAttr>>(gap::generator<mx::OMPDeclareTargetDeclAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXAddrspaceCastExpr>>(gap::generator<mx::CXXAddrspaceCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDeclareTargetDeclAttr>>(std::optional<mx::OMPDeclareTargetDeclAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeclFriendObjectKind>(mx::DeclFriendObjectKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedCompilationId>(PackedCompilationId) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RegCallAttr>>(std::optional<mx::RegCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXAddrspaceCastExpr>>(std::optional<mx::CXXAddrspaceCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RandomizeLayoutAttr>>(gap::generator<mx::RandomizeLayoutAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeclIdentifierNamespace>(mx::DeclIdentifierNamespace) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPCaptureNoInitAttr>>(gap::generator<mx::OMPCaptureNoInitAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeclModuleOwnershipKind>(mx::DeclModuleOwnershipKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ReadOnlyPlacementAttr>>(gap::generator<mx::ReadOnlyPlacementAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ReadOnlyPlacementAttr>>(std::optional<mx::ReadOnlyPlacementAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPCaptureNoInitAttr>>(std::optional<mx::OMPCaptureNoInitAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeclObjCDeclQualifier>(mx::DeclObjCDeclQualifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPAllocateDeclAttr>>(std::optional<mx::OMPAllocateDeclAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXStaticCastExpr>>(std::optional<mx::CXXStaticCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeprecatedAttrSpelling>(mx::DeprecatedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LockReturnedAttr>>(gap::generator<mx::LockReturnedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<PackedDeclId>(PackedDeclId) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RandomizeLayoutAttr>>(std::optional<mx::RandomizeLayoutAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CStyleCastExpr>>(gap::generator<mx::CStyleCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DestructorAttrSpelling>(mx::DestructorAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RISCVInterruptAttr>>(gap::generator<mx::RISCVInterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NotTailCalledAttr>>(gap::generator<mx::NotTailCalledAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXReinterpretCastExpr>>(gap::generator<mx::CXXReinterpretCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DiagnoseAsBuiltinAttrSpelling>(mx::DiagnoseAsBuiltinAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NotTailCalledAttr>>(std::optional<mx::NotTailCalledAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXReinterpretCastExpr>>(std::optional<mx::CXXReinterpretCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DiagnoseIfAttrDiagnosticType>(mx::DiagnoseIfAttrDiagnosticType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RISCVInterruptAttr>>(std::optional<mx::RISCVInterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoUwtableAttr>>(gap::generator<mx::NoUwtableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PureAttr>>(gap::generator<mx::PureAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DisableSanitizerInstrumentationAttrSpelling>(mx::DisableSanitizerInstrumentationAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoUwtableAttr>>(std::optional<mx::NoUwtableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXFunctionalCastExpr>>(gap::generator<mx::CXXFunctionalCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DisableTailCallsAttrSpelling>(mx::DisableTailCallsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PureAttr>>(std::optional<mx::PureAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoUniqueAddressAttr>>(gap::generator<mx::NoUniqueAddressAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PtGuardedVarAttr>>(gap::generator<mx::PtGuardedVarAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXFunctionalCastExpr>>(std::optional<mx::CXXFunctionalCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnforceTCBAttrSpelling>(mx::EnforceTCBAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoUniqueAddressAttr>>(std::optional<mx::NoUniqueAddressAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnforceTCBLeafAttrSpelling>(mx::EnforceTCBLeafAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PtGuardedVarAttr>>(std::optional<mx::PtGuardedVarAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoThrowAttr>>(gap::generator<mx::NoThrowAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnumExtensibilityAttrKind>(mx::EnumExtensibilityAttrKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::File>(mx::File) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnumExtensibilityAttrSpelling>(mx::EnumExtensibilityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PtGuardedByAttr>>(std::optional<mx::PtGuardedByAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoThrowAttr>>(std::optional<mx::NoThrowAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CStyleCastExpr>>(std::optional<mx::CStyleCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PreferredTypeAttr>>(gap::generator<mx::PreferredTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ErrorAttrSpelling>(mx::ErrorAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PreserveMostAttr>>(gap::generator<mx::PreserveMostAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoSplitStackAttr>>(gap::generator<mx::NoSplitStackAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BuiltinBitCastExpr>>(gap::generator<mx::BuiltinBitCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArmOutAttr>>(gap::generator<mx::ArmOutAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReleaseCapabilityAttr>(mx::ReleaseCapabilityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CStyleCastExpr>(mx::CStyleCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TopLevelStmtDecl>>(gap::generator<mx::TopLevelStmtDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::File>>(std::optional<mx::File>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RequiresExpr>>(std::optional<mx::RequiresExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TopLevelStmtDecl>>(std::optional<mx::TopLevelStmtDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReinitializesAttr>(mx::ReinitializesAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BuiltinBitCastExpr>(mx::BuiltinBitCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArmOutAttr>>(std::optional<mx::ArmOutAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RegCallAttr>(mx::RegCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBridgedCastExpr>(mx::ObjCBridgedCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RecoveryExpr>>(gap::generator<mx::RecoveryExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArmInOutAttr>>(gap::generator<mx::ArmInOutAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArmMveStrictPolymorphismAttr>>(gap::generator<mx::ArmMveStrictPolymorphismAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReadOnlyPlacementAttr>(mx::ReadOnlyPlacementAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CallExpr>(mx::CallExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::StaticAssertDecl>>(std::optional<mx::StaticAssertDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArmMveStrictPolymorphismAttr>>(std::optional<mx::ArmMveStrictPolymorphismAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RequiresExprBodyDecl>>(gap::generator<mx::RequiresExprBodyDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RandomizeLayoutAttr>(mx::RandomizeLayoutAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXOperatorCallExpr>(mx::CXXOperatorCallExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RequiresExprBodyDecl>>(std::optional<mx::RequiresExprBodyDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HLSLBufferDecl>>(gap::generator<mx::HLSLBufferDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArmInOutAttr>>(std::optional<mx::ArmInOutAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArmInAttr>>(gap::generator<mx::ArmInAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RISCVInterruptAttr>(mx::RISCVInterruptAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXMemberCallExpr>(mx::CXXMemberCallExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RecoveryExpr>>(std::optional<mx::RecoveryExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PragmaCommentDecl>>(gap::generator<mx::PragmaCommentDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Macro>>(std::optional<mx::Macro>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PragmaDetectMismatchDecl>>(gap::generator<mx::PragmaDetectMismatchDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PureAttr>(mx::PureAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDAKernelCallExpr>(mx::CUDAKernelCallExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArmInAttr>>(std::optional<mx::ArmInAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PragmaDetectMismatchDecl>>(std::optional<mx::PragmaDetectMismatchDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AnnotateTypeAttr>>(gap::generator<mx::AnnotateTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PtGuardedVarAttr>(mx::PtGuardedVarAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UserDefinedLiteral>(mx::UserDefinedLiteral) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PseudoObjectExpr>>(gap::generator<mx::PseudoObjectExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AnnotateTypeAttr>>(std::optional<mx::AnnotateTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PtGuardedByAttr>(mx::PtGuardedByAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXUuidofExpr>(mx::CXXUuidofExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AddressSpaceAttr>>(gap::generator<mx::AddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PseudoObjectExpr>>(std::optional<mx::PseudoObjectExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TemplateParameterList>>(gap::generator<mx::TemplateParameterList>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PragmaCommentDecl>>(std::optional<mx::PragmaCommentDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PreserveMostAttr>(mx::PreserveMostAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXUnresolvedConstructExpr>(mx::CXXUnresolvedConstructExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AddressSpaceAttr>>(std::optional<mx::AddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXBaseSpecifier>>(gap::generator<mx::CXXBaseSpecifier>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UPtrAttr>>(gap::generator<mx::UPtrAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PreserveAllAttr>(mx::PreserveAllAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXTypeidExpr>(mx::CXXTypeidExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HLSLBufferDecl>>(std::optional<mx::HLSLBufferDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WebAssemblyFuncrefAttr>>(gap::generator<mx::WebAssemblyFuncrefAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PredefinedExpr>>(gap::generator<mx::PredefinedExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PreferredTypeAttr>(mx::PreferredTypeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXThrowExpr>(mx::CXXThrowExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WebAssemblyFuncrefAttr>>(std::optional<mx::WebAssemblyFuncrefAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PredefinedExpr>>(std::optional<mx::PredefinedExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UsingEnumDecl>>(gap::generator<mx::UsingEnumDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PreferredNameAttr>(mx::PreferredNameAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXNewExpr>(mx::CXXNewExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UPtrAttr>>(std::optional<mx::UPtrAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaClangTextSectionAttr>(mx::PragmaClangTextSectionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXThisExpr>(mx::CXXThisExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ParenListExpr>>(gap::generator<mx::ParenListExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UsingEnumDecl>>(std::optional<mx::UsingEnumDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeNullableAttr>>(gap::generator<mx::TypeNullableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaClangRodataSectionAttr>(mx::PragmaClangRodataSectionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXStdInitializerListExpr>(mx::CXXStdInitializerListExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeNullableResultAttr>>(gap::generator<mx::TypeNullableResultAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ParenListExpr>>(std::optional<mx::ParenListExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::EnumDecl>>(gap::generator<mx::EnumDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::vector<std::string>>(std::vector<std::string>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeNullableResultAttr>>(std::optional<mx::TypeNullableResultAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaClangRelroSectionAttr>(mx::PragmaClangRelroSectionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXScalarValueInitExpr>(mx::CXXScalarValueInitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ParenExpr>>(gap::generator<mx::ParenExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EnumDecl>>(std::optional<mx::EnumDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaClangDataSectionAttr>(mx::PragmaClangDataSectionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXRewrittenBinaryOperator>(mx::CXXRewrittenBinaryOperator) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeNullableAttr>>(std::optional<mx::TypeNullableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeNonNullAttr>>(gap::generator<mx::TypeNonNullAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ParenExpr>>(std::optional<mx::ParenExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::EnumConstantDecl>>(gap::generator<mx::EnumConstantDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaClangBSSSectionAttr>(mx::PragmaClangBSSSectionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXPseudoDestructorExpr>(mx::CXXPseudoDestructorExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeNullUnspecifiedAttr>>(gap::generator<mx::TypeNullUnspecifiedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeNullUnspecifiedAttr>>(std::optional<mx::TypeNullUnspecifiedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PointerAttr>(mx::PointerAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXParenListInitExpr>(mx::CXXParenListInitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PackExpansionExpr>>(gap::generator<mx::PackExpansionExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EnumConstantDecl>>(std::optional<mx::EnumConstantDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PcsAttr>(mx::PcsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXNullPtrLiteralExpr>(mx::CXXNullPtrLiteralExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeNonNullAttr>>(std::optional<mx::TypeNonNullAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PackExpansionExpr>>(std::optional<mx::PackExpansionExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ThreadAttr>>(gap::generator<mx::ThreadAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PatchableFunctionEntryAttr>(mx::PatchableFunctionEntryAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXNoexceptExpr>(mx::CXXNoexceptExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OffsetOfExpr>>(gap::generator<mx::OffsetOfExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ThreadAttr>>(std::optional<mx::ThreadAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UsingDecl>>(gap::generator<mx::UsingDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PascalAttr>(mx::PascalAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXConstructExpr>(mx::CXXConstructExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnresolvedMemberExpr>>(gap::generator<mx::UnresolvedMemberExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UsingDecl>>(std::optional<mx::UsingDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ParamTypestateAttr>(mx::ParamTypestateAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXInheritedCtorInitExpr>(mx::CXXInheritedCtorInitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnresolvedMemberExpr>>(std::optional<mx::UnresolvedMemberExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftVersionedRemovalAttr>>(gap::generator<mx::SwiftVersionedRemovalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftVersionedRemovalAttr>>(std::optional<mx::SwiftVersionedRemovalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PackedAttr>(mx::PackedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ValueStmt>>(std::optional<mx::ValueStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXFoldExpr>(mx::CXXFoldExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OwnershipAttr>(mx::OwnershipAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXDependentScopeMemberExpr>(mx::CXXDependentScopeMemberExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OffsetOfExpr>>(std::optional<mx::OffsetOfExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnresolvedUsingValueDecl>>(gap::generator<mx::UnresolvedUsingValueDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::StmtAttr>>(gap::generator<mx::StmtAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnresolvedUsingValueDecl>>(std::optional<mx::UnresolvedUsingValueDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftVersionedAdditionAttr>>(gap::generator<mx::SwiftVersionedAdditionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OwnerAttr>(mx::OwnerAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXDeleteExpr>(mx::CXXDeleteExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftVersionedAdditionAttr>>(std::optional<mx::SwiftVersionedAdditionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCStringLiteral>>(gap::generator<mx::ObjCStringLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftObjCMembersAttr>>(gap::generator<mx::SwiftObjCMembersAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPCapturedExprDecl>>(gap::generator<mx::OMPCapturedExprDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OverrideAttr>(mx::OverrideAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXDefaultInitExpr>(mx::CXXDefaultInitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCSubscriptRefExpr>>(gap::generator<mx::ObjCSubscriptRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnnamedGlobalConstantDecl>>(gap::generator<mx::UnnamedGlobalConstantDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OptimizeNoneAttr>(mx::OptimizeNoneAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftObjCMembersAttr>>(std::optional<mx::SwiftObjCMembersAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXDefaultArgExpr>(mx::CXXDefaultArgExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCSubscriptRefExpr>>(std::optional<mx::ObjCSubscriptRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnnamedGlobalConstantDecl>>(std::optional<mx::UnnamedGlobalConstantDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLKernelAttr>(mx::OpenCLKernelAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Expr>>(std::optional<mx::Expr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXTemporaryObjectExpr>(mx::CXXTemporaryObjectExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::StmtAttr>>(std::optional<mx::StmtAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TemplateParamObjectDecl>>(gap::generator<mx::TemplateParamObjectDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MustTailAttr>>(gap::generator<mx::MustTailAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLIntelReqdSubGroupSizeAttr>(mx::OpenCLIntelReqdSubGroupSizeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXBoolLiteralExpr>(mx::CXXBoolLiteralExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TemplateParamObjectDecl>>(std::optional<mx::TemplateParamObjectDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLUnrollHintAttr>>(gap::generator<mx::OpenCLUnrollHintAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCSubclassingRestrictedAttr>(mx::ObjCSubclassingRestrictedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXBindTemporaryExpr>(mx::CXXBindTemporaryExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLUnrollHintAttr>>(std::optional<mx::OpenCLUnrollHintAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDeclareReductionDecl>>(gap::generator<mx::OMPDeclareReductionDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCStringLiteral>>(std::optional<mx::ObjCStringLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCRootClassAttr>(mx::ObjCRootClassAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BlockExpr>(mx::BlockExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDeclareReductionDecl>>(std::optional<mx::OMPDeclareReductionDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MustTailAttr>>(std::optional<mx::MustTailAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCReturnsInnerPointerAttr>(mx::ObjCReturnsInnerPointerAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LikelyAttr>>(gap::generator<mx::LikelyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BlockDecl>(mx::BlockDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCSelectorExpr>>(gap::generator<mx::ObjCSelectorExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCRequiresSuperAttr>(mx::ObjCRequiresSuperAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BinaryOperator>(mx::BinaryOperator) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LikelyAttr>>(std::optional<mx::LikelyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCSelectorExpr>>(std::optional<mx::ObjCSelectorExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPCapturedExprDecl>>(std::optional<mx::OMPCapturedExprDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FallThroughAttr>>(gap::generator<mx::FallThroughAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCRequiresPropertyDefsAttr>(mx::ObjCRequiresPropertyDefsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CompoundAssignOperator>(mx::CompoundAssignOperator) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCProtocolExpr>>(gap::generator<mx::ObjCProtocolExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DecompositionDecl>>(gap::generator<mx::DecompositionDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FallThroughAttr>>(std::optional<mx::FallThroughAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCPreciseLifetimeAttr>(mx::ObjCPreciseLifetimeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AtomicExpr>(mx::AtomicExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCProtocolExpr>>(std::optional<mx::ObjCProtocolExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DecompositionDecl>>(std::optional<mx::DecompositionDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCOwnershipAttr>(mx::ObjCOwnershipAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AsTypeExpr>(mx::AsTypeExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CodeAlignAttr>>(std::optional<mx::CodeAlignAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCNSObjectAttr>(mx::ObjCNSObjectAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArrayTypeTraitExpr>(mx::ArrayTypeTraitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCMessageExpr>>(gap::generator<mx::ObjCMessageExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BindingDecl>>(gap::generator<mx::BindingDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnlikelyAttr>>(gap::generator<mx::UnlikelyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCMethodFamilyAttr>(mx::ObjCMethodFamilyAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArraySubscriptExpr>(mx::ArraySubscriptExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnlikelyAttr>>(std::optional<mx::UnlikelyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCMessageExpr>>(std::optional<mx::ObjCMessageExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BindingDecl>>(std::optional<mx::BindingDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OverloadableAttr>>(gap::generator<mx::OverloadableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCIndependentClassAttr>(mx::ObjCIndependentClassAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArrayInitLoopExpr>(mx::ArrayInitLoopExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RenderScriptKernelAttr>>(gap::generator<mx::RenderScriptKernelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RenderScriptKernelAttr>>(std::optional<mx::RenderScriptKernelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCExternallyRetainedAttr>(mx::ObjCExternallyRetainedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArrayInitIndexExpr>(mx::ArrayInitIndexExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCIvarRefExpr>>(gap::generator<mx::ObjCIvarRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCExplicitProtocolImplAttr>(mx::ObjCExplicitProtocolImplAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AbstractConditionalOperator>(mx::AbstractConditionalOperator) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VarTemplateSpecializationDecl>>(gap::generator<mx::VarTemplateSpecializationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OverloadableAttr>>(std::optional<mx::OverloadableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCIvarRefExpr>>(std::optional<mx::ObjCIvarRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VarTemplateSpecializationDecl>>(std::optional<mx::VarTemplateSpecializationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCExceptionAttr>(mx::ObjCExceptionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLAccessAttr>>(gap::generator<mx::OpenCLAccessAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConditionalOperator>(mx::ConditionalOperator) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBridgeRelatedAttr>(mx::ObjCBridgeRelatedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BinaryConditionalOperator>(mx::BinaryConditionalOperator) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLAccessAttr>>(std::optional<mx::OpenCLAccessAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCRuntimeNameAttr>>(gap::generator<mx::ObjCRuntimeNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBridgeMutableAttr>(mx::ObjCBridgeMutableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VAArgExpr>(mx::VAArgExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCIsaExpr>>(gap::generator<mx::ObjCIsaExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCRuntimeVisibleAttr>>(gap::generator<mx::ObjCRuntimeVisibleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AllocAlignAttrSpelling>(mx::AllocAlignAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCRuntimeVisibleAttr>>(std::optional<mx::ObjCRuntimeVisibleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBridgeAttr>(mx::ObjCBridgeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnaryOperator>(mx::UnaryOperator) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCIsaExpr>>(std::optional<mx::ObjCIsaExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VarTemplatePartialSpecializationDecl>>(std::optional<mx::VarTemplatePartialSpecializationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VarTemplatePartialSpecializationDecl>>(gap::generator<mx::VarTemplatePartialSpecializationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSReturnsRetainedOnZeroAttr>(mx::OSReturnsRetainedOnZeroAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnaryExprOrTypeTraitExpr>(mx::UnaryExprOrTypeTraitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCRuntimeNameAttr>>(std::optional<mx::ObjCRuntimeNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSReturnsRetainedOnNonZeroAttr>(mx::OSReturnsRetainedOnNonZeroAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypoExpr>(mx::TypoExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCEncodeExpr>>(gap::generator<mx::ObjCEncodeExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCIndirectCopyRestoreExpr>>(gap::generator<mx::ObjCIndirectCopyRestoreExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCDirectAttr>>(gap::generator<mx::ObjCDirectAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSReturnsRetainedAttr>(mx::OSReturnsRetainedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeTraitExpr>(mx::TypeTraitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCIndirectCopyRestoreExpr>>(std::optional<mx::ObjCIndirectCopyRestoreExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXConversionDecl>>(gap::generator<mx::CXXConversionDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCNonRuntimeProtocolAttr>>(gap::generator<mx::ObjCNonRuntimeProtocolAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCNonRuntimeProtocolAttr>>(std::optional<mx::ObjCNonRuntimeProtocolAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXConversionDecl>>(std::optional<mx::CXXConversionDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSReturnsNotRetainedAttr>(mx::OSReturnsNotRetainedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SubstNonTypeTemplateParmPackExpr>(mx::SubstNonTypeTemplateParmPackExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCNonLazyClassAttr>>(gap::generator<mx::ObjCNonLazyClassAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSConsumesThisAttr>(mx::OSConsumesThisAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NonTypeTemplateParmDecl>(mx::NonTypeTemplateParmDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCEncodeExpr>>(std::optional<mx::ObjCEncodeExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCNonLazyClassAttr>>(std::optional<mx::ObjCNonLazyClassAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCDirectMembersAttr>>(gap::generator<mx::ObjCDirectMembersAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPThreadPrivateDeclAttr>(mx::OMPThreadPrivateDeclAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SubstNonTypeTemplateParmExpr>(mx::SubstNonTypeTemplateParmExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCBoxedExpr>>(gap::generator<mx::ObjCBoxedExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCAtDefsFieldDecl>>(gap::generator<mx::ObjCAtDefsFieldDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCDirectMembersAttr>>(std::optional<mx::ObjCDirectMembersAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXDeductionGuideDecl>>(gap::generator<mx::CXXDeductionGuideDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclareVariantAttr>(mx::OMPDeclareVariantAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StmtExpr>(mx::StmtExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCDictionaryLiteral>>(gap::generator<mx::ObjCDictionaryLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXDeductionGuideDecl>>(std::optional<mx::CXXDeductionGuideDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCDictionaryLiteral>>(std::optional<mx::ObjCDictionaryLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclareTargetDeclAttr>(mx::OMPDeclareTargetDeclAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SourceLocExpr>(mx::SourceLocExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCDirectAttr>>(std::optional<mx::ObjCDirectAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPCaptureNoInitAttr>(mx::OMPCaptureNoInitAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SizeOfPackExpr>(mx::SizeOfPackExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCClassStubAttr>>(gap::generator<mx::ObjCClassStubAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCDesignatedInitializerAttr>>(gap::generator<mx::ObjCDesignatedInitializerAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPAllocateDeclAttr>(mx::OMPAllocateDeclAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ShuffleVectorExpr>(mx::ShuffleVectorExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCDesignatedInitializerAttr>>(std::optional<mx::ObjCDesignatedInitializerAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCBoxedExpr>>(std::optional<mx::ObjCBoxedExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NotTailCalledAttr>(mx::NotTailCalledAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SYCLUniqueStableNameExpr>(mx::SYCLUniqueStableNameExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCAtDefsFieldDecl>>(std::optional<mx::ObjCAtDefsFieldDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Index>>(std::optional<mx::Index>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCClassStubAttr>>(std::optional<mx::ObjCClassStubAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoUwtableAttr>(mx::NoUwtableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCBoxableAttr>>(gap::generator<mx::ObjCBoxableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RequiresExpr>(mx::RequiresExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoUniqueAddressAttr>(mx::NoUniqueAddressAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RequiresExprBodyDecl>(mx::RequiresExprBodyDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCBoxableAttr>>(std::optional<mx::ObjCBoxableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCBoolLiteralExpr>>(gap::generator<mx::ObjCBoolLiteralExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Compilation>>(gap::generator<mx::Compilation>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPCaptureKindAttr>>(gap::generator<mx::OMPCaptureKindAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDeclarativeDirectiveValueDecl>>(gap::generator<mx::OMPDeclarativeDirectiveValueDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoThrowAttr>(mx::NoThrowAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RecoveryExpr>(mx::RecoveryExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCBoolLiteralExpr>>(std::optional<mx::ObjCBoolLiteralExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDeclarativeDirectiveValueDecl>>(std::optional<mx::OMPDeclarativeDirectiveValueDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPReferencedVarAttr>>(gap::generator<mx::OMPReferencedVarAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoThreadSafetyAnalysisAttr>(mx::NoThreadSafetyAnalysisAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PseudoObjectExpr>(mx::PseudoObjectExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPReferencedVarAttr>>(std::optional<mx::OMPReferencedVarAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDeclareMapperDecl>>(gap::generator<mx::OMPDeclareMapperDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDeclareSimdDeclAttr>>(gap::generator<mx::OMPDeclareSimdDeclAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoStackProtectorAttr>(mx::NoStackProtectorAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PredefinedExpr>(mx::PredefinedExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCArrayLiteral>>(gap::generator<mx::ObjCArrayLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDeclareSimdDeclAttr>>(std::optional<mx::OMPDeclareSimdDeclAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCAvailabilityCheckExpr>>(gap::generator<mx::ObjCAvailabilityCheckExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDeclareMapperDecl>>(std::optional<mx::OMPDeclareMapperDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoSplitStackAttr>(mx::NoSplitStackAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ParenListExpr>(mx::ParenListExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCAvailabilityCheckExpr>>(std::optional<mx::ObjCAvailabilityCheckExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoSpeculativeLoadHardeningAttr>(mx::NoSpeculativeLoadHardeningAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ParenExpr>(mx::ParenExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPCaptureKindAttr>>(std::optional<mx::OMPCaptureKindAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoEscapeAttr>>(gap::generator<mx::NoEscapeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoSanitizeAttr>(mx::NoSanitizeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PackExpansionExpr>(mx::PackExpansionExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCArrayLiteral>>(std::optional<mx::ObjCArrayLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UsingPackDecl>>(gap::generator<mx::UsingPackDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConstructorUsingShadowDecl>>(gap::generator<mx::ConstructorUsingShadowDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoEscapeAttr>>(std::optional<mx::NoEscapeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoReturnAttr>(mx::NoReturnAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnresolvedMemberExpr>(mx::UnresolvedMemberExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConstructorUsingShadowDecl>>(std::optional<mx::ConstructorUsingShadowDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoBuiltinAttr>>(gap::generator<mx::NoBuiltinAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoRandomizeLayoutAttr>(mx::NoRandomizeLayoutAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OffsetOfExpr>(mx::OffsetOfExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoBuiltinAttr>>(std::optional<mx::NoBuiltinAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPIteratorExpr>>(gap::generator<mx::OMPIteratorExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::File>>(gap::generator<mx::File>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoProfileFunctionAttr>(mx::NoProfileFunctionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ModeAttr>>(gap::generator<mx::ModeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCSubscriptRefExpr>(mx::ObjCSubscriptRefExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPIteratorExpr>>(std::optional<mx::OMPIteratorExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UsingPackDecl>>(std::optional<mx::UsingPackDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoMips16Attr>(mx::NoMips16Attr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCStringLiteral>(mx::ObjCStringLiteral) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ModeAttr>>(std::optional<mx::ModeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LoopHintAttr>>(gap::generator<mx::LoopHintAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPArrayShapingExpr>>(gap::generator<mx::OMPArrayShapingExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoMicroMipsAttr>(mx::NoMicroMipsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCSelectorExpr>(mx::ObjCSelectorExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UsingDirectiveDecl>>(gap::generator<mx::UsingDirectiveDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LoopHintAttr>>(std::optional<mx::LoopHintAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoInstrumentFunctionAttr>(mx::NoInstrumentFunctionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCProtocolExpr>(mx::ObjCProtocolExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPArrayShapingExpr>>(std::optional<mx::OMPArrayShapingExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<std::variant<mx::Macro, mx::Token, mx::Fragment>>>(gap::generator<std::variant<mx::Macro, mx::Token, mx::Fragment>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::InitSegAttr>>(gap::generator<mx::InitSegAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UsingDirectiveDecl>>(std::optional<mx::UsingDirectiveDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoDuplicateAttr>(mx::NoDuplicateAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCMessageExpr>(mx::ObjCMessageExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LoaderUninitializedAttr>>(gap::generator<mx::LoaderUninitializedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPArraySectionExpr>>(gap::generator<mx::OMPArraySectionExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LoaderUninitializedAttr>>(std::optional<mx::LoaderUninitializedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NamespaceDecl>>(gap::generator<mx::NamespaceDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoDestroyAttr>(mx::NoDestroyAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCIvarRefExpr>(mx::ObjCIvarRefExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPArraySectionExpr>>(std::optional<mx::OMPArraySectionExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::InitSegAttr>>(std::optional<mx::InitSegAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoDebugAttr>(mx::NoDebugAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCIsaExpr>(mx::ObjCIsaExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NamespaceDecl>>(std::optional<mx::NamespaceDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IBOutletCollectionAttr>>(gap::generator<mx::IBOutletCollectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoInitExpr>>(gap::generator<mx::NoInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoCommonAttr>(mx::NoCommonAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCIndirectCopyRestoreExpr>(mx::ObjCIndirectCopyRestoreExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IBOutletCollectionAttr>>(std::optional<mx::IBOutletCollectionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IBOutletAttr>>(gap::generator<mx::IBOutletAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoAliasAttr>(mx::NoAliasAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCEncodeExpr>(mx::ObjCEncodeExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoInitExpr>>(std::optional<mx::NoInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NakedAttr>(mx::NakedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCDictionaryLiteral>(mx::ObjCDictionaryLiteral) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IBOutletAttr>>(std::optional<mx::IBOutletAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MemberExpr>>(gap::generator<mx::MemberExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnresolvedUsingIfExistsDecl>>(gap::generator<mx::UnresolvedUsingIfExistsDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IBActionAttr>>(gap::generator<mx::IBActionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnresolvedUsingIfExistsDecl>>(std::optional<mx::UnresolvedUsingIfExistsDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NVPTXKernelAttr>(mx::NVPTXKernelAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBoxedExpr>(mx::ObjCBoxedExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MemberExpr>>(std::optional<mx::MemberExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IBActionAttr>>(std::optional<mx::IBActionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSReturnsRetainedAttr>(mx::NSReturnsRetainedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBoolLiteralExpr>(mx::ObjCBoolLiteralExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HotAttr>>(gap::generator<mx::HotAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ClassTemplateSpecializationDecl>>(gap::generator<mx::ClassTemplateSpecializationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSReturnsNotRetainedAttr>(mx::NSReturnsNotRetainedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCAvailabilityCheckExpr>(mx::ObjCAvailabilityCheckExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ClassTemplateSpecializationDecl>>(std::optional<mx::ClassTemplateSpecializationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HotAttr>>(std::optional<mx::HotAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HLSLShaderAttr>>(gap::generator<mx::HLSLShaderAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSReturnsAutoreleasedAttr>(mx::NSReturnsAutoreleasedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCArrayLiteral>(mx::ObjCArrayLiteral) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MatrixSubscriptExpr>>(gap::generator<mx::MatrixSubscriptExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MatrixSubscriptExpr>>(std::optional<mx::MatrixSubscriptExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSErrorDomainAttr>(mx::NSErrorDomainAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPIteratorExpr>(mx::OMPIteratorExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HLSLShaderAttr>>(std::optional<mx::HLSLShaderAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HLSLResourceAttr>>(gap::generator<mx::HLSLResourceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSConsumesSelfAttr>(mx::NSConsumesSelfAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPArrayShapingExpr>(mx::OMPArrayShapingExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HLSLResourceBindingAttr>>(gap::generator<mx::HLSLResourceBindingAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ClassTemplatePartialSpecializationDecl>>(gap::generator<mx::ClassTemplatePartialSpecializationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HLSLResourceBindingAttr>>(std::optional<mx::HLSLResourceBindingAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MipsShortCallAttr>(mx::MipsShortCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPArraySectionExpr>(mx::OMPArraySectionExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSPropertyRefExpr>>(gap::generator<mx::MSPropertyRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ClassTemplatePartialSpecializationDecl>>(std::optional<mx::ClassTemplatePartialSpecializationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MaterializeTemporaryExpr>>(gap::generator<mx::MaterializeTemporaryExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MaterializeTemporaryExpr>>(std::optional<mx::MaterializeTemporaryExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MipsLongCallAttr>(mx::MipsLongCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoInitExpr>(mx::NoInitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HLSLResourceAttr>>(std::optional<mx::HLSLResourceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HLSLNumThreadsAttr>>(gap::generator<mx::HLSLNumThreadsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCExternallyRetainedAttrSpelling>(mx::ObjCExternallyRetainedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDistributeParallelForSimdDirective>(mx::OMPDistributeParallelForSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCGCAttrSpelling>(mx::ObjCGCAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDistributeParallelForDirective>(mx::OMPDistributeParallelForDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCIndependentClassAttrSpelling>(mx::ObjCIndependentClassAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDistributeDirective>(mx::OMPDistributeDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCIvarDeclAccessControl>(mx::ObjCIvarDeclAccessControl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCMessageExprReceiverKind>(mx::ObjCMessageExprReceiverKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTeamsGenericLoopDirective>(mx::OMPTeamsGenericLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ImplicitParamDecl>>(gap::generator<mx::ImplicitParamDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCMethodFamilyAttrFamilyKind>(mx::ObjCMethodFamilyAttrFamilyKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTeamsDistributeSimdDirective>(mx::OMPTeamsDistributeSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCMethodFamilyAttrSpelling>(mx::ObjCMethodFamilyAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTeamsDistributeParallelForSimdDirective>(mx::OMPTeamsDistributeParallelForSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCNSObjectAttrSpelling>(mx::ObjCNSObjectAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCNonLazyClassAttrSpelling>(mx::ObjCNonLazyClassAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTeamsDistributeParallelForDirective>(mx::OMPTeamsDistributeParallelForDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCNonRuntimeProtocolAttrSpelling>(mx::ObjCNonRuntimeProtocolAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTeamsDistributeDirective>(mx::OMPTeamsDistributeDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCOwnershipAttrSpelling>(mx::ObjCOwnershipAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTaskLoopSimdDirective>(mx::OMPTaskLoopSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCPreciseLifetimeAttrSpelling>(mx::ObjCPreciseLifetimeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCPropertyDeclPropertyControl>(mx::ObjCPropertyDeclPropertyControl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTaskLoopDirective>(mx::OMPTaskLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCPropertyDeclSetterKind>(mx::ObjCPropertyDeclSetterKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetTeamsGenericLoopDirective>(mx::OMPTargetTeamsGenericLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCPropertyImplDeclKind>(mx::ObjCPropertyImplDeclKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetTeamsDistributeSimdDirective>(mx::OMPTargetTeamsDistributeSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCRequiresPropertyDefsAttrSpelling>(mx::ObjCRequiresPropertyDefsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCRequiresSuperAttrSpelling>(mx::ObjCRequiresSuperAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetTeamsDistributeParallelForSimdDirective>(mx::OMPTargetTeamsDistributeParallelForSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCReturnsInnerPointerAttrSpelling>(mx::ObjCReturnsInnerPointerAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelMasterTaskLoopDirective>(mx::OMPParallelMasterTaskLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCRootClassAttrSpelling>(mx::ObjCRootClassAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetTeamsDistributeParallelForDirective>(mx::OMPTargetTeamsDistributeParallelForDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCRuntimeNameAttrSpelling>(mx::ObjCRuntimeNameAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCRuntimeVisibleAttrSpelling>(mx::ObjCRuntimeVisibleAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetTeamsDistributeDirective>(mx::OMPTargetTeamsDistributeDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCSubclassingRestrictedAttrSpelling>(mx::ObjCSubclassingRestrictedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetSimdDirective>(mx::OMPTargetSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLAccessAttrSpelling>(mx::OpenCLAccessAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetParallelGenericLoopDirective>(mx::OMPTargetParallelGenericLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLConstantAddressSpaceAttrSpelling>(mx::OpenCLConstantAddressSpaceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLGenericAddressSpaceAttrSpelling>(mx::OpenCLGenericAddressSpaceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetParallelForSimdDirective>(mx::OMPTargetParallelForSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLGlobalAddressSpaceAttrSpelling>(mx::OpenCLGlobalAddressSpaceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPTargetParallelForDirective>(mx::OMPTargetParallelForDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLGlobalDeviceAddressSpaceAttrSpelling>(mx::OpenCLGlobalDeviceAddressSpaceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPSimdDirective>(mx::OMPSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLGlobalHostAddressSpaceAttrSpelling>(mx::OpenCLGlobalHostAddressSpaceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLKernelAttrSpelling>(mx::OpenCLKernelAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelMasterTaskLoopSimdDirective>(mx::OMPParallelMasterTaskLoopSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLLocalAddressSpaceAttrSpelling>(mx::OpenCLLocalAddressSpaceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelMaskedTaskLoopSimdDirective>(mx::OMPParallelMaskedTaskLoopSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLPrivateAddressSpaceAttrSpelling>(mx::OpenCLPrivateAddressSpaceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelMaskedTaskLoopDirective>(mx::OMPParallelMaskedTaskLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OptimizeNoneAttrSpelling>(mx::OptimizeNoneAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OverloadableAttrSpelling>(mx::OverloadableAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelGenericLoopDirective>(mx::OMPParallelGenericLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OwnershipAttrOwnershipKind>(mx::OwnershipAttrOwnershipKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelForSimdDirective>(mx::OMPParallelForSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OwnershipAttrSpelling>(mx::OwnershipAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPParallelForDirective>(mx::OMPParallelForDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PackedAttrSpelling>(mx::PackedAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ParamTypestateAttrConsumedState>(mx::ParamTypestateAttrConsumedState) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPMasterTaskLoopSimdDirective>(mx::OMPMasterTaskLoopSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ParamTypestateAttrSpelling>(mx::ParamTypestateAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPMasterTaskLoopDirective>(mx::OMPMasterTaskLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PascalAttrSpelling>(mx::PascalAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPMaskedTaskLoopSimdDirective>(mx::OMPMaskedTaskLoopSimdDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PassObjectSizeAttrSpelling>(mx::PassObjectSizeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PatchableFunctionEntryAttrSpelling>(mx::PatchableFunctionEntryAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPMaskedTaskLoopDirective>(mx::OMPMaskedTaskLoopDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PcsAttrPCSType>(mx::PcsAttrPCSType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPInteropDirective>(mx::OMPInteropDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PcsAttrSpelling>(mx::PcsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPFlushDirective>(mx::OMPFlushDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PreferredNameAttrSpelling>(mx::PreferredNameAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PreferredTypeAttrSpelling>(mx::PreferredTypeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPCanonicalLoop>(mx::OMPCanonicalLoop) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VarTemplateDecl>>(std::optional<mx::VarTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PreserveAllAttrSpelling>(mx::PreserveAllAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeclRefExpr>(mx::DeclRefExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PreserveMostAttrSpelling>(mx::PreserveMostAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NullStmt>(mx::NullStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PtGuardedVarAttrSpelling>(mx::PtGuardedVarAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PureAttrSpelling>(mx::PureAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSDependentExistsStmt>(mx::MSDependentExistsStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::QualifiedTypeDestructionKind>(mx::QualifiedTypeDestructionKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Decl>>(gap::generator<mx::Decl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IndirectGotoStmt>(mx::IndirectGotoStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ParmVarDecl>>(gap::generator<mx::ParmVarDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::QualifiedTypeNonConstantStorageReason>(mx::QualifiedTypeNonConstantStorageReason) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LabelDecl>(mx::LabelDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::QualifiedTypePrimitiveCopyKind>(mx::QualifiedTypePrimitiveCopyKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::QualifiedTypePrimitiveDefaultInitializeKind>(mx::QualifiedTypePrimitiveDefaultInitializeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LabelStmt>(mx::LabelStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RISCVInterruptAttrInterruptType>(mx::RISCVInterruptAttrInterruptType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXTryStmt>(mx::CXXTryStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RISCVInterruptAttrSpelling>(mx::RISCVInterruptAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IfStmt>(mx::IfStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RandomizeLayoutAttrSpelling>(mx::RandomizeLayoutAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReadOnlyPlacementAttrSpelling>(mx::ReadOnlyPlacementAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeclStmt>(mx::DeclStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RegCallAttrSpelling>(mx::RegCallAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GotoStmt>(mx::GotoStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReinitializesAttrSpelling>(mx::ReinitializesAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ForStmt>(mx::ForStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReleaseCapabilityAttrSpelling>(mx::ReleaseCapabilityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReleaseHandleAttrSpelling>(mx::ReleaseHandleAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DoStmt>(mx::DoStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RequiresCapabilityAttrSpelling>(mx::RequiresCapabilityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroutineBodyStmt>(mx::CoroutineBodyStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RestrictAttrSpelling>(mx::RestrictAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoreturnStmt>(mx::CoreturnStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RetainAttrSpelling>(mx::RetainAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReturnTypestateAttrConsumedState>(mx::ReturnTypestateAttrConsumedState) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ContinueStmt>(mx::ContinueStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReturnTypestateAttrSpelling>(mx::ReturnTypestateAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXCatchStmt>(mx::CXXCatchStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReturnsNonNullAttrSpelling>(mx::ReturnsNonNullAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXForRangeStmt>(mx::CXXForRangeStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReturnsTwiceAttrSpelling>(mx::ReturnsTwiceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SYCLKernelAttrSpelling>(mx::SYCLKernelAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BreakStmt>(mx::BreakStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SYCLSpecialClassAttrSpelling>(mx::SYCLSpecialClassAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AsmStmt>(mx::AsmStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ScopedLockableAttrSpelling>(mx::ScopedLockableAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSAsmStmt>(mx::MSAsmStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SectionAttrSpelling>(mx::SectionAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SelectAnyAttrSpelling>(mx::SelectAnyAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GCCAsmStmt>(mx::GCCAsmStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SentinelAttrSpelling>(mx::SentinelAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StringLiteral>(mx::StringLiteral) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SetTypestateAttrConsumedState>(mx::SetTypestateAttrConsumedState) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AddrLabelExpr>(mx::AddrLabelExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SetTypestateAttrSpelling>(mx::SetTypestateAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SpeculativeLoadHardeningAttrSpelling>(mx::SpeculativeLoadHardeningAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WhileStmt>(mx::WhileStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StandaloneDebugAttrSpelling>(mx::StandaloneDebugAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DesignatedInitUpdateExpr>(mx::DesignatedInitUpdateExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StdCallAttrSpelling>(mx::StdCallAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InitListExpr>(mx::InitListExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StmtLikelihood>(mx::StmtLikelihood) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StmtKind>(mx::StmtKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DesignatedInitExpr>(mx::DesignatedInitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SuppressAttrSpelling>(mx::SuppressAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DependentScopeDeclRefExpr>(mx::DependentScopeDeclRefExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncAttrKind>(mx::SwiftAsyncAttrKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DependentCoawaitExpr>(mx::DependentCoawaitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncAttrSpelling>(mx::SwiftAsyncAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncCallAttrSpelling>(mx::SwiftAsyncCallAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnresolvedLookupExpr>(mx::UnresolvedLookupExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncContextAttrSpelling>(mx::SwiftAsyncContextAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OverloadExpr>(mx::OverloadExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncErrorAttrConventionKind>(mx::SwiftAsyncErrorAttrConventionKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroutineSuspendExpr>(mx::CoroutineSuspendExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncErrorAttrSpelling>(mx::SwiftAsyncErrorAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftCallAttrSpelling>(mx::SwiftCallAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpaqueValueExpr>(mx::OpaqueValueExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftContextAttrSpelling>(mx::SwiftContextAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoawaitExpr>(mx::CoawaitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftErrorAttrConventionKind>(mx::SwiftErrorAttrConventionKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoyieldExpr>(mx::CoyieldExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftErrorResultAttrSpelling>(mx::SwiftErrorResultAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<uint32_t>(uint32_t) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftIndirectResultAttrSpelling>(mx::SwiftIndirectResultAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConvertVectorExpr>(mx::ConvertVectorExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftNewTypeAttrNewtypeKind>(mx::SwiftNewTypeAttrNewtypeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<uint64_t>(uint64_t) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConceptSpecializationExpr>(mx::ConceptSpecializationExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftNewTypeAttrSpelling>(mx::SwiftNewTypeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ImplicitConceptSpecializationDecl>(mx::ImplicitConceptSpecializationDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SysVABIAttrSpelling>(mx::SysVABIAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Stmt>>(std::optional<mx::Stmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<bool>(bool) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TLSModelAttrSpelling>(mx::TLSModelAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CompoundLiteralExpr>(mx::CompoundLiteralExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TargetAttrSpelling>(mx::TargetAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ChooseExpr>(mx::ChooseExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TargetClonesAttrSpelling>(mx::TargetClonesAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CharacterLiteral>(mx::CharacterLiteral) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TargetVersionAttrSpelling>(mx::TargetVersionAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AttrKind>(mx::AttrKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateArgumentKind>(mx::TemplateArgumentKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CastExpr>(mx::CastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TestTypestateAttrConsumedState>(mx::TestTypestateAttrConsumedState) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ImplicitCastExpr>(mx::ImplicitCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TestTypestateAttrSpelling>(mx::TestTypestateAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AArch64SVEPcsAttrSpelling>(mx::AArch64SVEPcsAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeclKind>(mx::DeclKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExplicitCastExpr>(mx::ExplicitCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ThisCallAttrSpelling>(mx::ThisCallAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TransparentUnionAttrSpelling>(mx::TransparentUnionAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXNamedCastExpr>(mx::CXXNamedCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TrivialABIAttrSpelling>(mx::TrivialABIAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXDynamicCastExpr>(mx::CXXDynamicCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TryAcquireCapabilityAttrSpelling>(mx::TryAcquireCapabilityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TokenContext>(mx::TokenContext) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXConstCastExpr>(mx::CXXConstCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeScalarTypeKind>(mx::TypeScalarTypeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeKind>(mx::TypeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXAddrspaceCastExpr>(mx::CXXAddrspaceCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeTagForDatatypeAttrSpelling>(mx::TypeTagForDatatypeAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXStaticCastExpr>(mx::CXXStaticCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeVisibilityAttrSpelling>(mx::TypeVisibilityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXReinterpretCastExpr>(mx::CXXReinterpretCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeVisibilityAttrVisibilityType>(mx::TypeVisibilityAttrVisibilityType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<SpecificEntityId<DeclId>>>(std::optional<SpecificEntityId<DeclId>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnaryTransformTypeUTTKind>(mx::UnaryTransformTypeUTTKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXFunctionalCastExpr>(mx::CXXFunctionalCastExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCGCAttr>(mx::ObjCGCAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::InitPriorityAttr>>(gap::generator<mx::InitPriorityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MemberExpr>(mx::MemberExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BaseUsingDecl>>(gap::generator<mx::BaseUsingDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TagDecl>>(gap::generator<mx::TagDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoDerefAttr>(mx::NoDerefAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MatrixSubscriptExpr>(mx::MatrixSubscriptExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::InitPriorityAttr>>(std::optional<mx::InitPriorityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BaseUsingDecl>>(std::optional<mx::BaseUsingDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CarriesDependencyAttr>>(gap::generator<mx::CarriesDependencyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TagDecl>>(std::optional<mx::TagDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLParamModifierAttr>(mx::HLSLParamModifierAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MaterializeTemporaryExpr>(mx::MaterializeTemporaryExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::InheritableParamAttr>>(gap::generator<mx::InheritableParamAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCInterfaceType>>(gap::generator<mx::ObjCInterfaceType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLGroupSharedAddressSpaceAttr>(mx::HLSLGroupSharedAddressSpaceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypedefNameDecl>>(gap::generator<mx::TypedefNameDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LifetimeExtendedTemporaryDecl>(mx::LifetimeExtendedTemporaryDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::InheritableParamAttr>>(std::optional<mx::InheritableParamAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CarriesDependencyAttr>>(std::optional<mx::CarriesDependencyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCInterfaceType>>(std::optional<mx::ObjCInterfaceType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CmseNSCallAttr>(mx::CmseNSCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSPropertySubscriptExpr>(mx::MSPropertySubscriptExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCObjectPointerType>>(gap::generator<mx::ObjCObjectPointerType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypedefNameDecl>>(std::optional<mx::TypedefNameDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnresolvedUsingType>>(gap::generator<mx::UnresolvedUsingType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnnotateTypeAttr>(mx::AnnotateTypeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCObjectPointerType>>(std::optional<mx::ObjCObjectPointerType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSPropertyRefExpr>(mx::MSPropertyRefExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnresolvedUsingType>>(std::optional<mx::UnresolvedUsingType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CFConsumedAttr>>(std::optional<mx::CFConsumedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BTFTypeTagAttr>(mx::BTFTypeTagAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSPropertyDecl>(mx::MSPropertyDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AnnotateAttr>>(gap::generator<mx::AnnotateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Attr>>(gap::generator<mx::Attr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmStreamingCompatibleAttr>(mx::ArmStreamingCompatibleAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnaryTransformType>>(std::optional<mx::UnaryTransformType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LambdaExpr>(mx::LambdaExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AnnotateAttr>>(std::optional<mx::AnnotateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnresolvedUsingTypenameDecl>>(gap::generator<mx::UnresolvedUsingTypenameDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UseHandleAttr>>(gap::generator<mx::UseHandleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmStreamingAttr>(mx::ArmStreamingAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IntegerLiteral>(mx::IntegerLiteral) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnresolvedUsingTypenameDecl>>(std::optional<mx::UnresolvedUsingTypenameDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmPreservesAttr>(mx::ArmPreservesAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ImplicitValueInitExpr>(mx::ImplicitValueInitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UseHandleAttr>>(std::optional<mx::UseHandleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeOfType>>(gap::generator<mx::TypeOfType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ReleaseHandleAttr>>(gap::generator<mx::ReleaseHandleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmOutAttr>(mx::ArmOutAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Token>>(gap::generator<mx::Token>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ImaginaryLiteral>(mx::ImaginaryLiteral) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypedefType>>(gap::generator<mx::TypedefType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ReleaseHandleAttr>>(std::optional<mx::ReleaseHandleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MemberPointerType>>(std::optional<mx::MemberPointerType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmMveStrictPolymorphismAttr>(mx::ArmMveStrictPolymorphismAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GenericSelectionExpr>(mx::GenericSelectionExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PassObjectSizeAttr>>(gap::generator<mx::PassObjectSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypedefType>>(std::optional<mx::TypedefType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmInOutAttr>(mx::ArmInOutAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GNUNullExpr>(mx::GNUNullExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PassObjectSizeAttr>>(std::optional<mx::PassObjectSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MatrixType>>(gap::generator<mx::MatrixType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ParameterABIAttr>>(gap::generator<mx::ParameterABIAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmInAttr>(mx::ArmInAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionParmPackExpr>(mx::FunctionParmPackExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RecordDecl>>(gap::generator<mx::RecordDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MatrixType>>(std::optional<mx::MatrixType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeOfType>>(std::optional<mx::TypeOfType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RecordDecl>>(std::optional<mx::RecordDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MacroQualifiedType>>(gap::generator<mx::MacroQualifiedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SEHTryStmt>>(gap::generator<mx::SEHTryStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AddressSpaceAttr>(mx::AddressSpaceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FullExpr>(mx::FullExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ParameterABIAttr>>(std::optional<mx::ParameterABIAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftContextAttr>>(gap::generator<mx::SwiftContextAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeOfExprType>>(gap::generator<mx::TypeOfExprType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::WebAssemblyFuncrefAttr>(mx::WebAssemblyFuncrefAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConstantMatrixType>>(gap::generator<mx::ConstantMatrixType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExprWithCleanups>(mx::ExprWithCleanups) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftIndirectResultAttr>>(gap::generator<mx::SwiftIndirectResultAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DependentSizedMatrixType>>(gap::generator<mx::DependentSizedMatrixType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeOfExprType>>(std::optional<mx::TypeOfExprType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftIndirectResultAttr>>(std::optional<mx::SwiftIndirectResultAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DependentSizedMatrixType>>(std::optional<mx::DependentSizedMatrixType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UPtrAttr>(mx::UPtrAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstantExpr>(mx::ConstantExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftErrorResultAttr>>(gap::generator<mx::SwiftErrorResultAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SEHTryStmt>>(std::optional<mx::SEHTryStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeNullableResultAttr>(mx::TypeNullableResultAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConstantMatrixType>>(std::optional<mx::ConstantMatrixType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FloatingLiteral>(mx::FloatingLiteral) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftErrorResultAttr>>(std::optional<mx::SwiftErrorResultAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SEHExceptStmt>>(gap::generator<mx::SEHExceptStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeNullableAttr>(mx::TypeNullableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FixedPointLiteral>(mx::FixedPointLiteral) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MacroQualifiedType>>(std::optional<mx::MacroQualifiedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftContextAttr>>(std::optional<mx::SwiftContextAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FunctionType>>(gap::generator<mx::FunctionType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeNullUnspecifiedAttr>(mx::TypeNullUnspecifiedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExtVectorElementExpr>(mx::ExtVectorElementExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OSConsumedAttr>>(gap::generator<mx::OSConsumedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SEHExceptStmt>>(std::optional<mx::SEHExceptStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeNonNullAttr>(mx::TypeNonNullAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwiftAsyncContextAttr>>(gap::generator<mx::SwiftAsyncContextAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::InjectedClassNameType>>(gap::generator<mx::InjectedClassNameType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExpressionTraitExpr>(mx::ExpressionTraitExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwiftAsyncContextAttr>>(std::optional<mx::SwiftAsyncContextAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::InjectedClassNameType>>(std::optional<mx::InjectedClassNameType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CompoundStmt>>(gap::generator<mx::CompoundStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ThreadAttr>(mx::ThreadAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AttributedStmt>(mx::AttributedStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CompoundStmt>>(std::optional<mx::CompoundStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftVersionedRemovalAttr>(mx::SwiftVersionedRemovalAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OSConsumedAttr>>(std::optional<mx::OSConsumedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwitchStmt>(mx::SwitchStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NonNullAttr>>(gap::generator<mx::NonNullAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FunctionType>>(std::optional<mx::FunctionType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXRecordDecl>>(gap::generator<mx::CXXRecordDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FunctionProtoType>>(gap::generator<mx::FunctionProtoType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftVersionedAdditionAttr>(mx::SwiftVersionedAdditionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwitchCase>(mx::SwitchCase) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXRecordDecl>>(std::optional<mx::CXXRecordDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NonNullAttr>>(std::optional<mx::NonNullAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftObjCMembersAttr>(mx::SwiftObjCMembersAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DefaultStmt>(mx::DefaultStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NSConsumedAttr>>(gap::generator<mx::NSConsumedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FunctionProtoType>>(std::optional<mx::FunctionProtoType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SEHFinallyStmt>>(gap::generator<mx::SEHFinallyStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CanThrowResult>>(std::optional<mx::CanThrowResult>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StmtAttr>(mx::StmtAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SEHFinallyStmt>>(std::optional<mx::SEHFinallyStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CaseStmt>(mx::CaseStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NSConsumedAttr>>(std::optional<mx::NSConsumedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ReferenceType>>(gap::generator<mx::ReferenceType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLUnrollHintAttr>(mx::OpenCLUnrollHintAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AccessSpecDecl>(mx::AccessSpecDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ReturnStmt>>(gap::generator<mx::ReturnStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IFuncAttr>>(gap::generator<mx::IFuncAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MustTailAttr>(mx::MustTailAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SEHLeaveStmt>>(gap::generator<mx::SEHLeaveStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclarativeDirectiveDecl>(mx::OMPDeclarativeDirectiveDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<std::vector<mx::CXXBaseSpecifier>>>(std::optional<std::vector<mx::CXXBaseSpecifier>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IFuncAttr>>(std::optional<mx::IFuncAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSInheritanceModel>>(std::optional<mx::MSInheritanceModel>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CalledOnceAttr>>(gap::generator<mx::CalledOnceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LikelyAttr>(mx::LikelyAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SEHLeaveStmt>>(std::optional<mx::SEHLeaveStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPThreadPrivateDecl>(mx::OMPThreadPrivateDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FunctionDecl>>(gap::generator<mx::FunctionDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DeducedType>>(gap::generator<mx::DeducedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FallThroughAttr>(mx::FallThroughAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPRequiresDecl>(mx::OMPRequiresDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CalledOnceAttr>>(std::optional<mx::CalledOnceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FunctionNoProtoType>>(gap::generator<mx::FunctionNoProtoType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BuiltinAliasAttr>>(gap::generator<mx::BuiltinAliasAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FunctionDecl>>(std::optional<mx::FunctionDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CodeAlignAttr>(mx::CodeAlignAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FunctionNoProtoType>>(std::optional<mx::FunctionNoProtoType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ReturnStmt>>(std::optional<mx::ReturnStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPAllocateDecl>(mx::OMPAllocateDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DependentVectorType>>(gap::generator<mx::DependentVectorType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BuiltinAliasAttr>>(std::optional<mx::BuiltinAliasAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnlikelyAttr>(mx::UnlikelyAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TranslationUnitDecl>(mx::TranslationUnitDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCAtTryStmt>>(gap::generator<mx::ObjCAtTryStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DependentVectorType>>(std::optional<mx::DependentVectorType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RenderScriptKernelAttr>(mx::RenderScriptKernelAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TemplateTypeParmType>>(gap::generator<mx::TemplateTypeParmType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCForCollectionStmt>>(gap::generator<mx::ObjCForCollectionStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FunctionTemplateDecl>>(std::optional<mx::FunctionTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TopLevelStmtDecl>(mx::TopLevelStmtDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCForCollectionStmt>>(std::optional<mx::ObjCForCollectionStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TemplateTypeParmType>>(std::optional<mx::TemplateTypeParmType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OverloadableAttr>(mx::OverloadableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DependentBitIntType>>(gap::generator<mx::DependentBitIntType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StaticAssertDecl>(mx::StaticAssertDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FunctionTemplateDecl>>(gap::generator<mx::FunctionTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TemplateTypeParmDecl>>(std::optional<mx::TemplateTypeParmDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DependentSizedExtVectorType>>(gap::generator<mx::DependentSizedExtVectorType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DependentSizedExtVectorType>>(std::optional<mx::DependentSizedExtVectorType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLAccessAttr>(mx::OpenCLAccessAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaDetectMismatchDecl>(mx::PragmaDetectMismatchDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TagType>>(gap::generator<mx::TagType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TemplateTypeParmDecl>>(gap::generator<mx::TemplateTypeParmDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCRuntimeVisibleAttr>(mx::ObjCRuntimeVisibleAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DependentBitIntType>>(std::optional<mx::DependentBitIntType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCAutoreleasePoolStmt>>(gap::generator<mx::ObjCAutoreleasePoolStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaCommentDecl>(mx::PragmaCommentDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCAutoreleasePoolStmt>>(std::optional<mx::ObjCAutoreleasePoolStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCRuntimeNameAttr>(mx::ObjCRuntimeNameAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLBufferDecl>(mx::HLSLBufferDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DependentAddressSpaceType>>(gap::generator<mx::DependentAddressSpaceType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCAtTryStmt>>(std::optional<mx::ObjCAtTryStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCNonRuntimeProtocolAttr>(mx::ObjCNonRuntimeProtocolAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DependentAddressSpaceType>>(std::optional<mx::DependentAddressSpaceType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UsingEnumDecl>(mx::UsingEnumDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCNonLazyClassAttr>(mx::ObjCNonLazyClassAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnumDecl>(mx::EnumDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCAtFinallyStmt>>(gap::generator<mx::ObjCAtFinallyStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DeducedType>>(std::optional<mx::DeducedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCDirectMembersAttr>(mx::ObjCDirectMembersAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnumConstantDecl>(mx::EnumConstantDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AutoType>>(gap::generator<mx::AutoType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TemplateSpecializationType>>(gap::generator<mx::TemplateSpecializationType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCAtFinallyStmt>>(std::optional<mx::ObjCAtFinallyStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoBuiltinAttr>(mx::NoBuiltinAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TemplateSpecializationType>>(std::optional<mx::TemplateSpecializationType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UsingDecl>(mx::UsingDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DeducedTemplateSpecializationType>>(gap::generator<mx::DeducedTemplateSpecializationType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCAtCatchStmt>>(gap::generator<mx::ObjCAtCatchStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCDirectAttr>(mx::ObjCDirectAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnresolvedUsingValueDecl>(mx::UnresolvedUsingValueDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DeducedTemplateSpecializationType>>(std::optional<mx::DeducedTemplateSpecializationType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AutoType>>(std::optional<mx::AutoType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCDesignatedInitializerAttr>(mx::ObjCDesignatedInitializerAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TagType>>(std::optional<mx::TagType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCAtCatchStmt>>(std::optional<mx::ObjCAtCatchStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnnamedGlobalConstantDecl>(mx::UnnamedGlobalConstantDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RecordType>>(gap::generator<mx::RecordType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCClassStubAttr>(mx::ObjCClassStubAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateParamObjectDecl>(mx::TemplateParamObjectDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RecordType>>(std::optional<mx::RecordType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBoxableAttr>(mx::ObjCBoxableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclareReductionDecl>(mx::OMPDeclareReductionDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::EnumType>>(gap::generator<mx::EnumType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPReferencedVarAttr>(mx::OMPReferencedVarAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCAtThrowStmt>>(gap::generator<mx::ObjCAtThrowStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPCapturedExprDecl>(mx::OMPCapturedExprDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EnumType>>(std::optional<mx::EnumType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConceptDecl>>(gap::generator<mx::ConceptDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCAtThrowStmt>>(std::optional<mx::ObjCAtThrowStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclareSimdDeclAttr>(mx::OMPDeclareSimdDeclAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DecompositionDecl>(mx::DecompositionDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConceptDecl>>(std::optional<mx::ConceptDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPCaptureKindAttr>(mx::OMPCaptureKindAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SubstTemplateTypeParmType>>(gap::generator<mx::SubstTemplateTypeParmType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPErrorDirective>>(gap::generator<mx::OMPErrorDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BindingDecl>(mx::BindingDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SubstTemplateTypeParmType>>(std::optional<mx::SubstTemplateTypeParmType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCAtSynchronizedStmt>>(gap::generator<mx::ObjCAtSynchronizedStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoEscapeAttr>(mx::NoEscapeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VarTemplateSpecializationDecl>(mx::VarTemplateSpecializationDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ComplexType>>(gap::generator<mx::ComplexType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCAtSynchronizedStmt>>(std::optional<mx::ObjCAtSynchronizedStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Attr>>(std::optional<mx::Attr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SubstTemplateTypeParmPackType>>(gap::generator<mx::SubstTemplateTypeParmPackType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DecltypeType>>(gap::generator<mx::DecltypeType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ModeAttr>(mx::ModeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VarTemplatePartialSpecializationDecl>(mx::VarTemplatePartialSpecializationDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SubstTemplateTypeParmPackType>>(std::optional<mx::SubstTemplateTypeParmPackType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ReferenceType>>(std::optional<mx::ReferenceType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DecltypeType>>(std::optional<mx::DecltypeType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LoopHintAttr>(mx::LoopHintAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPExecutableDirective>>(gap::generator<mx::OMPExecutableDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXConversionDecl>(mx::CXXConversionDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Compilation>>(std::optional<mx::Compilation>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::QualifiedType>>(gap::generator<mx::QualifiedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ComplexType>>(std::optional<mx::ComplexType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPExecutableDirective>>(std::optional<mx::OMPExecutableDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LoaderUninitializedAttr>(mx::LoaderUninitializedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXDeductionGuideDecl>(mx::CXXDeductionGuideDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RValueReferenceType>>(gap::generator<mx::RValueReferenceType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BuiltinType>>(gap::generator<mx::BuiltinType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXMethodDecl>>(gap::generator<mx::CXXMethodDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InitSegAttr>(mx::InitSegAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::RValueReferenceType>>(std::optional<mx::RValueReferenceType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXMethodDecl>>(std::optional<mx::CXXMethodDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCAtDefsFieldDecl>(mx::ObjCAtDefsFieldDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LValueReferenceType>>(gap::generator<mx::LValueReferenceType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BuiltinType>>(std::optional<mx::BuiltinType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CapturedStmt>>(gap::generator<mx::CapturedStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BlockPointerType>>(gap::generator<mx::BlockPointerType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IBOutletCollectionAttr>(mx::IBOutletCollectionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclarativeDirectiveValueDecl>(mx::OMPDeclarativeDirectiveValueDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LValueReferenceType>>(std::optional<mx::LValueReferenceType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CapturedStmt>>(std::optional<mx::CapturedStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IBOutletAttr>(mx::IBOutletAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclareMapperDecl>(mx::OMPDeclareMapperDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BlockPointerType>>(std::optional<mx::BlockPointerType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BitIntType>>(gap::generator<mx::BitIntType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IBActionAttr>(mx::IBActionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::QualifiedType>>(std::optional<mx::QualifiedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CapturedDecl>>(gap::generator<mx::CapturedDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstructorUsingShadowDecl>(mx::ConstructorUsingShadowDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BitIntType>>(std::optional<mx::BitIntType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HotAttr>(mx::HotAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UsingPackDecl>(mx::UsingPackDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AtomicType>>(gap::generator<mx::AtomicType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CapturedDecl>>(std::optional<mx::CapturedDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLShaderAttr>(mx::HLSLShaderAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AttributedType>>(gap::generator<mx::AttributedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UsingDirectiveDecl>(mx::UsingDirectiveDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BTFTagAttributedType>>(gap::generator<mx::BTFTagAttributedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLResourceBindingAttr>(mx::HLSLResourceBindingAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NamespaceDecl>(mx::NamespaceDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BTFTagAttributedType>>(std::optional<mx::BTFTagAttributedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLResourceAttr>(mx::HLSLResourceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnresolvedUsingIfExistsDecl>(mx::UnresolvedUsingIfExistsDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Fragment>>(gap::generator<mx::Fragment>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AttributedType>>(std::optional<mx::AttributedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXConstructorDecl>>(gap::generator<mx::CXXConstructorDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<std::filesystem::path>>(gap::generator<std::filesystem::path>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLNumThreadsAttr>(mx::HLSLNumThreadsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NullabilityKind>>(std::optional<mx::NullabilityKind>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXConstructorDecl>>(std::optional<mx::CXXConstructorDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ClassTemplateSpecializationDecl>(mx::ClassTemplateSpecializationDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLAnnotationAttr>(mx::HLSLAnnotationAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ClassTemplatePartialSpecializationDecl>(mx::ClassTemplatePartialSpecializationDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPErrorDirective>>(std::optional<mx::OMPErrorDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLSV_GroupIndexAttr>(mx::HLSLSV_GroupIndexAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AtomicType>>(std::optional<mx::AtomicType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypedefDecl>(mx::TypedefDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AdjustedType>>(gap::generator<mx::AdjustedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDepobjDirective>>(gap::generator<mx::OMPDepobjDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HLSLSV_DispatchThreadIDAttr>(mx::HLSLSV_DispatchThreadIDAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeAliasDecl>(mx::TypeAliasDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IncompleteArrayType>>(gap::generator<mx::IncompleteArrayType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDispatchDirective>>(gap::generator<mx::OMPDispatchDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::HIPManagedAttr>(mx::HIPManagedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeAliasTemplateDecl>(mx::TypeAliasTemplateDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IncompleteArrayType>>(std::optional<mx::IncompleteArrayType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DependentSizedArrayType>>(gap::generator<mx::DependentSizedArrayType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDispatchDirective>>(std::optional<mx::OMPDispatchDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FriendDecl>>(gap::generator<mx::FriendDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GuardedVarAttr>(mx::GuardedVarAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BuiltinTemplateDecl>(mx::BuiltinTemplateDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DependentSizedArrayType>>(std::optional<mx::DependentSizedArrayType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FriendDecl>>(std::optional<mx::FriendDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConstantArrayType>>(gap::generator<mx::ConstantArrayType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GuardedByAttr>(mx::GuardedByAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateTemplateParmDecl>(mx::TemplateTemplateParmDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDepobjDirective>>(std::optional<mx::OMPDepobjDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::GNUInlineAttr>(mx::GNUInlineAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConstantArrayType>>(std::optional<mx::ConstantArrayType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCCompatibleAliasDecl>(mx::ObjCCompatibleAliasDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionReturnThunksAttr>(mx::FunctionReturnThunksAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NamespaceAliasDecl>(mx::NamespaceAliasDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PointerType>>(gap::generator<mx::PointerType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AdjustedType>>(std::optional<mx::AdjustedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeWithKeyword>>(gap::generator<mx::TypeWithKeyword>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPCriticalDirective>>(gap::generator<mx::OMPCriticalDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<std::vector<mx::FriendDecl>>>(std::optional<std::vector<mx::FriendDecl>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FormatAttr>(mx::FormatAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LinkageSpecDecl>(mx::LinkageSpecDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PointerType>>(std::optional<mx::PointerType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PipeType>>(gap::generator<mx::PipeType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DecayedType>>(gap::generator<mx::DecayedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPCriticalDirective>>(std::optional<mx::OMPCriticalDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FormatArgAttr>(mx::FormatArgAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ClassTemplateDecl>>(gap::generator<mx::ClassTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ImportDecl>(mx::ImportDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DecayedType>>(std::optional<mx::DecayedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PipeType>>(std::optional<mx::PipeType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPCancelDirective>>(gap::generator<mx::OMPCancelDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FlattenAttr>(mx::FlattenAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ClassTemplateDecl>>(std::optional<mx::ClassTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FriendTemplateDecl>(mx::FriendTemplateDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ParenType>>(gap::generator<mx::ParenType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeWithKeyword>>(std::optional<mx::TypeWithKeyword>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPCancellationPointDirective>>(gap::generator<mx::OMPCancellationPointDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnforceTCBLeafAttr>(mx::EnforceTCBLeafAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VectorType>>(gap::generator<mx::VectorType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPCancellationPointDirective>>(std::optional<mx::OMPCancellationPointDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ParenType>>(std::optional<mx::ParenType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::PackExpansionType>>(gap::generator<mx::PackExpansionType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FlagEnumAttr>(mx::FlagEnumAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ElaboratedType>>(gap::generator<mx::ElaboratedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FileScopeAsmDecl>(mx::FileScopeAsmDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ElaboratedType>>(std::optional<mx::ElaboratedType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FinalAttr>(mx::FinalAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExternCContextDecl>(mx::ExternCContextDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::PackExpansionType>>(std::optional<mx::PackExpansionType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPCancelDirective>>(std::optional<mx::OMPCancelDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MemberPointerType>>(gap::generator<mx::MemberPointerType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXDestructorDecl>>(gap::generator<mx::CXXDestructorDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FastCallAttr>(mx::FastCallAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DependentNameType>>(gap::generator<mx::DependentNameType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExportDecl>(mx::ExportDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCTypeParamType>>(gap::generator<mx::ObjCTypeParamType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DependentTemplateSpecializationType>>(gap::generator<mx::DependentTemplateSpecializationType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPBarrierDirective>>(gap::generator<mx::OMPBarrierDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXDestructorDecl>>(std::optional<mx::CXXDestructorDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DependentTemplateSpecializationType>>(std::optional<mx::DependentTemplateSpecializationType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExclusiveTrylockFunctionAttr>(mx::ExclusiveTrylockFunctionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EmptyDecl>(mx::EmptyDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCTypeParamType>>(std::optional<mx::ObjCTypeParamType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPBarrierDirective>>(std::optional<mx::OMPBarrierDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCTypeParamDecl>>(gap::generator<mx::ObjCTypeParamDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExcludeFromExplicitInstantiationAttr>(mx::ExcludeFromExplicitInstantiationAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DependentNameType>>(std::optional<mx::DependentNameType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPAtomicDirective>>(gap::generator<mx::OMPAtomicDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ErrorAttr>(mx::ErrorAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCTypeParamDecl>>(std::optional<mx::ObjCTypeParamDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroSubstitution>(mx::MacroSubstitution) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VectorType>>(std::optional<mx::VectorType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnaryTransformType>>(gap::generator<mx::UnaryTransformType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnumExtensibilityAttr>(mx::EnumExtensibilityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroVAOpt>(mx::MacroVAOpt) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCObjectType>>(gap::generator<mx::ObjCObjectType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPAtomicDirective>>(std::optional<mx::OMPAtomicDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TemplateDecl>>(std::optional<mx::TemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ExtVectorType>>(gap::generator<mx::ExtVectorType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnforceTCBAttr>(mx::EnforceTCBAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LambdaCaptureDefault>>(std::optional<mx::LambdaCaptureDefault>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EmptyTokenTreeNode>(mx::EmptyTokenTreeNode) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCObjectType>>(std::optional<mx::ObjCObjectType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ExtVectorType>>(std::optional<mx::ExtVectorType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTeamsDirective>>(gap::generator<mx::OMPTeamsDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UsingType>>(gap::generator<mx::UsingType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AcquireHandleAttrSpelling>(mx::AcquireHandleAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnableIfAttr>(mx::EnableIfAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TokenTokenTreeNode>(mx::TokenTokenTreeNode) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<std::vector<mx::NamedDecl>>>(std::optional<std::vector<mx::NamedDecl>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTeamsDirective>>(std::optional<mx::OMPTeamsDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AddressSpaceAttrSpelling>(mx::AddressSpaceAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EmptyBasesAttr>(mx::EmptyBasesAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UsingType>>(std::optional<mx::UsingType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ChoiceTokenTreeNode>(mx::ChoiceTokenTreeNode) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<uint32_t>>(std::optional<uint32_t>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UsingShadowDecl>>(gap::generator<mx::UsingShadowDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTaskDirective>>(gap::generator<mx::OMPTaskDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DisableTailCallsAttr>(mx::DisableTailCallsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SubstitutionTokenTreeNode>(mx::SubstitutionTokenTreeNode) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTaskyieldDirective>>(gap::generator<mx::OMPTaskyieldDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UsingShadowDecl>>(std::optional<mx::UsingShadowDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DisableSanitizerInstrumentationAttr>(mx::DisableSanitizerInstrumentationAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SequenceTokenTreeNode>(mx::SequenceTokenTreeNode) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTaskyieldDirective>>(std::optional<mx::OMPTaskyieldDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoThreadSafetyAnalysisAttr>>(gap::generator<mx::NoThreadSafetyAnalysisAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MipsInterruptAttr>(mx::MipsInterruptAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CommonAttr>>(std::optional<mx::CommonAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AnalyzerNoReturnAttr>>(gap::generator<mx::AnalyzerNoReturnAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoThreadSafetyAnalysisAttr>>(std::optional<mx::NoThreadSafetyAnalysisAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ColdAttr>>(gap::generator<mx::ColdAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoStackProtectorAttr>>(gap::generator<mx::NoStackProtectorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Mips16Attr>(mx::Mips16Attr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BuiltinBitCastExpr>>(std::optional<mx::BuiltinBitCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AnalyzerNoReturnAttr>>(std::optional<mx::AnalyzerNoReturnAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPMaskedTaskLoopSimdDirective>>(gap::generator<mx::OMPMaskedTaskLoopSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MinVectorWidthAttr>(mx::MinVectorWidthAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ColdAttr>>(std::optional<mx::ColdAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoStackProtectorAttr>>(std::optional<mx::NoStackProtectorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPMaskedTaskLoopSimdDirective>>(std::optional<mx::OMPMaskedTaskLoopSimdDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCBridgedCastExpr>>(gap::generator<mx::ObjCBridgedCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CodeSegAttr>>(gap::generator<mx::CodeSegAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AlwaysDestroyAttr>>(std::optional<mx::AlwaysDestroyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AMDGPUWavesPerEUAttrSpelling>(mx::AMDGPUWavesPerEUAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Reference>>(gap::generator<mx::Reference>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AllocSizeAttr>>(gap::generator<mx::AllocSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MinSizeAttr>(mx::MinSizeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoSplitStackAttr>>(std::optional<mx::NoSplitStackAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPInteropDirective>>(gap::generator<mx::OMPInteropDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCBridgedCastExpr>>(std::optional<mx::ObjCBridgedCastExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CodeSegAttr>>(std::optional<mx::CodeSegAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ARMInterruptAttrInterruptType>(mx::ARMInterruptAttrInterruptType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MicroMipsAttr>(mx::MicroMipsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CodeModelAttr>>(gap::generator<mx::CodeModelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AllocSizeAttr>>(std::optional<mx::AllocSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPMaskedTaskLoopDirective>>(gap::generator<mx::OMPMaskedTaskLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AllocAlignAttr>>(gap::generator<mx::AllocAlignAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoSanitizeAttr>>(gap::generator<mx::NoSanitizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPMaskedTaskLoopDirective>>(std::optional<mx::OMPMaskedTaskLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CallExpr>>(gap::generator<mx::CallExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoSpeculativeLoadHardeningAttr>>(gap::generator<mx::NoSpeculativeLoadHardeningAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MaybeUndefAttr>(mx::MaybeUndefAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RegexQueryMatch>(mx::RegexQueryMatch) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CodeModelAttr>>(std::optional<mx::CodeModelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoSpeculativeLoadHardeningAttr>>(std::optional<mx::NoSpeculativeLoadHardeningAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CmseNSEntryAttr>>(gap::generator<mx::CmseNSEntryAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AllocAlignAttr>>(std::optional<mx::AllocAlignAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MayAliasAttr>(mx::MayAliasAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CallExpr>>(std::optional<mx::CallExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NamedDecl>>(std::optional<mx::NamedDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoSanitizeAttr>>(std::optional<mx::NoSanitizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPInteropDirective>>(std::optional<mx::OMPInteropDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MaxFieldAlignmentAttr>(mx::MaxFieldAlignmentAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CmseNSEntryAttr>>(std::optional<mx::CmseNSEntryAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AlignedAttr>>(std::optional<mx::AlignedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoReturnAttr>>(gap::generator<mx::NoReturnAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCStringFormatFamily>>(std::optional<mx::ObjCStringFormatFamily>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPFlushDirective>>(gap::generator<mx::OMPFlushDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSVtorDispAttr>(mx::MSVtorDispAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Expr>>(gap::generator<mx::Expr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CleanupAttr>>(std::optional<mx::CleanupAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoReturnAttr>>(std::optional<mx::NoReturnAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AssumeAlignedAttr>>(gap::generator<mx::AssumeAlignedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoMips16Attr>>(gap::generator<mx::NoMips16Attr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSStructAttr>(mx::MSStructAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AlignNaturalAttr>>(gap::generator<mx::AlignNaturalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPFlushDirective>>(std::optional<mx::OMPFlushDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TokenRange>(mx::TokenRange) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXOperatorCallExpr>>(gap::generator<mx::CXXOperatorCallExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCPropertyRefExpr>>(gap::generator<mx::ObjCPropertyRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CapturedRecordAttr>>(gap::generator<mx::CapturedRecordAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoRandomizeLayoutAttr>>(gap::generator<mx::NoRandomizeLayoutAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AlignNaturalAttr>>(std::optional<mx::AlignNaturalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoRandomizeLayoutAttr>>(std::optional<mx::NoRandomizeLayoutAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSP430InterruptAttr>(mx::MSP430InterruptAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXOperatorCallExpr>>(std::optional<mx::CXXOperatorCallExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CapturedRecordAttr>>(std::optional<mx::CapturedRecordAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AlignMac68kAttr>>(gap::generator<mx::AlignMac68kAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPCanonicalLoop>>(gap::generator<mx::OMPCanonicalLoop>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CapabilityAttr>>(gap::generator<mx::CapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoProfileFunctionAttr>>(gap::generator<mx::NoProfileFunctionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSNoVTableAttr>(mx::MSNoVTableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AlignMac68kAttr>>(std::optional<mx::AlignMac68kAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoProfileFunctionAttr>>(std::optional<mx::NoProfileFunctionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPCanonicalLoop>>(std::optional<mx::OMPCanonicalLoop>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSInheritanceAttr>(mx::MSInheritanceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CapabilityAttr>>(std::optional<mx::CapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AcquiredBeforeAttr>>(gap::generator<mx::AcquiredBeforeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CallbackAttr>>(gap::generator<mx::CallbackAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXMemberCallExpr>>(gap::generator<mx::CXXMemberCallExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DeclRefExpr>>(gap::generator<mx::DeclRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSConstexprAttr>(mx::MSConstexprAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AcquiredBeforeAttr>>(std::optional<mx::AcquiredBeforeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoMips16Attr>>(std::optional<mx::NoMips16Attr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXMemberCallExpr>>(std::optional<mx::CXXMemberCallExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CallbackAttr>>(std::optional<mx::CallbackAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AcquiredAfterAttr>>(gap::generator<mx::AcquiredAfterAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoMicroMipsAttr>>(gap::generator<mx::NoMicroMipsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSAllocatorAttr>(mx::MSAllocatorAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CallableWhenAttr>>(gap::generator<mx::CallableWhenAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DeclRefExpr>>(std::optional<mx::DeclRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AcquiredAfterAttr>>(std::optional<mx::AcquiredAfterAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoMicroMipsAttr>>(std::optional<mx::NoMicroMipsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MSABIAttr>(mx::MSABIAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CallableWhenAttr>>(std::optional<mx::CallableWhenAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AcquireHandleAttr>>(gap::generator<mx::AcquireHandleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXX11NoReturnAttr>>(gap::generator<mx::CXX11NoReturnAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CUDAKernelCallExpr>>(gap::generator<mx::CUDAKernelCallExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MIGServerRoutineAttr>(mx::MIGServerRoutineAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoDuplicateAttr>>(gap::generator<mx::NoDuplicateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AcquireHandleAttr>>(std::optional<mx::AcquireHandleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoInstrumentFunctionAttr>>(gap::generator<mx::NoInstrumentFunctionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CUDAKernelCallExpr>>(std::optional<mx::CUDAKernelCallExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::M68kRTDAttr>(mx::M68kRTDAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXX11NoReturnAttr>>(std::optional<mx::CXX11NoReturnAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AVRSignalAttr>>(gap::generator<mx::AVRSignalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoInstrumentFunctionAttr>>(std::optional<mx::NoInstrumentFunctionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CUDASharedAttr>>(gap::generator<mx::CUDASharedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IndirectGotoStmt>>(gap::generator<mx::IndirectGotoStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AcquireCapabilityAttr>>(gap::generator<mx::AcquireCapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::M68kInterruptAttr>(mx::M68kInterruptAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NullStmt>>(gap::generator<mx::NullStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UserDefinedLiteral>>(gap::generator<mx::UserDefinedLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AcquireCapabilityAttr>>(std::optional<mx::AcquireCapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoDuplicateAttr>>(std::optional<mx::NoDuplicateAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CUDASharedAttr>>(std::optional<mx::CUDASharedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoDestroyAttr>>(gap::generator<mx::NoDestroyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NullStmt>>(std::optional<mx::NullStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LocksExcludedAttr>(mx::LocksExcludedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CUDALaunchBoundsAttr>>(gap::generator<mx::CUDALaunchBoundsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UserDefinedLiteral>>(std::optional<mx::UserDefinedLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AVRSignalAttr>>(std::optional<mx::AVRSignalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoDestroyAttr>>(std::optional<mx::NoDestroyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LockReturnedAttr>(mx::LockReturnedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSDependentExistsStmt>>(gap::generator<mx::MSDependentExistsStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CUDALaunchBoundsAttr>>(std::optional<mx::CUDALaunchBoundsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AVRInterruptAttr>>(gap::generator<mx::AVRInterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoDebugAttr>>(gap::generator<mx::NoDebugAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXUuidofExpr>>(gap::generator<mx::CXXUuidofExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CUDAHostAttr>>(gap::generator<mx::CUDAHostAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSDependentExistsStmt>>(std::optional<mx::MSDependentExistsStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LifetimeBoundAttr>(mx::LifetimeBoundAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BuiltinReferenceKind>>(std::optional<mx::BuiltinReferenceKind>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CUDAInvalidTargetAttr>>(gap::generator<mx::CUDAInvalidTargetAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AVRInterruptAttr>>(std::optional<mx::AVRInterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoDebugAttr>>(std::optional<mx::NoDebugAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXUuidofExpr>>(std::optional<mx::CXXUuidofExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LeafAttr>(mx::LeafAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CUDAInvalidTargetAttr>>(std::optional<mx::CUDAInvalidTargetAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ARMInterruptAttr>>(gap::generator<mx::ARMInterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoCommonAttr>>(gap::generator<mx::NoCommonAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LayoutVersionAttr>(mx::LayoutVersionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ARMInterruptAttr>>(std::optional<mx::ARMInterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoCommonAttr>>(std::optional<mx::NoCommonAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IndirectGotoStmt>>(std::optional<mx::IndirectGotoStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CUDAHostAttr>>(std::optional<mx::CUDAHostAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AMDGPUWavesPerEUAttr>>(gap::generator<mx::AMDGPUWavesPerEUAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoAliasAttr>>(gap::generator<mx::NoAliasAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Type>>(std::optional<mx::Type>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LTOVisibilityPublicAttr>(mx::LTOVisibilityPublicAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CUDAGlobalAttr>>(gap::generator<mx::CUDAGlobalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXTypeidExpr>>(gap::generator<mx::CXXTypeidExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LabelDecl>>(gap::generator<mx::LabelDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AMDGPUWavesPerEUAttr>>(std::optional<mx::AMDGPUWavesPerEUAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoAliasAttr>>(std::optional<mx::NoAliasAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InternalLinkageAttr>(mx::InternalLinkageAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXUnresolvedConstructExpr>>(gap::generator<mx::CXXUnresolvedConstructExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Designator>>(gap::generator<mx::Designator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CUDAGlobalAttr>>(std::optional<mx::CUDAGlobalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AMDGPUNumVGPRAttr>>(gap::generator<mx::AMDGPUNumVGPRAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NakedAttr>>(gap::generator<mx::NakedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXUnresolvedConstructExpr>>(std::optional<mx::CXXUnresolvedConstructExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LabelDecl>>(std::optional<mx::LabelDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IntelOclBiccAttr>(mx::IntelOclBiccAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXCtorInitializer>>(gap::generator<mx::CXXCtorInitializer>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AMDGPUNumVGPRAttr>>(std::optional<mx::AMDGPUNumVGPRAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NakedAttr>>(std::optional<mx::NakedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InitPriorityAttr>(mx::InitPriorityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CUDADeviceBuiltinTextureTypeAttr>>(gap::generator<mx::CUDADeviceBuiltinTextureTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AMDGPUNumSGPRAttr>>(gap::generator<mx::AMDGPUNumSGPRAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NVPTXKernelAttr>>(gap::generator<mx::NVPTXKernelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LabelStmt>>(gap::generator<mx::LabelStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CUDADeviceBuiltinTextureTypeAttr>>(std::optional<mx::CUDADeviceBuiltinTextureTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXTypeidExpr>>(std::optional<mx::CXXTypeidExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CUDADeviceAttr>>(gap::generator<mx::CUDADeviceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InheritableParamAttr>(mx::InheritableParamAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AMDGPUNumSGPRAttr>>(std::optional<mx::AMDGPUNumSGPRAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NVPTXKernelAttr>>(std::optional<mx::NVPTXKernelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LabelStmt>>(std::optional<mx::LabelStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CUDADeviceBuiltinSurfaceTypeAttr>>(gap::generator<mx::CUDADeviceBuiltinSurfaceTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VecTypeHintAttr>>(gap::generator<mx::VecTypeHintAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CarriesDependencyAttr>(mx::CarriesDependencyAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CUDADeviceBuiltinSurfaceTypeAttr>>(std::optional<mx::CUDADeviceBuiltinSurfaceTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AMDGPUKernelCallAttr>>(gap::generator<mx::AMDGPUKernelCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NSReturnsRetainedAttr>>(gap::generator<mx::NSReturnsRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NSReturnsRetainedAttr>>(std::optional<mx::NSReturnsRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFConsumedAttr>(mx::CFConsumedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CUDADeviceAttr>>(std::optional<mx::CUDADeviceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AMDGPUKernelCallAttr>>(std::optional<mx::AMDGPUKernelCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CUDAConstantAttr>>(gap::generator<mx::CUDAConstantAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AMDGPUFlatWorkGroupSizeAttr>>(gap::generator<mx::AMDGPUFlatWorkGroupSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnnotateAttr>(mx::AnnotateAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXThrowExpr>>(gap::generator<mx::CXXThrowExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IfStmt>>(gap::generator<mx::IfStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AMDGPUFlatWorkGroupSizeAttr>>(std::optional<mx::AMDGPUFlatWorkGroupSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NSReturnsNotRetainedAttr>>(gap::generator<mx::NSReturnsNotRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IfStmt>>(std::optional<mx::IfStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXThrowExpr>>(std::optional<mx::CXXThrowExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UseHandleAttr>(mx::UseHandleAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CUDAConstantAttr>>(std::optional<mx::CUDAConstantAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AArch64SVEPcsAttr>>(gap::generator<mx::AArch64SVEPcsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NSReturnsNotRetainedAttr>>(std::optional<mx::NSReturnsNotRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CPUSpecificAttr>>(gap::generator<mx::CPUSpecificAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NSErrorDomainAttr>>(gap::generator<mx::NSErrorDomainAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AArch64VectorPcsAttr>>(gap::generator<mx::AArch64VectorPcsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReleaseHandleAttr>(mx::ReleaseHandleAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DeclStmt>>(gap::generator<mx::DeclStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NSReturnsAutoreleasedAttr>>(gap::generator<mx::NSReturnsAutoreleasedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CPUSpecificAttr>>(std::optional<mx::CPUSpecificAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AArch64VectorPcsAttr>>(std::optional<mx::AArch64VectorPcsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NSReturnsAutoreleasedAttr>>(std::optional<mx::NSReturnsAutoreleasedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PassObjectSizeAttr>(mx::PassObjectSizeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CPUDispatchAttr>>(gap::generator<mx::CPUDispatchAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DeclStmt>>(std::optional<mx::DeclStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXThisExpr>>(gap::generator<mx::CXXThisExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AArch64SVEPcsAttr>>(std::optional<mx::AArch64SVEPcsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NSErrorDomainAttr>>(std::optional<mx::NSErrorDomainAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ParameterABIAttr>(mx::ParameterABIAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXThisExpr>>(std::optional<mx::CXXThisExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CPUDispatchAttr>>(std::optional<mx::CPUDispatchAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::XRayLogArgsAttr>>(gap::generator<mx::XRayLogArgsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NSConsumesSelfAttr>>(gap::generator<mx::NSConsumesSelfAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftIndirectResultAttr>(mx::SwiftIndirectResultAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ZeroCallUsedRegsAttr>>(gap::generator<mx::ZeroCallUsedRegsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CFUnknownTransferAttr>>(gap::generator<mx::CFUnknownTransferAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NSConsumesSelfAttr>>(std::optional<mx::NSConsumesSelfAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftErrorResultAttr>(mx::SwiftErrorResultAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CFUnknownTransferAttr>>(std::optional<mx::CFUnknownTransferAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ZeroCallUsedRegsAttr>>(std::optional<mx::ZeroCallUsedRegsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MipsShortCallAttr>>(gap::generator<mx::MipsShortCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXStdInitializerListExpr>>(gap::generator<mx::CXXStdInitializerListExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CFReturnsRetainedAttr>>(gap::generator<mx::CFReturnsRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftContextAttr>(mx::SwiftContextAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::GotoStmt>>(gap::generator<mx::GotoStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXStdInitializerListExpr>>(std::optional<mx::CXXStdInitializerListExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::XRayLogArgsAttr>>(std::optional<mx::XRayLogArgsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MipsShortCallAttr>>(std::optional<mx::MipsShortCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CFReturnsRetainedAttr>>(std::optional<mx::CFReturnsRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::XRayInstrumentAttr>>(gap::generator<mx::XRayInstrumentAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MipsLongCallAttr>>(gap::generator<mx::MipsLongCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SwiftAsyncContextAttr>(mx::SwiftAsyncContextAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::GotoStmt>>(std::optional<mx::GotoStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXScalarValueInitExpr>>(gap::generator<mx::CXXScalarValueInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::XRayInstrumentAttr>>(std::optional<mx::XRayInstrumentAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MipsLongCallAttr>>(std::optional<mx::MipsLongCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OSConsumedAttr>(mx::OSConsumedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ForStmt>>(gap::generator<mx::ForStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXScalarValueInitExpr>>(std::optional<mx::CXXScalarValueInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CFReturnsNotRetainedAttr>>(gap::generator<mx::CFReturnsNotRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MipsInterruptAttr>>(gap::generator<mx::MipsInterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CFReturnsNotRetainedAttr>>(std::optional<mx::CFReturnsNotRetainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NonNullAttr>(mx::NonNullAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CFGuardAttr>>(gap::generator<mx::CFGuardAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ForStmt>>(std::optional<mx::ForStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::X86ForceAlignArgPointerAttr>>(gap::generator<mx::X86ForceAlignArgPointerAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MipsInterruptAttr>>(std::optional<mx::MipsInterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXNoexceptExpr>>(gap::generator<mx::CXXNoexceptExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NSConsumedAttr>(mx::NSConsumedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CFICanonicalJumpTableAttr>>(gap::generator<mx::CFICanonicalJumpTableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::X86ForceAlignArgPointerAttr>>(std::optional<mx::X86ForceAlignArgPointerAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Mips16Attr>>(gap::generator<mx::Mips16Attr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CFICanonicalJumpTableAttr>>(std::optional<mx::CFICanonicalJumpTableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WorkGroupSizeHintAttr>>(gap::generator<mx::WorkGroupSizeHintAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DoStmt>>(gap::generator<mx::DoStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXRewrittenBinaryOperator>>(gap::generator<mx::CXXRewrittenBinaryOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXRewrittenBinaryOperator>>(std::optional<mx::CXXRewrittenBinaryOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IFuncAttr>(mx::IFuncAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WorkGroupSizeHintAttr>>(std::optional<mx::WorkGroupSizeHintAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Mips16Attr>>(std::optional<mx::Mips16Attr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DoStmt>>(std::optional<mx::DoStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CFGuardAttr>>(std::optional<mx::CFGuardAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MinVectorWidthAttr>>(gap::generator<mx::MinVectorWidthAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CalledOnceAttr>(mx::CalledOnceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CDeclAttr>>(gap::generator<mx::CDeclAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXPseudoDestructorExpr>>(gap::generator<mx::CXXPseudoDestructorExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CoroutineBodyStmt>>(gap::generator<mx::CoroutineBodyStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CFAuditedTransferAttr>>(gap::generator<mx::CFAuditedTransferAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WebAssemblyImportNameAttr>>(gap::generator<mx::WebAssemblyImportNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MinVectorWidthAttr>>(std::optional<mx::MinVectorWidthAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BuiltinAliasAttr>(mx::BuiltinAliasAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXPseudoDestructorExpr>>(std::optional<mx::CXXPseudoDestructorExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CFAuditedTransferAttr>>(std::optional<mx::CFAuditedTransferAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WebAssemblyImportNameAttr>>(std::optional<mx::WebAssemblyImportNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MinSizeAttr>>(gap::generator<mx::MinSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CoroutineBodyStmt>>(std::optional<mx::CoroutineBodyStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateTypeParmType>(mx::TemplateTypeParmType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXParenListInitExpr>>(gap::generator<mx::CXXParenListInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WebAssemblyImportModuleAttr>>(gap::generator<mx::WebAssemblyImportModuleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MinSizeAttr>>(std::optional<mx::MinSizeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateTypeParmDecl>(mx::TemplateTypeParmDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CDeclAttr>>(std::optional<mx::CDeclAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WebAssemblyImportModuleAttr>>(std::optional<mx::WebAssemblyImportModuleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MicroMipsAttr>>(gap::generator<mx::MicroMipsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::C11NoReturnAttr>>(gap::generator<mx::C11NoReturnAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WeakRefAttr>>(gap::generator<mx::WeakRefAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXParenListInitExpr>>(std::optional<mx::CXXParenListInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateSpecializationType>(mx::TemplateSpecializationType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WebAssemblyExportNameAttr>>(gap::generator<mx::WebAssemblyExportNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MicroMipsAttr>>(std::optional<mx::MicroMipsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::C11NoReturnAttr>>(std::optional<mx::C11NoReturnAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WebAssemblyExportNameAttr>>(std::optional<mx::WebAssemblyExportNameAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MaybeUndefAttr>>(gap::generator<mx::MaybeUndefAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TagType>(mx::TagType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BuiltinAttr>>(gap::generator<mx::BuiltinAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WeakRefAttr>>(std::optional<mx::WeakRefAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MaybeUndefAttr>>(std::optional<mx::MaybeUndefAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RecordType>(mx::RecordType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXNullPtrLiteralExpr>>(gap::generator<mx::CXXNullPtrLiteralExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BuiltinAttr>>(std::optional<mx::BuiltinAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WeakImportAttr>>(gap::generator<mx::WeakImportAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MayAliasAttr>>(gap::generator<mx::MayAliasAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXNullPtrLiteralExpr>>(std::optional<mx::CXXNullPtrLiteralExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BlocksAttr>>(gap::generator<mx::BlocksAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EnumType>(mx::EnumType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WeakImportAttr>>(std::optional<mx::WeakImportAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MayAliasAttr>>(std::optional<mx::MayAliasAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CoreturnStmt>>(gap::generator<mx::CoreturnStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SubstTemplateTypeParmType>(mx::SubstTemplateTypeParmType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BlocksAttr>>(std::optional<mx::BlocksAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WeakAttr>>(gap::generator<mx::WeakAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSVtorDispAttr>>(gap::generator<mx::MSVtorDispAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BTFDeclTagAttr>>(gap::generator<mx::BTFDeclTagAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CoreturnStmt>>(std::optional<mx::CoreturnStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MaxFieldAlignmentAttr>>(gap::generator<mx::MaxFieldAlignmentAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SubstTemplateTypeParmPackType>(mx::SubstTemplateTypeParmPackType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXNoexceptExpr>>(std::optional<mx::CXXNoexceptExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WeakAttr>>(std::optional<mx::WeakAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MaxFieldAlignmentAttr>>(std::optional<mx::MaxFieldAlignmentAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BTFDeclTagAttr>>(std::optional<mx::BTFDeclTagAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WarnUnusedAttr>>(gap::generator<mx::WarnUnusedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXTryStmt>>(gap::generator<mx::CXXTryStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReferenceType>(mx::ReferenceType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXNewExpr>>(gap::generator<mx::CXXNewExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::WarnUnusedResultAttr>>(gap::generator<mx::WarnUnusedResultAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ContinueStmt>>(gap::generator<mx::ContinueStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSVtorDispAttr>>(std::optional<mx::MSVtorDispAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RValueReferenceType>(mx::RValueReferenceType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BPFPreserveStaticOffsetAttr>>(gap::generator<mx::BPFPreserveStaticOffsetAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WarnUnusedResultAttr>>(std::optional<mx::WarnUnusedResultAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSStructAttr>>(gap::generator<mx::MSStructAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ContinueStmt>>(std::optional<mx::ContinueStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXNewExpr>>(std::optional<mx::CXXNewExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BPFPreserveStaticOffsetAttr>>(std::optional<mx::BPFPreserveStaticOffsetAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::LValueReferenceType>(mx::LValueReferenceType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::WarnUnusedAttr>>(std::optional<mx::WarnUnusedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSStructAttr>>(std::optional<mx::MSStructAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::QualifiedType>(mx::QualifiedType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BPFPreserveAccessIndexAttr>>(gap::generator<mx::BPFPreserveAccessIndexAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VisibilityAttr>>(gap::generator<mx::VisibilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSP430InterruptAttr>>(gap::generator<mx::MSP430InterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BPFPreserveAccessIndexAttr>>(std::optional<mx::BPFPreserveAccessIndexAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXTryStmt>>(std::optional<mx::CXXTryStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCPropertyRefExpr>>(std::optional<mx::ObjCPropertyRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AvailableOnlyInDefaultEvalMethodAttr>>(gap::generator<mx::AvailableOnlyInDefaultEvalMethodAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PointerType>(mx::PointerType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXConstructExpr>>(gap::generator<mx::CXXConstructExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VisibilityAttr>>(std::optional<mx::VisibilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSP430InterruptAttr>>(std::optional<mx::MSP430InterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AvailableOnlyInDefaultEvalMethodAttr>>(std::optional<mx::AvailableOnlyInDefaultEvalMethodAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VectorCallAttr>>(gap::generator<mx::VectorCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSNoVTableAttr>>(gap::generator<mx::MSNoVTableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PipeType>(mx::PipeType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXCatchStmt>>(gap::generator<mx::CXXCatchStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AvailabilityAttr>>(gap::generator<mx::AvailabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXConstructExpr>>(std::optional<mx::CXXConstructExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCIvarDecl>>(gap::generator<mx::ObjCIvarDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCContainerDecl>>(std::optional<mx::ObjCContainerDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VectorCallAttr>>(std::optional<mx::VectorCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSNoVTableAttr>>(std::optional<mx::MSNoVTableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ParenType>(mx::ParenType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXCatchStmt>>(std::optional<mx::CXXCatchStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AvailabilityAttr>>(std::optional<mx::AvailabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSInheritanceAttr>>(gap::generator<mx::MSInheritanceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AssumptionAttr>>(gap::generator<mx::AssumptionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PackExpansionType>(mx::PackExpansionType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VecTypeHintAttr>>(std::optional<mx::VecTypeHintAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UuidAttr>>(gap::generator<mx::UuidAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSInheritanceAttr>>(std::optional<mx::MSInheritanceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCMethodDecl>>(std::optional<mx::ObjCMethodDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCTypeParamType>(mx::ObjCTypeParamType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AssumptionAttr>>(std::optional<mx::AssumptionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSConstexprAttr>>(gap::generator<mx::MSConstexprAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXForRangeStmt>>(gap::generator<mx::CXXForRangeStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VecReturnAttr>>(gap::generator<mx::VecReturnAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXForRangeStmt>>(std::optional<mx::CXXForRangeStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCObjectType>(mx::ObjCObjectType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AssumeAlignedAttr>>(std::optional<mx::AssumeAlignedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VecReturnAttr>>(std::optional<mx::VecReturnAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSConstexprAttr>>(std::optional<mx::MSConstexprAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AlignedAttr>>(gap::generator<mx::AlignedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSAllocatorAttr>>(gap::generator<mx::MSAllocatorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCPropertyDecl>>(std::optional<mx::ObjCPropertyDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCTypeParamDecl>(mx::ObjCTypeParamDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AsmStmt>>(gap::generator<mx::AsmStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AsmLabelAttr>>(gap::generator<mx::AsmLabelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UuidAttr>>(std::optional<mx::UuidAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXFoldExpr>>(gap::generator<mx::CXXFoldExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AssertSharedLockAttr>>(gap::generator<mx::AssertSharedLockAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSAllocatorAttr>>(std::optional<mx::MSAllocatorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCInterfaceType>(mx::ObjCInterfaceType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BreakStmt>>(gap::generator<mx::BreakStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXInheritedCtorInitExpr>>(gap::generator<mx::CXXInheritedCtorInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSABIAttr>>(gap::generator<mx::MSABIAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXInheritedCtorInitExpr>>(std::optional<mx::CXXInheritedCtorInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSGuidDecl>>(gap::generator<mx::MSGuidDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AssertSharedLockAttr>>(std::optional<mx::AssertSharedLockAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BreakStmt>>(std::optional<mx::BreakStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCObjectPointerType>(mx::ObjCObjectPointerType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AssertExclusiveLockAttr>>(gap::generator<mx::AssertExclusiveLockAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSGuidDecl>>(std::optional<mx::MSGuidDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSABIAttr>>(std::optional<mx::MSABIAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MemberPointerType>(mx::MemberPointerType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AssertExclusiveLockAttr>>(std::optional<mx::AssertExclusiveLockAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::M68kRTDAttr>>(gap::generator<mx::M68kRTDAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCIvarDecl>>(std::optional<mx::ObjCIvarDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AssertCapabilityAttr>>(gap::generator<mx::AssertCapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MIGServerRoutineAttr>>(gap::generator<mx::MIGServerRoutineAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MatrixType>(mx::MatrixType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AsmStmt>>(std::optional<mx::AsmStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UsingIfExistsAttr>>(gap::generator<mx::UsingIfExistsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXFoldExpr>>(std::optional<mx::CXXFoldExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AssertCapabilityAttr>>(std::optional<mx::AssertCapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MIGServerRoutineAttr>>(std::optional<mx::MIGServerRoutineAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DependentSizedMatrixType>(mx::DependentSizedMatrixType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UsingIfExistsAttr>>(std::optional<mx::UsingIfExistsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UsedAttr>>(gap::generator<mx::UsedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AsmLabelAttr>>(std::optional<mx::AsmLabelAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::M68kRTDAttr>>(std::optional<mx::M68kRTDAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstantMatrixType>(mx::ConstantMatrixType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArtificialAttr>>(gap::generator<mx::ArtificialAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::M68kInterruptAttr>>(gap::generator<mx::M68kInterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSAsmStmt>>(gap::generator<mx::MSAsmStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXDeleteExpr>>(gap::generator<mx::CXXDeleteExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UsedAttr>>(std::optional<mx::UsedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXDependentScopeMemberExpr>>(gap::generator<mx::CXXDependentScopeMemberExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroQualifiedType>(mx::MacroQualifiedType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnusedAttr>>(gap::generator<mx::UnusedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSAsmStmt>>(std::optional<mx::MSAsmStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXDependentScopeMemberExpr>>(std::optional<mx::CXXDependentScopeMemberExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArtificialAttr>>(std::optional<mx::ArtificialAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::M68kInterruptAttr>>(std::optional<mx::M68kInterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ComplexType>(mx::ComplexType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArmNewAttr>>(gap::generator<mx::ArmNewAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LocksExcludedAttr>>(gap::generator<mx::LocksExcludedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnusedAttr>>(std::optional<mx::UnusedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::GCCAsmStmt>>(gap::generator<mx::GCCAsmStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ImplicitParamDecl>>(std::optional<mx::ImplicitParamDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UninitializedAttr>>(gap::generator<mx::UninitializedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InjectedClassNameType>(mx::InjectedClassNameType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArmNewAttr>>(std::optional<mx::ArmNewAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LocksExcludedAttr>>(std::optional<mx::LocksExcludedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArmBuiltinAliasAttr>>(gap::generator<mx::ArmBuiltinAliasAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnsafeBufferUsageAttr>>(gap::generator<mx::UnsafeBufferUsageAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::GCCAsmStmt>>(std::optional<mx::GCCAsmStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionType>(mx::FunctionType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnsafeBufferUsageAttr>>(std::optional<mx::UnsafeBufferUsageAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArmLocallyStreamingAttr>>(gap::generator<mx::ArmLocallyStreamingAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LockReturnedAttr>>(std::optional<mx::LockReturnedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArmLocallyStreamingAttr>>(std::optional<mx::ArmLocallyStreamingAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CFConsumedAttr>>(gap::generator<mx::CFConsumedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionProtoType>(mx::FunctionProtoType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::StringLiteral>>(gap::generator<mx::StringLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXDeleteExpr>>(std::optional<mx::CXXDeleteExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UninitializedAttr>>(std::optional<mx::UninitializedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LifetimeBoundAttr>>(gap::generator<mx::LifetimeBoundAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionNoProtoType>(mx::FunctionNoProtoType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArmBuiltinAliasAttr>>(std::optional<mx::ArmBuiltinAliasAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnavailableAttr>>(gap::generator<mx::UnavailableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::StringLiteral>>(std::optional<mx::StringLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LifetimeBoundAttr>>(std::optional<mx::LifetimeBoundAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DependentVectorType>(mx::DependentVectorType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LeafAttr>>(gap::generator<mx::LeafAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ParmVarDecl>>(std::optional<mx::ParmVarDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArgumentWithTypeTagAttr>>(gap::generator<mx::ArgumentWithTypeTagAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnavailableAttr>>(std::optional<mx::UnavailableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArgumentWithTypeTagAttr>>(std::optional<mx::ArgumentWithTypeTagAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeVisibilityAttr>>(gap::generator<mx::TypeVisibilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DependentSizedExtVectorType>(mx::DependentSizedExtVectorType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AnyX86NoCfCheckAttr>>(gap::generator<mx::AnyX86NoCfCheckAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LeafAttr>>(std::optional<mx::LeafAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXDefaultInitExpr>>(gap::generator<mx::CXXDefaultInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LayoutVersionAttr>>(gap::generator<mx::LayoutVersionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AddrLabelExpr>>(gap::generator<mx::AddrLabelExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DependentBitIntType>(mx::DependentBitIntType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArcWeakrefUnavailableAttr>>(gap::generator<mx::ArcWeakrefUnavailableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeVisibilityAttr>>(std::optional<mx::TypeVisibilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXDefaultInitExpr>>(std::optional<mx::CXXDefaultInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArcWeakrefUnavailableAttr>>(std::optional<mx::ArcWeakrefUnavailableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeTagForDatatypeAttr>>(gap::generator<mx::TypeTagForDatatypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AddrLabelExpr>>(std::optional<mx::AddrLabelExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LayoutVersionAttr>>(std::optional<mx::LayoutVersionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DependentAddressSpaceType>(mx::DependentAddressSpaceType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeTagForDatatypeAttr>>(std::optional<mx::TypeTagForDatatypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::InternalLinkageAttr>>(gap::generator<mx::InternalLinkageAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AnyX86NoCfCheckAttr>>(std::optional<mx::AnyX86NoCfCheckAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeducedType>(mx::DeducedType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LTOVisibilityPublicAttr>>(gap::generator<mx::LTOVisibilityPublicAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LTOVisibilityPublicAttr>>(std::optional<mx::LTOVisibilityPublicAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXDefaultArgExpr>>(gap::generator<mx::CXXDefaultArgExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeducedTemplateSpecializationType>(mx::DeducedTemplateSpecializationType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AnyX86InterruptAttr>>(gap::generator<mx::AnyX86InterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TryAcquireCapabilityAttr>>(gap::generator<mx::TryAcquireCapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AnyX86NoCallerSavedRegistersAttr>>(gap::generator<mx::AnyX86NoCallerSavedRegistersAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TryAcquireCapabilityAttr>>(std::optional<mx::TryAcquireCapabilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXDefaultArgExpr>>(std::optional<mx::CXXDefaultArgExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AnyX86NoCallerSavedRegistersAttr>>(std::optional<mx::AnyX86NoCallerSavedRegistersAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TrivialABIAttr>>(gap::generator<mx::TrivialABIAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::InternalLinkageAttr>>(std::optional<mx::InternalLinkageAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AutoType>(mx::AutoType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IntelOclBiccAttr>>(gap::generator<mx::IntelOclBiccAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConceptDecl>(mx::ConceptDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AnyX86InterruptAttr>>(std::optional<mx::AnyX86InterruptAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TrivialABIAttr>>(std::optional<mx::TrivialABIAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AlwaysDestroyAttr>>(gap::generator<mx::AlwaysDestroyAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ThisCallAttr>>(gap::generator<mx::ThisCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IntelOclBiccAttr>>(std::optional<mx::IntelOclBiccAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HLSLNumThreadsAttr>>(std::optional<mx::HLSLNumThreadsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HLSLAnnotationAttr>>(gap::generator<mx::HLSLAnnotationAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HLSLAnnotationAttr>>(std::optional<mx::HLSLAnnotationAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCInterfaceDecl>>(std::optional<mx::ObjCInterfaceDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HLSLSV_GroupIndexAttr>>(gap::generator<mx::HLSLSV_GroupIndexAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HLSLSV_GroupIndexAttr>>(std::optional<mx::HLSLSV_GroupIndexAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCProtocolDecl>>(std::optional<mx::ObjCProtocolDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::GuardedByAttr>>(gap::generator<mx::GuardedByAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Macro>>(gap::generator<mx::Macro>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HLSLSV_DispatchThreadIDAttr>>(gap::generator<mx::HLSLSV_DispatchThreadIDAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HLSLSV_DispatchThreadIDAttr>>(std::optional<mx::HLSLSV_DispatchThreadIDAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HIPManagedAttr>>(gap::generator<mx::HIPManagedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReferenceKind>(mx::ReferenceKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HIPManagedAttr>>(std::optional<mx::HIPManagedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::GuardedVarAttr>>(gap::generator<mx::GuardedVarAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Type>>(gap::generator<mx::Type>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Type>(mx::Type) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::GuardedVarAttr>>(std::optional<mx::GuardedVarAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::GuardedByAttr>>(std::optional<mx::GuardedByAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::GNUInlineAttr>>(gap::generator<mx::GNUInlineAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCImplDecl>>(gap::generator<mx::ObjCImplDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateArgument>(mx::TemplateArgument) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::GNUInlineAttr>>(std::optional<mx::GNUInlineAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCImplDecl>>(std::optional<mx::ObjCImplDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateParameterList>(mx::TemplateParameterList) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FormatAttr>>(gap::generator<mx::FormatAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FunctionReturnThunksAttr>>(gap::generator<mx::FunctionReturnThunksAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCPropertyImplDecl>>(std::optional<mx::ObjCPropertyImplDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FunctionReturnThunksAttr>>(std::optional<mx::FunctionReturnThunksAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXBaseSpecifier>(mx::CXXBaseSpecifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCPropertyImplDecl>>(gap::generator<mx::ObjCPropertyImplDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FormatAttr>>(std::optional<mx::FormatAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<FragmentIdList>(FragmentIdList) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FormatArgAttr>>(gap::generator<mx::FormatArgAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Designator>(mx::Designator) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FormatArgAttr>>(std::optional<mx::FormatArgAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FlattenAttr>>(gap::generator<mx::FlattenAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXCtorInitializer>(mx::CXXCtorInitializer) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXCtorInitializer>>(std::optional<mx::CXXCtorInitializer>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FlattenAttr>>(std::optional<mx::FlattenAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FlagEnumAttr>>(gap::generator<mx::FlagEnumAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<bool>>(std::optional<bool>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FlagEnumAttr>>(std::optional<mx::FlagEnumAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FieldDecl>(mx::FieldDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FinalAttr>>(gap::generator<mx::FinalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeclaratorDecl>(mx::DeclaratorDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FinalAttr>>(std::optional<mx::FinalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FastCallAttr>>(gap::generator<mx::FastCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ValueDecl>(mx::ValueDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCImplementationDecl>>(gap::generator<mx::ObjCImplementationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCImplementationDecl>>(std::optional<mx::ObjCImplementationDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NamedDecl>(mx::NamedDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FastCallAttr>>(std::optional<mx::FastCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::EnableIfAttr>>(gap::generator<mx::EnableIfAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VarDecl>(mx::VarDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ExclusiveTrylockFunctionAttr>>(gap::generator<mx::ExclusiveTrylockFunctionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ExclusiveTrylockFunctionAttr>>(std::optional<mx::ExclusiveTrylockFunctionAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VarTemplateDecl>(mx::VarTemplateDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RedeclarableTemplateDecl>(mx::RedeclarableTemplateDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ExcludeFromExplicitInstantiationAttr>>(gap::generator<mx::ExcludeFromExplicitInstantiationAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ExcludeFromExplicitInstantiationAttr>>(std::optional<mx::ExcludeFromExplicitInstantiationAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ErrorAttr>>(gap::generator<mx::ErrorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateDecl>(mx::TemplateDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VarTemplateDecl>>(gap::generator<mx::VarTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ErrorAttr>>(std::optional<mx::ErrorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::EnforceTCBLeafAttr>>(gap::generator<mx::EnforceTCBLeafAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Expr>(mx::Expr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::EnumExtensibilityAttr>>(gap::generator<mx::EnumExtensibilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EnumExtensibilityAttr>>(std::optional<mx::EnumExtensibilityAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ValueStmt>(mx::ValueStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ValueStmt>>(gap::generator<mx::ValueStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EnforceTCBLeafAttr>>(std::optional<mx::EnforceTCBLeafAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::EnforceTCBAttr>>(gap::generator<mx::EnforceTCBAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCPropertyRefExpr>(mx::ObjCPropertyRefExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCCategoryDecl>>(gap::generator<mx::ObjCCategoryDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCCategoryDecl>>(std::optional<mx::ObjCCategoryDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCInterfaceDecl>(mx::ObjCInterfaceDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EnforceTCBAttr>>(std::optional<mx::EnforceTCBAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCContainerDecl>(mx::ObjCContainerDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EnableIfAttr>>(std::optional<mx::EnableIfAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DiagnoseIfAttr>>(gap::generator<mx::DiagnoseIfAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCMethodDecl>(mx::ObjCMethodDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCCategoryImplDecl>>(gap::generator<mx::ObjCCategoryImplDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::EmptyBasesAttr>>(gap::generator<mx::EmptyBasesAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCPropertyDecl>(mx::ObjCPropertyDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCCategoryImplDecl>>(std::optional<mx::ObjCCategoryImplDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::EmptyBasesAttr>>(std::optional<mx::EmptyBasesAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCIvarDecl>(mx::ObjCIvarDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DisableTailCallsAttr>>(gap::generator<mx::DisableTailCallsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ImplicitParamDecl>(mx::ImplicitParamDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DisableTailCallsAttr>>(std::optional<mx::DisableTailCallsAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ParmVarDecl>(mx::ParmVarDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DisableSanitizerInstrumentationAttr>>(gap::generator<mx::DisableSanitizerInstrumentationAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCProtocolDecl>(mx::ObjCProtocolDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DisableSanitizerInstrumentationAttr>>(std::optional<mx::DisableSanitizerInstrumentationAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DiagnoseIfAttr>>(std::optional<mx::DiagnoseIfAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCImplementationDecl>(mx::ObjCImplementationDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AlwaysInlineAttr>>(gap::generator<mx::AlwaysInlineAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FieldDecl>>(std::optional<mx::FieldDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCImplDecl>(mx::ObjCImplDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DiagnoseAsBuiltinAttr>>(gap::generator<mx::DiagnoseAsBuiltinAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DiagnoseAsBuiltinAttr>>(std::optional<mx::DiagnoseAsBuiltinAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCPropertyImplDecl>(mx::ObjCPropertyImplDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DestructorAttr>>(gap::generator<mx::DestructorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCCategoryDecl>(mx::ObjCCategoryDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DestructorAttr>>(std::optional<mx::DestructorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCCategoryImplDecl>(mx::ObjCCategoryImplDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DeprecatedAttr>>(gap::generator<mx::DeprecatedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VariableArrayType>(mx::VariableArrayType) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DeprecatedAttr>>(std::optional<mx::DeprecatedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DeclOrStmtAttr>>(gap::generator<mx::DeclOrStmtAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArrayType>(mx::ArrayType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IndirectFieldDecl>(mx::IndirectFieldDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DeclOrStmtAttr>>(std::optional<mx::DeclOrStmtAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXRecordDecl>(mx::CXXRecordDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AlwaysInlineAttr>>(std::optional<mx::AlwaysInlineAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SuppressAttr>>(gap::generator<mx::SuppressAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RecordDecl>(mx::RecordDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TagDecl>(mx::TagDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SuppressAttr>>(std::optional<mx::SuppressAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoMergeAttr>>(gap::generator<mx::NoMergeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeDecl>(mx::TypeDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoMergeAttr>>(std::optional<mx::NoMergeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypedefNameDecl>(mx::TypedefNameDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoInlineAttr>>(gap::generator<mx::NoInlineAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXConstructorDecl>(mx::CXXConstructorDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoInlineAttr>>(std::optional<mx::NoInlineAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CountedByAttr>>(gap::generator<mx::CountedByAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXMethodDecl>(mx::CXXMethodDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionDecl>(mx::FunctionDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DLLImportAttr>>(gap::generator<mx::DLLImportAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DLLImportStaticLocalAttr>>(gap::generator<mx::DLLImportStaticLocalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DLLImportStaticLocalAttr>>(std::optional<mx::DLLImportStaticLocalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FunctionTemplateDecl>(mx::FunctionTemplateDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VarDecl>>(std::optional<mx::VarDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FriendDecl>(mx::FriendDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DLLImportAttr>>(std::optional<mx::DLLImportAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DeclaratorDecl>>(gap::generator<mx::DeclaratorDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DeclaratorDecl>>(std::optional<mx::DeclaratorDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ClassTemplateDecl>(mx::ClassTemplateDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DLLExportAttr>>(gap::generator<mx::DLLExportAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DLLExportStaticLocalAttr>>(gap::generator<mx::DLLExportStaticLocalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXXDestructorDecl>(mx::CXXDestructorDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DLLExportStaticLocalAttr>>(std::optional<mx::DLLExportStaticLocalAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TokenTree>(mx::TokenTree) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DLLExportAttr>>(std::optional<mx::DLLExportAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RegexQuery>(mx::RegexQuery) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CountedByAttr>>(std::optional<mx::CountedByAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TokenTreeNode>(mx::TokenTreeNode) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CleanupAttr>>(gap::generator<mx::CleanupAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FieldDecl>>(gap::generator<mx::FieldDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CoroWrapperAttr>>(gap::generator<mx::CoroWrapperAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArrayType>>(gap::generator<mx::ArrayType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DefineMacroDirective>(mx::DefineMacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CoroWrapperAttr>>(std::optional<mx::CoroWrapperAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroDirective>(mx::MacroDirective) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CoroReturnTypeAttr>>(gap::generator<mx::CoroReturnTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ExternalSourceSymbolAttr>(mx::ExternalSourceSymbolAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CoroReturnTypeAttr>>(std::optional<mx::CoroReturnTypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArrayType>>(std::optional<mx::ArrayType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::InheritableAttr>(mx::InheritableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AlignValueAttr>(mx::AlignValueAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CoroOnlyDestroyWhenCompleteAttr>>(gap::generator<mx::CoroOnlyDestroyWhenCompleteAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VariableArrayType>>(gap::generator<mx::VariableArrayType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CoroOnlyDestroyWhenCompleteAttr>>(std::optional<mx::CoroOnlyDestroyWhenCompleteAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VariableArrayType>>(std::optional<mx::VariableArrayType>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AliasAttr>(mx::AliasAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CoroLifetimeBoundAttr>>(gap::generator<mx::CoroLifetimeBoundAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CoroLifetimeBoundAttr>>(std::optional<mx::CoroLifetimeBoundAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AbiTagAttr>(mx::AbiTagAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConvergentAttr>>(gap::generator<mx::ConvergentAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeAttr>(mx::TypeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CoroDisableLifetimeBoundAttr>>(gap::generator<mx::CoroDisableLifetimeBoundAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CoroDisableLifetimeBoundAttr>>(std::optional<mx::CoroDisableLifetimeBoundAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SPtrAttr>(mx::SPtrAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Ptr64Attr>(mx::Ptr64Attr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConvergentAttr>>(std::optional<mx::ConvergentAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConsumableAttr>>(gap::generator<mx::ConsumableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Ptr32Attr>(mx::Ptr32Attr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConsumableSetOnReadAttr>>(gap::generator<mx::ConsumableSetOnReadAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConsumableSetOnReadAttr>>(std::optional<mx::ConsumableSetOnReadAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLPrivateAddressSpaceAttr>(mx::OpenCLPrivateAddressSpaceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConsumableAutoCastAttr>>(gap::generator<mx::ConsumableAutoCastAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IndirectFieldDecl>>(gap::generator<mx::IndirectFieldDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLLocalAddressSpaceAttr>(mx::OpenCLLocalAddressSpaceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConsumableAutoCastAttr>>(std::optional<mx::ConsumableAutoCastAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IndirectFieldDecl>>(std::optional<mx::IndirectFieldDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLGlobalHostAddressSpaceAttr>(mx::OpenCLGlobalHostAddressSpaceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConsumableAttr>>(std::optional<mx::ConsumableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLGlobalDeviceAddressSpaceAttr>(mx::OpenCLGlobalDeviceAddressSpaceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConstructorAttr>>(gap::generator<mx::ConstructorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLGlobalAddressSpaceAttr>(mx::OpenCLGlobalAddressSpaceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConstructorAttr>>(std::optional<mx::ConstructorAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConstInitAttr>>(gap::generator<mx::ConstInitAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLGenericAddressSpaceAttr>(mx::OpenCLGenericAddressSpaceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenCLConstantAddressSpaceAttr>(mx::OpenCLConstantAddressSpaceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConstInitAttr>>(std::optional<mx::ConstInitAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConstAttr>>(gap::generator<mx::ConstAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeDecl>>(gap::generator<mx::TypeDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCKindOfAttr>(mx::ObjCKindOfAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConstAttr>>(std::optional<mx::ConstAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCInertUnsafeUnretainedAttr>(mx::ObjCInertUnsafeUnretainedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CommonAttr>>(gap::generator<mx::CommonAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeDecl>>(std::optional<mx::TypeDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MethodRefFlags>(mx::MethodRefFlags) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeclCategory>(mx::DeclCategory) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Token>(mx::Token) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DiagnoseIfAttr>(mx::DiagnoseIfAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXBoolLiteralExpr>>(gap::generator<mx::CXXBoolLiteralExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXTemporaryObjectExpr>>(gap::generator<mx::CXXTemporaryObjectExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ModifiableType>(mx::ModifiableType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PseudoKind>(mx::PseudoKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTaskwaitDirective>>(gap::generator<mx::OMPTaskwaitDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DiagnoseAsBuiltinAttr>(mx::DiagnoseAsBuiltinAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXTemporaryObjectExpr>>(std::optional<mx::CXXTemporaryObjectExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LifetimeExtendedTemporaryDecl>>(std::optional<mx::LifetimeExtendedTemporaryDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MultiVersionKind>(mx::MultiVersionKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::EntityCategory>(mx::EntityCategory) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LifetimeExtendedTemporaryDecl>>(gap::generator<mx::LifetimeExtendedTemporaryDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DestructorAttr>(mx::DestructorAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTaskwaitDirective>>(std::optional<mx::OMPTaskwaitDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NameKind>(mx::NameKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Attr>(mx::Attr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NeedExtraManglingDecl>(mx::NeedExtraManglingDecl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeprecatedAttr>(mx::DeprecatedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTaskgroupDirective>>(gap::generator<mx::OMPTaskgroupDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXBoolLiteralExpr>>(std::optional<mx::CXXBoolLiteralExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NestedNameSpecifierDependence>(mx::NestedNameSpecifierDependence) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::MacroKind>(mx::MacroKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DeclOrStmtAttr>(mx::DeclOrStmtAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTaskgroupDirective>>(std::optional<mx::OMPTaskgroupDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NonOdrUseReason>(mx::NonOdrUseReason) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BuiltinReferenceKind>(mx::BuiltinReferenceKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BlockExpr>>(gap::generator<mx::BlockExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AlwaysInlineAttr>(mx::AlwaysInlineAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NonceObjCInterface>(mx::NonceObjCInterface) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CXXBindTemporaryExpr>>(gap::generator<mx::CXXBindTemporaryExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSPropertySubscriptExpr>>(gap::generator<mx::MSPropertySubscriptExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NullabilityKind>(mx::NullabilityKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SuppressAttr>(mx::SuppressAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CXXBindTemporaryExpr>>(std::optional<mx::CXXBindTemporaryExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSPropertySubscriptExpr>>(std::optional<mx::MSPropertySubscriptExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTaskDirective>>(std::optional<mx::OMPTaskDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OMPDeclareReductionInitKind>(mx::OMPDeclareReductionInitKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoMergeAttr>(mx::NoMergeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCBridgeCastKind>(mx::ObjCBridgeCastKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCPropertyDecl>>(gap::generator<mx::ObjCPropertyDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::NoInlineAttr>(mx::NoInlineAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCImplementationControl>(mx::ObjCImplementationControl) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TokenTreeNodeKind>(mx::TokenTreeNodeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BlockExpr>>(std::optional<mx::BlockExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSPropertyRefExpr>>(std::optional<mx::MSPropertyRefExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCInstanceTypeFamily>(mx::ObjCInstanceTypeFamily) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TokenKind>(mx::TokenKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DLLImportStaticLocalAttr>(mx::DLLImportStaticLocalAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetUpdateDirective>>(gap::generator<mx::OMPTargetUpdateDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetUpdateDirective>>(std::optional<mx::OMPTargetUpdateDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BlockDecl>>(gap::generator<mx::BlockDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCLifetime>(mx::ObjCLifetime) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TokenCategory>(mx::TokenCategory) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::MSPropertyDecl>>(gap::generator<mx::MSPropertyDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DLLImportAttr>(mx::DLLImportAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCMethodFamily>(mx::ObjCMethodFamily) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IndexStatus>(mx::IndexStatus) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetTeamsDirective>>(gap::generator<mx::OMPTargetTeamsDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BlockDecl>>(std::optional<mx::BlockDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DLLExportStaticLocalAttr>(mx::DLLExportStaticLocalAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::MSPropertyDecl>>(std::optional<mx::MSPropertyDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCPropertyQueryKind>(mx::ObjCPropertyQueryKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::IncludePathLocation>(mx::IncludePathLocation) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetTeamsDirective>>(std::optional<mx::OMPTargetTeamsDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCStringFormatFamily>(mx::ObjCStringFormatFamily) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PathKind>(mx::PathKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::DLLExportAttr>(mx::DLLExportAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::LambdaExpr>>(gap::generator<mx::LambdaExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCSubstitutionContext>(mx::ObjCSubstitutionContext) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::FileType>(mx::FileType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CountedByAttr>(mx::CountedByAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::LambdaExpr>>(std::optional<mx::LambdaExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ObjCTypeParamVariance>(mx::ObjCTypeParamVariance) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CompilerName>(mx::CompilerName) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetParallelDirective>>(gap::generator<mx::OMPTargetParallelDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroWrapperAttr>(mx::CoroWrapperAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetParallelDirective>>(std::optional<mx::OMPTargetParallelDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OnOffSwitch>(mx::OnOffSwitch) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TargetLanguage>(mx::TargetLanguage) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OnStackType>(mx::OnStackType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroReturnTypeAttr>(mx::CoroReturnTypeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AcquireCapabilityAttrSpelling>(mx::AcquireCapabilityAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPAdjustArgsOpKind>(mx::OpenMPAdjustArgsOpKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroOnlyDestroyWhenCompleteAttr>(mx::CoroOnlyDestroyWhenCompleteAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPAtClauseKind>(mx::OpenMPAtClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BinaryOperator>>(gap::generator<mx::BinaryOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroLifetimeBoundAttr>(mx::CoroLifetimeBoundAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetExitDataDirective>>(gap::generator<mx::OMPTargetExitDataDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPAtomicDefaultMemOrderClauseKind>(mx::OpenMPAtomicDefaultMemOrderClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetExitDataDirective>>(std::optional<mx::OMPTargetExitDataDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BinaryOperator>>(std::optional<mx::BinaryOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPBindClauseKind>(mx::OpenMPBindClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CoroDisableLifetimeBoundAttr>(mx::CoroDisableLifetimeBoundAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPDefaultmapClauseKind>(mx::OpenMPDefaultmapClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TemplateArgument>>(std::optional<mx::TemplateArgument>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetDirective>>(gap::generator<mx::OMPTargetDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConvergentAttr>(mx::ConvergentAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::IntegerLiteral>>(gap::generator<mx::IntegerLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPDefaultmapClauseModifier>(mx::OpenMPDefaultmapClauseModifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetEnterDataDirective>>(gap::generator<mx::OMPTargetEnterDataDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConsumableSetOnReadAttr>(mx::ConsumableSetOnReadAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetEnterDataDirective>>(std::optional<mx::OMPTargetEnterDataDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::IntegerLiteral>>(std::optional<mx::IntegerLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPDependClauseKind>(mx::OpenMPDependClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPDeviceClauseModifier>(mx::OpenMPDeviceClauseModifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConsumableAutoCastAttr>(mx::ConsumableAutoCastAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TemplateParameterList>>(std::optional<mx::TemplateParameterList>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ImaginaryLiteral>>(gap::generator<mx::ImaginaryLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPDeviceType>(mx::OpenMPDeviceType) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConsumableAttr>(mx::ConsumableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetDirective>>(std::optional<mx::OMPTargetDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ImplicitValueInitExpr>>(gap::generator<mx::ImplicitValueInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPDistScheduleClauseKind>(mx::OpenMPDistScheduleClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AtomicExpr>>(gap::generator<mx::AtomicExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ImplicitValueInitExpr>>(std::optional<mx::ImplicitValueInitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CompoundAssignOperator>>(gap::generator<mx::CompoundAssignOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstructorAttr>(mx::ConstructorAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPDoacrossClauseModifier>(mx::OpenMPDoacrossClauseModifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPSingleDirective>>(gap::generator<mx::OMPSingleDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CompoundAssignOperator>>(std::optional<mx::CompoundAssignOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<std::variant<mx::NamedDecl, mx::DefineMacroDirective, mx::File>>>(gap::generator<std::variant<mx::NamedDecl, mx::DefineMacroDirective, mx::File>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPGrainsizeClauseModifier>(mx::OpenMPGrainsizeClauseModifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstInitAttr>(mx::ConstInitAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTargetDataDirective>>(gap::generator<mx::OMPTargetDataDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTargetDataDirective>>(std::optional<mx::OMPTargetDataDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPLastprivateModifier>(mx::OpenMPLastprivateModifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ConstAttr>(mx::ConstAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ImaginaryLiteral>>(std::optional<mx::ImaginaryLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPLinearClauseKind>(mx::OpenMPLinearClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AtomicExpr>>(std::optional<mx::AtomicExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CommonAttr>(mx::CommonAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPMapClauseKind>(mx::OpenMPMapClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::GNUNullExpr>>(gap::generator<mx::GNUNullExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPMapModifierKind>(mx::OpenMPMapModifierKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ColdAttr>(mx::ColdAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPSingleDirective>>(std::optional<mx::OMPSingleDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AsTypeExpr>>(gap::generator<mx::AsTypeExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::GenericSelectionExpr>>(gap::generator<mx::GenericSelectionExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPMotionModifierKind>(mx::OpenMPMotionModifierKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::GenericSelectionExpr>>(std::optional<mx::GenericSelectionExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CodeSegAttr>(mx::CodeSegAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPSectionDirective>>(gap::generator<mx::OMPSectionDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AsTypeExpr>>(std::optional<mx::AsTypeExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPNumTasksClauseModifier>(mx::OpenMPNumTasksClauseModifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CodeModelAttr>(mx::CodeModelAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPSectionsDirective>>(gap::generator<mx::OMPSectionsDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPOrderClauseKind>(mx::OpenMPOrderClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArrayTypeTraitExpr>>(gap::generator<mx::ArrayTypeTraitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ExternalSourceSymbolAttr>>(std::optional<mx::ExternalSourceSymbolAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPOrderClauseModifier>(mx::OpenMPOrderClauseModifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CmseNSEntryAttr>(mx::CmseNSEntryAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPSectionsDirective>>(std::optional<mx::OMPSectionsDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ValueDecl>>(gap::generator<mx::ValueDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::InheritableAttr>>(gap::generator<mx::InheritableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPReductionClauseModifier>(mx::OpenMPReductionClauseModifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArrayTypeTraitExpr>>(std::optional<mx::ArrayTypeTraitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CleanupAttr>(mx::CleanupAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NamedDecl>>(gap::generator<mx::NamedDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::InheritableAttr>>(std::optional<mx::InheritableAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPScheduleClauseKind>(mx::OpenMPScheduleClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::GNUNullExpr>>(std::optional<mx::GNUNullExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CapturedRecordAttr>(mx::CapturedRecordAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArraySubscriptExpr>>(gap::generator<mx::ArraySubscriptExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPScheduleClauseModifier>(mx::OpenMPScheduleClauseModifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ExternalSourceSymbolAttr>>(gap::generator<mx::ExternalSourceSymbolAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OpenMPSeverityClauseKind>(mx::OpenMPSeverityClauseKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CapabilityAttr>(mx::CapabilityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPSectionDirective>>(std::optional<mx::OMPSectionDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FullExpr>>(gap::generator<mx::FullExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArraySubscriptExpr>>(std::optional<mx::ArraySubscriptExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OverloadedOperatorKind>(mx::OverloadedOperatorKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FunctionParmPackExpr>>(gap::generator<mx::FunctionParmPackExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CallbackAttr>(mx::CallbackAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPScopeDirective>>(gap::generator<mx::OMPScopeDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::OverloadsShown>(mx::OverloadsShown) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArrayInitLoopExpr>>(gap::generator<mx::ArrayInitLoopExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FunctionParmPackExpr>>(std::optional<mx::FunctionParmPackExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Reference>(mx::Reference) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CallableWhenAttr>(mx::CallableWhenAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ParameterABI>(mx::ParameterABI) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPScopeDirective>>(std::optional<mx::OMPScopeDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArrayInitLoopExpr>>(std::optional<mx::ArrayInitLoopExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ParenLocsOffsets>(mx::ParenLocsOffsets) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CXX11NoReturnAttr>(mx::CXX11NoReturnAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPScanDirective>>(gap::generator<mx::OMPScanDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaFPKind>(mx::PragmaFPKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FullExpr>>(std::optional<mx::FullExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDASharedAttr>(mx::CUDASharedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArrayInitIndexExpr>>(gap::generator<mx::ArrayInitIndexExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaFloatControlKind>(mx::PragmaFloatControlKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPScanDirective>>(std::optional<mx::OMPScanDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDALaunchBoundsAttr>(mx::CUDALaunchBoundsAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ExprWithCleanups>>(gap::generator<mx::ExprWithCleanups>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaMSCommentKind>(mx::PragmaMSCommentKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArrayInitIndexExpr>>(std::optional<mx::ArrayInitIndexExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaMSPointersToMembersKind>(mx::PragmaMSPointersToMembersKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDAInvalidTargetAttr>(mx::CUDAInvalidTargetAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ExprWithCleanups>>(std::optional<mx::ExprWithCleanups>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaMSStructKind>(mx::PragmaMSStructKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDAHostAttr>(mx::CUDAHostAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelSectionsDirective>>(gap::generator<mx::OMPParallelSectionsDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PragmaSectionFlag>(mx::PragmaSectionFlag) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConditionalOperator>>(gap::generator<mx::ConditionalOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelSectionsDirective>>(std::optional<mx::OMPParallelSectionsDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AbstractConditionalOperator>>(gap::generator<mx::AbstractConditionalOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDAGlobalAttr>(mx::CUDAGlobalAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::PredefinedIdentKind>(mx::PredefinedIdentKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AbstractConditionalOperator>>(std::optional<mx::AbstractConditionalOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ConstantExpr>>(gap::generator<mx::ConstantExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Qualified>(mx::Qualified) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDADeviceBuiltinTextureTypeAttr>(mx::CUDADeviceBuiltinTextureTypeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConstantExpr>>(std::optional<mx::ConstantExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RangeExprOffset>(mx::RangeExprOffset) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDADeviceBuiltinSurfaceTypeAttr>(mx::CUDADeviceBuiltinSurfaceTypeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CodeAlignAttr>>(gap::generator<mx::CodeAlignAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ConditionalOperator>>(std::optional<mx::ConditionalOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RangeLocOffset>(mx::RangeLocOffset) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AlignValueAttr>>(gap::generator<mx::AlignValueAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelMasterDirective>>(gap::generator<mx::OMPParallelMasterDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FloatingLiteral>>(gap::generator<mx::FloatingLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDADeviceAttr>(mx::CUDADeviceAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelMasterDirective>>(std::optional<mx::OMPParallelMasterDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RecordArgPassingKind>(mx::RecordArgPassingKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AlignValueAttr>>(std::optional<mx::AlignValueAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::RefQualifierKind>(mx::RefQualifierKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AliasAttr>>(gap::generator<mx::AliasAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CUDAConstantAttr>(mx::CUDAConstantAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FloatingLiteral>>(std::optional<mx::FloatingLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::VAArgExpr>>(gap::generator<mx::VAArgExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReservedIdentifierStatus>(mx::ReservedIdentifierStatus) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BinaryConditionalOperator>>(gap::generator<mx::BinaryConditionalOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CPUSpecificAttr>(mx::CPUSpecificAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AliasAttr>>(std::optional<mx::AliasAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BinaryConditionalOperator>>(std::optional<mx::BinaryConditionalOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::FixedPointLiteral>>(gap::generator<mx::FixedPointLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ReservedLiteralSuffixIdStatus>(mx::ReservedLiteralSuffixIdStatus) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AbiTagAttr>>(gap::generator<mx::AbiTagAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPOrderedDirective>>(gap::generator<mx::OMPOrderedDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CPUDispatchAttr>(mx::CPUDispatchAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelMaskedDirective>>(gap::generator<mx::OMPParallelMaskedDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SFINAEResponse>(mx::SFINAEResponse) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelMaskedDirective>>(std::optional<mx::OMPParallelMaskedDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::FixedPointLiteral>>(std::optional<mx::FixedPointLiteral>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AbiTagAttr>>(std::optional<mx::AbiTagAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SYCLMajorVersion>(mx::SYCLMajorVersion) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFUnknownTransferAttr>(mx::CFUnknownTransferAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeAttr>>(gap::generator<mx::TypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::VAArgExpr>>(std::optional<mx::VAArgExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SanitizerOrdinal>(mx::SanitizerOrdinal) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ExpressionTraitExpr>>(gap::generator<mx::ExpressionTraitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFReturnsRetainedAttr>(mx::CFReturnsRetainedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SelectorLocationsKind>(mx::SelectorLocationsKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeAttr>>(std::optional<mx::TypeAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnaryOperator>>(gap::generator<mx::UnaryOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ExtVectorElementExpr>>(gap::generator<mx::ExtVectorElementExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SPtrAttr>>(gap::generator<mx::SPtrAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFReturnsNotRetainedAttr>(mx::CFReturnsNotRetainedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPParallelDirective>>(gap::generator<mx::OMPParallelDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ShaderStage>(mx::ShaderStage) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ExtVectorElementExpr>>(std::optional<mx::ExtVectorElementExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPParallelDirective>>(std::optional<mx::OMPParallelDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnaryOperator>>(std::optional<mx::UnaryOperator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SignReturnAddressKeyKind>(mx::SignReturnAddressKeyKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFICanonicalJumpTableAttr>(mx::CFICanonicalJumpTableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SPtrAttr>>(std::optional<mx::SPtrAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Ptr64Attr>>(gap::generator<mx::Ptr64Attr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SignReturnAddressScopeKind>(mx::SignReturnAddressScopeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFGuardAttr>(mx::CFGuardAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SignedOverflowBehaviorTy>(mx::SignedOverflowBehaviorTy) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Ptr64Attr>>(std::optional<mx::Ptr64Attr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CFAuditedTransferAttr>(mx::CFAuditedTransferAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SourceLocIdentKind>(mx::SourceLocIdentKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::Ptr32Attr>>(gap::generator<mx::Ptr32Attr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ExpressionTraitExpr>>(std::optional<mx::ExpressionTraitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPOrderedDirective>>(std::optional<mx::OMPOrderedDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypoExpr>>(gap::generator<mx::TypoExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SpecialMemberFlags>(mx::SpecialMemberFlags) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::CDeclAttr>(mx::CDeclAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::UnaryExprOrTypeTraitExpr>>(gap::generator<mx::UnaryExprOrTypeTraitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Ptr32Attr>>(std::optional<mx::Ptr32Attr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::UnaryExprOrTypeTraitExpr>>(std::optional<mx::UnaryExprOrTypeTraitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SpecifierKind>(mx::SpecifierKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AttributedStmt>>(gap::generator<mx::AttributedStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::C11NoReturnAttr>(mx::C11NoReturnAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPMetaDirective>>(gap::generator<mx::OMPMetaDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::Designator>>(std::optional<mx::Designator>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StackProtectorMode>(mx::StackProtectorMode) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AttributedStmt>>(std::optional<mx::AttributedStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BuiltinAttr>(mx::BuiltinAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StorageClass>(mx::StorageClass) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLPrivateAddressSpaceAttr>>(gap::generator<mx::OpenCLPrivateAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPMetaDirective>>(std::optional<mx::OMPMetaDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLPrivateAddressSpaceAttr>>(std::optional<mx::OpenCLPrivateAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypoExpr>>(std::optional<mx::TypoExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StorageDuration>(mx::StorageDuration) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BlocksAttr>(mx::BlocksAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwitchStmt>>(gap::generator<mx::SwitchStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPMasterDirective>>(gap::generator<mx::OMPMasterDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StoredNameKind>(mx::StoredNameKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLLocalAddressSpaceAttr>>(gap::generator<mx::OpenCLLocalAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BTFDeclTagAttr>(mx::BTFDeclTagAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TypeTraitExpr>>(gap::generator<mx::TypeTraitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLLocalAddressSpaceAttr>>(std::optional<mx::OpenCLLocalAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwitchStmt>>(std::optional<mx::SwitchStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StoredSpecifierKind>(mx::StoredSpecifierKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPMasterDirective>>(std::optional<mx::OMPMasterDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BPFPreserveStaticOffsetAttr>(mx::BPFPreserveStaticOffsetAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TypeTraitExpr>>(std::optional<mx::TypeTraitExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StrictFlexArraysLevelKind>(mx::StrictFlexArraysLevelKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLGlobalHostAddressSpaceAttr>>(gap::generator<mx::OpenCLGlobalHostAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SwitchCase>>(gap::generator<mx::SwitchCase>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::StringLiteralKind>(mx::StringLiteralKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLGlobalHostAddressSpaceAttr>>(std::optional<mx::OpenCLGlobalHostAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::BPFPreserveAccessIndexAttr>(mx::BPFPreserveAccessIndexAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPMaskedDirective>>(gap::generator<mx::OMPMaskedDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SubExpr>(mx::SubExpr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SwitchCase>>(std::optional<mx::SwitchCase>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AvailableOnlyInDefaultEvalMethodAttr>(mx::AvailableOnlyInDefaultEvalMethodAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLGlobalDeviceAddressSpaceAttr>>(gap::generator<mx::OpenCLGlobalDeviceAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPMaskedDirective>>(std::optional<mx::OMPMaskedDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SubStmt>(mx::SubStmt) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLGlobalDeviceAddressSpaceAttr>>(std::optional<mx::OpenCLGlobalDeviceAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SubstNonTypeTemplateParmPackExpr>>(gap::generator<mx::SubstNonTypeTemplateParmPackExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AvailabilityAttr>(mx::AvailabilityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SubstNonTypeTemplateParmPackExpr>>(std::optional<mx::SubstNonTypeTemplateParmPackExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::SyncScope>(mx::SyncScope) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLGlobalAddressSpaceAttr>>(gap::generator<mx::OpenCLGlobalAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Syntax>(mx::Syntax) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AssumptionAttr>(mx::AssumptionAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLGlobalAddressSpaceAttr>>(std::optional<mx::OpenCLGlobalAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPLoopBasedDirective>>(gap::generator<mx::OMPLoopBasedDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::StmtExpr>>(gap::generator<mx::StmtExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TQ>(mx::TQ) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPLoopBasedDirective>>(std::optional<mx::OMPLoopBasedDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::DefaultStmt>>(gap::generator<mx::DefaultStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AssumeAlignedAttr>(mx::AssumeAlignedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SubstNonTypeTemplateParmExpr>>(gap::generator<mx::SubstNonTypeTemplateParmExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TagTypeKind>(mx::TagTypeKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLGenericAddressSpaceAttr>>(gap::generator<mx::OpenCLGenericAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::DefaultStmt>>(std::optional<mx::DefaultStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NonTypeTemplateParmDecl>>(gap::generator<mx::NonTypeTemplateParmDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AVRInterruptAttrSpelling>(mx::AVRInterruptAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLGenericAddressSpaceAttr>>(std::optional<mx::OpenCLGenericAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AssertSharedLockAttr>(mx::AssertSharedLockAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TailPaddingUseRules>(mx::TailPaddingUseRules) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NonTypeTemplateParmDecl>>(std::optional<mx::NonTypeTemplateParmDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCKindOfAttr>>(gap::generator<mx::ObjCKindOfAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPUnrollDirective>>(gap::generator<mx::OMPUnrollDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RedeclarableTemplateDecl>>(gap::generator<mx::RedeclarableTemplateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CaseStmt>>(gap::generator<mx::CaseStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateArgumentDependence>(mx::TemplateArgumentDependence) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AssertExclusiveLockAttr>(mx::AssertExclusiveLockAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OpenCLConstantAddressSpaceAttr>>(gap::generator<mx::OpenCLConstantAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPLoopTransformationDirective>>(gap::generator<mx::OMPLoopTransformationDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OpenCLConstantAddressSpaceAttr>>(std::optional<mx::OpenCLConstantAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateNameDependence>(mx::TemplateNameDependence) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPLoopTransformationDirective>>(std::optional<mx::OMPLoopTransformationDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AssertCapabilityAttr>(mx::AssertCapabilityAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CaseStmt>>(std::optional<mx::CaseStmt>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TemplateSpecializationKind>(mx::TemplateSpecializationKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCKindOfAttr>>(std::optional<mx::ObjCKindOfAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AsmLabelAttr>(mx::AsmLabelAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TextDiagnosticFormat>(mx::TextDiagnosticFormat) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPUnrollDirective>>(std::optional<mx::OMPUnrollDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ThreadModelKind>(mx::ThreadModelKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArtificialAttr>(mx::ArtificialAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCGCAttr>>(gap::generator<mx::ObjCGCAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ObjCInertUnsafeUnretainedAttr>>(gap::generator<mx::ObjCInertUnsafeUnretainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPRequiresDecl>>(gap::generator<mx::OMPRequiresDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ThreadStorageClassSpecifier>(mx::ThreadStorageClassSpecifier) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCInertUnsafeUnretainedAttr>>(std::optional<mx::ObjCInertUnsafeUnretainedAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmNewAttr>(mx::ArmNewAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPTileDirective>>(gap::generator<mx::OMPTileDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SubstNonTypeTemplateParmExpr>>(std::optional<mx::SubstNonTypeTemplateParmExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::AccessSpecDecl>>(gap::generator<mx::AccessSpecDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TrailingAllocKind>(mx::TrailingAllocKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::AccessSpecDecl>>(std::optional<mx::AccessSpecDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmLocallyStreamingAttr>(mx::ArmLocallyStreamingAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TranslationUnitKind>(mx::TranslationUnitKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ObjCGCAttr>>(std::optional<mx::ObjCGCAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPTileDirective>>(std::optional<mx::OMPTileDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::NoDerefAttr>>(gap::generator<mx::NoDerefAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TrivialAutoVarInitKind>(mx::TrivialAutoVarInitKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArmBuiltinAliasAttr>(mx::ArmBuiltinAliasAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::StmtExpr>>(std::optional<mx::StmtExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPLoopDirective>>(gap::generator<mx::OMPLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeDependence>(mx::TypeDependence) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::NoDerefAttr>>(std::optional<mx::NoDerefAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArgumentWithTypeTagAttr>(mx::ArgumentWithTypeTagAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPThreadPrivateDecl>>(gap::generator<mx::OMPThreadPrivateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SourceLocExpr>>(gap::generator<mx::SourceLocExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPDeclarativeDirectiveDecl>>(gap::generator<mx::OMPDeclarativeDirectiveDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeLocClass>(mx::TypeLocClass) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPLoopDirective>>(std::optional<mx::OMPLoopDirective>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPDeclarativeDirectiveDecl>>(std::optional<mx::OMPDeclarativeDirectiveDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ArcWeakrefUnavailableAttr>(mx::ArcWeakrefUnavailableAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HLSLParamModifierAttr>>(gap::generator<mx::HLSLParamModifierAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeOfKind>(mx::TypeOfKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HLSLParamModifierAttr>>(std::optional<mx::HLSLParamModifierAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SourceLocExpr>>(std::optional<mx::SourceLocExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeSpecifierSign>(mx::TypeSpecifierSign) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnyX86NoCfCheckAttr>(mx::AnyX86NoCfCheckAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::CmseNSCallAttr>>(gap::generator<mx::CmseNSCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeSpecifierType>(mx::TypeSpecifierType) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SizeOfPackExpr>>(gap::generator<mx::SizeOfPackExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPThreadPrivateDecl>>(std::optional<mx::OMPThreadPrivateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnyX86NoCallerSavedRegistersAttr>(mx::AnyX86NoCallerSavedRegistersAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::HLSLGroupSharedAddressSpaceAttr>>(gap::generator<mx::HLSLGroupSharedAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeSpecifierWidth>(mx::TypeSpecifierWidth) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::HLSLGroupSharedAddressSpaceAttr>>(std::optional<mx::HLSLGroupSharedAddressSpaceAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnyX86InterruptAttr>(mx::AnyX86InterruptAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SizeOfPackExpr>>(std::optional<mx::SizeOfPackExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeSpecifiersPipe>(mx::TypeSpecifiersPipe) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::ARMInterruptAttrSpelling>(mx::ARMInterruptAttrSpelling) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::CmseNSCallAttr>>(std::optional<mx::CmseNSCallAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::TypeTrait>(mx::TypeTrait) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AnalyzerNoReturnAttr>(mx::AnalyzerNoReturnAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPRequiresDecl>>(std::optional<mx::OMPRequiresDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::BTFTypeTagAttr>>(gap::generator<mx::BTFTypeTagAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<std::vector<mx::TemplateArgument>>>(std::optional<std::vector<mx::TemplateArgument>>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnaryExprOrTypeTrait>(mx::UnaryExprOrTypeTrait) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AlwaysDestroyAttr>(mx::AlwaysDestroyAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::OMPAllocateDecl>>(gap::generator<mx::OMPAllocateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::UnaryOperatorKind>(mx::UnaryOperatorKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::BTFTypeTagAttr>>(std::optional<mx::BTFTypeTagAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AllocSizeAttr>(mx::AllocSizeAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ShuffleVectorExpr>>(gap::generator<mx::ShuffleVectorExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::APValueKind>(mx::APValueKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::OMPAllocateDecl>>(std::optional<mx::OMPAllocateDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArmStreamingAttr>>(gap::generator<mx::ArmStreamingAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ShuffleVectorExpr>>(std::optional<mx::ShuffleVectorExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VectorKind>(mx::VectorKind) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AllocAlignAttr>(mx::AllocAlignAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArmStreamingCompatibleAttr>>(gap::generator<mx::ArmStreamingCompatibleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArmStreamingCompatibleAttr>>(std::optional<mx::ArmStreamingCompatibleAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::Visibility>(mx::Visibility) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::TranslationUnitDecl>>(gap::generator<mx::TranslationUnitDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AlignedAttr>(mx::AlignedAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VisibilityForcedKinds>(mx::VisibilityForcedKinds) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArmStreamingAttr>>(std::optional<mx::ArmStreamingAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AlignNaturalAttr>(mx::AlignNaturalAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::RequiresExpr>>(gap::generator<mx::RequiresExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::TranslationUnitDecl>>(std::optional<mx::TranslationUnitDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::VisibilityFromDLLStorageClassKinds>(mx::VisibilityFromDLLStorageClassKinds) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::ArmPreservesAttr>>(gap::generator<mx::ArmPreservesAttr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::SYCLUniqueStableNameExpr>>(gap::generator<mx::SYCLUniqueStableNameExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::SYCLUniqueStableNameExpr>>(std::optional<mx::SYCLUniqueStableNameExpr>) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AttributeSyntax>(mx::AttributeSyntax) noexcept;

template MX_EXPORT SharedPyObject *to_python<mx::AlignMac68kAttr>(mx::AlignMac68kAttr) noexcept;

template MX_EXPORT SharedPyObject *to_python<gap::generator<mx::StaticAssertDecl>>(gap::generator<mx::StaticAssertDecl>) noexcept;

template MX_EXPORT SharedPyObject *to_python<std::optional<mx::ArmPreservesAttr>>(std::optional<mx::ArmPreservesAttr>) noexcept;
}  // namespace mx
