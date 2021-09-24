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

int main()
{
	int N, M;
	cin >> N >> M;
	
	parent = vector<int>(N + 1);
	level = vector<int>(N + 1);
	
	for(int i=1; i<=N; i++)
	{
	    parent[i] = i;
	    level[i] = 1;
	}
	
	for(int i=1; i<=N; i++)
	{
	    for(int j=1; j<=N; j++)
	    {
	        bool connected;
	        scanf("%d", &connected);
	        
	        if(connected)
	        {
	            if(!same(i, j))
	            {
	                unite(i, j);
	            }
	        }
	    }
	}
	
	vector<int> v(M);
	
	for(int i=0; i<M; i++)
	{
	    scanf("%d", &v[i]);
	}
	
	bool possible = true;
	
	for(int i=0; i<v.size() - 1; i++)
	{
	    if(!same(v[i], v[i + 1]))
	    {
	        possible = false;
	        break;
	    }
	}
	
	if(possible)
	{
	    cout << "YES" << endl;
	}
	
	else
	{
	    cout << "NO" << endl;
	}
	
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
