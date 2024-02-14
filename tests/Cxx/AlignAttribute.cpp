template <typename T>
struct AlignedStorage {
  __attribute__((aligned(alignof(T)))) char data[sizeof(T)];
};

AlignedStorage<int> aligned_int_storage;
AlignedStorage<double> aligned_double_storage;