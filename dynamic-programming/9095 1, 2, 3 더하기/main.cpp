#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cache;

int count(int left)
{
    if(left < 0)
    {
        return 0;
    }
    
    if(left == 0)
    {
        return 1;
    }
    
    if(cache[left] != -1)
    {
        return cache[left];
    }
    
    return cache[left] = count(left - 1) + count(left - 2) + count(left - 3);
}

int main()
{
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++)
    {
        cin >> n;
        cache = vector<int>(n + 1, -1);
        cout << count(n) << endl;
    }

    return 0;
}
