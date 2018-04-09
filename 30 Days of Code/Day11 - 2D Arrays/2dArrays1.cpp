#include <vector>
#include <climits>
#include <iostream>
using namespace std;

#define SIZE 6
#define SIZE_GLASS 3

int main(void){
   vector< vector<int> > arr(SIZE,vector<int>(SIZE));
    for(int arr_i = 0; arr_i < SIZE; arr_i++){
       for(int arr_j = 0; arr_j < SIZE; arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int max = INT_MIN;
    for(int arr_i = 0; arr_i<SIZE-SIZE_GLASS+1; arr_i++){
       for(int arr_j=0; arr_j<SIZE-SIZE_GLASS+1; arr_j++){
           int sum = 0;
           for(int x=arr_j; x<arr_j+SIZE_GLASS; x++)
               sum += arr[arr_i][x];
           for(int x=arr_j; x<arr_j+SIZE_GLASS; x++)
               sum += arr[arr_i+SIZE_GLASS-1][x];
           sum += arr[arr_i+1][arr_j+1];

           if(sum>max) max = sum;
       }
    }
    cout << max;
    return 0;
}
