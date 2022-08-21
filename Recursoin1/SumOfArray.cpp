int sum(int arr[], int n) {
    if(n == 0) {
        return 0;
    }
    int smallAns = sum(arr + 1, n - 1);
    return smallAns + arr[0];
}
