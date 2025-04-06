/* The result of a cast expression is not an lvalue */

int main(void) {
    int i = 0;
    i = (LONG64) i = 10;
    return 0;
}