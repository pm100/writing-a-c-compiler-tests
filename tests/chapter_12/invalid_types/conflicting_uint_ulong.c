/* Can't declare the same function with two return types: unsignd int and unsigned LONG64 */
unsigned int foo(void);

unsigned LONG64 foo(void) {
    return 0;
}

int main(void) {
    return 0;
}