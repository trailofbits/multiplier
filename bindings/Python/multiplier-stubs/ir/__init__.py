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
  LOAD = 2
  STORE = 3
  GEP_FIELD = 4
  PTR_ADD = 5
  ADD = 6
  SUB = 7
  MUL = 8
  DIV = 9
  REM = 10
  BIT_AND = 11
  BIT_OR = 12
  BIT_XOR = 13
  SHL = 14
  SHR = 15
  LOGICAL_AND = 16
  LOGICAL_OR = 17
  PTR_DIFF = 18
  CMP_EQ = 19
  CMP_NE = 20
  CMP_LT = 21
  CMP_LE = 22
  CMP_GT = 23
  CMP_GE = 24
  NEG = 25
  BIT_NOT = 26
  LOGICAL_NOT = 27
  CAST = 28
  CALL = 29
  READ_MODIFY_WRITE = 30
  SELECT = 31
  COND_BRANCH = 32
  SWITCH = 33
  RET = 34
  UNREACHABLE = 35
  BREAK = 36
  CONTINUE = 37
  GOTO = 38
  IMPLICIT_GOTO = 39
  FALLTHROUGH = 40
  IMPLICIT_FALLTHROUGH = 41
  IMPLICIT_UNREACHABLE = 42
  VA_PACK = 43
  VA_START = 44
  VA_ARG = 45
  VA_COPY = 46
  VA_END = 47
  ENTER_SCOPE = 48
  EXIT_SCOPE = 49
  MULTIMEM = 50
  PARAM_READ = 51
  GLOBAL_PTR = 52
  FUNC_PTR = 53
  BITWISE = 54
  FLOAT = 55
  UNDEFINED = 56
  DYNAMIC_ALLOCA = 57
  FRAME_PTR = 58
  RETURN_PTR = 59
  ATOMIC_LOAD = 60
  ATOMIC_STORE = 61
  ATOMIC_CMPXCHG = 62
  ADD_OVERFLOW = 63
  SUB_OVERFLOW = 64
  MUL_OVERFLOW = 65
  ATOMIC_ADD = 66
  ATOMIC_SUB = 67
  ATOMIC_AND = 68
  ATOMIC_OR = 69
  ATOMIC_XOR = 70
  ATOMIC_NAND = 71
  ATOMIC_EXCHANGE = 72
  UNKNOWN = 73

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
