#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++)
    {
        int n;
        cin >> n;
        
        vector<pair<string, int>> v;
        
        for(int j=0; j<n; j++)
        {
            string name, type;
            cin >> name >> type;
            
            if(v.empty())
            {
                v.push_back(make_pair(type, 1));
            }
            else
            {
                bool found = false;
                for(int k=0; k<v.size(); k++)
                {
                    if(v[k].first == type)
                    {
                        v[k].second++;
                        found = true;
                        break;
                    }
                }
                if(!found)
                {
                    v.push_back(make_pair(type, 1));
                }
            }
        }
        
        int mul = 1;
        
        for(auto element : v)
        {
            mul  = mul * (element.second + 1);
        }
        
        cout << mul - 1 << endl;
    }

    return 0;
}
