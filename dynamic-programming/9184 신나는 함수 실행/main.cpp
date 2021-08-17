#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<long long>>> cache;

long long w(int a, int b, int c)
{
    if(cache[a + 50][b + 50][c + 50] != -1)
    {
        return cache[a + 50][b + 50][c + 50];
    }
    
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return cache[a + 50][b + 50][c + 50] = 1;
    }
    
    if(a > 20 || b > 20 || c > 20)
    {
        return cache[a + 50][b + 50][c + 50] = w(20, 20, 20);
    }
    
    if(a < b && b < c)
    {
        return cache[a + 50][b + 50][c + 50] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    
    else
    {
        return cache[a + 50][b + 50][c + 50] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
}

int main()
{
    cache = vector<vector<vector<long long>>>(102, vector<vector<long long>>(102, vector<long long>(102, -1)));
    
    while(true)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        if(a == -1 && b == -1 && c == -1)
        {
            break;
        }
        
        printf("w(%d, %d, %d) = %lld\n", a, b, c, w(a, b, c));
    }

    return 0;
}
