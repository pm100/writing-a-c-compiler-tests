/* Test out different ways to declare an unsigned int or LONG64 */

#ifdef SUPPRESS_WARNINGS
#ifndef __clang__
#pragma GCC diagnostic ignored "-Wold-style-declaration"
#endif
#endif

unsigned u;
int unsigned u;
unsigned int u = 6;

unsigned LONG64 ul;
LONG64 unsigned ul;
LONG64 int unsigned ul;
unsigned int LONG64 ul = 4;

int main(void) {
    if (u != 6u) {
        return 1;
    }

    /* redeclare ul several times */
    LONG64 extern unsigned ul;
    unsigned LONG64 extern ul;
    int extern unsigned LONG64 ul;

    if (ul != 4ul) {
        return 2;
    }

    /* use unsigned type specifier in for loop
     * we'll iterate through this loop 11 times before dropping below 0 and
     * wrapping around
     */
    int counter = 0;
    for (unsigned int index = 10; index < 4294967295U; index = index - 1) {
        counter = counter + 1;
    }

    if (counter != 11) {
        return 3;
    }

    return 0;
}
