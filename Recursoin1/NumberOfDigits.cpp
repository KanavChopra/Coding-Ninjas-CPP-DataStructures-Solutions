int count(int n){
    if (!(n)){
        return 0;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}