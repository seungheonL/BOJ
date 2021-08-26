#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int l;
vector<vector<int>> graph;
vector<vector<int>> dist;

int curX, curY;
int targetX, targetY;

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

const int INF = 987654321;

bool valid(int x, int y)
{
    return 0 <= x && x < l && 0 <= y && y < l;
}

int bfs()
{
    queue<pair<int, int>> q;
    
    q.push({curX, curY});
    dist[curX][curY] = 0;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(valid(nx, ny) && (dist[nx][ny] == INF))
            {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
                
                if(nx == targetX && ny == targetY)
                {
                    return dist[nx][ny];
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++)
    {
        scanf("%d", &l);
        dist = vector<vector<int>>(l, vector<int>(l, INF));
        
        scanf("%d %d", &curX, &curY);
        scanf("%d %d", &targetX, &targetY);
        
        if(curX == targetX && curY == targetY)
        {
            printf("%d\n", 0);
        }
        
        else
        {
            printf("%d\n", bfs());
        }
    }

    return 0;
}
