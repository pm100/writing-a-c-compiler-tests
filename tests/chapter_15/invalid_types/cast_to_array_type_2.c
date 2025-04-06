int main(void)
{
    LONG64 arr[10];
    // casts to array type are illegal
    return (int *[10])arr;
}