
class ValueType {};
template<typename T>
class Signature {};

using FunctionSig = Signature<ValueType>;

class WasmModuleBuilder {
  public:
    explicit WasmModuleBuilder(void);

    int ForceAddSignature(const FunctionSig* sig, bool is_final, int supertype);
};

template <typename T, int kNumReturns = 0, int kNumParams = 0>
class FixedSizeSignature : public Signature<T> {
 public:
  template <typename... ReturnTypes>
  static auto Returns(ReturnTypes... return_types) {
    return FixedSizeSignature<T, sizeof...(ReturnTypes), kNumParams>();
  }

};

class WasmModule {
public:
  void test () {
    WasmModuleBuilder builder;
    constexpr bool kIsFinal = true;
    constexpr int kSuperType = 1;
    constexpr int kWasmI32 = 32;
    auto kMainFnSig = FixedSizeSignature<ValueType>::Returns(kWasmI32);
    builder.ForceAddSignature(&kMainFnSig, kIsFinal, kSuperType);
  }
};
