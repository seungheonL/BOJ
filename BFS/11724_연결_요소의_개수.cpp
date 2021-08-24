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
	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N + 1);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> visited(N + 1, false);

	queue<int> q;
	
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i])
		{
			continue;
		}
		visited[i] = true;

		q.push(i);
		while (!q.empty())
		{
			int next = q.front();
			q.pop();

			for (int u : adj[next])
			{
				if (visited[u])
				{
					continue;
				}
				visited[u] = true;
				q.push(u);
			}
		}
		cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}
