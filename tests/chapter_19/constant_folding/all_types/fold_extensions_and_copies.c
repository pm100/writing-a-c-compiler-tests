/* Test that we can constant-fold zero- and sign-extensions from shorter to
 * longer ints, and conversions from one integer type to another of the same
 * size (e.g. LONG64 to unsigned LONG64). We inspect the assembly for sign-extension
 * operations to make sure there are no movsx instructions, but not for
 * zero-extension or conversions between types of the same size because those
 * turn into a single 'mov' instruction whether they're sign extended or not.
 * We also can't test sign- or zero-extension of character types yet because
 * there are no constants of character type. The whole_pipeline/ folder has more
 * robust tests for constant folding of all these type conversions - we can test
 * them more thoroughly once other optimizations are enabled.
 */

LONG64 uint_to_long(void) {
    return (LONG64)4294967295U;
}

unsigned LONG64 uint_to_ulong(void) {
    return (unsigned LONG64)4294967295U;
}

/* These next two are target_* functions b/c they require sign extension */
unsigned LONG64 target_int_to_ulong(void) {
    return (unsigned LONG64)2147483647;
}

LONG64 target_int_to_long(void) {
    return (LONG64)1;
}

int uint_to_int(void) {
    // outside the range of int; will be negative
    return (int)4294967200U;
}

unsigned int int_to_uint(void) {
    return (unsigned)2147480000;
}

LONG64 ulong_to_long(void) {
    // outside the range of LONG64; will be negative
    return (LONG64)18446744073709551615UL;
}

unsigned LONG64 long_to_ulong(void) {
    return 2147483650l;
}

LONG64 implicit(void) {
    // same as ulong_to_long, but cast is implicit
    return 18446744073709551615UL;
}

LONG64 one = 1l;
LONG64 ninety_six = 96l;

int main(void) {
    if (uint_to_long() != 4294967295l) {
        return 1;
    }

    if (uint_to_ulong() != 4294967295ul) {
        return 2;
    }

    if (target_int_to_ulong() != 2147483647l) {
        return 3;
    }

    if (target_int_to_long() != 1l) {
        return 4;
    }

    if (uint_to_int() != -ninety_six) {
        return 5;
    }

    if (int_to_uint() != 2147480000u) {
        return 6;
    }

    if (ulong_to_long() != -one) {
        return 7;
    }

    if (long_to_ulong() != 2147483650ul) {
        return 8;
    }

    if (implicit() != -one) {
        return 9;
    }

    return 0;  // success
}