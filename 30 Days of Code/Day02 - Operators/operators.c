#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    double meal_cost;
    int tip_percent;
    int tax_percent;
    scanf("%lf", &meal_cost);
    scanf("%i", &tip_percent);
    scanf("%i", &tax_percent);

    double tip = meal_cost * (double)tip_percent / 100;
    double tax = meal_cost * tax_percent / 100.0f;
    double totalCost = meal_cost + tip + tax;
    printf("The total meal cost is %.0lf dollars.", totalCost);
    /*                              ^^ (round)                */
    return 0;
}
