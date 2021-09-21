#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

vector<vector<int>> paper;

string answer;

void solve(int x_begin, int x_end, int y_begin, int y_end)
{
    bool allBlue = true;
    bool allWhite = true;
    
    int countBlue = 0;
    int total = (x_end - x_begin + 1) * (y_end - y_begin + 1);
    
    if(x_begin == x_end)
    {
        if(paper[x_begin][y_begin] == 1)
        {
            cout << 1;
            return;
        }
        cout << 0;
        return;
    }
    
    for(int i=x_begin; i<=x_end; i++)
    {
        for(int j=y_begin; j<=y_end; j++)
        {
           if(paper[i][j] != 1)
           {
               allBlue = false;
           }
           else
           {
               allWhite = false;
           }
        }
    }
    if(allBlue)
    {
        cout << 1;
        return;
    }
    if(allWhite)
    {
        cout << 0;
        return;
    }
    
    int x_mid = (x_begin + x_end) / 2;
    int y_mid = (y_begin + y_end) / 2;
    
    cout << "(";
    solve(x_begin, x_mid, y_begin, y_mid);
    solve(x_begin, x_mid, y_mid + 1, y_end);
    solve(x_mid + 1, x_end, y_begin, y_mid);
    solve(x_mid + 1, x_end, y_mid + 1, y_end);
    cout <<")";
}

int main()
{
    int N;
    cin >> N;
    
    paper = vector<vector<int>>(N, vector<int>(N, 0));
    
    for(int i=0; i<N; i++)
    {
        string str;
        cin >> str;
        
        for(int j=0; j<N; j++)
        {
            paper[i][j] = stoi(str.substr(j, 1));
        }
    }
    
    solve(0, N-1, 0, N-1);

    return 0;
}
