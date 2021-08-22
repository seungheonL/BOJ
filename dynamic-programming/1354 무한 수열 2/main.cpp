#include <iostream>
#include <map>
#include <utility>

using namespace std;

long long N; 
unsigned long long P, Q, X, Y;

map<long long, unsigned long long> m;

unsigned long long getA(long long N)
{
    if(N <= 0)
    {
        return 1;
    }
    
    auto itr = m.find(N);
    
    if(itr != m.end())
    {
        return itr->second;
    }
    
    m.insert(pair<long long, unsigned long long>(N, getA(N / P - X) + getA(N / Q - Y)));
    
    return m[N];
}

int main()
{
    cin >> N >> P >> Q >> X >> Y;
    
    cout << getA(N) << endl;

    return 0;
}
