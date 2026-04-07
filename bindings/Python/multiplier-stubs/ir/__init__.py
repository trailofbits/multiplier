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
  ADDRESS_OF = 4
  GEP_FIELD = 5
  PTR_ADD = 6
  ADD = 7
  SUB = 8
  MUL = 9
  DIV = 10
  REM = 11
  BIT_AND = 12
  BIT_OR = 13
  BIT_XOR = 14
  SHL = 15
  SHR = 16
  LOGICAL_AND = 17
  LOGICAL_OR = 18
  PTR_DIFF = 19
  CMP_EQ = 20
  CMP_NE = 21
  CMP_LT = 22
  CMP_LE = 23
  CMP_GT = 24
  CMP_GE = 25
  NEG = 26
  BIT_NOT = 27
  LOGICAL_NOT = 28
  CAST = 29
  CALL = 30
  READ_MODIFY_WRITE = 31
  SELECT = 32
  COND_BRANCH = 33
  SWITCH = 34
  RET = 35
  UNREACHABLE = 36
  BREAK = 37
  CONTINUE = 38
  GOTO = 39
  IMPLICIT_GOTO = 40
  FALLTHROUGH = 41
  IMPLICIT_FALLTHROUGH = 42
  IMPLICIT_UNREACHABLE = 43
  VA_PACK = 44
  VA_START = 45
  VA_ARG = 46
  VA_COPY = 47
  VA_END = 48
  ENTER_SCOPE = 49
  EXIT_SCOPE = 50
  MULTIMEM = 51
  PARAM_READ = 52
  GLOBAL_ADDR = 53
  FUNC_ADDR = 54
  BITWISE = 55
  FLOAT = 56
  UNDEFINED = 57
  DYNAMIC_ALLOCA = 58
  FRAME_ADDRESS = 59
  RETURN_ADDRESS = 60
  ATOMIC_LOAD = 61
  ATOMIC_STORE = 62
  ATOMIC_CMPXCHG = 63
  ADD_OVERFLOW = 64
  SUB_OVERFLOW = 65
  MUL_OVERFLOW = 66
  ATOMIC_ADD = 67
  ATOMIC_SUB = 68
  ATOMIC_AND = 69
  ATOMIC_OR = 70
  ATOMIC_XOR = 71
  ATOMIC_NAND = 72
  ATOMIC_EXCHANGE = 73
  UNKNOWN = 74

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
