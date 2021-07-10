#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

class Dice
{
public:
	int top;
	int bottom;
	int up;
	int right;
	int down;
	int left;

	Dice(int top, int bottom, int up, int right, int down, int left)
		: top(top), bottom(bottom), up(up), right(right), down(down), left(left)
	{}

	void moveEast()
	{
		int temp_top = top;
		top = left;
		left = bottom;
		bottom = right;
		right = temp_top;
	}

	void moveWest()
	{
		int temp_top = top;
		top = right;
		right = bottom;
		bottom = left;
		left = temp_top;
	}

	void moveNorth()
	{
		int temp_top = top;
		top = down;
		down = bottom;
		bottom = up;
		up = temp_top;
	}

	void moveSouth()
	{
		int temp_top = top;
		top = up;
		up = bottom;
		bottom = down;
		down = temp_top;
	}
};

bool valid(int row, int col, int N, int M)
{
	return (row >= 0 && row < N && col >= 0 && col < M);
}

int main()
{
	Dice dice(0,0,0,0,0,0);

	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;

	vector<vector<int>> map(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int value;
			cin >> value;

			map[i][j] = value;
		}
	}
	
	for (int i = 0; i < K; i++)
	{
		int command;
		cin >> command;

		if (command == 1) //EAST	
		{
			if (valid(x, y + 1, N, M))
			{
				dice.moveEast();
				y++;

				if (map[x][y] == 0)
				{
					map[x][y] = dice.bottom;
				}
				else
				{
					dice.bottom = map[x][y];
					map[x][y] = 0;
				}
				printf("%d\n", dice.top);
			}
		}
		else if (command == 2) //WEST
		{
			if (valid(x, y - 1, N, M))
			{
				dice.moveWest();
				y--;

				if (map[x][y] == 0)
				{
					map[x][y] = dice.bottom;
				}
				else
				{
					dice.bottom = map[x][y];
					map[x][y] = 0;
				}
				printf("%d\n", dice.top);
			}
		}
		else if (command == 3) //NORTH
		{
			if (valid(x - 1, y, N, M))
			{
				dice.moveNorth();
				x--;

				if (map[x][y] == 0)
				{
					map[x][y] = dice.bottom;
				}
				else
				{
					dice.bottom = map[x][y];
					map[x][y] = 0;
				}
				printf("%d\n", dice.top);
			}
		}
		else if (command == 4) //SOUTH
		{
			if (valid(x + 1, y, N, M))
			{
				dice.moveSouth();
				x++;

				if (map[x][y] == 0)
				{
					map[x][y] = dice.bottom;
				}
				else
				{
					dice.bottom = map[x][y];
					map[x][y] = 0;
				}
				printf("%d\n", dice.top);
			}
		}
	}

	return 0;
}
