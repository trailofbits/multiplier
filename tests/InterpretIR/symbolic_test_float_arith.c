/* Declare fmod/fmodf directly to avoid system header dependency. */
float fmodf(float, float);
double fmod(double, double);

float  symbolic_test_fadd_f32(float a,  float b)  { return a + b; }
double symbolic_test_fadd_f64(double a, double b) { return a + b; }

float  symbolic_test_fsub_f32(float a,  float b)  { return a - b; }
double symbolic_test_fsub_f64(double a, double b) { return a - b; }

float  symbolic_test_fmul_f32(float a,  float b)  { return a * b; }
double symbolic_test_fmul_f64(double a, double b) { return a * b; }

float  symbolic_test_fdiv_f32(float a,  float b)  { return a / b; }
double symbolic_test_fdiv_f64(double a, double b) { return a / b; }

float  symbolic_test_frem_f32(float a,  float b)  { return fmodf(a, b); }
double symbolic_test_frem_f64(double a, double b) { return fmod(a, b); }

float  symbolic_test_fneg_f32(float a)  { return -a; }
double symbolic_test_fneg_f64(double a) { return -a; }
