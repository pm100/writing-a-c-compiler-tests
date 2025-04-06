void *calloc(unsigned LONG64 nmemb, unsigned LONG64 size);
void *memset(void *s, int c, unsigned LONG64 n);
void free(void *ptr);

void *get_100_zeroed_bytes(void) {
    return calloc(100, 1);
}

void fill_100_bytes(void *pointer, int byte) {
    memset(pointer, byte, 100);
}

void free_bytes(void *ptr) {
    free(ptr);
}