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
  def FROM(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.Operation]:
    ...

class CallArgsOp(multiplier.ir.abi.Operation):
  results: Generator[multiplier.ir.Result]
  body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.CallArgsOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.CallArgsOp]:
    ...

class CallExecutionOp(multiplier.ir.abi.Operation):
  args: Generator[multiplier.ir.Operand]
  result: multiplier.ir.Value
  body: multiplier.ir.Region
  callee: str
  arg_operands: Generator[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.CallExecutionOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.CallExecutionOp]:
    ...

class CallOp(multiplier.ir.abi.Operation):
  args: Generator[multiplier.ir.Operand]
  results: Generator[multiplier.ir.Result]
  callee: str
  arg_operands: Generator[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.CallOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.CallOp]:
    ...

class CallRetsOp(multiplier.ir.abi.Operation):
  results: Generator[multiplier.ir.Result]
  body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.CallRetsOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.CallRetsOp]:
    ...

class DirectOp(multiplier.ir.abi.Operation):
  value: Generator[multiplier.ir.Operand]
  result: Generator[multiplier.ir.Result]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.DirectOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.DirectOp]:
    ...

class EpilogueOp(multiplier.ir.abi.Operation):
  results: Generator[multiplier.ir.Result]
  body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.EpilogueOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.EpilogueOp]:
    ...

class FuncOp(multiplier.ir.abi.Operation):
  body: multiplier.ir.Region
  sym_name: str
  sym_visibility: Optional[str]
  is_var_arg: bool
  is_declaration: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.FuncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.FuncOp]:
    ...

class PrologueOp(multiplier.ir.abi.Operation):
  results: Generator[multiplier.ir.Result]
  body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.PrologueOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.PrologueOp]:
    ...

class RetDirectOp(multiplier.ir.abi.Operation):
  value: multiplier.ir.Value
  result: Generator[multiplier.ir.Result]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.RetDirectOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.RetDirectOp]:
    ...

class TodoOp(multiplier.ir.abi.Operation):
  value: multiplier.ir.Value
  result: Generator[multiplier.ir.Result]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.TodoOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.TodoOp]:
    ...

class WrapFuncOp(multiplier.ir.abi.Operation):
  body: multiplier.ir.Region
  sym_name: str
  sym_visibility: Optional[str]
  is_var_arg: bool
  is_declaration: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.WrapFuncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.WrapFuncOp]:
    ...

class YieldOp(multiplier.ir.abi.Operation):
  values: Generator[multiplier.ir.Operand]
  result: Generator[multiplier.ir.Result]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.YieldOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.YieldOp]:
    ...
