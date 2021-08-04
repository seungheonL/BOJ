#include <iostream>
#include <vector>
using namespace std;

vector<vector<unsigned long long>> cache;

unsigned long long C(int n, int r)
{
    if(n == r)
    {
        return 1;
    }
    if(r == 1)
    {
        return n;
    }
    if(cache[n][r] != -1)
    {
        return cache[n][r];
    }
    return cache[n][r] = C(n-1, r) + C(n-1, r-1);
}

int main()
{
    cache = vector<vector<unsigned long long>>(31, vector<unsigned long long>(31, -1));
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++)
    {
        int N, M;
        cin >> N >> M;
        
        cout << C(M, N) << endl;
    }

    return 0;
}
