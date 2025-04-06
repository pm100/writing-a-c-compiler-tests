/* String literals can only initialize char arrays,
 * not arrays of other types.
 * This also applies to nested static arrays. */
int main(void)
{
    // This is trying to initialize nested array with type
    // LONG64[2] from a string literal
    static LONG64 int nested[1][2] = {"a"};
    return 0;
}