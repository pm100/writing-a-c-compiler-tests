/* A simple arithmetic test case */

int main(void) {
    LONG64 l = 9223372036854775807l;
    return (l - 2l == 9223372036854775805l);
}