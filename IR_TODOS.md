# IR Implementation Progress

## Plan: Structural IR Entities (robust-plotting-rocket.md)

### Phase 1: FunctionKind + sourceDeclEntityId rename — COMPLETE
- Added `FunctionKind` enum (`NORMAL`, `GLOBAL_INITIALIZER`)
- Renamed `funcDeclEntityId` → `sourceDeclEntityId` in capnp
- Added `IRFunction::kind()`, `IRFunction::source_declaration()`
- Added `kind` field to capnp Function struct

### Phase 2: IRStructure entity + scope tracking — IN PROGRESS
- [x] Create `StructureKind` enum header (18 kinds)
- [x] Create `IRStructure` entity class + impl
- [x] Add `Structure` to `IR.capnp`, `irStructures` to `RPC.capnp`
- [x] Add `StructureIR` to `FunctionIR`, structure stack to `IRGenerator`
- [x] Add `PushStructure`/`PopStructure` helpers
- [x] Emit `FUNCTION_SCOPE` structure (wraps entire function body)
- [x] Update `Types.h`: `IRStructureId`, `MX_FOR_EACH_ENTITY_CATEGORY` slot 20
- [x] Update `Types.cpp`: pack/unpack with StructureKind in entity ID
- [x] Update serialization (`SerializeIR.cpp`)
- [x] Entity provider implementations (SQLite, Caching, Invalid via macros)
- [x] Control flow structures (IF, FOR, WHILE, DO_WHILE, SWITCH) — merged Phase 3
- [ ] Emit nested `SCOPE` structures for CompoundStmt bodies
- [ ] Add `ENTER_SCOPE`/`EXIT_SCOPE` opcodes
- [ ] Associate objects with scopes (`AssociateObjectWithScope` wired in)
- [ ] Add `parentStructureId` to blocks (in capnp Block struct)
- [ ] Migrate `IRSwitchCase` → `IRStructure(SWITCH_CASE)`
- [ ] Python bindings (stub exists, full binding requires bootstrap regen)

### Phase 3: Control flow region structures — MERGED INTO PHASE 2
All control flow structures are now emitted during codegen.

### Phase 4: Global initializer functions — NOT STARTED
- [ ] Generate synthetic init functions for globals
- [ ] Wire through `FunctionKind::GLOBAL_INITIALIZER`

## Additional work completed (not in plan)
- IMPLICIT_UNREACHABLE opcode for structurally unreachable blocks
- Empty block patching before dominator computation
- Implicit void return for unterminated function bodies
- Dead-terminator guard in EmitBranchWithOpCode
- parent_block_index tracking on instructions
- SizeOfInst::static_size() fix (reads from int pool)
- IRSwitchCase::parent_switch() accessor
- AST ir_instruction() → ir() returning VariantEntity (any IR entity)
- Bootstrap regeneration for AST ir() method

## Known Extensions (implement after plan phases)
- MEMSET/MEMCPY instructions
- VAR_INIT block kind + structure kind

## Known Issues / Lies Remaining
1. Nested SCOPE structures not yet emitted for CompoundStmt bodies
2. No ENTER_SCOPE/EXIT_SCOPE instructions yet
3. Objects not yet associated with scopes during codegen
4. Block parentStructureId not in capnp schema yet
5. IRSwitchCase still separate entity type (not yet migrated)
6. No global initializer functions
7. string_bytes() missing on IRObject for string literals
8. Python bindings are stub only — bootstrap regen needed for full support

## Decisions
- Phase 3 merged into Phase 2 since control flow structures are naturally emitted alongside scope tracking
- Python binding uses stub pattern (returns VariantEntity) until bootstrap can be re-run
- StructureKind embedded in IRStructureId (18 sub_kind offsets) for type discrimination
- Structure children stored in entity pool as interleaved IRStructureId/IRBlockId entries
