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
  def FROM(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.Operation]:
    ...

class BrOp(multiplier.ir.lowlevel.Operation):
  operands: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.BrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.BrOp]:
    ...

class ConcatOp(multiplier.ir.lowlevel.Operation):
  args: Iterable[multiplier.ir.Operand]
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.ConcatOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.ConcatOp]:
    ...

class CondBrOp(multiplier.ir.lowlevel.Operation):
  cond: multiplier.ir.Value
  true_operands: Iterable[multiplier.ir.Operand]
  false_operands: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.CondBrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.CondBrOp]:
    ...

class CondScopeRetOp(multiplier.ir.lowlevel.Operation):
  cond: multiplier.ir.Value
  dest_operands: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.CondScopeRetOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.CondScopeRetOp]:
    ...

class ExtractOp(multiplier.ir.lowlevel.Operation):
  arg: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.ExtractOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.ExtractOp]:
    ...

class InitializeVarOp(multiplier.ir.lowlevel.Operation):
  var: multiplier.ir.Value
  elements: Iterable[multiplier.ir.Operand]
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.InitializeVarOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.InitializeVarOp]:
    ...

class InlineScopeOp(multiplier.ir.lowlevel.Operation):
  body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.InlineScopeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.InlineScopeOp]:
    ...

class FuncOp(multiplier.ir.lowlevel.Operation):
  body: multiplier.ir.Region
  sym_name: str
  sym_visibility: Optional[str]
  is_var_arg: bool
  is_declaration: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.FuncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.FuncOp]:
    ...

class StructGEPOp(multiplier.ir.lowlevel.Operation):
  record: multiplier.ir.Value
  element: multiplier.ir.Value
  idx: int
  name: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.StructGEPOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.StructGEPOp]:
    ...

class ReturnOp(multiplier.ir.lowlevel.Operation):
  result: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.ReturnOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.ReturnOp]:
    ...

class ScopeOp(multiplier.ir.lowlevel.Operation):
  body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.ScopeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.ScopeOp]:
    ...

class ScopeRecurseOp(multiplier.ir.lowlevel.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.ScopeRecurseOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.ScopeRecurseOp]:
    ...

class ScopeRetOp(multiplier.ir.lowlevel.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.ScopeRetOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.ScopeRetOp]:
    ...

class UninitializedVarOp(multiplier.ir.lowlevel.Operation):
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.lowlevel.UninitializedVarOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.lowlevel.UninitializedVarOp]:
    ...
