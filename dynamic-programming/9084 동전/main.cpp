#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> coins;
vector<vector<int>> cache;

int count(int index, int money)
{
    if(index == N - 1)
    {
        if(money % coins[index] == 0)
        {
            return 1;
        }
        return 0;
    }
    
    if(cache[index][money] != -1)
    {
        return cache[index][money];
    }
    
    if(money == 0)
    {
        return cache[index][money] = 1;
    }
    
    int cnt = 0;
    int result = 0;
    
    while(money >= cnt * coins[index])
    {
        result += count(index + 1, money - cnt * coins[index]);
        cnt++;
    }
    
    return cache[index][money] = result;
}

int main()
{
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++)
    {
        cin >> N;
        
        coins = vector<int>(N);
        cache = vector<vector<int>>(N, vector<int>(10001, -1));
        
        for(int i=0; i<N; i++)
        {
            cin >> coins[i];
        }
    
        cin >> M;
        
        cout << count(0, M) << endl;
    }

    return 0;
}
