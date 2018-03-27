#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int findLonelyInteger(int* a, int n){
    int lonelyone = 0;
    for(int i = 0; i < n; i++){
        lonelyone ^= a[i];
        /*        XOR        */
    }
    return lonelyone;
}

int main(){
    int n;
    scanf("%d",&n);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }

    printf("%d", findLonelyInteger(a, n));
    return 0;
}
