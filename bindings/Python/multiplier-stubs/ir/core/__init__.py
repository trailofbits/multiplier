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
  def FROM(arg_0: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.Attribute]:
    ...

class BooleanAttr(multiplier.ir.core.Attribute):
  value: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.BooleanAttr]:
    ...

class IntegerAttr(multiplier.ir.core.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.IntegerAttr]:
    ...

class FloatAttr(multiplier.ir.core.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.core.FloatAttr]:
    ...

class VoidAttr(multiplier.ir.core.Attribute):

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
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
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
  lhs: multiplier.ir.Value
  rhs: multiplier.ir.Value
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

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.core.LazyOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.core.LazyOp]:
    ...

class ScopeOp(multiplier.ir.core.Operation):

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
  var_arg: bool

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.core.FunctionType]:
    ...
