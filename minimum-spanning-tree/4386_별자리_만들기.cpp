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
	double weight;

	Edge(int source = 0, int destination = 0, double weight = 0)
		: source(source), destination(destination), weight(weight)
	{}

	friend bool operator<(const Edge& lhs, const Edge& rhs)
	{
		return lhs.weight < rhs.weight;
	}
};

class Star
{
public:
	int id;
	int x;
	int y;

	Star(int id, int x, int y)
		: id(id), x(x), y(y)
	{}
};

int main()
{
	int n;
	cin >> n;

	vector<Edge> edges;
	vector<Star> stars;
	link.resize(n);
	Size.resize(n);	

	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;

		if (!stars.empty())
		{
			for (Star star : stars)
			{
				edges.push_back(Edge(i, star.id, sqrt(pow(x - star.x, 2) + pow(y - star.y, 2))));
				edges.push_back(Edge(star.id, i, sqrt(pow(x - star.x, 2) + pow(y - star.y, 2))));
			}
		}
		stars.push_back(Star(i, x, y));
	}
	sort(edges.begin(), edges.end());

	for (int i = 0; i < n; i++)
	{
		link[i] = i;
		Size[i] = 1;
	}

	double sum = 0;
	for (Edge edge : edges)
	{
		if (!same(edge.source, edge.destination))
		{
			unite(edge.source, edge.destination);
			sum += edge.weight;
		}
	}
	printf("%.2f\n", sum);

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
