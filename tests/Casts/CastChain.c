void test_func(int val) {

}

void TestSimpleCastChain() {
    // SOURCE
    int source = 65;

    // int -> char implicit
    char dest0 = source;

    // int -> char explicit
    // SINK
    char dest1 = (char) source;

    // char -> long
    long dest2 = dest0;

    // long -> int
    // SINK
    test_func(dest2);

    // is_identity_preserving should be true
}

void TestCyclicCastChain() {
    int source = 65;
    char dest0 = source;

    // SINK even with destination reference to source
    source = dest0;

    // is_identity_preserving should be true
}

void TestComplexCastChain() {

    // long -> int;
    // int -> int;
    int source = (int) (long) 80000;

    // char * -> int *
    // int * -> void *
    void *test = (int*) (char *) source;
}