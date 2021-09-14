#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

vector<int> parent;
vector<int> level;

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

int main()
{
	int N, M;
	cin >> N >> M;

	vector<Edge> edges;
	parent.resize(N + 1);
	level.resize(N + 1);
	
	vector<pair<long long, long long>> coords;
	
	for (int i = 1; i <= N; i++)
	{
		long long X, Y;
		scanf("%lld %lld", &X, &Y);
		
		coords.push_back({X, Y});
		
		for(int j = 0; j < i - 1; j++)
		{
		    edges.push_back(Edge(i, j + 1, sqrt((X - coords[j].first) * (X - coords[j].first) + (Y - coords[j].second) * (Y - coords[j].second))));
		}
	}
	sort(edges.begin(), edges.end());
	
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		level[i] = 1;
	}
	
	int cnt = 0;
	
	for(int i = 0; i < M; i++)
	{
	    int a, b;
	    scanf("%d %d", &a, &b);
	    
	    if(!same(a, b))
	    {
	        unite(a, b);
	        cnt++;
	    }
	}

	double sum = 0.0;
	
	for (Edge edge : edges)
	{
		if (!same(edge.source, edge.destination))
		{
			unite(edge.source, edge.destination);
			sum += edge.weight;
			
			cnt++;
			
			if(cnt == N - 1)
			{
			    break;
			}
		}
	}

	printf("%.2lf\n", sum);

	return 0;
}

int find(int x)
{
	while (x != parent[x])
	{
		x = parent[x];
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

	if (level[a] < level[b])
	{
		swap(a, b);
	}
	level[a] += level[b];
	parent[b] = a;
}
