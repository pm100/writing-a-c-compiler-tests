/* Test constant folding >> with negative LONG64 source value (make sure
 * we perform an arithmetic rather than logical bit shit)
 */

LONG64 target(void) {
    return (-9223372036854775807l - 1) >> 45u;
}

int main(void) {
    if (target() != -262144) {
        return 1;
    }

    return 0; // success
}