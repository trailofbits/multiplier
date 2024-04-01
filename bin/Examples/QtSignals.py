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
            debug(f"Found non-method caller {caller.id} of QMetaObject::activate of kind {caller.kind.name}")
            continue

        assert caller.is_out_of_line, "Signals are expected to be defined out-of-line"

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

        # # Signals are implemented in file paths that look like:
        # # /path/to/code/<cmake_target>_autogen/<id>/moc_<file name>
        # path = str(next(containing_file.paths))
        # if "moc_" not in path or "_autogen" not in path:
        #     continue

        yield caller


def find_connects(decl: mx.ast.NamedDecl) -> Iterable[mx.ast.CXXMethodDecl]:
    """Given that `decl` is named `connect, go and yield back `decl` if it is a method, otherwise if it's a
    template, then yield out the specializations."""
    if isinstance(decl, mx.ast.CXXMethodDecl) and not decl.is_instance:
        yield decl
        return

    if not isinstance(decl, mx.ast.FunctionTemplateDecl):
        return

    for meth in decl.specializations:
        assert isinstance(meth, mx.ast.CXXMethodDecl)
        assert not meth.is_instance
        yield meth


def find_qobject_connect(index: mx.Index, seen: Set[int]) -> Iterable[mx.ast.CXXMethodDecl]:
    """Finds `QObject::connect`. There are ~2 static methods, and a bunch of templates."""
    found = False
    for ent in index.query_entities("QObject"):
        if not isinstance(ent, mx.ast.CXXRecordDecl) or not ent.is_definition:
            continue

        # Go through all declarations in the class body. We want to see methods and function templates, as most
        # definitions of `connect` are actually method templates.
        for decl in ent.declarations_in_context:
            if not isinstance(decl, mx.ast.NamedDecl) or decl.name != "connect":
                continue

            for meth in find_connects(decl):
                canon_id = meth.canonical_declaration.id
                if canon_id in seen:
                    continue

                seen.add(canon_id)

                # There should be between three and four arguments. The three argument form is something like:
                # `connect(sender, signal, receiver_lambda)`, and the four argument form is something like:
                # `connect(sender, signal, receiver, slot)`. There is a 5-argument form, with a connection type as
                # well.
                if 3 > meth.num_parameters:
                    continue

                rt: mx.ast.Type = meth.return_type
                if not isinstance(rt, mx.ast.RecordType):
                    continue

                # The return type of `QObject::connect` and `QObject::connectImpl` should be
                # `QMetaObject::Connection`.
                rt_decl = rt.declaration
                if not isinstance(rt_decl, mx.ast.CXXRecordDecl) or rt_decl.name != "Connection":
                    continue

                yield meth
                found = True

    # NOTE(pag): We can also find implementations of `connect` via calls to `QObject::connectImpl`.
    debug_if(not found, "Failed to find QObject::connect")


def referenced_method(expr: mx.ast.Expr) -> Optional[mx.ast.CXXMethodDecl]:
    """Return the method that is addressed by an expression of the form `&Class::Method`."""
    if not isinstance(expr.type, mx.ast.MemberPointerType):
        return None

    if not isinstance(expr, mx.ast.UnaryOperator):
        return None

    if expr.opcode != mx.ast.UnaryOperatorKind.ADDRESS_OF:
        return None

    meth_ref = expr.sub_expression
    if not isinstance(meth_ref, mx.ast.DeclRefExpr):
        return None

    meth = meth_ref.referenced_declaration
    if not isinstance(meth, mx.ast.CXXMethodDecl):
        return None

    return meth


def find_connections(connect: mx.ast.CXXMethodDecl, seen: Set[int]) -> Iterable[Tuple[mx.ast.CXXMethodDecl, mx.ast.CXXMethodDecl]]:
    """Given calls to `connect`, go and find the (signal, slot) or (signal, signal) pairs."""
    for call in connect.callers:
        assert connect.num_parameters == call.num_arguments
        if not isinstance(call, mx.ast.CallExpr):
            continue

        containing_func = call.parent_declaration
        if not isinstance(containing_func, mx.ast.FunctionDecl):
            pass

        signal_method_arg: mx.ast.Expr = call.nth_argument(1).ignore_casts
        signal_method: Optional[mx.ast.CXXMethodDecl] = referenced_method(signal_method_arg)
        if not signal_method:
            debug("Skipping call ({}) to connect ({}) with signal argument '{}' ({}) that isn't the address of a method",
                  call.id, connect.id, " ".join(t.data for t in signal_method_arg.tokens), signal_method_arg.id)
            continue

        found = False
        for i in range(2, 4):
            slot_method_arg = call.nth_argument(i).ignore_casts
            slot_method: Optional[mx.ast.CXXMethodDecl] = referenced_method(slot_method_arg)
            if not slot_method:
                continue

            assert not found
            yield signal_method, slot_method
            found = True

        debug_if(not found, "Unable to find slot method for call ({}) to connect ({}) with signal {}::{} ({})",
                 call.id, connect.id, signal_method.parent_declaration.name, signal_method.name, signal_method.id)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--db", type=str, required=True, help="Path to the database")
    args = parser.parse_args()
    index = mx.Index.in_memory_cache(mx.Index.from_database(args.db))
    seen: Set[int] = set()

    for activate in find_qmetaobject_activate(index, seen):
        for signal in find_signals(activate, seen):
            #debug("SIGNAL {}::{}: {}", signal.parent_declaration.name, signal.name, " ".join(t.data for t in signal.type.tokens))
            pass

    for connect in find_qobject_connect(index, seen):
        for signal, slot in find_connections(connect, seen):
            debug("CONNECT({}::{}, {}::{})",
                  signal.parent_declaration.name, signal.name,
                  slot.parent_declaration.name, slot.name)

    return 0


if __name__ == "__main__":
    sys.exit(main())
