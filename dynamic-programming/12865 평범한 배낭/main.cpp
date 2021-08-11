#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, K;
vector<pair<int, int>> things;
vector<vector<int>> cache;

int maximize(int currentIndex, int currentWeight)
{
    if(currentIndex == N - 1)
    {
        if(currentWeight >= things[currentIndex].first)
        {
            return things[currentIndex].second;
        }
        return 0;
    }
    
    int& ret = cache[currentIndex][currentWeight];
    
    if(ret != -1)
    {
        return ret;
    }
    
    if(currentWeight >= things[currentIndex].first)
    {
        return ret = max(things[currentIndex].second + maximize(currentIndex + 1, currentWeight - things[currentIndex].first),
            maximize(currentIndex + 1, currentWeight));
    }
    return ret = maximize(currentIndex + 1, currentWeight);
}

int main()
{
    cin >> N >> K;
    
    cache = vector<vector<int>>(N, vector<int>(K + 1, -1));
    
    for(int i=0; i<N; i++)
    {
        int W, V;
        cin >> W >> V;
        
        things.push_back(make_pair(W, V));
    }
    
    cout << maximize(0, K) << endl;
    
    return 0;
}
