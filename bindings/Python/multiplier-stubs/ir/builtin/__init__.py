#
# Copyright (c) 2023-present, Trail of Bits, Inc.
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
  def FROM(arg_0: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.Attribute]:
    ...

class TypedAttr(multiplier.ir.builtin.Attribute):
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.TypedAttr]:
    ...

class ElementsAttr(multiplier.ir.builtin.Attribute):
  is_splat: bool
  num_elements: int
  size: int
  empty: bool
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.ElementsAttr]:
    ...

class AffineMapAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.AffineMapAttr]:
    ...

class ArrayAttr(multiplier.ir.builtin.Attribute):
  size: int
  empty: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.ArrayAttr]:
    ...

class DenseArrayAttr(multiplier.ir.builtin.Attribute):
  size: int
  empty: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.DenseArrayAttr]:
    ...

class DenseIntOrFPElementsAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.DenseIntOrFPElementsAttr]:
    ...

class DenseStringElementsAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.DenseStringElementsAttr]:
    ...

class DenseResourceElementsAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.DenseResourceElementsAttr]:
    ...

class DictionaryAttr(multiplier.ir.builtin.Attribute):
  empty: bool
  size: int

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.DictionaryAttr]:
    ...

class FloatAttr(multiplier.ir.builtin.Attribute):
  value_as_double: float
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.FloatAttr]:
    ...

class IntegerAttr(multiplier.ir.builtin.Attribute):
  int_: int
  s_int: int
  u_int: int
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.IntegerAttr]:
    ...

class IntegerSetAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.IntegerSetAttr]:
    ...

class OpaqueAttr(multiplier.ir.builtin.Attribute):
  attr_data: str
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.OpaqueAttr]:
    ...

class SparseElementsAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.SparseElementsAttr]:
    ...

class StridedLayoutAttr(multiplier.ir.builtin.Attribute):
  offset: int

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.StridedLayoutAttr]:
    ...

class StringAttr(multiplier.ir.builtin.Attribute):
  str: str
  size: int
  empty: bool
  value: str
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.StringAttr]:
    ...

class SymbolRefAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.SymbolRefAttr]:
    ...

class TypeAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.TypeAttr]:
    ...

class UnitAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.UnitAttr]:
    ...

class BoolAttr(multiplier.ir.builtin.Attribute):
  value: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.BoolAttr]:
    ...

class FlatSymbolRefAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.FlatSymbolRefAttr]:
    ...

class DenseIntElementsAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.DenseIntElementsAttr]:
    ...

class DataLayoutSpecAttr(multiplier.ir.builtin.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.builtin.DataLayoutSpecAttr]:
    ...

class Operation(multiplier.ir.Operation):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.builtin.Operation]:
    ...

class ModuleOp(multiplier.ir.builtin.Operation):
  body_region: multiplier.ir.Region
  sym_name: Optional[str]
  sym_visibility: Optional[str]
  name: Optional[str]
  is_optional_symbol: bool
  default_dialect: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.builtin.ModuleOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.builtin.ModuleOp]:
    ...

class UnrealizedConversionCastOp(multiplier.ir.builtin.Operation):
  inputs: Iterable[multiplier.ir.Operand]
  outputs: Iterable[multiplier.ir.Result]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.builtin.UnrealizedConversionCastOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.builtin.UnrealizedConversionCastOp]:
    ...

class Type(multiplier.ir.Type):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Type]:
    ...

class ShapedType(multiplier.ir.builtin.Type):
  element_type: multiplier.ir.Type
  has_rank: bool
  element_type_bit_width: int
  rank: int
  num_elements: int
  has_static_shape: bool
  num_dynamic_dims: int

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.ShapedType]:
    ...

class FloatType(multiplier.ir.builtin.Type):
  width: int
  fp_mantissa_width: int

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.FloatType]:
    ...

class ComplexType(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.ComplexType]:
    ...

class Float8E5M2Type(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Float8E5M2Type]:
    ...

class Float8E4M3FNType(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Float8E4M3FNType]:
    ...

class Float8E5M2FNUZType(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Float8E5M2FNUZType]:
    ...

class Float8E4M3FNUZType(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Float8E4M3FNUZType]:
    ...

class Float8E4M3B11FNUZType(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Float8E4M3B11FNUZType]:
    ...

class BFloat16Type(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.BFloat16Type]:
    ...

class Float16Type(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Float16Type]:
    ...

class FloatTF32Type(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.FloatTF32Type]:
    ...

class Float32Type(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Float32Type]:
    ...

class Float64Type(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Float64Type]:
    ...

class Float80Type(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Float80Type]:
    ...

class Float128Type(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.Float128Type]:
    ...

class FunctionType(multiplier.ir.builtin.Type):
  num_inputs: int
  num_results: int

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.FunctionType]:
    ...

class IndexType(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.IndexType]:
    ...

class IntegerType(multiplier.ir.builtin.Type):
  is_signless: bool
  is_signed: bool
  is_unsigned: bool
  width: int

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.IntegerType]:
    ...

class MemRefType(multiplier.ir.builtin.Type):
  memory_space_as_int: int

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.MemRefType]:
    ...

class NoneType(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.NoneType]:
    ...

class OpaqueType(multiplier.ir.builtin.Type):
  type_data: str

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.OpaqueType]:
    ...

class RankedTensorType(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.RankedTensorType]:
    ...

class TupleType(multiplier.ir.builtin.Type):
  size: int

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.TupleType]:
    ...

class UnrankedMemRefType(multiplier.ir.builtin.Type):
  memory_space_as_int: int

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.UnrankedMemRefType]:
    ...

class UnrankedTensorType(multiplier.ir.builtin.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.UnrankedTensorType]:
    ...

class VectorType(multiplier.ir.builtin.Type):
  is_scalable: bool
  all_dims_scalable: bool
  has_rank: bool

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.builtin.VectorType]:
    ...
