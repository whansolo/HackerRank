#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    // Declare second integer, double, and String variables.
    int j = 0;
    double e = 0.0;
    char s1[64];
    // Read and save an integer, double, and String to your variables.
    scanf("%d", &j);
    scanf("%f", &e);
    scanf(" %[^\n]", s1);
    //    ^^^^^^^^^
    // Print the sum of both integer variables on a new line.
    printf("%d\n", i+j);
    // Print the sum of the double variables on a new line.
    printf("%.1f\n", d+e);
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    char *s2 = (char*)malloc(strlen(s)+strlen(s1)+1);
    strcpy(s2, s);
    strcat(s2, s1);
    printf("%s\n", s2);

    return 0;
}
