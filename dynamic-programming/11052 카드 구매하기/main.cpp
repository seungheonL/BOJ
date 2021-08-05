#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> price(N + 1);
    vector<int> dp(N + 1, -1);
    
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &price[i]);
        dp[i] = price[i];
    }

    
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(i - j > 0)
            {
                dp[i] = max(dp[i], dp[i - j] + price[j]);
            }
        }
    }
    
    cout << dp[N] << endl;
    
    return 0;
}
