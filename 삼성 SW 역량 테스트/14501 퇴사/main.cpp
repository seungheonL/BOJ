#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> T;
vector<int> P;

int maximum_profit(int index)
{
    if(index >= N)
    {
        return 0;
    }
    
    if(index + T[index] >= N + 1)
    {
        return maximum_profit(index + 1);
    }
    
    return max(P[index] + maximum_profit(index + T[index]), maximum_profit(index + 1));
}

int main()
{
    cin >> N;
    
    T = vector<int>(N);
    P = vector<int>(N);
    
    for(int i=0; i<N; i++)
    {
        cin >> T[i] >> P[i];
    }
    
    cout << maximum_profit(0) << endl;

    return 0;
}
