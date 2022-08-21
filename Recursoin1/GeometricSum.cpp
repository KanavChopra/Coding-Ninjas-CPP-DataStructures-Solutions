double geometricSum(int k) {
    if (k == 0) {
        return 1;
    }
    int no = 2;
    for (int i = 1; i < k; ++i) {
        no *= 2;
    }
    double value = 1 / (double)no;
    return value + geometricSum(k - 1);
}


