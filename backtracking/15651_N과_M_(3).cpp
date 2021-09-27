#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void brute_force(int count)
{
    if(count == M)
    {
        for(int i=0; i<v.size(); i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    
    else
    {
        for(int i=1; i<=N; i++)
        {
            v.push_back(i);
            brute_force(count + 1);
            v.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;
    
    brute_force(0);
    
    return 0;
}
