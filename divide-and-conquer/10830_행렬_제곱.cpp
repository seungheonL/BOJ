#include <iostream>
#include <vector>

using namespace std;

int N;

vector<vector<unsigned long long>> multiply(vector<vector<unsigned long long>> A, vector<vector<unsigned long long>> B)
{
    vector<vector<unsigned long long>> result(N, vector<unsigned long long>(N, 0));
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                for(int k=0; k<N; k++)
                {
                    result[i][j] += ((A[i][k] * B[k][j]) % 1000);
                    result[i][j] % 1000;
                }
                result[i][j] % 1000;
            }
        }
    return result;
}

vector<vector<unsigned long long>> pow(vector<vector<unsigned long long>> A, unsigned long long B)
{
    if(B == 0)
    {
        vector<vector<unsigned long long>> result;(N, vector<unsigned long long>(N));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(i == j)
                {
                    result[i][j] = 1;
                }
                else
                {
                    result[i][j] = 0;
                }
            }
        }
        return result;
    }
    if(B == 1)
    {
        return A;
    }
    
    if(B % 2 == 0)
    {
        auto result = pow(A, B / 2);
        return multiply(result, result);
    }
    return (multiply(A, pow(A, B - 1)));
}

int main()
{
    unsigned long long B;
    cin >> N >> B;
    
    vector<vector<unsigned long long>> matrix(N, vector<unsigned long long>(N));
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int value;
            cin >> value;
            
            matrix[i][j] = value;
        }
    }
    
    matrix = pow(matrix, B);
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << matrix[i][j] % 1000 << " ";
        }
        cout << endl;
    }

    return 0;
}
