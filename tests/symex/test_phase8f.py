# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 8f — multi-function entry exploration via `engine.explore_many`.

`explore_many` is the smallest of the three Phase 8f candidates; it
turns "loop over candidate functions and call explore each time" into
a one-liner that drives a shared layout, a shared `until` predicate,
and one combined `PathSet` whose paths each carry their `entry_func`
of origin.

  P8f.1   List of names: explore_many(["test_byvalue", "test_struct_assign"])
          returns a PathSet whose by_entry() keys are exactly the two
          IRFunctions; each entry's return matches ConcretePolicy.
  P8f.2   Compiled regex: explore_many(re.compile(...)) resolves the
          known `test_(byvalue|struct_assign|init_lists|pointers)`
          functions and completes them all.
  P8f.3   Callable predicate: explore_many(lambda n: n == "factorial")
          resolves a single entry; factorial(5) returns 120.
  P8f.4   Empty resolution raises ValueError (caught regex / predicate
          typos before they vanish into a silent no-op exploration).
  P8f.5   Mixed list of name and pre-resolved IRFunction works.
  P8f.6   path.entry_func is the IRFunction the path started in,
          set on every path the engine returns (forks too).
  P8f.7   `until` firing on the first entry short-circuits the rest;
          the second entry never gets initialized.
"""

import re

import pytest

from symex import Layout, SymExEngine
from symex.events import Strategy, Terminal
from symex.until import ExploreUntil

from conftest import find_ir_function, run_via_concrete_policy


def _engine(index):
    e = SymExEngine(index)
    e.layout = Layout()
    return e


def _names_of(grouped, engine):
    return {engine._function_name(ir) for ir in grouped.keys()}


def test_p8f_1_list_of_names_matches_concrete_policy(index):
    """Two-name list resolves to two IRFunctions; each entry's return
    value matches the C++ ConcretePolicy ground truth."""
    engine = _engine(index)
    names = ["test_byvalue", "test_struct_assign"]
    paths = engine.explore_many(names)

    grouped = paths.by_entry()
    assert _names_of(grouped, engine) == set(names)

    for ir, ir_paths in grouped.items():
        name = engine._function_name(ir)
        completed = [p for p in ir_paths
                     if p.terminal == Terminal.COMPLETED]
        assert completed, f"{name}: no completed path"
        expected = run_via_concrete_policy(index, name)
        assert expected is not None, \
            f"{name}: ConcretePolicy did not complete (test setup bug)"
        assert completed[0].return_value == expected, \
            f"{name}: explore_many returned " \
            f"{completed[0].return_value!r} but ConcretePolicy " \
            f"returned {expected!r}"


def test_p8f_2_compiled_regex_resolves_and_completes(index):
    """A re.Pattern matches against every FunctionDecl name; the
    resolved set is asserted exactly so a regex tweak surfaces here."""
    engine = _engine(index)
    pattern = re.compile(r"^test_(byvalue|struct_assign|init_lists|pointers)$")
    paths = engine.explore_many(pattern)

    grouped = paths.by_entry()
    expected = {"test_byvalue", "test_struct_assign",
                "test_init_lists", "test_pointers"}
    assert _names_of(grouped, engine) == expected

    for ir, ir_paths in grouped.items():
        name = engine._function_name(ir)
        completed = [p for p in ir_paths
                     if p.terminal == Terminal.COMPLETED]
        assert completed, f"{name}: no completed path"


def test_p8f_3_callable_predicate_single_match(index):
    """A `name -> bool` predicate is the most flexible resolver; it
    turns analyst-side substring / prefix logic into one call."""
    engine = _engine(index)
    paths = engine.explore_many(
        lambda name: name == "factorial",
        args=[5])

    grouped = paths.by_entry()
    assert len(grouped) == 1
    ir, ir_paths = next(iter(grouped.items()))
    assert engine._function_name(ir) == "factorial"

    completed = [p for p in ir_paths if p.terminal == Terminal.COMPLETED]
    assert completed, "factorial(5): no completed path"
    assert completed[0].return_value == 120, \
        f"factorial(5): expected 120, got {completed[0].return_value!r}"


def test_p8f_4_empty_resolution_raises(index):
    """A regex that resolves to zero functions is almost always a typo;
    surface it immediately rather than returning an empty PathSet."""
    engine = _engine(index)
    with pytest.raises(ValueError):
        engine.explore_many(re.compile(r"^this_function_does_not_exist__\d+$"))

    with pytest.raises(ValueError):
        engine.explore_many(lambda name: False)


def test_p8f_5_mixed_name_and_irfunction(index):
    """The list form takes a mix of `str` and pre-resolved IRFunctions
    so analysts can hand-pick one entry plus a name they don't have a
    handle to yet."""
    engine = _engine(index)
    factorial_ir = find_ir_function(index, "factorial")
    assert factorial_ir is not None, "fixture: factorial missing from index"

    paths = engine.explore_many(["test_byvalue", factorial_ir], args=[5])
    grouped = paths.by_entry()
    assert _names_of(grouped, engine) == {"test_byvalue", "factorial"}


def test_p8f_6_entry_func_attribute_on_every_path(index):
    """`entry_func` propagates through forks too — every path the
    engine returns must point at the IRFunction it started in."""
    engine = _engine(index)
    paths = engine.explore_many(["test_byvalue", "test_pointers"])

    assert paths, "explore_many returned no paths"
    by_name = {}
    for p in paths:
        ir = p.entry_func
        assert ir is not None, f"path {p.id}: entry_func is None"
        name = engine._function_name(ir)
        by_name.setdefault(name, []).append(p)
    assert set(by_name.keys()) == {"test_byvalue", "test_pointers"}


def test_p8f_7_until_short_circuits_remaining_entries(index):
    """`until` evaluates against the cumulative state across entries:
    once the first entry pushes the aggregate past the threshold, the
    second entry is never initialized and contributes no paths."""
    engine = _engine(index)

    # `steps(1)` flips True as soon as any path advances at all. The
    # first entry's first slice advances `factorial(5)` by many
    # substrate steps; once the cross-entry guard re-checks the user
    # predicate before initializing entry 2, it's already True.
    paths = engine.explore_many(
        ["factorial", "test_byvalue"],
        args=[5],
        until=ExploreUntil.steps(1))

    grouped = paths.by_entry()
    present = _names_of(grouped, engine)
    assert "factorial" in present, \
        "factorial should still appear (it advanced before until fired)"
    assert "test_byvalue" not in present, \
        "test_byvalue should be absent — the cross-entry guard skipped it"
