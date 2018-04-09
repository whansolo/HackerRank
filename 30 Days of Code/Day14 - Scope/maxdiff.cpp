#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;

  	public:
  	int maximumDifference;

    // Add your code here
    Difference(vector<int> elements){
        this->elements = elements;
    }

    void computeDifference(){
        int e_max = elements[0];
        int e_min = elements[0];
        for(int i = 1; i < elements.size(); i++){
            e_max = max(e_max, elements[i]);
            e_min = min(e_min, elements[i]);
        }
        maximumDifference = e_max - e_min;
    }

    void computeDifference1(){
        for(int i = 0; i < elements.size(); i++){
            for(int j = i + 1; j < elements.size(); j++){
                maximumDifference = max(maximumDifference, abs(elements[i] - elements[j]));
            }
        }
    }
}; // End of Difference Class

int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}
