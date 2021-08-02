#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for(int j=0; j<T; j++)
    {
        int N;
        cin >> N;
    
        vector<long long> sequence(N);
        sequence[0] = sequence[1] = sequence[2] = 1;
    
        for(int i=3; i<N; i++)
        {
            sequence[i] = sequence[i - 2] + sequence[i - 3];
        }
    
        cout << sequence[N-1] << endl;
    }
   
    return 0;
}
