int sumOfDigits(int n) {
    if(n == 0) {
        return 0;
    }
    int remainder = n % 10;
    return remainder + sumOfDigits(n / 10);
}


