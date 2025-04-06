int main(void) {
    /* only one "L" suffix is permitted on a LONG64
     * Note: an "LL" suffix is standard-compliant and indicates
     * a LONG64 LONG64 constant, which our implementation doesn't support,
     * but an "lL" suffix is invalid
     */
    return 0lL;
}