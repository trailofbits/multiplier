"""Analyzes a Qt codebase to identify signal/slot relationships."""

import argparse
import multiplier as mx
import sys
from typing import List, Optional, Iterable, Set, Tuple


def debug(data: str, *args):
    print(data.format(*args), file=sys.stderr)


def debug_if(cond: bool, data: str, *args):
    if cond:
        print(data.format(*args), file=sys.stderr)


def find_qmetaobject_activate(index: mx.Index, seen: Set[int]) -> Iterable[mx.ast.CXXMethodDecl]:
    """Finds `QMetaObject::activate`. There are ~3 methods."""
    found = False
    for ent in index.query_entities("QMetaObject"):
        if not isinstance(ent, mx.ast.CXXRecordDecl) or not ent.is_definition:
            continue

        methods = ent.methods
        if methods is None:
            continue

        # Don't repeat visiting the class.
        canon_id = ent.canonical_declaration.id
        if canon_id in seen:
            continue
        seen.add(canon_id)

        for meth in methods:
            assert isinstance(meth, mx.ast.CXXMethodDecl)
            if not meth.is_instance and meth.name == "activate":
                yield meth
                found = True

    debug_if(not found, "Failed to find QMetaObject::activate")


def find_signals(activate: mx.ast.CXXMethodDecl, seen: Set[int]) -> Iterable[mx.ast.CXXMethodDecl]:
    """Given that `activate` is the method `QMetaObject::activate`, we go and find all call sites of
    this method, and those correspond to implementations of signal methods."""
    for call in activate.callers:
        caller = call.parent_declaration
        if not isinstance(caller, mx.ast.CXXMethodDecl) or not caller.is_definition or not caller.is_out_of_line:
            debug("Found non-method caller of QMetaObject::activate: {}", " ".join(t.data for t in caller.tokens))
            continue

        # Don't repeatedly visit the same function
        caller_id: int = caller.id
        if caller_id in seen:
            continue

        seen.add(caller_id)

        # Signals methods don't return anything.
        assert isinstance(caller.return_type, mx.ast.BuiltinType), f"Return type kind is {caller.return_type.kind.name}"
        assert caller.return_type.builtin_kind == mx.ast.BuiltinTypeKind.VOID, f"Return builtin kind name is {caller.return_type.builtin_kind.name}"

        # The fragment must be part of a file.
        containing_file = mx.frontend.File.containing(caller)
        if not isinstance(containing_file, mx.frontend.File):
            continue

        # Signals are implemented in file paths that look like:
        # /path/to/code/<cmake_target>_autogen/<id>/moc_<file name>
        path = str(next(containing_file.paths))
        if "moc_" not in path or "_autogen" not in path:
            continue

        yield caller


def find_qobject_connect(index: mx.Index, seen: Set[int]) -> Iterable[mx.ast.CXXMethodDecl]:
    """Finds `QObject::connect`. There are ~2 static methods, and a bunch of templates."""
    found = False
    impls: List[mx.ast.CXXMethodDecl] = []
    for ent in index.query_entities("QObject"):
        if not isinstance(ent, mx.ast.CXXRecordDecl) or not ent.is_definition:
            continue

        methods = ent.methods
        if methods is None:
            continue

        # Don't repeat visiting the class.
        canon_id = ent.canonical_declaration.id
        if canon_id in seen:
            continue
        seen.add(canon_id)

        for meth in methods:
            assert isinstance(meth, mx.ast.CXXMethodDecl)
            if meth.is_instance:
                continue

            rt: mx.ast.Type = meth.return_type
            if not isinstance(rt, mx.ast.RecordType):
                continue

            # The return type of `QObject::connect` and `QObject::connectImpl` should be
            # `QMetaObject::Connection`.
            rt_decl = rt.declaration
            if not isinstance(rt_decl, mx.ast.CXXRecordDecl) or rt_decl.name != "Connection":
                continue

            if meth.name == "connect":
                seen.add(meth.id)
                yield meth

            # `QObject::connectImpl` is called by the template specializations of `QObject::connect`.
            elif meth.name == "connectImpl":
                impls.append(meth)

    # Template specializations of `QObject::connect` call `QObject::connectImpl`, go find those.
    for impl in impls:
        for call in impl.callers:
            caller = call.parent_declaration
            if not isinstance(caller, mx.ast.CXXMethodDecl):
                continue

            if caller.name != "connect":
                continue

            # Don't repeat visiting the class.
            caller_id = caller.id
            if caller_id in seen:
                continue

            seen.add(caller_id)
            yield caller
            found = True

    debug_if(not found, "Failed to find QObject::connect")


# def looks_like_connect(func: mx.ast.FunctionDecl):
#     if func.name != "connect":
#         return False
#     print("!!!")
#     parent_frag = mx.Fragment.containing(func).parent
#     if parent_frag is None:
#         return False
#
#     print("???")
#     for tld in parent_frag.top_level_declarations:
#         print("+++" + tld.name)
#         if isinstance(tld, mx.ast.CXXRecordDecl) and tld.name == "QObject":
#             return True
#         elif isinstance(tld, mx.ast.FunctionDecl) and looks_like_connect(tld):
#             return True
#
#     print("---")
#     return False


def find_connections(connect: mx.ast.CXXMethodDecl, seen: Set[int]) -> Iterable[Tuple[mx.ast.CXXMethodDecl, mx.ast.CXXMethodDecl]]:
    """Given calls to `connect`, go and find the (signal, slot) or (signal, signal) pairs."""
    for call in connect.callers:
        if not isinstance(call, mx.ast.CallExpr):
            continue

        containing_func = call.parent_declaration
        if not isinstance(containing_func, mx.ast.FunctionDecl):
            pass

        # # One `QObject::connect` calling another.
        # if looks_like_connect(containing_func):
        #     print("Connect in connect!")
        #     continue

        input_signal: Optional[mx.ast.CXXMethodDecl] = None

        signal_method = call.nth_argument(1).ignore_casts
        signal_method_type = signal_method.type
        if isinstance(signal_method_type, mx.ast.SubstTemplateTypeParmType):
            signal_method_type = signal_method_type.replacement_type

        print((signal_method.kind.name, signal_method_type.kind.name))

        # New style: The argument is a member pointer to a signal method.
        if isinstance(signal_method_type, mx.ast.MemberPointerType):
            assert isinstance(signal_method, mx.ast.UnaryOperator)
            assert signal_method.opcode == mx.ast.UnaryOperatorKind.ADDRESS_OF
            print(signal_method.sub_expression.kind.name)

        # Old style using a string literal.
        elif isinstance(signal_method_type, mx.ast.PointerType) and \
             isinstance(signal_method_type.pointee_type.unqualified_type, mx.ast.BuiltinType) and \
             signal_method_type.pointee_type.unqualified_type.builtin_kind in (mx.ast.BuiltinTypeKind.CHARACTER_S,
                                                                               mx.ast.BuiltinTypeKind.CHARACTER_U):

            if isinstance(signal_method, mx.ast.StringLiteral):
                debug("Unhandled string literal signal argument '{}' to connect",
                      " ".join(t.data for t in signal_method.tokens))
            elif isinstance(signal_method, mx.ast.DeclRefExpr) and \
                 isinstance(signal_method.referenced_declaration, mx.ast.ParmVarDecl):
                debug("Unhandled parameter variable signal argument '{}' to connect",
                      " ".join(t.data for t in signal_method.tokens))
            else:
                debug("Unhandled string-typed signal argument '{}' to connect",
                      " ".join(t.data for t in signal_method.tokens))
        # Something else.
        else:
            debug("Unhandled signal argument '{}' with type '{}' to connect",
                  " ".join(t.data for t in signal_method.tokens),
                  signal_method.type.kind.name)
            continue
        yield 1, 1


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--db", type=str, required=True, help="Path to the database")
    args = parser.parse_args()
    index = mx.Index.in_memory_cache(mx.Index.from_database(args.db))
    seen: Set[int] = set()

    for activate in find_qmetaobject_activate(index, seen):
        for signal in find_signals(activate, seen):
            pass

    for connect in find_qobject_connect(index, seen):
        for slot, signal in find_connections(connect, seen):
            pass

    return 0


if __name__ == "__main__":
    sys.exit(main())
