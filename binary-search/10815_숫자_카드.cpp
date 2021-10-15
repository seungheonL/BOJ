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
	vector<int> list;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		list.push_back(num);
	}

	sort(list.begin(), list.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);

		printf("%d ",binary_search(list.begin(), list.end(), num));
	}

	return 0;
}
