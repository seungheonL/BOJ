#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int x, int y, int n, vector<vector<int>>& triangle, vector<vector<int>>& cache)
{
    if(x == n - 1)
    {
        return triangle[x][y];
    }
    
    int& ret = cache[x][y];
    
    if(ret != -1)
    {
        return ret;
    }
    
    return ret = triangle[x][y] + std::max(solve(x+1, y, n, triangle, cache), solve(x+1, y+1, n, triangle, cache));
}

int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> triangle(n, vector<int>(n));
    vector<vector<int>> cache(n, vector<int>(n, -1));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cin >> triangle[i][j];
        }
    }
    
    cout << solve(0, 0, n, triangle, cache);

    return 0;
}
