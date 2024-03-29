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

class AttributeKind(IntEnum):
  UNKNOWN = 0
  BUILTIN_TYPED = 1
  BUILTIN_ELEMENTS = 2
  BUILTIN_AFFINE_MAP = 3
  BUILTIN_ARRAY = 4
  BUILTIN_DENSE_ARRAY = 5
  BUILTIN_DENSE_INT_OR_FP_ELEMENTS = 6
  BUILTIN_DENSE_RESOURCE_ELEMENTS = 7
  BUILTIN_DENSE_STRING_ELEMENTS = 8
  BUILTIN_DICTIONARY = 9
  BUILTIN_FLOAT = 10
  BUILTIN_INTEGER = 11
  BUILTIN_INTEGER_SET = 12
  BUILTIN_OPAQUE = 13
  BUILTIN_SPARSE_ELEMENTS = 14
  BUILTIN_STRING = 15
  BUILTIN_SYMBOL_REF = 16
  BUILTIN_TYPE = 17
  BUILTIN_UNIT = 18
  BUILTIN_STRIDED_LAYOUT = 19
  BUILTIN_BOOL = 20
  BUILTIN_FLAT_SYMBOL_REF = 21
  BUILTIN_DENSE_INT_ELEMENTS = 22
  LLVM_C_CONV = 23
  LLVM_COMDAT = 24
  LLVM_ACCESS_GROUP = 25
  LLVM_ALIAS_SCOPE = 26
  LLVM_ALIAS_SCOPE_DOMAIN = 27
  LLVM_DI_BASIC_TYPE = 28
  LLVM_DI_COMPILE_UNIT = 29
  LLVM_DI_COMPOSITE_TYPE = 30
  LLVM_DI_DERIVED_TYPE = 31
  LLVM_DI_FILE = 32
  LLVM_DI_LABEL = 33
  LLVM_DI_LEXICAL_BLOCK = 34
  LLVM_DI_LEXICAL_BLOCK_FILE = 35
  LLVM_DI_LOCAL_VARIABLE = 36
  LLVM_DI_NAMESPACE = 37
  LLVM_DI_NULL_TYPE = 38
  LLVM_DI_SUBPROGRAM = 39
  LLVM_DI_SUBRANGE = 40
  LLVM_DI_SUBROUTINE_TYPE = 41
  LLVM_FASTMATH_FLAGS = 42
  LLVM_MEMORY_EFFECTS = 43
  LLVM_TBAA_MEMBER = 44
  LLVM_TBAA_ROOT = 45
  LLVM_TBAA_TAG = 46
  LLVM_TBAA_TYPE_DESCRIPTOR = 47
  LLVM_LINKAGE = 48
  LLVM_LOOP_ANNOTATION = 49
  LLVM_LOOP_DISTRIBUTE = 50
  LLVM_LOOP_INTERLEAVE = 51
  LLVM_LOOP_LICM = 52
  LLVM_LOOP_PEELED = 53
  LLVM_LOOP_PIPELINE = 54
  LLVM_LOOP_UNROLL_AND_JAM = 55
  LLVM_LOOP_UNROLL = 56
  LLVM_LOOP_UNSWITCH = 57
  LLVM_LOOP_VECTORIZE = 58
  HL_ALLOC_ALIGN = 59
  HL_ALLOC_SIZE = 60
  HL_ANNOTATION = 61
  HL_ASM_LABEL = 62
  HL_BUILTIN = 63
  HL_CV_QUALIFIERS = 64
  HL_CVR_QUALIFIERS = 65
  HL_CONST = 66
  HL_FORMAT = 67
  HL_LOADER_UNINITIALIZED = 68
  HL_MODE = 69
  HL_NO_INSTRUMENT_FUNCTION = 70
  HL_NO_THROW = 71
  HL_NON_NULL = 72
  HL_PACKED = 73
  HL_PURE = 74
  HL_RESTRICT = 75
  HL_SECTION = 76
  HL_UCV_QUALIFIERS = 77
  HL_WARN_UNUSED_RESULT = 78
  CORE_BOOLEAN = 79
  CORE_FLOAT = 80
  CORE_INTEGER = 81
  CORE_SOURCE_LANGUAGE = 82
  CORE_STRING_LITERAL = 83
  CORE_VOID = 84
  META_IDENTIFIER = 85

class ValueKind(IntEnum):
  OPERATION_RESULT = 0
  BLOCK_ARGUMENT = 1

class OperationKind(IntEnum):
  UNKNOWN = 0
  BUILTIN_MODULE = 1
  BUILTIN_UNREALIZED_CONVERSION_CAST = 2
  LLVM_ASHR = 3
  LLVM_ADD = 4
  LLVM_ADDRSPACECAST = 5
  LLVM_MLIR_ADDRESSOF = 6
  LLVM_ALLOCA = 7
  LLVM_AND = 8
  LLVM_CMPXCHG = 9
  LLVM_ATOMICRMW = 10
  LLVM_BITCAST = 11
  LLVM_BR = 12
  LLVM_CALL = 13
  LLVM_COMDAT = 14
  LLVM_COMDAT_SELECTOR = 15
  LLVM_COND_BR = 16
  LLVM_MLIR_CONSTANT = 17
  LLVM_EXTRACTELEMENT = 18
  LLVM_EXTRACTVALUE = 19
  LLVM_FADD = 20
  LLVM_FCMP = 21
  LLVM_FDIV = 22
  LLVM_FMUL = 23
  LLVM_FNEG = 24
  LLVM_FPEXT = 25
  LLVM_FPTOSI = 26
  LLVM_FPTOUI = 27
  LLVM_FPTRUNC = 28
  LLVM_FREM = 29
  LLVM_FSUB = 30
  LLVM_FENCE = 31
  LLVM_FREEZE = 32
  LLVM_GETELEMENTPTR = 33
  LLVM_MLIR_GLOBAL_CTORS = 34
  LLVM_MLIR_GLOBAL_DTORS = 35
  LLVM_MLIR_GLOBAL = 36
  LLVM_ICMP = 37
  LLVM_INLINE_ASM = 38
  LLVM_INSERTELEMENT = 39
  LLVM_INSERTVALUE = 40
  LLVM_INTTOPTR = 41
  LLVM_INVOKE = 42
  LLVM_FUNC = 43
  LLVM_LSHR = 44
  LLVM_LANDINGPAD = 45
  LLVM_LOAD = 46
  LLVM_METADATA = 47
  LLVM_MUL = 48
  LLVM_MLIR_NULL = 49
  LLVM_OR = 50
  LLVM_MLIR_POISON = 51
  LLVM_PTRTOINT = 52
  LLVM_RESUME = 53
  LLVM_RETURN = 54
  LLVM_SDIV = 55
  LLVM_SEXT = 56
  LLVM_SITOFP = 57
  LLVM_SREM = 58
  LLVM_SELECT = 59
  LLVM_SHL = 60
  LLVM_SHUFFLEVECTOR = 61
  LLVM_STORE = 62
  LLVM_SUB = 63
  LLVM_SWITCH = 64
  LLVM_TRUNC = 65
  LLVM_UDIV = 66
  LLVM_UITOFP = 67
  LLVM_UREM = 68
  LLVM_MLIR_UNDEF = 69
  LLVM_UNREACHABLE = 70
  LLVM_XOR = 71
  LLVM_ZEXT = 72
  LLVM_INTR_ABS = 73
  LLVM_INTR_ANNOTATION = 74
  LLVM_INTR_ASSUME = 75
  LLVM_INTR_BITREVERSE = 76
  LLVM_INTR_BSWAP = 77
  LLVM_CALL_INTRINSIC = 78
  LLVM_INTR_COPYSIGN = 79
  LLVM_INTR_CORO_ALIGN = 80
  LLVM_INTR_CORO_BEGIN = 81
  LLVM_INTR_CORO_END = 82
  LLVM_INTR_CORO_FREE = 83
  LLVM_INTR_CORO_ID = 84
  LLVM_INTR_CORO_RESUME = 85
  LLVM_INTR_CORO_SAVE = 86
  LLVM_INTR_CORO_SIZE = 87
  LLVM_INTR_CORO_SUSPEND = 88
  LLVM_INTR_COS = 89
  LLVM_INTR_CTLZ = 90
  LLVM_INTR_CTTZ = 91
  LLVM_INTR_CTPOP = 92
  LLVM_INTR_DBG_DECLARE = 93
  LLVM_INTR_DBG_LABEL = 94
  LLVM_INTR_DBG_VALUE = 95
  LLVM_INTR_DEBUGTRAP = 96
  LLVM_INTR_EH_TYPEID_FOR = 97
  LLVM_INTR_EXP2 = 98
  LLVM_INTR_EXP = 99
  LLVM_INTR_EXPECT = 100
  LLVM_INTR_EXPECT_WITH_PROBABILITY = 101
  LLVM_INTR_FABS = 102
  LLVM_INTR_CEIL = 103
  LLVM_INTR_FLOOR = 104
  LLVM_INTR_FMA = 105
  LLVM_INTR_FMULADD = 106
  LLVM_INTR_TRUNC = 107
  LLVM_INTR_FSHL = 108
  LLVM_INTR_FSHR = 109
  LLVM_INTR_GET_ACTIVE_LANE_MASK = 110
  LLVM_INTR_IS_CONSTANT = 111
  LLVM_INTR_IS_FPCLASS = 112
  LLVM_INTR_LIFETIME_END = 113
  LLVM_INTR_LIFETIME_START = 114
  LLVM_INTR_LLRINT = 115
  LLVM_INTR_LLROUND = 116
  LLVM_INTR_LOG10 = 117
  LLVM_INTR_LOG2 = 118
  LLVM_INTR_LOG = 119
  LLVM_INTR_LRINT = 120
  LLVM_INTR_LROUND = 121
  LLVM_INTR_MASKED_LOAD = 122
  LLVM_INTR_MASKED_STORE = 123
  LLVM_INTR_MATRIX_COLUMN_MAJOR_LOAD = 124
  LLVM_INTR_MATRIX_COLUMN_MAJOR_STORE = 125
  LLVM_INTR_MATRIX_MULTIPLY = 126
  LLVM_INTR_MATRIX_TRANSPOSE = 127
  LLVM_INTR_MAXNUM = 128
  LLVM_INTR_MAXIMUM = 129
  LLVM_INTR_MEMCPY_INLINE = 130
  LLVM_INTR_MEMCPY = 131
  LLVM_INTR_MEMMOVE = 132
  LLVM_INTR_MEMSET = 133
  LLVM_INTR_MINNUM = 134
  LLVM_INTR_MINIMUM = 135
  LLVM_INTR_NEARBYINT = 136
  LLVM_INTR_EXPERIMENTAL_NOALIAS_SCOPE_DECL = 137
  LLVM_INTR_POWI = 138
  LLVM_INTR_POW = 139
  LLVM_INTR_PREFETCH = 140
  LLVM_INTR_PTR_ANNOTATION = 141
  LLVM_INTR_RINT = 142
  LLVM_INTR_ROUNDEVEN = 143
  LLVM_INTR_ROUND = 144
  LLVM_INTR_SADD_SAT = 145
  LLVM_INTR_SADD_WITH_OVERFLOW = 146
  LLVM_INTR_SMAX = 147
  LLVM_INTR_SMIN = 148
  LLVM_INTR_SMUL_WITH_OVERFLOW = 149
  LLVM_INTR_SSA_COPY = 150
  LLVM_INTR_SSHL_SAT = 151
  LLVM_INTR_SSUB_SAT = 152
  LLVM_INTR_SSUB_WITH_OVERFLOW = 153
  LLVM_INTR_SIN = 154
  LLVM_INTR_SQRT = 155
  LLVM_INTR_STACKRESTORE = 156
  LLVM_INTR_STACKSAVE = 157
  LLVM_INTR_EXPERIMENTAL_STEPVECTOR = 158
  LLVM_INTR_THREADLOCAL_ADDRESS = 159
  LLVM_INTR_TRAP = 160
  LLVM_INTR_UADD_SAT = 161
  LLVM_INTR_UADD_WITH_OVERFLOW = 162
  LLVM_INTR_UBSANTRAP = 163
  LLVM_INTR_UMAX = 164
  LLVM_INTR_UMIN = 165
  LLVM_INTR_UMUL_WITH_OVERFLOW = 166
  LLVM_INTR_USHL_SAT = 167
  LLVM_INTR_USUB_SAT = 168
  LLVM_INTR_USUB_WITH_OVERFLOW = 169
  LLVM_INTR_VP_ASHR = 170
  LLVM_INTR_VP_ADD = 171
  LLVM_INTR_VP_AND = 172
  LLVM_INTR_VP_FADD = 173
  LLVM_INTR_VP_FDIV = 174
  LLVM_INTR_VP_FMULADD = 175
  LLVM_INTR_VP_FMUL = 176
  LLVM_INTR_VP_FNEG = 177
  LLVM_INTR_VP_FPEXT = 178
  LLVM_INTR_VP_FPTOSI = 179
  LLVM_INTR_VP_FPTOUI = 180
  LLVM_INTR_VP_FPTRUNC = 181
  LLVM_INTR_VP_FREM = 182
  LLVM_INTR_VP_FSUB = 183
  LLVM_INTR_VP_FMA = 184
  LLVM_INTR_VP_INTTOPTR = 185
  LLVM_INTR_VP_LSHR = 186
  LLVM_INTR_VP_LOAD = 187
  LLVM_INTR_VP_MERGE = 188
  LLVM_INTR_VP_MUL = 189
  LLVM_INTR_VP_OR = 190
  LLVM_INTR_VP_PTRTOINT = 191
  LLVM_INTR_VP_REDUCE_ADD = 192
  LLVM_INTR_VP_REDUCE_AND = 193
  LLVM_INTR_VP_REDUCE_FADD = 194
  LLVM_INTR_VP_REDUCE_FMAX = 195
  LLVM_INTR_VP_REDUCE_FMIN = 196
  LLVM_INTR_VP_REDUCE_FMUL = 197
  LLVM_INTR_VP_REDUCE_MUL = 198
  LLVM_INTR_VP_REDUCE_OR = 199
  LLVM_INTR_VP_REDUCE_SMAX = 200
  LLVM_INTR_VP_REDUCE_SMIN = 201
  LLVM_INTR_VP_REDUCE_UMAX = 202
  LLVM_INTR_VP_REDUCE_UMIN = 203
  LLVM_INTR_VP_REDUCE_XOR = 204
  LLVM_INTR_VP_SDIV = 205
  LLVM_INTR_VP_SEXT = 206
  LLVM_INTR_VP_SITOFP = 207
  LLVM_INTR_VP_SREM = 208
  LLVM_INTR_VP_SELECT = 209
  LLVM_INTR_VP_SHL = 210
  LLVM_INTR_VP_STORE = 211
  LLVM_INTR_EXPERIMENTAL_VP_STRIDED_LOAD = 212
  LLVM_INTR_EXPERIMENTAL_VP_STRIDED_STORE = 213
  LLVM_INTR_VP_SUB = 214
  LLVM_INTR_VP_TRUNC = 215
  LLVM_INTR_VP_UDIV = 216
  LLVM_INTR_VP_UITOFP = 217
  LLVM_INTR_VP_UREM = 218
  LLVM_INTR_VP_XOR = 219
  LLVM_INTR_VP_ZEXT = 220
  LLVM_INTR_VACOPY = 221
  LLVM_INTR_VAEND = 222
  LLVM_INTR_VASTART = 223
  LLVM_INTR_VAR_ANNOTATION = 224
  LLVM_INTR_MASKED_COMPRESSSTORE = 225
  LLVM_INTR_MASKED_EXPANDLOAD = 226
  LLVM_INTR_MASKED_GATHER = 227
  LLVM_INTR_MASKED_SCATTER = 228
  LLVM_INTR_VECTOR_EXTRACT = 229
  LLVM_INTR_VECTOR_INSERT = 230
  LLVM_INTR_VECTOR_REDUCE_ADD = 231
  LLVM_INTR_VECTOR_REDUCE_AND = 232
  LLVM_INTR_VECTOR_REDUCE_FADD = 233
  LLVM_INTR_VECTOR_REDUCE_FMAX = 234
  LLVM_INTR_VECTOR_REDUCE_FMAXIMUM = 235
  LLVM_INTR_VECTOR_REDUCE_FMIN = 236
  LLVM_INTR_VECTOR_REDUCE_FMINIMUM = 237
  LLVM_INTR_VECTOR_REDUCE_FMUL = 238
  LLVM_INTR_VECTOR_REDUCE_MUL = 239
  LLVM_INTR_VECTOR_REDUCE_OR = 240
  LLVM_INTR_VECTOR_REDUCE_SMAX = 241
  LLVM_INTR_VECTOR_REDUCE_SMIN = 242
  LLVM_INTR_VECTOR_REDUCE_UMAX = 243
  LLVM_INTR_VECTOR_REDUCE_UMIN = 244
  LLVM_INTR_VECTOR_REDUCE_XOR = 245
  LLVM_INTR_VSCALE = 246
  MEMREF_ASSUME_ALIGNMENT = 247
  MEMREF_ATOMIC_RMW = 248
  MEMREF_ATOMIC_YIELD = 249
  MEMREF_COPY = 250
  MEMREF_GENERIC_ATOMIC_RMW = 251
  MEMREF_LOAD = 252
  MEMREF_ALLOC = 253
  MEMREF_ALLOCA = 254
  MEMREF_ALLOCA_SCOPE = 255
  MEMREF_ALLOCA_SCOPE_RETURN = 256
  MEMREF_CAST = 257
  MEMREF_COLLAPSE_SHAPE = 258
  MEMREF_DEALLOC = 259
  MEMREF_DIM = 260
  MEMREF_DMA_START = 261
  MEMREF_DMA_WAIT = 262
  MEMREF_EXPAND_SHAPE = 263
  MEMREF_EXTRACT_ALIGNED_POINTER_AS_INDEX = 264
  MEMREF_EXTRACT_STRIDED_METADATA = 265
  MEMREF_GET_GLOBAL = 266
  MEMREF_GLOBAL = 267
  MEMREF_MEMORY_SPACE_CAST = 268
  MEMREF_PREFETCH = 269
  MEMREF_RANK = 270
  MEMREF_REALLOC = 271
  MEMREF_REINTERPRET_CAST = 272
  MEMREF_RESHAPE = 273
  MEMREF_STORE = 274
  MEMREF_TRANSPOSE = 275
  MEMREF_VIEW = 276
  MEMREF_SUBVIEW = 277
  MEMREF_TENSOR_STORE = 278
  ABI_CALL_ARGS = 279
  ABI_CALL_EXEC = 280
  ABI_CALL = 281
  ABI_CALL_RETS = 282
  ABI_DIRECT = 283
  ABI_EPILOGUE = 284
  ABI_FUNC = 285
  ABI_PROLOGUE = 286
  ABI_RET_DIRECT = 287
  ABI_TODO = 288
  ABI_WRAP_FN = 289
  ABI_YIELD = 290
  LL_BR = 291
  LL_CONCAT = 292
  LL_COND_BR = 293
  LL_COND_SCOPE_RET = 294
  LL_EXTRACT = 295
  LL_INITIALIZE = 296
  LL_INLINE_SCOPE = 297
  LL_FUNC = 298
  LL_GEP = 299
  LL_RETURN = 300
  LL_SCOPE = 301
  LL_SCOPE_RECURSE = 302
  LL_SCOPE_RET = 303
  LL_UNINITIALIZED_VAR = 304
  HL_ACCESS = 305
  HL_ASSIGN_FADD = 306
  HL_FADD = 307
  HL_ASSIGN_ADD = 308
  HL_ADD = 309
  HL_LABELADDR = 310
  HL_ADDRESSOF = 311
  HL_ALIGNOF_EXPR = 312
  HL_ALIGNOF_TYPE = 313
  HL_ASM = 314
  HL_ASSIGN = 315
  HL_ASSIGN_BIN_ASHR = 316
  HL_BIN_ASHR = 317
  HL_ASSIGN_BIN_AND = 318
  HL_BIN_AND = 319
  HL_BIN_COMMA = 320
  HL_BIN_LAND = 321
  HL_BIN_LOR = 322
  HL_ASSIGN_BIN_LSHR = 323
  HL_BIN_LSHR = 324
  HL_ASSIGN_BIN_OR = 325
  HL_BIN_OR = 326
  HL_ASSIGN_BIN_SHL = 327
  HL_BIN_SHL = 328
  HL_ASSIGN_BIN_XOR = 329
  HL_BIN_XOR = 330
  HL_BUILTIN_BITCAST = 331
  HL_CSTYLE_CAST = 332
  HL_CALL = 333
  HL_CLASS = 334
  HL_CMP = 335
  HL_CONST = 336
  HL_BASE = 337
  HL_CXXSTRUCT = 338
  HL_REF = 339
  HL_DEREF = 340
  HL_ASSIGN_FDIV = 341
  HL_FDIV = 342
  HL_ASSIGN_SDIV = 343
  HL_SDIV = 344
  HL_ASSIGN_UDIV = 345
  HL_UDIV = 346
  HL_ENUM_CONST = 347
  HL_ENUM = 348
  HL_ENUMREF = 349
  HL_EXPR = 350
  HL_GNU_EXTENSION = 351
  HL_FCMP = 352
  HL_FIELD = 353
  HL_FUNCREF = 354
  HL_GLOBREF = 355
  HL_BREAK = 356
  HL_CASE = 357
  HL_COND = 358
  HL_COND_YIELD = 359
  HL_CONTINUE = 360
  HL_DEFAULT = 361
  HL_DO = 362
  HL_EMPTY_DECL = 363
  HL_FOR = 364
  HL_FUNC = 365
  HL_GOTO = 366
  HL_IF = 367
  HL_LABEL_DECL = 368
  HL_LABEL = 369
  HL_SKIP = 370
  HL_SWITCH = 371
  HL_TYPE_YIELD = 372
  HL_VALUE_YIELD = 373
  HL_VAR = 374
  HL_WHILE = 375
  HL_IMPLICIT_CAST = 376
  HL_INDIRECT_CALL = 377
  HL_INITLIST = 378
  HL_LNOT = 379
  HL_MINUS = 380
  HL_ASSIGN_FMUL = 381
  HL_FMUL = 382
  HL_ASSIGN_MUL = 383
  HL_MUL = 384
  HL_NOT = 385
  HL_PLUS = 386
  HL_POST_DEC = 387
  HL_POST_INC = 388
  HL_PRE_DEC = 389
  HL_PRE_INC = 390
  HL_PREDEFINED_EXPR = 391
  HL_MEMBER = 392
  HL_ASSIGN_FREM = 393
  HL_FREM = 394
  HL_ASSIGN_SREM = 395
  HL_SREM = 396
  HL_ASSIGN_UREM = 397
  HL_UREM = 398
  HL_RETURN = 399
  HL_SIZEOF_EXPR = 400
  HL_SIZEOF_TYPE = 401
  HL_STMT_EXPR = 402
  HL_STRUCT = 403
  HL_ASSIGN_FSUB = 404
  HL_FSUB = 405
  HL_ASSIGN_SUB = 406
  HL_SUB = 407
  HL_SUBSCRIPT = 408
  HL_THIS = 409
  HL_TRANSLATION_UNIT = 410
  HL_TYPE = 411
  HL_TYPEDEF = 412
  HL_TYPEOF_EXPR = 413
  HL_TYPEOF_TYPE = 414
  HL_UNION = 415
  HL_UNREACHABLE = 416
  CORE_BIN_LAND = 417
  CORE_BIN_LOR = 418
  CORE_IMPLICIT_RETURN = 419
  CORE_LAZY_OP = 420
  CORE_SCOPE = 421
  CORE_SELECT = 422
  UNSUP_DECL = 423
  UNSUP_STMT = 424

class BasicBlockOrder(IntEnum):
  PRE_ORDER = 0
  POST_ORDER = 1

class TypeKind(IntEnum):
  UNKNOWN = 0
  BUILTIN_SHAPED = 1
  BUILTIN_FLOAT = 2
  BUILTIN_B_FLOAT16 = 3
  BUILTIN_COMPLEX = 4
  BUILTIN_FLOAT8_E4_M3_B11_FNUZ = 5
  BUILTIN_FLOAT8_E4_M3_FN = 6
  BUILTIN_FLOAT8_E4_M3_FNUZ = 7
  BUILTIN_FLOAT8_E5_M2 = 8
  BUILTIN_FLOAT8_E5_M2_FNUZ = 9
  BUILTIN_FLOAT16 = 10
  BUILTIN_FLOAT32 = 11
  BUILTIN_FLOAT64 = 12
  BUILTIN_FLOAT80 = 13
  BUILTIN_FLOAT128 = 14
  BUILTIN_FLOAT_TF32 = 15
  BUILTIN_FUNCTION = 16
  BUILTIN_INDEX = 17
  BUILTIN_INTEGER = 18
  BUILTIN_MEM_REF = 19
  BUILTIN_NONE = 20
  BUILTIN_OPAQUE = 21
  BUILTIN_RANKED_TENSOR = 22
  BUILTIN_TUPLE = 23
  BUILTIN_UNRANKED_MEM_REF = 24
  BUILTIN_UNRANKED_TENSOR = 25
  BUILTIN_VECTOR = 26
  LLVM_ARRAY = 27
  LLVM_FIXED_VECTOR = 28
  LLVM_FUNCTION = 29
  LLVM_POINTER = 30
  LLVM_SCALABLE_VECTOR = 31
  LLVM_TARGET_EXT = 32
  HL_ADJUSTED = 33
  HL_ARRAY = 34
  HL_ATTRIBUTED = 35
  HL_B_FLOAT16 = 36
  HL_BOOL = 37
  HL_CHAR = 38
  HL_DECAYED = 39
  HL_DOUBLE = 40
  HL_ELABORATED = 41
  HL_ENUM = 42
  HL_FLOAT128 = 43
  HL_FLOAT = 44
  HL_HALF = 45
  HL_INT128 = 46
  HL_INT = 47
  HL_L_VALUE = 48
  HL_LABEL = 49
  HL_LONG_DOUBLE = 50
  HL_LONG_LONG = 51
  HL_LONG = 52
  HL_PAREN = 53
  HL_POINTER = 54
  HL_R_VALUE = 55
  HL_RECORD = 56
  HL_REFERENCE = 57
  HL_SHORT = 58
  HL_TYPE_OF_EXPR = 59
  HL_TYPE_OF_TYPE = 60
  HL_TYPEDEF = 61
  HL_VOID = 62
  CORE_FUNCTION = 63
  UNSUP_UNSUPPORTED = 64

class Attribute(object):
  kind: multiplier.ir.AttributeKind

class Value(object):
  kind: multiplier.ir.ValueKind
  type: multiplier.ir.Type
  uses: Iterable[multiplier.ir.Operand]

class Argument(multiplier.ir.Value):
  index: int

  @staticmethod
  def static_kind() -> multiplier.ir.ValueKind:
    ...

  @staticmethod
  def FROM(val: multiplier.ir.Value) -> Optional[multiplier.ir.Argument]:
    ...

class Result(multiplier.ir.Value):
  operation: multiplier.ir.Operation
  index: int

  @staticmethod
  def static_kind() -> multiplier.ir.ValueKind:
    ...

  @staticmethod
  def of(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.Result]:
    ...

  @staticmethod
  def FROM(arg_0: multiplier.ir.Value) -> Optional[multiplier.ir.Result]:
    ...

class Block(object):
  num_arguments: int
  arguments: Iterable[multiplier.ir.Argument]
  operations: Iterable[multiplier.ir.Operation]
  reverse_operations: Iterable[multiplier.ir.Operation]
  uses: Iterable[multiplier.ir.Label]
  terminator: multiplier.ir.Operation

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ir.Argument) -> multiplier.ir.Block:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.Block]:
    ...

  def nth_argument(self, arg_0: int) -> Optional[multiplier.ir.Argument]:
    ...

class Label(object):
  operation: multiplier.ir.Operation
  block: multiplier.ir.Block
  index: int

class Operation(multiplier.Entity):
  kind_name: str
  kind: multiplier.ir.OperationKind
  num_operands: int
  operands: Iterable[multiplier.ir.Operand]
  num_results: int
  results: Iterable[multiplier.ir.Result]
  num_regions: int
  regions: Iterable[multiplier.ir.Region]
  only_region: Optional[multiplier.ir.Region]
  only_region_blocks: Iterable[multiplier.ir.Block]
  uses: Iterable[multiplier.ir.Operand]

  @staticmethod
  def classify(arg_0: str) -> multiplier.ir.OperationKind:
    ...

  @overload
  @staticmethod
  def producing(val: multiplier.ir.Result) -> multiplier.ir.Operation:
    ...

  @overload
  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.Operation]:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ir.Region) -> multiplier.ir.Operation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ir.Block) -> multiplier.ir.Operation:
    ...

  @overload
  @staticmethod
  def first_from(that: multiplier.ast.Decl) -> Optional[multiplier.ir.Operation]:
    ...

  @overload
  @staticmethod
  def first_from(that: multiplier.ast.Decl, arg_1: multiplier.ir.OperationKind) -> Optional[multiplier.ir.Operation]:
    ...

  @overload
  @staticmethod
  def first_from(that: multiplier.ast.Stmt) -> Optional[multiplier.ir.Operation]:
    ...

  @overload
  @staticmethod
  def first_from(that: multiplier.ast.Stmt, arg_1: multiplier.ir.OperationKind) -> Optional[multiplier.ir.Operation]:
    ...

  @overload
  @staticmethod
  def all_from(that: multiplier.ast.Decl) -> Iterable[multiplier.ir.Operation]:
    ...

  @overload
  @staticmethod
  def all_from(that: multiplier.ast.Stmt) -> Iterable[multiplier.ir.Operation]:
    ...

  def nth_operand(self, arg_0: int) -> Optional[multiplier.ir.Operand]:
    ...

  def nth_result(self, arg_0: int) -> Optional[multiplier.ir.Result]:
    ...

  def nth_region(self, arg_0: int) -> Optional[multiplier.ir.Region]:
    ...

class Operand(object):
  operation: multiplier.ir.Operation
  index: int
  value: multiplier.ir.Value

class Region(object):
  num_blocks: int
  blocks: Iterable[multiplier.ir.Block]
  reverse_blocks: Iterable[multiplier.ir.Block]
  entry_block: multiplier.ir.Block
  num_entry_block_arguments: int
  entry_block_arguments: Iterable[multiplier.ir.Argument]

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ir.Block) -> multiplier.ir.Region:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.Region]:
    ...

  def nth_block(self, arg_0: int) -> Optional[multiplier.ir.Block]:
    ...

  def nth_entry_block_argument(self, arg_0: int) -> Optional[multiplier.ir.Argument]:
    ...

class Type(object):
  kind: multiplier.ir.TypeKind
