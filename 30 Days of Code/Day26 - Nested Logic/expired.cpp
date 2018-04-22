#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct _date{
    int day;
    int month;
    int year;
}Date;

int calculateFine(Date actual, Date expected){
    int yearLate = actual.year - expected.year;
    int monthLate = actual.month - expected.month;
    int dayLate = actual.day - expected.day;

    return  (yearLate < 0) ? 0
          : (yearLate > 0) ? 10000
          : (monthLate < 0) ? 0
          : (monthLate > 0) ? monthLate * 500
          : (dayLate < 0) ? 0
          : (dayLate > 0) ? dayLate * 15 : 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    Date actual, expected;
    cin >> actual.day >> actual.month >> actual.year;
    cin >> expected.day >> expected.month >> expected.year;

    cout << calculateFine(actual, expected);
    return 0;
}
