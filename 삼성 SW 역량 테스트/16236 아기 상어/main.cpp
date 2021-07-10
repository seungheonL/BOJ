#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<vector<int>> space;
int currentSize;
int toEat;
int x;
int y;
int second;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 987654321;

bool valid(int i, int j)
{
    return 0 <= i && i < N && 0 <= j && j < N;
}

pair<int, pair<int, int>> bfs(int x_target, int y_target)
{
    vector<vector<int>> distance(N, vector<int>(N, INF));
    vector<vector<bool>> discovered(N, vector<bool>(N, false));
    distance[x][y] = 0;
    
    queue<pair<int, int>> q;
    q.push({x, y});
    discovered[x][y] = true;
    
    while(!q.empty())
    {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();
        
        //if(discovered[currentX][currentY]) continue;
        
        //discovered[currentX][currentY] = true;
        
        for(int i=0; i<4; i++)
        {
            int nx = currentX + dx[i];
            int ny = currentY + dy[i];
            
            if(valid(nx, ny) && space[nx][ny] <= currentSize)
            {
                if(!discovered[nx][ny])
                {
                    discovered[nx][ny] = true;
                    
                    distance[nx][ny] = distance[currentX][currentY] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return {distance[x_target][y_target], {x_target, y_target}};
}

int main()
{
    cin >> N;
    
    space = vector<vector<int>>(N, vector<int>(N));
    currentSize = 2;
    toEat = 0;
    second = 0;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> space[i][j];
            if(space[i][j] == 9)
            {
                x = i;
                y = j;
                
                space[i][j] = 0;
            }
        }
    }
    
    while(true)
    {
        vector<pair<int, pair<int, int>>> candidates;
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(1 <= space[i][j] && space[i][j] <= 6 && space[i][j] < currentSize)
                {
                    auto result = bfs(i, j);
                    
                    if(result.first != INF)
                    {
                        candidates.push_back(result);
                    }
                }
            }
        }
        
        if(candidates.empty())
        {
            cout << second << endl;
            return 0;
        }
        else
        {
            sort(candidates.begin(), candidates.end());
            
            second += candidates[0].first;
            
            x = candidates[0].second.first;
            y = candidates[0].second.second;
            
            space[x][y] = 0;
            
            toEat++;
            
            if(toEat == currentSize)
            {
                currentSize++;
                toEat = 0;
            }
        }
    }
    
    return 0;
}
