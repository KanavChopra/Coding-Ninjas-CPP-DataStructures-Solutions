#include<bits/stdc++.h>

void replacePiHelper(char input[], int start) {
    if(input[start] == '\0' || input[start + 1] == '\0') return;
    replacePiHelper(input, start + 1);
    /*	
    	1. Consider the ex pipix. Now assuming that recursion gives us the correct answer our string will look like pi3.14x.
    	2. Now all we have to do is to replace the first part of it. Now we are using the strlen function as eaxh time it 
            is calculating the length of string. For ex in the case of pipi after recursion length will be 4 (pi|3.14) and for 
            pipix after recursion length will be 5 (pi|3.14x) so if we compute the legnth initally it will use the constant length 
            and not the required length.
    */
    if(input[start] == 'p' && input[start + 1] == 'i') {
        for (int i = strlen(input); i >= start + 2; i--) {
            input[i + 2] = input[i];
        }
        input[start] = '3';
        input[start + 1] = '.';
        input[start + 2] = '1';
        input[start + 3] = '4';
    }
}
void replacePi(char input[]) {
    replacePiHelper(input, 0);
}


