// This tests the `CFAvailability.h` pattern used in `CFData.h` in macOS.

#define ENUM_OPTIONS __attribute__((flag_enum,enum_extensibility(open)))

#define NAMED_ENUM(enum_name, typedef_name) \
    enum ENUM_OPTIONS enum_name typedef_name ; enum enum_name

#define ENUM_AVAILABILITY(os) __attribute__((availability(os, introduced=14.0)))

typedef NAMED_ENUM(CFAvailableEnum, CFAvailable) {
  kFooBar
} ENUM_AVAILABILITY(macos);
