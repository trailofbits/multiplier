
// This is an example derived from the XNU kernel in zalloc.h

#define __options_decl(name, type, ...) enum name __VA_ARGS__

__options_decl(flags, int, {
    BLAH = 0
#define Z_VM_TAG 0
});

int DefineInMacroUse(void) {
  return Z_VM_TAG;
}
