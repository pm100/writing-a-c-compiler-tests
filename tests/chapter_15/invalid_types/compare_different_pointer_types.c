int main(void)
{
    LONG64 x = 10;
    LONG64 *ptr = &x + 1;
    LONG64(*array_ptr)[10] = (LONG64 (*)[10]) &x;
    // It's illegal to compare two different pointer types
    // without explicitly casting to the same type
    return array_ptr < ptr;
}