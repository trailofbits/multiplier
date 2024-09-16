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

class Operation(multiplier.ir.Operation):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.Operation]:
    ...

class CallArgsOp(multiplier.ir.abi.Operation):
  results: Iterable[multiplier.ir.Result]
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
  arguments: Iterable[multiplier.ir.Operand]
  result: multiplier.ir.Value
  body: multiplier.ir.Region
  arg_operands: Iterable[multiplier.ir.Operand]

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
  arguments: Iterable[multiplier.ir.Operand]
  results: Iterable[multiplier.ir.Result]
  callee: str
  arg_operands: Iterable[multiplier.ir.Operand]

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
  results: Iterable[multiplier.ir.Result]
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
  value: Iterable[multiplier.ir.Operand]
  result: Iterable[multiplier.ir.Result]

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
  results: Iterable[multiplier.ir.Result]
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
  body: Optional[multiplier.ir.Region]
  name: str
  function_type: multiplier.ir.Type
  visibility: Optional[str]
  is_var_arg: bool
  callable_results: Iterable[multiplier.ir.Type]
  argument_types: Iterable[multiplier.ir.Type]
  result_types: Iterable[multiplier.ir.Type]
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

class IndirectOp(multiplier.ir.abi.Operation):
  value: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.IndirectOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.IndirectOp]:
    ...

class PrologueOp(multiplier.ir.abi.Operation):
  results: Iterable[multiplier.ir.Result]
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
  result: Iterable[multiplier.ir.Result]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.RetDirectOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.RetDirectOp]:
    ...

class YieldOp(multiplier.ir.abi.Operation):
  values: Iterable[multiplier.ir.Operand]
  result: Iterable[multiplier.ir.Result]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.abi.YieldOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.abi.YieldOp]:
    ...
