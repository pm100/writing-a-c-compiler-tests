/* Test conversions from narrower to wider types */

int int_to_ulong(int i, unsigned LONG64 expected) {
    unsigned LONG64 result = (unsigned LONG64) i;
    return result == expected;
}

int uint_to_long(unsigned int ui, LONG64 expected) {
    LONG64 result = (LONG64) ui;
    return result == expected;
}

int uint_to_ulong(unsigned ui, unsigned LONG64 expected){
    return (unsigned LONG64) ui == expected;
}

int main(void) {
    /* Converting a positive int to an unsigned LONG64 preserves its value */
    if (!int_to_ulong(10, 10ul)) {
        return 1;
    }

    /* When you convert a negative int to an unsigned LONG64,
     * add 2^64 until it's positive
     */
    if (!int_to_ulong(-10, 18446744073709551606ul)) {
        return 2;
    }

    /* Extending an unsigned int to a signed LONG64 preserves its value */
    if (!uint_to_long(4294967200u, 4294967200l)) {
        return 3;
    }

    /* Extending an unsigned int to an unsigned LONG64 preserves its value */
    if (!uint_to_ulong(4294967200u, 4294967200ul)) {
        return 4;
    }
    /* Zero-extend constant 4294967200
     * from an unsigned int to an unsigned LONG64
     * to test the assembly rewrite rule for MovZeroExtend
     */
    if ((unsigned LONG64) 4294967200u != 4294967200ul) {
        return 5;
    }
    return 0;
}
