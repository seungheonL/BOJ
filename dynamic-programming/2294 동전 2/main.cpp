#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    vector<int> dp(100001, 987654321);
    
    for(int i=0; i<n; i++)
    {
        scanf("%d", &coins[i]);
        dp[coins[i]] = 1;
    }
    
    for(int i=1; i<=k; i++)
    {
        for(int j=0; j<coins.size(); j++)
        {
            if(i - coins[j] > 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    
    if(dp[k] >= 987654321)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[k] << endl;
    }
    
    return 0;
}
