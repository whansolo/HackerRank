#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* isWeird(int n){
    if((n & 1) || (6 <= n && n <= 20)) return "Weird";
    else return "Not Weird";
    /*
    if(n % 2) return "Weird";
    else if(n >= 2 && n <= 5) return "Not Weird";
    else if(n >= 6 && n <= 20) return "Weird";
    else if(n >= 20) return "Not Weird";
    else return 0;
    */
}

int main(){
    int N;
    scanf("%d",&N);
    printf("%s\n", isWeird(N));
    return 0;
}
