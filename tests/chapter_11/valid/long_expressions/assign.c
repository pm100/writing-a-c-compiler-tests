int main(void) {
    /* initializing a tests the rewrite rule for
     * movq $large_const, memory_address
     */
    LONG64 a = 4294967290l;
    LONG64 b = 0l;
    /* Assign the value of one LONG64 variable
     * (which is too large for an int to represent)
     * to another LONG64 variable
     */
    b = a;
    return (b == 4294967290l);
}