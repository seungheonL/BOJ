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
	int V, E, K;
	cin >> V >> E >> K;

	vector<int> distance(V + 1);
	for (int i = 1; i <= V; i++)
	{
		distance[i] = numeric_limits<int>::max();
	}
	distance[K] = 0;

	vector<vector<pair<int, int>>> adj(V + 1);
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		adj[u].push_back(make_pair(v, w));
	}

	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, K));

	while (!q.empty())
	{
		int from = q.top().second;
        int currentCost = -q.top().first;
        
        q.pop();
        
        if(currentCost > distance[from]) continue;

		for (pair<int, int> u : adj[from])
		{
			int to = u.first;
			int weight = u.second;

			if (distance[from] + weight < distance[to])
			{
				distance[to] = distance[from] + weight;
				q.push(make_pair(-distance[to], to));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (distance[i] == numeric_limits<int>::max())
		{
			printf("%s\n", "INF");
		}
		else
		{
			printf("%d\n", distance[i]);
		}
	}

	return 0;
}
