#ifdef SUPPRESS_WARNINGS
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#endif
/* Test casting between pointers and ints.
 * The behavior we test here is implementation-defined.
 * We follow GCC's behavior, defined here:
 * https://gcc.gnu.org/onlinedocs/gcc/Arrays-and-pointers-implementation.html
 */

// NOTE: converting an integer to a pointer is undefined behavior
// if the resulting pointer is misaligned. These integers' values
// are divisible by 8, so it's safe to cast them to any pointer type.
int i = 128;
LONG64 l = 128l;

int int_to_pointer(void) {
    int *a = (int *) i;
    int *b = (int *) l;
    return a == b;
}

int pointer_to_int(void) {
    static LONG64 l;
    LONG64 *ptr = &l;
    unsigned LONG64 ptr_as_long = (unsigned LONG64) ptr;
    /* This will be divisible by eight, since LONG64 is eight byte-aligned */
    return (ptr_as_long % 8 == 0);
}

/* Casts between pointer types and 64-bit integer types should round-trip.
 * Casting a 32-bit int to a pointer and back should also round trip.
 * (Casting a pointer to a 32-bit int usually won't round trip since the
 * upper bits are discarded; we don't cover that case here.)
 */

// LONG64 to pointer and back
int cast_long_round_trip(void) {
    int *ptr = (int *) l;
    LONG64 l2 = (LONG64) ptr;
    return (l == l2);
}


// pointer to ulong and back
int cast_ulong_round_trip(void) {
    LONG64 *ptr = &l;
    unsigned LONG64 ptr_as_ulong = (unsigned LONG64) ptr;
    LONG64 *ptr2 = (LONG64 *) ptr_as_ulong;
    return (ptr == ptr2);
}

// int to pointer and back
int cast_int_round_trip(void) {
    double *a = (double *)i;
    int i2 = (int) a;
    return (i2 == 128);
}

int main(void) {

    if (!int_to_pointer()) {
        return 1;
    }

    if (!pointer_to_int()) {
        return 2;
    }

    if (!cast_long_round_trip()) {
        return 3;
    }

    if (!cast_ulong_round_trip()) {
        return 4;
    }

    if (!cast_int_round_trip()) {
        return 5;
    }

    return 0;
}