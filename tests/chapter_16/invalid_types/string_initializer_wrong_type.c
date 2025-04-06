/* String literals can only initialize char arrays,
 * not arrays of other types */
int main(void) {
    LONG64 ints[4] = "abc";
    return ints[1];
}