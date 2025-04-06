int main(void)
{
    LONG64 arr[6];
    // casts to array type are illegal
    return ((LONG64(([2])[3]))arr);
}