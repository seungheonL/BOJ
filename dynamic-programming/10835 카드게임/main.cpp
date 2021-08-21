#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> leftCards;
vector<int> rightCards;
vector<vector<int>> cache;

int getMaxScore(int leftIndex, int rightIndex)
{
    if(leftIndex == N || rightIndex == N)
    {
        return 0;
    }
    
    if(cache[leftIndex][rightIndex] != -1)
    {
        return cache[leftIndex][rightIndex];
    }
    
    int result = -1;
    
    if(leftCards[leftIndex] > rightCards[rightIndex])
    {
        result = max(result, rightCards[rightIndex] + getMaxScore(leftIndex, rightIndex + 1));
        result = max(result, getMaxScore(leftIndex + 1, rightIndex));
        result = max(result, getMaxScore(leftIndex + 1, rightIndex + 1));
        
        return cache[leftIndex][rightIndex] = result;
    }
    
    result = max(result, getMaxScore(leftIndex + 1, rightIndex));
    result = max(result, getMaxScore(leftIndex + 1, rightIndex + 1));
    
    return cache[leftIndex][rightIndex] = result;
}

int main()
{
    cin >> N;
    
    leftCards = vector<int>(N);
    rightCards = vector<int>(N);
    cache = vector<vector<int>>(N, vector<int>(N, -1));
    
    for(int i=0; i<N; i++)
    {
        scanf("%d", &leftCards[i]);
    }
    
    for(int i=0; i<N; i++)
    {
        scanf("%d", &rightCards[i]);
    }
    
    cout << getMaxScore(0, 0) << endl;
    
    return 0;
}
