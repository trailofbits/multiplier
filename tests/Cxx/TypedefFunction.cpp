namespace TypedefFunction {
typedef bool hb_shape_func_t (int    *shape_plan,
                              int          *font,
                              void        *buffer,
                              void *features,
                                   unsigned int        num_features);
extern "C" __attribute__ ( ( __visibility__ ( "hidden" ) ) ) hb_shape_func_t _hb_ot_shape;
extern "C" __attribute__ ( ( __visibility__ ( "hidden" ) ) ) hb_shape_func_t _hb_fallback_shape;
}
