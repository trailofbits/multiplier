# IR Gaps and Issues

## DONE
- **MEM opcode** — Replaced LOAD/STORE/ATOMIC_LOAD/ATOMIC_STORE with unified MEM opcode. 32 sub-opcodes (MemAccessOp) encode load/store x atomic x LE/BE x 8/16/32/64.

## Critical Bugs

1. **Pointer decrement bug** — `--ptr` emits PTR_ADD same as `++ptr`. Should negate index.
2. **Bit-field initialization** — `OffsetInBits() / 8` truncates. Bit-field stores go to wrong offset.
3. **IRObject::source_declaration() and type() unimplemented** — Declared in header, no impl.
4. **Orphaned comma operator LHS** — `a, b` emits `a` but never adds root to block. Need LAST_VALUE.

## Missing Codegen

5. **DesignatedInitExpr** — `.x = 1` and `[5] = 42` syntax falls to UNKNOWN.
6. **VLAs** — `int arr[n]` should emit DYNAMIC_ALLOCA.
7. **C++ expressions** — Lambda, new/delete, this, constructors, etc. emit UNKNOWN.
8. **Missing float builtins** — sin, cos, tan, exp, log, pow, fmod, fma, etc.

## API Gaps

9. **No IRInstruction::result_type() on base class** — Must downcast.
10. **ENTER_SCOPE/EXIT_SCOPE have no instruction classes** — Need EnterScopeInst/ExitScopeInst.
11. **No IRBlock::parent_function()** — Must walk structure chain.
12. **No IRFunction::containing(IRInstruction)** — Inconsistent with Decl/Stmt containing().
13. **IRSwitchCaseStructure missing target_block()** — Dual API confusion.
14. **No Index::ir_functions() enumerator**.

## Interpreter Gaps

15. **Hardcoded 8-byte LOAD/STORE** — Needs type-aware sizing. → MEM opcode with size sub-opcodes.
16. **SCOPE tracking is no-op** — poisoned flag never set.
17. **MULTIMEM only handles 4 of 25 sub-opcodes**.
18. **No infinite loop protection beyond step count**.

## Unaddressed Conversation Items

19. **Duff's device compensation** — Only goto has compensation, not switch→case edges.
20. **String literal bytes on IRObject** — source_declaration()/type() not even implemented.
21. **Interpreter never tested against real codebase**.

## Design Changes Needed

22. **LAST_VALUE instruction** — For comma operator: `LAST_VALUE(a, b)` evaluates both, returns b.
23. **MEM opcode replacing LOAD/STORE** — Sub-opcodes: LOAD_LE_8, LOAD_LE_16, LOAD_LE_32, LOAD_LE_64, LOAD_BE_8, ..., STORE_LE_8, ..., STORE_BE_8, ...
24. **ATOMIC_LOAD/STORE fold into MEM** — ATOMIC_LOAD_LE_32, etc.
