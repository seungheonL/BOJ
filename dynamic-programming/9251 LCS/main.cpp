#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    
    if(A.size() < B.size())
    {
        swap(A, B);
    }
    
    vector<vector<int>> dp(B.size(), vector<int>(A.size(), 0));
    
    if(A[0] == B[0])
    {
        dp[0][0]++;
    }
    
    for(int i=1; i<dp[0].size(); i++)
    {
        if(B[0] == A[i])
        {
            dp[0][i]++;
        }
        else
        {
            dp[0][i] = dp[0][i-1];
        }
    }
    
    for(int i=1; i<dp.size(); i++)
    {
        if(A[0] == B[i])
        {
            dp[i][0]++;
        }
        else
        {
            dp[i][0] = dp[i-1][0];
        }
    }
    
    for(int i=1; i<dp.size(); i++)
    {
        for(int j=1; j<dp[0].size(); j++)
        {
            if(A[j] == B[i])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << dp[B.size() - 1][A.size() - 1] << endl;
    
    return 0;
}
