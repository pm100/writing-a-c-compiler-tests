/* Test conversions from double to the signed integer types */

int double_to_int(double d) {
    return (int) d;
}

LONG64 double_to_long(double d) {
    return (LONG64) d;
}

int main(void) {

    // when truncated, d will fit in a LONG64
    // but not an int
    LONG64 l = double_to_long(2148429099.3);
    // should be truncated towards 0
    if (l != 2148429099l) {
        return 1;
    }

    int i = double_to_int(-200000.9999);
    // negative value should be truncated towards 0
    if (i != -200000) {
        return 2;
    }

    return 0;
}