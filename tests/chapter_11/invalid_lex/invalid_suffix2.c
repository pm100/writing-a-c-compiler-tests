int main(void) {
    /* only one "L" suffix is permitted on a LONG64
     * Note: an "LL" suffix is standard-compliant and indicates
     * a LONG64 LONG64 constant, but isn't supported by our implementation.
     * Instead, we use an LLL suffix, which is always invalid.
     */
    return 0LLL;
}