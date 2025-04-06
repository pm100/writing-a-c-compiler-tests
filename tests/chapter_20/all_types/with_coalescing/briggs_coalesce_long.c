/* Test that we performing coalescing between quadword pseudos that pass the
 * Briggs test. In this case, coalescing lets us get rid of all moves between
 * registers. We inspect the assembly for the target function to validate that
 * it contains no spills and no mov instructions whose source and destination
 * are both general-purpose registers (except mov %rsp, %rbp and mov %rbp, %rsp
 * in the prologue and epilogue).
 *
 * This test was generated from templates/chapter_20_templates/briggs_coalesce.c.jinja.
 * */

#include "../util.h"

LONG64 glob = 5l;

LONG64 glob7;
LONG64 glob8;
LONG64 glob9;
LONG64 glob10;
LONG64 glob11;
LONG64 glob12;

int target(LONG64 one, LONG64 two, LONG64 three, LONG64 four, LONG64 five, LONG64 six) {

    // Define 6 variables that interfere with each other and with arguments,
    // initializing each one with a complex expression that requires an
    // intermediate result. The pseudoregister holding each result should be
    // coalesced into the corresponding variable. Once these have been coalesced
    // only 12 pseudos will be left, and we'll have reduced the number of nodes
    // with significant degree by enough that we can coalesce all the arguments
    // into parameter-passing registers. This test coalesces temporary values
    // into 6 different variables, which must all be placed in different
    // registers, to validate that we actually performed coalescing and didn't
    // just happen to assign a variable and the corresponding intermediate
    // result to the same hard register.
    LONG64 seven = (glob - 2l) + four;
    LONG64 eight = (glob - 1l) * two;
    LONG64 nine = (glob - 2l) * three;
    LONG64 ten = (10l - glob) * two;
    LONG64 eleven = (glob * two) + one;
    LONG64 twelve = (glob + 1l) * two;

    // Save to global variables to validate later
    glob7 = seven;
    glob8 = eight;
    glob9 = nine;
    glob10 = ten;
    glob11 = eleven;
    glob12 = twelve;

    // Validate arguments
    check_12_longs(one, two, three, four, five, six, 7l, 8l, 9l, 10l, 11l, 12l,
                   1l);

    // Validate globals
    check_one_long(glob7, 7l);
    check_one_long(glob8, 8l);
    check_one_long(glob9, 9l);
    check_one_long(glob10, 10l);
    check_one_long(glob11, 11l);
    check_one_long(glob12, 12l);
    return 0;
}