int countZeros(int n) {
    if(n == 0) {
        return 1;
    } else if (n < 10) {
        return 0;
    }
    int remainder = n % 10;
    if(remainder == 0) {
        return 1 + countZeros(n / 10);
    } else {
        return countZeros(n / 10);
    }
}


