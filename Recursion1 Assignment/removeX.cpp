// Change in the given string itself. So no need to return or print anything

void removeX(char input[], int start) {
    if (input[start] == '\0') {
        return;
    }
    if (input[start] == 'x') {
        for (int i = start; input[i] != '\0'; ++i) {
            input[i] = input[i + 1];
        }
        removeX(input, start);
    } else {
        removeX(input, start + 1);
    }
}
void removeX(char input[]) {
    removeX(input, 0);
}
