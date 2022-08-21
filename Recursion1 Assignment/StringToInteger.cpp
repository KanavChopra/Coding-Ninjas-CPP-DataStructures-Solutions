#include <math.h>

// for ex we want to convert "132" to integer
// so we will call recursion to convert 13 to integer and add 2 to it.
int length(char input[]) {
    int c = 0;
    for(int i = 0; input[i] != '\0'; ++i)
        c++;
    return c;
}
int help(char input[], int start) {
    if(start < 0)
        return 0;
    int a = input[start] - 48;
    return a + help(input, start - 1) * 10;
    
}
int stringToNumber(char input[]) {
    return help(input, length(input) - 1);

}