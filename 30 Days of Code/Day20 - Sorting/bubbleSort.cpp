#include <bits/stdc++.h>

using namespace std;


void swap(int* a, int* b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

class BubbleSort{
    int numberOfSwaps = 0;
    bool sorted;
    public:
        vector<int> bubbleSort(vector<int> a, int n);
        int getNumSwaps(){return numberOfSwaps;}
};

vector<int> BubbleSort::bubbleSort(vector<int> a, int n){
    for(int i = 0; i < n; i++){
        sorted = 0;
        // Track number of elements swapped during a single array traversal
        for(int j = 0; j < n - 1; j++){
            // Swap adjacent elements if they are in decreasing order
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
                sorted = 1;
            }
        }
        // If no elements were swapped during a traversal, array is sorted
        if(sorted == 0) break;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }

    BubbleSort v;
    a = v.bubbleSort(a, n);

    cout << "Array is sorted in " << v.getNumSwaps() << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n-1] << endl;
    return 0;
}
