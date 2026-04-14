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
  CONST = 0
  ALLOCA = 1
  MEMORY = 2
  GEP_FIELD = 3
  PTR_ADD = 4
  ADD = 5
  SUB = 6
  MUL = 7
  DIV = 8
  REM = 9
  BIT_AND = 10
  BIT_OR = 11
  BIT_XOR = 12
  SHL = 13
  SHR = 14
  LOGICAL_AND = 15
  LOGICAL_OR = 16
  PTR_DIFF = 17
  CMP_EQ = 18
  CMP_NE = 19
  CMP_LT = 20
  CMP_LE = 21
  CMP_GT = 22
  CMP_GE = 23
  NEG = 24
  BIT_NOT = 25
  LOGICAL_NOT = 26
  CAST = 27
  CALL = 28
  READ_MODIFY_WRITE = 29
  SELECT = 30
  COND_BRANCH = 31
  SWITCH = 32
  RET = 33
  UNREACHABLE = 34
  BREAK = 35
  CONTINUE = 36
  GOTO = 37
  IMPLICIT_GOTO = 38
  FALLTHROUGH = 39
  IMPLICIT_FALLTHROUGH = 40
  IMPLICIT_UNREACHABLE = 41
  VA_PACK = 42
  VA_START = 43
  VA_ARG = 44
  VA_COPY = 45
  VA_END = 46
  ENTER_SCOPE = 47
  EXIT_SCOPE = 48
  PARAM_READ = 49
  GLOBAL_PTR = 50
  THREAD_LOCAL_PTR = 51
  FUNC_PTR = 52
  BITWISE = 53
  FLOAT = 54
  UNDEFINED = 55
  DYNAMIC_ALLOCA = 56
  FRAME_PTR = 57
  RETURN_PTR = 58
  ADD_OVERFLOW = 59
  SUB_OVERFLOW = 60
  MUL_OVERFLOW = 61
  ATOMIC_ADD = 62
  ATOMIC_SUB = 63
  ATOMIC_AND = 64
  ATOMIC_OR = 65
  ATOMIC_XOR = 66
  ATOMIC_NAND = 67
  ATOMIC_EXCHANGE = 68
  LAST_VALUE = 69
  UNKNOWN = 70

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
