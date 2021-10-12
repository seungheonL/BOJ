#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

map<string, int> m;
vector<pair<int, string>> v;

int main()
{
    int K, L;
    cin >> K >> L;
    
    for(int i=0; i<L; i++)
    {
        char ID[10];
        scanf("%s", ID);
        
        auto itr = m.find(string(ID));
        
        if(itr != m.end())
        {
            itr->second = i;
        }
        
        else
        {
            m.insert(make_pair(string(ID), i));
        }
    }
    
    for(const auto& elem : m)
    {
        v.push_back(make_pair(elem.second, elem.first));
    }
    
    sort(v.begin(), v.end());
    
    int loop = min(L, K);
    loop = min(loop, (int)v.size());
    
    for(int i=0; i<loop; i++)
    {
        printf("%s\n", v[i].second.c_str());
    }

    return 0;
}
