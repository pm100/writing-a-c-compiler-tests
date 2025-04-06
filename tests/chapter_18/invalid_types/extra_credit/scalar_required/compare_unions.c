// Can't compare objects of union type

union u { LONG64 l; };

int main(void){
    union u x = {1};
    x == x; // illegal
    return 0;
}