#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> cache;

int count(int index, int prev)
{
    if(index == N - 1)
    {
        return 1;
    }
    
    int& result = cache[index][prev];
    
    if(result != -1)
    {
        return result;
    }
    
    int cnt = 0;
    
    for(int num = prev; num <= 9; num++)
    {
        cnt = cnt + (count(index + 1, num) % 10007);
        cnt = cnt % 10007;
    }
    
    return result = (cnt % 10007);
}

int main()
{
    cin >> N;
    
    cache = vector<vector<int>>(N, vector<int>(10, -1));
    int cnt = 0;
    
    for(int i=0; i<=9; i++)
    {
        cnt = cnt + (count(0, i) % 10007);
        cnt = cnt % 10007;
    }
    
    cout << cnt % 10007 << endl;

    return 0;
}
