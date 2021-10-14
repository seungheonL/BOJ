#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, C;
    cin >> N >> C;
    
    map<int, pair<int, int>> m;
    
    for(int i=0; i<N; i++)
    {
        int value;
        cin >> value;
        
        auto itr = m.find(value);
        
        if(itr != m.end())
        {
            itr->second.first--;
        }
        else
        {
            m.insert({value, {-1, i}});
        }
    }
    
    vector<pair<int, pair<int, int>>> v;
    
    for(const auto& elem : m)
    {
        v.push_back({elem.second.first, {elem.second.second, elem.first}});
    }
    
    sort(v.begin(), v.end());
    
    for(const auto& elem : v)
    {
        for(int i=0; i<-elem.first; i++)
        {
            printf("%d ", elem.second.second);
        }
    }
    
    return 0;
}
