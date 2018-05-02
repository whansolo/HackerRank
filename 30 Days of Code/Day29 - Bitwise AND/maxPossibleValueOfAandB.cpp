#include <iostream>
using namespace std;

int maxPossibleAandB(int n, int k){
    int maxAND = 0;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int tmpAND = i & j;
            maxAND = (tmpAND < k && tmpAND > maxAND)? tmpAND : maxAND;
        }
    }
    return maxAND;
}

int maxPossibleAB(int n, int k){
    if(((k-1) | k) <= n)
        return k-1;
    else
        return k-2;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        cout << maxPossibleAB(n, k) << endl;
    }
    return 0;
}
