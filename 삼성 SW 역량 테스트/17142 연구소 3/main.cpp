#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 987654321;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int N, M;
vector<vector<int>> graph;
vector<pair<int, int>> activated;
int answer = INF;

vector<pair<int, int>> viruses;

bool valid(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

void solve(int start, int count)
{
    if(count == M)
    {
        queue<pair<int, int>> q;
        vector<vector<int>> temp = graph;
        
        for(int i=0; i<activated.size(); i++)
        {
            q.push(activated[i]);
            temp[activated[i].first][activated[i].second] = 0;
        }
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(valid(nx, ny) && (temp[nx][ny] == INF || temp[nx][ny] == -2))
                {
                    temp[nx][ny] = temp[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        bool success = true;
        int result = -1;
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(temp[i][j] == INF)
                {
                    success = false;
                    break;
                }
                
                if(temp[i][j] != -1)
                {
                    bool flag = false;
                    for(auto& elem : viruses)
                    {
                        if(i == elem.first && j == elem.second)
                        {
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                    {
                       result = max(result, temp[i][j]); 
                    }
                }
            }
            
            if(!success)
            {
                break;
            }
        }
        
        if(success)
        {
            answer = min(answer, result);
        }
    }
    
    else
    {
        for(int i=start; i<N*N; i++)
        {
            int x = i / N;
            int y = i % N;
            
            if(graph[x][y] == -2)
            {
                activated.push_back({x, y});
                solve(i + 1, count + 1);
                activated.pop_back();
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    
    graph = vector<vector<int>>(N, vector<int>(N));
    
    bool done = true;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &graph[i][j]);
            
            if(graph[i][j] == 0) //empty space
            {
                graph[i][j] = INF;
                done = false;
            }
            
            else if(graph[i][j] == 1) //wall
            {
                graph[i][j] = -1;
            }
            
            else if(graph[i][j] == 2) //virus
            {
                graph[i][j] = -2;
                viruses.push_back({i, j});
            }
        }
    }
    
    if(done)
    {
        cout << 0 << endl;
        return 0;
    }
    
    solve(0, 0);
    
    if(answer != INF)
    {
        cout << answer << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    
    return 0;
}
