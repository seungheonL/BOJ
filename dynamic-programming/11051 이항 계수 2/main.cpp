#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache;

int C(int N, int K)
{
    if(cache[N][K] != -1)
    {
        return cache[N][K];
    }
    
    int& ret = cache[N][K];
    
    if(K < 0)
    {
        return ret = 0;
    }
    if(K > N)
    {
        return ret = 0;
    }
    if(N == 1)
    {
        return ret = 1;
    }
    return ret = C(N-1, K) % 10007 + C(N-1, K-1) % 10007;
}

int main()
{
    int N, K;
    cin >> N >> K;
    
    cache = vector<vector<int>>(N+1, vector<int>(K+1, -1));
    
    cout << C(N, K) % 10007 << endl;
    
    return 0;
}
