#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<string> input(N);
    
    for(int i=0; i<N; i++)
    {
        cin >> input[i];
    }
    
    
    int result = 987654321;
    
    for(int i=0; i<N-7; i++)
    {
        for(int j=0; j<M-7; j++)
        {
            int cnt_white=0;
            int cnt_black=0;
            
            for(int k=i; k<i+8; k++)
            {
                for(int l=j; l<j+8; l++)
                {
                    if((k+l) % 2 == 0)
                    {
                        if(input[k][l] == 'B')
                        {
                            cnt_white++;
                        }
                        if(input[k][l] == 'W')
                        {
                            cnt_black++;
                        }
                    }
                    else
                    {
                        if(input[k][l] == 'W')
                        {
                            cnt_white++;
                        }
                        if(input[k][l] == 'B')
                        {
                            cnt_black++;
                        }
                    }
                }
            }
            result = min(result, cnt_black);
            result = min(result, cnt_white);
        }
    }
    
    cout << result << endl;

    return 0;
}
