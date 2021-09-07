#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dist;

const int INF = 987654321;

int n, d, c;

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    dist = vector<int>(n + 1, INF);
    
    dist[c] = 0;
    pq.push({-dist[c], c});
    
    while(!pq.empty())
    {
        int current = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        if(cost > dist[current])
        {
            continue;
        }
        
        for(pair<int, int> u : graph[current])
        {
            int next = u.first;
            int weight = u.second;
            
            if(dist[next] > dist[current] + weight)
            {
                dist[next] = dist[current] + weight;
                pq.push({-dist[next], next});
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
        scanf("%d %d %d", &n, &d, &c);
        
        graph = vector<vector<pair<int, int>>>(n + 1);
        
        for(int j=0; j<d; j++)
        {
            int a, b, s;
            scanf("%d %d %d", &a, &b, &s);
            
            graph[b].push_back({a, s});
        }
        
        dijkstra();
        
        int infected = n;
        int longest = -1;
        
        for(int j=1; j<dist.size(); j++)
        {
            if(dist[j] == INF)
            {
                infected--;
            }
            
            if(dist[j] != INF)
            {
               longest = max(longest, dist[j]); 
            }
        }
        
        printf("%d %d\n", infected, longest);
    }
    
    return 0;
}
