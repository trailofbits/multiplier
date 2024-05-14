
typedef int cordz_info_t;
typedef unsigned long long size_t;
typedef long long intptr_t;
typedef unsigned long long uintptr_t;
typedef unsigned long long uint64_t;
typedef signed char int8_t;

extern "C" int memcmp(const void *, const void *, size_t);
extern "C" void *memcpy(void *, const void *, size_t);
extern "C" void __assert_rtn(const char *);

namespace absl {
static constexpr bool is_constant_evaluated(void) {
    return true;
}
static constexpr size_t kMaxInline = 15;

namespace little_endian {
inline static uint64_t FromHost64(uint64_t x) {
    return x;
}
inline static uint64_t ToHost64(uint64_t x) {
    return x;
}
}  // namespace little_endian
namespace cord_internal {
struct CordRep {};
}  // namespace cord_internal

using CordRep = cord_internal::CordRep;

struct string_view {
    size_t size(void);
};
struct CordzInfo {};

#define ABSL_CORD_INTERNAL_NO_SANITIZE
//#define ABSL_INTERNAL_CORD_HAVE_SANITIZER

#define assert(...) __assert_rtn(__func__)
#define ABSL_PREDICT_TRUE(cond) __builtin_expect((cond), true)
#define ABSL_ASSERT(cond) \
  (ABSL_PREDICT_TRUE(cond) ? static_cast<void>(0) : []{ assert(false); }())


inline static constexpr cordz_info_t LittleEndianByte(int) {
    return 1;
}

inline static char GetOrNull(string_view, int) {
    return '\0';
}

class InlineData {
 public:
  // DefaultInitType forces the use of the default initialization constructor.
  enum DefaultInitType { kDefaultInit };

  // kNullCordzInfo holds the little endian representation of intptr_t(1)
  // This is the 'null' / initial value of 'cordz_info'. The null value
  // is specifically big endian 1 as with 64-bit pointers, the last
  // byte of cordz_info overlaps with the last byte holding the tag.
  static constexpr cordz_info_t kNullCordzInfo = LittleEndianByte(1);

  // kTagOffset contains the offset of the control byte / tag. This constant is
  // intended mostly for debugging purposes: do not remove this constant as it
  // is actively inspected and used by gdb pretty printing code.
  static constexpr size_t kTagOffset = 0;

  // Implement `~InlineData()` conditionally: we only need this destructor to
  // unpoison poisoned instances under *SAN, and it will only compile correctly
  // if the current compiler supports `absl::is_constant_evaluated()`.
#ifdef ABSL_INTERNAL_CORD_HAVE_SANITIZER
  ~InlineData() noexcept { unpoison(); }
#endif

  constexpr InlineData() noexcept { poison_this(); }

  explicit InlineData(DefaultInitType) noexcept : rep_(kDefaultInit) {
    poison_this();
  }

  explicit InlineData(CordRep* rep) noexcept : rep_(rep) {
    ABSL_ASSERT(rep != nullptr);
  }

  // Explicit constexpr constructor to create a constexpr InlineData
  // value. Creates an inlined SSO value if `rep` is null, otherwise
  // creates a tree instance value.
  constexpr InlineData(absl::string_view sv, CordRep* rep) noexcept
      : rep_(rep ? Rep(rep) : Rep(sv)) {
    poison();
  }

  constexpr InlineData(const InlineData& rhs) noexcept;
  InlineData& operator=(const InlineData& rhs) noexcept;

  friend bool operator==(const InlineData& lhs, const InlineData& rhs) {
#ifdef ABSL_INTERNAL_CORD_HAVE_SANITIZER
    const Rep l = lhs.rep_.SanitizerSafeCopy();
    const Rep r = rhs.rep_.SanitizerSafeCopy();
    return memcmp(&l, &r, sizeof(l)) == 0;
#else
    return memcmp(&lhs, &rhs, sizeof(lhs)) == 0;
#endif
  }
  friend bool operator!=(const InlineData& lhs, const InlineData& rhs) {
    return !operator==(lhs, rhs);
  }

  // Poisons the unused inlined SSO data if the current instance
  // is inlined, else un-poisons the entire instance.
  constexpr void poison();

  // Un-poisons this instance.
  constexpr void unpoison();

  // Poisons the current instance. This is used on default initialization.
  constexpr void poison_this();

  // Returns true if the current instance is empty.
  // The 'empty value' is an inlined data value of zero length.
  bool is_empty() const { return rep_.tag() == 0; }

  // Returns true if the current instance holds a tree value.
  bool is_tree() const { return (rep_.tag() & 1) != 0; }

  // Returns true if the current instance holds a cordz_info value.
  // Requires the current instance to hold a tree value.
  bool is_profiled() const {
    assert(is_tree());
    return rep_.cordz_info() != kNullCordzInfo;
  }

  // Returns true if either of the provided instances hold a cordz_info value.
  // This method is more efficient than the equivalent `data1.is_profiled() ||
  // data2.is_profiled()`. Requires both arguments to hold a tree.
  static bool is_either_profiled(const InlineData& data1,
                                 const InlineData& data2) {
    assert(data1.is_tree() && data2.is_tree());
    return (data1.rep_.cordz_info() | data2.rep_.cordz_info()) !=
           kNullCordzInfo;
  }

  // Returns the cordz_info sampling instance for this instance, or nullptr
  // if the current instance is not sampled and does not have CordzInfo data.
  // Requires the current instance to hold a tree value.
  CordzInfo* cordz_info() const {
    assert(is_tree());
    intptr_t info = static_cast<intptr_t>(absl::little_endian::ToHost64(
        static_cast<uint64_t>(rep_.cordz_info())));
    assert(info & 1);
    return reinterpret_cast<CordzInfo*>(info - 1);
  }

  // Sets the current cordz_info sampling instance for this instance, or nullptr
  // if the current instance is not sampled and does not have CordzInfo data.
  // Requires the current instance to hold a tree value.
  void set_cordz_info(CordzInfo* cordz_info) {
    assert(is_tree());
    uintptr_t info = reinterpret_cast<uintptr_t>(cordz_info) | 1;
    rep_.set_cordz_info(
        static_cast<cordz_info_t>(absl::little_endian::FromHost64(info)));
  }

  // Resets the current cordz_info to null / empty.
  void clear_cordz_info() {
    assert(is_tree());
    rep_.set_cordz_info(kNullCordzInfo);
  }

  // Returns a read only pointer to the character data inside this instance.
  // Requires the current instance to hold inline data.
  const char* as_chars() const {
    assert(!is_tree());
    return rep_.as_chars();
  }

  // Returns a mutable pointer to the character data inside this instance.
  // Should be used for 'write only' operations setting an inlined value.
  // Applications can set the value of inlined data either before or after
  // setting the inlined size, i.e., both of the below are valid:
  //
  //   // Set inlined data and inline size
  //   memcpy(data_.as_chars(), data, size);
  //   data_.set_inline_size(size);
  //
  //   // Set inlined size and inline data
  //   data_.set_inline_size(size);
  //   memcpy(data_.as_chars(), data, size);
  //
  // It's an error to read from the returned pointer without a preceding write
  // if the current instance does not hold inline data, i.e.: is_tree() == true.
  char* as_chars() { return rep_.as_chars(); }

  // Returns the tree value of this value.
  // Requires the current instance to hold a tree value.
  CordRep* as_tree() const {
    assert(is_tree());
    return rep_.tree();
  }

  void set_inline_data(const char* data, size_t n) {
    ABSL_ASSERT(n <= kMaxInline);
    unpoison();
    rep_.set_tag(static_cast<int8_t>(n << 1));
    memcpy(rep_.as_chars(), data, n);
    poison();
  }

  void copy_max_inline_to(char* dst) const {
    assert(!is_tree());
    memcpy(dst, rep_.SanitizerSafeCopy().as_chars(), kMaxInline);
  }

  // Initialize this instance to holding the tree value `rep`,
  // initializing the cordz_info to null, i.e.: 'not profiled'.
  void make_tree(CordRep* rep) {
    unpoison();
    rep_.make_tree(rep);
  }

  // Set the tree value of this instance to 'rep`.
  // Requires the current instance to already hold a tree value.
  // Does not affect the value of cordz_info.
  void set_tree(CordRep* rep) {
    assert(is_tree());
    rep_.set_tree(rep);
  }

  // Returns the size of the inlined character data inside this instance.
  // Requires the current instance to hold inline data.
  size_t inline_size() const { return rep_.inline_size(); }

  // Sets the size of the inlined character data inside this instance.
  // Requires `size` to be <= kMaxInline.
  // See the documentation on 'as_chars()' for more information and examples.
  void set_inline_size(size_t size) {
    unpoison();
    rep_.set_inline_size(size);
    poison();
  }

  // Compares 'this' inlined data  with rhs. The comparison is a straightforward
  // lexicographic comparison. `Compare()` returns values as follows:
  //
  //   -1  'this' InlineData instance is smaller
  //    0  the InlineData instances are equal
  //    1  'this' InlineData instance larger
  int Compare(const InlineData& rhs) const {
    return Compare(rep_.SanitizerSafeCopy(), rhs.rep_.SanitizerSafeCopy());
  }

 private:
  struct Rep {
    // See cordz_info_t for forced alignment and size of `cordz_info` details.
    struct AsTree {
      explicit constexpr AsTree(absl::cord_internal::CordRep* tree)
          : rep(tree) {}
      cordz_info_t cordz_info = kNullCordzInfo;
      absl::cord_internal::CordRep* rep;
    };

    explicit Rep(DefaultInitType) {}
    constexpr Rep() : data{0} {}
    constexpr Rep(const Rep&) = default;
    constexpr Rep& operator=(const Rep&) = default;

    explicit constexpr Rep(CordRep* rep) : as_tree(rep) {}

    explicit constexpr Rep(absl::string_view chars)
        : data{static_cast<char>((chars.size() << 1)),
               GetOrNull(chars, 0),
               GetOrNull(chars, 1),
               GetOrNull(chars, 2),
               GetOrNull(chars, 3),
               GetOrNull(chars, 4),
               GetOrNull(chars, 5),
               GetOrNull(chars, 6),
               GetOrNull(chars, 7),
               GetOrNull(chars, 8),
               GetOrNull(chars, 9),
               GetOrNull(chars, 10),
               GetOrNull(chars, 11),
               GetOrNull(chars, 12),
               GetOrNull(chars, 13),
               GetOrNull(chars, 14)} {}

    // Disable sanitizer as we must always be able to read `tag`.
    ABSL_CORD_INTERNAL_NO_SANITIZE
    int8_t tag() const { return reinterpret_cast<const int8_t*>(this)[0]; }
    void set_tag(int8_t rhs) { reinterpret_cast<int8_t*>(this)[0] = rhs; }

    char* as_chars() { return data + 1; }
    const char* as_chars() const { return data + 1; }

    bool is_tree() const { return (tag() & 1) != 0; }

    size_t inline_size() const {
      ABSL_ASSERT(!is_tree());
      return static_cast<size_t>(tag()) >> 1;
    }

    void set_inline_size(size_t size) {
      ABSL_ASSERT(size <= kMaxInline);
      set_tag(static_cast<int8_t>(size << 1));
    }

    CordRep* tree() const { return as_tree.rep; }
    void set_tree(CordRep* rhs) { as_tree.rep = rhs; }

    cordz_info_t cordz_info() const { return as_tree.cordz_info; }
    void set_cordz_info(cordz_info_t rhs) { as_tree.cordz_info = rhs; }

    void make_tree(CordRep* tree) {
      as_tree.rep = tree;
      as_tree.cordz_info = kNullCordzInfo;
    }

#ifdef ABSL_INTERNAL_CORD_HAVE_SANITIZER
    constexpr Rep SanitizerSafeCopy() const {
      if (!absl::is_constant_evaluated()) {
        Rep res;
        if (is_tree()) {
          res = *this;
        } else {
          res.set_tag(tag());
          memcpy(res.as_chars(), as_chars(), inline_size());
        }
        return res;
      } else {
        return *this;
      }
    }
#else
    constexpr const Rep& SanitizerSafeCopy() const { return *this; }
#endif

    // If the data has length <= kMaxInline, we store it in `data`, and
    // store the size in the first char of `data` shifted left + 1.
    // Else we store it in a tree and store a pointer to that tree in
    // `as_tree.rep` with a tagged pointer to make `tag() & 1` non zero.
    union {
      char data[kMaxInline + 1];
      AsTree as_tree;
    };
  };

  // Private implementation of `Compare()`
  static inline int Compare(const Rep& lhs, const Rep& rhs) {
    return 1;
  }

  Rep rep_;
};

}  // namespace absl
