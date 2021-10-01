#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> indegree(N + 1, 0);
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int i=0; i<M; i++)
    {
        int A, B;
        cin >> A >> B;
        
        graph[A].push_back(B);
        indegree[B]++;
    }
    
    for(int i=1; i < N + 1; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int here = q.top();
        q.pop();
        
        cout << here << " ";
        
        for(int there: graph[here])
        {
            indegree[there]--;
            
            if(indegree[there] == 0)
            {
                q.push(there);
            }
        }
    }
    
    return 0;
}
