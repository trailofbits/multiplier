// This test reproduces Issue #457, discovered in cURL.
struct FragmentWithMultipleBounds {

#if 0
#endif

#ifdef SHORT_BOUNDS

#if 0
#endif

};

#if 0
#endif

#elifdef MEDIUM_BOUNDS
};

#else  // LONG_BOUNDS
};
#endif
