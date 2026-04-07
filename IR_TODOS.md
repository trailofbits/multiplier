# IR Implementation Progress

## Plan: Structural IR Entities (robust-plotting-rocket.md)

### Phase 1: FunctionKind + sourceDeclEntityId rename — COMPLETE
- Added `FunctionKind` enum (`NORMAL`, `GLOBAL_INITIALIZER`)
- Renamed `funcDeclEntityId` → `sourceDeclEntityId` in capnp
- Added `IRFunction::kind()`, `IRFunction::source_declaration()`
- Added `kind` field to capnp Function struct

### Phase 2: IRStructure entity + scope tracking — IN PROGRESS
- [ ] Create `StructureKind` enum header
- [ ] Create `IRStructure` entity class + impl
- [ ] Add `Structure` to `IR.capnp`, `irStructures` to `RPC.capnp`
- [ ] Add `StructureIR` to `FunctionIR`, structure stack to `IRGenerator`
- [ ] Add `PushStructure`/`PopStructure` helpers
- [ ] Emit `FUNCTION_SCOPE` and `SCOPE` structures
- [ ] Add `ENTER_SCOPE`/`EXIT_SCOPE` opcodes
- [ ] Associate objects with scopes
- [ ] Add `parentStructureId` to blocks
- [ ] Migrate `IRSwitchCase` → `IRStructure(SWITCH_CASE)`
- [ ] Update `Types.h`: `IRStructureId`, `MX_FOR_EACH_ENTITY_CATEGORY`
- [ ] Update `Types.cpp`: pack/unpack
- [ ] Update serialization (`SerializeIR.cpp`)
- [ ] Entity provider stubs (SQLite, Caching, Invalid)
- [ ] Python bindings

### Phase 3: Control flow region structures — NOT STARTED
- [ ] Add IF/IF_THEN/IF_ELSE structures
- [ ] Add FOR/FOR_INIT/FOR_CONDITION/FOR_BODY/FOR_INCREMENT structures
- [ ] Add WHILE/WHILE_CONDITION/WHILE_BODY structures
- [ ] Add DO_WHILE/DO_WHILE_BODY/DO_WHILE_CONDITION structures
- [ ] Add SWITCH structures
- [ ] Update all Emit* methods to push/pop structures

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
1. No structural nesting — blocks are flat within function
2. No scope lifetime tracking — ALLOCAs not associated with scopes
3. IRSwitchCase is separate entity type (should be structural entity)
4. No global initializer functions
5. string_bytes() missing on IRObject for string literals
6. Some instructions may have orphaned sub-expressions

## Decisions
- Phase 1 field rename `funcDeclEntityId` → `sourceDeclEntityId` is binary-compatible (same ordinal)
- IMPLICIT_UNREACHABLE added as terminator to handle empty blocks cleanly
- ir() on Decl/Stmt returns VariantEntity to support all IR entity types, not just instructions
