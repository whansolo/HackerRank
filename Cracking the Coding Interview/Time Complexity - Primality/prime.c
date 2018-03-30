#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int isPrime(int p){
    if(p < 2) return 0; // 0 and 1 -> not prime
    else if(p <= 3) return 1; // 2 and 3 -> prime
    else if(p % 2 == 0 || p % 3 == 0) return 0;

    int i = 5;
    int w = 2;
    while(i * i <= p){
        if(p % i == 0) return 0;
        i = i + w;
        w = 6 - w;
    }
    return 1;
}


int main(){
    int p;
    scanf("%d",&p);
    for(int a0 = 0; a0 < p; a0++){
        int n;
        scanf("%d",&n);
        if(isPrime(n) == 1) printf("Prime\n");
        else printf("Not prime\n");
    }
    return 0;
}
