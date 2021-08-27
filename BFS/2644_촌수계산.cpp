#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> graph;
int source, destination;

const int INF = 987654321;

int bfs()
{
    vector<int> dist(n + 1 , INF);
    queue<int> q;
    
    q.push(source);
    dist[source] = 0;
    
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for(int next : graph[current])
        {
            if(dist[next] == INF)
            {
                q.push(next);
                dist[next] = dist[current] + 1;
                
                if(next == destination)
                {
                    return dist[next];
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    cin >> n;
    graph = vector<vector<int>>(n + 1);
    
    cin >> source >> destination;
    
    int m;
    cin >> m;
    
    for(int i=0; i<m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    cout << bfs() << endl;
    
    return 0;
}
