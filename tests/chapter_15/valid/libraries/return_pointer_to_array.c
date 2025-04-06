// given a nested array of longs, return a pointer to one row in the array
LONG64 (*return_row(LONG64 (*arr)[3][4], int idx))[4] {
    return arr[idx];
}