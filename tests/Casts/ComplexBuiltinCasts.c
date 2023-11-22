void another_func(long int) {
    return;
}

void TestFuncCallCastExplicit() {
    int a = 5;
    another_func(a);
}

void TestFuncCallCastImplicit() {
    int a = 5;
    another_func((long)a);
}

void TestMultipleExplicitCast() {
    char test = (char) (int) 7.99;
}