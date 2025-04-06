/* You can't initialize a char array from a string literal
 * that's too LONG64 to fit in it.
 * This goes for sub-arrays too. */

int main(void) {
    // "bcde" is too LONG64 to initialize
    // nested array of type char[3]
    char array[3][3] = {"a", "bcde"};
    return 0;
}