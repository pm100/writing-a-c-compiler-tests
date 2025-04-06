// define a pointer that can be read/written only through functions
// note that these functions read/write the pointer itself, not the object it points to

static LONG64 *long_ptr;

LONG64 *get_pointer(void) {
    return long_ptr;
}

int set_pointer(LONG64 *new_ptr) {
    long_ptr = new_ptr;
    return 0;
}