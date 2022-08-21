int allIndexes(int input[], int size, int x, int output[]) {
    if (!size) {
        return 0;
    }
    if (size == 1) {
        if (input[0] == x) {
            output[0] = 0;
            return 1;
        } else {
            return 0;
        }
    }
    int sz = allIndexes(input + 1, size - 1, x, output);
    for (int i = 0; i < sz; ++i) {
        output[i]++;
    }
    if (input[0] == x) {
        for (int i = sz; i > 0; --i) {
            output[i] = output[i - 1];
        }
        output[0] = 0;
        sz++;
        return sz;
    } else {
        return sz;
    }
}
