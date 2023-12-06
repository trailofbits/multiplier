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

class Operation(multiplier.ir.Operation):

  @staticmethod
  def FROM(arg_0: 'multiplier.ir.Operation') -> Optional['multiplier.ir.unsupported.Operation']:
    ...

class UnsupportedDeclOp(multiplier.ir.unsupported.Operation):
  body: 'multiplier.ir.Region'
  name: str

  @staticmethod
  def static_kind() -> 'multiplier.ir.OperationKind':
    ...

  @staticmethod
  def FROM(that: 'multiplier.ir.Operation') -> Optional['multiplier.ir.unsupported.UnsupportedDeclOp']:
    ...

  @staticmethod
  def producing(val: 'multiplier.ir.Value') -> Optional['multiplier.ir.unsupported.UnsupportedDeclOp']:
    ...

class UnsupportedStmtOp(multiplier.ir.unsupported.Operation):
  result: 'multiplier.ir.Value'
  name: str

  @staticmethod
  def static_kind() -> 'multiplier.ir.OperationKind':
    ...

  @staticmethod
  def FROM(that: 'multiplier.ir.Operation') -> Optional['multiplier.ir.unsupported.UnsupportedStmtOp']:
    ...

  @staticmethod
  def producing(val: 'multiplier.ir.Value') -> Optional['multiplier.ir.unsupported.UnsupportedStmtOp']:
    ...

class Type(multiplier.ir.Type):

  @staticmethod
  def FROM(arg_0: 'multiplier.ir.Type') -> Optional['multiplier.ir.unsupported.Type']:
    ...

class UnsupportedType(multiplier.ir.unsupported.Type):
  origin_name: str

  @staticmethod
  def static_kind() -> 'multiplier.ir.TypeKind':
    ...

  @staticmethod
  def FROM(that: 'multiplier.ir.Type') -> Optional['multiplier.ir.unsupported.UnsupportedType']:
    ...
