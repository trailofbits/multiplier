namespace FunctionSpecializationOnMacroExpansion {
namespace std {
    class string {};
}

#define V8_BASE_EXPORT

// Define default PrintCheckOperand<T> for non-printable types.
template <typename T>
std::string PrintCheckOperand(T val) {
  return std::string();
}

// Define specializations for character types, defined in logging.cc.
#define DEFINE_PRINT_CHECK_OPERAND_CHAR(type)                       \
  template <>                                                       \
  V8_BASE_EXPORT std::string PrintCheckOperand<type>(type ch);      \
  template <>                                                       \
  V8_BASE_EXPORT std::string PrintCheckOperand<type*>(type * cstr); \
  template <>                                                       \
  V8_BASE_EXPORT std::string PrintCheckOperand<const type*>(const type* cstr);

DEFINE_PRINT_CHECK_OPERAND_CHAR(char)
DEFINE_PRINT_CHECK_OPERAND_CHAR(signed char)
DEFINE_PRINT_CHECK_OPERAND_CHAR(unsigned char)
#undef DEFINE_PRINT_CHECK_OPERAND_CHAR

}