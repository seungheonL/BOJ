#include <iostream>
#include <cstring>
#include <list>
#include <string>

using namespace std;

int main()
{
    string str;
    int M;
    cin >> str >> M;
    
    list<char> l;
    
    int size = str.size();
    
    for(int i=0; i<size; i++)
    {
        l.push_back(str[i]);
    }
    
    list<char>::iterator itr = l.end();
    
    
    
    for(int i=0; i<M; i++)
    {
        char command;
        cin >> command;
        if(command == 'L')
        {
            if(itr != l.begin())
            {
                itr--;
            }
        }
        else if(command == 'D')
        {
            if(itr != l.end())
            {
                itr++;
            }
        }
        else if (command == 'B')
        {
            if(itr != l.begin())
            {
                itr--;
                itr = l.erase(itr);
            }
        }
        else
        {
            char X;
            cin >> X;
            l.insert(itr, X);
        }
    }
    for(char c : l)
    {
        printf("%c", c);
    }
    
    return 0;
}
