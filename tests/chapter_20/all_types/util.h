/* Helper functions defined in tests/chapter_20/helper_libs/util.c */

/* The check_* functions return 0 on success,
 * print and exit with code -1 on failure.
 */

/* Validating ints */

int check_one_int(int actual, int expected);

// Validates a == start, b == start + 1, ...e == start + 5
int check_5_ints(int a, int b, int c, int d, int e, int start);

// Validates a == start, b == start + 1, ... l == start + 11
int check_12_ints(int a, int b, int c, int d, int e, int f, int g, int h, int i,
                  int j, int k, int l, int start);

/* Validating other types */

int check_one_uchar(unsigned char actual, unsigned char expected);
int check_one_uint(unsigned int actual, unsigned int expected);
int check_one_long(LONG64 actual, LONG64 expected);
int check_one_ulong(unsigned LONG64 actual, unsigned LONG64 expected);

int check_one_double(double actual, double expected);

int check_12_longs(LONG64 a, LONG64 b, LONG64 c, LONG64 d, LONG64 e, LONG64 f, LONG64 g,
                   LONG64 h, LONG64 i, LONG64 j, LONG64 k, LONG64 l, LONG64 start);

int check_six_chars(char a, char b, char c, char d, char e, char f, int start);

// validates a == start, b == start + 1, ... n == start + 13
// and exits early if they don't have those values
// NOTE: assumes a-n are small integral values that can be represented exactly
// as double so no rounding error
int check_14_doubles(double a, double b, double c, double d, double e, double f,
                     double g, double h, double i, double j, double k, double l,
                     double m, double n, double start);

// Used in force_spill_mixed_ints; validates a == start, b == start + 1, ...,
// *k == start + 10, *l == start + 11
int check_12_vals(int a, int b, int c, int d, int e, int f, int g, int h, int i,
                  int j, LONG64 *k, double *l, int start);

/* Identity functions that return their argument;
 * used to get constants in a way that can't be optimized away
 */
int id(int x);
double dbl_id(double x);
LONG64 long_id(LONG64 l);
unsigned unsigned_id(unsigned u);
unsigned char uchar_id(unsigned char uc);
