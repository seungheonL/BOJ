#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<unsigned long long>> adj(n + 1, vector<unsigned long long>(n + 1, -1));

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (adj[a][b] != -1)
		{
			if (adj[a][b] > c)
			{
				adj[a][b] = c;
			}
		}
		else
		{
			adj[a][b] = c;
		}
	}

	vector<vector<unsigned long long>> dist(n + 1, vector<unsigned long long>(n + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				dist[i][j] = 0;
			}
			else if (adj[i][j] != -1)
			{
				dist[i][j] = adj[i][j];
			}
			else
			{
				dist[i][j] = 50000000000;
			}
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] >= 50000000000)
			{
				printf("0 ");
			}
			else
			{
				printf("%d ", dist[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}
