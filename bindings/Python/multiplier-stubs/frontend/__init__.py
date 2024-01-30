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
  HASHAT = 68
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
  KEYWORD_STATIC = 101
  KEYWORD_STRUCT = 102
  KEYWORD_SWITCH = 103
  KEYWORD_TYPEDEF = 104
  KEYWORD_UNION = 105
  KEYWORD_UNSIGNED = 106
  KEYWORD_VOID = 107
  KEYWORD_VOLATILE = 108
  KEYWORD_WHILE = 109
  KEYWORD__ALIGNAS = 110
  KEYWORD__ALIGNOF = 111
  KEYWORD__ATOMIC = 112
  KEYWORD__BOOLEAN = 113
  KEYWORD__COMPLEX = 114
  KEYWORD__GENERIC = 115
  KEYWORD__IMAGINARY = 116
  KEYWORD__NORETURN = 117
  KEYWORD__STATIC_ASSERT = 118
  KEYWORD__THREAD_LOCAL = 119
  KEYWORD___FUNC__ = 120
  KEYWORD___OBJC_YES = 121
  KEYWORD___OBJC_NO = 122
  KEYWORD_ASSEMBLY = 123
  KEYWORD_BOOLEAN = 124
  KEYWORD_CATCH = 125
  KEYWORD_CLASS = 126
  KEYWORD_CONST_CAST = 127
  KEYWORD_DELETE = 128
  KEYWORD_DYNAMIC_CAST = 129
  KEYWORD_EXPLICIT = 130
  KEYWORD_EXPORT = 131
  KEYWORD_FALSE = 132
  KEYWORD_FRIEND = 133
  KEYWORD_MUTABLE = 134
  KEYWORD_NAMESPACE = 135
  KEYWORD_NEW = 136
  KEYWORD_OPERATOR = 137
  KEYWORD_PRIVATE = 138
  KEYWORD_PROTECTED = 139
  KEYWORD_PUBLIC = 140
  KEYWORD_REINTERPRET_CAST = 141
  KEYWORD_STATIC_CAST = 142
  KEYWORD_TEMPLATE = 143
  KEYWORD_THIS = 144
  KEYWORD_THROW = 145
  KEYWORD_TRUE = 146
  KEYWORD_TRY = 147
  KEYWORD_TYPENAME = 148
  KEYWORD_TYPEID = 149
  KEYWORD_USING = 150
  KEYWORD_VIRTUAL = 151
  KEYWORD_WCHAR_T = 152
  KEYWORD_RESTRICT = 153
  KEYWORD_INLINE = 154
  KEYWORD_ALIGNAS = 155
  KEYWORD_ALIGNOF = 156
  KEYWORD_CHAR16_T = 157
  KEYWORD_CHAR32_T = 158
  KEYWORD_CONSTEXPR = 159
  KEYWORD_DECLTYPE = 160
  KEYWORD_NOEXCEPT = 161
  KEYWORD_NULLPTR = 162
  KEYWORD_STATIC_ASSERT = 163
  KEYWORD_THREAD_LOCAL = 164
  KEYWORD_CO_AWAIT = 165
  KEYWORD_CO_RETURN = 166
  KEYWORD_CO_YIELD = 167
  KEYWORD_MODULE = 168
  KEYWORD_IMPORT = 169
  KEYWORD_CONSTEVAL = 170
  KEYWORD_CONSTINIT = 171
  KEYWORD_CONCEPT = 172
  KEYWORD_REQUIRES = 173
  KEYWORD_CHAR8_T = 174
  KEYWORD__FLOAT16 = 175
  KEYWORD_TYPEOF = 176
  KEYWORD_TYPEOF_UNQUALIFIED = 177
  KEYWORD__ACCUM = 178
  KEYWORD__FRACT = 179
  KEYWORD__SAT = 180
  KEYWORD__DECIMAL32 = 181
  KEYWORD__DECIMAL64 = 182
  KEYWORD__DECIMAL128 = 183
  KEYWORD___NULL = 184
  KEYWORD___ALIGNOF = 185
  KEYWORD___ATTRIBUTE = 186
  KEYWORD___BUILTIN_CHOOSE_EXPRESSION = 187
  KEYWORD___BUILTIN_OFFSETOF = 188
  KEYWORD___BUILTIN_FILE = 189
  KEYWORD___BUILTIN_FILENAME = 190
  KEYWORD___BUILTIN_FUNCTION = 191
  KEYWORD___BUILTIN_FUNCSIG = 192
  KEYWORD___BUILTIN_LINE = 193
  KEYWORD___BUILTIN_COLUMN = 194
  KEYWORD___BUILTIN_SOURCE_TOKEN = 195
  KEYWORD___BUILTIN_TYPES_COMPATIBLE_P = 196
  KEYWORD___BUILTIN_VA_ARGUMENT = 197
  KEYWORD___EXTENSION__ = 198
  KEYWORD___FLOAT128 = 199
  KEYWORD___IBM128 = 200
  KEYWORD___IMAG = 201
  KEYWORD___INT128 = 202
  KEYWORD___LABEL__ = 203
  KEYWORD___REAL = 204
  KEYWORD___THREAD = 205
  KEYWORD___FUNCTION__ = 206
  KEYWORD___PRETTYFUNCTION__ = 207
  KEYWORD___AUTO_TYPE = 208
  KEYWORD___FUNCDNAME__ = 209
  KEYWORD___FUNCSIG__ = 210
  KEYWORD_LFUNCTION__ = 211
  KEYWORD_LFUNCSIG__ = 212
  KEYWORD___IS_INTERFACE_CLASS = 213
  KEYWORD___IS_SEALED = 214
  KEYWORD___IS_DESTRUCTIBLE = 215
  KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE = 216
  KEYWORD___IS_NOTHROW_DESTRUCTIBLE = 217
  KEYWORD___IS_NOTHROW_ASSIGNABLE = 218
  KEYWORD___IS_CONSTRUCTIBLE = 219
  KEYWORD___IS_NOTHROW_CONSTRUCTIBLE = 220
  KEYWORD___IS_ASSIGNABLE = 221
  KEYWORD___HAS_NOTHROW_MOVE_ASSIGN = 222
  KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN = 223
  KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR = 224
  KEYWORD___HAS_NOTHROW_ASSIGN = 225
  KEYWORD___HAS_NOTHROW_COPY = 226
  KEYWORD___HAS_NOTHROW_CONSTRUCTOR = 227
  KEYWORD___HAS_TRIVIAL_ASSIGN = 228
  KEYWORD___HAS_TRIVIAL_COPY = 229
  KEYWORD___HAS_TRIVIAL_CONSTRUCTOR = 230
  KEYWORD___HAS_TRIVIAL_DESTRUCTOR = 231
  KEYWORD___HAS_VIRTUAL_DESTRUCTOR = 232
  KEYWORD___IS_ABSTRACT = 233
  KEYWORD___IS_AGGREGATE = 234
  KEYWORD___IS_BASE_OF = 235
  KEYWORD___IS_CLASS = 236
  KEYWORD___IS_CONVERTIBLE_TO = 237
  KEYWORD___IS_EMPTY = 238
  KEYWORD___IS_ENUM = 239
  KEYWORD___IS_FINAL = 240
  KEYWORD___IS_LITERAL = 241
  KEYWORD___IS_POD = 242
  KEYWORD___IS_POLYMORPHIC = 243
  KEYWORD___IS_STANDARD_LAYOUT = 244
  KEYWORD___IS_TRIVIAL = 245
  KEYWORD___IS_TRIVIALLY_ASSIGNABLE = 246
  KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE = 247
  KEYWORD___IS_TRIVIALLY_COPYABLE = 248
  KEYWORD___IS_UNION = 249
  KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS = 250
  KEYWORD___ADD_LVALUE_REFERENCE = 251
  KEYWORD___ADD_POINTER = 252
  KEYWORD___ADD_RVALUE_REFERENCE = 253
  KEYWORD___DECAY = 254
  KEYWORD___MAKE_SIGNED = 255
  KEYWORD___MAKE_UNSIGNED = 256
  KEYWORD___REMOVE_ALL_EXTENTS = 257
  KEYWORD___REMOVE_CONST = 258
  KEYWORD___REMOVE_CV = 259
  KEYWORD___REMOVE_CVREF = 260
  KEYWORD___REMOVE_EXTENT = 261
  KEYWORD___REMOVE_POINTER = 262
  KEYWORD___REMOVE_REFERENCE_T = 263
  KEYWORD___REMOVE_RESTRICT = 264
  KEYWORD___REMOVE_VOLATILE = 265
  KEYWORD___UNDERLYING_TYPE = 266
  KEYWORD___IS_TRIVIALLY_RELOCATABLE = 267
  KEYWORD___IS_TRIVIALLY_EQUALITY_COMPARABLE = 268
  KEYWORD___IS_BOUNDED_ARRAY = 269
  KEYWORD___IS_UNBOUNDED_ARRAY = 270
  KEYWORD___IS_NULLPTR = 271
  KEYWORD___IS_SCOPED_ENUM = 272
  KEYWORD___IS_REFERENCEABLE = 273
  KEYWORD___CAN_PASS_IN_REGS = 274
  KEYWORD___REFERENCE_BINDS_TO_TEMPORARY = 275
  KEYWORD___IS_LVALUE_EXPRESSION = 276
  KEYWORD___IS_RVALUE_EXPRESSION = 277
  KEYWORD___IS_ARITHMETIC = 278
  KEYWORD___IS_FLOATING_POINT = 279
  KEYWORD___IS_INTEGRAL = 280
  KEYWORD___IS_COMPLETE_TYPE = 281
  KEYWORD___IS_VOID = 282
  KEYWORD___IS_ARRAY = 283
  KEYWORD___IS_FUNCTION = 284
  KEYWORD___IS_REFERENCE = 285
  KEYWORD___IS_LVALUE_REFERENCE = 286
  KEYWORD___IS_RVALUE_REFERENCE = 287
  KEYWORD___IS_FUNDAMENTAL = 288
  KEYWORD___IS_OBJECT = 289
  KEYWORD___IS_SCALAR = 290
  KEYWORD___IS_COMPOUND = 291
  KEYWORD___IS_POINTER = 292
  KEYWORD___IS_MEMBER_OBJECT_POINTER = 293
  KEYWORD___IS_MEMBER_FUNCTION_POINTER = 294
  KEYWORD___IS_MEMBER_POINTER = 295
  KEYWORD___IS_CONST = 296
  KEYWORD___IS_VOLATILE = 297
  KEYWORD___IS_SIGNED = 298
  KEYWORD___IS_UNSIGNED = 299
  KEYWORD___IS_SAME = 300
  KEYWORD___IS_CONVERTIBLE = 301
  KEYWORD___ARRAY_RANK = 302
  KEYWORD___ARRAY_EXTENT = 303
  KEYWORD___PRIVATE_EXTERN__ = 304
  KEYWORD___MODULE_PRIVATE__ = 305
  KEYWORD___BUILTIN_PTRAUTH_TYPE_DISCRIMINATOR = 306
  KEYWORD___BUILTIN_XNU_TYPE_SIGNATURE = 307
  KEYWORD___BUILTIN_XNU_TYPE_SUMMARY = 308
  KEYWORD___BUILTIN_TMO_TYPE_METADATA = 309
  KEYWORD___BUILTIN_XNU_TYPES_COMPATIBLE = 310
  KEYWORD___DECLSPEC = 311
  KEYWORD___CDECL = 312
  KEYWORD___STDCALL = 313
  KEYWORD___FASTCALL = 314
  KEYWORD___THISCALL = 315
  KEYWORD___REGCALL = 316
  KEYWORD___VECTORCALL = 317
  KEYWORD___FORCEINLINE = 318
  KEYWORD___UNALIGNED = 319
  KEYWORD___SUPER = 320
  KEYWORD___GLOBAL = 321
  KEYWORD___LOCAL = 322
  KEYWORD___CONSTANT = 323
  KEYWORD___PRIVATE = 324
  KEYWORD___GENERIC = 325
  KEYWORD___KERNEL = 326
  KEYWORD___READ_ONLY = 327
  KEYWORD___WRITE_ONLY = 328
  KEYWORD___READ_WRITE = 329
  KEYWORD___BUILTIN_ASTYPE = 330
  KEYWORD_VEC_STEP = 331
  KEYWORD_IMAGE_1D_T = 332
  KEYWORD_IMAGE_1D_ARRAY_T = 333
  KEYWORD_IMAGE_1D_BUFFER_T = 334
  KEYWORD_IMAGE_2D_T = 335
  KEYWORD_IMAGE_2D_ARRAY_T = 336
  KEYWORD_IMAGE_2D_DEPTH_T = 337
  KEYWORD_IMAGE_2D_ARRAY_DEPTH_T = 338
  KEYWORD_IMAGE_2D_MSAA_T = 339
  KEYWORD_IMAGE_2D_ARRAY_MSAA_T = 340
  KEYWORD_IMAGE_2D_MSAA_DEPTH_T = 341
  KEYWORD_IMAGE_2D_ARRAY_MSAA_DEPTH_T = 342
  KEYWORD_IMAGE_3D_T = 343
  KEYWORD_PIPE = 344
  KEYWORD_ADDRSPACE_CAST = 345
  KEYWORD___NOINLINE__ = 346
  KEYWORD_CBUFFER = 347
  KEYWORD_TBUFFER = 348
  KEYWORD_GROUPSHARED = 349
  KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN = 350
  KEYWORD___PASCAL = 351
  KEYWORD___VECTOR = 352
  KEYWORD___PIXEL = 353
  KEYWORD___BOOLEAN = 354
  KEYWORD___BF16 = 355
  KEYWORD_HALF = 356
  KEYWORD___BRIDGE = 357
  KEYWORD___BRIDGE_TRANSFER = 358
  KEYWORD___BRIDGE_RETAINED = 359
  KEYWORD___BRIDGE_RETAIN = 360
  KEYWORD___COVARIANT = 361
  KEYWORD___CONTRAVARIANT = 362
  KEYWORD___KINDOF = 363
  KEYWORD__NONNULL = 364
  KEYWORD__NULLABLE = 365
  KEYWORD__NULLABLE_RESULT = 366
  KEYWORD__NULL_UNSPECIFIED = 367
  KEYWORD___FUNCREF = 368
  KEYWORD___PTR64 = 369
  KEYWORD___PTR32 = 370
  KEYWORD___SPTR = 371
  KEYWORD___UPTR = 372
  KEYWORD___W64 = 373
  KEYWORD___UUIDOF = 374
  KEYWORD___TRY = 375
  KEYWORD___FINALLY = 376
  KEYWORD___LEAVE = 377
  KEYWORD___INT64 = 378
  KEYWORD___IF_EXISTS = 379
  KEYWORD___IF_NOT_EXISTS = 380
  KEYWORD___SINGLE_INHERITANCE = 381
  KEYWORD___MULTIPLE_INHERITANCE = 382
  KEYWORD___VIRTUAL_INHERITANCE = 383
  KEYWORD___INTERFACE = 384
  KEYWORD___BUILTIN_CONVERTVECTOR = 385
  KEYWORD___BUILTIN_BIT_CAST = 386
  KEYWORD___BUILTIN_AVAILABLE = 387
  KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME = 388
  KEYWORD___ARM_STREAMING = 389
  KEYWORD___UNKNOWN_ANYTYPE = 390
  ANNOT_CXXSCOPE = 391
  ANNOT_TYPENAME = 392
  ANNOT_TEMPLATE_ID = 393
  ANNOT_NON_TYPE = 394
  ANNOT_NON_TYPE_UNDECLARED = 395
  ANNOT_NON_TYPE_DEPENDENT = 396
  ANNOT_OVERLOAD = 397
  ANNOT_PRIMARY_EXPRESSION = 398
  ANNOT_DECLTYPE = 399
  ANNOT_PRAGMA_UNUSED = 400
  ANNOT_PRAGMA_VIS = 401
  ANNOT_PRAGMA_PACK = 402
  ANNOT_PRAGMA_PARSER_CRASH = 403
  ANNOT_PRAGMA_CAPTURED = 404
  ANNOT_PRAGMA_DUMP = 405
  ANNOT_PRAGMA_MSSTRUCT = 406
  ANNOT_PRAGMA_ALIGN = 407
  ANNOT_PRAGMA_WEAK = 408
  ANNOT_PRAGMA_WEAKALIAS = 409
  ANNOT_PRAGMA_REDEFINE_EXTNAME = 410
  ANNOT_PRAGMA_FP_CONTRACT = 411
  ANNOT_PRAGMA_FENV_ACCESS = 412
  ANNOT_PRAGMA_FENV_ACCESS_MS = 413
  ANNOT_PRAGMA_FENV_ROUND = 414
  ANNOT_PRAGMA_FLOAT_CONTROL = 415
  ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS = 416
  ANNOT_PRAGMA_MS_VTORDISP = 417
  ANNOT_PRAGMA_MS_PRAGMA = 418
  ANNOT_PRAGMA_OPENCL_EXTENSION = 419
  ANNOT_ATTRIBUTE_OPENMP = 420
  ANNOT_PRAGMA_OPENMP = 421
  ANNOT_PRAGMA_OPENMP_END = 422
  ANNOT_PRAGMA_LOOP_HINT = 423
  ANNOT_PRAGMA_FP = 424
  ANNOT_PRAGMA_ATTRIBUTE = 425
  ANNOT_PRAGMA_RISCV = 426
  ANNOT_MODULE_INCLUDE = 427
  ANNOT_MODULE_BEGIN = 428
  ANNOT_MODULE_END = 429
  ANNOT_HEADER_UNIT = 430
  ANNOT_REPL_INPUT_END = 431
  PP_IF = 432
  PP_IFDEF = 433
  PP_IFNDEF = 434
  PP_ELIF = 435
  PP_ELIFDEF = 436
  PP_ELIFNDEF = 437
  PP_ELSE = 438
  PP_ENDIF = 439
  PP_DEFINED = 440
  PP_INCLUDE = 441
  PP___INCLUDE_MACROS = 442
  PP_DEFINE = 443
  PP_UNDEF = 444
  PP_LINE = 445
  PP_ERROR = 446
  PP_PRAGMA = 447
  PP_IMPORT = 448
  PP_INCLUDE_NEXT = 449
  PP_WARNING = 450
  PP_IDENTIFIER = 451
  PP_SCCS = 452
  PP_ASSERT = 453
  PP_UNASSERT = 454
  PP___PUBLIC_MACRO = 455
  PP___PRIVATE_MACRO = 456
  OBJC_AT_CLASS = 457
  OBJC_AT_COMPATIBILITY_ALIAS = 458
  OBJC_AT_DEFINITIONS = 459
  OBJC_AT_ENCODE = 460
  OBJC_AT_OBJC_END = 461
  OBJC_AT_IMPLEMENTATION = 462
  OBJC_AT_INTERFACE = 463
  OBJC_AT_PRIVATE = 464
  OBJC_AT_PROTECTED = 465
  OBJC_AT_PROTOCOL = 466
  OBJC_AT_PUBLIC = 467
  OBJC_AT_SELECTOR = 468
  OBJC_AT_THROW = 469
  OBJC_AT_TRY = 470
  OBJC_AT_CATCH = 471
  OBJC_AT_FINALLY = 472
  OBJC_AT_SYNCHRONIZED = 473
  OBJC_AT_AUTORELEASEPOOL = 474
  OBJC_AT_PROPERTY = 475
  OBJC_AT_PACKAGE = 476
  OBJC_AT_REQUIRED = 477
  OBJC_AT_OPTIONAL = 478
  OBJC_AT_SYNTHESIZE = 479
  OBJC_AT_DYNAMIC = 480
  OBJC_AT_IMPORT = 481
  OBJC_AT_AVAILABLE = 482

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
  aliasee: Optional[multiplier.frontend.TokenContext]
  parent: Optional[multiplier.frontend.TokenContext]

class Compilation(multiplier.Entity):
  ir: Optional[multiplier.ir.builtin.ModuleOp]
  fragments: Generator[multiplier.Fragment]
  files: Generator[multiplier.frontend.File]
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
  arguments: Generator[str]
  system_include_directories: Generator[Tuple[multiplier.frontend.IncludePathLocation, pathlib.PurePath]]
  user_include_directories: Generator[Tuple[multiplier.frontend.IncludePathLocation, pathlib.PurePath]]
  framework_directories: Generator[Tuple[multiplier.frontend.IncludePathLocation, pathlib.PurePath]]

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
  def containing(arg_0: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.Compilation]:
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
  def FROM(entity: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.Token]:
    ...

  @staticmethod
  def entity_category() -> multiplier.EntityCategory:
    ...

  @staticmethod
  def categorize(entity: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> multiplier.frontend.TokenCategory:
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
  fragments: Generator[multiplier.Fragment]
  paths: Generator[pathlib.PurePath]
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
  def containing(arg_0: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.File]:
    ...

  @staticmethod
  def FROM(arg_0: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.File]:
    ...

  @staticmethod
  def entity_category() -> multiplier.EntityCategory:
    ...

class Macro(multiplier.Entity):
  root: multiplier.frontend.Macro
  use_tokens: multiplier.frontend.TokenRange
  generate_use_tokens: Generator[multiplier.frontend.Token]
  expansion_tokens: multiplier.frontend.TokenRange
  generate_expansion_tokens: Generator[multiplier.frontend.Token]
  kind: multiplier.frontend.MacroKind
  parent: Optional[multiplier.frontend.Macro]
  children: Generator[multiplier.frontend.Macro | multiplier.frontend.Token]

  @staticmethod
  def static_category() -> multiplier.EntityCategory:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index, kinds: Sequence[multiplier.frontend.MacroKind]) -> Generator[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment, kinds: Sequence[multiplier.frontend.MacroKind]) -> Generator[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File, kinds: Sequence[multiplier.frontend.MacroKind]) -> Generator[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.Macro]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.Macro]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.Macro]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.Macro]:
    ...

class MacroSubstitution(multiplier.frontend.Macro):
  replacement_children: Generator[multiplier.frontend.Macro | multiplier.frontend.Token]
  first_fully_substituted_token: multiplier.frontend.Token
  last_fully_substituted_token: multiplier.frontend.Token
  name_or_operator: multiplier.frontend.Token

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.MacroSubstitution]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroSubstitution]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.MacroSubstitution]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroSubstitution]:
    ...

class MacroConcatenate(multiplier.frontend.MacroSubstitution):
  pasted_token: multiplier.frontend.Token

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.MacroConcatenate]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroConcatenate]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.MacroConcatenate]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroConcatenate]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroConcatenate]:
    ...

class MacroStringify(multiplier.frontend.MacroSubstitution):
  stringified_token: multiplier.frontend.Token

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.MacroStringify]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroStringify]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.MacroStringify]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroStringify]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroStringify]:
    ...

class MacroExpansion(multiplier.frontend.MacroSubstitution):
  intermediate_children: Generator[multiplier.frontend.Macro | multiplier.frontend.Token]
  definition: Optional[multiplier.frontend.DefineMacroDirective]
  num_arguments: int
  arguments: Generator[multiplier.frontend.MacroArgument]

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.MacroExpansion]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroExpansion]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.MacroExpansion]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.MacroExpansion]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroExpansion]:
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
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.MacroParameterSubstitution]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroParameterSubstitution]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroParameterSubstitution]:
    ...

class MacroVAOpt(multiplier.frontend.Macro):
  contents_are_elided: bool

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.MacroVAOpt]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroVAOpt]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.MacroVAOpt]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroVAOpt]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroVAOpt]:
    ...

class MacroVAOptArgument(multiplier.frontend.Macro):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.MacroVAOptArgument]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroVAOptArgument]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.MacroVAOptArgument]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.MacroVAOptArgument]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroVAOptArgument]:
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
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.MacroArgument]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroArgument]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.MacroArgument]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.MacroArgument]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroArgument]:
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
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.MacroParameter]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroParameter]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.MacroParameter]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.MacroParameter]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroParameter]:
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
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.MacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.MacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.MacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.MacroDirective]:
    ...

class DefineMacroDirective(multiplier.frontend.MacroDirective):
  name: multiplier.frontend.Token
  body: Generator[multiplier.frontend.Macro | multiplier.frontend.Token]
  is_variadic: bool
  is_function_like: bool
  parameters: Generator[multiplier.frontend.Macro | multiplier.frontend.Token]

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.DefineMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.DefineMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.DefineMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.DefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.DefineMacroDirective]:
    ...

class PragmaMacroDirective(multiplier.frontend.MacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.PragmaMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.PragmaMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.PragmaMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.PragmaMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.PragmaMacroDirective]:
    ...

class UndefineMacroDirective(multiplier.frontend.MacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.UndefineMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.UndefineMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.UndefineMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.UndefineMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.UndefineMacroDirective]:
    ...

class OtherMacroDirective(multiplier.frontend.MacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.OtherMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.OtherMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.OtherMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.OtherMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.OtherMacroDirective]:
    ...

class ConditionalMacroDirective(multiplier.frontend.MacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.ConditionalMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ConditionalMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ConditionalMacroDirective]:
    ...

class EndIfMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.EndIfMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.EndIfMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.EndIfMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.EndIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.EndIfMacroDirective]:
    ...

class ElseMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.ElseMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ElseMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.ElseMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ElseMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ElseMacroDirective]:
    ...

class ElseIfNotDefinedMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ElseIfNotDefinedMacroDirective]:
    ...

class ElseIfDefinedMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.ElseIfDefinedMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ElseIfDefinedMacroDirective]:
    ...

class ElseIfMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.ElseIfMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ElseIfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ElseIfMacroDirective]:
    ...

class IfNotDefinedMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.IfNotDefinedMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IfNotDefinedMacroDirective]:
    ...

class IfDefinedMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.IfDefinedMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IfDefinedMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IfDefinedMacroDirective]:
    ...

class IfMacroDirective(multiplier.frontend.ConditionalMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.IfMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IfMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.IfMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IfMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IfMacroDirective]:
    ...

class IncludeLikeMacroDirective(multiplier.frontend.MacroDirective):
  included_file: Optional[multiplier.frontend.File]

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.IncludeLikeMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IncludeLikeMacroDirective]:
    ...

class ImportMacroDirective(multiplier.frontend.IncludeLikeMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.ImportMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.ImportMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.ImportMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.ImportMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.ImportMacroDirective]:
    ...

class IncludeMacrosMacroDirective(multiplier.frontend.IncludeLikeMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.IncludeMacrosMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IncludeMacrosMacroDirective]:
    ...

class IncludeNextMacroDirective(multiplier.frontend.IncludeLikeMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.IncludeNextMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IncludeNextMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IncludeNextMacroDirective]:
    ...

class IncludeMacroDirective(multiplier.frontend.IncludeLikeMacroDirective):

  @overload
  @staticmethod
  def IN(frag: multiplier.Fragment) -> Generator[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(file: multiplier.frontend.File) -> Generator[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def IN(index: multiplier.Index) -> Generator[multiplier.frontend.IncludeMacroDirective]:
    ...

  @staticmethod
  def by_id(arg_0: multiplier.Index, arg_1: int) -> Optional[multiplier.frontend.IncludeMacroDirective]:
    ...

  @staticmethod
  def static_kind() -> multiplier.frontend.MacroKind:
    ...

  @overload
  @staticmethod
  def containing(macro: multiplier.frontend.Macro) -> Generator[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def containing(token: multiplier.frontend.Token) -> Generator[multiplier.frontend.IncludeMacroDirective]:
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
  def FROM(e: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.frontend.IncludeMacroDirective]:
    ...

  @overload
  @staticmethod
  def FROM(t: multiplier.frontend.TokenContext) -> Optional[multiplier.frontend.IncludeMacroDirective]:
    ...

class TokenTree(object):
  root: multiplier.frontend.TokenTreeNode

  @overload
  @staticmethod
  def FROM(arg_0: multiplier.frontend.File) -> multiplier.frontend.TokenTree:
    ...

  @overload
  @staticmethod
  def FROM(arg_0: multiplier.Fragment) -> multiplier.frontend.TokenTree:
    ...

  @overload
  @staticmethod
  def FROM(arg_0: multiplier.frontend.TokenRange) -> multiplier.frontend.TokenTree:
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
  children: Generator[Tuple[multiplier.Fragment, multiplier.frontend.TokenTreeNode]]

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
  children: Generator[multiplier.frontend.TokenTreeNode]

  @staticmethod
  def static_kind() -> multiplier.frontend.TokenTreeNodeKind:
    ...

  @staticmethod
  def FROM(arg_0: multiplier.frontend.TokenTreeNode) -> Optional[multiplier.frontend.SequenceTokenTreeNode]:
    ...
