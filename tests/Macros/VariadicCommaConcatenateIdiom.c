
// This is an example taken from the Linux kernel.
int VariadicCommaConcatenateIdiom(struct {int counter;} * v, int i) {
#define true 1
#define false 0
#define bool int
  bool c = false;

#define asm_volatile_goto(x...) asm goto(x)
#define LOCK_PREFIX "\n\tlock; "
#define __GEN_RMWcc(fullop, _var, cc, clobbers, ...)      \
({                  \
  bool c = false;             \
  asm_volatile_goto (fullop "; j" #cc " %l[cc_label]"   \
      : : [var] "m" (_var), ## __VA_ARGS__    \
      : clobbers : cc_label);       \
  if (0) {              \
cc_label: c = true;           \
  }               \
  c;                \
})

#define __CLOBBERS_MEM(clb...)  "memory", ## clb

#define __RMWcc_CONCAT(a, b) a ## b
#define RMWcc_CONCAT(a, b) __RMWcc_CONCAT(a, b)

/* This counts to 12. Any more, it will return 13th argument. */
#define __RMWcc_ARGS(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _n, X...) _n
#define RMWcc_ARGS(X...) __RMWcc_ARGS(, ##X, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define GEN_UNARY_RMWcc_4(op, var, cc, arg0)        \
  __GEN_RMWcc(op " " arg0, var, cc, __CLOBBERS_MEM())

#define GEN_UNARY_RMWcc_3(op, var, cc)          \
  GEN_UNARY_RMWcc_4(op, var, cc, "%[var]")

#define GEN_UNARY_RMWcc(X...) RMWcc_CONCAT(GEN_UNARY_RMWcc_, RMWcc_ARGS(X))(X)

#define GEN_BINARY_RMWcc_6(op, var, cc, vcon, _val, arg0)   \
  __GEN_RMWcc(op " %[val], " arg0, var, cc,     \
        __CLOBBERS_MEM(), [val] vcon (_val))

#define GEN_BINARY_RMWcc_5(op, var, cc, vcon, val)      \
  GEN_BINARY_RMWcc_6(op, var, cc, vcon, val, "%[var]")

#define GEN_BINARY_RMWcc(X...) RMWcc_CONCAT(GEN_BINARY_RMWcc_, RMWcc_ARGS(X))(X)

  return GEN_BINARY_RMWcc(LOCK_PREFIX "subl", v->counter, e, "er", i);
}
