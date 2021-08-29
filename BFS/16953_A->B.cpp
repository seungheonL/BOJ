#include <iostream>
#include <queue>
#include <map>
using namespace std;

long long A, B;
long long bfs()
{
    map<long long, long long> dist;
    queue<long long> q;
    
    dist[A] = 0;
    q.push(A);
    
    while(!q.empty())
    {
        long long current = q.front();
        q.pop();
        
        if(current * 2 <= B)
        {
            if(dist[current * 2] == 0)
            {
                dist[current * 2] = dist[current] + 1;
                q.push(current * 2);
                
                if(current * 2 == B)
                {
                    return dist[current * 2] + 1;
                }
            }
        }
        
        if(current * 10 + 1 <= B)
        {
            if(dist[current * 10 + 1] == 0)
            {
                dist[current * 10 + 1] = dist[current] + 1;
                q.push(current * 10 + 1);
                
                if(current * 10 + 1 == B)
                {
                    return dist[current * 10 + 1] + 1;
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    cin >> A >> B;
    
    cout << bfs() << endl;

    return 0;
}
