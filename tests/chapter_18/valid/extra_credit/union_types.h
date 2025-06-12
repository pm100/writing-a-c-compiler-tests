void *calloc(unsigned LONG64 nmemb, unsigned LONG64 size);
void *malloc(unsigned LONG64 size);

union simple {
    int i;
    LONG64 l;
    char c;
    unsigned char uc_arr[3];
};

union has_union {
    double d;
    union simple u;
    union simple *u_ptr;
};

struct simple_struct {
    LONG64 l;
    double d;
    unsigned int u;
};

union has_struct {
    LONG64 l;
    struct simple_struct s;
};

struct struct_with_union {
    union simple u;
    unsigned LONG64 ul;
};

union complex_union {
    double d_arr[2];
    struct struct_with_union s;
    union has_union *u_ptr;
};