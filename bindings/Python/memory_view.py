# Copyright (c) 2024-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Typed memory views over ConcreteMemory.

A MemoryView is a lightweight handle: (memory, address, type). It provides
typed read/write access to the bytes at that address using the multiplier
type system. Narrowing a view (accessing a struct field, indexing an array,
dereferencing a pointer) returns a new MemoryView with adjusted address
and type.

Usage:
    from memory_view import MemoryView, CallFrame

    mem = ConcreteMemory()
    view = MemoryView.alloc(mem, some_type)
    view.write(42)
    print(view.read())
"""

import struct as _struct

import multiplier
ast = multiplier.ast


# ============================================================================
# Type helpers
# ============================================================================

def _unwrap(ty):
    """Strip qualifiers, elaborated, typedef, etc. to get the canonical type."""
    c = ty.canonical_type
    return c if c is not None else ty


def _type_size_bytes(ty):
    """Get the size of a type in bytes."""
    bits = _unwrap(ty).size_in_bits
    if bits is None:
        raise TypeError(f"Type has no known size: {ty}")
    return (bits + 7) // 8


def _type_align_bytes(ty):
    """Get the alignment of a type in bytes."""
    bits = _unwrap(ty).alignment
    return (bits + 7) // 8 if bits else 8


def _as_record(ty):
    """If ty is a struct/union, return its RecordDecl."""
    ty = _unwrap(ty)
    rt = ast.RecordType.FROM(ty)
    if rt is None:
        return None
    return ast.RecordDecl.FROM(rt.declaration)


def _as_array(ty):
    """If ty is an array type, return the ArrayType."""
    return ast.ArrayType.FROM(_unwrap(ty))


def _as_constant_array(ty):
    """If ty is a fixed-size array, return the ConstantArrayType."""
    return ast.ConstantArrayType.FROM(_unwrap(ty))


def _as_pointer(ty):
    """If ty is a pointer type, return the PointerType."""
    return ast.PointerType.FROM(_unwrap(ty))


def _is_float_type(ty):
    """Check if a type is a floating-point type."""
    bt = ast.BuiltinType.FROM(_unwrap(ty))
    if bt is None:
        return False
    return bt.is_floating_point


def _is_signed_int_type(ty):
    """Check if a type is a signed integer type."""
    bt = ast.BuiltinType.FROM(_unwrap(ty))
    if bt is None:
        return False
    return bt.is_signed_integer


def _is_bool_type(ty):
    """Check if a type is a boolean type."""
    bt = ast.BuiltinType.FROM(_unwrap(ty))
    if bt is None:
        return False
    return bt.builtin_kind == ast.BuiltinTypeKind.BOOLEAN


def _is_void_type(ty):
    """Check if a type is void."""
    bt = ast.BuiltinType.FROM(_unwrap(ty))
    if bt is None:
        return False
    return bt.builtin_kind == ast.BuiltinTypeKind.VOID


def _find_field(record_decl, name):
    """Find a field by name in a RecordDecl.

    Recurses into anonymous struct/union members, since C makes their
    fields accessible as if they were direct members of the parent.
    """
    for field in record_decl.fields:
        if field.name == name:
            return field
        if field.is_anonymous_struct_or_union:
            nested = _as_record(field.type)
            if nested is not None:
                found = _find_field(nested, name)
                if found is not None:
                    return found
    return None


_FIELD_NOT_FOUND = object()  # sentinel


def _resolve_field(record, mem, base_addr, ty, name):
    """Look up a field by name, handling anonymous members.

    Returns a MemoryView (or scalar for bitfields), or _FIELD_NOT_FOUND.
    """
    for field in record.fields:
        if field.name == name:
            if field.offset_in_bits is None:
                return _FIELD_NOT_FOUND
            if field.is_bit_field:
                return MemoryView(mem, base_addr, ty)._read_bitfield(
                    field, record)
            offset = field.offset_in_bits // 8
            return MemoryView(mem, base_addr + offset, field.type)
        if field.is_anonymous_struct_or_union:
            nested = _as_record(field.type)
            if nested is not None:
                anon_offset = (field.offset_in_bits or 0) // 8
                result = _resolve_field(nested, mem,
                                        base_addr + anon_offset,
                                        field.type, name)
                if result is not _FIELD_NOT_FOUND:
                    return result
    return _FIELD_NOT_FOUND


def _write_field(record, mem, base_addr, ty, name, value):
    """Write to a field by name, handling anonymous members. Returns True if found."""
    for field in record.fields:
        if field.name == name:
            if field.is_bit_field:
                MemoryView(mem, base_addr, ty)._write_bitfield(
                    field, record, value)
            else:
                offset = (field.offset_in_bits or 0) // 8
                sub = MemoryView(mem, base_addr + offset, field.type)
                sub.write(value)
            return True
        if field.is_anonymous_struct_or_union:
            nested = _as_record(field.type)
            if nested is not None:
                anon_offset = (field.offset_in_bits or 0) // 8
                if _write_field(nested, mem, base_addr + anon_offset,
                                field.type, name, value):
                    return True
    return False


def _collect_field_names(record_decl):
    """Collect all accessible field names, recursing into anonymous members."""
    names = []
    for f in record_decl.fields:
        if f.is_anonymous_struct_or_union:
            nested = _as_record(f.type)
            if nested is not None:
                names.extend(_collect_field_names(nested))
        elif f.name:
            names.append(f.name)
    return names


def _bitfield_width_from_layout(field, record):
    """Compute bitfield width from the parent record's field layout.

    Uses field offsets (computed by Clang) rather than parsing the bit_width
    expression tokens, which is fragile for macros and complex constant
    expressions.
    """
    fields = list(record.fields)
    field_offset = field.offset_in_bits
    for i, f in enumerate(fields):
        if f.offset_in_bits != field_offset:
            continue
        if f.name != field.name:
            continue
        # Found — compute width from next field's offset.
        if i + 1 < len(fields) and fields[i + 1].offset_in_bits is not None:
            return fields[i + 1].offset_in_bits - field_offset
        # Last field: use record size.
        ty = record.type_for_declaration
        if ty is not None:
            total_bits = _unwrap(ty).size_in_bits
            if total_bits is not None:
                return total_bits - field_offset
        break
    raise TypeError(f"Cannot determine bitfield width for '{field.name}'")


def _array_element_count(ty):
    """Compute element count of a ConstantArrayType from sizes."""
    ty = _unwrap(ty)
    total_bits = ty.size_in_bits
    arr = ast.ArrayType.FROM(ty)
    if total_bits is None or arr is None:
        return None
    elem_bits = _unwrap(arr.element_type).size_in_bits
    if elem_bits is None or elem_bits == 0:
        return None
    return total_bits // elem_bits


_PACK_INT = {
    (1, False): '<B', (1, True): '<b',
    (2, False): '<H', (2, True): '<h',
    (4, False): '<I', (4, True): '<i',
    (8, False): '<Q', (8, True): '<q',
}
_PACK_FLOAT = {4: '<f', 8: '<d'}


def _decode_scalar(raw_bytes, ty):
    """Decode raw bytes into a Python value based on type."""
    size = len(raw_bytes)
    if _as_pointer(ty) is not None:
        return _struct.unpack('<Q' if size == 8 else '<I', raw_bytes)[0]
    if _is_float_type(ty):
        fmt = _PACK_FLOAT.get(size)
        if fmt:
            return _struct.unpack(fmt, raw_bytes)[0]
    if _is_bool_type(ty):
        return bool(_struct.unpack('<B', raw_bytes[:1])[0])
    signed = _is_signed_int_type(ty)
    fmt = _PACK_INT.get((size, signed))
    if fmt:
        return _struct.unpack(fmt, raw_bytes)[0]
    return int.from_bytes(raw_bytes, 'little', signed=signed)


def _encode_scalar(value, ty, size):
    """Encode a Python value into raw bytes based on type."""
    if _as_pointer(ty) is not None:
        return _struct.pack('<Q' if size == 8 else '<I', int(value))
    if _is_float_type(ty):
        fmt = _PACK_FLOAT.get(size)
        if fmt:
            return _struct.pack(fmt, float(value))
    signed = _is_signed_int_type(ty)
    fmt = _PACK_INT.get((size, signed))
    if fmt:
        v = int(value)
        if not signed:
            v &= (1 << (size * 8)) - 1
        return _struct.pack(fmt, v)
    v = int(value)
    if v < 0:
        return v.to_bytes(size, 'little', signed=True)
    return v.to_bytes(size, 'little', signed=False)


# ============================================================================
# MemoryView
# ============================================================================

class MemoryView:
    """Typed lens over a region of ConcreteMemory.

    A MemoryView does not own memory. It provides typed read/write access
    to the bytes at a given address, interpreted according to a multiplier
    type.

    Struct fields are accessible via attribute access:
        view.x = 10
        print(view.x)

    Array elements via indexing:
        view[0] = 100
        for elem in view: ...

    Pointer dereference:
        target = view.deref()
    """

    __slots__ = ('_mem', '_addr', '_type')

    def __init__(self, mem, addr, ty):
        object.__setattr__(self, '_mem', mem)
        object.__setattr__(self, '_addr', addr)
        object.__setattr__(self, '_type', ty)

    # --- Scalar read/write ---

    def read(self):
        """Read the value at this address, interpreted by this type."""
        # For structs/arrays, return self (navigate with field/index access).
        if _as_record(self._type) is not None:
            return self
        if _as_array(self._type) is not None:
            return self
        size = _type_size_bytes(self._type)
        raw = self._mem.read_bytes(self._addr, size)
        return _decode_scalar(raw, self._type)

    def write(self, value):
        """Write a value at this address, encoded by this type."""
        if isinstance(value, MemoryView):
            # Copy bytes from another view.
            size = min(self.size, value.size)
            raw = value._mem.read_bytes(value._addr, size)
            self._mem.write_bytes(self._addr, raw)
            return
        size = _type_size_bytes(self._type)
        raw = _encode_scalar(value, self._type, size)
        self._mem.write_bytes(self._addr, raw)

    def read_bytes(self):
        """Read the raw bytes at this address."""
        return self._mem.read_bytes(self._addr, _type_size_bytes(self._type))

    def write_bytes(self, data):
        """Write raw bytes at this address."""
        self._mem.write_bytes(self._addr, data)

    # --- Struct field access ---

    def __getattribute__(self, name):
        # Fast path: private names bypass field lookup.
        if name.startswith('_'):
            return object.__getattribute__(self, name)
        # For struct/union types, field access wins over methods.
        try:
            ty = object.__getattribute__(self, '_type')
            record = _as_record(ty)
            if record is not None:
                mem = object.__getattribute__(self, '_mem')
                addr = object.__getattribute__(self, '_addr')
                result = _resolve_field(record, mem, addr, ty, name)
                if result is not _FIELD_NOT_FOUND:
                    return result
        except AttributeError:
            pass
        # Fall through to normal lookup (methods, properties, etc.)
        return object.__getattribute__(self, name)

    def __getattr__(self, name):
        # Called only if __getattribute__ didn't find anything.
        raise AttributeError(
            f"'{type(self).__name__}' has no attribute '{name}'")

    def __setattr__(self, name, value):
        if name.startswith('_'):
            object.__setattr__(self, name, value)
            return
        record = _as_record(self._type)
        if record is None:
            raise AttributeError(
                f"Type is not a struct/union, cannot set field '{name}'")
        if not _write_field(record, self._mem, self._addr, self._type,
                            name, value):
            raise AttributeError(
                f"No field '{name}' in {record.name}")

    def field(self, name):
        """Explicit field access (alternative to __getattr__)."""
        return self.__getattr__(name)

    def field_names(self):
        """List field names if this is a struct/union.

        Includes fields from anonymous struct/union members (flattened).
        """
        record = _as_record(self._type)
        if record is None:
            return []
        return _collect_field_names(record)

    # --- Bitfield support ---

    def _read_bitfield(self, field, record):
        """Read a bitfield value via C++ bit-level memory ops."""
        offset = field.offset_in_bits
        width = _bitfield_width_from_layout(field, record)
        raw = self._mem.read_bits(self._addr, offset, width)
        if _is_signed_int_type(field.type) and (raw & (1 << (width - 1))):
            raw -= (1 << width)
        return raw

    def _write_bitfield(self, field, record, value):
        """Write a bitfield value via C++ bit-level memory ops."""
        offset = field.offset_in_bits
        width = _bitfield_width_from_layout(field, record)
        self._mem.write_bits(
            self._addr, offset, width,
            int(value) & ((1 << width) - 1))

    # --- Array element access ---

    def __getitem__(self, index):
        arr = _as_array(self._type)
        if arr is not None:
            elem_type = arr.element_type
            elem_size = _type_size_bytes(elem_type)
            if isinstance(index, slice):
                count = _array_element_count(self._type)
                indices = range(*index.indices(count if count else 0))
                return [MemoryView(self._mem,
                                   self._addr + i * elem_size,
                                   elem_type) for i in indices]
            return MemoryView(self._mem,
                              self._addr + index * elem_size,
                              elem_type)
        raise TypeError("Type is not an array")

    def __setitem__(self, index, value):
        self[index].write(value)

    def __len__(self):
        count = _array_element_count(self._type)
        if count is None:
            raise TypeError("Type is not a fixed-size array")
        return count

    def __iter__(self):
        for i in range(len(self)):
            yield self[i]

    # --- Pointer operations ---

    def deref(self):
        """Follow this pointer, return a view of the pointee."""
        ptr = _as_pointer(self._type)
        if ptr is None:
            raise TypeError("Type is not a pointer")
        # Read the pointer value (an address).
        size = _type_size_bytes(self._type)
        raw = self._mem.read_bytes(self._addr, size)
        target_addr = int.from_bytes(raw, 'little')
        return MemoryView(self._mem, target_addr, ptr.pointee_type)

    def cast(self, new_type):
        """Reinterpret this memory location as a different type."""
        return MemoryView(self._mem, self._addr, new_type)

    # --- Allocate + view (convenience) ---

    @staticmethod
    def alloc(mem, ty, align=None):
        """Allocate memory for this type and return a view."""
        size = _type_size_bytes(ty)
        al = align or _type_align_bytes(ty)
        addr = mem.allocate(size, al)
        return MemoryView(mem, addr, ty)

    # --- Display ---

    def __repr__(self):
        record = _as_record(self._type)
        if record is not None:
            return f"MemoryView(addr=0x{self._addr:x}, struct {record.name})"
        arr = _as_constant_array(self._type)
        if arr is not None:
            count = _array_element_count(self._type)
            return (f"MemoryView(addr=0x{self._addr:x}, "
                    f"array[{count}])")
        ptr = _as_pointer(self._type)
        if ptr is not None:
            return f"MemoryView(addr=0x{self._addr:x}, pointer)"
        return f"MemoryView(addr=0x{self._addr:x}, scalar)"

    def __int__(self):
        return int(self.read())

    def __float__(self):
        return float(self.read())

    def __bool__(self):
        # A MemoryView is always truthy — it represents a valid memory region.
        return True

    @property
    def address(self):
        """The base address of this view."""
        return self._addr

    @property
    def type(self):
        """The multiplier type of this view."""
        return self._type

    @property
    def size(self):
        """The size of this view in bytes."""
        return _type_size_bytes(self._type)


# ============================================================================
# CallFrame
# ============================================================================

class CallFrame:
    """Typed call frame: allocates and provides MemoryViews for args + return.

    Usage:
        frame = CallFrame(mem, func)
        frame.arg(0).write(42)
        frame.arg(1).x = 10  # if arg 1 is a struct

        # ... run interpreter ...

        ret = frame.return_value()
        print(ret.read())      # scalar return
        print(ret.x, ret.y)   # struct return
    """

    __slots__ = ('_mem', '_func', '_arg_views', '_ret_view')

    def __init__(self, mem, func):
        self._mem = mem
        self._func = func
        self._arg_views = []
        self._ret_view = None

        decl = func.declaration
        if decl is None:
            raise TypeError("IRFunction has no declaration")

        # Get parameter types from the function's parameters.
        for param in decl.parameters:
            param_type = param.type
            try:
                view = MemoryView.alloc(mem, param_type)
            except TypeError:
                # Parameter type has no known size — allocate 8 bytes.
                addr = mem.allocate(8, 8)
                view = MemoryView(mem, addr, param_type)
            self._arg_views.append(view)

        # Allocate return slot.
        ret_type = decl.return_type
        if not _is_void_type(ret_type):
            try:
                self._ret_view = MemoryView.alloc(mem, ret_type)
            except TypeError:
                pass

    def arg(self, index):
        """Get a MemoryView for the given argument slot."""
        if index < 0 or index >= len(self._arg_views):
            raise IndexError(
                f"Argument index {index} out of range "
                f"(function has {len(self._arg_views)} parameters)")
        return self._arg_views[index]

    def return_value(self):
        """Get a MemoryView for the return value slot, or None for void."""
        return self._ret_view

    @property
    def num_args(self):
        """Number of declared parameters."""
        return len(self._arg_views)

    @property
    def arg_addresses(self):
        """List of pre-allocated argument addresses (for init_state)."""
        return [v.address for v in self._arg_views]

    @property
    def return_address(self):
        """Pre-allocated return value address, or None."""
        return self._ret_view.address if self._ret_view is not None else None

    def init_state(self, state, policy,
                   func_resolver=None, global_resolver=None):
        """Initialize interpreter state using this frame's pre-allocated addresses.

        Equivalent to:
            init_state_frame(state, mem, policy, func,
                             frame.arg_addresses, frame.return_address,
                             func_resolver, global_resolver)
        """
        init_state_frame = multiplier.ir.interpret.init_state_frame
        init_state_frame(state, self._mem, policy, self._func,
                         self.arg_addresses, self.return_address,
                         func_resolver, global_resolver)

    def __repr__(self):
        name = "?"
        decl = self._func.declaration
        if decl is not None:
            name = decl.name
        return (f"CallFrame({name}, "
                f"{self.num_args} args, "
                f"ret={'void' if self._ret_view is None else 'allocated'})")
