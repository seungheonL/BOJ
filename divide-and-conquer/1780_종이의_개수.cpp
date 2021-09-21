#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> paper;

pair<int, pair<int, int>> count(int x_begin, int x_end, int y_begin, int y_end)
{
    bool allMinusOne = true;
    bool allZero = true;
    bool allOne = true;
    
    if(x_begin == x_end)
    {
        if(paper[x_begin][y_begin] == -1)
        {
            return make_pair(1, make_pair(0, 0));
        }
        if(paper[x_begin][y_begin] == 0)
        {
            return make_pair(0, make_pair(1, 0));
        }
        return make_pair(0, make_pair(0, 1));
    }
    
    for(int i=x_begin; i<=x_end; i++)
    {
        for(int j=y_begin; j<=y_end; j++)
        {
           if(paper[i][j] != -1)
           {
               allMinusOne = false;
           }
           if(paper[i][j] != 0)
           {
               allZero = false;
           }
           if(paper[i][j] != 1)
           {
               allOne = false;
           }
        }
    }
    if(allMinusOne)
    {
        return make_pair(1, make_pair(0, 0));
    }
    if(allZero)
    {
        return make_pair(0, make_pair(1, 0));
    }
    if(allOne)
    {
        return make_pair(0, make_pair(0, 1));
    }
    
    int x_first = (2 * x_begin + x_end) / 3;
    int x_second = (x_begin + 2 * x_end) / 3;
    
    int y_first = (2 * y_begin + y_end) / 3;
    int y_second = (y_begin + 2 * y_end) / 3;
    
    vector<pair<int, pair<int, int>>> counts;
    
    counts.push_back(count(x_begin, x_first, y_begin, y_first));
    counts.push_back(count(x_begin, x_first, y_first + 1, y_second));
    counts.push_back(count(x_begin, x_first, y_second + 1, y_end));
    
    counts.push_back(count(x_first + 1, x_second, y_begin, y_first));
    counts.push_back(count(x_first + 1, x_second, y_first + 1, y_second));
    counts.push_back(count(x_first + 1, x_second, y_second + 1, y_end));
    
    counts.push_back(count(x_second + 1, x_end, y_begin, y_first));
    counts.push_back(count(x_second + 1, x_end, y_first + 1, y_second));
    counts.push_back(count(x_second + 1, x_end, y_second + 1, y_end));
    
    int minusOne = 0, zero = 0, one = 0;
    
    for(int i=0; i<counts.size(); i++)
    {
        minusOne += counts[i].first;
        zero += counts[i].second.first;
        one += counts[i].second.second;
    }
    
    return make_pair(minusOne, make_pair(zero, one));
}

int main()
{
    int N;
    cin >> N;
    
    paper = vector<vector<int>>(N, vector<int>(N));
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> paper[i][j];
        }
    }
    
    auto result = count(0, N-1, 0, N-1);
    
    cout << result.first << endl;
    cout << result.second.first << endl;
    cout << result.second.second << endl;

    return 0;
}
