#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void swap(int *count, int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    *count++;
}

int sort(int *a, int n){
    int flag;
    int count = 0;
    for(int i = 0; i < n; i++){
        flag = 0;
        for(int j = 0; j < n - 1; j++){
            if(a[j] > a[j + 1]){
                swap(&count, &a[j], & a[j + 1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
    return count;
}

int main(){
    int n;
    scanf("%d",&n);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }

    printf("Array is sorted in %d swaps.\n", sort(a, n));
    printf("First Element: %d\n", a[0]);
    printf("Last Element: %d\n", a[n - 1]);
    return 0;
}
