#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}

	int cnt = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		while (K >= v[i])
		{
			K -= v[i];
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}
