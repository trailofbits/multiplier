#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

# Auto-generated file; do not modify!

from abc import ABC
from enum import IntEnum
from typing import Generator, Iterable, Mapping, Optional, overload, Sequence, Tuple
import pathlib
import multiplier
import multiplier.ir
import multiplier.ast
import multiplier.ir.abi
import multiplier.ir.llvm
import multiplier.ir.core
import multiplier.ir.meta
import multiplier.frontend
import multiplier.ir.memref
import multiplier.ir.builtin
import multiplier.ir.lowlevel
import multiplier.ir.highlevel
import multiplier.ir.unsupported

class Attribute(multiplier.ir.Attribute):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.Attribute]:
    ...

class CConvAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.CConvAttr]:
    ...

class ComdatAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.ComdatAttr]:
    ...

class AccessGroupAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.AccessGroupAttr]:
    ...

class AliasScopeAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.AliasScopeAttr]:
    ...

class AliasScopeDomainAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.AliasScopeDomainAttr]:
    ...

class DIBasicTypeAttr(multiplier.ir.llvm.Attribute):
  size_in_bits: int

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DIBasicTypeAttr]:
    ...

class DICompileUnitAttr(multiplier.ir.llvm.Attribute):
  is_optimized: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DICompileUnitAttr]:
    ...

class DICompositeTypeAttr(multiplier.ir.llvm.Attribute):
  line: int
  size_in_bits: int
  align_in_bits: int

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DICompositeTypeAttr]:
    ...

class DIDerivedTypeAttr(multiplier.ir.llvm.Attribute):
  size_in_bits: int
  align_in_bits: int
  offset_in_bits: int

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DIDerivedTypeAttr]:
    ...

class DIFileAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DIFileAttr]:
    ...

class DILabelAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DILabelAttr]:
    ...

class DILexicalBlockAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DILexicalBlockAttr]:
    ...

class DILexicalBlockFileAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DILexicalBlockFileAttr]:
    ...

class DILocalVariableAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DILocalVariableAttr]:
    ...

class DINamespaceAttr(multiplier.ir.llvm.Attribute):
  export_symbols: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DINamespaceAttr]:
    ...

class DINullTypeAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DINullTypeAttr]:
    ...

class DISubprogramAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DISubprogramAttr]:
    ...

class DISubrangeAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DISubrangeAttr]:
    ...

class DISubroutineTypeAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.DISubroutineTypeAttr]:
    ...

class FastmathFlagsAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.FastmathFlagsAttr]:
    ...

class MemoryEffectsAttr(multiplier.ir.llvm.Attribute):
  is_read_write: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.MemoryEffectsAttr]:
    ...

class TBAAMemberAttr(multiplier.ir.llvm.Attribute):
  offset: int

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.TBAAMemberAttr]:
    ...

class TBAARootAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.TBAARootAttr]:
    ...

class TBAATagAttr(multiplier.ir.llvm.Attribute):
  offset: int
  constant: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.TBAATagAttr]:
    ...

class TBAATypeDescriptorAttr(multiplier.ir.llvm.Attribute):
  id: str

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.TBAATypeDescriptorAttr]:
    ...

class LinkageAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LinkageAttr]:
    ...

class LoopAnnotationAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LoopAnnotationAttr]:
    ...

class LoopDistributeAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LoopDistributeAttr]:
    ...

class LoopInterleaveAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LoopInterleaveAttr]:
    ...

class LoopLICMAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LoopLICMAttr]:
    ...

class LoopPeeledAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LoopPeeledAttr]:
    ...

class LoopPipelineAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LoopPipelineAttr]:
    ...

class LoopUnrollAndJamAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LoopUnrollAndJamAttr]:
    ...

class LoopUnrollAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LoopUnrollAttr]:
    ...

class LoopUnswitchAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LoopUnswitchAttr]:
    ...

class LoopVectorizeAttr(multiplier.ir.llvm.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.llvm.LoopVectorizeAttr]:
    ...

class Operation(multiplier.ir.Operation):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.Operation]:
    ...

class AShrOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AShrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AShrOp]:
    ...

class AddOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AddOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AddOp]:
    ...

class AddrSpaceCastOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AddrSpaceCastOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AddrSpaceCastOp]:
    ...

class AddressOfOp(multiplier.ir.llvm.Operation):
  global_name: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AddressOfOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AddressOfOp]:
    ...

class AllocaOp(multiplier.ir.llvm.Operation):
  inalloca: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AllocaOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AllocaOp]:
    ...

class AndOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AndOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AndOp]:
    ...

class AtomicCmpXchgOp(multiplier.ir.llvm.Operation):
  cmp: multiplier.ir.Value
  val: multiplier.ir.Value
  res: multiplier.ir.Value
  syncscope: Optional[str]
  weak: bool
  volatile__: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AtomicCmpXchgOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AtomicCmpXchgOp]:
    ...

class AtomicRMWOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  res: multiplier.ir.Value
  syncscope: Optional[str]
  volatile__: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AtomicRMWOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AtomicRMWOp]:
    ...

class BitcastOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.BitcastOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.BitcastOp]:
    ...

class BrOp(multiplier.ir.llvm.Operation):
  dest_operands: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.BrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.BrOp]:
    ...

class CallOp(multiplier.ir.llvm.Operation):
  result: multiplier.ir.Value
  callee: Optional[str]
  arg_operands: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CallOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CallOp]:
    ...

class ComdatOp(multiplier.ir.llvm.Operation):
  body: multiplier.ir.Region
  sym_name: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ComdatOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ComdatOp]:
    ...

class ComdatSelectorOp(multiplier.ir.llvm.Operation):
  sym_name: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ComdatSelectorOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ComdatSelectorOp]:
    ...

class CondBrOp(multiplier.ir.llvm.Operation):
  true_dest_operands: Iterable[multiplier.ir.Operand]
  false_dest_operands: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CondBrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CondBrOp]:
    ...

class ConstantOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ConstantOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ConstantOp]:
    ...

class ExtractElementOp(multiplier.ir.llvm.Operation):
  vector: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ExtractElementOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ExtractElementOp]:
    ...

class ExtractValueOp(multiplier.ir.llvm.Operation):
  container: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ExtractValueOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ExtractValueOp]:
    ...

class FAddOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FAddOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FAddOp]:
    ...

class FCmpOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FCmpOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FCmpOp]:
    ...

class FDivOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FDivOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FDivOp]:
    ...

class FMulOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FMulOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FMulOp]:
    ...

class FNegOp(multiplier.ir.llvm.Operation):
  operand: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FNegOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FNegOp]:
    ...

class FPExtOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FPExtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FPExtOp]:
    ...

class FPToSIOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FPToSIOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FPToSIOp]:
    ...

class FPToUIOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FPToUIOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FPToUIOp]:
    ...

class FPTruncOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FPTruncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FPTruncOp]:
    ...

class FRemOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FRemOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FRemOp]:
    ...

class FSubOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FSubOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FSubOp]:
    ...

class FenceOp(multiplier.ir.llvm.Operation):
  syncscope: Optional[str]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FenceOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FenceOp]:
    ...

class FreezeOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FreezeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FreezeOp]:
    ...

class GetElementPtrOp(multiplier.ir.llvm.Operation):
  base: multiplier.ir.Value
  dynamic_indices: Iterable[multiplier.ir.Operand]
  res: multiplier.ir.Value
  inbounds: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.GetElementPtrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.GetElementPtrOp]:
    ...

class GlobalCtorsOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.GlobalCtorsOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.GlobalCtorsOp]:
    ...

class GlobalDtorsOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.GlobalDtorsOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.GlobalDtorsOp]:
    ...

class GlobalOp(multiplier.ir.llvm.Operation):
  initializer: multiplier.ir.Region
  constant: bool
  sym_name: str
  dso_local: bool
  thread_local__: bool
  addr_space: int
  section: Optional[str]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.GlobalOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.GlobalOp]:
    ...

class ICmpOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ICmpOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ICmpOp]:
    ...

class InlineAsmOp(multiplier.ir.llvm.Operation):
  operands: Iterable[multiplier.ir.Operand]
  res: multiplier.ir.Value
  asm_string: str
  constraints: str
  has_side_effects: bool
  is_align_stack: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.InlineAsmOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.InlineAsmOp]:
    ...

class InsertElementOp(multiplier.ir.llvm.Operation):
  vector: multiplier.ir.Value
  value: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.InsertElementOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.InsertElementOp]:
    ...

class InsertValueOp(multiplier.ir.llvm.Operation):
  container: multiplier.ir.Value
  value: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.InsertValueOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.InsertValueOp]:
    ...

class IntToPtrOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.IntToPtrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.IntToPtrOp]:
    ...

class InvokeOp(multiplier.ir.llvm.Operation):
  callee_operands: Iterable[multiplier.ir.Operand]
  normal_dest_operands: Iterable[multiplier.ir.Operand]
  unwind_dest_operands: Iterable[multiplier.ir.Operand]
  callee: Optional[str]
  arg_operands: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.InvokeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.InvokeOp]:
    ...

class FuncOp(multiplier.ir.llvm.Operation):
  body: multiplier.ir.Region
  sym_name: str
  dso_local: bool
  personality: Optional[str]
  garbage_collector: Optional[str]
  section: Optional[str]
  is_var_arg: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FuncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FuncOp]:
    ...

class LShrOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.LShrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.LShrOp]:
    ...

class LandingpadOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value
  cleanup: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.LandingpadOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.LandingpadOp]:
    ...

class LoadOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value
  volatile__: bool
  nontemporal: bool
  syncscope: Optional[str]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.LoadOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.LoadOp]:
    ...

class MetadataOp(multiplier.ir.llvm.Operation):
  body: multiplier.ir.Region
  sym_name: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MetadataOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MetadataOp]:
    ...

class MulOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MulOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MulOp]:
    ...

class NullOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.NullOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.NullOp]:
    ...

class OrOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.OrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.OrOp]:
    ...

class PoisonOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.PoisonOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.PoisonOp]:
    ...

class PtrToIntOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.PtrToIntOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.PtrToIntOp]:
    ...

class ResumeOp(multiplier.ir.llvm.Operation):
  value: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ResumeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ResumeOp]:
    ...

class ReturnOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ReturnOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ReturnOp]:
    ...

class SDivOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SDivOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SDivOp]:
    ...

class SExtOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SExtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SExtOp]:
    ...

class SIToFPOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SIToFPOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SIToFPOp]:
    ...

class SRemOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SRemOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SRemOp]:
    ...

class SelectOp(multiplier.ir.llvm.Operation):
  condition: multiplier.ir.Value
  true_value: multiplier.ir.Value
  false_value: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SelectOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SelectOp]:
    ...

class ShlOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ShlOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ShlOp]:
    ...

class ShuffleVectorOp(multiplier.ir.llvm.Operation):
  v1: multiplier.ir.Value
  v2: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ShuffleVectorOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ShuffleVectorOp]:
    ...

class StoreOp(multiplier.ir.llvm.Operation):
  value: multiplier.ir.Value
  volatile__: bool
  nontemporal: bool
  syncscope: Optional[str]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.StoreOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.StoreOp]:
    ...

class SubOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SubOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SubOp]:
    ...

class SwitchOp(multiplier.ir.llvm.Operation):
  default_operands: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SwitchOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SwitchOp]:
    ...

class TruncOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.TruncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.TruncOp]:
    ...

class UDivOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UDivOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UDivOp]:
    ...

class UIToFPOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UIToFPOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UIToFPOp]:
    ...

class URemOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.URemOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.URemOp]:
    ...

class UndefOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UndefOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UndefOp]:
    ...

class UnreachableOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UnreachableOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UnreachableOp]:
    ...

class XOrOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.XOrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.XOrOp]:
    ...

class ZExtOp(multiplier.ir.llvm.Operation):
  arg: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ZExtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ZExtOp]:
    ...

class AbsOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value
  is_int_min_poison: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AbsOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AbsOp]:
    ...

class AnnotationOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AnnotationOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AnnotationOp]:
    ...

class AssumeOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.AssumeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.AssumeOp]:
    ...

class BitReverseOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.BitReverseOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.BitReverseOp]:
    ...

class ByteSwapOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ByteSwapOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ByteSwapOp]:
    ...

class CallIntrinsicOp(multiplier.ir.llvm.Operation):
  args: Iterable[multiplier.ir.Operand]
  results: Iterable[multiplier.ir.Result]
  intrin: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CallIntrinsicOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CallIntrinsicOp]:
    ...

class CopySignOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CopySignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CopySignOp]:
    ...

class CoroAlignOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CoroAlignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CoroAlignOp]:
    ...

class CoroBeginOp(multiplier.ir.llvm.Operation):
  token: multiplier.ir.Value
  mem: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CoroBeginOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CoroBeginOp]:
    ...

class CoroEndOp(multiplier.ir.llvm.Operation):
  handle: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CoroEndOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CoroEndOp]:
    ...

class CoroFreeOp(multiplier.ir.llvm.Operation):
  id: multiplier.ir.Value
  handle: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CoroFreeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CoroFreeOp]:
    ...

class CoroIdOp(multiplier.ir.llvm.Operation):
  promise: multiplier.ir.Value
  coroaddr: multiplier.ir.Value
  fnaddrs: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CoroIdOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CoroIdOp]:
    ...

class CoroResumeOp(multiplier.ir.llvm.Operation):
  handle: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CoroResumeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CoroResumeOp]:
    ...

class CoroSaveOp(multiplier.ir.llvm.Operation):
  handle: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CoroSaveOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CoroSaveOp]:
    ...

class CoroSizeOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CoroSizeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CoroSizeOp]:
    ...

class CoroSuspendOp(multiplier.ir.llvm.Operation):
  save: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CoroSuspendOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CoroSuspendOp]:
    ...

class CosOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CosOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CosOp]:
    ...

class CountLeadingZerosOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value
  is_zero_poison: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CountLeadingZerosOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CountLeadingZerosOp]:
    ...

class CountTrailingZerosOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value
  is_zero_poison: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CountTrailingZerosOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CountTrailingZerosOp]:
    ...

class CtPopOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.CtPopOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.CtPopOp]:
    ...

class DbgDeclareOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.DbgDeclareOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.DbgDeclareOp]:
    ...

class DbgLabelOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.DbgLabelOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.DbgLabelOp]:
    ...

class DbgValueOp(multiplier.ir.llvm.Operation):
  value: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.DbgValueOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.DbgValueOp]:
    ...

class DebugTrapOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.DebugTrapOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.DebugTrapOp]:
    ...

class EhTypeidForOp(multiplier.ir.llvm.Operation):
  type_info: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.EhTypeidForOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.EhTypeidForOp]:
    ...

class Exp2Op(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.Exp2Op]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.Exp2Op]:
    ...

class ExpOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ExpOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ExpOp]:
    ...

class ExpectOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ExpectOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ExpectOp]:
    ...

class ExpectWithProbabilityOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ExpectWithProbabilityOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ExpectWithProbabilityOp]:
    ...

class FAbsOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FAbsOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FAbsOp]:
    ...

class FCeilOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FCeilOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FCeilOp]:
    ...

class FFloorOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FFloorOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FFloorOp]:
    ...

class FMAOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  c: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FMAOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FMAOp]:
    ...

class FMulAddOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  c: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FMulAddOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FMulAddOp]:
    ...

class FTruncOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FTruncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FTruncOp]:
    ...

class FShlOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  c: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FShlOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FShlOp]:
    ...

class FShrOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  c: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FShrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FShrOp]:
    ...

class GetActiveLaneMaskOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.GetActiveLaneMaskOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.GetActiveLaneMaskOp]:
    ...

class IsConstantOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.IsConstantOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.IsConstantOp]:
    ...

class IsFPClassOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value
  bit: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.IsFPClassOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.IsFPClassOp]:
    ...

class LifetimeEndOp(multiplier.ir.llvm.Operation):
  size: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.LifetimeEndOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.LifetimeEndOp]:
    ...

class LifetimeStartOp(multiplier.ir.llvm.Operation):
  size: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.LifetimeStartOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.LifetimeStartOp]:
    ...

class RoundAndCastToLongLongOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.RoundAndCastToLongLongOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.RoundAndCastToLongLongOp]:
    ...

class RoundAndCastToNearestLongLongOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.RoundAndCastToNearestLongLongOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.RoundAndCastToNearestLongLongOp]:
    ...

class Log10Op(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.Log10Op]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.Log10Op]:
    ...

class Log2Op(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.Log2Op]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.Log2Op]:
    ...

class LogOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.LogOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.LogOp]:
    ...

class RoundAndCastToLongOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.RoundAndCastToLongOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.RoundAndCastToLongOp]:
    ...

class RoundAndCastToNearestLongOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.RoundAndCastToNearestLongOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.RoundAndCastToNearestLongOp]:
    ...

class MaskedLoadOp(multiplier.ir.llvm.Operation):
  mask: multiplier.ir.Value
  pass_thru: Iterable[multiplier.ir.Operand]
  res: multiplier.ir.Value
  alignment: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MaskedLoadOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MaskedLoadOp]:
    ...

class MaskedStoreOp(multiplier.ir.llvm.Operation):
  value: multiplier.ir.Value
  mask: multiplier.ir.Value
  alignment: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MaskedStoreOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MaskedStoreOp]:
    ...

class MatrixColumnMajorLoadOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value
  is_volatile: bool
  rows: int
  columns: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MatrixColumnMajorLoadOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MatrixColumnMajorLoadOp]:
    ...

class MatrixColumnMajorStoreOp(multiplier.ir.llvm.Operation):
  matrix: multiplier.ir.Value
  is_volatile: bool
  rows: int
  columns: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MatrixColumnMajorStoreOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MatrixColumnMajorStoreOp]:
    ...

class MatrixMultiplyOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  res: multiplier.ir.Value
  lhs_rows: int
  lhs_columns: int
  rhs_columns: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MatrixMultiplyOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MatrixMultiplyOp]:
    ...

class MatrixTransposeOp(multiplier.ir.llvm.Operation):
  matrix: multiplier.ir.Value
  res: multiplier.ir.Value
  rows: int
  columns: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MatrixTransposeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MatrixTransposeOp]:
    ...

class MaxNumOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MaxNumOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MaxNumOp]:
    ...

class MaximumOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MaximumOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MaximumOp]:
    ...

class MemcpyInlineOp(multiplier.ir.llvm.Operation):
  is_volatile: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MemcpyInlineOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MemcpyInlineOp]:
    ...

class MemcpyOp(multiplier.ir.llvm.Operation):
  is_volatile: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MemcpyOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MemcpyOp]:
    ...

class MemmoveOp(multiplier.ir.llvm.Operation):
  is_volatile: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MemmoveOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MemmoveOp]:
    ...

class MemsetOp(multiplier.ir.llvm.Operation):
  is_volatile: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MemsetOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MemsetOp]:
    ...

class MinNumOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MinNumOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MinNumOp]:
    ...

class MinimumOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MinimumOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MinimumOp]:
    ...

class RoundToNearbyIntOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.RoundToNearbyIntOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.RoundToNearbyIntOp]:
    ...

class NoAliasScopeDeclOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.NoAliasScopeDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.NoAliasScopeDeclOp]:
    ...

class PowIOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.PowIOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.PowIOp]:
    ...

class FPowOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.FPowOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.FPowOp]:
    ...

class PrefetchOp(multiplier.ir.llvm.Operation):
  rw: int
  hint: int
  cache: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.PrefetchOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.PrefetchOp]:
    ...

class PtrAnnotationOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.PtrAnnotationOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.PtrAnnotationOp]:
    ...

class RoundToIntOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.RoundToIntOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.RoundToIntOp]:
    ...

class RoundToNearestEvenOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.RoundToNearestEvenOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.RoundToNearestEvenOp]:
    ...

class RoundToNearestOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.RoundToNearestOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.RoundToNearestOp]:
    ...

class SAddSatOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SAddSatOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SAddSatOp]:
    ...

class SAddWithOverflowOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SAddWithOverflowOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SAddWithOverflowOp]:
    ...

class SMaxOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SMaxOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SMaxOp]:
    ...

class SMinOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SMinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SMinOp]:
    ...

class SMulWithOverflowOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SMulWithOverflowOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SMulWithOverflowOp]:
    ...

class SSACopyOp(multiplier.ir.llvm.Operation):
  operand: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SSACopyOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SSACopyOp]:
    ...

class SShlSatOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SShlSatOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SShlSatOp]:
    ...

class SSubSatOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SSubSatOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SSubSatOp]:
    ...

class SSubWithOverflowOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SSubWithOverflowOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SSubWithOverflowOp]:
    ...

class SinOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SinOp]:
    ...

class SqrtOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.SqrtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.SqrtOp]:
    ...

class StackRestoreOp(multiplier.ir.llvm.Operation):
  ptr: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.StackRestoreOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.StackRestoreOp]:
    ...

class StackSaveOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.StackSaveOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.StackSaveOp]:
    ...

class StepVectorOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.StepVectorOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.StepVectorOp]:
    ...

class ThreadLocalAddressOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.ThreadLocalAddressOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.ThreadLocalAddressOp]:
    ...

class TrapOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.TrapOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.TrapOp]:
    ...

class UAddSatOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UAddSatOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UAddSatOp]:
    ...

class UAddWithOverflowOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UAddWithOverflowOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UAddWithOverflowOp]:
    ...

class UBSanTrapOp(multiplier.ir.llvm.Operation):
  failure_kind: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UBSanTrapOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UBSanTrapOp]:
    ...

class UMaxOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UMaxOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UMaxOp]:
    ...

class UMinOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UMinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UMinOp]:
    ...

class UMulWithOverflowOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UMulWithOverflowOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UMulWithOverflowOp]:
    ...

class UShlSatOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.UShlSatOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.UShlSatOp]:
    ...

class USubSatOp(multiplier.ir.llvm.Operation):
  a: multiplier.ir.Value
  b: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.USubSatOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.USubSatOp]:
    ...

class USubWithOverflowOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.USubWithOverflowOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.USubWithOverflowOp]:
    ...

class VPAShrOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPAShrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPAShrOp]:
    ...

class VPAddOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPAddOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPAddOp]:
    ...

class VPAndOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPAndOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPAndOp]:
    ...

class VPFAddOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFAddOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFAddOp]:
    ...

class VPFDivOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFDivOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFDivOp]:
    ...

class VPFMulAddOp(multiplier.ir.llvm.Operation):
  op1: multiplier.ir.Value
  op2: multiplier.ir.Value
  op3: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFMulAddOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFMulAddOp]:
    ...

class VPFMulOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFMulOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFMulOp]:
    ...

class VPFNegOp(multiplier.ir.llvm.Operation):
  op: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFNegOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFNegOp]:
    ...

class VPFPExtOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFPExtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFPExtOp]:
    ...

class VPFPToSIOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFPToSIOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFPToSIOp]:
    ...

class VPFPToUIOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFPToUIOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFPToUIOp]:
    ...

class VPFPTruncOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFPTruncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFPTruncOp]:
    ...

class VPFRemOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFRemOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFRemOp]:
    ...

class VPFSubOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFSubOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFSubOp]:
    ...

class VPFmaOp(multiplier.ir.llvm.Operation):
  op1: multiplier.ir.Value
  op2: multiplier.ir.Value
  op3: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPFmaOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPFmaOp]:
    ...

class VPIntToPtrOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPIntToPtrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPIntToPtrOp]:
    ...

class VPLShrOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPLShrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPLShrOp]:
    ...

class VPLoadOp(multiplier.ir.llvm.Operation):
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPLoadOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPLoadOp]:
    ...

class VPMergeMinOp(multiplier.ir.llvm.Operation):
  cond: multiplier.ir.Value
  true_val: multiplier.ir.Value
  false_val: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPMergeMinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPMergeMinOp]:
    ...

class VPMulOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPMulOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPMulOp]:
    ...

class VPOrOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPOrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPOrOp]:
    ...

class VPPtrToIntOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPPtrToIntOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPPtrToIntOp]:
    ...

class VPReduceAddOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceAddOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceAddOp]:
    ...

class VPReduceAndOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceAndOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceAndOp]:
    ...

class VPReduceFAddOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceFAddOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceFAddOp]:
    ...

class VPReduceFMaxOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceFMaxOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceFMaxOp]:
    ...

class VPReduceFMinOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceFMinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceFMinOp]:
    ...

class VPReduceFMulOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceFMulOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceFMulOp]:
    ...

class VPReduceMulOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceMulOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceMulOp]:
    ...

class VPReduceOrOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceOrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceOrOp]:
    ...

class VPReduceSMaxOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceSMaxOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceSMaxOp]:
    ...

class VPReduceSMinOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceSMinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceSMinOp]:
    ...

class VPReduceUMaxOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceUMaxOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceUMaxOp]:
    ...

class VPReduceUMinOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceUMinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceUMinOp]:
    ...

class VPReduceXorOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPReduceXorOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPReduceXorOp]:
    ...

class VPSDivOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPSDivOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPSDivOp]:
    ...

class VPSExtOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPSExtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPSExtOp]:
    ...

class VPSIToFPOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPSIToFPOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPSIToFPOp]:
    ...

class VPSRemOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPSRemOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPSRemOp]:
    ...

class VPSelectMinOp(multiplier.ir.llvm.Operation):
  cond: multiplier.ir.Value
  true_val: multiplier.ir.Value
  false_val: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPSelectMinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPSelectMinOp]:
    ...

class VPShlOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPShlOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPShlOp]:
    ...

class VPStoreOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPStoreOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPStoreOp]:
    ...

class VPStridedLoadOp(multiplier.ir.llvm.Operation):
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPStridedLoadOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPStridedLoadOp]:
    ...

class VPStridedStoreOp(multiplier.ir.llvm.Operation):
  val: multiplier.ir.Value
  mask: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPStridedStoreOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPStridedStoreOp]:
    ...

class VPSubOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPSubOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPSubOp]:
    ...

class VPTruncOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPTruncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPTruncOp]:
    ...

class VPUDivOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPUDivOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPUDivOp]:
    ...

class VPUIToFPOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPUIToFPOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPUIToFPOp]:
    ...

class VPURemOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPURemOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPURemOp]:
    ...

class VPXorOp(multiplier.ir.llvm.Operation):
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPXorOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPXorOp]:
    ...

class VPZExtOp(multiplier.ir.llvm.Operation):
  src: multiplier.ir.Value
  mask: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VPZExtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VPZExtOp]:
    ...

class VaCopyOp(multiplier.ir.llvm.Operation):
  dest_list: multiplier.ir.Value
  src_list: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VaCopyOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VaCopyOp]:
    ...

class VaEndOp(multiplier.ir.llvm.Operation):
  arg_list: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VaEndOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VaEndOp]:
    ...

class VaStartOp(multiplier.ir.llvm.Operation):
  arg_list: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VaStartOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VaStartOp]:
    ...

class VarAnnotationOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VarAnnotationOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VarAnnotationOp]:
    ...

class MaskedCompressStoreOp(multiplier.ir.llvm.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MaskedCompressStoreOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MaskedCompressStoreOp]:
    ...

class MaskedExpandLoadOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MaskedExpandLoadOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MaskedExpandLoadOp]:
    ...

class MaskedGatherOp(multiplier.ir.llvm.Operation):
  ptrs: multiplier.ir.Value
  mask: multiplier.ir.Value
  pass_thru: Iterable[multiplier.ir.Operand]
  res: multiplier.ir.Value
  alignment: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MaskedGatherOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MaskedGatherOp]:
    ...

class MaskedScatterOp(multiplier.ir.llvm.Operation):
  value: multiplier.ir.Value
  ptrs: multiplier.ir.Value
  mask: multiplier.ir.Value
  alignment: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.MaskedScatterOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.MaskedScatterOp]:
    ...

class VectorExtractOp(multiplier.ir.llvm.Operation):
  srcvec: multiplier.ir.Value
  res: multiplier.ir.Value
  pos: int
  src_vector_bit_width: int
  res_vector_bit_width: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorExtractOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorExtractOp]:
    ...

class VectorInsertOp(multiplier.ir.llvm.Operation):
  srcvec: multiplier.ir.Value
  dstvec: multiplier.ir.Value
  res: multiplier.ir.Value
  pos: int
  src_vector_bit_width: int
  dst_vector_bit_width: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorInsertOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorInsertOp]:
    ...

class VectorReduceAddOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceAddOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceAddOp]:
    ...

class VectorReduceAndOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceAndOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceAndOp]:
    ...

class VectorReduceFAddOp(multiplier.ir.llvm.Operation):
  input: multiplier.ir.Value
  res: multiplier.ir.Value
  reassoc: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceFAddOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceFAddOp]:
    ...

class VectorReduceFMaxOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceFMaxOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceFMaxOp]:
    ...

class VectorReduceFMaximumOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceFMaximumOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceFMaximumOp]:
    ...

class VectorReduceFMinOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceFMinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceFMinOp]:
    ...

class VectorReduceFMinimumOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceFMinimumOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceFMinimumOp]:
    ...

class VectorReduceFMulOp(multiplier.ir.llvm.Operation):
  input: multiplier.ir.Value
  res: multiplier.ir.Value
  reassoc: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceFMulOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceFMulOp]:
    ...

class VectorReduceMulOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceMulOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceMulOp]:
    ...

class VectorReduceOrOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceOrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceOrOp]:
    ...

class VectorReduceSMaxOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceSMaxOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceSMaxOp]:
    ...

class VectorReduceSMinOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceSMinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceSMinOp]:
    ...

class VectorReduceUMaxOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceUMaxOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceUMaxOp]:
    ...

class VectorReduceUMinOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceUMinOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceUMinOp]:
    ...

class VectorReduceXorOp(multiplier.ir.llvm.Operation):
  IN: multiplier.ir.Value
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VectorReduceXorOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VectorReduceXorOp]:
    ...

class VScaleOp(multiplier.ir.llvm.Operation):
  res: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.llvm.VScaleOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.llvm.VScaleOp]:
    ...

class Type(multiplier.ir.Type):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Type) -> Optional[multiplier.ir.llvm.Type]:
    ...

class ArrayType(multiplier.ir.llvm.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.llvm.ArrayType]:
    ...

class FixedVectorType(multiplier.ir.llvm.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.llvm.FixedVectorType]:
    ...

class FunctionType(multiplier.ir.llvm.Type):
  is_var_arg: bool
  var_arg: bool

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.llvm.FunctionType]:
    ...

class PointerType(multiplier.ir.llvm.Type):
  is_opaque: bool

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.llvm.PointerType]:
    ...

class ScalableVectorType(multiplier.ir.llvm.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.llvm.ScalableVectorType]:
    ...

class TargetExtType(multiplier.ir.llvm.Type):
  supports_mem_ops: bool
  ext_type_name: str

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.llvm.TargetExtType]:
    ...
