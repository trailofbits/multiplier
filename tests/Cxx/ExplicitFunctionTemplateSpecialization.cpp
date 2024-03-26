namespace ExplicitFunctionTemplateSpecialization {

class 
__attribute__ ( ( visibility ( "default" ) ) )
QMetaType {
public:
  template<typename T>
    constexpr static QMetaType fromType();
};

template<typename T>
constexpr QMetaType QMetaType::fromType()
{
    return QMetaType();
}

namespace x {
class Bar {
  void qt_static_metacall(QMetaType *type);
};
class Baz {
  void qt_static_metacall(QMetaType *type);
};
}

void x::Bar::qt_static_metacall(QMetaType *type) {
  *type = QMetaType::fromType<Bar *>();
}

void x::Baz::qt_static_metacall(QMetaType *type) {
  *type = QMetaType::fromType<Baz *>();
}

}