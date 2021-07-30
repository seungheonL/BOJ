#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<unsigned long long>> cache;

unsigned long long count(int index, int prev)
{
    if(index == N - 1)
    {
        if(prev == 0)
        {
            return 2;
        }
        return 1;
    }
    
    if(index == 0)
    {
        return count(index + 1, 1);
    }
    
    if(cache[index][prev] != -1)
    {
        return cache[index][prev];
    }
    
    if(prev == 0)
    {
        return cache[index][prev] = count(index + 1, 0) + count(index + 1, 1);
    }
    
    return cache[index][prev] = count(index + 1, 0);
}

int main()
{
    cin >> N;
    cache = vector<vector<unsigned long long>>(N + 1, vector<unsigned long long>(2, -1));
    cout << count(0, -1) << endl;

    return 0;
}
