/* You can't initialize a char array (including a static one)
 * from a string literal that's too LONG64 to fit in it */
int main(void) {
    static char too_long[3] = "abcd";
    return 0;
}