#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 987654321;

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> graph(N + 1);
    queue<int> q;
    vector<bool> inQ(N + 1, false);
    vector<long long> distance(N + 1, INF);
    vector<int> cycle(N + 1, 0);
    
    for(int i=0; i<M; i++)
    {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        
        graph[A].push_back(make_pair(B, C));
    }
    
    q.push(1);
    cycle[1]++;
    inQ[1] = true;
    distance[1] = 0;
    
    while(!q.empty())
    {
        int from = q.front();
        q.pop();
        inQ[from] = false;
        
        for(pair<int, int> u : graph[from])
        {
            int to = u.first;
            int cost = u.second;
            
            if(distance[to] > distance[from] + cost)
            {
                distance[to] = distance[from] + cost;
                
                if(!inQ[to])
                {
                    cycle[to]++;
                    if(cycle[to] >= N)
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                }
                
                q.push(to);
                inQ[to] = true;
      
            }
        }
    }
    
    for(int i=2; i<=N; i++)
    {
        if(distance[i] == INF)
        {
            printf("%d\n", -1);
        }
        else
        {
            printf("%d\n", distance[i]);
        }
    }
    
    return 0;
}
