#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string expr;
    cin >> expr;
    
    vector<string> lefts, rights;
    int leftSum = 0, rightSum = 0;
    int firstMinus = expr.find('-');
    
    if(firstMinus == string::npos)
    {
        string left = expr;
        
        while(true)
        {
            if(left.find('+') == string::npos)
            {
                lefts.push_back(left.substr(0));
                break;
            }
            lefts.push_back(left.substr(0, left.find('+')));
            left = left.substr(left.find('+') + 1);
        }
    
        for(int i=0; i<lefts.size(); i++)
        {
            leftSum += stoi(lefts[i]);
        }
        
        cout << leftSum << endl;
        return 0;
    }
    
    string left = expr.substr(0, firstMinus);
    string right = expr.substr(firstMinus + 1, expr.size() - firstMinus - 1);
    
    for(int i=0; i<right.size(); i++)
    {
        if(right[i] == '-')
        {
            right[i] = '+';
        }
    }
    
    //cout << left << " " << right << endl;
    
    while(true)
    {
        if(left.find('+') == string::npos)
        {
            lefts.push_back(left.substr(0));
            break;
        }
        lefts.push_back(left.substr(0, left.find('+')));
        left = left.substr(left.find('+') + 1);
    }
    
    for(int i=0; i<lefts.size(); i++)
    {
        leftSum += stoi(lefts[i]);
    }
    
    while(true)
    {
        if(right.find('+') == string::npos)
        {
            rights.push_back(right.substr(0));
            break;
        }
        rights.push_back(right.substr(0, right.find('+')));
        right = right.substr(right.find('+') + 1);
    }
    
    for(int i=0; i<rights.size(); i++)
    {
        rightSum += stoi(rights[i]);
    }
    
    //cout << leftSum << " " << rightSum << endl;
    
    cout << leftSum - rightSum << endl;

    return 0;
}
