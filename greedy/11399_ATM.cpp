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
	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int time;
		cin >> time;

		v.push_back(time);
	}

	sort(v.begin(), v.end());

	int sum = 0;
	
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += v[j];
		}
	}
	
	cout << sum << endl;

	return 0;
}
