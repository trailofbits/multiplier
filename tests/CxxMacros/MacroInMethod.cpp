namespace MacroInMethod {

// TODO(pag): Putting the `EXPORT` inside the `Template` causes Persist.cpp
//            issues because the `EXPORT` might show up as a top-level macro.
#define MACRO_IN_METHOD(x) x()

template <typename T>
class Template {
 public:
  /* Should have MACRO_IN_METHOD in `Foo`. */
  T Foo(void) {
    return MACRO_IN_METHOD(T);
  } 
};

int X = Template<int>().Foo();

}