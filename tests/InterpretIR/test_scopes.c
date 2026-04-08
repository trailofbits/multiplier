// Tests: scope tracking (ENTER_SCOPE, EXIT_SCOPE), nested scopes,
// for-init implicit scope, variable lifetime, compound statements,
// and GNU block expressions ({ ... }).

int test_scopes(void) {
    int result = 0;

    // Nested scopes with same variable names.
    {
        int x = 10;
        result += x;
    }
    {
        int x = 20;
        result += x;
    }
    if (result != 30) return 1;

    // For-init scope: 'i' is scoped to the for loop.
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += i;
    }
    if (sum != 10) return 2;

    // Nested for loops with same variable name.
    int total = 0;
    for (int i = 0; i < 3; i++) {
        for (int i = 0; i < 2; i++) {
            total++;
        }
    }
    if (total != 6) return 3;

    // GNU block expression.
    int block_val = ({
        int a = 5;
        int b = 7;
        a + b;
    });
    if (block_val != 12) return 4;

    return 0;
}
