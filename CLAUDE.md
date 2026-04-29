# Building

Always build with `--quiet` (or `-q`) to keep output focused on warnings and errors.

Build directories:
- Release: `~/Build/multiplier/Release/multiplier`
- Debug: `~/Build/multiplier/Debug/multiplier`

Example:
```
ninja -C ~/Build/multiplier/Debug/multiplier --quiet
```

# Python bindings

Multiplier's Python bindings already return the most-derived type. Don't
write `mx.ast.FunctionDecl.FROM(decl)` (or any other `.FROM(...)` cast)
to refine an entity in Python — the object you got out of an iterator,
property, or lookup is already the right subclass. Use `isinstance(...)`
when you genuinely need to gate on type, and access typed attributes
(`fd.parameters`, `vd.type`, etc.) directly. The `.FROM` pattern is a
C++-style code smell here and reads as one in review.
