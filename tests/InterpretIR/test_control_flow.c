// Tests: if/else (COND_BRANCH), while loop (LOOP_PREHEADER, LOOP_CONDITION,
// LOOP_BODY, LOOP_EXIT), for loop (FOR_INIT, LOOP_INCREMENT), do-while,
// break (BREAK), continue (CONTINUE), nested loops, early return (RET),
// and the ternary operator (SELECT).

/*
 * Expected IR (ENTRY block):
 *
 * function test_control_flow (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (result)
 *     obj_2 LOCAL_VALUE size=4 align=1 (sum)
 *     obj_3 LOCAL_VALUE size=4 align=1 (i)
 *     obj_4 LOCAL_VALUE size=4 align=1 (fact)
 *     obj_5 LOCAL_VALUE size=4 align=1 (j)
 *     obj_6 LOCAL_VALUE size=4 align=1 (count)
 *     obj_7 LOCAL_VALUE size=4 align=1 (brk)
 *     obj_8 LOCAL_VALUE size=4 align=1 (k)
 *     obj_9 LOCAL_VALUE size=4 align=1 (cont)
 *     obj_10 LOCAL_VALUE size=4 align=1 (k)
 *     obj_11 LOCAL_VALUE size=4 align=1 (nested)
 *     obj_12 LOCAL_VALUE size=4 align=1 (a)
 *     obj_13 LOCAL_VALUE size=4 align=1 (b)
 *     obj_14 LOCAL_VALUE size=4 align=1 (sel)
 *   blocks:
 *   block_1 ENTRY:
 *     >> %15 = ENTER_SCOPE
 *          %result.0 = ALLOCA/LOCAL size=4 align=1
 *          %16 = CONST/INT32 0
 *     >> %result.17 = MEMORY/STORE_LE_32 [%result.0, %16]
 *          %18 = CONST/INT32 1
 *     >> %19 = COND_BRANCH [%18]  // if (1) result = 1; else result = -1
 *     -> [block_2, block_3]
 *   ... (truncated, continues with LOOP_PREHEADER, LOOP_CONDITION, LOOP_BODY,
 *    LOOP_EXIT, LOOP_INCREMENT, BREAK, CONTINUE, SELECT blocks)
 * }
 */

int test_control_flow(void) {
    int result = 0;

    // If/else.
    if (1) result = 1;
    else result = -1;
    if (result != 1) return 1;

    // While loop: sum 1..5.
    int sum = 0;
    int i = 1;
    while (i <= 5) {
        sum += i;
        i++;
    }
    if (sum != 15) return 2;

    // For loop: factorial of 5.
    int fact = 1;
    for (int j = 1; j <= 5; j++) {
        fact *= j;
    }
    if (fact != 120) return 3;

    // Do-while: count to 3.
    int count = 0;
    do {
        count++;
    } while (count < 3);
    if (count != 3) return 4;

    // Break.
    int brk = 0;
    for (int k = 0; k < 100; k++) {
        if (k == 5) break;
        brk++;
    }
    if (brk != 5) return 5;

    // Continue.
    int cont = 0;
    for (int k = 0; k < 10; k++) {
        if (k % 2 == 0) continue;
        cont++;
    }
    if (cont != 5) return 6;

    // Nested loops.
    int nested = 0;
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            nested++;
        }
    }
    if (nested != 9) return 7;

    // Ternary (SELECT).
    int sel = (1 > 0) ? 42 : -1;
    if (sel != 42) return 8;

    return 0;
}
