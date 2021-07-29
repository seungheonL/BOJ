#include <iostream>
#include <vector>

using namespace std;

vector<int> wines;
vector<vector<int>> cache;

int maximum(int currentIndex, bool drinkPrev)
{
    if(currentIndex > wines.size() - 1) 
    {
        return 0;
    }
    if(currentIndex == 0)
    {
        return max(wines[currentIndex] + maximum(currentIndex+1, true), maximum(currentIndex+1, false));
    }
    
    int& ret = cache[currentIndex][drinkPrev];
    if(ret != -1)
    {
        return ret;
    }
    if(drinkPrev)
    {
        return ret = max(wines[currentIndex] + maximum(currentIndex + 2, false), maximum(currentIndex+1, false));
    }
    return ret = max(wines[currentIndex] + maximum(currentIndex+1, true), maximum(currentIndex+1, false));
}

int main()
{
    int n;
    cin >> n;
    
    wines = vector<int>(n);
    cache = vector<vector<int>>(n, vector<int>(2, -1));
    
    for(int i=0; i<n; i++)
    {
        cin >> wines[i];
    }
    
    cout << maximum(0, false) << endl;
    
    return 0;
}
