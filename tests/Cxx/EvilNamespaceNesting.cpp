namespace EvilNamespaceNesting {
namespace foo {

#define EVIL_NAMESPACE_NESTING \
  } \
  class Foo {}; \
  namespace foo {

// This is an example of something that happens in Qt with the following macro:
// QT_METATYPE_PRIVATE_DECLARE_TYPEINFO(QPairVariantInterfaceImpl, Q_RELOCATABLE_TYPE)
EVIL_NAMESPACE_NESTING

}
}