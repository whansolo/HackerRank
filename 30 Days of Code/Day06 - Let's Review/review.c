#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char *str = (char *)malloc(sizeof(char) * 10001);
        scanf("%s", str);
        int str_length = strlen(str);
        char *s_even = (char *)malloc(sizeof(char) * (2 + str_length/2));
        char *s_odd = (char *)malloc(sizeof(char) * (1+str_length/2));
        int e = 0;
        int o = 0;
        for(int j = 0; j < str_length; j++){
            if(j % 2){
                s_odd[o++] = str[j];
            }else{
                s_even[e++] = str[j];
            }
        }
        s_odd[o] = '\0';
        s_even[e] = '\0';

        printf("%s ", s_even);
        printf("%s\n", s_odd);
    }
    return 0;
}

/**
int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT //
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char str[10001];
        scanf("%s", str);
        int j;
        for(j = 0; j < strlen(str); j+=2){
            printf("%c", str[j]);
        }
        printf(" ");
        for(j = 1; j < strlen(str); j+=2){
            printf("%c", str[j]);
        }
        printf(" \n");
    }
    return 0;
}
**/
