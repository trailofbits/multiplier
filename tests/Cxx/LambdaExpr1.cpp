int x  = 0;
struct P {
    P(int) {}
    ~P() { ++x; }
    auto by_val() {
        return [=]() { return P(1);}();
    }
};

void test(void) {
    P p1(1);
    auto t = decltype(p1.by_val())(p1.by_val());
}