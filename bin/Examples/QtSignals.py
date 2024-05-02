"""Analyzes a Qt codebase to identify signal/slot relationships."""
import abc
import argparse
import collections

import multiplier as mx
import sys
from typing import List, Optional, Iterable, Set, Tuple, Dict


def debug(data: str, *args):
    print(data.format(*args), file=sys.stderr)


def debug_if(cond: bool, data: str, *args):
    if cond:
        print(data.format(*args), file=sys.stderr)


def name(decl: mx.ast.Decl) -> str:
    names = []
    while decl:
        if isinstance(decl, mx.ast.NamedDecl):
            names.append(decl.name)
            if not len(names[-1]):
                names.pop()
        decl = decl.parent_declaration
    return "::".join(reversed(names))


def location(decl_or_expr: mx.ast.Decl | mx.ast.Expr, flc: mx.frontend.FileLocationCache) -> str:
    for tok in decl_or_expr.tokens:
        tok = tok.file_token
        if tok is None or tok.id == 0:
            continue

        file = mx.frontend.File.containing(tok)
        if not file:
            continue

        path = str(next(file.paths))
        line_col = tok.location(flc)
        if line_col is None:
            return path

        return f"{path}:{line_col[0]}:{line_col[1]}"
    return "<unknown>"


_DECL_OBJECTS: Dict[int, 'DeclObject'] = {}


class Object(abc.ABC):
    @staticmethod
    def create_from_call(call: mx.ast.CallExpr, callee: mx.ast.FunctionDecl) -> 'Object':
        global _ANY_OBJECT
        if not isinstance(callee, mx.ast.CXXMethodDecl) or \
            not callee.is_instance or \
            not isinstance(call, mx.ast.CXXMemberCallExpr):
            return _ANY_OBJECT

        arg = call.implicit_object_argument
        if isinstance(arg, mx.ast.Expr):
            return Object.create_from_expr(arg, call)

        return _ANY_OBJECT

    @staticmethod
    def create_from_expr(expr: mx.ast.Expr, context: mx.ast.Expr) -> 'Object':
        if isinstance(expr, mx.ast.DeclRefExpr):
            return Object.create_from_decl(expr.referenced_declaration)
        elif isinstance(expr, mx.ast.MemberExpr):
            return Object.create_from_decl(expr.member_declaration)
        elif isinstance(expr, mx.ast.CXXThisExpr):
            return Object.create_from_instance(expr)
        elif isinstance(expr, mx.ast.CallExpr):
            callee = expr.direct_callee
            if isinstance(callee, mx.ast.Decl):
                return Object.create_from_decl(callee)
        elif isinstance(expr, mx.ast.BinaryOperator):
            lhs = Object.create_from_expr(expr.lhs, context)
            rhs = Object.create_from_expr(expr.rhs, context)
            return isinstance(rhs, AnyObject) and lhs or rhs
        elif isinstance(expr, (mx.ast.UnaryOperator, mx.ast.CastExpr)):
            return Object.create_from_expr(expr.sub_expression, context)
        elif isinstance(expr, mx.ast.ArraySubscriptExpr):
            return Object.create_from_expr(expr.base, context)

        global _ANY_OBJECT
        debug("Unsupported object ({}) of type '{}': {}",
              expr.id, expr.kind.name, " ".join(t.data for t in expr.tokens),
              " ".join(t.data for t in context.tokens))
        return _ANY_OBJECT


    @staticmethod
    def create_from_instance(expr: mx.ast.CXXThisExpr) -> 'Object':
        global _ANY_INSTANCE
        pointer_type = expr.type.unqualified_type
        assert isinstance(pointer_type, mx.ast.PointerType)
        record_type = pointer_type.pointee_type.unqualified_type
        assert isinstance(record_type, mx.ast.RecordType)
        decl = record_type.declaration.canonical_declaration
        decl_id = decl.id
        if decl_id in _ANY_INSTANCE:
            return _ANY_INSTANCE[decl_id]

        obj = DeclInstance(decl)
        _ANY_INSTANCE[decl_id] = obj
        return obj

    @staticmethod
    def create_from_decl(decl: mx.ast.Decl) -> 'Object':
        global _DECL_OBJECTS
        decl = decl.canonical_declaration
        decl_id = decl.id
        if decl_id in _DECL_OBJECTS:
            return _DECL_OBJECTS[decl_id]
        obj = DeclObject(decl)
        _DECL_OBJECTS[decl_id] = obj
        return obj

    @property
    def name(self) -> str:
        ...


class AnyObject(Object):
    @property
    def name(self) -> str:
        return "ANY"


class DeclObject(Object):
    decl: mx.ast.Decl

    def __init__(self, decl):
        self.decl = decl

    @property
    def name(self) -> str:
        if isinstance(self.decl, mx.ast.NamedDecl):
            decl_name: str = name(self.decl)
            if len(decl_name):
                return decl_name
        return f"Decl({self.decl.id})"


class DeclInstance(Object):
    decl: mx.ast.TypeDecl

    def __init__(self, decl):
        self.decl = decl

    @property
    def name(self) -> str:
        if isinstance(self.decl, mx.ast.NamedDecl):
            decl_name: str = name(self.decl)
            if len(decl_name):
                return decl_name + "::this"
        return f"{self.decl.id}::this"


_ANY_OBJECT = AnyObject()
_ANY_INSTANCE: Dict[int, DeclInstance] = {}


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

        # Signals are implemented in file paths that look like:
        # /path/to/code/<cmake_target>_autogen/<id>/moc_<file name>
        path = str(next(containing_file.paths))
        if "moc_" not in path or "_autogen" not in path:
            continue

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


def find_connections(connect: mx.ast.CXXMethodDecl, seen: Set[int]) -> Iterable[
    Tuple[mx.ast.CallExpr, Object, mx.ast.CXXMethodDecl, Object, mx.ast.CXXMethodDecl]]:
    """Given calls to `connect`, go and find the (signal, slot) or (signal, signal) pairs."""
    for call in connect.callers:
        assert connect.num_parameters == call.num_arguments
        if not isinstance(call, mx.ast.CallExpr):
            continue

        containing_func = call.parent_declaration
        if not isinstance(containing_func, mx.ast.FunctionDecl):
            pass

        sender = Object.create_from_expr(call.nth_argument(0), call)
        signal_method_arg: mx.ast.Expr = call.nth_argument(1).ignore_casts
        signal_method: Optional[mx.ast.CXXMethodDecl] = referenced_method(signal_method_arg)

        if not signal_method:
            debug(
                "Skipping call ({}) to connect ({}) with signal argument '{}' ({}) that isn't the address of a method",
                call.id, connect.id, " ".join(t.data for t in signal_method_arg.tokens), signal_method_arg.id)
            continue

        found = False
        for i in range(2, 4):
            slot_method_arg = call.nth_argument(i).ignore_casts
            slot_method: Optional[mx.ast.CXXMethodDecl] = referenced_method(slot_method_arg)
            if not slot_method:
                continue

            assert not found
            yield call, sender, signal_method.canonical_declaration, \
                  Object.create_from_expr(call.nth_argument(i - 1), call), slot_method.canonical_declaration
            found = True

        debug_if(not found, "Unable to find slot method for call ({}) to connect ({}) with signal {}::{} ({})",
                 call.id, connect.id, signal_method.parent_declaration.name, signal_method.name, signal_method.id)


class Call:
    """A triple representing a function/method call."""
    object: Object
    call: mx.ast.CallExpr
    target: mx.ast.FunctionDecl

    def __init__(self, object, call, target):
        self.object = object
        self.call = call
        self.target = target.canonical_declaration

    @staticmethod
    def create_from(call: mx.ast.CallExpr) -> Iterable['Call']:
        callee = call.direct_callee
        if not callee:
            debug(f"Skipping indirect call ({call.id})")
            return

        object = Object.create_from_call(call, callee)
        yield Call(object, call, callee)

        if not isinstance(callee, mx.ast.CXXMethodDecl) or \
            not callee.is_instance or \
            not isinstance(call, mx.ast.CXXMemberCallExpr):
            return

        for override in callee.transitive_overridden_by_methods:
            yield Call(object, call, override)


class CallGraph:
    calls: Dict[mx.ast.FunctionDecl, List[Call]]

    def __init__(self):
        self.calls = {}

    @staticmethod
    def _is_in(call: mx.ast.CallExpr, func_body: mx.ast.Stmt):
        """Check if `call` is nested inside of `func_body`. Generally, `func_body` have the type `mx.ast.CompoundStmt`,
        but it might also be a try/catch statement as well."""
        for containing_stmt in mx.ast.Stmt.containing(call):
            return containing_stmt == func_body
        return False

    @staticmethod
    def _overloads(meth: mx.ast.CXXMethodDecl):
        yield meth

    def __iter__(self) -> Iterable[Call]:
        for calls in self.calls.values():
            for call in calls:
                yield call

    def callees(self, func: mx.ast.FunctionDecl) -> Iterable[Call]:
        yield from self.calls.get(func, [])

    def _add_callees(self, func: mx.ast.FunctionDecl, work_list: List[mx.ast.FunctionDecl]):
        if func in self.calls:
            return

        call_list: List[Call] = []
        self.calls[func] = call_list

        func_body = func.body
        if not func_body:
            return

        for call in mx.ast.CallExpr.IN(mx.Fragment.containing(func)):
            if not CallGraph._is_in(call, func_body):
                continue

            for triple in Call.create_from(call):
                call_list.append(triple)
                work_list.append(triple.target)

    def add_callees(self, func: mx.ast.FunctionDecl):
        next_work_list = [func.canonical_declaration]
        while len(next_work_list):
            work_list, next_work_list = next_work_list, []
            for next_func in work_list:
                self._add_callees(next_func, next_work_list)

    def inject_call(self, from_func: mx.ast.FunctionDecl, edge: Call):
        if from_func not in self.calls:
            self.add_callees(from_func)

        if edge.target not in self.calls:
            self.add_callees(edge.target)

        self.calls[from_func].append(edge)

    def remove_acyclic(self):
        cyclic_funcs: Set[mx.ast.FunctionDecl] = set()
        for func in self.calls.keys():
            seen = set()
            next_work_list = [call.target for call in self.calls[func]]
            while func not in cyclic_funcs and len(next_work_list):
                work_list, next_work_list = next_work_list, []
                for work_func in work_list:
                    if work_func not in seen:
                        seen.add(work_func)
                        next_work_list.extend(call.target for call in self.calls[work_func])
            if func in seen:
                cyclic_funcs.add(func)

        new_calls: Dict[mx.ast.FunctionDecl, List[Call]] = {}
        for old_func, old_calls in self.calls.items():
            if old_func not in cyclic_funcs:
                continue
            new_edges: List[Call] = []
            for old_call in old_calls:
                if old_call.target in cyclic_funcs:
                    new_edges.append(old_call)

            new_calls[old_func] = new_edges

        self.calls = new_calls

    def dump(self) -> str:
        out: List[str] = []
        out.append("digraph {")
        seen_objects = set()
        for func, calls in self.calls.items():
            out.append(f"f{func.id} [label=\"{name(func)}\", shape=\"box\"];")
            for call in calls:
                if call.object not in seen_objects:
                    seen_objects.add(call.object)
                    out.append(f"o{id(call.object)} [label=\"{call.object.name}\", shape=\"hexagon\"];")
                out.append(f"f{func.id} -> o{id(call.object)};")
                out.append(f"o{id(call.object)} -> f{call.target.id};")
        out.append("}")
        return "\n".join(out)

    def dump_callsites(self) -> str:
        out: List[str] = []
        flc = mx.frontend.FileLocationCache()
        for func, calls in self.calls.items():
            out.append(f"{name(func)} at {location(func, flc)} calls:")
            for call in calls:
                out.append(f"\t{name(call.target)} at {location(call.call, flc)}")
        return "\n".join(out)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--db", type=str, required=True, help="Path to the database")
    parser.add_argument("--dot", type=str, help="Path to the output DOT file")
    parser.add_argument("--locations", type=str, help="Path to the output locations file")
    parser.add_argument("--only_cycles", action="store_true", help="Should acyclic signals be removed?")
    parser.add_argument("--save_references", action="store_true", help="Should references be added back into the database?")
    args = parser.parse_args()
    index = mx.Index.in_memory_cache(mx.Index.from_database(args.db))
    seen: Set[int] = set()
    cg: CallGraph = CallGraph()
    for activate in find_qmetaobject_activate(index, seen):
        for signal in find_signals(activate, seen):
            debug("SIGNAL {}: {}", name(signal), " ".join(t.data for t in signal.type.tokens))

    signal_slots: List[Tuple[mx.ast.FunctionDecl, mx.ast.FunctionDecl]] = []

    for connect in find_qobject_connect(index, seen):
        for connect_call, sender, signal, receiver, slot in find_connections(connect, seen):
            debug("CONNECT({}, {})", name(signal), name(slot))
            rx_edge: Call = Call(receiver, connect_call, slot.canonical_declaration)
            cg.inject_call(signal, rx_edge)
            signal_slots.append((signal.canonical_declaration, slot.canonical_declaration))

    # Add the actual references into the database.
    if args.save_references:
        call_kind = mx.ReferenceKind.get(index, mx.BuiltinReferenceKind.CALLS)
        for signal, slot in signal_slots:
            for call in cg.callees(signal):
                mx.Reference.add(call_kind, call.call, slot)

    if args.only_cycles:
        cg.remove_acyclic()

    if args.dot:
        with open(args.dot, "w") as f:
            f.write(cg.dump())

    if args.locations:
        with open(args.locations, "w") as f:
            f.write(cg.dump_callsites())

    return 0


if __name__ == "__main__":
    sys.exit(main())
