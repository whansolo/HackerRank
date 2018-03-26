#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int letters[26] = {0};
    int count = 0;

    char* a = (char *)malloc(512000 * sizeof(char));
    scanf("%s",a);
    char* b = (char *)malloc(512000 * sizeof(char));
    scanf("%s",b);

    while(*a){
      letters[*(a++)-'a'] += 1;
    }
    while(*b){
      letters[*(b++)-'a'] -= 1;
    }

    for(int i=0;i<26;i++){
      count += (letters[i] > 0)? letters[i] : (-letters[i]);
    }

    printf("%d\n", count);
    return 0;
}
