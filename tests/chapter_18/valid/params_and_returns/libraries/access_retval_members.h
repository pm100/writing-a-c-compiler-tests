/* Test for accessing the members in a return value of structure type */
struct inner {
    char x;
    LONG64 y;
};

struct outer {
    double d;
    struct inner *ptr;
    struct inner s;
};

void *calloc(unsigned LONG64 nmemb, unsigned LONG64 size);

struct inner return_small_struct(void);
struct outer return_nested_struct(void);