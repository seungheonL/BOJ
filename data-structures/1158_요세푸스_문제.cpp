#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    queue<int> q;
    vector<int> sequence;
    
    for(int i=1; i<=N; i++)
    {
        q.push(i);
    }
    
    while(!q.empty())
    {
        for(int i=0; i<K-1; i++)
        {
            int top = q.front();
            q.push(top);
            q.pop();
        }
        
        sequence.push_back(q.front());
        q.pop();
    }
    
    cout << "<";
    
    for(int i=0; i<N; i++)
    {
        if(i != N-1)
        {
            cout << sequence[i] << ", ";
        }
        else
        {
            cout << sequence[i];
        }
    }
    cout << ">";
    
    return 0;
}
