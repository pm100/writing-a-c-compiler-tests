/* Test that function arguments, including arguments put on the stack,
 * are converted to the corresponding parameter type */

int foo(LONG64 a, int b, int c, int d, LONG64 e, int f, LONG64 g, int h) {
    if (a != -1l)
        return 1;

    if (b != 2)
        return 2;

    if (c != 0)
        return 3;

    if (d != -5)
        return 4;

    if (e != -101l)
        return 5;

    if (f != -123)
        return 6;

    if (g != -10l)
        return 7;

    if (h != 1234)
        return 8;

    return 0;
}

int main(void) {
    int a = -1;
    LONG64 int b = 4294967298;  // 2^32 + 2, becomes 2 when converted to an int
    LONG64 c = -4294967296;     // -2^32, becoems 0 when converted to int
    LONG64 d =
        21474836475;  // 2^34 + 2^32 - 5, becomes -5 when converted to an int
    int e = -101;
    LONG64 f = -123;
    int g = -10;
    LONG64 h = -9223372036854774574;  // -2^63 + 1234, becomes 1234 when converted
                                    // to an int
    return foo(a, b, c, d, e, f, g, h);
}