# IR Implementation Progress

## Plan: Structural IR Entities (robust-plotting-rocket.md)

### Phase 1: FunctionKind + sourceDeclEntityId rename — COMPLETE

### Phase 2: IRStructure entity + scope tracking — MOSTLY COMPLETE
- [x] Create `StructureKind` enum header (18 kinds)
- [x] Create `IRStructure` entity class + impl
- [x] Add `Structure` to `IR.capnp`, `irStructures` to `RPC.capnp`
- [x] Add `StructureIR` to `FunctionIR`, structure stack to `IRGenerator`
- [x] Add `PushStructure`/`PopStructure` helpers
- [x] Emit `FUNCTION_SCOPE` structure (wraps entire function body)
- [x] Emit nested `SCOPE` structures for CompoundStmt bodies
- [x] Add `ENTER_SCOPE`/`EXIT_SCOPE` opcodes (66, 67)
- [x] Associate objects with scopes (DeclStmt → AssociateObjectWithScope)
- [x] Add `parentStructureId` to blocks (capnp + read-side accessor)
- [x] Control flow structures (IF, FOR, WHILE, DO_WHILE, SWITCH, SWITCH_CASE)
- [x] `IRFunction::body_scope()` accessor
- [x] `IRBlock::parent_structure()` accessor
- [x] Update `Types.h`: `IRStructureId`, `MX_FOR_EACH_ENTITY_CATEGORY` slot 20
- [x] Update `Types.cpp`: pack/unpack with StructureKind in entity ID
- [x] Update serialization (`SerializeIR.cpp`)
- [x] Entity provider implementations
- [ ] Migrate `IRSwitchCase` → `IRStructure(SWITCH_CASE)` (deferred — coexists for now)
- [ ] Full Python bindings (stub exists, requires bootstrap regen)
- [ ] EXIT_SCOPE on all exit paths (break/continue/return/goto)

### Phase 3: Control flow region structures — MERGED INTO PHASE 2

### Phase 4: Global initializer functions — NOT STARTED
- [ ] Generate synthetic init functions for globals
- [ ] Wire through `FunctionKind::GLOBAL_INITIALIZER`

## Known Extensions (implement after plan phases)
- MEMSET/MEMCPY instructions
- VAR_INIT block kind + structure kind

## Known Issues / Lies Remaining
1. EXIT_SCOPE not emitted on break/continue/return/goto exit paths
2. IRSwitchCase still separate entity type (coexists with SWITCH_CASE structures)
3. No global initializer functions
4. string_bytes() missing on IRObject for string literals
5. Python bindings are stub only — bootstrap regen needed for full support
6. For-init with DeclStmt should get implicit outer SCOPE for variable lifetime

## Decisions
- Phase 3 merged into Phase 2
- SWITCH_CASE structures coexist with IRSwitchCase entity for backward compat
- ENTER_SCOPE/EXIT_SCOPE are non-terminator instructions carrying IRStructureId extra
- StructureKind embedded in IRStructureId (18 sub_kind offsets)
