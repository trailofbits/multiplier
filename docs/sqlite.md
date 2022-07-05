# SQLite bindings for Multiplier

> This document has been automatically generated and provides a reference to the Multiplier API as exposed by the SQLite extension module.

## Connections

After loading the Multiplier SQLite extension into the SQLite session, the `MultiplierConnection` virtual table will be made available. This table is used to establish connections to Multiplier indices:

    INSERT INTO MultiplierConnection(name, host, port) VALUES ('default', 'localhost', '50051');

Use `'unix'` as `host` value to establish connections to Unix sockets.

Once a connection has been established, the tables described in this document can be instantiated using the following syntax:

    CREATE VIRTUAL TABLE CustomName USING multiplier(TableName, connection_name);

where `CustomName` is a name of your choice to be used in queries, and `TableName` refers to one of the tables described in this document. Notice that the connection name is not quoted in this command.

As an example, this command instantiates the `Decl` table for the connection `default`:

    CREATE VIRTUAL TABLE Decl USING multiplier(Decl, default);


## `File` table

Contains two fields `id` and `name`.

## `Fragment` table

Contains two field `id` and `file_id`.

## `Reference` table

Contains two fields `use_id` and `user_id`. It contains a row for each time a `Decl` with id `use_id` is referenced by a `Stmt` with id `user_id`.

This table can only be queried on `use_id`.

## `RegexQuery` table

Contains three fields:

* `query`: Regex that should be used for querying
* `variables`: JSON array of captured variable names
* `captures`: JSON object with two entries: `named` and `indexed`. `named` is an object that contains an entry for each of the captured variable names, consisting of a capture object. `indexed` is an array of capture objects containing all capture groups.

A capture object contains an array of token ids `tokens` and an optional `data` field containing the capture data represented as a string.

This table can only be queried on `query`.

## `WeggliQuery` table

Contains three fields:

* `query`: Weggli expression that should be used for querying
* `variables`: JSON array of captured variable names
* `captures`: JSON object with an entry for each of the variables contained in `variables`. Every entry will consist of an object containing a `tokens` array of token ids.

This table can only be queried on `query`.

## Enum functions

These functions allow users to refer to the numeric value of enum constants using their name. For example, `BuiltinTypeKind("U_LONG")` is equivalent to accessing `BuiltinTypeKind::U_LONG` in C++.

<details><summary><a name="DeclKind"></a>DeclKind</summary>

Available enumerations:

* `ACCESS_SPEC`
* `BASE_USING`
* `BINDING`
* `BLOCK`
* `BUILTIN_TEMPLATE`
* `CXX_CONSTRUCTOR`
* `CXX_CONVERSION`
* `CXX_DEDUCTION_GUIDE`
* `CXX_DESTRUCTOR`
* `CXX_METHOD`
* `CXX_RECORD`
* `CAPTURED`
* `CLASS_SCOPE_FUNCTION_SPECIALIZATION`
* `CLASS_TEMPLATE`
* `CLASS_TEMPLATE_PARTIAL_SPECIALIZATION`
* `CLASS_TEMPLATE_SPECIALIZATION`
* `CONCEPT`
* `CONSTRUCTOR_USING_SHADOW`
* `DECLARATOR`
* `DECOMPOSITION`
* `EMPTY`
* `ENUM_CONSTANT`
* `ENUM`
* `EXPORT`
* `EXTERN_C_CONTEXT`
* `FIELD`
* `FILE_SCOPE_ASM`
* `FRIEND`
* `FRIEND_TEMPLATE`
* `FUNCTION`
* `FUNCTION_TEMPLATE`
* `IMPLICIT_PARAM`
* `IMPORT`
* `INDIRECT_FIELD`
* `LABEL`
* `LIFETIME_EXTENDED_TEMPORARY`
* `LINKAGE_SPEC`
* `MS_GUID`
* `MS_PROPERTY`
* `NAMED`
* `NAMESPACE_ALIAS`
* `NAMESPACE`
* `NON_TYPE_TEMPLATE_PARM`
* `OMP_ALLOCATE`
* `OMP_CAPTURED_EXPR`
* `OMP_DECLARE_MAPPER`
* `OMP_DECLARE_REDUCTION`
* `OMP_REQUIRES`
* `OMP_THREAD_PRIVATE`
* `OBJ_C_AT_DEFS_FIELD`
* `OBJ_C_CATEGORY`
* `OBJ_C_CATEGORY_IMPL`
* `OBJ_C_COMPATIBLE_ALIAS`
* `OBJ_C_CONTAINER`
* `OBJ_C_IMPL`
* `OBJ_C_IMPLEMENTATION`
* `OBJ_C_INTERFACE`
* `OBJ_C_IVAR`
* `OBJ_C_METHOD`
* `OBJ_C_PROPERTY`
* `OBJ_C_PROPERTY_IMPL`
* `OBJ_C_PROTOCOL`
* `OBJ_C_TYPE_PARAM`
* `PARM_VAR`
* `PRAGMA_COMMENT`
* `PRAGMA_DETECT_MISMATCH`
* `RECORD`
* `REDECLARABLE_TEMPLATE`
* `REQUIRES_EXPR_BODY`
* `STATIC_ASSERT`
* `TAG`
* `TEMPLATE`
* `TEMPLATE_PARAM_OBJECT`
* `TEMPLATE_TEMPLATE_PARM`
* `TEMPLATE_TYPE_PARM`
* `TRANSLATION_UNIT`
* `TYPE_ALIAS`
* `TYPE_ALIAS_TEMPLATE`
* `TYPE`
* `TYPEDEF`
* `TYPEDEF_NAME`
* `UNRESOLVED_USING_IF_EXISTS`
* `UNRESOLVED_USING_TYPENAME`
* `UNRESOLVED_USING_VALUE`
* `USING`
* `USING_DIRECTIVE`
* `USING_ENUM`
* `USING_PACK`
* `USING_SHADOW`
* `VALUE`
* `VAR`
* `VAR_TEMPLATE`
* `VAR_TEMPLATE_PARTIAL_SPECIALIZATION`
* `VAR_TEMPLATE_SPECIALIZATION`

</details>

<details><summary><a name="AArch64VectorPcsAttrSpelling"></a>AArch64VectorPcsAttrSpelling</summary>

Available enumerations:

* `GNU_AARCH64_VECTOR_PCS`
* `CXX11_CLANG_AARCH64_VECTOR_PCS`
* `C2_XCLANG_AARCH64_VECTOR_PCS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AMDGPUFlatWorkGroupSizeAttrSpelling"></a>AMDGPUFlatWorkGroupSizeAttrSpelling</summary>

Available enumerations:

* `GNU_AMDGPU_FLAT_WORK_GROUP_SIZE`
* `CXX11_CLANG_AMDGPU_FLAT_WORK_GROUP_SIZE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AMDGPUNumSGPRAttrSpelling"></a>AMDGPUNumSGPRAttrSpelling</summary>

Available enumerations:

* `GNU_AMDGPU_NUM_SGPR`
* `CXX11_CLANG_AMDGPU_NUM_SGPR`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AMDGPUNumVGPRAttrSpelling"></a>AMDGPUNumVGPRAttrSpelling</summary>

Available enumerations:

* `GNU_AMDGPU_NUM_VGPR`
* `CXX11_CLANG_AMDGPU_NUM_VGPR`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AMDGPUWavesPerEUAttrSpelling"></a>AMDGPUWavesPerEUAttrSpelling</summary>

Available enumerations:

* `GNU_AMDGPU_WAVES_PER_EU`
* `CXX11_CLANG_AMDGPU_WAVES_PER_EU`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ARMInterruptAttrInterruptType"></a>ARMInterruptAttrInterruptType</summary>

Available enumerations:

* `IRQ`
* `FIQ`
* `SWI`
* `ABORT`
* `UNDEF`
* `GENERIC`

</details>

<details><summary><a name="ARMInterruptAttrSpelling"></a>ARMInterruptAttrSpelling</summary>

Available enumerations:

* `GNU_INTERRUPT`
* `CXX11_GNU_INTERRUPT`
* `C2_XGNU_INTERRUPT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AVRInterruptAttrSpelling"></a>AVRInterruptAttrSpelling</summary>

Available enumerations:

* `GNU_INTERRUPT`
* `CXX11_GNU_INTERRUPT`
* `C2_XGNU_INTERRUPT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AVRSignalAttrSpelling"></a>AVRSignalAttrSpelling</summary>

Available enumerations:

* `GNU_SIGNAL`
* `CXX11_GNU_SIGNAL`
* `C2_XGNU_SIGNAL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AbiTagAttrSpelling"></a>AbiTagAttrSpelling</summary>

Available enumerations:

* `GNU_ABI_TAG`
* `CXX11_GNU_ABI_TAG`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AcquireCapabilityAttrSpelling"></a>AcquireCapabilityAttrSpelling</summary>

Available enumerations:

* `GNU_ACQUIRE_CAPABILITY`
* `CXX11_CLANG_ACQUIRE_CAPABILITY`
* `GNU_ACQUIRE_SHARED_CAPABILITY`
* `CXX11_CLANG_ACQUIRE_SHARED_CAPABILITY`
* `GNU_EXCLUSIVE_LOCK_FUNCTION`
* `GNU_SHARED_LOCK_FUNCTION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AcquireHandleAttrSpelling"></a>AcquireHandleAttrSpelling</summary>

Available enumerations:

* `GNU_ACQUIRE_HANDLE`
* `CXX11_CLANG_ACQUIRE_HANDLE`
* `C2_XCLANG_ACQUIRE_HANDLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AddressSpaceAttrSpelling"></a>AddressSpaceAttrSpelling</summary>

Available enumerations:

* `GNU_ADDRESS_SPACE`
* `CXX11_CLANG_ADDRESS_SPACE`
* `C2_XCLANG_ADDRESS_SPACE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AliasAttrSpelling"></a>AliasAttrSpelling</summary>

Available enumerations:

* `GNU_ALIAS`
* `CXX11_GNU_ALIAS`
* `C2_XGNU_ALIAS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AlignedAttrSpelling"></a>AlignedAttrSpelling</summary>

Available enumerations:

* `GNU_ALIGNED`
* `CXX11_GNU_ALIGNED`
* `C2_XGNU_ALIGNED`
* `DECLSPEC_ALIGN`
* `KEYWORD_ALIGNAS`
* `KEYWORD__ALIGNAS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AllocAlignAttrSpelling"></a>AllocAlignAttrSpelling</summary>

Available enumerations:

* `GNU_ALLOC_ALIGN`
* `CXX11_GNU_ALLOC_ALIGN`
* `C2_XGNU_ALLOC_ALIGN`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AllocSizeAttrSpelling"></a>AllocSizeAttrSpelling</summary>

Available enumerations:

* `GNU_ALLOC_SIZE`
* `CXX11_GNU_ALLOC_SIZE`
* `C2_XGNU_ALLOC_SIZE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AlwaysDestroyAttrSpelling"></a>AlwaysDestroyAttrSpelling</summary>

Available enumerations:

* `GNU_ALWAYS_DESTROY`
* `CXX11_CLANG_ALWAYS_DESTROY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AlwaysInlineAttrSpelling"></a>AlwaysInlineAttrSpelling</summary>

Available enumerations:

* `GNU_ALWAYS_INLINE`
* `CXX11_GNU_ALWAYS_INLINE`
* `C2_XGNU_ALWAYS_INLINE`
* `KEYWORD_FORCEINLINE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AnnotateAttrSpelling"></a>AnnotateAttrSpelling</summary>

Available enumerations:

* `GNU_ANNOTATE`
* `CXX11_CLANG_ANNOTATE`
* `C2_XCLANG_ANNOTATE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AnyX86InterruptAttrSpelling"></a>AnyX86InterruptAttrSpelling</summary>

Available enumerations:

* `GNU_INTERRUPT`
* `CXX11_GNU_INTERRUPT`
* `C2_XGNU_INTERRUPT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AnyX86NoCallerSavedRegistersAttrSpelling"></a>AnyX86NoCallerSavedRegistersAttrSpelling</summary>

Available enumerations:

* `GNU_NO_CALLER_SAVED_REGISTERS`
* `CXX11_GNU_NO_CALLER_SAVED_REGISTERS`
* `C2_XGNU_NO_CALLER_SAVED_REGISTERS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AnyX86NoCfCheckAttrSpelling"></a>AnyX86NoCfCheckAttrSpelling</summary>

Available enumerations:

* `GNU_NOCF_CHECK`
* `CXX11_GNU_NOCF_CHECK`
* `C2_XGNU_NOCF_CHECK`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ArcWeakrefUnavailableAttrSpelling"></a>ArcWeakrefUnavailableAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE`
* `CXX11_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE`
* `C2_XCLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ArgumentWithTypeTagAttrSpelling"></a>ArgumentWithTypeTagAttrSpelling</summary>

Available enumerations:

* `GNU_ARGUMENT_WITH_TYPE_TAG`
* `CXX11_CLANG_ARGUMENT_WITH_TYPE_TAG`
* `C2_XCLANG_ARGUMENT_WITH_TYPE_TAG`
* `GNU_POINTER_WITH_TYPE_TAG`
* `CXX11_CLANG_POINTER_WITH_TYPE_TAG`
* `C2_XCLANG_POINTER_WITH_TYPE_TAG`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ArmBuiltinAliasAttrSpelling"></a>ArmBuiltinAliasAttrSpelling</summary>

Available enumerations:

* `GNU_CLANG_ARM_BUILTIN_ALIAS`
* `CXX11_CLANG_CLANG_ARM_BUILTIN_ALIAS`
* `C2_XCLANG_CLANG_ARM_BUILTIN_ALIAS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ArmMveStrictPolymorphismAttrSpelling"></a>ArmMveStrictPolymorphismAttrSpelling</summary>

Available enumerations:

* `GNU_CLANG_ARM_MVE_STRICT_POLYMORPHISM`
* `CXX11_CLANG_CLANG_ARM_MVE_STRICT_POLYMORPHISM`
* `C2_XCLANG_CLANG_ARM_MVE_STRICT_POLYMORPHISM`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ArrayTypeArraySizeModifier"></a>ArrayTypeArraySizeModifier</summary>

Available enumerations:

* `NORMAL`
* `STATIC`
* `STAR`

</details>

<details><summary><a name="ArtificialAttrSpelling"></a>ArtificialAttrSpelling</summary>

Available enumerations:

* `GNU_ARTIFICIAL`
* `CXX11_GNU_ARTIFICIAL`
* `C2_XGNU_ARTIFICIAL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AsmLabelAttrSpelling"></a>AsmLabelAttrSpelling</summary>

Available enumerations:

* `KEYWORD_ASSEMBLY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AssertCapabilityAttrSpelling"></a>AssertCapabilityAttrSpelling</summary>

Available enumerations:

* `GNU_ASSERT_CAPABILITY`
* `CXX11_CLANG_ASSERT_CAPABILITY`
* `GNU_ASSERT_SHARED_CAPABILITY`
* `CXX11_CLANG_ASSERT_SHARED_CAPABILITY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AssumeAlignedAttrSpelling"></a>AssumeAlignedAttrSpelling</summary>

Available enumerations:

* `GNU_ASSUME_ALIGNED`
* `CXX11_GNU_ASSUME_ALIGNED`
* `C2_XGNU_ASSUME_ALIGNED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AssumptionAttrSpelling"></a>AssumptionAttrSpelling</summary>

Available enumerations:

* `GNU_ASSUME`
* `CXX11_CLANG_ASSUME`
* `C2_XCLANG_ASSUME`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="AtomicExprAtomicOp"></a>AtomicExprAtomicOp</summary>

Available enumerations:

* `C11_ATOMIC_INITIALIZER`
* `C11_ATOMIC_LOAD`
* `C11_ATOMIC_STORE`
* `C11_ATOMIC_EXCHANGE`
* `C11_ATOMIC_COMPARE_EXCHANGE_STRONG`
* `C11_ATOMIC_COMPARE_EXCHANGE_WEAK`
* `C11_ATOMIC_FETCH_ADD`
* `C11_ATOMIC_FETCH_SUB`
* `C11_ATOMIC_FETCH_AND`
* `C11_ATOMIC_FETCH_OR`
* `C11_ATOMIC_FETCH_XOR`
* `C11_ATOMIC_FETCH_NAND`
* `C11_ATOMIC_FETCH_MAX`
* `C11_ATOMIC_FETCH_MIN`
* `ATOMIC_LOAD`
* `ATOMIC_LOAD_N`
* `ATOMIC_STORE`
* `ATOMIC_STORE_N`
* `ATOMIC_EXCHANGE`
* `ATOMIC_EXCHANGE_N`
* `ATOMIC_COMPARE_EXCHANGE`
* `ATOMIC_COMPARE_EXCHANGE_N`
* `ATOMIC_FETCH_ADD`
* `ATOMIC_FETCH_SUB`
* `ATOMIC_FETCH_AND`
* `ATOMIC_FETCH_OR`
* `ATOMIC_FETCH_XOR`
* `ATOMIC_FETCH_NAND`
* `ATOMIC_ADD_FETCH`
* `ATOMIC_SUB_FETCH`
* `ATOMIC_AND_FETCH`
* `ATOMIC_OR_FETCH`
* `ATOMIC_XOR_FETCH`
* `ATOMIC_MAX_FETCH`
* `ATOMIC_MIN_FETCH`
* `ATOMIC_NAND_FETCH`
* `OPENCL_ATOMIC_INITIALIZER`
* `OPENCL_ATOMIC_LOAD`
* `OPENCL_ATOMIC_STORE`
* `OPENCL_ATOMIC_EXCHANGE`
* `OPENCL_ATOMIC_COMPARE_EXCHANGE_STRONG`
* `OPENCL_ATOMIC_COMPARE_EXCHANGE_WEAK`
* `OPENCL_ATOMIC_FETCH_ADD`
* `OPENCL_ATOMIC_FETCH_SUB`
* `OPENCL_ATOMIC_FETCH_AND`
* `OPENCL_ATOMIC_FETCH_OR`
* `OPENCL_ATOMIC_FETCH_XOR`
* `OPENCL_ATOMIC_FETCH_MIN`
* `OPENCL_ATOMIC_FETCH_MAX`
* `ATOMIC_FETCH_MIN`
* `ATOMIC_FETCH_MAX`
* `HIP_ATOMIC_LOAD`
* `HIP_ATOMIC_STORE`
* `HIP_ATOMIC_COMPARE_EXCHANGE_WEAK`
* `HIP_ATOMIC_COMPARE_EXCHANGE_STRONG`
* `HIP_ATOMIC_EXCHANGE`
* `HIP_ATOMIC_FETCH_ADD`
* `HIP_ATOMIC_FETCH_AND`
* `HIP_ATOMIC_FETCH_OR`
* `HIP_ATOMIC_FETCH_XOR`
* `HIP_ATOMIC_FETCH_MIN`
* `HIP_ATOMIC_FETCH_MAX`

</details>

<details><summary><a name="AvailabilityAttrSpelling"></a>AvailabilityAttrSpelling</summary>

Available enumerations:

* `GNU_AVAILABILITY`
* `CXX11_CLANG_AVAILABILITY`
* `C2_XCLANG_AVAILABILITY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="BPFPreserveAccessIndexAttrSpelling"></a>BPFPreserveAccessIndexAttrSpelling</summary>

Available enumerations:

* `GNU_PRESERVE_ACCESS_INDEX`
* `CXX11_CLANG_PRESERVE_ACCESS_INDEX`
* `C2_XCLANG_PRESERVE_ACCESS_INDEX`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="BTFDeclTagAttrSpelling"></a>BTFDeclTagAttrSpelling</summary>

Available enumerations:

* `GNU_BTF_DECLARATION_TAG`
* `CXX11_CLANG_BTF_DECLARATION_TAG`
* `C2_XCLANG_BTF_DECLARATION_TAG`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="BTFTypeTagAttrSpelling"></a>BTFTypeTagAttrSpelling</summary>

Available enumerations:

* `GNU_BTF_TYPE_TAG`
* `CXX11_CLANG_BTF_TYPE_TAG`
* `C2_XCLANG_BTF_TYPE_TAG`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="BlocksAttrBlockType"></a>BlocksAttrBlockType</summary>

Available enumerations:

* `BY_REFERENCE`

</details>

<details><summary><a name="BlocksAttrSpelling"></a>BlocksAttrSpelling</summary>

Available enumerations:

* `GNU_BLOCKS`
* `CXX11_CLANG_BLOCKS`
* `C2_XCLANG_BLOCKS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="BuiltinAliasAttrSpelling"></a>BuiltinAliasAttrSpelling</summary>

Available enumerations:

* `CXX11_CLANG_BUILTIN_ALIAS`
* `C2_XCLANG_BUILTIN_ALIAS`
* `GNU_CLANG_BUILTIN_ALIAS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="BuiltinTypeKind"></a>BuiltinTypeKind</summary>

Available enumerations:

* `OCL_IMAGE1_DRO`
* `OCL_IMAGE1_DARRAY_RO`
* `OCL_IMAGE1_DBUFFER_RO`
* `OCL_IMAGE2_DRO`
* `OCL_IMAGE2_DARRAY_RO`
* `OCL_IMAGE2_DDEPTH_RO`
* `OCL_IMAGE2_DARRAY_DEPTH_RO`
* `OCL_IMAGE2_DMSAARO`
* `OCL_IMAGE2_DARRAY_MSAARO`
* `OCL_IMAGE2_DMSAA_DEPTH_RO`
* `OCL_IMAGE2_DARRAY_MSAA_DEPTH_RO`
* `OCL_IMAGE3_DRO`
* `OCL_IMAGE1_DWO`
* `OCL_IMAGE1_DARRAY_WO`
* `OCL_IMAGE1_DBUFFER_WO`
* `OCL_IMAGE2_DWO`
* `OCL_IMAGE2_DARRAY_WO`
* `OCL_IMAGE2_DDEPTH_WO`
* `OCL_IMAGE2_DARRAY_DEPTH_WO`
* `OCL_IMAGE2_DMSAAWO`
* `OCL_IMAGE2_DARRAY_MSAAWO`
* `OCL_IMAGE2_DMSAA_DEPTH_WO`
* `OCL_IMAGE2_DARRAY_MSAA_DEPTH_WO`
* `OCL_IMAGE3_DWO`
* `OCL_IMAGE1_DRW`
* `OCL_IMAGE1_DARRAY_RW`
* `OCL_IMAGE1_DBUFFER_RW`
* `OCL_IMAGE2_DRW`
* `OCL_IMAGE2_DARRAY_RW`
* `OCL_IMAGE2_DDEPTH_RW`
* `OCL_IMAGE2_DARRAY_DEPTH_RW`
* `OCL_IMAGE2_DMSAARW`
* `OCL_IMAGE2_DARRAY_MSAARW`
* `OCL_IMAGE2_DMSAA_DEPTH_RW`
* `OCL_IMAGE2_DARRAY_MSAA_DEPTH_RW`
* `OCL_IMAGE3_DRW`
* `OCL_INTEL_SUBGROUP_AVC_MCE_PAYLOAD`
* `OCL_INTEL_SUBGROUP_AVC_IME_PAYLOAD`
* `OCL_INTEL_SUBGROUP_AVC_REF_PAYLOAD`
* `OCL_INTEL_SUBGROUP_AVC_SIC_PAYLOAD`
* `OCL_INTEL_SUBGROUP_AVC_MCE_RESULT`
* `OCL_INTEL_SUBGROUP_AVC_IME_RESULT`
* `OCL_INTEL_SUBGROUP_AVC_REF_RESULT`
* `OCL_INTEL_SUBGROUP_AVC_SIC_RESULT`
* `OCL_INTEL_SUBGROUP_AVC_IME_RESULT_SINGLE_REFERENCE_STREAMOUT`
* `OCL_INTEL_SUBGROUP_AVC_IME_RESULT_DUAL_REFERENCE_STREAMOUT`
* `OCL_INTEL_SUBGROUP_AVC_IME_SINGLE_REFERENCE_STREAMIN`
* `OCL_INTEL_SUBGROUP_AVC_IME_DUAL_REFERENCE_STREAMIN`
* `SVE_INT8`
* `SVE_INT16`
* `SVE_INT32`
* `SVE_INT64`
* `SVE_UINT8`
* `SVE_UINT16`
* `SVE_UINT32`
* `SVE_UINT64`
* `SVE_FLOAT16`
* `SVE_FLOAT32`
* `SVE_FLOAT64`
* `SVE_B_FLOAT16`
* `SVE_INT8_X2`
* `SVE_INT16_X2`
* `SVE_INT32_X2`
* `SVE_INT64_X2`
* `SVE_UINT8_X2`
* `SVE_UINT16_X2`
* `SVE_UINT32_X2`
* `SVE_UINT64_X2`
* `SVE_FLOAT16_X2`
* `SVE_FLOAT32_X2`
* `SVE_FLOAT64_X2`
* `SVE_B_FLOAT16_X2`
* `SVE_INT8_X3`
* `SVE_INT16_X3`
* `SVE_INT32_X3`
* `SVE_INT64_X3`
* `SVE_UINT8_X3`
* `SVE_UINT16_X3`
* `SVE_UINT32_X3`
* `SVE_UINT64_X3`
* `SVE_FLOAT16_X3`
* `SVE_FLOAT32_X3`
* `SVE_FLOAT64_X3`
* `SVE_B_FLOAT16_X3`
* `SVE_INT8_X4`
* `SVE_INT16_X4`
* `SVE_INT32_X4`
* `SVE_INT64_X4`
* `SVE_UINT8_X4`
* `SVE_UINT16_X4`
* `SVE_UINT32_X4`
* `SVE_UINT64_X4`
* `SVE_FLOAT16_X4`
* `SVE_FLOAT32_X4`
* `SVE_FLOAT64_X4`
* `SVE_B_FLOAT16_X4`
* `SVE_BOOLEAN`
* `VECTOR_QUAD`
* `VECTOR_PAIR`
* `RVV_INT8_MF8`
* `RVV_INT8_MF4`
* `RVV_INT8_MF2`
* `RVV_INT8_M1`
* `RVV_INT8_M2`
* `RVV_INT8_M4`
* `RVV_INT8_M8`
* `RVV_UINT8_MF8`
* `RVV_UINT8_MF4`
* `RVV_UINT8_MF2`
* `RVV_UINT8_M1`
* `RVV_UINT8_M2`
* `RVV_UINT8_M4`
* `RVV_UINT8_M8`
* `RVV_INT16_MF4`
* `RVV_INT16_MF2`
* `RVV_INT16_M1`
* `RVV_INT16_M2`
* `RVV_INT16_M4`
* `RVV_INT16_M8`
* `RVV_UINT16_MF4`
* `RVV_UINT16_MF2`
* `RVV_UINT16_M1`
* `RVV_UINT16_M2`
* `RVV_UINT16_M4`
* `RVV_UINT16_M8`
* `RVV_INT32_MF2`
* `RVV_INT32_M1`
* `RVV_INT32_M2`
* `RVV_INT32_M4`
* `RVV_INT32_M8`
* `RVV_UINT32_MF2`
* `RVV_UINT32_M1`
* `RVV_UINT32_M2`
* `RVV_UINT32_M4`
* `RVV_UINT32_M8`
* `RVV_INT64_M1`
* `RVV_INT64_M2`
* `RVV_INT64_M4`
* `RVV_INT64_M8`
* `RVV_UINT64_M1`
* `RVV_UINT64_M2`
* `RVV_UINT64_M4`
* `RVV_UINT64_M8`
* `RVV_FLOAT16_MF4`
* `RVV_FLOAT16_MF2`
* `RVV_FLOAT16_M1`
* `RVV_FLOAT16_M2`
* `RVV_FLOAT16_M4`
* `RVV_FLOAT16_M8`
* `RVV_FLOAT32_MF2`
* `RVV_FLOAT32_M1`
* `RVV_FLOAT32_M2`
* `RVV_FLOAT32_M4`
* `RVV_FLOAT32_M8`
* `RVV_FLOAT64_M1`
* `RVV_FLOAT64_M2`
* `RVV_FLOAT64_M4`
* `RVV_FLOAT64_M8`
* `RVV_BOOL1`
* `RVV_BOOL2`
* `RVV_BOOL4`
* `RVV_BOOL8`
* `RVV_BOOL16`
* `RVV_BOOL32`
* `RVV_BOOL64`
* `VOID`
* `BOOLEAN`
* `CHARACTER_U`
* `U_CHAR`
* `W_CHAR_U`
* `CHAR8`
* `CHAR16`
* `CHAR32`
* `U_SHORT`
* `U_INT`
* `U_LONG`
* `U_LONG_LONG`
* `U_INT128`
* `CHARACTER_S`
* `S_CHAR`
* `W_CHAR_S`
* `SHORT`
* `INT`
* `LONG`
* `LONG_LONG`
* `INT128`
* `SHORT_ACCUM`
* `ACCUM`
* `LONG_ACCUM`
* `U_SHORT_ACCUM`
* `U_ACCUM`
* `U_LONG_ACCUM`
* `SHORT_FRACT`
* `FRACT`
* `LONG_FRACT`
* `U_SHORT_FRACT`
* `U_FRACT`
* `U_LONG_FRACT`
* `SAT_SHORT_ACCUM`
* `SAT_ACCUM`
* `SAT_LONG_ACCUM`
* `SAT_U_SHORT_ACCUM`
* `SAT_U_ACCUM`
* `SAT_U_LONG_ACCUM`
* `SAT_SHORT_FRACT`
* `SAT_FRACT`
* `SAT_LONG_FRACT`
* `SAT_U_SHORT_FRACT`
* `SAT_U_FRACT`
* `SAT_U_LONG_FRACT`
* `HALF`
* `FLOAT`
* `DOUBLE`
* `LONG_DOUBLE`
* `FLOAT16`
* `B_FLOAT16`
* `FLOAT128`
* `IBM128`
* `NULL_POINTER`
* `OBJ_C_ID`
* `OBJ_C_CLASS`
* `OBJ_C_SEL`
* `OCL_SAMPLER`
* `OCL_EVENT`
* `OCL_CLK_EVENT`
* `OCL_QUEUE`
* `OCL_RESERVE_ID`
* `DEPENDENT`
* `OVERLOAD`
* `BOUND_MEMBER`
* `PSEUDO_OBJECT`
* `UNKNOWN_ANY`
* `BUILTIN_FN`
* `ARC_UNBRIDGED_CAST`
* `INCOMPLETE_MATRIX_INDEX`
* `OMP_ARRAY_SECTION`
* `OMP_ARRAY_SHAPING`
* `OMP_ITERATOR`

</details>

<details><summary><a name="CDeclAttrSpelling"></a>CDeclAttrSpelling</summary>

Available enumerations:

* `GNU_CDECL`
* `CXX11_GNU_CDECL`
* `C2_XGNU_CDECL`
* `KEYWORD_CDECL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CFAuditedTransferAttrSpelling"></a>CFAuditedTransferAttrSpelling</summary>

Available enumerations:

* `GNU_CF_AUDITED_TRANSFER`
* `CXX11_CLANG_CF_AUDITED_TRANSFER`
* `C2_XCLANG_CF_AUDITED_TRANSFER`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CFConsumedAttrSpelling"></a>CFConsumedAttrSpelling</summary>

Available enumerations:

* `GNU_CF_CONSUMED`
* `CXX11_CLANG_CF_CONSUMED`
* `C2_XCLANG_CF_CONSUMED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CFGuardAttrGuardArg"></a>CFGuardAttrGuardArg</summary>

Available enumerations:

* `NOCF`

</details>

<details><summary><a name="CFICanonicalJumpTableAttrSpelling"></a>CFICanonicalJumpTableAttrSpelling</summary>

Available enumerations:

* `GNU_CFI_CANONICAL_JUMP_TABLE`
* `CXX11_CLANG_CFI_CANONICAL_JUMP_TABLE`
* `C2_XCLANG_CFI_CANONICAL_JUMP_TABLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CFReturnsNotRetainedAttrSpelling"></a>CFReturnsNotRetainedAttrSpelling</summary>

Available enumerations:

* `GNU_CF_RETURNS_NOT_RETAINED`
* `CXX11_CLANG_CF_RETURNS_NOT_RETAINED`
* `C2_XCLANG_CF_RETURNS_NOT_RETAINED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CFReturnsRetainedAttrSpelling"></a>CFReturnsRetainedAttrSpelling</summary>

Available enumerations:

* `GNU_CF_RETURNS_RETAINED`
* `CXX11_CLANG_CF_RETURNS_RETAINED`
* `C2_XCLANG_CF_RETURNS_RETAINED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CFUnknownTransferAttrSpelling"></a>CFUnknownTransferAttrSpelling</summary>

Available enumerations:

* `GNU_CF_UNKNOWN_TRANSFER`
* `CXX11_CLANG_CF_UNKNOWN_TRANSFER`
* `C2_XCLANG_CF_UNKNOWN_TRANSFER`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CPUDispatchAttrSpelling"></a>CPUDispatchAttrSpelling</summary>

Available enumerations:

* `GNU_CPU_DISPATCH`
* `CXX11_CLANG_CPU_DISPATCH`
* `C2_XCLANG_CPU_DISPATCH`
* `DECLSPEC_CPU_DISPATCH`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CPUSpecificAttrSpelling"></a>CPUSpecificAttrSpelling</summary>

Available enumerations:

* `GNU_CPU_SPECIFIC`
* `CXX11_CLANG_CPU_SPECIFIC`
* `C2_XCLANG_CPU_SPECIFIC`
* `DECLSPEC_CPU_SPECIFIC`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CUDAConstantAttrSpelling"></a>CUDAConstantAttrSpelling</summary>

Available enumerations:

* `GNU_CONSTANT`
* `DECLSPEC_CONSTANT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CUDADeviceAttrSpelling"></a>CUDADeviceAttrSpelling</summary>

Available enumerations:

* `GNU_DEVICE`
* `DECLSPEC_DEVICE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CUDADeviceBuiltinSurfaceTypeAttrSpelling"></a>CUDADeviceBuiltinSurfaceTypeAttrSpelling</summary>

Available enumerations:

* `GNU_DEVICE_BUILTIN_SURFACE_TYPE`
* `DECLSPEC_DEVICE_BUILTIN_SURFACE_TYPE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CUDADeviceBuiltinTextureTypeAttrSpelling"></a>CUDADeviceBuiltinTextureTypeAttrSpelling</summary>

Available enumerations:

* `GNU_DEVICE_BUILTIN_TEXTURE_TYPE`
* `DECLSPEC_DEVICE_BUILTIN_TEXTURE_TYPE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CUDAGlobalAttrSpelling"></a>CUDAGlobalAttrSpelling</summary>

Available enumerations:

* `GNU_GLOBAL`
* `DECLSPEC_GLOBAL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CUDAHostAttrSpelling"></a>CUDAHostAttrSpelling</summary>

Available enumerations:

* `GNU_HOST`
* `DECLSPEC_HOST`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CUDALaunchBoundsAttrSpelling"></a>CUDALaunchBoundsAttrSpelling</summary>

Available enumerations:

* `GNU_LAUNCH_BOUNDS`
* `DECLSPEC_LAUNCH_BOUNDS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CUDASharedAttrSpelling"></a>CUDASharedAttrSpelling</summary>

Available enumerations:

* `GNU_SHARED`
* `DECLSPEC_SHARED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CXXConstructExprConstructionKind"></a>CXXConstructExprConstructionKind</summary>

Available enumerations:

* `COMPLETE`
* `NON_VIRTUAL_BASE`
* `VIRTUAL_BASE`
* `DELEGATING`

</details>

<details><summary><a name="CXXNewExprInitializationStyle"></a>CXXNewExprInitializationStyle</summary>

Available enumerations:

* `NO_INITIALIZER`
* `CALL_INITIALIZER`
* `LIST_INITIALIZER`

</details>

<details><summary><a name="CallExprADLCallKind"></a>CallExprADLCallKind</summary>

Available enumerations:

* `NOT_ADL`
* `USES_ADL`

</details>

<details><summary><a name="CallableWhenAttrConsumedState"></a>CallableWhenAttrConsumedState</summary>

Available enumerations:

* `UNKNOWN`
* `CONSUMED`
* `UNCONSUMED`

</details>

<details><summary><a name="CallableWhenAttrSpelling"></a>CallableWhenAttrSpelling</summary>

Available enumerations:

* `GNU_CALLABLE_WHEN`
* `CXX11_CLANG_CALLABLE_WHEN`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CallbackAttrSpelling"></a>CallbackAttrSpelling</summary>

Available enumerations:

* `GNU_CALLBACK`
* `CXX11_CLANG_CALLBACK`
* `C2_XCLANG_CALLBACK`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CalledOnceAttrSpelling"></a>CalledOnceAttrSpelling</summary>

Available enumerations:

* `GNU_CALLED_ONCE`
* `CXX11_CLANG_CALLED_ONCE`
* `C2_XCLANG_CALLED_ONCE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CapabilityAttrSpelling"></a>CapabilityAttrSpelling</summary>

Available enumerations:

* `GNU_CAPABILITY`
* `CXX11_CLANG_CAPABILITY`
* `GNU_SHARED_CAPABILITY`
* `CXX11_CLANG_SHARED_CAPABILITY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CapturedStmtVariableCaptureKind"></a>CapturedStmtVariableCaptureKind</summary>

Available enumerations:

* `THIS`
* `BY_REFERENCE`
* `BY_COPY`
* `VLA_TYPE`

</details>

<details><summary><a name="CarriesDependencyAttrSpelling"></a>CarriesDependencyAttrSpelling</summary>

Available enumerations:

* `GNU_CARRIES_DEPENDENCY`
* `CXX11_CARRIES_DEPENDENCY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CharacterLiteralCharacterKind"></a>CharacterLiteralCharacterKind</summary>

Available enumerations:

* `ASCII`
* `WIDE`
* `UTF8`
* `UTF16`
* `UTF32`

</details>

<details><summary><a name="CleanupAttrSpelling"></a>CleanupAttrSpelling</summary>

Available enumerations:

* `GNU_CLEANUP`
* `CXX11_GNU_CLEANUP`
* `C2_XGNU_CLEANUP`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ColdAttrSpelling"></a>ColdAttrSpelling</summary>

Available enumerations:

* `GNU_COLD`
* `CXX11_GNU_COLD`
* `C2_XGNU_COLD`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="CommonAttrSpelling"></a>CommonAttrSpelling</summary>

Available enumerations:

* `GNU_COMMON`
* `CXX11_GNU_COMMON`
* `C2_XGNU_COMMON`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ConstAttrSpelling"></a>ConstAttrSpelling</summary>

Available enumerations:

* `GNU_CONST`
* `CXX11_GNU_CONST`
* `C2_XGNU_CONST`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ConstInitAttrSpelling"></a>ConstInitAttrSpelling</summary>

Available enumerations:

* `KEYWORD_CONSTINIT`
* `GNU_REQUIRE_CONSTANT_INITIALIZATION`
* `CXX11_CLANG_REQUIRE_CONSTANT_INITIALIZATION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ConstantExprResultStorageKind"></a>ConstantExprResultStorageKind</summary>

Available enumerations:

* `NONE`
* `INT64`
* `AP_VALUE`

</details>

<details><summary><a name="ConstructorAttrSpelling"></a>ConstructorAttrSpelling</summary>

Available enumerations:

* `GNU_CONSTRUCTOR`
* `CXX11_GNU_CONSTRUCTOR`
* `C2_XGNU_CONSTRUCTOR`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ConsumableAttrConsumedState"></a>ConsumableAttrConsumedState</summary>

Available enumerations:

* `UNKNOWN`
* `CONSUMED`
* `UNCONSUMED`

</details>

<details><summary><a name="ConsumableAttrSpelling"></a>ConsumableAttrSpelling</summary>

Available enumerations:

* `GNU_CONSUMABLE`
* `CXX11_CLANG_CONSUMABLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ConsumableAutoCastAttrSpelling"></a>ConsumableAutoCastAttrSpelling</summary>

Available enumerations:

* `GNU_CONSUMABLE_AUTO_CAST_STATE`
* `CXX11_CLANG_CONSUMABLE_AUTO_CAST_STATE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ConsumableSetOnReadAttrSpelling"></a>ConsumableSetOnReadAttrSpelling</summary>

Available enumerations:

* `GNU_CONSUMABLE_STATE_ON_READ`
* `CXX11_CLANG_CONSUMABLE_STATE_ON_READ`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ConvergentAttrSpelling"></a>ConvergentAttrSpelling</summary>

Available enumerations:

* `GNU_CONVERGENT`
* `CXX11_CLANG_CONVERGENT`
* `C2_XCLANG_CONVERGENT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="DLLExportAttrSpelling"></a>DLLExportAttrSpelling</summary>

Available enumerations:

* `DECLSPEC_DLLEXPORT`
* `GNU_DLLEXPORT`
* `CXX11_GNU_DLLEXPORT`
* `C2_XGNU_DLLEXPORT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="DLLImportAttrSpelling"></a>DLLImportAttrSpelling</summary>

Available enumerations:

* `DECLSPEC_DLLIMPORT`
* `GNU_DLLIMPORT`
* `CXX11_GNU_DLLIMPORT`
* `C2_XGNU_DLLIMPORT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="DeclFriendObjectKind"></a>DeclFriendObjectKind</summary>

Available enumerations:

* `NONE`
* `DECLARED`
* `UNDECLARED`

</details>

<details><summary><a name="DeclIdentifierNamespace"></a>DeclIdentifierNamespace</summary>

Available enumerations:

* `LABEL`
* `TAG`
* `TYPE`
* `MEMBER`
* `NAMESPACE`
* `ORDINARY`
* `OBJ_C_PROTOCOL`
* `ORDINARY_FRIEND`
* `TAG_FRIEND`
* `USING`
* `NON_MEMBER_OPERATOR`
* `LOCAL_EXTERN`
* `OMP_REDUCTION`
* `OMP_MAPPER`

</details>

<details><summary><a name="DeclModuleOwnershipKind"></a>DeclModuleOwnershipKind</summary>

Available enumerations:

* `UNOWNED`
* `VISIBLE`
* `VISIBLE_WHEN_IMPORTED`
* `MODULE_PRIVATE`

</details>

<details><summary><a name="DeclObjCDeclQualifier"></a>DeclObjCDeclQualifier</summary>

Available enumerations:

* `NONE`
* `IN`
* `INOUT`
* `OUT`
* `BYCOPY`
* `BYREF`
* `ONEWAY`
* `CS_NULLABILITY`

</details>

<details><summary><a name="DeprecatedAttrSpelling"></a>DeprecatedAttrSpelling</summary>

Available enumerations:

* `GNU_DEPRECATED`
* `CXX11_GNU_DEPRECATED`
* `C2_XGNU_DEPRECATED`
* `DECLSPEC_DEPRECATED`
* `CXX11_DEPRECATED`
* `C2_XDEPRECATED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="DestructorAttrSpelling"></a>DestructorAttrSpelling</summary>

Available enumerations:

* `GNU_DESTRUCTOR`
* `CXX11_GNU_DESTRUCTOR`
* `C2_XGNU_DESTRUCTOR`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="DiagnoseAsBuiltinAttrSpelling"></a>DiagnoseAsBuiltinAttrSpelling</summary>

Available enumerations:

* `GNU_DIAGNOSE_AS_BUILTIN`
* `CXX11_CLANG_DIAGNOSE_AS_BUILTIN`
* `C2_XCLANG_DIAGNOSE_AS_BUILTIN`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="DiagnoseIfAttrDiagnosticType"></a>DiagnoseIfAttrDiagnosticType</summary>

Available enumerations:

* `ERROR`
* `WARNING`

</details>

<details><summary><a name="DisableSanitizerInstrumentationAttrSpelling"></a>DisableSanitizerInstrumentationAttrSpelling</summary>

Available enumerations:

* `GNU_DISABLE_SANITIZER_INSTRUMENTATION`
* `CXX11_CLANG_DISABLE_SANITIZER_INSTRUMENTATION`
* `C2_XCLANG_DISABLE_SANITIZER_INSTRUMENTATION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="DisableTailCallsAttrSpelling"></a>DisableTailCallsAttrSpelling</summary>

Available enumerations:

* `GNU_DISABLE_TAIL_CALLS`
* `CXX11_CLANG_DISABLE_TAIL_CALLS`
* `C2_XCLANG_DISABLE_TAIL_CALLS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="EnforceTCBAttrSpelling"></a>EnforceTCBAttrSpelling</summary>

Available enumerations:

* `GNU_ENFORCE_TCB`
* `CXX11_CLANG_ENFORCE_TCB`
* `C2_XCLANG_ENFORCE_TCB`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="EnforceTCBLeafAttrSpelling"></a>EnforceTCBLeafAttrSpelling</summary>

Available enumerations:

* `GNU_ENFORCE_TCB_LEAF`
* `CXX11_CLANG_ENFORCE_TCB_LEAF`
* `C2_XCLANG_ENFORCE_TCB_LEAF`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="EnumExtensibilityAttrKind"></a>EnumExtensibilityAttrKind</summary>

Available enumerations:

* `CLOSED`
* `OPEN`

</details>

<details><summary><a name="EnumExtensibilityAttrSpelling"></a>EnumExtensibilityAttrSpelling</summary>

Available enumerations:

* `GNU_ENUM_EXTENSIBILITY`
* `CXX11_CLANG_ENUM_EXTENSIBILITY`
* `C2_XCLANG_ENUM_EXTENSIBILITY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ErrorAttrSpelling"></a>ErrorAttrSpelling</summary>

Available enumerations:

* `GNU_ERROR`
* `CXX11_GNU_ERROR`
* `C2_XGNU_ERROR`
* `GNU_WARNING`
* `CXX11_GNU_WARNING`
* `C2_XGNU_WARNING`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ExcludeFromExplicitInstantiationAttrSpelling"></a>ExcludeFromExplicitInstantiationAttrSpelling</summary>

Available enumerations:

* `GNU_EXCLUDE_FROM_EXPLICIT_INSTANTIATION`
* `CXX11_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION`
* `C2_XCLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ExprConstantExprKind"></a>ExprConstantExprKind</summary>

Available enumerations:

* `NORMAL`
* `NON_CLASS_TEMPLATE_ARGUMENT`
* `CLASS_TEMPLATE_ARGUMENT`
* `IMMEDIATE_INVOCATION`

</details>

<details><summary><a name="ExprLValueClassification"></a>ExprLValueClassification</summary>

Available enumerations:

* `VALID`
* `NOT_OBJECT_TYPE`
* `INCOMPLETE_VOID_TYPE`
* `DUPLICATE_VECTOR_COMPONENTS`
* `INVALID_EXPRESSION`
* `INVALID_MESSAGE_EXPRESSION`
* `MEMBER_FUNCTION`
* `SUB_OBJ_C_PROPERTY_SETTING`
* `CLASS_TEMPORARY`
* `ARRAY_TEMPORARY`

</details>

<details><summary><a name="ExprNullPointerConstantKind"></a>ExprNullPointerConstantKind</summary>

Available enumerations:

* `NOT_NULL`
* `ZERO_EXPRESSION`
* `ZERO_LITERAL`
* `CXX11_NULLPTR`
* `GNU_NULL`

</details>

<details><summary><a name="ExprNullPointerConstantValueDependence"></a>ExprNullPointerConstantValueDependence</summary>

Available enumerations:

* `NEVER_VALUE_DEPENDENT`
* `VALUE_DEPENDENT_IS_NULL`
* `VALUE_DEPENDENT_IS_NOT_NULL`

</details>

<details><summary><a name="ExprSideEffectsKind"></a>ExprSideEffectsKind</summary>

Available enumerations:

* `NO_SIDE_EFFECTS`
* `ALLOW_UNDEFINED_BEHAVIOR`
* `ALLOW_SIDE_EFFECTS`

</details>

<details><summary><a name="ExprisModifiableLvalueResult"></a>ExprisModifiableLvalueResult</summary>

Available enumerations:

* `VALID`
* `NOT_OBJECT_TYPE`
* `INCOMPLETE_VOID_TYPE`
* `DUPLICATE_VECTOR_COMPONENTS`
* `INVALID_EXPRESSION`
* `L_VALUE_CAST`
* `INCOMPLETE_TYPE`
* `CONST_QUALIFIED`
* `CONST_QUALIFIED_FIELD`
* `CONST_ADDR_SPACE`
* `ARRAY_TYPE`
* `NO_SETTER_PROPERTY`
* `MEMBER_FUNCTION`
* `SUB_OBJ_C_PROPERTY_SETTING`
* `INVALID_MESSAGE_EXPRESSION`
* `CLASS_TEMPORARY`
* `ARRAY_TEMPORARY`

</details>

<details><summary><a name="ExternalSourceSymbolAttrSpelling"></a>ExternalSourceSymbolAttrSpelling</summary>

Available enumerations:

* `GNU_EXTERNAL_SOURCE_SYMBOL`
* `CXX11_CLANG_EXTERNAL_SOURCE_SYMBOL`
* `C2_XCLANG_EXTERNAL_SOURCE_SYMBOL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="FallThroughAttrSpelling"></a>FallThroughAttrSpelling</summary>

Available enumerations:

* `CXX11_FALLTHROUGH`
* `C2_XFALLTHROUGH`
* `CXX11_CLANG_FALLTHROUGH`
* `GNU_FALLTHROUGH`
* `CXX11_GNU_FALLTHROUGH`
* `C2_XGNU_FALLTHROUGH`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="FastCallAttrSpelling"></a>FastCallAttrSpelling</summary>

Available enumerations:

* `GNU_FASTCALL`
* `CXX11_GNU_FASTCALL`
* `C2_XGNU_FASTCALL`
* `KEYWORD_FASTCALL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="FinalAttrSpelling"></a>FinalAttrSpelling</summary>

Available enumerations:

* `KEYWORD_FINAL`
* `KEYWORD_SEALED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="FlagEnumAttrSpelling"></a>FlagEnumAttrSpelling</summary>

Available enumerations:

* `GNU_FLAG_ENUM`
* `CXX11_CLANG_FLAG_ENUM`
* `C2_XCLANG_FLAG_ENUM`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="FlattenAttrSpelling"></a>FlattenAttrSpelling</summary>

Available enumerations:

* `GNU_FLATTEN`
* `CXX11_GNU_FLATTEN`
* `C2_XGNU_FLATTEN`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="FormatArgAttrSpelling"></a>FormatArgAttrSpelling</summary>

Available enumerations:

* `GNU_FORMAT_ARGUMENT`
* `CXX11_GNU_FORMAT_ARGUMENT`
* `C2_XGNU_FORMAT_ARGUMENT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="FormatAttrSpelling"></a>FormatAttrSpelling</summary>

Available enumerations:

* `GNU_FORMAT`
* `CXX11_GNU_FORMAT`
* `C2_XGNU_FORMAT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="FunctionDeclTemplatedKind"></a>FunctionDeclTemplatedKind</summary>

Available enumerations:

* `NON_TEMPLATE`
* `FUNCTION_TEMPLATE`
* `MEMBER_SPECIALIZATION`
* `FUNCTION_TEMPLATE_SPECIALIZATION`
* `DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION`

</details>

<details><summary><a name="GNUInlineAttrSpelling"></a>GNUInlineAttrSpelling</summary>

Available enumerations:

* `GNU_GNU_INLINE`
* `CXX11_GNU_GNU_INLINE`
* `C2_XGNU_GNU_INLINE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="GuardedVarAttrSpelling"></a>GuardedVarAttrSpelling</summary>

Available enumerations:

* `GNU_GUARDED_VARIABLE`
* `CXX11_CLANG_GUARDED_VARIABLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="HIPManagedAttrSpelling"></a>HIPManagedAttrSpelling</summary>

Available enumerations:

* `GNU_MANAGED`
* `DECLSPEC_MANAGED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="HotAttrSpelling"></a>HotAttrSpelling</summary>

Available enumerations:

* `GNU_HOT`
* `CXX11_GNU_HOT`
* `C2_XGNU_HOT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="IBActionAttrSpelling"></a>IBActionAttrSpelling</summary>

Available enumerations:

* `GNU_IBACTION`
* `CXX11_CLANG_IBACTION`
* `C2_XCLANG_IBACTION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="IBOutletAttrSpelling"></a>IBOutletAttrSpelling</summary>

Available enumerations:

* `GNU_IBOUTLET`
* `CXX11_CLANG_IBOUTLET`
* `C2_XCLANG_IBOUTLET`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="IBOutletCollectionAttrSpelling"></a>IBOutletCollectionAttrSpelling</summary>

Available enumerations:

* `GNU_IBOUTLETCOLLECTION`
* `CXX11_CLANG_IBOUTLETCOLLECTION`
* `C2_XCLANG_IBOUTLETCOLLECTION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="IFuncAttrSpelling"></a>IFuncAttrSpelling</summary>

Available enumerations:

* `GNU_IFUNC`
* `CXX11_GNU_IFUNC`
* `C2_XGNU_IFUNC`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ImplicitCastExprOnStack"></a>ImplicitCastExprOnStack</summary>

Available enumerations:

* `ON_STACK`

</details>

<details><summary><a name="ImplicitParamDeclImplicitParamKind"></a>ImplicitParamDeclImplicitParamKind</summary>

Available enumerations:

* `OBJ_C_SELF`
* `OBJ_C_CMD`
* `CXX_THIS`
* `CXXVTT`
* `CAPTURED_CONTEXT`
* `OTHER`

</details>

<details><summary><a name="InitPriorityAttrSpelling"></a>InitPriorityAttrSpelling</summary>

Available enumerations:

* `GNU_INITIALIZER_PRIORITY`
* `CXX11_GNU_INITIALIZER_PRIORITY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="IntelOclBiccAttrSpelling"></a>IntelOclBiccAttrSpelling</summary>

Available enumerations:

* `GNU_INTEL_OCL_BICC`
* `CXX11_CLANG_INTEL_OCL_BICC`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="InternalLinkageAttrSpelling"></a>InternalLinkageAttrSpelling</summary>

Available enumerations:

* `GNU_INTERNAL_LINKAGE`
* `CXX11_CLANG_INTERNAL_LINKAGE`
* `C2_XCLANG_INTERNAL_LINKAGE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="LTOVisibilityPublicAttrSpelling"></a>LTOVisibilityPublicAttrSpelling</summary>

Available enumerations:

* `GNU_LTO_VISIBILITY_PUBLIC`
* `CXX11_CLANG_LTO_VISIBILITY_PUBLIC`
* `C2_XCLANG_LTO_VISIBILITY_PUBLIC`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="LeafAttrSpelling"></a>LeafAttrSpelling</summary>

Available enumerations:

* `GNU_LEAF`
* `CXX11_GNU_LEAF`
* `C2_XGNU_LEAF`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="LifetimeBoundAttrSpelling"></a>LifetimeBoundAttrSpelling</summary>

Available enumerations:

* `GNU_LIFETIMEBOUND`
* `CXX11_CLANG_LIFETIMEBOUND`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="LikelyAttrSpelling"></a>LikelyAttrSpelling</summary>

Available enumerations:

* `CXX11_LIKELY`
* `C2_XCLANG_LIKELY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="LinkageSpecDeclLanguageIDs"></a>LinkageSpecDeclLanguageIDs</summary>

Available enumerations:

* `C`
* `CXX`

</details>

<details><summary><a name="LoaderUninitializedAttrSpelling"></a>LoaderUninitializedAttrSpelling</summary>

Available enumerations:

* `GNU_LOADER_UNINITIALIZED`
* `CXX11_CLANG_LOADER_UNINITIALIZED`
* `C2_XCLANG_LOADER_UNINITIALIZED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="LoopHintAttrLoopHintState"></a>LoopHintAttrLoopHintState</summary>

Available enumerations:

* `ENABLE`
* `DISABLE`
* `NUMERIC`
* `FIXED_WIDTH`
* `SCALABLE_WIDTH`
* `ASSUME_SAFETY`
* `FULL`

</details>

<details><summary><a name="LoopHintAttrOptionType"></a>LoopHintAttrOptionType</summary>

Available enumerations:

* `VECTORIZE`
* `VECTORIZE_WIDTH`
* `INTERLEAVE`
* `INTERLEAVE_COUNT`
* `UNROLL`
* `UNROLL_COUNT`
* `UNROLL_AND_JAM`
* `UNROLL_AND_JAM_COUNT`
* `PIPELINE_DISABLED`
* `PIPELINE_INITIATION_INTERVAL`
* `DISTRIBUTE`
* `VECTORIZE_PREDICATE`

</details>

<details><summary><a name="LoopHintAttrSpelling"></a>LoopHintAttrSpelling</summary>

Available enumerations:

* `PRAGMA_CLANG_LOOP`
* `PRAGMA_UNROLL`
* `PRAGMA_NOUNROLL`
* `PRAGMA_UNROLL_AND_JAM`
* `PRAGMA_NOUNROLL_AND_JAM`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MIGServerRoutineAttrSpelling"></a>MIGServerRoutineAttrSpelling</summary>

Available enumerations:

* `GNU_MIG_SERVER_ROUTINE`
* `CXX11_CLANG_MIG_SERVER_ROUTINE`
* `C2_XCLANG_MIG_SERVER_ROUTINE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MSABIAttrSpelling"></a>MSABIAttrSpelling</summary>

Available enumerations:

* `GNU_MS_ABI`
* `CXX11_GNU_MS_ABI`
* `C2_XGNU_MS_ABI`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MSInheritanceAttrSpelling"></a>MSInheritanceAttrSpelling</summary>

Available enumerations:

* `KEYWORD_SINGLE_INHERITANCE`
* `KEYWORD_MULTIPLE_INHERITANCE`
* `KEYWORD_VIRTUAL_INHERITANCE`
* `KEYWORD_UNSPECIFIED_INHERITANCE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MSP430InterruptAttrSpelling"></a>MSP430InterruptAttrSpelling</summary>

Available enumerations:

* `GNU_INTERRUPT`
* `CXX11_GNU_INTERRUPT`
* `C2_XGNU_INTERRUPT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MSStructAttrSpelling"></a>MSStructAttrSpelling</summary>

Available enumerations:

* `GNU_MS_STRUCT`
* `CXX11_GNU_MS_STRUCT`
* `C2_XGNU_MS_STRUCT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MayAliasAttrSpelling"></a>MayAliasAttrSpelling</summary>

Available enumerations:

* `GNU_MAY_ALIAS`
* `CXX11_GNU_MAY_ALIAS`
* `C2_XGNU_MAY_ALIAS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MicroMipsAttrSpelling"></a>MicroMipsAttrSpelling</summary>

Available enumerations:

* `GNU_MICROMIPS`
* `CXX11_GNU_MICROMIPS`
* `C2_XGNU_MICROMIPS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MinSizeAttrSpelling"></a>MinSizeAttrSpelling</summary>

Available enumerations:

* `GNU_MINSIZE`
* `CXX11_CLANG_MINSIZE`
* `C2_XCLANG_MINSIZE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MinVectorWidthAttrSpelling"></a>MinVectorWidthAttrSpelling</summary>

Available enumerations:

* `GNU_MIN_VECTOR_WIDTH`
* `CXX11_CLANG_MIN_VECTOR_WIDTH`
* `C2_XCLANG_MIN_VECTOR_WIDTH`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="Mips16AttrSpelling"></a>Mips16AttrSpelling</summary>

Available enumerations:

* `GNU_MIPS16`
* `CXX11_GNU_MIPS16`
* `C2_XGNU_MIPS16`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MipsInterruptAttrInterruptType"></a>MipsInterruptAttrInterruptType</summary>

Available enumerations:

* `SW0`
* `SW1`
* `HW0`
* `HW1`
* `HW2`
* `HW3`
* `HW4`
* `HW5`
* `EIC`

</details>

<details><summary><a name="MipsInterruptAttrSpelling"></a>MipsInterruptAttrSpelling</summary>

Available enumerations:

* `GNU_INTERRUPT`
* `CXX11_GNU_INTERRUPT`
* `C2_XGNU_INTERRUPT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MipsLongCallAttrSpelling"></a>MipsLongCallAttrSpelling</summary>

Available enumerations:

* `GNU_LONG_CALL`
* `CXX11_GNU_LONG_CALL`
* `C2_XGNU_LONG_CALL`
* `GNU_FAR`
* `CXX11_GNU_FAR`
* `C2_XGNU_FAR`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MipsShortCallAttrSpelling"></a>MipsShortCallAttrSpelling</summary>

Available enumerations:

* `GNU_SHORT_CALL`
* `CXX11_GNU_SHORT_CALL`
* `C2_XGNU_SHORT_CALL`
* `GNU_NEAR`
* `CXX11_GNU_NEAR`
* `C2_XGNU_NEAR`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ModeAttrSpelling"></a>ModeAttrSpelling</summary>

Available enumerations:

* `GNU_MODE`
* `CXX11_GNU_MODE`
* `C2_XGNU_MODE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="MustTailAttrSpelling"></a>MustTailAttrSpelling</summary>

Available enumerations:

* `GNU_MUSTTAIL`
* `CXX11_CLANG_MUSTTAIL`
* `C2_XCLANG_MUSTTAIL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NSConsumedAttrSpelling"></a>NSConsumedAttrSpelling</summary>

Available enumerations:

* `GNU_NS_CONSUMED`
* `CXX11_CLANG_NS_CONSUMED`
* `C2_XCLANG_NS_CONSUMED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NSConsumesSelfAttrSpelling"></a>NSConsumesSelfAttrSpelling</summary>

Available enumerations:

* `GNU_NS_CONSUMES_SELF`
* `CXX11_CLANG_NS_CONSUMES_SELF`
* `C2_XCLANG_NS_CONSUMES_SELF`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NSReturnsAutoreleasedAttrSpelling"></a>NSReturnsAutoreleasedAttrSpelling</summary>

Available enumerations:

* `GNU_NS_RETURNS_AUTORELEASED`
* `CXX11_CLANG_NS_RETURNS_AUTORELEASED`
* `C2_XCLANG_NS_RETURNS_AUTORELEASED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NSReturnsNotRetainedAttrSpelling"></a>NSReturnsNotRetainedAttrSpelling</summary>

Available enumerations:

* `GNU_NS_RETURNS_NOT_RETAINED`
* `CXX11_CLANG_NS_RETURNS_NOT_RETAINED`
* `C2_XCLANG_NS_RETURNS_NOT_RETAINED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NSReturnsRetainedAttrSpelling"></a>NSReturnsRetainedAttrSpelling</summary>

Available enumerations:

* `GNU_NS_RETURNS_RETAINED`
* `CXX11_CLANG_NS_RETURNS_RETAINED`
* `C2_XCLANG_NS_RETURNS_RETAINED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NakedAttrSpelling"></a>NakedAttrSpelling</summary>

Available enumerations:

* `GNU_NAKED`
* `CXX11_GNU_NAKED`
* `C2_XGNU_NAKED`
* `DECLSPEC_NAKED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NamedDeclExplicitVisibilityKind"></a>NamedDeclExplicitVisibilityKind</summary>

Available enumerations:

* `VISIBILITY_FOR_TYPE`
* `VISIBILITY_FOR_VALUE`

</details>

<details><summary><a name="NoBuiltinAttrSpelling"></a>NoBuiltinAttrSpelling</summary>

Available enumerations:

* `GNU_NO_BUILTIN`
* `CXX11_CLANG_NO_BUILTIN`
* `C2_XCLANG_NO_BUILTIN`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoCommonAttrSpelling"></a>NoCommonAttrSpelling</summary>

Available enumerations:

* `GNU_NOCOMMON`
* `CXX11_GNU_NOCOMMON`
* `C2_XGNU_NOCOMMON`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoDebugAttrSpelling"></a>NoDebugAttrSpelling</summary>

Available enumerations:

* `GNU_NODEBUG`
* `CXX11_GNU_NODEBUG`
* `C2_XGNU_NODEBUG`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoDerefAttrSpelling"></a>NoDerefAttrSpelling</summary>

Available enumerations:

* `GNU_NODEREF`
* `CXX11_CLANG_NODEREF`
* `C2_XCLANG_NODEREF`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoDestroyAttrSpelling"></a>NoDestroyAttrSpelling</summary>

Available enumerations:

* `GNU_NO_DESTROY`
* `CXX11_CLANG_NO_DESTROY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoDuplicateAttrSpelling"></a>NoDuplicateAttrSpelling</summary>

Available enumerations:

* `GNU_NODUPLICATE`
* `CXX11_CLANG_NODUPLICATE`
* `C2_XCLANG_NODUPLICATE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoEscapeAttrSpelling"></a>NoEscapeAttrSpelling</summary>

Available enumerations:

* `GNU_NOESCAPE`
* `CXX11_CLANG_NOESCAPE`
* `C2_XCLANG_NOESCAPE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoInlineAttrSpelling"></a>NoInlineAttrSpelling</summary>

Available enumerations:

* `GNU_NOINLINE`
* `CXX11_GNU_NOINLINE`
* `C2_XGNU_NOINLINE`
* `DECLSPEC_NOINLINE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoInstrumentFunctionAttrSpelling"></a>NoInstrumentFunctionAttrSpelling</summary>

Available enumerations:

* `GNU_NO_INSTRUMENT_FUNCTION`
* `CXX11_GNU_NO_INSTRUMENT_FUNCTION`
* `C2_XGNU_NO_INSTRUMENT_FUNCTION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoMergeAttrSpelling"></a>NoMergeAttrSpelling</summary>

Available enumerations:

* `GNU_NOMERGE`
* `CXX11_CLANG_NOMERGE`
* `C2_XCLANG_NOMERGE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoMicroMipsAttrSpelling"></a>NoMicroMipsAttrSpelling</summary>

Available enumerations:

* `GNU_NOMICROMIPS`
* `CXX11_GNU_NOMICROMIPS`
* `C2_XGNU_NOMICROMIPS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoMips16AttrSpelling"></a>NoMips16AttrSpelling</summary>

Available enumerations:

* `GNU_NOMIPS16`
* `CXX11_GNU_NOMIPS16`
* `C2_XGNU_NOMIPS16`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoProfileFunctionAttrSpelling"></a>NoProfileFunctionAttrSpelling</summary>

Available enumerations:

* `GNU_NO_PROFILE_INSTRUMENT_FUNCTION`
* `CXX11_GNU_NO_PROFILE_INSTRUMENT_FUNCTION`
* `C2_XGNU_NO_PROFILE_INSTRUMENT_FUNCTION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoReturnAttrSpelling"></a>NoReturnAttrSpelling</summary>

Available enumerations:

* `GNU_NORETURN`
* `CXX11_GNU_NORETURN`
* `C2_XGNU_NORETURN`
* `DECLSPEC_NORETURN`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoSanitizeAttrSpelling"></a>NoSanitizeAttrSpelling</summary>

Available enumerations:

* `GNU_NO_SANITIZE`
* `CXX11_CLANG_NO_SANITIZE`
* `C2_XCLANG_NO_SANITIZE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoSpeculativeLoadHardeningAttrSpelling"></a>NoSpeculativeLoadHardeningAttrSpelling</summary>

Available enumerations:

* `GNU_NO_SPECULATIVE_LOAD_HARDENING`
* `CXX11_CLANG_NO_SPECULATIVE_LOAD_HARDENING`
* `C2_XCLANG_NO_SPECULATIVE_LOAD_HARDENING`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoSplitStackAttrSpelling"></a>NoSplitStackAttrSpelling</summary>

Available enumerations:

* `GNU_NO_SPLIT_STACK`
* `CXX11_GNU_NO_SPLIT_STACK`
* `C2_XGNU_NO_SPLIT_STACK`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoStackProtectorAttrSpelling"></a>NoStackProtectorAttrSpelling</summary>

Available enumerations:

* `GNU_NO_STACK_PROTECTOR`
* `CXX11_CLANG_NO_STACK_PROTECTOR`
* `C2_XCLANG_NO_STACK_PROTECTOR`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoThreadSafetyAnalysisAttrSpelling"></a>NoThreadSafetyAnalysisAttrSpelling</summary>

Available enumerations:

* `GNU_NO_THREAD_SAFETY_ANALYSIS`
* `CXX11_CLANG_NO_THREAD_SAFETY_ANALYSIS`
* `C2_XCLANG_NO_THREAD_SAFETY_ANALYSIS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NoThrowAttrSpelling"></a>NoThrowAttrSpelling</summary>

Available enumerations:

* `GNU_NOTHROW`
* `CXX11_GNU_NOTHROW`
* `C2_XGNU_NOTHROW`
* `DECLSPEC_NOTHROW`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NonNullAttrSpelling"></a>NonNullAttrSpelling</summary>

Available enumerations:

* `GNU_NONNULL`
* `CXX11_GNU_NONNULL`
* `C2_XGNU_NONNULL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="NotTailCalledAttrSpelling"></a>NotTailCalledAttrSpelling</summary>

Available enumerations:

* `GNU_NOT_TAIL_CALLED`
* `CXX11_CLANG_NOT_TAIL_CALLED`
* `C2_XCLANG_NOT_TAIL_CALLED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OMPAllocateDeclAttrAllocatorTypeTy"></a>OMPAllocateDeclAttrAllocatorTypeTy</summary>

Available enumerations:

* `OMP_NULL_MEMORY_ALLOC`
* `OMP_DEFAULT_MEMORY_ALLOC`
* `OMP_LARGE_CAP_MEMORY_ALLOC`
* `OMP_CONST_MEMORY_ALLOC`
* `OMP_HIGH_BW_MEMORY_ALLOC`
* `OMP_LOW_LAT_MEMORY_ALLOC`
* `OMPC_GROUP_MEMORY_ALLOC`
* `OMPP_TEAM_MEMORY_ALLOC`
* `OMP_THREAD_MEMORY_ALLOC`
* `OMP_USER_DEFINED_MEMORY_ALLOC`

</details>

<details><summary><a name="OMPDeclareReductionDeclInitKind"></a>OMPDeclareReductionDeclInitKind</summary>

Available enumerations:

* `CALL_INITIALIZER`
* `DIRECT_INITIALIZER`
* `COPY_INITIALIZER`

</details>

<details><summary><a name="OMPDeclareSimdDeclAttrBranchStateTy"></a>OMPDeclareSimdDeclAttrBranchStateTy</summary>

Available enumerations:

* `UNDEFINED`
* `INBRANCH`
* `NOTINBRANCH`

</details>

<details><summary><a name="OMPDeclareTargetDeclAttrDevTypeTy"></a>OMPDeclareTargetDeclAttrDevTypeTy</summary>

Available enumerations:

* `HOST`
* `NO_HOST`
* `ANY`

</details>

<details><summary><a name="OMPDeclareTargetDeclAttrMapTypeTy"></a>OMPDeclareTargetDeclAttrMapTypeTy</summary>

Available enumerations:

* `TO`
* `LINK`

</details>

<details><summary><a name="OMPDeclareVariantAttrInteropType"></a>OMPDeclareVariantAttrInteropType</summary>

Available enumerations:

* `TARGET`
* `TARGET_SYNC`
* `TARGET_TARGET_SYNC`

</details>

<details><summary><a name="OSConsumedAttrSpelling"></a>OSConsumedAttrSpelling</summary>

Available enumerations:

* `GNU_OS_CONSUMED`
* `CXX11_CLANG_OS_CONSUMED`
* `C2_XCLANG_OS_CONSUMED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OSConsumesThisAttrSpelling"></a>OSConsumesThisAttrSpelling</summary>

Available enumerations:

* `GNU_OS_CONSUMES_THIS`
* `CXX11_CLANG_OS_CONSUMES_THIS`
* `C2_XCLANG_OS_CONSUMES_THIS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OSReturnsNotRetainedAttrSpelling"></a>OSReturnsNotRetainedAttrSpelling</summary>

Available enumerations:

* `GNU_OS_RETURNS_NOT_RETAINED`
* `CXX11_CLANG_OS_RETURNS_NOT_RETAINED`
* `C2_XCLANG_OS_RETURNS_NOT_RETAINED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OSReturnsRetainedAttrSpelling"></a>OSReturnsRetainedAttrSpelling</summary>

Available enumerations:

* `GNU_OS_RETURNS_RETAINED`
* `CXX11_CLANG_OS_RETURNS_RETAINED`
* `C2_XCLANG_OS_RETURNS_RETAINED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OSReturnsRetainedOnNonZeroAttrSpelling"></a>OSReturnsRetainedOnNonZeroAttrSpelling</summary>

Available enumerations:

* `GNU_OS_RETURNS_RETAINED_ON_NON_ZERO`
* `CXX11_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO`
* `C2_XCLANG_OS_RETURNS_RETAINED_ON_NON_ZERO`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OSReturnsRetainedOnZeroAttrSpelling"></a>OSReturnsRetainedOnZeroAttrSpelling</summary>

Available enumerations:

* `GNU_OS_RETURNS_RETAINED_ON_ZERO`
* `CXX11_CLANG_OS_RETURNS_RETAINED_ON_ZERO`
* `C2_XCLANG_OS_RETURNS_RETAINED_ON_ZERO`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCBoxableAttrSpelling"></a>ObjCBoxableAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_BOXABLE`
* `CXX11_CLANG_OBJC_BOXABLE`
* `C2_XCLANG_OBJC_BOXABLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCBridgeAttrSpelling"></a>ObjCBridgeAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_BRIDGE`
* `CXX11_CLANG_OBJC_BRIDGE`
* `C2_XCLANG_OBJC_BRIDGE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCBridgeMutableAttrSpelling"></a>ObjCBridgeMutableAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_BRIDGE_MUTABLE`
* `CXX11_CLANG_OBJC_BRIDGE_MUTABLE`
* `C2_XCLANG_OBJC_BRIDGE_MUTABLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCBridgeRelatedAttrSpelling"></a>ObjCBridgeRelatedAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_BRIDGE_RELATED`
* `CXX11_CLANG_OBJC_BRIDGE_RELATED`
* `C2_XCLANG_OBJC_BRIDGE_RELATED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCClassStubAttrSpelling"></a>ObjCClassStubAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_CLASS_STUB`
* `CXX11_CLANG_OBJC_CLASS_STUB`
* `C2_XCLANG_OBJC_CLASS_STUB`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCDesignatedInitializerAttrSpelling"></a>ObjCDesignatedInitializerAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_DESIGNATED_INITIALIZER`
* `CXX11_CLANG_OBJC_DESIGNATED_INITIALIZER`
* `C2_XCLANG_OBJC_DESIGNATED_INITIALIZER`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCDirectAttrSpelling"></a>ObjCDirectAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_DIRECT`
* `CXX11_CLANG_OBJC_DIRECT`
* `C2_XCLANG_OBJC_DIRECT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCDirectMembersAttrSpelling"></a>ObjCDirectMembersAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_DIRECT_MEMBERS`
* `CXX11_CLANG_OBJC_DIRECT_MEMBERS`
* `C2_XCLANG_OBJC_DIRECT_MEMBERS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCExceptionAttrSpelling"></a>ObjCExceptionAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_EXCEPTION`
* `CXX11_CLANG_OBJC_EXCEPTION`
* `C2_XCLANG_OBJC_EXCEPTION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCExplicitProtocolImplAttrSpelling"></a>ObjCExplicitProtocolImplAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION`
* `CXX11_CLANG_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION`
* `C2_XCLANG_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCExternallyRetainedAttrSpelling"></a>ObjCExternallyRetainedAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_EXTERNALLY_RETAINED`
* `CXX11_CLANG_OBJC_EXTERNALLY_RETAINED`
* `C2_XCLANG_OBJC_EXTERNALLY_RETAINED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCGCAttrSpelling"></a>ObjCGCAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_GC`
* `CXX11_CLANG_OBJC_GC`
* `C2_XCLANG_OBJC_GC`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCIndependentClassAttrSpelling"></a>ObjCIndependentClassAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_INDEPENDENT_CLASS`
* `CXX11_CLANG_OBJC_INDEPENDENT_CLASS`
* `C2_XCLANG_OBJC_INDEPENDENT_CLASS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCIvarDeclAccessControl"></a>ObjCIvarDeclAccessControl</summary>

Available enumerations:

* `NONE`
* `PRIVATE`
* `PROTECTED`
* `PUBLIC`
* `PACKAGE`

</details>

<details><summary><a name="ObjCMessageExprReceiverKind"></a>ObjCMessageExprReceiverKind</summary>

Available enumerations:

* `CLASS`
* `INSTANCE`
* `SUPER_CLASS`
* `SUPER_INSTANCE`

</details>

<details><summary><a name="ObjCMethodDeclImplementationControl"></a>ObjCMethodDeclImplementationControl</summary>

Available enumerations:

* `NONE`
* `REQUIRED`
* `OPTIONAL`

</details>

<details><summary><a name="ObjCMethodFamilyAttrFamilyKind"></a>ObjCMethodFamilyAttrFamilyKind</summary>

Available enumerations:

* `NONE`
* `ALLOC`
* `COPY`
* `INITIALIZER`
* `MUTABLE_COPY`
* `NEW`

</details>

<details><summary><a name="ObjCMethodFamilyAttrSpelling"></a>ObjCMethodFamilyAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_METHOD_FAMILY`
* `CXX11_CLANG_OBJC_METHOD_FAMILY`
* `C2_XCLANG_OBJC_METHOD_FAMILY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCNSObjectAttrSpelling"></a>ObjCNSObjectAttrSpelling</summary>

Available enumerations:

* `GNUNS_OBJECT`
* `CXX11_CLANG_NS_OBJECT`
* `C2_XCLANG_NS_OBJECT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCNonLazyClassAttrSpelling"></a>ObjCNonLazyClassAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_NONLAZY_CLASS`
* `CXX11_CLANG_OBJC_NONLAZY_CLASS`
* `C2_XCLANG_OBJC_NONLAZY_CLASS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCNonRuntimeProtocolAttrSpelling"></a>ObjCNonRuntimeProtocolAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_NON_RUNTIME_PROTOCOL`
* `CXX11_CLANG_OBJC_NON_RUNTIME_PROTOCOL`
* `C2_XCLANG_OBJC_NON_RUNTIME_PROTOCOL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCOwnershipAttrSpelling"></a>ObjCOwnershipAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_OWNERSHIP`
* `CXX11_CLANG_OBJC_OWNERSHIP`
* `C2_XCLANG_OBJC_OWNERSHIP`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCPreciseLifetimeAttrSpelling"></a>ObjCPreciseLifetimeAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_PRECISE_LIFETIME`
* `CXX11_CLANG_OBJC_PRECISE_LIFETIME`
* `C2_XCLANG_OBJC_PRECISE_LIFETIME`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCPropertyDeclPropertyControl"></a>ObjCPropertyDeclPropertyControl</summary>

Available enumerations:

* `NONE`
* `REQUIRED`
* `OPTIONAL`

</details>

<details><summary><a name="ObjCPropertyDeclSetterKind"></a>ObjCPropertyDeclSetterKind</summary>

Available enumerations:

* `ASSIGN`
* `RETAIN`
* `COPY`
* `WEAK`

</details>

<details><summary><a name="ObjCPropertyImplDeclKind"></a>ObjCPropertyImplDeclKind</summary>

Available enumerations:

* `SYNTHESIZE`
* `DYNAMIC`

</details>

<details><summary><a name="ObjCRequiresPropertyDefsAttrSpelling"></a>ObjCRequiresPropertyDefsAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_REQUIRES_PROPERTY_DEFINITIONS`
* `CXX11_CLANG_OBJC_REQUIRES_PROPERTY_DEFINITIONS`
* `C2_XCLANG_OBJC_REQUIRES_PROPERTY_DEFINITIONS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCRequiresSuperAttrSpelling"></a>ObjCRequiresSuperAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_REQUIRES_SUPER`
* `CXX11_CLANG_OBJC_REQUIRES_SUPER`
* `C2_XCLANG_OBJC_REQUIRES_SUPER`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCReturnsInnerPointerAttrSpelling"></a>ObjCReturnsInnerPointerAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_RETURNS_INNER_POINTER`
* `CXX11_CLANG_OBJC_RETURNS_INNER_POINTER`
* `C2_XCLANG_OBJC_RETURNS_INNER_POINTER`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCRootClassAttrSpelling"></a>ObjCRootClassAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_ROOT_CLASS`
* `CXX11_CLANG_OBJC_ROOT_CLASS`
* `C2_XCLANG_OBJC_ROOT_CLASS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCRuntimeNameAttrSpelling"></a>ObjCRuntimeNameAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_RUNTIME_NAME`
* `CXX11_CLANG_OBJC_RUNTIME_NAME`
* `C2_XCLANG_OBJC_RUNTIME_NAME`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCRuntimeVisibleAttrSpelling"></a>ObjCRuntimeVisibleAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_RUNTIME_VISIBLE`
* `CXX11_CLANG_OBJC_RUNTIME_VISIBLE`
* `C2_XCLANG_OBJC_RUNTIME_VISIBLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ObjCSubclassingRestrictedAttrSpelling"></a>ObjCSubclassingRestrictedAttrSpelling</summary>

Available enumerations:

* `GNU_OBJC_SUBCLASSING_RESTRICTED`
* `CXX11_CLANG_OBJC_SUBCLASSING_RESTRICTED`
* `C2_XCLANG_OBJC_SUBCLASSING_RESTRICTED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OpenCLAccessAttrSpelling"></a>OpenCLAccessAttrSpelling</summary>

Available enumerations:

* `KEYWORD_READ_ONLY`
* `KEYWORD_WRITE_ONLY`
* `KEYWORD_READ_WRITE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OpenCLConstantAddressSpaceAttrSpelling"></a>OpenCLConstantAddressSpaceAttrSpelling</summary>

Available enumerations:

* `KEYWORD_CONSTANT`
* `GNU_OPENCL_CONSTANT`
* `CXX11_CLANG_OPENCL_CONSTANT`
* `C2_XCLANG_OPENCL_CONSTANT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OpenCLGenericAddressSpaceAttrSpelling"></a>OpenCLGenericAddressSpaceAttrSpelling</summary>

Available enumerations:

* `KEYWORD_GENERIC`
* `GNU_OPENCL_GENERIC`
* `CXX11_CLANG_OPENCL_GENERIC`
* `C2_XCLANG_OPENCL_GENERIC`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OpenCLGlobalAddressSpaceAttrSpelling"></a>OpenCLGlobalAddressSpaceAttrSpelling</summary>

Available enumerations:

* `KEYWORD_GLOBAL`
* `GNU_OPENCL_GLOBAL`
* `CXX11_CLANG_OPENCL_GLOBAL`
* `C2_XCLANG_OPENCL_GLOBAL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OpenCLGlobalDeviceAddressSpaceAttrSpelling"></a>OpenCLGlobalDeviceAddressSpaceAttrSpelling</summary>

Available enumerations:

* `GNU_OPENCL_GLOBAL_DEVICE`
* `CXX11_CLANG_OPENCL_GLOBAL_DEVICE`
* `C2_XCLANG_OPENCL_GLOBAL_DEVICE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OpenCLGlobalHostAddressSpaceAttrSpelling"></a>OpenCLGlobalHostAddressSpaceAttrSpelling</summary>

Available enumerations:

* `GNU_OPENCL_GLOBAL_HOST`
* `CXX11_CLANG_OPENCL_GLOBAL_HOST`
* `C2_XCLANG_OPENCL_GLOBAL_HOST`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OpenCLKernelAttrSpelling"></a>OpenCLKernelAttrSpelling</summary>

Available enumerations:

* `KEYWORD_KERNEL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OpenCLLocalAddressSpaceAttrSpelling"></a>OpenCLLocalAddressSpaceAttrSpelling</summary>

Available enumerations:

* `KEYWORD_LOCAL`
* `GNU_OPENCL_LOCAL`
* `CXX11_CLANG_OPENCL_LOCAL`
* `C2_XCLANG_OPENCL_LOCAL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OpenCLPrivateAddressSpaceAttrSpelling"></a>OpenCLPrivateAddressSpaceAttrSpelling</summary>

Available enumerations:

* `KEYWORD_PRIVATE`
* `GNU_OPENCL_PRIVATE`
* `CXX11_CLANG_OPENCL_PRIVATE`
* `C2_XCLANG_OPENCL_PRIVATE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OptimizeNoneAttrSpelling"></a>OptimizeNoneAttrSpelling</summary>

Available enumerations:

* `GNU_OPTNONE`
* `CXX11_CLANG_OPTNONE`
* `C2_XCLANG_OPTNONE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OverloadableAttrSpelling"></a>OverloadableAttrSpelling</summary>

Available enumerations:

* `GNU_OVERLOADABLE`
* `CXX11_CLANG_OVERLOADABLE`
* `C2_XCLANG_OVERLOADABLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="OwnershipAttrOwnershipKind"></a>OwnershipAttrOwnershipKind</summary>

Available enumerations:

* `HOLDS`
* `RETURNS`
* `TAKES`

</details>

<details><summary><a name="OwnershipAttrSpelling"></a>OwnershipAttrSpelling</summary>

Available enumerations:

* `GNU_OWNERSHIP_HOLDS`
* `CXX11_CLANG_OWNERSHIP_HOLDS`
* `C2_XCLANG_OWNERSHIP_HOLDS`
* `GNU_OWNERSHIP_RETURNS`
* `CXX11_CLANG_OWNERSHIP_RETURNS`
* `C2_XCLANG_OWNERSHIP_RETURNS`
* `GNU_OWNERSHIP_TAKES`
* `CXX11_CLANG_OWNERSHIP_TAKES`
* `C2_XCLANG_OWNERSHIP_TAKES`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="PackedAttrSpelling"></a>PackedAttrSpelling</summary>

Available enumerations:

* `GNU_PACKED`
* `CXX11_GNU_PACKED`
* `C2_XGNU_PACKED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ParamTypestateAttrConsumedState"></a>ParamTypestateAttrConsumedState</summary>

Available enumerations:

* `UNKNOWN`
* `CONSUMED`
* `UNCONSUMED`

</details>

<details><summary><a name="ParamTypestateAttrSpelling"></a>ParamTypestateAttrSpelling</summary>

Available enumerations:

* `GNU_PARAMETER_TYPESTATE`
* `CXX11_CLANG_PARAMETER_TYPESTATE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="PascalAttrSpelling"></a>PascalAttrSpelling</summary>

Available enumerations:

* `GNU_PASCAL`
* `CXX11_CLANG_PASCAL`
* `C2_XCLANG_PASCAL`
* `KEYWORD_PASCAL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="PassObjectSizeAttrSpelling"></a>PassObjectSizeAttrSpelling</summary>

Available enumerations:

* `GNU_PASS_OBJECT_SIZE`
* `CXX11_CLANG_PASS_OBJECT_SIZE`
* `C2_XCLANG_PASS_OBJECT_SIZE`
* `GNU_PASS_DYNAMIC_OBJECT_SIZE`
* `CXX11_CLANG_PASS_DYNAMIC_OBJECT_SIZE`
* `C2_XCLANG_PASS_DYNAMIC_OBJECT_SIZE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="PatchableFunctionEntryAttrSpelling"></a>PatchableFunctionEntryAttrSpelling</summary>

Available enumerations:

* `GNU_PATCHABLE_FUNCTION_ENTRY`
* `CXX11_GNU_PATCHABLE_FUNCTION_ENTRY`
* `C2_XGNU_PATCHABLE_FUNCTION_ENTRY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="PcsAttrPCSType"></a>PcsAttrPCSType</summary>

Available enumerations:

* `AAPCS`
* `VFP`

</details>

<details><summary><a name="PcsAttrSpelling"></a>PcsAttrSpelling</summary>

Available enumerations:

* `GNU_PCS`
* `CXX11_GNU_PCS`
* `C2_XGNU_PCS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="PredefinedExprIdentKind"></a>PredefinedExprIdentKind</summary>

Available enumerations:

* `FUNC`
* `FUNCTION`
* `L_FUNCTION`
* `FUNC_D_NAME`
* `FUNC_SIG`
* `L_FUNC_SIG`
* `PRETTY_FUNCTION`
* `PRETTY_FUNCTION_NO_VIRTUAL`

</details>

<details><summary><a name="PreferredNameAttrSpelling"></a>PreferredNameAttrSpelling</summary>

Available enumerations:

* `GNU_PREFERRED_NAME`
* `CXX11_CLANG_PREFERRED_NAME`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="PreserveAllAttrSpelling"></a>PreserveAllAttrSpelling</summary>

Available enumerations:

* `GNU_PRESERVE_ALL`
* `CXX11_CLANG_PRESERVE_ALL`
* `C2_XCLANG_PRESERVE_ALL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="PreserveMostAttrSpelling"></a>PreserveMostAttrSpelling</summary>

Available enumerations:

* `GNU_PRESERVE_MOST`
* `CXX11_CLANG_PRESERVE_MOST`
* `C2_XCLANG_PRESERVE_MOST`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="PtGuardedVarAttrSpelling"></a>PtGuardedVarAttrSpelling</summary>

Available enumerations:

* `GNU_PT_GUARDED_VARIABLE`
* `CXX11_CLANG_PT_GUARDED_VARIABLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="PureAttrSpelling"></a>PureAttrSpelling</summary>

Available enumerations:

* `GNU_PURE`
* `CXX11_GNU_PURE`
* `C2_XGNU_PURE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="QualTypeDestructionKind"></a>QualTypeDestructionKind</summary>

Available enumerations:

* `NONE`
* `CXX_DESTRUCTOR`
* `OBJC_STRONG_LIFETIME`
* `OBJC_WEAK_LIFETIME`
* `NONTRIVIAL_C_STRUCT`

</details>

<details><summary><a name="QualTypePrimitiveCopyKind"></a>QualTypePrimitiveCopyKind</summary>

Available enumerations:

* `TRIVIAL`
* `VOLATILE_TRIVIAL`
* `ARC_STRONG`
* `ARC_WEAK`
* `STRUCT`

</details>

<details><summary><a name="QualTypePrimitiveDefaultInitializeKind"></a>QualTypePrimitiveDefaultInitializeKind</summary>

Available enumerations:

* `TRIVIAL`
* `ARC_STRONG`
* `ARC_WEAK`
* `STRUCT`

</details>

<details><summary><a name="RISCVInterruptAttrInterruptType"></a>RISCVInterruptAttrInterruptType</summary>

Available enumerations:

* `USER`
* `SUPERVISOR`
* `MACHINE`

</details>

<details><summary><a name="RISCVInterruptAttrSpelling"></a>RISCVInterruptAttrSpelling</summary>

Available enumerations:

* `GNU_INTERRUPT`
* `CXX11_GNU_INTERRUPT`
* `C2_XGNU_INTERRUPT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="RecordDeclArgPassingKind"></a>RecordDeclArgPassingKind</summary>

Available enumerations:

* `CAN_PASS_IN_REGS`
* `CANNOT_PASS_IN_REGS`
* `CAN_NEVER_PASS_IN_REGS`

</details>

<details><summary><a name="RegCallAttrSpelling"></a>RegCallAttrSpelling</summary>

Available enumerations:

* `GNU_REGCALL`
* `CXX11_GNU_REGCALL`
* `C2_XGNU_REGCALL`
* `KEYWORD_REGCALL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ReinitializesAttrSpelling"></a>ReinitializesAttrSpelling</summary>

Available enumerations:

* `GNU_REINITIALIZES`
* `CXX11_CLANG_REINITIALIZES`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ReleaseCapabilityAttrSpelling"></a>ReleaseCapabilityAttrSpelling</summary>

Available enumerations:

* `GNU_RELEASE_CAPABILITY`
* `CXX11_CLANG_RELEASE_CAPABILITY`
* `GNU_RELEASE_SHARED_CAPABILITY`
* `CXX11_CLANG_RELEASE_SHARED_CAPABILITY`
* `GNU_RELEASE_GENERIC_CAPABILITY`
* `CXX11_CLANG_RELEASE_GENERIC_CAPABILITY`
* `GNU_UNLOCK_FUNCTION`
* `CXX11_CLANG_UNLOCK_FUNCTION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ReleaseHandleAttrSpelling"></a>ReleaseHandleAttrSpelling</summary>

Available enumerations:

* `GNU_RELEASE_HANDLE`
* `CXX11_CLANG_RELEASE_HANDLE`
* `C2_XCLANG_RELEASE_HANDLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="RequiresCapabilityAttrSpelling"></a>RequiresCapabilityAttrSpelling</summary>

Available enumerations:

* `GNU_REQUIRES_CAPABILITY`
* `CXX11_CLANG_REQUIRES_CAPABILITY`
* `GNU_EXCLUSIVE_LOCKS_REQUIRED`
* `CXX11_CLANG_EXCLUSIVE_LOCKS_REQUIRED`
* `GNU_REQUIRES_SHARED_CAPABILITY`
* `CXX11_CLANG_REQUIRES_SHARED_CAPABILITY`
* `GNU_SHARED_LOCKS_REQUIRED`
* `CXX11_CLANG_SHARED_LOCKS_REQUIRED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="RestrictAttrSpelling"></a>RestrictAttrSpelling</summary>

Available enumerations:

* `DECLSPEC_RESTRICT`
* `GNU_MALLOC`
* `CXX11_GNU_MALLOC`
* `C2_XGNU_MALLOC`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="RetainAttrSpelling"></a>RetainAttrSpelling</summary>

Available enumerations:

* `GNU_RETAIN`
* `CXX11_GNU_RETAIN`
* `C2_XGNU_RETAIN`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ReturnTypestateAttrConsumedState"></a>ReturnTypestateAttrConsumedState</summary>

Available enumerations:

* `UNKNOWN`
* `CONSUMED`
* `UNCONSUMED`

</details>

<details><summary><a name="ReturnTypestateAttrSpelling"></a>ReturnTypestateAttrSpelling</summary>

Available enumerations:

* `GNU_RETURN_TYPESTATE`
* `CXX11_CLANG_RETURN_TYPESTATE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ReturnsNonNullAttrSpelling"></a>ReturnsNonNullAttrSpelling</summary>

Available enumerations:

* `GNU_RETURNS_NONNULL`
* `CXX11_GNU_RETURNS_NONNULL`
* `C2_XGNU_RETURNS_NONNULL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ReturnsTwiceAttrSpelling"></a>ReturnsTwiceAttrSpelling</summary>

Available enumerations:

* `GNU_RETURNS_TWICE`
* `CXX11_GNU_RETURNS_TWICE`
* `C2_XGNU_RETURNS_TWICE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SYCLKernelAttrSpelling"></a>SYCLKernelAttrSpelling</summary>

Available enumerations:

* `GNU_SYCL_KERNEL`
* `CXX11_CLANG_SYCL_KERNEL`
* `C2_XCLANG_SYCL_KERNEL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SYCLSpecialClassAttrSpelling"></a>SYCLSpecialClassAttrSpelling</summary>

Available enumerations:

* `GNU_SYCL_SPECIAL_CLASS`
* `CXX11_CLANG_SYCL_SPECIAL_CLASS`
* `C2_XCLANG_SYCL_SPECIAL_CLASS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ScopedLockableAttrSpelling"></a>ScopedLockableAttrSpelling</summary>

Available enumerations:

* `GNU_SCOPED_LOCKABLE`
* `CXX11_CLANG_SCOPED_LOCKABLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SectionAttrSpelling"></a>SectionAttrSpelling</summary>

Available enumerations:

* `GNU_SECTION`
* `CXX11_GNU_SECTION`
* `C2_XGNU_SECTION`
* `DECLSPEC_ALLOCATE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SelectAnyAttrSpelling"></a>SelectAnyAttrSpelling</summary>

Available enumerations:

* `DECLSPEC_SELECTANY`
* `GNU_SELECTANY`
* `CXX11_GNU_SELECTANY`
* `C2_XGNU_SELECTANY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SentinelAttrSpelling"></a>SentinelAttrSpelling</summary>

Available enumerations:

* `GNU_SENTINEL`
* `CXX11_GNU_SENTINEL`
* `C2_XGNU_SENTINEL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SetTypestateAttrConsumedState"></a>SetTypestateAttrConsumedState</summary>

Available enumerations:

* `UNKNOWN`
* `CONSUMED`
* `UNCONSUMED`

</details>

<details><summary><a name="SetTypestateAttrSpelling"></a>SetTypestateAttrSpelling</summary>

Available enumerations:

* `GNU_TYPESTATE`
* `CXX11_CLANG_TYPESTATE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SourceLocExprIdentKind"></a>SourceLocExprIdentKind</summary>

Available enumerations:

* `FUNCTION`
* `FILE`
* `LINE`
* `COLUMN`

</details>

<details><summary><a name="SpeculativeLoadHardeningAttrSpelling"></a>SpeculativeLoadHardeningAttrSpelling</summary>

Available enumerations:

* `GNU_SPECULATIVE_LOAD_HARDENING`
* `CXX11_CLANG_SPECULATIVE_LOAD_HARDENING`
* `C2_XCLANG_SPECULATIVE_LOAD_HARDENING`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="StandaloneDebugAttrSpelling"></a>StandaloneDebugAttrSpelling</summary>

Available enumerations:

* `GNU_STANDALONE_DEBUG`
* `CXX11_CLANG_STANDALONE_DEBUG`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="StdCallAttrSpelling"></a>StdCallAttrSpelling</summary>

Available enumerations:

* `GNU_STDCALL`
* `CXX11_GNU_STDCALL`
* `C2_XGNU_STDCALL`
* `KEYWORD_STDCALL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="StmtLikelihood"></a>StmtLikelihood</summary>

Available enumerations:

* `UNLIKELY`
* `NONE`
* `LIKELY`

</details>

<details><summary><a name="StmtKind"></a>StmtKind</summary>

Available enumerations:

* `GCC_ASM_STMT`
* `MS_ASM_STMT`
* `BREAK_STMT`
* `CXX_CATCH_STMT`
* `CXX_FOR_RANGE_STMT`
* `CXX_TRY_STMT`
* `CAPTURED_STMT`
* `COMPOUND_STMT`
* `CONTINUE_STMT`
* `CORETURN_STMT`
* `COROUTINE_BODY_STMT`
* `DECL_STMT`
* `DO_STMT`
* `FOR_STMT`
* `GOTO_STMT`
* `IF_STMT`
* `INDIRECT_GOTO_STMT`
* `MS_DEPENDENT_EXISTS_STMT`
* `NULL_STMT`
* `OMP_CANONICAL_LOOP`
* `OMP_ATOMIC_DIRECTIVE`
* `OMP_BARRIER_DIRECTIVE`
* `OMP_CANCEL_DIRECTIVE`
* `OMP_CANCELLATION_POINT_DIRECTIVE`
* `OMP_CRITICAL_DIRECTIVE`
* `OMP_DEPOBJ_DIRECTIVE`
* `OMP_DISPATCH_DIRECTIVE`
* `OMP_FLUSH_DIRECTIVE`
* `OMP_INTEROP_DIRECTIVE`
* `OMP_DISTRIBUTE_DIRECTIVE`
* `OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE`
* `OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE`
* `OMP_DISTRIBUTE_SIMD_DIRECTIVE`
* `OMP_FOR_DIRECTIVE`
* `OMP_FOR_SIMD_DIRECTIVE`
* `OMP_GENERIC_LOOP_DIRECTIVE`
* `OMP_MASTER_TASK_LOOP_DIRECTIVE`
* `OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE`
* `OMP_PARALLEL_FOR_DIRECTIVE`
* `OMP_PARALLEL_FOR_SIMD_DIRECTIVE`
* `OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE`
* `OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE`
* `OMP_SIMD_DIRECTIVE`
* `OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE`
* `OMP_TARGET_SIMD_DIRECTIVE`
* `OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE`
* `OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE`
* `OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE`
* `OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE`
* `OMP_TASK_LOOP_DIRECTIVE`
* `OMP_TASK_LOOP_SIMD_DIRECTIVE`
* `OMP_TEAMS_DISTRIBUTE_DIRECTIVE`
* `OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE`
* `OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE`
* `OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE`
* `OMP_TILE_DIRECTIVE`
* `OMP_UNROLL_DIRECTIVE`
* `OMP_MASKED_DIRECTIVE`
* `OMP_MASTER_DIRECTIVE`
* `OMP_META_DIRECTIVE`
* `OMP_ORDERED_DIRECTIVE`
* `OMP_PARALLEL_DIRECTIVE`
* `OMP_PARALLEL_MASTER_DIRECTIVE`
* `OMP_PARALLEL_SECTIONS_DIRECTIVE`
* `OMP_SCAN_DIRECTIVE`
* `OMP_SECTION_DIRECTIVE`
* `OMP_SECTIONS_DIRECTIVE`
* `OMP_SINGLE_DIRECTIVE`
* `OMP_TARGET_DATA_DIRECTIVE`
* `OMP_TARGET_DIRECTIVE`
* `OMP_TARGET_ENTER_DATA_DIRECTIVE`
* `OMP_TARGET_EXIT_DATA_DIRECTIVE`
* `OMP_TARGET_PARALLEL_DIRECTIVE`
* `OMP_TARGET_PARALLEL_FOR_DIRECTIVE`
* `OMP_TARGET_TEAMS_DIRECTIVE`
* `OMP_TARGET_UPDATE_DIRECTIVE`
* `OMP_TASK_DIRECTIVE`
* `OMP_TASKGROUP_DIRECTIVE`
* `OMP_TASKWAIT_DIRECTIVE`
* `OMP_TASKYIELD_DIRECTIVE`
* `OMP_TEAMS_DIRECTIVE`
* `OBJ_C_AT_CATCH_STMT`
* `OBJ_C_AT_FINALLY_STMT`
* `OBJ_C_AT_SYNCHRONIZED_STMT`
* `OBJ_C_AT_THROW_STMT`
* `OBJ_C_AT_TRY_STMT`
* `OBJ_C_AUTORELEASE_POOL_STMT`
* `OBJ_C_FOR_COLLECTION_STMT`
* `RETURN_STMT`
* `SEH_EXCEPT_STMT`
* `SEH_FINALLY_STMT`
* `SEH_LEAVE_STMT`
* `SEH_TRY_STMT`
* `CASE_STMT`
* `DEFAULT_STMT`
* `SWITCH_STMT`
* `ATTRIBUTED_STMT`
* `BINARY_CONDITIONAL_OPERATOR`
* `CONDITIONAL_OPERATOR`
* `ADDR_LABEL_EXPR`
* `ARRAY_INIT_INDEX_EXPR`
* `ARRAY_INIT_LOOP_EXPR`
* `ARRAY_SUBSCRIPT_EXPR`
* `ARRAY_TYPE_TRAIT_EXPR`
* `AS_TYPE_EXPR`
* `ATOMIC_EXPR`
* `BINARY_OPERATOR`
* `COMPOUND_ASSIGN_OPERATOR`
* `BLOCK_EXPR`
* `CXX_BIND_TEMPORARY_EXPR`
* `CXX_BOOL_LITERAL_EXPR`
* `CXX_CONSTRUCT_EXPR`
* `CXX_TEMPORARY_OBJECT_EXPR`
* `CXX_DEFAULT_ARG_EXPR`
* `CXX_DEFAULT_INIT_EXPR`
* `CXX_DELETE_EXPR`
* `CXX_DEPENDENT_SCOPE_MEMBER_EXPR`
* `CXX_FOLD_EXPR`
* `CXX_INHERITED_CTOR_INIT_EXPR`
* `CXX_NEW_EXPR`
* `CXX_NOEXCEPT_EXPR`
* `CXX_NULL_PTR_LITERAL_EXPR`
* `CXX_PSEUDO_DESTRUCTOR_EXPR`
* `CXX_REWRITTEN_BINARY_OPERATOR`
* `CXX_SCALAR_VALUE_INIT_EXPR`
* `CXX_STD_INITIALIZER_LIST_EXPR`
* `CXX_THIS_EXPR`
* `CXX_THROW_EXPR`
* `CXX_TYPEID_EXPR`
* `CXX_UNRESOLVED_CONSTRUCT_EXPR`
* `CXX_UUIDOF_EXPR`
* `CALL_EXPR`
* `CUDA_KERNEL_CALL_EXPR`
* `CXX_MEMBER_CALL_EXPR`
* `CXX_OPERATOR_CALL_EXPR`
* `USER_DEFINED_LITERAL`
* `BUILTIN_BIT_CAST_EXPR`
* `C_STYLE_CAST_EXPR`
* `CXX_FUNCTIONAL_CAST_EXPR`
* `CXX_ADDRSPACE_CAST_EXPR`
* `CXX_CONST_CAST_EXPR`
* `CXX_DYNAMIC_CAST_EXPR`
* `CXX_REINTERPRET_CAST_EXPR`
* `CXX_STATIC_CAST_EXPR`
* `OBJ_C_BRIDGED_CAST_EXPR`
* `IMPLICIT_CAST_EXPR`
* `CHARACTER_LITERAL`
* `CHOOSE_EXPR`
* `COMPOUND_LITERAL_EXPR`
* `CONCEPT_SPECIALIZATION_EXPR`
* `CONVERT_VECTOR_EXPR`
* `COAWAIT_EXPR`
* `COYIELD_EXPR`
* `DECL_REF_EXPR`
* `DEPENDENT_COAWAIT_EXPR`
* `DEPENDENT_SCOPE_DECL_REF_EXPR`
* `DESIGNATED_INIT_EXPR`
* `DESIGNATED_INIT_UPDATE_EXPR`
* `EXPRESSION_TRAIT_EXPR`
* `EXT_VECTOR_ELEMENT_EXPR`
* `FIXED_POINT_LITERAL`
* `FLOATING_LITERAL`
* `CONSTANT_EXPR`
* `EXPR_WITH_CLEANUPS`
* `FUNCTION_PARM_PACK_EXPR`
* `GNU_NULL_EXPR`
* `GENERIC_SELECTION_EXPR`
* `IMAGINARY_LITERAL`
* `IMPLICIT_VALUE_INIT_EXPR`
* `INIT_LIST_EXPR`
* `INTEGER_LITERAL`
* `LAMBDA_EXPR`
* `MS_PROPERTY_REF_EXPR`
* `MS_PROPERTY_SUBSCRIPT_EXPR`
* `MATERIALIZE_TEMPORARY_EXPR`
* `MATRIX_SUBSCRIPT_EXPR`
* `MEMBER_EXPR`
* `NO_INIT_EXPR`
* `OMP_ARRAY_SECTION_EXPR`
* `OMP_ARRAY_SHAPING_EXPR`
* `OMP_ITERATOR_EXPR`
* `OBJ_C_ARRAY_LITERAL`
* `OBJ_C_AVAILABILITY_CHECK_EXPR`
* `OBJ_C_BOOL_LITERAL_EXPR`
* `OBJ_C_BOXED_EXPR`
* `OBJ_C_DICTIONARY_LITERAL`
* `OBJ_C_ENCODE_EXPR`
* `OBJ_C_INDIRECT_COPY_RESTORE_EXPR`
* `OBJ_C_ISA_EXPR`
* `OBJ_C_IVAR_REF_EXPR`
* `OBJ_C_MESSAGE_EXPR`
* `OBJ_C_PROPERTY_REF_EXPR`
* `OBJ_C_PROTOCOL_EXPR`
* `OBJ_C_SELECTOR_EXPR`
* `OBJ_C_STRING_LITERAL`
* `OBJ_C_SUBSCRIPT_REF_EXPR`
* `OFFSET_OF_EXPR`
* `OPAQUE_VALUE_EXPR`
* `UNRESOLVED_LOOKUP_EXPR`
* `UNRESOLVED_MEMBER_EXPR`
* `PACK_EXPANSION_EXPR`
* `PAREN_EXPR`
* `PAREN_LIST_EXPR`
* `PREDEFINED_EXPR`
* `PSEUDO_OBJECT_EXPR`
* `RECOVERY_EXPR`
* `REQUIRES_EXPR`
* `SYCL_UNIQUE_STABLE_NAME_EXPR`
* `SHUFFLE_VECTOR_EXPR`
* `SIZE_OF_PACK_EXPR`
* `SOURCE_LOC_EXPR`
* `STMT_EXPR`
* `STRING_LITERAL`
* `SUBST_NON_TYPE_TEMPLATE_PARM_EXPR`
* `SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR`
* `TYPE_TRAIT_EXPR`
* `TYPO_EXPR`
* `UNARY_EXPR_OR_TYPE_TRAIT_EXPR`
* `UNARY_OPERATOR`
* `VA_ARG_EXPR`
* `LABEL_STMT`
* `WHILE_STMT`

</details>

<details><summary><a name="StringLiteralStringKind"></a>StringLiteralStringKind</summary>

Available enumerations:

* `ASCII`
* `WIDE`
* `UTF8`
* `UTF16`
* `UTF32`

</details>

<details><summary><a name="SwiftAsyncAttrKind"></a>SwiftAsyncAttrKind</summary>

Available enumerations:

* `NONE`
* `SWIFT_PRIVATE`
* `NOT_SWIFT_PRIVATE`

</details>

<details><summary><a name="SwiftAsyncAttrSpelling"></a>SwiftAsyncAttrSpelling</summary>

Available enumerations:

* `GNU_SWIFT_ASYNC`
* `CXX11_CLANG_SWIFT_ASYNC`
* `C2_XCLANG_SWIFT_ASYNC`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SwiftAsyncCallAttrSpelling"></a>SwiftAsyncCallAttrSpelling</summary>

Available enumerations:

* `GNU_SWIFTASYNCCALL`
* `CXX11_CLANG_SWIFTASYNCCALL`
* `C2_XCLANG_SWIFTASYNCCALL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SwiftAsyncContextAttrSpelling"></a>SwiftAsyncContextAttrSpelling</summary>

Available enumerations:

* `GNU_SWIFT_ASYNC_CONTEXT`
* `CXX11_CLANG_SWIFT_ASYNC_CONTEXT`
* `C2_XCLANG_SWIFT_ASYNC_CONTEXT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SwiftAsyncErrorAttrConventionKind"></a>SwiftAsyncErrorAttrConventionKind</summary>

Available enumerations:

* `NONE`
* `NON_NULL_ERROR`
* `ZERO_ARGUMENT`
* `NON_ZERO_ARGUMENT`

</details>

<details><summary><a name="SwiftAsyncErrorAttrSpelling"></a>SwiftAsyncErrorAttrSpelling</summary>

Available enumerations:

* `GNU_SWIFT_ASYNC_ERROR`
* `CXX11_CLANG_SWIFT_ASYNC_ERROR`
* `C2_XCLANG_SWIFT_ASYNC_ERROR`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SwiftCallAttrSpelling"></a>SwiftCallAttrSpelling</summary>

Available enumerations:

* `GNU_SWIFTCALL`
* `CXX11_CLANG_SWIFTCALL`
* `C2_XCLANG_SWIFTCALL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SwiftContextAttrSpelling"></a>SwiftContextAttrSpelling</summary>

Available enumerations:

* `GNU_SWIFT_CONTEXT`
* `CXX11_CLANG_SWIFT_CONTEXT`
* `C2_XCLANG_SWIFT_CONTEXT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SwiftErrorAttrConventionKind"></a>SwiftErrorAttrConventionKind</summary>

Available enumerations:

* `NONE`
* `NON_NULL_ERROR`
* `NULL_RESULT`
* `ZERO_RESULT`
* `NON_ZERO_RESULT`

</details>

<details><summary><a name="SwiftErrorResultAttrSpelling"></a>SwiftErrorResultAttrSpelling</summary>

Available enumerations:

* `GNU_SWIFT_ERROR_RESULT`
* `CXX11_CLANG_SWIFT_ERROR_RESULT`
* `C2_XCLANG_SWIFT_ERROR_RESULT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SwiftIndirectResultAttrSpelling"></a>SwiftIndirectResultAttrSpelling</summary>

Available enumerations:

* `GNU_SWIFT_INDIRECT_RESULT`
* `CXX11_CLANG_SWIFT_INDIRECT_RESULT`
* `C2_XCLANG_SWIFT_INDIRECT_RESULT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SwiftNewTypeAttrNewtypeKind"></a>SwiftNewTypeAttrNewtypeKind</summary>

Available enumerations:

* `STRUCT`
* `ENUM`

</details>

<details><summary><a name="SwiftNewTypeAttrSpelling"></a>SwiftNewTypeAttrSpelling</summary>

Available enumerations:

* `GNU_SWIFT_NEWTYPE`
* `GNU_SWIFT_WRAPPER`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="SysVABIAttrSpelling"></a>SysVABIAttrSpelling</summary>

Available enumerations:

* `GNU_SYSV_ABI`
* `CXX11_GNU_SYSV_ABI`
* `C2_XGNU_SYSV_ABI`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="TLSModelAttrSpelling"></a>TLSModelAttrSpelling</summary>

Available enumerations:

* `GNU_TLS_MODEL`
* `CXX11_GNU_TLS_MODEL`
* `C2_XGNU_TLS_MODEL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="TargetAttrSpelling"></a>TargetAttrSpelling</summary>

Available enumerations:

* `GNU_TARGET`
* `CXX11_GNU_TARGET`
* `C2_XGNU_TARGET`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="TargetClonesAttrSpelling"></a>TargetClonesAttrSpelling</summary>

Available enumerations:

* `GNU_TARGET_CLONES`
* `CXX11_GNU_TARGET_CLONES`
* `C2_XGNU_TARGET_CLONES`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="TemplateArgumentKind"></a>TemplateArgumentKind</summary>

Available enumerations:

* `EMPTY`
* `TYPE`
* `DECLARATION`
* `NULL_POINTER`
* `INTEGRAL`
* `TEMPLATE`
* `TEMPLATE_EXPANSION`
* `EXPRESSION`
* `PACK`

</details>

<details><summary><a name="TestTypestateAttrConsumedState"></a>TestTypestateAttrConsumedState</summary>

Available enumerations:

* `CONSUMED`
* `UNCONSUMED`

</details>

<details><summary><a name="TestTypestateAttrSpelling"></a>TestTypestateAttrSpelling</summary>

Available enumerations:

* `GNU_TEST_TYPESTATE`
* `CXX11_CLANG_TEST_TYPESTATE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ThisCallAttrSpelling"></a>ThisCallAttrSpelling</summary>

Available enumerations:

* `GNU_THISCALL`
* `CXX11_GNU_THISCALL`
* `C2_XGNU_THISCALL`
* `KEYWORD_THISCALL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="TransparentUnionAttrSpelling"></a>TransparentUnionAttrSpelling</summary>

Available enumerations:

* `GNU_TRANSPARENT_UNION`
* `CXX11_GNU_TRANSPARENT_UNION`
* `C2_XGNU_TRANSPARENT_UNION`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="TrivialABIAttrSpelling"></a>TrivialABIAttrSpelling</summary>

Available enumerations:

* `GNU_TRIVIAL_ABI`
* `CXX11_CLANG_TRIVIAL_ABI`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="TryAcquireCapabilityAttrSpelling"></a>TryAcquireCapabilityAttrSpelling</summary>

Available enumerations:

* `GNU_TRY_ACQUIRE_CAPABILITY`
* `CXX11_CLANG_TRY_ACQUIRE_CAPABILITY`
* `GNU_TRY_ACQUIRE_SHARED_CAPABILITY`
* `CXX11_CLANG_TRY_ACQUIRE_SHARED_CAPABILITY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="TypeScalarTypeKind"></a>TypeScalarTypeKind</summary>

Available enumerations:

* `C_POINTER`
* `BLOCK_POINTER`
* `OBJ_C_OBJECT_POINTER`
* `MEMBER_POINTER`
* `BOOLEAN`
* `INTEGRAL`
* `FLOATING`
* `INTEGRAL_COMPLEX`
* `FLOATING_COMPLEX`
* `FIXED_POINT`

</details>

<details><summary><a name="TypeKind"></a>TypeKind</summary>

Available enumerations:

* `ADJUSTED`
* `DECAYED`
* `CONSTANT_ARRAY`
* `DEPENDENT_SIZED_ARRAY`
* `INCOMPLETE_ARRAY`
* `VARIABLE_ARRAY`
* `ATOMIC`
* `ATTRIBUTED`
* `BIT_INT`
* `BLOCK_POINTER`
* `BUILTIN`
* `COMPLEX`
* `DECLTYPE`
* `AUTO`
* `DEDUCED_TEMPLATE_SPECIALIZATION`
* `DEPENDENT_ADDRESS_SPACE`
* `DEPENDENT_BIT_INT`
* `DEPENDENT_NAME`
* `DEPENDENT_SIZED_EXT_VECTOR`
* `DEPENDENT_TEMPLATE_SPECIALIZATION`
* `DEPENDENT_VECTOR`
* `ELABORATED`
* `FUNCTION_NO_PROTO`
* `FUNCTION_PROTO`
* `INJECTED_CLASS_NAME`
* `MACRO_QUALIFIED`
* `CONSTANT_MATRIX`
* `DEPENDENT_SIZED_MATRIX`
* `MEMBER_POINTER`
* `OBJ_C_OBJECT_POINTER`
* `OBJ_C_OBJECT`
* `OBJ_C_INTERFACE`
* `OBJ_C_TYPE_PARAM`
* `PACK_EXPANSION`
* `PAREN`
* `PIPE`
* `POINTER`
* `L_VALUE_REFERENCE`
* `R_VALUE_REFERENCE`
* `SUBST_TEMPLATE_TYPE_PARM_PACK`
* `SUBST_TEMPLATE_TYPE_PARM`
* `ENUM`
* `RECORD`
* `TEMPLATE_SPECIALIZATION`
* `TEMPLATE_TYPE_PARM`
* `TYPE_OF_EXPR`
* `TYPE_OF`
* `TYPEDEF`
* `UNARY_TRANSFORM`
* `UNRESOLVED_USING`
* `USING`
* `VECTOR`
* `EXT_VECTOR`

</details>

<details><summary><a name="TypeTagForDatatypeAttrSpelling"></a>TypeTagForDatatypeAttrSpelling</summary>

Available enumerations:

* `GNU_TYPE_TAG_FOR_DATATYPE`
* `CXX11_CLANG_TYPE_TAG_FOR_DATATYPE`
* `C2_XCLANG_TYPE_TAG_FOR_DATATYPE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="TypeVisibilityAttrSpelling"></a>TypeVisibilityAttrSpelling</summary>

Available enumerations:

* `GNU_TYPE_VISIBILITY`
* `CXX11_CLANG_TYPE_VISIBILITY`
* `C2_XCLANG_TYPE_VISIBILITY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="TypeVisibilityAttrVisibilityType"></a>TypeVisibilityAttrVisibilityType</summary>

Available enumerations:

* `DEFAULT`
* `HIDDEN`
* `PROTECTED`

</details>

<details><summary><a name="UnaryTransformTypeUTTKind"></a>UnaryTransformTypeUTTKind</summary>

Available enumerations:

* `ENUM_UNDERLYING_TYPE`

</details>

<details><summary><a name="UnavailableAttrImplicitReason"></a>UnavailableAttrImplicitReason</summary>

Available enumerations:

* `NONE`
* `ARC_FORBIDDEN_TYPE`
* `FORBIDDEN_WEAK`
* `ARC_FORBIDDEN_CONVERSION`
* `ARC_INIT_RETURNS_UNRELATED`
* `ARC_FIELD_WITH_OWNERSHIP`

</details>

<details><summary><a name="UnavailableAttrSpelling"></a>UnavailableAttrSpelling</summary>

Available enumerations:

* `GNU_UNAVAILABLE`
* `CXX11_CLANG_UNAVAILABLE`
* `C2_XCLANG_UNAVAILABLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="UninitializedAttrSpelling"></a>UninitializedAttrSpelling</summary>

Available enumerations:

* `GNU_UNINITIALIZED`
* `CXX11_CLANG_UNINITIALIZED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="UnlikelyAttrSpelling"></a>UnlikelyAttrSpelling</summary>

Available enumerations:

* `CXX11_UNLIKELY`
* `C2_XCLANG_UNLIKELY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="UnusedAttrSpelling"></a>UnusedAttrSpelling</summary>

Available enumerations:

* `CXX11_MAYBE_UNUSED`
* `GNU_UNUSED`
* `CXX11_GNU_UNUSED`
* `C2_XGNU_UNUSED`
* `C2_XMAYBE_UNUSED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="UseHandleAttrSpelling"></a>UseHandleAttrSpelling</summary>

Available enumerations:

* `GNU_USE_HANDLE`
* `CXX11_CLANG_USE_HANDLE`
* `C2_XCLANG_USE_HANDLE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="UsedAttrSpelling"></a>UsedAttrSpelling</summary>

Available enumerations:

* `GNU_USED`
* `CXX11_GNU_USED`
* `C2_XGNU_USED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="UserDefinedLiteralLiteralOperatorKind"></a>UserDefinedLiteralLiteralOperatorKind</summary>

Available enumerations:

* `RAW`
* `TEMPLATE`
* `INTEGER`
* `FLOATING`
* `STRING`
* `CHARACTER`

</details>

<details><summary><a name="UsingIfExistsAttrSpelling"></a>UsingIfExistsAttrSpelling</summary>

Available enumerations:

* `GNU_USING_IF_EXISTS`
* `CXX11_CLANG_USING_IF_EXISTS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="UuidAttrSpelling"></a>UuidAttrSpelling</summary>

Available enumerations:

* `DECLSPEC_UUID`
* `MICROSOFT_UUID`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="VarDeclDefinitionKind"></a>VarDeclDefinitionKind</summary>

Available enumerations:

* `DECLARATION_ONLY`
* `TENTATIVE_DEFINITION`
* `DEFINITION`

</details>

<details><summary><a name="VarDeclInitializationStyle"></a>VarDeclInitializationStyle</summary>

Available enumerations:

* `C_INIT`
* `CALL_INITIALIZER`
* `LIST_INITIALIZER`

</details>

<details><summary><a name="VarDeclTLSKind"></a>VarDeclTLSKind</summary>

Available enumerations:

* `NONE`
* `STATIC`
* `DYNAMIC`

</details>

<details><summary><a name="VecReturnAttrSpelling"></a>VecReturnAttrSpelling</summary>

Available enumerations:

* `GNU_VECRETURN`
* `CXX11_CLANG_VECRETURN`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="VectorCallAttrSpelling"></a>VectorCallAttrSpelling</summary>

Available enumerations:

* `GNU_VECTORCALL`
* `CXX11_CLANG_VECTORCALL`
* `C2_XCLANG_VECTORCALL`
* `KEYWORD_VECTORCALL`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="VectorTypeVectorKind"></a>VectorTypeVectorKind</summary>

Available enumerations:

* `GENERIC_VECTOR`
* `ALTI_VEC_VECTOR`
* `ALTI_VEC_PIXEL`
* `ALTI_VEC_BOOLEAN`
* `NEON_VECTOR`
* `NEON_POLY_VECTOR`
* `SVE_FIXED_LENGTH_DATA_VECTOR`
* `SVE_FIXED_LENGTH_PREDICATE_VECTOR`

</details>

<details><summary><a name="VisibilityAttrSpelling"></a>VisibilityAttrSpelling</summary>

Available enumerations:

* `GNU_VISIBILITY`
* `CXX11_GNU_VISIBILITY`
* `C2_XGNU_VISIBILITY`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="VisibilityAttrVisibilityType"></a>VisibilityAttrVisibilityType</summary>

Available enumerations:

* `DEFAULT`
* `HIDDEN`
* `PROTECTED`

</details>

<details><summary><a name="WarnUnusedAttrSpelling"></a>WarnUnusedAttrSpelling</summary>

Available enumerations:

* `GNU_WARN_UNUSED`
* `CXX11_GNU_WARN_UNUSED`
* `C2_XGNU_WARN_UNUSED`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="WarnUnusedResultAttrSpelling"></a>WarnUnusedResultAttrSpelling</summary>

Available enumerations:

* `CXX11_NODISCARD`
* `C2_XNODISCARD`
* `CXX11_CLANG_WARN_UNUSED_RESULT`
* `GNU_WARN_UNUSED_RESULT`
* `CXX11_GNU_WARN_UNUSED_RESULT`
* `C2_XGNU_WARN_UNUSED_RESULT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="WeakAttrSpelling"></a>WeakAttrSpelling</summary>

Available enumerations:

* `GNU_WEAK`
* `CXX11_GNU_WEAK`
* `C2_XGNU_WEAK`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="WeakImportAttrSpelling"></a>WeakImportAttrSpelling</summary>

Available enumerations:

* `GNU_WEAK_IMPORT`
* `CXX11_CLANG_WEAK_IMPORT`
* `C2_XCLANG_WEAK_IMPORT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="WeakRefAttrSpelling"></a>WeakRefAttrSpelling</summary>

Available enumerations:

* `GNU_WEAKREF`
* `CXX11_GNU_WEAKREF`
* `C2_XGNU_WEAKREF`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="WebAssemblyExportNameAttrSpelling"></a>WebAssemblyExportNameAttrSpelling</summary>

Available enumerations:

* `GNU_EXPORT_NAME`
* `CXX11_CLANG_EXPORT_NAME`
* `C2_XCLANG_EXPORT_NAME`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="WebAssemblyImportModuleAttrSpelling"></a>WebAssemblyImportModuleAttrSpelling</summary>

Available enumerations:

* `GNU_IMPORT_MODULE`
* `CXX11_CLANG_IMPORT_MODULE`
* `C2_XCLANG_IMPORT_MODULE`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="WebAssemblyImportNameAttrSpelling"></a>WebAssemblyImportNameAttrSpelling</summary>

Available enumerations:

* `GNU_IMPORT_NAME`
* `CXX11_CLANG_IMPORT_NAME`
* `C2_XCLANG_IMPORT_NAME`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="X86ForceAlignArgPointerAttrSpelling"></a>X86ForceAlignArgPointerAttrSpelling</summary>

Available enumerations:

* `GNU_FORCE_ALIGN_ARGUMENT_POINTER`
* `CXX11_GNU_FORCE_ALIGN_ARGUMENT_POINTER`
* `C2_XGNU_FORCE_ALIGN_ARGUMENT_POINTER`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="XRayInstrumentAttrSpelling"></a>XRayInstrumentAttrSpelling</summary>

Available enumerations:

* `GNU_XRAY_ALWAYS_INSTRUMENT`
* `CXX11_CLANG_XRAY_ALWAYS_INSTRUMENT`
* `C2_XCLANG_XRAY_ALWAYS_INSTRUMENT`
* `GNU_XRAY_NEVER_INSTRUMENT`
* `CXX11_CLANG_XRAY_NEVER_INSTRUMENT`
* `C2_XCLANG_XRAY_NEVER_INSTRUMENT`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="XRayLogArgsAttrSpelling"></a>XRayLogArgsAttrSpelling</summary>

Available enumerations:

* `GNU_XRAY_LOG_ARGUMENTS`
* `CXX11_CLANG_XRAY_LOG_ARGUMENTS`
* `C2_XCLANG_XRAY_LOG_ARGUMENTS`
* `SPELLING_NOT_CALCULATED`

</details>

<details><summary><a name="ASTDumpOutputFormat"></a>ASTDumpOutputFormat</summary>

Available enumerations:

* `DEFAULT`
* `JSON`

</details>

<details><summary><a name="AccessSpecifier"></a>AccessSpecifier</summary>

Available enumerations:

* `PUBLIC`
* `PROTECTED`
* `PRIVATE`
* `NONE`

</details>

<details><summary><a name="AddrSpaceMapMangling"></a>AddrSpaceMapMangling</summary>

Available enumerations:

* `TARGET`
* `ON`
* `OFF`

</details>

<details><summary><a name="AlignRequirementKind"></a>AlignRequirementKind</summary>

Available enumerations:

* `NONE`
* `REQUIRED_BY_TYPEDEF`
* `REQUIRED_BY_RECORD`
* `REQUIRED_BY_ENUM`

</details>

<details><summary><a name="AltivecSrcCompatKind"></a>AltivecSrcCompatKind</summary>

Available enumerations:

* `MIXED`
* `GCC`
* `XL`

</details>

<details><summary><a name="ArgumentKind"></a>ArgumentKind</summary>

Available enumerations:

* `STD_STRING`
* `C_STRING`
* `SINT`
* `UINT`
* `TOKENKIND`
* `IDENTIFIERINFO`
* `ADDRSPACE`
* `QUALIFIED`
* `QUALTYPE`
* `DECLARATIONNAME`
* `NAMEDDECL`
* `NESTEDNAMESPEC`
* `DECLCONTEXT`
* `QUALTYPE_PAIR`
* `ATTRIBUTE`

</details>

<details><summary><a name="ArrayTypeTrait"></a>ArrayTypeTrait</summary>

Available enumerations:

* `ARRAY_RANK`
* `ARRAY_EXTENT`

</details>

<details><summary><a name="AtomicScopeModelKind"></a>AtomicScopeModelKind</summary>

Available enumerations:

* `NONE`
* `OPEN_CL`
* `HIP`

</details>

<details><summary><a name="AttrKind"></a>AttrKind</summary>

Available enumerations:

* `ADDRESS_SPACE`
* `ARM_MVE_STRICT_POLYMORPHISM`
* `BTF_TYPE_TAG`
* `CMSE_NS_CALL`
* `NO_DEREF`
* `OBJ_CGC`
* `OBJ_C_INERT_UNSAFE_UNRETAINED`
* `OBJ_C_KIND_OF`
* `OPEN_CL_CONSTANT_ADDRESS_SPACE`
* `OPEN_CL_GENERIC_ADDRESS_SPACE`
* `OPEN_CL_GLOBAL_ADDRESS_SPACE`
* `OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE`
* `OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE`
* `OPEN_CL_LOCAL_ADDRESS_SPACE`
* `OPEN_CL_PRIVATE_ADDRESS_SPACE`
* `PTR32`
* `PTR64`
* `S_PTR`
* `TYPE_NON_NULL`
* `TYPE_NULL_UNSPECIFIED`
* `TYPE_NULLABLE`
* `TYPE_NULLABLE_RESULT`
* `U_PTR`
* `FALL_THROUGH`
* `LIKELY`
* `MUST_TAIL`
* `OPEN_CL_UNROLL_HINT`
* `SUPPRESS`
* `UNLIKELY`
* `NO_MERGE`
* `A_ARCH64_VECTOR_PCS`
* `ACQUIRE_HANDLE`
* `ANY_X86_NO_CF_CHECK`
* `C_DECL`
* `FAST_CALL`
* `INTEL_OCL_BICC`
* `LIFETIME_BOUND`
* `MSABI`
* `NS_RETURNS_RETAINED`
* `OBJ_C_OWNERSHIP`
* `PASCAL`
* `PCS`
* `PRESERVE_ALL`
* `PRESERVE_MOST`
* `REG_CALL`
* `STD_CALL`
* `SWIFT_ASYNC_CALL`
* `SWIFT_CALL`
* `SYS_VABI`
* `THIS_CALL`
* `VECTOR_CALL`
* `SWIFT_ASYNC_CONTEXT`
* `SWIFT_CONTEXT`
* `SWIFT_ERROR_RESULT`
* `SWIFT_INDIRECT_RESULT`
* `ANNOTATE`
* `CF_CONSUMED`
* `CARRIES_DEPENDENCY`
* `NS_CONSUMED`
* `NON_NULL`
* `OS_CONSUMED`
* `PASS_OBJECT_SIZE`
* `RELEASE_HANDLE`
* `USE_HANDLE`
* `AMDGPU_FLAT_WORK_GROUP_SIZE`
* `AMDGPU_NUM_SGPR`
* `AMDGPU_NUM_VGPR`
* `AMDGPU_WAVES_PER_EU`
* `ARM_INTERRUPT`
* `AVR_INTERRUPT`
* `AVR_SIGNAL`
* `ACQUIRE_CAPABILITY`
* `ACQUIRED_AFTER`
* `ACQUIRED_BEFORE`
* `ALIGN_MAC68_K`
* `ALIGN_NATURAL`
* `ALIGNED`
* `ALLOC_ALIGN`
* `ALLOC_SIZE`
* `ALWAYS_DESTROY`
* `ALWAYS_INLINE`
* `ANALYZER_NO_RETURN`
* `ANY_X86_INTERRUPT`
* `ANY_X86_NO_CALLER_SAVED_REGISTERS`
* `ARC_WEAKREF_UNAVAILABLE`
* `ARGUMENT_WITH_TYPE_TAG`
* `ARM_BUILTIN_ALIAS`
* `ARTIFICIAL`
* `ASSEMBLY_LABEL`
* `ASSERT_CAPABILITY`
* `ASSERT_EXCLUSIVE_LOCK`
* `ASSERT_SHARED_LOCK`
* `ASSUME_ALIGNED`
* `ASSUMPTION`
* `AVAILABILITY`
* `BPF_PRESERVE_ACCESS_INDEX`
* `BTF_DECL_TAG`
* `BLOCKS`
* `BUILTIN`
* `C11_NO_RETURN`
* `CF_AUDITED_TRANSFER`
* `CF_GUARD`
* `CFI_CANONICAL_JUMP_TABLE`
* `CF_RETURNS_NOT_RETAINED`
* `CF_RETURNS_RETAINED`
* `CF_UNKNOWN_TRANSFER`
* `CPU_DISPATCH`
* `CPU_SPECIFIC`
* `CUDA_CONSTANT`
* `CUDA_DEVICE`
* `CUDA_DEVICE_BUILTIN_SURFACE_TYPE`
* `CUDA_DEVICE_BUILTIN_TEXTURE_TYPE`
* `CUDA_GLOBAL`
* `CUDA_HOST`
* `CUDA_INVALID_TARGET`
* `CUDA_LAUNCH_BOUNDS`
* `CUDA_SHARED`
* `CXX11_NO_RETURN`
* `CALLABLE_WHEN`
* `CALLBACK`
* `CAPABILITY`
* `CAPTURED_RECORD`
* `CLEANUP`
* `CMSE_NS_ENTRY`
* `CODE_SEG`
* `COLD`
* `COMMON`
* `CONST`
* `CONST_INITIALIZER`
* `CONSTRUCTOR`
* `CONSUMABLE`
* `CONSUMABLE_AUTO_CAST`
* `CONSUMABLE_SET_ON_READ`
* `CONVERGENT`
* `DLL_EXPORT`
* `DLL_EXPORT_STATIC_LOCAL`
* `DLL_IMPORT`
* `DLL_IMPORT_STATIC_LOCAL`
* `DEPRECATED`
* `DESTRUCTOR`
* `DIAGNOSE_AS_BUILTIN`
* `DIAGNOSE_IF`
* `DISABLE_SANITIZER_INSTRUMENTATION`
* `DISABLE_TAIL_CALLS`
* `EMPTY_BASES`
* `ENABLE_IF`
* `ENFORCE_TCB`
* `ENFORCE_TCB_LEAF`
* `ENUM_EXTENSIBILITY`
* `ERROR`
* `EXCLUDE_FROM_EXPLICIT_INSTANTIATION`
* `EXCLUSIVE_TRYLOCK_FUNCTION`
* `EXTERNAL_SOURCE_SYMBOL`
* `FINAL`
* `FLAG_ENUM`
* `FLATTEN`
* `FORMAT`
* `FORMAT_ARGUMENT`
* `GNU_INLINE`
* `GUARDED_BY`
* `GUARDED_VARIABLE`
* `HIP_MANAGED`
* `HOT`
* `IB_ACTION`
* `IB_OUTLET`
* `IB_OUTLET_COLLECTION`
* `INITIALIZER_PRIORITY`
* `INTERNAL_LINKAGE`
* `LTO_VISIBILITY_PUBLIC`
* `LAYOUT_VERSION`
* `LEAF`
* `LOCK_RETURNED`
* `LOCKS_EXCLUDED`
* `M68_KINTERRUPT`
* `MIG_SERVER_ROUTINE`
* `MS_ALLOCATOR`
* `MS_INHERITANCE`
* `MS_NO_V_TABLE`
* `MSP430_INTERRUPT`
* `MS_STRUCT`
* `MS_VTOR_DISP`
* `MAX_FIELD_ALIGNMENT`
* `MAY_ALIAS`
* `MICRO_MIPS`
* `MIN_SIZE`
* `MIN_VECTOR_WIDTH`
* `MIPS16`
* `MIPS_INTERRUPT`
* `MIPS_LONG_CALL`
* `MIPS_SHORT_CALL`
* `NS_CONSUMES_SELF`
* `NS_ERROR_DOMAIN`
* `NS_RETURNS_AUTORELEASED`
* `NS_RETURNS_NOT_RETAINED`
* `NAKED`
* `NO_ALIAS`
* `NO_COMMON`
* `NO_DEBUG`
* `NO_DESTROY`
* `NO_DUPLICATE`
* `NO_INLINE`
* `NO_INSTRUMENT_FUNCTION`
* `NO_MICRO_MIPS`
* `NO_MIPS16`
* `NO_PROFILE_FUNCTION`
* `NO_RETURN`
* `NO_SANITIZE`
* `NO_SPECULATIVE_LOAD_HARDENING`
* `NO_SPLIT_STACK`
* `NO_STACK_PROTECTOR`
* `NO_THREAD_SAFETY_ANALYSIS`
* `NO_THROW`
* `NO_UNIQUE_ADDRESS`
* `NOT_TAIL_CALLED`
* `OMP_ALLOCATE_DECLARATION`
* `OMP_CAPTURE_NO_INITIALIZER`
* `OMP_DECLARE_TARGET_DECLARATION`
* `OMP_DECLARE_VARIANT`
* `OMP_THREAD_PRIVATE_DECLARATION`
* `OS_CONSUMES_THIS`
* `OS_RETURNS_NOT_RETAINED`
* `OS_RETURNS_RETAINED`
* `OS_RETURNS_RETAINED_ON_NON_ZERO`
* `OS_RETURNS_RETAINED_ON_ZERO`
* `OBJ_C_BRIDGE`
* `OBJ_C_BRIDGE_MUTABLE`
* `OBJ_C_BRIDGE_RELATED`
* `OBJ_C_EXCEPTION`
* `OBJ_C_EXPLICIT_PROTOCOL_IMPLEMENTATION`
* `OBJ_C_EXTERNALLY_RETAINED`
* `OBJ_C_INDEPENDENT_CLASS`
* `OBJ_C_METHOD_FAMILY`
* `OBJ_CNS_OBJECT`
* `OBJ_C_PRECISE_LIFETIME`
* `OBJ_C_REQUIRES_PROPERTY_DEFINITIONS`
* `OBJ_C_REQUIRES_SUPER`
* `OBJ_C_RETURNS_INNER_POINTER`
* `OBJ_C_ROOT_CLASS`
* `OBJ_C_SUBCLASSING_RESTRICTED`
* `OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE`
* `OPEN_CL_KERNEL`
* `OPTIMIZE_NONE`
* `OVERRIDE`
* `OWNER`
* `OWNERSHIP`
* `PACKED`
* `PARAMETER_TYPESTATE`
* `PATCHABLE_FUNCTION_ENTRY`
* `POINTER`
* `PRAGMA_CLANG_BSS_SECTION`
* `PRAGMA_CLANG_DATA_SECTION`
* `PRAGMA_CLANG_RELRO_SECTION`
* `PRAGMA_CLANG_RODATA_SECTION`
* `PRAGMA_CLANG_TEXT_SECTION`
* `PREFERRED_NAME`
* `PT_GUARDED_BY`
* `PT_GUARDED_VARIABLE`
* `PURE`
* `RISCV_INTERRUPT`
* `REINITIALIZES`
* `RELEASE_CAPABILITY`
* `REQD_WORK_GROUP_SIZE`
* `REQUIRES_CAPABILITY`
* `RESTRICT`
* `RETAIN`
* `RETURN_TYPESTATE`
* `RETURNS_NON_NULL`
* `RETURNS_TWICE`
* `SYCL_KERNEL`
* `SYCL_SPECIAL_CLASS`
* `SCOPED_LOCKABLE`
* `SECTION`
* `SELECT_ANY`
* `SENTINEL`
* `SET_TYPESTATE`
* `SHARED_TRYLOCK_FUNCTION`
* `SPECULATIVE_LOAD_HARDENING`
* `STANDALONE_DEBUG`
* `STRICT_FP`
* `SWIFT_ASYNC`
* `SWIFT_ASYNC_ERROR`
* `SWIFT_ASYNC_NAME`
* `SWIFT_ATTRIBUTE`
* `SWIFT_BRIDGE`
* `SWIFT_BRIDGED_TYPEDEF`
* `SWIFT_ERROR`
* `SWIFT_NAME`
* `SWIFT_NEW_TYPE`
* `SWIFT_PRIVATE`
* `TLS_MODEL`
* `TARGET`
* `TARGET_CLONES`
* `TEST_TYPESTATE`
* `TRANSPARENT_UNION`
* `TRIVIAL_ABI`
* `TRY_ACQUIRE_CAPABILITY`
* `TYPE_TAG_FOR_DATATYPE`
* `TYPE_VISIBILITY`
* `UNAVAILABLE`
* `UNINITIALIZED`
* `UNUSED`
* `USED`
* `USING_IF_EXISTS`
* `UUID`
* `VEC_RETURN`
* `VEC_TYPE_HINT`
* `VISIBILITY`
* `WARN_UNUSED`
* `WARN_UNUSED_RESULT`
* `WEAK`
* `WEAK_IMPORT`
* `WEAK_REFERENCE`
* `WEB_ASSEMBLY_EXPORT_NAME`
* `WEB_ASSEMBLY_IMPORT_MODULE`
* `WEB_ASSEMBLY_IMPORT_NAME`
* `WORK_GROUP_SIZE_HINT`
* `X86_FORCE_ALIGN_ARGUMENT_POINTER`
* `X_RAY_INSTRUMENT`
* `X_RAY_LOG_ARGUMENTS`
* `ABI_TAG`
* `ALIAS`
* `ALIGN_VALUE`
* `BUILTIN_ALIAS`
* `CALLED_ONCE`
* `I_FUNC`
* `INITIALIZER_SEG`
* `LOADER_UNINITIALIZED`
* `LOOP_HINT`
* `MODE`
* `NO_BUILTIN`
* `NO_ESCAPE`
* `OMP_CAPTURE_KIND`
* `OMP_DECLARE_SIMD_DECLARATION`
* `OMP_REFERENCED_VARIABLE`
* `OBJ_C_BOXABLE`
* `OBJ_C_CLASS_STUB`
* `OBJ_C_DESIGNATED_INITIALIZER`
* `OBJ_C_DIRECT`
* `OBJ_C_DIRECT_MEMBERS`
* `OBJ_C_NON_LAZY_CLASS`
* `OBJ_C_NON_RUNTIME_PROTOCOL`
* `OBJ_C_RUNTIME_NAME`
* `OBJ_C_RUNTIME_VISIBLE`
* `OPEN_CL_ACCESS`
* `OVERLOADABLE`
* `RENDER_SCRIPT_KERNEL`
* `SWIFT_OBJ_C_MEMBERS`
* `THREAD`

</details>

<details><summary><a name="AutoTypeKeyword"></a>AutoTypeKeyword</summary>

Available enumerations:

* `AUTO`
* `DECLTYPE_AUTO`
* `GNU_AUTO_TYPE`

</details>

<details><summary><a name="AvailabilityResult"></a>AvailabilityResult</summary>

Available enumerations:

* `AVAILABLE`
* `NOT_YET_INTRODUCED`
* `DEPRECATED`
* `UNAVAILABLE`

</details>

<details><summary><a name="BinaryOperatorKind"></a>BinaryOperatorKind</summary>

Available enumerations:

* `POINTER_MEMORY_D`
* `POINTER_MEMORY_I`
* `MUL`
* `DIV`
* `REM`
* `ADD`
* `SUB`
* `SHL`
* `SHR`
* `CMP`
* `LT`
* `GT`
* `LE`
* `GE`
* `EQ`
* `NE`
* `AND`
* `XOR`
* `OR`
* `L_AND`
* `L_OR`
* `ASSIGN`
* `MUL_ASSIGN`
* `DIV_ASSIGN`
* `REM_ASSIGN`
* `ADD_ASSIGN`
* `SUB_ASSIGN`
* `SHL_ASSIGN`
* `SHR_ASSIGN`
* `AND_ASSIGN`
* `XOR_ASSIGN`
* `OR_ASSIGN`
* `COMMA`

</details>

<details><summary><a name="Bits"></a>Bits</summary>

Available enumerations:

* `NONE`
* `UNEXPANDED_PACK`
* `INSTANTIATION`
* `TYPE`
* `VALUE`
* `DEPENDENT`
* `ERROR`
* `VARIABLY_MODIFIED`
* `SYNTACTIC`

</details>

<details><summary><a name="CallingConv"></a>CallingConv</summary>

Available enumerations:

* `C`
* `X86_STD_CALL`
* `X86_FAST_CALL`
* `X86_THIS_CALL`
* `X86_VECTOR_CALL`
* `X86_PASCAL`
* `WIN64`
* `X8664_SYS_V`
* `X86_REG_CALL`
* `AAPCS`
* `AAPCSVFP`
* `INTEL_OCL_BICC`
* `SPIR_FUNCTION`
* `OPEN_CL_KERNEL`
* `SWIFT`
* `SWIFT_ASYNC`
* `PRESERVE_MOST`
* `PRESERVE_ALL`
* `A_ARCH64_VECTOR_CALL`

</details>

<details><summary><a name="CanThrowResult"></a>CanThrowResult</summary>

Available enumerations:

* `CANNOT`
* `DEPENDENT`
* `CAN`

</details>

<details><summary><a name="CapturedRegionKind"></a>CapturedRegionKind</summary>

Available enumerations:

* `DEFAULT`
* `OBJ_C_AT_FINALLY`
* `OPEN_MP`

</details>

<details><summary><a name="CastKind"></a>CastKind</summary>

Available enumerations:

* `DEPENDENT`
* `BIT_CAST`
* `L_VALUE_BIT_CAST`
* `L_VALUE_TO_R_VALUE_BIT_CAST`
* `L_VALUE_TO_R_VALUE`
* `NO_OPERATION`
* `BASE_TO_DERIVED`
* `DERIVED_TO_BASE`
* `UNCHECKED_DERIVED_TO_BASE`
* `DYNAMIC`
* `TO_UNION`
* `ARRAY_TO_POINTER_DECAY`
* `FUNCTION_TO_POINTER_DECAY`
* `NULL_TO_POINTER`
* `NULL_TO_MEMBER_POINTER`
* `BASE_TO_DERIVED_MEMBER_POINTER`
* `DERIVED_TO_BASE_MEMBER_POINTER`
* `MEMBER_POINTER_TO_BOOLEAN`
* `REINTERPRET_MEMBER_POINTER`
* `USER_DEFINED_CONVERSION`
* `CONSTRUCTOR_CONVERSION`
* `INTEGRAL_TO_POINTER`
* `POINTER_TO_INTEGRAL`
* `POINTER_TO_BOOLEAN`
* `TO_VOID`
* `MATRIX_CAST`
* `VECTOR_SPLAT`
* `INTEGRAL_CAST`
* `INTEGRAL_TO_BOOLEAN`
* `INTEGRAL_TO_FLOATING`
* `FLOATING_TO_FIXED_POINT`
* `FIXED_POINT_TO_FLOATING`
* `FIXED_POINT_CAST`
* `FIXED_POINT_TO_INTEGRAL`
* `INTEGRAL_TO_FIXED_POINT`
* `FIXED_POINT_TO_BOOLEAN`
* `FLOATING_TO_INTEGRAL`
* `FLOATING_TO_BOOLEAN`
* `BOOLEAN_TO_SIGNED_INTEGRAL`
* `FLOATING_CAST`
* `C_POINTER_TO_OBJ_C_POINTER_CAST`
* `BLOCK_POINTER_TO_OBJ_C_POINTER_CAST`
* `ANY_POINTER_TO_BLOCK_POINTER_CAST`
* `OBJ_C_OBJECT_L_VALUE_CAST`
* `FLOATING_REAL_TO_COMPLEX`
* `FLOATING_COMPLEX_TO_REAL`
* `FLOATING_COMPLEX_TO_BOOLEAN`
* `FLOATING_COMPLEX_CAST`
* `FLOATING_COMPLEX_TO_INTEGRAL_COMPLEX`
* `INTEGRAL_REAL_TO_COMPLEX`
* `INTEGRAL_COMPLEX_TO_REAL`
* `INTEGRAL_COMPLEX_TO_BOOLEAN`
* `INTEGRAL_COMPLEX_CAST`
* `INTEGRAL_COMPLEX_TO_FLOATING_COMPLEX`
* `ARC_PRODUCE_OBJECT`
* `ARC_CONSUME_OBJECT`
* `ARC_RECLAIM_RETURNED_OBJECT`
* `ARC_EXTEND_BLOCK_OBJECT`
* `ATOMIC_TO_NON_ATOMIC`
* `NON_ATOMIC_TO_ATOMIC`
* `COPY_AND_AUTORELEASE_BLOCK_OBJECT`
* `BUILTIN_FN_TO_FN_POINTER`
* `ZERO_TO_OCL_OPAQUE_TYPE`
* `ADDRESS_SPACE_CONVERSION`
* `INT_TO_OCL_SAMPLER`

</details>

<details><summary><a name="ClangABI"></a>ClangABI</summary>

Available enumerations:

* `VER38`
* `VER4`
* `VER6`
* `VER7`
* `VER9`
* `VER11`
* `VER12`
* `LATEST`

</details>

<details><summary><a name="CommentKind"></a>CommentKind</summary>

Available enumerations:

* `INVALID`
* `ORDINARY_BCPL`
* `ORDINARY_C`
* `BCPL_SLASH`
* `BCPL_EXCL`
* `JAVA_DOC`
* `QT`
* `MERGED`

</details>

<details><summary><a name="ComparisonCategoryResult"></a>ComparisonCategoryResult</summary>

Available enumerations:

* `EQUAL`
* `EQUIVALENT`
* `LESS`
* `GREATER`
* `UNORDERED`

</details>

<details><summary><a name="ComparisonCategoryType"></a>ComparisonCategoryType</summary>

Available enumerations:

* `PARTIAL_ORDERING`
* `WEAK_ORDERING`
* `STRONG_ORDERING`

</details>

<details><summary><a name="CompilingModuleKind"></a>CompilingModuleKind</summary>

Available enumerations:

* `NONE`
* `MODULE_MAP`
* `HEADER_MODULE`
* `MODULE_INTERFACE`

</details>

<details><summary><a name="ConstexprSpecKind"></a>ConstexprSpecKind</summary>

Available enumerations:

* `UNSPECIFIED`
* `CONSTEXPR`
* `CONSTEVAL`
* `CONSTINIT`

</details>

<details><summary><a name="CoreFoundationABI"></a>CoreFoundationABI</summary>

Available enumerations:

* `UNSPECIFIED`
* `STANDALONE`
* `OBJECTIVE_C`
* `SWIFT`
* `SWIFT50`
* `SWIFT42`
* `SWIFT41`

</details>

<details><summary><a name="DataPositionTy"></a>DataPositionTy</summary>

Available enumerations:

* `POSX`
* `POSV`
* `POSE`
* `POS_UPDATE_EXPRESSION`

</details>

<details><summary><a name="DefaultArgKind"></a>DefaultArgKind</summary>

Available enumerations:

* `NONE`
* `UNPARSED`
* `UNINSTANTIATED`
* `NORMAL`

</details>

<details><summary><a name="DefaultCallingConvention"></a>DefaultCallingConvention</summary>

Available enumerations:

* `NONE`
* `C_DECL`
* `FAST_CALL`
* `STD_CALL`
* `VECTOR_CALL`
* `REG_CALL`

</details>

<details><summary><a name="DiagnosticLevelMask"></a>DiagnosticLevelMask</summary>

Available enumerations:

* `NONE`
* `NOTE`
* `REMARK`
* `WARNING`
* `ERROR`
* `ALL`

</details>

<details><summary><a name="ElaboratedTypeKeyword"></a>ElaboratedTypeKeyword</summary>

Available enumerations:

* `STRUCT`
* `INTERFACE`
* `UNION`
* `CLASS`
* `ENUM`
* `TYPENAME`
* `NONE`

</details>

<details><summary><a name="EmbedBitcodeKind"></a>EmbedBitcodeKind</summary>

Available enumerations:

* `EMBED_OFF`
* `EMBED_ALL`
* `EMBED_BITCODE`
* `EMBED_MARKER`

</details>

<details><summary><a name="ExceptionHandlingKind"></a>ExceptionHandlingKind</summary>

Available enumerations:

* `NONE`
* `SJ_LJ`
* `WIN_EH`
* `DWARF_CFI`
* `WASM`

</details>

<details><summary><a name="ExceptionSpecificationType"></a>ExceptionSpecificationType</summary>

Available enumerations:

* `NONE`
* `DYNAMIC_NONE`
* `DYNAMIC`
* `MS_ANY`
* `NO_THROW`
* `BASIC_NOEXCEPT`
* `DEPENDENT_NOEXCEPT`
* `NOEXCEPT_FALSE`
* `NOEXCEPT_TRUE`
* `UNEVALUATED`
* `UNINSTANTIATED`
* `UNPARSED`

</details>

<details><summary><a name="ExplicitSpecKind"></a>ExplicitSpecKind</summary>

Available enumerations:

* `RESOLVED_FALSE`
* `RESOLVED_TRUE`
* `UNRESOLVED`

</details>

<details><summary><a name="ExprDependence"></a>ExprDependence</summary>

Available enumerations:

* `UNEXPANDED_PACK`
* `INSTANTIATION`
* `TYPE`
* `VALUE`
* `ERROR`
* `NONE`
* `ALL`
* `TYPE_VALUE`
* `TYPE_INSTANTIATION`
* `VALUE_INSTANTIATION`
* `TYPE_VALUE_INSTANTIATION`
* `ERROR_DEPENDENT`

</details>

<details><summary><a name="ExprObjectKind"></a>ExprObjectKind</summary>

Available enumerations:

* `ORDINARY`
* `BIT_FIELD`
* `VECTOR_COMPONENT`
* `OBJ_C_PROPERTY`
* `OBJ_C_SUBSCRIPT`
* `MATRIX_COMPONENT`

</details>

<details><summary><a name="ExprOffsets"></a>ExprOffsets</summary>

Available enumerations:

* `ALLOCATOR`
* `ALLOCATOR_TRAITS`
* `TOTAL`

</details>

<details><summary><a name="ExprValueKind"></a>ExprValueKind</summary>

Available enumerations:

* `PR_VALUE`
* `L_VALUE`
* `X_VALUE`

</details>

<details><summary><a name="ExpressionTrait"></a>ExpressionTrait</summary>

Available enumerations:

* `IS_L_VALUE_EXPRESSION`
* `IS_R_VALUE_EXPRESSION`

</details>

<details><summary><a name="ExtKind"></a>ExtKind</summary>

Available enumerations:

* `ALWAYS`
* `NEVER`
* `REPLY_HAZY`

</details>

<details><summary><a name="ExtendArgsKind"></a>ExtendArgsKind</summary>

Available enumerations:

* `EXTEND_TO32`
* `EXTEND_TO64`

</details>

<details><summary><a name="FPExceptionModeKind"></a>FPExceptionModeKind</summary>

Available enumerations:

* `IGNORE`
* `MAY_TRAP`
* `STRICT`

</details>

<details><summary><a name="FPModeKind"></a>FPModeKind</summary>

Available enumerations:

* `OFF`
* `ON`
* `FAST`
* `FAST_HONOR_PRAGMAS`

</details>

<details><summary><a name="FiniteLoopsKind"></a>FiniteLoopsKind</summary>

Available enumerations:

* `LANGUAGE`
* `ALWAYS`
* `NEVER`

</details>

<details><summary><a name="FramePointerKind"></a>FramePointerKind</summary>

Available enumerations:

* `NONE`
* `NON_LEAF`
* `ALL`

</details>

<details><summary><a name="GC"></a>GC</summary>

Available enumerations:

* `GC_NONE`
* `WEAK`
* `STRONG`

</details>

<details><summary><a name="GCMode"></a>GCMode</summary>

Available enumerations:

* `NON_GC`
* `GC_ONLY`
* `HYBRID_GC`

</details>

<details><summary><a name="GVALinkage"></a>GVALinkage</summary>

Available enumerations:

* `INTERNAL`
* `AVAILABLE_EXTERNALLY`
* `DISCARDABLE_ODR`
* `STRONG_EXTERNAL`
* `STRONG_ODR`

</details>

<details><summary><a name="GetBuiltinTypeError"></a>GetBuiltinTypeError</summary>

Available enumerations:

* `NONE`
* `MISSING_TYPE`
* `MISSING_STDIO`
* `MISSING`
* `MISSING_UCONTEXT`

</details>

<details><summary><a name="ID"></a>ID</summary>

Available enumerations:

* `WORK_GROUP`
* `DEVICE`
* `ALL_SVM_DEVICES`
* `SUB_GROUP`

</details>

<details><summary><a name="IdentifierInfoFlag"></a>IdentifierInfoFlag</summary>

Available enumerations:

* `ZERO_ARGUMENT`
* `ONE_ARGUMENT`
* `MULTI_ARGUMENT`

</details>

<details><summary><a name="IfStatementKind"></a>IfStatementKind</summary>

Available enumerations:

* `ORDINARY`
* `CONSTEXPR`
* `CONSTEVAL_NON_NEGATED`
* `CONSTEVAL_NEGATED`

</details>

<details><summary><a name="ImbueAttribute"></a>ImbueAttribute</summary>

Available enumerations:

* `NONE`
* `ALWAYS`
* `NEVER`
* `ALWAYSARG1`

</details>

<details><summary><a name="InClassInitStyle"></a>InClassInitStyle</summary>

Available enumerations:

* `NO_INITIALIZER`
* `COPY_INITIALIZER`
* `LIST_INITIALIZER`

</details>

<details><summary><a name="InheritedDesignatedInitializersState"></a>InheritedDesignatedInitializersState</summary>

Available enumerations:

* `UNKNOWN`
* `INHERITED`
* `NOT_INHERITED`

</details>

<details><summary><a name="InitStorageKind"></a>InitStorageKind</summary>

Available enumerations:

* `NO_INITIALIZER`
* `IN_CLASS_COPY_INITIALIZER`
* `IN_CLASS_LIST_INITIALIZER`
* `CAPTURED_VLA_TYPE`

</details>

<details><summary><a name="InlineAsmDialectKind"></a>InlineAsmDialectKind</summary>

Available enumerations:

* `IADATT`
* `IAD_INTEL`

</details>

<details><summary><a name="InlineVariableDefinitionKind"></a>InlineVariableDefinitionKind</summary>

Available enumerations:

* `NONE`
* `WEAK`
* `WEAK_UNKNOWN`
* `STRONG`

</details>

<details><summary><a name="InliningMethod"></a>InliningMethod</summary>

Available enumerations:

* `NORMAL_INLINING`
* `ONLY_HINT_INLINING`
* `ONLY_ALWAYS_INLINING`

</details>

<details><summary><a name="Kinds"></a>Kinds</summary>

Available enumerations:

* `L_VALUE`
* `X_VALUE`
* `FUNCTION`
* `VOID`
* `ADDRESSABLE_VOID`
* `DUPLICATE_VECTOR_COMPONENTS`
* `MEMBER_FUNCTION`
* `SUB_OBJ_C_PROPERTY_SETTING`
* `CLASS_TEMPORARY`
* `ARRAY_TEMPORARY`
* `OBJ_C_MESSAGE_R_VALUE`
* `PR_VALUE`

</details>

<details><summary><a name="LambdaCaptureDefault"></a>LambdaCaptureDefault</summary>

Available enumerations:

* `NONE`
* `BY_COPY`
* `BY_REFERENCE`

</details>

<details><summary><a name="LambdaCaptureKind"></a>LambdaCaptureKind</summary>

Available enumerations:

* `THIS`
* `STAR_THIS`
* `BY_COPY`
* `BY_REFERENCE`
* `VLA_TYPE`

</details>

<details><summary><a name="LangAS"></a>LangAS</summary>

Available enumerations:

* `DEFAULT`
* `OPENCL_GLOBAL`
* `OPENCL_LOCAL`
* `OPENCL_CONSTANT`
* `OPENCL_PRIVATE`
* `OPENCL_GENERIC`
* `OPENCL_GLOBAL_DEVICE`
* `OPENCL_GLOBAL_HOST`
* `CUDA_DEVICE`
* `CUDA_CONSTANT`
* `CUDA_SHARED`
* `SYCL_GLOBAL`
* `SYCL_GLOBAL_DEVICE`
* `SYCL_GLOBAL_HOST`
* `SYCL_LOCAL`
* `SYCL_PRIVATE`
* `PTR32_SPTR`
* `PTR32_UPTR`
* `PTR64`

</details>

<details><summary><a name="LangFeatures"></a>LangFeatures</summary>

Available enumerations:

* `LINE_COMMENT`
* `C99`
* `C11`
* `C17`
* `C2_X`
* `C_PLUS_PLUS`
* `C_PLUS_PLUS11`
* `C_PLUS_PLUS14`
* `C_PLUS_PLUS17`
* `C_PLUS_PLUS20`
* `C_PLUS_PLUS2_B`
* `DIGRAPHS`
* `GNU_MODE`
* `HEX_FLOAT`
* `IMPLICIT_INT`
* `OPEN_CL`

</details>

<details><summary><a name="Language"></a>Language</summary>

Available enumerations:

* `UNKNOWN`
* `ASSEMBLY`
* `LLVMIR`
* `C`
* `CXX`
* `OBJ_C`
* `OBJ_CXX`
* `OPEN_CL`
* `OPEN_CLCXX`
* `CUDA`
* `RENDER_SCRIPT`
* `HIP`

</details>

<details><summary><a name="LanguageLinkage"></a>LanguageLinkage</summary>

Available enumerations:

* `C_LANGUAGE_LINKAGE`
* `CXX_LANGUAGE_LINKAGE`
* `NO_LANGUAGE_LINKAGE`

</details>

<details><summary><a name="LaxVectorConversionKind"></a>LaxVectorConversionKind</summary>

Available enumerations:

* `NONE`
* `INTEGER`
* `ALL`

</details>

<details><summary><a name="Level"></a>Level</summary>

Available enumerations:

* `IGNORED`
* `NOTE`
* `REMARK`
* `WARNING`
* `ERROR`
* `FATAL`

</details>

<details><summary><a name="Linkage"></a>Linkage</summary>

Available enumerations:

* `NO_LINKAGE`
* `INTERNAL_LINKAGE`
* `UNIQUE_EXTERNAL_LINKAGE`
* `VISIBLE_NO_LINKAGE`
* `MODULE_INTERNAL_LINKAGE`
* `MODULE_LINKAGE`
* `EXTERNAL_LINKAGE`

</details>

<details><summary><a name="MSInheritanceModel"></a>MSInheritanceModel</summary>

Available enumerations:

* `SINGLE`
* `MULTIPLE`
* `VIRTUAL`
* `UNSPECIFIED`

</details>

<details><summary><a name="MSVCMajorVersion"></a>MSVCMajorVersion</summary>

Available enumerations:

* `MSVC2010`
* `MSVC2012`
* `MSVC2013`
* `MSVC2015`
* `MSVC2017`
* `MSVC20175`
* `MSVC20177`
* `MSVC2019`
* `MSVC20195`
* `MSVC20198`

</details>

<details><summary><a name="MSVtorDispMode"></a>MSVtorDispMode</summary>

Available enumerations:

* `NEVER`
* `FOR_VIRTUAL_BASE_OVERRIDE`
* `FOR_VF_TABLE`

</details>

<details><summary><a name="MethodRefFlags"></a>MethodRefFlags</summary>

Available enumerations:

* `METHOD_REFERENCE_NONE`
* `METHOD_REFERENCE_GETTER`
* `METHOD_REFERENCE_SETTER`

</details>

<details><summary><a name="ModifiableType"></a>ModifiableType</summary>

Available enumerations:

* `UNTESTED`
* `MODIFIABLE`
* `R_VALUE`
* `FUNCTION`
* `L_VALUE_CAST`
* `NO_SETTER_PROPERTY`
* `CONST_QUALIFIED`
* `CONST_QUALIFIED_FIELD`
* `CONST_ADDR_SPACE`
* `ARRAY_TYPE`
* `INCOMPLETE_TYPE`

</details>

<details><summary><a name="MultiVersionKind"></a>MultiVersionKind</summary>

Available enumerations:

* `NONE`
* `TARGET`
* `CPU_SPECIFIC`
* `CPU_DISPATCH`
* `TARGET_CLONES`

</details>

<details><summary><a name="NameKind"></a>NameKind</summary>

Available enumerations:

* `TEMPLATE`
* `OVERLOADED_TEMPLATE`
* `ASSUMED_TEMPLATE`
* `QUALIFIED_TEMPLATE`
* `DEPENDENT_TEMPLATE`
* `SUBST_TEMPLATE_TEMPLATE_PARM`
* `SUBST_TEMPLATE_TEMPLATE_PARM_PACK`

</details>

<details><summary><a name="NeedExtraManglingDecl"></a>NeedExtraManglingDecl</summary>

Available enumerations:

* `NEED_EXTRA_MANGLING_DECLARATION`

</details>

<details><summary><a name="NestedNameSpecifierDependence"></a>NestedNameSpecifierDependence</summary>

Available enumerations:

* `UNEXPANDED_PACK`
* `INSTANTIATION`
* `DEPENDENT`
* `ERROR`
* `NONE`
* `DEPENDENT_INSTANTIATION`
* `ALL`

</details>

<details><summary><a name="NonOdrUseReason"></a>NonOdrUseReason</summary>

Available enumerations:

* `NONE`
* `UNEVALUATED`
* `CONSTANT`
* `DISCARDED`

</details>

<details><summary><a name="NonceObjCInterface"></a>NonceObjCInterface</summary>

Available enumerations:

* `OBJ_C_INTERFACE`

</details>

<details><summary><a name="NullabilityKind"></a>NullabilityKind</summary>

Available enumerations:

* `NON_NULL`
* `NULLABLE`
* `UNSPECIFIED`
* `NULLABLE_RESULT`

</details>

<details><summary><a name="ObjCBridgeCastKind"></a>ObjCBridgeCastKind</summary>

Available enumerations:

* `BRIDGE`
* `BRIDGE_TRANSFER`
* `BRIDGE_RETAINED`

</details>

<details><summary><a name="ObjCDispatchMethodKind"></a>ObjCDispatchMethodKind</summary>

Available enumerations:

* `LEGACY`
* `NON_LEGACY`
* `MIXED`

</details>

<details><summary><a name="ObjCInstanceTypeFamily"></a>ObjCInstanceTypeFamily</summary>

Available enumerations:

* `NONE`
* `ARRAY`
* `DICTIONARY`
* `SINGLETON`
* `INITIALIZER`
* `RETURNS_SELF`

</details>

<details><summary><a name="ObjCLifetime"></a>ObjCLifetime</summary>

Available enumerations:

* `NONE`
* `EXPLICIT_NONE`
* `STRONG`
* `WEAK`
* `AUTORELEASING`

</details>

<details><summary><a name="ObjCMethodFamily"></a>ObjCMethodFamily</summary>

Available enumerations:

* `NONE`
* `ALLOC`
* `COPY`
* `INITIALIZER`
* `MUTABLE_COPY`
* `NEW`
* `AUTORELEASE`
* `DEALLOC`
* `FINALIZE`
* `RELEASE`
* `RETAIN`
* `RETAIN_COUNT`
* `SELF`
* `INITIALIZE`
* `PERFORM_SELECTOR`

</details>

<details><summary><a name="ObjCPropertyQueryKind"></a>ObjCPropertyQueryKind</summary>

Available enumerations:

* `QUERY_UNKNOWN`
* `QUERY_INSTANCE`
* `QUERY_CLASS`

</details>

<details><summary><a name="ObjCStringFormatFamily"></a>ObjCStringFormatFamily</summary>

Available enumerations:

* `NONE`
* `NS_STRING`
* `CF_STRING`

</details>

<details><summary><a name="ObjCSubstitutionContext"></a>ObjCSubstitutionContext</summary>

Available enumerations:

* `ORDINARY`
* `RESULT`
* `PARAMETER`
* `PROPERTY`
* `SUPERCLASS`

</details>

<details><summary><a name="ObjCTypeParamVariance"></a>ObjCTypeParamVariance</summary>

Available enumerations:

* `INVARIANT`
* `COVARIANT`
* `CONTRAVARIANT`

</details>

<details><summary><a name="OnOffSwitch"></a>OnOffSwitch</summary>

Available enumerations:

* `ON`
* `OFF`
* `DEFAULT`

</details>

<details><summary><a name="OnStackType"></a>OnStackType</summary>

Available enumerations:

* `ON_STACK`

</details>

<details><summary><a name="OpenMPAdjustArgsOpKind"></a>OpenMPAdjustArgsOpKind</summary>

Available enumerations:

* `ADJUSTARGS_NOTHING`
* `ADJUSTARGS_NEED_DEVICE_POINTER`
* `ADJUSTARGS_UNKNOWN`

</details>

<details><summary><a name="OpenMPAtomicDefaultMemOrderClauseKind"></a>OpenMPAtomicDefaultMemOrderClauseKind</summary>

Available enumerations:

* `SEQ_CST`
* `ACQ_REL`
* `RELAXED`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPBindClauseKind"></a>OpenMPBindClauseKind</summary>

Available enumerations:

* `BIND_TEAMS`
* `BIND_PARALLEL`
* `BIND_THREAD`
* `BIND_UNKNOWN`

</details>

<details><summary><a name="OpenMPDefaultmapClauseKind"></a>OpenMPDefaultmapClauseKind</summary>

Available enumerations:

* `SCALAR`
* `AGGREGATE`
* `POINTER`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPDefaultmapClauseModifier"></a>OpenMPDefaultmapClauseModifier</summary>

Available enumerations:

* `UNKNOWN`
* `ALLOC`
* `TO`
* `FROM`
* `TOFROM`
* `NONE`
* `DEFAULT`
* `PRESENT`

</details>

<details><summary><a name="OpenMPDependClauseKind"></a>OpenMPDependClauseKind</summary>

Available enumerations:

* `IN`
* `OUT`
* `INOUT`
* `MUTEXINOUTSET`
* `DEPOBJ`
* `SOURCE`
* `SINK`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPDeviceClauseModifier"></a>OpenMPDeviceClauseModifier</summary>

Available enumerations:

* `ANCESTOR`
* `DEVICE_NUM`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPDeviceType"></a>OpenMPDeviceType</summary>

Available enumerations:

* `HOST`
* `NOHOST`
* `ANY`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPDistScheduleClauseKind"></a>OpenMPDistScheduleClauseKind</summary>

Available enumerations:

* `STATIC`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPLastprivateModifier"></a>OpenMPLastprivateModifier</summary>

Available enumerations:

* `CONDITIONAL`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPLinearClauseKind"></a>OpenMPLinearClauseKind</summary>

Available enumerations:

* `VALUE`
* `REFERENCE`
* `UVAL`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPMapClauseKind"></a>OpenMPMapClauseKind</summary>

Available enumerations:

* `ALLOC`
* `TO`
* `FROM`
* `TOFROM`
* `DELETE`
* `RELEASE`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPMapModifierKind"></a>OpenMPMapModifierKind</summary>

Available enumerations:

* `UNKNOWN`
* `ALWAYS`
* `CLOSE`
* `MAPPER`
* `PRESENT`
* `OMPX_HOLD`

</details>

<details><summary><a name="OpenMPMotionModifierKind"></a>OpenMPMotionModifierKind</summary>

Available enumerations:

* `MOTIONMODIFIER_MAPPER`
* `MOTIONMODIFIER_PRESENT`
* `MOTIONMODIFIER_UNKNOWN`

</details>

<details><summary><a name="OpenMPOrderClauseKind"></a>OpenMPOrderClauseKind</summary>

Available enumerations:

* `CONCURRENT`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPReductionClauseModifier"></a>OpenMPReductionClauseModifier</summary>

Available enumerations:

* `DEFAULT`
* `INSCAN`
* `TASK`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPScheduleClauseKind"></a>OpenMPScheduleClauseKind</summary>

Available enumerations:

* `STATIC`
* `DYNAMIC`
* `GUIDED`
* `AUTO`
* `RUNTIME`
* `UNKNOWN`

</details>

<details><summary><a name="OpenMPScheduleClauseModifier"></a>OpenMPScheduleClauseModifier</summary>

Available enumerations:

* `UNKNOWN`
* `MONOTONIC`
* `NONMONOTONIC`
* `SIMD`

</details>

<details><summary><a name="OverloadedOperatorKind"></a>OverloadedOperatorKind</summary>

Available enumerations:

* `NONE`
* `NEW`
* `DELETE`
* `ARRAY_NEW`
* `ARRAY_DELETE`
* `PLUS`
* `MINUS`
* `STAR`
* `SLASH`
* `PERCENT`
* `CARET`
* `AMP`
* `PIPE`
* `TILDE`
* `EXCLAIM`
* `EQUAL`
* `LESS`
* `GREATER`
* `PLUS_EQUAL`
* `MINUS_EQUAL`
* `STAR_EQUAL`
* `SLASH_EQUAL`
* `PERCENT_EQUAL`
* `CARET_EQUAL`
* `AMP_EQUAL`
* `PIPE_EQUAL`
* `LESS_LESS`
* `GREATER_GREATER`
* `LESS_LESS_EQUAL`
* `GREATER_GREATER_EQUAL`
* `EQUAL_EQUAL`
* `EXCLAIM_EQUAL`
* `LESS_EQUAL`
* `GREATER_EQUAL`
* `SPACESHIP`
* `AMP_AMP`
* `PIPE_PIPE`
* `PLUS_PLUS`
* `MINUS_MINUS`
* `COMMA`
* `ARROW_STAR`
* `ARROW`
* `CALL`
* `SUBSCRIPT`
* `CONDITIONAL`
* `COAWAIT`

</details>

<details><summary><a name="OverloadsShown"></a>OverloadsShown</summary>

Available enumerations:

* `ALL`
* `BEST`

</details>

<details><summary><a name="ParameterABI"></a>ParameterABI</summary>

Available enumerations:

* `ORDINARY`
* `SWIFT_INDIRECT_RESULT`
* `SWIFT_ERROR_RESULT`
* `SWIFT_CONTEXT`
* `SWIFT_ASYNC_CONTEXT`

</details>

<details><summary><a name="ParenLocsOffsets"></a>ParenLocsOffsets</summary>

Available enumerations:

* `L_PAREN_TOKEN`
* `R_PAREN_TOKEN`
* `TOTAL`

</details>

<details><summary><a name="PragmaFloatControlKind"></a>PragmaFloatControlKind</summary>

Available enumerations:

* `UNKNOWN`
* `PRECISE`
* `NO_PRECISE`
* `EXCEPT`
* `NO_EXCEPT`
* `PUSH`
* `POP`

</details>

<details><summary><a name="PragmaMSCommentKind"></a>PragmaMSCommentKind</summary>

Available enumerations:

* `UNKNOWN`
* `LINKER`
* `LIB`
* `COMPILER`
* `EXE_STRING`
* `USER`

</details>

<details><summary><a name="PragmaMSPointersToMembersKind"></a>PragmaMSPointersToMembersKind</summary>

Available enumerations:

* `BEST_CASE`
* `FULL_GENERALITY_SINGLE_INHERITANCE`
* `FULL_GENERALITY_MULTIPLE_INHERITANCE`
* `FULL_GENERALITY_VIRTUAL_INHERITANCE`

</details>

<details><summary><a name="PragmaMSStructKind"></a>PragmaMSStructKind</summary>

Available enumerations:

* `OFF`
* `ON`

</details>

<details><summary><a name="PragmaSectionFlag"></a>PragmaSectionFlag</summary>

Available enumerations:

* `NONE`
* `READ`
* `WRITE`
* `EXECUTE`
* `IMPLICIT`
* `ZERO_INITIALIZER`
* `INVALID`

</details>

<details><summary><a name="ProfileInstrKind"></a>ProfileInstrKind</summary>

Available enumerations:

* `PROFILE_NONE`
* `PROFILE_CLANG_INSTR`
* `PROFILE_IR_INSTR`
* `PROFILE_CSIR_INSTR`

</details>

<details><summary><a name="Qualified"></a>Qualified</summary>

Available enumerations:

* `NONE`
* `AS_WRITTEN`
* `FULLY`

</details>

<details><summary><a name="RangeExprOffset"></a>RangeExprOffset</summary>

Available enumerations:

* `BEGIN`
* `END`
* `STEP`
* `TOTAL`

</details>

<details><summary><a name="RangeLocOffset"></a>RangeLocOffset</summary>

Available enumerations:

* `ASSIGN_TOKEN`
* `SECOND_COLON_TOKEN`
* `TOTAL`

</details>

<details><summary><a name="RefQualifierKind"></a>RefQualifierKind</summary>

Available enumerations:

* `NONE`
* `L_VALUE`
* `R_VALUE`

</details>

<details><summary><a name="RemarkKind"></a>RemarkKind</summary>

Available enumerations:

* `MISSING`
* `ENABLED`
* `ENABLED_EVERYTHING`
* `DISABLED`
* `DISABLED_EVERYTHING`
* `WITH_PATTERN`

</details>

<details><summary><a name="ReservedIdentifierStatus"></a>ReservedIdentifierStatus</summary>

Available enumerations:

* `NOT_RESERVED`
* `STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE`
* `STARTS_WITH_UNDERSCORE_AND_IS_EXTERN_C`
* `STARTS_WITH_DOUBLE_UNDERSCORE`
* `STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER`
* `CONTAINS_DOUBLE_UNDERSCORE`

</details>

<details><summary><a name="SFINAEResponse"></a>SFINAEResponse</summary>

Available enumerations:

* `SUBSTITUTION_FAILURE`
* `SUPPRESS`
* `REPORT`
* `ACCESS_CONTROL`

</details>

<details><summary><a name="SYCLMajorVersion"></a>SYCLMajorVersion</summary>

Available enumerations:

* `VERSION_NONE`
* `VERSION2017`
* `VERSION2020`

</details>

<details><summary><a name="SanitizerOrdinal"></a>SanitizerOrdinal</summary>

Available enumerations:

* `ADDRESS`
* `POINTER_COMPARE`
* `POINTER_SUBTRACT`
* `KERNEL_ADDRESS`
* `HW_ADDRESS`
* `KERNEL_HW_ADDRESS`
* `MEMORY_TAG`
* `MEMORY`
* `KERNEL_MEMORY`
* `FUZZER`
* `FUZZER_NO_LINK`
* `THREAD`
* `LEAK`
* `ALIGNMENT`
* `ARRAY_BOUNDS`
* `BOOLEAN`
* `BUILTIN`
* `ENUM`
* `FLOAT_CAST_OVERFLOW`
* `FLOAT_DIVIDE_BY_ZERO`
* `FUNCTION`
* `INTEGER_DIVIDE_BY_ZERO`
* `NONNULL_ATTRIBUTE`
* `NULL__`
* `NULLABILITY_ARGUMENT`
* `NULLABILITY_ASSIGN`
* `NULLABILITY_RETURN`
* `NULLABILITY_GROUP`
* `OBJECT_SIZE`
* `POINTER_OVERFLOW`
* `RETURN`
* `RETURNS_NONNULL_ATTRIBUTE`
* `SHIFT_BASE`
* `SHIFT_EXPONENT`
* `SHIFT_GROUP`
* `SIGNED_INTEGER_OVERFLOW`
* `UNREACHABLE`
* `VLA_BOUND`
* `VPTR`
* `UNSIGNED_INTEGER_OVERFLOW`
* `UNSIGNED_SHIFT_BASE`
* `DATA_FLOW`
* `CFI_CAST_STRICT`
* `CFI_DERIVED_CAST`
* `CFII_CALL`
* `CFIMF_CALL`
* `CFI_UNRELATED_CAST`
* `CFINV_CALL`
* `CFIV_CALL`
* `CFI_GROUP`
* `SAFE_STACK`
* `SHADOW_CALL_STACK`
* `UNDEFINED_GROUP`
* `UNDEFINED_TRAP_GROUP`
* `IMPLICIT_UNSIGNED_INTEGER_TRUNCATION`
* `IMPLICIT_SIGNED_INTEGER_TRUNCATION`
* `IMPLICIT_INTEGER_TRUNCATION_GROUP`
* `IMPLICIT_INTEGER_SIGN_CHANGE`
* `IMPLICIT_INTEGER_ARITHMETIC_VALUE_CHANGE_GROUP`
* `OBJ_C_CAST`
* `IMPLICIT_CONVERSION_GROUP`
* `INTEGER_GROUP`
* `LOCAL_BOUNDS`
* `BOUNDS_GROUP`
* `SCUDO`
* `ALL_GROUP`
* `COUNT`

</details>

<details><summary><a name="SelectorLocationsKind"></a>SelectorLocationsKind</summary>

Available enumerations:

* `NON_STANDARD`
* `STANDARD_NO_SPACE`
* `STANDARD_WITH_SPACE`

</details>

<details><summary><a name="SignReturnAddressKeyKind"></a>SignReturnAddressKeyKind</summary>

Available enumerations:

* `A_KEY`
* `B_KEY`

</details>

<details><summary><a name="SignReturnAddressScopeKind"></a>SignReturnAddressScopeKind</summary>

Available enumerations:

* `NONE`
* `NON_LEAF`
* `ALL`

</details>

<details><summary><a name="SignedOverflowBehaviorTy"></a>SignedOverflowBehaviorTy</summary>

Available enumerations:

* `UNDEFINED`
* `DEFINED`
* `TRAPPING`

</details>

<details><summary><a name="SpecialMemberFlags"></a>SpecialMemberFlags</summary>

Available enumerations:

* `DEFAULT_CONSTRUCTOR`
* `COPY_CONSTRUCTOR`
* `MOVE_CONSTRUCTOR`
* `COPY_ASSIGNMENT`
* `MOVE_ASSIGNMENT`
* `DESTRUCTOR`
* `ALL`

</details>

<details><summary><a name="SpecifierKind"></a>SpecifierKind</summary>

Available enumerations:

* `IDENTIFIER`
* `NAMESPACE`
* `NAMESPACE_ALIAS`
* `TYPE_SPEC`
* `TYPE_SPEC_WITH_TEMPLATE`
* `GLOBAL`
* `SUPER`

</details>

<details><summary><a name="StackProtectorMode"></a>StackProtectorMode</summary>

Available enumerations:

* `OFF`
* `ON`
* `STRONG`
* `REQ`

</details>

<details><summary><a name="StorageClass"></a>StorageClass</summary>

Available enumerations:

* `NONE`
* `EXTERN`
* `STATIC`
* `PRIVATE_EXTERN`
* `AUTO`
* `REGISTER`

</details>

<details><summary><a name="StorageDuration"></a>StorageDuration</summary>

Available enumerations:

* `FULL_EXPRESSION`
* `AUTOMATIC`
* `THREAD`
* `STATIC`
* `DYNAMIC`

</details>

<details><summary><a name="StoredNameKind"></a>StoredNameKind</summary>

Available enumerations:

* `STORED_IDENTIFIER`
* `STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR`
* `STORED_OBJ_C_ONE_ARGUMENT_SELECTOR`
* `STORED_CXX_CONSTRUCTOR_NAME`
* `STORED_CXX_DESTRUCTOR_NAME`
* `STORED_CXX_CONVERSION_FUNCTION_NAME`
* `STORED_CXX_OPERATOR_NAME`
* `STORED_DECLARATION_NAME_EXTRA`
* `UNCOMMON_NAME_KIND_OFFSET`

</details>

<details><summary><a name="StoredSpecifierKind"></a>StoredSpecifierKind</summary>

Available enumerations:

* `STORED_IDENTIFIER`
* `STORED_DECLARATION`
* `STORED_TYPE_SPEC`
* `STORED_TYPE_SPEC_WITH_TEMPLATE`

</details>

<details><summary><a name="StructReturnConventionKind"></a>StructReturnConventionKind</summary>

Available enumerations:

* `DEFAULT`
* `ON_STACK`
* `IN_REGS`

</details>

<details><summary><a name="SubExpr"></a>SubExpr</summary>

Available enumerations:

* `CALLEE`
* `LHS`
* `RHS`
* `COUNT`

</details>

<details><summary><a name="SubStmt"></a>SubStmt</summary>

Available enumerations:

* `BODY`
* `PROMISE`
* `INITIALIZER_SUSPEND`
* `FINAL_SUSPEND`
* `ON_EXCEPTION`
* `ON_FALLTHROUGH`
* `ALLOCATE`
* `DEALLOCATE`
* `RETURN_VALUE`
* `RESULT_DECLARATION`
* `RETURN_STATEMENT`
* `RETURN_STATEMENT_ON_ALLOC_FAILURE`

</details>

<details><summary><a name="SwiftAsyncFramePointerKind"></a>SwiftAsyncFramePointerKind</summary>

Available enumerations:

* `AUTO`
* `ALWAYS`
* `NEVER`

</details>

<details><summary><a name="SyncScope"></a>SyncScope</summary>

Available enumerations:

* `HIP_SINGLE_THREAD`
* `HIP_WAVEFRONT`
* `HIP_WORKGROUP`
* `HIP_AGENT`
* `HIP_SYSTEM`
* `OPEN_CL_WORK_GROUP`
* `OPEN_CL_DEVICE`
* `OPEN_CL_ALL_SVM_DEVICES`
* `OPEN_CL_SUB_GROUP`

</details>

<details><summary><a name="Syntax"></a>Syntax</summary>

Available enumerations:

* `GNU`
* `CXX11`
* `C2_X`
* `DECLSPEC`
* `MICROSOFT`
* `KEYWORD`
* `PRAGMA`
* `CONTEXT_SENSITIVE_KEYWORD`

</details>

<details><summary><a name="TLSModel"></a>TLSModel</summary>

Available enumerations:

* `GENERAL_DYNAMIC_TLS_MODEL`
* `LOCAL_DYNAMIC_TLS_MODEL`
* `INITIAL_EXEC_TLS_MODEL`
* `LOCAL_EXEC_TLS_MODEL`

</details>

<details><summary><a name="TQ"></a>TQ</summary>

Available enumerations:

* `CONST`
* `RESTRICT`
* `VOLATILE`
* `CVR_MASK`

</details>

<details><summary><a name="TagTypeKind"></a>TagTypeKind</summary>

Available enumerations:

* `STRUCT`
* `INTERFACE`
* `UNION`
* `CLASS`
* `ENUM`

</details>

<details><summary><a name="TailPaddingUseRules"></a>TailPaddingUseRules</summary>

Available enumerations:

* `ALWAYS_USE_TAIL_PADDING`
* `USE_TAIL_PADDING_UNLESS_POD03`
* `USE_TAIL_PADDING_UNLESS_POD11`

</details>

<details><summary><a name="TemplateArgumentDependence"></a>TemplateArgumentDependence</summary>

Available enumerations:

* `UNEXPANDED_PACK`
* `INSTANTIATION`
* `DEPENDENT`
* `ERROR`
* `NONE`
* `DEPENDENT_INSTANTIATION`
* `ALL`

</details>

<details><summary><a name="TemplateNameDependence"></a>TemplateNameDependence</summary>

Available enumerations:

* `UNEXPANDED_PACK`
* `INSTANTIATION`
* `DEPENDENT`
* `ERROR`
* `NONE`
* `DEPENDENT_INSTANTIATION`
* `ALL`

</details>

<details><summary><a name="TemplateSpecializationKind"></a>TemplateSpecializationKind</summary>

Available enumerations:

* `UNDECLARED`
* `IMPLICIT_INSTANTIATION`
* `EXPLICIT_SPECIALIZATION`
* `EXPLICIT_INSTANTIATION_DECLARATION`
* `EXPLICIT_INSTANTIATION_DEFINITION`

</details>

<details><summary><a name="TextDiagnosticFormat"></a>TextDiagnosticFormat</summary>

Available enumerations:

* `CLANG`
* `MSVC`
* `VI`

</details>

<details><summary><a name="ThreadModelKind"></a>ThreadModelKind</summary>

Available enumerations:

* `POSIX`
* `SINGLE`

</details>

<details><summary><a name="ThreadStorageClassSpecifier"></a>ThreadStorageClassSpecifier</summary>

Available enumerations:

* `UNSPECIFIED`
* `__THREAD`
* `THREAD_LOCAL`
* `_THREAD_LOCAL`

</details>

<details><summary><a name="TokenKind"></a>TokenKind</summary>

Available enumerations:

* `UNKNOWN`
* `END_OF_FILE`
* `END_OF_DIRECTIVE`
* `CODE_COMPLETION`
* `COMMENT`
* `IDENTIFIER`
* `WHITESPACE`
* `NUMERIC_CONSTANT`
* `CHARACTER_CONSTANT`
* `WIDE_CHARACTER_CONSTANT`
* `UTF8_CHARACTER_CONSTANT`
* `UTF16_CHARACTER_CONSTANT`
* `UTF32_CHARACTER_CONSTANT`
* `STRING_LITERAL`
* `WIDE_STRING_LITERAL`
* `HEADER_NAME`
* `UTF8_STRING_LITERAL`
* `UTF16_STRING_LITERAL`
* `UTF32_STRING_LITERAL`
* `L_SQUARE`
* `R_SQUARE`
* `L_PARENTHESIS`
* `R_PARENTHESIS`
* `L_BRACE_TOKEN`
* `R_BRACE_TOKEN`
* `PERIOD`
* `ELLIPSIS`
* `AMP`
* `AMP_AMP`
* `AMP_EQUAL`
* `STAR`
* `STAR_EQUAL`
* `PLUS`
* `PLUS_PLUS`
* `PLUS_EQUAL`
* `MINUS`
* `ARROW`
* `MINUS_MINUS`
* `MINUS_EQUAL`
* `TILDE`
* `EXCLAIM`
* `EXCLAIM_EQUAL`
* `SLASH`
* `SLASH_EQUAL`
* `PERCENT`
* `PERCENT_EQUAL`
* `LESS`
* `LESS_LESS`
* `LESS_EQUAL`
* `LESS_LESS_EQUAL`
* `SPACESHIP`
* `GREATER`
* `GREATER_GREATER`
* `GREATER_EQUAL`
* `GREATER_GREATER_EQUAL`
* `CARET`
* `CARET_EQUAL`
* `PIPE`
* `PIPE_PIPE`
* `PIPE_EQUAL`
* `QUESTION`
* `COLON`
* `SEMI`
* `EQUAL`
* `EQUAL_EQUAL`
* `COMMA`
* `HASH`
* `HASH_HASH`
* `HASHAT`
* `PERIOD_STAR`
* `ARROW_STAR`
* `COLON_COLON`
* `AT`
* `LESS_LESS_LESS`
* `GREATER_GREATER_GREATER`
* `CARETCARET`
* `KEYWORD_AUTO`
* `KEYWORD_BREAK`
* `KEYWORD_CASE`
* `KEYWORD_CHARACTER`
* `KEYWORD_CONST`
* `KEYWORD_CONTINUE`
* `KEYWORD_DEFAULT`
* `KEYWORD_DO`
* `KEYWORD_DOUBLE`
* `KEYWORD_ELSE`
* `KEYWORD_ENUM`
* `KEYWORD_EXTERN`
* `KEYWORD_FLOAT`
* `KEYWORD_FOR`
* `KEYWORD_GOTO`
* `KEYWORD_IF`
* `KEYWORD_INLINE`
* `KEYWORD_INT`
* `KEYWORD__EXT_INT`
* `KEYWORD__BIT_INT`
* `KEYWORD_LONG`
* `KEYWORD_REGISTER`
* `KEYWORD_RESTRICT`
* `KEYWORD_RETURN`
* `KEYWORD_SHORT`
* `KEYWORD_SIGNED`
* `KEYWORD_SIZEOF`
* `KEYWORD_STATIC`
* `KEYWORD_STRUCT`
* `KEYWORD_SWITCH`
* `KEYWORD_TYPEDEF`
* `KEYWORD_UNION`
* `KEYWORD_UNSIGNED`
* `KEYWORD_VOID`
* `KEYWORD_VOLATILE`
* `KEYWORD_WHILE`
* `KEYWORD__ALIGNAS`
* `KEYWORD__ALIGNOF`
* `KEYWORD__ATOMIC`
* `KEYWORD__BOOLEAN`
* `KEYWORD__COMPLEX`
* `KEYWORD__GENERIC`
* `KEYWORD__IMAGINARY`
* `KEYWORD__NORETURN`
* `KEYWORD__STATIC_ASSERT`
* `KEYWORD__THREAD_LOCAL`
* `KEYWORD___FUNC__`
* `KEYWORD___OBJC_YES`
* `KEYWORD___OBJC_NO`
* `KEYWORD_ASSEMBLY`
* `KEYWORD_BOOLEAN`
* `KEYWORD_CATCH`
* `KEYWORD_CLASS`
* `KEYWORD_CONST_CAST`
* `KEYWORD_DELETE`
* `KEYWORD_DYNAMIC_CAST`
* `KEYWORD_EXPLICIT`
* `KEYWORD_EXPORT`
* `KEYWORD_FALSE`
* `KEYWORD_FRIEND`
* `KEYWORD_MUTABLE`
* `KEYWORD_NAMESPACE`
* `KEYWORD_NEW`
* `KEYWORD_OPERATOR`
* `KEYWORD_PRIVATE`
* `KEYWORD_PROTECTED`
* `KEYWORD_PUBLIC`
* `KEYWORD_REINTERPRET_CAST`
* `KEYWORD_STATIC_CAST`
* `KEYWORD_TEMPLATE`
* `KEYWORD_THIS`
* `KEYWORD_THROW`
* `KEYWORD_TRUE`
* `KEYWORD_TRY`
* `KEYWORD_TYPENAME`
* `KEYWORD_TYPEID`
* `KEYWORD_USING`
* `KEYWORD_VIRTUAL`
* `KEYWORD_WCHAR_T`
* `KEYWORD_ALIGNAS`
* `KEYWORD_ALIGNOF`
* `KEYWORD_CHAR16_T`
* `KEYWORD_CHAR32_T`
* `KEYWORD_CONSTEXPR`
* `KEYWORD_DECLTYPE`
* `KEYWORD_NOEXCEPT`
* `KEYWORD_NULLPTR`
* `KEYWORD_STATIC_ASSERT`
* `KEYWORD_THREAD_LOCAL`
* `KEYWORD_CONCEPT`
* `KEYWORD_REQUIRES`
* `KEYWORD_CO_AWAIT`
* `KEYWORD_CO_RETURN`
* `KEYWORD_CO_YIELD`
* `KEYWORD_MODULE`
* `KEYWORD_IMPORT`
* `KEYWORD_CONSTEVAL`
* `KEYWORD_CONSTINIT`
* `KEYWORD_CHAR8_T`
* `KEYWORD__FLOAT16`
* `KEYWORD__ACCUM`
* `KEYWORD__FRACT`
* `KEYWORD__SAT`
* `KEYWORD__DECIMAL32`
* `KEYWORD__DECIMAL64`
* `KEYWORD__DECIMAL128`
* `KEYWORD___NULL`
* `KEYWORD___ALIGNOF`
* `KEYWORD___ATTRIBUTE`
* `KEYWORD___BUILTIN_CHOOSE_EXPRESSION`
* `KEYWORD___BUILTIN_OFFSETOF`
* `KEYWORD___BUILTIN_FILE`
* `KEYWORD___BUILTIN_FUNCTION`
* `KEYWORD___BUILTIN_LINE`
* `KEYWORD___BUILTIN_COLUMN`
* `KEYWORD___BUILTIN_TYPES_COMPATIBLE_P`
* `KEYWORD___BUILTIN_VA_ARGUMENT`
* `KEYWORD___EXTENSION__`
* `KEYWORD___FLOAT128`
* `KEYWORD___IBM128`
* `KEYWORD___IMAG`
* `KEYWORD___INT128`
* `KEYWORD___LABEL__`
* `KEYWORD___REAL`
* `KEYWORD___THREAD`
* `KEYWORD___FUNCTION__`
* `KEYWORD___PRETTYFUNCTION__`
* `KEYWORD___AUTO_TYPE`
* `KEYWORD_TYPEOF`
* `KEYWORD___FUNCDNAME__`
* `KEYWORD___FUNCSIG__`
* `KEYWORD_LFUNCTION__`
* `KEYWORD_LFUNCSIG__`
* `KEYWORD___IS_INTERFACE_CLASS`
* `KEYWORD___IS_SEALED`
* `KEYWORD___IS_DESTRUCTIBLE`
* `KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE`
* `KEYWORD___IS_NOTHROW_DESTRUCTIBLE`
* `KEYWORD___IS_NOTHROW_ASSIGNABLE`
* `KEYWORD___IS_CONSTRUCTIBLE`
* `KEYWORD___IS_NOTHROW_CONSTRUCTIBLE`
* `KEYWORD___IS_ASSIGNABLE`
* `KEYWORD___HAS_NOTHROW_MOVE_ASSIGN`
* `KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN`
* `KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR`
* `KEYWORD___HAS_NOTHROW_ASSIGN`
* `KEYWORD___HAS_NOTHROW_COPY`
* `KEYWORD___HAS_NOTHROW_CONSTRUCTOR`
* `KEYWORD___HAS_TRIVIAL_ASSIGN`
* `KEYWORD___HAS_TRIVIAL_COPY`
* `KEYWORD___HAS_TRIVIAL_CONSTRUCTOR`
* `KEYWORD___HAS_TRIVIAL_DESTRUCTOR`
* `KEYWORD___HAS_VIRTUAL_DESTRUCTOR`
* `KEYWORD___IS_ABSTRACT`
* `KEYWORD___IS_AGGREGATE`
* `KEYWORD___IS_BASE_OF`
* `KEYWORD___IS_CLASS`
* `KEYWORD___IS_CONVERTIBLE_TO`
* `KEYWORD___IS_EMPTY`
* `KEYWORD___IS_ENUM`
* `KEYWORD___IS_FINAL`
* `KEYWORD___IS_LITERAL`
* `KEYWORD___IS_POD`
* `KEYWORD___IS_POLYMORPHIC`
* `KEYWORD___IS_STANDARD_LAYOUT`
* `KEYWORD___IS_TRIVIAL`
* `KEYWORD___IS_TRIVIALLY_ASSIGNABLE`
* `KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE`
* `KEYWORD___IS_TRIVIALLY_COPYABLE`
* `KEYWORD___IS_UNION`
* `KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS`
* `KEYWORD___UNDERLYING_TYPE`
* `KEYWORD___REFERENCE_BINDS_TO_TEMPORARY`
* `KEYWORD___IS_LVALUE_EXPRESSION`
* `KEYWORD___IS_RVALUE_EXPRESSION`
* `KEYWORD___IS_ARITHMETIC`
* `KEYWORD___IS_FLOATING_POINT`
* `KEYWORD___IS_INTEGRAL`
* `KEYWORD___IS_COMPLETE_TYPE`
* `KEYWORD___IS_VOID`
* `KEYWORD___IS_ARRAY`
* `KEYWORD___IS_FUNCTION`
* `KEYWORD___IS_REFERENCE`
* `KEYWORD___IS_LVALUE_REFERENCE`
* `KEYWORD___IS_RVALUE_REFERENCE`
* `KEYWORD___IS_FUNDAMENTAL`
* `KEYWORD___IS_OBJECT`
* `KEYWORD___IS_SCALAR`
* `KEYWORD___IS_COMPOUND`
* `KEYWORD___IS_POINTER`
* `KEYWORD___IS_MEMBER_OBJECT_POINTER`
* `KEYWORD___IS_MEMBER_FUNCTION_POINTER`
* `KEYWORD___IS_MEMBER_POINTER`
* `KEYWORD___IS_CONST`
* `KEYWORD___IS_VOLATILE`
* `KEYWORD___IS_SIGNED`
* `KEYWORD___IS_UNSIGNED`
* `KEYWORD___IS_SAME`
* `KEYWORD___IS_CONVERTIBLE`
* `KEYWORD___ARRAY_RANK`
* `KEYWORD___ARRAY_EXTENT`
* `KEYWORD___PRIVATE_EXTERN__`
* `KEYWORD___MODULE_PRIVATE__`
* `KEYWORD___DECLSPEC`
* `KEYWORD___CDECL`
* `KEYWORD___STDCALL`
* `KEYWORD___FASTCALL`
* `KEYWORD___THISCALL`
* `KEYWORD___REGCALL`
* `KEYWORD___VECTORCALL`
* `KEYWORD___FORCEINLINE`
* `KEYWORD___UNALIGNED`
* `KEYWORD___SUPER`
* `KEYWORD___GLOBAL`
* `KEYWORD___LOCAL`
* `KEYWORD___CONSTANT`
* `KEYWORD___PRIVATE`
* `KEYWORD___GENERIC`
* `KEYWORD___KERNEL`
* `KEYWORD___READ_ONLY`
* `KEYWORD___WRITE_ONLY`
* `KEYWORD___READ_WRITE`
* `KEYWORD___BUILTIN_ASTYPE`
* `KEYWORD_VEC_STEP`
* `KEYWORD_IMAGE1_DT`
* `KEYWORD_IMAGE1_DARRAY_T`
* `KEYWORD_IMAGE1_DBUFFER_T`
* `KEYWORD_IMAGE2_DT`
* `KEYWORD_IMAGE2_DARRAY_T`
* `KEYWORD_IMAGE2_DDEPTH_T`
* `KEYWORD_IMAGE2_DARRAY_DEPTH_T`
* `KEYWORD_IMAGE2_DMSAA_T`
* `KEYWORD_IMAGE2_DARRAY_MSAA_T`
* `KEYWORD_IMAGE2_DMSAA_DEPTH_T`
* `KEYWORD_IMAGE2_DARRAY_MSAA_DEPTH_T`
* `KEYWORD_IMAGE3_DT`
* `KEYWORD_PIPE`
* `KEYWORD_ADDRSPACE_CAST`
* `KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN`
* `KEYWORD___PASCAL`
* `KEYWORD___VECTOR`
* `KEYWORD___PIXEL`
* `KEYWORD___BOOLEAN`
* `KEYWORD___BF16`
* `KEYWORD_HALF`
* `KEYWORD___BRIDGE`
* `KEYWORD___BRIDGE_TRANSFER`
* `KEYWORD___BRIDGE_RETAINED`
* `KEYWORD___BRIDGE_RETAIN`
* `KEYWORD___COVARIANT`
* `KEYWORD___CONTRAVARIANT`
* `KEYWORD___KINDOF`
* `KEYWORD__NONNULL`
* `KEYWORD__NULLABLE`
* `KEYWORD__NULLABLE_RESULT`
* `KEYWORD__NULL_UNSPECIFIED`
* `KEYWORD___PTR64`
* `KEYWORD___PTR32`
* `KEYWORD___SPTR`
* `KEYWORD___UPTR`
* `KEYWORD___W64`
* `KEYWORD___UUIDOF`
* `KEYWORD___TRY`
* `KEYWORD___FINALLY`
* `KEYWORD___LEAVE`
* `KEYWORD___INT64`
* `KEYWORD___IF_EXISTS`
* `KEYWORD___IF_NOT_EXISTS`
* `KEYWORD___SINGLE_INHERITANCE`
* `KEYWORD___MULTIPLE_INHERITANCE`
* `KEYWORD___VIRTUAL_INHERITANCE`
* `KEYWORD___INTERFACE`
* `KEYWORD___BUILTIN_CONVERTVECTOR`
* `KEYWORD___BUILTIN_BIT_CAST`
* `KEYWORD___BUILTIN_AVAILABLE`
* `KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME`
* `KEYWORD___UNKNOWN_ANYTYPE`
* `ANNOT_CXXSCOPE`
* `ANNOT_TYPENAME`
* `ANNOT_TEMPLATE_ID`
* `ANNOT_NON_TYPE`
* `ANNOT_NON_TYPE_UNDECLARED`
* `ANNOT_NON_TYPE_DEPENDENT`
* `ANNOT_OVERLOAD`
* `ANNOT_PRIMARY_EXPRESSION`
* `ANNOT_DECLTYPE`
* `ANNOT_PRAGMA_UNUSED`
* `ANNOT_PRAGMA_VIS`
* `ANNOT_PRAGMA_PACK`
* `ANNOT_PRAGMA_PARSER_CRASH`
* `ANNOT_PRAGMA_CAPTURED`
* `ANNOT_PRAGMA_DUMP`
* `ANNOT_PRAGMA_MSSTRUCT`
* `ANNOT_PRAGMA_ALIGN`
* `ANNOT_PRAGMA_WEAK`
* `ANNOT_PRAGMA_WEAKALIAS`
* `ANNOT_PRAGMA_REDEFINE_EXTNAME`
* `ANNOT_PRAGMA_FP_CONTRACT`
* `ANNOT_PRAGMA_FENV_ACCESS`
* `ANNOT_PRAGMA_FENV_ACCESS_MS`
* `ANNOT_PRAGMA_FENV_ROUND`
* `ANNOT_PRAGMA_FLOAT_CONTROL`
* `ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS`
* `ANNOT_PRAGMA_MS_VTORDISP`
* `ANNOT_PRAGMA_MS_PRAGMA`
* `ANNOT_PRAGMA_OPENCL_EXTENSION`
* `ANNOT_ATTRIBUTE_OPENMP`
* `ANNOT_PRAGMA_OPENMP`
* `ANNOT_PRAGMA_OPENMP_END`
* `ANNOT_PRAGMA_LOOP_HINT`
* `ANNOT_PRAGMA_FP`
* `ANNOT_PRAGMA_ATTRIBUTE`
* `ANNOT_MODULE_INCLUDE`
* `ANNOT_MODULE_BEGIN`
* `ANNOT_MODULE_END`
* `ANNOT_HEADER_UNIT`
* `PP_IF`
* `PP_IFDEF`
* `PP_IFNDEF`
* `PP_ELIF`
* `PP_ELIFDEF`
* `PP_ELIFNDEF`
* `PP_ELSE`
* `PP_ENDIF`
* `PP_DEFINED`
* `PP_INCLUDE`
* `PP___INCLUDE_MACROS`
* `PP_DEFINE`
* `PP_UNDEF`
* `PP_LINE`
* `PP_ERROR`
* `PP_PRAGMA`
* `PP_IMPORT`
* `PP_INCLUDE_NEXT`
* `PP_WARNING`
* `PP_IDENTIFIER`
* `PP_SCCS`
* `PP_ASSERT`
* `PP_UNASSERT`
* `PP___PUBLIC_MACRO`
* `PP___PRIVATE_MACRO`
* `OBJC_AT_CLASS`
* `OBJC_AT_COMPATIBILITY_ALIAS`
* `OBJC_AT_DEFINITIONS`
* `OBJC_AT_ENCODE`
* `OBJC_AT_OBJC_END`
* `OBJC_AT_IMPLEMENTATION`
* `OBJC_AT_INTERFACE`
* `OBJC_AT_PRIVATE`
* `OBJC_AT_PROTECTED`
* `OBJC_AT_PROTOCOL`
* `OBJC_AT_PUBLIC`
* `OBJC_AT_SELECTOR`
* `OBJC_AT_THROW`
* `OBJC_AT_TRY`
* `OBJC_AT_CATCH`
* `OBJC_AT_FINALLY`
* `OBJC_AT_SYNCHRONIZED`
* `OBJC_AT_AUTORELEASEPOOL`
* `OBJC_AT_PROPERTY`
* `OBJC_AT_PACKAGE`
* `OBJC_AT_REQUIRED`
* `OBJC_AT_OPTIONAL`
* `OBJC_AT_SYNTHESIZE`
* `OBJC_AT_DYNAMIC`
* `OBJC_AT_IMPORT`
* `OBJC_AT_AVAILABLE`
* `BEGIN_OF_FILE_MARKER`
* `END_OF_FILE_MARKER`
* `BEGIN_OF_MACRO_EXPANSION_MARKER`
* `END_OF_MACRO_EXPANSION_MARKER`

</details>

<details><summary><a name="TrailingAllocKind"></a>TrailingAllocKind</summary>

Available enumerations:

* `TAK_INHERITS_CONSTRUCTOR`
* `TAK_HAS_TAIL_EXPLICIT`

</details>

<details><summary><a name="TranslationUnitKind"></a>TranslationUnitKind</summary>

Available enumerations:

* `COMPLETE`
* `PREFIX`
* `MODULE`
* `INCREMENTAL`

</details>

<details><summary><a name="TrivialAutoVarInitKind"></a>TrivialAutoVarInitKind</summary>

Available enumerations:

* `UNINITIALIZED`
* `ZERO`
* `PATTERN`

</details>

<details><summary><a name="TypeDependence"></a>TypeDependence</summary>

Available enumerations:

* `UNEXPANDED_PACK`
* `INSTANTIATION`
* `DEPENDENT`
* `VARIABLY_MODIFIED`
* `ERROR`
* `NONE`
* `ALL`
* `DEPENDENT_INSTANTIATION`

</details>

<details><summary><a name="TypeLocClass"></a>TypeLocClass</summary>

Available enumerations:

* `ADJUSTED`
* `DECAYED`
* `CONSTANT_ARRAY`
* `DEPENDENT_SIZED_ARRAY`
* `INCOMPLETE_ARRAY`
* `VARIABLE_ARRAY`
* `ATOMIC`
* `ATTRIBUTED`
* `BIT_INT`
* `BLOCK_POINTER`
* `BUILTIN`
* `COMPLEX`
* `DECLTYPE`
* `AUTO`
* `DEDUCED_TEMPLATE_SPECIALIZATION`
* `DEPENDENT_ADDRESS_SPACE`
* `DEPENDENT_BIT_INT`
* `DEPENDENT_NAME`
* `DEPENDENT_SIZED_EXT_VECTOR`
* `DEPENDENT_TEMPLATE_SPECIALIZATION`
* `DEPENDENT_VECTOR`
* `ELABORATED`
* `FUNCTION_NO_PROTO`
* `FUNCTION_PROTO`
* `INJECTED_CLASS_NAME`
* `MACRO_QUALIFIED`
* `CONSTANT_MATRIX`
* `DEPENDENT_SIZED_MATRIX`
* `MEMBER_POINTER`
* `OBJ_C_OBJECT_POINTER`
* `OBJ_C_OBJECT`
* `OBJ_C_INTERFACE`
* `OBJ_C_TYPE_PARAMETER`
* `PACK_EXPANSION`
* `PARENTHESIS`
* `PIPE`
* `POINTER`
* `L_VALUE_REFERENCE`
* `R_VALUE_REFERENCE`
* `SUBST_TEMPLATE_TYPE_PARM_PACK`
* `SUBST_TEMPLATE_TYPE_PARM`
* `ENUM`
* `RECORD`
* `TEMPLATE_SPECIALIZATION`
* `TEMPLATE_TYPE_PARM`
* `TYPE_OF_EXPRESSION`
* `TYPE_OF`
* `TYPEDEF`
* `UNARY_TRANSFORM`
* `UNRESOLVED_USING`
* `USING`
* `VECTOR`
* `EXT_VECTOR`
* `QUALIFIED`

</details>

<details><summary><a name="TypeSpecifierSign"></a>TypeSpecifierSign</summary>

Available enumerations:

* `UNSPECIFIED`
* `SIGNED`
* `UNSIGNED`

</details>

<details><summary><a name="TypeSpecifierType"></a>TypeSpecifierType</summary>

Available enumerations:

* `UNSPECIFIED`
* `VOID`
* `CHARACTER`
* `WCHAR`
* `CHAR8`
* `CHAR16`
* `CHAR32`
* `INT`
* `INT128`
* `BITINT`
* `HALF`
* `FLOAT16`
* `ACCUM`
* `FRACT`
* `B_FLOAT16`
* `FLOAT`
* `DOUBLE`
* `FLOAT128`
* `IBM128`
* `BOOLEAN`
* `DECIMAL32`
* `DECIMAL64`
* `DECIMAL128`
* `ENUM`
* `UNION`
* `STRUCT`
* `CLASS`
* `INTERFACE`
* `TYPENAME`
* `TYPEOF_TYPE`
* `TYPEOF_EXPRESSION`
* `DECLTYPE`
* `UNDERLYING_TYPE`
* `AUTO`
* `DECLTYPE_AUTO`
* `AUTO_TYPE`
* `UNKNOWN_ANYTYPE`
* `ATOMIC`
* `IMAGE1_DT`
* `IMAGE1_DARRAY_T`
* `IMAGE1_DBUFFER_T`
* `IMAGE2_DT`
* `IMAGE2_DARRAY_T`
* `IMAGE2_DDEPTH_T`
* `IMAGE2_DARRAY_DEPTH_T`
* `IMAGE2_DMSAA_T`
* `IMAGE2_DARRAY_MSAA_T`
* `IMAGE2_DMSAA_DEPTH_T`
* `IMAGE2_DARRAY_MSAA_DEPTH_T`
* `IMAGE3_DT`
* `ERROR`

</details>

<details><summary><a name="TypeSpecifierWidth"></a>TypeSpecifierWidth</summary>

Available enumerations:

* `UNSPECIFIED`
* `SHORT`
* `LONG`
* `LONG_LONG`

</details>

<details><summary><a name="TypeSpecifiersPipe"></a>TypeSpecifiersPipe</summary>

Available enumerations:

* `UNSPECIFIED`
* `PIPE`

</details>

<details><summary><a name="TypeTrait"></a>TypeTrait</summary>

Available enumerations:

* `IS_INTERFACE_CLASS`
* `IS_SEALED`
* `IS_DESTRUCTIBLE`
* `IS_TRIVIALLY_DESTRUCTIBLE`
* `IS_NOTHROW_DESTRUCTIBLE`
* `HAS_NOTHROW_MOVE_ASSIGN`
* `HAS_TRIVIAL_MOVE_ASSIGN`
* `HAS_TRIVIAL_MOVE_CONSTRUCTOR`
* `HAS_NOTHROW_ASSIGN`
* `HAS_NOTHROW_COPY`
* `HAS_NOTHROW_CONSTRUCTOR`
* `HAS_TRIVIAL_ASSIGN`
* `HAS_TRIVIAL_COPY`
* `HAS_TRIVIAL_DEFAULT_CONSTRUCTOR`
* `HAS_TRIVIAL_DESTRUCTOR`
* `HAS_VIRTUAL_DESTRUCTOR`
* `IS_ABSTRACT`
* `IS_AGGREGATE`
* `IS_CLASS`
* `IS_EMPTY`
* `IS_ENUM`
* `IS_FINAL`
* `IS_LITERAL`
* `IS_POD`
* `IS_POLYMORPHIC`
* `IS_STANDARD_LAYOUT`
* `IS_TRIVIAL`
* `IS_TRIVIALLY_COPYABLE`
* `IS_UNION`
* `HAS_UNIQUE_OBJECT_REPRESENTATIONS`
* `IS_ARITHMETIC`
* `IS_FLOATING_POINT`
* `IS_INTEGRAL`
* `IS_COMPLETE_TYPE`
* `IS_VOID`
* `IS_ARRAY`
* `IS_FUNCTION`
* `IS_REFERENCE`
* `IS_LVALUE_REFERENCE`
* `IS_RVALUE_REFERENCE`
* `IS_FUNDAMENTAL`
* `IS_OBJECT`
* `IS_SCALAR`
* `IS_COMPOUND`
* `IS_POINTER`
* `IS_MEMBER_OBJECT_POINTER`
* `IS_MEMBER_FUNCTION_POINTER`
* `IS_MEMBER_POINTER`
* `IS_CONST`
* `IS_VOLATILE`
* `IS_SIGNED`
* `IS_UNSIGNED`
* `TYPE_COMPATIBLE`
* `IS_NOTHROW_ASSIGNABLE`
* `IS_ASSIGNABLE`
* `IS_BASE_OF`
* `IS_CONVERTIBLE_TO`
* `IS_TRIVIALLY_ASSIGNABLE`
* `REFERENCE_BINDS_TO_TEMPORARY`
* `IS_SAME`
* `IS_CONVERTIBLE`
* `IS_CONSTRUCTIBLE`
* `IS_NOTHROW_CONSTRUCTIBLE`
* `IS_TRIVIALLY_CONSTRUCTIBLE`

</details>

<details><summary><a name="UnaryExprOrTypeTrait"></a>UnaryExprOrTypeTrait</summary>

Available enumerations:

* `SIZE_OF`
* `ALIGN_OF`
* `PREFERRED_ALIGN_OF`
* `VEC_STEP`
* `OPEN_MP_REQUIRED_SIMD_ALIGN`

</details>

<details><summary><a name="UnaryOperatorKind"></a>UnaryOperatorKind</summary>

Available enumerations:

* `POST_INCREMENT`
* `POST_DEC`
* `PRE_INCREMENT`
* `PRE_DEC`
* `ADDR_OF`
* `DEREF`
* `PLUS`
* `MINUS`
* `NOT`
* `L_NOT`
* `REAL`
* `IMAG`
* `EXTENSION`
* `COAWAIT`

</details>

<details><summary><a name="APValueKind"></a>APValueKind</summary>

Available enumerations:

* `NONE`
* `INDETERMINATE`
* `INT`
* `FLOAT`
* `FIXED_POINT`
* `COMPLEX_INT`
* `COMPLEX_FLOAT`
* `L_VALUE`
* `VECTOR`
* `ARRAY`
* `STRUCT`
* `UNION`
* `MEMBER_POINTER`
* `ADDR_LABEL_DIFF`

</details>

<details><summary><a name="VectorLibrary"></a>VectorLibrary</summary>

Available enumerations:

* `NO_LIBRARY`
* `ACCELERATE`
* `LIBMVEC`
* `MASSV`
* `SVML`
* `DARWIN_LIBSYSTEM_M`

</details>

<details><summary><a name="Visibility"></a>Visibility</summary>

Available enumerations:

* `HIDDEN_VISIBILITY`
* `PROTECTED_VISIBILITY`
* `DEFAULT_VISIBILITY`

</details>

<details><summary><a name="AttributeSyntax"></a>AttributeSyntax</summary>

Available enumerations:

* `GNU`
* `CXX11`
* `C2_X`
* `DECLSPEC`
* `MICROSOFT`
* `KEYWORD`
* `PRAGMA`
* `CONTEXT_SENSITIVE_KEYWORD`

</details>

<details><summary><a name="DeclCategory"></a>DeclCategory</summary>

Available enumerations:

* `UNKNOWN`
* `LOCAL_VARIABLE`
* `GLOBAL_VARIABLE`
* `PARAMETER_VARIABLE`
* `FUNCTION`
* `INSTANCE_METHOD`
* `INSTANCE_MEMBER`
* `CLASS_METHOD`
* `CLASS_MEMBER`
* `THIS`
* `CLASS`
* `STRUCTURE`
* `UNION`
* `INTERFACE`
* `ENUMERATION`
* `ENUMERATOR`
* `NAMESPACE`
* `TYPE_ALIAS`
* `TEMPLATE_TYPE_PARAMETER`
* `TEMPLATE_VALUE_PARAMETER`
* `LABEL`

</details>

<details><summary><a name="PathKind"></a>PathKind</summary>

Available enumerations:

* `UNIX`
* `WINDOWS`

</details>

<details><summary><a name="FileType"></a>FileType</summary>

Available enumerations:

* `NONE`
* `NOT_FOUND`
* `REGULAR`
* `DIRECTORY`
* `SYMBOLIC_LINK`
* `BLOCK`
* `CHARACTER`
* `FIRST_IN_FIRST_OUT`
* `SOCKET`
* `KNKNOWN`

</details>

<details><summary><a name="CompilerName"></a>CompilerName</summary>

Available enumerations:

* `UNKNOWN`
* `CLANG`
* `APPLE_CLANG`
* `CLANG_CL`
* `CL`
* `GNU`

</details>

<details><summary><a name="IncludePathLocation"></a>IncludePathLocation</summary>

Available enumerations:

* `ABSOLUTE`
* `SYSROOT_RELATIVE`

</details>

<details><summary><a name="TargetLanguage"></a>TargetLanguage</summary>

Available enumerations:

* `C`
* `CXX`

</details>

<details><summary><a name="PseudoKind"></a>PseudoKind</summary>

Available enumerations:

* `TEMPLATE_ARGUMENT`
* `TEMPLATE_PARAMETER_LIST`
* `CXX_BASE_SPECIFIER`
* `DESIGNATOR`

</details>

## Class tables

Every class exposed by the Multiplier API has a corresponding table for use with SQL queries.

In addition to the fields listed in each entry's summary, every table also has `id` and `fragment_id` fields

<!-- | `is_field_designator` | `INTEGER` | :heavy_check_mark: | |
| `is_array_designator` | `INTEGER` | :heavy_check_mark: | |
| `is_array_range_designator` | `INTEGER` | :heavy_check_mark: | |
| `field` | `INTEGER` | :x: | [`FieldDecl`](#FieldDecl) |
| `dot_token` | `INTEGER` | :heavy_check_mark: | |
| `field_token` | `INTEGER` | :heavy_check_mark: | |
| `left_bracket_token` | `INTEGER` | :heavy_check_mark: | |
| `right_bracket_token` | `INTEGER` | :heavy_check_mark: | |
| `ellipsis_token` | `INTEGER` | :heavy_check_mark: | |
| `first_expression_index` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
 -->

<!-- | `num_parameters` | `INTEGER` | :heavy_check_mark: | |
| `num_required_parameters` | `INTEGER` | :heavy_check_mark: | |
| `depth` | `INTEGER` | :heavy_check_mark: | |
| `has_unexpanded_parameter_pack` | `INTEGER` | :heavy_check_mark: | |
| `has_parameter_pack` | `INTEGER` | :heavy_check_mark: | |
| `requires_clause` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `template_keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `left_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `right_angle_token` | `INTEGER` | :heavy_check_mark: | |
 -->

<!-- | `kind` | `INTEGER` | :heavy_check_mark: | [`TemplateArgumentKind`](#TemplateArgumentKind) |
| `is_null` | `INTEGER` | :heavy_check_mark: | |
| `is_dependent` | `INTEGER` | :heavy_check_mark: | |
| `is_instantiation_dependent` | `INTEGER` | :heavy_check_mark: | |
| `contains_unexpanded_parameter_pack` | `INTEGER` | :heavy_check_mark: | |
| `is_pack_expansion` | `INTEGER` | :heavy_check_mark: | |
| `as_declaration` | `INTEGER` | :x: | [`ValueDecl`](#ValueDecl) |
| `as_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `parameter_type_for_declaration` | `INTEGER` | :x: | [`Type`](#Type) |
| `null_pointer_type` | `INTEGER` | :x: | [`Type`](#Type) |
 -->

<!-- | `base_type_token` | `INTEGER` | :heavy_check_mark: | |
| `is_virtual` | `INTEGER` | :heavy_check_mark: | |
| `base_kind` | `INTEGER` | :heavy_check_mark: | [`TagTypeKind`](#TagTypeKind) |
| `is_pack_expansion` | `INTEGER` | :heavy_check_mark: | |
| `constructors_are_inherited` | `INTEGER` | :heavy_check_mark: | |
| `ellipsis_token` | `INTEGER` | :x: | [`Token`](#Token) |
| `semantic_access_specifier` | `INTEGER` | :heavy_check_mark: | [`AccessSpecifier`](#AccessSpecifier) |
| `lexical_access_specifier` | `INTEGER` | :heavy_check_mark: | [`AccessSpecifier`](#AccessSpecifier) |
| `base_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
 -->

<details><summary><a name="Type"></a>Type</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `is_qualified` | `INTEGER` | :heavy_check_mark: | |
| `unqualified_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `accepts_obj_c_type_parameters` | `INTEGER` | :heavy_check_mark: | |
| `can_decay_to_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `can_have_nullability` | `INTEGER` | :heavy_check_mark: | |
| `contains_errors` | `INTEGER` | :heavy_check_mark: | |
| `contains_unexpanded_parameter_pack` | `INTEGER` | :heavy_check_mark: | |
| `array_element_type_no_type_qualified` | `INTEGER` | :x: | [`Type`](#Type) |
| `as_cxx_record_declaration` | `INTEGER` | :x: | [`CXXRecordDecl`](#CXXRecordDecl) |
| `as_complex_integer_type` | `INTEGER` | :x: | [`ComplexType`](#ComplexType) |
| `as_obj_c_interface_pointer_type` | `INTEGER` | :x: | [`ObjCObjectPointerType`](#ObjCObjectPointerType) |
| `as_obj_c_interface_type` | `INTEGER` | :x: | [`ObjCObjectType`](#ObjCObjectType) |
| `as_obj_c_qualified_class_type` | `INTEGER` | :x: | [`ObjCObjectPointerType`](#ObjCObjectPointerType) |
| `as_obj_c_qualified_id_type` | `INTEGER` | :x: | [`ObjCObjectPointerType`](#ObjCObjectPointerType) |
| `as_obj_c_qualified_interface_type` | `INTEGER` | :x: | [`ObjCObjectType`](#ObjCObjectType) |
| `as_placeholder_type` | `INTEGER` | :x: | [`BuiltinType`](#BuiltinType) |
| `as_record_declaration` | `INTEGER` | :x: | [`RecordDecl`](#RecordDecl) |
| `as_structure_type` | `INTEGER` | :x: | [`RecordType`](#RecordType) |
| `as_tag_declaration` | `INTEGER` | :x: | [`TagDecl`](#TagDecl) |
| `as_union_type` | `INTEGER` | :x: | [`RecordType`](#RecordType) |
| `contained_auto_type` | `INTEGER` | :x: | [`AutoType`](#AutoType) |
| `contained_deduced_type` | `INTEGER` | :x: | [`DeducedType`](#DeducedType) |
| `linkage` | `INTEGER` | :heavy_check_mark: | [`Linkage`](#Linkage) |
| `locally_unqualified_single_step_desugared_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `nullability` | `INTEGER` | :x: | |
| `pointee_cxx_record_declaration` | `INTEGER` | :x: | [`CXXRecordDecl`](#CXXRecordDecl) |
| `pointee_or_array_element_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `pointee_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `scalar_type_kind` | `INTEGER` | :x: | |
| `sve_element_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `kind` | `INTEGER` | :heavy_check_mark: | [`TypeKind`](#TypeKind) |
| `unqualified_desugared_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `visibility` | `INTEGER` | :heavy_check_mark: | [`Visibility`](#Visibility) |
| `has_auto_for_trailing_return_type` | `INTEGER` | :heavy_check_mark: | |
| `has_floating_representation` | `INTEGER` | :heavy_check_mark: | |
| `has_integer_representation` | `INTEGER` | :heavy_check_mark: | |
| `has_obj_c_pointer_representation` | `INTEGER` | :heavy_check_mark: | |
| `has_pointer_representation` | `INTEGER` | :heavy_check_mark: | |
| `has_signed_integer_representation` | `INTEGER` | :heavy_check_mark: | |
| `has_sized_vla_type` | `INTEGER` | :heavy_check_mark: | |
| `has_unnamed_or_local_type` | `INTEGER` | :heavy_check_mark: | |
| `has_unsigned_integer_representation` | `INTEGER` | :heavy_check_mark: | |
| `is_aggregate_type` | `INTEGER` | :x: | |
| `is_align_value_t` | `INTEGER` | :heavy_check_mark: | |
| `is_any_character_type` | `INTEGER` | :heavy_check_mark: | |
| `is_any_complex_type` | `INTEGER` | :heavy_check_mark: | |
| `is_any_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_arithmetic_type` | `INTEGER` | :heavy_check_mark: | |
| `is_array_type` | `INTEGER` | :heavy_check_mark: | |
| `is_atomic_type` | `INTEGER` | :heavy_check_mark: | |
| `is_b_float16_type` | `INTEGER` | :heavy_check_mark: | |
| `is_bit_int_type` | `INTEGER` | :heavy_check_mark: | |
| `is_block_compatible_obj_c_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_block_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_boolean_type` | `INTEGER` | :heavy_check_mark: | |
| `is_builtin_type` | `INTEGER` | :heavy_check_mark: | |
| `is_carc_bridgable_type` | `INTEGER` | :heavy_check_mark: | |
| `is_cuda_device_builtin_surface_type` | `INTEGER` | :heavy_check_mark: | |
| `is_cuda_device_builtin_texture_type` | `INTEGER` | :heavy_check_mark: | |
| `is_canonical_unqualified` | `INTEGER` | :heavy_check_mark: | |
| `is_char16_type` | `INTEGER` | :heavy_check_mark: | |
| `is_char32_type` | `INTEGER` | :heavy_check_mark: | |
| `is_char8_type` | `INTEGER` | :heavy_check_mark: | |
| `is_character_type` | `INTEGER` | :heavy_check_mark: | |
| `is_class_type` | `INTEGER` | :heavy_check_mark: | |
| `is_clk_event_t` | `INTEGER` | :heavy_check_mark: | |
| `is_complex_integer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_complex_type` | `INTEGER` | :heavy_check_mark: | |
| `is_compound_type` | `INTEGER` | :heavy_check_mark: | |
| `is_constant_array_type` | `INTEGER` | :heavy_check_mark: | |
| `is_constant_matrix_type` | `INTEGER` | :heavy_check_mark: | |
| `is_constant_size_type` | `INTEGER` | :x: | |
| `is_decltype_type` | `INTEGER` | :heavy_check_mark: | |
| `is_dependent_address_space_type` | `INTEGER` | :heavy_check_mark: | |
| `is_dependent_sized_array_type` | `INTEGER` | :heavy_check_mark: | |
| `is_dependent_type` | `INTEGER` | :heavy_check_mark: | |
| `is_elaborated_type_specifier` | `INTEGER` | :heavy_check_mark: | |
| `is_enumeral_type` | `INTEGER` | :heavy_check_mark: | |
| `is_event_t` | `INTEGER` | :heavy_check_mark: | |
| `is_ext_vector_type` | `INTEGER` | :heavy_check_mark: | |
| `is_fixed_point_or_integer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_fixed_point_type` | `INTEGER` | :heavy_check_mark: | |
| `is_float128_type` | `INTEGER` | :heavy_check_mark: | |
| `is_float16_type` | `INTEGER` | :heavy_check_mark: | |
| `is_floating_type` | `INTEGER` | :heavy_check_mark: | |
| `is_from_ast` | `INTEGER` | :heavy_check_mark: | |
| `is_function_no_proto_type` | `INTEGER` | :heavy_check_mark: | |
| `is_function_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_function_proto_type` | `INTEGER` | :heavy_check_mark: | |
| `is_function_reference_type` | `INTEGER` | :heavy_check_mark: | |
| `is_function_type` | `INTEGER` | :heavy_check_mark: | |
| `is_fundamental_type` | `INTEGER` | :heavy_check_mark: | |
| `is_half_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ibm128_type` | `INTEGER` | :heavy_check_mark: | |
| `is_image_type` | `INTEGER` | :heavy_check_mark: | |
| `is_incomplete_array_type` | `INTEGER` | :heavy_check_mark: | |
| `is_incomplete_or_object_type` | `INTEGER` | :heavy_check_mark: | |
| `is_incomplete_type` | `INTEGER` | :heavy_check_mark: | |
| `is_instantiation_dependent_type` | `INTEGER` | :heavy_check_mark: | |
| `is_integer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_integral_or_enumeration_type` | `INTEGER` | :heavy_check_mark: | |
| `is_integral_or_unscoped_enumeration_type` | `INTEGER` | :heavy_check_mark: | |
| `is_integral_type` | `INTEGER` | :heavy_check_mark: | |
| `is_interface_type` | `INTEGER` | :heavy_check_mark: | |
| `is_l_value_reference_type` | `INTEGER` | :heavy_check_mark: | |
| `is_linkage_valid` | `INTEGER` | :heavy_check_mark: | |
| `is_literal_type` | `INTEGER` | :x: | |
| `is_matrix_type` | `INTEGER` | :heavy_check_mark: | |
| `is_member_data_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_member_function_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_member_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_non_overload_placeholder_type` | `INTEGER` | :heavy_check_mark: | |
| `is_nothrow_t` | `INTEGER` | :heavy_check_mark: | |
| `is_null_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_ext_opaque_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image1_darray_ro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image1_darray_rw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image1_darray_wo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image1_dbuffer_ro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image1_dbuffer_rw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image1_dbuffer_wo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image1_dro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image1_drw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image1_dwo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_depth_ro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_depth_rw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_depth_wo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_msaa_depth_ro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_msaa_depth_rw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_msaa_depth_wo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_msaaro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_msaarw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_msaawo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_ro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_rw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_darray_wo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_ddepth_ro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_ddepth_rw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_ddepth_wo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_dmsaa_depth_ro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_dmsaa_depth_rw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_dmsaa_depth_wo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_dmsaaro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_dmsaarw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_dmsaawo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_dro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_drw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image2_dwo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image3_dro_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image3_drw_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_image3_dwo_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_ime_dual_reference_streamin_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_ime_payload_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_ime_result_dual_reference_streamout_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_ime_result_single_reference_streamout_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_ime_result_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_ime_single_reference_streamin_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_mce_payload_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_mce_result_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_ref_payload_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_ref_result_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_sic_payload_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_sic_result_type` | `INTEGER` | :heavy_check_mark: | |
| `is_ocl_intel_subgroup_avc_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_carc_bridgable_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_carc_implicitly_unretained_type` | `INTEGER` | :x: | |
| `is_obj_c_boxable_record_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_builtin_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_class_or_class_kind_of_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_class_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_id_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_independent_class_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_indirect_lifetime_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_inert_unsafe_unretained_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_lifetime_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_cns_object_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_object_or_interface_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_object_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_object_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_qualified_class_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_qualified_id_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_qualified_interface_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_retainable_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_sel_type` | `INTEGER` | :heavy_check_mark: | |
| `is_object_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_object_type` | `INTEGER` | :heavy_check_mark: | |
| `is_open_cl_specific_type` | `INTEGER` | :heavy_check_mark: | |
| `is_overloadable_type` | `INTEGER` | :heavy_check_mark: | |
| `is_pipe_type` | `INTEGER` | :heavy_check_mark: | |
| `is_placeholder_type` | `INTEGER` | :heavy_check_mark: | |
| `is_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_promotable_integer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_queue_t` | `INTEGER` | :heavy_check_mark: | |
| `is_r_value_reference_type` | `INTEGER` | :heavy_check_mark: | |
| `is_real_floating_type` | `INTEGER` | :heavy_check_mark: | |
| `is_real_type` | `INTEGER` | :heavy_check_mark: | |
| `is_record_type` | `INTEGER` | :heavy_check_mark: | |
| `is_reference_type` | `INTEGER` | :heavy_check_mark: | |
| `is_reserve_idt` | `INTEGER` | :heavy_check_mark: | |
| `is_sampler_t` | `INTEGER` | :heavy_check_mark: | |
| `is_saturated_fixed_point_type` | `INTEGER` | :heavy_check_mark: | |
| `is_scalar_type` | `INTEGER` | :heavy_check_mark: | |
| `is_scoped_enumeral_type` | `INTEGER` | :heavy_check_mark: | |
| `is_signed_fixed_point_type` | `INTEGER` | :heavy_check_mark: | |
| `is_signed_integer_or_enumeration_type` | `INTEGER` | :heavy_check_mark: | |
| `is_signed_integer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_sizeless_builtin_type` | `INTEGER` | :heavy_check_mark: | |
| `is_sizeless_type` | `INTEGER` | :heavy_check_mark: | |
| `is_specifier_type` | `INTEGER` | :heavy_check_mark: | |
| `is_standard_layout_type` | `INTEGER` | :x: | |
| `is_std_byte_type` | `INTEGER` | :heavy_check_mark: | |
| `is_structural_type` | `INTEGER` | :x: | |
| `is_structure_or_class_type` | `INTEGER` | :heavy_check_mark: | |
| `is_structure_type` | `INTEGER` | :heavy_check_mark: | |
| `is_template_type_parm_type` | `INTEGER` | :heavy_check_mark: | |
| `is_typedef_name_type` | `INTEGER` | :heavy_check_mark: | |
| `is_undeduced_auto_type` | `INTEGER` | :heavy_check_mark: | |
| `is_undeduced_type` | `INTEGER` | :heavy_check_mark: | |
| `is_union_type` | `INTEGER` | :heavy_check_mark: | |
| `is_unsaturated_fixed_point_type` | `INTEGER` | :heavy_check_mark: | |
| `is_unscoped_enumeration_type` | `INTEGER` | :heavy_check_mark: | |
| `is_unsigned_fixed_point_type` | `INTEGER` | :heavy_check_mark: | |
| `is_unsigned_integer_or_enumeration_type` | `INTEGER` | :heavy_check_mark: | |
| `is_unsigned_integer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_vlst_builtin_type` | `INTEGER` | :heavy_check_mark: | |
| `is_variable_array_type` | `INTEGER` | :heavy_check_mark: | |
| `is_variably_modified_type` | `INTEGER` | :heavy_check_mark: | |
| `is_vector_type` | `INTEGER` | :heavy_check_mark: | |
| `is_visibility_explicit` | `INTEGER` | :heavy_check_mark: | |
| `is_void_pointer_type` | `INTEGER` | :heavy_check_mark: | |
| `is_void_type` | `INTEGER` | :heavy_check_mark: | |
| `is_wide_character_type` | `INTEGER` | :heavy_check_mark: | |
| `ignore_parentheses` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `address_space` | `INTEGER` | :heavy_check_mark: | [`LangAS`](#LangAS) |
| `atomic_unqualified_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `canonical_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `desugared_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `local_unqualified_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `non_l_value_expression_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `non_pack_expansion_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `non_reference_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `single_step_desugared_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `has_address_space` | `INTEGER` | :heavy_check_mark: | |
| `has_local_non_fast_qualifiers` | `INTEGER` | :heavy_check_mark: | |
| `has_local_qualifiers` | `INTEGER` | :heavy_check_mark: | |
| `has_non_trivial_obj_c_lifetime` | `INTEGER` | :heavy_check_mark: | |
| `has_non_trivial_to_primitive_copy_c_union` | `INTEGER` | :heavy_check_mark: | |
| `has_non_trivial_to_primitive_default_initialize_c_union` | `INTEGER` | :heavy_check_mark: | |
| `has_non_trivial_to_primitive_destruct_c_union` | `INTEGER` | :heavy_check_mark: | |
| `has_qualifiers` | `INTEGER` | :heavy_check_mark: | |
| `has_strong_or_weak_obj_c_lifetime` | `INTEGER` | :heavy_check_mark: | |
| `is_c_forbidden_l_value_type` | `INTEGER` | :heavy_check_mark: | |
| `is_cxx11_pod_type` | `INTEGER` | :heavy_check_mark: | |
| `is_cxx98_pod_type` | `INTEGER` | :heavy_check_mark: | |
| `is_canonical` | `INTEGER` | :heavy_check_mark: | |
| `is_canonical_as_parameter` | `INTEGER` | :heavy_check_mark: | |
| `is_const_qualified` | `INTEGER` | :heavy_check_mark: | |
| `is_constant` | `INTEGER` | :heavy_check_mark: | |
| `is_destructed_type` | `INTEGER` | :heavy_check_mark: | [`QualTypeDestructionKind`](#QualTypeDestructionKind) |
| `is_local_const_qualified` | `INTEGER` | :heavy_check_mark: | |
| `is_local_restrict_qualified` | `INTEGER` | :heavy_check_mark: | |
| `is_local_volatile_qualified` | `INTEGER` | :heavy_check_mark: | |
| `is_non_trivial_to_primitive_copy` | `INTEGER` | :heavy_check_mark: | [`QualTypePrimitiveCopyKind`](#QualTypePrimitiveCopyKind) |
| `is_non_trivial_to_primitive_default_initialize` | `INTEGER` | :heavy_check_mark: | [`QualTypePrimitiveDefaultInitializeKind`](#QualTypePrimitiveDefaultInitializeKind) |
| `is_non_trivial_to_primitive_destructive_move` | `INTEGER` | :heavy_check_mark: | [`QualTypePrimitiveCopyKind`](#QualTypePrimitiveCopyKind) |
| `is_non_weak_in_mrr_with_obj_c_weak` | `INTEGER` | :heavy_check_mark: | |
| `is_null` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_cgc_strong` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_cgc_weak` | `INTEGER` | :heavy_check_mark: | |
| `is_pod_type` | `INTEGER` | :heavy_check_mark: | |
| `is_restrict_qualified` | `INTEGER` | :heavy_check_mark: | |
| `is_trivial_type` | `INTEGER` | :heavy_check_mark: | |
| `is_trivially_copyable_type` | `INTEGER` | :heavy_check_mark: | |
| `is_volatile_qualified` | `INTEGER` | :heavy_check_mark: | |
| `may_be_dynamic_class` | `INTEGER` | :heavy_check_mark: | |
| `may_be_not_dynamic_class` | `INTEGER` | :heavy_check_mark: | |
| `strip_obj_c_kind_of_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `with_const` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `with_restrict` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `with_volatile` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `without_local_fast_qualifiers` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |

</details>

<details><summary><a name="TemplateTypeParmType"></a>TemplateTypeParmType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `declaration` | `INTEGER` | :x: | [`TemplateTypeParmDecl`](#TemplateTypeParmDecl) |
| `is_parameter_pack` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="TemplateSpecializationType"></a>TemplateSpecializationType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `aliased_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `is_current_instantiation` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |
| `is_type_alias` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="TagType"></a>TagType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `declaration` | `INTEGER` | :heavy_check_mark: | [`TagDecl`](#TagDecl) |
| `is_being_defined` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="RecordType"></a>RecordType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `has_const_fields` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TagType`](#TagType).


</details>

<details><summary><a name="EnumType"></a>EnumType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TagType`](#TagType).


</details>

<details><summary><a name="SubstTemplateTypeParmType"></a>SubstTemplateTypeParmType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `replaced_parameter` | `INTEGER` | :heavy_check_mark: | [`TemplateTypeParmType`](#TemplateTypeParmType) |
| `replacement_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="SubstTemplateTypeParmPackType"></a>SubstTemplateTypeParmPackType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `replaced_parameter` | `INTEGER` | :heavy_check_mark: | [`TemplateTypeParmType`](#TemplateTypeParmType) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="ReferenceType"></a>ReferenceType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `pointee_type_as_written` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_inner_reference` | `INTEGER` | :heavy_check_mark: | |
| `is_spelled_as_l_value` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="RValueReferenceType"></a>RValueReferenceType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ReferenceType`](#ReferenceType).


</details>

<details><summary><a name="LValueReferenceType"></a>LValueReferenceType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ReferenceType`](#ReferenceType).


</details>

<details><summary><a name="PointerType"></a>PointerType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="PipeType"></a>PipeType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `element_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_read_only` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="ParenType"></a>ParenType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `inner_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="PackExpansionType"></a>PackExpansionType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `num_expansions` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `pattern` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="ObjCTypeParamType"></a>ObjCTypeParamType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCTypeParamDecl`](#ObjCTypeParamDecl) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="ObjCObjectType"></a>ObjCObjectType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `base_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `interface` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |
| `super_class_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `is_kind_of_type` | `INTEGER` | :heavy_check_mark: | |
| `is_kind_of_type_as_written` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_class` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_id` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_qualified_class` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_qualified_id` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_unqualified_class` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_unqualified_id` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_unqualified_id_or_class` | `INTEGER` | :heavy_check_mark: | |
| `is_specialized` | `INTEGER` | :heavy_check_mark: | |
| `is_specialized_as_written` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |
| `is_unspecialized` | `INTEGER` | :heavy_check_mark: | |
| `is_unspecialized_as_written` | `INTEGER` | :heavy_check_mark: | |
| `strip_obj_c_kind_of_type_and_qualifieds` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="ObjCInterfaceType"></a>ObjCInterfaceType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |

This table also includes all of the fields contained in [`ObjCObjectType`](#ObjCObjectType).


</details>

<details><summary><a name="ObjCObjectPointerType"></a>ObjCObjectPointerType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `interface_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |
| `interface_type` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceType`](#ObjCInterfaceType) |
| `object_type` | `INTEGER` | :heavy_check_mark: | [`ObjCObjectType`](#ObjCObjectType) |
| `super_class_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_kind_of_type` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_id_or_class_type` | `INTEGER` | :heavy_check_mark: | |
| `is_specialized` | `INTEGER` | :heavy_check_mark: | |
| `is_specialized_as_written` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |
| `is_unspecialized` | `INTEGER` | :heavy_check_mark: | |
| `is_unspecialized_as_written` | `INTEGER` | :heavy_check_mark: | |
| `strip_obj_c_kind_of_type_and_qualifieds` | `INTEGER` | :heavy_check_mark: | [`ObjCObjectPointerType`](#ObjCObjectPointerType) |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="MemberPointerType"></a>MemberPointerType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `class_` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `most_recent_cxx_record_declaration` | `INTEGER` | :heavy_check_mark: | [`CXXRecordDecl`](#CXXRecordDecl) |
| `is_member_data_pointer` | `INTEGER` | :heavy_check_mark: | |
| `is_member_function_pointer` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="MatrixType"></a>MatrixType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `element_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="DependentSizedMatrixType"></a>DependentSizedMatrixType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `attribute_token` | `INTEGER` | :heavy_check_mark: | |
| `column_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `row_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`MatrixType`](#MatrixType).


</details>

<details><summary><a name="ConstantMatrixType"></a>ConstantMatrixType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`MatrixType`](#MatrixType).


</details>

<details><summary><a name="MacroQualifiedType"></a>MacroQualifiedType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `modified_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `underlying_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="InjectedClassNameType"></a>InjectedClassNameType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `declaration` | `INTEGER` | :heavy_check_mark: | [`CXXRecordDecl`](#CXXRecordDecl) |
| `injected_specialization_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `injected_tst` | `INTEGER` | :heavy_check_mark: | [`TemplateSpecializationType`](#TemplateSpecializationType) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="FunctionType"></a>FunctionType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `call_conv` | `INTEGER` | :heavy_check_mark: | [`CallingConv`](#CallingConv) |
| `call_result_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `cmse_ns_call_attribute` | `INTEGER` | :heavy_check_mark: | |
| `has_reg_parm` | `INTEGER` | :heavy_check_mark: | |
| `no_return_attribute` | `INTEGER` | :heavy_check_mark: | |
| `return_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_const` | `INTEGER` | :heavy_check_mark: | |
| `is_restrict` | `INTEGER` | :heavy_check_mark: | |
| `is_volatile` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="FunctionProtoType"></a>FunctionProtoType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `can_throw` | `INTEGER` | :x: | |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `ellipsis_token` | `INTEGER` | :heavy_check_mark: | |
| `exception_spec_declaration` | `INTEGER` | :x: | [`FunctionDecl`](#FunctionDecl) |
| `exception_spec_template` | `INTEGER` | :x: | [`FunctionDecl`](#FunctionDecl) |
| `exception_spec_type` | `INTEGER` | :heavy_check_mark: | [`ExceptionSpecificationType`](#ExceptionSpecificationType) |
| `noexcept_expression` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `reference_qualifier` | `INTEGER` | :heavy_check_mark: | [`RefQualifierKind`](#RefQualifierKind) |
| `has_dependent_exception_spec` | `INTEGER` | :heavy_check_mark: | |
| `has_dynamic_exception_spec` | `INTEGER` | :heavy_check_mark: | |
| `has_exception_spec` | `INTEGER` | :heavy_check_mark: | |
| `has_ext_parameter_infos` | `INTEGER` | :heavy_check_mark: | |
| `has_instantiation_dependent_exception_spec` | `INTEGER` | :heavy_check_mark: | |
| `has_noexcept_exception_spec` | `INTEGER` | :heavy_check_mark: | |
| `has_trailing_return` | `INTEGER` | :heavy_check_mark: | |
| `is_nothrow` | `INTEGER` | :x: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |
| `is_template_variadic` | `INTEGER` | :heavy_check_mark: | |
| `is_variadic` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`FunctionType`](#FunctionType).


</details>

<details><summary><a name="FunctionNoProtoType"></a>FunctionNoProtoType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`FunctionType`](#FunctionType).


</details>

<details><summary><a name="DependentVectorType"></a>DependentVectorType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `attribute_token` | `INTEGER` | :heavy_check_mark: | |
| `element_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `size_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `vector_kind` | `INTEGER` | :heavy_check_mark: | [`VectorTypeVectorKind`](#VectorTypeVectorKind) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="DependentSizedExtVectorType"></a>DependentSizedExtVectorType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `attribute_token` | `INTEGER` | :heavy_check_mark: | |
| `element_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `size_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="DependentBitIntType"></a>DependentBitIntType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `num_bits_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_signed` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |
| `is_unsigned` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="DependentAddressSpaceType"></a>DependentAddressSpaceType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `addr_space_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `attribute_token` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="DeducedType"></a>DeducedType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `resolved_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `is_deduced` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="DeducedTemplateSpecializationType"></a>DeducedTemplateSpecializationType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`DeducedType`](#DeducedType).


</details>

<details><summary><a name="AutoType"></a>AutoType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `keyword` | `INTEGER` | :heavy_check_mark: | [`AutoTypeKeyword`](#AutoTypeKeyword) |
| `type_constraint_concept` | `INTEGER` | :x: | [`ConceptDecl`](#ConceptDecl) |
| `is_constrained` | `INTEGER` | :heavy_check_mark: | |
| `is_decltype_auto` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`DeducedType`](#DeducedType).


</details>

<details><summary><a name="DecltypeType"></a>DecltypeType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `underlying_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `underlying_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="ComplexType"></a>ComplexType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `element_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="BuiltinType"></a>BuiltinType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `builtin_kind` | `INTEGER` | :heavy_check_mark: | [`BuiltinTypeKind`](#BuiltinTypeKind) |
| `is_floating_point` | `INTEGER` | :heavy_check_mark: | |
| `is_integer` | `INTEGER` | :heavy_check_mark: | |
| `is_signed_integer` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |
| `is_unsigned_integer` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="BlockPointerType"></a>BlockPointerType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="BitIntType"></a>BitIntType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_signed` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |
| `is_unsigned` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="AttributedType"></a>AttributedType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `attribute_kind` | `INTEGER` | :heavy_check_mark: | [`AttrKind`](#AttrKind) |
| `equivalent_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `immediate_nullability` | `INTEGER` | :x: | |
| `modified_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_calling_conv` | `INTEGER` | :heavy_check_mark: | |
| `is_ms_type_spec` | `INTEGER` | :heavy_check_mark: | |
| `is_qualifier` | `INTEGER` | :heavy_check_mark: | |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="AtomicType"></a>AtomicType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `value_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="ArrayType"></a>ArrayType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `element_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `size_modifier` | `INTEGER` | :heavy_check_mark: | [`ArrayTypeArraySizeModifier`](#ArrayTypeArraySizeModifier) |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="VariableArrayType"></a>VariableArrayType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `l_bracket_token` | `INTEGER` | :heavy_check_mark: | |
| `r_bracket_token` | `INTEGER` | :heavy_check_mark: | |
| `size_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ArrayType`](#ArrayType).


</details>

<details><summary><a name="IncompleteArrayType"></a>IncompleteArrayType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ArrayType`](#ArrayType).


</details>

<details><summary><a name="DependentSizedArrayType"></a>DependentSizedArrayType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `l_bracket_token` | `INTEGER` | :heavy_check_mark: | |
| `r_bracket_token` | `INTEGER` | :heavy_check_mark: | |
| `size_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ArrayType`](#ArrayType).


</details>

<details><summary><a name="ConstantArrayType"></a>ConstantArrayType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `size_expression` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ArrayType`](#ArrayType).


</details>

<details><summary><a name="AdjustedType"></a>AdjustedType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `resolved_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `original_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="DecayedType"></a>DecayedType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`AdjustedType`](#AdjustedType).


</details>

<details><summary><a name="TypeWithKeyword"></a>TypeWithKeyword</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `keyword` | `INTEGER` | :heavy_check_mark: | [`ElaboratedTypeKeyword`](#ElaboratedTypeKeyword) |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="ElaboratedType"></a>ElaboratedType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `named_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `owned_tag_declaration` | `INTEGER` | :x: | [`TagDecl`](#TagDecl) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TypeWithKeyword`](#TypeWithKeyword).


</details>

<details><summary><a name="DependentTemplateSpecializationType"></a>DependentTemplateSpecializationType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TypeWithKeyword`](#TypeWithKeyword).


</details>

<details><summary><a name="DependentNameType"></a>DependentNameType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TypeWithKeyword`](#TypeWithKeyword).


</details>

<details><summary><a name="VectorType"></a>VectorType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `element_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `vector_kind` | `INTEGER` | :heavy_check_mark: | [`VectorTypeVectorKind`](#VectorTypeVectorKind) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="ExtVectorType"></a>ExtVectorType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`VectorType`](#VectorType).


</details>

<details><summary><a name="UsingType"></a>UsingType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `found_declaration` | `INTEGER` | :heavy_check_mark: | [`UsingShadowDecl`](#UsingShadowDecl) |
| `underlying_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="UnresolvedUsingType"></a>UnresolvedUsingType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `declaration` | `INTEGER` | :heavy_check_mark: | [`UnresolvedUsingTypenameDecl`](#UnresolvedUsingTypenameDecl) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="UnaryTransformType"></a>UnaryTransformType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `base_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `utt_kind` | `INTEGER` | :heavy_check_mark: | [`UnaryTransformTypeUTTKind`](#UnaryTransformTypeUTTKind) |
| `underlying_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="TypedefType"></a>TypedefType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `declaration` | `INTEGER` | :heavy_check_mark: | [`TypedefNameDecl`](#TypedefNameDecl) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="TypeOfType"></a>TypeOfType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `underlying_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="TypeOfExprType"></a>TypeOfExprType</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `desugar` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `underlying_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_sugared` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Type`](#Type).


</details>

<details><summary><a name="Stmt"></a>Stmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `referenced_declaration` | `INTEGER` | :x: | [`Decl`](#Decl) |
| `ignore_containers` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `kind` | `INTEGER` | :heavy_check_mark: | [`StmtKind`](#StmtKind) |
| `strip_label_like_statements` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |

</details>

<details><summary><a name="SEHTryStmt"></a>SEHTryStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `except_handler` | `INTEGER` | :heavy_check_mark: | [`SEHExceptStmt`](#SEHExceptStmt) |
| `finally_handler` | `INTEGER` | :heavy_check_mark: | [`SEHFinallyStmt`](#SEHFinallyStmt) |
| `handler` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `is_cxx_try` | `INTEGER` | :heavy_check_mark: | |
| `try_block` | `INTEGER` | :heavy_check_mark: | [`CompoundStmt`](#CompoundStmt) |
| `try_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="SEHLeaveStmt"></a>SEHLeaveStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `leave_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="SEHFinallyStmt"></a>SEHFinallyStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `block` | `INTEGER` | :heavy_check_mark: | [`CompoundStmt`](#CompoundStmt) |
| `finally_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="SEHExceptStmt"></a>SEHExceptStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `block` | `INTEGER` | :heavy_check_mark: | [`CompoundStmt`](#CompoundStmt) |
| `except_token` | `INTEGER` | :heavy_check_mark: | |
| `filter_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ReturnStmt"></a>ReturnStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `nrvo_candidate` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |
| `return_value` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `return_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ObjCForCollectionStmt"></a>ObjCForCollectionStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `collection` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `element` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `for_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ObjCAutoreleasePoolStmt"></a>ObjCAutoreleasePoolStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_token` | `INTEGER` | :heavy_check_mark: | |
| `sub_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ObjCAtTryStmt"></a>ObjCAtTryStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_try_token` | `INTEGER` | :heavy_check_mark: | |
| `finally_statement` | `INTEGER` | :heavy_check_mark: | [`ObjCAtFinallyStmt`](#ObjCAtFinallyStmt) |
| `try_body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ObjCAtThrowStmt"></a>ObjCAtThrowStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `throw_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `throw_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ObjCAtSynchronizedStmt"></a>ObjCAtSynchronizedStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_synchronized_token` | `INTEGER` | :heavy_check_mark: | |
| `synch_body` | `INTEGER` | :heavy_check_mark: | [`CompoundStmt`](#CompoundStmt) |
| `synch_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ObjCAtFinallyStmt"></a>ObjCAtFinallyStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_finally_token` | `INTEGER` | :heavy_check_mark: | |
| `finally_body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ObjCAtCatchStmt"></a>ObjCAtCatchStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_catch_token` | `INTEGER` | :heavy_check_mark: | |
| `catch_body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `catch_parameter_declaration` | `INTEGER` | :heavy_check_mark: | [`VarDecl`](#VarDecl) |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `has_ellipsis` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="OMPExecutableDirective"></a>OMPExecutableDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `associated_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `innermost_captured_statement` | `INTEGER` | :heavy_check_mark: | [`CapturedStmt`](#CapturedStmt) |
| `raw_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `structured_block` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `has_associated_statement` | `INTEGER` | :heavy_check_mark: | |
| `is_standalone_directive` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="OMPDispatchDirective"></a>OMPDispatchDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `target_call_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPDepobjDirective"></a>OMPDepobjDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPCriticalDirective"></a>OMPCriticalDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPCancellationPointDirective"></a>OMPCancellationPointDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPCancelDirective"></a>OMPCancelDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPBarrierDirective"></a>OMPBarrierDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPAtomicDirective"></a>OMPAtomicDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `update_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `v` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `x` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_postfix_update` | `INTEGER` | :heavy_check_mark: | |
| `is_xlhs_in_rhs_part` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTeamsDirective"></a>OMPTeamsDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTaskyieldDirective"></a>OMPTaskyieldDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTaskwaitDirective"></a>OMPTaskwaitDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTaskgroupDirective"></a>OMPTaskgroupDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `reduction_reference` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTaskDirective"></a>OMPTaskDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTargetUpdateDirective"></a>OMPTargetUpdateDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTargetTeamsDirective"></a>OMPTargetTeamsDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTargetParallelDirective"></a>OMPTargetParallelDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTargetExitDataDirective"></a>OMPTargetExitDataDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTargetEnterDataDirective"></a>OMPTargetEnterDataDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTargetDirective"></a>OMPTargetDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPTargetDataDirective"></a>OMPTargetDataDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPSingleDirective"></a>OMPSingleDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPSectionsDirective"></a>OMPSectionsDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPSectionDirective"></a>OMPSectionDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPScanDirective"></a>OMPScanDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPParallelSectionsDirective"></a>OMPParallelSectionsDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPParallelMasterDirective"></a>OMPParallelMasterDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPParallelDirective"></a>OMPParallelDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPOrderedDirective"></a>OMPOrderedDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPMetaDirective"></a>OMPMetaDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `if_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPMasterDirective"></a>OMPMasterDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPMaskedDirective"></a>OMPMaskedDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPLoopBasedDirective"></a>OMPLoopBasedDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPLoopTransformationDirective"></a>OMPLoopTransformationDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `pre_initializers` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `transformed_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`OMPLoopBasedDirective`](#OMPLoopBasedDirective).


</details>

<details><summary><a name="OMPUnrollDirective"></a>OMPUnrollDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopTransformationDirective`](#OMPLoopTransformationDirective).


</details>

<details><summary><a name="OMPTileDirective"></a>OMPTileDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopTransformationDirective`](#OMPLoopTransformationDirective).


</details>

<details><summary><a name="OMPLoopDirective"></a>OMPLoopDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `calculate_last_iteration` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combined_condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combined_distance_condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combined_ensure_upper_bound` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combined_initializer` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combined_lower_bound_variable` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combined_next_lower_bound` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combined_next_upper_bound` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combined_parallel_for_in_distance_condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combined_upper_bound_variable` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `distance_increment` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ensure_upper_bound` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `increment` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `initializer` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_last_iteration_variable` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `iteration_variable` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `last_iteration` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `lower_bound_variable` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `next_lower_bound` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `next_upper_bound` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `num_iterations` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `pre_condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `pre_initializers` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `prev_ensure_upper_bound` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `prev_lower_bound_variable` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `prev_upper_bound_variable` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `stride_variable` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `upper_bound_variable` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`OMPLoopBasedDirective`](#OMPLoopBasedDirective).


</details>

<details><summary><a name="OMPGenericLoopDirective"></a>OMPGenericLoopDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPForSimdDirective"></a>OMPForSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPForDirective"></a>OMPForDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPDistributeSimdDirective"></a>OMPDistributeSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPDistributeParallelForSimdDirective"></a>OMPDistributeParallelForSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPDistributeParallelForDirective"></a>OMPDistributeParallelForDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPDistributeDirective"></a>OMPDistributeDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTeamsDistributeSimdDirective"></a>OMPTeamsDistributeSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTeamsDistributeParallelForSimdDirective"></a>OMPTeamsDistributeParallelForSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTeamsDistributeParallelForDirective"></a>OMPTeamsDistributeParallelForDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTeamsDistributeDirective"></a>OMPTeamsDistributeDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTaskLoopSimdDirective"></a>OMPTaskLoopSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTaskLoopDirective"></a>OMPTaskLoopDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTargetTeamsDistributeSimdDirective"></a>OMPTargetTeamsDistributeSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTargetTeamsDistributeParallelForSimdDirective"></a>OMPTargetTeamsDistributeParallelForSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTargetTeamsDistributeParallelForDirective"></a>OMPTargetTeamsDistributeParallelForDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTargetTeamsDistributeDirective"></a>OMPTargetTeamsDistributeDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTargetSimdDirective"></a>OMPTargetSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTargetParallelForSimdDirective"></a>OMPTargetParallelForSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPTargetParallelForDirective"></a>OMPTargetParallelForDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPSimdDirective"></a>OMPSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPParallelMasterTaskLoopSimdDirective"></a>OMPParallelMasterTaskLoopSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPParallelMasterTaskLoopDirective"></a>OMPParallelMasterTaskLoopDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPParallelForSimdDirective"></a>OMPParallelForSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPParallelForDirective"></a>OMPParallelForDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `task_reduction_reference_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPMasterTaskLoopSimdDirective"></a>OMPMasterTaskLoopSimdDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPMasterTaskLoopDirective"></a>OMPMasterTaskLoopDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `has_cancel` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OMPLoopDirective`](#OMPLoopDirective).


</details>

<details><summary><a name="OMPInteropDirective"></a>OMPInteropDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPFlushDirective"></a>OMPFlushDirective</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPExecutableDirective`](#OMPExecutableDirective).


</details>

<details><summary><a name="OMPCanonicalLoop"></a>OMPCanonicalLoop</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `distance_func` | `INTEGER` | :heavy_check_mark: | [`CapturedStmt`](#CapturedStmt) |
| `loop_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `loop_variable_func` | `INTEGER` | :heavy_check_mark: | [`CapturedStmt`](#CapturedStmt) |
| `loop_variable_reference` | `INTEGER` | :heavy_check_mark: | [`DeclRefExpr`](#DeclRefExpr) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="NullStmt"></a>NullStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `semi_token` | `INTEGER` | :heavy_check_mark: | |
| `has_leading_empty_macro` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="MSDependentExistsStmt"></a>MSDependentExistsStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `sub_statement` | `INTEGER` | :heavy_check_mark: | [`CompoundStmt`](#CompoundStmt) |
| `is_if_exists` | `INTEGER` | :heavy_check_mark: | |
| `is_if_not_exists` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="IndirectGotoStmt"></a>IndirectGotoStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `constant_target` | `INTEGER` | :x: | [`LabelDecl`](#LabelDecl) |
| `goto_token` | `INTEGER` | :heavy_check_mark: | |
| `star_token` | `INTEGER` | :heavy_check_mark: | |
| `target` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="IfStmt"></a>IfStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `condition_variable` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |
| `condition_variable_declaration_statement` | `INTEGER` | :x: | [`DeclStmt`](#DeclStmt) |
| `else_` | `INTEGER` | :x: | [`Stmt`](#Stmt) |
| `else_token` | `INTEGER` | :heavy_check_mark: | |
| `if_token` | `INTEGER` | :heavy_check_mark: | |
| `initializer` | `INTEGER` | :x: | [`Stmt`](#Stmt) |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `statement_kind` | `INTEGER` | :heavy_check_mark: | [`IfStatementKind`](#IfStatementKind) |
| `then` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `has_else_storage` | `INTEGER` | :heavy_check_mark: | |
| `has_initializer_storage` | `INTEGER` | :heavy_check_mark: | |
| `has_variable_storage` | `INTEGER` | :heavy_check_mark: | |
| `is_consteval` | `INTEGER` | :heavy_check_mark: | |
| `is_constexpr` | `INTEGER` | :heavy_check_mark: | |
| `is_negated_consteval` | `INTEGER` | :heavy_check_mark: | |
| `is_non_negated_consteval` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_availability_check` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="GotoStmt"></a>GotoStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `goto_token` | `INTEGER` | :heavy_check_mark: | |
| `label` | `INTEGER` | :heavy_check_mark: | [`LabelDecl`](#LabelDecl) |
| `label_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ForStmt"></a>ForStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `condition` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `condition_variable` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |
| `condition_variable_declaration_statement` | `INTEGER` | :x: | [`DeclStmt`](#DeclStmt) |
| `for_token` | `INTEGER` | :heavy_check_mark: | |
| `increment` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `initializer` | `INTEGER` | :x: | [`Stmt`](#Stmt) |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="DoStmt"></a>DoStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `do_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `while_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="DeclStmt"></a>DeclStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `single_declaration` | `INTEGER` | :x: | [`Decl`](#Decl) |
| `is_single_declaration` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="CoroutineBodyStmt"></a>CoroutineBodyStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `allocate` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `deallocate` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `exception_handler` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `fallthrough_handler` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `final_suspend_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `initializer_suspend_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `promise_declaration` | `INTEGER` | :heavy_check_mark: | [`VarDecl`](#VarDecl) |
| `promise_declaration_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `result_declaration` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `return_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `return_statement_on_alloc_failure` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `return_value_initializer` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_dependent_promise_type` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="CoreturnStmt"></a>CoreturnStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `operand` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `promise_call` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_implicit` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ContinueStmt"></a>ContinueStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `continue_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="CompoundStmt"></a>CompoundStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `left_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `right_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `statement_expression_result` | `INTEGER` | :x: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="CapturedStmt"></a>CapturedStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `captured_declaration` | `INTEGER` | :heavy_check_mark: | [`CapturedDecl`](#CapturedDecl) |
| `captured_record_declaration` | `INTEGER` | :heavy_check_mark: | [`RecordDecl`](#RecordDecl) |
| `captured_region_kind` | `INTEGER` | :heavy_check_mark: | [`CapturedRegionKind`](#CapturedRegionKind) |
| `captured_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="CXXTryStmt"></a>CXXTryStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `try_block` | `INTEGER` | :heavy_check_mark: | [`CompoundStmt`](#CompoundStmt) |
| `try_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="CXXForRangeStmt"></a>CXXForRangeStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `begin_statement` | `INTEGER` | :heavy_check_mark: | [`DeclStmt`](#DeclStmt) |
| `body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `coawait_token` | `INTEGER` | :heavy_check_mark: | |
| `colon_token` | `INTEGER` | :heavy_check_mark: | |
| `condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `end_statement` | `INTEGER` | :heavy_check_mark: | [`DeclStmt`](#DeclStmt) |
| `for_token` | `INTEGER` | :heavy_check_mark: | |
| `increment` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `initializer` | `INTEGER` | :x: | [`Stmt`](#Stmt) |
| `loop_variable_statement` | `INTEGER` | :heavy_check_mark: | [`DeclStmt`](#DeclStmt) |
| `loop_variable` | `INTEGER` | :heavy_check_mark: | [`VarDecl`](#VarDecl) |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `range_initializer` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `range_statement` | `INTEGER` | :heavy_check_mark: | [`DeclStmt`](#DeclStmt) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="CXXCatchStmt"></a>CXXCatchStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `catch_token` | `INTEGER` | :heavy_check_mark: | |
| `caught_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `exception_declaration` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |
| `handler_block` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="BreakStmt"></a>BreakStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `break_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="AsmStmt"></a>AsmStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `generate_assembly_string` | `TEXT` | :heavy_check_mark: | |
| `assembly_token` | `INTEGER` | :heavy_check_mark: | |
| `is_simple` | `INTEGER` | :heavy_check_mark: | |
| `is_volatile` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="MSAsmStmt"></a>MSAsmStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `assembly_string` | `TEXT` | :heavy_check_mark: | |
| `l_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `has_braces` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`AsmStmt`](#AsmStmt).


</details>

<details><summary><a name="GCCAsmStmt"></a>GCCAsmStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `assembly_string` | `INTEGER` | :heavy_check_mark: | [`StringLiteral`](#StringLiteral) |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `is_assembly_goto` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`AsmStmt`](#AsmStmt).


</details>

<details><summary><a name="WhileStmt"></a>WhileStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `condition_variable` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |
| `condition_variable_declaration_statement` | `INTEGER` | :x: | [`DeclStmt`](#DeclStmt) |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `while_token` | `INTEGER` | :heavy_check_mark: | |
| `has_variable_storage` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="ValueStmt"></a>ValueStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `expression_statement` | `INTEGER` | :x: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="LabelStmt"></a>LabelStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `declaration` | `INTEGER` | :heavy_check_mark: | [`LabelDecl`](#LabelDecl) |
| `identifier_token` | `INTEGER` | :heavy_check_mark: | |
| `name` | `TEXT` | :heavy_check_mark: | |
| `sub_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `is_side_entry` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ValueStmt`](#ValueStmt).


</details>

<details><summary><a name="Expr"></a>Expr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `has_side_effects` | `INTEGER` | :heavy_check_mark: | |
| `ignore_casts` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_conversion_operator_single_step` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_imp_casts` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_implicit` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_implicit_as_written` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_parenthesis_base_casts` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_parenthesis_casts` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_parenthesis_imp_casts` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_parenthesis_l_value_casts` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_parenthesis_noop_casts` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_parentheses` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `ignore_unless_spelled_in_source` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `contains_errors` | `INTEGER` | :heavy_check_mark: | |
| `contains_unexpanded_parameter_pack` | `INTEGER` | :heavy_check_mark: | |
| `best_dynamic_class_type_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `expression_token` | `INTEGER` | :heavy_check_mark: | |
| `obj_c_property` | `INTEGER` | :x: | [`ObjCPropertyRefExpr`](#ObjCPropertyRefExpr) |
| `object_kind` | `INTEGER` | :heavy_check_mark: | [`ExprObjectKind`](#ExprObjectKind) |
| `referenced_declaration_of_callee` | `INTEGER` | :x: | [`Decl`](#Decl) |
| `source_bit_field` | `INTEGER` | :x: | [`FieldDecl`](#FieldDecl) |
| `type` | `INTEGER` | :x: | [`Type`](#Type) |
| `value_kind` | `INTEGER` | :heavy_check_mark: | [`ExprValueKind`](#ExprValueKind) |
| `has_non_trivial_call` | `INTEGER` | :heavy_check_mark: | |
| `is_cxx98_integral_constant_expression` | `INTEGER` | :x: | |
| `is_default_argument` | `INTEGER` | :heavy_check_mark: | |
| `is_gl_value` | `INTEGER` | :heavy_check_mark: | |
| `is_implicit_cxx_this` | `INTEGER` | :heavy_check_mark: | |
| `is_instantiation_dependent` | `INTEGER` | :heavy_check_mark: | |
| `is_integer_constant_expression` | `INTEGER` | :x: | |
| `is_known_to_have_boolean_value` | `INTEGER` | :heavy_check_mark: | |
| `is_l_value` | `INTEGER` | :heavy_check_mark: | |
| `is_objcgc_candidate` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_self_expression` | `INTEGER` | :heavy_check_mark: | |
| `is_ordinary_or_bit_field_object` | `INTEGER` | :heavy_check_mark: | |
| `is_pr_value` | `INTEGER` | :heavy_check_mark: | |
| `is_read_if_discarded_in_c_plus_plus11` | `INTEGER` | :heavy_check_mark: | |
| `is_type_dependent` | `INTEGER` | :heavy_check_mark: | |
| `is_value_dependent` | `INTEGER` | :heavy_check_mark: | |
| `is_x_value` | `INTEGER` | :heavy_check_mark: | |
| `refers_to_bit_field` | `INTEGER` | :heavy_check_mark: | |
| `refers_to_global_register_variable` | `INTEGER` | :heavy_check_mark: | |
| `refers_to_matrix_element` | `INTEGER` | :heavy_check_mark: | |
| `refers_to_vector_element` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ValueStmt`](#ValueStmt).


</details>

<details><summary><a name="DesignatedInitUpdateExpr"></a>DesignatedInitUpdateExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `updater` | `INTEGER` | :heavy_check_mark: | [`InitListExpr`](#InitListExpr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="DesignatedInitExpr"></a>DesignatedInitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `equal_or_colon_token` | `INTEGER` | :heavy_check_mark: | |
| `initializer` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_direct_initializer` | `INTEGER` | :heavy_check_mark: | |
| `uses_gnu_syntax` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="DependentScopeDeclRefExpr"></a>DependentScopeDeclRefExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `l_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `r_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `template_keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `has_explicit_template_arguments` | `INTEGER` | :heavy_check_mark: | |
| `has_template_keyword` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="DependentCoawaitExpr"></a>DependentCoawaitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `operand` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `operator_coawait_lookup` | `INTEGER` | :heavy_check_mark: | [`UnresolvedLookupExpr`](#UnresolvedLookupExpr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="DeclRefExpr"></a>DeclRefExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `declaration` | `INTEGER` | :heavy_check_mark: | [`ValueDecl`](#ValueDecl) |
| `found_declaration` | `INTEGER` | :heavy_check_mark: | [`NamedDecl`](#NamedDecl) |
| `l_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `r_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `template_keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `had_multiple_candidates` | `INTEGER` | :heavy_check_mark: | |
| `has_explicit_template_arguments` | `INTEGER` | :heavy_check_mark: | |
| `has_qualifier` | `INTEGER` | :heavy_check_mark: | |
| `has_template_keyword_and_arguments_info` | `INTEGER` | :heavy_check_mark: | |
| `has_template_keyword` | `INTEGER` | :heavy_check_mark: | |
| `is_non_odr_use` | `INTEGER` | :heavy_check_mark: | [`NonOdrUseReason`](#NonOdrUseReason) |
| `refers_to_enclosing_variable_or_capture` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CoroutineSuspendExpr"></a>CoroutineSuspendExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `common_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `opaque_value` | `INTEGER` | :heavy_check_mark: | [`OpaqueValueExpr`](#OpaqueValueExpr) |
| `ready_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `resume_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `suspend_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CoawaitExpr"></a>CoawaitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `operand` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_implicit` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`CoroutineSuspendExpr`](#CoroutineSuspendExpr).


</details>

<details><summary><a name="CoyieldExpr"></a>CoyieldExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `operand` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`CoroutineSuspendExpr`](#CoroutineSuspendExpr).


</details>

<details><summary><a name="ConvertVectorExpr"></a>ConvertVectorExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `builtin_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `src_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ConceptSpecializationExpr"></a>ConceptSpecializationExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `is_satisfied` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CompoundLiteralExpr"></a>CompoundLiteralExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `initializer` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `is_file_scope` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ChooseExpr"></a>ChooseExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `builtin_token` | `INTEGER` | :heavy_check_mark: | |
| `chosen_sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `lhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `rhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `is_condition_dependent` | `INTEGER` | :heavy_check_mark: | |
| `is_condition_true` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CharacterLiteral"></a>CharacterLiteral</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `character_kind` | `INTEGER` | :heavy_check_mark: | [`CharacterLiteralCharacterKind`](#CharacterLiteralCharacterKind) |
| `token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CastExpr"></a>CastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `cast_kind` | `INTEGER` | :heavy_check_mark: | [`CastKind`](#CastKind) |
| `cast_kind_name` | `TEXT` | :heavy_check_mark: | |
| `conversion_function` | `INTEGER` | :x: | [`NamedDecl`](#NamedDecl) |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `sub_expression_as_written` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `target_union_field` | `INTEGER` | :x: | [`FieldDecl`](#FieldDecl) |
| `has_stored_fp_features` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ImplicitCastExpr"></a>ImplicitCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `is_part_of_explicit_cast` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`CastExpr`](#CastExpr).


</details>

<details><summary><a name="ExplicitCastExpr"></a>ExplicitCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `type_as_written` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |

This table also includes all of the fields contained in [`CastExpr`](#CastExpr).


</details>

<details><summary><a name="CXXNamedCastExpr"></a>CXXNamedCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `cast_name` | `TEXT` | :heavy_check_mark: | |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ExplicitCastExpr`](#ExplicitCastExpr).


</details>

<details><summary><a name="CXXDynamicCastExpr"></a>CXXDynamicCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `is_always_null` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`CXXNamedCastExpr`](#CXXNamedCastExpr).


</details>

<details><summary><a name="CXXConstCastExpr"></a>CXXConstCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`CXXNamedCastExpr`](#CXXNamedCastExpr).


</details>

<details><summary><a name="CXXAddrspaceCastExpr"></a>CXXAddrspaceCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`CXXNamedCastExpr`](#CXXNamedCastExpr).


</details>

<details><summary><a name="CXXStaticCastExpr"></a>CXXStaticCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`CXXNamedCastExpr`](#CXXNamedCastExpr).


</details>

<details><summary><a name="CXXReinterpretCastExpr"></a>CXXReinterpretCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`CXXNamedCastExpr`](#CXXNamedCastExpr).


</details>

<details><summary><a name="CXXFunctionalCastExpr"></a>CXXFunctionalCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `is_list_initialization` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ExplicitCastExpr`](#ExplicitCastExpr).


</details>

<details><summary><a name="CStyleCastExpr"></a>CStyleCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ExplicitCastExpr`](#ExplicitCastExpr).


</details>

<details><summary><a name="BuiltinBitCastExpr"></a>BuiltinBitCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`ExplicitCastExpr`](#ExplicitCastExpr).


</details>

<details><summary><a name="ObjCBridgedCastExpr"></a>ObjCBridgedCastExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `bridge_keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `bridge_kind` | `INTEGER` | :heavy_check_mark: | [`ObjCBridgeCastKind`](#ObjCBridgeCastKind) |
| `bridge_kind_name` | `TEXT` | :heavy_check_mark: | |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ExplicitCastExpr`](#ExplicitCastExpr).


</details>

<details><summary><a name="CallExpr"></a>CallExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `adl_call_kind` | `INTEGER` | :heavy_check_mark: | [`CallExprADLCallKind`](#CallExprADLCallKind) |
| `call_return_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `callee` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `callee_declaration` | `INTEGER` | :x: | [`Decl`](#Decl) |
| `direct_callee` | `INTEGER` | :x: | [`FunctionDecl`](#FunctionDecl) |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `has_stored_fp_features` | `INTEGER` | :heavy_check_mark: | |
| `has_unused_result_attribute` | `INTEGER` | :heavy_check_mark: | |
| `is_builtin_assume_false` | `INTEGER` | :heavy_check_mark: | |
| `is_call_to_std_move` | `INTEGER` | :heavy_check_mark: | |
| `is_unevaluated_builtin_call` | `INTEGER` | :heavy_check_mark: | |
| `uses_adl` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXOperatorCallExpr"></a>CXXOperatorCallExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `operator_` | `INTEGER` | :heavy_check_mark: | [`OverloadedOperatorKind`](#OverloadedOperatorKind) |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `is_assignment_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_comparison_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_infix_binary_operation` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`CallExpr`](#CallExpr).


</details>

<details><summary><a name="CXXMemberCallExpr"></a>CXXMemberCallExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `implicit_object_argument` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `method_declaration` | `INTEGER` | :x: | [`CXXMethodDecl`](#CXXMethodDecl) |
| `object_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `record_declaration` | `INTEGER` | :heavy_check_mark: | [`CXXRecordDecl`](#CXXRecordDecl) |

This table also includes all of the fields contained in [`CallExpr`](#CallExpr).


</details>

<details><summary><a name="CUDAKernelCallExpr"></a>CUDAKernelCallExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `config` | `INTEGER` | :heavy_check_mark: | [`CallExpr`](#CallExpr) |

This table also includes all of the fields contained in [`CallExpr`](#CallExpr).


</details>

<details><summary><a name="UserDefinedLiteral"></a>UserDefinedLiteral</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `cooked_literal` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `literal_operator_kind` | `INTEGER` | :heavy_check_mark: | [`UserDefinedLiteralLiteralOperatorKind`](#UserDefinedLiteralLiteralOperatorKind) |
| `ud_suffix_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`CallExpr`](#CallExpr).


</details>

<details><summary><a name="CXXUuidofExpr"></a>CXXUuidofExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `expression_operand` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `guid_declaration` | `INTEGER` | :heavy_check_mark: | [`MSGuidDecl`](#MSGuidDecl) |
| `type_operand` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `type_operand_source_info` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_type_operand` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXUnresolvedConstructExpr"></a>CXXUnresolvedConstructExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `type_as_written` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_list_initialization` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXTypeidExpr"></a>CXXTypeidExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `expression_operand` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `type_operand` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `type_operand_source_info` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_most_derived` | `INTEGER` | :x: | |
| `is_potentially_evaluated` | `INTEGER` | :heavy_check_mark: | |
| `is_type_operand` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXThrowExpr"></a>CXXThrowExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `sub_expression` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `throw_token` | `INTEGER` | :heavy_check_mark: | |
| `is_thrown_variable_in_scope` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXThisExpr"></a>CXXThisExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `is_implicit` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXStdInitializerListExpr"></a>CXXStdInitializerListExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXScalarValueInitExpr"></a>CXXScalarValueInitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXRewrittenBinaryOperator"></a>CXXRewrittenBinaryOperator</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `lhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `opcode` | `INTEGER` | :heavy_check_mark: | [`BinaryOperatorKind`](#BinaryOperatorKind) |
| `opcode_string` | `TEXT` | :heavy_check_mark: | |
| `operator_` | `INTEGER` | :heavy_check_mark: | [`BinaryOperatorKind`](#BinaryOperatorKind) |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `rhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `semantic_form` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_assignment_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_comparison_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_reversed` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXPseudoDestructorExpr"></a>CXXPseudoDestructorExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `colon_colon_token` | `INTEGER` | :heavy_check_mark: | |
| `destroyed_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `destroyed_type_token` | `INTEGER` | :heavy_check_mark: | |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `scope_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `tilde_token` | `INTEGER` | :heavy_check_mark: | |
| `has_qualifier` | `INTEGER` | :heavy_check_mark: | |
| `is_arrow` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXNullPtrLiteralExpr"></a>CXXNullPtrLiteralExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXNoexceptExpr"></a>CXXNoexceptExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `operand` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `value` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXNewExpr"></a>CXXNewExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `does_usual_array_delete_want_size` | `INTEGER` | :heavy_check_mark: | |
| `allocated_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `array_size` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `construct_expression` | `INTEGER` | :x: | [`CXXConstructExpr`](#CXXConstructExpr) |
| `initialization_style` | `INTEGER` | :heavy_check_mark: | [`CXXNewExprInitializationStyle`](#CXXNewExprInitializationStyle) |
| `initializer` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `operator_delete` | `INTEGER` | :heavy_check_mark: | [`FunctionDecl`](#FunctionDecl) |
| `operator_new` | `INTEGER` | :heavy_check_mark: | [`FunctionDecl`](#FunctionDecl) |
| `has_initializer` | `INTEGER` | :heavy_check_mark: | |
| `is_array` | `INTEGER` | :heavy_check_mark: | |
| `is_global_new` | `INTEGER` | :heavy_check_mark: | |
| `is_parenthesis_type_id` | `INTEGER` | :heavy_check_mark: | |
| `pass_alignment` | `INTEGER` | :heavy_check_mark: | |
| `should_null_check_allocation` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXInheritedCtorInitExpr"></a>CXXInheritedCtorInitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `constructs_virtual_base` | `INTEGER` | :heavy_check_mark: | |
| `construction_kind` | `INTEGER` | :heavy_check_mark: | [`CXXConstructExprConstructionKind`](#CXXConstructExprConstructionKind) |
| `constructor` | `INTEGER` | :heavy_check_mark: | [`CXXConstructorDecl`](#CXXConstructorDecl) |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `inherited_from_virtual_base` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXFoldExpr"></a>CXXFoldExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `callee` | `INTEGER` | :heavy_check_mark: | [`UnresolvedLookupExpr`](#UnresolvedLookupExpr) |
| `ellipsis_token` | `INTEGER` | :heavy_check_mark: | |
| `initializer` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `lhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `num_expansions` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `operator_` | `INTEGER` | :heavy_check_mark: | [`BinaryOperatorKind`](#BinaryOperatorKind) |
| `pattern` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `rhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `is_left_fold` | `INTEGER` | :heavy_check_mark: | |
| `is_right_fold` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXDependentScopeMemberExpr"></a>CXXDependentScopeMemberExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `base_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `first_qualifier_found_in_scope` | `INTEGER` | :x: | [`NamedDecl`](#NamedDecl) |
| `l_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `member_token` | `INTEGER` | :heavy_check_mark: | |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `r_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `template_keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `has_explicit_template_arguments` | `INTEGER` | :heavy_check_mark: | |
| `has_template_keyword` | `INTEGER` | :heavy_check_mark: | |
| `is_arrow` | `INTEGER` | :heavy_check_mark: | |
| `is_implicit_access` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXDeleteExpr"></a>CXXDeleteExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `does_usual_array_delete_want_size` | `INTEGER` | :heavy_check_mark: | |
| `argument` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `destroyed_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `operator_delete` | `INTEGER` | :heavy_check_mark: | [`FunctionDecl`](#FunctionDecl) |
| `is_array_form` | `INTEGER` | :heavy_check_mark: | |
| `is_array_form_as_written` | `INTEGER` | :heavy_check_mark: | |
| `is_global_delete` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXDefaultInitExpr"></a>CXXDefaultInitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `expression` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `field` | `INTEGER` | :heavy_check_mark: | [`FieldDecl`](#FieldDecl) |
| `used_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXDefaultArgExpr"></a>CXXDefaultArgExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `parameter` | `INTEGER` | :heavy_check_mark: | [`ParmVarDecl`](#ParmVarDecl) |
| `used_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXConstructExpr"></a>CXXConstructExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `construction_kind` | `INTEGER` | :heavy_check_mark: | [`CXXConstructExprConstructionKind`](#CXXConstructExprConstructionKind) |
| `constructor` | `INTEGER` | :heavy_check_mark: | [`CXXConstructorDecl`](#CXXConstructorDecl) |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `had_multiple_candidates` | `INTEGER` | :heavy_check_mark: | |
| `is_elidable` | `INTEGER` | :heavy_check_mark: | |
| `is_list_initialization` | `INTEGER` | :heavy_check_mark: | |
| `is_std_initializer_list_initialization` | `INTEGER` | :heavy_check_mark: | |
| `requires_zero_initialization` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXTemporaryObjectExpr"></a>CXXTemporaryObjectExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`CXXConstructExpr`](#CXXConstructExpr).


</details>

<details><summary><a name="CXXBoolLiteralExpr"></a>CXXBoolLiteralExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `value` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CXXBindTemporaryExpr"></a>CXXBindTemporaryExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="BlockExpr"></a>BlockExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `block_declaration` | `INTEGER` | :heavy_check_mark: | [`BlockDecl`](#BlockDecl) |
| `body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `caret_token` | `INTEGER` | :heavy_check_mark: | |
| `function_type` | `INTEGER` | :heavy_check_mark: | [`FunctionProtoType`](#FunctionProtoType) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="BinaryOperator"></a>BinaryOperator</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `lhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `opcode` | `INTEGER` | :heavy_check_mark: | [`BinaryOperatorKind`](#BinaryOperatorKind) |
| `opcode_string` | `TEXT` | :heavy_check_mark: | |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `rhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_stored_fp_features` | `INTEGER` | :heavy_check_mark: | |
| `is_additive_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_assignment_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_bitwise_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_comma_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_comparison_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_compound_assignment_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_equality_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_logical_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_multiplicative_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_pointer_memory_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_relational_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_shift_assign_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_shift_operation` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="CompoundAssignOperator"></a>CompoundAssignOperator</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `computation_lhs_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `computation_result_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |

This table also includes all of the fields contained in [`BinaryOperator`](#BinaryOperator).


</details>

<details><summary><a name="AtomicExpr"></a>AtomicExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `builtin_token` | `INTEGER` | :heavy_check_mark: | |
| `operation` | `INTEGER` | :heavy_check_mark: | [`AtomicExprAtomicOp`](#AtomicExprAtomicOp) |
| `order` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `order_fail` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `pointer` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `scope` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `value1` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `value2` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `value_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `weak` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `is_cmp_x_chg` | `INTEGER` | :heavy_check_mark: | |
| `is_open_cl` | `INTEGER` | :heavy_check_mark: | |
| `is_volatile` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="AsTypeExpr"></a>AsTypeExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `builtin_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `src_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ArrayTypeTraitExpr"></a>ArrayTypeTraitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `dimension_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `queried_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `trait` | `INTEGER` | :heavy_check_mark: | [`ArrayTypeTrait`](#ArrayTypeTrait) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ArraySubscriptExpr"></a>ArraySubscriptExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `index` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `lhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `r_bracket_token` | `INTEGER` | :heavy_check_mark: | |
| `rhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ArrayInitLoopExpr"></a>ArrayInitLoopExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `common_expression` | `INTEGER` | :heavy_check_mark: | [`OpaqueValueExpr`](#OpaqueValueExpr) |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ArrayInitIndexExpr"></a>ArrayInitIndexExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="AddrLabelExpr"></a>AddrLabelExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `amp_amp_token` | `INTEGER` | :heavy_check_mark: | |
| `label` | `INTEGER` | :heavy_check_mark: | [`LabelDecl`](#LabelDecl) |
| `label_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="AbstractConditionalOperator"></a>AbstractConditionalOperator</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `colon_token` | `INTEGER` | :heavy_check_mark: | |
| `condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `false_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `question_token` | `INTEGER` | :heavy_check_mark: | |
| `true_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ConditionalOperator"></a>ConditionalOperator</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `lhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `rhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`AbstractConditionalOperator`](#AbstractConditionalOperator).


</details>

<details><summary><a name="BinaryConditionalOperator"></a>BinaryConditionalOperator</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `common` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `opaque_value` | `INTEGER` | :heavy_check_mark: | [`OpaqueValueExpr`](#OpaqueValueExpr) |

This table also includes all of the fields contained in [`AbstractConditionalOperator`](#AbstractConditionalOperator).


</details>

<details><summary><a name="VAArgExpr"></a>VAArgExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `builtin_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `written_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_microsoft_abi` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="UnaryOperator"></a>UnaryOperator</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `can_overflow` | `INTEGER` | :heavy_check_mark: | |
| `opcode` | `INTEGER` | :heavy_check_mark: | [`UnaryOperatorKind`](#UnaryOperatorKind) |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `has_stored_fp_features` | `INTEGER` | :heavy_check_mark: | |
| `is_arithmetic_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_decrement_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_increment_decrement_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_increment_operation` | `INTEGER` | :heavy_check_mark: | |
| `is_postfix` | `INTEGER` | :heavy_check_mark: | |
| `is_prefix` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="UnaryExprOrTypeTraitExpr"></a>UnaryExprOrTypeTraitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `argument_expression` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `argument_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `expression_or_trait_kind` | `INTEGER` | :heavy_check_mark: | [`UnaryExprOrTypeTrait`](#UnaryExprOrTypeTrait) |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `type_of_argument` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_argument_type` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="TypoExpr"></a>TypoExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="TypeTraitExpr"></a>TypeTraitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `trait` | `INTEGER` | :heavy_check_mark: | [`TypeTrait`](#TypeTrait) |
| `value` | `INTEGER` | :x: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="SubstNonTypeTemplateParmPackExpr"></a>SubstNonTypeTemplateParmPackExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `parameter_pack` | `INTEGER` | :heavy_check_mark: | [`NonTypeTemplateParmDecl`](#NonTypeTemplateParmDecl) |
| `parameter_pack_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="SubstNonTypeTemplateParmExpr"></a>SubstNonTypeTemplateParmExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `name_token` | `INTEGER` | :heavy_check_mark: | |
| `parameter` | `INTEGER` | :heavy_check_mark: | [`NonTypeTemplateParmDecl`](#NonTypeTemplateParmDecl) |
| `parameter_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `replacement` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_reference_parameter` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="StringLiteral"></a>StringLiteral</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `contains_non_ascii` | `INTEGER` | :x: | |
| `contains_non_ascii_or_null` | `INTEGER` | :x: | |
| `bytes` | `TEXT` | :heavy_check_mark: | |
| `string_kind` | `INTEGER` | :heavy_check_mark: | [`StringLiteralStringKind`](#StringLiteralStringKind) |
| `string` | `TEXT` | :x: | |
| `is_ascii` | `INTEGER` | :heavy_check_mark: | |
| `is_pascal` | `INTEGER` | :heavy_check_mark: | |
| `is_utf16` | `INTEGER` | :heavy_check_mark: | |
| `is_utf32` | `INTEGER` | :heavy_check_mark: | |
| `is_utf8` | `INTEGER` | :heavy_check_mark: | |
| `is_wide` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="StmtExpr"></a>StmtExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `sub_statement` | `INTEGER` | :heavy_check_mark: | [`CompoundStmt`](#CompoundStmt) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="SourceLocExpr"></a>SourceLocExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `builtin_string` | `TEXT` | :heavy_check_mark: | |
| `identifier_kind` | `INTEGER` | :heavy_check_mark: | [`SourceLocExprIdentKind`](#SourceLocExprIdentKind) |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `is_int_type` | `INTEGER` | :heavy_check_mark: | |
| `is_string_type` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="SizeOfPackExpr"></a>SizeOfPackExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `pack` | `INTEGER` | :heavy_check_mark: | [`NamedDecl`](#NamedDecl) |
| `pack_length` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `pack_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `is_partially_substituted` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ShuffleVectorExpr"></a>ShuffleVectorExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `builtin_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="SYCLUniqueStableNameExpr"></a>SYCLUniqueStableNameExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `compute_name` | `TEXT` | :heavy_check_mark: | |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="RequiresExpr"></a>RequiresExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `body` | `INTEGER` | :heavy_check_mark: | [`RequiresExprBodyDecl`](#RequiresExprBodyDecl) |
| `r_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `requires_keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `is_satisfied` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="RecoveryExpr"></a>RecoveryExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="PseudoObjectExpr"></a>PseudoObjectExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `result_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `syntactic_form` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="PredefinedExpr"></a>PredefinedExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `function_name` | `INTEGER` | :heavy_check_mark: | [`StringLiteral`](#StringLiteral) |
| `identifier_kind` | `INTEGER` | :heavy_check_mark: | [`PredefinedExprIdentKind`](#PredefinedExprIdentKind) |
| `identifier_kind_name` | `TEXT` | :heavy_check_mark: | |
| `token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ParenListExpr"></a>ParenListExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ParenExpr"></a>ParenExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="PackExpansionExpr"></a>PackExpansionExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `ellipsis_token` | `INTEGER` | :heavy_check_mark: | |
| `num_expansions` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `pattern` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="OverloadExpr"></a>OverloadExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `l_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `name_token` | `INTEGER` | :heavy_check_mark: | |
| `naming_class` | `INTEGER` | :x: | [`CXXRecordDecl`](#CXXRecordDecl) |
| `r_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `template_keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `has_explicit_template_arguments` | `INTEGER` | :heavy_check_mark: | |
| `has_template_keyword` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="UnresolvedMemberExpr"></a>UnresolvedMemberExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `base_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `member_token` | `INTEGER` | :heavy_check_mark: | |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `has_unresolved_using` | `INTEGER` | :heavy_check_mark: | |
| `is_arrow` | `INTEGER` | :heavy_check_mark: | |
| `is_implicit_access` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OverloadExpr`](#OverloadExpr).


</details>

<details><summary><a name="UnresolvedLookupExpr"></a>UnresolvedLookupExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `is_overloaded` | `INTEGER` | :heavy_check_mark: | |
| `requires_adl` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`OverloadExpr`](#OverloadExpr).


</details>

<details><summary><a name="OpaqueValueExpr"></a>OpaqueValueExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `source_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_unique` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="OffsetOfExpr"></a>OffsetOfExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCSubscriptRefExpr"></a>ObjCSubscriptRefExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_index_method_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |
| `base_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `key_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `r_bracket_token` | `INTEGER` | :heavy_check_mark: | |
| `is_array_subscript_reference_expression` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCStringLiteral"></a>ObjCStringLiteral</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_token` | `INTEGER` | :heavy_check_mark: | |
| `string` | `INTEGER` | :heavy_check_mark: | [`StringLiteral`](#StringLiteral) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCSelectorExpr"></a>ObjCSelectorExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCProtocolExpr"></a>ObjCProtocolExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_token` | `INTEGER` | :heavy_check_mark: | |
| `protocol` | `INTEGER` | :heavy_check_mark: | [`ObjCProtocolDecl`](#ObjCProtocolDecl) |
| `protocol_id_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCPropertyRefExpr"></a>ObjCPropertyRefExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `class_receiver` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |
| `explicit_property` | `INTEGER` | :heavy_check_mark: | [`ObjCPropertyDecl`](#ObjCPropertyDecl) |
| `implicit_property_getter` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |
| `implicit_property_setter` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `receiver_token` | `INTEGER` | :heavy_check_mark: | |
| `receiver_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `super_receiver_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_class_receiver` | `INTEGER` | :heavy_check_mark: | |
| `is_explicit_property` | `INTEGER` | :heavy_check_mark: | |
| `is_implicit_property` | `INTEGER` | :heavy_check_mark: | |
| `is_messaging_getter` | `INTEGER` | :heavy_check_mark: | |
| `is_messaging_setter` | `INTEGER` | :heavy_check_mark: | |
| `is_object_receiver` | `INTEGER` | :heavy_check_mark: | |
| `is_super_receiver` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCMessageExpr"></a>ObjCMessageExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `call_return_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `class_receiver` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `class_receiver_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `instance_receiver` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `left_token` | `INTEGER` | :heavy_check_mark: | |
| `method_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |
| `method_family` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodFamily`](#ObjCMethodFamily) |
| `receiver_interface` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |
| `receiver_kind` | `INTEGER` | :heavy_check_mark: | [`ObjCMessageExprReceiverKind`](#ObjCMessageExprReceiverKind) |
| `receiver_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `right_token` | `INTEGER` | :heavy_check_mark: | |
| `selector_start_token` | `INTEGER` | :heavy_check_mark: | |
| `super_token` | `INTEGER` | :heavy_check_mark: | |
| `super_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_class_message` | `INTEGER` | :heavy_check_mark: | |
| `is_delegate_initializer_call` | `INTEGER` | :heavy_check_mark: | |
| `is_implicit` | `INTEGER` | :heavy_check_mark: | |
| `is_instance_message` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCIvarRefExpr"></a>ObjCIvarRefExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCIvarDecl`](#ObjCIvarDecl) |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `operation_token` | `INTEGER` | :heavy_check_mark: | |
| `is_arrow` | `INTEGER` | :heavy_check_mark: | |
| `is_free_instance_variable` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCIsaExpr"></a>ObjCIsaExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `base_token_end` | `INTEGER` | :heavy_check_mark: | |
| `isa_member_token` | `INTEGER` | :heavy_check_mark: | |
| `operation_token` | `INTEGER` | :heavy_check_mark: | |
| `is_arrow` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCIndirectCopyRestoreExpr"></a>ObjCIndirectCopyRestoreExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `should_copy` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCEncodeExpr"></a>ObjCEncodeExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_token` | `INTEGER` | :heavy_check_mark: | |
| `encoded_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCDictionaryLiteral"></a>ObjCDictionaryLiteral</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `dictionary_with_objects_method` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCBoxedExpr"></a>ObjCBoxedExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_token` | `INTEGER` | :heavy_check_mark: | |
| `boxing_method` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_expressible_as_constant_initializer` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCBoolLiteralExpr"></a>ObjCBoolLiteralExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `value` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCAvailabilityCheckExpr"></a>ObjCAvailabilityCheckExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `has_version` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ObjCArrayLiteral"></a>ObjCArrayLiteral</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `array_with_objects_method` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="OMPIteratorExpr"></a>OMPIteratorExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `iterator_kw_token` | `INTEGER` | :heavy_check_mark: | |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="OMPArrayShapingExpr"></a>OMPArrayShapingExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="OMPArraySectionExpr"></a>OMPArraySectionExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `first_colon_token` | `INTEGER` | :heavy_check_mark: | |
| `second_colon_token` | `INTEGER` | :heavy_check_mark: | |
| `length` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `lower_bound` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `r_bracket_token` | `INTEGER` | :heavy_check_mark: | |
| `stride` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="NoInitExpr"></a>NoInitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="MemberExpr"></a>MemberExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `l_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `member_declaration` | `INTEGER` | :heavy_check_mark: | [`ValueDecl`](#ValueDecl) |
| `member_token` | `INTEGER` | :heavy_check_mark: | |
| `operator_token` | `INTEGER` | :heavy_check_mark: | |
| `r_angle_token` | `INTEGER` | :heavy_check_mark: | |
| `template_keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `had_multiple_candidates` | `INTEGER` | :heavy_check_mark: | |
| `has_explicit_template_arguments` | `INTEGER` | :heavy_check_mark: | |
| `has_qualifier` | `INTEGER` | :heavy_check_mark: | |
| `has_template_keyword` | `INTEGER` | :heavy_check_mark: | |
| `is_arrow` | `INTEGER` | :heavy_check_mark: | |
| `is_implicit_access` | `INTEGER` | :heavy_check_mark: | |
| `is_non_odr_use` | `INTEGER` | :heavy_check_mark: | [`NonOdrUseReason`](#NonOdrUseReason) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="MatrixSubscriptExpr"></a>MatrixSubscriptExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `column_index` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `r_bracket_token` | `INTEGER` | :heavy_check_mark: | |
| `row_index` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_incomplete` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="MaterializeTemporaryExpr"></a>MaterializeTemporaryExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `extending_declaration` | `INTEGER` | :x: | [`ValueDecl`](#ValueDecl) |
| `lifetime_extended_temporary_declaration` | `INTEGER` | :x: | [`LifetimeExtendedTemporaryDecl`](#LifetimeExtendedTemporaryDecl) |
| `storage_duration` | `INTEGER` | :heavy_check_mark: | [`StorageDuration`](#StorageDuration) |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_bound_to_lvalue_reference` | `INTEGER` | :heavy_check_mark: | |
| `is_usable_in_constant_expressions` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="MSPropertySubscriptExpr"></a>MSPropertySubscriptExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `index` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `r_bracket_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="MSPropertyRefExpr"></a>MSPropertyRefExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `base_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `member_token` | `INTEGER` | :heavy_check_mark: | |
| `property_declaration` | `INTEGER` | :heavy_check_mark: | [`MSPropertyDecl`](#MSPropertyDecl) |
| `is_arrow` | `INTEGER` | :heavy_check_mark: | |
| `is_implicit_access` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="LambdaExpr"></a>LambdaExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `call_operator` | `INTEGER` | :heavy_check_mark: | [`CXXMethodDecl`](#CXXMethodDecl) |
| `capture_default` | `INTEGER` | :heavy_check_mark: | [`LambdaCaptureDefault`](#LambdaCaptureDefault) |
| `capture_default_token` | `INTEGER` | :heavy_check_mark: | |
| `compound_statement_body` | `INTEGER` | :heavy_check_mark: | [`CompoundStmt`](#CompoundStmt) |
| `lambda_class` | `INTEGER` | :heavy_check_mark: | [`CXXRecordDecl`](#CXXRecordDecl) |
| `trailing_requires_clause` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `has_explicit_parameters` | `INTEGER` | :heavy_check_mark: | |
| `has_explicit_result_type` | `INTEGER` | :heavy_check_mark: | |
| `is_generic_lambda` | `INTEGER` | :heavy_check_mark: | |
| `is_mutable` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="IntegerLiteral"></a>IntegerLiteral</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="InitListExpr"></a>InitListExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `array_filler` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `initialized_field_in_union` | `INTEGER` | :x: | [`FieldDecl`](#FieldDecl) |
| `l_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `r_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `semantic_form` | `INTEGER` | :x: | [`InitListExpr`](#InitListExpr) |
| `syntactic_form` | `INTEGER` | :x: | [`InitListExpr`](#InitListExpr) |
| `had_array_range_designator` | `INTEGER` | :heavy_check_mark: | |
| `has_array_filler` | `INTEGER` | :heavy_check_mark: | |
| `is_explicit` | `INTEGER` | :heavy_check_mark: | |
| `is_semantic_form` | `INTEGER` | :heavy_check_mark: | |
| `is_string_literal_initializer` | `INTEGER` | :heavy_check_mark: | |
| `is_syntactic_form` | `INTEGER` | :heavy_check_mark: | |
| `is_transparent` | `INTEGER` | :x: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ImplicitValueInitExpr"></a>ImplicitValueInitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ImaginaryLiteral"></a>ImaginaryLiteral</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="GenericSelectionExpr"></a>GenericSelectionExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `controlling_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `default_token` | `INTEGER` | :heavy_check_mark: | |
| `generic_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `result_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_result_dependent` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="GNUNullExpr"></a>GNUNullExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `token_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="FunctionParmPackExpr"></a>FunctionParmPackExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `parameter_pack` | `INTEGER` | :heavy_check_mark: | [`VarDecl`](#VarDecl) |
| `parameter_pack_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="FullExpr"></a>FullExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `sub_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ExprWithCleanups"></a>ExprWithCleanups</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `cleanups_have_side_effects` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`FullExpr`](#FullExpr).


</details>

<details><summary><a name="ConstantExpr"></a>ConstantExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `result_storage_kind` | `INTEGER` | :heavy_check_mark: | [`ConstantExprResultStorageKind`](#ConstantExprResultStorageKind) |
| `has_ap_value_result` | `INTEGER` | :heavy_check_mark: | |
| `is_immediate_invocation` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`FullExpr`](#FullExpr).


</details>

<details><summary><a name="FloatingLiteral"></a>FloatingLiteral</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `token` | `INTEGER` | :heavy_check_mark: | |
| `is_exact` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="FixedPointLiteral"></a>FixedPointLiteral</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ExtVectorElementExpr"></a>ExtVectorElementExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `contains_duplicate_elements` | `INTEGER` | :heavy_check_mark: | |
| `accessor_token` | `INTEGER` | :heavy_check_mark: | |
| `base` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_arrow` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="ExpressionTraitExpr"></a>ExpressionTraitExpr</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `queried_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `trait` | `INTEGER` | :heavy_check_mark: | [`ExpressionTrait`](#ExpressionTrait) |
| `value` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Expr`](#Expr).


</details>

<details><summary><a name="AttributedStmt"></a>AttributedStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `attribute_token` | `INTEGER` | :heavy_check_mark: | |
| `sub_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`ValueStmt`](#ValueStmt).


</details>

<details><summary><a name="SwitchStmt"></a>SwitchStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `body` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |
| `condition` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `condition_variable` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |
| `condition_variable_declaration_statement` | `INTEGER` | :x: | [`DeclStmt`](#DeclStmt) |
| `initializer` | `INTEGER` | :x: | [`Stmt`](#Stmt) |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `first_switch_case` | `INTEGER` | :x: | [`SwitchCase`](#SwitchCase) |
| `switch_token` | `INTEGER` | :heavy_check_mark: | |
| `has_initializer_storage` | `INTEGER` | :heavy_check_mark: | |
| `has_variable_storage` | `INTEGER` | :heavy_check_mark: | |
| `is_all_enum_cases_covered` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="SwitchCase"></a>SwitchCase</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `colon_token` | `INTEGER` | :heavy_check_mark: | |
| `keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `next_switch_case` | `INTEGER` | :x: | [`SwitchCase`](#SwitchCase) |
| `sub_statement` | `INTEGER` | :heavy_check_mark: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`Stmt`](#Stmt).


</details>

<details><summary><a name="DefaultStmt"></a>DefaultStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `default_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`SwitchCase`](#SwitchCase).


</details>

<details><summary><a name="CaseStmt"></a>CaseStmt</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `case_statement_is_gnu_range` | `INTEGER` | :heavy_check_mark: | |
| `case_token` | `INTEGER` | :heavy_check_mark: | |
| `ellipsis_token` | `INTEGER` | :heavy_check_mark: | |
| `lhs` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `rhs` | `INTEGER` | :x: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`SwitchCase`](#SwitchCase).


</details>

<details><summary><a name="Decl"></a>Decl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `is_definition` | `INTEGER` | :heavy_check_mark: | |
| `access` | `INTEGER` | :heavy_check_mark: | [`AccessSpecifier`](#AccessSpecifier) |
| `availability` | `INTEGER` | :heavy_check_mark: | [`AvailabilityResult`](#AvailabilityResult) |
| `friend_object_kind` | `INTEGER` | :heavy_check_mark: | [`DeclFriendObjectKind`](#DeclFriendObjectKind) |
| `function_type` | `INTEGER` | :x: | [`FunctionType`](#FunctionType) |
| `module_ownership_kind` | `INTEGER` | :heavy_check_mark: | [`DeclModuleOwnershipKind`](#DeclModuleOwnershipKind) |
| `non_closure_context` | `INTEGER` | :x: | [`Decl`](#Decl) |
| `has_attributes` | `INTEGER` | :heavy_check_mark: | |
| `has_defining_attribute` | `INTEGER` | :heavy_check_mark: | |
| `has_owning_module` | `INTEGER` | :heavy_check_mark: | |
| `has_tag_identifier_namespace` | `INTEGER` | :heavy_check_mark: | |
| `is_defined_outside_function_or_method` | `INTEGER` | :heavy_check_mark: | |
| `is_deprecated` | `INTEGER` | :heavy_check_mark: | |
| `is_function_or_function_template` | `INTEGER` | :heavy_check_mark: | |
| `is_implicit` | `INTEGER` | :heavy_check_mark: | |
| `is_in_anonymous_namespace` | `INTEGER` | :heavy_check_mark: | |
| `is_in_export_declaration_context` | `INTEGER` | :heavy_check_mark: | |
| `is_in_local_scope_for_instantiation` | `INTEGER` | :heavy_check_mark: | |
| `is_in_std_namespace` | `INTEGER` | :heavy_check_mark: | |
| `is_invalid_declaration` | `INTEGER` | :heavy_check_mark: | |
| `is_module_private` | `INTEGER` | :heavy_check_mark: | |
| `is_out_of_line` | `INTEGER` | :heavy_check_mark: | |
| `is_parameter_pack` | `INTEGER` | :heavy_check_mark: | |
| `is_template_declaration` | `INTEGER` | :heavy_check_mark: | |
| `is_template_parameter` | `INTEGER` | :heavy_check_mark: | |
| `is_template_parameter_pack` | `INTEGER` | :heavy_check_mark: | |
| `is_templated` | `INTEGER` | :heavy_check_mark: | |
| `is_top_level_declaration_in_obj_c_container` | `INTEGER` | :heavy_check_mark: | |
| `is_unavailable` | `INTEGER` | :heavy_check_mark: | |
| `is_unconditionally_visible` | `INTEGER` | :heavy_check_mark: | |
| `is_weak_imported` | `INTEGER` | :heavy_check_mark: | |
| `kind` | `INTEGER` | :heavy_check_mark: | [`DeclKind`](#DeclKind) |
| `category` | `INTEGER` | :heavy_check_mark: | [`DeclCategory`](#DeclCategory) |
| `token` | `INTEGER` | :heavy_check_mark: | |

</details>

<details><summary><a name="ClassScopeFunctionSpecializationDecl"></a>ClassScopeFunctionSpecializationDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `specialization` | `INTEGER` | :heavy_check_mark: | [`CXXMethodDecl`](#CXXMethodDecl) |
| `has_explicit_template_arguments` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="CapturedDecl"></a>CapturedDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `context_parameter` | `INTEGER` | :heavy_check_mark: | [`ImplicitParamDecl`](#ImplicitParamDecl) |
| `is_nothrow` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="BlockDecl"></a>BlockDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `block_missing_return_type` | `INTEGER` | :heavy_check_mark: | |
| `can_avoid_copy_to_heap` | `INTEGER` | :heavy_check_mark: | |
| `captures_cxx_this` | `INTEGER` | :heavy_check_mark: | |
| `does_not_escape` | `INTEGER` | :heavy_check_mark: | |
| `block_mangling_context_declaration` | `INTEGER` | :x: | [`Decl`](#Decl) |
| `caret_token` | `INTEGER` | :heavy_check_mark: | |
| `compound_body` | `INTEGER` | :heavy_check_mark: | [`CompoundStmt`](#CompoundStmt) |
| `signature_as_written` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `has_captures` | `INTEGER` | :heavy_check_mark: | |
| `is_conversion_from_lambda` | `INTEGER` | :heavy_check_mark: | |
| `is_variadic` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="AccessSpecDecl"></a>AccessSpecDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `access_specifier_token` | `INTEGER` | :heavy_check_mark: | |
| `colon_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="OMPDeclarativeDirectiveDecl"></a>OMPDeclarativeDirectiveDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="OMPThreadPrivateDecl"></a>OMPThreadPrivateDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPDeclarativeDirectiveDecl`](#OMPDeclarativeDirectiveDecl).


</details>

<details><summary><a name="OMPRequiresDecl"></a>OMPRequiresDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPDeclarativeDirectiveDecl`](#OMPDeclarativeDirectiveDecl).


</details>

<details><summary><a name="OMPAllocateDecl"></a>OMPAllocateDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`OMPDeclarativeDirectiveDecl`](#OMPDeclarativeDirectiveDecl).


</details>

<details><summary><a name="TranslationUnitDecl"></a>TranslationUnitDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="StaticAssertDecl"></a>StaticAssertDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `assert_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `message` | `INTEGER` | :heavy_check_mark: | [`StringLiteral`](#StringLiteral) |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `is_failed` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="RequiresExprBodyDecl"></a>RequiresExprBodyDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="PragmaDetectMismatchDecl"></a>PragmaDetectMismatchDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `name` | `TEXT` | :heavy_check_mark: | |
| `value` | `TEXT` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="PragmaCommentDecl"></a>PragmaCommentDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `argument` | `TEXT` | :heavy_check_mark: | |
| `comment_kind` | `INTEGER` | :heavy_check_mark: | [`PragmaMSCommentKind`](#PragmaMSCommentKind) |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="ObjCPropertyImplDecl"></a>ObjCPropertyImplDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `getter_cxx_constructor` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `getter_method_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |
| `property_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCPropertyDecl`](#ObjCPropertyDecl) |
| `property_implementation` | `INTEGER` | :heavy_check_mark: | [`ObjCPropertyImplDeclKind`](#ObjCPropertyImplDeclKind) |
| `property_instance_variable_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCIvarDecl`](#ObjCIvarDecl) |
| `property_instance_variable_declaration_token` | `INTEGER` | :heavy_check_mark: | |
| `setter_cxx_assignment` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `setter_method_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |
| `is_instance_variable_name_specified` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="NamedDecl"></a>NamedDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `formal_linkage` | `INTEGER` | :heavy_check_mark: | [`Linkage`](#Linkage) |
| `name` | `TEXT` | :heavy_check_mark: | |
| `obj_cf_string_formatting_family` | `INTEGER` | :x: | |
| `qualified_name_as_string` | `TEXT` | :heavy_check_mark: | |
| `underlying_declaration` | `INTEGER` | :heavy_check_mark: | [`NamedDecl`](#NamedDecl) |
| `visibility` | `INTEGER` | :heavy_check_mark: | [`Visibility`](#Visibility) |
| `has_external_formal_linkage` | `INTEGER` | :heavy_check_mark: | |
| `has_linkage` | `INTEGER` | :heavy_check_mark: | |
| `has_linkage_been_computed` | `INTEGER` | :heavy_check_mark: | |
| `is_cxx_class_member` | `INTEGER` | :heavy_check_mark: | |
| `is_cxx_instance_member` | `INTEGER` | :heavy_check_mark: | |
| `is_externally_declarable` | `INTEGER` | :heavy_check_mark: | |
| `is_externally_visible` | `INTEGER` | :heavy_check_mark: | |
| `is_linkage_valid` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="LabelDecl"></a>LabelDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `ms_assembly_label` | `TEXT` | :heavy_check_mark: | |
| `statement` | `INTEGER` | :heavy_check_mark: | [`LabelStmt`](#LabelStmt) |
| `is_gnu_local` | `INTEGER` | :heavy_check_mark: | |
| `is_ms_assembly_label` | `INTEGER` | :heavy_check_mark: | |
| `is_resolved_ms_assembly_label` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="BaseUsingDecl"></a>BaseUsingDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="UsingEnumDecl"></a>UsingEnumDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `enum_declaration` | `INTEGER` | :heavy_check_mark: | [`EnumDecl`](#EnumDecl) |
| `enum_token` | `INTEGER` | :heavy_check_mark: | |
| `using_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`BaseUsingDecl`](#BaseUsingDecl).


</details>

<details><summary><a name="UsingDecl"></a>UsingDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `using_token` | `INTEGER` | :heavy_check_mark: | |
| `has_typename` | `INTEGER` | :heavy_check_mark: | |
| `is_access_declaration` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`BaseUsingDecl`](#BaseUsingDecl).


</details>

<details><summary><a name="ValueDecl"></a>ValueDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_weak` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="UnresolvedUsingValueDecl"></a>UnresolvedUsingValueDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `ellipsis_token` | `INTEGER` | :heavy_check_mark: | |
| `using_token` | `INTEGER` | :heavy_check_mark: | |
| `is_access_declaration` | `INTEGER` | :heavy_check_mark: | |
| `is_pack_expansion` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ValueDecl`](#ValueDecl).


</details>

<details><summary><a name="TemplateParamObjectDecl"></a>TemplateParamObjectDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`ValueDecl`](#ValueDecl).


</details>

<details><summary><a name="OMPDeclareReductionDecl"></a>OMPDeclareReductionDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `combiner` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combiner_in` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `combiner_out` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `initializer_original` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `initializer_private` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `initializer` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `initializer_kind` | `INTEGER` | :heavy_check_mark: | [`OMPDeclareReductionDeclInitKind`](#OMPDeclareReductionDeclInitKind) |

This table also includes all of the fields contained in [`ValueDecl`](#ValueDecl).


</details>

<details><summary><a name="MSGuidDecl"></a>MSGuidDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`ValueDecl`](#ValueDecl).


</details>

<details><summary><a name="IndirectFieldDecl"></a>IndirectFieldDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `anonymous_field` | `INTEGER` | :x: | [`FieldDecl`](#FieldDecl) |
| `variable_declaration` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |

This table also includes all of the fields contained in [`ValueDecl`](#ValueDecl).


</details>

<details><summary><a name="EnumConstantDecl"></a>EnumConstantDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `initializer_expression` | `INTEGER` | :x: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`ValueDecl`](#ValueDecl).


</details>

<details><summary><a name="DeclaratorDecl"></a>DeclaratorDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `first_inner_token` | `INTEGER` | :heavy_check_mark: | |
| `first_outer_token` | `INTEGER` | :heavy_check_mark: | |
| `trailing_requires_clause` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `type_spec_end_token` | `INTEGER` | :heavy_check_mark: | |
| `type_spec_start_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ValueDecl`](#ValueDecl).


</details>

<details><summary><a name="VarDecl"></a>VarDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `acting_definition` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |
| `initializer` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `initializer_style` | `INTEGER` | :heavy_check_mark: | [`VarDeclInitializationStyle`](#VarDeclInitializationStyle) |
| `initializing_declaration` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |
| `instantiated_from_static_data_member` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |
| `language_linkage` | `INTEGER` | :heavy_check_mark: | [`LanguageLinkage`](#LanguageLinkage) |
| `point_of_instantiation` | `INTEGER` | :heavy_check_mark: | |
| `storage_class` | `INTEGER` | :heavy_check_mark: | [`StorageClass`](#StorageClass) |
| `storage_duration` | `INTEGER` | :heavy_check_mark: | [`StorageDuration`](#StorageDuration) |
| `tls_kind` | `INTEGER` | :heavy_check_mark: | [`VarDeclTLSKind`](#VarDeclTLSKind) |
| `tsc_spec` | `INTEGER` | :heavy_check_mark: | [`ThreadStorageClassSpecifier`](#ThreadStorageClassSpecifier) |
| `template_instantiation_pattern` | `INTEGER` | :x: | [`VarDecl`](#VarDecl) |
| `template_specialization_kind` | `INTEGER` | :heavy_check_mark: | [`TemplateSpecializationKind`](#TemplateSpecializationKind) |
| `template_specialization_kind_for_instantiation` | `INTEGER` | :heavy_check_mark: | [`TemplateSpecializationKind`](#TemplateSpecializationKind) |
| `has_constant_initialization` | `INTEGER` | :heavy_check_mark: | |
| `has_dependent_alignment` | `INTEGER` | :heavy_check_mark: | |
| `has_external_storage` | `INTEGER` | :heavy_check_mark: | |
| `has_global_storage` | `INTEGER` | :heavy_check_mark: | |
| `has_ice_initializer` | `INTEGER` | :x: | |
| `has_initializer` | `INTEGER` | :heavy_check_mark: | |
| `has_local_storage` | `INTEGER` | :heavy_check_mark: | |
| `is_arc_pseudo_strong` | `INTEGER` | :heavy_check_mark: | |
| `is_cxx_for_range_declaration` | `INTEGER` | :heavy_check_mark: | |
| `is_constexpr` | `INTEGER` | :heavy_check_mark: | |
| `is_direct_initializer` | `INTEGER` | :heavy_check_mark: | |
| `is_escaping_byref` | `INTEGER` | :heavy_check_mark: | |
| `is_exception_variable` | `INTEGER` | :heavy_check_mark: | |
| `is_extern_c` | `INTEGER` | :heavy_check_mark: | |
| `is_file_variable_declaration` | `INTEGER` | :heavy_check_mark: | |
| `is_function_or_method_variable_declaration` | `INTEGER` | :heavy_check_mark: | |
| `is_in_extern_c_context` | `INTEGER` | :heavy_check_mark: | |
| `is_in_extern_cxx_context` | `INTEGER` | :heavy_check_mark: | |
| `is_initializer_capture` | `INTEGER` | :heavy_check_mark: | |
| `is_inline` | `INTEGER` | :heavy_check_mark: | |
| `is_inline_specified` | `INTEGER` | :heavy_check_mark: | |
| `is_known_to_be_defined` | `INTEGER` | :heavy_check_mark: | |
| `is_local_variable_declaration` | `INTEGER` | :heavy_check_mark: | |
| `is_local_variable_declaration_or_parm` | `INTEGER` | :heavy_check_mark: | |
| `is_nrvo_variable` | `INTEGER` | :heavy_check_mark: | |
| `is_no_destroy` | `INTEGER` | :heavy_check_mark: | |
| `is_non_escaping_byref` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_for_declaration` | `INTEGER` | :heavy_check_mark: | |
| `is_previous_declaration_in_same_block_scope` | `INTEGER` | :heavy_check_mark: | |
| `is_static_data_member` | `INTEGER` | :heavy_check_mark: | |
| `is_static_local` | `INTEGER` | :heavy_check_mark: | |
| `is_demoted_definition` | `INTEGER` | :heavy_check_mark: | |
| `is_usable_in_constant_expressions` | `INTEGER` | :heavy_check_mark: | |
| `might_be_usable_in_constant_expressions` | `INTEGER` | :heavy_check_mark: | |
| `needs_destruction` | `INTEGER` | :heavy_check_mark: | [`QualTypeDestructionKind`](#QualTypeDestructionKind) |

This table also includes all of the fields contained in [`DeclaratorDecl`](#DeclaratorDecl).


</details>

<details><summary><a name="ParmVarDecl"></a>ParmVarDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `default_argument` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `obj_c_decl_qualifier` | `INTEGER` | :heavy_check_mark: | [`DeclObjCDeclQualifier`](#DeclObjCDeclQualifier) |
| `original_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `uninstantiated_default_argument` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `has_default_argument` | `INTEGER` | :heavy_check_mark: | |
| `has_inherited_default_argument` | `INTEGER` | :heavy_check_mark: | |
| `has_uninstantiated_default_argument` | `INTEGER` | :heavy_check_mark: | |
| `has_unparsed_default_argument` | `INTEGER` | :heavy_check_mark: | |
| `is_destroyed_in_callee` | `INTEGER` | :heavy_check_mark: | |
| `is_knr_promoted` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_method_parameter` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`VarDecl`](#VarDecl).


</details>

<details><summary><a name="OMPCapturedExprDecl"></a>OMPCapturedExprDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`VarDecl`](#VarDecl).


</details>

<details><summary><a name="ImplicitParamDecl"></a>ImplicitParamDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `parameter_kind` | `INTEGER` | :heavy_check_mark: | [`ImplicitParamDeclImplicitParamKind`](#ImplicitParamDeclImplicitParamKind) |

This table also includes all of the fields contained in [`VarDecl`](#VarDecl).


</details>

<details><summary><a name="DecompositionDecl"></a>DecompositionDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`VarDecl`](#VarDecl).


</details>

<details><summary><a name="VarTemplateSpecializationDecl"></a>VarTemplateSpecializationDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `extern_token` | `INTEGER` | :heavy_check_mark: | |
| `specialization_kind` | `INTEGER` | :heavy_check_mark: | [`TemplateSpecializationKind`](#TemplateSpecializationKind) |
| `template_keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `type_as_written` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_class_scope_explicit_specialization` | `INTEGER` | :heavy_check_mark: | |
| `is_explicit_instantiation_or_specialization` | `INTEGER` | :heavy_check_mark: | |
| `is_explicit_specialization` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`VarDecl`](#VarDecl).


</details>

<details><summary><a name="VarTemplatePartialSpecializationDecl"></a>VarTemplatePartialSpecializationDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`VarTemplateSpecializationDecl`](#VarTemplateSpecializationDecl).


</details>

<details><summary><a name="NonTypeTemplateParmDecl"></a>NonTypeTemplateParmDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `default_argument_was_inherited` | `INTEGER` | :heavy_check_mark: | |
| `default_argument` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `default_argument_token` | `INTEGER` | :heavy_check_mark: | |
| `num_expansion_types` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `placeholder_type_constraint` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `has_default_argument` | `INTEGER` | :heavy_check_mark: | |
| `has_placeholder_type_constraint` | `INTEGER` | :heavy_check_mark: | |
| `is_expanded_parameter_pack` | `INTEGER` | :heavy_check_mark: | |
| `is_pack_expansion` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`DeclaratorDecl`](#DeclaratorDecl).


</details>

<details><summary><a name="MSPropertyDecl"></a>MSPropertyDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `has_getter` | `INTEGER` | :heavy_check_mark: | |
| `has_setter` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`DeclaratorDecl`](#DeclaratorDecl).


</details>

<details><summary><a name="FunctionDecl"></a>FunctionDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `uses_fp_intrin` | `INTEGER` | :heavy_check_mark: | |
| `does_declaration_force_externally_visible_definition` | `INTEGER` | :x: | |
| `does_this_declaration_have_a_body` | `INTEGER` | :heavy_check_mark: | |
| `call_result_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `constexpr_kind` | `INTEGER` | :heavy_check_mark: | [`ConstexprSpecKind`](#ConstexprSpecKind) |
| `declared_return_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `ellipsis_token` | `INTEGER` | :heavy_check_mark: | |
| `exception_spec_type` | `INTEGER` | :heavy_check_mark: | [`ExceptionSpecificationType`](#ExceptionSpecificationType) |
| `instantiated_from_member_function` | `INTEGER` | :x: | [`FunctionDecl`](#FunctionDecl) |
| `language_linkage` | `INTEGER` | :heavy_check_mark: | [`LanguageLinkage`](#LanguageLinkage) |
| `multi_version_kind` | `INTEGER` | :heavy_check_mark: | [`MultiVersionKind`](#MultiVersionKind) |
| `odr_hash` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `overloaded_operator` | `INTEGER` | :heavy_check_mark: | [`OverloadedOperatorKind`](#OverloadedOperatorKind) |
| `point_of_instantiation` | `INTEGER` | :heavy_check_mark: | |
| `return_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `storage_class` | `INTEGER` | :heavy_check_mark: | [`StorageClass`](#StorageClass) |
| `template_instantiation_pattern` | `INTEGER` | :x: | [`FunctionDecl`](#FunctionDecl) |
| `template_specialization_kind` | `INTEGER` | :heavy_check_mark: | [`TemplateSpecializationKind`](#TemplateSpecializationKind) |
| `template_specialization_kind_for_instantiation` | `INTEGER` | :heavy_check_mark: | [`TemplateSpecializationKind`](#TemplateSpecializationKind) |
| `templated_kind` | `INTEGER` | :heavy_check_mark: | [`FunctionDeclTemplatedKind`](#FunctionDeclTemplatedKind) |
| `has_implicit_return_zero` | `INTEGER` | :heavy_check_mark: | |
| `has_inherited_prototype` | `INTEGER` | :heavy_check_mark: | |
| `has_one_parameter_or_default_arguments` | `INTEGER` | :heavy_check_mark: | |
| `has_prototype` | `INTEGER` | :heavy_check_mark: | |
| `has_skipped_body` | `INTEGER` | :heavy_check_mark: | |
| `has_trivial_body` | `INTEGER` | :heavy_check_mark: | |
| `has_written_prototype` | `INTEGER` | :heavy_check_mark: | |
| `instantiation_is_pending` | `INTEGER` | :heavy_check_mark: | |
| `is_cpu_dispatch_multi_version` | `INTEGER` | :heavy_check_mark: | |
| `is_cpu_specific_multi_version` | `INTEGER` | :heavy_check_mark: | |
| `is_consteval` | `INTEGER` | :heavy_check_mark: | |
| `is_constexpr` | `INTEGER` | :heavy_check_mark: | |
| `is_constexpr_specified` | `INTEGER` | :heavy_check_mark: | |
| `is_defaulted` | `INTEGER` | :heavy_check_mark: | |
| `is_deleted` | `INTEGER` | :heavy_check_mark: | |
| `is_deleted_as_written` | `INTEGER` | :heavy_check_mark: | |
| `is_destroying_operator_delete` | `INTEGER` | :heavy_check_mark: | |
| `is_explicitly_defaulted` | `INTEGER` | :heavy_check_mark: | |
| `is_extern_c` | `INTEGER` | :heavy_check_mark: | |
| `is_function_template_specialization` | `INTEGER` | :heavy_check_mark: | |
| `is_global` | `INTEGER` | :heavy_check_mark: | |
| `is_implicitly_instantiable` | `INTEGER` | :heavy_check_mark: | |
| `is_in_extern_c_context` | `INTEGER` | :heavy_check_mark: | |
| `is_in_extern_cxx_context` | `INTEGER` | :heavy_check_mark: | |
| `is_inline_builtin_declaration` | `INTEGER` | :heavy_check_mark: | |
| `is_inline_definition_externally_visible` | `INTEGER` | :x: | |
| `is_inline_specified` | `INTEGER` | :heavy_check_mark: | |
| `is_inlined` | `INTEGER` | :heavy_check_mark: | |
| `is_late_template_parsed` | `INTEGER` | :heavy_check_mark: | |
| `is_ms_extern_inline` | `INTEGER` | :x: | |
| `is_msvcrt_entry_point` | `INTEGER` | :heavy_check_mark: | |
| `is_main` | `INTEGER` | :heavy_check_mark: | |
| `is_multi_version` | `INTEGER` | :heavy_check_mark: | |
| `is_no_return` | `INTEGER` | :heavy_check_mark: | |
| `is_overloaded_operator` | `INTEGER` | :heavy_check_mark: | |
| `is_pure` | `INTEGER` | :heavy_check_mark: | |
| `is_replaceable_global_allocation_function` | `INTEGER` | :heavy_check_mark: | |
| `is_reserved_global_placement_operator` | `INTEGER` | :x: | |
| `is_static` | `INTEGER` | :heavy_check_mark: | |
| `is_target_clones_multi_version` | `INTEGER` | :heavy_check_mark: | |
| `is_target_multi_version` | `INTEGER` | :heavy_check_mark: | |
| `is_template_instantiation` | `INTEGER` | :heavy_check_mark: | |
| `is_this_declaration_instantiated_from_a_friend_definition` | `INTEGER` | :heavy_check_mark: | |
| `is_trivial` | `INTEGER` | :heavy_check_mark: | |
| `is_trivial_for_call` | `INTEGER` | :heavy_check_mark: | |
| `is_user_provided` | `INTEGER` | :heavy_check_mark: | |
| `is_variadic` | `INTEGER` | :heavy_check_mark: | |
| `is_virtual_as_written` | `INTEGER` | :heavy_check_mark: | |
| `uses_seh_try` | `INTEGER` | :heavy_check_mark: | |
| `will_have_body` | `INTEGER` | :heavy_check_mark: | |
| `body` | `INTEGER` | :x: | [`Stmt`](#Stmt) |

This table also includes all of the fields contained in [`DeclaratorDecl`](#DeclaratorDecl).


</details>

<details><summary><a name="CXXMethodDecl"></a>CXXMethodDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `reference_qualifier` | `INTEGER` | :heavy_check_mark: | [`RefQualifierKind`](#RefQualifierKind) |
| `this_object_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `this_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `has_inline_body` | `INTEGER` | :heavy_check_mark: | |
| `is_const` | `INTEGER` | :heavy_check_mark: | |
| `is_copy_assignment_operator` | `INTEGER` | :heavy_check_mark: | |
| `is_instance` | `INTEGER` | :heavy_check_mark: | |
| `is_lambda_static_invoker` | `INTEGER` | :heavy_check_mark: | |
| `is_move_assignment_operator` | `INTEGER` | :heavy_check_mark: | |
| `is_virtual` | `INTEGER` | :heavy_check_mark: | |
| `is_volatile` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`FunctionDecl`](#FunctionDecl).


</details>

<details><summary><a name="CXXDestructorDecl"></a>CXXDestructorDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `operator_delete` | `INTEGER` | :x: | [`FunctionDecl`](#FunctionDecl) |
| `operator_delete_this_argument` | `INTEGER` | :x: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`CXXMethodDecl`](#CXXMethodDecl).


</details>

<details><summary><a name="CXXConversionDecl"></a>CXXConversionDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `conversion_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_explicit` | `INTEGER` | :heavy_check_mark: | |
| `is_lambda_to_block_pointer_conversion` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`CXXMethodDecl`](#CXXMethodDecl).


</details>

<details><summary><a name="CXXConstructorDecl"></a>CXXConstructorDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `target_constructor` | `INTEGER` | :x: | [`CXXConstructorDecl`](#CXXConstructorDecl) |
| `is_default_constructor` | `INTEGER` | :heavy_check_mark: | |
| `is_delegating_constructor` | `INTEGER` | :heavy_check_mark: | |
| `is_explicit` | `INTEGER` | :heavy_check_mark: | |
| `is_inheriting_constructor` | `INTEGER` | :heavy_check_mark: | |
| `is_specialization_copying_object` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`CXXMethodDecl`](#CXXMethodDecl).


</details>

<details><summary><a name="CXXDeductionGuideDecl"></a>CXXDeductionGuideDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `corresponding_constructor` | `INTEGER` | :heavy_check_mark: | [`CXXConstructorDecl`](#CXXConstructorDecl) |
| `is_copy_deduction_candidate` | `INTEGER` | :heavy_check_mark: | |
| `is_explicit` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`FunctionDecl`](#FunctionDecl).


</details>

<details><summary><a name="FieldDecl"></a>FieldDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `bit_width` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `captured_vla_type` | `INTEGER` | :x: | [`VariableArrayType`](#VariableArrayType) |
| `in_class_initializer_style` | `INTEGER` | :heavy_check_mark: | [`InClassInitStyle`](#InClassInitStyle) |
| `in_class_initializer` | `INTEGER` | :x: | [`Expr`](#Expr) |
| `has_captured_vla_type` | `INTEGER` | :heavy_check_mark: | |
| `has_in_class_initializer` | `INTEGER` | :heavy_check_mark: | |
| `is_anonymous_struct_or_union` | `INTEGER` | :heavy_check_mark: | |
| `is_bit_field` | `INTEGER` | :heavy_check_mark: | |
| `is_mutable` | `INTEGER` | :heavy_check_mark: | |
| `is_unnamed_bitfield` | `INTEGER` | :heavy_check_mark: | |
| `is_zero_length_bit_field` | `INTEGER` | :heavy_check_mark: | |
| `is_zero_size` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`DeclaratorDecl`](#DeclaratorDecl).


</details>

<details><summary><a name="ObjCIvarDecl"></a>ObjCIvarDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `access_control` | `INTEGER` | :heavy_check_mark: | [`ObjCIvarDeclAccessControl`](#ObjCIvarDeclAccessControl) |
| `canonical_access_control` | `INTEGER` | :heavy_check_mark: | [`ObjCIvarDeclAccessControl`](#ObjCIvarDeclAccessControl) |
| `containing_interface` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |
| `next_instance_variable` | `INTEGER` | :heavy_check_mark: | [`ObjCIvarDecl`](#ObjCIvarDecl) |
| `synthesize` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`FieldDecl`](#FieldDecl).


</details>

<details><summary><a name="ObjCAtDefsFieldDecl"></a>ObjCAtDefsFieldDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`FieldDecl`](#FieldDecl).


</details>

<details><summary><a name="BindingDecl"></a>BindingDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `binding` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `decomposed_declaration` | `INTEGER` | :heavy_check_mark: | [`ValueDecl`](#ValueDecl) |
| `holding_variable` | `INTEGER` | :heavy_check_mark: | [`VarDecl`](#VarDecl) |

This table also includes all of the fields contained in [`ValueDecl`](#ValueDecl).


</details>

<details><summary><a name="OMPDeclarativeDirectiveValueDecl"></a>OMPDeclarativeDirectiveValueDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`ValueDecl`](#ValueDecl).


</details>

<details><summary><a name="OMPDeclareMapperDecl"></a>OMPDeclareMapperDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `mapper_variable_reference` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`OMPDeclarativeDirectiveValueDecl`](#OMPDeclarativeDirectiveValueDecl).


</details>

<details><summary><a name="UsingShadowDecl"></a>UsingShadowDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `introducer` | `INTEGER` | :heavy_check_mark: | [`BaseUsingDecl`](#BaseUsingDecl) |
| `next_using_shadow_declaration` | `INTEGER` | :x: | [`UsingShadowDecl`](#UsingShadowDecl) |
| `target_declaration` | `INTEGER` | :heavy_check_mark: | [`NamedDecl`](#NamedDecl) |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="ConstructorUsingShadowDecl"></a>ConstructorUsingShadowDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `constructs_virtual_base` | `INTEGER` | :heavy_check_mark: | |
| `constructed_base_class` | `INTEGER` | :heavy_check_mark: | [`CXXRecordDecl`](#CXXRecordDecl) |
| `constructed_base_class_shadow_declaration` | `INTEGER` | :x: | [`ConstructorUsingShadowDecl`](#ConstructorUsingShadowDecl) |
| `nominated_base_class` | `INTEGER` | :heavy_check_mark: | [`CXXRecordDecl`](#CXXRecordDecl) |
| `nominated_base_class_shadow_declaration` | `INTEGER` | :x: | [`ConstructorUsingShadowDecl`](#ConstructorUsingShadowDecl) |

This table also includes all of the fields contained in [`UsingShadowDecl`](#UsingShadowDecl).


</details>

<details><summary><a name="UsingPackDecl"></a>UsingPackDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `instantiated_from_using_declaration` | `INTEGER` | :heavy_check_mark: | [`NamedDecl`](#NamedDecl) |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="UsingDirectiveDecl"></a>UsingDirectiveDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `identifier_token` | `INTEGER` | :heavy_check_mark: | |
| `namespace_key_token` | `INTEGER` | :heavy_check_mark: | |
| `nominated_namespace_as_written` | `INTEGER` | :heavy_check_mark: | [`NamedDecl`](#NamedDecl) |
| `using_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="UnresolvedUsingIfExistsDecl"></a>UnresolvedUsingIfExistsDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="TypeDecl"></a>TypeDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `type_for_declaration` | `INTEGER` | :x: | [`Type`](#Type) |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="TemplateTypeParmDecl"></a>TemplateTypeParmDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `default_argument_was_inherited` | `INTEGER` | :heavy_check_mark: | |
| `default_argument` | `INTEGER` | :x: | [`Type`](#Type) |
| `default_argument_info` | `INTEGER` | :x: | [`Type`](#Type) |
| `default_argument_token` | `INTEGER` | :heavy_check_mark: | |
| `has_default_argument` | `INTEGER` | :heavy_check_mark: | |
| `has_type_constraint` | `INTEGER` | :heavy_check_mark: | |
| `is_expanded_parameter_pack` | `INTEGER` | :heavy_check_mark: | |
| `is_pack_expansion` | `INTEGER` | :heavy_check_mark: | |
| `was_declared_with_typename` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TypeDecl`](#TypeDecl).


</details>

<details><summary><a name="TagDecl"></a>TagDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `first_inner_token` | `INTEGER` | :heavy_check_mark: | |
| `first_outer_token` | `INTEGER` | :heavy_check_mark: | |
| `tag_kind` | `INTEGER` | :heavy_check_mark: | [`TagTypeKind`](#TagTypeKind) |
| `typedef_name_for_anonymous_declaration` | `INTEGER` | :x: | [`TypedefNameDecl`](#TypedefNameDecl) |
| `has_name_for_linkage` | `INTEGER` | :heavy_check_mark: | |
| `is_being_defined` | `INTEGER` | :heavy_check_mark: | |
| `is_class` | `INTEGER` | :heavy_check_mark: | |
| `is_complete_definition` | `INTEGER` | :heavy_check_mark: | |
| `is_complete_definition_required` | `INTEGER` | :heavy_check_mark: | |
| `is_dependent_type` | `INTEGER` | :heavy_check_mark: | |
| `is_embedded_in_declarator` | `INTEGER` | :heavy_check_mark: | |
| `is_enum` | `INTEGER` | :heavy_check_mark: | |
| `is_free_standing` | `INTEGER` | :heavy_check_mark: | |
| `is_interface` | `INTEGER` | :heavy_check_mark: | |
| `is_struct` | `INTEGER` | :heavy_check_mark: | |
| `is_union` | `INTEGER` | :heavy_check_mark: | |
| `may_have_out_of_date_definition` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TypeDecl`](#TypeDecl).


</details>

<details><summary><a name="RecordDecl"></a>RecordDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `can_pass_in_registers` | `INTEGER` | :heavy_check_mark: | |
| `argument_passing_restrictions` | `INTEGER` | :heavy_check_mark: | [`RecordDeclArgPassingKind`](#RecordDeclArgPassingKind) |
| `has_flexible_array_member` | `INTEGER` | :heavy_check_mark: | |
| `has_loaded_fields_from_external_storage` | `INTEGER` | :heavy_check_mark: | |
| `has_non_trivial_to_primitive_copy_c_union` | `INTEGER` | :heavy_check_mark: | |
| `has_non_trivial_to_primitive_default_initialize_c_union` | `INTEGER` | :heavy_check_mark: | |
| `has_non_trivial_to_primitive_destruct_c_union` | `INTEGER` | :heavy_check_mark: | |
| `has_object_member` | `INTEGER` | :heavy_check_mark: | |
| `has_volatile_member` | `INTEGER` | :heavy_check_mark: | |
| `is_anonymous_struct_or_union` | `INTEGER` | :heavy_check_mark: | |
| `is_captured_record` | `INTEGER` | :heavy_check_mark: | |
| `is_injected_class_name` | `INTEGER` | :heavy_check_mark: | |
| `is_lambda` | `INTEGER` | :heavy_check_mark: | |
| `is_ms_struct` | `INTEGER` | :heavy_check_mark: | |
| `is_non_trivial_to_primitive_copy` | `INTEGER` | :heavy_check_mark: | |
| `is_non_trivial_to_primitive_default_initialize` | `INTEGER` | :heavy_check_mark: | |
| `is_non_trivial_to_primitive_destroy` | `INTEGER` | :heavy_check_mark: | |
| `is_or_contains_union` | `INTEGER` | :heavy_check_mark: | |
| `is_parameter_destroyed_in_callee` | `INTEGER` | :heavy_check_mark: | |
| `may_insert_extra_padding` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TagDecl`](#TagDecl).


</details>

<details><summary><a name="CXXRecordDecl"></a>CXXRecordDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `allow_const_default_initializer` | `INTEGER` | :x: | |
| `calculate_inheritance_model` | `INTEGER` | :x: | |
| `destructor` | `INTEGER` | :x: | [`CXXDestructorDecl`](#CXXDestructorDecl) |
| `instantiated_from_member_class` | `INTEGER` | :x: | [`CXXRecordDecl`](#CXXRecordDecl) |
| `lambda_call_operator` | `INTEGER` | :x: | [`CXXMethodDecl`](#CXXMethodDecl) |
| `lambda_capture_default` | `INTEGER` | :x: | |
| `lambda_context_declaration` | `INTEGER` | :x: | [`Decl`](#Decl) |
| `lambda_mangling_number` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `lambda_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `ms_inheritance_model` | `INTEGER` | :x: | |
| `ms_vtor_disp_mode` | `INTEGER` | :heavy_check_mark: | [`MSVtorDispMode`](#MSVtorDispMode) |
| `num_bases` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `num_virtual_bases` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `odr_hash` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `template_instantiation_pattern` | `INTEGER` | :x: | [`CXXRecordDecl`](#CXXRecordDecl) |
| `template_specialization_kind` | `INTEGER` | :heavy_check_mark: | [`TemplateSpecializationKind`](#TemplateSpecializationKind) |
| `has_any_dependent_bases` | `INTEGER` | :x: | |
| `has_constexpr_default_constructor` | `INTEGER` | :x: | |
| `has_constexpr_destructor` | `INTEGER` | :x: | |
| `has_constexpr_non_copy_move_constructor` | `INTEGER` | :x: | |
| `has_copy_assignment_with_const_parameter` | `INTEGER` | :x: | |
| `has_copy_constructor_with_const_parameter` | `INTEGER` | :x: | |
| `has_default_constructor` | `INTEGER` | :x: | |
| `has_definition` | `INTEGER` | :x: | |
| `has_direct_fields` | `INTEGER` | :x: | |
| `has_friends` | `INTEGER` | :x: | |
| `has_in_class_initializer` | `INTEGER` | :x: | |
| `has_inherited_assignment` | `INTEGER` | :x: | |
| `has_inherited_constructor` | `INTEGER` | :x: | |
| `has_initializer_method` | `INTEGER` | :x: | |
| `has_irrelevant_destructor` | `INTEGER` | :x: | |
| `has_known_lambda_internal_linkage` | `INTEGER` | :x: | |
| `has_move_assignment` | `INTEGER` | :x: | |
| `has_move_constructor` | `INTEGER` | :x: | |
| `has_mutable_fields` | `INTEGER` | :x: | |
| `has_non_literal_type_fields_or_bases` | `INTEGER` | :x: | |
| `has_non_trivial_copy_assignment` | `INTEGER` | :x: | |
| `has_non_trivial_copy_constructor` | `INTEGER` | :x: | |
| `has_non_trivial_copy_constructor_for_call` | `INTEGER` | :x: | |
| `has_non_trivial_default_constructor` | `INTEGER` | :x: | |
| `has_non_trivial_destructor` | `INTEGER` | :x: | |
| `has_non_trivial_destructor_for_call` | `INTEGER` | :x: | |
| `has_non_trivial_move_assignment` | `INTEGER` | :x: | |
| `has_non_trivial_move_constructor` | `INTEGER` | :x: | |
| `has_non_trivial_move_constructor_for_call` | `INTEGER` | :x: | |
| `has_private_fields` | `INTEGER` | :x: | |
| `has_protected_fields` | `INTEGER` | :x: | |
| `has_simple_copy_assignment` | `INTEGER` | :x: | |
| `has_simple_copy_constructor` | `INTEGER` | :x: | |
| `has_simple_destructor` | `INTEGER` | :x: | |
| `has_simple_move_assignment` | `INTEGER` | :x: | |
| `has_simple_move_constructor` | `INTEGER` | :x: | |
| `has_trivial_copy_assignment` | `INTEGER` | :x: | |
| `has_trivial_copy_constructor` | `INTEGER` | :x: | |
| `has_trivial_copy_constructor_for_call` | `INTEGER` | :x: | |
| `has_trivial_default_constructor` | `INTEGER` | :x: | |
| `has_trivial_destructor` | `INTEGER` | :x: | |
| `has_trivial_destructor_for_call` | `INTEGER` | :x: | |
| `has_trivial_move_assignment` | `INTEGER` | :x: | |
| `has_trivial_move_constructor` | `INTEGER` | :x: | |
| `has_trivial_move_constructor_for_call` | `INTEGER` | :x: | |
| `has_uninitialized_reference_member` | `INTEGER` | :x: | |
| `has_user_declared_constructor` | `INTEGER` | :x: | |
| `has_user_declared_copy_assignment` | `INTEGER` | :x: | |
| `has_user_declared_copy_constructor` | `INTEGER` | :x: | |
| `has_user_declared_destructor` | `INTEGER` | :x: | |
| `has_user_declared_move_assignment` | `INTEGER` | :x: | |
| `has_user_declared_move_constructor` | `INTEGER` | :x: | |
| `has_user_declared_move_operation` | `INTEGER` | :x: | |
| `has_user_provided_default_constructor` | `INTEGER` | :x: | |
| `has_variant_members` | `INTEGER` | :x: | |
| `implicit_copy_assignment_has_const_parameter` | `INTEGER` | :x: | |
| `implicit_copy_constructor_has_const_parameter` | `INTEGER` | :x: | |
| `is_abstract` | `INTEGER` | :x: | |
| `is_aggregate` | `INTEGER` | :x: | |
| `is_any_destructor_no_return` | `INTEGER` | :x: | |
| `is_c_like` | `INTEGER` | :x: | |
| `is_cxx11_standard_layout` | `INTEGER` | :x: | |
| `is_dependent_lambda` | `INTEGER` | :heavy_check_mark: | |
| `is_dynamic_class` | `INTEGER` | :x: | |
| `is_effectively_final` | `INTEGER` | :x: | |
| `is_empty` | `INTEGER` | :x: | |
| `is_generic_lambda` | `INTEGER` | :heavy_check_mark: | |
| `is_interface_like` | `INTEGER` | :x: | |
| `is_literal` | `INTEGER` | :x: | |
| `is_local_class` | `INTEGER` | :x: | [`FunctionDecl`](#FunctionDecl) |
| `is_pod` | `INTEGER` | :x: | |
| `is_polymorphic` | `INTEGER` | :x: | |
| `is_standard_layout` | `INTEGER` | :x: | |
| `is_structural` | `INTEGER` | :x: | |
| `is_trivial` | `INTEGER` | :x: | |
| `is_trivially_copyable` | `INTEGER` | :x: | |
| `lambda_is_default_constructible_and_assignable` | `INTEGER` | :x: | |
| `may_be_abstract` | `INTEGER` | :x: | |
| `may_be_dynamic_class` | `INTEGER` | :x: | |
| `may_be_non_dynamic_class` | `INTEGER` | :x: | |
| `needs_implicit_copy_assignment` | `INTEGER` | :x: | |
| `needs_implicit_copy_constructor` | `INTEGER` | :x: | |
| `needs_implicit_default_constructor` | `INTEGER` | :x: | |
| `needs_implicit_destructor` | `INTEGER` | :x: | |
| `needs_implicit_move_assignment` | `INTEGER` | :x: | |
| `needs_implicit_move_constructor` | `INTEGER` | :x: | |
| `needs_overload_resolution_for_copy_assignment` | `INTEGER` | :x: | |
| `needs_overload_resolution_for_copy_constructor` | `INTEGER` | :x: | |
| `needs_overload_resolution_for_destructor` | `INTEGER` | :x: | |
| `needs_overload_resolution_for_move_assignment` | `INTEGER` | :x: | |
| `needs_overload_resolution_for_move_constructor` | `INTEGER` | :x: | |
| `null_field_offset_is_zero` | `INTEGER` | :x: | |

This table also includes all of the fields contained in [`RecordDecl`](#RecordDecl).


</details>

<details><summary><a name="ClassTemplateSpecializationDecl"></a>ClassTemplateSpecializationDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `extern_token` | `INTEGER` | :heavy_check_mark: | |
| `point_of_instantiation` | `INTEGER` | :heavy_check_mark: | |
| `specialization_kind` | `INTEGER` | :heavy_check_mark: | [`TemplateSpecializationKind`](#TemplateSpecializationKind) |
| `template_keyword_token` | `INTEGER` | :heavy_check_mark: | |
| `type_as_written` | `INTEGER` | :x: | [`Type`](#Type) |
| `is_class_scope_explicit_specialization` | `INTEGER` | :heavy_check_mark: | |
| `is_explicit_instantiation_or_specialization` | `INTEGER` | :heavy_check_mark: | |
| `is_explicit_specialization` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`CXXRecordDecl`](#CXXRecordDecl).


</details>

<details><summary><a name="ClassTemplatePartialSpecializationDecl"></a>ClassTemplatePartialSpecializationDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`ClassTemplateSpecializationDecl`](#ClassTemplateSpecializationDecl).


</details>

<details><summary><a name="EnumDecl"></a>EnumDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `instantiated_from_member_enum` | `INTEGER` | :x: | [`EnumDecl`](#EnumDecl) |
| `integer_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `odr_hash` | `INTEGER` | :x: | [`unsigned`](#unsigned) |
| `promotion_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `template_instantiation_pattern` | `INTEGER` | :x: | [`EnumDecl`](#EnumDecl) |
| `template_specialization_kind` | `INTEGER` | :heavy_check_mark: | [`TemplateSpecializationKind`](#TemplateSpecializationKind) |
| `is_closed` | `INTEGER` | :heavy_check_mark: | |
| `is_closed_flag` | `INTEGER` | :heavy_check_mark: | |
| `is_closed_non_flag` | `INTEGER` | :heavy_check_mark: | |
| `is_complete` | `INTEGER` | :heavy_check_mark: | |
| `is_fixed` | `INTEGER` | :heavy_check_mark: | |
| `is_scoped` | `INTEGER` | :heavy_check_mark: | |
| `is_scoped_using_class_tag` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TagDecl`](#TagDecl).


</details>

<details><summary><a name="UnresolvedUsingTypenameDecl"></a>UnresolvedUsingTypenameDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `ellipsis_token` | `INTEGER` | :heavy_check_mark: | |
| `typename_token` | `INTEGER` | :heavy_check_mark: | |
| `using_token` | `INTEGER` | :heavy_check_mark: | |
| `is_pack_expansion` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TypeDecl`](#TypeDecl).


</details>

<details><summary><a name="TypedefNameDecl"></a>TypedefNameDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `anonymous_declaration_with_typedef_name` | `INTEGER` | :x: | [`TagDecl`](#TagDecl) |
| `underlying_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_moded` | `INTEGER` | :heavy_check_mark: | |
| `is_transparent_tag` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TypeDecl`](#TypeDecl).


</details>

<details><summary><a name="TypedefDecl"></a>TypedefDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`TypedefNameDecl`](#TypedefNameDecl).


</details>

<details><summary><a name="TypeAliasDecl"></a>TypeAliasDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `described_alias_template` | `INTEGER` | :x: | [`TypeAliasTemplateDecl`](#TypeAliasTemplateDecl) |

This table also includes all of the fields contained in [`TypedefNameDecl`](#TypedefNameDecl).


</details>

<details><summary><a name="ObjCTypeParamDecl"></a>ObjCTypeParamDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `colon_token` | `INTEGER` | :heavy_check_mark: | |
| `variance` | `INTEGER` | :heavy_check_mark: | [`ObjCTypeParamVariance`](#ObjCTypeParamVariance) |
| `variance_token` | `INTEGER` | :heavy_check_mark: | |
| `has_explicit_bound` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TypedefNameDecl`](#TypedefNameDecl).


</details>

<details><summary><a name="TemplateDecl"></a>TemplateDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="RedeclarableTemplateDecl"></a>RedeclarableTemplateDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`TemplateDecl`](#TemplateDecl).


</details>

<details><summary><a name="FunctionTemplateDecl"></a>FunctionTemplateDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`RedeclarableTemplateDecl`](#RedeclarableTemplateDecl).


</details>

<details><summary><a name="ClassTemplateDecl"></a>ClassTemplateDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`RedeclarableTemplateDecl`](#RedeclarableTemplateDecl).


</details>

<details><summary><a name="VarTemplateDecl"></a>VarTemplateDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`RedeclarableTemplateDecl`](#RedeclarableTemplateDecl).


</details>

<details><summary><a name="TypeAliasTemplateDecl"></a>TypeAliasTemplateDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `instantiated_from_member_template` | `INTEGER` | :x: | [`TypeAliasTemplateDecl`](#TypeAliasTemplateDecl) |
| `templated_declaration` | `INTEGER` | :heavy_check_mark: | [`TypeAliasDecl`](#TypeAliasDecl) |

This table also includes all of the fields contained in [`RedeclarableTemplateDecl`](#RedeclarableTemplateDecl).


</details>

<details><summary><a name="ConceptDecl"></a>ConceptDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `constraint_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |
| `is_type_concept` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`TemplateDecl`](#TemplateDecl).


</details>

<details><summary><a name="BuiltinTemplateDecl"></a>BuiltinTemplateDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`TemplateDecl`](#TemplateDecl).


</details>

<details><summary><a name="TemplateTemplateParmDecl"></a>TemplateTemplateParmDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`TemplateDecl`](#TemplateDecl).


</details>

<details><summary><a name="ObjCPropertyDecl"></a>ObjCPropertyDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_token` | `INTEGER` | :heavy_check_mark: | |
| `getter_method_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |
| `getter_name_token` | `INTEGER` | :heavy_check_mark: | |
| `l_paren_token` | `INTEGER` | :heavy_check_mark: | |
| `property_implementation` | `INTEGER` | :heavy_check_mark: | [`ObjCPropertyDeclPropertyControl`](#ObjCPropertyDeclPropertyControl) |
| `property_instance_variable_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCIvarDecl`](#ObjCIvarDecl) |
| `query_kind` | `INTEGER` | :heavy_check_mark: | [`ObjCPropertyQueryKind`](#ObjCPropertyQueryKind) |
| `setter_kind` | `INTEGER` | :heavy_check_mark: | [`ObjCPropertyDeclSetterKind`](#ObjCPropertyDeclSetterKind) |
| `setter_method_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDecl`](#ObjCMethodDecl) |
| `setter_name_token` | `INTEGER` | :heavy_check_mark: | |
| `type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `is_atomic` | `INTEGER` | :heavy_check_mark: | |
| `is_class_property` | `INTEGER` | :heavy_check_mark: | |
| `is_direct_property` | `INTEGER` | :heavy_check_mark: | |
| `is_instance_property` | `INTEGER` | :heavy_check_mark: | |
| `is_optional` | `INTEGER` | :heavy_check_mark: | |
| `is_read_only` | `INTEGER` | :heavy_check_mark: | |
| `is_retaining` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="ObjCMethodDecl"></a>ObjCMethodDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `defined_in_ns_object` | `INTEGER` | :heavy_check_mark: | |
| `find_property_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCPropertyDecl`](#ObjCPropertyDecl) |
| `class_interface` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |
| `command_declaration` | `INTEGER` | :heavy_check_mark: | [`ImplicitParamDecl`](#ImplicitParamDecl) |
| `declarator_end_token` | `INTEGER` | :heavy_check_mark: | |
| `implementation_control` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodDeclImplementationControl`](#ObjCMethodDeclImplementationControl) |
| `method_family` | `INTEGER` | :heavy_check_mark: | [`ObjCMethodFamily`](#ObjCMethodFamily) |
| `obj_c_decl_qualifier` | `INTEGER` | :heavy_check_mark: | [`DeclObjCDeclQualifier`](#DeclObjCDeclQualifier) |
| `return_type` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `selector_start_token` | `INTEGER` | :heavy_check_mark: | |
| `self_declaration` | `INTEGER` | :heavy_check_mark: | [`ImplicitParamDecl`](#ImplicitParamDecl) |
| `has_parameter_destroyed_in_callee` | `INTEGER` | :heavy_check_mark: | |
| `has_redeclaration` | `INTEGER` | :heavy_check_mark: | |
| `has_related_result_type` | `INTEGER` | :heavy_check_mark: | |
| `has_skipped_body` | `INTEGER` | :heavy_check_mark: | |
| `is_class_method` | `INTEGER` | :heavy_check_mark: | |
| `is_defined` | `INTEGER` | :heavy_check_mark: | |
| `is_designated_initializer_for_the_interface` | `INTEGER` | :heavy_check_mark: | |
| `is_direct_method` | `INTEGER` | :heavy_check_mark: | |
| `is_instance_method` | `INTEGER` | :heavy_check_mark: | |
| `is_optional` | `INTEGER` | :heavy_check_mark: | |
| `is_overriding` | `INTEGER` | :heavy_check_mark: | |
| `is_property_accessor` | `INTEGER` | :heavy_check_mark: | |
| `is_redeclaration` | `INTEGER` | :heavy_check_mark: | |
| `is_synthesized_accessor_stub` | `INTEGER` | :heavy_check_mark: | |
| `is_this_declaration_a_designated_initializer` | `INTEGER` | :heavy_check_mark: | |
| `is_variadic` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="ObjCContainerDecl"></a>ObjCContainerDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `at_start_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="ObjCCategoryDecl"></a>ObjCCategoryDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `is_class_extension` | `INTEGER` | :heavy_check_mark: | |
| `category_name_token` | `INTEGER` | :heavy_check_mark: | |
| `class_interface` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |
| `implementation` | `INTEGER` | :heavy_check_mark: | [`ObjCCategoryImplDecl`](#ObjCCategoryImplDecl) |
| `instance_variable_l_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `instance_variable_r_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `next_class_category` | `INTEGER` | :heavy_check_mark: | [`ObjCCategoryDecl`](#ObjCCategoryDecl) |

This table also includes all of the fields contained in [`ObjCContainerDecl`](#ObjCContainerDecl).


</details>

<details><summary><a name="ObjCProtocolDecl"></a>ObjCProtocolDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `obj_c_runtime_name_as_string` | `TEXT` | :heavy_check_mark: | |
| `has_definition` | `INTEGER` | :heavy_check_mark: | |
| `is_non_runtime_protocol` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ObjCContainerDecl`](#ObjCContainerDecl).


</details>

<details><summary><a name="ObjCInterfaceDecl"></a>ObjCInterfaceDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `declares_or_inherits_designated_initializers` | `INTEGER` | :heavy_check_mark: | |
| `end_of_definition_token` | `INTEGER` | :heavy_check_mark: | |
| `implementation` | `INTEGER` | :heavy_check_mark: | [`ObjCImplementationDecl`](#ObjCImplementationDecl) |
| `obj_c_runtime_name_as_string` | `TEXT` | :heavy_check_mark: | |
| `super_class` | `INTEGER` | :x: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |
| `super_class_token` | `INTEGER` | :heavy_check_mark: | |
| `super_class_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `type_for_declaration` | `INTEGER` | :heavy_check_mark: | [`Type`](#Type) |
| `has_definition` | `INTEGER` | :heavy_check_mark: | |
| `has_designated_initializers` | `INTEGER` | :heavy_check_mark: | |
| `is_arc_weakref_unavailable` | `INTEGER` | :heavy_check_mark: | |
| `is_implicit_interface_declaration` | `INTEGER` | :heavy_check_mark: | |
| `is_obj_c_requires_property_definitions` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |

This table also includes all of the fields contained in [`ObjCContainerDecl`](#ObjCContainerDecl).


</details>

<details><summary><a name="ObjCImplDecl"></a>ObjCImplDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `class_interface` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |

This table also includes all of the fields contained in [`ObjCContainerDecl`](#ObjCContainerDecl).


</details>

<details><summary><a name="ObjCCategoryImplDecl"></a>ObjCCategoryImplDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `category_declaration` | `INTEGER` | :heavy_check_mark: | [`ObjCCategoryDecl`](#ObjCCategoryDecl) |
| `category_name_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ObjCImplDecl`](#ObjCImplDecl).


</details>

<details><summary><a name="ObjCImplementationDecl"></a>ObjCImplementationDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `instance_variable_l_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `instance_variable_r_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `obj_c_runtime_name_as_string` | `TEXT` | :heavy_check_mark: | |
| `super_class` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |
| `super_class_token` | `INTEGER` | :heavy_check_mark: | |
| `has_destructors` | `INTEGER` | :heavy_check_mark: | |
| `has_non_zero_constructors` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`ObjCImplDecl`](#ObjCImplDecl).


</details>

<details><summary><a name="ObjCCompatibleAliasDecl"></a>ObjCCompatibleAliasDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `class_interface` | `INTEGER` | :heavy_check_mark: | [`ObjCInterfaceDecl`](#ObjCInterfaceDecl) |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="NamespaceDecl"></a>NamespaceDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="NamespaceAliasDecl"></a>NamespaceAliasDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `alias_token` | `INTEGER` | :heavy_check_mark: | |
| `aliased_namespace` | `INTEGER` | :heavy_check_mark: | [`NamedDecl`](#NamedDecl) |
| `namespace_token` | `INTEGER` | :heavy_check_mark: | |
| `target_name_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`NamedDecl`](#NamedDecl).


</details>

<details><summary><a name="LinkageSpecDecl"></a>LinkageSpecDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="LifetimeExtendedTemporaryDecl"></a>LifetimeExtendedTemporaryDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `extending_declaration` | `INTEGER` | :heavy_check_mark: | [`ValueDecl`](#ValueDecl) |
| `storage_duration` | `INTEGER` | :heavy_check_mark: | [`StorageDuration`](#StorageDuration) |
| `temporary_expression` | `INTEGER` | :heavy_check_mark: | [`Expr`](#Expr) |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="ImportDecl"></a>ImportDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="FriendTemplateDecl"></a>FriendTemplateDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="FriendDecl"></a>FriendDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `friend_declaration` | `INTEGER` | :x: | [`NamedDecl`](#NamedDecl) |
| `friend_token` | `INTEGER` | :heavy_check_mark: | |
| `friend_type` | `INTEGER` | :x: | [`Type`](#Type) |
| `is_unsupported_friend` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="FileScopeAsmDecl"></a>FileScopeAsmDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `assembly_token` | `INTEGER` | :heavy_check_mark: | |
| `assembly_string` | `INTEGER` | :heavy_check_mark: | [`StringLiteral`](#StringLiteral) |
| `r_paren_token` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="ExternCContextDecl"></a>ExternCContextDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="ExportDecl"></a>ExportDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |
| `export_token` | `INTEGER` | :heavy_check_mark: | |
| `r_brace_token` | `INTEGER` | :heavy_check_mark: | |
| `has_braces` | `INTEGER` | :heavy_check_mark: | |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>

<details><summary><a name="EmptyDecl"></a>EmptyDecl</summary>

| Name | Type | `NOT NULL` | References |
| --- | --- | --- | --- |

This table also includes all of the fields contained in [`Decl`](#Decl).


</details>



## List tables

These tables represent one-to-many relations between objects. For example, the arguments passed to a `CallExpr` will be represented using the `CallExprArguments` table, which will contain a row for each argument.

Each table consists of three fields:

* `parent_id`: id of the object this list belongs to.
* `pos`: position in the list of this row.
* `value`: value of the list entry. May be either an `INTEGER` or `TEXT` field depending on whether this is a list of booleans, integers, strings or entities.

These tables can only be queried on `parent_id`.


<details><summary><a name="TemplateParameterListParameters"></a>TemplateParameterListParameters</summary>

* Parent type: [`TemplateParameterList`](#TemplateParameterList)
* Value type: `INTEGER`
* References: [`NamedDecl`](#NamedDecl)

</details>


<details><summary><a name="ObjCObjectTypeTypeArguments"></a>ObjCObjectTypeTypeArguments</summary>

* Parent type: [`ObjCObjectType`](#ObjCObjectType)
* Value type: `INTEGER`
* References: [`Type`](#Type)

</details>


<details><summary><a name="ObjCObjectTypeTypeArgumentsAsWritten"></a>ObjCObjectTypeTypeArgumentsAsWritten</summary>

* Parent type: [`ObjCObjectType`](#ObjCObjectType)
* Value type: `INTEGER`
* References: [`Type`](#Type)

</details>


<details><summary><a name="ObjCObjectPointerTypeTypeArguments"></a>ObjCObjectPointerTypeTypeArguments</summary>

* Parent type: [`ObjCObjectPointerType`](#ObjCObjectPointerType)
* Value type: `INTEGER`
* References: [`Type`](#Type)

</details>


<details><summary><a name="ObjCObjectPointerTypeTypeArgumentsAsWritten"></a>ObjCObjectPointerTypeTypeArgumentsAsWritten</summary>

* Parent type: [`ObjCObjectPointerType`](#ObjCObjectPointerType)
* Value type: `INTEGER`
* References: [`Type`](#Type)

</details>


<details><summary><a name="ObjCObjectPointerTypeQualifieds"></a>ObjCObjectPointerTypeQualifieds</summary>

* Parent type: [`ObjCObjectPointerType`](#ObjCObjectPointerType)
* Value type: `INTEGER`
* References: [`ObjCProtocolDecl`](#ObjCProtocolDecl)

</details>


<details><summary><a name="ObjCObjectPointerTypeProtocols"></a>ObjCObjectPointerTypeProtocols</summary>

* Parent type: [`ObjCObjectPointerType`](#ObjCObjectPointerType)
* Value type: `INTEGER`
* References: [`ObjCProtocolDecl`](#ObjCProtocolDecl)

</details>


<details><summary><a name="FunctionProtoTypeExceptions"></a>FunctionProtoTypeExceptions</summary>

* Parent type: [`FunctionProtoType`](#FunctionProtoType)
* Value type: `INTEGER`
* References: [`Type`](#Type)

</details>


<details><summary><a name="FunctionProtoTypeParameterTypes"></a>FunctionProtoTypeParameterTypes</summary>

* Parent type: [`FunctionProtoType`](#FunctionProtoType)
* Value type: `INTEGER`
* References: [`Type`](#Type)

</details>


<details><summary><a name="FunctionProtoTypeExceptionTypes"></a>FunctionProtoTypeExceptionTypes</summary>

* Parent type: [`FunctionProtoType`](#FunctionProtoType)
* Value type: `INTEGER`
* References: [`Type`](#Type)

</details>


<details><summary><a name="StmtChildren"></a>StmtChildren</summary>

* Parent type: [`Stmt`](#Stmt)
* Value type: `INTEGER`
* References: [`Stmt`](#Stmt)

</details>


<details><summary><a name="ObjCAtTryStmtCatchStatements"></a>ObjCAtTryStmtCatchStatements</summary>

* Parent type: [`ObjCAtTryStmt`](#ObjCAtTryStmt)
* Value type: `INTEGER`
* References: [`ObjCAtCatchStmt`](#ObjCAtCatchStmt)

</details>


<details><summary><a name="OMPLoopDirectiveCounters"></a>OMPLoopDirectiveCounters</summary>

* Parent type: [`OMPLoopDirective`](#OMPLoopDirective)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="OMPLoopDirectiveDependentCounters"></a>OMPLoopDirectiveDependentCounters</summary>

* Parent type: [`OMPLoopDirective`](#OMPLoopDirective)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="OMPLoopDirectiveDependentInitializers"></a>OMPLoopDirectiveDependentInitializers</summary>

* Parent type: [`OMPLoopDirective`](#OMPLoopDirective)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="OMPLoopDirectiveFinals"></a>OMPLoopDirectiveFinals</summary>

* Parent type: [`OMPLoopDirective`](#OMPLoopDirective)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="OMPLoopDirectiveFinalsConditions"></a>OMPLoopDirectiveFinalsConditions</summary>

* Parent type: [`OMPLoopDirective`](#OMPLoopDirective)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="OMPLoopDirectiveInitializers"></a>OMPLoopDirectiveInitializers</summary>

* Parent type: [`OMPLoopDirective`](#OMPLoopDirective)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="OMPLoopDirectivePrivateCounters"></a>OMPLoopDirectivePrivateCounters</summary>

* Parent type: [`OMPLoopDirective`](#OMPLoopDirective)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="OMPLoopDirectiveUpdates"></a>OMPLoopDirectiveUpdates</summary>

* Parent type: [`OMPLoopDirective`](#OMPLoopDirective)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="DeclStmtDeclarations"></a>DeclStmtDeclarations</summary>

* Parent type: [`DeclStmt`](#DeclStmt)
* Value type: `INTEGER`
* References: [`Decl`](#Decl)

</details>


<details><summary><a name="CoroutineBodyStmtParameterMoves"></a>CoroutineBodyStmtParameterMoves</summary>

* Parent type: [`CoroutineBodyStmt`](#CoroutineBodyStmt)
* Value type: `INTEGER`
* References: [`Stmt`](#Stmt)

</details>


<details><summary><a name="CXXTryStmtHandlers"></a>CXXTryStmtHandlers</summary>

* Parent type: [`CXXTryStmt`](#CXXTryStmt)
* Value type: `INTEGER`
* References: [`CXXCatchStmt`](#CXXCatchStmt)

</details>


<details><summary><a name="AsmStmtInputs"></a>AsmStmtInputs</summary>

* Parent type: [`AsmStmt`](#AsmStmt)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="AsmStmtOutputs"></a>AsmStmtOutputs</summary>

* Parent type: [`AsmStmt`](#AsmStmt)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="AsmStmtOutputConstraints"></a>AsmStmtOutputConstraints</summary>

* Parent type: [`AsmStmt`](#AsmStmt)
* Value type: `TEXT`

</details>


<details><summary><a name="AsmStmtOutputExpressions"></a>AsmStmtOutputExpressions</summary>

* Parent type: [`AsmStmt`](#AsmStmt)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="AsmStmtInputConstraints"></a>AsmStmtInputConstraints</summary>

* Parent type: [`AsmStmt`](#AsmStmt)
* Value type: `TEXT`

</details>


<details><summary><a name="AsmStmtInputExpressions"></a>AsmStmtInputExpressions</summary>

* Parent type: [`AsmStmt`](#AsmStmt)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="AsmStmtClobbers"></a>AsmStmtClobbers</summary>

* Parent type: [`AsmStmt`](#AsmStmt)
* Value type: `TEXT`

</details>


<details><summary><a name="MSAsmStmtAllConstraints"></a>MSAsmStmtAllConstraints</summary>

* Parent type: [`MSAsmStmt`](#MSAsmStmt)
* Value type: `TEXT`

</details>


<details><summary><a name="MSAsmStmtAllExpressions"></a>MSAsmStmtAllExpressions</summary>

* Parent type: [`MSAsmStmt`](#MSAsmStmt)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="GCCAsmStmtLabels"></a>GCCAsmStmtLabels</summary>

* Parent type: [`GCCAsmStmt`](#GCCAsmStmt)
* Value type: `INTEGER`
* References: [`AddrLabelExpr`](#AddrLabelExpr)

</details>


<details><summary><a name="GCCAsmStmtOutputConstraintLiterals"></a>GCCAsmStmtOutputConstraintLiterals</summary>

* Parent type: [`GCCAsmStmt`](#GCCAsmStmt)
* Value type: `INTEGER`
* References: [`StringLiteral`](#StringLiteral)

</details>


<details><summary><a name="GCCAsmStmtOutputNames"></a>GCCAsmStmtOutputNames</summary>

* Parent type: [`GCCAsmStmt`](#GCCAsmStmt)
* Value type: `TEXT`

</details>


<details><summary><a name="GCCAsmStmtInputConstraintLiterals"></a>GCCAsmStmtInputConstraintLiterals</summary>

* Parent type: [`GCCAsmStmt`](#GCCAsmStmt)
* Value type: `INTEGER`
* References: [`StringLiteral`](#StringLiteral)

</details>


<details><summary><a name="GCCAsmStmtInputNames"></a>GCCAsmStmtInputNames</summary>

* Parent type: [`GCCAsmStmt`](#GCCAsmStmt)
* Value type: `TEXT`

</details>


<details><summary><a name="GCCAsmStmtClobberStringLiterals"></a>GCCAsmStmtClobberStringLiterals</summary>

* Parent type: [`GCCAsmStmt`](#GCCAsmStmt)
* Value type: `INTEGER`
* References: [`StringLiteral`](#StringLiteral)

</details>


<details><summary><a name="GCCAsmStmtLabelExpressions"></a>GCCAsmStmtLabelExpressions</summary>

* Parent type: [`GCCAsmStmt`](#GCCAsmStmt)
* Value type: `INTEGER`
* References: [`AddrLabelExpr`](#AddrLabelExpr)

</details>


<details><summary><a name="GCCAsmStmtLabelNames"></a>GCCAsmStmtLabelNames</summary>

* Parent type: [`GCCAsmStmt`](#GCCAsmStmt)
* Value type: `TEXT`

</details>


<details><summary><a name="DesignatedInitExprSubExpressions"></a>DesignatedInitExprSubExpressions</summary>

* Parent type: [`DesignatedInitExpr`](#DesignatedInitExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="CallExprArguments"></a>CallExprArguments</summary>

* Parent type: [`CallExpr`](#CallExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="CXXUnresolvedConstructExprArguments"></a>CXXUnresolvedConstructExprArguments</summary>

* Parent type: [`CXXUnresolvedConstructExpr`](#CXXUnresolvedConstructExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="CXXNewExprPlacementArguments"></a>CXXNewExprPlacementArguments</summary>

* Parent type: [`CXXNewExpr`](#CXXNewExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="CXXConstructExprArguments"></a>CXXConstructExprArguments</summary>

* Parent type: [`CXXConstructExpr`](#CXXConstructExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="AtomicExprSubExpressions"></a>AtomicExprSubExpressions</summary>

* Parent type: [`AtomicExpr`](#AtomicExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="TypeTraitExprArguments"></a>TypeTraitExprArguments</summary>

* Parent type: [`TypeTraitExpr`](#TypeTraitExpr)
* Value type: `INTEGER`
* References: [`Type`](#Type)

</details>


<details><summary><a name="RequiresExprLocalParameters"></a>RequiresExprLocalParameters</summary>

* Parent type: [`RequiresExpr`](#RequiresExpr)
* Value type: `INTEGER`
* References: [`ParmVarDecl`](#ParmVarDecl)

</details>


<details><summary><a name="RecoveryExprSubExpressions"></a>RecoveryExprSubExpressions</summary>

* Parent type: [`RecoveryExpr`](#RecoveryExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="PseudoObjectExprSemantics"></a>PseudoObjectExprSemantics</summary>

* Parent type: [`PseudoObjectExpr`](#PseudoObjectExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="PseudoObjectExprSemanticExpressions"></a>PseudoObjectExprSemanticExpressions</summary>

* Parent type: [`PseudoObjectExpr`](#PseudoObjectExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="ParenListExprExpressions"></a>ParenListExprExpressions</summary>

* Parent type: [`ParenListExpr`](#ParenListExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="ObjCMessageExprArguments"></a>ObjCMessageExprArguments</summary>

* Parent type: [`ObjCMessageExpr`](#ObjCMessageExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="ObjCMessageExprSelectorTokens"></a>ObjCMessageExprSelectorTokens</summary>

* Parent type: [`ObjCMessageExpr`](#ObjCMessageExpr)
* Value type: `INTEGER`
* References: [`Token`](#Token)

</details>


<details><summary><a name="ObjCArrayLiteralElements"></a>ObjCArrayLiteralElements</summary>

* Parent type: [`ObjCArrayLiteral`](#ObjCArrayLiteral)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="OMPArrayShapingExprDimensions"></a>OMPArrayShapingExprDimensions</summary>

* Parent type: [`OMPArrayShapingExpr`](#OMPArrayShapingExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="LambdaExprExplicitTemplateParameters"></a>LambdaExprExplicitTemplateParameters</summary>

* Parent type: [`LambdaExpr`](#LambdaExpr)
* Value type: `INTEGER`
* References: [`NamedDecl`](#NamedDecl)

</details>


<details><summary><a name="InitListExprInitializers"></a>InitListExprInitializers</summary>

* Parent type: [`InitListExpr`](#InitListExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="GenericSelectionExprAssociationExpressions"></a>GenericSelectionExprAssociationExpressions</summary>

* Parent type: [`GenericSelectionExpr`](#GenericSelectionExpr)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="FunctionParmPackExprExpansions"></a>FunctionParmPackExprExpansions</summary>

* Parent type: [`FunctionParmPackExpr`](#FunctionParmPackExpr)
* Value type: `INTEGER`
* References: [`VarDecl`](#VarDecl)

</details>


<details><summary><a name="DeclRedeclarations"></a>DeclRedeclarations</summary>

* Parent type: [`Decl`](#Decl)
* Value type: `INTEGER`
* References: [`Decl`](#Decl)

</details>


<details><summary><a name="CapturedDeclParameters"></a>CapturedDeclParameters</summary>

* Parent type: [`CapturedDecl`](#CapturedDecl)
* Value type: `INTEGER`
* References: [`ImplicitParamDecl`](#ImplicitParamDecl)

</details>


<details><summary><a name="BlockDeclParameters"></a>BlockDeclParameters</summary>

* Parent type: [`BlockDecl`](#BlockDecl)
* Value type: `INTEGER`
* References: [`ParmVarDecl`](#ParmVarDecl)

</details>


<details><summary><a name="BlockDeclParameterDeclarations"></a>BlockDeclParameterDeclarations</summary>

* Parent type: [`BlockDecl`](#BlockDecl)
* Value type: `INTEGER`
* References: [`ParmVarDecl`](#ParmVarDecl)

</details>


<details><summary><a name="OMPThreadPrivateDeclVarlists"></a>OMPThreadPrivateDeclVarlists</summary>

* Parent type: [`OMPThreadPrivateDecl`](#OMPThreadPrivateDecl)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="OMPAllocateDeclVarlists"></a>OMPAllocateDeclVarlists</summary>

* Parent type: [`OMPAllocateDecl`](#OMPAllocateDecl)
* Value type: `INTEGER`
* References: [`Expr`](#Expr)

</details>


<details><summary><a name="BaseUsingDeclShadows"></a>BaseUsingDeclShadows</summary>

* Parent type: [`BaseUsingDecl`](#BaseUsingDecl)
* Value type: `INTEGER`
* References: [`UsingShadowDecl`](#UsingShadowDecl)

</details>


<details><summary><a name="IndirectFieldDeclChain"></a>IndirectFieldDeclChain</summary>

* Parent type: [`IndirectFieldDecl`](#IndirectFieldDecl)
* Value type: `INTEGER`
* References: [`NamedDecl`](#NamedDecl)

</details>


<details><summary><a name="DecompositionDeclBindings"></a>DecompositionDeclBindings</summary>

* Parent type: [`DecompositionDecl`](#DecompositionDecl)
* Value type: `INTEGER`
* References: [`BindingDecl`](#BindingDecl)

</details>


<details><summary><a name="NonTypeTemplateParmDeclExpansionTypes"></a>NonTypeTemplateParmDeclExpansionTypes</summary>

* Parent type: [`NonTypeTemplateParmDecl`](#NonTypeTemplateParmDecl)
* Value type: `INTEGER`
* References: [`Type`](#Type)

</details>


<details><summary><a name="FunctionDeclParameters"></a>FunctionDeclParameters</summary>

* Parent type: [`FunctionDecl`](#FunctionDecl)
* Value type: `INTEGER`
* References: [`ParmVarDecl`](#ParmVarDecl)

</details>


<details><summary><a name="CXXMethodDeclOverriddenMethods"></a>CXXMethodDeclOverriddenMethods</summary>

* Parent type: [`CXXMethodDecl`](#CXXMethodDecl)
* Value type: `INTEGER`
* References: [`CXXMethodDecl`](#CXXMethodDecl)

</details>


<details><summary><a name="CXXMethodDeclParameterDeclarations"></a>CXXMethodDeclParameterDeclarations</summary>

* Parent type: [`CXXMethodDecl`](#CXXMethodDecl)
* Value type: `INTEGER`
* References: [`ParmVarDecl`](#ParmVarDecl)

</details>


<details><summary><a name="CXXDeductionGuideDeclParameterDeclarations"></a>CXXDeductionGuideDeclParameterDeclarations</summary>

* Parent type: [`CXXDeductionGuideDecl`](#CXXDeductionGuideDecl)
* Value type: `INTEGER`
* References: [`ParmVarDecl`](#ParmVarDecl)

</details>


<details><summary><a name="UsingPackDeclExpansions"></a>UsingPackDeclExpansions</summary>

* Parent type: [`UsingPackDecl`](#UsingPackDecl)
* Value type: `INTEGER`
* References: [`NamedDecl`](#NamedDecl)

</details>


<details><summary><a name="RecordDeclFields"></a>RecordDeclFields</summary>

* Parent type: [`RecordDecl`](#RecordDecl)
* Value type: `INTEGER`
* References: [`FieldDecl`](#FieldDecl)

</details>


<details><summary><a name="CXXRecordDeclConstructors"></a>CXXRecordDeclConstructors</summary>

* Parent type: [`CXXRecordDecl`](#CXXRecordDecl)
* Value type: `INTEGER`
* References: [`CXXConstructorDecl`](#CXXConstructorDecl)

</details>


<details><summary><a name="CXXRecordDeclFriends"></a>CXXRecordDeclFriends</summary>

* Parent type: [`CXXRecordDecl`](#CXXRecordDecl)
* Value type: `INTEGER`
* References: [`FriendDecl`](#FriendDecl)

</details>


<details><summary><a name="CXXRecordDeclLambdaExplicitTemplateParameters"></a>CXXRecordDeclLambdaExplicitTemplateParameters</summary>

* Parent type: [`CXXRecordDecl`](#CXXRecordDecl)
* Value type: `INTEGER`
* References: [`NamedDecl`](#NamedDecl)

</details>


<details><summary><a name="CXXRecordDeclMethods"></a>CXXRecordDeclMethods</summary>

* Parent type: [`CXXRecordDecl`](#CXXRecordDecl)
* Value type: `INTEGER`
* References: [`CXXMethodDecl`](#CXXMethodDecl)

</details>


<details><summary><a name="EnumDeclEnumerators"></a>EnumDeclEnumerators</summary>

* Parent type: [`EnumDecl`](#EnumDecl)
* Value type: `INTEGER`
* References: [`EnumConstantDecl`](#EnumConstantDecl)

</details>


<details><summary><a name="ObjCMethodDeclParameters"></a>ObjCMethodDeclParameters</summary>

* Parent type: [`ObjCMethodDecl`](#ObjCMethodDecl)
* Value type: `INTEGER`
* References: [`ParmVarDecl`](#ParmVarDecl)

</details>


<details><summary><a name="ObjCMethodDeclSelectorTokens"></a>ObjCMethodDeclSelectorTokens</summary>

* Parent type: [`ObjCMethodDecl`](#ObjCMethodDecl)
* Value type: `INTEGER`
* References: [`Token`](#Token)

</details>


<details><summary><a name="ObjCContainerDeclClassMethods"></a>ObjCContainerDeclClassMethods</summary>

* Parent type: [`ObjCContainerDecl`](#ObjCContainerDecl)
* Value type: `INTEGER`
* References: [`ObjCMethodDecl`](#ObjCMethodDecl)

</details>


<details><summary><a name="ObjCContainerDeclClassProperties"></a>ObjCContainerDeclClassProperties</summary>

* Parent type: [`ObjCContainerDecl`](#ObjCContainerDecl)
* Value type: `INTEGER`
* References: [`ObjCPropertyDecl`](#ObjCPropertyDecl)

</details>


<details><summary><a name="ObjCContainerDeclInstanceMethods"></a>ObjCContainerDeclInstanceMethods</summary>

* Parent type: [`ObjCContainerDecl`](#ObjCContainerDecl)
* Value type: `INTEGER`
* References: [`ObjCMethodDecl`](#ObjCMethodDecl)

</details>


<details><summary><a name="ObjCContainerDeclInstanceProperties"></a>ObjCContainerDeclInstanceProperties</summary>

* Parent type: [`ObjCContainerDecl`](#ObjCContainerDecl)
* Value type: `INTEGER`
* References: [`ObjCPropertyDecl`](#ObjCPropertyDecl)

</details>


<details><summary><a name="ObjCContainerDeclMethods"></a>ObjCContainerDeclMethods</summary>

* Parent type: [`ObjCContainerDecl`](#ObjCContainerDecl)
* Value type: `INTEGER`
* References: [`ObjCMethodDecl`](#ObjCMethodDecl)

</details>


<details><summary><a name="ObjCContainerDeclProperties"></a>ObjCContainerDeclProperties</summary>

* Parent type: [`ObjCContainerDecl`](#ObjCContainerDecl)
* Value type: `INTEGER`
* References: [`ObjCPropertyDecl`](#ObjCPropertyDecl)

</details>


<details><summary><a name="ObjCCategoryDeclInstanceVariables"></a>ObjCCategoryDeclInstanceVariables</summary>

* Parent type: [`ObjCCategoryDecl`](#ObjCCategoryDecl)
* Value type: `INTEGER`
* References: [`ObjCIvarDecl`](#ObjCIvarDecl)

</details>


<details><summary><a name="ObjCCategoryDeclProtocolTokens"></a>ObjCCategoryDeclProtocolTokens</summary>

* Parent type: [`ObjCCategoryDecl`](#ObjCCategoryDecl)
* Value type: `INTEGER`
* References: [`Token`](#Token)

</details>


<details><summary><a name="ObjCCategoryDeclProtocols"></a>ObjCCategoryDeclProtocols</summary>

* Parent type: [`ObjCCategoryDecl`](#ObjCCategoryDecl)
* Value type: `INTEGER`
* References: [`ObjCProtocolDecl`](#ObjCProtocolDecl)

</details>


<details><summary><a name="ObjCProtocolDeclProtocolTokens"></a>ObjCProtocolDeclProtocolTokens</summary>

* Parent type: [`ObjCProtocolDecl`](#ObjCProtocolDecl)
* Value type: `INTEGER`
* References: [`Token`](#Token)

</details>


<details><summary><a name="ObjCProtocolDeclProtocols"></a>ObjCProtocolDeclProtocols</summary>

* Parent type: [`ObjCProtocolDecl`](#ObjCProtocolDecl)
* Value type: `INTEGER`
* References: [`ObjCProtocolDecl`](#ObjCProtocolDecl)

</details>


<details><summary><a name="ObjCInterfaceDeclAllReferencedProtocols"></a>ObjCInterfaceDeclAllReferencedProtocols</summary>

* Parent type: [`ObjCInterfaceDecl`](#ObjCInterfaceDecl)
* Value type: `INTEGER`
* References: [`ObjCProtocolDecl`](#ObjCProtocolDecl)

</details>


<details><summary><a name="ObjCInterfaceDeclInstanceVariables"></a>ObjCInterfaceDeclInstanceVariables</summary>

* Parent type: [`ObjCInterfaceDecl`](#ObjCInterfaceDecl)
* Value type: `INTEGER`
* References: [`ObjCIvarDecl`](#ObjCIvarDecl)

</details>


<details><summary><a name="ObjCInterfaceDeclKnownCategories"></a>ObjCInterfaceDeclKnownCategories</summary>

* Parent type: [`ObjCInterfaceDecl`](#ObjCInterfaceDecl)
* Value type: `INTEGER`
* References: [`ObjCCategoryDecl`](#ObjCCategoryDecl)

</details>


<details><summary><a name="ObjCInterfaceDeclKnownExtensions"></a>ObjCInterfaceDeclKnownExtensions</summary>

* Parent type: [`ObjCInterfaceDecl`](#ObjCInterfaceDecl)
* Value type: `INTEGER`
* References: [`ObjCCategoryDecl`](#ObjCCategoryDecl)

</details>


<details><summary><a name="ObjCInterfaceDeclProtocolTokens"></a>ObjCInterfaceDeclProtocolTokens</summary>

* Parent type: [`ObjCInterfaceDecl`](#ObjCInterfaceDecl)
* Value type: `INTEGER`
* References: [`Token`](#Token)

</details>


<details><summary><a name="ObjCInterfaceDeclProtocols"></a>ObjCInterfaceDeclProtocols</summary>

* Parent type: [`ObjCInterfaceDecl`](#ObjCInterfaceDecl)
* Value type: `INTEGER`
* References: [`ObjCProtocolDecl`](#ObjCProtocolDecl)

</details>


<details><summary><a name="ObjCInterfaceDeclVisibleCategories"></a>ObjCInterfaceDeclVisibleCategories</summary>

* Parent type: [`ObjCInterfaceDecl`](#ObjCInterfaceDecl)
* Value type: `INTEGER`
* References: [`ObjCCategoryDecl`](#ObjCCategoryDecl)

</details>


<details><summary><a name="ObjCInterfaceDeclVisibleExtensions"></a>ObjCInterfaceDeclVisibleExtensions</summary>

* Parent type: [`ObjCInterfaceDecl`](#ObjCInterfaceDecl)
* Value type: `INTEGER`
* References: [`ObjCCategoryDecl`](#ObjCCategoryDecl)

</details>


<details><summary><a name="ObjCImplDeclPropertyImplementations"></a>ObjCImplDeclPropertyImplementations</summary>

* Parent type: [`ObjCImplDecl`](#ObjCImplDecl)
* Value type: `INTEGER`
* References: [`ObjCPropertyImplDecl`](#ObjCPropertyImplDecl)

</details>


<details><summary><a name="ObjCImplementationDeclInstanceVariables"></a>ObjCImplementationDeclInstanceVariables</summary>

* Parent type: [`ObjCImplementationDecl`](#ObjCImplementationDecl)
* Value type: `INTEGER`
* References: [`ObjCIvarDecl`](#ObjCIvarDecl)

</details>


<details><summary><a name="LifetimeExtendedTemporaryDeclChildrenExpression"></a>LifetimeExtendedTemporaryDeclChildrenExpression</summary>

* Parent type: [`LifetimeExtendedTemporaryDecl`](#LifetimeExtendedTemporaryDecl)
* Value type: `INTEGER`
* References: [`Stmt`](#Stmt)

</details>


<details><summary><a name="ImportDeclIdentifierTokens"></a>ImportDeclIdentifierTokens</summary>

* Parent type: [`ImportDecl`](#ImportDecl)
* Value type: `INTEGER`
* References: [`Token`](#Token)

</details>

