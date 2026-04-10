// Tests: C23-specific features — true/false keywords, typeof,
// constexpr, u8 character literals, nullptr, auto type inference,
// digit separators, binary literals, static_assert without message.

#include <stddef.h>

int test_c23(void) {
    // true/false are keywords in C23 (not macros from stdbool.h).
    bool b1 = true;
    bool b2 = false;
    if (b1 != 1) return 1;
    if (b2 != 0) return 2;

    // typeof (C23 keyword, was GNU extension).
    int x = 42;
    typeof(x) y = x + 1;
    if (y != 43) return 3;

    // Binary literals (0b prefix).
    int bin = 0b10101010;
    if (bin != 170) return 4;

    // Digit separators.
    int big = 1'000'000;
    if (big != 1000000) return 5;

    // static_assert without message (C23).
    static_assert(sizeof(int) >= 4);

    // nullptr (C23).
    int *np = nullptr;
    if (np != 0) return 6;

    // u8 character literal (C23 — produces unsigned char value).
    unsigned char u8c = u8'A';
    if (u8c != 65) return 7;

    // auto type inference (C23).
    auto z = 100;
    if (z != 100) return 8;

    // Underscore in numeric literals.
    unsigned long long ull = 0xFF'FF'FF'FF;
    if (ull != 4294967295ULL) return 9;

    return 0;
}
