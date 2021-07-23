#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cache;

int count(int n)
{
    if(n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 2;
    }
    
    int& result = cache[n];
    
    if(result != -1)
    {
        return result % 10007;
    }
    
    return result = count(n-1) % 10007 + count(n-2) % 10007;
}

int main()
{
    cin >> n;
    cache = vector<int>(n + 1, -1);
    
    cout << count(n) % 10007 << endl;
    
    return 0;
}
