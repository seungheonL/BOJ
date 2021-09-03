#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<vector<pair<int, int>>> graph;

const int INF = 987654321;

vector<long long> dijkstra(int start)
{
    vector<bool> visited(N + 1, false);
    vector<long long> distance(N + 1, INF);
    priority_queue<pair<int, int>> pq;
    
    pq.push(make_pair(0, start));
    distance[start] = 0;
    
    while(!pq.empty())
    {
        int from = pq.top().second;
        pq.pop();
        
        if(visited[from])
        {
            continue;
        }
        visited[from] = true;
        
        for(pair<int, int> u : graph[from])
        {
            int to = u.first;
            int weight = u.second;
            
            if(distance[to] > distance[from] + weight)
            {
                distance[to] = distance[from] + weight;
                pq.push(make_pair(-distance[to], to));
            }
        }
    }
    
    return distance;
}

int main()
{
    int E;
    cin >> N >> E;
    
    graph = vector<vector<pair<int, int>>>(N + 1);
    
    for(int i=0; i<E; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    
   
    int v1, v2;
    cin >> v1 >> v2;
    
    auto d1 = dijkstra(1);
    auto d2 = dijkstra(v1);
    auto d3= dijkstra(v2);
    
    if(d1[v1] == INF || d2[v2] == INF || d3[N] == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    
    int result = min(d1[v1] + d2[v2] + d3[N], d1[v2] + d3[v1] + d2[N]);
    cout << result << endl;

    return 0;
}
