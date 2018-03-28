#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    int k;
    scanf("%d %d",&n,&k);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }

    int *b = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        b[i] = a[(i + k) % n];
        printf("%d ", a[(i + k) % n]);
    }
    /** use pointer:
    int *b = a + k;
    for(int i = 0; i < n; i++){
        if(b >= (a + n)) b = a;
        printf("%d ", *b++);
    }
    */

    return 0;
}
