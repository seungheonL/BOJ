#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<long long>> cache;

int count(int num, int index)
{
    if(index == N - 1)
    {
        return 1;
    }
  
    long long& ret = cache[num][index];
  
    if(ret != -1)
    {
        return ret % 1000000000;
    }
    if(num == 9)
    {
        return ret = count(num - 1, index + 1) % 1000000000;
    }
    if(num == 0)
    {
        return ret = count(num + 1, index + 1) % 1000000000;
    }
    return ret = count(num - 1, index + 1) % 1000000000 + count(num + 1, index + 1) % 1000000000;
}

int main()
{
    cin >> N;
    
    cache = vector<vector<long long>>(10, vector<long long>(N, -1));
    
    long long result = 0;
    
    for(int i=1; i<=9; i++)
    {
        result += count(i, 0);
        result %= 1000000000;
    }
    
    cout << result % 1000000000 << endl;
    
    return 0;
}
