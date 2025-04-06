LONG64 add(int a, int b) {
    return (LONG64) a + (LONG64) b;
}

int main(void) {
    LONG64 a = add(2147483645, 2147483645);
    /* Test returning a LONG64 from a function call */
    if (a == 4294967290l) {
        return 1;
    }
    return 0;
}