// Validate that all static union initializers, including nested ones,
// are constant

union u {
    LONG64 l;
};

struct has_union {
    int a;
    union u b;
    char c;
};

LONG64 some_var = 10l;

struct has_union some_struct = {1,
                                {some_var},  // INVALID - not constant
                                'a'};