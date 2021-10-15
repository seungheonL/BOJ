#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    
    int N;
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        int value;
        scanf("%d", &value);
        
        v.push_back(value);
    }
    sort(v.begin(), v.end());
    int K;
    cin >> K;
    
    for(int i=0; i<K; i++)
    {
        int value;
        scanf("%d", &value);
        
        
        printf("%d ", upper_bound(v.begin(), v.end(), value)-lower_bound(v.begin(), v.end(), value));
    }

    return 0;
}
