#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> paper;

pair<int, int> count(int x_begin, int x_end, int y_begin, int y_end)
{
    bool allBlue = true;
    bool allWhite = true;
    
    int countBlue = 0;
    int total = (x_end - x_begin + 1) * (y_end - y_begin + 1);
    
    if(x_begin == x_end)
    {
        if(paper[x_begin][y_begin] == 1)
        {
            return make_pair(0, 1);
        }
        return make_pair(1, 0);
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
        return make_pair(0, 1);
    }
    if(allWhite)
    {
        return make_pair(1, 0);
    }
    
    int x_mid = (x_begin + x_end) / 2;
    int y_mid = (y_begin + y_end) / 2;
    
    auto leftUp = count(x_begin, x_mid, y_begin, y_mid);
    auto rightUp = count(x_begin, x_mid, y_mid + 1, y_end);
    auto leftDown = count(x_mid + 1, x_end, y_begin, y_mid);
    auto rightDown = count(x_mid + 1, x_end, y_mid + 1, y_end);
    
    return make_pair(leftUp.first + rightUp.first + leftDown.first + rightDown.first, leftUp.second + rightUp.second + leftDown.second + rightDown.second);
}

int main()
{
    int N;
    cin >> N;
    
    paper = vector<vector<int>>(N, vector<int>(N, 0));
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            bool isBlue;
            cin >> isBlue;
            
            if(isBlue)
            {
                paper[i][j] = 1;
            }
        }
    }
    
    auto result = count(0, N-1, 0, N-1);
    
    cout << result.first << endl;
    cout << result.second << endl;

    return 0;
}
