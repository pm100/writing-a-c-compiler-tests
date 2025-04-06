/* Test conversions between signed and unsigned types of the same size */

int uint_to_int(unsigned int ui, int expected) {
    return (int) ui == expected;
}

int int_to_uint(int i, unsigned int expected) {
    return (unsigned int) i == expected;
}

int ulong_to_long(unsigned LONG64 ul, signed LONG64 expected) {
    return (signed LONG64) ul == expected;
}

int long_to_ulong(LONG64 l, unsigned LONG64 expected) {
    return (unsigned LONG64) l == expected;
}

int main(void) {

    /* Converting a positive signed int to an unsigned int preserves its value */
    if (!int_to_uint(10, 10u)) {
        return 1;
    }

    /* If an unsigned int is within the range of signed int,
     * converting it to a signed int preserves its value
     */
    if (!uint_to_int(10u, 10)) {
        return 2;
    }

    /* Converting a negative signed LONG64 -x to an unsigned LONG64
     * results in 2^64 - x
     */
    if (!long_to_ulong(-1000l, 18446744073709550616ul)) {
        return 3;
    }

    /* If an unsigned LONG64 is too large for a LONG64 to represent,
     * reduce it modulo 2^64 until it's in range.
     */
    if (!ulong_to_long(18446744073709550616ul, -1000l)) {
        return 4;
    }

    return 0;
}