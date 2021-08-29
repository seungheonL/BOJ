#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int w, h;
vector<vector<char>> graph;
queue<pair<int, int>> q;
vector<vector<int>> delay;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int INF = 987654321;

bool valid(int x, int y)
{
    return 0 <= x && x < h && 0 <= y && y < w;
}

void compute_delay()
{
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(valid(nx, ny) && graph[nx][ny] != '#' && delay[nx][ny] == INF)
            {
                delay[nx][ny] = delay[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int bfs(pair<int, int> start)
{
    queue<pair<int, int>> q;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    
    q.push(start);
    dist[start.first][start.second] = 0;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx == -1 || nx == h || ny == -1 || ny == w)
            {
                return dist[x][y] + 1;
            }
            
            if(valid(nx, ny) && graph[nx][ny] != '#' && dist[nx][ny] == INF && dist[x][y] + 1 < delay[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return -1;
}

int main()
{
    scanf("%d %d", &h, &w);
        
    graph = vector<vector<char>>(h, vector<char>(w));
    delay = vector<vector<int>>(h, vector<int>(w, INF));
    pair<int, int> start;
        
    for(int j=0; j<h; j++)
    {
        char str[1002];
        scanf("%s", str);
            
        for(int k=0; k<w; k++)
        {
            graph[j][k] = str[k];
                
            if(graph[j][k] == 'F')
            {
                q.push({j, k});
                delay[j][k] = 0;
            }
                
            if(graph[j][k] == 'J')
            {
                start = {j, k};
            }
        }
    }
        
    compute_delay();
        
    int result = bfs(start);
        
    if(result == -1)
    {
        printf("IMPOSSIBLE\n");
    }
    else
    {
        printf("%d\n", result);
    }
    
    return 0;
}
