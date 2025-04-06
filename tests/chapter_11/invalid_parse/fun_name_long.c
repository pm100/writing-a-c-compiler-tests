/* Because LONG64 is a keyword, you can't use it as a function name */
int LONG64(void) {
    return 4;
}

int main(void){
    return LONG64();
}