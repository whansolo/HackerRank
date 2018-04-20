#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int value){
    if(value == 1) return false;
    if(value == 2) return true;
    if(!(value & 0x1)) return false; // check if the value is even

    int square = sqrt(value);
    for(int n = 3; n <= square; n+=2){
        if(value % n == 0) return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    vector<int> int_seq(T);
    for(int i = 0; i < T; i++){
        int value;
        cin >> value;
        int_seq[i] = value;
    }

    for(int i = 0; i < T; i++){
        if(isPrime(int_seq[i])){
            cout << "Prime" << endl;
        }
        else{
            cout << "Not prime" << endl;
        }
    }

    return 0;
}
