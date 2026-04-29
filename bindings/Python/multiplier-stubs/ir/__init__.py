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

class FunctionKind(IntEnum):
  NORMAL = 0
  GLOBAL_INITIALIZER = 1
  THREAD_LOCAL_INITIALIZER = 2

class BlockKind(IntEnum):
  FRAME = 0
  ENTRY = 1
  IF_THEN = 2
  IF_ELSE = 3
  IF_MERGE = 4
  LOOP_PREHEADER = 5
  LOOP_CONDITION = 6
  LOOP_BODY = 7
  LOOP_EXIT = 8
  LOOP_INCREMENT = 9
  SWITCH_CASE = 10
  SWITCH_DEFAULT = 11
  SWITCH_EXIT = 12
  LABEL = 13
  COMPENSATION = 14
  UNREACHABLE = 15
  GENERIC = 16

class ConstOp(IntEnum):
  INT8 = 0
  INT16 = 1
  INT32 = 2
  INT64 = 3
  UINT8 = 4
  UINT16 = 5
  UINT32 = 6
  UINT64 = 7
  FLOAT32 = 8
  FLOAT64 = 9
  FLOAT16 = 10
  NULL_PTR = 11
  INF32 = 12
  INF64 = 13
  NAN32 = 14
  NAN64 = 15
  WCHAR16 = 16
  WCHAR32 = 17
  BOOL = 18

class AllocaKind(IntEnum):
  LOCAL = 0
  ARG = 1
  RETURN = 2
  DYNAMIC = 3

class CastOp(IntEnum):
  SEXT_I8_I16 = 0
  SEXT_I8_I32 = 1
  SEXT_I8_I64 = 2
  SEXT_I16_I32 = 3
  SEXT_I16_I64 = 4
  SEXT_I32_I64 = 5
  ZEXT_I8_I16 = 6
  ZEXT_I8_I32 = 7
  ZEXT_I8_I64 = 8
  ZEXT_I16_I32 = 9
  ZEXT_I16_I64 = 10
  ZEXT_I32_I64 = 11
  TRUNC_I16_I8 = 12
  TRUNC_I32_I8 = 13
  TRUNC_I64_I8 = 14
  TRUNC_I32_I16 = 15
  TRUNC_I64_I16 = 16
  TRUNC_I64_I32 = 17
  F32_TO_F64 = 18
  F64_TO_F32 = 19
  SI8_TO_F32 = 20
  SI8_TO_F64 = 21
  SI16_TO_F32 = 22
  SI16_TO_F64 = 23
  SI32_TO_F32 = 24
  SI32_TO_F64 = 25
  SI64_TO_F32 = 26
  SI64_TO_F64 = 27
  UI8_TO_F32 = 28
  UI8_TO_F64 = 29
  UI16_TO_F32 = 30
  UI16_TO_F64 = 31
  UI32_TO_F32 = 32
  UI32_TO_F64 = 33
  UI64_TO_F32 = 34
  UI64_TO_F64 = 35
  F32_TO_SI8 = 36
  F32_TO_SI16 = 37
  F32_TO_SI32 = 38
  F32_TO_SI64 = 39
  F64_TO_SI8 = 40
  F64_TO_SI16 = 41
  F64_TO_SI32 = 42
  F64_TO_SI64 = 43
  F32_TO_UI8 = 44
  F32_TO_UI16 = 45
  F32_TO_UI32 = 46
  F32_TO_UI64 = 47
  F64_TO_UI8 = 48
  F64_TO_UI16 = 49
  F64_TO_UI32 = 50
  F64_TO_UI64 = 51
  PTR_TO_I32 = 52
  PTR_TO_I64 = 53
  I32_TO_PTR = 54
  I64_TO_PTR = 55
  BITCAST = 56
  IDENTITY = 57

class OpCode(IntEnum):
  CONST = 0
  ALLOCA = 1
  MEMORY = 2
  LOGICAL_AND = 3
  LOGICAL_OR = 4
  LOGICAL_NOT = 5
  CAST = 6
  CALL = 7
  READ_MODIFY_WRITE = 8
  SELECT = 9
  COND_BRANCH = 10
  SWITCH = 11
  RET = 12
  UNREACHABLE = 13
  BREAK = 14
  CONTINUE = 15
  GOTO = 16
  IMPLICIT_GOTO = 17
  FALLTHROUGH = 18
  IMPLICIT_FALLTHROUGH = 19
  IMPLICIT_UNREACHABLE = 20
  VA_START = 21
  VA_COPY = 22
  VA_END = 23
  ENTER_SCOPE = 24
  EXIT_SCOPE = 25
  FLOAT = 26
  UNDEFINED = 27
  LAST_VALUE = 28
  UNKNOWN = 29
  FCMP_EQ_32 = 30
  FCMP_EQ_64 = 31
  FCMP_NE_32 = 32
  FCMP_NE_64 = 33
  FCMP_LT_32 = 34
  FCMP_LT_64 = 35
  FCMP_LE_32 = 36
  FCMP_LE_64 = 37
  FCMP_GT_32 = 38
  FCMP_GT_64 = 39
  FCMP_GE_32 = 40
  FCMP_GE_64 = 41
  FADD_32 = 42
  FADD_64 = 43
  FSUB_32 = 44
  FSUB_64 = 45
  FMUL_32 = 46
  FMUL_64 = 47
  FDIV_32 = 48
  FDIV_64 = 49
  FREM_32 = 50
  FREM_64 = 51
  FNEG_32 = 52
  FNEG_64 = 53
  ADD_8 = 54
  ADD_16 = 55
  ADD_32 = 56
  ADD_64 = 57
  SUB_8 = 58
  SUB_16 = 59
  SUB_32 = 60
  SUB_64 = 61
  MUL_8 = 62
  MUL_16 = 63
  MUL_32 = 64
  MUL_64 = 65
  DIV_8 = 66
  DIV_16 = 67
  DIV_32 = 68
  DIV_64 = 69
  REM_8 = 70
  REM_16 = 71
  REM_32 = 72
  REM_64 = 73
  UDIV_8 = 74
  UDIV_16 = 75
  UDIV_32 = 76
  UDIV_64 = 77
  UREM_8 = 78
  UREM_16 = 79
  UREM_32 = 80
  UREM_64 = 81
  USHR_8 = 82
  USHR_16 = 83
  USHR_32 = 84
  USHR_64 = 85
  BIT_AND_8 = 86
  BIT_AND_16 = 87
  BIT_AND_32 = 88
  BIT_AND_64 = 89
  BIT_OR_8 = 90
  BIT_OR_16 = 91
  BIT_OR_32 = 92
  BIT_OR_64 = 93
  BIT_XOR_8 = 94
  BIT_XOR_16 = 95
  BIT_XOR_32 = 96
  BIT_XOR_64 = 97
  SHL_8 = 98
  SHL_16 = 99
  SHL_32 = 100
  SHL_64 = 101
  SHR_8 = 102
  SHR_16 = 103
  SHR_32 = 104
  SHR_64 = 105
  CMP_EQ_8 = 106
  CMP_EQ_16 = 107
  CMP_EQ_32 = 108
  CMP_EQ_64 = 109
  CMP_NE_8 = 110
  CMP_NE_16 = 111
  CMP_NE_32 = 112
  CMP_NE_64 = 113
  CMP_LT_8 = 114
  CMP_LT_16 = 115
  CMP_LT_32 = 116
  CMP_LT_64 = 117
  CMP_LE_8 = 118
  CMP_LE_16 = 119
  CMP_LE_32 = 120
  CMP_LE_64 = 121
  CMP_GT_8 = 122
  CMP_GT_16 = 123
  CMP_GT_32 = 124
  CMP_GT_64 = 125
  CMP_GE_8 = 126
  CMP_GE_16 = 127
  CMP_GE_32 = 128
  CMP_GE_64 = 129
  UCMP_LT_8 = 130
  UCMP_LT_16 = 131
  UCMP_LT_32 = 132
  UCMP_LT_64 = 133
  UCMP_LE_8 = 134
  UCMP_LE_16 = 135
  UCMP_LE_32 = 136
  UCMP_LE_64 = 137
  UCMP_GT_8 = 138
  UCMP_GT_16 = 139
  UCMP_GT_32 = 140
  UCMP_GT_64 = 141
  UCMP_GE_8 = 142
  UCMP_GE_16 = 143
  UCMP_GE_32 = 144
  UCMP_GE_64 = 145
  NEG_8 = 146
  NEG_16 = 147
  NEG_32 = 148
  NEG_64 = 149
  BIT_NOT_8 = 150
  BIT_NOT_16 = 151
  BIT_NOT_32 = 152
  BIT_NOT_64 = 153
  PTR_ADD_32 = 154
  PTR_ADD_64 = 155
  GEP_FIELD_32 = 156
  GEP_FIELD_64 = 157
  GLOBAL_PTR_32 = 158
  GLOBAL_PTR_64 = 159
  THREAD_LOCAL_PTR_32 = 160
  THREAD_LOCAL_PTR_64 = 161
  FUNC_PTR_32 = 162
  FUNC_PTR_64 = 163
  STRING_PTR_32 = 164
  STRING_PTR_64 = 165
  PARAM_PTR_32 = 166
  PARAM_PTR_64 = 167
  FRAME_PTR_32 = 168
  FRAME_PTR_64 = 169
  RETURN_PTR_32 = 170
  RETURN_PTR_64 = 171
  RETURN_ADDRESS_32 = 172
  RETURN_ADDRESS_64 = 173
  ATOMIC_ADD_8 = 174
  ATOMIC_ADD_16 = 175
  ATOMIC_ADD_32 = 176
  ATOMIC_ADD_64 = 177
  ATOMIC_SUB_8 = 178
  ATOMIC_SUB_16 = 179
  ATOMIC_SUB_32 = 180
  ATOMIC_SUB_64 = 181
  ATOMIC_AND_8 = 182
  ATOMIC_AND_16 = 183
  ATOMIC_AND_32 = 184
  ATOMIC_AND_64 = 185
  ATOMIC_OR_8 = 186
  ATOMIC_OR_16 = 187
  ATOMIC_OR_32 = 188
  ATOMIC_OR_64 = 189
  ATOMIC_XOR_8 = 190
  ATOMIC_XOR_16 = 191
  ATOMIC_XOR_32 = 192
  ATOMIC_XOR_64 = 193
  ATOMIC_NAND_8 = 194
  ATOMIC_NAND_16 = 195
  ATOMIC_NAND_32 = 196
  ATOMIC_NAND_64 = 197
  ATOMIC_EXCHANGE_8 = 198
  ATOMIC_EXCHANGE_16 = 199
  ATOMIC_EXCHANGE_32 = 200
  ATOMIC_EXCHANGE_64 = 201
  ADD_OVERFLOW_8 = 202
  ADD_OVERFLOW_16 = 203
  ADD_OVERFLOW_32 = 204
  ADD_OVERFLOW_64 = 205
  SUB_OVERFLOW_8 = 206
  SUB_OVERFLOW_16 = 207
  SUB_OVERFLOW_32 = 208
  SUB_OVERFLOW_64 = 209
  MUL_OVERFLOW_8 = 210
  MUL_OVERFLOW_16 = 211
  MUL_OVERFLOW_32 = 212
  MUL_OVERFLOW_64 = 213
  PTR_DIFF_32 = 214
  PTR_DIFF_64 = 215
  BITWISE_8 = 216
  BITWISE_16 = 217
  BITWISE_32 = 218
  BITWISE_64 = 219
  ABS_8 = 220
  ABS_16 = 221
  ABS_32 = 222
  ABS_64 = 223

class MemOp(IntEnum):
  LOAD_LE_8 = 0
  LOAD_LE_16 = 1
  LOAD_LE_32 = 2
  LOAD_LE_64 = 3
  LOAD_BE_8 = 4
  LOAD_BE_16 = 5
  LOAD_BE_32 = 6
  LOAD_BE_64 = 7
  STORE_LE_8 = 8
  STORE_LE_16 = 9
  STORE_LE_32 = 10
  STORE_LE_64 = 11
  STORE_BE_8 = 12
  STORE_BE_16 = 13
  STORE_BE_32 = 14
  STORE_BE_64 = 15
  ATOMIC_LOAD_LE_8 = 16
  ATOMIC_LOAD_LE_16 = 17
  ATOMIC_LOAD_LE_32 = 18
  ATOMIC_LOAD_LE_64 = 19
  ATOMIC_LOAD_BE_8 = 20
  ATOMIC_LOAD_BE_16 = 21
  ATOMIC_LOAD_BE_32 = 22
  ATOMIC_LOAD_BE_64 = 23
  ATOMIC_STORE_LE_8 = 24
  ATOMIC_STORE_LE_16 = 25
  ATOMIC_STORE_LE_32 = 26
  ATOMIC_STORE_LE_64 = 27
  ATOMIC_STORE_BE_8 = 28
  ATOMIC_STORE_BE_16 = 29
  ATOMIC_STORE_BE_32 = 30
  ATOMIC_STORE_BE_64 = 31
  MEMSET = 32
  MEMCPY = 33
  MEMMOVE = 34
  MEMCMP = 35
  MEMCHR = 36
  BZERO = 37
  STRLEN = 38
  STRNLEN = 39
  STRCMP = 40
  STRNCMP = 41
  STRCHR = 42
  STRRCHR = 43
  STRSTR = 44
  STRCPY = 45
  STRNCPY = 46
  STRCAT = 47
  STRNCAT = 48
  STPCPY = 49
  STPNCPY = 50
  STRTOI32 = 51
  STRTOI64 = 52
  STRTOU32 = 53
  STRTOU64 = 54
  STRTOF32 = 55
  STRTOF64 = 56
  BIT_READ_LE = 57
  BIT_WRITE_LE = 58
  BIT_READ_BE = 59
  BIT_WRITE_BE = 60
  CMPXCHG_LE_8 = 61
  CMPXCHG_LE_16 = 62
  CMPXCHG_LE_32 = 63
  CMPXCHG_LE_64 = 64
  CMPXCHG_BE_8 = 65
  CMPXCHG_BE_16 = 66
  CMPXCHG_BE_32 = 67
  CMPXCHG_BE_64 = 68
  CONSUME_VA_PARAM = 69
  LOAD_F32_LE = 70
  LOAD_F64_LE = 71
  LOAD_F32_BE = 72
  LOAD_F64_BE = 73
  STORE_F32_LE = 74
  STORE_F64_LE = 75
  STORE_F32_BE = 76
  STORE_F64_BE = 77

class BitwiseOp(IntEnum):
  BSWAP_16 = 0
  BSWAP_32 = 1
  BSWAP_64 = 2
  POPCOUNT = 3
  CLZ = 4
  CTZ = 5
  FFS = 6
  PARITY = 7
  ROTL = 8
  ROTR = 9

class FloatOp(IntEnum):
  ISNAN_32 = 0
  ISNAN_64 = 1
  ISINF_32 = 2
  ISINF_64 = 3
  ISFINITE_32 = 4
  ISFINITE_64 = 5
  FABS_32 = 6
  FABS_64 = 7
  COPYSIGN_32 = 8
  COPYSIGN_64 = 9
  FMIN_32 = 10
  FMIN_64 = 11
  FMAX_32 = 12
  FMAX_64 = 13
  CEIL_32 = 14
  CEIL_64 = 15
  FLOOR_32 = 16
  FLOOR_64 = 17
  ROUND_32 = 18
  ROUND_64 = 19
  TRUNC_32 = 20
  TRUNC_64 = 21
  SQRT_32 = 22
  SQRT_64 = 23
  INF_32 = 24
  INF_64 = 25
  NAN_32 = 26
  NAN_64 = 27
  HUGE_32 = 28
  HUGE_64 = 29
  SIN_32 = 30
  SIN_64 = 31
  COS_32 = 32
  COS_64 = 33
  TAN_32 = 34
  TAN_64 = 35
  ASIN_32 = 36
  ASIN_64 = 37
  ACOS_32 = 38
  ACOS_64 = 39
  ATAN_32 = 40
  ATAN_64 = 41
  ATAN2_32 = 42
  ATAN2_64 = 43
  EXP_32 = 44
  EXP_64 = 45
  EXP2_32 = 46
  EXP2_64 = 47
  LOG_32 = 48
  LOG_64 = 49
  LOG2_32 = 50
  LOG2_64 = 51
  LOG10_32 = 52
  LOG10_64 = 53
  POW_32 = 54
  POW_64 = 55
  FMOD_32 = 56
  FMOD_64 = 57
  REMAINDER_32 = 58
  REMAINDER_64 = 59
  FMA_32 = 60
  FMA_64 = 61
  SINH_32 = 62
  SINH_64 = 63
  COSH_32 = 64
  COSH_64 = 65
  TANH_32 = 66
  TANH_64 = 67
  HYPOT_32 = 68
  HYPOT_64 = 69
  ERF_32 = 70
  ERF_64 = 71
  ERFC_32 = 72
  ERFC_64 = 73
  TGAMMA_32 = 74
  TGAMMA_64 = 75
  LGAMMA_32 = 76
  LGAMMA_64 = 77
  FDIM_32 = 78
  FDIM_64 = 79
  SIGNBIT_32 = 80
  SIGNBIT_64 = 81

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

class StructureKind(IntEnum):
  FUNCTION_SCOPE = 0
  SCOPE = 1
  IF = 2
  IF_THEN = 3
  IF_ELSE = 4
  FOR = 5
  FOR_INIT = 6
  FOR_CONDITION = 7
  FOR_BODY = 8
  FOR_INCREMENT = 9
  WHILE = 10
  WHILE_CONDITION = 11
  WHILE_BODY = 12
  DO_WHILE = 13
  DO_WHILE_BODY = 14
  DO_WHILE_CONDITION = 15
  SWITCH = 16
  SWITCH_CASE = 17
  EXPRESSION_SCOPE = 18

class IRFunction(multiplier.Entity):
  kind: multiplier.ir.FunctionKind
  declaration: Optional[multiplier.ast.FunctionDecl]
  source_declaration: Optional[multiplier.ast.Decl]
  entry_block: multiplier.ir.IRBlock
  blocks: Iterable[multiplier.ir.IRBlock]
  objects: Iterable[multiplier.ir.IRObject]
  body_scope: Optional[multiplier.ir.IRStructure]
  frame_size_bytes: int
  has_dynamic_allocas: bool

  @overload
  @staticmethod
  def FROM(decl: multiplier.ast.FunctionDecl) -> Optional[multiplier.ir.IRFunction]:
    ...

  @overload
  @staticmethod
  def FROM(decl: multiplier.ast.VarDecl) -> Optional[multiplier.ir.IRFunction]:
    ...

  @overload
  @staticmethod
  def containing(decl: multiplier.ast.Decl) -> Optional[multiplier.ir.IRFunction]:
    ...

  @overload
  @staticmethod
  def containing(stmt: multiplier.ast.Stmt) -> Optional[multiplier.ir.IRFunction]:
    ...

  @overload
  @staticmethod
  def containing(block: multiplier.ir.IRBlock) -> Optional[multiplier.ir.IRFunction]:
    ...

  @overload
  @staticmethod
  def containing(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.IRFunction]:
    ...

class IRBlock(multiplier.Entity):
  kind: multiplier.ir.BlockKind
  parent_structure: Optional[multiplier.ir.IRStructure]
  parent_function: Optional[multiplier.ir.IRFunction]
  all_instructions: Iterable[multiplier.ir.IRInstruction]
  instructions: Iterable[multiplier.ir.IRInstruction]
  successors: Iterable[multiplier.ir.IRBlock]
  predecessors: Iterable[multiplier.ir.IRBlock]
  immediate_dominator: Optional[multiplier.ir.IRBlock]
  immediate_post_dominator: Optional[multiplier.ir.IRBlock]
  dominators: Iterable[multiplier.ir.IRBlock]
  post_dominators: Iterable[multiplier.ir.IRBlock]

  def dominates(self, other: multiplier.ir.IRBlock) -> bool:
    ...

class IRInstruction(multiplier.Entity):
  opcode: multiplier.ir.OpCode
  operands: Iterable[multiplier.ir.IRInstruction]
  num_operands: int
  parent_instruction: Optional[multiplier.ir.IRInstruction]
  is_root: bool
  users: Iterable[multiplier.ir.IRInstruction]
  num_users: int
  source_statement: Optional[multiplier.ast.Stmt]
  source_entity_id: int
  parent_block: multiplier.ir.IRBlock
  is_terminator: bool
  is_conditionally_executed: bool
  name: str
  ref_string: str
  to_string: str

  def nth_operand(self, n: int) -> multiplier.ir.IRInstruction:
    ...

class ConstInst(multiplier.ir.IRInstruction):
  sub_opcode: multiplier.ir.ConstOp
  signed_value: int
  unsigned_value: int
  float_value: float
  type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ConstInst]:
    ...

class AllocaInst(multiplier.ir.IRInstruction):
  alloca_kind: multiplier.ir.AllocaKind
  allocated_type: multiplier.ast.Type
  object: multiplier.ir.IRObject
  size_bytes: int
  align_bytes: int

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.AllocaInst]:
    ...

class LocalAllocaInst(multiplier.ir.AllocaInst):

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.LocalAllocaInst]:
    ...

class ArgAllocaInst(multiplier.ir.AllocaInst):

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ArgAllocaInst]:
    ...

class ReturnAllocaInst(multiplier.ir.AllocaInst):

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ReturnAllocaInst]:
    ...

class DynamicAllocaInst(multiplier.ir.AllocaInst):
  size: multiplier.ir.IRInstruction

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.DynamicAllocaInst]:
    ...

class MemoryInst(multiplier.ir.IRInstruction):
  sub_opcode: multiplier.ir.MemOp
  address: multiplier.ir.IRInstruction
  stored_value: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type
  bit_offset: int
  bit_width: int

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.MemoryInst]:
    ...

class GEPFieldInst(multiplier.ir.IRInstruction):
  base: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type
  field: multiplier.ast.FieldDecl
  byte_offset: int

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.GEPFieldInst]:
    ...

class PtrAddInst(multiplier.ir.IRInstruction):
  base: multiplier.ir.IRInstruction
  index: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type
  element_type: multiplier.ast.Type
  element_size: int

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.PtrAddInst]:
    ...

class PtrDiffInst(multiplier.ir.IRInstruction):
  lhs: multiplier.ir.IRInstruction
  rhs: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type
  element_size: int

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.PtrDiffInst]:
    ...

class BinaryInst(multiplier.ir.IRInstruction):
  lhs: multiplier.ir.IRInstruction
  rhs: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.BinaryInst]:
    ...

class ComparisonInst(multiplier.ir.IRInstruction):
  lhs: multiplier.ir.IRInstruction
  rhs: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ComparisonInst]:
    ...

class UnaryInst(multiplier.ir.IRInstruction):
  operand: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.UnaryInst]:
    ...

class CastInst(multiplier.ir.IRInstruction):
  sub_opcode: multiplier.ir.CastOp
  operand: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.CastInst]:
    ...

class CallInst(multiplier.ir.IRInstruction):
  result_type: Optional[multiplier.ast.Type]
  target: Optional[multiplier.ast.FunctionDecl]
  is_indirect: bool
  has_return_value: bool
  return_alloca: Optional[multiplier.ir.AllocaInst]
  arguments: Iterable[multiplier.ir.IRInstruction]

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.CallInst]:
    ...

class ReadModifyWriteInst(multiplier.ir.IRInstruction):
  address: multiplier.ir.IRInstruction
  underlying_op: multiplier.ir.OpCode
  element_size: int
  is_big_endian: bool
  is_atomic: bool
  returns_new_value: bool
  result_type: multiplier.ast.Type
  rhs_operands: Iterable[multiplier.ir.IRInstruction]

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ReadModifyWriteInst]:
    ...

class LastValueInst(multiplier.ir.IRInstruction):
  last: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.LastValueInst]:
    ...

class SelectInst(multiplier.ir.IRInstruction):
  condition: multiplier.ir.IRInstruction
  true_value: multiplier.ir.IRInstruction
  false_value: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.SelectInst]:
    ...

class ParamPtrInst(multiplier.ir.IRInstruction):
  parameter_index: int
  parameter_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ParamPtrInst]:
    ...

class GlobalPtrInst(multiplier.ir.IRInstruction):
  variable: Optional[multiplier.ast.VarDecl]

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.GlobalPtrInst]:
    ...

class ThreadLocalPtrInst(multiplier.ir.IRInstruction):
  variable: Optional[multiplier.ast.VarDecl]

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ThreadLocalPtrInst]:
    ...

class FuncPtrInst(multiplier.ir.IRInstruction):
  function: Optional[multiplier.ast.FunctionDecl]

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.FuncPtrInst]:
    ...

class ReturnPtrInst(multiplier.ir.IRInstruction):
  return_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ReturnPtrInst]:
    ...

class BitwiseOpInst(multiplier.ir.IRInstruction):
  sub_opcode: multiplier.ir.BitwiseOp
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.BitwiseOpInst]:
    ...

class FloatOpInst(multiplier.ir.IRInstruction):
  sub_opcode: multiplier.ir.FloatOp
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.FloatOpInst]:
    ...

class FramePtrInst(multiplier.ir.IRInstruction):
  level: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.FramePtrInst]:
    ...

class ReturnAddressInst(multiplier.ir.IRInstruction):
  level: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ReturnAddressInst]:
    ...

class UndefinedInst(multiplier.ir.IRInstruction):
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.UndefinedInst]:
    ...

class EnterScopeInst(multiplier.ir.IRInstruction):
  scope: multiplier.ir.IRStructure

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.EnterScopeInst]:
    ...

class ExitScopeInst(multiplier.ir.IRInstruction):
  scope: multiplier.ir.IRStructure

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ExitScopeInst]:
    ...

class VAStartInst(multiplier.ir.IRInstruction):
  va_list_operand: multiplier.ir.IRInstruction

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.VAStartInst]:
    ...

class VAEndInst(multiplier.ir.IRInstruction):
  va_list_operand: multiplier.ir.IRInstruction

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.VAEndInst]:
    ...

class VACopyInst(multiplier.ir.IRInstruction):
  dest: multiplier.ir.IRInstruction
  src: multiplier.ir.IRInstruction

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.VACopyInst]:
    ...

class ConsumeVAParamInst(multiplier.ir.IRInstruction):
  va_list_operand: multiplier.ir.IRInstruction
  result_type: multiplier.ast.Type

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.ConsumeVAParamInst]:
    ...

class RetInst(multiplier.ir.IRInstruction):

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.RetInst]:
    ...

class BranchInst(multiplier.ir.IRInstruction):
  target_block: multiplier.ir.IRBlock

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.BranchInst]:
    ...

class CondBranchInst(multiplier.ir.IRInstruction):
  condition: multiplier.ir.IRInstruction
  true_block: multiplier.ir.IRBlock
  false_block: multiplier.ir.IRBlock

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.CondBranchInst]:
    ...

class SwitchInst(multiplier.ir.IRInstruction):
  selector: multiplier.ir.IRInstruction
  case_type: Optional[multiplier.ast.Type]
  cases: Iterable[multiplier.ir.IRSwitchCaseStructure]
  num_cases: int

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.SwitchInst]:
    ...

class UnreachableInst(multiplier.ir.IRInstruction):

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.UnreachableInst]:
    ...

class UnknownInst(multiplier.ir.IRInstruction):

  @staticmethod
  def FROM(inst: multiplier.ir.IRInstruction) -> Optional[multiplier.ir.UnknownInst]:
    ...

class IRObject(multiplier.Entity):
  kind: multiplier.ir.ObjectKind
  source_declaration: Optional[multiplier.ast.VarDecl]
  type: Optional[multiplier.ast.Type]
  size_bytes: int
  align_bytes: int
  frame_offset: int
  needs_memory: bool

class IRStructure(multiplier.Entity):
  kind: multiplier.ir.StructureKind
  source_statement: Optional[multiplier.ast.Stmt]
  parent_structure: Optional[multiplier.ir.IRStructure]
  parent_function: Optional[multiplier.ir.IRFunction]
  child_structures: Iterable[multiplier.ir.IRStructure]
  child_blocks: Iterable[multiplier.ir.IRBlock]
  objects: Iterable[multiplier.ir.IRObject]
  is_scope: bool

class IRScopeStructure(multiplier.ir.IRStructure):

  @staticmethod
  def FROM(s: multiplier.ir.IRStructure) -> Optional[multiplier.ir.IRScopeStructure]:
    ...

class IRIfStructure(multiplier.ir.IRStructure):
  then_branch: Optional[multiplier.ir.IRStructure]
  else_branch: Optional[multiplier.ir.IRStructure]

  @staticmethod
  def FROM(s: multiplier.ir.IRStructure) -> Optional[multiplier.ir.IRIfStructure]:
    ...

class IRIfThenStructure(multiplier.ir.IRStructure):

  @staticmethod
  def FROM(s: multiplier.ir.IRStructure) -> Optional[multiplier.ir.IRIfThenStructure]:
    ...

class IRIfElseStructure(multiplier.ir.IRStructure):

  @staticmethod
  def FROM(s: multiplier.ir.IRStructure) -> Optional[multiplier.ir.IRIfElseStructure]:
    ...

class IRForStructure(multiplier.ir.IRStructure):
  init: Optional[multiplier.ir.IRStructure]
  condition: Optional[multiplier.ir.IRStructure]
  body: Optional[multiplier.ir.IRStructure]
  increment: Optional[multiplier.ir.IRStructure]

  @staticmethod
  def FROM(s: multiplier.ir.IRStructure) -> Optional[multiplier.ir.IRForStructure]:
    ...

class IRWhileStructure(multiplier.ir.IRStructure):
  condition: Optional[multiplier.ir.IRStructure]
  body: Optional[multiplier.ir.IRStructure]

  @staticmethod
  def FROM(s: multiplier.ir.IRStructure) -> Optional[multiplier.ir.IRWhileStructure]:
    ...

class IRDoWhileStructure(multiplier.ir.IRStructure):
  body: Optional[multiplier.ir.IRStructure]
  condition: Optional[multiplier.ir.IRStructure]

  @staticmethod
  def FROM(s: multiplier.ir.IRStructure) -> Optional[multiplier.ir.IRDoWhileStructure]:
    ...

class IRSwitchStructure(multiplier.ir.IRStructure):
  cases: Iterable[multiplier.ir.IRSwitchCaseStructure]
  default_case: Optional[multiplier.ir.IRSwitchCaseStructure]

  @staticmethod
  def FROM(s: multiplier.ir.IRStructure) -> Optional[multiplier.ir.IRSwitchStructure]:
    ...

class IRSwitchCaseStructure(multiplier.ir.IRStructure):
  low: int
  high: int
  is_range: bool
  is_default: bool
  target_block: multiplier.ir.IRBlock

  @staticmethod
  def FROM(s: multiplier.ir.IRStructure) -> Optional[multiplier.ir.IRSwitchCaseStructure]:
    ...

class IRExpressionScopeStructure(multiplier.ir.IRStructure):

  @staticmethod
  def FROM(s: multiplier.ir.IRStructure) -> Optional[multiplier.ir.IRExpressionScopeStructure]:
    ...
