#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int K, W, H;
vector<vector<int>> graph;

int dx[] = {2, 2, 1, 1, -2, -2, -1, -1,  0, 0, 1, -1};
int dy[] = {1, -1, 2, -2, 1, -1, 2, -2,  1, -1, 0, 0};

bool valid(int x, int y)
{
    return 0 <= x && x < H && 0 <= y && y < W;
}

int bfs()
{
    if(W == 1 && H == 1 && graph[0][0] == 0)
    {
        return 0;
    }
    
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(K + 1, -1)));
    queue<pair<pair<int, int>, int>> q;
    
    dist[0][0][0] = 0;
    q.push({{0, 0}, 0});
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int used = q.front().second;
        
        q.pop();
        
        if(used < K)
        {
            for(int i=0; i<8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(valid(nx, ny) && graph[nx][ny] == 0 && dist[nx][ny][used + 1] == -1)
                {
                    dist[nx][ny][used + 1] = dist[x][y][used] + 1;
                    q.push({{nx, ny}, used + 1});
                    
                    if(nx == H - 1 && ny == W - 1)
                    {
                        return dist[nx][ny][used + 1];
                    }
                }
            }
        }
        
        for(int i=8; i<12; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
                
            if(valid(nx, ny) && graph[nx][ny] == 0 && dist[nx][ny][used] == -1)
            {
                dist[nx][ny][used] = dist[x][y][used] + 1;
                q.push({{nx, ny}, used});
                
                if(nx == H - 1 && ny == W - 1)
                {
                    return dist[nx][ny][used];
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    cin >> K >> W >> H;
    graph = vector<vector<int>>(H, vector<int>(W));
    
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    cout << bfs() << endl;
    
    return 0;
}
