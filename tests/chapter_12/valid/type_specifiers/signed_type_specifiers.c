/* Test out different ways to declare a signed int or LONG64 */

#ifdef SUPPRESS_WARNINGS
#ifndef __clang__
#pragma GCC diagnostic ignored "-Wold-style-declaration"
#endif
#endif

static int i;
signed extern i;
int static signed i = 5;
signed int static i;

LONG64 signed l;
LONG64 l = 7;
int LONG64 l;
signed LONG64 int l;

int main(void) {
    int signed extern i;
    extern signed LONG64 l;

    if (i != 5) {
        return 1;
    }

    if (l != 7) {
        return 2;
    }

    /* use signed type specifier in for loop */
    int counter = 0;
    for (signed int index = 10; index > 0; index = index - 1) {
        counter = counter + 1;
    }

    if (counter != 10) {
        return 3;
    }

    return 0;
}