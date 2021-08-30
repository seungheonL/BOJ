#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
bool found = false;

void dfs(int current, int count)
{
    if(count == 4)
    {
        found = true;
        return;
    }
    
    visited[current] = true;
    
    for(auto next : graph[current])
    {
        if(!visited[next])
        {
            dfs(next, count + 1);
        }
    }
    
    visited[current] = false;
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    graph = vector<vector<int>>(N + 1);
    visited = vector<bool>(N, false);
    
    for(int i=0; i<M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i=0; i<N; i++)
    {
        if(!visited[i])
        {
            dfs(i, 0);
            
            if(found)
            {
                cout << 1 << endl;
                return 0;
            }
        }
    }
    
    cout << 0 << endl;

    return 0;
}
