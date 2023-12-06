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

class Attribute(multiplier.ir.Attribute):

  @staticmethod
  def FROM(arg_0: 'multiplier.ir.Attribute') -> Optional['multiplier.ir.meta.Attribute']:
    ...

class IdentifierAttr(multiplier.ir.meta.Attribute):

  @staticmethod
  def static_kind() -> 'multiplier.ir.AttributeKind':
    ...

  @staticmethod
  def FROM(that: 'multiplier.ir.Attribute') -> Optional['multiplier.ir.meta.IdentifierAttr']:
    ...
