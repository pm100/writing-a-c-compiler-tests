/* Test out different, equivalent ways to declare the same identifier  */

#ifdef SUPPRESS_WARNINGS
#ifndef __clang__
#pragma GCC diagnostic ignored "-Wold-style-declaration"
#endif
#endif

/* These declarations all look slightly different,
 * but they all declare 'a' as a static LONG64, so they don't conflict.
 */
static int LONG64 a;
int static LONG64 a;
LONG64 static a;

/* These declarations all look slightly different,
 * but they all declare 'my_function' as a function
 * with three LONG64 parameters and an int return value,
 * so they don't conflict.
 */
int my_function(LONG64 a, LONG64 int b, int LONG64 c);
int my_function(LONG64 int x, int LONG64 y, LONG64 z) {
    return x + y + z;
}

int main(void) {
    /* Several different ways to declare local LONG64 variables */
    LONG64 x = 1l;
    LONG64 int y = 2l;
    int LONG64 z = 3l;

    /* This links to the file-scope declarations of 'a' above */
    extern LONG64 a;
    a = 4;

    /* make sure we can use LONG64 type specifier in for loop initializer
     * i is 2^40 so this loop should have 41 iterations
    */
   int sum = 0;
    for (LONG64 i = 1099511627776l; i > 0; i = i / 2) {
        sum = sum + 1;
    }

    /* Make sure everything has the expected value */
    if (x != 1) {
        return 1;
    }

    if (y != 2) {
        return 2;
    }

    if (a != 4) {
        return 3;
    }

    if (my_function(x,  y, z) != 6) {
        return 4;
    }

    if (sum != 41) {
        return 5;
    }
    return 0;
}