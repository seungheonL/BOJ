#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<vector<int>> map;
vector<vector<int>> cache;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return 0 <= x && x < M && 0 <= y && y < N;
}

int count(int x, int y)
{
    if(x == M - 1 && y == N - 1)
    {
        return 1;
    }
    
    int& ret = cache[x][y];
    
    if(ret != -1)
    {
        return ret;
    }
    
    int sum = 0;
    
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(valid(nx, ny))
        {
            if(map[nx][ny] < map[x][y])
            {
                sum += count(nx, ny);
            }
        }
    }
    
    return ret = sum;
}

int main()
{
    cin >> M >> N;
    
    map = vector<vector<int>>(M, vector<int>(N));
    cache = vector<vector<int>>(M, vector<int>(N, -1));
    
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
    cout << count(0, 0) << endl;
    
    return 0;
}
