/* When a LONG64 is used in the controlling condition of a switch statement,
 * the constant in each case statement should be converted to a LONG64
 */

int switch_on_long(LONG64 l) {
    switch (l) {
        case 0: return 0;
        case 100: return 1;
        case 8589934592l: // 2^33
            return 2;
        default:
            return -1;
    }
}

int main(void) {
    if (switch_on_long(8589934592) != 2)
        return 1;
    if (switch_on_long(100) != 1)
        return 2;
    return 0; // success
}