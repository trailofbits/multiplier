# IR Gaps and Issues

## DONE
- **MEM opcode** — Unified MEMORY opcode with 70 sub-opcodes (load/store x atomic x LE/BE x 8/16/32/64, bulk memory, string ops, bit-field access, cmpxchg, CONSUME_VA_PARAM).
- **LAST_VALUE** — Comma operator: evaluates all operands, returns last.
- **Pointer decrement fix** — `--ptr` correctly emits CONST(-1) with PTR_ADD.
- **IRObject methods** — source_declaration() and type() implemented.
- **EnterScopeInst/ExitScopeInst** — Instruction classes with scope() accessor.
- **Convenience methods** — IRBlock::parent_function(), IRFunction::containing(IRBlock/IRInstruction).
- **DesignatedInitExpr** — Unwrap to Initializer(). ImplicitValueInitExpr as zero.
- **Float builtins** — 41 FloatOp sub-opcodes.
- **Bit-field init fix** — Uses BIT_WRITE with exact bit_offset/bit_width.
- **Interpreter improvements** — Scope tracking (poison on EXIT_SCOPE), all string/memory ops.
- **Pointer compound assign fix** — `ptr += n` uses PTR_ADD, not ADD.
- **PTR_DIFF element_size** — Extracted from pointee type.
- **_Atomic plain load/store** — Correctly uses atomic ops.
- **BIT_READ** — Emitted in EmitLoadFromLValue for bit-field reads.
- **Switch case compensation** — Compensation blocks for switch→case scope crossings.
- **CFG predecessor fix** — Correct predecessor list updates in compensation.
- **Database teardown** — Isolated try/catch per step, leaked statement detection.
- **Entity ID type safety** — Typed enums in IRBlockId, IRInstructionId, IRStructureId.
- **IRSwitchCase → IRSwitchCaseStructure** — Switch cases are now IRStructure entities.
- **ALLOCA sub-opcodes** — AllocaKind: LOCAL, ARG, RETURN, DYNAMIC. DynamicAllocaInst derived from AllocaInst.
- **EXPRESSION_SCOPE** — New StructureKind for call argument/return allocas.
- **PARAM_PTR** — Renamed from PARAM_READ. Returns pointer to caller's argument alloca.
- **RETURN_ADDRESS** — Renamed from RETURN_PTR (for __builtin_return_address).
- **VA_PACK removed** — Variadic args are regular operands.
- **VA_ARG → CONSUME_VA_PARAM** — New MemOp sub-opcode.
- **ArrayToPointerDecay fix** — Uses EmitLValue (address), not EmitRValue (load).
- **MEMCPY for direct assignment** — `a = b` with lvalue RHS always uses MEMCPY.
- **Scalar size guards** — IsScalarSize() check before DetermineMemOp; MEMCPY fallback for non-1/2/4/8.
- **String literal init** — Non-power-of-2 sizes use MEMCPY.
- **source_statement() assertion fix** — Checks entity ID is StmtId before calling StmtFor.
- **IRObject::source_declaration() assertion fix** — Checks entity ID is DeclId before calling DeclFor.
- **Interpreter moved to bin/InterpretIR/** — Separate from Examples.
- **mx-print-ir human-readable output** — Uses EnumeratorName() for all opcodes, sub-opcodes, kinds.
- **MX_EXPORT on IR enum EnumeratorName** — All IR enum name functions exported from shared library.
- **GNU statement expression** — Already handled: SCOPE + emit children + last expr value.
- **Compound literal** — Already handled: ALLOCA + EmitInitializer + scope-tracked.
- **EXPRESSION_SCOPE at call sites** — Calls wrapped in EXPRESSION_SCOPE with ALLOCA/ARG for each argument and ALLOCA/RETURN for return value. Scope popped at full-expression boundary.
- **RETURN_PTR in callee** — Callee emits RETURN_PTR to get pointer to caller's return storage, stores return value into it before RET.
- **PARAM_PTR without local copy** — Parameters no longer copied into local allocas. PARAM_PTR directly gives pointer to caller's ARG alloca. DeclRefExpr resolves to PARAM_PTR.
- **CallInst::return_alloca()** — Returns the ALLOCA/RETURN instruction for the return value. `has_return_value()` for void check.
- **IRObject string literal bytes** — Not needed; content accessible via AST StringLiteral through source_declaration().

## Remaining Gaps

### Codegen
1. **C++ expressions** — Lambda, new/delete, this, constructors, destructors, etc. emit UNKNOWN. (C-only for now.)

### API
6. **No IRInstruction::result_type() on base class** — Must downcast to get result type. A base-class method would simplify interpreters/printers. Deferred.
7. **No Index::ir_functions() enumerator** — Can't iterate all IR functions from an Index.

### Interpreter
10. **Interpreter is monolithic** — ~1500-line switch in bin/InterpretIR. Plan exists to extract into lib/IR/Interpret/ with ValueFactory/Memory/Driver/Checker policy classes. See docs/InterpreterLibraryPlan.md.
11. **No multi-path exploration** — Single-path concrete execution only. Need COW memory + fork.
12. **No call inlining** — Interpreter doesn't step into callees.
13. **No external function modeling** — malloc/free/memcpy/printf etc. not modeled.

### Codegen / Types
14. **`__int128` / `_BitInt(N>64)`** — Sized integer opcodes only cover 8/16/32/64-bit widths. Wider types (e.g., `__int128`, `_BitInt(128)`) currently round down to `_64`. These could be decomposed into paired 64-bit operations.

### C23
15. **`#embed` directive** — C23's `#embed` for embedding binary data. Not handled.

### Documentation
15. **IR_GAPS.md** — This file (kept up to date).
16. **docs/IR.md** — Updated.
17. **docs/InterpreterLibraryPlan.md** — Written.
