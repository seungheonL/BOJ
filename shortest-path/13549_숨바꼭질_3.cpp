#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, K;

const int INF = 987654321;

int dijkstra()
{
    vector<int> dist(100001, INF);
    priority_queue<pair<int, int>> pq;
    
    dist[N] = 0;
    pq.push({-dist[N], N});
    
    while(!pq.empty())
    {
        int current = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        if(dist[current] < cost) continue;
        
        if(current - 1 >= 0)
        {
            if(dist[current - 1] > dist[current] + 1)
            {
                dist[current - 1] = dist[current] + 1;
                pq.push({-dist[current - 1], current - 1});
            }
        }
        
        if(current + 1 <= 100000)
        {
            if(dist[current + 1] > dist[current] + 1)
            {
                dist[current + 1] = dist[current] + 1;
                pq.push({-dist[current + 1], current + 1});
            }
        }
        
        if(2 * current <= 100000)
        {
            if(dist[2 * current] > dist[current])
            {
                dist[2 * current] = dist[current];
                pq.push({-dist[2 * current], 2 * current});
            }
        }
    }
    
    return dist[K];
}

int main()
{
    cin >> N >> K;
    
    cout << dijkstra() << endl;
    
    return 0;
}
