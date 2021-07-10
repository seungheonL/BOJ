#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void rotate_clockwise(vector<string>& target, int index)
{
    int last = target[index][7];
    
    for(int i=7; i>=1; i--)
    {
        target[index][i] = target[index][i-1];
    }
    
    target[index][0] = last;
}

void rotate_counterclockwise(vector<string>& target, int index)
{
    int first = target[index][0];
    
    for(int i=0; i<7; i++)
    {
        target[index][i] = target[index][i+1];
    }
    
    target[index][7] = first;
}

int main()
{
    vector<string> wheels(4);
    int K;
    
    for(int i=0; i<4; i++)
    {
        cin >> wheels[i];
    }
    
    cin >> K;
    
    for(int i=0; i<K; i++)
    {
        int number, dir;
        cin >> number >> dir;
        
        vector<bool> different(3, false);
        
        for(int i=0; i<3; i++)
        {
            if(wheels[i][2] != wheels[i+1][6])
            {
                different[i] = true;
            }
        }
        
        if(number == 1)
        {
            if(dir == 1)
            {
                rotate_clockwise(wheels, 0);
                
                if(different[0])
                {
                    rotate_counterclockwise(wheels, 1);
                    
                    if(different[1])
                    {
                        rotate_clockwise(wheels, 2);
                        
                        if(different[2])
                        {
                            rotate_counterclockwise(wheels, 3);
                        }
                    }
                }
            }
            
            else if(dir == -1)
            {
                rotate_counterclockwise(wheels, 0);
                
                if(different[0])
                {
                    rotate_clockwise(wheels, 1);
                    
                    if(different[1])
                    {
                        rotate_counterclockwise(wheels, 2);
                        
                        if(different[2])
                        {
                            rotate_clockwise(wheels, 3);
                        }
                    }
                }
            }
        }
        
        else if(number == 2)
        {
            if(dir == 1)
            {
                rotate_clockwise(wheels, 1);
                
                if(different[0])
                {
                    rotate_counterclockwise(wheels, 0);
                }
                
                if(different[1])
                {
                    rotate_counterclockwise(wheels, 2);
                    
                    if(different[2])
                    {
                        rotate_clockwise(wheels, 3);
                    }
                }
            }
            
            else if(dir == -1)
            {
                rotate_counterclockwise(wheels, 1);
                
                if(different[0])
                {
                    rotate_clockwise(wheels, 0);
                }
                
                if(different[1])
                {
                    rotate_clockwise(wheels, 2);
                    
                    if(different[2])
                    {
                        rotate_counterclockwise(wheels, 3);
                    }
                }
            }
        }
        
        else if(number == 3)
        {
            if(dir == 1)
            {
                rotate_clockwise(wheels, 2);
                
                if(different[1])
                {
                    rotate_counterclockwise(wheels, 1);
                    
                    if(different[0])
                    {
                        rotate_clockwise(wheels, 0);
                    }
                }
                
                if(different[2])
                {
                    rotate_counterclockwise(wheels, 3);
                }
            }
            
            else if(dir == -1)
            {
                rotate_counterclockwise(wheels, 2);
                
                if(different[1])
                {
                    rotate_clockwise(wheels, 1);
                    
                    if(different[0])
                    {
                        rotate_counterclockwise(wheels, 0);
                    }
                }
                
                if(different[2])
                {
                    rotate_clockwise(wheels, 3);
                }
            }
        }
        
        else if(number == 4)
        {
            if(dir == 1)
            {
                rotate_clockwise(wheels, 3);
                
                if(different[2])
                {
                    rotate_counterclockwise(wheels, 2);
                    
                    if(different[1])
                    {
                        rotate_clockwise(wheels, 1);
                        
                        if(different[0])
                        {
                            rotate_counterclockwise(wheels, 0);
                        }
                    }
                }
            }
            
            else if(dir == -1)
            {
                rotate_counterclockwise(wheels, 3);
                
                if(different[2])
                {
                    rotate_clockwise(wheels, 2);
                    
                    if(different[1])
                    {
                        rotate_counterclockwise(wheels, 1);
                        
                        if(different[0])
                        {
                            rotate_clockwise(wheels, 0);
                        }
                    }
                }
            }
        }
    }
    
    int score = 0;
    
    for(int i=0; i<4; i++)
    {
        if(wheels[i][0] == '1')
        {
            score += pow(2, i);
        }
    }
    
    cout << score << endl;
    
    return 0;
}
