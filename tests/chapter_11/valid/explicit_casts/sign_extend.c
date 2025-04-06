LONG64 sign_extend(int i, LONG64 expected) {
    LONG64 extended = (LONG64) i;
    return (extended == expected);
}


int main(void) {
    /* Converting a positive or negative int to a LONG64 preserves its value */
    if (!sign_extend(10, 10l)) {
        return 1;
    }

    if (!sign_extend(-10, -10l)) {
        return 2;
    }

    /* sign-extend a constant to make sure we've implemented rewrite rule for movsx correctly */
    LONG64 l = (LONG64) 100;
    if (l != 100l) {
        return 3;
    }
    return 0;
}