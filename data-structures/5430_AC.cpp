#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		bool error = false;
		bool reverse = false;
		int idx = 0;

		string p;
		cin >> p;

		vector<std::deque<int>> d(10, std::deque<int>());

		int n;
		scanf("%d", &n);

		string x;
		cin >> x;
		for (int i = 1; i < x.size() - 1; i++) {
			if (x[i] != ',') {
				if (x[i - 1] != ',' && x[i - 1] != '[') {
					int temp = d[idx].back();
					d[idx].pop_back();
					int temp2 = x[i] - '0';
					d[idx].push_back(temp * 10 + temp2);
				}
				else d[idx].push_back(x[i] - '0');
			}
		}

		for (int j = 0; j < p.size(); j++)
		{
			if (p[j] == 'R')
			{
				reverse = !reverse;
			}
			else if (p[j] == 'D')
			{
				if (d[idx].empty())
				{
					cout << "error" << endl;
					error = true;
					break;
				}
				if (!reverse)
				{
					d[idx].pop_front();
				}
				else
				{
					d[idx].pop_back();
				}
			}
		}

		if (!error)
		{
			cout << "[";

			if (!reverse)
			{
				for (int i = 0; i < d[idx].size(); i++)
				{
					if (i == d[idx].size() - 1)
					{
						cout << d[idx][i];

					}
					else
					{
						cout << d[idx][i] << ",";
					}
				}
			}
			else
			{
				for (int i = d[idx].size() - 1; i >= 0 ; i--)
				{
					if (i == 0)
					{
						cout << d[idx][i];

					}
					else
					{
						cout << d[idx][i] << ",";
					}
				}
			}
			
			cout << "]" << endl;
		}
	}

	return 0;
}
