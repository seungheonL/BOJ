#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int d(int n)
{
	int sum = n;
	for (int i = 0; i < std::to_string(n).size(); i++)
	{
		sum += std::atoi(std::to_string(n).substr(i, 1).c_str());
	}
	return sum;
}

int main()
{
	bool* flags = new bool[10000]{ false };

	for (int i = 1; i < 10000; i++)
	{
		int result = d(i);
		if (result < 10000)
		{
			flags[d(i)] = true;

		}
	}

	for (int i = 1; i < 10000; i++)
	{
		if (!flags[i])
		{
			printf("%d\n", i);
		}
	}

	return 0;
}
