#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {
    // Complete this function
    return (n <= 1)? 1: n * factorial(n - 1);
}

int main() {
    int n;
    cin >> n;
    int result = factorial(n);
    cout << result << endl;
    return 0;
}
