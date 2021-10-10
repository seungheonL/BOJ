#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    set<int> s;
    
    for(int i=0; i<N; i++)
    {
        int value;
        scanf("%d", &value);
        
        s.insert(value);
    }
    
    for(int i=0; i<M; i++)
    {
        int value;
        scanf("%d", &value);
        
        auto itr = s.find(value);
        
        if(itr != s.end())
        {
            N--;
        }
        else
        {
            N++;
        }
    }
    
    cout << N << endl;
    
    return 0;
}
