#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> link;
vector<int> Size;

int find(int x);
bool same(int a, int b);
void unite(int a, int b);

class Edge
{
public:
	int source;
	int destination;
	int weight;

	Edge(int source = 0, int destination = 0, int weight = 0)
		: source(source), destination(destination), weight(weight)
	{}

	friend bool operator<(const Edge& lhs, const Edge& rhs)
	{
		return lhs.weight < rhs.weight;
	}
};

int main()
{
	int V, E;
	cin >> V >> E;

	vector<Edge> edges;
	link.resize(V + 1);
	Size.resize(V + 1);

	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);

		edges.push_back(Edge(A, B, C));
	}
	sort(edges.begin(), edges.end());

	for (int i = 1; i <= V; i++)
	{
		link[i] = i;
		Size[i] = 1;
	}

	int sum = 0;
	for (Edge edge : edges)
	{
		if (!same(edge.source, edge.destination))
		{
			unite(edge.source, edge.destination);
			sum += edge.weight;
		}
	}

	cout << sum << endl;

	return 0;
}

int find(int x)
{
	while (x != link[x])
	{
		x = link[x];
	}
	return x;
}

bool same(int a, int b)
{
	return find(a) == find(b);
}

void unite(int a, int b)
{
	a = find(a);
	b = find(b);

	if (Size[a] < Size[b])
	{
		swap(a, b);
	}
	Size[a] += Size[b];
	link[b] = a;
}
