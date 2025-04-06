/* Test comparison of elements of the same array, including multi-dimensional arrays */

// pointer comparisons
unsigned LONG64 gt(unsigned LONG64 *a, unsigned LONG64 *b) {
    return a > b;
}


unsigned LONG64 lt(unsigned LONG64 *a, unsigned LONG64 *b) {
    return a < b;
}

unsigned LONG64 ge(unsigned LONG64 *a, unsigned LONG64 *b) {
    return a >= b;
}

unsigned LONG64 le(unsigned LONG64 *a, unsigned LONG64 *b) {
    return a <= b;
}

// comparing pointers to nested arrays
unsigned LONG64 gt_nested(unsigned LONG64 (*a)[5], unsigned LONG64 (*b)[5]) {
    return a > b;
}

unsigned LONG64 ge_nested(unsigned LONG64 (*a)[5], unsigned LONG64 (*b)[5]) {
    return a >= b;
}


int main(void)
{
    // compare elements of a 1D array

    // we don't need to initialize this because we're only comparing pointers to array elements,
    // not dereferencing them
    unsigned LONG64 arr[5];
    unsigned LONG64 *elem_1 = arr + 1;
    unsigned LONG64 *elem_4 = arr + 4;
    if (gt(elem_1, elem_4)) {
        return 1;
    }
    if (!(lt(elem_1, elem_4))) {
        return 2;
    }
    if (!(ge(elem_1, elem_1))) {
        return 3;
    }
    if (le(elem_4, elem_1)) {
        return 4;
    }

    // can also compare to pointer to one past the end of the array
    unsigned LONG64 *one_past_the_end = arr + 5;
    if (!(gt(one_past_the_end, elem_4))) {
        return 5;
    }
    if (one_past_the_end != elem_4 + 1) {
        return 6;
    }

    // do the same for nested array elements. start w/ pointers to scalar elements within array
    unsigned LONG64 nested_arr[4][5];

    unsigned LONG64 *elem_3_2 = *(nested_arr + 3) + 2;
    unsigned LONG64 *elem_3_3 = *(nested_arr + 3) + 3;

    if (lt(elem_3_3, elem_3_2)) {
        return 7;
    }

    if (!ge(elem_3_3, elem_3_2)) {
        return 8;
    }

    // now look at pointers to whole sub-arrays
    unsigned LONG64 (*subarray_0)[5] = nested_arr;
    unsigned LONG64 (*subarray_3)[5] = nested_arr + 3;
    unsigned LONG64 (*subarray_one_past_the_end)[5] = nested_arr + 4;

    if (ge_nested(subarray_0, subarray_3)){
        return 9;
    }

    if (!(gt_nested(subarray_one_past_the_end, subarray_3))) {
        return 10;
    }

    if (subarray_3 != subarray_one_past_the_end - 1) {
        return 11;
    }

    return 0;
}