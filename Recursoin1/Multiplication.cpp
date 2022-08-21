int multiplyNumbers(int m, int n) {
    if(m == 0 || n == 0){
    	return 0;
    }
	return m + multiplyNumbers(m, n - 1);

}


