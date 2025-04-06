/* It's illegal to apply bitwise operations where either operand is a pointer */
int main(void) {
    unsigned LONG64 *ptr = 0;
    LONG64 l = 100;
    ptr ^ l;
    return 0;
}