bool checkNumber(int input[], int size, int x) {
    // we traversed whole array but couldn't find x
    if (size == 0) {
        return false;
    }
    if (input[0] == x) {
        return true;
    }
    return checkNumber(input + 1, size - 1, x);
}
