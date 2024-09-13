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

class Attribute(multiplier.ir.Attribute):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.Attribute]:
    ...

class AnnotationAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.AnnotationAttr]:
    ...

class FormatAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.FormatAttr]:
    ...

class SectionAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.SectionAttr]:
    ...

class AliasAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.AliasAttr]:
    ...

class ErrorAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.ErrorAttr]:
    ...

class CountedByAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.CountedByAttr]:
    ...

class CleanupAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.CleanupAttr]:
    ...

class AlignedAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.AlignedAttr]:
    ...

class AlwaysInlineAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.AlwaysInlineAttr]:
    ...

class NoInlineAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.NoInlineAttr]:
    ...

class ConstAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.ConstAttr]:
    ...

class LoaderUninitializedAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.LoaderUninitializedAttr]:
    ...

class NoInstrumentFunctionAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.NoInstrumentFunctionAttr]:
    ...

class PackedAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.PackedAttr]:
    ...

class PureAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.PureAttr]:
    ...

class WarnUnusedResultAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.WarnUnusedResultAttr]:
    ...

class RestrictAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.RestrictAttr]:
    ...

class NoThrowAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.NoThrowAttr]:
    ...

class NonNullAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.NonNullAttr]:
    ...

class LeafAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.LeafAttr]:
    ...

class ColdAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.ColdAttr]:
    ...

class TransparentUnionAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.TransparentUnionAttr]:
    ...

class ReturnsTwiceAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.ReturnsTwiceAttr]:
    ...

class MayAliasAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.MayAliasAttr]:
    ...

class UnusedAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.UnusedAttr]:
    ...

class UsedAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.UsedAttr]:
    ...

class GNUInlineAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.GNUInlineAttr]:
    ...

class NoCfCheckAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.NoCfCheckAttr]:
    ...

class AvailableOnlyInDefaultEvalMethodAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.AvailableOnlyInDefaultEvalMethodAttr]:
    ...

class AvailabilityAttrAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.AvailabilityAttrAttr]:
    ...

class FallthroughAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.FallthroughAttr]:
    ...

class NoProfileInstrumentFunctionAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.NoProfileInstrumentFunctionAttr]:
    ...

class AsmLabelAttr(multiplier.ir.highlevel.Attribute):
  is_literal: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.AsmLabelAttr]:
    ...

class ModeAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.ModeAttr]:
    ...

class BuiltinAttr(multiplier.ir.highlevel.Attribute):
  id: int

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.BuiltinAttr]:
    ...

class AllocAlignAttr(multiplier.ir.highlevel.Attribute):
  alignment: int

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.AllocAlignAttr]:
    ...

class AllocSizeAttr(multiplier.ir.highlevel.Attribute):
  size_arg_pos: int
  num_arg_pos: int

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.AllocSizeAttr]:
    ...

class DeprecatedAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.DeprecatedAttr]:
    ...

class MaxFieldAlignmentAttr(multiplier.ir.highlevel.Attribute):
  alignment: int

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.MaxFieldAlignmentAttr]:
    ...

class VisibilityAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.VisibilityAttr]:
    ...

class AssumeAlignedAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.AssumeAlignedAttr]:
    ...

class CVQualifiersAttr(multiplier.ir.highlevel.Attribute):
  is_const: bool
  is_volatile: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.CVQualifiersAttr]:
    ...

class UCVQualifiersAttr(multiplier.ir.highlevel.Attribute):
  is_unsigned: bool
  is_const: bool
  is_volatile: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.UCVQualifiersAttr]:
    ...

class CVRQualifiersAttr(multiplier.ir.highlevel.Attribute):
  is_const: bool
  is_volatile: bool
  is_restrict: bool

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.CVRQualifiersAttr]:
    ...

class OffsetOfNodeAttr(multiplier.ir.highlevel.Attribute):

  @staticmethod
  def static_kind() -> multiplier.ir.AttributeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Attribute) -> Optional[multiplier.ir.highlevel.OffsetOfNodeAttr]:
    ...

class Operation(multiplier.ir.Operation):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.Operation]:
    ...

class RefOp(multiplier.ir.highlevel.Operation):
  referenced_symbol: Optional[multiplier.ir.Symbol]

  @staticmethod
  def FROM(arg_0: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.RefOp]:
    ...

class DeclRefOp(multiplier.ir.highlevel.RefOp):
  declaration: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.DeclRefOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.DeclRefOp]:
    ...

class EnumRefOp(multiplier.ir.highlevel.RefOp):
  result: multiplier.ir.Value
  value: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.EnumRefOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.EnumRefOp]:
    ...

class FuncRefOp(multiplier.ir.highlevel.RefOp):
  result: multiplier.ir.Value
  function: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.FuncRefOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.FuncRefOp]:
    ...

class GlobalRefOp(multiplier.ir.highlevel.RefOp):
  result: multiplier.ir.Value
  global_: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.GlobalRefOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.GlobalRefOp]:
    ...

class AccessSpecifierOp(multiplier.ir.highlevel.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AccessSpecifierOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AccessSpecifierOp]:
    ...

class AddFAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AddFAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AddFAssignOp]:
    ...

class AddFOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AddFOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AddFOp]:
    ...

class AddIAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AddIAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AddIAssignOp]:
    ...

class AddIOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AddIOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AddIOp]:
    ...

class AddrLabelExprOp(multiplier.ir.highlevel.Operation):
  label: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AddrLabelExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AddrLabelExprOp]:
    ...

class AddressOfOp(multiplier.ir.highlevel.Operation):
  value: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AddressOfOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AddressOfOp]:
    ...

class AlignOfExprOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  expression: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AlignOfExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AlignOfExprOp]:
    ...

class AlignOfTypeOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  argument: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AlignOfTypeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AlignOfTypeOp]:
    ...

class AsmOp(multiplier.ir.highlevel.Operation):
  asm_outputs: Iterable[multiplier.ir.Operand]
  asm_inputs: Iterable[multiplier.ir.Operand]
  labels: Iterable[multiplier.ir.Operand]
  asm_template: str
  is_volatile: bool
  has_goto: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AsmOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AsmOp]:
    ...

class AssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AssignOp]:
    ...

class AttributedStmtOp(multiplier.ir.highlevel.Operation):
  body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.AttributedStmtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.AttributedStmtOp]:
    ...

class BinAShrAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinAShrAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinAShrAssignOp]:
    ...

class BinAShrOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinAShrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinAShrOp]:
    ...

class BinAndAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinAndAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinAndAssignOp]:
    ...

class BinAndOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinAndOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinAndOp]:
    ...

class BinCommaOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinCommaOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinCommaOp]:
    ...

class BinLAndOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  left: multiplier.ir.Region
  right: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinLAndOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinLAndOp]:
    ...

class BinLOrOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  left: multiplier.ir.Region
  right: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinLOrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinLOrOp]:
    ...

class BinLShrAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinLShrAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinLShrAssignOp]:
    ...

class BinLShrOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinLShrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinLShrOp]:
    ...

class BinOrAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinOrAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinOrAssignOp]:
    ...

class BinOrOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinOrOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinOrOp]:
    ...

class BinShlAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinShlAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinShlAssignOp]:
    ...

class BinShlOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinShlOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinShlOp]:
    ...

class BinXorAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinXorAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinXorAssignOp]:
    ...

class BinXorOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinXorOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinXorOp]:
    ...

class BinaryCondOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  common_region: Optional[multiplier.ir.Region]
  condition_region: multiplier.ir.Region
  then_region: multiplier.ir.Region
  else_region: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BinaryCondOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BinaryCondOp]:
    ...

class BreakOp(multiplier.ir.highlevel.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BreakOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BreakOp]:
    ...

class BuiltinBitCastOp(multiplier.ir.highlevel.Operation):
  value: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BuiltinBitCastOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BuiltinBitCastOp]:
    ...

class BuiltinTypesCompatiblePOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  type1: multiplier.ir.Type
  type2: multiplier.ir.Type
  compatible: bool
  arguments: Iterable[multiplier.ir.Type]
  value: Optional[bool]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.BuiltinTypesCompatiblePOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.BuiltinTypesCompatiblePOp]:
    ...

class CStyleCastOp(multiplier.ir.highlevel.Operation):
  value: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.CStyleCastOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.CStyleCastOp]:
    ...

class CallOp(multiplier.ir.highlevel.Operation):
  arg_operands: Iterable[multiplier.ir.Operand]
  results: Iterable[multiplier.ir.Result]
  callee: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.CallOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.CallOp]:
    ...

class CaseOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Region
  body: Optional[multiplier.ir.Region]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.CaseOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.CaseOp]:
    ...

class ChooseExprOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  condition_region: multiplier.ir.Region
  then_region: multiplier.ir.Region
  else_region: multiplier.ir.Region
  cond_true: Optional[bool]
  is_condition_true: Optional[bool]
  is_condition_dependent: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ChooseExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ChooseExprOp]:
    ...

class ClassDeclOp(multiplier.ir.highlevel.Operation):
  bases: multiplier.ir.Region
  fields: multiplier.ir.Region
  name: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ClassDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ClassDeclOp]:
    ...

class CmpOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.CmpOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.CmpOp]:
    ...

class CompoundLiteralOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  initializer: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.CompoundLiteralOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.CompoundLiteralOp]:
    ...

class CondOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  condition_region: multiplier.ir.Region
  then_region: multiplier.ir.Region
  else_region: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.CondOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.CondOp]:
    ...

class CondYieldOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.CondYieldOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.CondYieldOp]:
    ...

class ConstantOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ConstantOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ConstantOp]:
    ...

class ContinueOp(multiplier.ir.highlevel.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ContinueOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ContinueOp]:
    ...

class CxxBaseSpecifierOp(multiplier.ir.highlevel.Operation):
  type: multiplier.ir.Type
  is_virtual: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.CxxBaseSpecifierOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.CxxBaseSpecifierOp]:
    ...

class CxxStructDeclOp(multiplier.ir.highlevel.Operation):
  bases: multiplier.ir.Region
  fields: multiplier.ir.Region
  name: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.CxxStructDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.CxxStructDeclOp]:
    ...

class DefaultOp(multiplier.ir.highlevel.Operation):
  body: Optional[multiplier.ir.Region]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.DefaultOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.DefaultOp]:
    ...

class DerefOp(multiplier.ir.highlevel.Operation):
  addr: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.DerefOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.DerefOp]:
    ...

class DivFAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.DivFAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.DivFAssignOp]:
    ...

class DivFOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.DivFOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.DivFOp]:
    ...

class DivSAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.DivSAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.DivSAssignOp]:
    ...

class DivSOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.DivSOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.DivSOp]:
    ...

class DivUAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.DivUAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.DivUAssignOp]:
    ...

class DivUOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.DivUOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.DivUOp]:
    ...

class DoOp(multiplier.ir.highlevel.Operation):
  body_region: multiplier.ir.Region
  condition_region: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.DoOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.DoOp]:
    ...

class EmptyDeclOp(multiplier.ir.highlevel.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.EmptyDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.EmptyDeclOp]:
    ...

class EnumConstantOp(multiplier.ir.highlevel.Operation):
  initializer: multiplier.ir.Region
  name: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.EnumConstantOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.EnumConstantOp]:
    ...

class EnumDeclOp(multiplier.ir.highlevel.Operation):
  constants: multiplier.ir.Region
  name: str
  type: Optional[multiplier.ir.Type]
  is_complete: bool
  constants_block: multiplier.ir.Block

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.EnumDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.EnumDeclOp]:
    ...

class ExprOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  nested_expression: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ExprOp]:
    ...

class ExtensionOp(multiplier.ir.highlevel.Operation):
  value: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ExtensionOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ExtensionOp]:
    ...

class FCmpOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.FCmpOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.FCmpOp]:
    ...

class FieldDeclOp(multiplier.ir.highlevel.Operation):
  name: str
  type: multiplier.ir.Type
  bits: Optional[int]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.FieldDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.FieldDeclOp]:
    ...

class FileScopeAsmOp(multiplier.ir.highlevel.Operation):
  assembly: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.FileScopeAsmOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.FileScopeAsmOp]:
    ...

class ForOp(multiplier.ir.highlevel.Operation):
  condition_region: multiplier.ir.Region
  incr_region: Optional[multiplier.ir.Region]
  body_region: Optional[multiplier.ir.Region]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ForOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ForOp]:
    ...

class FuncOp(multiplier.ir.highlevel.Operation):
  body: Optional[multiplier.ir.Region]
  name: str
  function_type: multiplier.ir.Type
  visibility: Optional[str]
  is_var_arg: bool
  callable_results: Iterable[multiplier.ir.Type]
  argument_types: Iterable[multiplier.ir.Type]
  result_types: Iterable[multiplier.ir.Type]
  is_declaration: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.FuncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.FuncOp]:
    ...

class GenericAssocExprOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  body: multiplier.ir.Region
  match_type: Optional[multiplier.ir.Type]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.GenericAssocExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.GenericAssocExprOp]:
    ...

class GenericSelectionExprOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  control: multiplier.ir.Region
  body: multiplier.ir.Region
  control_type: Optional[multiplier.ir.Type]
  is_expression_predicate: bool
  is_type_predicate: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.GenericSelectionExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.GenericSelectionExprOp]:
    ...

class GotoStmtOp(multiplier.ir.highlevel.Operation):
  label: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.GotoStmtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.GotoStmtOp]:
    ...

class IfOp(multiplier.ir.highlevel.Operation):
  condition_region: multiplier.ir.Region
  then_region: multiplier.ir.Region
  else_region: Optional[multiplier.ir.Region]
  has_else: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.IfOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.IfOp]:
    ...

class ImagOp(multiplier.ir.highlevel.Operation):
  argument: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ImagOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ImagOp]:
    ...

class ImplicitCastOp(multiplier.ir.highlevel.Operation):
  value: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ImplicitCastOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ImplicitCastOp]:
    ...

class IndirectCallOp(multiplier.ir.highlevel.Operation):
  callee: multiplier.ir.Value
  arg_operands: Iterable[multiplier.ir.Operand]
  results: Iterable[multiplier.ir.Result]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.IndirectCallOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.IndirectCallOp]:
    ...

class IndirectGotoStmtOp(multiplier.ir.highlevel.Operation):
  target: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.IndirectGotoStmtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.IndirectGotoStmtOp]:
    ...

class InitListExprOp(multiplier.ir.highlevel.Operation):
  elements: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.InitListExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.InitListExprOp]:
    ...

class InitializedConstantOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  initializer: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.InitializedConstantOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.InitializedConstantOp]:
    ...

class LNotOp(multiplier.ir.highlevel.Operation):
  argument: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.LNotOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.LNotOp]:
    ...

class LabelDeclOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  name: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.LabelDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.LabelDeclOp]:
    ...

class LabelStmtOp(multiplier.ir.highlevel.Operation):
  label: multiplier.ir.Value
  body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.LabelStmtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.LabelStmtOp]:
    ...

class MinusOp(multiplier.ir.highlevel.Operation):
  argument: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.MinusOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.MinusOp]:
    ...

class MulFAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.MulFAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.MulFAssignOp]:
    ...

class MulFOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.MulFOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.MulFOp]:
    ...

class MulIAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.MulIAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.MulIAssignOp]:
    ...

class MulIOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.MulIOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.MulIOp]:
    ...

class NotOp(multiplier.ir.highlevel.Operation):
  argument: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.NotOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.NotOp]:
    ...

class NullStmtOp(multiplier.ir.highlevel.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.NullStmtOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.NullStmtOp]:
    ...

class OffsetOfExprOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  array_index_exprs: Iterable[multiplier.ir.Region]
  source: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.OffsetOfExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.OffsetOfExprOp]:
    ...

class OpaqueValueExprOp(multiplier.ir.highlevel.Operation):
  argument: Iterable[multiplier.ir.Operand]
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.OpaqueValueExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.OpaqueValueExprOp]:
    ...

class PlusOp(multiplier.ir.highlevel.Operation):
  argument: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.PlusOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.PlusOp]:
    ...

class PostDecOp(multiplier.ir.highlevel.Operation):
  argument: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.PostDecOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.PostDecOp]:
    ...

class PostIncOp(multiplier.ir.highlevel.Operation):
  argument: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.PostIncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.PostIncOp]:
    ...

class PreDecOp(multiplier.ir.highlevel.Operation):
  argument: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.PreDecOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.PreDecOp]:
    ...

class PreIncOp(multiplier.ir.highlevel.Operation):
  argument: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.PreIncOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.PreIncOp]:
    ...

class PredefinedExprOp(multiplier.ir.highlevel.Operation):
  value: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.PredefinedExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.PredefinedExprOp]:
    ...

class PreferredAlignOfExprOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  expression: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.PreferredAlignOfExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.PreferredAlignOfExprOp]:
    ...

class PreferredAlignOfTypeOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  argument: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.PreferredAlignOfTypeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.PreferredAlignOfTypeOp]:
    ...

class RealOp(multiplier.ir.highlevel.Operation):
  argument: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.RealOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.RealOp]:
    ...

class RecordMemberOp(multiplier.ir.highlevel.Operation):
  record: multiplier.ir.Value
  element: multiplier.ir.Value
  field: str

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.RecordMemberOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.RecordMemberOp]:
    ...

class RemFAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.RemFAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.RemFAssignOp]:
    ...

class RemFOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.RemFOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.RemFOp]:
    ...

class RemSAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.RemSAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.RemSAssignOp]:
    ...

class RemSOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.RemSOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.RemSOp]:
    ...

class RemUAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.RemUAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.RemUAssignOp]:
    ...

class RemUOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.RemUOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.RemUOp]:
    ...

class ReturnOp(multiplier.ir.highlevel.Operation):
  result: Iterable[multiplier.ir.Operand]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ReturnOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ReturnOp]:
    ...

class SizeOfExprOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  expression: multiplier.ir.Region
  value: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.SizeOfExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.SizeOfExprOp]:
    ...

class SizeOfTypeOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  argument: multiplier.ir.Type
  value: int

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.SizeOfTypeOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.SizeOfTypeOp]:
    ...

class StaticAssertDeclOp(multiplier.ir.highlevel.Operation):
  assertion: multiplier.ir.Region
  message: multiplier.ir.Region
  failed: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.StaticAssertDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.StaticAssertDeclOp]:
    ...

class StmtExprOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  nested_statement: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.StmtExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.StmtExprOp]:
    ...

class StructDeclOp(multiplier.ir.highlevel.Operation):
  fields: multiplier.ir.Region
  name: str
  field_types: Iterable[multiplier.ir.Type]
  defined_type: multiplier.ir.Type
  is_complete_definition: bool
  fields_block: multiplier.ir.Block

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.StructDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.StructDeclOp]:
    ...

class SubFAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.SubFAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.SubFAssignOp]:
    ...

class SubFOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.SubFOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.SubFOp]:
    ...

class SubIAssignOp(multiplier.ir.highlevel.Operation):
  source: multiplier.ir.Value
  destination: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.SubIAssignOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.SubIAssignOp]:
    ...

class SubIOp(multiplier.ir.highlevel.Operation):
  left: multiplier.ir.Value
  right: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.SubIOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.SubIOp]:
    ...

class SubscriptOp(multiplier.ir.highlevel.Operation):
  array: multiplier.ir.Value
  index: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.SubscriptOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.SubscriptOp]:
    ...

class SwitchOp(multiplier.ir.highlevel.Operation):
  condition_region: multiplier.ir.Region
  cases: Iterable[multiplier.ir.Region]

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.SwitchOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.SwitchOp]:
    ...

class ThisOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ThisOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ThisOp]:
    ...

class TranslationUnitOp(multiplier.ir.highlevel.Operation):
  body: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.TranslationUnitOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.TranslationUnitOp]:
    ...

class TypeAliasOp(multiplier.ir.highlevel.Operation):
  name: str
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.TypeAliasOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.TypeAliasOp]:
    ...

class TypeDeclOp(multiplier.ir.highlevel.Operation):
  name: str
  type: multiplier.ir.Type
  defined_type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.TypeDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.TypeDeclOp]:
    ...

class TypeDefOp(multiplier.ir.highlevel.Operation):
  name: str
  type: multiplier.ir.Type
  defined_type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.TypeDefOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.TypeDefOp]:
    ...

class TypeOfExprOp(multiplier.ir.highlevel.Operation):
  expression: multiplier.ir.Region
  name: str
  type: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.TypeOfExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.TypeOfExprOp]:
    ...

class TypeYieldOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  yielded: multiplier.ir.Type

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.TypeYieldOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.TypeYieldOp]:
    ...

class UnionDeclOp(multiplier.ir.highlevel.Operation):
  fields: multiplier.ir.Region
  name: str
  field_types: Iterable[multiplier.ir.Type]
  defined_type: multiplier.ir.Type
  is_complete_definition: bool
  fields_block: multiplier.ir.Block

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.UnionDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.UnionDeclOp]:
    ...

class UnreachableOp(multiplier.ir.highlevel.Operation):

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.UnreachableOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.UnreachableOp]:
    ...

class VAArgExprOp(multiplier.ir.highlevel.Operation):
  argument_list: multiplier.ir.Value
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.VAArgExprOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.VAArgExprOp]:
    ...

class ValueYieldOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.ValueYieldOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.ValueYieldOp]:
    ...

class VarDeclOp(multiplier.ir.highlevel.Operation):
  result: multiplier.ir.Value
  initializer: Optional[multiplier.ir.Region]
  allocation_size: Optional[multiplier.ir.Region]
  name: str
  has_local_storage: bool
  is_local_variable_declaration: bool
  is_static_local_variable_declaration: bool
  has_external_storage: bool
  has_global_storage: bool
  is_static_data_member: bool
  is_in_file_context: bool
  is_in_function_or_method_context: bool
  is_in_record_context: bool
  is_file_variable_declaration: bool

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.VarDeclOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.VarDeclOp]:
    ...

class WhileOp(multiplier.ir.highlevel.Operation):
  condition_region: multiplier.ir.Region
  body_region: multiplier.ir.Region

  @staticmethod
  def static_kind() -> multiplier.ir.OperationKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Operation) -> Optional[multiplier.ir.highlevel.WhileOp]:
    ...

  @staticmethod
  def producing(val: multiplier.ir.Value) -> Optional[multiplier.ir.highlevel.WhileOp]:
    ...

class Type(multiplier.ir.Type):

  @staticmethod
  def FROM(arg_0: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.Type]:
    ...

class RecordType(multiplier.ir.highlevel.Type):
  name: str

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.RecordType]:
    ...

class EnumType(multiplier.ir.highlevel.Type):
  name: str

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.EnumType]:
    ...

class TypedefType(multiplier.ir.highlevel.Type):
  name: str

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.TypedefType]:
    ...

class ElaboratedType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.ElaboratedType]:
    ...

class LabelType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.LabelType]:
    ...

class ParenType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.ParenType]:
    ...

class LValueType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.LValueType]:
    ...

class RValueType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.RValueType]:
    ...

class VoidType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.VoidType]:
    ...

class BoolType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.BoolType]:
    ...

class CharType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.CharType]:
    ...

class ShortType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.ShortType]:
    ...

class IntType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.IntType]:
    ...

class LongType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.LongType]:
    ...

class LongLongType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.LongLongType]:
    ...

class Int128Type(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.Int128Type]:
    ...

class HalfType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.HalfType]:
    ...

class BFloat16Type(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.BFloat16Type]:
    ...

class FloatType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.FloatType]:
    ...

class DoubleType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.DoubleType]:
    ...

class LongDoubleType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.LongDoubleType]:
    ...

class Float128Type(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.Float128Type]:
    ...

class ComplexType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.ComplexType]:
    ...

class PointerType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.PointerType]:
    ...

class ArrayType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.ArrayType]:
    ...

class VectorType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.VectorType]:
    ...

class DecayedType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.DecayedType]:
    ...

class AttributedType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.AttributedType]:
    ...

class AdjustedType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.AdjustedType]:
    ...

class ReferenceType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.ReferenceType]:
    ...

class TypeOfExprType(multiplier.ir.highlevel.Type):
  name: str

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.TypeOfExprType]:
    ...

class TypeOfTypeType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.TypeOfTypeType]:
    ...

class AutoType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.AutoType]:
    ...

class AtomicType(multiplier.ir.highlevel.Type):

  @staticmethod
  def static_kind() -> multiplier.ir.TypeKind:
    ...

  @staticmethod
  def FROM(that: multiplier.ir.Type) -> Optional[multiplier.ir.highlevel.AtomicType]:
    ...
