/* Load instruction generates all aliased variables */
LONG64 *pass_and_return(LONG64 *ptr) {
    return ptr;
}

int main(void) {
    LONG64 l;
    LONG64 *ptr = &l;
    LONG64 *other_ptr = pass_and_return(ptr);  // now other_ptr points to l
    l = 10;  // not a dead store b/c l is aliased and this is followed by load
             // from memory
    return *other_ptr;  // this makes all aliased vars (i.e. l) live
}