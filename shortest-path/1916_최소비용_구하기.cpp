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

	vector<vector<pair<int, int>>> adj(N + 1);
	vector<unsigned long long> distance(N + 1, 50000000000);
	priority_queue<pair<int, int>> q;
	vector<bool> processed(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);

		adj[from].push_back(make_pair(to, cost));
	}

	int X, Y;
	cin >> X >> Y;

	distance[X] = 0;
	q.push(make_pair(0, X));

	while (!q.empty())
	{
		int a = q.top().second;
		q.pop();

		if (processed[a])
		{
			continue;
		}
		processed[a] = true;
		for (auto u : adj[a])
		{
			int b = u.first;
			int w = u.second;

			if (distance[b] > distance[a] + w)
			{
				distance[b] = distance[a] + w;
				q.push(make_pair(-distance[b], b));
			}
		}
	}
	cout << distance[Y] << endl;

	return 0;
}
