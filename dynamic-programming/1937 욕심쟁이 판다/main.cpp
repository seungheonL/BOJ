#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<int>> cache;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

int getMaxDays(int x, int y)
{
    if(cache[x][y] != -1)
    {
        return cache[x][y];
    }
    
    int result = 0;
    bool foundNext = false;
    
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(valid(nx, ny) && (graph[nx][ny] > graph[x][y]))
        {
            result = max(result, 1 + getMaxDays(nx, ny));
            foundNext = true;
        }
    }
    
    if(!foundNext)
    {
        return 1;
    }
    
    return cache[x][y] = result;

}

int main()
{
    cin >> n;
    
    graph = vector<vector<int>>(n, vector<int>(n));
    cache = vector<vector<int>>(n, vector<int>(n, -1));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    int result = -1;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            result = max(result, getMaxDays(i, j));
        }
    }
    
    cout << result << endl;
    
    return 0;
}
