int symbolic_test_logical_and(int a, int b) { return a && b; }
int symbolic_test_logical_or(int a, int b)  { return a || b; }
int symbolic_test_select_i32(int cond, int a, int b) { return cond ? a : b; }
