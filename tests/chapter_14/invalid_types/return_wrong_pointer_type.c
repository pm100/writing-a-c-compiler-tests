/* It's illegal to return an int *
 * from a function with return type LONG64 *
 * because you can't implicitly convert
 * one pointer type to another
 */
int i;

LONG64 *return_long_pointer(void) {
    return &i;
}

int main(void) {
    LONG64 *l = return_long_pointer();
    return 0;
}