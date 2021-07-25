#include <iostream>
#include <vector>

using namespace std;

vector<int> scores;
vector<vector<int>> cache;
int N;

int maximize(int currrentIndex, bool stepPrev)
{
    if(currrentIndex > N -1)
    {
        return -987654321;
    }
    if(currrentIndex == N - 1)
    {
        return scores[N-1];
    }
    
    if(currrentIndex == 0)
    {
        return max(scores[currrentIndex] + maximize(currrentIndex + 1, true), maximize(currrentIndex + 1, false));
    }
    
    int& ret = cache[currrentIndex][stepPrev];
    
    if(ret != -1)
    {
        return ret;
    }
    
    if(stepPrev)
    {
        return ret = max(scores[currrentIndex] + maximize(currrentIndex + 2, false), maximize(currrentIndex + 1, false));
    }
    return ret = scores[currrentIndex] + maximize(currrentIndex + 1, true);
    
}

int main()
{
    cin >> N;
    
    scores = vector<int>(N);
    cache = vector<vector<int>>(N, vector<int>(2, -1));
    
    for(int i=0; i<N; i++)
    {
        cin >> scores[i];
    }
    
    cout << maximize(0, false) << endl;
    
    return 0;
}
