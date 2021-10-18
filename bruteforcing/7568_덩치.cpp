#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int main()
{
	vector<pair<int, int>> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int weight, height;
		cin >> weight >> height;

		v.push_back(make_pair(weight, height));
	}

	for (int i = 0; i < N; i++)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			else
			{
				if (v[i].first < v[j].first && v[i].second < v[j].second)
				{
					count++;
				}
			}
		}
		cout << count + 1 << endl;;
	}

	return 0;
}
