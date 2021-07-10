#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    
    vector<long long> v(N);
    
    for(int i=0; i<N; i++)
    {
        scanf("%lld", &v[i]);
    }
    
    long long B, C;
    cin >> B >> C;
    
    long long sum = 0;
    
    for(int i=0; i<N; i++)
    {
        v[i] -= B;
        sum++;
        
        if(v[i] > 0)
        {
            long long result = v[i] / C;
            
            if(v[i] % C == 0)
            {
                sum += result;
            }
            
            else
            {
                sum += result + 1;
            }
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
