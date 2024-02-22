
namespace A {
    struct B { };
    void operator+(B, B);
}

using A::operator+;
