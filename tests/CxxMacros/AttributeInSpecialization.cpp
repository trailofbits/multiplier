namespace AttributeInSpecialization {

// TODO(pag): Putting the `EXPORT` inside the `Template` causes Persist.cpp
//            issues because the `EXPORT` might show up as a top-level macro.
#define EXPORT __attribute__((visibility("default")))

template <typename T>
class Template {
  /* Should have EXPORT before `;` */
  T Foo(void) EXPORT; 
};

/* Should have EXPORT before `int` */
template <>
EXPORT int Template<int>::Foo(void) {
  return 1;
}

/* Should NOT have EXPORT before { */
template <>
double Template<double>::Foo(void) {
  return 1.0;
}

}