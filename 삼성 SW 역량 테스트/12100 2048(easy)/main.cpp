#include <iostream>
#include <vector>

using namespace std;

int N;
int largest;

void getLargestBlock(const vector<vector<int>>& board, int count)
{
    if(count == 5)
    {
        return;
    }
    
    int dir = 0;
    
    while(dir < 4)
    {
        if(dir == 0) //UP
        {
            vector<vector<bool>> updated(N, vector<bool>(N, false));
            vector<vector<int>> newBoard = board;
            
            for(int j=0; j<N; j++)
            {
                for(int i=0; i<N; i++)
                {
                    if(newBoard[i][j] != 0)
                    {
                        int k = i;
                        
                        while(k > 0 && newBoard[k-1][j] == 0)
                        {
                            newBoard[k-1][j] = newBoard[k][j];
                            newBoard[k][j] = 0;
                            k--;
                        }
                        
                        if(k > 0)
                        {
                            if(newBoard[k-1][j] == newBoard[k][j])
                            {
                                if(!updated[k-1][j])
                                {
                                    newBoard[k-1][j] *= 2;
                                    updated[k-1][j] = true;
                                    largest = max(largest, newBoard[k-1][j]);
                                    newBoard[k][j] = 0;
                                }
                            }
                        }
                        
                    }
                }
            }
            
            getLargestBlock(newBoard, count + 1);
        }
        
        else if(dir == 1) //DOWN
        {
            vector<vector<bool>> updated(N, vector<bool>(N, false));
            vector<vector<int>> newBoard = board;
            
            for(int j=0; j<N; j++)
            {
                for(int i=N-1; i>=0; i--)
                {
                    if(newBoard[i][j] != 0)
                    {
                        int k = i;
                        
                        while(k < N - 1 && newBoard[k+1][j] ==0)
                        {
                            newBoard[k+1][j] = newBoard[k][j];
                            newBoard[k][j] = 0;
                            k++;
                        }
                        
                        if(k < N - 1)
                        {
                            if(newBoard[k+1][j] == newBoard[k][j])
                            {
                                if(!updated[k+1][j])
                                {
                                    newBoard[k+1][j] *= 2;
                                    updated[k+1][j] = true;
                                    largest = max(largest, newBoard[k+1][j]);
                                    newBoard[k][j] = 0;
                                }
                                
                            }
                        }
                    }
                }
            }

            getLargestBlock(newBoard, count + 1);
        }
        
        else if(dir == 2) //LEFT
        {
            vector<vector<bool>> updated(N, vector<bool>(N, false));
            vector<vector<int>> newBoard = board;
            
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    if(newBoard[i][j] != 0)
                    {
                        int k = j;
                        
                        while(k > 0 && newBoard[i][k-1] == 0)
                        {
                            newBoard[i][k-1] = newBoard[i][k];
                            newBoard[i][k] = 0;
                            k--;
                        }
                        
                        if(k > 0)
                        {
                            if(newBoard[i][k-1] == newBoard[i][k])
                            {
                                if(!updated[i][k-1])
                                {
                                newBoard[i][k-1] *= 2;
                                updated[i][k-1] = true;
                                largest = max(largest, newBoard[i][k-1]);
                                newBoard[i][k] = 0;
                                }

                            }
                        }
                    }
                }
            }
            
            getLargestBlock(newBoard, count + 1);
        }
        
        else if (dir == 3) //RIGHT
        {
            vector<vector<bool>> updated(N, vector<bool>(N, false));
            vector<vector<int>> newBoard = board;
            
            for(int i=0; i<N; i++)
            {
                for(int j=N-1; j>=0; j--)
                {
                    if(newBoard[i][j] != 0)
                    {
                        int k = j;
                        
                        while(k < N - 1 && newBoard[i][k+1] == 0)
                        {
                            newBoard[i][k+1] = newBoard[i][k];
                            newBoard[i][k] = 0;
                            k++;
                        }
                        
                        if(k < N - 1)
                        {
                            if(newBoard[i][k+1] == newBoard[i][k])
                            {
                                if(!updated[i][k+1])
                                {
                                    newBoard[i][k+1] *= 2;
                                    updated[i][k+1] = true;
                                    largest = max(largest, newBoard[i][k+1]);
                                    newBoard[i][k] = 0;
                                }
                                
                            }
                        }
                    }
                }
            }
            getLargestBlock(newBoard, count + 1);
        }
        
        dir++;
    }
}

int main()
{
    cin >> N;
    
    vector<vector<int>> board(N, vector<int>(N));
    
    largest = -1;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &board[i][j]);
            largest = max(largest, board[i][j]);
        }
    }
    
    getLargestBlock(board, 0);
    
    cout << largest << endl;
    
    return 0;
}
