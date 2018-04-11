#include <iostream>

using namespace std;

int main(){
    string S;
    cin >> S;

    try{
        cout << stoi(S) << endl;
    }
    //catch(...){
    //catch(exception a){
    catch(const invalid_argument &a){
        cout << "Bad String" << endl;
    }
    return 0;
}

/**
 1. std::stoi can crash for multiple reasons. We intend to print "Bad String" only when the input is wrong.
    Thus, it's better to catch std::invalid_argument instead of std::exception.
 2. In C++ exceptions should be caught by reference (e.g. exception& instead of exception).
    If you catch it by value, you'll create a copy.
 **/
