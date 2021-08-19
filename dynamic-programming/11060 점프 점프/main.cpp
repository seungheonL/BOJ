#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> maze;
vector<int> cache;

int getMinJump(int index)
{
    if(index == N - 1)
    {
        return 0;
    }
    
    if(index > N - 1)
    {
        return 987654321;
    }
    
    if(cache[index] != -1)
    {
        return cache[index];
    }
    
    int result = 987654321;
    
    for(int i=1; i<=maze[index]; i++)
    {
        result = min(result, 1 + getMinJump(index + i));
    }
    
    return cache[index] = result;
}

int main()
{
    cin >> N;
    
    maze = vector<int>(N);
    cache = vector<int>(N, -1);
    
    for(int i=0; i<N; i++)
    {
        scanf("%d", &maze[i]);
    }
    
    int result = getMinJump(0);
    
    if(result >= 987654321)
    {
        cout << -1 << endl;
    }
    
    else
    {
        cout << result << endl;
    }
    
    return 0;
}
