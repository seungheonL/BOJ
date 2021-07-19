#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int N, vector<int>& cache)
{
    if(N == 1) return 0;
    
    int& ret = cache[N];
        
        if(ret != -1)
        {
            return ret;
        }
    
    if(N % 3 == 0 && N % 2 == 0)
    {
        int larger = std::min(solve(N / 3, cache), solve(N / 2, cache));
        return ret = 1 + std::min(larger, solve(N - 1, cache));
    }
    if(N % 3 == 0)
    {
        return ret = 1 + std::min(solve(N / 3, cache), solve(N - 1, cache));
    }
    if(N % 2 == 0)
    {
        return ret = 1 + std::min(solve(N / 2, cache), solve(N - 1, cache));
    }
    return ret = 1 + solve(N - 1, cache);
}

int main()
{
    int N;
    cin >> N;
    vector<int> cache(N + 1, -1);
    
    for(int i=0; i<N+1; i++)
    {
        cache[i] = -1;
    }
    
    cout << solve(N, cache) << endl;

    return 0;
}
