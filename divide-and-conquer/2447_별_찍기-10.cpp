#include <iostream>
#include <vector>

using namespace std;

void solve(int N, int x, int y, vector<vector<char>>& arr)
{
    if(N==3)
    {
        for(int i=x; i < x + N; i++)
        {
            for(int j=y; j < y + N; j++)
            {
                if(i == x + N / 3 && j == y + N / 3)
                {
                    arr[i][j] = ' ';
                }
                else
                {
                    arr[i][j] = '*';
                }
            }
        }
    }
    else
    {
        solve(N / 3, x, y, arr);
        solve(N / 3, x, y + N / 3, arr);
        solve(N / 3, x, y + 2 * N / 3, arr);
        
        solve(N / 3, x + N / 3, y, arr);
        
        for(int i=x + N / 3; i < x + 2 * N / 3; i++)
        {
            for(int j=y + N / 3; j < y + 2 * N / 3; j++)
            {
                arr[i][j] = ' ';
            }
        }
        
        solve(N / 3, x + N / 3, y + 2 * N / 3, arr);
        
        solve(N / 3, x + 2 * N / 3, y, arr);
        solve(N / 3, x + 2 * N / 3, y + N / 3, arr);
        solve(N / 3, x + 2 * N / 3, y + 2 * N / 3, arr);
    }
}

int main()
{
    int N;
    cin >> N;
    
    vector<vector<char>> arr(N, vector<char>(N));
    
    solve(N, 0, 0, arr);
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
