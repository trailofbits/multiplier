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

class Operation(multiplier.ir.Operation):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.Operation]:
    ...

class AssumeAlignmentOp(multiplier.ir.memref.Operation):
  alignment: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.AssumeAlignmentOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.AssumeAlignmentOp]:
    ...

class AtomicRMWOp(multiplier.ir.memref.Operation):
  value: multiplier.ir.Value
  indices: Iterable[multiplier.ir.Operand]
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.AtomicRMWOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.AtomicRMWOp]:
    ...

class AtomicYieldOp(multiplier.ir.memref.Operation):
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.AtomicYieldOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.AtomicYieldOp]:
    ...

class CopyOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.CopyOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.CopyOp]:
    ...

class GenericAtomicRMWOp(multiplier.ir.memref.Operation):
  indices: Iterable[multiplier.ir.Operand]
  result: multiplier.ir.Value
  atomic_body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.GenericAtomicRMWOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.GenericAtomicRMWOp]:
    ...

class LoadOp(multiplier.ir.memref.Operation):
  indices: Iterable[multiplier.ir.Operand]
  result: multiplier.ir.Value
  nontemporal: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.LoadOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.LoadOp]:
    ...

class AllocOp(multiplier.ir.memref.Operation):
  dynamic_sizes: Iterable[multiplier.ir.Operand]
  symbol_operands: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.AllocOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.AllocOp]:
    ...

class AllocaOp(multiplier.ir.memref.Operation):
  dynamic_sizes: Iterable[multiplier.ir.Operand]
  symbol_operands: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.AllocaOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.AllocaOp]:
    ...

class AllocaScopeOp(multiplier.ir.memref.Operation):
  results: Iterable[multiplier.ir.Result]
  body_region: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.AllocaScopeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.AllocaScopeOp]:
    ...

class AllocaScopeReturnOp(multiplier.ir.memref.Operation):
  results: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.AllocaScopeReturnOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.AllocaScopeReturnOp]:
    ...

class CastOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.CastOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.CastOp]:
    ...

class CollapseShapeOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.CollapseShapeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.CollapseShapeOp]:
    ...

class DeallocOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.DeallocOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.DeallocOp]:
    ...

class DimOp(multiplier.ir.memref.Operation):
  source: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.DimOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.DimOp]:
    ...

class DMAStartOp(multiplier.ir.memref.Operation):
  operands: Iterable[multiplier.ir.Operand]
  is_dest_memory_space_faster: bool
  is_src_memory_space_faster: bool
  is_strided: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.DMAStartOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.DMAStartOp]:
    ...

class DMAWaitOp(multiplier.ir.memref.Operation):
  tag_indices: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.DMAWaitOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.DMAWaitOp]:
    ...

class ExpandShapeOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.ExpandShapeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.ExpandShapeOp]:
    ...

class ExtractAlignedPointerAsIndexOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.ExtractAlignedPointerAsIndexOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.ExtractAlignedPointerAsIndexOp]:
    ...

class ExtractStridedMetadataOp(multiplier.ir.memref.Operation):
  base_buffer: multiplier.ir.Value
  sizes: Iterable[multiplier.ir.Result]
  strides: Iterable[multiplier.ir.Result]
  view_source: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.ExtractStridedMetadataOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.ExtractStridedMetadataOp]:
    ...

class GetGlobalOp(multiplier.ir.memref.Operation):
  name: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.GetGlobalOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.GetGlobalOp]:
    ...

class GlobalOp(multiplier.ir.memref.Operation):
  sym_name: str
  sym_visibility: Optional[str]
  constant: bool
  is_external: bool
  is_uninitialized: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.GlobalOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.GlobalOp]:
    ...

class MemorySpaceCastOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.MemorySpaceCastOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.MemorySpaceCastOp]:
    ...

class PrefetchOp(multiplier.ir.memref.Operation):
  indices: Iterable[multiplier.ir.Operand]
  is_write: bool
  locality_hint: int
  is_data_cache: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.PrefetchOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.PrefetchOp]:
    ...

class RankOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.RankOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.RankOp]:
    ...

class ReallocOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.ReallocOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.ReallocOp]:
    ...

class ReinterpretCastOp(multiplier.ir.memref.Operation):
  offsets: Iterable[multiplier.ir.Operand]
  sizes: Iterable[multiplier.ir.Operand]
  strides: Iterable[multiplier.ir.Operand]
  dynamic_sizes: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.ReinterpretCastOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.ReinterpretCastOp]:
    ...

class ReshapeOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.ReshapeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.ReshapeOp]:
    ...

class StoreOp(multiplier.ir.memref.Operation):
  value: multiplier.ir.Value
  indices: Iterable[multiplier.ir.Operand]
  nontemporal: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.StoreOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.StoreOp]:
    ...

class TransposeOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.TransposeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.TransposeOp]:
    ...

class ViewOp(multiplier.ir.memref.Operation):
  sizes: Iterable[multiplier.ir.Operand]
  view_source: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.ViewOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.ViewOp]:
    ...

class SubViewOp(multiplier.ir.memref.Operation):
  offsets: Iterable[multiplier.ir.Operand]
  sizes: Iterable[multiplier.ir.Operand]
  strides: Iterable[multiplier.ir.Operand]
  view_source: multiplier.ir.Value
  dynamic_sizes: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.SubViewOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.SubViewOp]:
    ...

class TensorStoreOp(multiplier.ir.memref.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.memref.TensorStoreOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.memref.TensorStoreOp]:
    ...
