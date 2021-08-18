#include <iostream>
#include <vector>
#include <string>

using namespace std;

string password;
vector<long long> cache;

long long count(int index)
{
    if(index == password.size())
    {
        return 1;
    }
    
    if(index == password.size() - 1)
    {
        if(password[index] - '0' != 0)
        {
            return 1;
        }
        
        return 0;
    }
    
    if(cache[index] != -1)
    {
        return cache[index];
    }
    
    if(password[index] - '0' == 0)
    {
        return cache[index] = 0;
    }
    
    if(password[index] - '0' == 1)
    {
        if(password[index + 1] - '0' != 0)
        {
            cache[index] = count(index + 1) % 1000000 + count(index + 2) % 1000000;
            cache[index] %= 1000000;
            return cache[index];
        }
        
        cache[index] = count(index + 2) % 1000000;
        cache[index] %= 1000000;
        return cache[index];
    }
    
    
    if(password[index] - '0' == 2 && password[index + 1] - '0' <= 6)
    {
        if(password[index + 1] - '0' != 0)
        {
            cache[index] = count(index + 1) % 1000000 + count(index + 2) % 1000000;
            cache[index] %= 1000000;
            return cache[index];
        }
        
        cache[index] = count(index + 2) % 1000000;
        cache[index] %= 1000000;
        return cache[index];
    }
    
    cache[index] = count(index + 1) % 1000000;
    cache[index] %= 1000000;
    return cache[index];
}

int main()
{
    cin >> password;
    
    cache = vector<long long>(password.size(), -1);
    
    cout << count(0) % 1000000 << endl;
    
    return 0;
}
