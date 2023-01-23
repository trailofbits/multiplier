#define XMACRO(name) k ## name,
#include XMACRO_GEN_H
#undef XMACRO
