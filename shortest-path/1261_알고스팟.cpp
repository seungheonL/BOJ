#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int M, N;
vector<vector<int>> maze;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int INF = 987654321;

bool valid(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < M;
}

int dijkstra()
{
    vector<vector<int>> dist(N, vector<int>(M, INF));
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
                dist[nx][ny] = min(dist[nx][ny], dist[x][y] + maze[nx][ny]);
                pq.push({-dist[nx][ny], {nx, ny}});
            }
        }
    }
    
    return dist[N-1][M-1];
}

int main()
{
    cin >> M >> N;
    maze = vector<vector<int>>(N, vector<int>(M));
    
    for(int i=0; i<N; i++)
    {
        string str;
        cin >> str;
        
        for(int j=0; j<M; j++)
        {
            maze[i][j] = stoi(str.substr(j, 1));
        }
    }
    
    cout << dijkstra() << endl;

    return 0;
}
