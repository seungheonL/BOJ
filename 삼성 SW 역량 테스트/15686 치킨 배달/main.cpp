#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int N, M;
vector<vector<int>> city;
vector<pair<int, int>> chickens;
int answer = 987654321;;

void select_compute(int start, int count)
{
    if(count == M)
    {
        int sum = 0;
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(city[i][j] == 1)
                {
                    int result = 987654321;
                    
                    for(auto& elem : chickens)
                    {
                        result = min(result, abs(elem.first - i) + abs(elem.second - j));
                    }
                    
                    sum += result;
                }
            }
        }
        
        answer = min(answer, sum);
    }
    else
    {
        for(int i=start; i<N*N; i++)
        {
            int row = i / N;
            int col = i % N;
            
            if(city[row][col] == 2)
            {
                chickens.push_back({row, col});
                select_compute(i + 1, count + 1);
                chickens.pop_back();
            }
        }
    }
    
}

int main()
{
    cin >> N >> M;
    
    city = vector<vector<int>>(N, vector<int>(N));
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> city[i][j];
        }
    }
    
    select_compute(0, 0);
    
    cout << answer << endl;

    return 0;
}
