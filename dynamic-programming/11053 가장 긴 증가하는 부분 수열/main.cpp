#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		int value;
		cin >> value;

		v[i] = value;
	}

	vector<int> dp(N, 1);
	int length = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
		length = max(length, dp[i]);
	}
	cout << length << endl;


	return 0;
}
