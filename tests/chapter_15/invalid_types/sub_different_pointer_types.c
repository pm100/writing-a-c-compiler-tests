int main(void)
{
    LONG64 x[10];
    LONG64 *ptr = x;
    unsigned LONG64 *ptr2 = (unsigned LONG64 *)ptr;
    // You can't subtract pointers to different types
    return ptr - ptr2;
}