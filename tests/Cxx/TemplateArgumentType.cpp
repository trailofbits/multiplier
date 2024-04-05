namespace TemplateArgumentType {
template <class T> class X {};
template <class T> void func(T t) {}
struct {} unnamed_object;

void func(void) {
    struct A {};
    enum {e1};
    typedef struct {} B;
    B b;
    X<A> x1;
    X<A*> x2;
    X<B> x3;
    func(e1);
    func(unnamed_object);
    func(b);
}
} // namespace TemplateArgumentType
