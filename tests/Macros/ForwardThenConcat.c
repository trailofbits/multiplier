// Derived from PMU_FORMAT_ATTR and PMU_FORMAT_ATTR_SHOW in the Linux kernel.
//
// NOTE(pag): The `inner_param1 ## _concat_rhs` must be on a different line.
//            This test case is whitespace-sensitive. The issue was in PASTA,
//            where some token alignment was based on a raw location of
//            `inner_param1` that didn't strip the leading whitespace of the
//            line continuation.
//
// XREF(pag): Multiplier Issue #505: https://github.com/trailofbits/multiplier/issues/505

#define PMU_FORMAT_ATTR_SHOW(inner_param1, inner_param2) \
const char * \
inner_param1 \
## \
_concat_rhs() { return inner_param2; }

#define PMU_FORMAT_ATTR(outer_param1, outer_param2) \
    PMU_FORMAT_ATTR_SHOW(outer_param1, outer_param2)

PMU_FORMAT_ATTR(arg1, "arg2")
