#include <iostream>
#include <vector>

using namespace std;

int R, C;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return 0 <= x && x < R && 0 <= y && y < C;
}

int main()
{
    int T;
    cin >> R >> C >> T;
    
    vector<vector<int>> A(R, vector<int>(C));
    
    int top, bottom;
    
    bool flag = false;
    
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            scanf("%d", &A[i][j]);
            
            if(A[i][j] == -1)
            {
                if(!flag)
                {
                    top = i;
                    flag = true;
                }
                else
                {
                    bottom = i;
                }
            }
        }
    }
    
    while(T--)
    {
        vector<vector<int>> updated = A;
        
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(A[i][j] > 0)
                {
                    int sum = 0;
                    
                    for(int k=0; k<4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        
                        if(valid(nx, ny) && !(nx == top && ny == 0) && !(nx == bottom && ny == 0))
                        {
                            updated[nx][ny] += A[i][j] / 5;
                            sum += A[i][j] / 5;
                        }
                    }
                    
                    updated[i][j] -= sum;
                }
            }
        }
        
        A = updated;
        
        //top
        
        for(int i=top-1; i>=0; i--)
        {
            if(i + 1 != top)
            {
                A[i+1][0] = A[i][0];
            }
        }
        
        for(int i=1; i<C; i++)
        {
            A[0][i-1] = A[0][i];
        }
        
        for(int i=0; i<=top; i++)
        {
            A[i][C-1] = A[i+1][C-1];
        }
        
        for(int i=C-1; i>=2; i--)
        {
            A[top][i] = A[top][i-1];
        }
        
        A[top][1] = 0;
        
        //bottom
        
        for(int i=bottom+1; i<R-1; i++)
        {
            A[i][0] = A[i+1][0];
        }
        
        for(int i=0; i<C-1; i++)
        {
            A[R-1][i] = A[R-1][i+1];
        }
        
        for(int i=R-1; i>=bottom+1; i--)
        {
            A[i][C-1] = A[i-1][C-1];
        }
        
        for(int i=C-1; i>=2; i--)
        {
            A[bottom][i] = A[bottom][i-1];
        }
        
        A[bottom][1] = 0;
    }
    
    int sum = 0;
    
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(A[i][j] != -1)
            {
                sum += A[i][j];
            }
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
