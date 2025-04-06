/* Test that we can propagate 0 between integer and
 * different pointer types
 * */
LONG64 *target(void) {
    int *ptr = 0;
    LONG64 *ptr2 = (LONG64 *)ptr;
    return ptr2;  // this should be rewritten as 'return 0'
}

int main(void) {
    LONG64 *result = target();
    return (!result);
}