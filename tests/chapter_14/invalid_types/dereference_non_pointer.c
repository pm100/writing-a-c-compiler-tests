/* It's illegal to dereference an expression with a non-pointer type */
int main(void) {
    unsigned LONG64 l = 100ul;
    return *l;
}