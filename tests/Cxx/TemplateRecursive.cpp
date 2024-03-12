namespace TemplateRecursive {
class base { };

template <class T> class foo : public base  {
  void operator=(const foo r) { }
};

class bar : public foo<void> { };
bar filters;

} // namespace TemplateRecursive
