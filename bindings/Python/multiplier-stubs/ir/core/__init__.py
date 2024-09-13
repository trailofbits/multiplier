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
  def FROM(arg_0: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.Attribute]:
    ...

class BooleanAttr(multiplier.ir.core.Attribute):
  type: multiplier.ir.Type
  value: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.BooleanAttr]:
    ...

class IntegerAttr(multiplier.ir.core.Attribute):
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.IntegerAttr]:
    ...

class FloatAttr(multiplier.ir.core.Attribute):
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.FloatAttr]:
    ...

class VoidAttr(multiplier.ir.core.Attribute):
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.VoidAttr]:
    ...

class SourceLanguageAttr(multiplier.ir.core.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.SourceLanguageAttr]:
    ...

class GlobalLinkageKindAttr(multiplier.ir.core.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.GlobalLinkageKindAttr]:
    ...

class Operation(multiplier.ir.Operation):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.core.Operation]:
    ...

class BinLAndOp(multiplier.ir.core.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.core.BinLAndOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.core.BinLAndOp]:
    ...

class BinLOrOp(multiplier.ir.core.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.core.BinLOrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.core.BinLOrOp]:
    ...

class ImplicitReturnOp(multiplier.ir.core.Operation):
  result: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.core.ImplicitReturnOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.core.ImplicitReturnOp]:
    ...

class LazyOp(multiplier.ir.core.Operation):
  result: multiplier.ir.Value
  lazy: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.core.LazyOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.core.LazyOp]:
    ...

class ModuleOp(multiplier.ir.core.Operation):
  body: multiplier.ir.Region
  name: Optional[str]
  is_optional_symbol: bool
  default_dialect: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.core.ModuleOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.core.ModuleOp]:
    ...

class ScopeOp(multiplier.ir.core.Operation):
  body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.core.ScopeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.core.ScopeOp]:
    ...

class SelectOp(multiplier.ir.core.Operation):
  cond: multiplier.ir.Value
  then_region: multiplier.ir.Value
  else_region: multiplier.ir.Value
  results: Iterable[multiplier.ir.Result]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.core.SelectOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.core.SelectOp]:
    ...

class Type(multiplier.ir.Type):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Type) -> Optional[multiplier.ir.core.Type]:
    ...

class FunctionType(multiplier.ir.core.Type):
  is_var_arg: bool
  num_inputs: int
  num_results: int
  inputs: Iterable[multiplier.ir.Type]
  results: Iterable[multiplier.ir.Type]
  var_arg: bool

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.core.FunctionType]:
    ...
