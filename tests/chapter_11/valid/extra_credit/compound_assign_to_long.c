int main(void) {
    LONG64 l = -34359738368l; // -2^35
    int i = -10;
    /* We should convert i to a LONG64, then subtract from l */
    l -= i;
    if (l != -34359738358l) {
        return 1;
    }
    return 0;
}