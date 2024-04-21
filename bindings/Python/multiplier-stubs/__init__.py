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


DeclId = int
StmtId = int
TypeId = int
MacroId = int
DesignatorId = int
CXXCtorInitializer = int
CXXBaseSpecifierId = int
TemplateArgumentId = int
TemplateParameterListId = int
FileTokenId = int
MacroTokenId = int
ParsedTokenId = int
TypeTokenId = int

class Entity(object, ABC):
  id: int

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

class EntityCategory(IntEnum):
  NOT_AN_ENTITY = 0
  FRAGMENT = 1
  DECLARATION = 2
  STATEMENT = 3
  ATTRIBUTE = 4
  MACRO = 5
  TYPE = 6
  FILE = 7
  TOKEN = 8
  TEMPLATE_ARGUMENT = 9
  TEMPLATE_PARAMETER_LIST = 10
  CXX_BASE_SPECIFIER = 11
  DESIGNATOR = 12
  CXX_CTOR_INITIALIZER = 13
  COMPILATION = 14
  OPERATION = 15

class BuiltinReferenceKind(IntEnum):
  USES_VALUE = 0
  USES_TYPE = 1
  CASTS_WITH_TYPE = 2
  COPIES_VALUE = 3
  TESTS_VALUE = 4
  WRITES_VALUE = 5
  UPDATES_VALUE = 6
  ACCESSES_VALUE = 7
  TAKES_VALUE = 8
  CALLS = 9
  TAKES_ADDRESS = 10
  INCLUDES_FILE = 11
  EXPANSION_OF = 12
  EXTENDS = 13
  OVERRIDES = 14
  SPECIALIZES = 15

class IndexStatus(IntEnum):
  UNINITIALIZED = 0
  INDEXING_IN_PROGRESS = 1
  INDEXED = 2

class ReferenceKind(object):
  builtin_reference_kind: Optional[multiplier.BuiltinReferenceKind]
  data: str

  @overload
  @staticmethod
  def get(arg_0: multiplier.Index, kind: multiplier.BuiltinReferenceKind) -> multiplier.ReferenceKind:
    ...

  @overload
  @staticmethod
  def get(arg_0: multiplier.Index, name: str) -> multiplier.ReferenceKind:
    ...

class Reference(object):
  category: multiplier.EntityCategory
  builtin_reference_kind: Optional[multiplier.BuiltinReferenceKind]
  referenced_entity_id: int
  kind: multiplier.ReferenceKind
  context: multiplier.Entity
  as_variant: multiplier.Entity
  as_fragment: Optional[multiplier.Fragment]
  as_declaration: Optional[multiplier.ast.Decl]
  as_statement: Optional[multiplier.ast.Stmt]
  as_attribute: Optional[multiplier.ast.Attr]
  as_macro: Optional[multiplier.frontend.Macro]
  as_type: Optional[multiplier.ast.Type]
  as_file: Optional[multiplier.frontend.File]
  as_token: Optional[multiplier.frontend.Token]
  as_template_argument: Optional[multiplier.ast.TemplateArgument]
  as_template_parameter_list: Optional[multiplier.ast.TemplateParameterList]
  as_cxx_base_specifier: Optional[multiplier.ast.CXXBaseSpecifier]
  as_designator: Optional[multiplier.ast.Designator]
  as_cxx_ctor_initializer: Optional[multiplier.ast.CXXCtorInitializer]
  as_compilation: Optional[multiplier.frontend.Compilation]
  as_operation: Optional[multiplier.ir.Operation]

  @overload
  @staticmethod
  def add(kind: multiplier.ReferenceKind, from_: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation], to: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> bool:
    ...

  @overload
  @staticmethod
  def add(kind: multiplier.ReferenceKind, from_: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation], to: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation], context: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> bool:
    ...

  @staticmethod
  def FROM(entity: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Iterable[multiplier.Reference]:
    ...

  @staticmethod
  def to(entity: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Iterable[multiplier.Reference]:
    ...

class Fragment(multiplier.Entity):
  parent: Optional[multiplier.Fragment]
  parent_id: Optional[multiplier.FragmentId]
  compilation: multiplier.frontend.Compilation
  file_tokens: multiplier.frontend.TokenRange
  parsed_tokens: multiplier.frontend.TokenRange
  nested_fragments: Iterable[multiplier.Fragment]
  top_level_declarations: Iterable[multiplier.ast.Decl]
  preprocessed_code: Iterable[multiplier.frontend.Macro | multiplier.frontend.Token | multiplier.Fragment]

  @overload
  @staticmethod
  def containing(arg_0: multiplier.Fragment) -> Optional[multiplier.Fragment]:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.frontend.RegexQueryMatch) -> multiplier.Fragment:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.frontend.TokenTree) -> Optional[multiplier.Fragment]:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.Decl) -> multiplier.Fragment:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.Stmt) -> multiplier.Fragment:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.Attr) -> multiplier.Fragment:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.TemplateArgument) -> multiplier.Fragment:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.TemplateParameterList) -> multiplier.Fragment:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.CXXBaseSpecifier) -> multiplier.Fragment:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.CXXCtorInitializer) -> multiplier.Fragment:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ast.Designator) -> multiplier.Fragment:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.frontend.Token) -> Optional[multiplier.Fragment]:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.frontend.Macro) -> multiplier.Fragment:
    ...

  @overload
  @staticmethod
  def containing(arg_0: multiplier.ir.Operation) -> Optional[multiplier.Fragment]:
    ...

  @overload
  @staticmethod
  def containing(arg_0: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.Fragment]:
    ...

  @staticmethod
  def FROM(arg_0: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.Fragment]:
    ...

  @staticmethod
  def IN(index: multiplier.Index) -> Iterable[multiplier.Fragment]:
    ...

  @staticmethod
  def entity_category() -> multiplier.EntityCategory:
    ...

  def query(self, query: multiplier.RegexQuery) -> Iterable[multiplier.frontend.RegexQueryMatch]:
    ...

class Index(object):
  file_paths: FilePathMap
  compilations: Iterable[multiplier.frontend.Compilation]
  files: Iterable[multiplier.frontend.File]

  @overload
  @staticmethod
  def in_memory_cache(next: multiplier.Index) -> multiplier.Index:
    ...

  @overload
  @staticmethod
  def in_memory_cache(next: multiplier.Index, timeout_s: int) -> multiplier.Index:
    ...

  @staticmethod
  def from_database(path: pathlib.PurePath) -> multiplier.Index:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.Fragment) -> multiplier.Index:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.frontend.File) -> multiplier.Index:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.Decl) -> multiplier.Index:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.Stmt) -> multiplier.Index:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.Type) -> multiplier.Index:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.Attr) -> multiplier.Index:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.frontend.Macro) -> multiplier.Index:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ast.Designator) -> multiplier.Index:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.frontend.Token) -> Optional[multiplier.Index]:
    ...

  @overload
  @staticmethod
  def containing(entity: Optional[multiplier.Fragment | multiplier.ast.Decl | multiplier.ast.Stmt | multiplier.ast.Attr | multiplier.frontend.Macro | multiplier.ast.Type | multiplier.frontend.File | multiplier.frontend.Token | multiplier.ast.TemplateArgument | multiplier.ast.TemplateParameterList | multiplier.ast.CXXBaseSpecifier | multiplier.ast.Designator | multiplier.ast.CXXCtorInitializer | multiplier.frontend.Compilation | multiplier.ir.Operation]) -> Optional[multiplier.Index]:
    ...

  @overload
  @staticmethod
  def containing(entity: multiplier.ir.Operation) -> multiplier.Index:
    ...

  def status(self, block: bool) -> multiplier.IndexStatus:
    ...

  def fragment_containing(self, arg_0: int) -> Optional[multiplier.Fragment]:
    ...

  @overload
  def fragment(self, id: int) -> Optional[multiplier.Fragment]:
    ...

  @overload
  def fragment(self, id: multiplier.FragmentId) -> Optional[multiplier.Fragment]:
    ...

  @overload
  def declaration(self, id: int) -> Optional[multiplier.ast.Decl]:
    ...

  @overload
  def declaration(self, id: multiplier.DeclId) -> Optional[multiplier.ast.Decl]:
    ...

  @overload
  def statement(self, id: int) -> Optional[multiplier.ast.Stmt]:
    ...

  @overload
  def statement(self, id: multiplier.StmtId) -> Optional[multiplier.ast.Stmt]:
    ...

  @overload
  def attribute(self, id: int) -> Optional[multiplier.ast.Attr]:
    ...

  @overload
  def attribute(self, id: multiplier.AttrId) -> Optional[multiplier.ast.Attr]:
    ...

  @overload
  def macro(self, id: int) -> Optional[multiplier.frontend.Macro]:
    ...

  @overload
  def macro(self, id: multiplier.MacroId) -> Optional[multiplier.frontend.Macro]:
    ...

  @overload
  def type(self, id: int) -> Optional[multiplier.ast.Type]:
    ...

  @overload
  def type(self, id: multiplier.TypeId) -> Optional[multiplier.ast.Type]:
    ...

  @overload
  def file(self, id: int) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  def file(self, id: multiplier.FileId) -> Optional[multiplier.frontend.File]:
    ...

  @overload
  def template_argument(self, id: int) -> Optional[multiplier.ast.TemplateArgument]:
    ...

  @overload
  def template_argument(self, id: multiplier.TemplateArgumentId) -> Optional[multiplier.ast.TemplateArgument]:
    ...

  @overload
  def template_parameter_list(self, id: int) -> Optional[multiplier.ast.TemplateParameterList]:
    ...

  @overload
  def template_parameter_list(self, id: multiplier.TemplateParameterListId) -> Optional[multiplier.ast.TemplateParameterList]:
    ...

  @overload
  def cxx_base_specifier(self, id: int) -> Optional[multiplier.ast.CXXBaseSpecifier]:
    ...

  @overload
  def cxx_base_specifier(self, id: multiplier.CXXBaseSpecifierId) -> Optional[multiplier.ast.CXXBaseSpecifier]:
    ...

  @overload
  def designator(self, id: int) -> Optional[multiplier.ast.Designator]:
    ...

  @overload
  def designator(self, id: multiplier.DesignatorId) -> Optional[multiplier.ast.Designator]:
    ...

  @overload
  def cxx_ctor_initializer(self, id: int) -> Optional[multiplier.ast.CXXCtorInitializer]:
    ...

  @overload
  def cxx_ctor_initializer(self, id: multiplier.CXXCtorInitializerId) -> Optional[multiplier.ast.CXXCtorInitializer]:
    ...

  @overload
  def compilation(self, id: int) -> Optional[multiplier.frontend.Compilation]:
    ...

  @overload
  def compilation(self, id: multiplier.CompilationId) -> Optional[multiplier.frontend.Compilation]:
    ...

  @overload
  def operation(self, id: int) -> Optional[multiplier.ir.Operation]:
    ...

  @overload
  def operation(self, id: multiplier.OperationId) -> Optional[multiplier.ir.Operation]:
    ...

  def entity(self, eid: int) -> multiplier.Entity:
    ...

  def query_entities(self, name: str) -> Iterable[multiplier.ast.NamedDecl | multiplier.frontend.DefineMacroDirective | multiplier.frontend.File]:
    ...

class RegexQuery(object):
  pattern: str
  is_valid: bool

  @staticmethod
  def FROM(match: multiplier.frontend.RegexQueryMatch) -> multiplier.RegexQuery:
    ...

  @overload
  def match_fragments(self, arg_0: multiplier.frontend.File) -> Iterable[multiplier.frontend.RegexQueryMatch]:
    ...

  @overload
  def match_fragments(self, arg_0: multiplier.Fragment) -> Iterable[multiplier.frontend.RegexQueryMatch]:
    ...
