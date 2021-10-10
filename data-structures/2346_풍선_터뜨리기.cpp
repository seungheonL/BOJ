#include <iostream>
#include <deque>

using namespace std;

class Ballon
{
public:
    int value;
    int num;
    
    Ballon(int value, int num) : value(value), num(num) {}
};

int main()
{
    int N;
    cin >> N;
    
    deque<Ballon> dq;
    
    for(int i=1; i<=N; i++)
    {
        int value;
        cin >> value;
        
        dq.push_back(Ballon(value, i));
    }
    
    Ballon next = dq.front();
    
    bool right = true;
    
    while(!dq.empty())
    {
        cout << next.num << " ";
        
        if(right)
        {
            dq.pop_front();
        }
        else
        {
            dq.pop_back();
        }
        
        if(next.value >= 0)
        {
            for(int i=0; i<next.value - 1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            right = true;
        }
        else
        {
            for(int i=0; i<-next.value - 1; i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            right = false;
        }
        
        if(right)
        {
            next = dq.front();
        }
        else
        {
            next = dq.back();
        }
    }

    return 0;
}
