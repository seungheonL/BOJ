#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find_parent(int value)
{
    if(parent[value] == value)
    {
        return value;
    }
    else
    {
        return parent[value] = find_parent(parent[value]);
    }
}

void union_set(int a, int b)
{
   int a_parent = find_parent(a);
   int b_parent = find_parent(b);
   
   if(a_parent < b_parent)
   {
       parent[b_parent] = a_parent;
   }
   else
   {
       parent[a_parent] = b_parent;
   }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    parent = vector<int>(n+1);
    
    for(int i=0; i<parent.size(); i++)
    {
        parent[i] = i;
    }
    
    for(int i=0; i<m; i++)
    {
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);
        
        if(op == 0)
        {
            union_set(a, b);
        }
        else if(op == 1)
        {
            if(find_parent(a) == find_parent(b))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    
    return 0;
}
