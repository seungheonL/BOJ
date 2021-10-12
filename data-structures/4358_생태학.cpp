#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    map<string, int> m;
    
    char str[40];
    
    int N = 0;
    
    while(fgets(str, 30, stdin))
    {
        m[string(str).substr(0, string(str).size() - 1)]++;
        
        N++;
    }
    
    for(const auto& elem : m)
    {
        printf("%s ", elem.first.c_str());
        printf("%.4lf\n", (double)(elem.second) * 100 / N);
    }
    
    return 0;
}
