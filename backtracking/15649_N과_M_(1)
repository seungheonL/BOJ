#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void brute_force(int index, int count)
{
    if(count == M)
    {
        for(int i=0; i<v.size(); i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    
    for(int i=1; i<=N; i++)
    {
        bool found = false;
        for(int j=0; j<v.size(); j++)
        {
            if(v[j] == i)
            {
                found = true;
                break;
            }
        }
        if(!found)
        {
            v.push_back(i);
            brute_force(1, count + 1);
            v.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;
    
    brute_force(0, 0);
    
    return 0;
}
