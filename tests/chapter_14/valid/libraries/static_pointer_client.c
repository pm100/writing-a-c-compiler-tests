LONG64 *get_pointer(void);
int set_pointer(LONG64 *new_ptr);

static LONG64 private_long = 100l;

int main(void) {
    LONG64 *initial_ptr = get_pointer();
    if (initial_ptr) { // should be null for now
        return 1;
    }

    set_pointer(&private_long);

    LONG64 *new_ptr = get_pointer();
    if (initial_ptr == new_ptr) {
        return 2;
    }

    if (*new_ptr != 100l) {
        return 3;
    }

    if (new_ptr != &private_long) {
        return 4;
    }

    // set it back to null
    set_pointer(0);

    if (get_pointer()) {
        return 5;
    }

    // new_ptr still pointers to private_long
    if (new_ptr != &private_long) {
        return 6;
    }

    return 0;
}