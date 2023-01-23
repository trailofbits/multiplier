#define XMACRO(name) int g ## name;
#include XMACRO_GEN_H
#undef XMACRO
