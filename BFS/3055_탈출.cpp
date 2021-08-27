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

pair<int, int> src, dest;

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
            
            if(valid(nx, ny) && graph[nx][ny] == '.' && delay[nx][ny] == INF)
            {
                delay[nx][ny] = delay[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int bfs()
{
    queue<pair<int, int>> q;
    vector<vector<int>> dist(h, vector<int>(w, INF));
        
    q.push(src);
    dist[src.first][src.second] = 0;
        
    int dest_x = dest.first;
    int dest_y = dest.second;
        
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
            
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
                
            if(valid(nx, ny) && dist[nx][ny] == INF && graph[nx][ny] != 'X' && dist[x][y] + 1 < delay[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
                    
                if(nx == dest_x && ny == dest_y)
                {
                    return dist[nx][ny];
                }
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
    
    for(int j=0; j<h; j++)
    {
        char str[1002];
        scanf("%s", str);
            
        for(int k=0; k<w; k++)
        {
            graph[j][k] = str[k];
                
            if(graph[j][k] == '*')
            {
                q.push({j, k});
                delay[j][k] = 0;
            }
            
            if(graph[j][k] == 'S')
            {
                src = make_pair(j, k);
            }
            
            if(graph[j][k] == 'D')
            {
                dest = make_pair(j, k);
            }
        }
    }
        
    compute_delay();
    
    int result = bfs();
    
    if(result != -1)
    {
        cout << result << endl;
    }
    else
    {
        cout << "KAKTUS" << endl;
    }
    
    return 0;
}
