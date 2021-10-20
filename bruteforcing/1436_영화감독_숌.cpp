#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int cnt=0;
    
    for(int i=665; ; i++)
    {
        string str = to_string(i);
        
        if(str.find("666") != string::npos)
        {
           cnt++;
        }
        if(cnt == N)
        {
            cout << str << endl;
            return 0;
        }
    }
    
   

    return 0;
}
