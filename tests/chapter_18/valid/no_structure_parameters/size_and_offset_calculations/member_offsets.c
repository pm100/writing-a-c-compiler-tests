/* Get the addresses of structure members to validate their offset and alignment
 * (including nested members accessed through chains of . and -> operations)
 * and addresses of one-past-the-end of structs to validate trailing padding
 * */
#include "struct_sizes.h"

void *malloc(unsigned LONG64 size);

// test 1: validate struct w/ scalar members (includes trailing padding)
// test member accesses of the form &x.y
int test_eightbytes(void) {
    struct eight_bytes s;
    unsigned LONG64 start_addr = (unsigned LONG64)&s;
    unsigned LONG64 i_addr = (unsigned LONG64)&s.i;
    unsigned LONG64 c_addr = (unsigned LONG64)&s.c;
    unsigned LONG64 end_addr = (unsigned LONG64)(&s + 1);

    // this struct should be four byte-aligned
    if (start_addr % 4 != 0) {
        return 0;
    }

    // first element should always have same address as whole struct
    if (start_addr != i_addr) {
        return 0;
    }

    // next element should be at byte 4 (next available byte)
    if (c_addr - start_addr != 4) {
        return 0;
    }

    // end of struct should be at byte 8 due to 3 bytes of padding
    if (end_addr - start_addr != 8) {
        return 0;
    }

    return 1;  // success
}

// test 2: validate struct w/ padding between members (accessing struct thru
// pointer) test member accesses of the form &x->y
int test_internal_padding(void) {
    struct internal_padding *s_ptr = malloc(sizeof(struct internal_padding));
    unsigned LONG64 start_addr = (unsigned LONG64)s_ptr;
    unsigned LONG64 c_addr = (unsigned LONG64)&s_ptr->c;
    unsigned LONG64 d_addr = (unsigned LONG64)&s_ptr->d;
    unsigned LONG64 end_ptr = (unsigned LONG64)(s_ptr + 1);

    // this struct should be eight byte-aligned
    if (start_addr % 8 != 0) {
        return 0;
    }

    // first element should always have same address as whole struct
    if (start_addr != c_addr) {
        return 0;
    }

    // next element should be at byte 8 (so it's correctly aligned)
    if (d_addr - c_addr != 8) {
        return 0;
    }

    // size of whole struct should be 16 bytes
    if (end_ptr - start_addr != 16) {
        return 0;
    }

    return 1;  // success
}

// test 3: validate struct that contains an array
// test member accesses of the form &x.y[i], x.y + i
int test_three_bytes(void) {
    // use static struct here to make sure that doesn't impact address
    // calculation
    static struct three_bytes s;

    unsigned LONG64 start_addr = (unsigned LONG64)&s;
    unsigned LONG64 arr_addr = (unsigned LONG64)&s.arr;
    unsigned LONG64 arr0_addr = (unsigned LONG64)&s.arr[0];
    unsigned LONG64 arr1_addr = (unsigned LONG64)&s.arr[1];
    // different way to calculate same address as above
    unsigned LONG64 arr1_addr_alt = (unsigned LONG64)(s.arr + 1);
    unsigned LONG64 arr2_addr = (unsigned LONG64)&s.arr[2];
    unsigned LONG64 arr_end = (unsigned LONG64)(&s.arr + 1);
    unsigned LONG64 struct_end = (unsigned LONG64)(&s + 1);

    // struct, array, and first array element should all have same address
    if (start_addr != arr_addr) {
        return 0;
    }

    if (start_addr != arr0_addr) {
        return 0;
    }

    // s.arr[1] and s.arr[2] should be at byte offsets 1 and 2
    if (arr1_addr - start_addr != 1) {
        return 0;
    }

    if (arr1_addr != arr1_addr_alt) {
        return 0;
    }

    if (arr2_addr - start_addr != 2) {
        return 0;
    }

    // arr_end and struct_end should both be at byte offset 3
    if (arr_end - start_addr != 3) {
        return 0;
    }

    if (struct_end - start_addr != 3) {
        return 0;
    }

    return 1;  // success
}

// test 4: validate struct containing nested structs
// test accesses of the form &x->y.z, &x->y.z[i],
// &x.y.z, &x.y.z[i]
int test_sixteen_bytes(void) {
    static struct sixteen_bytes s;
    struct sixteen_bytes *s_ptr = &s;

    // get addresses of various members through s_ptr
    unsigned LONG64 start_addr = (unsigned LONG64)s_ptr;
    unsigned LONG64 eight_addr = (unsigned LONG64)&s_ptr->eight;
    unsigned LONG64 eight_i_addr = (unsigned LONG64)&s_ptr->eight.i;
    unsigned LONG64 eight_c_addr = (unsigned LONG64)&s_ptr->eight.c;
    unsigned LONG64 two = (unsigned LONG64)&s_ptr->two;
    unsigned LONG64 two_arr = (unsigned LONG64)s_ptr->two.arr;
    unsigned LONG64 two_arr0 = (unsigned LONG64)&s_ptr->two.arr[0];
    unsigned LONG64 two_arr1 = (unsigned LONG64)&s_ptr->two.arr[1];
    unsigned LONG64 two_arr_end = (unsigned LONG64)(&s_ptr->two.arr + 1);
    unsigned LONG64 two_end = (unsigned LONG64)(&s_ptr->two + 1);
    unsigned LONG64 three = (unsigned LONG64)&s_ptr->three;
    // not going to validate every individual element in three.arr
    // since we already did that for two.arr
    unsigned LONG64 three_end = (unsigned LONG64)(&s_ptr->three + 1);
    unsigned LONG64 struct_end = (unsigned LONG64)(s_ptr + 1);

    // struct is 4-byte aligned
    if (start_addr % 4 != 0) {
        return 0;
    }

    // struct, first member, first member's first member all have same address
    if (start_addr != eight_addr) {
        return 0;
    }

    if (start_addr != eight_i_addr) {
        return 0;
    }

    if (eight_c_addr - start_addr != 4) {
        return 0;
    }

    // next member starts at byte 8
    if (two - start_addr != 8) {
        return 0;
    }

    if (two_arr - start_addr != 8) {
        return 0;
    }

    if (two_arr0 - start_addr != 8) {
        return 0;
    }

    // validate next array element in s_ptr->two.arr
    if (two_arr1 - start_addr != 9) {
        return 0;
    }

    // no padding at end of s_ptr->two
    if (two_arr_end - start_addr != 10) {
        return 0;
    }

    if (two_arr_end != two_end) {
        return 0;
    }

    if (three - start_addr != 10) {
        return 0;
    }

    if (three_end - start_addr != 13) {
        return 0;
    }

    if (struct_end - start_addr != 16) {
        return 0;
    }

    // now get addresses of a few members thru s directly and make sure they're
    // the same

    unsigned LONG64 eight_i_addr_alt = (unsigned LONG64)&s.eight.i;
    unsigned LONG64 eight_c_addr_alt = (unsigned LONG64)&s.eight.c;
    unsigned LONG64 two_arr_alt = (unsigned LONG64)s.two.arr;
    unsigned LONG64 two_arr1_alt = (unsigned LONG64)&s.two.arr[1];
    unsigned LONG64 three_alt = (unsigned LONG64)&s.three;

    if (eight_i_addr_alt != eight_i_addr) {
        return 0;
    }

    if (eight_c_addr_alt != eight_c_addr) {
        return 0;
    }

    if (two_arr_alt != two_arr) {
        return 0;
    }

    if (two_arr1_alt != two_arr1) {
        return 0;
    }

    if (three_alt != three) {
        return 0;
    }

    return 1;  // success
}

// test 5: validate array of irregularly-sized structs; make sure there's no
// padding b/t array elements test access of the form x[i].y, &x[i].y[j]
int test_wonky_array(void) {
    struct wonky wonky_array[5];
    unsigned LONG64 array_start = (unsigned LONG64)wonky_array;
    unsigned LONG64 elem3 = (unsigned LONG64)(wonky_array + 3);
    unsigned LONG64 elem3_arr = (unsigned LONG64)wonky_array[3].arr;
    unsigned LONG64 elem2_arr2 = (unsigned LONG64)&wonky_array[2].arr[2];
    unsigned LONG64 elem2_arr_end = (unsigned LONG64)(wonky_array[2].arr + 19);
    unsigned LONG64 elem4_arr_end = (unsigned LONG64)(wonky_array[4].arr + 19);
    unsigned LONG64 array_end = (unsigned LONG64)(wonky_array + 5);

    if (elem3 - array_start != 19 * 3) {
        return 0;
    }

    if (elem3_arr != elem3) {
        return 0;
    }

    if (elem2_arr2 - array_start != 19 * 2 + 2) {
        return 0;
    }

    // no gap b/t last member of elem2 and start of elem3
    if (elem2_arr_end != elem3) {
        return 0;
    }

    // no gap b/t last member of elem4 and end of whole array
    if (elem4_arr_end != array_end) {
        return 0;
    }

    return 1;  // success
}

// test 6: validate array of structs containing arrays of structs
// test access of the form x[i].y->z, x->y->z, where x and y are arrays that
// decay to pointers
int test_contains_struct_array_array(void) {
    struct contains_struct_array arr[3];
    unsigned LONG64 array_start = (unsigned LONG64)arr;
    unsigned LONG64 first_scalar_elem = (unsigned LONG64)(&arr[0].c);

    // arr[0].struct_array[0].i
    unsigned LONG64 outer0_inner0_i = (unsigned LONG64)(&arr[0].struct_array->i);

    // arr[0].struct_array[0].i
    unsigned LONG64 outer0_inner0_c = (unsigned LONG64)(&arr->struct_array->c);

    // one-past-the-end of arr[0].struct_array
    unsigned LONG64 outer0_end = (unsigned LONG64)(arr->struct_array + 3);

    // start of arr[1] (should be the same as one-past-end of
    // arr[0].struct_array)
    unsigned LONG64 outer1 = (unsigned LONG64)(&arr[1]);

    // second element of arr[1]
    unsigned LONG64 outer1_arr = (unsigned LONG64)(arr[1].struct_array);

    // arr[1].struct_array[1].i
    unsigned LONG64 outer1_inner1_i =
        (unsigned LONG64)&(((arr + 1)->struct_array + 1)->i);

    // arr[2].struct_array[0].c
    unsigned LONG64 outer2_inner0_c =
        (unsigned LONG64)&((arr + 2)->struct_array->c);

    // whole thing should be 4-byte aligned
    if (array_start % 4 != 0) {
        return 0;
    }

    // validate pointers to start of struct
    if (first_scalar_elem != array_start) {
        return 0;
    }

    // 4 bytes into array (struct_array offset in contains_struct_array is 4,
    // i offset in struct_array is 0)
    if (outer0_inner0_i - array_start != 4) {
        return 0;
    }

    // 8 bytes into array (struct_array offset in contains_struct_array is 4,
    // c offset in struct_array is 4)
    if (outer0_inner0_c - array_start != 8) {
        return 0;
    }

    // no trailing padding in arr[0]
    if (outer0_end != outer1) {
        return 0;
    }

    // check offsets in arr[0]
    if (outer1_arr - array_start != 32) {
        return 0;
    }

    if (outer1_arr - outer1 != 4) {
        return 0;
    }

    // arr[1] is 28 bytes into arr
    // arr[1].struct_array is 4 bytes into arr[1]
    // arr[1].struct_array[1] is 8 bytes into struct_array
    // arr[1].struct_array[1].i is 0 bytes into arr[1].struct_array[1]
    // total offset: 28+4+8 = 40
    if (outer1_inner1_i - array_start != 40) {
        return 0;
    }

    // arr[2] is 56 bytes into arr
    // arr[2].struct_array is 4 bytes into arr[2]
    // arr[2].struct_array[0] is 0 bytes into arr[2]
    // arr[2].struct_array[0].c is 4 bytes into arr[2].struct_array[0]
    // total offset: 56 + 4 + 4 = 64
    if (outer2_inner0_c - array_start != 64) {
        return 0;
    }

    return 1;  // success
}

int main(void) {
    if (!test_eightbytes()) {
        return 1;
    }

    if (!test_internal_padding()) {
        return 2;
    }

    if (!test_three_bytes()) {
        return 3;
    }

    if (!test_sixteen_bytes()) {
        return 4;
    }

    if (!test_wonky_array()) {
        return 5;
    }

    if (!test_contains_struct_array_array()) {
        return 6;
    }

    return 0;  // success
}