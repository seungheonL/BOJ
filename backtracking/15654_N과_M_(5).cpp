#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> w;
vector<int> v;
vector<bool> visited;
int N, M;

void print(int index, int size)
{
    if(size == M)
    {
        for(int i=0; i<M; i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
        
        return;
    }
    
    for(int i=index; i<N; i++)
    {
        if(visited[i])
        {
            continue;
        }
        
        visited[i] = true;
        v.push_back(w[i]);
        
        print(0, size + 1);
        
        visited[i] = false;
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    
    visited = vector<bool>(N, false);
    
    for(int i=0; i<N; i++)
    {
        int value;
        scanf("%d", &value);
        
        w.push_back(value);
    }
    
    sort(w.begin(), w.end());
    
    print(0, 0);
    
    return 0;
}
