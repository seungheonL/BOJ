#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> cache;

int count(int index)
{
    if(index == N - 1)
    {
        return 1;
    }
    if(index == N - 2)
    {
        return 2;
    }
    
    long long& ret = cache[index];
    
    if(ret != -1)
    {
        return ret;
    }
    
    return ret = count(index + 1) % 15746 + count(index + 2) % 15746;
}

int main()
{
    cin >> N;
    cache = vector<long long>(N, -1);
    cout << count(0) % 15746 << endl;

    return 0;
}
