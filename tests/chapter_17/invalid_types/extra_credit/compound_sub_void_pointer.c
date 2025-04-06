// Can't perform +=/-= with void * lvalue
// NOTE: GCC/Clang permit this as a language extension
void *malloc(unsigned LONG64 size);

int main(void) {
    void *buff = malloc(100);
    buff -= 0;
    return 0;
}