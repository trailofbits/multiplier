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

class MacroKind(IntEnum):
  SUBSTITUTION = 0
  EXPANSION = 1
  ARGUMENT = 2
  PARAMETER = 3
  OTHER_DIRECTIVE = 4
  IF_DIRECTIVE = 5
  IF_DEFINED_DIRECTIVE = 6
  IF_NOT_DEFINED_DIRECTIVE = 7
  ELSE_IF_DIRECTIVE = 8
  ELSE_IF_DEFINED_DIRECTIVE = 9
  ELSE_IF_NOT_DEFINED_DIRECTIVE = 10
  ELSE_DIRECTIVE = 11
  END_IF_DIRECTIVE = 12
  DEFINE_DIRECTIVE = 13
  UNDEFINE_DIRECTIVE = 14
  PRAGMA_DIRECTIVE = 15
  INCLUDE_DIRECTIVE = 16
  INCLUDE_NEXT_DIRECTIVE = 17
  INCLUDE_MACROS_DIRECTIVE = 18
  IMPORT_DIRECTIVE = 19
  PARAMETER_SUBSTITUTION = 20
  STRINGIFY = 21
  CONCATENATE = 22
  VA_OPT = 23
  VA_OPT_ARGUMENT = 24

class TokenTreeNodeKind(IntEnum):
  EMPTY = 0
  TOKEN = 1
  CHOICE = 2
  SUBSTITUTION = 3
  SEQUENCE = 4

class TokenKind(IntEnum):
  UNKNOWN = 0
  END_OF_FILE = 1
  END_OF_DIRECTIVE = 2
  CODE_COMPLETION = 3
  COMMENT = 4
  IDENTIFIER = 5
  WHITESPACE = 6
  NUMERIC_CONSTANT = 7
  CHARACTER_CONSTANT = 8
  WIDE_CHARACTER_CONSTANT = 9
  UTF8_CHARACTER_CONSTANT = 10
  UTF16_CHARACTER_CONSTANT = 11
  UTF32_CHARACTER_CONSTANT = 12
  STRING_LITERAL = 13
  WIDE_STRING_LITERAL = 14
  HEADER_NAME = 15
  UTF8_STRING_LITERAL = 16
  UTF16_STRING_LITERAL = 17
  UTF32_STRING_LITERAL = 18
  L_SQUARE = 19
  R_SQUARE = 20
  L_PARENTHESIS = 21
  R_PARENTHESIS = 22
  L_BRACE = 23
  R_BRACE = 24
  PERIOD = 25
  ELLIPSIS = 26
  AMP = 27
  AMP_AMP = 28
  AMP_EQUAL = 29
  STAR = 30
  STAR_EQUAL = 31
  PLUS = 32
  PLUS_PLUS = 33
  PLUS_EQUAL = 34
  MINUS = 35
  ARROW = 36
  MINUS_MINUS = 37
  MINUS_EQUAL = 38
  TILDE = 39
  EXCLAIM = 40
  EXCLAIM_EQUAL = 41
  SLASH = 42
  SLASH_EQUAL = 43
  PERCENT = 44
  PERCENT_EQUAL = 45
  LESS = 46
  LESS_LESS = 47
  LESS_EQUAL = 48
  LESS_LESS_EQUAL = 49
  SPACESHIP = 50
  GREATER = 51
  GREATER_GREATER = 52
  GREATER_EQUAL = 53
  GREATER_GREATER_EQUAL = 54
  CARET = 55
  CARET_EQUAL = 56
  PIPE = 57
  PIPE_PIPE = 58
  PIPE_EQUAL = 59
  QUESTION = 60
  COLON = 61
  SEMI = 62
  EQUAL = 63
  EQUAL_EQUAL = 64
  COMMA = 65
  HASH = 66
  HASH_HASH = 67
  HASH_AT = 68
  PERIOD_STAR = 69
  ARROW_STAR = 70
  COLON_COLON = 71
  AT = 72
  LESS_LESS_LESS = 73
  GREATER_GREATER_GREATER = 74
  CARETCARET = 75
  KEYWORD_AUTO = 76
  KEYWORD_BREAK = 77
  KEYWORD_CASE = 78
  KEYWORD_CHARACTER = 79
  KEYWORD_CONST = 80
  KEYWORD_CONTINUE = 81
  KEYWORD_DEFAULT = 82
  KEYWORD_DO = 83
  KEYWORD_DOUBLE = 84
  KEYWORD_ELSE = 85
  KEYWORD_ENUM = 86
  KEYWORD_EXTERN = 87
  KEYWORD_FLOAT = 88
  KEYWORD_FOR = 89
  KEYWORD_GOTO = 90
  KEYWORD_IF = 91
  KEYWORD_INT = 92
  KEYWORD__EXT_INT = 93
  KEYWORD__BIT_INT = 94
  KEYWORD_LONG = 95
  KEYWORD_REGISTER = 96
  KEYWORD_RETURN = 97
  KEYWORD_SHORT = 98
  KEYWORD_SIGNED = 99
  KEYWORD_SIZEOF = 100
  KEYWORD___DATASIZEOF = 101
  KEYWORD_STATIC = 102
  KEYWORD_STRUCT = 103
  KEYWORD_SWITCH = 104
  KEYWORD_TYPEDEF = 105
  KEYWORD_UNION = 106
  KEYWORD_UNSIGNED = 107
  KEYWORD_VOID = 108
  KEYWORD_VOLATILE = 109
  KEYWORD_WHILE = 110
  KEYWORD__ALIGNAS = 111
  KEYWORD__ALIGNOF = 112
  KEYWORD__ATOMIC = 113
  KEYWORD__BOOLEAN = 114
  KEYWORD__COMPLEX = 115
  KEYWORD__GENERIC = 116
  KEYWORD__IMAGINARY = 117
  KEYWORD__NORETURN = 118
  KEYWORD__STATIC_ASSERT = 119
  KEYWORD__THREAD_LOCAL = 120
  KEYWORD___FUNC__ = 121
  KEYWORD___OBJC_YES = 122
  KEYWORD___OBJC_NO = 123
  KEYWORD_ASSEMBLY = 124
  KEYWORD_BOOLEAN = 125
  KEYWORD_CATCH = 126
  KEYWORD_CLASS = 127
  KEYWORD_CONST_CAST = 128
  KEYWORD_DELETE = 129
  KEYWORD_DYNAMIC_CAST = 130
  KEYWORD_EXPLICIT = 131
  KEYWORD_EXPORT = 132
  KEYWORD_FALSE = 133
  KEYWORD_FRIEND = 134
  KEYWORD_MUTABLE = 135
  KEYWORD_NAMESPACE = 136
  KEYWORD_NEW = 137
  KEYWORD_OPERATOR = 138
  KEYWORD_PRIVATE = 139
  KEYWORD_PROTECTED = 140
  KEYWORD_PUBLIC = 141
  KEYWORD_REINTERPRET_CAST = 142
  KEYWORD_STATIC_CAST = 143
  KEYWORD_TEMPLATE = 144
  KEYWORD_THIS = 145
  KEYWORD_THROW = 146
  KEYWORD_TRUE = 147
  KEYWORD_TRY = 148
  KEYWORD_TYPENAME = 149
  KEYWORD_TYPEID = 150
  KEYWORD_USING = 151
  KEYWORD_VIRTUAL = 152
  KEYWORD_WCHAR_T = 153
  KEYWORD_RESTRICT = 154
  KEYWORD_INLINE = 155
  KEYWORD_ALIGNAS = 156
  KEYWORD_ALIGNOF = 157
  KEYWORD_CHAR16_T = 158
  KEYWORD_CHAR32_T = 159
  KEYWORD_CONSTEXPR = 160
  KEYWORD_DECLTYPE = 161
  KEYWORD_NOEXCEPT = 162
  KEYWORD_NULLPTR = 163
  KEYWORD_STATIC_ASSERT = 164
  KEYWORD_THREAD_LOCAL = 165
  KEYWORD_CO_AWAIT = 166
  KEYWORD_CO_RETURN = 167
  KEYWORD_CO_YIELD = 168
  KEYWORD_MODULE = 169
  KEYWORD_IMPORT = 170
  KEYWORD_CONSTEVAL = 171
  KEYWORD_CONSTINIT = 172
  KEYWORD_CONCEPT = 173
  KEYWORD_REQUIRES = 174
  KEYWORD_CHAR8_T = 175
  KEYWORD__FLOAT16 = 176
  KEYWORD_TYPEOF = 177
  KEYWORD_TYPEOF_UNQUALIFIED = 178
  KEYWORD__ACCUM = 179
  KEYWORD__FRACT = 180
  KEYWORD__SAT = 181
  KEYWORD__DECIMAL32 = 182
  KEYWORD__DECIMAL64 = 183
  KEYWORD__DECIMAL128 = 184
  KEYWORD___NULL = 185
  KEYWORD___ALIGNOF = 186
  KEYWORD___ATTRIBUTE = 187
  KEYWORD___BUILTIN_CHOOSE_EXPRESSION = 188
  KEYWORD___BUILTIN_OFFSETOF = 189
  KEYWORD___BUILTIN_FILE = 190
  KEYWORD___BUILTIN_FILENAME = 191
  KEYWORD___BUILTIN_FUNCTION = 192
  KEYWORD___BUILTIN_FUNCSIG = 193
  KEYWORD___BUILTIN_LINE = 194
  KEYWORD___BUILTIN_COLUMN = 195
  KEYWORD___BUILTIN_SOURCE_TOKEN = 196
  KEYWORD___BUILTIN_TYPES_COMPATIBLE_P = 197
  KEYWORD___BUILTIN_VA_ARGUMENT = 198
  KEYWORD___EXTENSION__ = 199
  KEYWORD___FLOAT128 = 200
  KEYWORD___IBM128 = 201
  KEYWORD___IMAG = 202
  KEYWORD___INT128 = 203
  KEYWORD___LABEL__ = 204
  KEYWORD___REAL = 205
  KEYWORD___THREAD = 206
  KEYWORD___FUNCTION__ = 207
  KEYWORD___PRETTYFUNCTION__ = 208
  KEYWORD___AUTO_TYPE = 209
  KEYWORD___FUNCDNAME__ = 210
  KEYWORD___FUNCSIG__ = 211
  KEYWORD_LFUNCTION__ = 212
  KEYWORD_LFUNCSIG__ = 213
  KEYWORD___IS_INTERFACE_CLASS = 214
  KEYWORD___IS_SEALED = 215
  KEYWORD___IS_DESTRUCTIBLE = 216
  KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE = 217
  KEYWORD___IS_NOTHROW_DESTRUCTIBLE = 218
  KEYWORD___IS_NOTHROW_ASSIGNABLE = 219
  KEYWORD___IS_CONSTRUCTIBLE = 220
  KEYWORD___IS_NOTHROW_CONSTRUCTIBLE = 221
  KEYWORD___IS_ASSIGNABLE = 222
  KEYWORD___HAS_NOTHROW_MOVE_ASSIGN = 223
  KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN = 224
  KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR = 225
  KEYWORD___HAS_NOTHROW_ASSIGN = 226
  KEYWORD___HAS_NOTHROW_COPY = 227
  KEYWORD___HAS_NOTHROW_CONSTRUCTOR = 228
  KEYWORD___HAS_TRIVIAL_ASSIGN = 229
  KEYWORD___HAS_TRIVIAL_COPY = 230
  KEYWORD___HAS_TRIVIAL_CONSTRUCTOR = 231
  KEYWORD___HAS_TRIVIAL_DESTRUCTOR = 232
  KEYWORD___HAS_VIRTUAL_DESTRUCTOR = 233
  KEYWORD___IS_ABSTRACT = 234
  KEYWORD___IS_AGGREGATE = 235
  KEYWORD___IS_BASE_OF = 236
  KEYWORD___IS_CLASS = 237
  KEYWORD___IS_CONVERTIBLE_TO = 238
  KEYWORD___IS_EMPTY = 239
  KEYWORD___IS_ENUM = 240
  KEYWORD___IS_FINAL = 241
  KEYWORD___IS_LITERAL = 242
  KEYWORD___IS_POD = 243
  KEYWORD___IS_POLYMORPHIC = 244
  KEYWORD___IS_STANDARD_LAYOUT = 245
  KEYWORD___IS_TRIVIAL = 246
  KEYWORD___IS_TRIVIALLY_ASSIGNABLE = 247
  KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE = 248
  KEYWORD___IS_TRIVIALLY_COPYABLE = 249
  KEYWORD___IS_UNION = 250
  KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS = 251
  KEYWORD___ADD_LVALUE_REFERENCE = 252
  KEYWORD___ADD_POINTER = 253
  KEYWORD___ADD_RVALUE_REFERENCE = 254
  KEYWORD___DECAY = 255
  KEYWORD___MAKE_SIGNED = 256
  KEYWORD___MAKE_UNSIGNED = 257
  KEYWORD___REMOVE_ALL_EXTENTS = 258
  KEYWORD___REMOVE_CONST = 259
  KEYWORD___REMOVE_CV = 260
  KEYWORD___REMOVE_CVREF = 261
  KEYWORD___REMOVE_EXTENT = 262
  KEYWORD___REMOVE_POINTER = 263
  KEYWORD___REMOVE_REFERENCE_T = 264
  KEYWORD___REMOVE_RESTRICT = 265
  KEYWORD___REMOVE_VOLATILE = 266
  KEYWORD___UNDERLYING_TYPE = 267
  KEYWORD___IS_TRIVIALLY_RELOCATABLE = 268
  KEYWORD___IS_TRIVIALLY_EQUALITY_COMPARABLE = 269
  KEYWORD___IS_BOUNDED_ARRAY = 270
  KEYWORD___IS_UNBOUNDED_ARRAY = 271
  KEYWORD___IS_NULLPTR = 272
  KEYWORD___IS_SCOPED_ENUM = 273
  KEYWORD___IS_REFERENCEABLE = 274
  KEYWORD___CAN_PASS_IN_REGS = 275
  KEYWORD___REFERENCE_BINDS_TO_TEMPORARY = 276
  KEYWORD___REFERENCE_CONSTRUCTS_FROM_TEMPORARY = 277
  KEYWORD___IS_LVALUE_EXPRESSION = 278
  KEYWORD___IS_RVALUE_EXPRESSION = 279
  KEYWORD___IS_ARITHMETIC = 280
  KEYWORD___IS_FLOATING_POINT = 281
  KEYWORD___IS_INTEGRAL = 282
  KEYWORD___IS_COMPLETE_TYPE = 283
  KEYWORD___IS_VOID = 284
  KEYWORD___IS_ARRAY = 285
  KEYWORD___IS_FUNCTION = 286
  KEYWORD___IS_REFERENCE = 287
  KEYWORD___IS_LVALUE_REFERENCE = 288
  KEYWORD___IS_RVALUE_REFERENCE = 289
  KEYWORD___IS_FUNDAMENTAL = 290
  KEYWORD___IS_OBJECT = 291
  KEYWORD___IS_SCALAR = 292
  KEYWORD___IS_COMPOUND = 293
  KEYWORD___IS_POINTER = 294
  KEYWORD___IS_MEMBER_OBJECT_POINTER = 295
  KEYWORD___IS_MEMBER_FUNCTION_POINTER = 296
  KEYWORD___IS_MEMBER_POINTER = 297
  KEYWORD___IS_CONST = 298
  KEYWORD___IS_VOLATILE = 299
  KEYWORD___IS_SIGNED = 300
  KEYWORD___IS_UNSIGNED = 301
  KEYWORD___IS_SAME = 302
  KEYWORD___IS_CONVERTIBLE = 303
  KEYWORD___ARRAY_RANK = 304
  KEYWORD___ARRAY_EXTENT = 305
  KEYWORD___PRIVATE_EXTERN__ = 306
  KEYWORD___MODULE_PRIVATE__ = 307
  KEYWORD___BUILTIN_PTRAUTH_TYPE_DISCRIMINATOR = 308
  KEYWORD___BUILTIN_XNU_TYPE_SIGNATURE = 309
  KEYWORD___BUILTIN_XNU_TYPE_SUMMARY = 310
  KEYWORD___BUILTIN_TMO_TYPE_METADATA = 311
  KEYWORD___BUILTIN_XNU_TYPES_COMPATIBLE = 312
  KEYWORD___DECLSPEC = 313
  KEYWORD___CDECL = 314
  KEYWORD___STDCALL = 315
  KEYWORD___FASTCALL = 316
  KEYWORD___THISCALL = 317
  KEYWORD___REGCALL = 318
  KEYWORD___VECTORCALL = 319
  KEYWORD___FORCEINLINE = 320
  KEYWORD___UNALIGNED = 321
  KEYWORD___SUPER = 322
  KEYWORD___GLOBAL = 323
  KEYWORD___LOCAL = 324
  KEYWORD___CONSTANT = 325
  KEYWORD___PRIVATE = 326
  KEYWORD___GENERIC = 327
  KEYWORD___KERNEL = 328
  KEYWORD___READ_ONLY = 329
  KEYWORD___WRITE_ONLY = 330
  KEYWORD___READ_WRITE = 331
  KEYWORD___BUILTIN_ASTYPE = 332
  KEYWORD_VEC_STEP = 333
  KEYWORD_IMAGE_1D_T = 334
  KEYWORD_IMAGE_1D_ARRAY_T = 335
  KEYWORD_IMAGE_1D_BUFFER_T = 336
  KEYWORD_IMAGE_2D_T = 337
  KEYWORD_IMAGE_2D_ARRAY_T = 338
  KEYWORD_IMAGE_2D_DEPTH_T = 339
  KEYWORD_IMAGE_2D_ARRAY_DEPTH_T = 340
  KEYWORD_IMAGE_2D_MSAA_T = 341
  KEYWORD_IMAGE_2D_ARRAY_MSAA_T = 342
  KEYWORD_IMAGE_2D_MSAA_DEPTH_T = 343
  KEYWORD_IMAGE_2D_ARRAY_MSAA_DEPTH_T = 344
  KEYWORD_IMAGE_3D_T = 345
  KEYWORD_PIPE = 346
  KEYWORD_ADDRSPACE_CAST = 347
  KEYWORD___NOINLINE__ = 348
  KEYWORD_CBUFFER = 349
  KEYWORD_TBUFFER = 350
  KEYWORD_GROUPSHARED = 351
  KEYWORD_IN = 352
  KEYWORD_INOUT = 353
  KEYWORD_OUT = 354
  KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN = 355
  KEYWORD___PASCAL = 356
  KEYWORD___VECTOR = 357
  KEYWORD___PIXEL = 358
  KEYWORD___BOOLEAN = 359
  KEYWORD___BF16 = 360
  KEYWORD_HALF = 361
  KEYWORD___BRIDGE = 362
  KEYWORD___BRIDGE_TRANSFER = 363
  KEYWORD___BRIDGE_RETAINED = 364
  KEYWORD___BRIDGE_RETAIN = 365
  KEYWORD___COVARIANT = 366
  KEYWORD___CONTRAVARIANT = 367
  KEYWORD___KINDOF = 368
  KEYWORD__NONNULL = 369
  KEYWORD__NULLABLE = 370
  KEYWORD__NULLABLE_RESULT = 371
  KEYWORD__NULL_UNSPECIFIED = 372
  KEYWORD___FUNCREF = 373
  KEYWORD___PTR64 = 374
  KEYWORD___PTR32 = 375
  KEYWORD___SPTR = 376
  KEYWORD___UPTR = 377
  KEYWORD___W64 = 378
  KEYWORD___UUIDOF = 379
  KEYWORD___TRY = 380
  KEYWORD___FINALLY = 381
  KEYWORD___LEAVE = 382
  KEYWORD___INT64 = 383
  KEYWORD___IF_EXISTS = 384
  KEYWORD___IF_NOT_EXISTS = 385
  KEYWORD___SINGLE_INHERITANCE = 386
  KEYWORD___MULTIPLE_INHERITANCE = 387
  KEYWORD___VIRTUAL_INHERITANCE = 388
  KEYWORD___INTERFACE = 389
  KEYWORD___BUILTIN_CONVERTVECTOR = 390
  KEYWORD___BUILTIN_VECTORELEMENTS = 391
  KEYWORD___BUILTIN_BIT_CAST = 392
  KEYWORD___BUILTIN_AVAILABLE = 393
  KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME = 394
  KEYWORD___ARM_IN = 395
  KEYWORD___ARM_INOUT = 396
  KEYWORD___ARM_LOCALLY_STREAMING = 397
  KEYWORD___ARM_NEW = 398
  KEYWORD___ARM_OUT = 399
  KEYWORD___ARM_PRESERVES = 400
  KEYWORD___ARM_STREAMING = 401
  KEYWORD___ARM_STREAMING_COMPATIBLE = 402
  KEYWORD___UNKNOWN_ANYTYPE = 403
  ANNOT_CXXSCOPE = 404
  ANNOT_TYPENAME = 405
  ANNOT_TEMPLATE_ID = 406
  ANNOT_NON_TYPE = 407
  ANNOT_NON_TYPE_UNDECLARED = 408
  ANNOT_NON_TYPE_DEPENDENT = 409
  ANNOT_OVERLOAD = 410
  ANNOT_PRIMARY_EXPRESSION = 411
  ANNOT_DECLTYPE = 412
  ANNOT_PRAGMA_UNUSED = 413
  ANNOT_PRAGMA_VIS = 414
  ANNOT_PRAGMA_PACK = 415
  ANNOT_PRAGMA_PARSER_CRASH = 416
  ANNOT_PRAGMA_CAPTURED = 417
  ANNOT_PRAGMA_DUMP = 418
  ANNOT_PRAGMA_MSSTRUCT = 419
  ANNOT_PRAGMA_ALIGN = 420
  ANNOT_PRAGMA_WEAK = 421
  ANNOT_PRAGMA_WEAKALIAS = 422
  ANNOT_PRAGMA_REDEFINE_EXTNAME = 423
  ANNOT_PRAGMA_FP_CONTRACT = 424
  ANNOT_PRAGMA_FENV_ACCESS = 425
  ANNOT_PRAGMA_FENV_ACCESS_MS = 426
  ANNOT_PRAGMA_FENV_ROUND = 427
  ANNOT_PRAGMA_CX_LIMITED_RANGE = 428
  ANNOT_PRAGMA_FLOAT_CONTROL = 429
  ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS = 430
  ANNOT_PRAGMA_MS_VTORDISP = 431
  ANNOT_PRAGMA_MS_PRAGMA = 432
  ANNOT_PRAGMA_OPENCL_EXTENSION = 433
  ANNOT_ATTRIBUTE_OPENMP = 434
  ANNOT_PRAGMA_OPENMP = 435
  ANNOT_PRAGMA_OPENMP_END = 436
  ANNOT_PRAGMA_OPENACC = 437
  ANNOT_PRAGMA_OPENACC_END = 438
  ANNOT_PRAGMA_LOOP_HINT = 439
  ANNOT_PRAGMA_FP = 440
  ANNOT_PRAGMA_ATTRIBUTE = 441
  ANNOT_PRAGMA_RISCV = 442
  ANNOT_MODULE_INCLUDE = 443
  ANNOT_MODULE_BEGIN = 444
  ANNOT_MODULE_END = 445
  ANNOT_HEADER_UNIT = 446
  ANNOT_REPL_INPUT_END = 447
  L_ANGLE = 448
  R_ANGLE = 449
  PP_IF = 450
  PP_IFDEF = 451
  PP_IFNDEF = 452
  PP_ELIF = 453
  PP_ELIFDEF = 454
  PP_ELIFNDEF = 455
  PP_ELSE = 456
  PP_ENDIF = 457
  PP_DEFINED = 458
  PP_INCLUDE = 459
  PP___INCLUDE_MACROS = 460
  PP_DEFINE = 461
  PP_UNDEF = 462
  PP_LINE = 463
  PP_ERROR = 464
  PP_PRAGMA = 465
  PP_IMPORT = 466
  PP_INCLUDE_NEXT = 467
  PP_WARNING = 468
  PP_IDENTIFIER = 469
  PP_SCCS = 470
  PP_ASSERT = 471
  PP_UNASSERT = 472
  PP___PUBLIC_MACRO = 473
  PP___PRIVATE_MACRO = 474
  OBJC_AT_CLASS = 475
  OBJC_AT_COMPATIBILITY_ALIAS = 476
  OBJC_AT_DEFINITIONS = 477
  OBJC_AT_ENCODE = 478
  OBJC_AT_OBJC_END = 479
  OBJC_AT_IMPLEMENTATION = 480
  OBJC_AT_INTERFACE = 481
  OBJC_AT_PRIVATE = 482
  OBJC_AT_PROTECTED = 483
  OBJC_AT_PROTOCOL = 484
  OBJC_AT_PUBLIC = 485
  OBJC_AT_SELECTOR = 486
  OBJC_AT_THROW = 487
  OBJC_AT_TRY = 488
  OBJC_AT_CATCH = 489
  OBJC_AT_FINALLY = 490
  OBJC_AT_SYNCHRONIZED = 491
  OBJC_AT_AUTORELEASEPOOL = 492
  OBJC_AT_PROPERTY = 493
  OBJC_AT_PACKAGE = 494
  OBJC_AT_REQUIRED = 495
  OBJC_AT_OPTIONAL = 496
  OBJC_AT_SYNTHESIZE = 497
  OBJC_AT_DYNAMIC = 498
  OBJC_AT_IMPORT = 499
  OBJC_AT_AVAILABLE = 500

class PathKind(IntEnum):
  UNIX = 0
  WINDOWS = 1

class FileType(IntEnum):
  NONE = 0
  NOT_FOUND = 1
  REGULAR = 2
  DIRECTORY = 3
  SYMBOLIC_LINK = 4
  BLOCK = 5
  CHARACTER = 6
  FIRST_IN_FIRST_OUT = 7
  SOCKET = 8
  KNKNOWN = 9

class CompilerName(IntEnum):
  UNKNOWN = 0
  CLANG = 1
  APPLE_CLANG = 2
  CLANG_CL = 3
  CL = 4
  GNU = 5

class IncludePathLocation(IntEnum):
  ABSOLUTE = 0
  SYSROOT_RELATIVE = 1

class TargetLanguage(IntEnum):
  C = 0
  CXX = 1

class TokenCategory(IntEnum):
  UNKNOWN = 0
  IDENTIFIER = 1
  MACRO_NAME = 2
  MACRO_PARAMETER_NAME = 3
  MACRO_DIRECTIVE_NAME = 4
  KEYWORD = 5
  OBJECTIVE_C_KEYWORD = 6
  BUILTIN_TYPE_NAME = 7
  PUNCTUATION = 8
  LITERAL = 9
  COMMENT = 10
  LOCAL_VARIABLE = 11
  GLOBAL_VARIABLE = 12
  PARAMETER_VARIABLE = 13
  FUNCTION = 14
  INSTANCE_METHOD = 15
  INSTANCE_MEMBER = 16
  CLASS_METHOD = 17
  CLASS_MEMBER = 18
  THIS = 19
  CLASS = 20
  STRUCT = 21
  UNION = 22
  CONCEPT = 23
  INTERFACE = 24
  ENUM = 25
  ENUMERATOR = 26
  NAMESPACE = 27
  TYPE_ALIAS = 28
  TEMPLATE_PARAMETER_TYPE = 29
  TEMPLATE_PARAMETER_VALUE = 30
  LABEL = 31
  WHITESPACE = 32
  FILE_NAME = 33
  LINE_NUMBER = 34
  COLUMN_NUMBER = 35
  INFORMATION = 36
  WARNING = 37
  ERROR = 38

class TokenContext(object):
  entity_id: int
  has_parent: bool
  is_alias: bool
  index_in_fragment: int
  as_declaration: Optional[multiplier.ast.Decl]
  as_statement: Optional[multiplier.ast.Stmt]
  as_attribute: Optional[multiplier.ast.Attr]
  as_macro: Optional[multiplier.frontend.Macro]
  as_type: Optional[multiplier.ast.Type]
  as_template_argument: Optional[multiplier.ast.TemplateArgument]
  as_template_parameter_list: Optional[multiplier.ast.TemplateParameterList]
  as_cxx_base_specifier: Optional[multiplier.ast.CXXBaseSpecifier]
  as_designator: Optional[multiplier.ast.Designator]
  as_cxx_ctor_initializer: Optional[multiplier.ast.CXXCtorInitializer]
  aliasee: Optional[multiplier.frontend.TokenContext]
  parent: Optional[multiplier.frontend.TokenContext]

class Compilation(multiplier.Entity):
  ir: Optional[multiplier.ir.builtin.ModuleOp]
  fragments: Iterable[multiplier.Fragment]
  files: Iterable[multiplier.frontend.File]
  main_source_file: multiplier.frontend.File
  main_source_file_path: pathlib.PurePath
  compiler_executable_path: pathlib.PurePath
  compiler_installation_directory: pathlib.PurePath
  working_directory: pathlib.PurePath
  system_root_directory: pathlib.PurePath
  system_root_directory_include_path: pathlib.PurePath
  resource_directory: pathlib.PurePath
  target_triple: str
  auxiliary_target_triple: Optional[str]
  arguments: Iterable[str]
  system_include_directories: Iterable[Tuple[multiplier.frontend.IncludePathLocation, pathlib.PurePath]]
  user_include_directories: Iterable[Tuple[multiplier.frontend.IncludePathLocation, pathlib.PurePath]]
  framework_directories: Iterable[Tuple[multiplier.frontend.IncludePathLocation, pathlib.PurePath]]

  @overload
  @staticmethod
  def containing(arg_0: multiplier.Fragment) -> multiplier.frontend.Compilation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: Optional[multiplier.Fragment]) -> Optional[multiplier.frontend.Compilation]:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.Decl) -> multiplier.frontend.Compilation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.Stmt) -> multiplier.frontend.Compilation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.Attr) -> multiplier.frontend.Compilation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.TemplateArgument) -> multiplier.frontend.Compilation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.TemplateParameterList) -> multiplier.frontend.Compilation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.CXXBaseSpecifier) -> multiplier.frontend.Compilation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.CXXCtorInitializer) -> multiplier.frontend.Compilation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.Designator) -> multiplier.frontend.Compilation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.frontend.Token) -> Optional[multiplier.frontend.Compilation]:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.frontend.Macro) -> multiplier.frontend.Compilation:
    ...

  @overload
  @staticmethod
  def containing(arg_0: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.Compilation]:
    ...

  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.Compilation]:
    ...

class Token(multiplier.Entity):
  kind: multiplier.frontend.TokenKind
  data: str
  context: Optional[multiplier.frontend.TokenContext]
  parsed_token: multiplier.frontend.Token
  derived_token: multiplier.frontend.Token
  file_token: multiplier.frontend.Token
  nearest_file_token: multiplier.frontend.Token
  related_entity: multiplier.Entity
  related_entity_id: int
  category: multiplier.frontend.TokenCategory
  containing_macro: Optional[multiplier.frontend.Macro]

  @staticmethod
  def FROM(entity: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.Token]:
    ...

  @staticmethod
  def entity_category() -> multiplier.EntityCategory:
    ...

  @staticmethod
  def categorize(entity: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> multiplier.frontend.TokenCategory:
    ...

  def location(self, arg_0: multiplier.frontend.FileLocationCache) -> Optional[Tuple[int, int]]:
    ...

  def next_location(self, arg_0: multiplier.frontend.FileLocationCache) -> Optional[Tuple[int, int]]:
    ...

  def nearest_location(self, cache: multiplier.frontend.FileLocationCache) -> Optional[Tuple[int, int]]:
    ...

  def __bool__(self) -> bool:
    ...

class TokenRange(object, Sequence[Token], Iterable[Token]):
  empty: bool
  size: int
  front: multiplier.frontend.Token
  back: multiplier.frontend.Token
  data: str
  file_tokens: multiplier.frontend.TokenRange
  strip_whitespace: multiplier.frontend.TokenRange

  @staticmethod
  def create(tokens: Sequence[multiplier.frontend.UserToken | multiplier.frontend.Token]) -> multiplier.frontend.TokenRange:
    ...

  def slice(self, start_index: int, end_index: int) -> multiplier.frontend.TokenRange:
    ...

  def index_of(self, that: multiplier.frontend.Token) -> Optional[int]:
    ...

  def __bool__(self) -> bool:
    ...

  def __getitem__(self, index: int) -> Token:
    ...

  def __iter__(self) -> Iterable[Token]:
    ...

class RegexQueryMatch(multiplier.frontend.TokenRange):
  data: str
  captured_variables: Sequence[str]
  num_captures: int

  def index_of_captured_variable(self, var: str) -> Optional[int]:
    ...

  @overload
  def captured_tokens(self, var: str) -> Optional[multiplier.frontend.TokenRange]:
    ...

  @overload
  def captured_tokens(self, catpture_index: int) -> Optional[multiplier.frontend.TokenRange]:
    ...

  @overload
  def captured_data(self, var: str) -> Optional[str]:
    ...

  @overload
  def captured_data(self, capture_index: int) -> Optional[str]:
    ...

class File(multiplier.Entity):
  fragments: Iterable[multiplier.Fragment]
  paths: Iterable[pathlib.PurePath]
  fragment_ids: FragmentIdList
  tokens: multiplier.frontend.TokenRange
  data: str

  @overload
  @staticmethod
  def containing(match: multiplier.frontend.RegexQueryMatch) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(file: multiplier.frontend.File) -> multiplier.frontend.File:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.Fragment) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.Decl) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.Stmt) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.Attr) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.frontend.Macro) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.TemplateArgument) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.TemplateParameterList) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.CXXBaseSpecifier) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.Designator) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.CXXCtorInitializer) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ir.Operation) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(tokens: multiplier.frontend.TokenRange) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(tokens: multiplier.frontend.TokenTree) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  @staticmethod
  def containing(arg_0: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.File]:
    ...

  @staticmethod
  def FROM(arg_0: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.File]:
    ...

  @staticmethod
  def entity_category() -> multiplier.EntityCategory:
    ...

  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.File]:
    ...

class Macro(multiplier.Entity):
  root: multiplier.frontend.Macro
  use_tokens: multiplier.frontend.TokenRange
  generate_use_tokens: Iterable[multiplier.frontend.Token]
  expansion_tokens: multiplier.frontend.TokenRange
  generate_expansion_tokens: Iterable[multiplier.frontend.Token]
  kind: multiplier.frontend.MacroKind
  parent: Optional[multiplier.frontend.Macro]
  children: Iterable[multiplier.frontend.Macro | multiplier.frontend.Token | multiplier.Fragment]

  @staticmethod
  def static_category() -> multiplier.EntityCategory:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index, kinds: Sequence[multiplier.frontend.MacroKind]) -> Iterable[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment, kinds: Sequence[multiplier.frontend.MacroKind]) -> Iterable[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File, kinds: Sequence[multiplier.frontend.MacroKind]) -> Iterable[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.Macro]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def FROM(self: multiplier.frontend.Macro) -> Optional[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def FROM(self: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.Macro]:
    ...

class MacroSubstitution(multiplier.frontend.Macro):
  replacement_children: Iterable[multiplier.frontend.Macro | multiplier.frontend.Token | multiplier.Fragment]
  first_fully_substituted_token: multiplier.frontend.Token
  last_fully_substituted_token: multiplier.frontend.Token
  name_or_operator: multiplier.frontend.Token

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.MacroSubstitution]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroSubstitution]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.MacroSubstitution]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroSubstitution]:
    ...

class MacroConcatenate(multiplier.frontend.MacroSubstitution):
  pasted_token: multiplier.frontend.Token

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.MacroConcatenate]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroConcatenate]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.MacroConcatenate]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroConcatenate]:
    ...

class MacroStringify(multiplier.frontend.MacroSubstitution):
  stringified_token: multiplier.frontend.Token

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.MacroStringify]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroStringify]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.MacroStringify]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroStringify]:
    ...

class MacroExpansion(multiplier.frontend.MacroSubstitution):
  intermediate_children: Iterable[multiplier.frontend.Macro | multiplier.frontend.Token | multiplier.Fragment]
  definition: Optional[multiplier.frontend.DefineMacroDirective]
  num_arguments: int
  arguments: Iterable[multiplier.frontend.MacroArgument]

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.MacroExpansion]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroExpansion]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.MacroExpansion]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroExpansion]:
    ...

  def nth_argument(self, n: int) -> Optional[multiplier.frontend.MacroArgument]:
    ...

class MacroParameterSubstitution(multiplier.frontend.MacroSubstitution):
  parameter: multiplier.frontend.MacroParameter
  parameter_use: multiplier.frontend.Token

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroParameterSubstitution]:
    ...

class MacroVAOpt(multiplier.frontend.Macro):
  contents_are_elided: bool

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.MacroVAOpt]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroVAOpt]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.MacroVAOpt]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroVAOpt]:
    ...

class MacroVAOptArgument(multiplier.frontend.Macro):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.MacroVAOptArgument]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroVAOptArgument]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.MacroVAOptArgument]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroVAOptArgument]:
    ...

class MacroArgument(multiplier.frontend.Macro):
  is_variadic: bool
  index: int

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.MacroArgument]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroArgument]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.MacroArgument]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroArgument]:
    ...

class MacroParameter(multiplier.frontend.Macro):
  variadic_dots: multiplier.frontend.Token
  name: multiplier.frontend.Token
  index: int

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.MacroParameter]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroParameter]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.MacroParameter]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroParameter]:
    ...

class MacroDirective(multiplier.frontend.Macro):
  hash: multiplier.frontend.Token
  directive_name: multiplier.frontend.Token

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.MacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.MacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroDirective]:
    ...

class DefineMacroDirective(multiplier.frontend.MacroDirective):
  name: multiplier.frontend.Token
  body: Iterable[multiplier.frontend.Macro | multiplier.frontend.Token | multiplier.Fragment]
  is_variadic: bool
  is_function_like: bool
  parameters: Iterable[multiplier.frontend.Macro | multiplier.frontend.Token | multiplier.Fragment]

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.DefineMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.DefineMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.DefineMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.DefineMacroDirective]:
    ...

class PragmaMacroDirective(multiplier.frontend.MacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.PragmaMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.PragmaMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.PragmaMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.PragmaMacroDirective]:
    ...

class UndefineMacroDirective(multiplier.frontend.MacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.UndefineMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.UndefineMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.UndefineMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.UndefineMacroDirective]:
    ...

class OtherMacroDirective(multiplier.frontend.MacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.OtherMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.OtherMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.OtherMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.OtherMacroDirective]:
    ...

class ConditionalMacroDirective(multiplier.frontend.MacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ConditionalMacroDirective]:
    ...

class EndIfMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.EndIfMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.EndIfMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.EndIfMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.EndIfMacroDirective]:
    ...

class ElseMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.ElseMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ElseMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.ElseMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ElseMacroDirective]:
    ...

class ElseIfNotDefinedMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

class ElseIfDefinedMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

class ElseIfMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ElseIfMacroDirective]:
    ...

class IfNotDefinedMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

class IfDefinedMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IfDefinedMacroDirective]:
    ...

class IfMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.IfMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IfMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.IfMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IfMacroDirective]:
    ...

class IncludeLikeMacroDirective(multiplier.frontend.MacroDirective):
  included_file: Optional[multiplier.frontend.File]

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

class ImportMacroDirective(multiplier.frontend.IncludeLikeMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.ImportMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ImportMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.ImportMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ImportMacroDirective]:
    ...

class IncludeMacrosMacroDirective(multiplier.frontend.IncludeLikeMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

class IncludeNextMacroDirective(multiplier.frontend.IncludeLikeMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IncludeNextMacroDirective]:
    ...

class IncludeMacroDirective(multiplier.frontend.IncludeLikeMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Iterable[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Iterable[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.frontend.IncludeMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IncludeMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Iterable[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Iterable[multiplier.frontend.IncludeMacroDirective]:
    ...

  @staticmethod
  def from_base(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: multiplier.frontend.Macro) -> Optional[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(parent: Optional[multiplier.frontend.Macro]) -> Optional[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(r: multiplier.Reference) -> Optional[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IncludeMacroDirective]:
    ...

class TokenTree(object):
  root: multiplier.frontend.TokenTreeNode

  @overload
  @staticmethod
  def create(arg_0: multiplier.frontend.File) -> multiplier.frontend.TokenTree:
    ...

  @overload
  @staticmethod
  def create(arg_0: multiplier.Fragment) -> multiplier.frontend.TokenTree:
    ...

  @overload
  @staticmethod
  def create(arg_0: multiplier.frontend.TokenRange) -> multiplier.frontend.TokenTree:
    ...

  @overload
  @staticmethod
  def create(elems: Sequence[multiplier.frontend.TokenRange | multiplier.frontend.TokenTreeNode]) -> multiplier.frontend.TokenTree:
    ...

  def serialize(self, vis: multiplier.frontend.TokenTreeVisitor) -> multiplier.frontend.TokenRange:
    ...

  def __bool__(self) -> bool:
    ...

class TokenTreeNode(object):
  kind: multiplier.frontend.TokenTreeNodeKind

class EmptyTokenTreeNode(multiplier.frontend.TokenTreeNode):

  @staticmethod
  def static_kind() -> multiplier.frontend.TokenTreeNodeKind:
    ...

  @staticmethod
  def FROM(arg_0: multiplier.frontend.TokenTreeNode) -> Optional[multiplier.frontend.EmptyTokenTreeNode]:
    ...

class TokenTokenTreeNode(multiplier.frontend.TokenTreeNode):
  token: multiplier.frontend.Token

  @staticmethod
  def static_kind() -> multiplier.frontend.TokenTreeNodeKind:
    ...

  @staticmethod
  def FROM(arg_0: multiplier.frontend.TokenTreeNode) -> Optional[multiplier.frontend.TokenTokenTreeNode]:
    ...

class ChoiceTokenTreeNode(multiplier.frontend.TokenTreeNode):
  children: Iterable[Tuple[multiplier.Fragment, multiplier.frontend.TokenTreeNode]]

  @staticmethod
  def static_kind() -> multiplier.frontend.TokenTreeNodeKind:
    ...

  @staticmethod
  def FROM(arg_0: multiplier.frontend.TokenTreeNode) -> Optional[multiplier.frontend.ChoiceTokenTreeNode]:
    ...

class SubstitutionTokenTreeNode(multiplier.frontend.TokenTreeNode):
  macro: multiplier.frontend.MacroSubstitution | multiplier.frontend.MacroVAOpt
  before: multiplier.frontend.TokenTreeNode
  after: multiplier.frontend.TokenTreeNode

  @staticmethod
  def static_kind() -> multiplier.frontend.TokenTreeNodeKind:
    ...

  @staticmethod
  def FROM(arg_0: multiplier.frontend.TokenTreeNode) -> Optional[multiplier.frontend.SubstitutionTokenTreeNode]:
    ...

class SequenceTokenTreeNode(multiplier.frontend.TokenTreeNode):
  children: Iterable[multiplier.frontend.TokenTreeNode]

  @staticmethod
  def static_kind() -> multiplier.frontend.TokenTreeNodeKind:
    ...

  @staticmethod
  def FROM(arg_0: multiplier.frontend.TokenTreeNode) -> Optional[multiplier.frontend.SequenceTokenTreeNode]:
    ...
