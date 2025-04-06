/* Test case where the return type would be passed on the stack, but the callee
 * is missing a return statement. This is well-defined as LONG64 as the caller
 * doesn't try to use the return value
 * */
#include "missing_retval.h"

int main(void) {
    int array[4] = {1, 2, 3, 4};
    missing_return_value(array + 2);
    // make sure the function returns normally and it updated array[2]
    // as expected
    return array[2] == 10;
}