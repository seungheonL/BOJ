#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	priority_queue<pair<int, int>> q;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int value;
		scanf("%d", &value);

		if (value > 0)
		{
			q.push(make_pair(-value, -value));
		}
		else if (value < 0)
		{
			q.push(make_pair(value, -value));
		}
		else
		{
			if (!q.empty())
			{
				printf("%d\n", -q.top().second);
				q.pop();
			}
			else
			{
				printf("0\n");
			}
		}
	}

	return 0;
}
