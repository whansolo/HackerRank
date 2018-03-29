#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


// using recursion
int countWayR(int n){
    if(n < 0) return 0;
    else if(n <= 1) return 1;
    //f(0) = 1, f(1) = 1, f(2) = 2
    return countWayR(n-1) + countWayR(n-2) + countWayR(n-3);
}

// using array to store the value counted
int countWayMemo(int n, int memo[]){
    if(n < 0) return 0;
    else if(n <= 1) return 1;
    //f(0) = 1, f(1) = 1, f(2) = 2
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    for(int i = 3; i <= n; i++){
        memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
    }
    return memo[n];
}

// using loop
int countWayL(int n) {
    if (n < 1) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    int ways[] = {1,2,4};

    for (int i = 4; i < n; i++) {
        int idx = (i - 1) % 3;
        ways[idx] = ways[0] + ways[1] + ways[2];
    }
    return ways[0] + ways[1] + ways[2];
}

int main(){
    int s;
    int m[36];
    scanf("%d",&s);
    for(int a0 = 0; a0 < s; a0++){
        int n;
        scanf("%d",&n);
        printf("%d\n", countWayMemo(n, m));
    }
    return 0;
}
