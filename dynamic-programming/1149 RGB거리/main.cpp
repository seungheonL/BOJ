#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class House
{
public:
    int red;
    int green;
    int blue;
    
    House(int red, int green, int blue) : red(red), green(green), blue(blue) {}
    House(){}
};

int N;

vector<House> houses;
vector<vector<int>> cache;

int solve(int index, int color)
{
    int ret = 987654321;
    if(index == 0)
    {
        ret = std::min(ret, houses[0].red + solve(1, 0));
        ret = std::min(ret, houses[0].green + solve(1, 1));
        ret = std::min(ret, houses[0].blue + solve(1, 2));
        return ret;
    }
    if(index == N - 1)
    {
        if(color == 0)
        {
            return std::min(houses[index].green, houses[index].blue);
        }
        if(color == 1)
        {
            return std::min(houses[index].red, houses[index].blue);
        }
        if(color == 2)
        {
            return std::min(houses[index].red, houses[index].green);
        }
    }
    
    if(cache[index][color] != -1)
    {
        return cache[index][color];
    }
    
    if(color == 0)
    {
        ret = std::min(ret, std::min(houses[index].green + solve(index + 1, 1), houses[index].blue + solve(index + 1, 2)));
        return cache[index][color] = ret;
    }
    if(color == 1)
    {
        ret = std::min(ret, std::min(houses[index].red + solve(index + 1, 0), houses[index].blue + solve(index + 1, 2)));
        return cache[index][color] = ret;
    }
    if(color == 2)
    {
        ret = std::min(ret, std::min(houses[index].red + solve(index + 1, 0), houses[index].green + solve(index + 1, 1)));
        return cache[index][color] = ret;
    }
}

int main()
{
    cin >> N;
    
    houses = vector<House>(N);
    cache = vector<vector<int>>(N, vector<int>(3));
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<3; j++)
        {
            cache[i][j] = -1;
        }
    }
    
    for(int i=0; i<N; i++)
    {
        cin >> houses[i].red;
        cin >> houses[i].green;
        cin >> houses[i].blue;
    }
    
    if(N == 1)
    {
        cout << std::min(houses[0].red, std::min(houses[0].blue, houses[0].green));
    }
    else
        cout << solve(0, -1) << endl;
    
    return 0;
}
