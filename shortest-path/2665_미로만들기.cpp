#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int N;
vector<vector<int>> maze;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int INF = 987654321;

bool valid(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

int dijkstra()
{
    vector<vector<int>> dist(N, vector<int>(N, INF));
    priority_queue<pair<int, pair<int, int>>> pq;
    
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    
    while(!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = -pq.top().first;
        
        pq.pop();
        
        if(dist[x][y] < cost)
        {
            continue;
        }
        
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(valid(nx, ny) && dist[nx][ny] == INF)
            {
                if(maze[nx][ny] == 1)
                {
                    if(dist[nx][ny] > dist[x][y])
                    {
                        dist[nx][ny] = dist[x][y] + 0;
                        pq.push({-dist[nx][ny], {nx, ny}});
                    }
                }
                else
                {
                    if(dist[nx][ny] > dist[x][y] + 1)
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        pq.push({-dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
    }
    
    return dist[N-1][N-1];
}

int main()
{
    cin >> N;
    maze = vector<vector<int>>(N, vector<int>(N));
    
    for(int i=0; i<N; i++)
    {
        string str;
        cin >> str;
        
        for(int j=0; j<N; j++)
        {
            maze[i][j] = stoi(str.substr(j, 1));
        }
    }
    
    cout << dijkstra() << endl;

    return 0;
}
