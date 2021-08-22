#include <iostream>
#include <map>
#include <utility>

using namespace std;

unsigned long long N, P, Q;

map<unsigned long long, unsigned long long> m;

unsigned long long getA(unsigned long long N)
{
    if(N == 0)
    {
        return 1;
    }
    
    auto itr = m.find(N);
    
    if(itr != m.end())
    {
        return itr->second;
    }
    
    m.insert(pair<unsigned long long, unsigned long long>(N, getA(N / P) + getA(N / Q)));
    
    return m[N];
}

int main()
{
    cin >> N >> P >> Q;
    
    cout << getA(N) << endl;

    return 0;
}
