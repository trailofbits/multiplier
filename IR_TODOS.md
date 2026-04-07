# IR Implementation Progress

## Plan: Structural IR Entities (robust-plotting-rocket.md)

### Phase 1: FunctionKind + sourceDeclEntityId rename — COMPLETE

### Phase 2: IRStructure entity + scope tracking — COMPLETE
- [x] StructureKind enum (18 kinds), IRStructure entity, IRStructureId
- [x] Structure capnp schema, entity providers, pack/unpack
- [x] Structure generation (PushStructure/PopStructure) for all control flow
- [x] FUNCTION_SCOPE, nested SCOPE for CompoundStmt, implicit SCOPE for for-init
- [x] ENTER_SCOPE/EXIT_SCOPE opcodes on all paths (including break/continue/return/goto)
- [x] Block parentStructureId, scope object association via AssociateObjectWithScope
- [x] IRFunction::body_scope(), IRBlock::parent_structure() accessors
- [x] SWITCH_CASE structures for each case/default
- [ ] IRSwitchCase → IRStructure(SWITCH_CASE) full migration (deferred)
- [ ] Full Python bindings (stub exists, requires bootstrap regen)

### Phase 3: Control flow region structures — MERGED INTO PHASE 2

### Phase 4: Global initializer functions — COMPLETE
- [x] GenerateGlobalInit creates synthetic FunctionIR for globals with initializers
- [x] FunctionKind::GLOBAL_INITIALIZER, sourceDeclEntityId = VarDecl
- [x] Entry block with ADDRESS_OF → EmitRValue(init) → STORE → RET
- [x] VarDecl maps to its GLOBAL_INITIALIZER IRFunction

## Known Extensions — PARTIALLY COMPLETE
- [x] MEMSET (opcode 68): dest, byte_value, size — lowered from memset/builtin calls
- [x] MEMCPY (opcode 69): dest, src, size — lowered from memcpy/memmove/builtin calls
- [x] MemsetInst, MemcpyInst instruction class wrappers
- [ ] VAR_INIT block kind + structure kind (for variable initialization regions)

## Known Issues / Lies Remaining
1. IRSwitchCase still separate entity type (coexists with SWITCH_CASE structures)
2. string_bytes() missing on IRObject for string literals
3. Python bindings are stub only for IRStructure
4. Global initializer quality depends on EmitRValue handling of all init expressions

## Decisions Made
- Phase 3 merged into Phase 2
- SWITCH_CASE structures coexist with IRSwitchCase for backward compat
- ENTER_SCOPE/EXIT_SCOPE carry IRStructureId extra in entity pool
- StructureKind embedded in IRStructureId (18 sub_kind offsets)
- Global initializer uses same EmitRValue path as function body codegen
- MEMSET/MEMCPY lowered from memset/memcpy/memmove and all __builtin_ variants
- Goto conservatively exits all scopes to FUNCTION_SCOPE
