#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class negative_power : public exception
{
    const char* what() const noexcept //c-string return type
    {
        return "n and p should be non-negative";
    }
} neg_pow;


class Calculator {
    public:
        int power(int num, int pow) {
            if(num < 0 || pow < 0) {
                //throw runtime_error("n and p should be non-negative");
                //throw invalid_argument{"n and p should be non-negative"};
                throw neg_pow;
            }

            int result = 1;
            for(int i = 0; i < pow; i++) result *= num;

            return result;
        }
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
        if(scanf("%d %d",&n,&p)==2){
            try{
                int ans=myCalculator.power(n,p);
                cout<<ans<<endl;
            }
            catch(exception& e){
                cout<<e.what()<<endl;
            }
        }
    }
}
