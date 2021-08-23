#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

class State
{
public:
	int X;
	int cnt;

	State(int X, int cnt) :X(X), cnt(cnt) {}
};

int main()
{
	int N, K;
	cin >> N >> K;
	queue<State> q;
	vector<bool> visited(2000001, false);
	vector<int> count(2000001, 0);
	q.push(State(N, 0));

	int cnt = 0;

	if (N == K)
	{
		cout << 0 << endl;
	}
	else
	{
		while (!q.empty())
		{
			State state = q.front();
			q.pop();
			
			if (state.X == K)
			{
				cout << state.cnt << endl;

				break;
			}
			else
			{
				if (state.X - 1 >= 0 && !visited[state.X - 1])
				{
					q.push(State(state.X - 1, state.cnt + 1));
					visited[state.X - 1] = true;
	
				}
				if (state.X + 1 <= 200000 && !visited[state.X + 1])
				{
					q.push(State(state.X + 1, state.cnt + 1));
					visited[state.X + 1] = true;

				}
				if (state.X * 2 <= 2000000 && !visited[state.X * 2])
				{
					q.push(State(state.X * 2, state.cnt + 1));
					visited[state.X * 2] = true;

				}
			}
		}
		
	}

	return 0;
}
