# Copyright 2024, Peter Goodman. All rights reserved.

"""
This program does some lightweight analysis of uses of structure fields and
function parameters, and tries to produce a new version of the codebase
annotated with the `mutable` keyword (or an alternate annotation via
`--annotation`) to highlight where we think an LLM needs to be hinted to use
Rust's `mut` keyword when prompting for a C to Rust conversion.
"""

import argparse
import os
import pathlib
from typing import Set, List, Optional

import multiplier as mx


MUTABLE_KINDS = (mx.BuiltinReferenceKind.WRITES_VALUE,
                 mx.BuiltinReferenceKind.UPDATES_VALUE,
                 mx.BuiltinReferenceKind.TAKES_ADDRESS)


def contained_in_function(stmt: Optional[mx.ast.Stmt]) -> bool:
    if stmt is None:
        return False

    parent_decl = stmt.parent_declaration
    while parent_decl is not None:
        if isinstance(parent_decl, mx.ast.FunctionDecl):
            return True
        parent_decl = parent_decl.parent_declaration

    return False


def field_might_be_mutable(field: mx.ast.FieldDecl):
    global MUTABLE_KINDS
    for ref in mx.Reference.to(field):
        if brk := ref.builtin_reference_kind:
            if brk in MUTABLE_KINDS:
                if contained_in_function(ref.as_statement):
                    return True
    return False


def find_mutable_fields(index: mx.Index) -> List[mx.ast.FieldDecl]:
    changed = False
    next_record_fields: List[mx.ast.FieldDecl] = []
    mutable_field_ids: Set[int] = set()
    mutable_fields: List[mx.ast.FieldDecl] = []

    for field in mx.ast.FieldDecl.IN(index):
        if field_might_be_mutable(field):
            mutable_field_ids.add(field.id)
            mutable_fields.append(field)
            changed = True
            continue

        fty = field.type.unqualified_desugared_type
        if isinstance(fty, mx.ast.RecordType):
            next_record_fields.append(field)

    while changed and len(next_record_fields):
        changed = False
        record_fields, next_record_fields = next_record_fields, []

        for field in record_fields:
            field_id: int = field.id
            if field_id in mutable_field_ids:
                continue

            record: mx.ast.RecordDecl = field.type.unqualified_desugared_type.declaration
            for nested_field in record.fields:
                nested_field_id = nested_field.id
                if nested_field_id in mutable_field_ids:
                    changed = True
                    mutable_field_ids.add(field_id)
                    mutable_fields.append(field)
                    break
            else:
                next_record_fields.append(field)

    return mutable_fields


def non_constant_type(type: mx.ast.Type) -> Optional[mx.ast.Type]:
    if isinstance(type, mx.ast.QualifiedType):
        if type.is_const_qualified or type.is_constant:
            return None
    return type.unqualified_desugared_type


def non_const_element_type(type: mx.ast.Type, fallback: Optional[mx.ast.Type] = None) -> Optional[mx.ast.Type]:
    if isinstance(type, (mx.ast.PointerType, mx.ast.ReferenceType)):
        if followed := non_constant_type(type.pointee_type):
            return non_const_element_type(followed, followed)
    elif isinstance(type, mx.ast.ArrayType):
        if followed := non_constant_type(type.element_type):
            return non_const_element_type(followed, followed)
    else:
        return fallback


def find_mutable_annotation_sites(
    index: mx.Index, mutable_fields: List[mx.ast.FieldDecl]) -> Set[int]:

    annotation_sites: Set[int] = set()

    # Find the IDs of all records with mutable fields.
    record_ids: Set[int] = set()
    for field in mutable_fields:
        fty = field.type

        # Focus on making value records, or pointers/arrays of records mutabls.
        backup_ty: Optional[mx.ast.Type] = non_constant_type(field.type)
        if not isinstance(backup_ty, mx.ast.RecordType):
            backup_ty = None

        if non_const_element_type(fty, backup_ty) is not None:
            if tok := field.tokens.file_tokens.front:
                annotation_sites.add(tok.id)

        for redecl_record in field.parent_declaration.redeclarations:
            record_ids.add(redecl_record.id)

    for param in mx.ast.ParmVarDecl.IN(index):
        if ety := non_const_element_type(param.type):
            if isinstance(ety, mx.ast.RecordType):
                if ety.declaration.id in record_ids:
                    if tok := param.tokens.file_tokens.front:
                        annotation_sites.add(tok.id)

    return annotation_sites


def annotate_code(index: mx.Index, root_path: pathlib.PurePath, annotation: str):
    annotation_sites = find_mutable_annotation_sites(index, find_mutable_fields(index))
    for file in mx.frontend.File.IN(index):

        # Reproduce the code of this file, with `mutable ` injected in before
        # mutable parameters and mutable fields.
        token_datas: List[str] = []
        for tok in file.tokens:
            tok_id: int = tok.id
            if tok_id in annotation_sites:
                token_datas.append(annotation)
            token_datas.append(tok.data)

        annotated_code: str = "".join(token_datas)

        # For each path associated with this file, write a version of the
        # annotated file.
        for path in file.paths:
            nested = root_path / pathlib.PurePath("." + str(path))
            nested_dir = nested.parent
            os.makedirs(nested_dir, exist_ok=True)
            with open(str(nested), "w") as annotated_file:
                annotated_file.write(annotated_code)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Annotate parameter and field declarations as mutable")
    parser.add_argument('--db', type=str,
                        required=True,
                        help="Path to mx-index-produced database")

    parser.add_argument('--out_dir', type=str, required=True,
                        help="The output directory into which to place the modified codebase")
    parser.add_argument('--annotation', type=str, default='mutable',
                        help="The annotation to inject before function parameters and structure fields.")

    args = parser.parse_args()
    index = mx.Index.in_memory_cache(mx.Index.from_database(args.db))
    annotate_code(index, pathlib.PosixPath(args.out_dir), f"{args.annotation} ")
