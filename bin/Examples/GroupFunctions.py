#
# Copyright (c) 2024-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

"""
This program approximately groups functions by their types, and then prints
out the grouped functions.

XREF: https://x.com/eatonphil/status/1821573274582823247
"""

import argparse
import collections
from typing import List, DefaultDict, Set, Optional, Iterable

import multiplier as mx


def sep(out: List[str], prev_out_len: int, tok: str):
    if len(out) != prev_out_len:
        out.append(tok)


def mangle(ty: mx.ast.Type, out: List[str],
           strip_trivial_qualifiers: bool = False,
           func: Optional[mx.ast.FunctionDecl] = None) -> None:

    # TODO(pag): Look into throwing, `const`-qualified methods, etc.
    if isinstance(ty, mx.ast.FunctionType):
        out.append("Func(")
        out_len = len(out)

        # Try to inject the `this` pointer type.
        if isinstance(func, mx.ast.CXXMethodDecl):
            if this_ty := func.this_type:
                mangle(this_ty, out, False)

        if isinstance(ty, mx.ast.FunctionProtoType):
            for pty in ty.parameter_types:
                sep(out, out_len, ", ")
                mangle(pty, out, True)
            if ty.is_variadic:
                sep(out, out_len, ", ")
                out.append("...")
        else:
            sep(out, out_len, ", ")
            out.append("...")
        out.append("; ")
        mangle(ty.return_type, out, True)
        out.append(")")

    elif isinstance(ty, mx.ast.QualifiedType):
        bty = ty.unqualified_desugared_type

        # Try to double check if we think we should ignore trivial qualifiers.
        # The idea here is that if you have two functions, one taking an `int`
        # parameter, and the other taking a `const int` parameter, then their
        # prototypes are functionally identical. The `const` qualifier really
        # only impacts whether or not the bodies of those functions can assign
        # to those parameters.
        #
        # Similarly, we always want to strip off a `const` qualified on
        # something like an `int` return type, because `const` on the return
        # type is mostly meaningless.
        if strip_trivial_qualifiers:
            if isinstance(bty, mx.ast.PointerType):
                if not isinstance(bty.pointee_type, mx.ast.FunctionType):
                    strip_trivial_qualifiers = False
            elif isinstance(bty, mx.ast.ReferenceType):
                strip_trivial_qualifiers = False

        if not strip_trivial_qualifiers:
            out_len = len(out)
            if ty.is_const_qualified:
                out.append("C")
            if ty.is_restrict_qualified:
                out.append("V")
            if ty.is_restrict_qualified:
                out.append("R")
            if ty.has_address_space:
                out.append(f"-{ty.address_space.name}")
            sep(out, out_len, " ")
        mangle(bty, out, False)

    elif isinstance(ty, mx.ast.BuiltinType):
        out.append(str(ty.builtin_kind.name))

    elif isinstance(ty, mx.ast.TypedefType):
        mangle(ty.declaration.underlying_type, out, strip_trivial_qualifiers)

    elif isinstance(ty, mx.ast.UsingType):
        mangle(ty.underlying_type, out, strip_trivial_qualifiers)

    elif isinstance(ty, mx.ast.TagType):
        decl = ty.declaration.canonical_declaration
        out.append(f"{decl.kind.name}({decl.id})")

    elif isinstance(ty, mx.ast.AtomicType):
        out.append("Atomic(")
        mangle(ty.value_type, out, False)
        out.append(")")

    # NOTE(pag): Ignores all the derived classes.
    elif isinstance(ty, mx.ast.VectorType):
        out.append("Vector(")
        mangle(ty.element_type, out, False)
        out.append(", ")
        out.append(ty.vector_kind.name)
        out.append(")")

    # NOTE(pag): Ignores all the derived classes.
    elif isinstance(ty, mx.ast.ArrayType):
        out.append("Array(")
        mangle(ty.element_type, out, False)
        out.append(", ")
        out.append(ty.size_modifier.name)
        out.append(")")

    elif isinstance(ty, mx.ast.TemplateSpecializationType):
        if aliased_ty := ty.aliased_type:
            mangle(aliased_ty, out, strip_trivial_qualifiers)
        else:
            out.append("?")

    elif isinstance(ty, (mx.ast.PointerType, mx.ast.ReferenceType)):
        name = ty.__class__.__name__[:-4]
        out.append(f"{name}(")
        mangle(ty.pointee_type, out, False)
        out.append(")")

    elif isinstance(ty, mx.ast.ParenType):
        mangle(ty.inner_type, out, strip_trivial_qualifiers)

    elif isinstance(ty, mx.ast.MacroQualifiedType):
        mangle(ty.underlying_type, out, strip_trivial_qualifiers)

    else:
        if ty.__class__.__name__.startswith("Dependent"):
            raise Exception("Ignoring dependent types")

        # TODO(pag): Add more.
        out.append(ty.kind.name)


def canon_type(ty: mx.ast.Type, out: List):
    if isinstance(ty, mx.ast.FunctionType):
        out.append(ty.kind)


def group_functions_by_type(index: mx.Index | str) -> List[List[int]]:
    grouped_functions: DefaultDict[str, List[int]] = collections.defaultdict(
        list)
    seen: Set[int] = set()

    if isinstance(index, str):
        index = mx.Index.in_memory_cache(mx.Index.from_database(args.db))

    # Iterate over all functions in the project, and group them by a form of their
    # mangled type.
    for func in mx.ast.FunctionDecl.IN(index):
        func = func.canonical_declaration

        # Don't repeat more of the same function.
        func_id = func.id
        if func_id in seen:
            continue

        seen.add(func_id)

        out: List[str] = []
        try:
            mangle(func.type, out, False, func)

        # Likely a dependent type, i.e. an unspecialized function template, or a
        # function inside of a template. We can't reliably compare dependent
        # function types.
        except:
            continue

        type_str: str = "".join(out)
        grouped_functions[type_str].append(func.id)

    return list(grouped_functions.values())


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Multiplier Code Browser")
    parser.add_argument('--db', type=str,
                        required=True,
                        help="Path to mx-index-produced database")
    args = parser.parse_args()
    index = mx.Index.in_memory_cache(mx.Index.from_database(args.db))
    name_config = mx.ast.QualifiedNameRenderOptions(fully_qualified=True)
    flc = mx.frontend.FileLocationCache()
    first = True

    # Dump out the groups functions.
    for funcs in group_functions_by_type(index):

        # Skip groups with only one function
        if len(funcs) == 1:
            continue

        if not first:
            print()
            print("///////////////////////////////////////////////////////////////")

        first = False
        nested_first = True

        for func_id in funcs:
            func = index.declaration(func_id)
            func_file_toks = func.tokens.file_tokens

            if not nested_first:
                print()

            nested_first = False

            # Get the fully qualified name. This will let the human distinguish
            # methods.
            func_name = func.qualified_name(name_config).data

            # Print out the name and optionally the location of the function. The
            # function's name as printed may appear different than what shows up
            # in the code snippet below. This can happen if one function has an
            # `alias` attribute for another, or if the definition of the function
            # in the file is actually subject to macro substitution.
            first_tok = func_file_toks.front
            if file := mx.frontend.File.containing(first_tok):
                path = str(next(file.paths))
                if line_col := first_tok.location(flc):
                    print(f"// \t{func_name} @ {path}:{line_col[0]}:{line_col[1]}")
                else:
                    print(f"// \t{func_name} @ {path}")
            else:
                print(f"// \t{func_name}")

            # If we're dealing with the function definition, then try to chop the
            # printing off at the beginning of the function's body.
            max_index = func_file_toks.size
            if body := func.body:
                if body_index := func_file_toks.index_of(body.tokens.file_tokens.front):
                    max_index = body_index

            # Render out the tokens (as they appear in the file), except doubly
            # indendet.
            token_datas: List[str] = ["\t\t"]
            for i, tok in enumerate(func_file_toks):
                if i >= max_index:
                    break
                token_datas.append(tok.data)
            print("".join(token_datas).replace("\n", "\n\t\t"))
