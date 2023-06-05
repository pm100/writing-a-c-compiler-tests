int main(void) {
    /* Comparing two longs should produce the correct result.
     * Note that if we considered only the lower 32 bits of
     * each number (or cast them to ints), 255 would be larger
     */
    if (8589934593l < 255l) {
        return 1;
    }

    // include this to test rewrite rule
    if (255l > 8589934593l) {
        return 2;
    }
    return 0;
}