#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    priority_queue<int> pq;
    
    for(int i=0; i<N; i++)
    {
        int value;
        scanf("%d", &value);
        
        pq.push(-value);
    }
    
    if(N == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    int result = 0;
    
    while(!pq.empty())
    {
        int first = -pq.top();
        pq.pop();
        
        int second = -pq.top();
        pq.pop();
        
        result += first + second;
        
        if(pq.empty())
        {
            break;
        }
        
        pq.push(-(first + second));
    }
    
    cout << result << endl;
    
    return 0;
}
