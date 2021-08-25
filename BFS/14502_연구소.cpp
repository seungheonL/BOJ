#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, M;
vector<vector<int>> graph;
int cnt;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int i, int j)
{
    return 0 <= i && i < N && 0 <= j && j < M;
}



int main()
{
    cin >> N >> M;
    
    graph = vector<vector<int>>(N, vector<int>(M));
    vector<pair<int, int>> coords;
    
    cnt=0;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> graph[i][j];
            
            if(graph[i][j] == 2)
            {
                coords.push_back({i, j});
            }
            if(graph[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    
    int max_safeArea = -1;
    
    for(int i = 0; i < N * M; i++)
    {
        int begin_x = i / M;
        int begin_y = i % M;
        
        if(graph[begin_x][begin_y] == 1) continue;
        
        for(int j = i + 2; j < N * M; j++)
        {
            int end_x = j / M;
            int end_y = j % M;
            
            if(graph[end_x][end_y] == 1) continue;
            
            for(int k = i + 1; k < j; k++)
            {
                int between_x = k / M;
                int between_y = k % M;
                
                if(graph[between_x][between_y] == 1) continue;
                
                graph[begin_x][begin_y] = 1;
                graph[between_x][between_y] = 1;
                graph[end_x][end_y] = 1;
                
                int safeArea = cnt - 3;
                
                vector<vector<bool>> discovered(N, vector<bool>(M, false));
                queue<pair<int, int>> q;
                
                for(auto coord : coords)
                {
                    q.push(coord);
                    discovered[coord.first][coord.second] = true;
                }
                
                while(!q.empty())
                {
                    int currentX = q.front().first;
                    int currentY = q.front().second;
                    q.pop();
                    
                    
                    for(int i=0; i<4; i++)
                    {
                        int nx = currentX + dx[i];
                        int ny = currentY + dy[i];
                        
                        if(valid(nx, ny) && !discovered[nx][ny] && graph[nx][ny] == 0)
                        {
                            discovered[nx][ny] = true;
                            q.push({nx, ny});
                            
                            safeArea--;
                        }
                    }
                }
                
                graph[begin_x][begin_y] = 0;
                graph[between_x][between_y] = 0;
                graph[end_x][end_y] = 0;
                
                max_safeArea = max(max_safeArea, safeArea);
            }
        }
    }
    
    cout << max_safeArea << endl;
    
    return 0;
}
