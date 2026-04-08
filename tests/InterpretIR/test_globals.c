// Tests: global variable initialization (GLOBAL_INITIALIZER functions),
// global pointer access (GLOBAL_PTR), static local variables,
// and aggregate global initialization (MEMSET + element stores).

int g_simple = 42;
int g_array[3] = {1, 2, 3};

struct Config {
    int width;
    int height;
    int depth;
};
struct Config g_config = {640, 480, 32};

static int g_static = 100;

int test_globals(void) {
    // Simple global.
    if (g_simple != 42) return 1;

    // Global array.
    if (g_array[0] != 1) return 2;
    if (g_array[1] != 2) return 3;
    if (g_array[2] != 3) return 4;

    // Global struct.
    if (g_config.width != 640) return 5;
    if (g_config.height != 480) return 6;
    if (g_config.depth != 32) return 7;

    // Static local.
    static int s_local = 77;
    if (s_local != 77) return 8;

    // File-scope static.
    if (g_static != 100) return 9;

    // Modify global.
    g_simple = 99;
    if (g_simple != 99) return 10;

    return 0;
}
