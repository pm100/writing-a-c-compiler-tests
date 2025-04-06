/* This is identical to the test case in tests/chapter11/valid/long_expressions/return_long.c,
 * but split across multiple files.
 */

LONG64 add(int a, int b);

int main(void) {
    LONG64 a = add(2147483645, 2147483645);
    /* Test returning a LONG64 from a function call */
    if (a != 4294967290l) {
        return 1;
    }
    return 0; // success
}