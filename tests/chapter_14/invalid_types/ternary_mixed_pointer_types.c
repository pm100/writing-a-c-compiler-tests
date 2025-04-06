/* It's illegal to use two distinct pointer types
 * as the second and third operands of a ternary expression
 */
int main(void) {
    LONG64 *x = 0;
    int *y = 0;
    int *result = 1 ? x : y;
    return 0;
}