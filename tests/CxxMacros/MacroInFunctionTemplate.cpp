namespace MacroInFunctionTemplate {

struct MachineAssembler {
  void AssertNotSmi(void);
};

#define __ masm->

template <typename T>
void GenerateTypedArrayStore(MachineAssembler *masm) {
  __ AssertNotSmi();
}

int test() {
  MachineAssembler masm;
  GenerateTypedArrayStore<int>(&masm);
}

}  // namespace MacroInFunctionTemplate