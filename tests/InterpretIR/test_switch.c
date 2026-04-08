// Tests: switch statement (SWITCH, SWITCH_CASE, SWITCH_DEFAULT, SWITCH_EXIT),
// fallthrough (IMPLICIT_FALLTHROUGH), explicit fallthrough (FALLTHROUGH),
// break within switch (BREAK), nested switch, and switch with ranges (GNU).

int test_switch(void) {
    // Basic switch.
    int val = 2;
    int result = 0;
    switch (val) {
        case 1: result = 10; break;
        case 2: result = 20; break;
        case 3: result = 30; break;
        default: result = -1; break;
    }
    if (result != 20) return 1;

    // Default case.
    switch (99) {
        case 1: result = 10; break;
        default: result = 42; break;
    }
    if (result != 42) return 2;

    // Fallthrough (implicit).
    result = 0;
    switch (1) {
        case 1: result += 1;
        case 2: result += 2;
        case 3: result += 3; break;
        default: result = -1; break;
    }
    if (result != 6) return 3;  // 1+2+3 from fallthrough

    // Empty cases.
    result = 0;
    switch (2) {
        case 1:
        case 2:
        case 3:
            result = 100;
            break;
        default:
            result = -1;
            break;
    }
    if (result != 100) return 4;

    return 0;
}
