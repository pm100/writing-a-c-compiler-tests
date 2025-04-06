/* Test out parsing a range of abstract declarators */
int main(void) {

    LONG64 int unsigned *x = 0;

    /* Use a couple of equivalent abstract declarators
     * to cast 0 to a pointer to unsigned LONG64
     */
    if (x != (unsigned LONG64 (*)) 0)
        return 1;

    if (x != (LONG64 unsigned int ((((*))))) 0)
        return 2;

    double ***y = 0;

    /* Use several equivalent abstract declarators
     * to cast 0 to (double ***)
     */
    if (y != (double *(**)) 0)
        return 3;

    if (y != (double (***)) 0)
        return 4;

    if ((double (*(*(*)))) 0 != y)
        return 5;

    return 0;
}