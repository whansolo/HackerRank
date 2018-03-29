#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* the example would not pass Test Case #3-#9 */

void sort(int a[], int n){
    int i;
    for(i = n; i > 0; i--){
        if(a[i-1] > a[i]){
            int tmp = a[i];
            a[i] = a[i-1];
            a[i-1] =tmp;
        }
    }
}

float median(int a[], int n){
    int index = n >> 1;
    if(n % 2){
        return (float)a[index];
    }
    else{
        return (float)(a[index-1]+a[index])/2.0f;
    }
}

int main(){
    int num;
    scanf("%d",&num);
    int *a = malloc(sizeof(int) * num);
    for(int a_i = 0; a_i < num; a_i++){
        scanf("%d",&a[a_i]);
        sort(a, a_i);
        printf("%.1f\n", median(a, a_i+1));
    }
    return 0;
}
