#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N;
vector<vector<int>> graph;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

const int INF = 987654321;

int dijkstra()
{
    vector<vector<int>> dist(N, vector<int>(N, INF));
    priority_queue<pair<int, pair<int, int>>> pq;
    
    dist[0][0] = graph[0][0];
    pq.push({dist[0][0], {0, 0}});
    
    while(!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = -pq.top().first;
        
        pq.pop();
        
        if(dist[x][y] < cost) continue;
        
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(valid(nx, ny))
            {
                int weight = graph[nx][ny];
                
                if(dist[nx][ny] > dist[x][y] + weight)
                {
                    dist[nx][ny] = dist[x][y] + weight;
                    pq.push({-dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
    
    return dist[N-1][N-1];
}

int main()
{
    int cnt = 1;
    
    while(true)
    {
        scanf("%d", &N);
        
        if(N == 0) break;
        
        graph = vector<vector<int>>(N, vector<int>(N));
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                scanf("%d", &graph[i][j]);
            }
        }
        
        printf("Problem %d: %d\n", cnt, dijkstra());
        cnt++;
    }

    return 0;
}
