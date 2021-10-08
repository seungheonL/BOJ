#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i=0; i<N; i++)
    {
        int value;
        scanf("%d", &value);
        
        if(maxHeap.empty())
        {
            maxHeap.push(value);
        }
        else
        {
            if(value > maxHeap.top())
            {
                minHeap.push(value);
                
                if(maxHeap.size() + 1 <= minHeap.size())
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
            else
            {
                maxHeap.push(value);
                
                if(maxHeap.size() - 1 > minHeap.size())
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
        }
        
        printf("%d\n", maxHeap.top());
    }
    
    return 0;
}
