#include <iostream>

using namespace std;

class Pair
{
    public:
    int zero, one;
    
    Pair(int zero, int one) : zero(zero), one(one){}
    Pair(){}
};

int main()
{
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++)
    {
        int N;
        cin >> N;
        
        Pair* result = new Pair[N+1];
        
        result[0].zero = 1;
        result[0].one = 0;
        
        result[1].zero = 0;
        result[1].one = 1;
        
        for(int j=2; j<=N; j++)
        {
            result[j].zero = result[j-1].zero + result[j-2].zero;
            result[j].one = result[j-1].one + result[j-2].one;
        }
        cout << result[N].zero << " " << result[N].one <<  endl;
    }

    return 0;
}
