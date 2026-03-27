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
import multiplier.frontend

class OpCode(IntEnum):
  BLOCK_ARG_DEF = 0
  CONST_INT = 1
  CONST_FLOAT = 2
  CONST_NULL = 3
  ALLOCA = 4
  LOAD = 5
  STORE = 6
  ADDRESS_OF = 7
  GEP_FIELD = 8
  GEP_INDEX = 9
  PTR_ADD = 10
  ADD = 11
  SUB = 12
  MUL = 13
  DIV = 14
  REM = 15
  BIT_AND = 16
  BIT_OR = 17
  BIT_XOR = 18
  SHL = 19
  SHR = 20
  LOGICAL_AND = 21
  LOGICAL_OR = 22
  PTR_DIFF = 23
  CMP_EQ = 24
  CMP_NE = 25
  CMP_LT = 26
  CMP_LE = 27
  CMP_GT = 28
  CMP_GE = 29
  NEG = 30
  BIT_NOT = 31
  LOGICAL_NOT = 32
  CAST_SEXT = 33
  CAST_ZEXT = 34
  CAST_TRUNC = 35
  CAST_BITCAST = 36
  CAST_PTR_TO_INT = 37
  CAST_INT_TO_PTR = 38
  CAST_FP_TO_SI = 39
  CAST_SI_TO_FP = 40
  CAST_FP_TRUNC = 41
  CAST_FP_EXT = 42
  CAST_INT_CAST = 43
  CAST_FP_CAST = 44
  SIZE_OF = 45
  CALL = 46
  INC_DEC = 47
  COMPOUND_ASSIGN = 48
  SELECT = 49
  COPY = 50
  COND_BRANCH = 51
  SWITCH = 52
  RET = 53
  UNREACHABLE = 54
  BREAK = 55
  CONTINUE = 56
  GOTO = 57
  IMPLICIT_GOTO = 58
  FALLTHROUGH = 59
  IMPLICIT_FALLTHROUGH = 60
  VA_PACK = 61
  VA_START = 62
  VA_ARG = 63
  VA_COPY = 64
  VA_END = 65
  UNKNOWN = 66

class ObjectKind(IntEnum):
  LOCAL = 0
  LOCAL_VALUE = 1
  PARAMETER = 2
  PARAMETER_VALUE = 3
  GLOBAL = 4
  THREAD_LOCAL = 5
  STRING_LITERAL = 6
  COMPOUND_LITERAL = 7
  RETURN_SLOT = 8
  ALLOCA = 9
  HEAP = 10

class BlockKind(IntEnum):
  ENTRY = 0
  IF_THEN = 1
  IF_ELSE = 2
  IF_MERGE = 3
  LOOP_CONDITION = 4
  LOOP_BODY = 5
  LOOP_EXIT = 6
  LOOP_INCREMENT = 7
  SWITCH_CASE = 8
  SWITCH_DEFAULT = 9
  SWITCH_EXIT = 10
  LABEL = 11
  UNREACHABLE = 12
  GENERIC = 13

class IRFunction(multiplier.Entity):
  pass

class IRBlock(multiplier.Entity):
  pass

class IRInstruction(multiplier.Entity):
  pass

class IRObject(multiplier.Entity):
  pass
