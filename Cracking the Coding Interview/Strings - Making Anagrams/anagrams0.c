#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int ca[26] ={0};
    int cb[26] ={0};
    int count = 0;

    char* a = (char *)malloc(512000 * sizeof(char));
    scanf("%s",a);
    while(*a){
      ca[*(a++)-'a'] += 1;
    }

    char* b = (char *)malloc(512000 * sizeof(char));
    scanf("%s",b);
    while(*b){
      cb[*(b++)-'a'] += 1;
    }

    int tmp;
    for(int i=0;i<26;i++){
      tmp=0;
      tmp=ca[i]-cb[i];
      count += (tmp >0)?tmp:-tmp;
    }

    printf("%d\n", count);
    return 0;
}
