#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> sequence(n);
    
    for(int i=0; i<n; i++)
    {
        cin >> sequence[i];
    }
    
    int currentSum = 0;
    int max = -987654321;
    
    for(int i=0; i<n; i++)
    {
        currentSum += sequence[i];
        if(max < currentSum)
        {
            max = currentSum;
        }
        if(currentSum < 0)
        {
            currentSum = 0;
        }
    }
    
    cout << max << endl;
    
    return 0;
}
