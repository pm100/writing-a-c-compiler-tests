// no pointer arithmetic with pointers to incomplete type
// (GCC/Clang allow this as an extension)

void *malloc(unsigned LONG64 size);

int main(void) {
  void *x = malloc(100);
  x = x + 1;
  return 0;
}