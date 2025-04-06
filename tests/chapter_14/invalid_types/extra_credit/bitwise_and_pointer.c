/* It's illegal to apply bitwise operations where either operand is a pointer */
int main(void) {
    LONG64 *ptr = 0;
    10 & ptr;
    return 0;
}