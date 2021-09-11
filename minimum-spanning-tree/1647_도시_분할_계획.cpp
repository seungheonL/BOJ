#include <iostream>
#include <vector>
#include <algorithm>

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
	int N, M;
	cin >> N >> M;
	
	parent = vector<int>(N + 1);
	level = vector<int>(N + 1);
	
	vector<Edge> edges;
	
	for(int i=1; i<=N; i++)
	{
	    parent[i] = i;
	    level[i] = 1;
	}
	
	for(int i=0; i<M; i++)
	{
	    int a, b, c;
	    scanf("%d %d %d", &a, &b, &c);
	    
	    if(a != b)
	    {
	        edges.push_back(Edge(a, b, c));
	    }
	}
	
	sort(edges.begin(), edges.end());
	
	int cost = 0;
	int cnt = 0;
	
	for(Edge& edge : edges)
	{
	    if(!same(edge.source, edge.destination))
	    {
	        unite(edge.source, edge.destination);
	        cost += edge.weight;
	        
	        cnt++;
	        
	        if(cnt == N - 2)
	        {
	            break;
	        }
	    }
	}
	
	cout << cost << endl;
	
	return 0;
}

int find(int x)
{
	if (x == parent[x])
	{
		return x;
	}
	return parent[x] = find(parent[x]);
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
