LONG64 x(void);

int main(void) {
    LONG64 x = 0;
    /* x isn't a function, so you can't call it */
    return x();
}