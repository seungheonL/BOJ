#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

pair<int, int> head;
int dir;
int N;
deque<pair<int, int>> snake;

pair<int, int> getNextPosition()
{
    if(dir == 0)
    {
        return pair<int, int>({head.first, head.second + 1});
    }
    
    else if(dir == 1)
    {
        return pair<int, int>({head.first, head.second - 1});
    }
    
    else if(dir == 2)
    {
        return pair<int, int>({head.first + 1, head.second});
    }
    
    else if(dir == 3)
    {
        return pair<int, int>({head.first - 1, head.second});
    }
}

bool valid(pair<int, int> p)
{
    return 0 <= p.first && p.first < N && 0 <= p.second && p.second < N;
}

bool hit(pair<int, int> p)
{
    for(auto elem : snake)
    {
        if(p.first == elem.first && p.second == elem.second)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    int K;
    cin >> N >> K;
    
    vector<vector<int>> board(N, vector<int>(N, 0));
    
    for(int i=0; i<K; i++)
    {
        int x, y;
        cin >> x >> y;
        
        board[x-1][y-1] = 1;
    }
    
    int L;
    cin >> L;
    
    queue<pair<int, char>> information;
    
    for(int i=0; i<L; i++)
    {
        int X;
        char C;
        cin >> X >> C;
        
        information.push({X, C});
    }
    
    snake.push_front({0, 0});
    
    head = {0, 0};
    dir = 0; // 0: east, 1: west, 2: south, 3: north
    
    int t = 0;
    
    while(true)
    {
        pair<int, int> nextHead = getNextPosition();
        
        t++;
        
        if(!valid(nextHead) || hit(nextHead))
        {
            break;
        }
        
        if(board[nextHead.first][nextHead.second])
        {
            snake.push_front({nextHead});
            head = nextHead;
            board[nextHead.first][nextHead.second] = 0;
        }
        else
        {
            snake.push_front({nextHead});
            snake.pop_back();
            head = nextHead;
        }
        
        if(t == information.front().first)
        {
            if(information.front().second == 'L')
            {
                if(dir == 0)
                {
                    dir = 3;
                }
                else if(dir == 1)
                {
                    dir = 2;
                }
                else if(dir == 2)
                {
                    dir = 0;
                }
                else if(dir == 3)
                {
                    dir = 1;
                }
            }
            else if(information.front().second == 'D')
            {
                if(dir == 0)
                {
                    dir = 2;
                }
                else if(dir == 1)
                {
                    dir = 3;
                }
                else if(dir == 2)
                {
                    dir = 1;
                }
                else if(dir == 3)
                {
                    dir = 0;
                }
            }
            
            information.pop();
        }
    }
    
    cout << t << endl;

    return 0;
}
