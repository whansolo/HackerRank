#include <iostream>

using namespace std;

int main(){
    int num;
    int cnt = 0;
    int max = 0;
    cin >> num;

    while(num){
        cnt = ++cnt * (num & 0x1);
        max = (max > cnt)? max : cnt;
        num >>= 1;
    }

    cout << max << endl;
    return 0;
}
