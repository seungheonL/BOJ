#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int N, M;

void print(int index, int size)
{
    if(size == M)
    {
        for(int i=0; i<M; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        
        return;
    }
    
    for(int i=index; i<=N; i++)
    {
        v.push_back(i);
        print(i, size + 1);
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    
    print(1, 0);
    
    return 0;
}
