#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> score;
int n;
vector<vector<int>> cache;

int maximize(int index, int choice)
{
    int result = -1;
    
    if(index == n - 1)
    {
        if(choice == 2)
        {
            return max(score[0][index], score[1][index]);
        }
        
        return score[choice][index];
    }
    
    if(cache[index][choice] != -1)
    {
        return cache[index][choice];
    }
    
    if(choice == 2)
    {
        result = max(result, score[0][index] + maximize(index + 1, 1));
        result = max(result, score[1][index] + maximize(index + 1, 0));
        result = max(result, maximize(index + 1, 2));
        
        return cache[index][choice] = result;
    }
    
    if(choice == 1)
    {
        result = max(result, score[1][index] + maximize(index + 1, 0));
        result = max(result, maximize(index + 1, 2));
        
        return cache[index][choice] = result;
    }
    
    if(choice == 0)
    {
        result = max(result, score[0][index] + maximize(index + 1, 1));
        result = max(result, maximize(index + 1, 2));
        
        return cache[index][choice] = result;
    }
}

int main()
{
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++)
    {
        scanf("%d", &n);
        
        score = vector<vector<int>>(2, vector<int>(n));
        cache = vector<vector<int>>(n, vector<int>(3, -1));
        
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d", &score[i][j]);
            }
        }
        
        printf("%d\n", maximize(0, 2));
    }

    return 0;
}
