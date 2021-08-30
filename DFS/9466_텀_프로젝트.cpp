#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> choose;
vector<bool> visited;
vector<bool> finished; 
int count;

void dfs(int here)
{
    visited[here] = true;
    int there = choose[here];
    
    if(!visited[there])
    {
        dfs(there);
    }
    
    else if(!finished[there])
    {
        int student = there;
        
        while(student != here)
        {
            count++;
            student = choose[student];
        }
        count++;
    }
    
    finished[here] = true;
}

int main()
{
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++)
    {
        scanf("%d", &n);
        
        choose = vector<int>(n+1);
        visited = vector<bool>(n+1, false);
        finished = vector<bool>(n+1, false);
        count = 0;
        
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &choose[j]);
        }
        
        for(int j=1; j<=n; j++)
        {
            if(!visited[j])
            {
                dfs(j);
            }
        }
        
        printf("%d\n", n - count);
    }

    return 0;
}
