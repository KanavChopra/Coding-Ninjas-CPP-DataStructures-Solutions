// Change in the given string itself. So no need to return or print the changed string.

#include <cstring>

void pairStar(char input[], int start) {
    if (input[start] == '\0') {
        return;
    }
    if (input[start] == input[start + 1]) {
        int len = strlen(input);
        for (int i = len; i >= (start + 1); i--) {
            input[i + 1] = input[i];
        }
        input[start + 1] = '*';
    }
     pairStar(input + 1, start);
}
void pairStar(char input[]) {
    pairStar(input, 0);
}
