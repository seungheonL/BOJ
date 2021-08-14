#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<unsigned long long>> board;
vector<vector<unsigned long long>> cache;

bool valid(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

unsigned long long count(int x, int y)
{
    if(x == N - 1 && y == N - 1)
    {
        return 1;
    }
    
    if(cache[x][y] != -1)
    {
        return cache[x][y];
    }
    
    unsigned long long cnt = 0;
    
    if(valid(x + board[x][y], y) && board[x][y] != 0)
    {
        cnt += count(x + board[x][y], y);
    }
    
    if(valid(x, y + board[x][y]) && board[x][y] != 0)
    {
        cnt += count(x, y + board[x][y]);
    }
    
    return cache[x][y] = cnt;
}

int main()
{
    cin >> N;
    
    board = vector<vector<unsigned long long>>(N, vector<unsigned long long>(N));
    cache = vector<vector<unsigned long long>>(N, vector<unsigned long long>(N, -1));
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%llu", &board[i][j]);
        }
    }
    
    cout << count(0, 0) << endl;
    
    return 0;
}
