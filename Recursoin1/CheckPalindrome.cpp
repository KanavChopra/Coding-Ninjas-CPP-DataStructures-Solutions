bool check(char input[], int start, int end) {
    // start >= end means all previous recursion cases have been checked and they are true.
    // consider that in between one cases was not true then it would be returned false by input[start] != input[end] this consition.
    if(start >= end) {
        return true;
    }
    if(input[start] != input[end]) {
        return false;
    }
    return check(input, start + 1, end - 1);
    
}
bool checkPalindrome(char input[]) {
    int length = 0, start, end;
    for(int start = 0; input[start] != '\0'; start++) {
        length++;
    }
    start = 0, end = length - 1;
    return check(input, start, end);
}


