#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_LENGTH (1000 + 1)

bool is_balanced(char expression[]) {
    int length = strlen(expression);
    if(length % 2) return 0;

    char stack[MAX_LENGTH];
    int count = 0;
    for(int i = 0; i < length; i++){
        if((expression[i] == '{') || (expression[i] == '[') || (expression[i] == '(')){
            stack[count++] = expression[i];
        }
        else{ /* ')', ']', '}' */
            char pop = stack[--count];
            if(expression[i] == ')' && pop == '(') continue;
            else if(expression[i] == ']' && pop == '[') continue;
            else if(expression[i] == '}' && pop == '{') continue;
            else return 0;
        }
    }
    return (count == 0) ? 1 : 0;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        char* expression = (char *)malloc(MAX_LENGTH * sizeof(char));
        scanf("%s",expression);
        bool answer = is_balanced(expression);
        if(answer)
            printf("YES\n");
        else
            printf("NO\n");
        free(expression);
    }
    return 0;
}
