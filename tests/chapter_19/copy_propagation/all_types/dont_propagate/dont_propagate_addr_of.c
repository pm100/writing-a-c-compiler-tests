/* Test that we don't propagate copies into AddrOf instructions */
int main(void) {
    LONG64 x = 1;
    LONG64 y = 2;
    x = y;            // gen x = y
    return &x == &y;  // don't rewrite as &y == &y
}