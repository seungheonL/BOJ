#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int M, N;

bool valid(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < M;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}; 

int main()
{
    cin >> M >> N;
    
    vector<vector<int>> box(N, vector<int>(M));
    queue<pair<int, int>> q;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            scanf("%d", &box[i][j]);
            
            if(box[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            if(valid(nextX, nextY))
            {
                if(box[nextX][nextY] == 0)
                {
                    box[nextX][nextY] = box[x][y] + 1;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(box[i][j] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    int answer = -1;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(answer < box[i][j])
            {
                answer = box[i][j];
            }
        }
    }
    
    cout << answer - 1 << endl;

    return 0;
}
