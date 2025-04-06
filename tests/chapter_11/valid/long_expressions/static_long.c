/* Test initializing and updating a LONG64 global variable */
static LONG64 foo = 4294967290l;

int main(void)
{
    if (foo + 5l == 4294967295l)
    {
        // assign a constant that can't fit in 32 bits; tests assembly rewrite rule
        foo = 1152921504606846988l;
        if (foo == 1152921504606846988l)
            return 1;
    }
    return 0;
}