#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int N;
	int count = 0;
	cin >> N;
	bool isFound = false;
	vector<int> v;

	for (int i = 1; i <= N; i++)
	{
		isFound = true;
		if (i < 100)
		{
			v.push_back(i / 10);
			v.push_back(i % 10);

			int difference = v[0] - v[1];

			for (int i = 0; i < v.size() - 1; i++)
			{
				if (v[i] - v[i + 1] != difference)
				{
					isFound = false;
					break;
				}
			}
			if(isFound)
				count++;

			v.clear();
		}
		
		else if (i < 1000)
		{
			v.push_back(i / 10 / 10);
			v.push_back(i % 100 / 10);
			v.push_back(i % 10 % 10);
			int difference = v[0] - v[1];

			//cout << v[0] << " " << v[1] << " " << v[2] << endl;

			for (int i = 0; i < v.size() - 1; i++)
			{
				if (v[i] - v[i + 1] != difference)
				{
					isFound = false;
					break;
				}
			}
			if(isFound)
				count++;
			v.clear();
		}
		else
		{

		}
	}
	cout << count << endl;
}
