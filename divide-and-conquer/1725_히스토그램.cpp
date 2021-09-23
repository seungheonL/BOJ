#include <iostream>
#include <vector>

using namespace std;

vector<long long> heights;

long long getMaxArea(int begin, int end)
{
    if(begin == end)
    {
        return heights[begin];
    }
    
    int mid = (begin + end) / 2;
    
    long long result = max(getMaxArea(begin, mid), getMaxArea(mid + 1, end));
    
    int i = mid;
    int j = mid + 1;
    
    long long height = min(heights[i], heights[j]);
    
    result = max(result, 2 * height);
    
    while(begin < i || j < end)
    {
        if(j < end && (begin >= i || heights[i - 1] < heights[j + 1]))
        {
            j++;
            height = min(height, heights[j]);
        }
        else
        {
            i--;
            height = min(height, heights[i]);
        }
        
        result = max(result, (j - i + 1) * height);
    }
    
    return result;
}

int main()
{
    int n;
    
    heights = vector<long long>(100000);
    cin >> n;
        
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &heights[i]);
    }
        
    cout << getMaxArea(0, n - 1) << endl;

    return 0;
}
