#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> w;
vector<int> v;
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
        v.push_back(w[i]);
        print(i, size + 1);
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    
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
